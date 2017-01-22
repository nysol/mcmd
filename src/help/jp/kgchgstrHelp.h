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
/// kgchgstrHelp.h : kgchgstr help
// =============================================================================
_titleL="文字列の置換";
_docL="\
\n\
MCHGSTR 文字列の置換\n\
\n\
f=パラメータで指定した項目について、\n\
c=パラメータで指定した置換条件で文字列を置換する。\n\
\n\
書式\n\
\n\
mchgstr c= f= [O=] [-A] [-F] [-sub] [-W]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  c=     置換対象となる文字列と置換文字列を指定する。\n\
  f=     ここで指定した項目(複数項目指定可)の文字列をc=パラメータで指定した置換条件リストに従って置換する。\n\
  O=     c=パラメータで指定した置換条件リストのいずれとも合致しない値を\n\
         置換するときの文字列(指定がなければNULL値となる)を指定する。\n\
  -A     このオプションにより、指定した項目を置き換えるのではなく、 新たに項目が追加される。\n\
  -F     c=パラメータで指定した置換条件リストのいずれとも合致しない値は、\n\
         その項目の値のまま出力する。\n\
  -sub   検索を完全一致ではなく部分文字列マッチで比較する\n\
         すなわち、f=パラメータで指定した項目の値に、\n\
         c=パラメータで指定した置換条件で文字列を置換する。\n\
  -W     -subオプションが指定されているときにワイド文字として部分文字列マッチをおこなう。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
itemの値が \"01\"を\"A\"に、 \"03\"を\"B\"に、 \"04\"を\"C\"に置換する。\n\
その他はNULL値として出力する。\n\
\n\
    $ more dat1.csv\n\
    id,item\n\
    1,01\n\
    2,02\n\
    3,03\n\
    4,04\n\
    5,05\n\
    $ mchgstr f=item c=01:A,03:B,05:C i=dat1.csv o=rsl1.csv\n\
    #END# kgchgstr c=01:A,03:B,05:C f=item i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,item\n\
    1,A\n\
    2,\n\
    3,B\n\
    4,\n\
    5,C\n\
\n\
例2: 条件に合致しない値を置換する文字列の指定\n\
\n\
O=パラメータを指定することで、\n\
置換条件に合致しない場合は\"out of range\"という文字列に置換して出力する。\n\
\n\
    $ mchgstr f=item c=01:A,03:B,05:C O=\"out of range\" i=dat1.csv o=rsl2.csv\n\
    #END# kgchgstr O=out of range c=01:A,03:B,05:C f=item i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,item\n\
    1,A\n\
    2,out of range\n\
    3,B\n\
    4,out of range\n\
    5,C\n\
\n\
例3: 新しい項目として出力\n\
\n\
-Aオプションを付けることで、新しい項目(item info)として出力する。\n\
\n\
    $ mchgstr f=item:\"item info\" c=01:A,03:B,05:C O=\"out of range\" -A i=dat1.csv o=rsl3.csv\n\
    #END# kgchgstr -A O=out of range c=01:A,03:B,05:C f=item:item info i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id,item,item info\n\
    1,01,A\n\
    2,02,out of range\n\
    3,03,B\n\
    4,04,out of range\n\
    5,05,C\n\
\n\
例4: 条件外を項目の値として出力\n\
\n\
-Fオプションを付けることで、\n\
置換条件に合致しない場合は、元の値をそのまま出力する。\n\
\n\
    $ mchgstr f=item c=01:A,03:B,05:C -F i=dat1.csv o=rsl4.csv\n\
    #END# kgchgstr -F c=01:A,03:B,05:C f=item i=dat1.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id,item\n\
    1,A\n\
    2,02\n\
    3,B\n\
    4,04\n\
    5,C\n\
\n\
例5: 条件を部分文字列マッチで置換\n\
\n\
-subオプションをつけることで、部分文字列の置換となる。\n\
以下の例では、item項目に文字列\"01\"が含まれていれば、それを\"A\"に置換する。\n\
\n\
    $ more dat2.csv\n\
    id,item\n\
    1,0111\n\
    2,0121\n\
    3,0231\n\
    4,0241\n\
    5,0151\n\
    $ mchgstr f=item c=01:A -sub i=dat2.csv o=rsl5.csv\n\
    #END# kgchgstr -sub c=01:A f=item i=dat2.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    id,item\n\
    1,A11\n\
    2,A21\n\
    3,\n\
    4,\n\
    5,A51\n\
\n\
例6: ワイド文字での部分文字列マッチ\n\
\n\
ワイド文字の部分文字列置換をする場合は-Wオプションを用いる。\n\
ただし、UTF-8エンコーディングを用いているのであれば-Wをつけなくても正しく動作する。\n\
詳しくは「マルチバイト文字」の節を参照されたい。\n\
\n\
    $ more dat3.csv\n\
    id,city\n\
    1,奈良市\n\
    2,下市町\n\
    3,十津川村\n\
    4,五條市\n\
    5,山添村\n\
    $ mchgstr f=city c=市:01,町:02,村:02 -sub -W i=dat3.csv o=rsl6.csv\n\
    #END# kgchgstr -W -sub c=市:01,町:02,村:02 f=city i=dat3.csv o=rsl6.csv\n\
    $ more rsl6.csv\n\
    id,city\n\
    1,奈良01\n\
    2,下0102\n\
    3,十津川02\n\
    4,五條01\n\
    5,山添02\n\
";

