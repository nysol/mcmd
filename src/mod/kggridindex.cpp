/* ////////// LICENSE INFO ////////////////////

 * Copyright (C) 2013 by NYSOL CORPORATION
 *
 * Unless you have received this program directly from NYSOL pursuant
 * to the terms of a commercial license agreement with NYSOL, then
 * this program is licensed to you under the terms of the GNU Affero General
 * Public License (AGPL) as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF 
 * NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Please refer to the AGPL (http://www.gnu.org/licenses/agpl-3.0.txt)
 * for more details.

 ////////// LICENSE INFO ////////////////////*/

// x flush時のメモリ解放
// x datがなくてもkeyのみで動作 => addTimeファイルは作成しない
// x buffersizeをパラメータに
// x treeのサイズはどんどん大きくなるので、addされたleafへのpointerを覚えておいて、tree を走査しなくてもflushできるようにする。
// x addTimeをデータい入れる
// mode=add => json絡みなので最後に
// x h=の実装
// n=の実装
// jsonの出力

// =============================================================================
// kggridindex.cpp grid index生成クラス
// =============================================================================
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <kggridindex.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgTempfile.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem.hpp>

using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost::posix_time;

namespace fs = boost::filesystem;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgGridindex::kgGridindex(void)
{
	_name    = "kggridindex";
	_version = "###VERSION###";

	#include <help/en/kgcrossHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcrossHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgGridindex::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,h=,n=,i=,O=,-p,mode=,bufSize=",kgArgs::ALLPARAM);
	//cout << _args.to_s() << endl;

	// 入力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
	_iFile.read_header();

	// -p
	_forceFlg = _args.toBool("-p");
	kgstr_t bsStr = _args.toString("bufSize=",false);
	if(bsStr.empty()){
		_bufSize = 1000000;
	}else{
		_bufSize = aToSizeT(bsStr.c_str());
	}
	if(_bufSize<=0){
		throw kgError("bufSize= must be >=1");	
	}

	// 出力ディレクトリ
	kgstr_t str = _args.toString("O=",true)+"/data";
	if(str.empty()){
		ostringstream ss;
		ss << "O= is mandatory:";
		throw kgError(ss.str());	
	}
	oPath_=boost::filesystem::path(str);

	//cerr << "forceFlg=" << _forceFlg << " oPath=" << oPath_.string() << endl;

	// O= ディレクトリ作成
	if(_forceFlg){
		boost::system::error_code error;
		const bool status = fs::create_directories(oPath_, error);
		if (!status || error) {
			ostringstream ss;
			ss << "cannot create the directories: " << oPath_.string();
			throw kgError(ss.str());	
		}
	}else{
		boost::system::error_code error;
		const bool status = fs::create_directory(oPath_, error);
		if (!status || error) {
			ostringstream ss;
			ss << "cannot create the directory: " << oPath_.string();
			throw kgError(ss.str());	
		}
	}

	// f= 項目引数のセット
	vector<kgstr_t> vs_f = _args.toStringVector("f=",false);

	// h= 項目引数のセット
	vector< vector<kgstr_t> > vvs_h = _args.toStringVecVec("h=",':',2,false);
	for(size_t i=0; i<vvs_h[0].size(); i++){
		int hs=atoi(vvs_h[1][i].c_str());
		if(hs<2){
			ostringstream ss;
			ss << "hash size must be greater than 2: " << vvs_h[0][i];
			throw kgError(ss.str());	
		}
		hSize_.push_back(hs);
	}

	// n= 項目引数のセット
	vector< vector<kgstr_t> > vvs_n = _args.toStringVecVec("n=",':',2,false);
	for(size_t i=0; i<vvs_h[0].size(); i++){
		vector<double> rng;
		vector<string> sp = splitToken(vvs_n[1][i], '_');
		for(size_t i=0; i<sp.size(); i++){
			//cerr << sp.at(i) << endl;
			rng.push_back(::atof(sp.at(i).c_str()));
		}
		rng.push_back(DBL_MAX);
		nRange_.push_back(rng);
	}

