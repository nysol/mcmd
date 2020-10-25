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
// kgselrand.h ランダムに行選択クラス
// =============================================================================
#include <cstdio>
#include <ctime>
#include <vector>
#include <kgConfig.h>
#include <kgselrand.h>
#include <kgError.h>
#include <kgMethod.h>
#include <boost/random.hpp>
#include <kgTempfile.h>

using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSelrand::kgSelrand(void)
{
	_name    = "kgselrand";
	_version = "###VERSION###";
	
	#include <help/en/kgselrandHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgselrandHelp.h>
	#endif
	
}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSelrand::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,u=,S=,k=,c=,p=,-B,-q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_KEY);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	kgstr_t ufile = _args.toString("u=",false);
	if(ufile.empty()){
		_elsefile=false;
	}
	else {
		_elsefile=true;
		_uFile.open(ufile,_env,_nfn_o);
	}		
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",false);

	//乱数の種
	kgstr_t S_s = _args.toString("S=",false);
	if(S_s.empty())	{
		//乱数の種生成（時間）
		time_t  long_time;                               
		struct tm     *nt;
		time(&long_time); 
		nt = localtime(&long_time); 
 		_seed=static_cast<unsigned long>(nt->tm_hour*10000+nt->tm_min*100+nt->tm_sec);  	
	}
	else	{ _seed = static_cast<unsigned long>(atoi(S_s.c_str()));}

	//パーセント	
	kgstr_t p_s = _args.toString("p=",false);
	if(p_s.empty())	{	_percent=0;}
	else	{
		_percent = atof(p_s.c_str());
		_cnt_flg=false;
	}

	//件数
	kgstr_t c_s = _args.toString("c=",false);
	if(c_s.empty())	{
		_cnt=1;
	} else	{
		_cnt = atoi(c_s.c_str());
		_cnt_flg=true;
	}

	// -B キー単位
	_b_flg = _args.toBool("-B");

	// エラー処理
	if(_b_flg  && vs_k.size()==0){
		throw kgError("-B must be specified with k=");
	}

	if(p_s.empty() && c_s.empty()){
		throw kgError("must specify either c= or p=");
  }

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg && !vs_k.empty()){ sortingRun(&_iFile,vs_k);}

	_kField.set(vs_k, &_iFile,_fldByNum);

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSelrand::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名出力
	_oFile.writeFldName(_iFile);
	if(_elsefile){ _uFile.writeFldName(_iFile); }

	//乱数生成エンジン
	uniform_int<> dst(0,INT_MAX);
	variate_generator< mt19937,uniform_int<> > rand_m(mt19937(_seed),dst); 

	//ファイルオープン
	kgCSVout otmpFile;
	kgstr_t tmpfName;
	kgTempfile tempFile;
	if(_b_flg&&_iFile.isFifo()){ 
		tempFile.init(_env);
		tmpfName = tempFile.create();
		otmpFile.open(tmpfName,_env,true);
		otmpFile.writeFldName(_iFile);
	}

	// 入力、参照ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());
	if(_b_flg){
		int total=0;
		while(_iFile.read()!=EOF){
			if( _iFile.keybreak() ){//keybreakしたらカウント
				total++;
				//ENDなら終了
				if((_iFile.status() & kgCSV::End )) break;
			}			
			//入力がパイプの場合はファイル出力する
			if(otmpFile.isOpend()){
				otmpFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
			}
		}
		if(otmpFile.isOpend()){			
			otmpFile.close();
			_iFile.close();
			_iFile.open(tmpfName,_env,true);
			_iFile.read_header();
			_iFile.setKey(_kField.getNum());
		}
		else{
			_iFile.seekTop();
		}
		//ここから出力処理
		bool output =false;
		int out_cnt;
		if(_cnt_flg) out_cnt=_cnt;
		else         out_cnt=(int)((_percent/(double)100)*(double)total);
		while(_iFile.read()!=EOF){
			if(_iFile.begin()){
				if( (rand_m()%total) < out_cnt ){	output = true;}
				total--;
				if(output){out_cnt--;}			
			}
			if( _iFile.keybreak() ){
				//ENDなら終了
				if((_iFile.status() & kgCSV::End )) break;
				output = ( (rand_m()%total) < out_cnt );
				total--;
				if(output){out_cnt--;}
			}
			if(output){
					_oFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
			}
			else{
					if(_elsefile){ _uFile.writeFld(_iFile.fldSize(),_iFile.getNewFld()); }
			}
		}
	}
	else{
		while(_iFile.blkset()!=EOF){
			//出力行数決定
			int total = _iFile.blkrecNo();
			int out_cnt;
			if(_cnt_flg) out_cnt=_cnt;
			else         out_cnt=(int)((_percent/(double)100)*(double)total);
 	   if(out_cnt>total) out_cnt=total;
			while(_iFile.blkread() != EOF){
				if( (rand_m()%total) < out_cnt ){
					_oFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld());
					out_cnt--;
				}
				else{
					if(_elsefile){ _uFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld()); }
     	 }
				total--;
			}
		}
	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理
	th_cancel();
	_iFile.close();
	_oFile.close();
	if(_elsefile){ _uFile.close();}
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
