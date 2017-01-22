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
/// kgtraflgHelp.h : kgtraflg help
// =============================================================================
_titleL="クロス表をトランザクション項目に変換";
_docL="\
\n\
MTRAFLG クロス表をトランザクション項目に変換\n\
\n\
f=パラメータで指定した項目値がNULL値かどうかをチェックし、\n\
NULL値以外であれば，それらの項目名を1つのアイテムとして連結し\n\
新しいベクトル項目(トランザクション項目とも呼ぶ)として出力する。\n\
\n\
書式\n\
\n\
mtraflg a= f= [delim=] [-r]   [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=       トランザクション項目名を指定する。\n\
  f=       ここで指定された項目値(複数項目指定可)をチェックし、トランザクションデータを作成する。\n\
           (-rオプションの指定がある時はトランザクションデータから項目名として抜き出す値のリスト)\n\
  delim=   ここで指定した文字をトランザクション項目のアイテム間の区切りとする（省略時はスペース）。\n\
           文字列の指定はできない。1バイト文字のみ指定可能。\n\
  -r       条件反転\n\
           トランザクション型から縦型へデータを変換する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
eggとmilk項目の値がNULL値以外なら、それら項目名を要素としたベクトルを作成する。\n\
\n\
    $ more dat1.csv\n\
    customer,egg,milk\n\
    A,1,1\n\
    B,,1\n\
    C,1,\n\
    D,1,1\n\
    $ mtraflg f=egg,milk a=transaction i=dat1.csv o=rsl1.csv\n\
    #END# kgtraflg a=transaction f=egg,milk i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,transaction\n\
    A,egg milk\n\
    B,milk\n\
    C,egg\n\
    D,egg milk\n\
\n\
例2: 基本例2\n\
\n\
出力された結果を-rをつけて再実行し元に戻す。\n\
\n\
    $ mtraflg -r f=egg,milk a=transaction i=rsl1.csv o=rsl2.csv\n\
    #END# kgtraflg -r a=transaction f=egg,milk i=rsl1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer,egg,milk\n\
    A,1,1\n\
    B,,1\n\
    C,1,\n\
    D,1,1\n\
\n\
例3: 区切り文字の指定\n\
\n\
区切り文字を-(ハイフン）で連結し、transactionという項目名で出力する。\n\
\n\
    $ mtraflg f=egg,milk a=transaction delim=- i=dat1.csv o=rsl3.csv\n\
    #END# kgtraflg a=transaction delim=- f=egg,milk i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer,transaction\n\
    A,egg-milk\n\
    B,milk\n\
    C,egg\n\
    D,egg-milk\n\
";

