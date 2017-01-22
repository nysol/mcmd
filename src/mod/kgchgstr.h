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
// kgchgstr.h 文字列の置換
// =============================================================================
#pragma once

#include <vector>
#include <map>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>


using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgChgstr:public kgMod 
{
	// 引数
	kgArgFld _fField; // f=
	kgCSVfld _iFile;  // i=
	kgCSVout _oFile;  // o=
	map<kgstr_t,kgstr_t>       _cField;     // 完全一致の場合
	vector<vector<kgstr_t> >  _cFieldSub;  // -subの場合
	vector<vector<wstring> > _cFieldSubw; // -sub -wの場合
	kgstr_t	 _elsestr; 		//O=
	bool     _substr;		// -sub
	bool     _widechr;	// -w
	bool     _F_flg;		// -F
	bool     _add_flg;	// -A
	bool     _estrflg;	//O=の指定があるとセットされる

	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ&引数セット
	kgChgstr(void);
	~kgChgstr(void){}

	//実行メソッド
	int run(void);
	
	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

};

}
