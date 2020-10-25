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
// kgsummary.h 行集計(複数の統計量一括)クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgVal.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSummary : public kgModIncludeSort
{


	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVblk _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgstr_t  _vField; //a=
	kgstr_t  _aField; //v=
	kgstr_t  _c_type; // c=
	bool _null;

	bool _PreCal1;
	vector<double> _Sum;
	vector<double> _Cnt;
	vector<double> _Dv2;
	vector<double> _Min;
	vector<double> _Max;
	bool _PreCal2;
	vector<double> _Uct;
	vector<double> _Qt1;
	vector<double> _Qt2;
	vector<double> _Qt3;
	vector<double> _Mod;
	vector<int>    _Mdc;
	bool _PreCal3;
	vector<double> _Dv3;
	vector<double> _Dv4;
	vector<bool> _NulF;

	vector<vector<kgstr_t> >  _c_types; // c=
	vector<void (*)(kgSummary*,vector<kgVal>&,bool)> _functions;
	vector<string> _names;


	// 引数セット
  void setArgs(void);

public:

	// 
	double atSum(size_t pos){ return _Sum.at(pos); }
	void   atSum(size_t pos,double val){ _Sum.at(pos)=val; }
	void   adSum(size_t pos,double val){ _Sum.at(pos)+=val; }

	double atCnt(size_t pos){ return _Cnt.at(pos); }
	void   atCnt(size_t pos,double val){ _Cnt.at(pos)=val; }
	void   adCnt(size_t pos,double val=1){ _Cnt.at(pos)+=val; }

	double atDv2(size_t pos){ return _Dv2.at(pos); }
	void   atDv2(size_t pos,double val){ _Dv2.at(pos)=val; }
	void   adDv2(size_t pos,double val){ _Dv2.at(pos)+=val; }

	double atDv3(size_t pos){ return _Dv3.at(pos); }
	void   atDv3(size_t pos,double val){ _Dv3.at(pos)=val; }
	void   adDv3(size_t pos,double val){ _Dv3.at(pos)+=val; }

	double atDv4(size_t pos){ return _Dv4.at(pos); }
	void   atDv4(size_t pos,double val){ _Dv4.at(pos)=val; }
	void   adDv4(size_t pos,double val){ _Dv4.at(pos)+=val; }

	double atMin(size_t pos){ return _Min.at(pos); }
	void   atMin(size_t pos,double val){ _Min.at(pos)=val; }
	void   adMin(size_t pos,double val){ if(_Min.at(pos)>val){ _Min.at(pos)=val; } }

	double atMax(size_t pos){ return _Max.at(pos); }
	void   atMax(size_t pos,double val){ _Max.at(pos)=val; }
	void   adMax(size_t pos,double val){ if(_Max.at(pos)<val){ _Max.at(pos)=val; } }

	double atUct(size_t pos){ return _Uct.at(pos); }
	void   atUct(size_t pos,double val){ _Uct.at(pos)=val; }
	void   adUct(size_t pos,double val=1){ _Uct.at(pos)+=val; }

	double atQt1(size_t pos){ return _Qt1.at(pos); }
	void   atQt1(size_t pos,double val){ _Qt1.at(pos)=val; }

	double atQt2(size_t pos){ return _Qt2.at(pos); }
	void   atQt2(size_t pos,double val){ _Qt2.at(pos)=val; }

	double atQt3(size_t pos){ return _Qt3.at(pos); }
	void   atQt3(size_t pos,double val){ _Qt3.at(pos)=val; }

	double atMod(size_t pos){ return _Mod.at(pos); }
	void   atMod(size_t pos,double val){ _Mod.at(pos)=val; }
	
	int    atMdc(size_t pos){ return _Mdc.at(pos); }
	void   atMdc(size_t pos,int val){ _Mdc.at(pos)=val; }

	bool   atNulF(size_t pos){ return _NulF.at(pos); }
	void   atNulF(size_t pos,bool val){ _NulF.at(pos)=val; }


	void pre1Clr(){
		for(std::size_t i=0; i<_fField.size(); i++){
			_Cnt.at(i)=0;
			_Sum.at(i)=0;
			_Dv2.at(i)=0;
			_Min.at(i)= DBL_MAX;
			_Max.at(i)=-DBL_MAX;
			_NulF.at(i)=false;
		}
	}

	void pre2Clr(){
		for(std::size_t i=0; i<_fField.size(); i++){
			_Qt1.at(i)=0;
			_Qt2.at(i)=0;
			_Qt3.at(i)=0;
			_Mod.at(i)=0;
			_Mdc.at(i)=0;
			_Uct.at(i)=0;
			if(!_PreCal1 && !_PreCal3 ){
				_Cnt.at(i) = 0;
				_NulF.at(i) = false;
			}
		}
	}
	void pre3Clr(){
		for(std::size_t i=0; i<_fField.size(); i++){
			_Dv3.at(i)=0;
			_Dv4.at(i)=0;
		}
	}
	bool has_PreCal1(){return _PreCal1;}
	bool has_PreCal2(){return _PreCal2;}
	bool has_PreCal3(){return _PreCal3;}

  // コンストラクタ
	kgSummary(void);
	~kgSummary(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
