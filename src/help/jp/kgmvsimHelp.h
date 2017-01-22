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
/// kgmvsimHelp.h : kgmvsim help
// =============================================================================
_titleL="移動窓の類似度計算";
_docL="\
\n\
MMVSIM 移動窓の類似度計算\n\
\n\
移動窓を設定し、各種類似度(2変量の統計量)を計算する。\n\
msimコマンドの移動窓バージョンとして考えればよい。\n\
msimとの違いは、指定できる類似度は一つだけで、また類似度計算の対象項目は2つのみである。\n\
\n\
書式\n\
\n\
mmvsim [s=] [k=] f= c= a= [t=] [skip=] -n  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  s=      ここで指定した項目(複数項目指定可)で並べ替えられた後、各種類似度が計算される。\n\
          -qオプションを指定しないとき、s=パラメータは必須。\n\
  k=      ここで指定された項目(複数項目指定可)を単位として集計する。\n\
  f=      集計項目名リスト(複数項目指定可)を指定する。\n\
  t=      期間数を1以上の整数で指定する。\n\
  c=      類似度(以下のリストから一つだけ)指定する。\n\
          covar|ucovar|pearson|spearman|kendall|euclid|\n\
          cosine|cityblock|hamming|chi|phi|jaccard|support|lift\n\
          詳細な定義はmsimコマンドを参照のこと。\n\
  skip=   出力を抑制する最初の行数を指定する。【デフォルト値:skip=(t=の値-1)】\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
x、y項目についてのピアソンの積率相関係数を3期を窓として計算する。\n\
\n\
    $ more dat1.csv\n\
    t,x,y\n\
    1,14,0.17\n\
    2,11,0.2\n\
    3,32,0.15\n\
    4,13,0.33\n\
    5,8,0.1\n\
    6,19,0.56\n\
    $ mmvsim s=t t=3 c=pearson f=x,y a=sim i=dat1.csv o=rsl1.csv\n\
    #END# kgmvsim a=sim c=pearson f=x,y i=dat1.csv o=rsl1.csv s=t t=3\n\
    $ more rsl1.csv\n\
    t%0,x,y,sim\n\
    3,32,0.15,-0.8746392857\n\
    4,13,0.33,-0.6515529194\n\
    5,8,0.1,-0.1164257338\n\
    6,19,0.56,0.9986254289\n\
";

