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
/// kgshuffleHelp.h : kgshuffle help
// =============================================================================
_titleL="レコード分割";
_docL="\
\n\
MSHUFFLE レコード分割\n\
\n\
ファイルを指定した数のファイルに分割する。f=を指定した場合にはその項目値が等しいものは同一ファイルに含まれる。\n\
\n\
書式\n\
\n\
mshuffle n=|v= d= [f=] [i=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  d=   出力するファイル名の接頭辞を指定する\n\
       ここで指定した値＋連番が実際に出力されるファイル名になる\n\
  f=   分割単位となるキーを指定する\n\
       ここで指定した項目値が等しいものは同じファイルに出力される\n\
  n=   分割するファイル数を指定する\n\
  v=   分割するファイルごとにデータ量の重みを指定する\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
2つのファイルに分割する\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,20,5200 \n\
    B,18,4000   \n\
    C,15,3500 \n\
    D,10,2000 \n\
    E,3,800 \n\
    $ mshuffle d=./dat/d n=2 i=dat1.csv\n\
    #END# kgshuffle d=./dat/d i=dat1.csv n=2\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,数量,金額\n\
    B,18,4000   \n\
    D,10,2000 \n\
    $ more ./dat/d_1\n\
    顧客,数量,金額\n\
    A,20,5200 \n\
    C,15,3500 \n\
    E,3,800 \n\
\n\
例2: f=の指定\n\
\n\
指定した項目の値が同じファイルに出力にされるように2つのファイルに分割する\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ mshuffle f=顧客 d=./dat/d n=2 i=dat2.csv\n\
    #END# kgshuffle d=./dat/d f=顧客 i=dat2.csv n=2\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,日付,金額\n\
    B,20081002,40\n\
    B,20081209,50\n\
    $ more ./dat/d_1\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    C,20081003,60\n\
    C,20081219,20\n\
\n\
例3: v=の指定\n\
\n\
重みで2つのファイルのデータ量を指定して分割する\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,20,5200 \n\
    B,18,4000   \n\
    C,15,3500 \n\
    D,10,2000 \n\
    E,3,800 \n\
    $ mshuffle d=./dat/d v=2,1 i=dat1.csv\n\
    #END# kgshuffle d=./dat/d i=dat1.csv v=2,1\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,数量,金額\n\
    A,20,5200 \n\
    C,15,3500 \n\
    D,10,2000 \n\
    $ more ./dat/d_1\n\
    顧客,数量,金額\n\
    B,18,4000   \n\
    E,3,800 \n\
\n\
例4: v=,f=の指定\n\
\n\
重みで2つのファイルのデータ量を指定して分割する\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ mshuffle f=顧客 d=./dat/d v=2,1 i=dat2.csv\n\
    #END# kgshuffle d=./dat/d f=顧客 i=dat2.csv v=2,1\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,日付,金額\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ more ./dat/d_1\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
";

