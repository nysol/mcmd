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
// kgmvstats.cpp 移動窓の統計量の算出クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cfloat>
#include <kgmvstats.h>
#include <kgError.h>
#include <kgVal.h>
#include <kgMethod.h>
#include <kgConfig.h>

#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost;



// =============================================================================
// kgMvBase 
// =============================================================================
//--------------------------------------------------------------
// データの更新
// _valのデータを更新する_sposが最初に一周したとき_fullをtureにする
// -----------------------------------------------------------------------------
void kgmvstats_::kgMvBase::update(vector<kgVal>& inp)
{
		for(size_t i=0; i<_fsize; i++){
			if(!_val.at(i).at(_spos).null()) _stock_size.at(i)--;
			_val.at(i).at(_spos).set(&inp.at(i)); 
			if(!_val.at(i).at(_spos).null()) _stock_size.at(i)++;
		}
		pos_inc();
		if(_spos==0){ _filled = true; }
}
//--------------------------------------------------------------
// データの初期化(ポジション,fullフラグ、データの初期化)
//--------------------------------------------------------------
void kgmvstats_::kgMvBase::clear()
{
	for(vector<double>::size_type i=0;  i < _val.size(); i++){
		for(vector<double>::size_type j=0;  j < _val[i].size(); j++){
			_val.at(i).at(j).type('N');
		}
		_stock_size.at(i)=0;
	}
	_spos=0;
	_filled=false;
}

// =============================================================================
// kgMvSum　集計 
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvSum::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	for(vector<double>::size_type i = 0 ;i < _sumary.size() ;i++){
		_sumary.at(i) = _sumary.at(i) - kgMvBase::get(i) + inp.at(i).r(); 
		rls.at(i).r(_sumary.at(i));
	}
	kgMvBase::update(inp);
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvstats_::kgMvSum::clear()
{
	for(vector<double>::size_type i = 0 ;i < _sumary.size() ;i++){
		_sumary.at(i) = 0; 
	}
	kgMvBase::clear();
}
// =============================================================================
// kgMvMean 算術平均
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvMean::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvSum::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(stocksize(i)>0){
			_mean.at(i)= rls.at(i).r()/stocksize(i);
			rls.at(i).r(_mean.at(i));
		}
		else{
			rls.at(i).null(true);		
		}
	}
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvstats_::kgMvMean::clear()
{
	for(vector<double>::size_type i = 0 ;i < _mean.size() ;i++){
		_mean.at(i) = 0; 
	}
	kgMvSum::clear();
}

// =============================================================================
// kgMvDevsq 二乗差
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvDevsq::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvMean::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(!rls.at(i).null()){
			vector<kgVal>& v = gets(i);
			double t=0;
			for(size_t j = 0 ;j < v.size() ;j++){
				if(!v.at(j).null()){
					t += ( (v.at(j).r()-rls.at(i).r())*(v.at(j).r()-rls.at(i).r()) );
				}
			}
			rls.at(i).r(t);
		}
	}
}
// =============================================================================
// kgMvVar 分散
// =============================================================================
//--------------------------------------------------------------
// データの分散
//--------------------------------------------------------------
void kgmvstats_::kgMvVar::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvDevsq::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(stocksize(i)>0){
			rls.at(i).r(rls.at(i).r()/stocksize(i));
		}else{
			rls.at(i).null(true);		
		}
	}	
}
// =============================================================================
// kgMvUvar 分散 (不偏推定値)
// =============================================================================
//--------------------------------------------------------------
// データの分散
//--------------------------------------------------------------
void kgmvstats_::kgMvUvar::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvDevsq::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(stocksize(i)>1){
			rls.at(i).r(rls.at(i).r()/(stocksize(i)-1));
		}else{
			rls.at(i).null(true);		
		}
	}	
}
// =============================================================================
// kgMvSd 標準偏差
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvSd::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvDevsq::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(stocksize(i)>0){
			rls.at(i).r(sqrt(rls.at(i).r()/stocksize(i)));
		}else{
			rls.at(i).null(true);		
		}
	}	
}
// =============================================================================
// kgMvUsd 標準偏差 (不偏推定値)
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvUsd::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvDevsq::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(stocksize(i)>1){
			rls.at(i).r(sqrt(rls.at(i).r()/(stocksize(i)-1)));
		}else{
			rls.at(i).null(true);		
		}
	}	
}

