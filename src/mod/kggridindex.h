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
// kggridindex.h 
// =============================================================================
#pragma once
#include <cfloat>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <boost/filesystem.hpp>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgGridindex : public kgModIncludeSort
{
	// 引数
	kgArgFld _fField;   // f=
	kgArgFld _hField;   // h=
	kgArgFld _nField;   // n=
	kgstr_t  _mode;			// mode=
	kgCSVfld _iFile;    // i=
	boost::filesystem::path oPath_; // O=
	bool _forceFlg;			//-p

	size_t _bufSize; // bufSize=

	// f=で指定した項目がとる値の一覧を格納する=>msearch.rbでasis項目を範囲検索するために必要となる=>JSONで保存
	// 　map stringは項目名、setは値一覧
	map<string, set<string> > _asis_value;

	vector<int> hSize_; // h=で指定した各項目のhash size
	vector<vector<double> > nRange_; // n=で指定した各項目の区切り範囲
	size_t _outCount;		 // 総出力件数

	// 引数セット
	void setArgs(void);	

	unsigned int hashval(char *key, int hashval);
public:
  // コンストラクタ
	kgGridindex(void);
	~kgGridindex(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _outCount; }

	void outCountUp(size_t n){_outCount+=1;}

	//実行メソッド
	int run(void);

};

}
