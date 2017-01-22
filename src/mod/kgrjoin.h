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
// kgrjoin.h 参照ファイル項目の数値範囲マッチング結合クラス
// =============================================================================
#pragma once
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgRjoin:public kgModIncludeSort {
	// 引数
	kgArgFld _kField;  // k=
	kgArgFld _KField;  // K=
	kgArgFld _fField;  // f=
	kgArgFld _RField;  // R=
	kgArgFld _rField;  // v=
	kgCSVkey _iFile;   // i=
	kgCSVkey _mFile;   // m=
	kgCSVout _oFile;   // o=
	bool     _i_outer; // -n
	bool     _range_type; // -r true:より大きい〜以下 false:以上〜未満
	
	//比較方法(初期値false) true:数字ソート false:文字ソート
	bool _cmp_type;

	// 範囲マッチ
	void range_match(void);

	// 引数セット
	void setArgs(void);

public:
	// コンストラクタ&引数セット
	kgRjoin(void);
	~kgRjoin(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t mRecNo(void) const { return _mFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
