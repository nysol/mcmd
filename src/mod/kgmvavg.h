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
// kgmvavg.h 移動平均クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgMvavg : public kgModIncludeSort 
{
	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVkey _iFile;  // i=
	kgCSVout _oFile;  // o=
	size_t   _term;   // t=
	bool     _weighted;	 // -weighted
	bool   	 _exp;   		 // -exp
	bool     _simple;
	bool		 _null;      // -n

	size_t   _skip; 		 //
	double   _alpha; 		 //



	vector<double> _val;   // orgデータ領域
	vector<bool>   _nullv; // orgデータ領域(null flg)
	vector<size_t> _cnt;	 // 現在件数

	vector<kgVal>	 _avg;	 // rlsデータ領域(avg)


  void setArgs(void);
	void simpleMA(void);
	void weightedMA(void);
	void expMA(void);

public:
  // コンストラクタ
	 kgMvavg(void);
	~kgMvavg(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
