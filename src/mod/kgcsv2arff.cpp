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
// kgcsv2arff.cpp CSV→wekaのデータフォーマット変換
// =============================================================================
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <kgcsv2arff.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// 文字ソート
// -----------------------------------------------------------------------------
namespace {
	class strsort{
		public:
			bool operator()(char* t1,char* t2) const {
				return strcmp(t1,t2) < 0 ;			
			}
	};
}
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgCsv2arff::kgCsv2arff(void)
{
	_name    = "kgcsv2arff";
	_version = "###VERSION###";

	#include <help/en/kgcsv2arffHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcsv2arffHelp.h>
	#endif
	
}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------

void kgCsv2arff::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("d=,D=,n=,s=,i=,o=,T=",kgArgs::COMMON|kgArgs::NULL_IN);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",true), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_iFile.read_header();

	// d= 項目引数のセット
	vector<kgstr_t> vd = _args.toStringVector("d=",false);
	_dField.set(vd, &_iFile, _fldByNum);

	// n= 項目引数のセット
	vector<kgstr_t> vn = _args.toStringVector("n=",false);
	_nField.set(vn, &_iFile, _fldByNum);

	// s= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("s=",false);
	_sField.set(vs, &_iFile, _fldByNum);

	// D= 項目引数のセット
	vector< vector<kgstr_t> > vvd = _args.toStringVecVec("D=","%:",2,false);
	_DField.set(vvd, &_iFile, _fldByNum);

	// t= 項目引数のセット
	_titles =_args.toString("T=",false);

	if(_DField.size()==0&&_nField.size()==0&&_sField.size()==0&&_dField.size()==0){
		throw kgError("must be specify at least one of parameters n=,d=,s=,D=.");
	}

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCsv2arff::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	//d=の指定があるときのみカテゴリデータを作成するために一度全データ読み込む
	vector< set<char*,strsort> > categoryfld(_dField.size());
	if(_dField.size()){
		while(EOF != _iFile.read()){
			for(unsigned int i=0;i<_dField.size();i++){
				if(categoryfld.at(i).find( _iFile.getVal(_dField.num(i)) ) == categoryfld.at(i).end()){
					char *str = new char[KG_MAX_STR_LEN];
					_d_stock_p.push_back(str);
					strcpy(str,_iFile.getVal(_dField.num(i)));
					categoryfld.at(i).insert(str);
				}
			}
		}
		_iFile.seekTop();
	}
	
	//arffヘッダ出力
  _oFile.writeStrNdq("@RELATION\t");
  if(_titles.empty()){
    _oFile.writeStr("By_KGMOD");
  }else{
  	string::size_type pos = 0;
  	string sp = " ";
  	string ub = "_";
  	string rtitle = _titles;
		while(pos = rtitle.find(sp, pos), pos != string::npos) {
			rtitle.replace(pos, sp.length(), ub);
			pos += sp.length();
    }
		_oFile.writeStr(rtitle.c_str());
  } 
  _oFile.writeStrNdq("\n\n");

  // arff attribute(string)
	if(_sField.size()){
		for(unsigned int i=0;i<_sField.size();i++){
			_oFile.writeStrNdq("@ATTRIBUTE\t");
			_oFile.writeStr(_sField.name(i).c_str());
     _oFile.writeStrNdq("\t");
     _oFile.writeStr("string",true);
    }
  }

  // arff attribute(date) 
	if(_DField.size()){
		for(unsigned int i=0;i<_DField.size();i++){
			_oFile.writeStrNdq("@ATTRIBUTE\t");
			_oFile.writeStr(_DField.name(i).c_str());
			_oFile.writeStrNdq("\t");
			if( _DField.attr(i).find("t") != kgstr_t::npos){
				_oFile.writeStr("date yyyyMMddHHmmss",true);
			}
			else{
				_oFile.writeStr("date yyyyMMdd",true);
			}
    }
  }
  
  // arff attribute(numeric)
	if(_nField.size()){
		for(unsigned int i=0;i<_nField.size();i++){
			_oFile.writeStrNdq("@ATTRIBUTE\t");
			_oFile.writeStr(_nField.name(i).c_str());
			_oFile.writeStrNdq("\t");
			_oFile.writeStr("numeric",true);
		}
  }
  
  // arff attribute(categorical)
	if(_dField.size()){
		for(unsigned int i=0;i<_dField.size();i++){
			_oFile.writeStrNdq("@ATTRIBUTE\t");
			_oFile.writeStr(_dField.name(i).c_str());
			_oFile.writeStrNdq("\t");
			_oFile.writeStr("{");
			for(set<char*,strsort>::iterator j=categoryfld.at(i).begin();j!=categoryfld.at(i).end();j++){
				if(j==categoryfld.at(i).begin()) { 
					_oFile.writeStr(*j); 
				}else{
					_oFile.writeDlm();
					_oFile.writeStr(*j);
				}
			}
			_oFile.writeStr("}",true);
    }
  }
	_oFile.writeEol();

	//データ部出力
	_oFile.writeStr("@DATA",true);
	while(EOF != _iFile.read()){
		bool firstFlg=true;

		//string
		if(_sField.size()){
			for(unsigned int i=0;i<_sField.size();i++){
				if(firstFlg){firstFlg=false;}
				else{	_oFile.writeDlm();}				
				if(*(_iFile.getVal(_sField.num(i)))=='\0'){
					if(_assertNullIN) { _existNullIN  = true;}
					_oFile.writeStr("?");
				}else{
					_oFile.writeStr(_iFile.getVal(_sField.num(i)));
				}
	    }
	  }

		//date
		if(_DField.size()){
			for(unsigned int i=0;i<_DField.size();i++){
				if(firstFlg){ firstFlg=false;}
				else				{	_oFile.writeDlm();}	
				char *strtmp =_iFile.getVal(_DField.num(i));
				int len =strlen(strtmp);
				if(*strtmp=='\0'){
					if(_assertNullIN) { _existNullIN  = true;}
					_oFile.writeStr("?");
				}else{
					if( _DField.attr(i).find("t") != kgstr_t::npos){
						if(len==14){_oFile.writeStr(strtmp);}
						else { _oFile.writeStr("?");}	
					}else{
						if(len==8) {_oFile.writeStr(strtmp);}
						else 			 { _oFile.writeStr("?");}	
					}
				}
	    }
	  }

		//numric
		if(_nField.size()){
			for(unsigned int i=0;i<_nField.size();i++){
				if(firstFlg){firstFlg=false;}
				else{	_oFile.writeDlm();}				
				if(*(_iFile.getVal(_nField.num(i)))=='\0'){
					if(_assertNullIN) { _existNullIN  = true;}
					_oFile.writeStr("?");
				}else{
					_oFile.writeStr(_iFile.getVal(_nField.num(i)));
				}
	    }
	  }

		//categorical
		if(_dField.size()){
			for(unsigned int i=0;i<_dField.size();i++){
				if(firstFlg) {firstFlg=false;}
				else				 {	_oFile.writeDlm();}				
				if(*(_iFile.getVal(_dField.num(i)))=='\0'){ 
					if(_assertNullIN) { _existNullIN  = true;}
					_oFile.writeStr("?");
				}
				else { _oFile.writeStr(_iFile.getVal(_dField.num(i)));}
			}
		}
		_oFile.writeEol();
	}
	// 終了処理
	_iFile.close();
	_oFile.close();
	successEnd();
	return 0;

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
