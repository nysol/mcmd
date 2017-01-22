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
/// kgsimHelp.h : kgsim help
// =============================================================================
_titleL="二変数間の類似度の計算";
_docL="\
\n\
MSIM 二変数間の類似度の計算\n\
\n\
f=パラメータで指定した項目の二変数間の類似度(距離)を\n\
c=パラメータで指定した類似度(距離)関数で計算し類似度行列として出力する。\n\
\n\
書式\n\
\n\
msim c= f= [a=] [k=] [n=] [-d] [i=] [o=] [bufcount=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   ここで指定された項目(複数項目指定可)を単位として求める。\n\
  f=   ここで指定された項目全ての二項目間の類似度を求める。\n\
  c=   類似度(距離)名リスト(複数項目指定可)\n\
       次項に示した類似度(距離)名を指定する。\n\
       項目名は以下のように，(:)コロンに続けて指定して変更可能。\n\
       コロンに続く名称を省略した場合は類似度(距離)関数名がそのまま項目名として利用される。\n\
       例) msim f=x,y,z c=pearson:ピアソン積率相関係数,euclid:ユークリッド距離,cosine:コサイン\n\
       類似度=covar|ucovar|pearson|spearman|kendall|euclid|cosine|\n\
         cityblock|hamming|chi|phi|jaccard|supportr|lift|confMax|\n\
         confMin|yuleQ|yuleY|kappa|oddsRatio|convMax|convMin\n\
  a=   2変数の名称を示す項目名を指定する。カンマで区切って2つ指定する。\n\
       省略するとfld1,fld2が使われる。\n\
  -d   対角行列、上三角行列を出力する。\n\
       -dオプションが指定されないと類似度行列の下三角行列のみ出力されるが、\n\
       -dオプションを指定することにより対角行列及び上三角行列も出力される。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
x、y、z項目の2項目間の組み合わせについて\n\
ピアソンの積率相関係数とコサインを計算する。\n\
\n\
    $ more dat1.csv\n\
    x,y,z\n\
    14,0.17,-14\n\
    11,0.2,-1\n\
    32,0.15,-2\n\
    13,0.33,-2\n\
    $ msim c=pearson,cosine f=x,y,z i=dat1.csv o=rsl1.csv\n\
    #END# kgsim c=pearson,cosine f=x,y,z i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    fld1,fld2,pearson,cosine\n\
    x,y,-0.5088704666,0.7860308044\n\
    x,z,0.1963041929,-0.5338153343\n\
    y,z,0.3311001423,-0.5524409416\n\
\n\
例2: 対角行列、上三角行列を出力\n\
\n\
x、y、z項目の2項目間の組み合わせについて\n\
ピアソンの積率相関係数とコサインを計算する。(dオプションあり)\n\
\n\
    $ msim c=pearson,cosine f=x,y,z -d i=dat1.csv o=rsl2.csv\n\
    #END# kgsim -d c=pearson,cosine f=x,y,z i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    fld1,fld2,pearson,cosine\n\
    x,x,1,1\n\
    x,y,-0.5088704666,0.7860308044\n\
    x,z,0.1963041929,-0.5338153343\n\
    y,x,-0.5088704666,0.7860308044\n\
    y,y,1,1\n\
    y,z,0.3311001423,-0.5524409416\n\
    z,x,0.1963041929,-0.5338153343\n\
    z,y,0.3311001423,-0.5524409416\n\
    z,z,1,1\n\
\n\
例3: キー単位での計算\n\
\n\
key項目を単位にして計算する。\n\
\n\
    $ more dat2.csv\n\
    key,x,y,z\n\
    A,14,0.17,-14\n\
    A,11,0.2,-1\n\
    A,32,0.15,-2\n\
    B,13,0.33,-2\n\
    B,10,0.8,-5\n\
    B,15,0.45,-9\n\
    $ msim k=key c=pearson,cosine f=x,y,z i=dat2.csv o=rsl3.csv\n\
    #END# kgsim c=pearson,cosine f=x,y,z i=dat2.csv k=key o=rsl3.csv\n\
    $ more rsl3.csv\n\
    key%0,fld1,fld2,pearson,cosine\n\
    A,x,y,-0.8746392857,0.8472573627\n\
    A,x,z,0.3164384831,-0.521983618\n\
    A,y,z,0.1830936883,-0.6719258683\n\
    B,x,y,-0.7919009884,0.8782575583\n\
    B,x,z,-0.471446429,-0.9051543403\n\
    B,y,z,-0.1651896746,-0.8514129252\n\
\n\
例4: 類似度名の指定\n\
\n\
01値のデータに付いての計算。ハミング距離とphi係数を計算する。\n\
\n\
    $ more dat3.csv\n\
    x,y,z\n\
    1,1,0\n\
    1,0,1\n\
    1,0,1\n\
    0,1,1\n\
    $ msim c=hamming,phi f=x,y,z i=dat3.csv o=rsl4.csv\n\
    #END# kgsim c=hamming,phi f=x,y,z i=dat3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    fld1,fld2,hamming,phi\n\
    x,y,0.75,-0.5773502692\n\
    x,z,0.5,-0.3333333333\n\
    y,z,0.75,-0.5773502692\n\
\n\
例5: 類似度名の変更\n\
\n\
01値のデータに付いての計算。ハミング距離とphi係数を計算し、\n\
出力項目名を変更する。\n\
\n\
    $ msim c=hamming:ハミング距離,phi:ファイ係数 a=変数1,変数2 f=x,y,z i=dat3.csv o=rsl5.csv\n\
    #END# kgsim a=変数1,変数2 c=hamming:ハミング距離,phi:ファイ係数 f=x,y,z i=dat3.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    変数1,変数2,ハミング距離,ファイ係数\n\
    x,y,0.75,-0.5773502692\n\
    x,z,0.5,-0.3333333333\n\
    y,z,0.75,-0.5773502692\n\
";

