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
// kgmvsim.cpp 移動窓の２変数統計量の算出クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cfloat>
#include <kgmvsim.h>
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
// kgMvBase dbl
// =============================================================================
//--------------------------------------------------------------
// データの更新
// _valのデータを更新する_sposが最初に一周したとき_fullをtureにする
// -----------------------------------------------------------------------------
void kgmvsim_::kgMvBase_dbl::update(vector<double>& inp)
{
		for(size_t i=0; i<_fsize; i++){
			_val.at(i).at(_spos)=inp[i];
		}
		pos_inc();
		if(_spos==0){ _filled = true; }
}
//--------------------------------------------------------------
// データの初期化(ポジション,fullフラグ、データの初期化)
//--------------------------------------------------------------
void kgmvsim_::kgMvBase_dbl::clear()
{
	for(vector<double>::size_type i=0;  i < _val.size(); i++){
		for(vector<double>::size_type j=0;  j < _val[i].size(); j++){
			_val.at(i).at(j)=0;
		}
	}
	_spos=0;
	_filled=false;
}
// =============================================================================
// kgMvBase bool
// =============================================================================
//--------------------------------------------------------------
// データの更新
// _valのデータを更新する_sposが最初に一周したとき_fullをtureにする
// -----------------------------------------------------------------------------
void kgmvsim_::kgMvBase_bool::update(vector<bool>& inp)
{
		for(size_t i=0; i<_fsize; i++){
			_val.at(i).at(_spos)=inp[i];
		}
		pos_inc();
		if(_spos==0){ _filled = true; }
}
//--------------------------------------------------------------
// データの初期化(ポジション,fullフラグ、データの初期化)
//--------------------------------------------------------------
void kgmvsim_::kgMvBase_bool::clear()
{
	for(vector<bool>::size_type i=0;  i < _val.size(); i++){
		for(vector<bool>::size_type j=0;  j < _val[i].size(); j++){
			_val.at(i).at(j)=false;
		}
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
void kgmvsim_::kgMvSum::calc(vector<double>& inp)
{
	for(vector<double>::size_type i = 0 ;i < _sumary.size() ;i++){
		_sumary.at(i) = _sumary.at(i) - kgMvBase_dbl::get(i) + inp.at(i); 
	}
	kgMvBase_dbl::update(inp);
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvsim_::kgMvSum::clear()
{
	for(vector<double>::size_type i = 0 ;i < _sumary.size() ;i++){
		_sumary.at(i) = 0; 
	}
	kgMvBase_dbl::clear();
}
// =============================================================================
// kgMvMean 算術平均
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvsim_::kgMvMean::calc(vector<double>& inp)
{
	kgMvSum::calc(inp);
	size_t cnt = stocksize();
	for(vector<kgVal>::size_type i = 0 ;i < inp.size() ;i++){
		_mean.at(i)= get_sum(i) / cnt;
	}
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvsim_::kgMvMean::clear()
{
	for(vector<double>::size_type i = 0 ;i < _mean.size() ;i++){
		_mean.at(i) = 0; 
	}
	kgMvSum::clear();
}
// =============================================================================
// kgMvValCount　 値ごとカウント
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvsim_::kgMvValCount::calc(vector<double>& inp)
{
	for(vector<double>::size_type i = 0 ;i < _vcount.size() ;i++){

		if(isfilled()){
			double oldv = kgMvBase_dbl::get(i);
			map<double,int>::iterator it = _vcount[i].find(oldv);
			if(it==_vcount[i].end()){ throw kgError("data check error");}
			if(it->second==1) { _vcount[i].erase(oldv);}
			else						  { it->second--;}
		}

		if(_vcount[i].find(inp[i])!=_vcount[i].end())	{ _vcount[i][inp[i]]++;}
		else														    					{ _vcount[i][inp[i]]=1;}
		
	}
	kgMvBase_dbl::update(inp);
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvsim_::kgMvValCount::clear()
{
	for(vector<double>::size_type i = 0 ;i < _vcount.size() ;i++){
		_vcount.at(i).clear(); 
	}
	kgMvBase_dbl::clear();
}
// =============================================================================
// kgMvRank 順位 
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvsim_::kgMvRank::calc(vector<double>& inp)
{
	kgMvValCount::calc(inp);
	for(vector<double>::size_type i = 0 ;i < _rank.size() ;i++){
		map<double,int> &vc_map = get_valc(i);
		double vcount=0;
		for(map<double,int>::iterator j=vc_map.begin(); j!=vc_map.end(); j++){
			int c=j->second;
			_rank[i][j->first] =  vcount+(c+1.0)/2.0;
			vcount += c;
		}
	}
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvsim_::kgMvRank::clear()
{
	for(vector<double>::size_type i = 0 ;i < _rank.size() ;i++){
		_rank.at(i).clear(); 
	}
	kgMvValCount::clear();
}
// =============================================================================
// kgMvTrueCnt (True カウント)
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvsim_::kgMvTrueCnt::calc(vector<bool>& inp)
{
	for(vector<double>::size_type i = 0 ;i < _tcount.size() ;i++){
		double add=0;
		double sub=0;
		if(kgMvBase_bool::get(i)==true){ sub=1;}
		if(inp.at(i)==true){ add=1;}
		_tcount.at(i) = _tcount.at(i) - sub + add; 
	}
	kgMvBase_bool::update(inp);
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvsim_::kgMvTrueCnt::clear()
{
	for(vector<double>::size_type i = 0 ;i < _tcount.size() ;i++){
		_tcount.at(i) = 0; 
	}
	kgMvBase_bool::clear();
}
// =============================================================================
// kgMvBoolMatrix (BOOL MATRIX)
// =============================================================================
//--------------------------------------------------------------
// 計算
//--------------------------------------------------------------
void kgmvsim_::kgMvBoolMatrix::calc(vector<char*>& inp)
{
	bool x,y;
	char *strx =inp[0];
	char *stry =inp[1];
	vector<bool> input(2,false);

	if(*strx=='\0')					{ x=false;}
	else if(*(strx+1)!='\0'){ x=false;}
	else if(*strx=='0')			{ x=false;}
	else if(*strx=='1')			{ x=true; }			
	else										{ x=false;}
	input[0]=x;
	
	if(*stry=='\0')					{ y=false;}
	else if(*(stry+1)!='\0'){ y=false;}
	else if(*stry=='0')			{ y=false;}
	else if(*stry=='1')			{ y=true; }			
	else										{ y=false;}
	input[1]=y;
	
	bool x_b = kgMvBase_bool::get(0);
	bool y_b = kgMvBase_bool::get(1);
	
	if(isfilled()){
		     if( x_b && y_b ){ _matrix[3] -= 1;}
		else if( x_b        ){ _matrix[2] -= 1;}
		else if(        y_b ){ _matrix[1] -= 1;}
		else                 { _matrix[0] -= 1;}
	}
	     if( x && y ){ _matrix[3] += 1;}
	else if( x      ){ _matrix[2] += 1;}
	else if(      y ){ _matrix[1] += 1;}
	else             { _matrix[0] += 1;}

	kgMvBase_bool::update(input);
}
//--------------------------------------------------------------
// データの初期化
//--------------------------------------------------------------
void kgmvsim_::kgMvBoolMatrix::clear()
{
	for(vector<double>::size_type i = 0 ;i < _matrix.size() ;i++){
		_matrix.at(i) = 0; 
	}
	kgMvBase_bool::clear();
}
//--------------------------------------------------------------
// MATRIX値取得
//--------------------------------------------------------------
double kgmvsim_::kgMvBoolMatrix::getMat(int x,int y)
{
	if(x==-1 && y==-1){
		return _matrix[0]+_matrix[1]+_matrix[2]+_matrix[3];
	}
	else if(x==-1){
		return _matrix[0*2+y] + _matrix[2+y];
	}
	else if(y==-1){
		return _matrix[x*2]+_matrix[x*2+1];
	}
	else {
		return _matrix[x*2+y];
	}
	return 0;
}
//--------------------------------------------------------------
// MATRIX確率取得
//--------------------------------------------------------------
double kgmvsim_::kgMvBoolMatrix::getMatP(int x,int y,int x_D,int y_D)
{
	double nnum=getMat(x,y);
	double dnum=getMat(x_D,y_D);
	return nnum/dnum;
}

// ============================================================================
// SIM関数関連クラス
// ============================================================================
// =============================================================================
// COVAR クラス 
// =============================================================================
void kgmvsim_::kgMvSimFunc_Covar::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(2,0);
	for(size_t i=0;i<2;i++){
		if(*inp[i]=='\0')	{ input[i]=0; }
		else							{ input[i]=atof(inp[i]);}
	}
	_data.calc(input);
	vector<double> v_x = _data.gets(0);
	vector<double> v_y = _data.gets(1);
	double t=0;
	size_t cnt = _data.stocksize();
	for(size_t j = 0 ;j < cnt ;j++){
		t += ( (v_x[j]-_data.get_mean(0))*(v_y[j]-_data.get_mean(0)) );
	}
	if(cnt>1)	{ rls.r(t/cnt); } 
	else			{ rls.null(true);}
}
//--------------------------------------------------------------
// UCOVAR
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Ucovar::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(2,0);
	for(size_t i=0;i<2;i++){
		if(*inp[i]=='\0')	{ input[i]=0; }
		else							{ input[i]=atof(inp[i]);}
	}
	_data.calc(input);
	vector<double> v_x = _data.gets(0);
	vector<double> v_y = _data.gets(1);
	double t=0;
	size_t cnt = _data.stocksize();
	for(size_t j = 0 ;j < cnt ;j++){
		t += ( (v_x[j]-_data.get_mean(0))*(v_y[j]-_data.get_mean(1)) );
	}
	if(cnt>2)	{ rls.r(t/(cnt-1)); } 
	else			{ rls.null(true);}
}
//--------------------------------------------------------------
// SPEARMAN
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Spearman::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(2,0);
	for(size_t i=0;i<2;i++){
		if(*inp[i]=='\0')	{ input[i]=DBL_MAX; }
		else							{ input[i]=atof(inp[i]);}
	}
	_data.calc(input);	
	int cnt = _data.stocksize();

	//tx,ty計算
	vector<double> t(2,0);
	for(size_t i=0;i<2;i++){
		map<double,int> &vc_map = _data.get_valc(i);
		for(map<double,int>::iterator j=vc_map.begin(); j!=vc_map.end(); j++){
			double c=j->second;
			if(c>1) { t[i]+=c*c*c-c;}
		}
	}
	for(size_t i=0;i<2;i++){
		t[i]=((cnt*cnt*cnt-cnt)-t[i])/12.0;
	}

	// Σdi^2の計算
	double sum=0;
	for(size_t i=0;i<_data.stocksize();i++){
		double dx = _data.get(0,i);
		double dy = _data.get(1,i);
		double dx_r = _data.getRank(0,dx);
		double dy_r = _data.getRank(1,dy);
		sum += (dx_r - dy_r) * (dx_r - dy_r);
	}		
	if(cnt>1&& t[0]>0 && t[1]>0)	{ rls.r((t[0]+t[1]-sum)/(2*sqrt(t[0]*t[1]))); } 
	else			{ rls.null(true);}
}
//--------------------------------------------------------------
// KENDALL
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_kendall::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(2,0);
	for(size_t i=0;i<2;i++){
		if(*inp[i]=='\0')	{ input[i]=DBL_MAX; }
		else							{ input[i]=atof(inp[i]);}
	}
	_data.calc(input);	
	int cnt = _data.stocksize();

	//tx,ty計算
	vector<double> t(2,0);
	for(size_t i=0;i<2;i++){
		map<double,int> &vc_map = _data.get_valc(i);
		for(map<double,int>::iterator j=vc_map.begin(); j!=vc_map.end(); j++){
			double c=j->second;
			if(c>1) { t[i]+=(c*c-c)/2.0;}
		}
	}

	double pSum=0;
	double qSum=0;
	for(size_t i=0;i<_data.stocksize();i++){
		for(size_t j=0;j<_data.stocksize();j++){
			double d1x = _data.get(0,i);
			double d1y = _data.get(1,i);
			double d2x = _data.get(0,j);
			double d2y = _data.get(1,j);
			
			     if(d1x>d2x && d1y>d2y) { pSum+=1; }
			else if(d1x<d2x && d1y<d2y) { pSum+=1; }
			else if(d1x>d2x && d1y<d2y) { qSum+=1; }
			else if(d1x<d2x && d1y>d2y) { qSum+=1; }
		}
	}		

	if(cnt>1)	{
		double nn=(cnt*cnt-cnt)/2.0;
		if(nn!=t[0] && nn!=t[1]){
			rls.r(
				((pSum-qSum)/2.0)/(sqrt(nn-t[0])*sqrt(nn-t[1]))
			); 
		}else{
			rls.null(true);
		}
	} 
	else{
		rls.null(true);
	}
}
//--------------------------------------------------------------
// Pearson
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Pearson::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(2,0);
	for(size_t i=0;i<2;i++){
		if(*inp[i]=='\0')	{ input[i]=0; }
		else							{ input[i]=atof(inp[i]);}
	}
	_data.calc(input);

	vector<double> v_x = _data.gets(0);
	vector<double> v_y = _data.gets(1);
	double xt=0;
	double yt=0;
	double xyt=0;

	size_t cnt = _data.stocksize();
	for(size_t j = 0 ;j < cnt ;j++){
		xyt += ( (v_x[j]-_data.get_mean(0))*(v_y[j]-_data.get_mean(1)) );
		xt  += ( (v_x[j]-_data.get_mean(0))*(v_x[j]-_data.get_mean(0)) );
		yt  += ( (v_y[j]-_data.get_mean(1))*(v_y[j]-_data.get_mean(1)) );
	}

	if(cnt>1)	{ rls.r(xyt / ( (cnt-1)* sqrt(xt/(cnt-1)) * sqrt(yt/(cnt-1)) ) ); } 
	else			{ rls.null(true);}
	
}
//--------------------------------------------------------------
// EUCLID
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Euclid::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(1,0);
	double x,y;
	if(*inp[0]=='\0') { x=0;}
	else							{ x=atof(inp[0]);}
	if(*inp[1]=='\0') { y=0;}
	else							{ y=atof(inp[1]);}
	input[0] = (x-y)*(x-y);
	_data.calc(input);

	if(_data.stocksize()>0)	{ rls.r( sqrt(_data.get_sum(0)) ); } 
	else										{ rls.null(true);}

}
//--------------------------------------------------------------
// COSINE
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Cosine::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(3,0);
	double x,y;
	if(*inp[0]=='\0') { x=0;}
	else							{ x=atof(inp[0]);}
	if(*inp[1]=='\0') { y=0;}
	else							{ y=atof(inp[1]);}

	input[0] = x * y;
	input[1] = x * x;
	input[2] = y * y;
	_data.calc(input);

	if(_data.stocksize()>0)	{ rls.r( _data.get_sum(0)/ sqrt(_data.get_sum(1)*_data.get_sum(2)) ); } 
	else										{ rls.null(true);}
	
}
//--------------------------------------------------------------
// CITYBLOCK
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_CityBlock::calc(kgVal &rls,vector<char*>& inp)
{
	vector<double> input(1,0);
	double x,y;
	if(*inp[0]=='\0') { x=0;}
	else							{ x=atof(inp[0]);}
	if(*inp[1]=='\0') { y=0;}
	else							{ y=atof(inp[1]);}
	input[0] = fabs(x-y);
	_data.calc(input);

	if(_data.stocksize()>0)	{ rls.r( _data.get_sum(0) ); } 
	else										{ rls.null(true);}
}

