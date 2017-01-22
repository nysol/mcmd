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
// kgsep2.h 行の複数ファイルへの分割ver.2
// =============================================================================
#pragma once
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <boost/filesystem.hpp>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSep2 : public kgModIncludeSort {

	// 引数
	kgCSVkey _iFile;  	// i=
	kgCSVout _oFile; 		// ファイル連番-k=対応表出力用
	kgCSVout _sepFile;  // 分割データ出力用
	bool forceFlg_;			//-p
	kgArgFld _kField;		// k=
	kgstr_t  _newFld;		// a=
	boost::filesystem::path  oPath_;   // O=

	// 引数セット
	void setArgs(void);
public:
  // コンストラクタ
	kgSep2(void);
	~kgSep2(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
