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
// kgvjoin.cpp ベクトル要素の参照結合クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <map>
#include <kgvjoin.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgVjoin::kgVjoin(void)
{
	_name    = "kgVjoin";
	_version = "###VERSION###";

	#include <help/en/kgvjoinHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgvjoinHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgVjoin::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,m=,n=,vf=,f=,K=,delim=,-A",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_mFile.open(_args.toString("m=",true),_env,_nfn_i);
	_iFile.read_header();
	_mFile.read_header();

	// vf= 項目引数のセット
	vector< vector<kgstr_t> >  vs = _args.toStringVecVec("vf=","%:",2,true);
	_vfField.set(vs, &_iFile,_fldByNum);

	// f= 項目引数のセット
	vector<kgstr_t>  vsf = _args.toStringVector("f=",true);
	if(vsf.size()!=1){ throw kgError("f= takes just one item "); }
	_fField.set(vsf, &_mFile,_fldByNum);

	// n= 項目引数のセット
	_nullVal = _args.toString("n=",false);

	// delim= 項目引数のセット
	kgstr_t s_d = _args.toString("delim=",false);
	if(s_d.empty()){	
		_delim=' ';
	}else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= takes 1 byte charactor (" << s_d << ")";
		throw kgError(ss.str());
	}else{
		_delim=*(s_d.c_str());
	}
	
	// K= 項目引数のセット
	vector<kgstr_t>  vs2 = _args.toStringVector("K=",true);
	if(vs2.size()!=1){ throw kgError("K= takes just one item "); }
	_mkField.set(vs2, &_mFile,_fldByNum);	

	// -A（追加）フラグセット
	_add_flg 		= _args.toBool("-A");

	_delimstr[0] =_delim;
	_delimstr[1] ='\0';

}

void kgVjoin::output_n(char *str,bool eol)
{
	*_outstr = '\0'; 

	strcpy(_outstr,str);
	int len=strlen(_outstr);
	
	vector<char*> eachItem = splitToken( str ,_delim);
	for(vector<char*>::iterator j=eachItem.begin(); j!=eachItem.end(); j++){
		if(_itmSet.find(*j)!=_itmSet.end()){
			len += ( strlen(_delimstr)+strlen(_itmSet[*j].c_str()) );
			if(len>=KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN");}
			strcat(_outstr,_delimstr);
			strcat(_outstr,_itmSet[*j].c_str());
		}
		else if(!_nullVal.empty()){
			len += ( strlen(_delimstr)+strlen(_nullVal.c_str()) );
			if(len>=KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN");}
			strcat(_outstr,_delimstr);
			strcat(_outstr,_nullVal.c_str());
		}
	}
	if(_assertNullOUT && *_outstr=='\0'){ _existNullOUT = true;}
	_oFile.writeStr(_outstr,eol);
}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgVjoin::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 参照ファイルからitemのhash表を作成する
	while(EOF != _mFile.read() ){
		const char* item = _mFile.getVal(_mkField.num(0));
		const char* taxo = _mFile.getVal(_fField.num(0));
		if(_assertNullKEY && *item=='\0') { _existNullKEY = true; }
		_itmSet[item]=taxo;
	}

	//出力項目名出力 追加 or 置換
	if(_add_flg) { _oFile.writeFldName(_iFile,_vfField,true);}
	else				 { _oFile.writeFldName(_vfField, true);}
	int outsize = _iFile.fldSize();
	if(_add_flg) { outsize += _vfField.size(); }	

	// データ出力
	while(EOF != _iFile.read() ){
		int outcnt=0;
		for(size_t i=0; i<_iFile.fldSize(); i++){
			outcnt++;
			char* str=_iFile.getVal(i);
			if(_add_flg||_vfField.flg(i)==-1){
				_oFile.writeStr(str,outcnt==outsize);
			}
			else{
				if(_assertNullIN && *str=='\0' ) { _existNullIN  = true;}
				output_n(str,outcnt==outsize);
			}
		}
		if(_add_flg){
			for(kgstr_t::size_type i=0 ; i< _vfField.size() ;i++){
				outcnt++;
				if(_assertNullIN && *_iFile.getVal(_vfField.num(i))=='\0') { _existNullIN  = true;}
				output_n(_iFile.getVal(_vfField.num(i)),outcnt==outsize);
			}
		}
	}

	// 終了処理
	_iFile.close();
	_mFile.close();
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