	//for(size_t i=0; i<nRange_.size(); i++){
	//	for(size_t j=0; j<nRange_.at(i).size(); j++){
	//		cerr << nRange_[i][j] << endl;
	//	}
	//}

	// mode= 新規作成 or 追加
	_mode = _args.toString("mode=",true);
  if((! (_mode=="new")) && (! (_mode=="add"))){
		ostringstream ss;
		ss << "unknown mode: " << _mode << ": mode=new|add";
		throw kgError(ss.str());	
	}

	_fField.set(vs_f,  &_iFile, _fldByNum);
	_hField.set(vvs_h, &_iFile, _fldByNum);
	_nField.set(vvs_n, &_iFile, _fldByNum);
}


class Node;

class Tree {
	//kgCSVfld& iFile;
	//kgArgFld& fField;
	boost::filesystem::path& oPath_;
	Node* top;

	vector<Node*> updNodes_; // 追加されたnodeへのインデックス(出力時に利用)

	kgEnv* _env;
	bool _nfn_o;
	kgGridindex *_gi;
	vector<size_t> level2fldno_; /// node level => CSVの項目番号 変換表
	vector<string> keyNames_; /// key項目名配列
	vector<string> datNames_; /// dat項目名配列(leafに格納するデータの項目名:f=項目は省かれる)
	vector<bool>   datFlags_; /// iFileにおけるdat項目位置(true,false)
	string addTime_;

public:
	Tree(kgGridindex *gi, kgCSVfld& iFile, kgArgFld& fField, kgArgFld& hField, kgArgFld& nField, boost::filesystem::path& oPath, kgEnv* env, bool nfn_o);
	~Tree();

	void outCountUp(size_t n){_gi->outCountUp(n);}
	size_t level2fldno(int level){return level2fldno_[level];}
	string& keyNames(int level){return keyNames_[level];}
	vector<string>& datNames(void){return datNames_;}
	bool datFlags(size_t i){return datFlags_[i];}
	string& addTime(void){return addTime_;}

	void flush(void);
	void add(vector<const char *>& keys, vector<const char *>& dat);
	void addUpdNode(Node* node);
	void clearUpdNodes();

	void show(void);
	boost::filesystem::path& oPath(void){return oPath_;}
	kgEnv* env(void){return _env;}
	bool nfn_o(void){return _nfn_o;}
};

class Node {
	boost::filesystem::path path;
	string _oFile;
	bool isLeaf;

	int level;
	vector<vector<string> > dats; // 実データ(リーフのみ)
	Tree *tree; // Tree classへの参照

	// 要素番号が入力ファイルの項目番号(初期化にて全項目分の要素をNULLで確保)
	std::map<std::string, Node*> children;
	Node* parent;

	//vector<string> kv; // 本nodeに対応するkey-value(2要素固定)
	//vector<vector<string> > kvs; // ここのlevelまでのkey-value 配列 不必要?

	void mkDir(void);
public:
	Node(Tree* tree); // top node用constructor1
	Node(string keyName,string key, Node* parent=NULL);

	void free(void);
	void add(vector<const char *>& keys, vector<const char *>& dat);

	void flush(void);
	void show(void);
	void getKey(int level);
};

