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
/// kgvnulltoHelp.h : kgvnullto help
// =============================================================================
_titleL="ベクトル要素のNULL置換";
_docL="\
\n\
MVNULLTO ベクトル要素のNULL置換\n\
\n\
ベクトル要素でNULLの要素を任意の値に置換する。\n\
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
mvnullto vf= [v=|-p] [O=] [-A]  i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  vf=   NULL置換の対象となる項目名(i=ファイル上)を指定する。\n\
        複数項目指定可能。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
  v=    置換文字列を指定する。\n\
  -p    直前の要素で置換する。v=と同時に指定はできない。\n\
  O=    NULL値以外の要素を全て、ここで指定した文字列に置換する。\n\
        指定しなければNULL値以外は置換しない。\n\
\n\
利用例\n\
\n\
例1: nullを文字列‘null’に置換する例\n\
\n\
    $ more dat1.csv\n\
    items\n\
    b a  c\n\
     c c\n\
    e a   b \n\
    $ mvnullto vf=items v=null i=dat1.csv o=rsl1.csv\n\
    #END# kgvnullto i=dat1.csv o=rsl1.csv v=null vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    b a null c\n\
    null c c\n\
    e a null null b null\n\
\n\
例2: 分かりやすく区切り文字を.(ドット)にした例\n\
\n\
    $ more dat2.csv\n\
    items\n\
    b.a..c\n\
    .c.c\n\
    e.a...b.\n\
    $ mvnullto vf=items v=null delim=. i=dat2.csv o=rsl2.csv\n\
    #END# kgvnullto delim=. i=dat2.csv o=rsl2.csv v=null vf=items\n\
    $ more rsl2.csv\n\
    items\n\
    b.a.null.c\n\
    null.c.c\n\
    e.a.null.null.b.null\n\
\n\
例3: nullを直前の値に置換する例\n\
\n\
    $ mvnullto vf=items -p i=dat1.csv o=rsl3.csv\n\
    #END# kgvnullto -p i=dat1.csv o=rsl3.csv vf=items\n\
    $ more rsl3.csv\n\
    items\n\
    b a a c\n\
     c c\n\
    e a a a b b\n\
\n\
例4: O=を指定することで、null以外は全て指定の値に置換される\n\
\n\
    $ mvnullto vf=items v=null O=X i=dat1.csv o=rsl4.csv\n\
    #END# kgvnullto O=X i=dat1.csv o=rsl4.csv v=null vf=items\n\
    $ more rsl4.csv\n\
    items\n\
    X X null X\n\
    null X X\n\
    X X null null X null\n\
";