//--------------------------------------------------------------
// Hamming
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Hamming::calc(kgVal &rls,vector<char*>& inp)
{
	vector<bool> input(1,false);
	input[0] = ( 0!=strcmp(inp[0],inp[1]) );
	_data.calc(input);

	size_t cnt = _data.stocksize();
	if(cnt>0)	{ rls.r( _data.get_tcnt(0)/cnt ); } 
	else			{ rls.null(true);}
	
}
//--------------------------------------------------------------
// PHI
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Phi::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	double dnum = _data.getMat(1,-1)*_data.getMat(0,-1)*_data.getMat(-1,1)*_data.getMat(-1,0);
	
	if(dnum>0){ 
		rls.r( 
			( _data.getMat(1,1)*_data.getMat(0,0) - _data.getMat(1,0)*_data.getMat(0,1) ) / sqrt(dnum) 
		); 
	} 
	else			{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// CHI
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Chi::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	double dnum = _data.getMat(1,-1)*_data.getMat(0,-1)*_data.getMat(-1,1)*_data.getMat(-1,0);
	double nnum = _data.getMat(-1,-1)*
								( _data.getMat(1,1)*_data.getMat(0,0) - _data.getMat(1,0)*_data.getMat(0,1) )*
								( _data.getMat(1,1)*_data.getMat(0,0) - _data.getMat(1,0)*_data.getMat(0,1) );

	if(dnum>0){ rls.r( nnum/dnum ); } 
	else			{ rls.null(true);}

}
//--------------------------------------------------------------
// JACCARD
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Jaccard::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	double nnum = _data.getMat(1,1);
	double dnum = _data.getMat(1,1)+_data.getMat(0,1)+_data.getMat(1,0);

	if( dnum>0 && nnum>0 ){ rls.r( nnum/dnum ); } 
	else									{ rls.null(true);}

}
//--------------------------------------------------------------
// SUPPORT
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Support::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	double dnum = _data.getMat(-1,-1);

	if(dnum>0){ rls.r( _data.getMat(1,1)/dnum ); } 
	else			{ rls.null(true);}

}
//--------------------------------------------------------------
// LIFT
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Lift::calc(kgVal &rls,vector<char*>& inp)
{

	_data.calc(inp);

	double dnum = _data.getMat(1,-1)*_data.getMat(-1,1);
	
	if(dnum>0){ rls.r( _data.getMat(1,1)*_data.getMat(-1,-1)/dnum ); } 
	else			{ rls.null(true);}

}
//--------------------------------------------------------------
// CONFMAX
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_ConfMax::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		if( _data.getMat(1,-1)==0 || _data.getMat(-1,1)==0){
			rls.null(true);
		}
		else{
			double cp_ab = _data.getMatP(1,1,-1,1);
			double cp_ba = _data.getMatP(1,1,1,-1);
			if(cp_ab>cp_ba)	{ rls.r(cp_ab);}
			else						{ rls.r(cp_ba);}
		}
	}
	else{
		rls.null(true);
	}

}
//--------------------------------------------------------------
// CONFMIN
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_ConfMin::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		if( _data.getMat(1,-1)==0 || _data.getMat(-1,1)==0){
			rls.null(true);
		}
		else{
			double cp_ab = _data.getMatP(1,1,-1,1);
			double cp_ba = _data.getMatP(1,1,1,-1);
			if(cp_ab<cp_ba)	{ rls.r(cp_ab);}
			else						{ rls.r(cp_ba);}
		}
	}
	else{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// YULEQ
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_YuleQ::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		if( _data.getMatP(1,0,-1,-1)==0 || _data.getMatP(0,1,-1,-1)==0){
			rls.r(1);
		}
		else{
			double alpha=(_data.getMatP(1,1,-1,-1)*_data.getMatP(0,0,-1,-1))
										/(_data.getMatP(1,0,-1,-1)*_data.getMatP(0,1,-1,-1));
			rls.r( (alpha-1)/(alpha+1) );
		}
	}
	else{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// YULEY
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_YuleY::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		if( _data.getMatP(1,0,-1,-1)==0 || _data.getMatP(0,1,-1,-1)==0){
			rls.r(1);
		}
		else{
			double alpha=(_data.getMatP(1,1,-1,-1)*_data.getMatP(0,0,-1,-1))
										/(_data.getMatP(1,0,-1,-1)*_data.getMatP(0,1,-1,-1));
			rls.r( (sqrt(alpha)-1)/(sqrt(alpha)+1) );
		}
	}
	else{
		rls.null(true);
	}
	
}

