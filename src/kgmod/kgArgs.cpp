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
// ============================================================================
// kgArgs.cpp コマンドライン引数クラス
// ============================================================================
#include <sstream>
#include <kgArgs.h>
#include <kgMethod.h>
#include <string.h>
#include <cstdlib>
//#include <unistd.h>


using namespace kglib;
using namespace std;

// -----------------------------------------------------------------------------
// key,valを引数として追加 ex. key="f=" val="a,b,c" ,  key="--quiet" val=""
// 同じkeywordがなければ登録，あればエラー
// -----------------------------------------------------------------------------
void kgArgs::add(const string& key, const kgstr_t& val) 
{
	if(keyVal_.find(key)==keyVal_.end()){
		keyVal_[key]=val;
	}else{
		ostringstream ss;
		ss << "same keywords are specified: " << key;
		throw kgError(ss.str());
	}
}
// -----------------------------------------------------------------------------
// 引数strをkeywordとvalを分けて引数として追加 str="f=a,b,c" , str="--quiet"
//  実際の登録は add(const string& key, const kgstr_t& val)
// -----------------------------------------------------------------------------
void kgArgs::add(string str) 
{
	string key;
	string::size_type pos;
	kgstr_t val;
	kgstr_t s=str;

	//引数分割 ( delim: - or = )
	if( 0==s.compare(0,1,"-") ){
		key=s;
		val="";
	}else if ( kgstr_t::npos != (pos=s.find("=") ) ){
		key=s.substr(0,pos+1);
		val=s.substr(pos+1);
	}else{
		ostringstream ss;
		ss << "invalid argument: " << str;
		throw kgError(ss.str());
	}
	add(key,val);
}
// -----------------------------------------------------------------------------
// 引数追加処理
// main関数のargc,argvによる登録
//  keywordとその値をmapクラス(連想配列)に格納する
//  実際の登録は add(const string& key, const kgstr_t& val)
// -----------------------------------------------------------------------------
void kgArgs::add(size_t argc, const char *argv[])
{
	for(size_t i=1; i<argc; i++){
		if(strlen(argv[i])> KG_ARGLEN_MAX){
			ostringstream ss;
			ss << "too long argument is specified (" << KG_ARGLEN_MAX << ")";
			throw kgError(ss.str());
		}
		add( argv[i] );
	}
}
// -----------------------------------------------------------------------------
// keyValからkeyWordを探し，見つかればその文字列を返す．
// 見つからなければ""を返す．
// f=a,b,c  get("f=") -> a,b,c
// -----------------------------------------------------------------------------
kgstr_t kgArgs::get(const string& keyWord, bool mandatory, bool nullNG) const 
{
	map<string,kgstr_t>::const_iterator it=keyVal_.find(keyWord);
	if(it!=keyVal_.end()){
		if(nullNG){
			if(it->second.length()==0){
				ostringstream ss;
				ss << "parameter " << keyWord << " cannot take null value";
				throw kgError(ss.str());
			}
		}
		return it->second;
	}else{
		if(mandatory){
			ostringstream ss;
			ss << "parameter " << keyWord << " is mandatory";
			throw kgError(ss.str());
		}
	}
	return "";
}

