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
// Keybreak.cpp キーブレーク情報付加クラス
// =============================================================================
#include <cstdio>
#include <vector>
#include <kgConfig.h>
#include <kgkeybreak.h>
#include <kgError.h>
#include <kgVal.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgKeybreak::kgKeybreak(void)
{
	_name    = "kgkeybreak";
	_version = "###VERSION###";

	#include <help/en/kgkeybreakHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgkeybreakHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgKeybreak::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("a=,i=,o=,k=,s=,-q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_KEY|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
	_iFile.read_header();
	_oFile.setPrecision(_precision);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",true);

	// a=は２項目足りないときは自動的保管され多い場合は無視される
	_addstr.resize(2);
	_addstr[0]="top";
	_addstr[1]="bot";
	vector<kgstr_t> vs_a = _args.toStringVector("a=",false);
	size_t alim = vs_a.size();
	if ( alim > 2 ) { alim=2; }
	for(size_t i=0 ; i< alim ;i++){
		if(vs_a[i].empty()){ continue; }
		_addstr[i]=vs_a[i];
	}

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	vector<kgstr_t> vss = _args.toStringVector("s=",false);

	if( !seqflg ){
		vector<kgstr_t> vsk	= vs;
		vsk.insert(vsk.end(),vss.begin(),vss.end());
		sortingRun(&_iFile,vsk);
	}

	_kField.set(vs,  &_iFile,_fldByNum);

}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgKeybreak::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
  _oFile.writeFldName(_iFile, _addstr);

	// break flg
	bool top = true;
	bool bot  = false;
	bool kb    = true;
	vector<kgstr_t> output(2);

	while(_iFile.read()!=EOF){
	
		if(kb){ top = true;}
		else	{ top = false;}

		if( _iFile.keybreak() )	{ 
			bot = true;
			kb   = true;
		}
		else{
			bot = false;
			kb   = false;
		}

		if(_iFile.begin()){
			kb   = true;
			continue;
		}
		// アウトプット
		if(top) { output[0]="1";}
		else		{ output[0]="";}
		if(bot) { output[1]="1";}
		else		{ output[1]="";}
		if(_assertNullOUT && output[0].size()==0 && output[1].size()==0){ _existNullOUT = true;}

		_oFile.writeFld(_iFile.getOldFld(),_iFile.fldSize(),&output);
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理(メッセージ出力,thread pipe終了通知)
	th_cancel();
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
