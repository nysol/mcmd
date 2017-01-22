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
// kgmbucket.h 件数均等化バケット分割(２項目以上)
// =============================================================================
#pragma once
#include <vector>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgMbucket : public kgModIncludeSort
{
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVblk _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgCSVout _rFile;  // O=
	vector<int> _bktSize;			//n=
	int _out_type;			//F=
	bool _reverse;			//-r
	bool _multiStart;		//--ms
	bool _rangefile;		//バケット範囲を出力する場合trueとなる

	void setArgs(void);

public:
  // コンストラクタ
	kgMbucket(void);
	~kgMbucket(void){}

	//実行メソッド
	int run(void);

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

};

}
