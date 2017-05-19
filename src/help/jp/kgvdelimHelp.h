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
/// kgvdelimHelp.h : kgvdelim help
// =============================================================================
_titleL="ベクトル要素の区切り文字変更";
_docL="\
\n\
MVDELIM ベクトル要素の区切り文字変更\n\
\n\
ベクトル型の要素を区切る文字列を変更する。\n\
ただし、区切り文字に空文字を指定すれば区切り文字を削除することになる。\n\
\n\
書式\n\
\n\
mvdelim vf= v= [-A]  [i=] [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  vf=   区切り文字を変更するベクトル項目名を指定する。複数項目指定可能。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
  v=    新しい区切り文字を指定する。何も指定しなければ空文字として扱われる。\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
ベクトル型要素のデフォルトの区切り文字である半角スペースを_(アンダーバー)に置換する。\n\
\n\
    $ more dat1.csv\n\
    item1\n\
    b a c\n\
    c c\n\
    e a a\n\
    $ mvdelim vf=item1 v=_ i=dat1.csv o=rsl1.csv\n\
    #END# kgvdelim i=dat1.csv o=rsl1.csv v=_ vf=item1\n\
    $ more rsl1.csv\n\
    item1\n\
    b_a_c\n\
    c_c\n\
    e_a_a\n\
\n\
例2: カンマ\n\
\n\
CSVの区切り文字であるカンマに置換すると、CSVの区切り文字との区別を付けるために、\n\
ベクトル全体がダブルクオーツで囲われる。\n\
\n\
    $ mvdelim vf=item1 v=, i=dat1.csv o=rsl2.csv\n\
    #END# kgvdelim i=dat1.csv o=rsl2.csv v=, vf=item1\n\
    $ more rsl2.csv\n\
    item1\n\
    \"b,a,c\"\n\
    \"c,c\"\n\
    \"e,a,a\"\n\
";

