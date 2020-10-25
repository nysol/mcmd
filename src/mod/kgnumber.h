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
// kgnumber.h 連続値項目の追加クラス
// =============================================================================
#pragma once
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgNumber : public kgModIncludeSort
{
	// 引数
	kgArgFld _kField; // k=
	kgArgFld _sField; // s=
	kgCSVkey _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgstr_t _addstr;	// a=
	int _e_type; 			// e=(seq:0,same:1,skip:2)
	int _start;				// S=
	int _interval;		// I=
	bool _B_flg;			// -B

	// 連続値にアルファベットを使用するならture
	bool _alpha_flg;	

	// 引数セット
	void setArgs(void);

public:
  // コンストラクタ
	kgNumber(void);
	~kgNumber(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }
	
	//実行メソッド
	int run(void);

};

}
