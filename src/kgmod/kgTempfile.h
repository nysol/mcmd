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
// kgTempfile.h : 一時ファイルクラス
// ============================================================================
#pragma once
#include <string>
#include <kgEnv.h>

using namespace std;

namespace kglib  ////////////////////////////////////////////// start namespace
{
class kgTempfile 
{
	kgEnv* env_;
	vector<string> names_;
public:
	 kgTempfile(void) : env_(0){}
	 kgTempfile(kgEnv* env) : env_(env){}
	~kgTempfile(void);
	void init(kgEnv* env){env_=env;}

	// 一時ファイルを作成し、そのファイル名を返す
	string create(bool pipe=false, string prefix="");
	// 一時ファイル名を返す
	string name(void);
	void remove_all(void);
	//登録ファイル名チェック
	bool empty(void);
	static void interrupt_clean(kgstr_t spath);

};

}
