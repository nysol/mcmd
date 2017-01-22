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
// kgConfig.h 設定ヘッダファイル
// =============================================================================
#pragma once
#include <string>

// ファイル名(パス込)の最大長
#define KG_MaxFileNameLen 256

// read,writeのサイズ (KG_MaxRecLenで割り切れ値にする必要あり)
//#define KG_ioSize 4096000
// #define KG_iSize 4096000000 //test用
#define KG_iSize 4096000
#define KG_oSize 4096000

// 一行あたりの最大文字数 (上限:1024000)
// KG_ioSizeの1以上の整数倍でなければならない。
#define KG_MaxRecLen 1024000
#define KG_LimitRecLen 10240000

// 出力バッファサイズ (上限:1024000)
// KG_ioSizeの1以上の整数倍でなければならない。
//#define KG_OutBufSize 40960
//#define KG_LimitOutBufSize 1024000

// キー単位ごとに処理する際に使用するバッファ数
//  デフォルトでの最大バッファサイズは
// (KG_MaxRecLen *2 + 4 * KG_ioSize) * KG_BlockCount
#define KG_BlockCount 128

// ライブラリ関数が用いるデフォルトの一時ファイル用ディレクトリ
#define KG_TmpPath "/tmp"

// Mコマンドのエラーメッセージ出力レベル
// 0:何も表示しない
// 1:ERRORメッセージのみ表示
// 2:+WARNINGメッセージ表示
// 3:+ENDメッセージ表示
// 4:+MSGメッセージ表示
// 5:+DEBAGメッセージ表示
#define KG_VerboseLevel 4

// 再帰メッセージ出力フラグ
#define KG_RecursiveMsg true

// KGMODが内部で扱うデフォルトの文字列encoding
#define KG_DEFAULT_ENC "ja_JP.UTF-8"

// 別名登録
typedef char         kgchr_t;
typedef std::string  kgstr_t;

// 一項目あたりの最大文字数
#define KG_MAX_STR_LEN 100000

// cal,sel時最大項目数
#define KG_MAX_CAL_TERMS 1000

// 有効桁数
#define KG_PRECISION 10

// 最大有効桁数
#define KG_MAX_PRECISION 16

//### 以下システムconfiguration

// size_tの最大値
#define KG_SIZE_MAX ((size_t)-1)

// 引数最大長
#define KG_ARGLEN_MAX 102400

// OPEN　FLG
#define KG_IOPEN_FLG O_RDONLY
#define KG_OOPEN_FLG O_WRONLY|O_TRUNC|O_CREAT|O_APPEND



