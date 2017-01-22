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
// kgselstr.h 文字列による行選択クラス
// =============================================================================
#pragma once
#include <string>
#include <vector>
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSelstr:public kgModIncludeSort 
{
	// 引数
	kgArgFld _kField;  // k=
	kgArgFld _fField;  // f=
	vector<kgstr_t> _vField;//v=
	vector<wstring> _vFieldw; //-sub -vのときのみ_vFieldをwstringでコピー

	map<string,bool> _val;  // v=のmapによる実装(将来はmapで統一する)
	map<wstring,bool> _valw;

	kgCSVblk _iFile;   // i=
	kgCSVout _oFile;   // o=
	kgCSVout _uFile;   // u=

	int			 _macth_type; // 0:normal 1:-head 2:-tail 3:-sub  
	bool     _widechr; // -w
	bool     _sel_flg; // -F
	bool     _keysel_flg; // -R
	bool     _keyval_flg; // -V
	bool     _reverse; // -r
	bool     _elsefile; // 不一致ファイルを使用するかどうか(u=の指定があればtrue)

	// 文字列比較
	bool str_comp(char* str);
	// 文字列チェック
	bool str_check(vector<int>& cnt,char** str);
	void clearVal(void);

	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ&引数セット
	kgSelstr(void);
	~kgSelstr(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
