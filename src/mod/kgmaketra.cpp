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
// kg2cross.cpp クロス集計クラス(N vs 1)
// =============================================================================
#include <cstdio>
#include <iostream>
#include <sstream>
#include <kgmaketra.h>
#include <kgError.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgMaketra::kgMaketra(void)
{
	_name    = "kgmaketra";
	_version = "###VERSION###";

	#include <help/en/kg2crossHelp.h>	
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kg2crossHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgMaketra::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,s=,k=,i=,o=,-q");

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vk  = _args.toStringVector("k=",false);

	// f= 項目引数のセット
	vector<kgstr_t> vf = _args.toStringVector("f=",true);

	// s= 項目引数のセット	%nr
	vector<kgstr_t> vs = _args.toStringVector("s=",false);

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }


	if(!seqflg && (!vk.empty()||!vs.empty()) ){ 
		vector<kgstr_t> vsk	= vk;
		vsk.insert(vsk.end(),vs.begin(),vs.end());
		sortingRun(&_iFile,vsk);
	}
	_kField.set(vk, &_iFile, _fldByNum);
	_fField.set(vf, &_iFile, _fldByNum);

}

int kgMaketra::run(void) 
{

	try {
		// パラメータセット＆入出力ファイルオープン
		setArgs();

		// 入力ファイルにkey項目番号をセットする．
		_iFile.setKey(_kField.getNum());

		while( EOF != _iFile.read() ){
			if( _iFile.keybreak() ){
				_oFile.writeEol();
				if((_iFile.status() & kgCSV::End )) break;
			}
			for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
				_oFile.writeStr(_iFile.getNewVal(_fField.num(i)));
				_oFile.writeStr(" ");
			}
		}
		//ASSERT keynull_CHECK
		th_cancel();

		_iFile.close();
		_oFile.close();
		successEnd();
		return 0;

	}catch(kgError& err){
		runErrEnd();
		errorEnd(err);
	}catch (const exception& e) {
		runErrEnd();
		kgError err(e.what());
		errorEnd(err);
	}catch(char * er){
		runErrEnd();
		kgError err(er);	
		errorEnd(err);
	}catch(...){
		runErrEnd();
		kgError err("unknown error" );
		errorEnd(err);
	}
	return 1;

}