// =============================================================================
// kgMvCv 変動係数
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvCv::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvSd::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		if(stocksize(i)>0){
			rls.at(i).r( 100.0 * rls.at(i).r()/ kgMvMean::get(i));
		}else{
			rls.at(i).null(true);		
		}
	}	
}
// =============================================================================
// kgMvMin 最小値
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvMin::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvBase::update(inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		vector<kgVal> v = gets(i);
		double min=DBL_MAX;
		for(size_t j = 0 ;j < v.size() ;j++){
			if(!v.at(j).null()){
				if(min > v.at(j).r()){ min = v.at(j).r(); }
			}
		}
		if(min==DBL_MAX){ rls.at(i).null(true);}
		else            { rls.at(i).r(min);}
	}
}
// =============================================================================
// kgMvMin 最大値
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvMax::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvBase::update(inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		vector<kgVal> v = gets(i);
		double max=-DBL_MAX;
		for(size_t j = 0 ;j < v.size() ;j++){
			if(!v.at(j).null()){
				if(max < v.at(j).r()){ max = v.at(j).r(); }
			}
		}
		if(max==-DBL_MAX){ rls.at(i).null(true);}
		else             { rls.at(i).r(max);}
	}
}
// =============================================================================
// kgMvRane 範囲
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvRange::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvBase::update(inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		vector<kgVal> v = gets(i);
		double min=  DBL_MAX;
		double max= -DBL_MAX;
		for(size_t j = 0 ;j < v.size() ;j++){
			if(!v.at(j).null()){
				if(min > v.at(j).r()){ min = v.at(j).r(); }
				if(max < v.at(j).r()){ max = v.at(j).r(); }
			}
		}
		if(min==DBL_MAX){ rls.at(i).null(true);}
		else            { rls.at(i).r(max-min);}
	}
}
// =============================================================================
// kgMvSkew 歪度
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvSkew::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvMean::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		size_t cnt =stocksize(i);
		if( cnt>0 ){
			vector<kgVal> v = gets(i);
			double t2,t3;
			t2=0; t3=0;
			for(size_t j = 0 ;j < v.size() ;j++){
				if(!v.at(j).null()){
					double dv = v.at(j).r()-rls.at(i).r();
					t2 += ( dv*dv );
					t3 += ( dv*dv*dv );
				}
			}
			if(t2==0){ rls.at(i).null(true);}		
			else     { rls.at(i).r( t3 / (pow(t2/cnt,1.5) * cnt) );}
		}else{
			rls.at(i).null(true);		
		}
	}
}
// =============================================================================
// kgMvUskew 歪度 (不偏推定値)
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvUskew::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvMean::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		size_t cnt =stocksize(i);
		if(cnt > 2 ){
			vector<kgVal> v = gets(i);
			double t2,t3;
			t2=0; t3=0;
			for(size_t j = 0 ;j < v.size() ;j++){
				if(!v.at(j).null()){
					double dv = v.at(j).r()-rls.at(i).r();
					t2 += ( dv*dv );
					t3 += ( dv*dv*dv );
				}
			}
			if(t2==0) { rls.at(i).null(true);}
			else      { rls.at(i).r( t3 / pow(t2/(cnt-1),1.5) * cnt / ((cnt-1)*(cnt-2))   ); }
		}
		else{ rls.at(i).null(true);}
	}
}
// =============================================================================
// kgMvKurt 尖度
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvKurt::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvMean::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		size_t cnt =stocksize(i);
		if(cnt > 0 ){
			vector<kgVal> v = gets(i);
			double t2,t4;
			t2=0; t4=0;
			for(size_t j = 0 ;j < v.size() ;j++){
				if(!v.at(j).null()){
					double dv = v.at(j).r()-rls.at(i).r();
					t2 += ( dv*dv );
					t4 += ( dv*dv*dv*dv );
				}
			}
			if(t2==0){ rls.at(i).null(true);}
			else     { rls.at(i).r( t4 / (pow(t2/cnt,2) * cnt) -3.0); }
		}
		else{
			rls.at(i).null(true);		
		}
	}
}
// =============================================================================
// kgMvUkurt 尖度 (不偏推定値)
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvstats_::kgMvUkurt::calc(vector<kgVal>& rls ,vector<kgVal>& inp)
{
	kgMvMean::calc(rls,inp);
	for(vector<kgVal>::size_type i = 0 ;i < rls.size() ;i++){
		size_t cnt =stocksize(i);
		if( cnt > 3 ){
			vector<kgVal> v = gets(i);
			double t2,t4;
			t2=0; t4=0;
			for(size_t j = 0 ;j < v.size() ;j++){
				if(!v.at(j).null()){
					double dv = v.at(j).r()-rls.at(i).r();
					t2 += ( dv*dv );
					t4 += ( dv*dv*dv*dv );
				}
			}
			if(t2==0){ rls.at(i).null(true);}
			else{
				rls.at(i).r( t4/(pow(t2/(cnt-1),2))*cnt*(cnt+1)/(cnt-1)/(cnt-2)/(cnt-3)
											- 3.0*(cnt-1)*(cnt-1)/(cnt-2)/(cnt-3));		
			}
		}
		else{
			rls.at(i).null(true);		
		}
	}
}

