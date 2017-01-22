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
// kgEnv.h エラー処理クラス
// ============================================================================
#pragma once
#include <vector>
#include <string>
#include <exception>

using namespace std;

namespace kglib  ////////////////////////////////////////////// start namespace
{
class kgError : public std::exception 
{
	// errorをcatchした関数のメッセージ
	vector<string> message_;

	public:
	// コンストラクタ
	kgError(){}
	kgError(string msg);

	// デストラクタ
	~kgError(void) throw() {}

	string::size_type size(void)   const { return message_.size(); }
	string         message(int no) const { return message_.at(no); }
	vector<string> message(void  ) const { return message_;        }

	void   addMessage(string msg);
	void   addModName(string msg);
	//クラスメソッド
	static void fldCntErr(int fldCnt, int j);
	static void recLenErr(size_t manlen);
	static void recLenErr(void);
};

} //////////////////////////////////////////////////////////////// end namespace
