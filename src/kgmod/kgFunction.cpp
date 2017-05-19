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
// ============================================================================
//  kgFunction.cpp : 演算に使用する関数のクラス
// ============================================================================
#include <cstdio>
#include <sstream>
#include <cmath>
#include <ctime>
#include <kgFunction.h>
#include <kgError.h>
#include <boost/math/distributions.hpp>


using namespace std;
using namespace kglib;
using namespace boost::xpressive;
using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace boost;
//using namespace boost::math;

// static function
namespace 
{	
	// ptimeでの年の差
	int diffYear(ptime* t0, ptime* t1){
		int y0 = t0->date().year();
		int m0 = t0->date().month();
		int d0 = t0->date().day();
		int h0 = t0->time_of_day().hours();
		int n0 = t0->time_of_day().minutes();
		int s0 = t0->time_of_day().seconds();
		int us0 = t0->time_of_day().fractional_seconds();

		int y1 = t1->date().year();
		int m1 = t1->date().month();
		int d1 = t1->date().day();
		int h1 = t1->time_of_day().hours();
		int n1 = t1->time_of_day().minutes();
		int s1 = t1->time_of_day().seconds();
		int us1 = t1->time_of_day().fractional_seconds();
		
		int fract=( m0*100000000+d0*1000000+h0*10000+n0*100+s0
				       -m1*100000000-d1*1000000-h1*10000-n1*100-s1);
		if(fract==0){
			fract = us0 - us1;
		}
		if(fract<0) return y0-y1-1;
		else        return y0-y1;
	}
	
	// dateでの年の差
	int diffYear(date* t0, date* t1)
	{
		int y0 = t0->year();
		int m0 = t0->month();
		int d0 = t0->day();
		int y1 = t1->year();
		int m1 = t1->month();
		int d1 = t1->day();
		int fract= m0*100+d0 - m1*100-d1;
		if(fract<0) return y0-y1-1;
		else        return y0-y1;
	}

	// ptimeでの月の差
	int diffMonth(ptime* t0, ptime* t1)
	{
		int y0 = t0->date().year();
		int m0 = t0->date().month();
		int d0 = t0->date().day();
		int h0 = t0->time_of_day().hours();
		int n0 = t0->time_of_day().minutes();
		int s0 = t0->time_of_day().seconds();
		int us0 = t0->time_of_day().fractional_seconds();
		int y1 = t1->date().year();
		int m1 = t1->date().month();
		int d1 = t1->date().day();
		int h1 = t1->time_of_day().hours();
		int n1 = t1->time_of_day().minutes();
		int s1 = t1->time_of_day().seconds();
		int us1 = t1->time_of_day().fractional_seconds();
		int fract=( d0*1000000+h0*10000+n0*100+s0
				       -d1*1000000-h1*10000-n1*100-s1);
		if(fract==0){
			fract = us0 - us1;
		}
		if(fract<0) return (y0-y1)*12+(m0-m1)-1;
		else        return (y0-y1)*12+(m0-m1);
	}

	// dateでの月の数
	int diffMonth(date* t0, date* t1)
	{
		int y0 = t0->year();
		int m0 = t0->month();
		int d0 = t0->day();
		int y1 = t1->year();
		int m1 = t1->month();
		int d1 = t1->day();
		int fract=d0-d1;
		if(fract<0) return (y0-y1)*12+(m0-m1)-1;
		else        return (y0-y1)*12+(m0-m1);
	}

	// ptimeでの日の差
	int diffDay(ptime* t0, ptime* t1)
	{
		int h0 = t0->time_of_day().hours();
		int n0 = t0->time_of_day().minutes();
		int s0 = t0->time_of_day().seconds();
		int us0 = t0->time_of_day().fractional_seconds();
		int h1 = t1->time_of_day().hours();
		int n1 = t1->time_of_day().minutes();
		int s1 = t1->time_of_day().seconds();
		int us1 = t1->time_of_day().fractional_seconds();
		int fract=( h0*10000+n0*100+s0
				       -h1*10000-n1*100-s1);
		if(fract==0){
			fract = us0 - us1;
		}
		date_duration dd= t0->date() - t1->date();
		if(fract<0) return dd.days()-1;
		else        return dd.days();
	}

	// dateでの日の差
	int diffDay(date* t0, date* t1){
		date_duration dd= *t0 - *t1;
		return dd.days();
	}

	// ptimeのメモリを確保するのでその管理は呼び出しもとで行う
	ptime* s2ptime(const char *str)
	{
	
		int yr,mo,dy,hr,mi,sc,usec;
		const char *p ; //"."位置
		size_t len = strlen(str);
		for(p=str;*p;p++){ 
			if(*p == '.') { break; }
		}
		size_t ilen = (p - str);
		size_t flen = 0;
		if(*p=='.'){ flen = len - (ilen+1); }
		// 時分秒の場合(len:6)は本日日付を利用してptimeを求める
		// 年月日の場合(len:8)は12:00:00を利用してptimeを求める
		try {
			if(ilen==6){
				if(flen==0){
					if( time_set(str,&hr,&mi,&sc) ){
						return new ptime( day_clock::local_day(), time_duration(hr,mi,sc));
					}
				}
				else{
					if( utime_set(str,&hr,&mi,&sc,&usec,time_duration::num_fractional_digits()) ){
						return new ptime( day_clock::local_day(), time_duration(hr,mi,sc,usec) );
					}
				}
			}
			else if(ilen==8){
				if(flen==0){
					if( date_set(str,&yr,&mo,&dy)){
						return new ptime( date(yr,mo,dy), hours(12)+minutes(0)+seconds(0) );
					}
				}
				else{
					return NULL ; //format error
				}
			}
			else if(ilen==14){
				if(flen==0){
					if(ptime_set(str,&yr,&mo,&dy,&hr,&mi,&sc)){
						return new ptime( date(yr,mo,dy), time_duration(hr,mi,sc));
					}
				}
				else{
					if(putime_set(str,&yr,&mo,&dy,&hr,&mi,&sc,&usec,time_duration::num_fractional_digits())){
						return new ptime( date(yr,mo,dy), time_duration(hr,mi,sc,usec));
					}
				}
			}
			else{
				return NULL;
			}
		}
		catch(...){
			return NULL;
		}
		return NULL;
	}

	// dateのメモリを確保するのでその管理は呼び出しもとで行う
	date* s2date(const char *str){
		int y,m,d;
		if ( date_set(str,&y,&m,&d)){
			try {
				return new date(y,m,d);
			}catch(...){
				return NULL;
			}
		}
		return NULL;
	}
	// boolの文字列をkgvalにセット
	void boolset(const char *str,kgVal *kval)
	{	
		     if( *str=='1' ) kval->b( true );
		else if( *str=='0' ) kval->b( false );
		else          		   kval->null(true);
	}

}	
// =============================================================================
// 引数の数のチェック
// =============================================================================
void kgFunction::chkArgc(void)
{
	if(_args.size()<_minArgc || _args.size()>_maxArgc){
		ostringstream ss;
		if(_minArgc==_maxArgc){
			ss << "the number of arguments must be ";
			ss << _minArgc << " (" << _name << ")";
		}else{
			ss << "the number of arguments is out of range (" << _name << ":";
			ss << _minArgc << "~" << _maxArgc << ")";
		}
		throw kgError(ss.str());
	}
}
// =============================================================================
// 定数のセット
// =============================================================================
// -------------------------------------------------------------------------
// 文字列セット::初期設定(文字列格納)
// -------------------------------------------------------------------------
void kgFunction_const_str::initialize(kgstr_t& str)
{
	evalEscape(str);
	_val=str;
	_result.s(const_cast<char*>(_val.c_str()));
	if(*_val.c_str()=='\0'){ _result.null(true);}
	return;
}
// -------------------------------------------------------------------------
// 実数定数セット::初期設定(定数格納)
// -------------------------------------------------------------------------
void kgFunction_const_real::initialize(kgstr_t& str)
{
	_result.r(atof(str.c_str()));
	return;
}
// -------------------------------------------------------------------------
// 日付定数セット::初期設定(定数格納)
// -------------------------------------------------------------------------
void kgFunction_const_date::initialize(kgstr_t& str)
{
	date * d = s2date(str.c_str());
	if(d!=NULL){
  	_ap.set(d);
		_result.d(_ap.get());
	}else{
		_result.null(true);
	}
	return;
}
// -------------------------------------------------------------------------
// 時刻定数セット::初期設定(定数格納)
// -------------------------------------------------------------------------
void kgFunction_const_time::initialize(kgstr_t& str)
{
	ptime* t = s2ptime(str.c_str());
	if(t!=NULL){
	  _ap.set(t);
		_result.t(_ap.get());
	}else{
		_result.null(true);
	}
}
// -------------------------------------------------------------------------
// 時刻定数セット::初期設定(定数格納)
// -------------------------------------------------------------------------
void kgFunction_const_utime::initialize(kgstr_t& str)
{
	ptime* t = s2ptime(str.c_str());
	if(t!=NULL){
	  _ap.set(t);
		_result.t(_ap.get());
	}else{
		_result.null(true);
	}
}

