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
/// kgsplitHelp.h : kgsplit help
// =============================================================================
_titleL="区切り文字による項目分割";
_docL="\
\n\
MSPLIT 区切り文字による項目分割\n\
\n\
区切り文字によって項目を分割する。\n\
\n\
書式\n\
\n\
msplit f= a= [-r] [delim=] [i=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=       区切り文字で分割するデータの項目名を指定する\n\
  a=       新項目を指定する\n\
           ここで指定した項目名分分割される。足りない分はNULLとなる\n\
  delim=   新しい区切り文字を指定する。デフォルト値は半角スペース。\n\
  -r       f=で指定した項目を取り除く\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
半角スペースで分割\n\
\n\
    $ more dat1.csv\n\
    id,data\n\
    A,1 10 2\n\
    A,2 20 3\n\
    B,1 15 5\n\
    B,3 10 4\n\
    B,1 20 6\n\
    $ msplit f=data a=d1,d2,d3 i=dat1.csv o=rsl1.csv\n\
    #END# kgsplit a=d1,d2,d3 f=data i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,data,d1,d2,d3\n\
    A,1 10 2,1,10,2\n\
    A,2 20 3,2,20,3\n\
    B,1 15 5,1,15,5\n\
    B,3 10 4,3,10,4\n\
    B,1 20 6,1,20,6\n\
\n\
例2: -r利用\n\
\n\
-rを指定することで、f=で項目を削除できる。\n\
\n\
    $ msplit f=data a=d1,d2,d3 -r i=dat1.csv o=rsl2.csv\n\
    #END# kgsplit -r a=d1,d2,d3 f=data i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,d1,d2,d3\n\
    A,1,10,2\n\
    A,2,20,3\n\
    B,1,15,5\n\
    B,3,10,4\n\
    B,1,20,6\n\
\n\
例3: 分割数不一致\n\
\n\
a=で指定した項目数よりも分割できる項目数が少ない場合は、NULLが追加され、\n\
多い場合、先頭から指定した分割数まで出力する\n\
\n\
    $ more dat2.csv\n\
    id,data\n\
    A,1 10 2\n\
    A,2 20 3\n\
    B,1 15 5\n\
    B,3 4\n\
    B,1\n\
    $ msplit f=data a=d1,d2 i=dat2.csv o=rsl3.csv\n\
    #END# kgsplit a=d1,d2 f=data i=dat2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id,data,d1,d2\n\
    A,1 10 2,1,10\n\
    A,2 20 3,2,20\n\
    B,1 15 5,1,15\n\
    B,3 4,3,4\n\
    B,1,1,\n\
\n\
例4: delim指定\n\
\n\
delim=を使用して半角スペース以外の文字で分割する\n\
\n\
    $ more dat3.csv\n\
    id,data\n\
    A,1_10_3\n\
    A,2_20_5\n\
    B,1_15_6\n\
    B,3_10_7\n\
    B,1_20_8\n\
    $ msplit f=data a=d1,d2,d3 delim=_ i=dat3.csv o=rsl4.csv\n\
    #END# kgsplit a=d1,d2,d3 delim=_ f=data i=dat3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id,data,d1,d2,d3\n\
    A,1_10_3,1,10,3\n\
    A,2_20_5,2,20,5\n\
    B,1_15_6,1,15,6\n\
    B,3_10_7,3,10,7\n\
    B,1_20_8,1,20,8\n\
";

