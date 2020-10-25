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
// kgfsort.h 項目ソートクラス
// =============================================================================
#pragma once
#include <vector>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>


using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgFsort:public kgMod 
{
	// 引数
	kgCSVfld _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgArgFld _fField; // f=
	bool _reverse;		// -r
	bool _numsort;		// -n

	void writeFld(char** fld, const vector<int>* flg, vector<char*>& val);
	// 引数セット
	void setArgs(void);

public:
	// コンストラクタ&引数セット
	kgFsort(void);
	~kgFsort(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
