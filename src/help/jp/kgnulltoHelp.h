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
/// kgnulltoHelp.h : kgnullto help
// =============================================================================
_titleL="NULL値の置換";
_docL="\
\n\
MNULLTO NULL値の置換\n\
\n\
f=パラメータで指定した項目について\n\
NULL値をv=パラメータで指定した文字列に置換する。\n\
\n\
書式\n\
\n\
mnullto f= [v=|-p] [O=] [-A] [i=] [o=] [-assert_diffSize] [-nfn] [-nfno]\n\
[-x] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定した項目(複数項目指定可)のNULL値が置換される。\n\
  v=   ここで指定した文字列にNULL値を置換する。\n\
  -p   前の行のNULL値で置換する。\n\
       v=パラメータと同時に指定できない。\n\
  O=   NULL値以外を置換したい場合は、ここで値を指定する。 指定しなければNULL値以外は置換しない。\n\
  -A   このオプションにより、指定した項目を置き換えるのではなく、 新たに項目が追加される。\n\
       -Aオプションを指定した場合は必ず、\n\
       :(コロン）で新項目名を指定する必要がある。例）f=数量:置換後の項目名\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
birthday項目がNULL値の場合は\"no value\"に置換する。\n\
\n\
    $ more dat1.csv\n\
    customer,birthday\n\
    A,19690103\n\
    B,\n\
    C,19500501\n\
    D,\n\
    E,\n\
    $ mnullto f=birthday v=\"no value\" i=dat1.csv o=rsl1.csv\n\
    #END# kgnullto f=birthday i=dat1.csv o=rsl1.csv v=no value\n\
    $ more rsl1.csv\n\
    customer,birthday\n\
    A,19690103\n\
    B,no value\n\
    C,19500501\n\
    D,no value\n\
    E,no value\n\
\n\
例2: NULL値以外の置換\n\
\n\
birthday項目がNULL値の場合は、\"no value\"\n\
値がある場合は\"value\"置換しentryという項目名に変更して出力する。\n\
\n\
    $ mnullto f=birthday:entry v=\"no value\" O=\"value\" i=dat1.csv o=rsl2.csv\n\
    #END# kgnullto O=value f=birthday:entry i=dat1.csv o=rsl2.csv v=no value\n\
    $ more rsl2.csv\n\
    customer,entry\n\
    A,value\n\
    B,no value\n\
    C,value\n\
    D,no value\n\
    E,no value\n\
\n\
例3: 新しい項目を出力\n\
\n\
birthday項目がNULL値の場合は\"no value\"、値がある場合は\"value\"に置換しentryという項目名で出力する。\n\
\n\
    $ mnullto f=birthday:entry v=\"no value\" O=\"value\" -A i=dat1.csv o=rsl3.csv\n\
    #END# kgnullto -A O=value f=birthday:entry i=dat1.csv o=rsl3.csv v=no value\n\
    $ more rsl3.csv\n\
    customer,birthday,entry\n\
    A,19690103,value\n\
    B,,no value\n\
    C,19500501,value\n\
    D,,no value\n\
    E,,no value\n\
\n\
例4: 前行の値に置換\n\
\n\
    $ more dat2.csv\n\
    id,date\n\
    A,19690103\n\
    B,\n\
    C,19500501\n\
    D,\n\
    E,\n\
    $ mnullto f=date -p i=dat2.csv o=rsl4.csv\n\
    #END# kgnullto -p f=date i=dat2.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id,date\n\
    A,19690103\n\
    B,19690103\n\
    C,19500501\n\
    D,19500501\n\
    E,19500501\n\
";

