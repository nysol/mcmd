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
// kgshuffle.h ファイル分割クラス
// =============================================================================
#pragma once

#include <kgMethod.h>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgShuffle:public kgMod {
	// 引数
	kgArgFld          _fField;   // f=
	size_t            _hashSize; // v=
	kgCSVfld          _iFile;    // i=
	vector<kgCSVout*> _oFile;    // 出力ファイル
	vector<int>	 			_hash2outf; // 出力ファイル名
	bool              _woFld;    // f=指定なしフラグ

	size_t _outCount;		 // 総出力件数
	kgAutoPtr2<kgCSVout> _csvOut_ap;
	// 引数セット
	void setArgs(void);

public:
	// コンストラクタ&引数セット
	kgShuffle(void);
	~kgShuffle(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _outCount; }

	//実行メソッド
	int run(void);

};

}
