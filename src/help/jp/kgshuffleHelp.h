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
/// kgshuffleHelp.h : kgshuffle help
// =============================================================================
_titleL="レコード分割";
_docL="\
\n\
MSHUFFLE レコード分割\n\
\n\
f=で指定した項目のhash値に従って指定した数のファイルに入力ファイルを分割する。\n\
分割数(hashサイズ)をnとすると、f=で指定した「項目の値」vのhash値は\n\
nの剰余(v mod n)として計算される。\n\
「項目の値」は、データを文字列として考え、バイト単位の文字コードの合計値として計算される。\n\
f=を指定しなかった場合は、「項目の値」として行番号が用いられる。\n\
そして、各行は、得られたhash値を名前に持ったファイルに出力される。\n\
以上の方法により、同じ項目データを持つ行は全て同一のファイルに出力されることが保証される。\n\
\n\
また、v=で重みを指定することで、分割される各ファイルに複数のhash値を割り当てることもできる。\n\
n=3,v=2,1,3と指定すれば、hashサイズを重みの合計2 + 1 + 3 = 6とし、\n\
2つのhash値(0,1)を分割ファイル0に、1つのhash値(2)を分割ファイル1に、\n\
そして3つのhash値(3,4,5)を分割ファイル2に出力する。\n\
重みはhash値の割当数の重みであり、出力行数の重みではないことに注意する。\n\
\n\
書式\n\
\n\
mshuffle n=|v= d= [f=] [i=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  d=   出力するファイル名の接頭辞を指定する\n\
       ここで指定した値＋連番(hash値)が実際に出力されるファイル名になる\n\
  f=   分割単位となるキーを指定する\n\
       ここで指定した項目値が等しいものは同じファイルに出力される\n\
  n=   分割するファイル数を指定する\n\
  v=   分割するファイルごとにデータ量の重みを指定する\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
指定した項目の値(顧客)が同じであれば同一のファイルに出力にされるように2つのファイルに分割する\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ mshuffle f=顧客 d=./dat/d n=2 i=dat2.csv\n\
    #END# kgshuffle d=./dat/d f=顧客 i=dat2.csv n=2\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,日付,金額\n\
    B,20081002,40\n\
    B,20081209,50\n\
    $ more ./dat/d_1\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    C,20081003,60\n\
    C,20081219,20\n\
\n\
例2: f=を指定しない例\n\
\n\
f=を指定せず2つのファイルに分割する。\n\
行番号のhash値を用いるので、2つのファイルの行数はほぼ等しくなる。\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ mshuffle d=./dat/d n=2 i=dat2.csv\n\
    #END# kgshuffle d=./dat/d i=dat2.csv n=2\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,日付,金額\n\
    A,20081207,20\n\
    B,20081002,40\n\
    C,20081003,60\n\
    $ more ./dat/d_1\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081213,30\n\
    B,20081209,50\n\
    C,20081219,20\n\
\n\
例3: v=,f=の指定\n\
\n\
v=2,1を指定することで、ファイル0(d_0)には2つのhash値を割り当て、\n\
ファイル1(d_1)には1つのhash値を割り当てて分割する。\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ mshuffle f=顧客 d=./dat/d v=2,1 i=dat2.csv\n\
    #END# kgshuffle d=./dat/d f=顧客 i=dat2.csv v=2,1\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,日付,金額\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ more ./dat/d_1\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
\n\
例4: v=の指定\n\
\n\
例3をf=の指定なしで実行する。\n\
行番号のhash値を用いるので、この場合は出力行数の比と重みの比がほぼ等しくなる。\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ mshuffle d=./dat/d v=2,1 i=dat2.csv\n\
    #END# kgshuffle d=./dat/d i=dat2.csv v=2,1\n\
    $ ls ./dat\n\
    d_0\n\
    d_1\n\
    $ more ./dat/d_0\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081213,30\n\
    B,20081002,40\n\
    C,20081003,60\n\
    C,20081219,20\n\
    $ more ./dat/d_1\n\
    顧客,日付,金額\n\
    A,20081207,20\n\
    B,20081209,50\n\
";

