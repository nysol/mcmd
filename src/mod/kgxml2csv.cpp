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
// =============================================================================
// kgsum.cpp 行集計(合計)クラス
// =============================================================================
#include <cstdio>
#include <vector>

#include <kgConfig.h>
#include <kgxml2csv.h>
#include <kgError.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// ----------------------------------------------
// k=のキーに入ったならば1を返す。その他は0。
// ----------------------------------------------
bool matchKey(XmlKey& key, string& currentPath){
  //if(0==key.path.compare(0,key.length,currentPath)) return(true);
//cerr << "key=" << key.path << ", cp=" << currentPath << " : compare=" << key.path.compare(currentPath) << endl;
	if(0==key.path.compare(currentPath)) return(true);
  return(false);
}

// ----------------------------------------------
// f=の要素にマッチしているかどうかを判定し、項目数文のbool vectorを返す。
// ----------------------------------------------
vector<bool> matchFld(XmlFld& fld, XmlKey& key, string& currentPath){
	vector<bool> flag(fld.cnt,false);
//cerr << "&&&&& start matchFld" << endl;

	for(int i=0; i<fld.cnt; i++){
//cerr << "&& i=" << i << endl;
//cerr << "&& currentPath=" << currentPath << ", fld.element=" << fld.element.at(i) << ", key.length=" << key.length << endl;
		if(fld.element.at(i)[0]=='/'){ // ----- 絶対パスの場合 ( f=/a/b )
			if( 0==fld.element.at(i).compare(currentPath) ){
//cerr << "&& compare match0\n";
				flag.at(i)=true;
			}
		}else{                         // ----- 相対パスの場合 ( f=a/b )
			if(currentPath.size()>=key.length){
				const char* relPos=currentPath.c_str()+key.length;
				if(*relPos=='/') relPos++;
//cerr << "&& cat=" << relPos << endl;
				if( 0==fld.element.at(i).compare(relPos) ){
//cerr << "&& compare match1 " << flag.size() << ", fld.cnt=" << fld.cnt << endl;
					flag.at(i)=true;
				}
			}
		}
	}
//cerr << "&& end matchFld" << endl;
	return flag;
}

// ----------------------------------------------
// データ上の属性配列attsとユーザが指定した属性名attNameを比較し
// データ配列に存在すれば、その「属性名の値」を返す。
// a="x" b="y"の属性は attsに["a","x","b","y"]のように
// 属性名と値のペアでフラットな配列に格納されている。
// ----------------------------------------------
char *getAttVal(string& attName, char **atts) {
  int i;

  if(atts==NULL) return(NULL);

  i=0;
  while(1){
    if( *(atts+i)==NULL ){
			return(NULL);
		}
    if( 0==attName.compare(*(atts+i)) ){
      return(*(atts+i+1));
    }
    i=i+2;
  }
}

// ----------------------------------------------
// fldDatをCSV出力
// ----------------------------------------------
void printDat(XmlState *state){
//cerr << "printDat\n";
	vector<kgstr_t>& fldDat      = *state->fldDat;
	state->oFile->writeFld(NULL,0,&fldDat);
}

void showFlag(XmlState *state){
	XmlFld& fld = *state->fld;
	cerr << "fld.in: ";
	for(size_t i=0; i<fld.in.size(); i++){
		cerr << fld.in.at(i) << " ";
	}
	cerr << endl;
}

