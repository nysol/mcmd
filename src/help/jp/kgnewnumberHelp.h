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
/// kgnewnumberHelp.h : kgnewnumber help
// =============================================================================
_titleL="連番データの新規生成";
_docL="\
\n\
MNEWNUMBER 連番データの新規生成\n\
\n\
S=パラメータで指定した開始数値もしくはアルファベットにより、\n\
I=パラメータで指定した間隔で連番もしくはアルファベット連番を新規作成し、a=パラメータで指定した項目名で出力する。\n\
アルファベット連番とは、AからZの26文字を用いた26進数のこと(A,B,…,Z,AA,AB,…,AZ,BA,BB,…,ZZ,AAA,AAB,…)。\n\
\n\
書式\n\
\n\
mnewnumber a= [I=] [S=] [l=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=   新規に作成する連番行の項目名を指定する。\n\
       -nfn,-nfnoオプション指定時は指定の必要はない。\n\
  I=   連番をふる間隔を指定する。【デフォルト値:1】\n\
  S=   開始数値/アルファベット(大文字)【デフォルト値:1】\n\
       連番の開始数値もしくはアルファベットを指定する。\n\
       数値を指定した場合は数値の連番がふられる。\n\
       アルファベットを指定した場合はアルファベット連番がふられる。(小文字は指定できない)\n\
  l=   作成するデータ行数を指定する。【デフォルト値:10】\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
1から始まる間隔が1の連番をふり、No.という項目名で新規に5行のデータを作成する。\n\
\n\
    $ mnewnumber a=No. I=1 S=1 l=5 o=rsl1.csv\n\
    #END# kgNewnumber I=1 S=1 a=No. l=5 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    No.\n\
    1\n\
    2\n\
    3\n\
    4\n\
    5\n\
\n\
例2: 開始番号と間隔の変更\n\
\n\
10から始まる間隔が5の連番をふり、No.という項目名で新規に5行のデータを作成する。\n\
\n\
    $ mnewnumber a=No. I=5 S=10 l=5 o=rsl2.csv\n\
    #END# kgNewnumber I=5 S=10 a=No. l=5 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    No.\n\
    10\n\
    15\n\
    20\n\
    25\n\
    30\n\
\n\
例3: アルファベット連番\n\
\n\
Aから始まる間隔が1のアルファベット連番をふり、No.という項目名で新規に5行のデータを作成する。\n\
\n\
    $ mnewnumber a=No. I=1 S=A l=5 o=rsl3.csv\n\
    #END# kgNewnumber I=1 S=A a=No. l=5 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    No.\n\
    A\n\
    B\n\
    C\n\
    D\n\
    E\n\
\n\
例4: ヘッダ行なしで新規作成\n\
\n\
Bから始まる間隔が3のアルファベット連番をふり、ヘッダなしで新規に11行のデータを作成する。\n\
\n\
    $ mnewnumber  -nfn  I=3 l=11 S=B o=rsl4.csv\n\
    #END# kgNewnumber -nfn I=3 S=B l=11 o=rsl4.csv\n\
    $ more rsl4.csv\n\
    B\n\
    E\n\
    H\n\
    K\n\
    N\n\
    Q\n\
    T\n\
    W\n\
    Z\n\
    AC\n\
    AF\n\
";

