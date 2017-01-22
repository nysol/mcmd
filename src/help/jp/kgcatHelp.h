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
/// kgcatHelp.h : kgcat help
// =============================================================================
_titleL="併合";
_docL="\
\n\
MCAT 併合\n\
\n\
i=パラメータで指定した全ファイルのレコードを、指定した順に併合する。\n\
ワイルドカードでファイル名を指定した場合は、ファイル名のアルファベット順に併合される。\n\
\n\
書式\n\
\n\
mcat [f=] [-skip_fnf] [-nostop|-skip|-force] [i=] [o=] [-stdin]\n\
[-assert_diffSize] [-assert_nullin] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  i=           入力ファイル名リストを指定する。\n\
               複数のファイルをカンマで区切って指定する。ワイルドカードを用いることができる。\n\
  f=           併合する項目名を指定する。\n\
               指定を省略すればi=で指定した1つ目のファイルの項目名が使われる。\n\
  -skip_fnf    i=で指定したファイルが存在しなくてもエラー終了しない。\n\
               ただし、全ファイルがなければエラーとなる。\n\
  -nostop      -nostop ,-skip,-forceは、指定の項目名がなかったときの動作を制御するフラグである。\n\
               -nostopは、指定の項目名がなければnullを出力する。\n\
               -nfnが同時に指定された場合，項目数が異なればエラー終了する。\n\
  -skip        指定の項目名がなければそのファイルは併合しない。\n\
               -nfnが同時に指定された場合、項目数が異なればそのファイルは併合しない。\n\
  -force       指定の項目名がなければ，項目番号で強制併合する。\n\
               指定の項目番号がなければnullを出力する。\n\
  -stdin       標準入力も併合する。\n\
  -add_fname   併合元のファイル名を最終項目として追加する。\n\
               標準入力は/dev/stdinという名称になる。\n\
               項目名は\"fileName\"固定なので、入力データに同一の項目名があるとエラーとなる。\n\
\n\
利用例\n\
\n\
例1: 同一項目名ファイルの併合\n\
\n\
    $ more dat1.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    $ mcat i=dat1.csv,dat2.csv o=rsl1.csv\n\
    #END# kgcat i=dat1.csv,dat2.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
\n\
例2: 項目名の異なるファイルの併合\n\
\n\
i=の最初のファイルdat1.csvの項目「顧客,日付,金額」の3項目を併合する。\n\
しかし、dat3.csvには「金額」項目がないので、エラーとなる。\n\
ただし、dat1.csvの内容は既に出力されていることに注意する。\n\
\n\
    $ more dat3.csv\n\
    顧客,日付,数量\n\
    A,20081201,3\n\
    B,20081002,1\n\
    $ mcat i=dat1.csv,dat3.csv o=rsl2.csv\n\
    #ERROR# field name [金額] not found on file [dat3.csv] (kgcat)\n\
    $ more rsl2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
\n\
例3: 項目名の異なるファイルの併合2\n\
\n\
前例に-nostopオプションを付けると、項目が見つからないデータについてはNULL値を出力するようになり、\n\
途中でエラー終了することはなくなる。\n\
その他にも、項目が見つからなかった場合の動作を変更するオプションとして、skip,forceがある。\n\
詳しくはパラメータの説明を参照されたい。\n\
\n\
    $ more dat3.csv\n\
    顧客,日付,数量\n\
    A,20081201,3\n\
    B,20081002,1\n\
    $ mcat -nostop i=dat1.csv,dat3.csv o=rsl3.csv\n\
    #END# kgcat -nostop i=dat1.csv,dat3.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081201,\n\
    B,20081002,\n\
\n\
例4: 項目名を指定して併合\n\
\n\
f=で項目名を指定すると、それら指定した項目のみを併合する。\n\
\n\
    $ mcat f=顧客,日付 i=dat2.csv,dat3.csv o=rsl4.csv\n\
    #END# kgcat f=顧客,日付 i=dat2.csv,dat3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    顧客,日付\n\
    A,20081207\n\
    A,20081213\n\
    B,20081209\n\
    A,20081201\n\
    B,20081002\n\
\n\
例5: 標準入力の併合\n\
\n\
-stdinを指定することで、dat2.csvを標準入力から追加する。\n\
\n\
    $ mcat -stdin i=dat1.csv o=rsl5.csv <dat2.csv\n\
    #END# kgcat -stdin i=dat1.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    顧客,日付,金額\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    A,20081201,10\n\
    B,20081002,40\n\
\n\
例6: ファイル名項目を追加\n\
\n\
-add_fnameを指定すると、元ファイルの名前をfileName項目で追加する。\n\
標準入力のファイル名は/dev/stdinとなる。\n\
\n\
    $ mcat -add_fname -stdin i=dat1.csv o=rsl6.csv <dat2.csv\n\
    #END# kgcat -add_fname -stdin i=dat1.csv o=rsl6.csv\n\
    $ more rsl6.csv\n\
    顧客,日付,金額,fileName\n\
    A,20081207,20,/dev/stdin\n\
    A,20081213,30,/dev/stdin\n\
    B,20081209,50,/dev/stdin\n\
    A,20081201,10,dat1.csv\n\
    B,20081002,40,dat1.csv\n\
\n\
例7: ワイルドカード指定\n\
\n\
カレントディレクトリにdat1.csv,dat2.csv,dat3.csvの3つのCSVファイルがあったとして、\n\
それらを全て併合するのにワイルドカードdat*.csvを指定する。\n\
\n\
    $ more dat1.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    $ more dat3.csv\n\
    顧客,日付,数量\n\
    A,20081201,3\n\
    B,20081002,1\n\
    $ mcat -force i=dat*.csv o=rsl7.csv\n\
    #END# kgcat -force i=dat*.csv o=rsl7.csv\n\
    $ more rsl7.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    A,20081201,3\n\
    B,20081002,1\n\
\n\
例8: 同一ファイルの複数回併合\n\
\n\
同一ファイルを複数指定することも可能である。\n\
\n\
    $ mcat i=dat1.csv,dat1.csv,dat1.csv o=rsl8.csv\n\
    #END# kgcat i=dat1.csv,dat1.csv,dat1.csv o=rsl8.csv\n\
    $ more rsl8.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081201,10\n\
    B,20081002,40\n\
";

