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
// kgFldHash.h 項目ハッシュ(hashavg,hashsumで使用)
// =============================================================================
#pragma once
#include <vector>
#include <kgCSV.h>
#include <kgArgFld.h>
#include <kgMethod.h>

namespace kglib {////////////////////////////////////////////// namespace start

class kgFldHashNode;

class kgFldHash 
{
		int _hashVal;                 // hashのバケットサイズ
		int _cnt;                     // 現在登録されている値の数
		vector<kgFldHashNode*> _node; // バッケトへのポインタ
		kgCSVfld* _csv;
		kgArgFld* _key;
		kgArgFld* _fld;
		bool _keynull;
		unsigned int calHashVal(const char** flds);

	public:
		// コンストラクタ パラメータ省略時のバケット数は199999
		kgFldHash(int hashVal, kgCSVfld* csv, kgArgFld* key, kgArgFld* fld);

		// デストラクタ
		~kgFldHash(void);

		// 挿入
		kgFldHashNode* insert(const char** flds);
		kgFldHashNode* node(int num) const { return _node.at(num); }

		int recLen(void)  { return _csv->recLen(); }    // レコード長
		int csvSize(void) { return _csv->fldSize(); }   // データ項目数
		char* csv(int num){ return _csv->getVal(num); } // データのnum番目項目
		
		int key(int num) { return _key->num(num);} // k=で指定した第num番目項目番号
		int keySize(void) { return _key->size(); } // k=で指定した項目数
		int fldSize(void) { return _fld->size(); } // f=で指定した項目数

		int hashVal(void){ return  _hashVal;}
		bool   keynull(void){ return _keynull;}
};


class kgFldHashNode 
{
	kgFldHash*        _hash;
	kgAutoPtr2<char>  _ap1;  // _bufをラッピングするsmart pointer
	char*             _buf;  // 一行まるまま登録領域
	kgAutoPtr2<char*> _ap2;  // _idxをラッピングするsmart pointer
	char**            _idx;  // 登録されたデータの各項目へのポインタ
	vector<double>    _cnt;  // null以外件数
	vector<double>    _sum;  // 合計
	vector<bool>      _nul;  // nullが一行でもあればtrue
	kgFldHashNode*    _next; // 次nodeへのリンク

	public:
	// コンストラクタ
	kgFldHashNode(const char** flds, kgFldHash* hash);
	virtual ~kgFldHashNode(void) {};

	// keyの比較
	bool keycmp(const char** flds);

	void next(kgFldHashNode* next) {_next=next;}
	void cnt(int num, double v) { _cnt.at(num)+=v;}  // f=num番目の項目cnt up
	void sum(int num, double v) { _sum.at(num)+=v;}  // f=num番目の項目sum up
	void nul(int num, bool   v) { _nul.at(num) =v;}

	// accessors(get)
	kgFldHashNode* next(void) const {return _next;}
	char* idx(int num) const { return *(_idx+num); }
	double cnt(int num) const {return _cnt.at(num);} // f=num番目の件数を返す
	double sum(int num) const {return _sum.at(num);} // f=num番目の合計を返す
	bool   nul(int num) const {return _nul.at(num);}
};
}////////////////////////////////////////////// namespace end
