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
/// kgrjoinHelp.h : kgrjoin help
// =============================================================================
_titleL="参照ファイルの範囲条件による結合";
_docL="\
\n\
MRJOIN 参照ファイルの範囲条件による結合\n\
\n\
範囲により参照ファイルの項目を結合(join)する。\n\
r=パラメータで指定した項目値が、参照ファイル上にある範囲条件(項目値以上、次行の項目値未満)にマッチすればf=パラメータで指定した項目値を結合する。\n\
より複雑な範囲条件で結合したければmnrjoinを使う。\n\
範囲条件数が少なければmchgnumの利用を考えるとよい。\n\
\n\
書式\n\
\n\
mrjoin r= [k=] [K=] [R=] [f=] [-n] [-lo] [m=]  [i=] [o=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=    結合する参照ファイル上の項目名リスト(複数項目指定可)。\n\
        省略するとK=で指定された項目以外の項目を全て結合する。\n\
  m=    参照ファイル名を指定する。\n\
        このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  r=    範囲比較される項目名[%n]\n\
        入力ファイル上の項目名を指定する。\n\
        ここでここで指定した項目(複数項目指定可)で並べ替えられた後、結合が行われる。\n\
        %nが指定されると、数値範囲として解釈し、指定がなければ文字列範囲として解釈する。\n\
        ここで指定する項目にNULL値があってはならない。NULL値があった場合の動作は不定である。\n\
  R=    参照ファイル上の範囲項目名。\n\
        省略時はr=パラメータと同名として扱われる。\n\
  k=    入力データ上の突き合わせる項目名リスト(複数項目指定可)\n\
        ここで指定した入力データの項目とK=パラメータで指定された 参照データの項目が同じ行の項目結合が行われる。\n\
  K=    参照データ上の突き合わせる項目名リスト(複数項目指定可)\n\
        ここで指定した参照データの項目とk=パラメータで指定された 入力データの項目が同じ行の項目結合が行われる。\n\
        参照データ上にk=パラメータで指定した入力データ上の 項目と同名の項目が存在する場合は指定する必要はない。\n\
  -n    参照データにない入力データをNULL値として出力するフラグ。\n\
  -lo   left open interval\n\
        R= パラメータで指定した範囲を左半開区間（より大きい～以下）と解釈する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
priceを範囲で 分類項目low、middle、highを結合する。\n\
\n\
    $ more dat1.csv\n\
    price\n\
    8\n\
    15\n\
    35\n\
    50\n\
    90\n\
    200\n\
    $ more ref1.csv\n\
    range,category\n\
    10,low\n\
    35,middle\n\
    80,high\n\
    100,\n\
    $ mrjoin r=price%n m=ref1.csv R=range f=category i=dat1.csv o=rsl1.csv\n\
    #END# kgrjoin R=range f=category i=dat1.csv m=ref1.csv o=rsl1.csv r=price%n\n\
    $ more rsl1.csv\n\
    price%0n,category\n\
    15,low\n\
    35,middle\n\
    50,middle\n\
    90,high\n\
\n\
例2: 基本例2\n\
\n\
    $ mrjoin -lo r=price%n m=ref1.csv R=range f=category i=dat1.csv o=rsl2.csv\n\
    #END# kgrjoin -lo R=range f=category i=dat1.csv m=ref1.csv o=rsl2.csv r=price%n\n\
    $ more rsl2.csv\n\
    price%0n,category\n\
    15,low\n\
    35,low\n\
    50,middle\n\
    90,high\n\
\n\
例3: 基本例3\n\
\n\
    $ mrjoin -n r=price%n m=ref1.csv R=range f=category i=dat1.csv o=rsl3.csv\n\
    #END# kgrjoin -n R=range f=category i=dat1.csv m=ref1.csv o=rsl3.csv r=price%n\n\
    $ more rsl3.csv\n\
    price%0n,category\n\
    8,\n\
    15,low\n\
    35,middle\n\
    50,middle\n\
    90,high\n\
    200,\n\
\n\
例4: 商品別に異なる範囲を設定して結合\n\
\n\
    $ more dat2.csv\n\
    item,price\n\
    A,10\n\
    A,20\n\
    B,10\n\
    B,20\n\
    $ more ref2.csv\n\
    item,price,category\n\
    A,10,low\n\
    A,15,high\n\
    A,100,\n\
    B,10,low\n\
    B,35,high\n\
    B,100,\n\
    $ mrjoin k=item r=price%n m=ref2.csv f=category i=dat2.csv o=rsl4.csv\n\
    #END# kgrjoin f=category i=dat2.csv k=item m=ref2.csv o=rsl4.csv r=price%n\n\
    $ more rsl4.csv\n\
    item%0,price%1n,category\n\
    A,10,low\n\
    A,20,high\n\
    B,10,low\n\
    B,20,low\n\
";

