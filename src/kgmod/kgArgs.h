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
// ============================================================================
// kgArgs.h コマンドライン引数クラス
// ============================================================================
#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <kgConfig.h>
#include <kgError.h>


using namespace std;

namespace kglib  ////////////////////////////////////////////// start namespace
{
// コマンドライン引数クラス
class kgArgs 
{
	// 登録されているkeywordの情報
	set<string> _available;	

	map<string,kgstr_t> keyVal_;
public:
	enum _ADD_PARAM {
		NOADD    = 0,
		COMMON   = 1,
		IODIFF   = 2,
		NULL_KEY = 4,
		NULL_IN  = 8,
		NULL_OUT = 16,
		ALLPARAM = 31
	};
	// 引数登録
	void add(size_t c, const char **v) ;
	void add(string str);
	void add(const string& key, const kgstr_t& val) ;

	// 引数サイズ＆イテレーター	
	map<string,kgstr_t>::size_type      size (void) const{ return keyVal_.size();  }
	map<string,kgstr_t>::const_iterator begin(void) const{ return keyVal_.begin(); }
	map<string,kgstr_t>::const_iterator end  (void) const{ return keyVal_.end();   }
	
	// keywordに対応する値を返す
	kgstr_t get(const string& keyWord, bool mandatory=false, bool nullNG=false) const ;
	bool find(const string& keyWord);
	// 登録された引数を，様々なデータ型に変換する関数群
	bool 						toBool(const string& keyWord) const;
	kgstr_t					toString(const string& keyWord, bool mandatory=false, bool nullNG=false) const;
	vector<kgstr_t> toStringVector(const string& keyWord, bool mandatory=false, bool nullNG=false) const;
	set<kgstr_t> 		toStringSet(const string& keyWord, bool mandatory=false, bool nullNG=false) const;
	vector< vector<kgstr_t> > toStringVecVec(const string& keyWord, const wchar_t delim, unsigned int rowSize, bool mandatory, bool nullNG=false) const;
	vector< vector<kgstr_t> > toStringVecVec(const string& keyWord, const kgstr_t delim, unsigned int rowSize, bool mandatory, bool nullNG=false) const;

	// 使用不能パラメータチェック
	void paramcheck(const char *cstr, int addCommonArgs=COMMON);

	// 全引数を一つの文字列に変換する(コマンドライン出力用)
	string to_s(void) const;
	set<string>::iterator begin_avail(void) const{ return _available.begin(); }
	set<string>::iterator end_avail (void) const{ return _available.end(); }

};

} //////////////////////////////////////////////////////////////// end namespace
