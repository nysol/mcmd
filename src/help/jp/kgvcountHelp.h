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
/// kgvcountHelp.h : kgvcount help
// =============================================================================
_titleL="ベクトルサイズの計算";
_docL="\
\n\
MVCOUNT ベクトルサイズの計算\n\
\n\
ベクトルのサイズ(ベクトルの要素数)を計算する。\n\
\n\
書式\n\
\n\
mvcount vf= [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  vf=   要素数をカウントするベクトルの項目名(i=ファイル上)を指定する。\n\
        結果項目を:に続けて複数項目指定可能。\n\
        複数項目指定可能。\n\
\n\
利用例\n\
\n\
例1: 複数項目に対して適用する例\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,b\n\
    c c,\n\
    e a a,a a a\n\
    $ mvcount vf=items1:size1,items2:size2 i=dat1.csv o=rsl1.csv\n\
    #END# kgvcount i=dat1.csv o=rsl1.csv vf=items1:size1,items2:size2\n\
    $ more rsl1.csv\n\
    items1,items2,size1,size2\n\
    b a c,b,3,1\n\
    c c,,2,0\n\
    e a a,a a a,3,3\n\
";

