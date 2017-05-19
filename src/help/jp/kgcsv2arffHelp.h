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
/// kgcsv2arffHelp.h : kgcsv2arff help
// =============================================================================
_titleL="CSVをARFF形式に変換";
_docL="\
\n\
MCSV2ARFF CSVをARFF形式に変換\n\
\n\
csv形式のデータからarff形式(WEKA用のデータフォーマット)のデータへ変換する。\n\
arffでは、属性の型を指定する必要があり、\n\
d=でカテゴリ型項目を、n=で数値型項目を、s=で文字列型項目を、\n\
そしてD=で日付型項目をそれぞれ指定する。\n\
日付型項目名に%tを付ければ時刻を含んだ値と見なし、付けなければ日付のみの値と見なす。\n\
\n\
書式\n\
\n\
mcsv2arff n=|d=|D=|s= [T=] i= [o=] [-assert_nullin] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  n=   数値項目名(複数項目指定可)を指定する。\n\
  d=   カテゴリ項目名(複数項目指定可)を指定する。\n\
  D=   日付(時刻)項目名(複数項目指定可)リストを指定する。 [%t]\n\
       %tを指定しなかった場合：yyyyMMdd\n\
       %tを指定した場合　　　：yyyyMMddHHmmss\n\
  s=   文字列項目名(複数項目指定可)を指定する。\n\
  T=   タイトルにする文字列を指定する。\n\
\n\
利用例\n\
\n\
例1: csv形式のデータをarff形式のデータへ変換\n\
\n\
「顧客」項目は文字列型、 「商品」項目はカテゴリ型、\n\
「日付」項目は日付型(時刻は含まない)、\n\
そして「数量」と「金額」項目は数値型として、\n\
arff形式のデータへ変換する。\n\
\n\
    $ more dat1.csv\n\
    顧客,商品,日付,数量,金額\n\
    No.1,A,20081201,1,10\n\
    No.2,A,20081202,2,20\n\
    No.3,A,20081203,3,30\n\
    No.4,B,20081201,4,40\n\
    No.5,B,20081203,5,50\n\
    $ mcsv2arff s=顧客 d=商品 D=日付 n=数量,金額 T=顧客購買データ i=dat1.csv  o=rsl1.csv\n\
    #END# kgcsv2arff D=日付 T=顧客購買データ d=商品 i=dat1.csv n=数量,金額 o=rsl1.csv s=顧客\n\
    $ more rsl1.csv\n\
    @RELATION	顧客購買データ\n\
\n\
    @ATTRIBUTE	顧客	string\n\
    @ATTRIBUTE	日付	date yyyyMMdd\n\
    @ATTRIBUTE	数量	numeric\n\
    @ATTRIBUTE	金額	numeric\n\
    @ATTRIBUTE	商品	{A,B}\n\
\n\
    @DATA\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
\n\
例2: csv形式のデータをarff形式のデータへ変換(時刻を含む日付データ指定)\n\
\n\
時刻を伴うデータはD=日付%tのように%tを加えて指定する。\n\
\n\
    $ more dat2.csv\n\
    顧客,商品,日付,数量,金額\n\
    No.1,A,20081201102030,1,10\n\
    No.2,A,20081202123010,2,20\n\
    No.3,A,20081203153010,3,30\n\
    No.4,B,20081201174010,4,40\n\
    No.5,B,20081203133010,5,50\n\
    $ mcsv2arff s=顧客 d=商品 D=日付%t n=数量,金額 T=顧客購買データ i=dat2.csv  o=rsl2.csv\n\
    #END# kgcsv2arff D=日付%t T=顧客購買データ d=商品 i=dat2.csv n=数量,金額 o=rsl2.csv s=顧客\n\
    $ more rsl2.csv\n\
    @RELATION	顧客購買データ\n\
\n\
    @ATTRIBUTE	顧客	string\n\
    @ATTRIBUTE	日付	date yyyyMMddHHmmss\n\
    @ATTRIBUTE	数量	numeric\n\
    @ATTRIBUTE	金額	numeric\n\
    @ATTRIBUTE	商品	{A,B}\n\
\n\
    @DATA\n\
    No.1,20081201102030,1,10,A\n\
    No.2,20081202123010,2,20,A\n\
    No.3,20081203153010,3,30,A\n\
    No.4,20081201174010,4,40,B\n\
    No.5,20081203133010,5,50,B\n\
";

