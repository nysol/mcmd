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
/// kgtraHelp.h : kgtra help
// =============================================================================
_titleL="縦型データをベクトル項目に変換";
_docL="\
\n\
MTRA 縦型データをベクトル項目に変換\n\
\n\
f=パラメータで指定した項目値をアイテムとし、それらのアイテムを連結し新しいベクトル項目(トランザクション項目とも呼ぶ)として出力する。\n\
アイテムの区切り文字はdelim=パラメータで指定する。\n\
\n\
書式\n\
\n\
mtra f= [s=] [k=] [delim=] [-r]   [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=       ここで指定した項目(複数項目指定可)の値がアイテムとして連結されトランザクション項目となる。\n\
           NULL値は無視される。\n\
  s=       ここで指定した項目(複数項目指定可)で並べ替えられた後、変換が行われる。\n\
  k=       文字列パターンの単位となる項目名(複数項目指定可)リスト。\n\
           -rオプションが指定された時は指定できない。\n\
  delim=   ここで指定した文字を区切り文字とする（省略時はスペース）。\n\
  -r       条件反転\n\
           トランザクション項目を縦型データに変換する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
customerを単位にitemをスペース区切りで結合し、\n\
transactionという項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    customer,item\n\
    A,a\n\
    A,b\n\
    B,c\n\
    B,d\n\
    B,e\n\
    $ mtra k=customer f=item:transaction i=dat1.csv o=rsl1.csv\n\
    #END# kgtra f=item:transaction i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,transaction\n\
    A,a b\n\
    B,c d e\n\
\n\
例2: アイテムの区切り文字を-(ハイフン）で実行\n\
\n\
    $ mtra k=customer f=item:transaction delim=- i=dat1.csv o=rsl2.csv\n\
    #END# kgtra delim=- f=item:transaction i=dat1.csv k=customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer%0,transaction\n\
    A,a-b\n\
    B,c-d-e\n\
\n\
例3: アイテムを降順に並べ替えてから変換\n\
\n\
    $ mtra k=customer s=item%r f=item:transaction i=dat1.csv o=rsl3.csv\n\
    #END# kgtra f=item:transaction i=dat1.csv k=customer o=rsl3.csv s=item%r\n\
    $ more rsl3.csv\n\
    customer%0,transaction\n\
    A,b a\n\
    B,e d c\n\
";

