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
/// kgshareHelp.h : kgshare help
// =============================================================================
_titleL="構成比の計算";
_docL="\
\n\
MSHARE 構成比の計算\n\
\n\
f=パラメータで指定した項目の構成比を計算し、新しい項目として追加する。\n\
\n\
書式\n\
\n\
mshare f= [k=]  [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定された項目（複数項目指定可）の値のシェアが計算される。\n\
       :(コロン）で新項目名を指定する必要がある。例）f=数量:数量シェア\n\
  k=   シェア計算の単位となる項目名リスト（複数項目指定可）を指定する。\n\
       省略すると全行同じキーの値として処理される。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目のシェアを計算し、\n\
「数量シェア」と「金額シェア」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mshare k=顧客 f=数量:数量シェア,金額:金額シェア i=dat1.csv o=rsl1.csv\n\
    #END# kgshare f=数量:数量シェア,金額:金額シェア i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,数量,金額,数量シェア,金額シェア\n\
    A,1,10,0.3333333333,0.3333333333\n\
    A,2,20,0.6666666667,0.6666666667\n\
    B,1,15,0.2,0.3333333333\n\
    B,3,10,0.6,0.2222222222\n\
    B,1,20,0.2,0.4444444444\n\
";

