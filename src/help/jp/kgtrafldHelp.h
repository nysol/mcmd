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
/// kgtrafldHelp.h : kgtrafld help
// =============================================================================
_titleL="クロス表をトランザクション項目に変換";
_docL="\
\n\
MTRAFLD クロス表をトランザクション項目に変換\n\
\n\
f=で指定した項目値とその値のペアのアイテムを作成し、\n\
それらのアイテムを連結し新しいベクトル項目(トランザクション項目とも呼ぶ)として出力する。\n\
\n\
書式\n\
\n\
mtrafld a= [f=] [delim=] [delim2=] [-r] [-valOnly]  [i=] [o=]\n\
[-assert_diffSize] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno]\n\
[-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=         トランザクション項目名を指定する。\n\
  f=         項目名リスト(複数項目指定可)【-r指定時必須、それ以外は任意】\n\
             ここで指定された項目名と値とを連結したアイテムを作成し\n\
             トランザクション項目として出力される。\n\
             -rオプションの指定がある時は\n\
             トランザクションデータから抜き出す項目名を指定する。\n\
             -rオプションが指定されたとき，このパラメータは省略可能である。\n\
             省略すると、全ての項目名と値ペアを処理対象とする。\n\
             ただし、f=パラメータを省略すると標準入力(パイプ入力)は利用できない。\n\
  delim=     トランザクション項目のアイテムを区切る文字を指定する(省略時はスペース)。\n\
  delim2=    項目名と値ペアとを区切る文字を指定する(省略時は=)。\n\
  -r         条件反転\n\
             トランザクション項目をクロス表に変換する。\n\
  -valOnly   このオプションが指定されると、アイテムとして「項目名=」は出力しない。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
priceとquantity項目を1つの文字列として連結し、\n\
transactionという項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,325,2\n\
    C,200,3\n\
    D,450,2\n\
    E,100,1\n\
    $ mtrafld a=transaction f=price,quantity i=dat1.csv o=rsl1.csv\n\
    #END# kgtrafld a=transaction f=price,quantity i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,transaction\n\
    A,price=198 quantity=1\n\
    B,price=325 quantity=2\n\
    C,price=200 quantity=3\n\
    D,price=450 quantity=2\n\
    E,price=100 quantity=1\n\
\n\
例2: 基本例2\n\
\n\
出力された結果を-rをつけて再実行し元に戻す。\n\
\n\
    $ mtrafld -r a=transaction f=price,quantity i=rsl1.csv o=rsl2.csv\n\
    #END# kgtrafld -r a=transaction f=price,quantity i=rsl1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,325,2\n\
    C,200,3\n\
    D,450,2\n\
    E,100,1\n\
\n\
例3: 区切り文字の指定\n\
\n\
priceと数量quantity項目を_(アンダーバー）で区切り1つの文字列として連結し、\n\
項目名とデータは：（コロン）で区切りtransactionという項目名で出力する。\n\
\n\
    $ mtrafld a=transaction f=price,quantity delim=_ delim2=':' i=dat1.csv o=rsl3.csv\n\
    #END# kgtrafld a=transaction delim2=: delim=_ f=price,quantity i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer,transaction\n\
    A,price:198_quantity:1\n\
    B,price:325_quantity:2\n\
    C,price:200_quantity:3\n\
    D,price:450_quantity:2\n\
    E,price:100_quantity:1\n\
\n\
例4: NULL値を含む場合\n\
\n\
    $ more dat2.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,,2\n\
    C,200,\n\
    D,450,2\n\
    E,,\n\
    $ mtrafld a=transaction f=price,quantity i=dat2.csv o=rsl4.csv\n\
    #END# kgtrafld a=transaction f=price,quantity i=dat2.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    customer,transaction\n\
    A,price=198 quantity=1\n\
    B,quantity=2\n\
    C,price=200\n\
    D,price=450 quantity=2\n\
    E,\n\
\n\
例5: NULL値を含む場合2\n\
\n\
出力された結果を-rをつけて再実行し元に戻す。\n\
\n\
    $ mtrafld -r a=transaction f=price,quantity i=rsl4.csv o=rsl5.csv\n\
    #END# kgtrafld -r a=transaction f=price,quantity i=rsl4.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,,2\n\
    C,200,\n\
    D,450,2\n\
    E,,\n\
\n\
例6: -valOnlyの指定\n\
\n\
    $ mtrafld -valOnly f=price,quantity a=transaction i=dat2.csv o=rsl6.csv\n\
    #END# kgtrafld -valOnly a=transaction f=price,quantity i=dat2.csv o=rsl6.csv\n\
    $ more rsl6.csv\n\
    customer,transaction\n\
    A,198 1\n\
    B,2\n\
    C,200\n\
    D,450 2\n\
    E,\n\
";

