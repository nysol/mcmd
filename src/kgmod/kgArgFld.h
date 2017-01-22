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
// kgArgFld.h 引数項目クラス
// ============================================================================
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <kgConfig.h>
#include <kgError.h>
#include <kgCSV.h>

using namespace std;

namespace kglib ////////////////////////////////////////////// start namespace
{

// コマンドライン引数クラス
class kgArgFld 
{
	kgCSV*          _csv;  // 対象CSVクラス
	vector<kgstr_t> _name; // 項目名
	vector<kgstr_t> _attr; // 属性
	vector<int>     _num;  // name位置->CSV項目番号
	vector<int>     _flg;  // csv項目番号->name位置

	// _name,_attrの項目名展開＆
	// _name,_attrから_num,_flgへのデータセット(set関数で使用)
	void _num_flg_Set(kgCSV* csv ,bool fldno,bool attrEval=true);

public:

	// コンストラクタ
	kgArgFld() : _csv(0){}

	// set関数
	void set(vector< vector<kgstr_t> >& vvs, kgCSV* csv ,bool fldno, bool attrEval=true) throw(kgError);
	void set(vector<kgstr_t>& vs, kgCSV* csv,bool fldno) throw(kgError);
	void set(kgstr_t& s, kgCSV* csv,bool fldno) throw(kgError);

	// 登録されている項目名数
	size_t size(void)			const { return _name.size();}
	size_t attrSize(void)	const { return _attr.size();}
	size_t numSize(void)	const { return _num.size(); }

	//アクセッサ
	const kgCSV*					csv(void)				const	{ return _csv; }	
	const vector<kgstr_t> getAttr(void) 	const { return _attr; }
	const vector<kgstr_t> getName(void) 	const { return _name; }
	const vector<int>     getNum(void)  	const { return _num;  }
	const vector<int>     getFlg(void)  	const { return _flg;  }
	const vector<int>*    getFlg_p(void)	const { return &_flg; }

	const kgstr_t name(size_t num) const;
	const kgstr_t attr(size_t num) const;
	int   num (size_t num) const;
	int   flg (size_t num) const;

};

} //////////////////////////////////////////////////////////////// end namespace
