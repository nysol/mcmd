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
/// kgvuniqHelp.h : kgvuniq help
// =============================================================================
_titleL="ベクトル要素の単一化";
_docL="\
\n\
MVUNIQ ベクトル要素の単一化\n\
\n\
ベクトル型の項目の要素を単一化する。\n\
内部的にはtree構造を利用して単一化をしているので、\n\
出力される要素の順序は文字列昇順に並び変わる。\n\
\n\
一方で、-nオプションを指定すると、 ベクトルを系列として考え、\n\
要素を先頭から順番に走査し、互いに隣接した要素のみを単一化し出力する。\n\
\n\
書式\n\
\n\
mvuniq vf= [-A] [-n] [i=] [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
  vf=   単一化する対象項目名を指定する。複数項目指定可能。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
  -n    ベクトルを系列と考え隣接する同一要素のみ単一化する\n\
\n\
利用例\n\
\n\
例1: 複数項目を単一化する例\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,1 1\n\
    c c,2 2 3\n\
    e a a,3 1\n\
    $ mvuniq vf=items1,items2 i=dat1.csv o=rsl1.csv\n\
    #END# kgvuniq i=dat1.csv o=rsl1.csv vf=items1,items2\n\
    $ more rsl1.csv\n\
    items1,items2\n\
    a b c,1\n\
    c,2 3\n\
    a e,1 3\n\
";