//--------------------------------------------------------------
// Kappa
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_Kappa::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		if( _data.getMatP(1,0,-1,-1)==0 || _data.getMatP(0,1,-1,-1)==0){
			rls.r(1);
		}
		else{
			double bunbo = 1 - _data.getMatP(1,-1,-1,-1) * _data.getMatP(-1,1,-1,-1) 
										   - _data.getMatP(0,-1,-1,-1) * _data.getMatP(-1,0,-1,-1);
			if(bunbo==0){
				rls.r(DBL_MAX);		
			}
			else{
				double bunsi = _data.getMatP(1,1,-1,-1) + _data.getMatP(0,0,-1,-1)
												- _data.getMatP(1,-1,-1,-1) * _data.getMatP(-1,1,-1,-1)  
												- _data.getMatP(0,-1,-1,-1) * _data.getMatP(-1,0,-1,-1); 
				rls.r(bunsi/bunbo);
			}
		}
	}
	else{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// ODDSRATIO
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_OddsRatio::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		if( _data.getMatP(1,0,-1,-1)==0 || _data.getMatP(0,1,-1,-1)==0){
			rls.r(DBL_MAX);
		}
		else{
			rls.r( ( _data.getMatP(1,1,-1,-1) * _data.getMatP(0,0,-1,-1) )
						 / ( _data.getMatP(1,0,-1,-1) * _data.getMatP(0,1,-1,-1) ) );
		}
	}
	else{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// CONVMAX
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_ConvMax::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		double conv_ab = _data.getMatP(1,-1,-1,-1) * _data.getMatP(-1,0,-1,-1) / _data.getMatP(1,0,-1,-1);
		double conv_ba = _data.getMatP(-1,1,-1,-1) * _data.getMatP(0,-1,-1,-1) / _data.getMatP(0,1,-1,-1);
		if(conv_ab>conv_ba)	{ rls.r(conv_ab);}
		else								{ rls.r(conv_ba);}
	}
	else{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// CONVMIN
//--------------------------------------------------------------
void kgmvsim_::kgMvSimFunc_ConvMin::calc(kgVal &rls,vector<char*>& inp)
{
	_data.calc(inp);

	if(_data.getMat(-1,-1)>0){
		double conv_ab = _data.getMatP(1,-1,-1,-1) * _data.getMatP(-1,0,-1,-1) / _data.getMatP(1,0,-1,-1);
		double conv_ba = _data.getMatP(-1,1,-1,-1) * _data.getMatP(0,-1,-1,-1) / _data.getMatP(0,1,-1,-1);
		if(conv_ab<conv_ba)	{ rls.r(conv_ab);}
		else								{ rls.r(conv_ba);}
	}
	else{
		rls.null(true);
	}
	
}
//--------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgMvsim::kgMvsim(void){

	_name    = "kgmvsim";
	_version = "###VERSION###";

	#include <help/en/kgmvsimHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgmvsimHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgMvsim::setArgs(void){
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,c=,skip=,t=,a=,-n,s=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
  _oFile.setPrecision(_precision);
	_iFile.read_header();

	// f= 項目引数のセット
	vector<kgstr_t> vs_f = _args.toStringVector("f=",true);
	if(vs_f.size()!=2){
		throw kgError("parameter f= takes two fields");	
	}

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
	
	// a= 項目名
	_addstr = _args.toString("a=",false);
	if(_addstr.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}
	
	// c= 計算方法のセット
	_c_type = _args.toString("c=", true);
			 if(_c_type=="covar"    ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Covar     >(),lambda::_1,lambda::_2); }
	else if(_c_type=="ucovar"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Ucovar    >(),lambda::_1,lambda::_2); }
	else if(_c_type=="pearson"  ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Pearson   >(),lambda::_1,lambda::_2); }
	else if(_c_type=="spearman" ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Spearman  >(),lambda::_1,lambda::_2); }
	else if(_c_type=="kendall"  ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_kendall   >(),lambda::_1,lambda::_2); }
	else if(_c_type=="euclid"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Euclid    >(),lambda::_1,lambda::_2); }
	else if(_c_type=="cosine"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Cosine    >(),lambda::_1,lambda::_2); }
	else if(_c_type=="cityblock"){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_CityBlock >(),lambda::_1,lambda::_2); }
	else if(_c_type=="hamming"  ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Hamming   >(),lambda::_1,lambda::_2); }
	else if(_c_type=="chi"      ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Chi       >(),lambda::_1,lambda::_2); }
	else if(_c_type=="phi"      ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Phi       >(),lambda::_1,lambda::_2); }
	else if(_c_type=="jaccard"  ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Jaccard   >(),lambda::_1,lambda::_2); }
	else if(_c_type=="support"  ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Support   >(),lambda::_1,lambda::_2); }
	else if(_c_type=="lift"     ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Lift      >(),lambda::_1,lambda::_2); }
	else if(_c_type=="confMax"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_ConfMax  >(),lambda::_1,lambda::_2); }
	else if(_c_type=="confMin"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_ConfMin  >(),lambda::_1,lambda::_2); }
	else if(_c_type=="yuleQ"     ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_YuleQ    >(),lambda::_1,lambda::_2); }
	else if(_c_type=="yuleY"     ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_YuleY    >(),lambda::_1,lambda::_2); }
	else if(_c_type=="kappa"     ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_Kappa    >(),lambda::_1,lambda::_2); }
	else if(_c_type=="oddsRatio" ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_OddsRatio>(),lambda::_1,lambda::_2); }
	else if(_c_type=="convMax"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_ConvMax  >(),lambda::_1,lambda::_2); }
	else if(_c_type=="convMin"   ){_function = lambda::bind(lambda::new_ptr<kgmvsim_::kgMvSimFunc_ConvMin  >(),lambda::_1,lambda::_2); }
	else {
		ostringstream ss;
		ss << "unknown keyword: " << _c_type << ": c=covar|ucovar|pearson|spearman|kendall|euclid|cosine|cityblock|hamming|chi|phi|jaccard|support|lift|confMax|confMin|yuleQ|yuleY|kappa|oddsRatio|convMax|convMin" << _c_type;
		throw kgError(ss.str());	
	}
	// -n オプションのセット
	_nullout = _args.toBool("-n");

	bool seqflg = _args.toBool("-q");
	vector<kgstr_t> vss = _args.toStringVector("s=",false);
	if(_nfn_i) { seqflg = true; }

	if(!seqflg&&vss.empty()){
		throw kgError("parameter s= is mandatory without -q,-nfn");
	}
	if(!seqflg && (!vs.empty()||!vss.empty()) ){ 
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
int kgMvsim::run(void) try {

	setArgs();
	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());
	
	// 項目名の出力
	_oFile.writeFldName(_iFile,_addstr);

	size_t fldSize=_fField.size();

	// 結果格納変数の領域確保
	kgVal  result('N');
	vector<char*> inpchar(fldSize ,0);
	
	// 計算クラスセット
	kgmvsim_::kgMvSimFunc* kmvb = _function(_skip,_term);

	while(_iFile.blkset()!=EOF){
		int nullchkcnt =0;
		while(  EOF != _iFile.blkread() ){
			bool nuldata=false;
			for(size_t i=0; i<fldSize; i++){
				inpchar[i] =_iFile.getBlkVal(_fField.num(i));
				if(*inpchar[i]=='\0'){ 
					nuldata = true;
					if(_assertNullIN) { _existNullIN  = true;}
				}
			}
			// null値の処理
			// 通常:skip -n有り:NULLデータを含むブロックはNULL
			if( nuldata ){
				if(_nullout){ nullchkcnt=_term;}
				else				{ continue;}
			}
			kmvb->calc(result,inpchar);
			if(kmvb->stocksize()>_skip){
				_oFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld(),false);
				if(nullchkcnt==0){ 
					if(_assertNullOUT && result.null() ){ _existNullOUT = true; }
					_oFile.writeVal(result,true);
				}
				else{
					if(_assertNullOUT){ _existNullOUT = true; }
					_oFile.writeEol();
				}
			}
			if(nullchkcnt>0){ nullchkcnt--;}
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