// -------------------------------------------------------------------------
// bool定数セット
// -------------------------------------------------------------------------
void kgFunction_const_bool::initialize(kgstr_t& str)
{
	boolset(str.c_str(),&_result);
}
// =============================================================================
// 項目値のセット
// =============================================================================
// -------------------------------------------------------------------------
// 文字列項目値セット
// -------------------------------------------------------------------------
void kgFunction_field_str::run(void)
{
	char *str=_csv->getNewVal(_fld.num(0));
	_result.s(str);
	if(*str=='\0'){ _result.null(true);}
}
// -------------------------------------------------------------------------
// 実数項目値セット
// -------------------------------------------------------------------------
void kgFunction_field_real::run(void)
{
	char *str=_csv->getNewVal(_fld.num(0));
	if(*str=='\0'){
		_result.null(true);
	}else{
		_result.r(atof(str));
	}
}
// -------------------------------------------------------------------------
// 日付項目値セット
// -------------------------------------------------------------------------
void kgFunction_field_date::run(void)
{
	date * d = s2date(_csv->getNewVal(_fld.num(0)));
	if(d!=NULL){
  	_ap.set(d);
		_result.d(_ap.get());
	}else{
		_result.null(true);
	}
}
// -------------------------------------------------------------------------
// 時刻項目値セット
// -------------------------------------------------------------------------
void kgFunction_field_time::run(void)
{
	ptime *t = s2ptime(_csv->getNewVal(_fld.num(0)));
	if(t!=NULL){
	  _ap.set(t);
		_result.t(_ap.get());
	}else{
		_result.null(true);
	}
}
// -------------------------------------------------------------------------
// bool値セット
// -------------------------------------------------------------------------
void kgFunction_field_bool::run(void)
{
	boolset(_csv->getNewVal(_fld.num(0)),&_result);
}
// =============================================================================
// 前行項目値のセット
// =============================================================================
// -------------------------------------------------------------------------
// 前行項目値：初期設定
// -------------------------------------------------------------------------
void kgFunction_pfield::initialize(kgstr_t& str)
{
	if(str.length()==0){
		_rsl=true;
	}else{
		_rsl=false;
		_fld.set(str,_csv,_fldno);
	}
}
// -------------------------------------------------------------------------
// 文字列前行項目値セット
// -------------------------------------------------------------------------
void kgFunction_pfield_str::run(void)
{
	if(_rsl){
		_result=*_prvRsl;
		return;
	}
	char *str=_csv->getOldVal(_fld.num(0)); // 項目値の取得(項目名は必ず1つ)
	_result.s(str);
	if(*str=='\0'){ _result.null(true);}
		
}
// -------------------------------------------------------------------------
// 実数前行項目値セット
// -------------------------------------------------------------------------
void kgFunction_pfield_real::run(void)
{
	if(_rsl){
		_result=*_prvRsl;
		return;
	}
	char *str=_csv->getOldVal(_fld.num(0));
	if(*str=='\0'){
		_result.null(true);
	}else{
		_result.r(atof(str));
	}
}
// -------------------------------------------------------------------------
// 日付前行項目値セット
// -------------------------------------------------------------------------
void kgFunction_pfield_date::run(void)
{
	if(_rsl){
		_result=*_prvRsl;
		return;
	}
	date * d = s2date(_csv->getOldVal(_fld.num(0)));
	if(d!=NULL){
  	_ap.set(d);
		_result.d(_ap.get());
	}else{
		_result.null(true);
	}
}
// -------------------------------------------------------------------------
// 時刻前行項目値セット
// -------------------------------------------------------------------------
void kgFunction_pfield_time::run(void)
{
	if(_rsl){
		_result=*_prvRsl;
		return;
	}
	ptime *t = s2ptime(_csv->getOldVal(_fld.num(0)));
	if(t!=NULL){
	  _ap.set(t);
		_result.t(_ap.get());
	}else{
		_result.null(true);
	}
}
// -------------------------------------------------------------------------
// bool前行項目値セット
// -------------------------------------------------------------------------
void kgFunction_pfield_bool::run(void)
{
	if(_rsl){
		_result=*_prvRsl;
		return;
	}
	boolset(_csv->getOldVal(_fld.num(0)),&_result);
}
// =============================================================================
// 算術演算子
// =============================================================================
// -----------------------------------------------------------------------------
// 加算:：double+double
// -----------------------------------------------------------------------------
void kgFunction_add_real::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		_result.r(_args.at(0)->r() + _args.at(1)->r());
	}
}
// -----------------------------------------------------------------------------
// 加算:：char*+char*
// -----------------------------------------------------------------------------
void kgFunction_add_str::run(void)
{	
	int size = strlen(_args.at(0)->s())+strlen(_args.at(1)->s())+1;
	if(size>KG_MAX_STR_LEN){
		*_buf='\0';
		_result.s(_buf);
	}else{
		strcpy(_buf,_args.at(0)->s());
 		strcat(_buf,_args.at(1)->s());
		_result.s(_buf);
	}
} 
// -----------------------------------------------------------------------------
// 加算:：date+double
// -----------------------------------------------------------------------------
void kgFunction_add_day::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		try {
   		_ap.set( 
   			new date(*_args.at(0)->d()+date_duration(static_cast<int>(_args.at(1)->r()))) 
   		);
			_result.d(_ap.get());
		}catch(...){
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// 加算:time+double
// -----------------------------------------------------------------------------
void kgFunction_add_sec::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		try {
			double i;
			double fract = modf(_args.at(1)->r(), &i);
    	_ap.set( 
    		new ptime(*_args.at(0)->t()+time_duration(0,0,i, fract * time_duration::ticks_per_second())) 
    	);
			_result.t(_ap.get());
		}catch(...){
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// 減算:double - double
// -----------------------------------------------------------------------------
void kgFunction_sub_real::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		_result.r(_args.at(0)->r() - _args.at(1)->r());
	}
} 
// -----------------------------------------------------------------------------
// 減算:：char* - char*　( 一つ目の文字列から二つ目の文字列をを取り除く)
// -----------------------------------------------------------------------------
void kgFunction_sub_str::run(void)
{	
	if(*_args.at(0)->s()=='\0' || *_args.at(1)->s()=='\0' ){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int size = strlen(_args.at(0)->s());
		if(size>=KG_MAX_STR_LEN){
			*_buf='\0';
			_result.s(_buf);
		}else{
			char* q = _buf;
			char* p = _args.at(0)->s();
			char* r = _args.at(1)->s();
			while(*p){
				if(*p==*r){
					int i;
					for(i=0;*(p+i)&&*(r+i);i++){
						if(*(p+i)!=*(r+i)){break;}
					}
					if(!*(r+i)){
						p = p+i;	continue;
					}
				}
				*q++=*p++;
			}
			*q='\0';
			_result.s(_buf);
		}
	}
} 
// -----------------------------------------------------------------------------
// 減算:date - double
// -----------------------------------------------------------------------------
void kgFunction_sub_day::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		try {
   		_ap.set( 
   			new date(*_args.at(0)->d()-date_duration(static_cast<int>(_args.at(1)->r())))
			);
			_result.d(_ap.get());
		}catch(...){
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// 減算:time - double
// -----------------------------------------------------------------------------
void kgFunction_sub_sec::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		try {
			double i;
			double fract = modf(_args.at(1)->r(), &i);
    	_ap.set( 
    		new ptime(*_args.at(0)->t()-time_duration(0,0,i, fract * time_duration::ticks_per_second())) 
    	);
			_result.t(_ap.get());
		}catch(...){
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// 減算:date-date
// -----------------------------------------------------------------------------
void kgFunction_sub_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		days day_sub = (*_args.at(0)->d()) - (*_args.at(1)->d());
		_result.r( static_cast<double>(day_sub.days()) );
	}
}
// -----------------------------------------------------------------------------
// 減算:time-time
// -----------------------------------------------------------------------------
void kgFunction_sub_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		time_duration td( *_args.at(0)->t() - *_args.at(1)->t() );
		_result.r( static_cast<double>(td.total_seconds())+ static_cast<double>(td.fractional_seconds())/time_duration::ticks_per_second() );
	}
}
// -----------------------------------------------------------------------------
// 乗算：double * double
// -----------------------------------------------------------------------------
void kgFunction_mul_real::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		_result.r(_args.at(0)->r() * _args.at(1)->r());
	}
} 
// -----------------------------------------------------------------------------
// 除算：ouble / double
// -----------------------------------------------------------------------------
void kgFunction_div_real::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(1)->r() == 0 ){
			_result.null(true);
		}else{
			_result.r( _args.at(0)->r() / _args.at(1)->r() );
		}
	}
} 
// -----------------------------------------------------------------------------
// 剰余：double % double
// -----------------------------------------------------------------------------
void kgFunction_mod_real::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(1)->r() == 0) {
			_result.null(true);
		}else{
			_result.r( fmod(_args.at(0)->r(), _args.at(1)->r()) );
		}
	}
} 
// -----------------------------------------------------------------------------
// 冪乗：double ^ double
// -----------------------------------------------------------------------------
void kgFunction_pow_real::run(void)
{	
	double v;
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		v= pow(_args.at(0)->r(),_args.at(1)->r());
		if(isfinite(v))	_result.r( v );
		else						_result.null(true);
	}
}
// =============================================================================
// 比較演算子
// =============================================================================
// -----------------------------------------------------------------------------
// char* >= char*
// -----------------------------------------------------------------------------
void kgFunction_ge_str::run(void)
{
	if( strcmp(_args.at(0)->s(),_args.at(1)->s())  >= 0 ) {
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// char* > char*
// -----------------------------------------------------------------------------
void kgFunction_gt_str::run(void)
{
	if( strcmp(_args.at(0)->s(),_args.at(1)->s())  >  0 ) {
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// char* <= char*
// -----------------------------------------------------------------------------
void kgFunction_le_str::run(void)
{
	if( strcmp(_args.at(0)->s(),_args.at(1)->s())  <= 0 ) {
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// char* < char*
// -----------------------------------------------------------------------------
void kgFunction_lt_str::run(void)
{
	if( strcmp(_args.at(0)->s(),_args.at(1)->s())  <  0 ) {
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// char* == char*
// -----------------------------------------------------------------------------
void kgFunction_eq_str::run(void)
{
	if( strcmp(_args.at(0)->s(),_args.at(1)->s())  == 0 ) {
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// char* != char*
// -----------------------------------------------------------------------------
void kgFunction_ne_str::run(void)
{
	if( strcmp(_args.at(0)->s(),_args.at(1)->s())  != 0 ) {
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// double >= double
// -----------------------------------------------------------------------------
void kgFunction_ge_real::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->r() >= _args.at(1)->r()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// double > double
// -----------------------------------------------------------------------------
void kgFunction_gt_real::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->r() >  _args.at(1)->r()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// double <= double
// -----------------------------------------------------------------------------
void kgFunction_le_real::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->r() <= _args.at(1)->r()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// double < double
// -----------------------------------------------------------------------------
void kgFunction_lt_real::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->r() <  _args.at(1)->r()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// double == double
// -----------------------------------------------------------------------------
void kgFunction_eq_real::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->r() == _args.at(1)->r()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// double != double
// -----------------------------------------------------------------------------
void kgFunction_ne_real::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->r() != _args.at(1)->r()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// date >= date
// -----------------------------------------------------------------------------
void kgFunction_ge_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->d() >= *_args.at(1)->d()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// date > date
// -----------------------------------------------------------------------------
void kgFunction_gt_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->d() >  *_args.at(1)->d()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// date <= date
// -----------------------------------------------------------------------------
void kgFunction_le_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->d() <= *_args.at(1)->d()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// date < date
// -----------------------------------------------------------------------------
void kgFunction_lt_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->d() <  *_args.at(1)->d()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// date == date
// -----------------------------------------------------------------------------
void kgFunction_eq_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->d() == *_args.at(1)->d()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// date != date
// -----------------------------------------------------------------------------
void kgFunction_ne_date::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->d() != *_args.at(1)->d()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// time >= time
// -----------------------------------------------------------------------------
void kgFunction_ge_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->t() >= *_args.at(1)->t()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// time > time
// -----------------------------------------------------------------------------
void kgFunction_gt_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->t() >  *_args.at(1)->t()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// time <= time
// -----------------------------------------------------------------------------
void kgFunction_le_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->t() <= *_args.at(1)->t()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// time < time
// -----------------------------------------------------------------------------
void kgFunction_lt_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->t() <  *_args.at(1)->t()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// time == time
// -----------------------------------------------------------------------------
void kgFunction_eq_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->t() == *_args.at(1)->t()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// time != time
// -----------------------------------------------------------------------------
void kgFunction_ne_time::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		if( *_args.at(0)->t() != *_args.at(1)->t()){
			_result.b(true);
		}else{
			_result.b(false);
		}
	}
}
// -----------------------------------------------------------------------------
// 論理演算 B && B
//       |true |null |false 
// true  |true |null |false
// null  |null |null |false
// false |false|false|false
//true:1,false:0,null:-1
//		|1  |-1 |0 
//  1	|1  |-1 |0
// -1 |-1 |-1 |0
//  0	|0	|0  |0
// -----------------------------------------------------------------------------
void kgFunction_and::run(void)
{
	int v0 = 0;
	int v1 = 0;
	if(_args.at(0)->null())		{ v0 = -1;}
	else if(_args.at(0)->b())	{ v0 =  1;}
	if(_args.at(1)->null())		{ v1 = -1;}
	else if(_args.at(1)->b())	{ v1 =  1;}
	
	if 			(v0==0||v1==0){ _result.b(false);		}
	else if (v0==1&&v1==1){ _result.b(true);		}
	else									{ _result.null(true);	}

}
// -----------------------------------------------------------------------------
// 論理演算 B || B
//       |true |null |false 
// true  |true |true |true
// null  |true |null |null 
// false |true |null |false
//true:1,false:0,null:-1
//		| 1  |-1 | 0 
//  1	| 1  | 1 | 1
// -1 | 1  |-1 |-1
//  0	| 1	 |-1 | 0
// -----------------------------------------------------------------------------
void kgFunction_or::run(void)
{
	int v0 = 0;
	int v1 = 0;
	if(_args.at(0)->null())		{ v0 = -1;}
	else if(_args.at(0)->b())	{ v0 =  1;}
	if(_args.at(1)->null())		{ v1 = -1;}
	else if(_args.at(1)->b())	{ v1 =  1;}

	if 			(v0==1||v1==1){ _result.b(true);		}
	else if (v0==0&&v1==0){ _result.b(false);		}
	else									{ _result.null(true);	}
}
// -----------------------------------------------------------------------------
// 論理演算 B ^^ B
//       |true |null |false 
// true  |false|null |true
// null  |null |null |null 
// false |true |null |false
// -----------------------------------------------------------------------------
void kgFunction_xor::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		_result.b( _args.at(0)->b() != _args.at(1)->b() );
	}
}
// -----------------------------------------------------------------------------
// 論理関数 if(B,S,S)
// -----------------------------------------------------------------------------
void kgFunction_if_str::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->b() ){
 			_result.s(_args.at(1)->s());
		}else{
			_result.s(_args.at(2)->s());
		}
	}
}
// -----------------------------------------------------------------------------
// 論理関数 if(B,N,N)
// -----------------------------------------------------------------------------
void kgFunction_if_real::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->b() ){
			if( _args.at(1)->null() ) _result.null(true);
 			else                      _result.r(_args.at(1)->r());
		}else{
			if( _args.at(2)->null() ) _result.null(true);
			else                      _result.r(_args.at(2)->r());
		}
	}
}
// -----------------------------------------------------------------------------
// 論理関数 if(B,D,D)
// -----------------------------------------------------------------------------
void kgFunction_if_date::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->b() ){
			if( _args.at(1)->null() ) _result.null(true);
 			else                      _result.d(_args.at(1)->d());
		}else{
			if( _args.at(2)->null() ) _result.null(true);
			else                      _result.d(_args.at(2)->d());
		}
	}
}
// -----------------------------------------------------------------------------
// 論理関数 if(B,T,T)
// -----------------------------------------------------------------------------
void kgFunction_if_time::run(void){
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->b() ){
			if( _args.at(1)->null() ) _result.null(true);
 			else                      _result.t(_args.at(1)->t());
		}else{
			if( _args.at(2)->null() ) _result.null(true);
			else                      _result.t(_args.at(2)->t());
		}
	}
}
// -----------------------------------------------------------------------------
// 論理関数 if(B,T,T)
// -----------------------------------------------------------------------------
void kgFunction_if_bool::run(void){
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->b() ){
			if( _args.at(1)->null() ) _result.null(true);
 			else                      _result.b(_args.at(1)->b());
		}else{
			if( _args.at(2)->null() ) _result.null(true);
			else                      _result.b(_args.at(2)->b());
		}
	}
}

// -----------------------------------------------------------------------------
// 論理関数 and(B,B,...,B)
// -----------------------------------------------------------------------------
void kgFunction_multi_and::run(void)
{
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			if( ! _args.at(i)->b() ) {
				_result.b(false);
				return;
			}
		}
	}
	_result.b(true);
}
// -----------------------------------------------------------------------------
// 論理関数 or(B,B,...,B)
// -----------------------------------------------------------------------------
void kgFunction_multi_or::run(void)
{
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			if( _args.at(i)->b() ) {
				_result.b(true);
				return;
			}
		}
	}
	_result.b(false);
}
// -----------------------------------------------------------------------------
// 論理関数 not(B)
// -----------------------------------------------------------------------------
void kgFunction_not::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.b( !_args.at(0)->b() );
	}
}
// -----------------------------------------------------------------------------
// null check isnull(S)
// -----------------------------------------------------------------------------
void kgFunction_isnull_s::run(void)
{
	if(*_args.at(0)->s()=='\0'){
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// null check isnull(N)
// -----------------------------------------------------------------------------
void kgFunction_isnull_n::run(void)
{
	if( _args.at(0)->null() ) _result.b(true);
	else                      _result.b(false);
}
// -----------------------------------------------------------------------------
// null check isnull(D)
// -----------------------------------------------------------------------------
void kgFunction_isnull_d::run(void)
{
	if( _args.at(0)->null() ) _result.b(true);
	else                      _result.b(false);
}
// -----------------------------------------------------------------------------
// null check isnull(T)
// -----------------------------------------------------------------------------
void kgFunction_isnull_t::run(void)
{
	if( _args.at(0)->null() ) _result.b(true);
	else                      _result.b(false);
}
// -----------------------------------------------------------------------------
// null check isnull(B)
// -----------------------------------------------------------------------------
void kgFunction_isnull_b::run(void)
{
	if( _args.at(0)->null() ) _result.b(true);
	else                      _result.b(false);
}
// -----------------------------------------------------------------------------
// null count countnull(S,S,....)
// -----------------------------------------------------------------------------
void kgFunction_countnull_s::run(void)
{
	double count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if(*_args.at(i)->s()=='\0'){
			count += 1;
		}
	}
	_result.r(count);
}
// -----------------------------------------------------------------------------
// null count countnull(N,...)
// null count countnull(D,...)
// null count countnull(T,...)
// null count countnull(B,...)
// -----------------------------------------------------------------------------
void kgFunction_countnull::run(void)
{
	double count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			count += 1;
		}
	}
	_result.r(count);
}
// 型変換
// =============================================================================
// -----------------------------------------------------------------------------
// 文字列->実数
// -----------------------------------------------------------------------------
void kgFunction_s2n::run(void)
{
	_result.r( atof( _args.at(0)->s() ) );
}
// -----------------------------------------------------------------------------
// 文字列->日付
// -----------------------------------------------------------------------------
void kgFunction_s2d::run(void)
{
	date * d = s2date(_args.at(0)->s());
	if(d!=NULL){
  	_ap.set(d);
		_result.d(_ap.get());
	}else{
		_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// 時刻->日付
// -----------------------------------------------------------------------------
void kgFunction_t2d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);	
		return;
	}
	else{
		date * d = new date(_args.at(0)->t()->date());
		if(d!=NULL){
 			_ap.set(d);
 			_result.d(_ap.get());
		}else{
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// 文字列->時刻
// -----------------------------------------------------------------------------
void kgFunction_s2t::run(void)
{
	ptime* t = s2ptime(_args.at(0)->s());
	if(t!=NULL){
	  _ap.set(t);
		_result.t(_ap.get());
	}else{
		_result.null(true);
	}
}

// -----------------------------------------------------------------------------
// 日付->時刻
// -----------------------------------------------------------------------------
void kgFunction_d2t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);	
		return;
	}
	ptime* t = new ptime( *_args.at(0)->d(), hours(12)+minutes(0)+seconds(0) );
	if(t!=NULL){
	  _ap.set(t);
		_result.t(_ap.get());
	}else{
		_result.null(true);
	}
}

// -----------------------------------------------------------------------------
// 実数->文字列
// -----------------------------------------------------------------------------
void kgFunction_n2s::run(void)
{
	if( _args.at(0)->null() ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		sprintf(_buf,"%g", _args.at(0)->r() );
		_result.s(_buf);
	}
}
// -----------------------------------------------------------------------------
// 日付->文字列
// -----------------------------------------------------------------------------
void kgFunction_d2s::run(void)
{
	if( _args.at(0)->null() ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		int y = _args.at(0)->d()->year();
		int m = _args.at(0)->d()->month();
		int d = _args.at(0)->d()->day();
		sprintf( _buf,"%04d%02d%02d",y,m,d);
		_result.s(_buf);
	}
}
// -----------------------------------------------------------------------------
// 時刻->文字列
// -----------------------------------------------------------------------------
void kgFunction_t2s::run(void)
{
	if( _args.at(0)->null() ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		int y = static_cast<int>(_args.at(0)->t()->date().year());
		int mm= static_cast<int>(_args.at(0)->t()->date().month());
		int d = static_cast<int>(_args.at(0)->t()->date().day());
		int h = _args.at(0)->t()->time_of_day().hours();
		int m = _args.at(0)->t()->time_of_day().minutes();
		int s = _args.at(0)->t()->time_of_day().seconds();
		sprintf( _buf,"%04d%02d%02d%02d%02d%02d",y,mm,d, h,m,s);
		_result.s(_buf);
	}
}

// -----------------------------------------------------------------------------
// bool -> 実数
// -----------------------------------------------------------------------------
void kgFunction_b2n::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		if( _args.at(0)->b() ) _result.r(1);
		else                   _result.r(0);
	}
}
// -----------------------------------------------------------------------------
// bool->文字列
// -----------------------------------------------------------------------------
void kgFunction_b2s::run(void)
{
	if( _args.at(0)->null() ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		if( _args.at(0)->b() ) _buf[0]='1';
		else                   _buf[0]='0';
		_result.s(_buf);
	}
}
// -----------------------------------------------------------------------------
// 実数 -> bool
// -----------------------------------------------------------------------------
void kgFunction_n2b::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double r=_args.at(0)->r();
	       if( r==0 ) _result.b(false);
	  else if( r==1 ) _result.b(true);
		else            _result.null(true);
	}
}
// -----------------------------------------------------------------------------
// 文字列 -> bool
// -----------------------------------------------------------------------------
void kgFunction_s2b::run(void)
{
		char* s= _args.at(0)->s();
		     if( *s=='0' ) _result.b(false);
		else if( *s=='1' ) _result.b(true);
		else               _result.null(true);
}
// -----------------------------------------------------------------------------
// 実数の書式付き出力
// -----------------------------------------------------------------------------
void kgFunction_format_real::run(void)
{
	if( _args.at(0)->null()  ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		sprintf(_buf, _args.at(1)->s(), _args.at(0)->r() );
		_result.s(_buf);
	}
}
// =============================================================================
// 日付時刻関数
// =============================================================================
// -----------------------------------------------------------------------------
// 今日日付
// -----------------------------------------------------------------------------
void kgFunction_today::initialize(kgstr_t& str)
{
	_today = day_clock::local_day();
	_result.d(&_today);
}
// -----------------------------------------------------------------------------
// 現在時刻
// -----------------------------------------------------------------------------
void kgFunction_now::initialize(kgstr_t& str)
{
	_now=second_clock::local_time();
	_result.t(&_now);
}
// -----------------------------------------------------------------------------
// 現在時刻
// -----------------------------------------------------------------------------
void kgFunction_unow::initialize(kgstr_t& str)
{
	_unow=microsec_clock::local_time();
	_result.t(&_unow);
}

