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
#pragma once
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgRand : public kgModIncludeSort
{

	// 引数
	kgCSVkey _iFile;   // i=
	kgCSVout _oFile;   // o=
	kgstr_t	 _aField;		//a=
	kgArgFld _kField; // k=

	int		 		_min;		//min=
	int 			_max;		//max=

	unsigned long _seed;			 // S=

	bool _int_rand;
	bool _B_flg;

	// CSV項目出力
	void writeFld(char** fld ,int size ,double val);
	// 引数セット	
	void setArgs(void);

public:
	// コンストラクタ
	kgRand(void);
	~kgRand(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}