// -----------------------------------------------------------------------------
// Tree
// -----------------------------------------------------------------------------
Tree::Tree(kgGridindex *gi, kgCSVfld& iFile, kgArgFld& fField, kgArgFld& hField, kgArgFld& nField, boost::filesystem::path& oPath, kgEnv* env, bool nfn_o) : _gi(gi), oPath_(oPath), _env(env), _nfn_o(nfn_o){
	top=new Node(this);

	// 現在時刻を取得 => leafのファイル名: addTime_yyyymmddHHMMSS.xxxxxxx
	char buf[100];
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	sprintf(buf,"%04d%02d%02d%02d%02d%02d.%06d",
	  static_cast<int>(now.date().year() ),
	  static_cast<int>(now.date().month()),
	  static_cast<int>(now.date().day()  ),
		static_cast<int>(now.time_of_day().hours()),
	  static_cast<int>(now.time_of_day().minutes()),
	  static_cast<int>(now.time_of_day().seconds()),
	  static_cast<int>(now.time_of_day().fractional_seconds()));
	addTime_=string(buf);

	// 格納データ(f=項目を省いたデータ)の項目位置 true/false vector
	datFlags_.resize(iFile.fldSize(),true);
	for(size_t i=0; i<fField.size(); i++){
		datFlags_[fField.num(i)]=false;
	}
	// 格納データの項目名
	for(size_t i=0; i<iFile.fldSize(); i++){
		if(datFlags_[i]){
			datNames_.push_back(iFile.fldName(i));
		}
	}

	// key項目名vector(f=,h=,n=の順)
	for(size_t i=0; i<fField.size(); i++){
		keyNames_.push_back(iFile.fldName(fField.num(i)));
	}
	for(size_t i=0; i<hField.size(); i++){
		keyNames_.push_back(iFile.fldName(hField.num(i)));
	}
	for(size_t i=0; i<nField.size(); i++){
		keyNames_.push_back(iFile.fldName(nField.num(i)));
	}

	// node level => CSVの項目番号 変換表の作成
	for(size_t i=0; i<fField.size(); i++){
		level2fldno_.push_back(fField.num(i));
	}
}

Tree::~Tree(){
	//cerr << "destructor" << endl;
	top->free();
}

void Tree::add(vector<const char *>& keys, vector<const char *>& dat){
	top->add(keys,dat);
}

void Tree::flush(void){
	//cerr << "-------------------- tree flush start" << endl;
	for(size_t i=0; i<updNodes_.size(); i++){
		updNodes_[i]->flush();
	}
	//cerr << "-------------------- tree flush end" << endl;
}

void Tree::show(void){
	//cerr << "-------------------- tree show start" << endl;
	top->show();
	//cerr << "-------------------- tree show end" << endl;
}

void Tree::addUpdNode(Node* node){
	updNodes_.push_back(node);
}
void Tree::clearUpdNodes(){
	updNodes_.resize(0);
}

// -----------------------------------------------------------------------------
// Node
// -----------------------------------------------------------------------------
Node::Node(Tree* tree) : tree(tree){
	parent=NULL;
	level=0;
	isLeaf=false;
	path=tree->oPath();
}

Node::Node(string keyName,string key,Node* parent) : parent(parent){
	//cerr << "xxxxxxxxxxxx2 : " << keyName << endl;

	tree=parent->tree;
	level=parent->level+1;
	isLeaf=false;
	//cerr << "xxxst" << endl;
	path=parent->path / (keyName+"_"+key);
	//cerr << "xxxxxxxxxxxx3 : " << path.string() << endl;
	mkDir();

	//kv.push_back(keyName);
	//kv.push_back(key);
	//kvs=parent->kvs;
	//kvs.push_back(kv);
}

// a_{x,y,z}/b_{p,q}
// tree
//  top children[x]    : level=0
//    node children[p] : level=1
//      leaf           : level=2
//    node children[q]
//      leaf
//  top children[y]
//    node children[p]
//      leaf
//    node children[q]
//      leaf
//  top children[z]
//    node children[p]
//      leaf
//    node children[q]
//      leaf
void Node::add(vector<const char *>& keys, vector<const char *>& dat){
	// leaf処理:行データの蓄積
	if(keys.size()==level){
		isLeaf=true;

		// file name(full path)
		if(_oFile.size()==0){
			_oFile=(path/("addTime_"+tree->addTime())).string();
		}

		if(dat.size()==0) return;

		vector<string> d;
		for(size_t i=0; i<dat.size(); i++){
			d.push_back(dat[i]);
		}
		dats.push_back(d);

		tree->addUpdNode(this);
		return;
	}

	// node処理:keysを辿っていく
	string& keyName=tree->keyNames(level);
	//cerr << "xxxxxxxxxxxx1 : " << keyName << endl;
	string key=string(keys[level]);
	Node *child=children[key];
	if(!child){
		try {
			child=new Node(keyName,key,this);
			children[key]=child;
		} catch(...) {
			throw kgError("memory allocation error ");
		} 
	}
	//cerr << "child[" << key << "]=" << children[key] << endl;

	// 再帰call
	child->add(keys,dat);
}

