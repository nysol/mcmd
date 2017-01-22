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
/// kgchgnumHelp.h : kgchgnum help
// =============================================================================
_titleL="数値範囲による置換";
_docL="\
\n\
MCHGNUM 数値範囲による置換\n\
\n\
f=パラメータで指定した項目について、R=パラメータで指定する\n\
数値範囲条件とv=パラメータで指定する置換文字列により、項目の値を置換する。\n\
\n\
書式\n\
\n\
mchgnum f= R= [O=|-F] [v=] [-A] [-r] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ここで指定した項目(複数項目指定可)の数値をR=とv=パラメータで指定した\n\
       数値範囲リストおよび置換文字列リストに従って置換する。\n\
  R=   置換対象となる数値範囲を指定(複数項目指定可)する(1.1,2.5 : 1.1以上2.5未満)。\n\
       最小値、最大値としてMIN,MAXを使うことができる(MIN,2.5 : 2.5未満)。\n\
  O=   範囲外文字列\n\
       R=パラメータで指定した数値範囲リストのいずれとも合致しない値を\n\
       置換するときの文字列(指定がなければNULL値となる)を指定する。\n\
  -F   範囲外を項目の値として出力\n\
       R=パラメータで指定した数値範囲リストのいずれとも\n\
       合致しない値は、その項目の値のまま出力する。\n\
  v=   R=パラメータで指定した数値範囲に対応する置換文字列を指定する。\n\
       R=で指定した値の個数より1つ少い個数でなければならない。\n\
  -A   このオプションにより、指定した項目を置き換えるのではなく、新たに項目が追加される。\n\
  -r   R=パラメータの範囲を’〜より大きく〜以下’として扱う。\n\
       例えば、1.1_2.5は「1.1より大きく2.5以下」として扱う。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
quantity項目の値が最小以上10未満をlow、\n\
10以上20未満をmiddle、20以上最大未満をhighという文字列に置換する。\n\
\n\
    $ more dat1.csv\n\
    customer,quantity\n\
    A,5\n\
    B,10\n\
    C,15\n\
    D,2\n\
    E,50\n\
    $ mchgnum f=quantity R=MIN,10,20,MAX v=low,middle,high i=dat1.csv o=rsl1.csv\n\
    #END# kgchgnum R=MIN,10,20,MAX f=quantity i=dat1.csv o=rsl1.csv v=low,middle,high\n\
    $ more rsl1.csv\n\
    customer,quantity\n\
    A,low\n\
    B,middle\n\
    C,middle\n\
    D,low\n\
    E,high\n\
\n\
例2: パラメータ範囲にイコールをつける例\n\
\n\
quantity項目の値が最小より多く10以下をlow、\n\
10より多く20以下をmiddle、20より多く最大以下をhighという文字列に置換する。\n\
\n\
    $ mchgnum f=quantity R=MIN,10,20,MAX v=low,middle,high -r i=dat1.csv o=rsl2.csv\n\
    #END# kgchgnum -r R=MIN,10,20,MAX f=quantity i=dat1.csv o=rsl2.csv v=low,middle,high\n\
    $ more rsl2.csv\n\
    customer,quantity\n\
    A,low\n\
    B,low\n\
    C,middle\n\
    D,low\n\
    E,high\n\
\n\
例3: 数値範囲リストに合致しない値を置換\n\
\n\
quantity項目の値が10以上20未満をlow、\n\
20以上30未満をmiddle、30以上最大未満をhigh、\n\
数量が10より小さい値はout of rangeという文字列に置換する。\n\
\n\
    $ mchgnum f=quantity R=10,20,30,MAX v=low,middle,high O=\"out of range\" i=dat1.csv o=rsl3.csv\n\
    #END# kgchgnum O=out of range R=10,20,30,MAX f=quantity i=dat1.csv o=rsl3.csv v=low,middle,high\n\
    $ more rsl3.csv\n\
    customer,quantity\n\
    A,out of range\n\
    B,low\n\
    C,low\n\
    D,out of range\n\
    E,high\n\
\n\
例4: 新たな項目の追加\n\
\n\
quantity項目の値が最小以上10未満をlow、\n\
10以上20未満をmiddle、20以上最大未満をhighという文字列に置換し\n\
evaluateという項目名で出力する。\n\
\n\
    $ mchgnum f=quantity:evaluate R=MIN,10,20,MAX v=low,middle,high -A i=dat1.csv o=rsl4.csv\n\
    #END# kgchgnum -A R=MIN,10,20,MAX f=quantity:evaluate i=dat1.csv o=rsl4.csv v=low,middle,high\n\
    $ more rsl4.csv\n\
    customer,quantity,evaluate\n\
    A,5,low\n\
    B,10,middle\n\
    C,15,middle\n\
    D,2,low\n\
    E,50,high\n\
\n\
例5: 範囲外を項目の値として出力\n\
\n\
quantity項目の値が10以上20未満をlow、20以上30未満をmiddle、\n\
30以上最大未満をhigh、数量が10より小さい値は置換しないでそのまま出力する。\n\
\n\
    $ mchgnum f=quantity R=10,20,30,MAX v=low,middle,high -F i=dat1.csv o=rsl5.csv\n\
    #END# kgchgnum -F R=10,20,30,MAX f=quantity i=dat1.csv o=rsl5.csv v=low,middle,high\n\
    $ more rsl5.csv\n\
    customer,quantity\n\
    A,5\n\
    B,low\n\
    C,low\n\
    D,2\n\
    E,high\n\
";

