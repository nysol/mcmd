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
/// kghashavgHelp.h : kghashavg help
// =============================================================================
_titleL="ハッシュ法による項目値の平均";
_docL="\
\n\
MHASHAVG ハッシュ法による項目値の平均\n\
\n\
hash法を使ってk=パラメータで指定した項目を単位にして、f=パラメータで指定した項目値の平均を計算する。\n\
mavgとの違いは、キー項目の並べ変えが必要ないため、その分処理速度が速い。\n\
ただし、キーのサイズ(キー項目のとる値の種類数)が多い場合は処理速度が遅くなる。\n\
\n\
書式\n\
\n\
mhashavg f= [hs=] [k=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=    ここで指定された項目(複数項目指定可)の平均が計算される。\n\
        :(コロン）で新項目名を指定可能。例）f=数量:数量平均\n\
  k=    ここで指定された項目をキーとして集計する(複数項目指定可)。\n\
  hs=   ハッシュサイズ【デフォルト値:199999】\n\
        ハッシュサイズを指定する。【デフォルト値:199999】\n\
        詳細に関してはmhashsum参照\n\
  -n    NULL値が1つでも含まれていると結果もNULL値とする。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位にして、「数量」と「金額」項目の平均を計算する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,\n\
    B,,15\n\
    A,2,20\n\
    B,3,10\n\
    B,1,20\n\
    $ mhashavg k=顧客 f=数量,金額 i=dat1.csv o=rsl1.csv\n\
    #END# kghashavg f=数量,金額 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客,数量,金額\n\
    A,1.5,20\n\
    B,2,15\n\
\n\
例2: NULL値の出力\n\
\n\
-nオプションを指定することで、NULL値が含まれている場合は、結果もNULL値として出力する。\n\
\n\
    $ mhashavg k=顧客 f=数量,金額 -n i=dat1.csv o=rsl2.csv\n\
    #END# kghashavg -n f=数量,金額 i=dat1.csv k=顧客 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客,数量,金額\n\
    A,1.5,\n\
    B,,15\n\
";

