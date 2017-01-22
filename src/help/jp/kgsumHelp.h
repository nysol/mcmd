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
/// kgsumHelp.h : kgsum help
// =============================================================================
_titleL="項目値の合計";
_docL="\
\n\
MSUM 項目値の合計\n\
\n\
k=パラメータで指定した項目の値が同じ行について、\n\
f=パラメータで指定した集計項目の項目値を合計する。\n\
(注)k=とf=パラメータで指定した項目以外については、どの行が出力されるかは不定であることに注意してください。\n\
\n\
書式\n\
\n\
msum f= [k=] [-n] [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   集計の単位となる項目名リスト（複数項目指定可）を指定する。\n\
  f=   ここで指定された項目（複数項目指定可）の値が集計される。NULL値は無視される。\n\
  -n   f=で指定した項目にNULL値が入っていると計算結果もNULLとする。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目の合計値を計算し、\n\
「数量合計」と「金額合計」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    B,1,15\n\
    A,2,20\n\
    B,3,10\n\
    B,1,20\n\
    $ msum k=顧客 f=数量:数量合計,金額:金額合計 i=dat1.csv o=rsl1.csv\n\
    #END# kgsum f=数量:数量合計,金額:金額合計 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,数量合計,金額合計\n\
    A,3,30\n\
    B,5,45\n\
";

