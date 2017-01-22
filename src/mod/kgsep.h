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
// kgsep.h 行の複数ファイルへの分割
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSep : public kgModIncludeSort
{
	// 引数
	vector<kgstr_t> _dField_str; 	// d=の文字列部分
	vector<int> 		_dField; 			// d=の項目番号
	kgArgFld 				_fField;   // f=
	kgCSVkey				_iFile;  			// i=
	kgCSVout				_oFile;  			// 出力用
	bool 						_mkdir_flg;		//-p

	// 引数セット 
	void setArgs(void);
	void writeFldName(void) throw(kgError);
public:

  // コンストラクタ
	kgSep(void);
	~kgSep(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
