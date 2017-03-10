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
// kgcat.h 複数のcsvファイルの併合クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod  ////////////////////////////////////////////// start namespace
{
class kgCat : public kgMod 
{
	// 引数
	vector<kgstr_t> _iFilename;	// i=:ファイル名
	kgCSVfld* _iCsv;						// i=:kgcsv class
	kgCSVfld _iFile; 						// stdin専用
	kgCSVout _oFile; 						// o=
	vector<kgstr_t> _fvstr;			// f=:項目名
	kgArgFld _fField;						// f=:kgargfldクラス
	vector<size_t> _kv;			// f=:項目名

	vector<kgstr_t> _fldNames;
	size_t _fldSize;
	size_t _iCnt; //処理行数

	// 併合パターンフラグ
	bool _stdin;
	bool _force;
	bool _stop;
	bool _skip;
	bool _skip_fnf; // file not found でerror終了する
	bool _zskip;    // ０バイトファイルはskipする

	bool _add_fn;   // 項目にファイル名の追加
	bool _is_f;			// f=指定あり
	size_t  _inf_pos;	// オープンするファイルナンバー
	
	// 引数セット
	void setArgs(void);

	// 処理ファイルセット&アンセット
	int readFile_set(kgstr_t fname);
	void readFile_unset(void);

	// 出力
	void output(kgCSVfld* csv);

public:
	// コンストラクタ
	kgCat(void);
	~kgCat(void){}

	// 実行メソッド
	int run(void);

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iCnt; }
	size_t oRecNo(void) const { return _oFile.recNo(); }

};

}

