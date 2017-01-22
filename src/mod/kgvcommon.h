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
// kgvcommon.h ベクトル要素の参照選択クラス
// =============================================================================
#pragma once

#include <string>
#include <vector>
#include <map>
#include <kgConfig.h>
#include <kgEnv.h>
#include <kgmod.h>
#include <kgError.h>
#include <kgArgs.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>


using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgVcommon:public kgMod {

	// 引数
	kgArgFld _vfField; // vf=
	kgArgFld _mkField; // K=
	kgCSVfld _iFile;   // i=
	kgCSVfld _mFile;   // m=
	kgCSVout _oFile;   // o=
	char		 _delim; //delim=
	char		 _delimstr[2]; //delim=
	bool     _reverse;  //-r
	bool 	 _add_flg;  //-A
	char _outstr[KG_MAX_STR_LEN];

	//item表
	set<string> _itmSet; 

	// 引数セット
	void setArgs(void);

	void output_n(char *str,bool eol);

public:
	// コンストラクタ&引数セット
	kgVcommon(void);
	~kgVcommon(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