// -----------------------------------------------------------------------------
// 時刻->日付文字列
// -----------------------------------------------------------------------------
void kgFunction_date_str::run(void)
{
	if( _args.at(0)->null() ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		int y = static_cast<int>(_args.at(0)->t()->date().year());
		int mm= static_cast<int>(_args.at(0)->t()->date().month());
		int d = static_cast<int>(_args.at(0)->t()->date().day());
		sprintf( _buf,"%04d%02d%02d", y,mm,d);
		_result.s(_buf);
	}
}

// -----------------------------------------------------------------------------
// 時刻->時間文字列
// -----------------------------------------------------------------------------
void kgFunction_time_str::run(void)
{
	if( _args.at(0)->null() ){
		*_buf = '\0';
		_result.s(_buf);
	}else{
		int h = _args.at(0)->t()->time_of_day().hours();
		int m = _args.at(0)->t()->time_of_day().minutes();
		int s = _args.at(0)->t()->time_of_day().seconds();
		long long us = _args.at(0)->t()->time_of_day().fractional_seconds();
		
		if(us==0){
			sprintf( _buf,"%02d%02d%02d", h,m,s);
		}
		else{
			char fmt[32];
			sprintf(fmt,"%%02d%%02d%%02d.%%0%dlld",_args.at(0)->t()->time_of_day().num_fractional_digits() );
			sprintf(_buf,fmt,
				_args.at(0)->t()->time_of_day().hours()  ,
				_args.at(0)->t()->time_of_day().minutes(),
				_args.at(0)->t()->time_of_day().seconds(),
				_args.at(0)->t()->time_of_day().fractional_seconds()
    	);  
    	//後ろ０クリア
			for(char *p = _buf+strlen(_buf)-1 ; p>_buf && *p=='0' ;p-- ){
				*p='\0';
			}
		}
		_result.s(_buf);
	}

}
// -----------------------------------------------------------------------------
// 閏年判定:date
// -----------------------------------------------------------------------------
void kgFunction_leapyear_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.b( gregorian_calendar::is_leap_year(_args.at(0)->d()->year()) );
	}
}
// -----------------------------------------------------------------------------
// 閏年判定:time
// -----------------------------------------------------------------------------
void kgFunction_leapyear_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.b( gregorian_calendar::is_leap_year
			( _args.at(0)->t()->date().year() )
		);
	}
}
// -----------------------------------------------------------------------------
// date->ユリウス通日
// -----------------------------------------------------------------------------
void kgFunction_d2julian::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( _args.at(0)->d()->julian_day() );
	}
}
// -----------------------------------------------------------------------------
// time->ユリウス通日
// -----------------------------------------------------------------------------
void kgFunction_t2julian::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		// 精度対策
		_result.r(
			static_cast<double>( _args.at(0)->t()->date().julian_day() ) + 
			static_cast<double>
				( 
					( _args.at(0)->t()->time_of_day().total_seconds() * time_duration::ticks_per_second() 		
		      + _args.at(0)->t()->time_of_day().fractional_seconds() )
        	- 43200 * time_duration::ticks_per_second() 
        ) 
        / 
        static_cast<double>( 86400 * time_duration::ticks_per_second() )
		);
	}
}
// -----------------------------------------------------------------------------
// ユリウス通日->date
// -----------------------------------------------------------------------------
void kgFunction_julian2d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		try {
 			_ap.set(
				new date( 
					gregorian_calendar::from_julian_day_number( (static_cast<unsigned long>(_args.at(0)->r())))
				)
			);
			_result.d(_ap.get());
		}catch(...){
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// ユリウス通日->time
// -----------------------------------------------------------------------------
void kgFunction_julian2t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double i,f;
		try {
			f = modf(_args.at(0)->r(), &i);
			date d( gregorian_calendar::from_julian_day_number( static_cast<unsigned long>(i) ) );
			f = modf(f*86400, &i);
			ptime t( d, time_duration(12,0,i,f*time_duration::ticks_per_second()) );
    	_ap.set( new ptime(t) );
			_result.t(_ap.get());
		}catch(...){
			_result.null(true);
		}
	}
}
// -----------------------------------------------------------------------------
// date->UNIXtime
// -----------------------------------------------------------------------------
void kgFunction_d2uxt::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		date d(1970,1,1);
		ptime t0( d, hours(0)+minutes(0)+seconds(0) );
		ptime t1( *_args.at(0)->d(), hours(0)+minutes(0)+seconds(0) );
		time_duration td( t1- t0 );
		_result.r(static_cast<double>(td.total_seconds()));
	}
}
// -----------------------------------------------------------------------------
// time->UNIXtime
// -----------------------------------------------------------------------------
void kgFunction_t2uxt::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		date d(1970,1,1);
		ptime t( d, hours(0)+minutes(0)+seconds(0) );

		time_duration td( *_args.at(0)->t() - t );
		_result.r(static_cast<double>(td.total_seconds()));
	}
}
// -----------------------------------------------------------------------------
// UNIXtime->time (local timeは考慮してない)
// -----------------------------------------------------------------------------
void kgFunction_uxt2t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		date d(1970,1,1);
		ptime t( d, hours(0)+minutes(0)+seconds(0) );
		t=t+seconds( static_cast<int>(_args.at(0)->r()) );
  	_ap.set( new ptime(t) );
		_result.t(_ap.get());
	}
}
// -----------------------------------------------------------------------------
// UNIXtime->date (local timeは考慮してない)
// -----------------------------------------------------------------------------
void kgFunction_uxt2d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		date d(1970,1,1);
		ptime t( d, hours(0)+minutes(0)+seconds(0) );
		t=t+seconds( static_cast<int>(_args.at(0)->r()) );
   	_ap.set( new date(t.date()) );
		_result.d(_ap.get());
	}
}
// -----------------------------------------------------------------------------
// age(D1,D2) : 年齢計算(D2-D1)
// -----------------------------------------------------------------------------
void kgFunction_age_d::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		int y = diffYear(_args.at(1)->d(), _args.at(0)->d());
		_result.r(static_cast<double>(y));
	}
}
// -----------------------------------------------------------------------------
// age(T1,T2) 年齢計算(T2-T1)
// -----------------------------------------------------------------------------
void kgFunction_age_t::run(void)
{
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		int y = diffYear(_args.at(1)->t(), _args.at(0)->t());
		_result.r(static_cast<double>(y));
	}
}

// -----------------------------------------------------------------------------
// diffyear(D1,D2) 日付の引き算(D2-D1) 年数
// -----------------------------------------------------------------------------
void kgFunction_diffyear_d::run(void){
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
		return;
	}
	double diff = static_cast<double>(diffYear(_args.at(0)->d(), _args.at(1)->d()));
	_result.r(diff);
}
// -----------------------------------------------------------------------------
// diffyear(D1,D2) 日付の引き算(D2-D1) 月数
// -----------------------------------------------------------------------------
void kgFunction_diffmonth_d::run(void){
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
		return;
	}
	double diff = static_cast<double>(diffMonth(_args.at(0)->d(), _args.at(1)->d()));
	_result.r(diff);
}
// -----------------------------------------------------------------------------
// diffday(D1,D2) 日付の引き算(D2-D1) 日数
// -----------------------------------------------------------------------------
void kgFunction_diffday_d::run(void){
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
		return;
	}
	double diff = static_cast<double>(diffDay(_args.at(0)->d(), _args.at(1)->d()));
	_result.r(diff);
}

// -----------------------------------------------------------------------------
// diffyear(T1,T2) 時間の引き算(T2-T1) 年数
// -----------------------------------------------------------------------------
void kgFunction_diffyear_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	double diff = static_cast<double>(diffYear(_args.at(0)->t(), _args.at(1)->t()));
	_result.r(diff);
}
// -----------------------------------------------------------------------------
// diffmonth(T1,T2) 時間の引き算(T2-T1) 月数
// -----------------------------------------------------------------------------
void kgFunction_diffmonth_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	double diff = static_cast<double>(diffMonth(_args.at(0)->t(), _args.at(1)->t()));
	_result.r(diff);
}
// -----------------------------------------------------------------------------
// diffday(T1,T2) 時間の引き算(T2-T1) 日数
// -----------------------------------------------------------------------------
void kgFunction_diffday_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	double diff = static_cast<double>(diffDay(_args.at(0)->t(), _args.at(1)->t()));
	_result.r(diff);
}

// -----------------------------------------------------------------------------
// diffhour(T1,T2) 時間の引き算(T2-T1) 時間数
// -----------------------------------------------------------------------------
void kgFunction_diffhour_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	time_duration td= *_args.at(0)->t() - *_args.at(1)->t(); 
	double diff =  static_cast<double>(td.total_seconds()/3600);
	_result.r(diff);
}
// -----------------------------------------------------------------------------
// diffminute(T1,T2) 時間の引き算(T2-T1) 分数
// -----------------------------------------------------------------------------
void kgFunction_diffminute_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	time_duration td= *_args.at(0)->t() - *_args.at(1)->t(); 
	double diff =  static_cast<double>(td.total_seconds()/60);
	_result.r(diff);
}
// -----------------------------------------------------------------------------
// diffsecond(T1,T2) 時間の引き算(T2-T1) 秒数
// -----------------------------------------------------------------------------
void kgFunction_diffsecond_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	time_duration td= *_args.at(0)->t() - *_args.at(1)->t(); 
	double diff =  static_cast<double>(td.total_seconds());
	_result.r(diff);
}

// -----------------------------------------------------------------------------
// diffusecond(T1,T2) 時間の引き算(T2-T1) マイクロ対応
// -----------------------------------------------------------------------------
void kgFunction_diffusecond_t::run(void){
	if( _args.at(0)->null() || _args.at(1)->null()  ){
		_result.null(true);
		return;
	}
	time_duration td= *_args.at(0)->t() - *_args.at(1)->t(); 
//	double diff =  static_cast<double>( td.total_microseconds() );
	double diff = static_cast<double>( td.total_seconds()*time_duration::ticks_per_second() +  td.fractional_seconds() )/ time_duration::ticks_per_second();
	_result.r(diff);
}



// -----------------------------------------------------------------------------
// year(DorT) 年を抽出
// -----------------------------------------------------------------------------
// year(D)
void kgFunction_year_d::run(void)
{
	if( _args.at(0)->null() )
	{
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->d()->year()) );
	}
}
// year(T)
void kgFunction_year_t::run(void){
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->date().year()) );
	}
}
// -----------------------------------------------------------------------------
// years(DorT) 年を抽出
// -----------------------------------------------------------------------------
// years(D)
void kgFunction_years_d::run(void)
{
	if( _args.at(0)->null() )
	{
		_result.null(true);
	}else{
		sprintf( _buf,"%04d",static_cast<int>(_args.at(0)->d()->year()) );
		_result.s(_buf);
	}
}
// years(T)
void kgFunction_years_t::run(void){
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		sprintf( _buf,"%04d", static_cast<int>(_args.at(0)->t()->date().year()) );
		_result.s( _buf );
	}
}
// -----------------------------------------------------------------------------
// month(DorT) 月を抽出
// -----------------------------------------------------------------------------
// month(D)
void kgFunction_month_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->d()->month()) );
	}
}
// month(T)
void kgFunction_month_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->date().month()) );
	}
}
// -----------------------------------------------------------------------------
// months(DorT) 月を抽出
// -----------------------------------------------------------------------------
// months(D)
void kgFunction_months_d::run(void)
{
	if( _args.at(0)->null() )
	{
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", static_cast<int>(_args.at(0)->d()->month()) );
		_result.s(_buf);
	}
}
// months(T)
void kgFunction_months_t::run(void){
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", static_cast<int>(_args.at(0)->t()->date().month()) );
		_result.s( _buf );
	}
}
// -----------------------------------------------------------------------------
// emonth(DorT) 英語表記月を抽出
// -----------------------------------------------------------------------------
const char* kgFunction_emonth::_str[13]=
{
	"","January","February","March","April","May","June",
	"July","August","September","October","November","December"
};
// emonth(D)
void kgFunction_emonth_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[0]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->d()->month())]) );
	}
}
// emonth(T)
void kgFunction_emonth_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[0]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->t()->date().month())]) );
	}
}
// -----------------------------------------------------------------------------
// esmonth(DorT) 英語短縮表記月を抽出
// -----------------------------------------------------------------------------
const char* kgFunction_esmonth::_str[13]=
{
	"","Jan","Feb","Mar","Apr","May","Jun",
	"Jul","Aug","Sep","Oct","Nov","Dec"
};
// esmonth(D) 
void kgFunction_esmonth_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[0]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->d()->month())]) );
	}
}
// esmonth(T) 
void kgFunction_esmonth_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[0]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->t()->date().month())]) );
	}
}
// -----------------------------------------------------------------------------
// day(DorT) 日抽出
// -----------------------------------------------------------------------------
// day(D)
void kgFunction_day_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->d()->day()) );
	}
}
// day(T)
void kgFunction_day_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->date().day()) );
	}
}
// -----------------------------------------------------------------------------
// days(DorT) 日を抽出
// -----------------------------------------------------------------------------
// days(D)
void kgFunction_days_d::run(void)
{
	if( _args.at(0)->null() )
	{
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", static_cast<int>(_args.at(0)->d()->day()) );
		_result.s(_buf);
	}
}
// days(T)
void kgFunction_days_t::run(void){
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", static_cast<int>(_args.at(0)->t()->date().day()) );
		_result.s( _buf );
	}
}
// -----------------------------------------------------------------------------
// week(DorT)  週数抽出
// -----------------------------------------------------------------------------
// N week(D)
void kgFunction_week_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->d()->week_number()) );
	}
}
// N week(T)
void kgFunction_week_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->date().week_number()) );
	}
}

// -----------------------------------------------------------------------------
// week(DorT)  週数抽出(1/1:stast)
// -----------------------------------------------------------------------------
// N week(D)
void kgFunction_week111_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		date s(_args.at(0)->d()->year(),1,1);
		int diff = (*(_args.at(0)->d()) - s).days();
		_result.r( diff/7+1 );
	}
}
// N week(T)
void kgFunction_week111_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		date s(_args.at(0)->t()->date().year(),1,1);
		int diff = (_args.at(0)->t()->date() - s).days();
		_result.r( diff/7+1 );
	}
}
// -----------------------------------------------------------------------------
// dow(DorT)  曜日番号抽出(7:日曜)
// -----------------------------------------------------------------------------
// dow(D)
void kgFunction_dow_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		int wno=_args.at(0)->d()->day_of_week();
		if(wno==0){ _result.r(7);}
		else			{ _result.r( wno );}
	}
}
// dow(T)
void kgFunction_dow_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		int wno=_args.at(0)->t()->date().day_of_week();
		if(wno==0){ _result.r(7);}
		else			{ _result.r( wno );}
	}
}
// -----------------------------------------------------------------------------
// edow(日付) => 文字列 : 曜日抽出(英語表記)
// -----------------------------------------------------------------------------
const char* kgFunction_edow::_str[8]=
{
	"Sunday","Monday","Tuesday","Wednesday",
	"Thursday","Friday","Saturday",""
};
//edow(D)
void kgFunction_edow_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[7]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->d()->day_of_week())]) );
	}
}
//edow(T)
void kgFunction_edow_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[7]));
	}else{
		_result.s(const_cast<char*>(_str[static_cast<int>(_args.at(0)->t()->date().day_of_week())]) );
	}
}
// -----------------------------------------------------------------------------
// esdow(DorT) => 文字列 : 曜日抽出(短縮英語表記)
// -----------------------------------------------------------------------------
const char* kgFunction_esdow::_str[8]=
{
	"Sun","Mon","Tue","Wed",
	"Thu","Fri","Sat",""
};
// S esdow(D)
void kgFunction_esdow_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[7]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->d()->day_of_week())]) );
	}
}
// S esdow(T)
void kgFunction_esdow_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[7]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->t()->date().day_of_week())]) );
	}
}

