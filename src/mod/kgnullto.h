﻿/* ////////// LICENSE INFO ////////////////////

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
// kgnullto.h NULL値の置換クラス
// =============================================================================
#pragma once
#include <string>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgNullto : public kgModIncludeSort
{
	// 引数
	kgCSVkey _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgArgFld _kField;  // k=
	kgArgFld _fField; // f=
	kgstr_t	 _OField;	// O=:NULL以外の置換文字列
	kgstr_t	 _vField;	// v=:置換文字列

	bool _exp_nul;	// O=指定時にtrue
	bool _add_flg;		// 項目追加
	bool _prv_flg; 		// 前行値で置換
	// 引数セット
	void setArgs(void);

public:
	// コンストラクタ
	kgNullto(void);
	~kgNullto(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}