void Node::show(void){
	string indent="";
	for(int i=0; i<level; i++){
		indent+="  ";
	}
	// leafの場合: dats内容出力
	if(isLeaf){
		cerr << indent << "dats:" << endl;
		for(size_t i=0; i<dats.size(); i++){
			cerr << indent;
			for(size_t j=0; j<dats[i].size(); j++){
				cerr << dats[i][j] << ",";
			}
			cerr << endl;
		}
	}

	// nodeの場合: 再帰call
	for(map<string,Node*>::iterator child = children.begin(); child != children.end(); child++) {
		//cerr << indent << "key:" << child->second->kv[0] << "_" << child->second->kv[1] << endl;
		child->second->show();
	}
}

void Node::mkDir(void){
	try {
		create_directories(path);
	} catch(...) {
		throw kgError("cannot create the directory:");
	}
}

void Node::flush(void){
	//cerr << "dats.size=" << dats.size() << endl;

	const bool exists = fs::exists(_oFile);
	kgCSVout oCSV;
	oCSV.aopen(_oFile, tree->env(), tree->nfn_o());

	// datの項目名出力
	if (!exists){
		vector<string>& names=tree->datNames();
		for(size_t i=0; i<names.size(); i++){
			oCSV.writeStr(names[i].c_str(),false);
		}
		oCSV.writeStr("addTime",true);
	}

	// datの値出力
	for(size_t i=0; i<dats.size(); i++){
		for(size_t j=0; j<dats[i].size(); j++){
			oCSV.writeStr(dats[i][j].c_str(),false);
		}
		oCSV.writeStr(tree->addTime().c_str(),true);
		tree->outCountUp(1);
	}

	oCSV.close();
	dats.resize(0); // dats領域開放
}

// Nodeの開放(深さ優先探索で葉っぱから開放)
void Node::free(){
	// 再帰call
	for(map<string,Node*>::iterator child = children.begin(); child != children.end(); child++) {
		child->second->free();
	}
	// delete実行
	for(map<string,Node*>::iterator child = children.begin(); child != children.end(); child++) {
		//cerr << "delete " << child->second << endl;
		delete child->second;
	}
}

// hash値の計算
unsigned int kgGridindex::hashval(char *key,int hashval){
	unsigned int v=0; 
	while(*key != '\0') v+=v*137+static_cast<unsigned int>(*key++);
	return v % hashval;
}

//////////////////// JSON
/*
{
x"iFile":"input/datS.csv",
x"asis_names":["date1"],
x"hash_names":["id"],
x"num_names":["num3"],
x"iFldNames":["id","date1","key1","key2","key3","key4","num1","num2","num3"],
x"asis_value":{"date1":["20000101","20000102","20000103","20000104","20000105","20000106","20000107","20000108","20000109","20000110"]},
x"hash_size":[4],
x"num_range":[[0.25,0.5,0.75]],
"oIndexNo":[9,10,11],
x"oFldNames":["id","num3","key1","key2","key3","key4","num1","num2","addTime"],
"oFldNo":[0,8,2,3,4,5,6,7,-1],
o"asisNo":[3],
x"addTime":"20171204192722.474096",
x"oPath":"./grid/ruby"
}
*/

class JSON {
	string jsonStr;

public:
	JSON();
	~JSON(){};

	void addName(string name);
	void add(string name, string s);
	void add(string name, vector<int> vec);
	void add(string name, vector<double> vec);
	void add(string name, vector<string> vec);
	void add(string name, vector<vector<double> > vec);
	void add(string name, map<string,set<string> > vec);
	void show(void);
	void write(string fName);
};

