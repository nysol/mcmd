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
// kgsetstr.cpp 固定文字列項目の追加クラス
// =============================================================================
#include <cstdio>
#include <kgsetstr.h>
#include <kgError.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgSetstr::kgSetstr(void)
{
	_name    = "kgsetstr";
	_version = "###VERSION###";

	#include <help/en/kgsetstrHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsetstrHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSetstr::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("v=,a=,i=,o=",kgArgs::COMMON|kgArgs::IODIFF);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_iFile.read_header();

	// a=,v= 項目引数のセット
	_aField = _args.toStringVector("a=",false);
	if(_aField.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}

	_vField = _args.toStringVector("v=",true);
	// _vFieldのサイズが0でエラーになっていない場合は
	// "v="と指定しているはず。
	if(_vField.size()==0){ _vField.push_back("");}

	// k=とK=の数があっている化チェック
	if((_aField.size()!=_vField.size())&& _nfn_o==false){
		throw kgError("item size of parameters a= and v= must be same");
	}
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSetstr::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名の出力
	_oFile.writeFldName(_iFile, _aField);

	// データ出力
	while( EOF != _iFile.read() ){
		_oFile.writeFld(_iFile.getFld(),_iFile.fldSize(),&_vField);
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
