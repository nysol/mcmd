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
// kgcut.cpp 項目の選択クラス
// =============================================================================
#include <cstdio>
#include <vector>
#include <kgcut.h>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgCut::kgCut(void)
{
	_name    = "kgcut";
	_version = "###VERSION###";

	#include <help/en/kgcutHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcutHelp.h>
	#endif
}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgCut::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,-r,-nfni",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN);

	// -nfniを指定した場合、-xも指定されていることにする
	bool nfniflg = _args.toBool("-nfni");
	if(nfniflg){ 
		_nfn_i =nfniflg; 
		_fldByNum = true;
	}

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
	_oFile.open(_args.toString("o=",false), _env,_nfn_o, _rp );
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);
	_fField.set(vvs, &_iFile, _fldByNum);

	// -r 出力反転フラグ
	_reverse = _args.toBool("-r");
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void kgCut::writeFldName(const vector<int>& fld,bool reverse) 
{
	if( _oFile.noFldName( ) ) return;
	if(fld.size()<=0){ throw kgError("no output fields"); }

	vector<kgstr_t> outfld;
	for(size_t i=0; i<fld.size(); i++){
		kgstr_t oName;
		if(!reverse){ oName =  _fField.attr(i); }
		if( oName.empty()){ oName=_iFile.fldName(fld.at(i)); } // second項目名がない時
		oName.append(_iFile.sortParaStr(fld.at(i)));
		outfld.push_back(oName);
	}
	_oFile.writeFldNameCHK(outfld);
} 


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCut::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 出力項目番号のセット
	vector<int> oField;
	if(! (_iFile.end() && _nfn_o) ){
		if(_reverse){
			for(size_t i=0; i<_iFile.fldSize(); i++){
				if( _fField.flg(i)==-1 ) oField.push_back(i);
			}
		}else{
			for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
				oField.push_back(_fField.num(i));
			}
		}
	}
	// 項目名出力
	writeFldName(oField,_reverse);

	// データ出力
	while( EOF != _iFile.read() ){
		if(_assertNullIN) { 
			if(_iFile.isNull(oField)) { _existNullIN  = true;}
		}
		_oFile.writeFld(_iFile.getFld(),&oField);
	}

	// 終了処理
	_iFile.close();
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
