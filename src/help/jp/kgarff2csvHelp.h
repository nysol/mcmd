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
/// kgarff2csvHelp.h : kgarff2csv help
// =============================================================================
_titleL="ARFF形式からCSV形式への変換";
_docL="\
\n\
MARFF2CSV ARFF形式からCSV形式への変換\n\
\n\
arff形式(WEKA用のデータフォーマット)のデータからcsv形式のデータへ変換する。\n\
\n\
arff形式データ\n\
\n\
以下arff形式データのフォーマットを記載する。\n\
\n\
    @RELATION       タイトル\n\
\n\
    @ATTRIBUTE      項目名    string(文字列)\n\
    @ATTRIBUTE      項目名    date(日時 フォーマット:フォーマットは省略可能。\n\
                                    省略した場合は、\"yyyy-MM-dd'T'HH:mm:ss\"）\n\
    @ATTRIBUTE      数量    numeric(数字)\n\
    @ATTRIBUTE      商品    {A,B}(カテゴリ型項目)\n\
\n\
    @DATA(実データ)\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
\n\
書式\n\
\n\
marff2csv [i=] [o=] [-assert_nullout] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
arff形式の顧客購買データをcsv形式のデータへ変換する。\n\
\n\
    $ more dat1.arff\n\
    @RELATION       顧客購買データ\n\
\n\
    @ATTRIBUTE      顧客    string\n\
    @ATTRIBUTE      日付    date yyyyMMdd\n\
    @ATTRIBUTE      数量    numeric\n\
    @ATTRIBUTE      金額    numeric\n\
    @ATTRIBUTE      商品    {A,B}\n\
\n\
    @DATA\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
    $ marff2csv i=dat1.arff  o=rsl1.csv\n\
    #END# kgarff2csv i=dat1.arff o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客,日付,数量,金額,商品\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
";