// -----------------------------------------------------------------------------
// esdowj(DorT) => 文字列 : 曜日抽出(日本語表記)
// -----------------------------------------------------------------------------
const char* kgFunction_dowj::_str[8]=
{
	"日","月","火","水",
	"木","金","土",""
};
// S esdow(D)
void kgFunction_dowj_d::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[7]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->d()->day_of_week())]) );
	}
}
// S esdow(T)
void kgFunction_dowj_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.s(const_cast<char*>(_str[7]));
	}else{
		_result.s( const_cast<char*>(_str[static_cast<int>(_args.at(0)->t()->date().day_of_week())]) );
	}
}
// -----------------------------------------------------------------------------
// hour(時刻) => 数値 : 時間抽出
// -----------------------------------------------------------------------------
void kgFunction_hour_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->time_of_day().hours()) );
	}
}
// -----------------------------------------------------------------------------
// hours(時刻) => 数値 : 時間抽出
// -----------------------------------------------------------------------------
void kgFunction_hours_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", _args.at(0)->t()->time_of_day().hours());
		_result.s(_buf);
	}
}
// -----------------------------------------------------------------------------
// minute(時刻) => 数値 : 分抽出
// -----------------------------------------------------------------------------
void kgFunction_minute_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->time_of_day().minutes()) );
	}
}
// -----------------------------------------------------------------------------
// minutes(時刻) => 文字列 : 分抽出
// -----------------------------------------------------------------------------
void kgFunction_minutes_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", _args.at(0)->t()->time_of_day().minutes());
		_result.s(_buf);
	}
}
// -----------------------------------------------------------------------------
// seconds(時刻) => 数値 : 秒抽出
// -----------------------------------------------------------------------------
void kgFunction_second_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->time_of_day().seconds()) );
	}
}
// -----------------------------------------------------------------------------
// useconds(時刻) => 数値 : 秒抽出マイクロ秒対応
// -----------------------------------------------------------------------------
void kgFunction_usecond_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
//	double diff = static_cast<double>( td.total_seconds()*time_duration::ticks_per_second() +  td.fractional_seconds() )/ time_duration::ticks_per_second();
		_result.r( 
			static_cast<double>( _args.at(0)->t()->time_of_day().seconds() * time_duration::ticks_per_second() +  _args.at(0)->t()->time_of_day().fractional_seconds() ) / time_duration::ticks_per_second()
		);
	}
}
// -----------------------------------------------------------------------------
// seconds(時刻) => 数値 : 秒抽出
// -----------------------------------------------------------------------------
void kgFunction_seconds_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		sprintf( _buf,"%02d", _args.at(0)->t()->time_of_day().seconds());
		_result.s(_buf);
	}
}

// -----------------------------------------------------------------------------
// seconds(時刻) => 数値 : 秒抽出マイクロ対応
// -----------------------------------------------------------------------------
void kgFunction_useconds_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		char fmt[32];
		sprintf(fmt,"%%02d.%%0%dlld",time_duration::num_fractional_digits() );
		sprintf(_buf,fmt, 
			_args.at(0)->t()->time_of_day().seconds(),
			_args.at(0)->t()->time_of_day().fractional_seconds()
		);
		_result.s(_buf);
	}
}
// -----------------------------------------------------------------------------
// tseconds(時刻) => 数値 : トータルの秒数計算
// -----------------------------------------------------------------------------
void kgFunction_tseconds_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(_args.at(0)->t()->time_of_day().total_seconds()) );
	}
}
// -----------------------------------------------------------------------------
// tseconds(時刻) => 数値 : トータルの秒数計算
// -----------------------------------------------------------------------------
void kgFunction_tuseconds_t::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( 
			static_cast<double>( 
			_args.at(0)->t()->time_of_day().total_seconds() * time_duration::ticks_per_second() 
			+ _args.at(0)->t()->time_of_day().fractional_seconds() 
			) / time_duration::ticks_per_second()
		);
	}
}

// ============================================================================
// 数値関連クラス
// ============================================================================
// -----------------------------------------------------------------------------
// sum(数値,...,数値) => 数値 : 合計(NULLはskip)
// -----------------------------------------------------------------------------
void kgFunction_sum::run(void)
{	
	double s=0;
	int    count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			continue;
		}else{
			s+=_args.at(i)->r();
			count++;
		}
	}
	if(count==0){ _result.null(true);}
	else				{	_result.r(s);}
}
// -----------------------------------------------------------------------------
// sum_N(数値,...,数値,文字列) => 数値 : 合計(1でもNULLが有ると結果はNULL)
//  文字列には-nが入る
// -----------------------------------------------------------------------------
void kgFunction_sum_N::preprocess(void)
{	
	if(_args.at(_args.size()-1)->s()==NULL || 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
}
void kgFunction_sum_N::run(void)
{	
	if( 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
	double s=0;
	for( vector<int>::size_type i=0; i<_args.size()-1; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			s+=_args.at(i)->r();
		}
	}
	_result.r(s);
}
// -----------------------------------------------------------------------------
// avg(数値,...,数値) => 数値 : 平均計算(NULLはskip)
// -----------------------------------------------------------------------------
void kgFunction_avg::run(void)
{	
	double s=0;
	int    count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			continue;
		}else{
			s+=_args.at(i)->r();
			count++;
		}
	}
	if(count==0){ _result.null(true);}
	else				{	_result.r(s/static_cast<double>(count));
	}
}
// -----------------------------------------------------------------------------
// avg(数値,...,数値,文字列) => 数値 : 平均計算(1でもNULLが有ると結果はNULL)
//  文字列には-nが入る
// -----------------------------------------------------------------------------
void kgFunction_avg_N::preprocess(void)
{	
	if(_args.at(_args.size()-1)->s()==NULL || 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
}
void kgFunction_avg_N::run(void)
{	
	if( 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
	double s=0;
	for( vector<int>::size_type i=0; i<_args.size()-1; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			s+=_args.at(i)->r();
		}
	}
	_result.r(s/static_cast<double>(_args.size()-1));
}
// -----------------------------------------------------------------------------
// sqsum(数値,...,数値) => 数値 : 平方合計(NULLはskip)
// -----------------------------------------------------------------------------
void kgFunction_sqsum::run(void)
{	
	double s=0;
	int    count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			continue;
		}else{
			s+= (_args.at(i)->r() * _args.at(i)->r());
			count++;
		}
	}
	if(count==0){ _result.null(true);} 
	else				{	_result.r(s);}
}
// -----------------------------------------------------------------------------
// sqsuma(数値,...,数値,文字列) => 数値 : 平方合計(1でもNULLが有ると結果はNULL)
//  文字列には-nが入る
// -----------------------------------------------------------------------------
void kgFunction_sqsum_N::preprocess(void)
{	
	if(_args.at(_args.size()-1)->s()==NULL || 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
}
void kgFunction_sqsum_N::run(void)
{	
	double s=0;
	for( vector<int>::size_type i=0; i<_args.size()-1; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			s+= (_args.at(i)->r() * _args.at(i)->r());
		}
	}
	_result.r(s);
}
// -----------------------------------------------------------------------------
// factorial(数値) => 数値 : 階乗計算
// -----------------------------------------------------------------------------
void kgFunction_factorial::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = tgamma(_args.at(0)->r()+1.0);
		if(isfinite(v))	{ _result.r( v );}
		else 						{ _result.null(true);}
	}
}
// -----------------------------------------------------------------------------
// gcd(数値,数値) => 数値 : 最大公約数計算
// -----------------------------------------------------------------------------
void kgFunction_gcd::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		_result.r( static_cast<double>(
			kglib::gcd(static_cast<int>(fabs(_args.at(0)->r())),
			           static_cast<int>(fabs(_args.at(1)->r())))
		));
	}
}
// -----------------------------------------------------------------------------
// lcm(数値,数値) => 数値 : 最小公倍数計算
// -----------------------------------------------------------------------------
void kgFunction_lcm::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		int a=static_cast<int>(_args.at(0)->r());
		int b=static_cast<int>(_args.at(1)->r());
		if(a==0 || b==0){
			_result.null(true);
		}else{
			_result.r(static_cast<double>(kglib::lcm(a,b)));
		}
	}
}
// -----------------------------------------------------------------------------
// sqrt(数値) => 数値 : 平方根計算
// -----------------------------------------------------------------------------
void kgFunction_sqrt::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = sqrt(_args.at(0)->r());
		if( isfinite(v)) { _result.r( v );}
		else 						 { _result.null(true);}
	}
}
// -----------------------------------------------------------------------------
// fract(数値) => 数値 : 小数部分抽出
// -----------------------------------------------------------------------------
void kgFunction_fract::run(void)
{	
	double i;
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( modf(_args.at(0)->r(), &i) );
	}
}
// -----------------------------------------------------------------------------
// int(数値) => 数値 : 整数部分抽出
// -----------------------------------------------------------------------------
void kgFunction_int::run(void)
{	
	double i;
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		modf(_args.at(0)->r(), &i );
		_result.r( i );
	}
}
// -----------------------------------------------------------------------------
// min(数値,...,数値) => 数値 : 最小値計算(NULLはskip)
// -----------------------------------------------------------------------------
void kgFunction_min::run(void)
{	
	double s=DBL_MAX;
	int    count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			continue;
		}else{
			if( s > _args.at(i)->r() ) s=_args.at(i)->r();
			count++;
		}
	}
	if(count==0){_result.null(true);}
	else				{ _result.r(s);}
}
// -----------------------------------------------------------------------------
// min(数値,...,数値,文字列) => 数値 : 最小値計算(1でもNULLが有ると結果はNULL)
//  文字列には-nが入る
// -----------------------------------------------------------------------------
void kgFunction_min_N::preprocess(void)
{
	if(  _args.at(_args.size()-1)->s()==NULL || 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
}
void kgFunction_min_N::run(void)
{
	if( 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
	double s=DBL_MAX;
	for( vector<int>::size_type i=0; i<_args.size()-1; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			if( s > _args.at(i)->r() ) s=_args.at(i)->r();
		}
	}
	_result.r(s);
}
// -----------------------------------------------------------------------------
// max(数値,...,数値) => 数値 : 最大値計算(NULLはskip)
// -----------------------------------------------------------------------------
void kgFunction_max::run(void)
{	
	double s=-DBL_MAX;
	int    count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			continue;
		}else{
			if( s < _args.at(i)->r() ) s=_args.at(i)->r();
			count++;
		}
	}
	if(count==0){
		_result.null(true);
	}else{	
		_result.r(s);
	}
}
// -----------------------------------------------------------------------------
// max(数値,...,数値,文字列) => 数値 : 最大値計算(1でもNULLが有ると結果はNULL)
//  文字列には-nが入る
// -----------------------------------------------------------------------------
void kgFunction_max_N::preprocess(void)
{
	if(  _args.at(_args.size()-1)->s()==NULL || 0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
}
void kgFunction_max_N::run(void)
{	
	double s=-DBL_MAX;
	for( vector<int>::size_type i=0; i<_args.size()-1; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			if( s < _args.at(i)->r() ) s=_args.at(i)->r();
		}
	}
	_result.r(s);
}
// -----------------------------------------------------------------------------
// abs(数値) => 数値 : 絶対値計算
// -----------------------------------------------------------------------------
void kgFunction_abs::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( fabs(_args.at(0)->r()) );
	}
}
// -----------------------------------------------------------------------------
// round(数値1,数値2) => 数値 : 四捨五入計算(数値１を数値2の値で四捨五入)
// -----------------------------------------------------------------------------
void kgFunction_round::run(void)
{
	if( _args.size()==1){
		if( _args.at(0)->null() ){
			_result.null(true);
		}else{
			_result.r( 
				floor(_args.at(0)->r() + 0.5)
			);		
		}
	}
	else{
		if( _args.at(0)->null() || _args.at(1)->null() ){
			_result.null(true);
		}else{
			//データを丸め
			char t[256];
			sprintf(t,_dblFmt,_args.at(0)->r()/_args.at(1)->r()+0.5);
			_result.r( floor(atof(t))*_args.at(1)->r());
		}
	}
}
// -----------------------------------------------------------------------------
// power(数値1,数値2) => 数値 : べき乗計算(数値１を数値2の値でべき乗)
// -----------------------------------------------------------------------------
void kgFunction_power::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		double v = pow(_args.at(0)->r(),_args.at(1)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// floor(数値1,数値2) => 数値 : 切捨計算(数値１を数値2の値で切り捨てて０に近い値にする)
// -----------------------------------------------------------------------------
void kgFunction_floor::run(void)
{	
	if( _args.size()==1){
		if( _args.at(0)->null() ){
			_result.null(true);
		}else{
			_result.r( 
				floor(_args.at(0)->r())
			);		
		}
	}
	else{
		if( _args.at(0)->null() || _args.at(1)->null() ){
			_result.null(true);
		}else{
			char t[256];
			sprintf(t,_dblFmt,_args.at(0)->r()/_args.at(1)->r());
			double v = floor(atof(t))*_args.at(1)->r();
			_result.r( v );
		}
	}
}
// -----------------------------------------------------------------------------
// ceil(数値1,数値2) => 数値 : 切上計算(数値１を数値2の値で切り上げて０に遠い値にする)
// -----------------------------------------------------------------------------
void kgFunction_ceil::run(void)
{	
	if( _args.size()==1){
		if( _args.at(0)->null() ){
			_result.null(true);
		}else{
			_result.r( 
				ceil(_args.at(0)->r())
			);		
		}
	}
	else{
		if( _args.at(0)->null() || _args.at(1)->null() ){
			_result.null(true);
		}else{
			char t[256];
			sprintf(t,_dblFmt,_args.at(0)->r()/_args.at(1)->r());
			double v= ceil(atof(t))*_args.at(1)->r();
			_result.r( v );
		}
	}
}
// -----------------------------------------------------------------------------
// exp(数値) => 数値 : eを底とするべき乗計算
// -----------------------------------------------------------------------------
void kgFunction_exp::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v= exp(_args.at(0)->r());
		if( isfinite(v) )	{ _result.r( v );}
		else 							{ _result.null(true);}
	}
}
// -----------------------------------------------------------------------------
// ln(数値) => 数値 : 自然対数計算
// -----------------------------------------------------------------------------
void kgFunction_ln::run(void)
{	
	double v;
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		v= log(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// log(数値) => 数値 : 対数計算
// -----------------------------------------------------------------------------
void kgFunction_log::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		double v= log(_args.at(0)->r())/log(_args.at(1)->r());
		if( isfinite(v)){ _result.r( v );}
		else 						{ _result.null(true);}
	}
}
// -----------------------------------------------------------------------------
// log2(数値) => 数値 : 2を底とする対数計算
// -----------------------------------------------------------------------------
void kgFunction_log2::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v= log(_args.at(0)->r())/log(2.0);
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// log10(数値) => 数値 : 10を底とする対数計算
// -----------------------------------------------------------------------------
void kgFunction_log10::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = log(_args.at(0)->r())/log(10.0);
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// product(数値,...,数値) => 数値 : 数値すべての積(NULLはskip)
// -----------------------------------------------------------------------------
void kgFunction_product::run(void)
{	
	double s=1;
	int    count=0;
	for( vector<int>::size_type i=0; i<_args.size(); i++){
		if( _args.at(i)->null() ){
			continue;
		}else{
			s*=_args.at(i)->r();
			count++;
		}
	}
	if(count==0)	{ _result.null(true);}
	else					{ _result.r(s);}
}
// -----------------------------------------------------------------------------
// product(数値,...,数値,文字列) => 数値 : 数値すべての積(1でもNULLが有ると結果はNULL)
//  文字列には-nが入る
// -----------------------------------------------------------------------------
void kgFunction_product_N::preprocess(void)
{
	if( _args.at(_args.size()-1)->s()==NULL ||
			0!=strcmp(_args.at(_args.size()-1)->s(),"-n") ){
		throw kgError("not exist -n parameter");	
	}
}

void kgFunction_product_N::run(void)
{	
	double s=1;
	for( vector<int>::size_type i=0; i<_args.size()-1; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return;
		}else{
			s*=_args.at(i)->r();
		}
	}
	_result.r(s);
}
// -----------------------------------------------------------------------------
// sign(数値) => 数値 : 正負符号を判定する(正:1,負:-1,0:0)
// -----------------------------------------------------------------------------
void kgFunction_sign::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
				 if( _args.at(0)->r() == 0 ){ _result.r(  0 );}
		else if( _args.at(0)->r() < 0 )	{ _result.r( -1 );}
		else 														{ _result.r(  1 );}
	}
}

