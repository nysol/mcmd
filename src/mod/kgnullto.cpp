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
// kgnullto.cpp NULL値の置換クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <kgnullto.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgNullto::kgNullto(void)
{
	_name    = "kgnullto";
	_version = "###VERSION###";

	#include <help/en/kgnulltoHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgnulltoHelp.h>
	#endif


}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgNullto::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,O=,v=,-A,-p",kgArgs::COMMON|kgArgs::IODIFF);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_iFile.read_header();

	// -A（追加）,-p(前行文字列での置換) フラグセット
	_add_flg 		= _args.toBool("-A");
	_prv_flg 		= _args.toBool("-p");

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);
	_fField.set(vvs, &_iFile,_fldByNum);

	// v= 置換文字列
	_vField = _args.toString("v=",false);

	// O= NULL値以外の置換文字列
	_OField = _args.toString("O=",false);
	_exp_nul = !_OField.empty();

	if(_prv_flg && !_vField.empty()){ throw kgError("-p cannot be specified with v=");}
	if(!_prv_flg && _vField.empty()){ throw kgError("-p or v= must be specified"); }
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgNullto::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	//出力項目名出力 追加 or 置換
	if(_add_flg) { _oFile.writeFldName(_iFile,_fField,true);}
	else				 { _oFile.writeFldName(_fField, true);}

	//	fieldの項目番号をセット
	vector<int> field_lst = _fField.getNum();

	// 前行保存用配列(-p用)
	vector<string> prvRec(_fField.size());

	// OUT領域確保:f=項目数分
	kgAutoPtr2<char*> o_stock_ap;
	try {
		o_stock_ap.set( new char*[_fField.size()] ); 
	} catch(...) {
		throw kgError("memory allocation error ");
	}
	char** stock = o_stock_ap.get();

	while( EOF != _iFile.read() ){
		for(size_t i=0 ; i<_fField.size();i++){
			char* val=_iFile.getVal(_fField.num(i));
			if(*val=='\0'){
				if(_prv_flg){ *(stock+i) = const_cast<char*>(prvRec.at(i).c_str());}
				else				{ *(stock+i) = const_cast<char*>(_vField.c_str());}
			}else{
				if(_exp_nul){ *(stock+i) = const_cast<char*>(_OField.c_str());}
				else				{ *(stock+i) = val;}
				//前回値としてセット
				if(_prv_flg){ prvRec.at(i)=val;}	
			}
		}
		if(_add_flg){
			_oFile.writeFld(_iFile.getFld(),_iFile.fldSize(),stock,_fField.size());		
		}else{
			_oFile.writeFld(_iFile.getFld(),_fField.getFlg_p(),stock);
		}
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
