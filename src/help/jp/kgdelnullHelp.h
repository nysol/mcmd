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
/// kgdelnullHelp.h : kgdelnull help
// =============================================================================
_titleL="NULL値行の削除";
_docL="\
\n\
MDELNULL NULL値行の削除\n\
\n\
f=パラメータで指定した項目について、NULL値が含まれる行を削除(撰択)する。\n\
\n\
書式\n\
\n\
mdelnull f= [k=] [u=] [-F] [-r] [-R] [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   NULL値の検索対象となる項目名（複数項目指定可）を指定する。\n\
  k=   削除(撰択)する単位となるキー項目名（複数項目指定可）を指定する。\n\
  u=   不一致データ出力ファイル名を指定する。\n\
  -F   項目間AND条件\n\
       f=パラメータで複数項目を指定した場合、その全ての値がNULL値の行を削除(撰択)する。\n\
  -r   条件反転\n\
       削除ではなく選択する。\n\
  -R   レコード間AND条件\n\
       k=パラメータを指定した場合、その全ての行がNULL値の行を削除(撰択)する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「数量」と「金額」項目がNULL値の行を削除する。\n\
NULL値の行はoth.csvに出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,,20\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
    $ mdelnull f=数量,金額 u=oth.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgdelnull f=数量,金額 i=dat1.csv o=rsl1.csv u=oth.csv\n\
    $ more rsl1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    B,1,15\n\
    C,1,20\n\
    $ more oth.csv\n\
    顧客,数量,金額\n\
    A,,20\n\
    B,3,\n\
\n\
例2: NULL値の行を選択\n\
\n\
-rを指定することで、削除ではなく選択することになる。\n\
\n\
    $ mdelnull f=数量,金額 -r i=dat1.csv o=rsl2.csv\n\
    #END# kgdelnull -r f=数量,金額 i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客,数量,金額\n\
    A,,20\n\
    B,3,\n\
\n\
例3: キー項目でのNULL値の行の削除\n\
\n\
k=を指定することで、集計キー単位で削除することになる。\n\
以下では「顧客」項目を単位にして、「数量」と「金額」項目にNULL値が一つでも含まれていれば削除する。\n\
\n\
    $ mdelnull k=顧客 f=数量,金額 i=dat1.csv o=rsl3.csv\n\
    #END# kgdelnull f=数量,金額 i=dat1.csv k=顧客 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客%0,数量,金額\n\
    C,1,20\n\
\n\
例4: 項目間AND条件の例\n\
\n\
「数量」と「金額」項目の両方がNULL値の行を削除する。\n\
\n\
    $ more dat2.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,,\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
    $ mdelnull f=数量,金額 -F i=dat2.csv o=rsl4.csv\n\
    #END# kgdelnull -F f=数量,金額 i=dat2.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
\n\
例5: レコード間AND条件の例\n\
\n\
「顧客」項目を単位にして、「数量」項目が全てNULL値の行を削除する。\n\
\n\
    $ mdelnull k=顧客 f=数量 -R i=dat1.csv o=rsl5.csv\n\
    #END# kgdelnull -R f=数量 i=dat1.csv k=顧客 o=rsl5.csv\n\
    $ more rsl5.csv\n\
    顧客%0,数量,金額\n\
    A,1,10\n\
    A,,20\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
";

