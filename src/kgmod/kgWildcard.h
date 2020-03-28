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
// kgWildcard.h : ファイルカードクラス
// ============================================================================
#pragma once

#include <string>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;

namespace kglib ////////////////////////////////////////////// start namespace
{
class kgWildCard 
{
  kgstr_t  _pat;         // ワイルドカードを含むパターン文字列 (ex "abc*d?a*")
  string::size_type _patLen; // その長さ
	bool		 _hasWildCard; // _patにワイルドカード記号が含まれるかどうか

	// ワイルドカード記号格納配列 (ex "   * ? *")
	kgchr_t  _wildc[KG_MAX_STR_LEN];
	// 決定性有限オートマトン(FSA) 全てtrueでmatchに
	bool     _state[KG_MAX_STR_LEN];

public:
	kgWildCard(const kgstr_t& p);
	~kgWildCard(void){}
	bool match(const kgstr_t& txt);
	bool hasWildCard(void){ return _hasWildCard; }
};

}
