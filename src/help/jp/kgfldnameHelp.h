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
/// kgfldnameHelp.h : kgfldname help
// =============================================================================
_titleL="項目名の変更";
_docL="\
\n\
MFLDNAME 項目名の変更\n\
\n\
f=で指定した項目名を変更する。又、n=で項目名を新規設定する。\n\
\n\
書式\n\
\n\
mfldname f=|n= [-nfni] [i=] [o=] [-assert_diffSize] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=      ここで指定された項目名のみを変更する。(現項目名:新項目名)\n\
          指定していない項目名は変更せずに元の項目名が出力される。\n\
  n=      ここで指定された項目名が新たに採用される。\n\
          データ項目数と同じ数の項目名を指定する必要がある。\n\
  -nfni   入力データの１行目を項目名行とみなさない。このオプションが指定された場合はf=は利用できない。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
項目名の「顧客」を「cust」に、「10月」を「Oct.」に変更する。\n\
\n\
    $ more dat1.csv\n\
    顧客,itemID,10月\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
    $ mfldname f=顧客:cust,10月:Oct. i=dat1.csv o=rsl1.csv\n\
    #END# kgfldname f=顧客:cust,10月:Oct. i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    cust,itemID,Oct.\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
\n\
例2: 項目名変更\n\
\n\
項目名をx,y,zに変更する。\n\
\n\
    $ mfldname n=x,y,z i=dat1.csv o=rsl2.csv\n\
    #END# kgfldname i=dat1.csv n=x,y,z o=rsl2.csv\n\
    $ more rsl2.csv\n\
    x,y,z\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
\n\
例3: 項目名行がないデータ\n\
\n\
    $ more dat2.csv\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
    $ mfldname -nfni n=x,y,z i=dat2.csv o=rsl3.csv\n\
    #END# kgfldname -nfni i=dat2.csv n=x,y,z o=rsl3.csv\n\
    $ more rsl3.csv\n\
    x,y,z\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
";

