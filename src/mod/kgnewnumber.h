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
// kgnewnumber.h 連続値項目の新規生成クラス
// =============================================================================
#pragma once
#include <kgConfig.h>
#include <kgmod.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgNewnumber:public kgMod {
	// 引数
	kgstr_t  _aField;					// a=
	kgCSVout _oFile;					// o=
	size_t	 _line;								// l=
	kgstr_t  _addstr;					// a=
	int _start;								// S=
	int _interval;						// I=

	bool _alpha_flg;
	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ
	kgNewnumber(void);
	~kgNewnumber(void){}

	// 処理行数取得メソッド
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);


};

}

