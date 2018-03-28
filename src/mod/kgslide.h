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
// kgslide.h 前行データ項目の追加クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgMethod.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgSlide : public kgModIncludeSort
{

	// 引数
	kgArgFld _kField;	 	//k=
	kgArgFld _fField;		//f=
	kgCSVkey _iFile;		//i=
	kgCSVout _oFile;		//o=
	bool 		 _nulout;		//-n
	bool 		 _reverse;	//-r
	bool 		 _last;			//-l
	int			 _interval;	//t=
	size_t 	 _stock_cnt;

	// データ確保用、出力用
	void output(int spos,int epos);
	char ** _d_stock_ap;
	kgAutoPtr2<char*> _o_stock_ap;
	kgAutoPtr2<char*> _onew_stock_ap;

	//循環インクリメント＆デクリメント
	int pos_proceed(int i,bool reverse=false){
		if (reverse) { return (i+_interval)%(_interval+1); }
		else				 { return (++i)%(_interval+1); }
	}

	// 引数セット
	void setArgs(void);

public:
  // コンストラクタ
	kgSlide(void);
	~kgSlide(void){
		if(_d_stock_ap!=NULL){
			for(size_t j=0;j<_stock_cnt;j++){
				delete [] _d_stock_ap[j];
			}
			delete [] _d_stock_ap;
		}
	}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
