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
/// kgmvavgHelp.h : kgmvavg help
// =============================================================================
_titleL="移動平均の算出";
_docL="\
\n\
MMVAVG 移動平均の算出\n\
\n\
移動平均(moving average)を算出する。\n\
移動平均としては、単純移動平均(SMA)、線形荷重移動平均(WMA)、指数平滑移動平均(EMA)の３種類の移動平均が計算可能である。\n\
\n\
書式\n\
\n\
mmvavg [s=] [k=] [n=] f= [t=] [-exp|-w] [alpha=] [skip=] [i=] [o=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [precision=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  s=       ここで指定した項目(複数項目指定可)で並べ替えられた後、移動平均が計算される。\n\
           -qオプションを指定しないとき、s=パラメータは必須。\n\
  k=       ここで指定された項目(複数項目指定可)を単位として集計する。\n\
  f=       移動平均を求める項目名リスト(複数項目指定可)を指定する。\n\
  t=       期間数を1以上の整数で指定する。\n\
           -exp指定時にalpha=を指定すればt=は指定できない。\n\
  -w       線形加重移動平均を求める。\n\
  -exp     指数平滑移動平均を求める。\n\
  alpha=   -expが指定された時の平滑化係数を実数値で与える。\n\
           省略時はalpha=2/(t=の値+1)。\n\
  skip=    出力を抑制する最初の行数。\n\
           デフォルト値: skip=(t=の値-1), -expが指定された場合はskip=0\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
最初の行は期数に満たないため出力されない。\n\
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
    $ mmvavg s=id f=value t=2 i=dat1.csv o=rsl1.csv\n\
    #END# kgmvavg f=value i=dat1.csv o=rsl1.csv s=id t=2\n\
    $ more rsl1.csv\n\
    id%0,value\n\
    2,3\n\
    3,2\n\
    4,3.5\n\
    5,4\n\
    6,5\n\
    7,3.5\n\
    8,2.5\n\
    9,5.5\n\
\n\
例2: 基本例2\n\
\n\
最初の行は期数に満たないため出力されない。\n\
\n\
    $ mmvavg s=id f=value t=2 -w i=dat1.csv o=rsl2.csv\n\
    #END# kgmvavg -w f=value i=dat1.csv o=rsl2.csv s=id t=2\n\
    $ more rsl2.csv\n\
    id%0,value\n\
    2,2.333333333\n\
    3,2.333333333\n\
    4,3.666666667\n\
    5,4\n\
    6,5.333333333\n\
    7,2.666666667\n\
    8,3\n\
    9,6\n\
\n\
例3: 基本例3\n\
\n\
指数平滑移動平均(-exp)の場合は最初の行から出力される。\n\
\n\
    $ mmvavg s=id f=value t=2 -exp i=dat1.csv o=rsl3.csv\n\
    #END# kgmvavg -exp f=value i=dat1.csv o=rsl3.csv s=id t=2\n\
    $ more rsl3.csv\n\
    id%0,value\n\
    1,5\n\
    2,2.333333333\n\
    3,2.777777778\n\
    4,3.592592593\n\
    5,3.864197531\n\
    6,5.288065844\n\
    7,2.429355281\n\
    8,3.47645176\n\
    9,5.82548392\n\
\n\
例4: キーを指定する例\n\
\n\
    $ more dat2.csv\n\
    id,key,value\n\
    1,a,5\n\
    2,a,1\n\
    3,a,3\n\
    4,a,4\n\
    5,a,4\n\
    6,b,6\n\
    7,b,1\n\
    8,b,4\n\
    9,b,7\n\
    $ mmvavg s=key,id k=key f=value t=2 i=dat2.csv o=rsl4.csv\n\
    #END# kgmvavg f=value i=dat2.csv k=key o=rsl4.csv s=key,id t=2\n\
    $ more rsl4.csv\n\
    id,key,value\n\
    2,a,3\n\
    3,a,2\n\
    4,a,3.5\n\
    5,a,4\n\
    7,b,3.5\n\
    8,b,2.5\n\
    9,b,5.5\n\
\n\
例5: 指定した期に満たなくても出力する例\n\
\n\
    $ more dat3.csv\n\
    key,value\n\
    a,1\n\
    a,2\n\
    a,3\n\
    a,4\n\
    a,5\n\
    b,6\n\
    b,1\n\
    b,4\n\
    b,7\n\
    $ mmvavg -q k=key f=value t=2 skip=0 i=dat3.csv o=rsl5.csv\n\
    #END# kgmvavg -q f=value i=dat3.csv k=key o=rsl5.csv skip=0 t=2\n\
    $ more rsl5.csv\n\
    key,value\n\
    a,1\n\
    a,1.5\n\
    a,2.5\n\
    a,3.5\n\
    a,4.5\n\
    b,6\n\
    b,3.5\n\
    b,2.5\n\
    b,5.5\n\
";

