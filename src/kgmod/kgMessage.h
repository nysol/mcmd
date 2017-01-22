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
// kgMessage.h メッセージ関係クラス
// =============================================================================
#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <kgConfig.h>
#include <kgmod.h>
using namespace std;

namespace kglib { ////////////////////////////////////////////// start namespace

// メッセージ出力クラス
class kgMsg {

public:
	enum Plevel {ERR,WAR,END,MSG,DEB};

private:
	kgEnv* env_;

	// ERR: 1以上
	// WAR: 2以上
	// END: 3以上
	// MSG: 4以上
	// DEB: 5以上
	Plevel plevel_;

	// ヘッダ文字列取得
	string header(void);
	// 日付時間取得
	string getTime(void);
	// 出力要否チェック
	bool isOn(void);
	// 出力処理
	void WriteMsg(string v,string t);

public:
	kgMsg(Plevel plevel, kgEnv* env){
		plevel_=plevel;
		env_=env;
	}
	~kgMsg(void){}

	//メッセージ出力
	void output(const string& v, const string& comment="");
	void output(const vector<string>& vv, const string& comment="");
	void output(kglib::kgMod* kgmod, string v, const string& comment="");
	void output(kgMod* kgmod, vector<string> vv, const string& comment="");

};

} //////////////////////////////////////////////////////////////// end namespace