// -----------------------------------------------------------------------------
// dist(距離関数名,数値,...,数値[2n]) => 数値 : n次元の2点の座標間のユークリッド距離を計算
// -----------------------------------------------------------------------------
void kgFunction_dist::preprocess(void)
{
	if( _args.size()%2 != 1 ){
		throw kgError("the number of arguments must be odd number");
	}
	// タイプセット
	char *p = _args.at(0)->s();
	if(p==NULL){
		throw kgError("type error :specify euclid or cityblock");			
	}
	if(!strcmp(p,"euclid"))					{ _type=1;}
	else if(!strcmp(p,"cityblock"))	{ _type=2;}
	else{
		throw kgError("type error :specify euclid or cityblock");	
	}
	_dim=(_args.size()-1)/2;
}
void kgFunction_dist::run(void)
{
	double v=0;
	for( vector<int>::size_type i=1; i<=_dim; i++){
		if( _args.at(i)->null() || _args.at(_dim+i)->null() ){
			_result.null(true);
			return;
		}else{
			switch(_type){
			case 1:
				v+=(_args.at(i)->r()-_args.at(_dim+i)->r())*
				   (_args.at(i)->r()-_args.at(_dim+i)->r());
				break;
			case 2:
				v+=fabs(_args.at(i)->r()-_args.at(_dim+i)->r());
				break;
			}
		}
	}
	if(_type==1){	_result.r(sqrt(v));}
	else				{	_result.r(v);}
}
// -----------------------------------------------------------------------------
// disth(数値,...,数値[2n]) => 数値 : n次元の2点の座標間のハミング距離を計算
// -----------------------------------------------------------------------------
void kgFunction_disth::preprocess(void)
{
	if( _args.size()%2 != 1 ){
		throw kgError("the number of arguments must be odd number");
	}
	if(_args.at(0)->s() == NULL || strcmp(_args.at(0)->s(),"hamming")){
		throw kgError("type error : specify hamming");	
	}
	_dim=(_args.size()-1)/2;
}
void kgFunction_disth::run(void)
{	
	double v=0;
	for( vector<int>::size_type i=1; i<=_dim; i++){
		if( _args.at(i)->null() || _args.at(_dim+i)->null() ){
			_result.null(true);
			return;
		}else{
			if( !strcmp(_args.at(i)->s(),_args.at(_dim+i)->s()) ){
			  v+=1;
			}
		}
	}
	_result.r(v);
}
// -----------------------------------------------------------------------------
// distgps(数値[緯度],数値[経度],数値[緯度],数値[経度])(北緯,東経がデフォルト) 
//   => 数値 : 2点の緯度経度から距離を計算
//  参考：http://www.kiteretsu-so.com/archives/1183
// -----------------------------------------------------------------------------
const double kgFunction_distgps::Eradius_=6378.137;
void kgFunction_distgps::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ||
			_args.at(2)->null() || _args.at(3)->null() )
	{
		_result.null(true);
		return;
	}
	if( fabs(_args.at(0)->r())>90 || fabs(_args.at(2)->r())>90 ||
		fabs(_args.at(1)->r())>180||fabs(_args.at(3)->r())>180) {
		_result.null(true);
		return;
	}
	double ido_diff_d = fabs(_args.at(0)->r() - _args.at(2)->r());
	double kdo_diff_d = fabs(_args.at(1)->r() - _args.at(3)->r());
	if(kdo_diff_d>180){ kdo_diff_d = 360-kdo_diff_d;}	
	double ido_diff = ( ido_diff_d) * M_PI/180.0;
	double kdo_diff = ( kdo_diff_d ) * M_PI/180.0;
	double leng_y = Eradius_ * ido_diff;
	double leng_x = cos(_args.at(0)->r()*M_PI/180.0) * Eradius_ * kdo_diff;
	_result.r( sqrt(pow(leng_x,2)+pow(leng_y,2)) );
}