//----------------------------------------------------------------------------
// SAX ハンドラー
//----------------------------------------------------------------------------
//############## start_element
void kgXml2csv::start_element(XmlState *state, char *element, char **atts){

	(*(state->iRecNo))++; // 入力件数カウントアップ

	XmlKey&          key         = *state->key;
	XmlFld&          fld         = *state->fld;
	string&          currentPath = *state->currentPath;
	vector<kgstr_t>& fldDat      = *state->fldDat;

	// 現在のノードパスを更新*/
	currentPath+="/";
	currentPath+=element;

	// k=のキーに入っていなければkeyに入ったかどうか検査
	if(!key.in){
		if(::matchKey(key, currentPath)){
			key.in=true;
		}
	}

	// f=で指定した要素にマッチするかどうか
	vector<bool> isFld=::matchFld(fld, key, currentPath);

	// 以下、データのセット
	for(int i=0; i<fld.cnt; i++){
		// start_elementでは、開始タグ行だけでカタのつくf=項目のみ処理(テキストはstart_charactorsにて)
		if(!isFld.at(i)) continue;

		// 「f=要素@属性」指定の場合
		if(fld.attribute.at(i).size()>0){
			char *attVal=::getAttVal(fld.attribute.at(i),atts);
			if( attVal!=NULL ){
				if(fld.option.at(i)=='f') fldDat.at(i)="1";
				else                      fldDat.at(i)=attVal;
			}

		// 「f=要素」指定の場合
		}else{
			fldDat.at(i)=""; // ここでクリア
			if(fld.option.at(i)=='f'){
				fldDat.at(i)="1";
			}
			// 要素内テキスト指定の場合(<a>text</a>)はstart_characterハンドラにてセットする
			// 同じ要素が出て来たときのために、前のデータをクリアする
    }
  }

	// f=で指定した要素の内側にいるかどうかフラグ(start_characterハンドラでtextを集めるため)
	for(size_t i=0; i<isFld.size(); i++){
		if(!fld.in.at(i)) fld.in.at(i)=isFld.at(i);
	}
  state->level++;
}

//############## end_element
void kgXml2csv::end_element(XmlState *state, char *element)
{
	string&          currentPath = *state->currentPath;
	XmlKey&          key         = *state->key;
	XmlFld&          fld         = *state->fld;
	vector<kgstr_t>& fldDat      = *state->fldDat;

	// f=で指定の要素から出るのか？(currentPathを更新する前に実行)
	vector<bool> isFld=::matchFld(fld, key, currentPath);

	// f=で指定した要素の内側から出るとinフラグをfalseにセット
	for(size_t i=0; i<isFld.size(); i++){
		if(isFld.at(i)){
			fld.in.at(i)=false;
		}
	}
	// このend_elementでキーを出た場合、データ出力＆初期化
	if(key.in && ::matchKey(key, currentPath)){
		key.in=false;

		::printDat(state); //データ出力

		// f=で指定した要素のうち、その要素から出たfldDatのみ初期化する
		for(size_t i=0; i<isFld.size(); i++){
			if(!fld.in.at(i)){
				fldDat.at(i)="";
			}
		}
	}

	// 現在のノードパスを更新(最後の/以降を消去)
	size_t pos=currentPath.find_last_of('/');
	currentPath=currentPath.substr(0,pos);

	state->level--;
}

//############## start_characters
void kgXml2csv::start_characters(XmlState *state, xmlChar *chars, int len)
{
	XmlFld& fld             = *state->fld;
	vector<kgstr_t>& fldDat = *state->fldDat;

	for(int i=0; i<fld.cnt; i++){
		// 1) f=で指定した要素の内側に入っている、
		// 2) かつ要素内容の指定であり属性指定でない、
		// 3) かつオプション%fでない
		// 場合に項目値として要素内テキストを追記していく
		// その時spaceと制御文字は出力しない。
		if(fld.in.at(i) && fld.attribute.at(i).size()==0 && fld.option.at(i)!='f'){
			for(int j=0; j<len; j++){
				unsigned char c=*((unsigned char*)chars+j);
				if(c>0x20 && c!=0x7f){ // spaceと制御文字以外を追加
					fldDat.at(i).append(1,c);
				}
			}
		}
	}
}

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgXml2csv::kgXml2csv(void)
{
	_name    = "kgxml2csv";
	_version = "###VERSION###";

	_iRecNo=0;

	_currentPath=""; // currentPathの初期化
	_state.level       = 0;
	_state.args        = &_args;
	_state.key         = &_key;
	_state.fld         = &_fld;
	_state.currentPath = &_currentPath;
	_state.fldDat      = &_fldDat;
	_state.oFile       = &_oFile;
	_state.iRecNo      = &_iRecNo;

	#include <help/en/kgxml2csvHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgxml2csvHelp.h>
	#endif


}

