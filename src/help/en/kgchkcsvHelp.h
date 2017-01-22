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
/// kgchkcsvHelp.h : kgchkcsv help
// =============================================================================
_title="-";
_doc="\
\n\
MCHKCSV - CHECK CSV DATA\n\
\n\
Automatically repair (standardize the number of fields for all rows)\n\
comma-separated-values (CSV) data that do not meet the f[sect:csv]CSV\n\
format for MCMD. Use the -diag option to perform checking on CSV data.\n\
\n\
Format\n\
\n\
mchkcsv [a=] [-diag] [-r] [i=] [o=] [-option_assert_nullout] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  i=      Input file name\n\
          The CSV data defined here is checked for incomplete lines.\n\
          Issues identified in this file is automatically repaired.\n\
          If this parameter is omitted, the standard input is used.\n\
  a=      Substitute the field name(s) in the input data with the field name(s) specified at this parameter.\n\
          If the number of fields specified is less than the number of fields in the header,\n\
          the output will only yield portion of columns from the input data starting from the left.\n\
          Conversely, if the number of fields specified here is greater than the number of fields in input data,\n\
          data items in the extra fields are expressed as NULL values in the output.\n\
  -diag   Execute check.\n\
          When this option is specified, write result to standard output.\n\
  -r      Exclude control characters\n\
          This defines the control character as ASCII character code 0x00-0x1f,0x7f (remove 0x09,0x0a,0x0d).\n\
          Control code is automatically converted to the string &#x when this option is not specified.\n\
\n\
Examples\n\
\n\
Example 1: Repair data\n\
\n\
This data contains different number of columns in all records. For\n\
instance, only 3 records have 4 columns. Use M-Command to repair and\n\
standardize 3rd and 5th rows to 4 columns.\n\
\n\
    $ more dat1.csv\n\
    product,date,quantity,amount\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3\n\
    B,20081201,4,40\n\
    B,20081203,50\n\
    $ mchkcsv i=dat1.csv o=rsl1.csv\n\
    #END# kgchkcsv i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    product,date,quantity,amount\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3,\n\
    B,20081201,4,40\n\
    B,20081203,50,\n\
\n\
Example 2: Change field name after repairing the data\n\
\n\
This data contains different number of columns in all records. For\n\
instance, only 3 records have 4 columns. Use M Command to repair and\n\
standardize 3rd and 5th rows to 4 columns. At the same time, label the\n\
field names from the input data as ¥verb|“product,date,quantity,amount”|\n\
starting from the left.\n\
\n\
    $ more dat2.csv\n\
    fld1,fld2,fld3,fld4\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3\n\
    B,20081201,4,40\n\
    B,20081203,50\n\
    $ mchkcsv a=product,date,quantity,amount i=dat2.csv o=rsl2.csv\n\
    #END# kgchkcsv a=product,date,quantity,amount i=dat2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    product,date,quantity,amount\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3,\n\
    B,20081201,4,40\n\
    B,20081203,50,\n\
\n\
Example 3: Check data integrity and output diagnostic results\n\
\n\
It merely checks for incomplete data structure in the CSV data, and save\n\
the diagnosis result in CSV file.\n\
\n\
    $ mchkcsv -diag i=dat1.csv o=rsl3.csv\n\
    #END# kgchkcsv -diag i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    #===================================================\n\
    # CSVファイル診断 \n\
    # file name : dat1.csv\n\
    #---------------------------------------------------\n\
    # 結果の一文字目の意味\n\
    # # : 情報行(問題なし)\n\
    # ? : KGMODにて扱えない問題点(?の後の文字は解説参照)\n\
    # よって、左端が全て#になればOK\n\
    #===================================================\n\
    ############################ ヘッダー情報(1行目) ###\n\
    # 項目数 : 4\n\
    # 項目No.  項目名\n\
    # 1   product\n\
    # 2   date\n\
    # 3   quantity\n\
    # 4   amount\n\
    #\n\
    ############## EOL(End Of Line)情報(ヘッダー含む) ##\n\
    #         LF改行行数 : 6 (LineNo: 0 1 2 ... )\n\
    #\n\
    ################# データ行情報(ヘッダー含まない) ###\n\
    #           総行数 : 5\n\
    #       総バイト数 : 66\n\
    #           平均長 : 13.2\n\
    #           最大長 : 16 (LineNo:2)\n\
    #           最小長 : 6 (LineNo:4)\n\
    # 注:長さは、改行文字も含めた長さ\n\
    #\n\
    ################################# 項目数の一貫性 ###\n\
    ?g 異なる項目数の行が発見されました。\n\
    ?g  項目数:3 (LineNo:4)\n\
    ?g  項目数:3 (LineNo:6)\n\
    #\n\
    ####################################### 項目情報 ###\n\
    #  項目番号[1] 項目名[product]\n\
    #    NULL値の行数                : 0 \n\
    #    DQUOTEで囲われていない行数  : 5 (LineNo: 1 2 3 ... )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    #  項目番号[2] 項目名[date]\n\
    #    NULL値の行数                : 0 \n\
    #    DQUOTEで囲われていない行数  : 5 (LineNo: 1 2 3 ... )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    #  項目番号[3] 項目名[quantity]\n\
    #    NULL値の行数                : 0 \n\
    #    DQUOTEで囲われていない行数  : 5 (LineNo: 1 2 3 ... )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    #  項目番号[4] 項目名[amount]\n\
    #    NULL値の行数                : 1 (LineNo: 2 )\n\
    #    DQUOTEで囲われていない行数  : 3 (LineNo: 1 2 4 )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    ################################### 問題点の解説 ###\n\
    # ?a : 同じ項目名があると項目番号を特定できない。\n\
    #  【対処方法】kgchkcsv a=x,y,z のように項目名を新たに指定する。\n\
    # ?b : 項目名に不正な文字があるとエラーになる\n\
    #  【対処方法】kgchkcsv a=x,y,z のように項目名を新たに指定する。\n\
    # ?c : KGMODが扱う改行は高速化のためLF(UNIX改行)のみ。\n\
    #      この問題はRFC4180には準拠しておらずKGMOD独自の制約である。\n\
    #  【対処方法】kgchkcsv にて全てLFに変換される。\n\
    #\n\
    # ?d : 最終行にLFやCRなどの改行(EOL)文字が存在しない。\n\
    #      これはRFC4180にも準拠していない。\n\
    #  【対処方法】kgchkcsv にてLFが付加される。\n\
    #\n\
    # ?e : データファイル内に'\\0'が入り込んでいる。\n\
    #      テキストファイルでない可能性が高い。\n\
    #      RFC4180には準拠していない。\n\
    #  【対処方法】kgchkcsv にて、\"&#x00\n\
    #              kgchkcsv -rにて\\0は削除される。\n\
    #\n\
    # ?f : KGMODが扱える一行の最大長を超過している。\n\
    #      現在の設定では1024000バイト以上の長さの行は扱えない。\n\
    #  【対処方法】環境変数を設定することで最大値を変更可能である。\n\
    #        ex) export KG_MaxRecLen=204800\n\
    #      ただし10240000バイトを越えては指定できない。 \n\
    #      この問題はRFC4180には準拠しておりKGMOD独自の制約である。\n\
    #\n\
    # ?g : KGMODでは全行同じ項目数を前提とする。\n\
    #      この問題はRFC4180には準拠しておりKGMOD独自の制約である。\n\
    #  【対処方法】\n\
    #       1) kgchkcsv  データHEADERの項目数に合わせる.\n\
    #            超過項目は捨てられ、足りない項目はnull値となる\n\
    #       2) kgchkcsv  a=x,y,z HEADER行をスキップし、\n\
    #            指定したx,y,zを項目名として1)と同様の処理を行う。\n\
    #\n\
    # ?h : 制御文字(0x01~0x1F,0x7F)が項目値として入り込んでいる。\n\
    #      テキストファイルでない可能性が高い。\n\
    #      RFC4180には準拠していない。\n\
    #  【対処方法】kgchkcsv にて、\"&#x01\n\
    #              kgchkcsv -rにて制御文字は削除される。\n\
    #\n\
    # ?i : TABは利用できない。\n\
    #      RFC4180には準拠していない。\n\
    #  【対処方法】kgchksv にて、\"&#x09\n\
    #              kgchkcsv -rにてTABは削除される。\n\
    #\n\
    # ?j : DQUOTEで囲われていない中でDQUOTEが見つかった\n\
    #        ex) NG: xxx,oo\"oo,xxx  -> OK: xxx,\"oo\"\"oo\",xxx\n\
    #      RFC4180には準拠していない。\n\
    #  【対処方法】kgchkcsv にて上記の変換を行う。\n\
    #\n\
    # ?k : DQUOTEで囲われている中で単一のDQUOTEが見つかった\n\
    #      ex) NG: xxx,\"oo\"oo\",xxx  -> OK: xxx,\"oo\"\"oo\",xxx\n\
    #      RFC4180には準拠していない。\n\
    #  【対処方法】kgchkcsvにて上記の変換を行う。\n\
    #-------------------------------------------------------------\n\
";