// -----------------------------------------------------------------------------
// heron(数値,...,数値[3n]) => 数値 : n次元の3点の座標によって作られる3角形の面積を計算
// -----------------------------------------------------------------------------
void kgFunction_heron::preprocess(void)
{
	if( _args.size()%3 != 0 ){
		throw kgError("the number of arguments must be multiple of 3");
	}
	_dim=_args.size()/3;
}
void kgFunction_heron::run(void)
{	
	double a=0, b=0, c=0;
	for( vector<int>::size_type i=0; i<_dim; i++){
		if( _args.at(       i)->null() ||
		    _args.at(  _dim+i)->null() ||
		    _args.at(2*_dim+i)->null()){
			_result.null(true);
			return;
		}else{
			double A=_args.at(       i)->r();
			double B=_args.at(  _dim+i)->r();
			double C=_args.at(2*_dim+i)->r();
			a+=(A-B)*(A-B);
			b+=(B-C)*(B-C);
			c+=(C-A)*(C-A);
		}
	}
	a=sqrt(a);
	b=sqrt(b);
	c=sqrt(c);
	double s=(a+b+c)/2;
	_result.r(sqrt(s*(s-a)*(s-b)*(s-c)));
}
// -----------------------------------------------------------------------------
// rand(数値[最小値]，数値[最大値]，数値[シード]) => 数値 : 一様乱数を発生させる
// 引数が2つの場合,最小値,最大値と見なす
// 引数が3つの場合,最小値,最大値,seedと見なす
// -----------------------------------------------------------------------------
//前処理
void kgFunction_rand::preprocess(void)
{
	for(size_t i=0 ; i< _args.size() ; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return ;
		}
	} 

	int start = 0;
	int end   = INT_MAX;
	unsigned long seed = 0;
	if(_args.size()==2){
		start = static_cast<int>(_args.at(0)->r());
		end   = static_cast<int>(_args.at(1)->r());
		// 乱数の種生成（時間）
		posix_time::ptime now = posix_time::microsec_clock::local_time();
		posix_time::time_duration nowt = now.time_of_day();
		seed = static_cast<unsigned long>(nowt.total_microseconds());
	}
	else { //arg = 3
		start = static_cast<int>(_args.at(0)->r());
		end   = static_cast<int>(_args.at(1)->r());
		seed  = static_cast<unsigned long>(_args.at(2)->r());
	}
	if( start > end){
		int swp = end;
		end = start;
		start = swp;
	}
	uniform_int<> dst(start,end);
	try {
		_api.set( new variate_generator< mt19937,uniform_int<> >
					(mt19937(seed),dst) );
		_result.null(false);
	}catch(...){
		_result.null(true);
	}
}
// 整数値の一様乱数を発生 	
void kgFunction_rand::run(void)
{	
	if( !_result.null() ){ _result.r( (*_api.get())() ); }
}
// -----------------------------------------------------------------------------
// rand(数値[seed]) => 数値 : 一様乱数を発生させる
// -----------------------------------------------------------------------------
//前処理
void kgFunction_rand_real::preprocess(void)
{
	unsigned long seed = 0;
	if( _args.size()==0 ){
		// 乱数の種生成（時間）
		posix_time::ptime now = posix_time::microsec_clock::local_time();
		posix_time::time_duration nowt = now.time_of_day();
		seed = static_cast<unsigned long>(nowt.total_microseconds());
	
	}else{
		if( _args.at(0)->null() ){
			_result.null(true);
			return ;
		}
		seed  = static_cast<unsigned long>(_args.at(0)->r());
	}
	uniform_real<> dst(0,1);
	try {
		_apr.set( new variate_generator< mt19937,uniform_real<> >
				(mt19937(seed),dst) );
		_result.null(false);
	}catch(...){
		_result.null(true);
	}
}
// 実数値の一様乱数を発生 	
void kgFunction_rand_real::run(void)
{	
	if( !_result.null() ){ _result.r( (*_apr.get())() ); }
}
// -----------------------------------------------------------------------------
// nrand(平均値，標準偏差，シード) => 数値 : 一様乱数を発生させる
// 引数が2つの場合,平均値,標準偏差と見なす
// 引数が3つの場合,平均値,標準偏差,最大値,seedと見なす
// -----------------------------------------------------------------------------
void kgFunction_nrand::preprocess(void)
{
	for(size_t i=0 ; i< _args.size() ; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return ;
		}
	} 
	double avg  = _args.at(0)->r();
	double std  = _args.at(1)->r();
	unsigned long seed;
	if(_args.size()==2){
		// 乱数の種生成（時間）
		posix_time::ptime now = posix_time::microsec_clock::local_time();
		posix_time::time_duration nowt = now.time_of_day();
		seed = static_cast<unsigned long>(nowt.total_microseconds());
	}else{
		seed = static_cast<unsigned long>(_args.at(2)->r());
	}
	normal_distribution<> dst(avg,std);
	try {
		_ap.set( new variate_generator< mt19937,normal_distribution<> >
			(mt19937(seed),dst) );
		_result.null(false);
	}catch(...){
		_result.null(true);
	}
}
// double値の正規乱数を発生 	
void kgFunction_nrand::run(void){	
	if( !_result.null() ){
		_result.r( (*_ap.get())() );
	}
}
// -----------------------------------------------------------------------------
// berrand(数値[?]，数値[シード]) => 数値 : ベルヌーイ分布に基づいた乱数生成
// -----------------------------------------------------------------------------
// ベルヌーイ分布に基づいた乱数生成::初期設定 	
void kgFunction_berrand::preprocess(void)
{
	for(size_t i=0 ; i< _args.size() ; i++){
		if( _args.at(i)->null() ){
			_result.null(true);
			return ;
		}
	} 

	double p  = _args.at(0)->r();
	if(p<0 || p>1) { 
		_result.null(true);
		return;
	}
	unsigned long seed;
	
	if(_args.size()==1){
		// 乱数の種生成（時間）
		posix_time::ptime now = posix_time::microsec_clock::local_time();
		posix_time::time_duration nowt = now.time_of_day();
		seed = static_cast<unsigned long>(nowt.total_microseconds());
	}else{
		seed = static_cast<unsigned long>(_args.at(1)->r());
	}
	bernoulli_distribution<> dst(p);
	try {
		_ap.set( new variate_generator< mt19937,bernoulli_distribution<> >
						(mt19937(seed),dst) );
		_result.null(false);
	}catch(...){
		_result.null(true);
	}
}
// 成功確率pにおける成功(true)もしくは失敗(false)を乱数として発生 	
void kgFunction_berrand::run(void){	
	if( !_result.null() ){
		_result.b( (*_ap.get())() );
	}
}
// -----------------------------------------------------------------------------
// binomdist(数値[成功回数],数値[試行回数],数値[確率]) => 数値 : 二項分布の確率?
// -----------------------------------------------------------------------------
/*
void kgFunction_binomdist::preprocess(void)
{
	ub_=200;
	pascal_.resize(ub_+1);
	for(size_t i=0; i<=ub_; i++){
		pascal_.at(i).resize(ub_+1);
	}
	pascal_.at(0).at(0)=1;
	for(size_t i=1; i<=ub_; i++){
		pascal_.at(i).at(0)=1;
		pascal_.at(i).at(1)=i;
		for(size_t j=2; j<=i; j++){
			pascal_.at(i).at(j)=pascal_.at(i-1).at(j-1)+pascal_.at(i-1).at(j);
		}
	}
}
*/
void kgFunction_binomdist::run(void)
{	
	//double accum=0.0;
	if( _args.at(0)->null() || _args.at(1)->null() || _args.at(2)->null() ){
		_result.null(true);
	}else{
		size_t x = static_cast<int>(_args.at(0)->r());
		size_t n = static_cast<int>(_args.at(1)->r());
		double p = _args.at(2)->r();
		//double q = 1-p;
		try {
			boost::math::binomial b(n,p);
			_result.r(boost::math::cdf(b,x));
		}catch(...){
			_result.null(true);
		}

		//_result.r(0.0);
		// 試行回数が多い時は正規分布で近似する
/*
		if(x > ub_){
			double xd    = static_cast<double>(x);
			double mean = static_cast<double>(n)*p;
			double sd   = sqrt(static_cast<double>(n)*p*q);
			//accum = 1.0 - (1+erf((xd - mean)/(sd * sqrt(2)))) * 0.5;
			accum = (1+erf((xd - mean)/(sd * sqrt(2)))) * 0.5;
			//accum = (1+erf((xd - mean + 0.5)/sd;
			end
		}else{
			//for(size_t i=x; i<=n; i++){
			for(size_t i=0; i<=x; i++){
				accum += pascal_.at(n).at(i) * pow(p,static_cast<double>(i))*pow(q,static_cast<double>(n-i));
			}
		}
		_result.r(accum);
*/
	}
}
// ============================================================================
// 三角関数関連クラス
// ============================================================================
// -----------------------------------------------------------------------------
// acos(数値) => 数値 : アークコサインを計算
// -----------------------------------------------------------------------------
void kgFunction_acos::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = acos(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// asin(数値) => 数値 : アークサインを計算
// -----------------------------------------------------------------------------
// N asin(N)
void kgFunction_asin::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = asin(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// atan(数値) => 数値 : アークタンジェントを計算
// -----------------------------------------------------------------------------
void kgFunction_atan::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = atan(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// atan2(数値1,数値2) => 数値 : x,y座標(数値1,数値2)と原点を結ぶ線分とx軸とが作る角度を計算する
// -----------------------------------------------------------------------------
void kgFunction_atan2::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		_result.null(true);
	}else{
		double v = atan2(_args.at(1)->r(),_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// cos(数値) => 数値 : 数値(ラジアン)に相当するコサインを計算
// -----------------------------------------------------------------------------
void kgFunction_cos::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = cos(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// sin(数値) => 数値 : 数値(ラジアン)に相当するサインを計算
// -----------------------------------------------------------------------------
void kgFunction_sin::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = sin(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// tan(数値) => 数値 : 数値(ラジアン)に相当するタンジェントを計算
// -----------------------------------------------------------------------------
void kgFunction_tan::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = tan(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// degree(数値) => 数値 : 数値(ラジアン)を角度に変換する
// -----------------------------------------------------------------------------
void kgFunction_degree::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( _args.at(0)->r()*180.0/M_PI );
	}
}
// -----------------------------------------------------------------------------
// radian(数値) => 数値 : 数値(角度)をラジアンに変換する
// -----------------------------------------------------------------------------
void kgFunction_radian::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		_result.r( _args.at(0)->r()*M_PI/180.0 );
	}
}
// -----------------------------------------------------------------------------
// cosh(数値) => 数値 : 双曲線余弦(ハイパーボリックコサイン)を計算
// -----------------------------------------------------------------------------
void kgFunction_cosh::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = cosh(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// sinh(数値) => 数値 : 双曲線正弦(ハイパーボリックサイン)を計算する
// -----------------------------------------------------------------------------
void kgFunction_sinh::run(void)
{
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = sinh(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// -----------------------------------------------------------------------------
// tanh(数値) => 数値 : 双曲線逆正接(ハイパーボリックタンジェントの逆関数)を計算する
// -----------------------------------------------------------------------------
void kgFunction_tanh::run(void)
{	
	if( _args.at(0)->null() ){
		_result.null(true);
	}else{
		double v = tanh(_args.at(0)->r());
		if( isfinite(v))	_result.r( v );
		else 							_result.null(true);
	}
}
// ============================================================================
// 文字列関数クラス
// ============================================================================
// -----------------------------------------------------------------------------
// cat(文字列0，文字列1，...，文字列m) => 文字列 : 
//  文字列1...文字列mを文字列0（トークン）で結合する
// -----------------------------------------------------------------------------
void kgFunction_cat::run(void)
{	
	int tokLen=strlen(_args.at(0)->s());
	int len=strlen(_args.at(1)->s());
	if(len>=KG_MAX_STR_LEN){
		_result.null(true);
		return;
	}
	strcpy(_buf,_args.at(1)->s());
	if(_args.size()>2){
		for( vector<int>::size_type i=2; i<_args.size(); i++){
			len+=tokLen+strlen(_args.at(i)->s());
			if(len>=KG_MAX_STR_LEN){
				_result.null(true);
				return;
			}
			strcat(_buf,_args.at(0)->s());
			strcat(_buf,_args.at(i)->s());
		}
	}
	_result.s(_buf);
}
// -----------------------------------------------------------------------------
// length[w](文字列) => 数値 : 文字列の長さを計算
// -----------------------------------------------------------------------------
void kgFunction_length::run(void)
{	
	_result.r(strlen(_args.at(0)->s()));
} 
void kgFunction_lengthw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	_result.r(ws.length());
} 
// -----------------------------------------------------------------------------
// fixlen[w](文字列,数値,文字1[R|L],文字2) => 文字列 : 
//   文字列を数値分固定長に変換(文字1はR:右詰orL:左詰,文字2は詰める文字)
// -----------------------------------------------------------------------------
// 初期処理
void kgFunction_fixlen::preprocess(void)
{
	if( *_args.at(2)->s()!='R' && *_args.at(2)->s()!='L'){
		throw kgError("3rd argument must be `R' or `L'");
	}
}
void kgFunction_fixlenw::preprocess(void)
{
	if( *_args.at(2)->s()!='R' && *_args.at(2)->s()!='L'){
		throw kgError("3rd argument must be `R' or `L'");
	}
}
// padding
void kgFunction_fixlenw::run(void)
{	
	if( _args.at(1)->null() ){
		_result.null(true);
	}else{
		int   fixlen = static_cast<int>(_args.at(1)->r());
		if( fixlen >= KG_MAX_STR_LEN ){ throw kgError("too long string");}
		char  rl     = *_args.at(2)->s();
		wstring pad  = toWcs(_args.at(3)->s());
		pad.erase(1);
		wstring str  = toWcs(_args.at(0)->s());
		int   len    = str.size();

		int   slen   = len;        // 出力文字列長
		int   padlen = fixlen-len; // 詰め文字長
		// 対象文字列長lenが指定された固定文字列長より長い場合は途中で打ち切る．
  	if(len>fixlen){
			padlen = 0;
			slen   = fixlen;
		}
		if(rl=='L'){
			if(padlen==0) str.erase(slen);
			else          for(int i=0; i<padlen; i++) str+=pad; 
		}else{
			if(padlen==0) str.replace(0,len-slen,pad,0,0);
			else          for(int i=0; i<padlen; i++) str.insert(0,pad); 
		}
		string retstr=toMbs(str.c_str());
		if(retstr.size()>=KG_MAX_STR_LEN){
			_result.null(true);
		}else{
			strncpy(_buf, toMbs(str).c_str(), KG_MAX_STR_LEN-1);
			_result.s(_buf);
		}
	}
} 
void kgFunction_fixlen::run(void)
{	
	if(  _args.at(1)->null()  ){
		_result.null(true);
	}else{
		int   fixlen = static_cast<int>(_args.at(1)->r());
		if( fixlen >= KG_MAX_STR_LEN ){ throw kgError("too long string");}
		char  rl     = *_args.at(2)->s();
		char  pad    = *_args.at(3)->s();
		char* str    =  _args.at(0)->s();	
		int   len    = strlen(str);
		int   slen   = len;        // 出力文字列長
		int   padlen = fixlen-len; // 詰め文字長
		// 対象文字列長lenが指定された固定文字列長より長い場合は途中で打ち切る．
  	if(len>fixlen){
			padlen = 0;
			slen   = fixlen;
		}
		int pos=0; 
		if(rl=='L'){
			for(int i=0; i<slen  ; i++) _buf[pos++]=*(str+i); 
			for(int i=0; i<padlen; i++) _buf[pos++]=pad; 
		}else{
			for(int i=0; i<padlen; i++) _buf[pos++]=pad; 
			for(int i=len-slen; i<len  ; i++) _buf[pos++]=*(str+i); 
		}
		_buf[pos]='\0'; 
		_result.s(_buf);
	}
} 
// -----------------------------------------------------------------------------
// right[w](文字列,数値) => 文字列 : 文字列を右から数値分抽出
// -----------------------------------------------------------------------------
void kgFunction_right::run(void){	
	if( _args.at(0)->null() ||_args.at(1)->null() ){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int size = strlen(_args.at(0)->s());
		int len  = static_cast<int>(_args.at(1)->r());
		if(len<0){ len=0; }
		if( size >= KG_MAX_STR_LEN ){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		if( len > size ){
			len=size;
		}
		strncpy(_buf,_args.at(0)->s()+size-len,len);
		_buf[len]='\0';
		_result.s(_buf);
	}
} 
void kgFunction_rightw::run(void){	
	if( _args.at(0)->null() || _args.at(1)->null() ){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int c_size = strlen(_args.at(0)->s());
		int len  = static_cast<int>(_args.at(1)->r());
		if(len<0){ len=0; }
		if( c_size >= KG_MAX_STR_LEN ){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		wstring ws=toWcs(_args.at(0)->s());
		int size=ws.length();
		int pos = size-len ;
		if(pos<0){ pos=0; }
		strcpy(_buf,toMbs(ws.substr(pos)).c_str());
		_result.s(_buf);
	}
} 
// -----------------------------------------------------------------------------
// left(文字列,数値) => 文字列 : 文字列を左から数値分抽出
// -----------------------------------------------------------------------------
void kgFunction_left::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null()){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int size = strlen(_args.at(0)->s());
		int len  = static_cast<int>(_args.at(1)->r());
		if(len<0){ len=0; }
		if( size >= KG_MAX_STR_LEN ){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		if( len > size ){
			len=size;
		}
		strncpy(_buf,_args.at(0)->s(),len);
		_buf[len]='\0';
		_result.s(_buf);
	}
} 
void kgFunction_leftw::run(void)
{	
	if( _args.at(0)->null() ||_args.at(1)->null() ){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int size = strlen(_args.at(0)->s());
		int len  = static_cast<int>(_args.at(1)->r());
		if(len<0){ len=0; }
		if( size >= KG_MAX_STR_LEN ){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		wstring ws=toWcs(_args.at(0)->s());
		strcpy(_buf,toMbs(ws.substr(0,len)).c_str());
		_result.s(_buf);
	}
} 
// -----------------------------------------------------------------------------
// mid(文字列,数値[開始位置],数値[抽出長]) => 文字列 :
//  文字列を左から開始位置と抽出長を指定して抽出する
// -----------------------------------------------------------------------------
void kgFunction_mid::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() || _args.at(2)->null() ){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int size = strlen(_args.at(0)->s());
		int pos  = static_cast<int>(_args.at(1)->r());
		int len  = static_cast<int>(_args.at(2)->r());
		if(pos<0){ pos=0;}
		if(len<0){ len=0;}
		if( size >= KG_MAX_STR_LEN || pos >= size){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		if( pos+len > size ){
			len=size-pos;
		}
		strncpy(_buf,_args.at(0)->s()+pos,len);
		_buf[len]='\0';
		_result.s(_buf);
	}
} 
void kgFunction_midw::run(void)
{	
	if( _args.at(0)->null() || _args.at(1)->null() || _args.at(2)->null() ){
		*_buf='\0';
		_result.s(_buf);
	}else{
		int c_size = strlen(_args.at(0)->s());
		int pos  = static_cast<int>(_args.at(1)->r());
		int len  = static_cast<int>(_args.at(2)->r());
		if(pos<0){ pos=0;}
		if(len<0){ len=0;}
		if( c_size >= KG_MAX_STR_LEN ){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		wstring ws=toWcs(_args.at(0)->s());
		int size=ws.length();
		if( pos >= size){
			*_buf='\0';
			_result.s(_buf);
			return;
		}
		strcpy(_buf,toMbs(ws.substr(pos,len)).c_str());
		_result.s(_buf);
	}
} 
// -----------------------------------------------------------------------------
// toupper(文字列) => 文字列 : 文字列をすべて大文字に変更
// -----------------------------------------------------------------------------
void kgFunction_toupper::run(void)
{	
	char* pos=_args.at(0)->s();
	int i=0;
	while(*pos){
		_buf[i]=toupper(*pos);
		pos++;i++;
	}
	_buf[i]='\0';
	_result.s(_buf);
} 
// -----------------------------------------------------------------------------
// tolower(文字列) => 文字列 : 文字列をすべて小文字に変更
// -----------------------------------------------------------------------------
void kgFunction_tolower::run(void)
{	
	char* pos=_args.at(0)->s();
	int i=0;
	while(*pos){
		_buf[i]=tolower(*pos);
		pos++;i++;
	}
	_buf[i]='\0';
	_result.s(_buf);
} 
// -----------------------------------------------------------------------------
// capitalize(文字列) => 文字列 : 文字列の先頭を大文字に変更
// -----------------------------------------------------------------------------
void kgFunction_capitalize::run(void)
{	
	char* pos=_args.at(0)->s();
	int i=0;
	if(*pos){
		_buf[i]=toupper(*pos);
		pos++;i++;
		while(*pos){
			_buf[i]=*pos;
			pos++;i++;
		}
	}
	_buf[i]='\0';
	_result.s(_buf);
} 

// -----------------------------------------------------------------------------
// match(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのいずれかに文字列0が存在すれば真，しなければ偽(全マッチ)
// -----------------------------------------------------------------------------
void kgFunction_match::run(void)
{	
	char* s=_args.at(0)->s();
	for( vector<int>::size_type i=1; i<_args.size(); i++){
		if( 0==strcmp(_args.at(i)->s(),s) ){
			_result.b(true);
			return;
		}
	}
	_result.b(false);
}
// -----------------------------------------------------------------------------
// matcha(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのすべてに文字列0が存在すれば真，しなければ偽(全マッチ)
// -----------------------------------------------------------------------------
void kgFunction_matcha::run(void)
{	
	char* s=_args.at(0)->s();
	for( vector<int>::size_type i=1; i<_args.size(); i++){
		if( 0!=strcmp(_args.at(i)->s(),s) ){
			_result.b(false);
			return;
		}
	}
	_result.b(true);
}
// -----------------------------------------------------------------------------
// isinor(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのいずれかに文字列0が存在すれば真，しなければ偽
// -----------------------------------------------------------------------------
void kgFunction_matchs::run(void)
{	
	char* s=_args.at(0)->s();
	for( vector<int>::size_type i=1; i<_args.size(); i++){
		if( NULL!=strstr(_args.at(i)->s(),s) ){
			_result.b(true);
			return;
		}
	}
	_result.b(false);
}
// -----------------------------------------------------------------------------
// isinand(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのすべてに文字列0が存在すれば真，しなければ偽
// -----------------------------------------------------------------------------
void kgFunction_matchas::run(void)
{	
	char* s=_args.at(0)->s();
	for( vector<int>::size_type i=1; i<_args.size(); i++){
		if( NULL==strstr(_args.at(i)->s(),s) ){
			_result.b(false);
			return;
		}
	}
	_result.b(true);
}
// -----------------------------------------------------------------------------
// hasspace(文字列) => bool : 文字列に空白があれば真，なければ偽
// -----------------------------------------------------------------------------
void kgFunction_hasspace::run(void)
{	
	char* pos=_args.at(0)->s();
	while(*pos){
		if( isspace(*pos) ){
			_result.b(true);
			return;
		}
		pos++;
	}
	_result.b(false);
} 
// -----------------------------------------------------------------------------
// hasspacew(文字列) => bool : 文字列に空白(全角半角空白)があれば真，なければ偽
// -----------------------------------------------------------------------------
void kgFunction_hasspacew::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	for(wstring::const_iterator i=ws.begin(); i!=ws.end(); i++){
		if(iswspace(*i)){
			_result.b(true);
			return;
		}
	}
	_result.b(false);
} 
// -----------------------------------------------------------------------------
// strchr(文字列,文字) => 数値 : 文字列にある文字の個数
// -----------------------------------------------------------------------------
void kgFunction_strchr::run(void)
{	
	int cnt=0;
	char c=*_args.at(1)->s();
	char* s=_args.at(0)->s();
	while(*s!='\0'){
		if(*s++==c) cnt++;
	}
	_result.r(static_cast<double>(cnt));
}
// ============================================================================
// 正規表現関連クラス
// ============================================================================
// -----------------------------------------------------------------------------
// regex[w] 正規表現スーパクラス
// -----------------------------------------------------------------------------
void kgFunction_regex::preprocess(void)
{
	if( _args.at(1)->null() ){
		throw kgError("regular expression must be a constant string");
	}else{
		_reg = cregex::compile(_args.at(1)->s());
	}
}
void kgFunction_regexw::preprocess(void){
	if( _args.at(1)->null() ){
		throw kgError("regular expression must be a constant string");
	}else{
		wstring ws=toWcs(_args.at(1)->s());
		_reg = wsregex::compile( ws );
	}
}
// -----------------------------------------------------------------------------
// regexs[w](文字列,文字列[正規表現]) => bool : 
//   文字列に対して正規表現がマッチする部分文字列があれば真を返す
// -----------------------------------------------------------------------------
void kgFunction_regexs::run(void)
{	
	if(regex_search(_args.at(0)->s(),_reg )){
		_result.b(true);
	}else{
		_result.b(false);
	}
	return;
}
void kgFunction_regexsw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	if(regex_search(ws,_reg) ){
		_result.b(true);
	}else{
		_result.b(false);
	}
	return;
}
// -----------------------------------------------------------------------------
// regexm[w](文字列,文字列[正規表現]) => bool : 
//   文字列に対して正規表現が完全にマッチすれば真を返す
// -----------------------------------------------------------------------------
void kgFunction_regexm::run(void)
{
	if(regex_match(_args.at(0)->s(),_reg )){
		_result.b(true);
	}else{
		_result.b(false);
	}
	return;
}
void kgFunction_regexmw::run(void)
{
	wstring ws=toWcs(_args.at(0)->s());
	if(regex_match(ws,_reg) ){
		_result.b(true);
	}else{
		_result.b(false);
	}
	return;
}
// -----------------------------------------------------------------------------
// regexrep[w](文字列,文字列[正規表現],文字列[置換文字列]) => 文字列 : 
//   文字列に対して正規表現がマッチする部分を置換文字列に置換する
// -----------------------------------------------------------------------------
void kgFunction_regexrep::run(void)
{	
	_buf = regex_replace(_args.at(0)->s(),_reg,_args.at(2)->s());
	_result.s(const_cast<char*>(_buf.c_str()));
	return;
}
void kgFunction_regexrepw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	wstring rs=toWcs(_args.at(2)->s());
	_buf = toMbs( regex_replace(ws,_reg,rs) );
	_result.s(const_cast<char*>(_buf.c_str()));
	return;
}
// -----------------------------------------------------------------------------
// regexlen[w](文字列,文字列[正規表現]) => 数値 :
//  文字列に対して正規表現がマッチした長さを返す
// -----------------------------------------------------------------------------
void kgFunction_regexlen::run(void)
{	
	regex_search(_args.at(0)->s(),_mat,_reg);
	_result.r(_mat.length());
	return;
}
void kgFunction_regexlenw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	regex_search(ws,_mat,_reg);
	_result.r(_mat.length());
	return;
}
// -----------------------------------------------------------------------------
// regexpos[w](文字列,文字列[正規表現]) => 数値 :
//  文字列に対して正規表現がマッチした先頭位置を返す(マッチしなければ−１)
// -----------------------------------------------------------------------------
void kgFunction_regexpos::run(void)
{
	regex_search(_args.at(0)->s(),_mat,_reg);
	if(_mat.position()==-1){
		_result.null(true);
	}
	else{
		_result.r(_mat.position());
	}
	return;
}
void kgFunction_regexposw::run(void)
{
	wstring ws=toWcs(_args.at(0)->s());
	regex_search(ws,_mat,_reg);
	if(_mat.position()==-1){
		_result.null(true);	
	}else{
		_result.r(_mat.position());
	}
	return;
}
// -----------------------------------------------------------------------------
// regexstr[w](文字列,文字列[正規表現]) => 文字列 :
//  文字列に対して正規表現がマッチする部分文字列を返す
// -----------------------------------------------------------------------------
void kgFunction_regexstr::run(void)
{	
	regex_search(_args.at(0)->s(),_mat,_reg);
	unsigned int size=_mat.str().size();
	if( size >= KG_MAX_STR_LEN){
		_result.null(true);
		return;
	}
	strcpy(_buf,_mat.str().c_str());
	_result.s(_buf);
	return;
}
void kgFunction_regexstrw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	regex_search(ws,_mat,_reg);
	_buf = toMbs( _mat.str() );
	_result.s(const_cast<char*>(_buf.c_str()));
	return;
}
// -----------------------------------------------------------------------------
// regexpfx[w](文字列,文字列[正規表現]) => 文字列 :
//  文字列に対して正規表現がマッチした部分文字列の直前までの文字列を左から出力する
// -----------------------------------------------------------------------------
void kgFunction_regexpfx::run(void)
{
	bool rls = regex_search(_args.at(0)->s(),_mat,_reg);
	unsigned int size=_mat.prefix().str().size();
	if( !rls || size >= KG_MAX_STR_LEN){
		*_buf='\0';
		_result.s(_buf);
		return;
	}
	strcpy(_buf,_mat.prefix().str().c_str());
	_result.s(_buf);
	return;
}
void kgFunction_regexpfxw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	bool rls = regex_search(ws,_mat,_reg);
	if(rls){
		_buf = toMbs( _mat.prefix().str() );
	}else{
		_buf = "";
	}
	_result.s(const_cast<char*>(_buf.c_str()));
	return;
}
// -----------------------------------------------------------------------------
// regexsfx[w](文字列,文字列[正規表現]) => 文字列 :
//  文字列に対して正規表現がマッチした部分文字列の直後から右方向に最後までの文字列を出力する
// -----------------------------------------------------------------------------
void kgFunction_regexsfx::run(void)
{	
	bool rls = regex_search(_args.at(0)->s(),_mat,_reg);
	unsigned int size=_mat.suffix().str().size();
	if( !rls || size >= KG_MAX_STR_LEN){
		*_buf='\0';
		_result.s(_buf);
		return;
	}
	strcpy(_buf,_mat.suffix().str().c_str());
	_result.s(_buf);
	return;
}
void kgFunction_regexsfxw::run(void)
{	
	wstring ws=toWcs(_args.at(0)->s());
	bool rls = regex_search(ws,_mat,_reg);
	if(rls){
		_buf = toMbs( _mat.suffix().str() );
	}else{
		_buf = "";
	}
	_result.s(const_cast<char*>(_buf.c_str()));
	return;
}
// ============================================================================
// 行項目関連
// ============================================================================
// -----------------------------------------------------------------------------
// line() => 数値 :処理行中番号の取得
// -----------------------------------------------------------------------------
void kgFunction_line::run(void)
{	
	_result.r(static_cast<double>(_csv->recNo()-1));
	return;
}
// -----------------------------------------------------------------------------
// fldsize() => 数値 :データ項目数の取得
// -----------------------------------------------------------------------------
void kgFunction_fldsize::run(void)
{	
	_result.r(static_cast<double>(_csv->fldSize()));
	return;
}
// -----------------------------------------------------------------------------
// top() => bool :先頭行チェック 先頭ならtrue
// -----------------------------------------------------------------------------
void kgFunction_top::run(void)
{
	if( _csv->status() & kgCSV::Begin ){
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// bottom() => bottom :最終行チェック 最終ならtrue
// -----------------------------------------------------------------------------
void kgFunction_bottom::run(void)
{
	if( _csv->isEOF()){
		_result.b(true);
	}else{
		_result.b(false);
	}
}
// -----------------------------------------------------------------------------
// argsize(S,S,...,S) => 数値 :引数の数
// -----------------------------------------------------------------------------
void kgFunction_argsize::run(void)
{
	_result.r(_args.size());
}
// =============================================================================
// kgFuncMapクラス関連
// =============================================================================
// ------- コンストラクタ(インデックスの作成)
kgFuncMap::kgFuncMap(void){
	_usedCnt=0;

	// 可変引数は_func_vecREGにも登録

	// 定数
	_func_map["CS"   ]= lambda::bind(lambda::new_ptr<kgFunction_const_str >());
	_func_map["CN"   ]= lambda::bind(lambda::new_ptr<kgFunction_const_real>());
	_func_map["CD"   ]= lambda::bind(lambda::new_ptr<kgFunction_const_date>());
	_func_map["CT"   ]= lambda::bind(lambda::new_ptr<kgFunction_const_time>());
	_func_map["CB"   ]= lambda::bind(lambda::new_ptr<kgFunction_const_bool>());
//	_func_map["CU"   ]= lambda::bind(lambda::new_ptr<kgFunction_const_utime>());

	// 項目
	_func_map["FS"  ]= lambda::bind(lambda::new_ptr<kgFunction_field_str >());
	_func_map["FN"  ]= lambda::bind(lambda::new_ptr<kgFunction_field_real>());
	_func_map["FD"  ]= lambda::bind(lambda::new_ptr<kgFunction_field_date>());
	_func_map["FT"  ]= lambda::bind(lambda::new_ptr<kgFunction_field_time>());
	_func_map["FB"  ]= lambda::bind(lambda::new_ptr<kgFunction_field_bool>());

	// 前行項目
	_func_map["PS"  ]= lambda::bind(lambda::new_ptr<kgFunction_pfield_str >());
	_func_map["PN"  ]= lambda::bind(lambda::new_ptr<kgFunction_pfield_real>());
	_func_map["PD"  ]= lambda::bind(lambda::new_ptr<kgFunction_pfield_date>());
	_func_map["PT"  ]= lambda::bind(lambda::new_ptr<kgFunction_pfield_time>());
	_func_map["PB"  ]= lambda::bind(lambda::new_ptr<kgFunction_pfield_bool>());

	// 算術演算子
	_func_map["+_SS"]= lambda::bind(lambda::new_ptr<kgFunction_add_str >());
	_func_map["+_NN"]= lambda::bind(lambda::new_ptr<kgFunction_add_real>());
	_func_map["+_DN"]= lambda::bind(lambda::new_ptr<kgFunction_add_day >());
	_func_map["+_TN"]= lambda::bind(lambda::new_ptr<kgFunction_add_sec >());
	_func_map["-_SS"]= lambda::bind(lambda::new_ptr<kgFunction_sub_str >());
	_func_map["-_NN"]= lambda::bind(lambda::new_ptr<kgFunction_sub_real>());
	_func_map["-_DN"]= lambda::bind(lambda::new_ptr<kgFunction_sub_day >());
	_func_map["-_TN"]= lambda::bind(lambda::new_ptr<kgFunction_sub_sec >());
	_func_map["-_DD"]= lambda::bind(lambda::new_ptr<kgFunction_sub_date>());
	_func_map["-_TT"]= lambda::bind(lambda::new_ptr<kgFunction_sub_time>());
	_func_map["*_NN"]= lambda::bind(lambda::new_ptr<kgFunction_mul_real>());
	_func_map["/_NN"]= lambda::bind(lambda::new_ptr<kgFunction_div_real>());
	_func_map["%_NN"]= lambda::bind(lambda::new_ptr<kgFunction_mod_real>());
	_func_map["^_NN"]= lambda::bind(lambda::new_ptr<kgFunction_pow_real>());

	// 関係演算子
	_func_map[">=_SS"]= lambda::bind(lambda::new_ptr<kgFunction_ge_str  >());
	_func_map[">=_NN"]= lambda::bind(lambda::new_ptr<kgFunction_ge_real >());
	_func_map[">=_DD"]= lambda::bind(lambda::new_ptr<kgFunction_ge_date >());
	_func_map[">=_TT"]= lambda::bind(lambda::new_ptr<kgFunction_ge_time >());
	_func_map["<=_SS"]= lambda::bind(lambda::new_ptr<kgFunction_le_str  >());
	_func_map["<=_NN"]= lambda::bind(lambda::new_ptr<kgFunction_le_real >());
	_func_map["<=_DD"]= lambda::bind(lambda::new_ptr<kgFunction_le_date >());
	_func_map["<=_TT"]= lambda::bind(lambda::new_ptr<kgFunction_le_time >());
	_func_map[">_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_gt_str  >());
	_func_map[">_NN" ]= lambda::bind(lambda::new_ptr<kgFunction_gt_real >());
	_func_map[">_DD" ]= lambda::bind(lambda::new_ptr<kgFunction_gt_date >());
	_func_map[">_TT" ]= lambda::bind(lambda::new_ptr<kgFunction_gt_time >());
	_func_map["<_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_lt_str  >());
	_func_map["<_NN" ]= lambda::bind(lambda::new_ptr<kgFunction_lt_real >());
	_func_map["<_DD" ]= lambda::bind(lambda::new_ptr<kgFunction_lt_date >());
	_func_map["<_TT" ]= lambda::bind(lambda::new_ptr<kgFunction_lt_time >());
	_func_map["==_SS"]= lambda::bind(lambda::new_ptr<kgFunction_eq_str  >());
	_func_map["==_NN"]= lambda::bind(lambda::new_ptr<kgFunction_eq_real >());
	_func_map["==_DD"]= lambda::bind(lambda::new_ptr<kgFunction_eq_date >());
	_func_map["==_TT"]= lambda::bind(lambda::new_ptr<kgFunction_eq_time >());
	_func_map["!=_SS"]= lambda::bind(lambda::new_ptr<kgFunction_ne_str  >());
	_func_map["!=_NN"]= lambda::bind(lambda::new_ptr<kgFunction_ne_real >());
	_func_map["!=_DD"]= lambda::bind(lambda::new_ptr<kgFunction_ne_date >());
	_func_map["!=_TT"]= lambda::bind(lambda::new_ptr<kgFunction_ne_time >());

	// 論理演算子
	_func_map["&&_BB" ]= lambda::bind(lambda::new_ptr<kgFunction_and     >());
	_func_map["and_B*"]= lambda::bind(lambda::new_ptr<kgFunction_multi_and>());
	_func_map["||_BB" ]= lambda::bind(lambda::new_ptr<kgFunction_or      >());
	_func_map["or_B*" ]= lambda::bind(lambda::new_ptr<kgFunction_multi_or >());
	_func_map["^^_BB" ]= lambda::bind(lambda::new_ptr<kgFunction_xor     >());
	_func_map["not_B*"]= lambda::bind(lambda::new_ptr<kgFunction_not     >());

	_func_vecREG.push_back("and_B*");
	_func_vecREG.push_back("or_B*");
	_func_vecREG.push_back("not_B*");

	// 論理関数
	_func_map["if_BNN"]= lambda::bind(lambda::new_ptr<kgFunction_if_real >());
	_func_map["if_BSS"]= lambda::bind(lambda::new_ptr<kgFunction_if_str  >());
	_func_map["if_BDD"]= lambda::bind(lambda::new_ptr<kgFunction_if_date >());
	_func_map["if_BTT"]= lambda::bind(lambda::new_ptr<kgFunction_if_time >());
	_func_map["if_BBB"]= lambda::bind(lambda::new_ptr<kgFunction_if_bool >());


	//NULL値関連
	_func_map["nulls_"]= lambda::bind(lambda::new_ptr<kgFunction_const_nulls>());
	_func_map["nulln_"]= lambda::bind(lambda::new_ptr<kgFunction_const_nulln>());
	_func_map["nulld_"]= lambda::bind(lambda::new_ptr<kgFunction_const_nulld>());
	_func_map["nullt_"]= lambda::bind(lambda::new_ptr<kgFunction_const_nullt>());
	_func_map["nullb_"]= lambda::bind(lambda::new_ptr<kgFunction_const_nullb>());
	_func_map["isnull_S"]= lambda::bind(lambda::new_ptr<kgFunction_isnull_s>());
	_func_map["isnull_N"]= lambda::bind(lambda::new_ptr<kgFunction_isnull_n>());
	_func_map["isnull_D"]= lambda::bind(lambda::new_ptr<kgFunction_isnull_d>());
	_func_map["isnull_T"]= lambda::bind(lambda::new_ptr<kgFunction_isnull_t>());
	_func_map["isnull_B"]= lambda::bind(lambda::new_ptr<kgFunction_isnull_b>());
	_func_map["countnull_S*"]= lambda::bind(lambda::new_ptr<kgFunction_countnull_s>());
	_func_map["countnull_N*"]= lambda::bind(lambda::new_ptr<kgFunction_countnull>());
	_func_map["countnull_D*"]= lambda::bind(lambda::new_ptr<kgFunction_countnull>());
	_func_map["countnull_T*"]= lambda::bind(lambda::new_ptr<kgFunction_countnull>());
	_func_map["countnull_B*"]= lambda::bind(lambda::new_ptr<kgFunction_countnull>());

	_func_vecREG.push_back("countnull_S*");
	_func_vecREG.push_back("countnull_N*");
	_func_vecREG.push_back("countnull_D*");
	_func_vecREG.push_back("countnull_T*");
	_func_vecREG.push_back("countnull_B*");

	// 変換関数
	_func_map["s2n_S"     ]= lambda::bind(lambda::new_ptr<kgFunction_s2n        >());
	_func_map["s2d_S"     ]= lambda::bind(lambda::new_ptr<kgFunction_s2d        >());
	_func_map["s2t_S"     ]= lambda::bind(lambda::new_ptr<kgFunction_s2t        >());
	_func_map["n2s_N"     ]= lambda::bind(lambda::new_ptr<kgFunction_n2s        >());
	_func_map["d2s_D"     ]= lambda::bind(lambda::new_ptr<kgFunction_d2s        >());
	_func_map["t2s_T"     ]= lambda::bind(lambda::new_ptr<kgFunction_t2s        >());
	_func_map["t2d_T"     ]= lambda::bind(lambda::new_ptr<kgFunction_t2d        >());
	_func_map["d2t_D"     ]= lambda::bind(lambda::new_ptr<kgFunction_d2t        >());
	_func_map["b2n_B"     ]= lambda::bind(lambda::new_ptr<kgFunction_b2n        >());
	_func_map["b2s_B"     ]= lambda::bind(lambda::new_ptr<kgFunction_b2s        >());
	_func_map["n2b_N"     ]= lambda::bind(lambda::new_ptr<kgFunction_n2b        >());
	_func_map["s2b_S"     ]= lambda::bind(lambda::new_ptr<kgFunction_s2b        >());
	_func_map["format_NS" ]= lambda::bind(lambda::new_ptr<kgFunction_format_real>());

	// 日付関数
	_func_map["today_"]= lambda::bind(lambda::new_ptr<kgFunction_today     >());
	_func_map["now_"  ]= lambda::bind(lambda::new_ptr<kgFunction_now       >());
	_func_map["unow_"  ]= lambda::bind(lambda::new_ptr<kgFunction_unow       >());
	_func_map["time_T"]= lambda::bind(lambda::new_ptr<kgFunction_time_str  >());
	_func_map["date_T"]= lambda::bind(lambda::new_ptr<kgFunction_date_str  >());
	
	_func_map["leapyear_D"]= lambda::bind(lambda::new_ptr<kgFunction_leapyear_d>());
	_func_map["leapyear_T"]= lambda::bind(lambda::new_ptr<kgFunction_leapyear_t>());

	_func_map["julian_D"  ]= lambda::bind(lambda::new_ptr<kgFunction_d2julian  >());
	_func_map["julian_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_t2julian  >());
	_func_map["julian2d_N"]= lambda::bind(lambda::new_ptr<kgFunction_julian2d  >());
	_func_map["julian2t_N"]= lambda::bind(lambda::new_ptr<kgFunction_julian2t  >());

	_func_map["uxt_D"  ]= lambda::bind(lambda::new_ptr<kgFunction_d2uxt     >());
	_func_map["uxt_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_t2uxt     >());
	_func_map["uxt2d_N"]= lambda::bind(lambda::new_ptr<kgFunction_uxt2d     >());
	_func_map["uxt2t_N"]= lambda::bind(lambda::new_ptr<kgFunction_uxt2t     >());

	_func_map["age_DD"]= lambda::bind(lambda::new_ptr<kgFunction_age_d     >());
	_func_map["age_TT"]= lambda::bind(lambda::new_ptr<kgFunction_age_t     >());

	_func_map["diffyear_TT"  ]= lambda::bind(lambda::new_ptr<kgFunction_diffyear_t  >());
	_func_map["diffyear_DD"  ]= lambda::bind(lambda::new_ptr<kgFunction_diffyear_d  >());
	_func_map["diffmonth_TT" ]= lambda::bind(lambda::new_ptr<kgFunction_diffmonth_t >());
	_func_map["diffmonth_DD" ]= lambda::bind(lambda::new_ptr<kgFunction_diffmonth_d >());
	_func_map["diffday_TT"   ]= lambda::bind(lambda::new_ptr<kgFunction_diffday_t   >());
	_func_map["diffday_DD"   ]= lambda::bind(lambda::new_ptr<kgFunction_diffday_d   >());
	_func_map["diffhour_TT"  ]= lambda::bind(lambda::new_ptr<kgFunction_diffhour_t  >());
	_func_map["diffminute_TT"]= lambda::bind(lambda::new_ptr<kgFunction_diffminute_t>());
	_func_map["diffsecond_TT"]= lambda::bind(lambda::new_ptr<kgFunction_diffsecond_t>());

	_func_map["year_D"    ]= lambda::bind(lambda::new_ptr<kgFunction_year_d    >());
	_func_map["year_T"    ]= lambda::bind(lambda::new_ptr<kgFunction_year_t    >());
	_func_map["years_D"   ]= lambda::bind(lambda::new_ptr<kgFunction_years_d   >());
	_func_map["years_T"   ]= lambda::bind(lambda::new_ptr<kgFunction_years_t   >());
	_func_map["month_D"   ]= lambda::bind(lambda::new_ptr<kgFunction_month_d   >());
	_func_map["month_T"   ]= lambda::bind(lambda::new_ptr<kgFunction_month_t   >());
	_func_map["months_D"  ]= lambda::bind(lambda::new_ptr<kgFunction_months_d  >());
	_func_map["months_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_months_t  >());
	_func_map["monthe_D"  ]= lambda::bind(lambda::new_ptr<kgFunction_emonth_d  >());
	_func_map["monthe_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_emonth_t  >());
	_func_map["monthes_D" ]= lambda::bind(lambda::new_ptr<kgFunction_esmonth_d >());
	_func_map["monthes_T" ]= lambda::bind(lambda::new_ptr<kgFunction_esmonth_t >());
	_func_map["day_D"     ]= lambda::bind(lambda::new_ptr<kgFunction_day_d     >());
	_func_map["day_T"     ]= lambda::bind(lambda::new_ptr<kgFunction_day_t     >());
	_func_map["days_D"    ]= lambda::bind(lambda::new_ptr<kgFunction_days_d    >());
	_func_map["days_T"    ]= lambda::bind(lambda::new_ptr<kgFunction_days_t    >());
	_func_map["week_D"    ]= lambda::bind(lambda::new_ptr<kgFunction_week_d    >());
	_func_map["week_T"    ]= lambda::bind(lambda::new_ptr<kgFunction_week_t    >());
	_func_map["week111_D" ]= lambda::bind(lambda::new_ptr<kgFunction_week111_d >());
	_func_map["week111_T" ]= lambda::bind(lambda::new_ptr<kgFunction_week111_t >());
	_func_map["dow_D"     ]= lambda::bind(lambda::new_ptr<kgFunction_dow_d     >());
	_func_map["dow_T"     ]= lambda::bind(lambda::new_ptr<kgFunction_dow_t     >());
	_func_map["dowe_D"    ]= lambda::bind(lambda::new_ptr<kgFunction_edow_d    >());
	_func_map["dowe_T"    ]= lambda::bind(lambda::new_ptr<kgFunction_edow_t    >());
	_func_map["dowes_D"   ]= lambda::bind(lambda::new_ptr<kgFunction_esdow_d   >());
	_func_map["dowes_T"   ]= lambda::bind(lambda::new_ptr<kgFunction_esdow_t   >());
	_func_map["dowj_D"    ]= lambda::bind(lambda::new_ptr<kgFunction_dowj_d    >());
	_func_map["dowj_T"    ]= lambda::bind(lambda::new_ptr<kgFunction_dowj_t    >());
	_func_map["hour_T"    ]= lambda::bind(lambda::new_ptr<kgFunction_hour_t    >());
	_func_map["hours_T"   ]= lambda::bind(lambda::new_ptr<kgFunction_hours_t   >());
	_func_map["minute_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_minute_t  >());
	_func_map["minutes_T" ]= lambda::bind(lambda::new_ptr<kgFunction_minutes_t >());
	_func_map["second_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_second_t  >());
	_func_map["seconds_T" ]= lambda::bind(lambda::new_ptr<kgFunction_seconds_t >());
	_func_map["tseconds_T"]= lambda::bind(lambda::new_ptr<kgFunction_tseconds_t>());

	_func_map["diffusecond_TT"]= lambda::bind(lambda::new_ptr<kgFunction_diffusecond_t>());
	_func_map["usecond_T"  ]= lambda::bind(lambda::new_ptr<kgFunction_usecond_t  >());
	_func_map["useconds_T" ]= lambda::bind(lambda::new_ptr<kgFunction_useconds_t >());
	_func_map["tuseconds_T"]= lambda::bind(lambda::new_ptr<kgFunction_tuseconds_t>());

	// 数学関数
	_func_map["sum_N*"       ]= lambda::bind(lambda::new_ptr<kgFunction_sum       >());
	_func_map["sum_N*S"      ]= lambda::bind(lambda::new_ptr<kgFunction_sum_N     >());
	_func_map["avg_N*"       ]= lambda::bind(lambda::new_ptr<kgFunction_avg       >());
	_func_map["avg_N*S"      ]= lambda::bind(lambda::new_ptr<kgFunction_avg_N     >());
	_func_map["sqsum_N*"     ]= lambda::bind(lambda::new_ptr<kgFunction_sqsum     >());
	_func_map["sqsum_N*S"    ]= lambda::bind(lambda::new_ptr<kgFunction_sqsum_N   >());
	_func_map["factorial_N"  ]= lambda::bind(lambda::new_ptr<kgFunction_factorial >());
	_func_map["gcd_NN"       ]= lambda::bind(lambda::new_ptr<kgFunction_gcd       >());
	_func_map["lcm_NN"       ]= lambda::bind(lambda::new_ptr<kgFunction_lcm       >());
	_func_map["sqrt_N"       ]= lambda::bind(lambda::new_ptr<kgFunction_sqrt      >());
	_func_map["fract_N"      ]= lambda::bind(lambda::new_ptr<kgFunction_fract     >());
	_func_map["int_N"        ]= lambda::bind(lambda::new_ptr<kgFunction_int       >());
	_func_map["min_N*"       ]= lambda::bind(lambda::new_ptr<kgFunction_min       >());
	_func_map["min_N*S"      ]= lambda::bind(lambda::new_ptr<kgFunction_min_N     >());
	_func_map["max_N*"       ]= lambda::bind(lambda::new_ptr<kgFunction_max       >());
	_func_map["max_N*S"      ]= lambda::bind(lambda::new_ptr<kgFunction_max_N     >());
	_func_map["abs_N"        ]= lambda::bind(lambda::new_ptr<kgFunction_abs       >());
	_func_map["round_N"     ]= lambda::bind(lambda::new_ptr<kgFunction_round     >());
	_func_map["round_NN"     ]= lambda::bind(lambda::new_ptr<kgFunction_round     >());
	_func_map["power_NN"     ]= lambda::bind(lambda::new_ptr<kgFunction_power     >());
	_func_map["floor_N"      ]= lambda::bind(lambda::new_ptr<kgFunction_floor     >());
	_func_map["floor_NN"     ]= lambda::bind(lambda::new_ptr<kgFunction_floor     >());
	_func_map["ceil_N"       ]= lambda::bind(lambda::new_ptr<kgFunction_ceil      >());
	_func_map["ceil_NN"      ]= lambda::bind(lambda::new_ptr<kgFunction_ceil      >());
	_func_map["exp_N"        ]= lambda::bind(lambda::new_ptr<kgFunction_exp       >());
	_func_map["ln_N"         ]= lambda::bind(lambda::new_ptr<kgFunction_ln        >());
	_func_map["log_NN"       ]= lambda::bind(lambda::new_ptr<kgFunction_log       >());
	_func_map["log2_N"       ]= lambda::bind(lambda::new_ptr<kgFunction_log2      >());
	_func_map["log10_N"      ]= lambda::bind(lambda::new_ptr<kgFunction_log10     >());
	_func_map["product_N*"   ]= lambda::bind(lambda::new_ptr<kgFunction_product   >());
	_func_map["product_N*S"  ]= lambda::bind(lambda::new_ptr<kgFunction_product_N >());
	_func_map["sign_N"       ]= lambda::bind(lambda::new_ptr<kgFunction_sign      >());
	_func_map["dist_SNNNN*"  ]= lambda::bind(lambda::new_ptr<kgFunction_dist      >());
	_func_map["dist_SSSSS*"  ]= lambda::bind(lambda::new_ptr<kgFunction_disth     >());
	_func_map["distgps_NNNN" ]= lambda::bind(lambda::new_ptr<kgFunction_distgps   >());
	_func_map["heron_NNN*"   ]= lambda::bind(lambda::new_ptr<kgFunction_heron     >());
	_func_map["pi_"          ]= lambda::bind(lambda::new_ptr<kgFunction_pi        >());
	_func_map["e_"           ]= lambda::bind(lambda::new_ptr<kgFunction_e         >());
	_func_map["randi_NN"     ]= lambda::bind(lambda::new_ptr<kgFunction_rand      >());
	_func_map["randi_NNN"    ]= lambda::bind(lambda::new_ptr<kgFunction_rand      >());
	_func_map["rand_N"       ]= lambda::bind(lambda::new_ptr<kgFunction_rand_real >());
	_func_map["rand_"        ]= lambda::bind(lambda::new_ptr<kgFunction_rand_real >());
	_func_map["nrand_NN"     ]= lambda::bind(lambda::new_ptr<kgFunction_nrand     >());
	_func_map["nrand_NNN"    ]= lambda::bind(lambda::new_ptr<kgFunction_nrand     >());
	_func_map["berrand_N"    ]= lambda::bind(lambda::new_ptr<kgFunction_berrand   >());
	_func_map["berrand_NN"   ]= lambda::bind(lambda::new_ptr<kgFunction_berrand   >());
	_func_map["binomdist_NNN"]= lambda::bind(lambda::new_ptr<kgFunction_binomdist >());

	_func_vecREG.push_back("sum_N*");
	_func_vecREG.push_back("sum_N*S");
	_func_vecREG.push_back("avg_N*");
	_func_vecREG.push_back("avg_N*S");
	_func_vecREG.push_back("sqsum_N*");
	_func_vecREG.push_back("sqsum_N*S");
	_func_vecREG.push_back("min_N*");
	_func_vecREG.push_back("min_N*S");
	_func_vecREG.push_back("max_N*");
	_func_vecREG.push_back("max_N*S");
	_func_vecREG.push_back("product_N*");
	_func_vecREG.push_back("product_N*S");
	_func_vecREG.push_back("dist_SNNNN*");
	_func_vecREG.push_back("dist_SSSSS*");
	_func_vecREG.push_back("heron_NNN*");

	// 三角関数
	_func_map["acos_N"   ]= lambda::bind(lambda::new_ptr<kgFunction_acos      >());
	_func_map["asin_N"   ]= lambda::bind(lambda::new_ptr<kgFunction_asin      >());
	_func_map["atan_N"   ]= lambda::bind(lambda::new_ptr<kgFunction_atan      >());
	_func_map["atan2_NN" ]= lambda::bind(lambda::new_ptr<kgFunction_atan2     >());
	_func_map["cos_N"    ]= lambda::bind(lambda::new_ptr<kgFunction_cos       >());
	_func_map["sin_N"    ]= lambda::bind(lambda::new_ptr<kgFunction_sin       >());
	_func_map["tan_N"    ]= lambda::bind(lambda::new_ptr<kgFunction_tan       >());
	_func_map["degree_N" ]= lambda::bind(lambda::new_ptr<kgFunction_degree    >());
	_func_map["radian_N" ]= lambda::bind(lambda::new_ptr<kgFunction_radian    >());
	_func_map["sinh_N"   ]= lambda::bind(lambda::new_ptr<kgFunction_sinh      >());
	_func_map["cosh_N"   ]= lambda::bind(lambda::new_ptr<kgFunction_cosh      >());
	_func_map["tanh_N"   ]= lambda::bind(lambda::new_ptr<kgFunction_tanh      >());

	// 文字列関数
  _func_map["cat_SS*"     ]= lambda::bind(lambda::new_ptr<kgFunction_cat       >());
	_func_map["length_S"    ]= lambda::bind(lambda::new_ptr<kgFunction_length    >());
	_func_map["lengthw_S"   ]= lambda::bind(lambda::new_ptr<kgFunction_lengthw   >());
  _func_map["fixlen_SNSS" ]= lambda::bind(lambda::new_ptr<kgFunction_fixlen    >());
  _func_map["fixlenw_SNSS"]= lambda::bind(lambda::new_ptr<kgFunction_fixlenw   >());
  _func_map["right_SN"    ]= lambda::bind(lambda::new_ptr<kgFunction_right     >());
  _func_map["rightw_SN"   ]= lambda::bind(lambda::new_ptr<kgFunction_rightw    >());
  _func_map["left_SN"     ]= lambda::bind(lambda::new_ptr<kgFunction_left      >());
  _func_map["leftw_SN"    ]= lambda::bind(lambda::new_ptr<kgFunction_leftw     >());
  _func_map["mid_SNN"     ]= lambda::bind(lambda::new_ptr<kgFunction_mid       >());
  _func_map["midw_SNN"    ]= lambda::bind(lambda::new_ptr<kgFunction_midw      >());
  _func_map["toupper_S"   ]= lambda::bind(lambda::new_ptr<kgFunction_toupper   >());
  _func_map["tolower_S"   ]= lambda::bind(lambda::new_ptr<kgFunction_tolower   >());
  _func_map["capitalize_S"]= lambda::bind(lambda::new_ptr<kgFunction_capitalize>());
  _func_map["match_SS*"   ]= lambda::bind(lambda::new_ptr<kgFunction_match    >());
  _func_map["matcha_SS*"  ]= lambda::bind(lambda::new_ptr<kgFunction_matcha   >());
  _func_map["matchs_SS*"  ]= lambda::bind(lambda::new_ptr<kgFunction_matchs    >());
  _func_map["matchas_SS*" ]= lambda::bind(lambda::new_ptr<kgFunction_matchas   >());
  _func_map["hasspace_S"  ]= lambda::bind(lambda::new_ptr<kgFunction_hasspace  >());
  _func_map["hasspacew_S" ]= lambda::bind(lambda::new_ptr<kgFunction_hasspacew >());
//  _func_map["strchr_SS"   ]= lambda::bind(lambda::new_ptr<kgFunction_strchr    >());

	_func_vecREG.push_back("cat_SS*");
	_func_vecREG.push_back("match_SS*");
	_func_vecREG.push_back("matcha_SS*");
	_func_vecREG.push_back("matchs_SS*");
	_func_vecREG.push_back("matchas_SS*");


	// 正規表現関数
  _func_map["regexs_SS"    ]= lambda::bind(lambda::new_ptr<kgFunction_regexs    >());
  _func_map["regexsw_SS"   ]= lambda::bind(lambda::new_ptr<kgFunction_regexsw   >());
  _func_map["regexm_SS"    ]= lambda::bind(lambda::new_ptr<kgFunction_regexm    >());
  _func_map["regexmw_SS"   ]= lambda::bind(lambda::new_ptr<kgFunction_regexmw   >());
  _func_map["regexrep_SSS" ]= lambda::bind(lambda::new_ptr<kgFunction_regexrep  >());
  _func_map["regexrepw_SSS"]= lambda::bind(lambda::new_ptr<kgFunction_regexrepw >());
  _func_map["regexlen_SS"  ]= lambda::bind(lambda::new_ptr<kgFunction_regexlen  >());
  _func_map["regexlenw_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_regexlenw >());
  _func_map["regexpos_SS"  ]= lambda::bind(lambda::new_ptr<kgFunction_regexpos  >());
  _func_map["regexposw_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_regexposw >());
  _func_map["regexstr_SS"  ]= lambda::bind(lambda::new_ptr<kgFunction_regexstr  >());
  _func_map["regexstrw_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_regexstrw >());
  _func_map["regexpfx_SS"  ]= lambda::bind(lambda::new_ptr<kgFunction_regexpfx  >());
  _func_map["regexpfxw_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_regexpfxw >());
  _func_map["regexsfx_SS"  ]= lambda::bind(lambda::new_ptr<kgFunction_regexsfx  >());
  _func_map["regexsfxw_SS" ]= lambda::bind(lambda::new_ptr<kgFunction_regexsfxw >());

	// 行，列関数
  _func_map["top_"        ]= lambda::bind(lambda::new_ptr<kgFunction_top       >());
  _func_map["bottom_"     ]= lambda::bind(lambda::new_ptr<kgFunction_bottom    >());
  _func_map["line_"       ]= lambda::bind(lambda::new_ptr<kgFunction_line      >());
  _func_map["fldsize_"    ]= lambda::bind(lambda::new_ptr<kgFunction_fldsize   >());
  _func_map["argsize_S*"  ]= lambda::bind(lambda::new_ptr<kgFunction_argsize   >());
	_func_vecREG.push_back("argsize_S*");

}

kgFunction* kgFuncMap::getSUB(const string& id){

	// オリジナル と trim後の両方チェックする
	func_map_t::const_iterator m_org = _func_map.find(id);
	if( m_org!=_func_map.end() ){
		if(_usedCnt >= KG_MAX_CAL_TERMS){
			throw kgError("too many functions or fields specified");
		}
		_ap[_usedCnt].set( m_org->second() ); 
		return _ap[_usedCnt++].get();
	}
	for(size_t i=0;i<_func_vecREG.size();i++){
		boost::xpressive::cregex reg = cregex::compile(_func_vecREG[i]);
		if( regex_match(id.c_str() ,reg)){
			func_map_t::const_iterator m_org = _func_map.find(_func_vecREG[i]);
			if( m_org!=_func_map.end() ){
				if(_usedCnt >= KG_MAX_CAL_TERMS){
					throw kgError("too many functions or fields specified");
				}
				_ap[_usedCnt].set( m_org->second() );
				return _ap[_usedCnt++].get();
			}
		}
	}
	ostringstream oss;
	oss << "unknown function or operator: " << id;
	throw kgError(oss.str());
	return NULL;
}

// -----------------------------------------------------------------------------
// 関数表(func_map)のidを検索し，関数をインスタンス化しそのアドレスを返す
// func_mapのidはidの_以降の重複を省いて作成されている．
// (可変引数対策 ex. cat_SSSSSSSS -> cat_S,sum_SSSN -> sum_SN)
// -----------------------------------------------------------------------------
kgFunction* kgFuncMap::get(const string& id)
{
	if(id.empty()){ return NULL; }	
	return getSUB(id);
}

