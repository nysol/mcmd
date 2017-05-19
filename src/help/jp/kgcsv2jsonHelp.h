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
/// kgcsv2jsonHelp.h : kgcsv2json help
// =============================================================================
_titleL="CSVをJSON形式へ変換";
_docL="\
\n\
MCSV2JSON CSVをJSON形式へ変換\n\
\n\
CSVデータをJavaScriptのオブジェクト表記構文であるJSON形式に変換する。\n\
本コマンドは以下のような特徴を持つ。 詳細は例を参照のこと。\n\
\n\
-   JSON上のデータ型は文字列のみに対応\n\
\n\
-   配列とオブジェクト(key-valueのペア)による出力が可能\n\
\n\
-   キー項目を指定することで、配列の入れ子構造で出力可能\n\
\n\
書式\n\
\n\
mcsv2json [k=] [s=] f=|h=|p= -flat  i= [o=] [-assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   JSON上で配列をネストさせる項目名リスト。\n\
       3つの項目を指定すれば、3重のJSON配列となる。\n\
  s=   値を並べる順序項目。%n(数値順),%r(逆順)も指定可能。\n\
  f=   指定した項目の値をJSONの配列として出力する\n\
  h=   指定した項目名をキーにしたJSONオブジェクト(hash構造)として出力する。\n\
  p=   JSONオブジェクトのキーと値の項目名を2つ指定する。\n\
       2項目は次のようにコロンで区切る。p=key項目名1:value項目名1,key項目名2:value項目名2,...\n\
\n\
利用例\n\
\n\
例1: 配列として出力する例\n\
\n\
    $ more dat1.csv\n\
    key1,key2,v1,v2\n\
    A,X,1,a\n\
    A,Y,2,b\n\
    A,Y,3,c\n\
    B,X,4,d\n\
    B,Y,5,e\n\
    $ mcsv2json f=v1,v2 i=dat1.csv\n\
    [[\"1\",\"a\"],[\"2\",\"b\"],[\"3\",\"c\"],[\"4\",\"d\"],[\"5\",\"e\"]]\n\
    #END# kgcsv2json f=v1,v2 i=dat1.csv\n\
\n\
例2: オブジェクト(key-value)として出力する例\n\
\n\
    $ mcsv2json h=v1,v2 i=dat1.csv\n\
    [{\"v1\":\"1\",\"v2\":\"a\"},{\"v1\":\"2\",\"v2\":\"b\"},{\"v1\":\"3\",\"v2\":\"c\"},{\"v1\":\"4\",\"v2\":\"d\"},{\"v1\":\"5\",\"v2\":\"e\"}]\n\
    #END# kgcsv2json h=v1,v2 i=dat1.csv\n\
\n\
例3: 項目指定によってオブジェクトとして出力する例\n\
\n\
    $ mcsv2json p=v2:v1 i=dat1.csv\n\
    [{\"a\":\"1\"},{\"b\":\"2\"},{\"c\":\"3\"},{\"d\":\"4\"},{\"e\":\"5\"}]\n\
    #END# kgcsv2json i=dat1.csv p=v2:v1\n\
\n\
例4: キー項目を指定する例\n\
\n\
key1項目がAの3行が一つの配列として出力され、\n\
続いてkey1=Bの2行が一つの配列として出力される。\n\
\n\
    $ mcsv2json k=key1 f=v1 i=dat1.csv\n\
    [[[\"1\"],[\"2\"],[\"3\"]],\n\
    [[\"4\"],[\"5\"]]]\n\
    #END# kgcsv2json f=v1 i=dat1.csv k=key1\n\
\n\
例5: キー項目のネスト例\n\
\n\
key1=Aかつkey2=Xの1行が一つの配列として出力され、\n\
key1=Aかつkey2=Yの2行が一つの配列として出力され、\n\
それら2つの配列(すなわちkey1=Aの行)がさらに一つの配列として括られる。\n\
\n\
    $ mcsv2json k=key1,key2 f=v1 i=dat1.csv\n\
    [[[[\"1\"]],\n\
    [[\"2\"],[\"3\"]]],\n\
    [[[\"4\"]],\n\
    [[\"5\"]]]]\n\
    #END# kgcsv2json f=v1 i=dat1.csv k=key1,key2\n\
\n\
例6: 行を配列で括らずにフラットに出力する例\n\
\n\
    $ mcsv2json f=v1,v2 -flat i=dat1.csv\n\
    [\"1\",\"a\",\"2\",\"b\",\"3\",\"c\",\"4\",\"d\",\"5\",\"e\"]\n\
    #END# kgcsv2json -flat f=v1,v2 i=dat1.csv\n\
";