//--------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgMvstats::kgMvstats(void){

	_name    = "kgmvstats";
	_version = "###VERSION###";

	#include <help/en/kgmvstatsHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgmvstatsHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgMvstats::setArgs(void){
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,c=,skip=,t=,s=,-q,-n",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
  _oFile.setPrecision(_precision);
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vs_f = _args.toStringVecVec("f=",':',2,true,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// t= の値をセット
	kgstr_t strT=_args.toString("t=",true);
	_term = aToSizeT(strT.c_str());

	kgstr_t strS=_args.toString("skip=",false);
	if(strS.empty()){
		_skip = _term-1;
	}else{
		_skip = atoi(strS.c_str());
		if(_skip>=_term){ _skip = _term -1; }
	}
	// c= 計算方法のセット
	_c_type = _args.toString("c=", true);
    	 	 if(_c_type=="sum"   ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvSum  >(),lambda::_1,lambda::_2); }
	  else if(_c_type=="mean"  ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvMean >(),lambda::_1,lambda::_2); }
		else if(_c_type=="devsq" ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvDevsq>(),lambda::_1,lambda::_2); }
		else if(_c_type=="var"   ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvVar  >(),lambda::_1,lambda::_2); }
		else if(_c_type=="uvar"  ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvUvar >(),lambda::_1,lambda::_2); }
		else if(_c_type=="sd"    ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvSd   >(),lambda::_1,lambda::_2); }
		else if(_c_type=="usd"   ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvUsd  >(),lambda::_1,lambda::_2); }
		else if(_c_type=="cv"    ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvCv   >(),lambda::_1,lambda::_2); }
		else if(_c_type=="min"   ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvMin  >(),lambda::_1,lambda::_2); }
		else if(_c_type=="max"   ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvMax >(),lambda::_1,lambda::_2); }
		else if(_c_type=="range" ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvRange>(),lambda::_1,lambda::_2); }
		else if(_c_type=="skew"  ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvSkew >(),lambda::_1,lambda::_2); }
		else if(_c_type=="uskew" ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvUskew>(),lambda::_1,lambda::_2); }
		else if(_c_type=="kurt"  ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvKurt >(),lambda::_1,lambda::_2); }
		else if(_c_type=="ukurt" ){_function = lambda::bind(lambda::new_ptr<kgmvstats_::kgMvUkurt>(),lambda::_1,lambda::_2); }
	else {
		ostringstream ss;
		ss << "unknown keyword: " << _c_type << ": c=sum|mean|devsq|var|uvar|sd|usd|cv|min|max|range|skew|kurt|uskew|ukurt" << _c_type;
		throw kgError(ss.str());	
	}
	_null = _args.toBool("-n");

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	vector<kgstr_t> vss = _args.toStringVector("s=",false);
	if(!seqflg&&vss.empty()){
		throw kgError("parameter s= is mandatory without -q,-nfn");
	}

	if(!seqflg && (!vs.empty()||!vss.empty())){ 
		vector<kgstr_t> vsk	= vs;
		vsk.insert(vsk.end(),vss.begin(),vss.end());
		sortingRun(&_iFile,vsk);
	}

	_kField.set(vs,  &_iFile,_fldByNum);
	_fField.set(vs_f, &_iFile,_fldByNum);

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgMvstats::run(void) try {

	setArgs();
	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());
	
	// 項目名の出力
  _oFile.writeFldName(_fField, true);

	size_t fldSize=_fField.size();

	// 結果格納変数の領域確保
	vector<kgVal>  result(fldSize ,kgVal('N'));
	vector<kgVal> inpval   (fldSize ,kgVal('N'));
	
	// 計算クラスセット
	kgmvstats_::kgMvBase* kmvb = _function(_term,fldSize);

	while(_iFile.blkset()!=EOF){
		size_t recno =0;
		while(  EOF != _iFile.blkread() ){
			recno++;
			for(size_t i=0; i<fldSize; i++){
				char* str=_iFile.getBlkVal(_fField.num(i));
				if(*str=='\0') { 
					inpval[i].null(true); 
					if(_assertNullIN) { _existNullIN  = true;}
				}
				else{
					inpval[i].r(atof(str));
				}
			}
			kmvb->calc(result,inpval);
			if(recno>_skip){
				if(_null){
					for(size_t i=0; i < result.size() ;i++){
						if(kmvb->isNull(i)){ result.at(i).null(true); }
					}
				}
				if(_assertNullOUT){ 
					for(size_t i=0; i < result.size() ;i++){
						if(result.at(i).null()){ _existNullOUT = true; }
					}
				}				
				_oFile.writeFld(_iFile.getBlkFld(),_fField.getFlg_p(),result);
			}
		}
		kmvb->clear();
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
