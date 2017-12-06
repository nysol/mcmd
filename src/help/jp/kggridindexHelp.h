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
/// kgcrossHelp.h : kgcross help
// =============================================================================
_titleL="クロス集計";
_docL="\
\n\
MCROSS クロス集計\n\
\n\
クロス集計を行う。\n\
s=で指定した項目の値が項目名となるように横に展開され、\n\
k=で指定した値が行idとなり、 f=で指定した項目がセルとして出力される。\n\
\n\
書式\n\
\n\
mcross f= s= [a=] [k=] [v=] [n=]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定された項目の値がセルの値として出力される。\n\
       複数項目指定すると、複数行に展開される。\n\
       それら複数行を識別するための項目としてfld項目が出力され、\n\
       f=で指定した項目名が値として出力される。\n\
       このfldという項目名を変更したい場合はa=パラメータを使う。\n\
  s=   列項目名に展開する項目を指定する。\n\
       ここで指定された項目の値が項目名として出力される。\n\
  a=   f=で指定した項目名がデータとして展開される項目名を指定する。\n\
       省略した場合はfldという項目名で出力される。\n\
  k=   キー項目名リスト\n\
       ここで指定した項目を単位に横展開をおこなう。\n\
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
    item,date,quantity,price\n\
    A,20081201,1,10\n\
    A,20081202,2,20\n\
    A,20081203,3,30\n\
    B,20081201,4,40\n\
    B,20081203,5,50\n\
    $ mcross k=item f=quantity s=date i=dat1.csv o=rsl1.csv\n\
    #END# kgcross f=quantity i=dat1.csv k=item o=rsl1.csv s=date\n\
    $ more rsl1.csv\n\
    item%0,fld,20081201,20081202,20081203\n\
    A,quantity,1,2,3\n\
    B,quantity,4,,5\n\
\n\
例2: 元の入力データに戻す例\n\
\n\
例1の出力結果を元に戻すには、同じくmcrossを以下のよう用いればよい。\n\
\n\
    $ more rsl1.csv\n\
    item%0,fld,20081201,20081202,20081203\n\
    A,quantity,1,2,3\n\
    B,quantity,4,,5\n\
    $ mcross k=item f=2008* s=fld a=date i=rsl1.csv o=rsl2.csv\n\
    #END# kgcross a=date f=2008* i=rsl1.csv k=item o=rsl2.csv s=fld\n\
    $ more rsl2.csv\n\
    item%0,date,quantity\n\
    A,20081201,1\n\
    A,20081202,2\n\
    A,20081203,3\n\
    B,20081201,4\n\
    B,20081202,\n\
    B,20081203,5\n\
\n\
例3: 複数の値を出力\n\
\n\
quantity,priceの2項目を出力する。\n\
\n\
    $ mcross k=item f=quantity,price s=date i=dat1.csv o=rsl3.csv\n\
    #END# kgcross f=quantity,price i=dat1.csv k=item o=rsl3.csv s=date\n\
    $ more rsl3.csv\n\
    item%0,fld,20081201,20081202,20081203\n\
    A,quantity,1,2,3\n\
    A,price,10,20,30\n\
    B,quantity,4,,5\n\
    B,price,40,,50\n\
\n\
例4: 並びを逆順する例\n\
\n\
横に展開する項目名の並びを逆順にする。\n\
\n\
    $ mcross k=item f=quantity,price s=date%r i=dat1.csv o=rsl4.csv\n\
    #END# kgcross f=quantity,price i=dat1.csv k=item o=rsl4.csv s=date%r\n\
    $ more rsl4.csv\n\
    item%0,fld,20081203,20081202,20081201\n\
    A,quantity,3,2,1\n\
    A,price,30,20,10\n\
    B,quantity,5,,4\n\
    B,price,50,,40\n\
";

