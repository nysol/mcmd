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
/// kgvsortHelp.h : kgvsort help
// =============================================================================
_titleL="ベクトル要素のソート";
_docL="\
\n\
MVSORT ベクトル要素のソート\n\
\n\
ベクトル型の項目をソートする。\n\
ベクトル型の項目とは、表のitems項目のように、\n\
スペースで区切られた複数の文字列を値として持つ項目である。\n\
\n\
書式\n\
\n\
mvsort vf= [-A] [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  vf=   ソーティングするベクトル項目名を指定する。複数項目指定可能。\n\
        %に続けてnを指定すれば数値ソートに、\n\
        %に続けてrを指定すれば逆順ソートに、\n\
        また、nとrの両方を指定すれば数値逆順ソートとなる。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
\n\
利用例\n\
\n\
例1: 複数項目を並べる例\n\
\n\
item1項目を文字列降順に並べ、item2項目を数値昇順に並べる。\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,10 2\n\
    c c,2 5 3\n\
    e a a,1\n\
    $ mvsort vf=items1%r,items2%n i=dat1.csv o=rsl1.csv\n\
    #END# kgvsort i=dat1.csv o=rsl1.csv vf=items1%r,items2%n\n\
    $ more rsl1.csv\n\
    items1,items2\n\
    c b a,2 10\n\
    c c,2 3 5\n\
    e a a,1\n\
";

