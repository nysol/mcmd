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
/// kgavgHelp.h : kgavg help
// =============================================================================
_titleL="項目値の平均";
_docL="\
\n\
MAVG 項目値の平均\n\
\n\
f=パラメータで指定した項目の平均値を計算する。\n\
(注)k=とf=パラメータで指定した項目以外については、どの行が出力されるか>は不定であることに注意してください。\n\
\n\
書式\n\
\n\
mavg f= [k=] [-n] [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定した項目(複数項目指定可)の値が集計される。\n\
       :(コロン）で新項目名を指定可能。例）f=数量:数量平均\n\
  k=   集計の単位となる項目(複数項目指定可)名リストを指定する。\n\
  -n   NULL値が1つでも含まれていると結果もNULL値とする。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目の平均値を計算し、「数量平均」と「金額平均」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,5\n\
    A,2,20\n\
    B,1,15\n\
    B,,10\n\
    B,5,20\n\
    $ mavg k=顧客 f=数量:数量平均,金額:金額平均 i=dat1.csv o=rsl1.csv\n\
    #END# kgavg f=数量:数量平均,金額:金額平均 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,数量平均,金額平均\n\
    A,1.5,12.5\n\
    B,3,15\n\
\n\
例2: NULL値がある場合の出力\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目の平均値を計算し、「数量平均」と「金額平均」という項目名で出力する。\n\
-nオプションを指定することで、NULL値が含まれている場合は、結果もNULL値として出力する。\n\
\n\
    $ mavg k=顧客 f=数量:数量平均,金額:金額平均 -n i=dat1.csv o=rsl2.csv\n\
    #END# kgavg -n f=数量:数量平均,金額:金額平均 i=dat1.csv k=顧客 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客%0,数量平均,金額平均\n\
    A,1.5,12.5\n\
    B,,15\n\
\n\
例3: 顧客項目を単位としない例\n\
\n\
「数量」と「金額」項目の平均値を計算し、「数量平均」と「金額平均」という項目名で出力する。\n\
\n\
    $ mavg f=数量:数量平均,金額:金額平均 i=dat1.csv o=rsl3.csv\n\
    #END# kgavg f=数量:数量平均,金額:金額平均 i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客,数量平均,金額平均\n\
    B,2.25,14\n\
";

