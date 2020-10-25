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
// kgrand.h 乱数値項目の追加クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <ctime>
#include <kgrand.h>
#include <kgError.h>
#include <kgMethod.h>
#include <boost/random.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgRand::kgRand(void)
{
	_name    = "kgrand";
	_version = "###VERSION###";

	#include <help/en/kgrandHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgrandHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgRand::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("S=,min=,max=,a=,i=,o=,k=,-int,-q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_KEY);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_oFile.setPrecision(_precision);
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	//キー指定が有ればキー内では全行同じ乱数
	_B_flg = false;
	if(vs.size() != 0){
		_B_flg = true;
	}

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
	}
	else	{ _seed = static_cast<unsigned long>(aToSizeT(S_s.c_str()));}

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
		throw kgError("min= or max=  must be specified with -int.");	
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

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if(!seqflg && !vs.empty()){ sortingRun(&_iFile,vs);}
	_kField.set(vs,  &_iFile,_fldByNum);

}
// -----------------------------------------------------------------------------
// 実数用出力
// -----------------------------------------------------------------------------
void kgRand::writeFld(char** fld ,int size ,double val) 
{
	for(int i=0; i<size; i++){
		if(fld==NULL) 	_oFile.writeStr( ""    	  , false );
		else 					 	_oFile.writeStr( *(fld+i), false );
	}
	_oFile.writeDbl( val, true );
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgRand::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
	_oFile.writeFldName(_iFile, _aField);

	//実数版
	if(!_int_rand){
		uniform_real<> dst_r(_min,_max);
		variate_generator< mt19937,uniform_real<> > *rand_r=NULL;
		double val=0;
		while(_iFile.read()!=EOF){
			if((_iFile.status() & kgCSV::End )) break;
			//keybreakあるいは最初は乱数生成エンジン生成
			if( _iFile.begin() ){
				rand_r = new variate_generator< mt19937,uniform_real<> > (mt19937(_seed),dst_r);
			}
			if( _iFile.keybreak() ){
				if(!_B_flg){
					if(rand_r){ delete rand_r;}
					rand_r = new variate_generator< mt19937,uniform_real<> > (mt19937(_seed),dst_r);
				}
			}
			if( _iFile.begin() ||  _iFile.keybreak() || !_B_flg ){
				val=(*rand_r)();
			}
			writeFld(_iFile.getNewFld() ,_iFile.fldSize() ,val);
		}
		if(rand_r){ delete rand_r ;}
	}
	else{//整数版
		uniform_int<> dst_i(_min,_max);
		variate_generator< mt19937,uniform_int<> > *rand_i=NULL;
		int val=0;
		while(_iFile.read()!=EOF){
			//keybreakあるいは最初は乱数生成エンジン生成
			if((_iFile.status() & kgCSV::End )) break;
			if( _iFile.begin() ){
				rand_i = new variate_generator< mt19937,uniform_int<> > (mt19937(_seed),dst_i);
			}
			if( _iFile.keybreak() ){
				if(!_B_flg){
					if(rand_i){ delete rand_i;}
					rand_i = new variate_generator< mt19937,uniform_int<> > (mt19937(_seed),dst_i);
				}
			}
			if( _iFile.begin() ||  _iFile.keybreak() || !_B_flg ){
				val=(*rand_i)();
			}
			_oFile.writeFld(_iFile.getNewFld() ,_iFile.fldSize() ,val,false);
		}
		if(rand_i){ delete rand_i;}
	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理(メッセージ出力,thread pipe終了通知)
	th_cancel();
	_iFile.close();
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
