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
/// kgtab2csvHelp.h : kgtab2csv help
// =============================================================================
_titleL="TSVからCSVデータへの変換";
_docL="\
\n\
MTAB2CSV TSVからCSVデータへの変換\n\
\n\
タブ区切りデータをCSVデータへ変換する。\n\
d=で区切り文字を指定することで、タブ以外の区切り文字のテキストファイルも\n\
変換することが可能である。\n\
変換後の項目数に違いある場合には、その直前行まで出力され、\n\
その後エラー終了する。\n\
\n\
書式\n\
\n\
mtab2csv [d=] [-r]  [i=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  d=   区切り文字の指定(１バイト文字のみ指定可)。\n\
  -r   改行コード(CR:\\r)を取り除く。\n\
       MCMDが扱うCSVは改行コードがLF(\\n)固定であるため、\n\
       Windowsのテキスト改行CR+LF(\\r\\n)やMacのテキスト改行CR(\\r)があれば、\n\
       単なる文字列として扱ってしまい、変換後に不具合が生じる。\n\
       この問題を回避するためのオプションである。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
タブ区切りデータをcsvへ変換\n\
\n\
    $ more dat1.tab\n\
    id	data	data2\n\
    A	1102	a\n\
    A	2203	aaa\n\
    B	1155	bbbb\n\
    B	3104	c\n\
    B	1206	de\n\
    $ mtab2csv i=dat1.tab o=rsl1.csv\n\
    #END# kgtab2csv i=dat1.tab o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,data,data2\n\
    A,1102,a\n\
    A,2203,aaa\n\
    B,1155,bbbb\n\
    B,3104,c\n\
    B,1206,de\n\
\n\
例2: d=指定\n\
\n\
d=を使用してtab以外の区切り文字を使う\n\
\n\
    $ more dat2.bar\n\
    id-data-data2\n\
    A-1102-a\n\
    A-2203-aaa\n\
    B-1155-bbbb\n\
    B-3104-c\n\
    B-1206-de\n\
    $ mtab2csv d=- i=dat2.bar o=rsl2.csv\n\
    #END# kgtab2csv d=- i=dat2.bar o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,data,data2\n\
    A,1102,a\n\
    A,2203,aaa\n\
    B,1155,bbbb\n\
    B,3104,c\n\
    B,1206,de\n\
";

