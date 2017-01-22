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
/// kgselHelp.h : kgsel help
// =============================================================================
_titleL="条件式による行選択";
_docL="\
\n\
MSEL 条件式による行選択\n\
\n\
c=パラメータで指定した計算式で計算をおこない、結果が真であれば、その行を選択する。\n\
なおmcalと同じ計算式が利用できるので、詳細はmcalを参照されたい。\n\
\n\
書式\n\
\n\
msel c=  [u=] [-r] [i=] [o=] [-assert_diffSize] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  c=   用意された関数を組み合わせて計算する式を指定する。\n\
       詳細はmcalを参照。\n\
  o=   指定の条件に一致する行を出力するファイル名を指定する。\n\
  u=   指定の条件に一致しない行を出力するファイル名を指定する。\n\
  -r   条件反転\n\
       選択ではなく削除する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「金額」項目の値が40より大きい行を選択する。\n\
それ以外のデータはunmatch1.csvに出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,30\n\
    B,3,40\n\
    B,1,50\n\
    $ msel c='${金額}>40' u=unmatch1.csv i=dat1.csv o=match1.csv\n\
    #END# kgsel c=${金額}>40 i=dat1.csv o=match1.csv u=unmatch1.csv\n\
    $ more match1.csv\n\
    顧客,数量,金額\n\
    B,1,50\n\
    $ more unmatch1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,30\n\
    B,3,40\n\
\n\
例2: NULL値の選択規制\n\
\n\
mselコマンドではc=で与えられた式を評価した結果がNULL値の場合その行は選択されない。\n\
また、アンマッチ出力ファイルがu=によって指定されていれば、そのファイルに出力される。\n\
以下の例では項目bに-1、NULL値、1を持つ3行のデータについて、0より大きい行を選択しているが、\n\
NULL値を含む行はアンマッチ出力ファイルへと出力される。\n\
\n\
    $ more dat2.csv\n\
    a,b\n\
    A,-1\n\
    B,\n\
    C,1\n\
    $ msel c='${b}>0' i=dat2.csv o=match2.csv u=unmatch2.csv\n\
    #END# kgsel c=${b}>0 i=dat2.csv o=match2.csv u=unmatch2.csv\n\
    $ more match2.csv\n\
    a,b\n\
    C,1\n\
    $ more unmatch2.csv\n\
    a,b\n\
    A,-1\n\
    B,\n\
\n\
例3: -rオプション指定\n\
\n\
真偽は逆転するがNULL値の評価に変わりはない。\n\
すなわちNULL値の行は選択されない。\n\
以下の例では、上の例と同様のデータおよび選択条件で-rをつけている。\n\
真偽の選択条件は逆転しているが、NULL値を含む行は上記の例と同様にアンマッチファイルへと出力されていることがわかる。\n\
\n\
    $ msel -r c='${b}>0' i=dat2.csv o=match3.csv u=unmatch3.csv\n\
    #END# kgsel -r c=${b}>0 i=dat2.csv o=match3.csv u=unmatch3.csv\n\
    $ more match3.csv\n\
    a,b\n\
    A,-1\n\
    $ more unmatch3.csv\n\
    a,b\n\
    B,\n\
    C,1\n\
";

