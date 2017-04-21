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
/// kg2crossHelp.h : kg2cross help
// =============================================================================
_titleL="1対Nのクロス集計";
_docL="\
\n\
M2CROSS 1対Nのクロス集計\n\
\n\
1対Nのクロス集計を行う。\n\
s=を指定した場合には項目の値が項目名となるように横に展開され、\n\
f=で指定した項目がセルとして出力される。 a=を指定した場合(2項目指定)には\n\
指定した値が項目名となり、 １項目にf=で指定した項目名が、\n\
２項目にf=で指定した項目値がそれぞれ縦展開される\n\
k=が指定されていた場合には、\n\
指定した値が行idとなり、id単位で展開される。\n\
\n\
書式\n\
\n\
m2cross f= s=|a= [k=] [v=] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定された項目の値がセルの値として出力される。\n\
       a=を使用するときのみ複数項目指定可。\n\
  s=   列項目名に展開する項目を指定する。\n\
       ここで指定された項目の値が項目名として出力される。\n\
  a=   ２項目指定する。\n\
       １項目目にf=で指定した項目名がデータとして展開される項目名を指定する。\n\
       ２項目目にf=で指定した項目値の項目名を指定する\n\
  k=   キー項目名リスト\n\
       ここで指定した項目を単位に展開をおこなう。\n\
  v=   NULL値置換文字列\n\
       NULL値があった場合、v=パラメータで指定する置換文字列により、項目の値を置換する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
item項目を単位にdate項目を横に展開し、 quantity項目を出力する。\n\
\n\
    $ more dat1.csv\n\
    item,date,quantity\n\
    A,20081201,1\n\
    A,20081202,2\n\
    A,20081203,3\n\
    B,20081201,4\n\
    B,20081203,5\n\
    $ m2cross k=item f=quantity s=date i=dat1.csv o=rsl1.csv\n\
    #END# kg2cross f=quantity i=dat1.csv k=item o=rsl1.csv s=date\n\
    $ more rsl1.csv\n\
    item%0,20081201,20081202,20081203\n\
    A,1,2,3\n\
    B,4,,5\n\
\n\
例2: 元の入力データに戻す例\n\
\n\
例1の出力結果を元に戻すには、同じくm2crossを以下のよう用いればよい。\n\
\n\
    $ more rsl1.csv\n\
    item%0,20081201,20081202,20081203\n\
    A,1,2,3\n\
    B,4,,5\n\
    $ m2cross f=2008* a=date,quantity i=rsl1.csv o=rsl2.csv\n\
    #END# kg2cross a=date,quantity f=2008* i=rsl1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    item%0,date,quantity\n\
    A,20081201,1\n\
    A,20081202,2\n\
    A,20081203,3\n\
    B,20081201,4\n\
    B,20081202,\n\
    B,20081203,5\n\
\n\
例3: 並びを逆順する例\n\
\n\
横に展開する項目名の並びを逆順にする。\n\
\n\
    $ m2cross k=item f=quantity s=date%r i=dat1.csv o=rsl4.csv\n\
    #END# kg2cross f=quantity i=dat1.csv k=item o=rsl4.csv s=date%r\n\
    $ more rsl4.csv\n\
    item%0,20081203,20081202,20081201\n\
    A,3,2,1\n\
    B,5,,4\n\
";