JSON::JSON(){
	jsonStr.append("{");
}

void JSON::write(string fname){
	ofstream outputfile(fname.c_str());
	outputfile << jsonStr;
	outputfile << "}";
	outputfile.close();
}

void JSON::addName(string name){
	if(jsonStr.size()>1){
		jsonStr.append(",");
	}
	jsonStr.append("\"");
	jsonStr.append(name);
	jsonStr.append("\":");
}

void JSON::add(string name, string s){
	char buf[100];
	addName(name);
	jsonStr.append("\""); jsonStr.append(s); jsonStr.append("\"");
}

void JSON::add(string name, vector<int> vec){
	if(vec.size()==0) return;
	char buf[100];
	addName(name);
	jsonStr.append("[");
	for(size_t i=0; i<vec.size()-1; i++){
		sprintf(buf, "%d,", vec.at(i)); jsonStr.append(buf);
	}
	sprintf(buf, "%d]", vec.back()); jsonStr.append(buf);
}

void JSON::add(string name, vector<double> vec){
	if(vec.size()==0) return;
	char buf[100];
	addName(name);
	jsonStr.append("[");
	for(size_t i=0; i<vec.size()-1; i++){
		sprintf(buf, "%g,", vec.at(i)); jsonStr.append(buf);
	}
	sprintf(buf, "%g]", vec.back()); jsonStr.append(buf);
}

void JSON::add(string name, vector<string> vec){
	if(vec.size()==0) return;
	char buf[100];
	addName(name);
	jsonStr.append("[");
	for(size_t i=0; i<vec.size()-1; i++){
		jsonStr.append("\""); jsonStr.append(vec.at(i)); jsonStr.append("\",");
	}
	jsonStr.append("\""); jsonStr.append(vec.back()); jsonStr.append("\"]");
}

void JSON::add(string name, vector<vector<double> > vec){
	//cerr << "vec.size:" << vec.back().size() << endl;
	if(vec.size()==0) return;
	if(vec.size()==1 && vec.back().size()==0 ) return;
	char buf[100];
	addName(name);
	jsonStr.append("[");
	for(size_t i=0; i<vec.size(); i++){
		jsonStr.append("[");
		for(size_t j=0; j<vec.at(i).size()-1; j++){ // 最後はDBL_MAXなので出力しない
			if(j==vec.at(i).size()-2){
				sprintf(buf, "%g]", vec.at(i).at(j)); jsonStr.append(buf);
			}else{
				sprintf(buf, "%g,", vec.at(i).at(j)); jsonStr.append(buf);
			}
		}
		if(i==vec.size()-1){
			jsonStr.append("]");
		}else{
			jsonStr.append(",");
		}
	}
}

void JSON::add(string name, map<string,set<string> > vec){
	if(vec.size()==0) return;
	char buf[100];
	addName(name);
	jsonStr.append("{");

	//"asis_value":{"date1":["20000101","20000102","20000103","20000104","20000105","20000106","20000107","20000108","20000109","20000110"]},
	size_t i=0;
	for(map<string,set<string> >::iterator map = vec.begin(); map != vec.end(); map++) {
		jsonStr.append("\"");
		jsonStr.append(map->first);
		jsonStr.append("\":");

		jsonStr.append("[");
		size_t j=0;
		for(set<string>::iterator set = map->second.begin(); set != map->second.end(); set++) {
			if(j==map->second.size()-1){
				jsonStr.append("\""); jsonStr.append(*set); jsonStr.append("\"]");
			}else{
				jsonStr.append("\""); jsonStr.append(*set); jsonStr.append("\",");
			}
			j++;
		}
		if(i==vec.size()-1){
			jsonStr.append("}");
		}else{
			jsonStr.append(",");
		}
		i++;
	}
}


void JSON::show(void){
	cerr << jsonStr << endl;
}

