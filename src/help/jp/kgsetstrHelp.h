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
/// kgsetstrHelp.h : kgsetstr help
// =============================================================================
_titleL="文字列項目の追加";
_docL="\
\n\
MSETSTR 文字列項目の追加\n\
\n\
指定した文字列を項目として全行に追加する。複数項目の追加も可能。\n\
\n\
書式\n\
\n\
msetstr v= a=  [i=] [o=] [-assert_diffSize] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  v=   追加する文字列リスト。\n\
       値を何も指定しないとNULL値が追加される。\n\
  a=   追加する項目名。\n\
       v=で指定した文字列の個数と同数の項目名を指定しなければならない。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
日付計算で必要となる基準日を(2007年01月01日と定義した場合)すべての行に「20070101」という文字列を追加し「基準日」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,日付\n\
    A,20081202\n\
    A,20081204\n\
    B,20081203\n\
    $ msetstr v=20070101 a=基準日 i=dat1.csv o=rsl1.csv\n\
    #END# kgsetstr a=基準日 i=dat1.csv o=rsl1.csv v=20070101\n\
    $ more rsl1.csv\n\
    顧客,日付,基準日\n\
    A,20081202,20070101\n\
    A,20081204,20070101\n\
    B,20081203,20070101\n\
\n\
例2: 複数項目を追加\n\
\n\
    $ msetstr v=20070101,20070201 a=基準日1,基準日2 i=dat1.csv o=rsl2.csv\n\
    #END# kgsetstr a=基準日1,基準日2 i=dat1.csv o=rsl2.csv v=20070101,20070201\n\
    $ more rsl2.csv\n\
    顧客,日付,基準日1,基準日2\n\
    A,20081202,20070101,20070201\n\
    A,20081204,20070101,20070201\n\
    B,20081203,20070101,20070201\n\
\n\
例3: null値項目追加\n\
\n\
    $ msetstr v= a=追加項目 i=dat1.csv o=rsl3.csv\n\
    #END# kgsetstr a=追加項目 i=dat1.csv o=rsl3.csv v=\n\
    $ more rsl3.csv\n\
    顧客,日付,追加項目\n\
    A,20081202,\n\
    A,20081204,\n\
    B,20081203,\n\
";

