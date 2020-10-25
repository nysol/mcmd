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
// kgnewrand.cpp 乱数値項目の新規作成クラス
// =============================================================================
#include <sstream>
#include <ctime>
#include <kgnewrand.h>
#include <kgError.h>
#include <boost/random.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost;
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgNewrand::kgNewrand(void)
{
	_name    = "kgnewrand";
	_version = "###VERSION###";

	#include <help/en/kgnewrandHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgnewrandHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgNewrand::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("S=,min=,max=,a=,o=,l=,-int");

	// 出力ファイルオープン
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);

	// a= 項目引数のセット
	_aField = _args.toString("a=",false);
	if(_aField.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}

	//乱数の種
	kgstr_t S_s = _args.toString("S=",false);
	if(S_s.empty())	{
		// 乱数の種生成（時間）
		posix_time::ptime now = posix_time::microsec_clock::local_time();
		posix_time::time_duration nowt = now.time_of_day();
		_seed = static_cast<unsigned long>(nowt.total_microseconds());
	}else	{ 
		_seed = static_cast<unsigned long>(aToSizeT(S_s.c_str()));
	}

	_int_rand = _args.toBool("-int");

	//乱数の最小値(min)
	kgstr_t min_s = _args.toString("min=",false);
	if(min_s.empty())	{ _min = 0;}
	else	{ _min = atoi(min_s.c_str());}

	//乱数の最大値(max)
	kgstr_t max_s = _args.toString("max=",false);
	if(max_s.empty())	{ _max = INT_MAX;}
	else	{ _max = atoi(max_s.c_str());}

	// エラーチェック
	if(!_int_rand&&(!min_s.empty()||!max_s.empty())){
		throw kgError("min= or max= must be specified with -int.");	
	}

	if(!_int_rand){
		_min=0;
		_max=1;
	}


	//最小値最大値のチェック
	if(_min>_max){
		ostringstream ss;
		ss << "min= > max= [" << _min << ">" << _max << "]" ;
		throw kgError(ss.str());
	}	

	kgstr_t s_l =  _args.toString("l=",false);
	if(s_l.empty()){
		_line = 10;
	}else{
		_line = aToSizeT(s_l.c_str()) ; 
	}

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgNewrand::run(void) try 
{
	// パラメータセット＆出力ファイルオープン
	setArgs();

	// 項目名の出力
	_oFile.writeFldName(_aField);

	//実数版
	if(!_int_rand){
		uniform_real<> dst_r(_min,_max);
		variate_generator< mt19937,uniform_real<> > rand_r(mt19937(_seed),dst_r);
		// データ出力
		for(size_t i=0;i<_line;i++){	
			_oFile.writeDbl(rand_r(),true);
		}
	}
	else{
		//乱数生成エンジン
		uniform_int<> dst(_min,_max);
		variate_generator< mt19937,uniform_int<> > rand_m(mt19937(_seed),dst); 

		// データ出力
		for(size_t i=0;i<_line;i++){	
			_oFile.writeInt(rand_m(),true);
		}
	}

	// 終了処理
	_oFile.close();
	successEnd();
	return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const std::exception& e) {
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