///////////////////
int kgGridindex::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	char **hBuf = new char*[_hField.size()];
	for(int i=0; i<_hField.size(); i++){
		hBuf[i] = new char[100];
	}

	char **nBuf = new char*[_nField.size()];
	for(int i=0; i<_nField.size(); i++){
		nBuf[i] = new char[100];
	}

	//cerr << "bufSize" << _bufSize << endl;
	int counter=0;
	Tree tree(this, _iFile,_fField,_hField,_nField, oPath_, _env, _nfn_i);
	while( EOF != _iFile.read() ){
		vector<const char *> keys; // key項目に対する値配列
		vector<const char *> dat; // leafに保存するデータ

		// f=項目のval処理
		for(size_t i=0; i<_fField.size(); i++){
			char* str=_iFile.getVal(_fField.num(i));
			if(*str!='\0'){
				keys.push_back(str);
				_asis_value[_fField.name(i)].insert(str);
			}else{
				keys.push_back("");
			}
		}

		// h=項目のval処理
		for(size_t i=0; i<_hField.size(); i++){
			char* str=_iFile.getVal(_hField.num(i));
			sprintf(hBuf[i],"%d", hashval(str,hSize_[i]));
			//cerr << "hBuf=" << hBuf[i] << endl;
			keys.push_back(static_cast<const char *>(hBuf[i]));
		}

		// n=項目のval処理
		for(size_t i=0; i<_nField.size(); i++){
			char* str=_iFile.getVal(_nField.num(i));
			double v=::atof(str);
			vector<double>& rng=nRange_.at(i);
			int cls=0;
			for(size_t i=0; i<rng.size(); i++){
				if(v<rng.at(i)) break;
				cls++;
			}
			sprintf(nBuf[0],"%d", cls);
			//cerr << "nBuf=" << nBuf[i] << endl;
			keys.push_back(static_cast<const char *>(nBuf[0]));
		}

		// 格納データ(f=項目を省いたデータ)の処理
		for(size_t i=0; i<_iFile.fldSize(); i++){
			if(tree.datFlags(i)){
				dat.push_back(_iFile.getVal(i));
			}
		}

		//for(size_t i=0;i<keys.size();i++) cerr << keys[i] << ",";
		//cerr << endl;

		// iFileのカレント行を、_fFieldで指定した項目を除いてtree上のkeys pathに追加する
		tree.add(keys,dat);

		counter++;
		if(counter>=_bufSize){
			tree.flush();
			tree.clearUpdNodes();
			counter=0;
		}
		;
	}
	tree.flush();
	tree.clearUpdNodes();
	//tree.show();

	vector<int> asis_no;
	int start=_fField.size()+_hField.size()+_nField.size();
	for(size_t i=0; i<_fField.size(); i++){
		asis_no.push_back(start);
		start--;
	}
	JSON json;
	json.add("iFile",_args.toString("i="));
	json.add("oPath",_args.toString("O="));
	json.add("asis_names",_fField.getName());
	json.add("hash_names",_hField.getName());
	json.add("hash_size",hSize_);
	json.add("num_names",_nField.getName());
	json.add("iFldNames",_iFile.fldName());
	json.add("addTime",tree.addTime());
	vector<string> tmp=tree.datNames();
	tmp.push_back("addTime");
	json.add("oFldNames",tmp);
	json.add("num_range",nRange_);
	json.add("asis_value",_asis_value);
	json.add("asisNo",asis_no);
	json.write(_args.toString("O=")+"/info.json");
	//json.show();

	for(int i=0; i<_hField.size(); i++){
		delete [] hBuf[i];
	}
	delete [] hBuf;

	for(int i=0; i<_nField.size(); i++){
		delete [] nBuf[i];
	}
	delete [] nBuf;


	// 終了処理
	_iFile.close();
	successEnd();
	exit(0);
	//return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const exception& e) {
	kgError err(e.what());
	errorEnd(err);
	return 1;
}catch(char * er){
	kgError err(er);
	errorEnd(err);
	return 1;
}catch(...){
	kgError err("unknown error");
	errorEnd(err);
	return 1;
}
