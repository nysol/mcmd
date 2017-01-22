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
/// kgaccumHelp.h : kgaccum help
// =============================================================================
_titleL="累積計算";
_docL="\
\n\
MACCUM 累積計算\n\
\n\
f=パラメータで指定した項目の累積を計算し、新しい項目として追加する。\n\
k=を指定することで、キー単位毎に累積計算が可能となる。\n\
\n\
書式\n\
\n\
maccum f= s= [k=]  [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定した項目(複数項目指定可)の値が累積される。\n\
       項目の値がNULL値である場合は無視される。\n\
       :(コロン）で新項目名を指定する必要がある。例）f=数量:数量累計\n\
  s=   ここで指定した項目(複数項目指定可)で並べ替えられた後、累積が計算される。\n\
       -qオプションを指定しないとき、s=パラメータは必須。\n\
  k=   累積の単位となる項目名リスト(複数項目指定可)を指定する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「数量」と「金額」項目の累積値を計算し、「数量累計」と「金額累計」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ maccum s=顧客 f=数量:数量累計,金額:金額累計 i=dat1.csv o=rsl1.csv\n\
    #END# kgaccum f=数量:数量累計,金額:金額累計 i=dat1.csv o=rsl1.csv s=顧客\n\
    $ more rsl1.csv\n\
    顧客%0,数量,金額,数量累計,金額累計\n\
    A,1,10,1,10\n\
    A,2,20,3,30\n\
    B,1,15,4,45\n\
    B,3,10,7,55\n\
    B,1,20,8,75\n\
\n\
例2: キー項目を指定する例\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目の累積値を計算し、「数量累計」と「金額累計」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ maccum k=顧客 s=顧客 f=数量:数量累計,金額:金額累計 i=dat1.csv o=rsl2.csv\n\
    #END# kgaccum f=数量:数量累計,金額:金額累計 i=dat1.csv k=顧客 o=rsl2.csv s=顧客\n\
    $ more rsl2.csv\n\
    顧客,数量,金額,数量累計,金額累計\n\
    A,1,10,1,10\n\
    A,2,20,3,30\n\
    B,1,15,1,15\n\
    B,3,10,4,25\n\
    B,1,20,5,45\n\
\n\
例3: NULL値を含む累計\n\
\n\
「数量」と「金額」項目の累積値を計算し、「数量累計」と「金額累計」という項目名で出力する。\n\
NULLは無視される。結果もNULLが出力される。\n\
\n\
    $ more dat2.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,,20\n\
    B,1,15\n\
    B,3,\n\
    B,1,20\n\
    $ maccum s=顧客 f=数量:数量累計,金額:金額累計 i=dat2.csv o=rsl3.csv\n\
    #END# kgaccum f=数量:数量累計,金額:金額累計 i=dat2.csv o=rsl3.csv s=顧客\n\
    $ more rsl3.csv\n\
    顧客%0,数量,金額,数量累計,金額累計\n\
    A,1,10,1,10\n\
    A,,20,,30\n\
    B,1,15,2,45\n\
    B,3,,5,\n\
    B,1,20,6,65\n\
";

