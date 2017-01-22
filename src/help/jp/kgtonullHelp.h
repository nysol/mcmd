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
/// kgtonullHelp.h : kgtonull help
// =============================================================================
_titleL="NULL値へ置換";
_docL="\
\n\
MTONULL NULL値へ置換\n\
\n\
f=パラメータで指定した項目を対象に、\n\
v=パラメータで指定した値にマッチした項目データをNULL値に置換する。\n\
マッチの方法としては完全一致(デフォルト)と部分文字列マッチ(-subオプション)を選択できる。\n\
\n\
書式\n\
\n\
mtonull f= v= [-sub] [-W] [i=] [o=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   置換対象の項目名リスト(複数項目指定可)を指定する。\n\
  v=   f=パラメータで指定した項目の値が、ここで指定した文字列リスト(複数項目指定可)\n\
       のいずれかにマッチすればNULL値に置換する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
quantityとprice項目が0をNULL値に置換する。\n\
\n\
    $ more dat1.csv\n\
    item,quantity,price\n\
    A,0,1\n\
    B,1,0\n\
    C,2,200\n\
    D,3,0\n\
    E,0,298\n\
    $ mtonull f=quantity,price v=0 i=dat1.csv o=rsl1.csv\n\
    #END# kgtonull f=quantity,price i=dat1.csv o=rsl1.csv v=0\n\
    $ more rsl1.csv\n\
    item,quantity,price\n\
    A,,1\n\
    B,1,\n\
    C,2,200\n\
    D,3,\n\
    E,,298\n\
\n\
例2: NULL値に置換する数字の指定\n\
\n\
quantityとprice項目が0もしくは1をNULL値に置換する。\n\
\n\
    $ mtonull f=quantity,price v=0,1 i=dat1.csv o=rsl2.csv\n\
    #END# kgtonull f=quantity,price i=dat1.csv o=rsl2.csv v=0,1\n\
    $ more rsl2.csv\n\
    item,quantity,price\n\
    A,,\n\
    B,,\n\
    C,2,200\n\
    D,3,\n\
    E,,298\n\
\n\
例3: 部分文字列マッチでの置換\n\
\n\
quantityとprice項目が0を含めばNULL値に置換する。\n\
\n\
    $ mtonull -sub f=quantity,price v=0 i=dat1.csv o=rsl3.csv\n\
    #END# kgtonull -sub f=quantity,price i=dat1.csv o=rsl3.csv v=0\n\
    $ more rsl3.csv\n\
    item,quantity,price\n\
    A,,1\n\
    B,1,\n\
    C,2,\n\
    D,3,\n\
    E,,298\n\
\n\
例4: 指定の文字列の置換\n\
\n\
item項目にapple、orange、pineappleを含む値をNULL値に置換する。\n\
\n\
    $ more dat2.csv\n\
    item,price\n\
    fruit:apple,100\n\
    fruit:peach,250\n\
    fruit:grape,300\n\
    fruit:pineapple,450\n\
    fruit:orange,500\n\
    $ mtonull f=item v=apple,orange,pineapple -sub i=dat2.csv o=rsl4.csv\n\
    #END# kgtonull -sub f=item i=dat2.csv o=rsl4.csv v=apple,orange,pineapple\n\
    $ more rsl4.csv\n\
    item,price\n\
    ,100\n\
    fruit:peach,250\n\
    fruit:grape,300\n\
    ,450\n\
    ,500\n\
";

