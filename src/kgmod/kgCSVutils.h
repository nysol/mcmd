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
// kgCSVutils.h csvファイル(infile)関連のutils
// ============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgCSV.h>

namespace kglib {////////////////////////////////////////////// namespace start

// -----------------------------------------------------------------------------
// c=で与えられた式の項目名(${..})を検索し，項目名を展開する．
// exp1. c=sum(${a*})  c=sum(${aa},${ab})
// exp2. c=sum(${1_2L})  c=sum(${1},${2},${3})
// 返り値:展開後の式
// -----------------------------------------------------------------------------
kgstr_t evalCalFldName(kgstr_t& expr, kgCSV& iFile,bool fldno);

// -----------------------------------------------------------------------------
// d=で与えられたファイル名で項目名(${..})を検索し，
// 分割した文字列を返す、項目番号をセットする
// exp1. d=dat-${日付}  	返り値文字列:dat-,\0 項目番号:1 
// exp2. d=${日付}${時間}	返り値文字列:\0,\0,\0 項目番号:1,2
// -----------------------------------------------------------------------------
vector<kgstr_t> evalFileFldName(kgstr_t& expr, kgCSV& iFile,vector<int>& set,bool fldno);

// -----------------------------------------------------------------------------
// 項目名->項目番号を評価する．（evalflg=true:項目名変換有,evalflg=false:項目名変換無）
// -----------------------------------------------------------------------------
vector<int> evalFldName(vector<kgstr_t>& name, kgCSV* csv,bool fldByNum,bool evalflg=false);

// -----------------------------------------------------------------------------
// 項目名->項目番号を評価する．（項目名変換あり）
// 項目名変換するのは以下の２つ．
// 1. 範囲指定 -:数値指定のみの場合
//	 ex. 1-3 => 1,3
// 2. ワイルドカード *:任意の文字列にマッチ ?:任意の一文字にマッチ
// 3. 第二vector(attr)の第一vector(name)による置換(&をnameに置換)
//   ex. aaa:&_cm =>aaa:aaa_cm  aa*:&_cm => aab:aab_cm,aac:aac_cm,...
// -----------------------------------------------------------------------------
vector<int> evalFldName(vector<kgstr_t>& name, vector<kgstr_t>& attr, kgCSV* csv,bool fldByNum);

}////////////////////////////////////////////// namespace end
