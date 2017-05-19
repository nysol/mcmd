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
/// kgrandHelp.h : kgrand help
// =============================================================================
_titleL="擬似乱数";
_docL="\
\n\
MRAND 擬似乱数\n\
\n\
0.0から1.0の範囲の実数の擬似乱数、もしくは範囲指定による整数の擬似乱数を生成し、a=パラメータで指定した項目名で出力する。\n\
\n\
乱数の生成にはメルセンヌ・ツイスター法を利用している\n\
(http://www.math.sci.hiroshima-u.ac.jp/ m-mat/MT/emt.html ,\n\
http://www.boost.org/doc/libs/1_54_0/doc/html/boost_random.html)。\n\
\n\
書式\n\
\n\
mrand [k=] a= [max=] [min=] [S=] [-int] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  k=     指定したキー項目について、同じキー値には同じ乱数値が振られる。\n\
  a=     新たに追加される項目の名前を指定する。【但し、-nfn,-nfnoオプション指定時は必要なし】\n\
  max=   乱数の最大値【デフォルト値:INT_MAX】\n\
         0〜2³²(約21億)の範囲の整数が指定可能\n\
         このパラメータを指定するときは-intも指定しなければならない。\n\
  min=   整数乱数の最小値【デフォルト値:0】\n\
         0〜2³²(約21億)の範囲の整数が指定可能\n\
         このパラメータを指定するときは-intも指定しなければならない。\n\
  S=     乱数の種【デフォルト値:現在時刻】\n\
         同じ乱数の種を指定すれば、同じ乱数系列となる。\n\
         S=を指定しなければ、時刻(ミリ(1/1000秒単位)に応じた異なる乱数の種が利用される。\n\
         指定可能な乱数の種(-2147483648〜2147483647)\n\
  -int   整数乱数を生成\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
0.0から1.0の範囲の実数乱数を生成する。\n\
\n\
    $ more dat1.csv\n\
    顧客\n\
    A\n\
    B\n\
    C\n\
    D\n\
    E\n\
    $ mrand a=rand i=dat1.csv o=rsl1.csv\n\
    #END# kgrand a=rand i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客,rand\n\
    A,0.05056004506\n\
    B,0.5912564802\n\
    C,0.8582792655\n\
    D,0.9130602113\n\
    E,0.1935953016\n\
\n\
例2: 基本例2\n\
\n\
-intで整数乱数\n\
\n\
    $ mrand a=rand -int i=dat1.csv o=rsl2.csv\n\
    #END# kgrand -int a=rand i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客,rand\n\
    A,1914956170\n\
    B,127938271\n\
    C,1793744235\n\
    D,334816752\n\
    E,1197767906\n\
\n\
例3: 最小値、最大値を決めた乱数の生成\n\
\n\
最小値が10、最大値が100の整数の乱数を生成し、randという項目名で出力する。\n\
\n\
    $ mrand a=rand -int min=10 max=100 S=1 i=dat1.csv o=rsl3.csv\n\
    #END# kgrand -int S=1 a=rand i=dat1.csv max=100 min=10 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客,rand\n\
    A,47\n\
    B,100\n\
    C,75\n\
    D,94\n\
    E,10\n\
\n\
例4: キー単位の乱数生成\n\
\n\
以下の例は、顧客A,B,C,Dの4人について同じ顧客には同じ乱数値を振る。\n\
\n\
    $ more dat2.csv\n\
    顧客\n\
    A\n\
    A\n\
    A\n\
    B\n\
    B\n\
    C\n\
    D\n\
    D\n\
    D\n\
    $ mrand k=顧客 -int min=0 max=1 a=rand i=dat2.csv o=rsl4.csv\n\
    #END# kgrand -int a=rand i=dat2.csv k=顧客 max=1 min=0 o=rsl4.csv\n\
    $ more rsl4.csv\n\
    顧客%0,rand\n\
    A,1\n\
    A,1\n\
    A,1\n\
    B,0\n\
    B,0\n\
    C,0\n\
    D,0\n\
    D,0\n\
    D,0\n\
";

