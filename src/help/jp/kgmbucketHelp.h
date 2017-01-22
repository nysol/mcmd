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
/// kgmbucketHelp.h : kgmbucket help
// =============================================================================
_titleL="多次元均等化バケット分割";
_docL="\
\n\
MMBUCKET 多次元均等化バケット分割\n\
\n\
f=で指定した複数の数値項目を次元とした件数均等化バケット分割を行う。\n\
例えば、f=a,b,cそしてn=5と指定すると、\n\
mbucketコマンドと同様に、項目a,b,cそれぞれを5つの区間に分割するが、\n\
mmbucketでは、項目a,b,cの3次元空間における各バケット(バケット数は5³ = 125個になる)に\n\
属する件数ができるだけ均等になるような区間を計算する\n\
\n\
書式\n\
\n\
mmbucket f= n= [F=] [k=] [O=] [-ms] [-r] [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=    ここで指定した項目(複数項目指定可)の値を分割する。\n\
        複数指定すれば、その数の次元に基づく均等化バケット分割を行う。\n\
        1項目のみ指定すればmbucketと同じ結果になる。\n\
        -x,-nfnオプション使用時は、項目番号(0〜)で指定可能。\n\
  n=    f=で指定した項目数と同じ個数分指定する。\n\
        ただし1つの数字を指定した場合、f=で指定した全ての項目に、同じ分割数が適用される。\n\
  F=    出力形式を指定する。【デフォルト値:1】\n\
        バケットの名前を出力形式。\n\
        0:バケット番号のみを表示する。\n\
        1:バケットの範囲のみを表示する。\n\
        2:バケット番号とバケット範囲の両方を表示する。\n\
  k=    バケット分割を行う単位となる項目名リスト(複数項目指定可)を指定する。\n\
  O=    f=パラメータで指定した各項目の各バケットの数値範囲を出力するファイル名を指定する。\n\
  -ms   各項目を順次バケット分割していく時の開始項目を変えることで複数回のバケット分割をトライし、\n\
        よりよい解を求める。詳細は、以下の「アルゴリズムの概要」を参照のこと。\n\
  -r    バケット番号を逆順に出力する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
x、y項目の件数ができるだけ多次元均等になるように2分割する。\n\
その際、各バケットの数値範囲をrng.csvという名前のファイルに出力する。\n\
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
    $ mmbucket f=x:xb,y:yb n=2,2 O=rng.csv i=dat1.csv o=rsl1.csv\n\
    calculating on dimension ... #0 #1 done. VAR=30 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=28 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=28\n\
    #END# kgmbucket O=rng.csv f=x:xb,y:yb i=dat1.csv n=2,2 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,x,y,xb,yb\n\
    A,2,7,1,2\n\
    B,6,7,2,2\n\
    C,5,6,2,2\n\
    D,7,5,2,2\n\
    E,6,4,2,1\n\
    F,1,3,1,1\n\
    G,3,3,1,1\n\
    H,4,2,2,1\n\
    I,7,2,2,1\n\
    J,2,1,1,1\n\
    $ more rng.csv\n\
    fieldName,bucketNo,rangeFrom,rangeTo\n\
    x,1,,3.5\n\
    x,2,3.5,\n\
    y,1,,4.5\n\
    y,2,4.5,\n\
\n\
例2: 出力形式\n\
\n\
id項目を単位に件数ができるだけ多次元均等になるようにx,y項目を2分割する。\n\
出力形式はバケット番号とバケット範囲の両方を表示する。\n\
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
    $ mmbucket k=id f=x:xb,y:yb n=2,2 F=2 i=dat2.csv o=rsl2.csv\n\
    calculating on dimension ... #0 #1 done. VAR=3 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=3\n\
    calculating on dimension ... #0 #1 done. VAR=3 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=3\n\
    calculating on dimension ... #0 #1 done. VAR=6 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=6\n\
    #END# kgmbucket F=2 f=x:xb,y:yb i=dat2.csv k=id n=2,2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id%0,x,y,xb,yb\n\
    A,2,7,1:_3.5,2:6.5_\n\
    A,6,7,2:3.5_,2:6.5_\n\
    A,5,6,2:3.5_,1:_6.5\n\
    B,7,5,2:3.5_,2:4.5_\n\
    B,6,4,2:3.5_,1:_4.5\n\
    B,1,3,1:_3.5,1:_4.5\n\
    C,3,3,1:_3.5,2:1.5_\n\
    C,4,2,2:3.5_,2:1.5_\n\
    C,7,2,2:3.5_,2:1.5_\n\
    C,2,1,1:_3.5,1:_1.5\n\
";