// -----------------------------------------------------------------------------
// パラメータ設定
// -----------------------------------------------------------------------------
void kgXml2csv::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=");

	// 入出力ファイルオープン
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
	_oFile.setPrecision(_precision);

	// SAXのイベントハンドラーの登録(NULLは何もしない)
	_SAXFunctions.internalSubset       =NULL;
	_SAXFunctions.isStandalone         =NULL;
	_SAXFunctions.hasInternalSubset    =NULL;
	_SAXFunctions.hasExternalSubset    =NULL;
	_SAXFunctions.resolveEntity        =NULL;
	_SAXFunctions.getEntity            =NULL;
	_SAXFunctions.entityDecl           =NULL;
	_SAXFunctions.notationDecl         =NULL;
	_SAXFunctions.attributeDecl        =NULL;
	_SAXFunctions.elementDecl          =NULL;
	_SAXFunctions.unparsedEntityDecl   =NULL;
	_SAXFunctions.setDocumentLocator   =NULL;
	_SAXFunctions.startDocument        =NULL;
	_SAXFunctions.endDocument          =NULL;

	_SAXFunctions.startElement         =(startElementSAXFunc)start_element;
	_SAXFunctions.endElement           =(endElementSAXFunc)end_element;
	_SAXFunctions.reference            =NULL;
	_SAXFunctions.characters           =(charactersSAXFunc) start_characters;
	_SAXFunctions.ignorableWhitespace  =NULL;
	_SAXFunctions.processingInstruction=NULL;
	_SAXFunctions.comment              =NULL;
	_SAXFunctions.warning              =NULL;
	_SAXFunctions.error                =NULL;
	_SAXFunctions.fatalError           =NULL;
	_SAXFunctions.cdataBlock           =NULL;
	_SAXFunctions.externalSubset       =NULL;

	// xml入力ファイル名の設定
	_fname=_args.toString("i=",false);
	if(_fname.size()==0){
		_fname="/dev/stdin";
	}

	// k= 項目引数のセット
	_key.path   = _args.toString("k=",true,true); // mandatory, nullNG
	_key.in     =  false;
	_key.length = _key.path.size();
	if(_key.path.at(0)!='/'){
		throw kgError("key XML path (k=) must be start with root '/'."); 
	}

	// f=で指定された項目の設定
	// ex) f=element@att%f:name,element2@att2:name2

	// 新項目名 :の後ろ
	vector<vector<kgstr_t> > vv1 = _args.toStringVecVec("f=",':',2,true);
	_fld.field = vv1.at(1);
	_fld.cnt = vv1.at(0).size();

	// :の前を次々に分割していく
	vector<kgstr_t>::iterator str;
	for(str=vv1.at(0).begin(); str!=vv1.at(0).end(); str++){
		vector<kgstr_t> v1;
		vector<kgstr_t> v2;

		                v1 = splitToken(*str,'%');
		if(v1.size()>0) v2 = splitToken(v1.at(0),'@');

		// オプション %の後ろ
		if(v1.size()>1) _fld.option.push_back(v1.at(1).c_str()[0]);
		else            _fld.option.push_back('\0');

		// 属性 @の後ろ
		if(v2.size()>1) _fld.attribute.push_back(v2.at(1));
		else            _fld.attribute.push_back("");

		// 要素名 @の前
		if(v2.size()>0) _fld.element.push_back(v2.at(0));
		else            _fld.element.push_back("");
	}

	// 新項目名が指定されていなければエラー
	//   要素名+属性名を新項目名として登録することも考えられるが今回は見送り
	for(size_t i=0; i<_fld.field.size(); i++){
		if(_fld.field.at(i)==""){
			throw kgError("new field name must be specified"); 
		}
	}

	// fld.in,fldDatの初期化
	for(int i=0; i<_fld.cnt; i++){
		_fldDat.push_back("");
		_fld.in.push_back(false);
	}
}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgXml2csv::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名の出力
  if(!_nfn_o){
		_oFile.writeFldNameCHK(_fld.field);
	}

	// SAX前処理
	_ctxt=(xmlParserCtxtPtr)xmlCreateFileParserCtxt(_fname.c_str());
	_state.ctxt=_ctxt;
	if(!_ctxt){
		throw kgError("not xml"); 
	}
	_ctxt->sax=&_SAXFunctions;
	_ctxt->userData=&_state;

	// parse実行
	xmlParseDocument(_ctxt);

	// 後処理
	_ctxt->sax=NULL;
	xmlFreeParserCtxt(_ctxt);

	// 終了処理
	_oFile.close();
	successEnd();
	return 0;

// 例外catcher
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
	kgError err("unknown error" );
	errorEnd(err);
	return 1;
}
