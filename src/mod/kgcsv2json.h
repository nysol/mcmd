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
// kgsum.h 行集計(合計)クラス
// =============================================================================
#pragma once
#include <kgmod.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgCsv2json : public kgModIncludeSort 
{
	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgArgFld _hField; // h=
	kgArgFld _pFieldk; // p= key 前
	kgArgFld _pFieldv; // p= value 後ろ
	 

	kgCSVkey _iFile;  // i=

	
	kgCSVout _oFile;  // o=
	vector<bool> _oFLG;   // -n
	bool _fltFlg;   // -flat

	int _fldPtn;   // -flat

	// 引数セット
	void kebreak_output(int pos ,bool end=false);
  void setArgs(void);

public:
  // コンストラクタ
	kgCsv2json(void);
	~kgCsv2json(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return -1; }

	//実行メソッド
	int run(void);

};

}
