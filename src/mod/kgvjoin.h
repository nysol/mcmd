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
// kgvjoin.h ベクトル要素の参照結合クラス
// =============================================================================
#pragma once
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>


using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgVjoin:public kgMod 
{
	// 引数
	kgArgFld _vfField; // vf=
	kgArgFld _mkField; // K=
	kgArgFld _fField; // K=
	kgCSVfld _iFile;  // i=
	kgCSVfld _mFile;  // m=
	kgCSVout _oFile;  // o=
	kgstr_t	 _nullVal; // n=
	char		 _delim; //delim=
	char		 _delimstr[2]; //delim=
	bool 	 _add_flg;  //-A

	char _outstr[KG_MAX_STR_LEN];

	map<kgstr_t,kgstr_t> _itmSet; 
	// 引数セット
	void setArgs(void);
	void output_n(char *str,bool eol);

public:
	// コンストラクタ&引数セット
	kgVjoin(void);
	~kgVjoin(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
