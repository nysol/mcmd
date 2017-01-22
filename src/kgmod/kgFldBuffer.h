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
// kgFldBuffer.h 項目データバッファクラス
// ============================================================================
#pragma once
#include <kgMethod.h>
#include <kgTempfile.h>

namespace kglib { ////////////////////////////////////////////// start namespace

// 専用バッファリングクラス
// 一度拡張されると縮小されない
// マックスページを超えると以降のデータはファイル書き出される
// page
// +----------------
// |
// |
// +----------------
// +----------------
// |
// |
// +----------------
// +----------------
// |
// |
// +----------------
class kgFldBuffer{
	size_t max_page_;		// 最大ページ数
	size_t page_size_;  // ページ自体サイズ
	size_t limit_page_; // 確保済みページ数
	size_t w_page_; 		// 書込中ページ	
	size_t r_page_;			// 読込中ページ
	size_t r_pos_;			// 読込位置

	vector<kgAutoPtr2<char> > page_p_; // ページ領域へポインタ
	vector<size_t > end_pos_; 				 // データ終了位置

	kgAutoPtr2<char> fpage_p_;	// ファイル読み込み領域
	kgTempfile tempFile_; 			// 書き出しファイル用
	vector<string> flist_;			// 書き出しファイルリスト
	char* pageSet(void);				// 読み込みページセット
	void fileload(int fno);			// ファイル（バッファファイル）からの読み込み

public:
	//コンストラクタ	
	kgFldBuffer(size_t pmax=10,size_t size=KG_iSize ,kgEnv* env=0):
		max_page_(pmax),page_size_(size),limit_page_(0),w_page_(0),r_page_(0),r_pos_(0),tempFile_(env){
		page_p_.resize(max_page_);	 		
		end_pos_.resize(max_page_,0);
	}
	~kgFldBuffer(void){};
	// バッファへの書き込み
	void write(char * start,size_t size);
	// データ項目セット
	int getFld(char ** pnt, int fldcnt);
	// SEKKTOP 
	int seekRTop(void);
	// 初期化
	void reset(void);

};
}


