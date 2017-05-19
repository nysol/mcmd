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
/// kgsortfHelp.h : kgsortf help
// =============================================================================
_titleL="レコードの並べ換え";
_docL="\
\n\
MSORTF レコードの並べ換え\n\
\n\
f=パラメータで指定した項目を基準にして、レコードを並べ換える。\n\
ソーティングアルゴリズムはquick sortを利用しており、\n\
安定ソート(キーの値が同じ行については元の順序を保存する)にはならないことに注意する。\n\
出力CSVの項目名の後ろには、並び順情報として%で始まる文字列が付加される。\n\
書式は%優先順位[並び順]で、 詳細は以下、f=パラメータを参照のこと。\n\
\n\
書式\n\
\n\
msortf f= [pways=] [maxlines=] [blocks=] [threadCnt=] [-noflg] [i=] [o=]\n\
[-assert_diffSize] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=           レコードを並べ換える基準となる項目名リストを指定する。\n\
               並び順は、数値/文字列、昇順/降順の組み合せで4通り指定できる。\n\
               指定方法は%に続けてnとrを以下の通り組み合わせる。\n\
               文字列昇順:項目名(%指定なし)、文字列逆順:f=項目名%r、数値昇順:f=項目名%n、数値降順:f=項目名%nr。\n\
  -noflg       出力CSVのヘッダーにソーティングの印(%0,%0nなど)を付けない。\n\
  pways=       同時併合ファイル数([2-100]:デフォルト32)【任意】\n\
               分割ソートされた複数のファイルを同時に何個併合するかを指定する。\n\
  blocks=      バッファブロック数([1-1000]:デフォルト10)【任意】\n\
               メモリ内でソートする際のメモリサイズ上限をブロックサイズで指定する。\n\
               1ブロックは入力バッファサイズ×4で、デフォルトは4MB。\n\
  maxlines=    メモリソートレコード件数上限([100-1000万]:デフォルト50万)【任意】\n\
               メモリ内でソートする際の件数の上限を指定する。\n\
               データの一行あたりの平均サイズに応じて、 blocks=制限とmaxlines=制限のいずれかが使われる。\n\
  threadCnt=   メモリ内でソートを実行するthread数 ([1-50]:デフォルト8)【任意】\n\
               分割ソートする際に、マルチスレッドの機能を用いて同時にソートする数を指定する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
item、date順に並べ替える。\n\
\n\
    $ more dat1.csv\n\
    item,date,quantity,price\n\
    B,20081201,4,40\n\
    A,20081201,10,200\n\
    A,20081201,10,100\n\
    B,20081203,5,50\n\
    B,20081201,2,500\n\
    A,20081201,3,300\n\
    $ msortf f=item,date i=dat1.csv o=rsl1.csv\n\
    #END# kgsortf f=item,date i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    item%0,date%1,quantity,price\n\
    A,20081201,10,200\n\
    A,20081201,10,100\n\
    A,20081201,3,300\n\
    B,20081201,4,40\n\
    B,20081201,2,500\n\
    B,20081203,5,50\n\
\n\
例2: 数量(quantity)降順，金額(price)昇順に並べ替える例\n\
\n\
    $ msortf f=quantity%nr,price%n i=dat1.csv o=rsl2.csv\n\
    #END# kgsortf f=quantity%nr,price%n i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    item,date,quantity%0nr,price%1n\n\
    A,20081201,10,100\n\
    A,20081201,10,200\n\
    B,20081203,5,50\n\
    B,20081201,4,40\n\
    A,20081201,3,300\n\
    B,20081201,2,500\n\
";

