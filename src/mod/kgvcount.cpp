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
// kgvcat.cpp ベクトルサイズの計算クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <csignal>
#include <kgvcount.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgVcount::kgVcount(void)
{

	_name    = "kgvcount";
	_version = "###VERSION###";

	#include <help/en/kgvcountHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgvcountHelp.h>
	#endif
	
}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgVcount::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,vf=,delim=",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_iFile.read_header();

	// vf= 項目引数のセット
	vector< vector<kgstr_t> >  vs = _args.toStringVecVec("vf=",':',2,true);
	_vfField.set(vs, &_iFile,_fldByNum);

	// delim指定
	kgstr_t s_d = _args.toString("delim=",false);
	if(s_d.empty()){	
		_delim=' ';
	}else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= takes 1 byte charactor (" <<  s_d << ")";
		throw kgError(ss.str());
	}else{
		_delim=*(s_d.c_str());
	}	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgVcount::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名出力
  _oFile.writeFldName(_iFile,_vfField, true);

	while(EOF != _iFile.read() ){
		_oFile.writeFld(_iFile.fldSize(),_iFile.getFld(),false);
		for(size_t i=0; i<_vfField.size(); i++){
			size_t cnt = cntToken(_iFile.getVal(_vfField.num(i)),_delim,true);
			if(_assertNullIN && cnt==0) { _existNullIN  = true;}
			if(i<_vfField.size()-1){ _oFile.writeSizeT(cnt,false);}
			else                   { _oFile.writeSizeT(cnt,true);	}
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
