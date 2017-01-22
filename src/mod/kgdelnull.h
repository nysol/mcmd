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
// kgdelnull.h NULL値行の削除
// =============================================================================
#pragma once
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgDelnull:public kgModIncludeSort
{
	// 引数
	kgArgFld _kField;  // k=
	kgArgFld _fField;  // f=
	kgCSVblk _iFile;   // i=
	kgCSVout _oFile;   // o=
	kgCSVout _uFile;   // u=

	bool     _sel_flg; // -F
	bool     _keysel_flg; // -R
	bool     _reverse; // -r
	bool     _elsefile; // 不一致ファイルを使用するかどうか(u=の指定があればtrue)

	// 引数セット
	void setArgs(void);

	// nullがあるかチェック
	bool nullcheck(vector<int>& cnt,char** str);

public:
	// コンストラクタ&引数セット
	kgDelnull(void);
	~kgDelnull(void){}

	// 実行
	int run(void);

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

};

}
