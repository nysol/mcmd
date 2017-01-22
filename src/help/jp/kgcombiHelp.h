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
/// kgcombiHelp.h : kgcombi help
// =============================================================================
_titleL="組合せ計算";
_docL="\
\n\
MCOMBI 組合せ計算\n\
\n\
f=パラメータで指定した項目について、\n\
n=パラメータで指定した数の組み合せを求め、\n\
a=パラメータで指定した項目名で出力する。\n\
-pを指定することで順列として出力することも可能である。\n\
\n\
書式\n\
\n\
mcombi a= f= n= [s=] [k=] [-p] [-dup] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  a=     新たに追加される項目の名前を指定する。\n\
  f=     組合せを求める項目名リスト（複数項目指定可）を指定する。\n\
         ここで指定した項目の値の全組合せを出力する。\n\
  n=     組合せの数を指定する。\n\
         組み合わせ数を大きくすると、出力レコードが爆発的に大きくなることに注意する。\n\
  s=     ここで指定した項目(複数項目指定可)で並べ替えられた後、f=で指定した項目の組み合わせを求める。\n\
  k=     キー項目名リスト(複数項目指定可)\n\
         組合せを求める単位となる項目名リスト。\n\
  -p     組合せでなく順列を求める。\n\
  -dup   同一の値の組み合せも出力する\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
customer項目を単位に、item項目の2アイテムの組み合わせを求め、\n\
item1,item2という項目名で出力する。\n\
k=,f=で指定していない項目(ここではitem項目)は、キーの最終行の値が出力される。\n\
\n\
    $ more dat1.csv\n\
    customer,item\n\
    A,a1\n\
    A,a2\n\
    A,a3\n\
    B,a4\n\
    B,a5\n\
    $ mcombi k=customer f=item n=2 a=item1,item2 i=dat1.csv o=rsl1.csv\n\
    #END# kgcombi a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,item,item1,item2\n\
    A,a3,a1,a2\n\
    A,a3,a1,a3\n\
    A,a3,a2,a3\n\
    B,a5,a4,a5\n\
\n\
例2: 基本例2\n\
\n\
-dupオプションを指定すると同一のアイテムの組み合せも出力される。\n\
\n\
    $ mcombi k=customer f=item n=2 a=item1,item2 i=dat1.csv o=rsl2.csv -dup\n\
    #END# kgcombi -dup a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer%0,item,item1,item2\n\
    A,a3,a1,a1\n\
    A,a3,a1,a2\n\
    A,a3,a1,a3\n\
    A,a3,a2,a2\n\
    A,a3,a2,a3\n\
    A,a3,a3,a3\n\
    B,a5,a4,a4\n\
    B,a5,a4,a5\n\
    B,a5,a5,a5\n\
\n\
例3: 順列を求める例\n\
\n\
customer項目を単位に、item項目の2アイテムの順列を求め、\n\
item1,item2という項目名で出力する。\n\
\n\
    $ mcombi k=customer f=item n=2 a=item1,item2 -p i=dat1.csv o=rsl3.csv\n\
    #END# kgcombi -p a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer%0,item,item1,item2\n\
    A,a3,a1,a2\n\
    A,a3,a2,a1\n\
    A,a3,a1,a3\n\
    A,a3,a3,a1\n\
    A,a3,a2,a3\n\
    A,a3,a3,a2\n\
    B,a5,a4,a5\n\
    B,a5,a5,a4\n\
\n\
例4: 順列を求める例\n\
\n\
item項目を降順に並べ替えた後、 item項目の2アイテムの順列を求める。\n\
\n\
    $ mcombi k=customer f=item n=2 s=item%r a=item1,item2 -p i=dat1.csv o=rsl4.csv\n\
    #END# kgcombi -p a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl4.csv s=item%r\n\
    $ more rsl4.csv\n\
    customer%0,item%1r,item1,item2\n\
    A,a1,a3,a2\n\
    A,a1,a2,a3\n\
    A,a1,a3,a1\n\
    A,a1,a1,a3\n\
    A,a1,a2,a1\n\
    A,a1,a1,a2\n\
    B,a4,a5,a4\n\
    B,a4,a4,a5\n\
";