// -----------------------------------------------------------------------------
// keyValからkeyWordがあればtrue無ければfalse
// -----------------------------------------------------------------------------
bool kgArgs::find(const string& keyWord)
{
	return keyVal_.find(keyWord) != keyVal_.end();
}
// -----------------------------------------------------------------------------
// keyWordで指定されたオプションを探しあればtrueをなければfalseを返す
// keyVal="... -r ..." keyWord="-r" -> bool trueに変換
// -----------------------------------------------------------------------------
bool kgArgs::toBool(const string& keyWord) const
{
	if(keyVal_.find(keyWord)!=keyVal_.end()){
		return true;
	}else{
		return false;
	}
}
// -----------------------------------------------------------------------------
// keyWordで指定された引数を探しその値をkgstr_tで返す
// keyVal="... i=input.csv ..." keyWord="i=" -> kgstr_t input.csvに変換
// keywordが見付からない場合、もしくは値がない場合は""を返す
// -----------------------------------------------------------------------------
kgstr_t kgArgs::toString(const string& keyWord, bool mandatory, bool nullNG) const
{
	return get(keyWord, mandatory, nullNG);
}
// -----------------------------------------------------------------------------
// keyWordで指定された引数を探しその値をkgstr_t vectorで返す
// keyVal="... f=aa,bb,cc ..." keyWord="f=" -> vector aa,bb,ccに変換
// keywordが見付からない場合、もしくは値がない場合は""を返す
// -----------------------------------------------------------------------------
vector<kgstr_t> kgArgs::toStringVector(const string& keyWord, bool mandatory, bool nullNG) const
{
	vector<kgstr_t> vstr;
	kgstr_t val=get(keyWord, mandatory, nullNG);
	if(! val.empty()){ vstr = splitToken(val, ',');}
	return vstr;
}
// -----------------------------------------------------------------------------
// toStringVectorの返り値をsetにしたもの
// -----------------------------------------------------------------------------
set<kgstr_t> kgArgs::toStringSet(const string& keyWord, bool mandatory, bool nullNG) const
{
	vector<kgstr_t> vstr=toStringVector(keyWord, mandatory, nullNG);
	set<kgstr_t>    sstr=vector2set(vstr);
	return sstr;
}
// -----------------------------------------------------------------------------
// 2次元ベクトルのセット
// 区切り文字が2つあるが，第1要素の区切りはカンマ固定．
// 第2要素の区切りは delimで指定する．
// 例) f=aaa:AAA,bbb,ccc:CCC  (aaa,bbb,ccc),(AAA,,CCC)
// -----------------------------------------------------------------------------
vector< vector<kgstr_t> > kgArgs::toStringVecVec(const string& keyWord, const wchar_t delim, unsigned int rowSize, bool mandatory, bool nullNG) const
{
	kgstr_t val=get(keyWord, mandatory, nullNG);
	if(! val.empty()){
		vector< vector<kgstr_t> > vvs;
		vvs = transVector(splitToken2(val,',',delim), rowSize);
		return vvs;
	}else{
		vector< vector<kgstr_t> > vvs(rowSize);
		return vvs;
	}
}
// -----------------------------------------------------------------------------
// 2次元ベクトルのセット(delimがkgstr_tバージョン)
// 区切り文字が2つあるが，第1要素の区切りはカンマ固定．
// 第2要素の区切りは delimで指定する．
// 例) f=aaa:AAA,bbb,ccc:CCC  (aaa,bbb,ccc),(AAA,,CCC)
// -----------------------------------------------------------------------------
vector< vector<kgstr_t> > kgArgs::toStringVecVec(const string& keyWord, const kgstr_t delim, unsigned int rowSize, bool mandatory, bool nullNG) const
{
	kgstr_t val=get(keyWord, mandatory, nullNG);
	if(! val.empty()){
		vector< vector<kgstr_t> > vvs;
		vvs = transVector(splitToken2(val,',',delim), rowSize);
		return vvs;
	}else{
		vector< vector<kgstr_t> > vvs(rowSize);
		return vvs;
	}
}
// -----------------------------------------------------------------------------
// 使用可能パラメータ以外があるかチェック
// strで使用可能パラメータを指定する
// addCommonArgsよって共通使用可能パラメータを変更する
// -----------------------------------------------------------------------------
void kgArgs::paramcheck(const char *cstr, int addCommonArgs) 
{
	/*使用可能パラメータを分割してセット*/
	/*
	string str(cstr);
	if(! str.empty()){
  	string::size_type prv=0;
  	string::size_type pos=0;
  	string::size_type end=str.size();
  	while(1){
    	if(end==pos || str[pos] == '\0'){
      	_available.insert(str.substr(prv, pos-prv));
 				break;
			}
			else if(str[pos] == ','){
      	_available.insert(str.substr(prv, pos-prv));
				prv = ++pos;
			}else{
				pos++;
			}
		}
  }*/
  
  const char *p = cstr;
  const char *prv = cstr;
  while(*p){
  	if(*p == ','){
      _available.insert(string(prv, p - prv));
      prv = p+1;
  	}
  	p++;
  }
  if(p>prv){ _available.insert(string(prv, p - prv)); }
  
  

	// 共通項目のセット
	// tmpPath(tempディレクトリ), nfn(1行目が項目行でないflag)
	// nfno(項目行を出力しないflag) precision(数値出力の有効桁数) x(項目番号指定)
	if(addCommonArgs & COMMON){
  	_available.insert("tmpPath=");
  	_available.insert("-nfn");
  	_available.insert("-nfno");
  	_available.insert("precision=");
  	_available.insert("-x");
  	_available.insert("-rp");
	}
	// ASSERT関係
		if(addCommonArgs & IODIFF){
	  _available.insert("-assert_diffSize");
	}
	if(addCommonArgs & NULL_KEY){
	  _available.insert("-assert_nullkey");
	}
	if(addCommonArgs & NULL_IN){
	  _available.insert("-assert_nullin");
	}
	if(addCommonArgs & NULL_OUT){
	  _available.insert("-assert_nullout");
	}

	if(addCommonArgs & NULL_OUT){
	  _available.insert("-assert_nullout");
	}
	_available.insert("-params");

	if(keyVal_.find("-params")!=keyVal_.end()){
		set<string>::iterator i;
		for(i=_available.begin(); i!=_available.end(); i++){
			cout << *i << endl;
		}
		_exit(0); 

	}
	// セットされたパラメータと使用可能パラメータにあるかチェック
	for(map<string,kgstr_t>::const_iterator i=keyVal_.begin() ;i!=keyVal_.end();i++){
		if(_available.find(i->first)==_available.end()){
			ostringstream ss;	
			ss << "unknown parameter " << i->first;
			throw kgError(ss.str());
		}
	}
}
// -----------------------------------------------------------------------------
// 全引数を一つの文字列に変換する(コマンドライン出力用)
// -----------------------------------------------------------------------------
string kgArgs::to_s(void) const
{
	ostringstream ss;
	map<string,kgstr_t>::const_iterator i;
	for(i=this->keyVal_.begin(); i!=this->keyVal_.end(); i++){
		ss << " " << i->first << i->second;
	}
	return ss.str();
}

