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
/// kgcountHelp.h : kgcount help
// =============================================================================
_titleL="行数カウント";
_docL="\
\n\
MCOUNT 行数カウント\n\
\n\
行数をカウントし、a=パラメータで指定した項目名で出力する。\n\
k=を指定すると、集計キー毎の件数をカウントし、\n\
k=を指定しなければ、全行数がカウントされる。\n\
\n\
書式\n\
\n\
mcount a= [k=] [i=] [o=] [-assert_diffSize] [-assert_nullkey] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=   新たに追加される項目の名前を指定する。\n\
       nfnオプション使用時は、必須ではない。\n\
  k=   キー項目名リスト(複数項目指定可)\n\
       カウントの単位となる項目名リスト。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
date項目を単位に行数をカウントし、countという項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    date\n\
    20090109\n\
    20090109\n\
    20090110\n\
    20090109\n\
    20090110\n\
    $ mcount k=date a=count i=dat1.csv o=rsl1.csv\n\
    #END# kgcount a=count i=dat1.csv k=date o=rsl1.csv\n\
    $ more rsl1.csv\n\
    date%0,count\n\
    20090109,3\n\
    20090110,2\n\
\n\
例2: 集計キーなし\n\
\n\
集計キーを指定しなければ全体の行数をカウントする。\n\
\n\
    $ mcount a=count i=dat1.csv o=rsl2.csv\n\
    #END# kgcount a=count i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    date,count\n\
    20090110,5\n\
";

