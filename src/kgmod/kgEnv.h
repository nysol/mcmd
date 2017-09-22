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
// kgEnv.h 環境変数クラス
// ============================================================================
#pragma once
#include <iostream>
#include <string>
#include <kgConfig.h>
#include <kgMethod.h>
#include <boost/random.hpp>
using namespace std;

namespace kglib { ////////////////////////////////////////////// start namespace

// kgmodが利用するグローバル変数クラス
class kgEnv {
	int     oSize_;        // readのsize
	int     iSize_;        // writeのsize
	int     maxRecLen;     // 一行の最大文字数
	int     outBufSize;    // 出力バッファのサイズ
	int     verboseLevel;  // メッセージ出力をしないフラグ(kgInitで設定)
	kgstr_t tmpPath;       // 一時ファイル用ディレクトリパス名
	string  encoding;      // CSVとコンソールのエンコーディング
	bool    noFldName;     // 1行目は項目名行でない
	int     _precision;    // double型の出力有効桁数
	bool    _fldByNum;     // 項目番号で指定する
	bool    recursiveMsg_; // 再帰的にmodのエラーメッセージを出すかどうか

	bool    msgTimebyfsec_; // fractional_secondsによる時刻表示
	
	bool    sigact_;       // シグナルトラップ起動中かどうか(true:起動中, false:なし)
	int     blockCount_;   // キー単位ごとに処理する際に使用するバッファ数

  kgAutoPtr1<boost::variate_generator< boost::mt19937,boost::uniform_int<>  > > randStrAP_;
	
public:
	kgEnv(void);
	~kgEnv(void){}
	
	// アクセッサ
	size_t  iSize(void) 					const{ return iSize_; }
	size_t  oSize(void) 					const{ return oSize_; }
	int     getMaxRecLen(void)		const{ return maxRecLen; }
	int     getOutBufSize(void)		const{ return outBufSize; }
	int     getVerboseLevel(void)	const{ return verboseLevel; }
	kgstr_t getTmpPath(void)			const{ return tmpPath; }
	string  getEncoding(void)			const{ return encoding; }
	bool    getNoFldName(void)		const{ return noFldName; }
	int     precision(void)				const{ return _precision; }
	bool    fldByNum(void)				const{ return _fldByNum; }
	bool    recursiveMsg(void)		const{ return recursiveMsg_; }
	int     getBlockCount(void)		const{ return blockCount_; }
	bool    sigactcheck(void)			const{ return sigact_; }
	bool    msgTimebyfsec(void)			const{ return msgTimebyfsec_; }

	// 有効桁数セット
	void    precision(int p);

	// シグナル状況登録
	void sigact(bool b=true){sigact_=b;}
	void verblvl(int veb){ verboseLevel=veb; }
	void setTmpPath(kgstr_t tp){ tmpPath=tp; }
	
	// 乱数文字作成
	string  randStr(size_t size);

};

} //////////////////////////////////////////////////////////////// end namespace

