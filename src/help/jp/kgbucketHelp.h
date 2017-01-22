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
/// kgbucketHelp.h : kgbucket help
// =============================================================================
_titleL="件数均等化バケット分割";
_docL="\
\n\
MBUCKET 件数均等化バケット分割\n\
\n\
f=で指定した数値項目をn=で指定した数の区間に分割する。\n\
区間の計算には2通りの方法があり、一つは、\n\
各区間に属する件数ができるだけ均等になるような区間を計算する\n\
(件数均等化バケット分割と呼ぶ)。\n\
他方は、区間の範囲が均等になるような区間を計算する\n\
(範囲均等化バケット分割と呼ぶ)。\n\
-rngを指定すると範囲均等分割となり、指定しなければ件数均等分割となる。\n\
f=に複数の項目を指定した場合は、それぞれの項目ごとにバケット分割を実行する。\n\
\n\
書式\n\
\n\
mbucket f= n= [-rng] [-r] [F=] [k=] [O=] [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullout] [-nfn] [-nfno]\n\
[-x] [-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=     ここで指定した項目(複数項目指定可)の値に基づいて分割をおこなう。\n\
         分割対象の項目名:出力する項目名\n\
  n=     分割数\n\
         f=で指定した項目それぞれの分割数をカンマで区切って指定する。\n\
         ただし1つの数字を指定した場合は全ての項目の分割数として扱われる。\n\
  F=     出力形式【デフォルト値:0】\n\
         バケットの名前を出力形式。\n\
         0:バケット番号のみを表示する。\n\
         1:バケットの範囲のみを表示する。\n\
         2:バケット番号とバケット範囲の両方を表示する。\n\
  k=     バケット分割を行う単位となる項目(複数項目指定可)名リスト。\n\
  O=     バケット範囲出力ファイル\n\
         f=パラメータで指定した各項目の各バケットの数値範囲を出力するファイル名。\n\
  -rng   バケットの範囲均等指定\n\
         バケットの範囲が均等になるように分割する。\n\
  -r     バケットの番号を逆順に出力する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
x,y項目それぞれで、件数ができるだけ均等になるように2分割する。\n\
その際、各バケットの数値範囲をrng1.csvに出力する。\n\
\n\
    $ more dat1.csv\n\
    id,x,y\n\
    A,2,7\n\
    B,6,7\n\
    C,5,6\n\
    D,7,5\n\
    E,6,4\n\
    F,1,3\n\
    G,3,3\n\
    H,4,2\n\
    I,7,2\n\
    J,2,1\n\
    $ mbucket f=x:xb,y:yb n=2 O=rng1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgbucket O=rng1.csv f=x:xb,y:yb i=dat1.csv n=2 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,x,y,xb,yb\n\
    A,2,7,1,2\n\
    B,6,7,2,2\n\
    C,5,6,2,2\n\
    D,7,5,2,2\n\
    E,6,4,2,2\n\
    F,1,3,1,1\n\
    G,3,3,1,1\n\
    H,4,2,1,1\n\
    I,7,2,2,1\n\
    J,2,1,1,1\n\
    $ more rng1.csv\n\
    fieldName,bucketNo,rangeFrom,rangeTo\n\
    x,1,,4.5\n\
    x,2,4.5,\n\
    y,1,,3.5\n\
    y,2,3.5,\n\
\n\
例2: 範囲均等化分割\n\
\n\
-rngオプションを指定すると範囲均等化分割となる。\n\
\n\
    $ mbucket f=x:xb,y:yb n=2 -rng O=rng2.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgbucket -rng O=rng2.csv f=x:xb,y:yb i=dat1.csv n=2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,x,y,xb,yb\n\
    A,2,7,1,2\n\
    B,6,7,2,2\n\
    C,5,6,2,2\n\
    D,7,5,2,2\n\
    E,6,4,2,2\n\
    F,1,3,1,1\n\
    G,3,3,1,1\n\
    H,4,2,2,1\n\
    I,7,2,2,1\n\
    J,2,1,1,1\n\
    $ more rng2.csv\n\
    fieldName,bucketNo,rangeFrom,rangeTo\n\
    x,1,,4\n\
    x,2,4,\n\
    y,1,,4\n\
    y,2,4,\n\
\n\
例3: キー項目を指定した例\n\
\n\
id項目を集計キーとして、x,y項目それぞれを件数均等化バケット分割する。\n\
n=2,3と指定することで、x項目の分割数は2に、 y項目の分割数は3となる。\n\
出力形式はバケット番号とバケット範囲の両方を表示する(F=2)。\n\
\n\
    $ more dat2.csv\n\
    id,x,y\n\
    A,2,7\n\
    A,6,7\n\
    A,5,6\n\
    B,7,5\n\
    B,6,4\n\
    B,1,3\n\
    C,3,3\n\
    C,4,2\n\
    C,7,2\n\
    C,2,1\n\
    $ mbucket k=id f=x:xb,y:yb n=2,3 F=2 i=dat2.csv o=rsl3.csv\n\
    #END# kgbucket F=2 f=x:xb,y:yb i=dat2.csv k=id n=2,3 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id%0,x,y,xb,yb\n\
    A,2,7,1:_3.5,2:6.5_\n\
    A,6,7,2:3.5_,2:6.5_\n\
    A,5,6,2:3.5_,1:_6.5\n\
    B,7,5,2:3.5_,3:4.5_\n\
    B,6,4,2:3.5_,2:3.5_4.5\n\
    B,1,3,1:_3.5,1:_3.5\n\
    C,3,3,1:_3.5,3:2.5_\n\
    C,4,2,2:3.5_,2:1.5_2.5\n\
    C,7,2,2:3.5_,2:1.5_2.5\n\
    C,2,1,1:_3.5,1:_1.5\n\
";

