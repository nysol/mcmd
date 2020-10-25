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
// kgsed.h 正規表現による文字列置換
// =============================================================================
#pragma once
#include <string>
#include <vector>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSed : public kgMod {

	// 引数
	kgArgFld _fField;  	// f=
	kgCSVfld _iFile;  	// i=
	kgCSVout _oFile;		// o=
	kgstr_t   _regstr;	// c=
	kgstr_t _vstr;			// v=
	bool     _add;			// -A
	bool     _global; 	// -g
	bool     _widechar; // -w

	// CSV項目出力
	void writeFld(char** fld, const vector<int>* flg, const vector<string>* val);

	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ
	kgSed(void);
	~kgSed(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }
	
	//実行メソッド
	int run(void);

};

}
