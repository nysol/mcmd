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
// kgcombi.h 組合出力クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgCombi : public kgModIncludeSort 
{

	// 引数
	kgCSVkey _iFile;					// i=
	kgCSVout _oFile;					// o=
	kgArgFld _kField;					// k=
	kgArgFld _fField;					// f=
	size_t 	 _combi_cnt;			// n=
	vector<kgstr_t> _aField;	// a=
	bool _p_flg;							// -p　順列フラグ
	bool _dup_flg;						// -dup　重複させるフラグ

	char ** 		_writedata;		//出力するデータセットされる
	vector<int> _CombiList;		//出力する値の番号がセットされる

	// 組合計算
	void combi(vector<char*>& fldlist,unsigned int from,unsigned int depth);
	// 順列計算
	void perm(vector<char*>& fldlist,int i);
	// 引数セット
	void setArgs(void);

public:
	// コンストラクタ
	kgCombi(void);
	~kgCombi(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);


};

}

