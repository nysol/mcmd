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
/// kgduprecHelp.h : kgduprec help
// =============================================================================
_titleL="レコードの複写";
_docL="\
\n\
MDUPREC レコードの複写\n\
\n\
各レコードを複写する。 複写する行数はn=で固定値を与えるか、\n\
もしくはf=で指定した項目の値により与える。\n\
\n\
書式\n\
\n\
mduprec f=|n= [i=] [o=] [-assert_diffSize] [-assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   複写行数をもつ項目名\n\
       ここで指定した項目の値の数分、その行を複写する。\n\
  n=   複写行数の指定\n\
       ここで指定した値の数分、行を複写する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「数量」項目の値の数分、データを複写し複数行のデータを生成する。\n\
対象項目がNULL値の場合は複写しない。\n\
\n\
    $ more dat1.csv\n\
    store,val\n\
    A,2\n\
    B,\n\
    C,5\n\
    $ mduprec f=val i=dat1.csv o=rsl1.csv\n\
    #END# kgduprec f=val i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    store,val\n\
    A,2\n\
    A,2\n\
    C,5\n\
    C,5\n\
    C,5\n\
    C,5\n\
    C,5\n\
\n\
例2: 複写行数の指定\n\
\n\
データを2行づつ複写した(n=2)データを生成する。\n\
\n\
    $ mduprec n=2 i=dat1.csv o=rsl2.csv\n\
    #END# kgduprec i=dat1.csv n=2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    store,val\n\
    A,2\n\
    A,2\n\
    B,\n\
    B,\n\
    C,5\n\
    C,5\n\
";

