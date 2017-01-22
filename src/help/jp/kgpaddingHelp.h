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
/// kgpaddingHelp.h : kgpadding help
// =============================================================================
_titleL="(行補完)";
_docL="\
\n\
MPADDING (行補完) コマンド\n\
\n\
k=パラメータで指定した項目をキーとして、f=パラメータで指定した項目の値が連続するようにレコードを作成する。v=パラメータを指定した場合は、k=,f=で指定した以外の項目値を指定した文字列でパディングし、-nオプション指定時は、nullでパディングする。(v=,-n共に指定がなければ直前の項目値でパディングする)\n\
\n\
書式\n\
\n\
mpadding [k=] f= [v=] [S=] [E=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   ここで指定された項目をキーとする。\n\
  f=   連続パディング対象項目名\n\
       ここで指定された項目の値が連続するようにレコードをパディングする。\n\
       数字としてパディングするときは、no%nのように%nを指定する。\n\
       日付としてパディングするときは%d、時刻としてパディングするときは%tを指定する。\n\
       降順でパディングしたいときはno%d%rのようにrを追加する。\n\
  v=   パディング用文字列指定\n\
       k=,f=で指定した以外の項目値を指定した文字列で出力する。\n\
  S=   開始値\n\
       f=で指定した項目の値の開始値を指定する。\n\
  E=   終了値\n\
       f=で指定した項目の値の終了値を指定する。\n\
  -n   パディングにnull値指定\n\
       k=,f=で指定した以外の項目値をnullで出力する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
no項目が整数(%n)として連続するようにレコードをパディングする。\n\
1とverb|4|の間に2,3を、4と2の間に3が挿入されている。\n\
\n\
    $ more dat1.csv\n\
    no\n\
    3\n\
    6\n\
    8\n\
    $ mpadding f=no%n i=dat1.csv o=rsl1.csv\n\
    #END# kgpadding f=no%n i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    no%0n\n\
    3\n\
    4\n\
    5\n\
    6\n\
    7\n\
    8\n\
\n\
例2: 開始値、終了値の指定\n\
\n\
行間のパディングだけでなく、先頭行/終端行の前後もパディングする。\n\
前後の範囲はS=,E=で指定する。\n\
\n\
    $ mpadding f=no%n S=1 E=10 i=dat1.csv o=rsl2.csv\n\
    #END# kgpadding E=10 S=1 f=no%n i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    no%0n\n\
    1\n\
    2\n\
    3\n\
    4\n\
    5\n\
    6\n\
    7\n\
    8\n\
    9\n\
    10\n\
\n\
例3: 日付パディング\n\
\n\
date項目が日付(%d)として連続するようにレコードをパディングする。\n\
k=,f=で指定した以外の項目は、直前の行の項目値でパディングする。\n\
\n\
    $ more dat2.csv\n\
    date,dummy\n\
    20130929,a\n\
    20131002,b\n\
    20131004,c\n\
    $ mpadding f=date%d i=dat2.csv o=rsl3.csv\n\
    #END# kgpadding f=date%d i=dat2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    date%0,dummy\n\
    20130929,a\n\
    20130930,a\n\
    20131001,a\n\
    20131002,b\n\
    20131003,b\n\
    20131004,c\n\
\n\
例4: パディング用文字列指定\n\
\n\
v=にてパディング文字列を指定することもできる。\n\
\n\
    $ mpadding f=date%d v=padding i=dat2.csv o=rsl4.csv\n\
    #END# kgpadding f=date%d i=dat2.csv o=rsl4.csv v=padding\n\
    $ more rsl4.csv\n\
    date%0,dummy\n\
    20130929,a\n\
    20130930,padding\n\
    20131001,padding\n\
    20131002,b\n\
    20131003,padding\n\
    20131004,c\n\
\n\
例5: パディングにNULL値を指定\n\
\n\
-nを指定してNULL値でパディングすることも可能。\n\
\n\
    $ mpadding f=date%d -n i=dat2.csv o=rsl5.csv\n\
    #END# kgpadding -n f=date%d i=dat2.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    date%0,dummy\n\
    20130929,a\n\
    20130930,\n\
    20131001,\n\
    20131002,b\n\
    20131003,\n\
    20131004,c\n\
";

