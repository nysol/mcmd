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
// kgstats.cpp 行集計(統計量)クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cfloat>
#include <kgstats.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgStats::kgStats(void)
{
	_name    = "kgstats";
	_version = "###VERSION###";

	#include <help/en/kgstatsHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgstatsHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 統計クラス
// -----------------------------------------------------------------------------
namespace kgstats_ 
{
	// -----------------------------------------------------------------------------
	// q分位数計算クラス
	// Qq=x(1-q+q*n)
	// x(t)=(t2-t)x1+(t-t1)x2
	//   nはデータ数
	//   t1はtのfloor, t2はtのceiling
	//   x1はt1番目の値, x2はt2番目の値
	// -----------------------------------------------------------------------------
	class Qtile 
	{
		double _c;  // 件数
		double _q;  // q分位(0<=q<=1)
		double _Qq; // q分位数
		double _t;
		double _t1;
		double _t2;
		double _x1;
		double _x2;
	public:
		Qtile(double q, double c){
			_c=c; _q=q;
			_t=1.0-_q+_q*_c;
			modf(_t,&_t1);
			if(modf(_t,&_t1)==0) _t2=_t1;
			else                 _t2=_t1+1;
		}
		double t1(void) const {return _t1;}
		double t2(void) const {return _t2;}
		void x1(double x){_x1=x;}
		void x2(double x){_x2=x;}
		double Qq(void){return _Qq;}
		void cal(void){
			if(modf(_t,&_t1)==0) _Qq = _x1;
			else                 _Qq = (_t2-_t)*_x1+(_t-_t1)*_x2;
		}
	};
	// -----------------------------------------------------------------------------
	// 件数計算クラス
	// -----------------------------------------------------------------------------
	class CntCal 
	{
			vector< double > _cnt;
			vector<bool> 	 _null;
		public:
			CntCal(size_t i){
				_cnt.resize(i,0);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){ _cnt.at(fldno) += 1;}
			}
			double get(size_t fldno){ return _cnt.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// ユニーク件数計算クラス
	// -----------------------------------------------------------------------------
	class UcntCal 
	{
			vector< set<double> > _ucnt;
			vector<bool> 	 _null;
		public:
			UcntCal(size_t i){
				_ucnt.resize(i);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){ 
					double d=atof(val);
					_ucnt.at(fldno).insert(d);
				}
				else {
					_null.at(fldno) = true;
				}
			}
			double get(size_t fldno){ return _ucnt.at(fldno).size();}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// モード(頻出値)計算クラス
	// -----------------------------------------------------------------------------
	class ModCal 
	{
			vector< map<double,int> > _ucnt;
			vector< int > _mdc;
			vector< double > _modc;
			vector< bool > _null;
		public:
			ModCal(size_t i){
				_ucnt.resize(i);
				_mdc.resize(i,0);
				_modc.resize(i);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){ 
					double d=atof(val);		
					if(_ucnt.at(fldno).find(d) == _ucnt.at(fldno).end()){
						_ucnt.at(fldno)[d] = 1;
					}else{
						_ucnt.at(fldno)[d] += 1;
					}
					if (_mdc.at(fldno) < _ucnt.at(fldno)[d]){
						_mdc.at(fldno) = _ucnt.at(fldno)[d];
						_modc.at(fldno) = d;
					}
				}
				else {
					_null.at(fldno) = true;
				}
			}
			double get(size_t fldno){ return _modc.at(fldno);}
			double mdc(size_t fldno){ return _mdc.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// 集計計算クラス
	// -----------------------------------------------------------------------------
	class SummaryCal 
	{
			vector<double> _sum;
			vector<double> _cnt;
			vector<bool> 	 _null;
		public:
			SummaryCal(size_t i){
				_sum.resize(i,0);
				_cnt.resize(i,0);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){ 
					_sum.at(fldno) += atof(val); 
					_cnt.at(fldno) += 1;
				}
				else{ 
					_null.at(fldno) = true; 
				}
			}
			void reset(size_t fldno){ _sum.at(fldno)=0; _cnt.at(fldno)=0; }
			double ave(size_t fldno){ return _sum.at(fldno)/_cnt.at(fldno);}
			double cnt(size_t fldno){ return _cnt.at(fldno);}
			double sum(size_t fldno){ return _sum.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// 最小値計算クラス
	// -----------------------------------------------------------------------------
	class MinCal 
	{
			vector<double> _min;
			vector<bool> 	 _null;
		public:
			MinCal(size_t i){
				_min.resize(i,DBL_MAX);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){
					double d = atof(val);
					if (_min.at(fldno) > d ){ _min.at(fldno) = d; }
				}else{
					_null.at(fldno) = true;
				}

			}
			double get(size_t fldno){ return _min.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// 最大値計算クラス
	// -----------------------------------------------------------------------------
	class MaxCal 
	{
			vector<double> _max;
			vector<bool> 	 _null;
		public:
			MaxCal(size_t i){
				_max.resize(i,-DBL_MAX);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){
					double d = atof(val);
					if (_max.at(fldno) < d){ _max.at(fldno) = d; }
				}
				else {
					_null.at(fldno) = true;
				}
			}
			double get(size_t fldno){ return _max.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// 差の2乗の集計計算クラス
	// -----------------------------------------------------------------------------
	class Dv2Cal 
	{
			vector<double> _dv2;
			vector<double> _sx;
			vector< double > _cnt;
			vector<bool>   _null;
		public:
			Dv2Cal(size_t i):_cnt(i){
				_dv2.resize(i,0);
				_sx.resize(i,0);
				_cnt.resize(i,0);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){
					double dx = atof(val);
					dx -= _sx.at(fldno);
					_sx.at(fldno) += dx / (_cnt.at(fldno)+1); 
					_dv2.at(fldno) += _cnt.at(fldno) * dx * dx / (_cnt.at(fldno)+1); 
					_cnt.at(fldno) +=1 ;
				}
				else{
					_null.at(fldno) = true; 
				}
			}
			double get(size_t fldno){ return _dv2.at(fldno);}
			double cnt(size_t fldno){ return _cnt.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}			
	};
	// -----------------------------------------------------------------------------
	// 差の3乗の集計計算クラス
	// -----------------------------------------------------------------------------
	class Dv3Cal 
	{
			SummaryCal _ave;
			vector< double > _dv3;
			vector<bool>   _null;
		public:
			Dv3Cal(size_t i,SummaryCal ave):_ave(ave){
				_dv3.resize(i,0);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){ 
					double dx = atof(val)-_ave.ave(fldno); //偏差
					_dv3.at(fldno)+=dx*dx*dx;
				}
				else{
					_null.at(fldno) = true; 
				}
			}
			double get(size_t fldno){ return _dv3.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// 差の4乗の集計計算クラス
	// -----------------------------------------------------------------------------
	class Dv4Cal 
	{
			SummaryCal _ave;
			vector< double > _dv4;
			vector<bool>   _null;
		public:
			Dv4Cal(size_t i,SummaryCal ave):_ave(ave){
				_dv4.resize(i,0);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){ 
					double dx = atof(val)-_ave.ave(fldno); //偏差
					_dv4.at(fldno)+=dx*dx*dx*dx;
				}
				else{
					_null.at(fldno) = true; 
				}
			}
			double get(size_t fldno){ return _dv4.at(fldno);}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// -----------------------------------------------------------------------------
	// q分位計算クラス
	// -----------------------------------------------------------------------------
	class QtCal 
	{
			vector<double> _qt;
			double _quantile;
			vector< vector<double> > _sval;
			vector<bool>   _null;
		public:
			QtCal(size_t i,double quantile):_quantile(quantile),_sval(i){
				_qt.resize(i,0);
				_null.resize(i,false);
			}
			void add(size_t fldno,char *val){
				if(*val!='\0'){
					_sval.at(fldno).push_back(atof(val));
				}
				else { 
					_null.at(fldno) = true;
				}
			}
			void cal(size_t fldno){
				Qtile qtile(_quantile,_sval.at(fldno).size());

				nth_element (_sval.at(fldno).begin(), _sval.at(fldno).begin()+(qtile.t1()-1), _sval.at(fldno).end());
				qtile.x1(_sval.at(fldno).at(qtile.t1()-1));
				if(qtile.t1()==qtile.t2()){
					qtile.x2(_sval.at(fldno).at(qtile.t1()-1));
				}
				else{
					nth_element (_sval.at(fldno).begin(), _sval.at(fldno).begin()+(qtile.t2()-1), _sval.at(fldno).end());
					qtile.x2(_sval.at(fldno).at(qtile.t2()-1));
				}
				qtile.cal();
				_qt.at(fldno)=qtile.Qq();
			}
			double get(size_t fldno){ return _qt.at(fldno);}
			double cnt(size_t fldno){ return _sval.at(fldno).size();}
			bool isNull(size_t fldno){ return _null.at(fldno);}
	};
	// ---------------------------------------------------------------------------
	// sum function
	// ---------------------------------------------------------------------------
	void sum(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal sum_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				sum_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(sum_cal.isNull(i)&&nullF){ result.at(i).null(true); }
			else if(sum_cal.cnt(i)>0)		{ result.at(i).r(sum_cal.sum(i));}
			else                 				{ result.at(i).null(true);}
			if(a_Nin  && sum_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// count function
	// ---------------------------------------------------------------------------
	void count(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal cnt_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				cnt_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(cnt_cal.isNull(i)&&nullF){ result.at(i).null(true); }
			else 												{ result.at(i).r(cnt_cal.cnt(i));}		
			if(a_Nin  && cnt_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// mean function
	// ---------------------------------------------------------------------------
	void mean(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal mean_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				mean_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(mean_cal.isNull(i)&&nullF)	{ result.at(i).null(true); }	
			else if(mean_cal.cnt(i)>0)		{ result.at(i).r(mean_cal.ave(i)); }
			else 													{ result.at(i).null(true); }
			if(a_Nin  && mean_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// max function
	// ---------------------------------------------------------------------------
	void maximum(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		MaxCal max_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				max_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(max_cal.isNull(i)&&nullF)		 { result.at(i).null(true); }	
			else if(max_cal.get(i)!=-DBL_MAX) { result.at(i).r(max_cal.get(i));}
			else                      			 { result.at(i).null(true);}
			if(a_Nin  && max_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}

	// ---------------------------------------------------------------------------
	// min function
	// ---------------------------------------------------------------------------
	void minimum(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		MinCal min_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				min_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(min_cal.isNull(i)&&nullF) 			{ result.at(i).null(true); }	
			else if(min_cal.get(i)!=DBL_MAX) { result.at(i).r(min_cal.get(i));}
			else                        			{ result.at(i).null(true);}
			if(a_Nin  && min_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// range function
	// ---------------------------------------------------------------------------
	void range(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		MaxCal max_cal(fld.size());
		MinCal min_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				max_cal.add(i,str);
				min_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(max_cal.isNull(i)&&nullF) 		 { result.at(i).null(true); }	
			else if(max_cal.get(i)!=DBL_MAX) { result.at(i).r(max_cal.get(i)-min_cal.get(i));}
			else                       			 { result.at(i).null(true); }
			if(a_Nin  && max_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// devsq function
	// ---------------------------------------------------------------------------
	void devsq(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF) { result.at(i).null(true); }	
			else if(dv2_cal.cnt(i)>0) 	 { result.at(i).r(dv2_cal.get(i));}
			else                 				 { result.at(i).null(true);}
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// var function
	// ---------------------------------------------------------------------------
	void var(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF) { result.at(i).null(true); }	
			else if(dv2_cal.cnt(i)>0) 	 { result.at(i).r(dv2_cal.get(i)/dv2_cal.cnt(i));}
			else                				 { result.at(i).null(true); }
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// uvar function
	// ---------------------------------------------------------------------------
	void uvar(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(dv2_cal.cnt(i)>1)		{ result.at(i).r(dv2_cal.get(i)/(dv2_cal.cnt(i)-1));}
			else    										{ result.at(i).null(true); }
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// sd function
	// ---------------------------------------------------------------------------
	void sd(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());	
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF){ result.at(i).null(true);}	
			else if(dv2_cal.cnt(i)>0)		{ result.at(i).r(sqrt(dv2_cal.get(i)/dv2_cal.cnt(i)));}
			else                 				{ result.at(i).null(true);}
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}

	// ---------------------------------------------------------------------------
	// ssd（一般的なusd）function
	// ---------------------------------------------------------------------------
	void ssd(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());	
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF){ result.at(i).null(true);}	
			else if(dv2_cal.cnt(i)>1)		{ result.at(i).r(sqrt(dv2_cal.get(i)/(dv2_cal.cnt(i)-1)));}
			else                				{ result.at(i).null(true);}
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// usd function
	// ---------------------------------------------------------------------------
	void usd(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());	
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF){ 
				result.at(i).null(true); 
			}	
			else if(dv2_cal.cnt(i)>1){
				double ssd=sqrt(dv2_cal.get(i)/(dv2_cal.cnt(i)-1));
				double num = dv2_cal.cnt(i);
				double rval = sqrt(M_PI);
				for(double d=0.5 ;d <= num/2 - 1 ;d+=0.5){
					rval = 1/d/rval;
				}
				//ガンマ関数でそれぞれ計算するとすぐにオーバーフローしちゃう
				//result.at(i).r( ssd*sqrt((num-1)/2)*tgamma((num-1)/2)/tgamma(num/2));
				result.at(i).r( ssd*sqrt((num-1)/2)*rval);
			}
			else{
				result.at(i).null(true);
			}
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// cv function
	// ---------------------------------------------------------------------------
	void cv(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		Dv2Cal dv2_cal(fld.size());	
		SummaryCal ave_cal(fld.size());

		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
				ave_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(dv2_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(dv2_cal.cnt(i)>0)   { result.at(i).r(100.0*sqrt(dv2_cal.get(i)/(dv2_cal.cnt(i)))/ave_cal.ave(i)); }
			else                        { result.at(i).null(true);}
			if(a_Nin  && dv2_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}

	// ---------------------------------------------------------------------------
	// qtile1 function
	// ---------------------------------------------------------------------------
	void qtile1(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		QtCal qt_cal(fld.size(),0.25);	
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				qt_cal.add(i,str);
			}
		}

		for(std::size_t i=0; i<result.size(); i++){
			qt_cal.cal(i);
			if(qt_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(qt_cal.cnt(i)>0)   { result.at(i).r(qt_cal.get(i));}
			else               			   { result.at(i).null(true);}
			if(a_Nin  && qt_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}

	// ---------------------------------------------------------------------------
	// qtile3 function
	// ---------------------------------------------------------------------------
	void qtile3(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		QtCal qt_cal(fld.size(),0.75);
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				qt_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			qt_cal.cal(i);
			if(qt_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(qt_cal.cnt(i)>0)   { result.at(i).r(qt_cal.get(i));}
			else               			   { result.at(i).null(true); }
			if(a_Nin  && qt_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// median function
	// ---------------------------------------------------------------------------
	void median(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		QtCal qt_cal(fld.size(),0.5);
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				qt_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			qt_cal.cal(i);
			if(qt_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(qt_cal.cnt(i)>0)   { result.at(i).r(qt_cal.get(i));}
			else                       { result.at(i).null(true);}
			if(a_Nin  && qt_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// qrange function
	// ---------------------------------------------------------------------------
	void qrange(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		QtCal qt1_cal(fld.size(),0.25);	
		QtCal qt3_cal(fld.size(),0.75);	
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				qt1_cal.add(i,str);
				qt3_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			qt1_cal.cal(i);
			qt3_cal.cal(i);
			if(qt1_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(qt1_cal.cnt(i)>0)   { result.at(i).r(qt3_cal.get(i)-qt1_cal.get(i));}
			else                        { result.at(i).null(true);}
			if(a_Nin  && qt1_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// mode function
	// ---------------------------------------------------------------------------
	void mode(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		ModCal mod_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				mod_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(mod_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(mod_cal.mdc(i)>1)		{ result.at(i).r(mod_cal.get(i));}
			else                				{ result.at(i).null(true);}
			if(a_Nin  && mod_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// uniqcount function
	// ---------------------------------------------------------------------------
	void ucount(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		UcntCal ucnt_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				ucnt_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(ucnt_cal.isNull(i)&&nullF){ result.at(i).null(true); }	
			else if(ucnt_cal.get(i)>0)   { result.at(i).r(ucnt_cal.get(i));}
			else                         { result.at(i).null(true);}
			if(a_Nin  && ucnt_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// skew function
	// ---------------------------------------------------------------------------
	void skew(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal ave_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				ave_cal.add(i,str);
			}
		}
		Dv2Cal dv2_cal(fld.size());
		Dv3Cal dv3_cal(fld.size(),ave_cal);
		csv.seekBlkTop();
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
				dv3_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(ave_cal.isNull(i)&&nullF){ 
				result.at(i).null(true); 
			}	else if(ave_cal.cnt(i)>0 && dv2_cal.get(i)>0){
				double var15=pow(dv2_cal.get(i)/ave_cal.cnt(i),1.5);
				result.at(i).r( dv3_cal.get(i) / (var15*ave_cal.cnt(i)) );
			}else{
				result.at(i).null(true);
			}
			if(a_Nin  && ave_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}

	// ---------------------------------------------------------------------------
	// uskew function
	// ---------------------------------------------------------------------------
	void uskew(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal ave_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				ave_cal.add(i,str);
			}
		}
		Dv2Cal dv2_cal(fld.size());
		Dv3Cal dv3_cal(fld.size(),ave_cal);
		csv.seekBlkTop();
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
				dv3_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(ave_cal.isNull(i)&&nullF){ 
				result.at(i).null(true); 
			}else if(ave_cal.cnt(i)>2 && dv2_cal.get(i)>0){
				double c=ave_cal.cnt(i);
				double var15=pow(dv2_cal.get(i)/(c-1),1.5);
				result.at(i).r( c/((c-1)*(c-2)) * dv3_cal.get(i) / var15 );
			}else{
				result.at(i).null(true);
			}
			if(a_Nin  && ave_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// kurt function
	// ---------------------------------------------------------------------------
	void kurt(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal ave_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				ave_cal.add(i,str);
			}
		}
		Dv2Cal dv2_cal(fld.size());
		Dv4Cal dv4_cal(fld.size(),ave_cal);
		csv.seekBlkTop();
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
				dv4_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(ave_cal.isNull(i)&&nullF){ 
				result.at(i).null(true); 
			} else if(ave_cal.cnt(i)>0 && dv2_cal.get(i)>0){
				double var2=pow(dv2_cal.get(i)/ave_cal.cnt(i),2);
				result.at(i).r( dv4_cal.get(i) / (var2*ave_cal.cnt(i)) - 3.0 );
			}else{
				result.at(i).null(true);
			}
			if(a_Nin  && ave_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
	// ---------------------------------------------------------------------------
	// ukurt function
	// ---------------------------------------------------------------------------
	void ukurt(vector<kgVal>& result,kgCSVblk& csv,kgArgFld& fld,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		SummaryCal ave_cal(fld.size());
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				ave_cal.add(i,str);
			}
		}
		Dv2Cal dv2_cal(fld.size());
		Dv4Cal dv4_cal(fld.size(),ave_cal);
		csv.seekBlkTop();
		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				dv2_cal.add(i,str);
				dv4_cal.add(i,str);
			}
		}
		for(std::size_t i=0; i<result.size(); i++){
			if(ave_cal.isNull(i)&&nullF){ 
				result.at(i).null(true); 
			}else if(ave_cal.cnt(i)>3 && dv2_cal.get(i)>0){
				double c=ave_cal.cnt(i);
				double var2=pow(dv2_cal.get(i)/(c-1),2);
				result.at(i).r( c*(c+1)/(c-1)/(c-2)/(c-3) * dv4_cal.get(i) / var2 - 3.0 * (c-1)*(c-1)/(c-2)/(c-3) );
			}else{
				result.at(i).null(true);
			}
			if(a_Nin  && ave_cal.isNull(i)  ){ *e_Nin=true; }
			if(a_Nout && result.at(i).null()){ *e_Nout=true; }
		}
	}
}///////namespace ///////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgStats::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,c=,-q,-n",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
  _oFile.setPrecision(_precision);
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vs_f = _args.toStringVecVec("f=",':',2,true,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// c= 計算方法のセット
	_c_type = _args.toString("c=", true);
	
     	 if(_c_type=="sum"   ){_function = &kgstats_::sum    ; }
  else if(_c_type=="mean"  ){_function = &kgstats_::mean   ; }
	else if(_c_type=="count" ){_function = &kgstats_::count  ; }
	else if(_c_type=="devsq" ){_function = &kgstats_::devsq  ; }
	else if(_c_type=="var"   ){_function = &kgstats_::var    ; }
	else if(_c_type=="uvar"  ){_function = &kgstats_::uvar   ; }
	else if(_c_type=="sd"    ){_function = &kgstats_::sd     ; }
	else if(_c_type=="usd"   ){_function = &kgstats_::ssd    ; }
	else if(_c_type=="USD"   ){_function = &kgstats_::usd    ; }
	else if(_c_type=="cv"    ){_function = &kgstats_::cv     ; }
	else if(_c_type=="min"   ){_function = &kgstats_::minimum; }
	else if(_c_type=="qtile1"){_function = &kgstats_::qtile1 ; }
	else if(_c_type=="median"){_function = &kgstats_::median ; }
	else if(_c_type=="qtile3"){_function = &kgstats_::qtile3 ; }
	else if(_c_type=="max"   ){_function = &kgstats_::maximum; }
	else if(_c_type=="range" ){_function = &kgstats_::range  ; }
	else if(_c_type=="qrange"){_function = &kgstats_::qrange ; }
	else if(_c_type=="mode"  ){_function = &kgstats_::mode   ; }
	else if(_c_type=="ucount"){_function = &kgstats_::ucount ; }
	else if(_c_type=="skew"  ){_function = &kgstats_::skew   ; }
	else if(_c_type=="kurt"  ){_function = &kgstats_::kurt   ; }
	else if(_c_type=="uskew" ){_function = &kgstats_::uskew  ; }
	else if(_c_type=="ukurt" ){_function = &kgstats_::ukurt  ; }
	else {
		ostringstream ss;
		ss << "unknown keyword: " << _c_type << ": c=sum|mean|count|ucount|devsq|var|uvar|sd|usd|USD|cv|min|qtile1|median|qtile3|max|range|qrange|mode|skew|kurt|uskew|ukurt" << _c_type;
		throw kgError(ss.str());	
	}
	_null = _args.toBool("-n");

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if(!seqflg && !vs.empty()){ sortingRun(&_iFile,vs);}
	_kField.set(vs,  &_iFile,_fldByNum);
	_fField.set(vs_f, &_iFile,_fldByNum);

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgStats::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());
	
	// 項目名の出力
  _oFile.writeFldName(_fField, true);

	// 結果格納変数の領域確保
	vector<kgVal>  result(_fField.size() ,kgVal('N'));

	while(_iFile.blkset()!=EOF){
		// 計算の実行本体
		_function(result,_iFile,_fField,_null,_assertNullIN,_assertNullOUT,&_existNullIN,&_existNullOUT);
		// 結果出力
		_oFile.writeFld(_iFile.getOldFld(),_fField.getFlg_p(),result);
	}

	// 終了処理
	th_cancel();
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
