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
/// kgvjoinHelp.h : kgvjoin help
// =============================================================================
_titleL="ベクトル要素の参照結合";
_docL="\
\n\
MVJOIN ベクトル要素の参照結合\n\
\n\
ベクトル要素をキーにして参照ファイル上のベクトル型データを結合する。\n\
ベクトル型の項目とは、表のitems項目のように、\n\
スペースで区切られた複数の文字列を値として持つ項目である。\n\
\n\
書式\n\
\n\
mvjoin vf= [-A] K= f= [n=] m=| i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  vf=   結合キーとなるベクトルの項目名(i=ファイル上)を指定する。\n\
        複数項目指定可能。ベクトル要素はソーティングされている必要はない。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
  m=    参照ファイルを指定する。\n\
  K=    参照ファイル(m=)上の結合キーとなるベクトル要素の項目名を指定する。\n\
        並べ変わっている必要はないが、ベクトル要素は単一化されていなければならない。\n\
        単一化されていない時の動作は不定である。\n\
  f=    結合するベクトル(要素)項目名を指定する。\n\
  n=    vf=とK=のベクトル要素がマッチしなかった場合に結合する文字列を指定する。\n\
        省略した場合、対象のベクトル(要素)の結合は行われない。\n\
\n\
利用例\n\
\n\
例1: ベクトルを結合する例\n\
\n\
    $ more dat1.csv\n\
    items\n\
    b a c\n\
    c c\n\
    e a a\n\
    $ more ref1.csv\n\
    item,taxo\n\
    a,X Y\n\
    b,X\n\
    c,Z Z\n\
    $ mvjoin vf=items K=item m=ref1.csv f=taxo i=dat1.csv o=rsl1.csv\n\
    #END# kgVjoin K=item f=taxo i=dat1.csv m=ref1.csv o=rsl1.csv vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    b a c X X Y Z Z\n\
    c c Z Z Z Z\n\
    e a a X Y X Y\n\
\n\
例2: 複数項目に対して適用する例\n\
\n\
    $ more dat2.csv\n\
    items1,items2\n\
    b a c,b b\n\
    c c,a d\n\
    e a a,a a\n\
    $ more ref2.csv\n\
    item,taxo\n\
    a,X\n\
    b,X\n\
    c,Y\n\
    d,Y\n\
    $ mvjoin vf=items1,items2 K=item m=ref2.csv f=taxo i=dat2.csv o=rsl2.csv\n\
    #END# kgVjoin K=item f=taxo i=dat2.csv m=ref2.csv o=rsl2.csv vf=items1,items2\n\
    $ more rsl2.csv\n\
    items1,items2\n\
    b a c X X Y,b b X X\n\
    c c Y Y,a d X Y\n\
    e a a X X,a a X X\n\
";

