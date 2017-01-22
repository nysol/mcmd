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
/// kgnewrandHelp.h : kgnewrand help
// =============================================================================
_titleL="乱数データの新規生成";
_docL="\
\n\
MNEWRAND 乱数データの新規生成\n\
\n\
0.0から1.0の範囲の実数乱数を生成する。\n\
-intを指定することで、整数乱数を生成することもできる。\n\
\n\
乱数の生成にはメルセンヌ・ツイスター法を利用している\n\
(http://www.math.sci.hiroshima-u.ac.jp/ m-mat/MT/emt.html ,\n\
http://www.boost.org/doc/libs/1_54_0/doc/html/boost_random.html)。\n\
\n\
書式\n\
\n\
mnewrand a= [max=] [min=] [S=] [l=] [-int] [o=] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=     新規に作成するデータの項目名を指定する。\n\
         -nfn,-nfnoオプション指定時は指定の必要はない。\n\
  max=   乱数の最大値を指定する。【デフォルト値:INT_MAX】\n\
         このパラメータを指定するときは-intも指定しなければならない。\n\
  min=   乱数の最小値を指定する。【デフォルト値:0】\n\
         このパラメータを指定するときは-intも指定しなければならない。\n\
  S=     乱数の種を指定する。【デフォルト値:現在時刻】\n\
  l=     行数【デフォルト値:10】\n\
         新規作成する乱数データの行数を指定する。\n\
  -int   整数乱数を生成する\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
実数乱数を10行生成する。乱数の種は1に固定しているので、いつ実行しても乱数系列は同じになる。\n\
\n\
    $ mnewrand a=rand S=1 o=rsl1.csv\n\
    #END# kgnewrand S=1 a=rand o=rsl1.csv\n\
    $ more rsl1.csv\n\
    rand\n\
    0.4170219984\n\
    0.9971848081\n\
    0.7203244893\n\
    0.9325573612\n\
    0.0001143810805\n\
    0.1281244478\n\
    0.3023325677\n\
    0.9990405154\n\
    0.1467558926\n\
    0.2360889763\n\
\n\
例2: 整数乱数\n\
\n\
最小値が0、最大値が1000、乱数の種が1の整数乱数を5行作成する。\n\
\n\
    $ mnewrand a=rand -int max=1000 min=0 l=5 S=1 o=rsl2.csv\n\
    #END# kgnewrand -int S=1 a=rand l=5 max=1000 min=0 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    rand\n\
    417\n\
    998\n\
    721\n\
    933\n\
    0\n\
\n\
例3: ヘッダ行なしで出力\n\
\n\
-nfnでヘッダーなしのデータが生成される。\n\
\n\
    $ mnewrand -nfn l=5 S=1 o=rsl3.csv\n\
    #END# kgnewrand -nfn S=1 l=5 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    0.4170219984\n\
    0.9971848081\n\
    0.7203244893\n\
    0.9325573612\n\
    0.0001143810805\n\
";

