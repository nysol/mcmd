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
// kgcal.h 項目間演算クラス
// =============================================================================
#pragma once
#include <string>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgError.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgFunction.h>
#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/classic_core.hpp>
#include <boost/spirit/include/classic_utility.hpp>
#include <boost/spirit/include/classic_ast.hpp>

using namespace kglib;
using namespace boost::spirit::classic;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgCal:public kgMod {
	// 引数
	kgArgFld  _kField; // k=
	kgstr_t   _expr;   // c=
	kgstr_t   _newFld; // a=
	kgCSVkey  _iFile;  // i=
	kgCSVout  _oFile;  // o=
	kgVal     _prvRsl;// 前行の結果:初期値はNULL
	kgAutoPtr1 <ptime> _prv_t_ap;
	kgAutoPtr1 <date> _prv_d_ap;
	char  _prv_s_p[KG_MAX_STR_LEN];

	kgFuncMap _funcMap;

	// 引数セット
	void setArgs(void);

	// 構文木を走査するiterator型定義
	typedef tree_match<std::string::const_iterator,
		node_val_data_factory<void *> >::tree_iterator tree_node_iter_t;

	// 計算実行
	void calculate( tree_node_iter_t const &iter );

	// 前処理(正規表現のコンパイルなど)
	void runPreProcess( tree_node_iter_t const &iter );

	// 構文解析後の初期設定及び引数タイプチェック
	kgVal* setFuncArg( tree_node_iter_t const &iter );

	// 構文解析後の関数の引数の数のチェック
	void chkFuncArgc( tree_node_iter_t const &iter );

	// ノードに関数(クラス)のアドレスの設定しクラスを初期化する
	char setFuncType( tree_node_iter_t const &iter );

	// CSV項目出力
	void writeFld(char** fld,int size, kgVal& val);

	//前回データセット
	void prersl_set(kgVal *rls);

public:
	// コンストラクタ
	kgCal(void);
	~kgCal(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}

