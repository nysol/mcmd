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
/// kgmvstatsHelp.h : kgmvstats help
// =============================================================================
_titleL="移動窓の統計量の計算";
_docL="\
\n\
MMVSTATS 移動窓の統計量の計算\n\
\n\
移動窓を設定し、各種統計量(1変量)を計算する。\n\
mstatsコマンドの移動窓バージョンとして考えればよい。\n\
\n\
書式\n\
\n\
mmvstats [s=] [k=] f= [t=] c= [skip=] -n  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  s=      ここで指定した項目(複数項目指定可)で並べ替えられた後、各種統計量が計算される。\n\
          -qオプションを指定しないとき、s=パラメータは必須。\n\
  k=      ここで指定された項目(複数項目指定可)を単位として集計する。\n\
  f=      集計項目名リスト(複数項目指定可)を指定する。\n\
  t=      期間数を1以上の整数で指定する。\n\
  c=      統計量(以下のリストから一つだけ指定可)\n\
          sum|mean|devsq|var|uvar|sd|usd|cv|min|\n\
          |max|range|skew|uskew|kurt|ukurt\n\
          詳細な定義はmstatsコマンドを参照のこと。\n\
  skip=   出力を抑制する最初の行数\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
移動窓の合計を計算する。 最初の行は期数に満たないため出力されない。\n\
\n\
    $ more dat1.csv\n\
    id,value\n\
    1,5\n\
    2,1\n\
    3,3\n\
    4,4\n\
    5,4\n\
    6,6\n\
    7,1\n\
    8,4\n\
    9,7\n\
    $ mmvstats s=id f=value t=2 c=sum i=dat1.csv o=rsl1.csv\n\
    #END# kgmvstats c=sum f=value i=dat1.csv o=rsl1.csv s=id t=2\n\
    $ more rsl1.csv\n\
    id%0,value\n\
    2,6\n\
    3,4\n\
    4,7\n\
    5,8\n\
    6,10\n\
    7,7\n\
    8,5\n\
    9,11\n\
";

