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
// kgstat.cpp 行集計(複数の統計量一括)クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cfloat>
#include <kgsummary.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSummary::kgSummary(void)
{
	_name    = "kgsummary";
	_version = "###VERSION###";
	
	#include <help/en/kgsummaryHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsummaryHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 統計関数
// -----------------------------------------------------------------------------
bool PreCal1;
vector<double> Sum;
vector<double> Cnt;
vector<double> Dv2;
vector<double> Min;
vector<double> Max;
bool PreCal2;
vector<double> Uct;
vector<double> Qt1;
vector<double> Qt2;
vector<double> Qt3;
vector<double> Mod;
vector<int>    Mdc;
bool PreCal3;
vector<double> Dv3;
vector<double> Dv4;

vector<bool> NulF;

namespace kgsummary_ {/////////////////////////////////////////////////////////////////////////////
	// ---------------------------------------------------------------------------
	// sum
	// ---------------------------------------------------------------------------
	void sum(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Sum.at(i));}
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// count
	// ---------------------------------------------------------------------------
	void count(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else                 { result.at(i).r(Cnt.at(i));}
		}
	}
	// ---------------------------------------------------------------------------
	// mean
	// ---------------------------------------------------------------------------
	void mean(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Sum.at(i)/Cnt.at(i));}
			else                 { result.at(i).null(true);}
		}
	}
	// ---------------------------------------------------------------------------
	// max
	// ---------------------------------------------------------------------------
	void maximum(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Max.at(i));}
			else                 { result.at(i).null(true);}
		}
	}
	// ---------------------------------------------------------------------------
	// min
	// ---------------------------------------------------------------------------
	void minimum(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Min.at(i)); }
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// range
	// ---------------------------------------------------------------------------
	void range(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Max.at(i)-Min.at(i)); }
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// devsq
	// ---------------------------------------------------------------------------
	void devsq(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>1) { result.at(i).r(Dv2.at(i)); }
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// var
	// ---------------------------------------------------------------------------
	void var(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Dv2.at(i)/(Cnt.at(i)));}
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// uvar
	// ---------------------------------------------------------------------------
	void uvar(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>1) { result.at(i).r(Dv2.at(i)/(Cnt.at(i)-1));}
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// sd
	// ---------------------------------------------------------------------------
	void sd(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>1) { result.at(i).r(sqrt(Dv2.at(i)/(Cnt.at(i))));}
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// usd
	// ---------------------------------------------------------------------------
	void usd(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>1) { result.at(i).r(sqrt(Dv2.at(i)/(Cnt.at(i)-1)));}
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// cv
	// ---------------------------------------------------------------------------
	void cv(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>1) { result.at(i).r(100.0*sqrt(Dv2.at(i)/(Cnt.at(i)))/
                                    (Sum.at(i)/Cnt.at(i))); }
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// preCal1
	// ---------------------------------------------------------------------------
	void preCal1(kgCSVblk& csv, kgArgFld& fld,bool _null)
	{
		// 集計用変数領域確保＆初期化
		int fldCnt=fld.size();
		vector<double> sx(fldCnt,0);

		for(std::size_t i=0; i<fld.size(); i++){
			Cnt.at(i)=0;
			Sum.at(i)=0;
			Dv2.at(i)=0;
			Min.at(i)= DBL_MAX;
			Max.at(i)=-DBL_MAX;
			NulF.at(i)=false;
		}

		csv.seekBlkTop();

		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){

				char* str=csv.getBlkVal(fld.num(i));

				// データがnullの場合は何もしない
				if(*str=='\0') { NulF.at(i)=true; continue; }

				double dx = atof(str);
				Sum.at(i)+=dx;
				if(Min.at(i)>dx) Min.at(i)=dx;
				if(Max.at(i)<dx) Max.at(i)=dx;
				dx -= sx.at(i);
				sx.at(i) += dx / (Cnt.at(i)+1); 
				Dv2.at(i) += Cnt.at(i) * dx * dx / (Cnt.at(i)+1); 
				Cnt.at(i) += 1;
			}
		}
	}
	// ---------------------------------------------------------------------------
	// median
	// ---------------------------------------------------------------------------
	void median(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Qt2.at(i)); }
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// qtile1
	// ---------------------------------------------------------------------------
	void qtile1(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Qt1.at(i));}
			else                 { result.at(i).null(true);}
		}
	}
	// ---------------------------------------------------------------------------
	// qtile3
	// ---------------------------------------------------------------------------
	void qtile3(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Qt3.at(i));}
			else                 { result.at(i).null(true);}
		}
	}
	// ---------------------------------------------------------------------------
	// qrange
	// ---------------------------------------------------------------------------
	void qrange(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Qt3.at(i)-Qt1.at(i));}
			else                 { result.at(i).null(true);}
		}
	}
	// ---------------------------------------------------------------------------
	// mode
	// ---------------------------------------------------------------------------
	void mode(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Mdc.at(i)>1) { result.at(i).r(Mod.at(i)); }
			else                 { result.at(i).null(true); }
		}
	}
	// ---------------------------------------------------------------------------
	// uniqcount
	// ---------------------------------------------------------------------------
	void ucount(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0) { result.at(i).r(Uct.at(i));}
			else                 { result.at(i).null(true);}
		}
	}
	// ---------------------------------------------------------------------------
	// preCal2
	// median,quatile等の前処理
	// 対象項目を抜き出し，sortingした後にq分位数を求める.
	// q分位数Qq=x(1-q+q*n)
	// x(t)=(t2-t)x1+(t-t1)x2
	//   nはデータ数
	//   t1はtのfloor, t2はtのceiling
	//   x1はt1番目の値, x2はt2番目の値
	// ---------------------------------------------------------------------------
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

		Qtile(double q, double c)
		{
			_c=c; _q=q;
			_t=1.0-_q+_q*_c;
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
	
	// ---------------------------------------------------------------------------
	// 前処理2
	// ---------------------------------------------------------------------------
	void preCal2( kgCSVblk& csv, kgArgFld& fld,bool _null)
	{
		for(std::size_t i=0; i<fld.size(); i++){
			Qt1.at(i)=0;
			Qt2.at(i)=0;
			Qt3.at(i)=0;
			Mod.at(i)=0;
			Mdc.at(i)=0;
			Uct.at(i)=0;

			if(!PreCal1 && !PreCal3 ){
				Cnt.at(i) = 0;
				NulF.at(i) = false;
			}
		}
		csv.seekBlkTop();

		//値=>出現回数
		vector< map<double ,int> > ctables(fld.size());
		while(  EOF != csv.blkread() ){

			// f=指定した項目のNULLを除いた件数
			for(std::size_t i=0; i<fld.size(); i++){
				char* str=csv.getBlkVal(fld.num(i));
				if(*str=='\0'){ NulF.at(i) =true; continue; }
				if(!PreCal1 && !PreCal3){
					Cnt.at(i) += 1;
				}
				double v_d = atof(str);
				if ( ctables.at(i).find(v_d) != ctables.at(i).end()){
					((ctables.at(i))[v_d])++;
				}else{
					ctables.at(i)[v_d]=1;
				}
			}
		}

		for(std::size_t i=0; i<fld.size(); i++){

			int preC=0,nowC;
			double maxModeVal=0;
			int maxModeCnt = 0; 
			Qtile q25(0.25,Cnt.at(i));
			Qtile q50(0.50,Cnt.at(i));
			Qtile q75(0.75,Cnt.at(i));

			for(map<double,int>::iterator j=ctables.at(i).begin();j!=ctables.at(i).end();j++)	{

				nowC = j->second + preC;
				if( q25.t1() > preC && nowC >= q25.t1() )  q25.x1(j->first);
				if( q25.t2() > preC && nowC >= q25.t2() )  q25.x2(j->first);
				if( q50.t1() > preC && nowC >= q50.t1() )  q50.x1(j->first);
				if( q50.t2() > preC && nowC >= q50.t1() )  q50.x2(j->first);
				if( q75.t1() > preC && nowC >= q75.t1() )  q75.x1(j->first);
				if( q75.t2() > preC && nowC >= q75.t1() )  q75.x2(j->first);
				Uct.at(i)+=1;

				if ( j->second > maxModeCnt ){
					maxModeCnt = j->second;
					maxModeVal = j->first;
				}
				preC += j->second;
			}

			q25.cal();
			q50.cal();
			q75.cal();
			Qt1.at(i)=q25.Qq();
			Qt2.at(i)=q50.Qq();
			Qt3.at(i)=q75.Qq();
			Mod.at(i)=maxModeVal;
			Mdc.at(i)=maxModeCnt;
		}
	}
	// ---------------------------------------------------------------------------
	// skew
	// ---------------------------------------------------------------------------
	void skew(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }		
			else if(Cnt.at(i)>0 && Dv2.at(i)>0){
				double var15=pow(Dv2.at(i)/(Cnt.at(i)),1.5);
				result.at(i).r( Dv3.at(i) / (var15*(Cnt.at(i))) );
			}else{
				result.at(i).null(true);
			}
		}
	}
	// ---------------------------------------------------------------------------
	// uskew
	// ---------------------------------------------------------------------------
	void uskew(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>2 && Dv2.at(i)>0){
				double c=Cnt.at(i);
				double var15=pow(Dv2.at(i)/(c-1),1.5);
				result.at(i).r( c/((c-1)*(c-2)) * Dv3.at(i) / var15 );
			}else{
				result.at(i).null(true);
			}
		}
	}
	// ---------------------------------------------------------------------------
	// kurt
	// ---------------------------------------------------------------------------
	void kurt(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>0 && Dv2.at(i)>0){
				double var2=pow(Dv2.at(i)/(Cnt.at(i)),2);
				result.at(i).r( Dv4.at(i) / (var2*(Cnt.at(i))) - 3.0 );
			}else{
				result.at(i).null(true);
			}
		}
	}
	// ---------------------------------------------------------------------------
	// ukurt
	// ---------------------------------------------------------------------------
	void ukurt(vector<kgVal>& result,bool nullF )
	{
		for(std::size_t i=0; i<result.size(); i++){
			if(NulF.at(i)&&nullF){ result.at(i).null(true); }
			else if(Cnt.at(i)>3 && Dv2.at(i)>0){
				double c=Cnt.at(i);
				double var2=pow(Dv2.at(i)/(c-1),2);
				result.at(i).r( c*(c+1)/(c-1)/(c-2)/(c-3) * Dv4.at(i) / var2 - 3.0 * (c-1)*(c-1)/(c-2)/(c-3) );
			}else{
				result.at(i).null(true);
			}
		}
	}
	// ---------------------------------------------------------------------------
	// preCal3
	// ---------------------------------------------------------------------------
	void preCal3(kgCSVblk& csv, kgArgFld& fld,bool _null)
	{
		for(std::size_t i=0; i<fld.size(); i++){
			Dv3.at(i)=0;
			Dv4.at(i)=0;
		}
		// 集計用変数領域確保＆初期化
		int fldCnt=fld.size();
		vector<double> sx(fldCnt,0);

		// 平均値を求める
		if(!PreCal1) preCal1(csv, fld,_null);

		csv.seekBlkTop();

		while(  EOF != csv.blkread() ){
			for(std::size_t i=0; i<fld.size(); i++){

				char* str=csv.getBlkVal(fld.num(i));
				if(*str=='\0') continue;

				double dx = atof(str)-Sum.at(i)/Cnt.at(i); //偏差
				Dv3.at(i)+=dx*dx*dx;
				Dv4.at(i)+=dx*dx*dx*dx;
			}
		}
	}

} /////////namespace kgsummary_///////////////////////////////////////////

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSummary::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("a=,f=,i=,o=,k=,c=,-q,-n",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
  _oFile.setPrecision(_precision);
	_iFile.read_header();

	// a=　新項目名セット
	_vField = _args.toString("a=",false);
	if(_vField.empty()){ _vField="fld"; }

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vs_f = _args.toStringVecVec("f=",':',2,true,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// c= 計算方法のセット
	_c_types = _args.toStringVecVec("c=", ':', 2, true);

	PreCal1=false; PreCal2=false; PreCal3=false;
	for(std::size_t i=0; i<_c_types.at(0).size();i++){
		kgstr_t kw=_c_types.at(0).at(i);
	     	 if(kw=="sum"   ){_functions.push_back(&kgsummary_::sum)    ; PreCal1=true; }
	  else if(kw=="mean"  ){_functions.push_back(&kgsummary_::mean)   ; PreCal1=true; }
		else if(kw=="count" ){_functions.push_back(&kgsummary_::count)  ; PreCal1=true; }
		else if(kw=="devsq" ){_functions.push_back(&kgsummary_::devsq)  ; PreCal1=true; }
		else if(kw=="var"   ){_functions.push_back(&kgsummary_::var)    ; PreCal1=true; }
		else if(kw=="uvar"  ){_functions.push_back(&kgsummary_::uvar)   ; PreCal1=true; }
		else if(kw=="sd"    ){_functions.push_back(&kgsummary_::sd)     ; PreCal1=true; }
		else if(kw=="usd"   ){_functions.push_back(&kgsummary_::usd)    ; PreCal1=true; }
		else if(kw=="cv"    ){_functions.push_back(&kgsummary_::cv)     ; PreCal1=true; }
		else if(kw=="min"   ){_functions.push_back(&kgsummary_::minimum); PreCal1=true; }
		else if(kw=="qtile1"){_functions.push_back(&kgsummary_::qtile1) ; PreCal2=true; }
		else if(kw=="median"){_functions.push_back(&kgsummary_::median) ; PreCal2=true; }
		else if(kw=="qtile3"){_functions.push_back(&kgsummary_::qtile3) ; PreCal2=true; }
		else if(kw=="max"   ){_functions.push_back(&kgsummary_::maximum); PreCal1=true; }
		else if(kw=="range" ){_functions.push_back(&kgsummary_::range)  ; PreCal1=true; }
		else if(kw=="qrange"){_functions.push_back(&kgsummary_::qrange) ; PreCal2=true; }
		else if(kw=="mode"  ){_functions.push_back(&kgsummary_::mode)   ; PreCal2=true; }
		else if(kw=="ucount"){_functions.push_back(&kgsummary_::ucount) ; PreCal2=true; }
		else if(kw=="skew"  ){_functions.push_back(&kgsummary_::skew)   ; PreCal3=true; }
		else if(kw=="kurt"  ){_functions.push_back(&kgsummary_::kurt)   ; PreCal3=true; }
		else if(kw=="uskew" ){_functions.push_back(&kgsummary_::uskew)  ; PreCal3=true; }
		else if(kw=="ukurt" ){_functions.push_back(&kgsummary_::ukurt)  ; PreCal3=true; }
		else {
			ostringstream ss;
			ss << "unknown keyword: " << kw << ": c=sum|mean|count|ucount|devsq|var|uvar|sd|usd|cv|min|qtile1|median|qtile3|max|range|qrange|mode|skew|kurt|uskew|ukurt" << _c_type;
			throw kgError(ss.str());	
		}
	}

	for(std::size_t i=0; i<_c_types.at(1).size(); i++){
		kgstr_t str=_c_types.at(1).at(i);
		if(str.empty()) _names.push_back(_c_types.at(0).at(i));
		else            _names.push_back(str);
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

int kgSummary::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
	if(!_oFile.noFldName()){
		vector<kgstr_t> outfld;
		for(size_t k=0; k < _kField.size(); k++){
			outfld.push_back(_iFile.fldName(_kField.num(k),true));
		}
		outfld.push_back(_vField);
		for(size_t k=0; k<_names.size(); k++){
			outfld.push_back(_names.at(k));
		}
		_oFile.writeFldNameCHK(outfld);
	}

	// グローバル変数(計算部品)の初期化
	int fldSize=_fField.size();
	Cnt.resize(fldSize,0);
	Uct.resize(fldSize,0);
	Sum.resize(fldSize,0);
	Dv2.resize(fldSize,0);
	Dv3.resize(fldSize,0);
	Dv4.resize(fldSize,0);
	Min.resize(fldSize,0);
	Max.resize(fldSize,0);
	Qt1.resize(fldSize,0);
	Qt2.resize(fldSize,0);
	Qt3.resize(fldSize,0);
	Mod.resize(fldSize,0);
	Mdc.resize(fldSize,0);
	NulF.resize(fldSize,0);

	// 結果格納変数の領域確保
	vector<vector<kgVal> > result;
	result.resize(_functions.size());
	for(std::size_t i=0; i<_functions.size(); i++){
		result.at(i).resize(fldSize);
		for(int j=0; j<fldSize; j++){
			result.at(i).at(j).type('N');
		}
	}

	while(_iFile.blkset()!=EOF){

		// 前計算(sum,mean等)
		if(PreCal1) kgsummary_::preCal1(_iFile, _fField,_null);

		// 前計算(median,qtile1等)
		if(PreCal2) kgsummary_::preCal2(_iFile, _fField,_null);

		// 前計算(偏差の３乗和，４乗和)
		if(PreCal3) kgsummary_::preCal3(_iFile, _fField,_null);

		// 計算の実行本体
		for(std::size_t k=0; k<_functions.size(); k++){
			_functions.at(k)(result.at(k),_null );
		}

		// 結果出力
		for(int i=0; i<fldSize; i++){
			if(_assertNullIN && NulF.at(i) ) { _existNullIN  = true;}
			// k=項目出力
			for(std::size_t j=0; j<_kField.size(); j++){
				_oFile.writeStr(_iFile.getOldVal(_kField.num(j)),false);
			}
			// 対象項目名
			kgstr_t oName=_fField.attr(i);
			if( oName.empty()) oName=_fField.name(i);
			_oFile.writeStr(oName.c_str(),false);
			for(std::size_t j=0; j<_functions.size(); j++){
				bool retFlg=false;
				if(j==_functions.size()-1) retFlg=true;
				_oFile.writeVal(result.at(j).at(i),retFlg);
				if(_assertNullOUT && result.at(j).at(i).null() ) { _existNullOUT  = true;}
			}
		}
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

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
