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
// kgcsv2arff.h CSV→wekaのデータフォーマット変換
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgCsv2arff : public kgMod {

	// 引数
	kgArgFld _dField;  // d=
	kgArgFld _DField;  // D=
	kgArgFld _sField;  // s=
	kgArgFld _nField;  // n=
	kgCSVfld _iFile;   // i=
	kgCSVout _oFile;   // o=
	kgstr_t  _titles;		 //	T=
	vector<char *> _d_stock_p;
	void setArgs(void);
public:
	// コンストラクタ
	kgCsv2arff(void);
	~kgCsv2arff(void){
		for(vector<char*>::iterator it = _d_stock_p.begin();it != _d_stock_p.end();it++){
			if(*it){ delete [] *it; }
		}
	}

	//実行メソッド
	int run(void);

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

};

}
