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
/// kgvdelnullHelp.h : kgvdelnull help
// =============================================================================
_titleL="ベクトルのNULL要素の削除";
_docL="\
\n\
MVDELNULL ベクトルのNULL要素の削除\n\
\n\
ベクトル要素でNULLの要素を全て削除する。\n\
ベクトル要素がNULLであれば、要素の区切り文字が連続する。\n\
以下に示したベクトルは全てNULLを含む。\n\
ただし、わかりやすさのためにベクトルの末尾に`\\n'を記している。\n\
上から順番に、3番目、1番目、4番目の要素がNULLである。\n\
\n\
    a b  c\\n\n\
     a b\\n\n\
    a b c \\n\n\
\n\
書式\n\
\n\
mvdelnull vf= [-A]  i= [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  vf=   NULL要素を削除する対象となる項目名(i=ファイル上)を指定する。\n\
        複数項目指定可能。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
\n\
利用例\n\
\n\
例1: nullを削除する基本例\n\
\n\
    $ more dat1.csv\n\
    items\n\
    b a  c\n\
     c c\n\
    e a   b \n\
    $ mvdelnull vf=items i=dat1.csv o=rsl1.csv\n\
    #END# kgvdelnull i=dat1.csv o=rsl1.csv vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    b a c\n\
    c c\n\
    e a b\n\
\n\
例2: 分かりやすく区切り文字を.(ドット)にした例\n\
\n\
    $ more dat2.csv\n\
    items\n\
    b.a..c\n\
    .c.c\n\
    e.a...b.\n\
    $ mvdelnull vf=items delim=. i=dat2.csv o=rsl2.csv\n\
    #END# kgvdelnull delim=. i=dat2.csv o=rsl2.csv vf=items\n\
    $ more rsl2.csv\n\
    items\n\
    b.a.c\n\
    c.c\n\
    e.a.b\n\
\n\
例3: 項目名を変更して出力\n\
\n\
    $ mvdelnull vf=items:new i=dat1.csv o=rsl3.csv\n\
    #END# kgvdelnull i=dat1.csv o=rsl3.csv vf=items:new\n\
    $ more rsl3.csv\n\
    new\n\
    b a c\n\
    c c\n\
    e a b\n\
\n\
例4: -Aを指定することで追加項目として出力\n\
\n\
    $ mvdelnull vf=items:new -A i=dat1.csv o=rsl4.csv\n\
    #END# kgvdelnull -A i=dat1.csv o=rsl4.csv vf=items:new\n\
    $ more rsl4.csv\n\
    items,new\n\
    b a  c,b a c\n\
     c c,c c\n\
    e a   b ,e a b\n\
";

