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
// kgsortf.h 項目指定によるレコードの並べ換えクラス
// =============================================================================
#pragma once

#include <vector>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgTempfile.h>
//#include <pthread.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

namespace kgsortf_local {//////////////////////////////////////////////////
	// -----------------------------------------------------------------------------
	// 内部で利用するクラスとデータ構造
	// -----------------------------------------------------------------------------
	struct _COMP_FLD {
		int    cnt; // その数
		int*   num; // キー項目番号の配列
		int*   flg; // 比較フラグ 0:文字昇順 1:文字降順 2:数値昇順 3:数値降順
	};

} //////////////////////////////////////////////////////////////////////////////



class kgSortf :public kgMod{

	// 引数
	kgArgFld _fField;    // f=
	kgCSVfld _iFile;     // i=
	kgCSVout _oFile;     // o=
	int      _pways;     //pways=
	size_t   _maxlines;  //maxlines=
	int      _blocks;    //blocks=
	int      _threadCnt; // threadCnt=
	bool 		 _noflg;
  void setArgs(void); // 引数セット

	kgTempfile tempFile_;                        // 分割ソート時の一時ファイル
	vector< vector<kgstr_t> > tmpName_;          // 一時ファイルの名前を格納する2次元vector(level,no)
	kgstr_t& getTmpName(size_t level,size_t no); // そのアクセス用
	kgstr_t& newTmpName(size_t level,size_t no); // その登録用

	struct kgsortf_local::_COMP_FLD cfld_;        // key項目情報
	kgAutoPtr2<int>  compFld_num_; // その動的メモリ
	kgAutoPtr2<int>  compFld_flg_; // その動的メモリ
	void setCfld(kgArgFld* fField); // 初期化
	int  cmpFld(char** fld1, char** fld2); // fld1,fld2の大小比較

	void qsort5(char*** base, int nel); // quick sort
	void writeBuf(char ***index, int recCnt, int fldCnt, kgstr_t& ofName); // indexの内容をofNameに出力
	void do_sort(char*** index, int recCnt, kgstr_t ofName); // qsort5+writeBuf

	int sort(kgCSVfld& csv);
	void merge(int level, int iBgn, int iEnd, int oNum, bool final);
	int mergeOneLevel(int level, int iCnt);

public:
  // コンストラクタ&引数セット
	kgSortf(void);
	~kgSortf(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }
	
	void replace_ifile(kgCSVfld * csv){
		if(_iFile.opened()){ _iFile.clear(); }
		_iFile.replaceSet(csv,_env,_nfn_i);
	}
	//実行メソッド
	int run(void);
	static void* run_sort_thread(void *obj);

	//実行メソッド
	void prerun_noargs(int fd);
	void run_noargs(void);
	void forcedClose(void){
		_iFile.close();     // i=
		_oFile.forceclose();     // o=
		
	}
};
struct sortArgST{
	kgSortf * mobj;
	char*** start;
	int     blkSize;
	kgstr_t ofName;
};


}

