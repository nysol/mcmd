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
/// kgstatsHelp.h : kgstats help
// =============================================================================
_titleL="一変数の統計量算出";
_docL="\
\n\
MSTATS 一変数の統計量算出\n\
\n\
f=パラメータで指定した数値項目について\n\
c=パラメータで指定した統計量の計算をする。\n\
k=を指定することで、キー単位で集計することができる。\n\
f=で指定した項目のNULL値は無視される。\n\
ただし、全行がNULL値であればNULL値が出力される。\n\
(注)k=とf=パラメータで指定した項目以外については、どの行が出力されるか>は不定であることに注意してください。\n\
\n\
書式\n\
\n\
mstats c= f= [k=] [-n]  [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   ここで指定された項目(複数項目指定可)を単位として集計する。\n\
  f=   ここで指定された項目(複数項目指定可)の値が集計される。\n\
  c=   統計量(以下のリストから一つだけ指定可)\n\
       sum|mean|count|ucount|devsq|var|uvar|sd|usd|USD|cv|min|qtile1|\n\
       median|qtile3|max|range|qrange|mode|skew|uskew|kurt|ukurt\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目の 各統計量合計値を計算する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    B,5,20\n\
    B,2,10\n\
    C,1,15\n\
    C,3,10\n\
    C,1,21\n\
    $ mstats k=顧客 f=数量,金額 c=sum i=dat1.csv o=rsl1.csv\n\
    #END# kgstats c=sum f=数量,金額 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,数量,金額\n\
    A,1,10\n\
    B,7,30\n\
    C,5,46\n\
\n\
例2: 基本例2\n\
\n\
各統計量最大値を計算する。\n\
\n\
    $ mstats k=顧客 f=数量,金額 c=max i=dat1.csv o=rsl2.csv\n\
    #END# kgstats c=max f=数量,金額 i=dat1.csv k=顧客 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客%0,数量,金額\n\
    A,1,10\n\
    B,5,20\n\
    C,3,21\n\
";

