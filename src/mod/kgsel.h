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
// kgsel.h 条件式による行選択クラス
// =============================================================================
#pragma once
#include <kgConfig.h>
#include <kgmod.h>
#include <kgVal.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgFunction.h>
#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/classic_ast.hpp>

using namespace kglib;
using namespace boost::spirit::classic;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSel:public kgMod 
{
	// 引数
	kgstr_t   _expr;   // c=
	kgstr_t   _newFld; // a=
	kgCSVkey  _iFile;  // i=
	kgCSVout  _oFile;  // o=
	bool			_reverse;// -r
	kgCSVout  _uFile;  // u=
	bool      _uFlg;

	kgFuncMap _funcMap;

	// 前行の結果を保持する変数(初期値はNULL)
	kgVal     _prvRsl;

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

	void deleteFuncClass( tree_node_iter_t const &iter );

	void setArgs(void);

public:
	// コンストラクタ
	kgSel(void);
	~kgSel(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);


};

}

