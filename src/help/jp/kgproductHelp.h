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
/// kgproductHelp.h : kgproduct help
// =============================================================================
_titleL="参照ファイルの直積結合";
_docL="\
\n\
MPRODUCT 参照ファイルの直積結合\n\
\n\
入力データ1行に対して、m=パラメータで指定した参照データの\n\
f=パラメータで指定した項目全行を結合する。\n\
\n\
書式\n\
\n\
mproduct [f=] m=| i= [o=] [bufcount=] [-assert_diffSize]\n\
[-assert_nullin] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  f=   結合する参照ファイル上の項目名リスト(複数項目指定可)。\n\
       省略するとキー項目を除いた全ての項目が結合される。\n\
  m=   参照ファイル名を指定する。\n\
       このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
入力ファイルにあるcustomer項目に対して、\n\
参照ファイルにあるdate項目全行を結合する。\n\
\n\
    $ more dat1.csv\n\
    customer\n\
    A\n\
    B\n\
    $ more ref1.csv\n\
    date\n\
    20090101\n\
    20090201\n\
    20090301\n\
    $ mproduct f=date m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgproduct f=date i=dat1.csv m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,date\n\
    A,20090101\n\
    A,20090201\n\
    A,20090301\n\
    B,20090101\n\
    B,20090201\n\
    B,20090301\n\
";

