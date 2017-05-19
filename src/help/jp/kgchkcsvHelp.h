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
_titleL="CSVデータのチェック";
_docL="\
\n\
MCHKCSV CSVデータのチェック\n\
\n\
MCMDが前提とするCSVの仕様を満たしていないデータを自動修復する(項目数の統一など)。\n\
また、-diagオプションを指定することで、CSVデータのチェックのみ実行する。\n\
\n\
書式\n\
\n\
mchkcsv [a=] [-diagl-diag] [-r]| [i=] [o=] [-assert_nullout] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  i=       入力ファイル名\n\
           このパラメータで指定したCSVデータに不備な箇所がないかチェックを行い、\n\
           不備がある場合その箇所を自動的に補完する。\n\
           このパラメータが省略された時には標準入力が用いられる。\n\
  a=       入力データの項目名を無視し、ここで指定した項目名を出力する。\n\
           ここで指定した項目数が入力データの項目数より少ない場合は、\n\
           入力データの左から順番に指定の個数分の項目が出力される。\n\
           逆に、ここで指定した項目数が入力データの項目数より多い場合、不足分はNULL値が出力される。\n\
  -diagl   このオプションを指定した場合、データの修正/補完は行わず、\n\
           データ項目の統計情報を出力するとともに、CSVお妥当性チェックの結果を標準出力に出力する。\n\
           チェックする内容は以下の通り。\n\
           a): 同一項目名がないか。\n\
           b): 項目名に不正な文字がないか。\n\
           c): 改行がLFか。\n\
           d): 最終行に改行が存在するか。\n\
           e): データファイル内に\\0がないか。\n\
           f): 一行の最大長を超過していないか。\n\
           g): 全行同じ項目数か。\n\
           h): 制御文字(0x01 0x1F,0x7F)が入り込んでいないか。\n\
           i): TABが入っていないか。\n\
           j): DQUOTEで囲われていない中でDQUOTEがない。\n\
           k): DQUOTEで囲われている中で単一のDQUOTEがないか。\n\
           l): 先頭にBOM(Bit Order Mark)が含まれていないか。\n\
  -diag    -diaglの英語版\n\
  -r       制御文字を無視\n\
           ここではASCII文字コードの0x00〜0x1f,0x7f(0x09,0x0a,0x0dは除く)を制御文字と定義している。\n\
           このオプションを指定しなければ制御コードは自動的に&#xという文字列に変換される。\n\
\n\
利用例\n\
\n\
例1: データの補完\n\
\n\
データの項目数が違う（2,4行目が3項目しかない）問題のあるデータを\n\
Mコマンドで利用できるデータに補完（4項目に自動的に補完）する。\n\
\n\
    $ more dat1.csv\n\
    商品,日付,数量,金額\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3\n\
    B,20081201,4,40\n\
    B,20081203,50\n\
    $ mchkcsv i=dat1.csv o=rsl1.csv\n\
    #END# kgchkcsv i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    商品,日付,数量,金額\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3,\n\
    B,20081201,4,40\n\
    B,20081203,50,\n\
\n\
例2: データの補完、項目名変更\n\
\n\
データの項目数が違う（3,5行目が3項目しかない）問題のあるデータを\n\
Mコマンドで利用できるデータに補完（4項目に自動的に補完）する。\n\
その際に、入力データの左の項目から順番に「商品,日付,数量,金額」という項目名で出力する。\n\
\n\
    $ more dat2.csv\n\
    fld1,fld2,fld3,fld4\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3\n\
    B,20081201,4,40\n\
    B,20081203,50\n\
    $ mchkcsv a=商品,日付,数量,金額 i=dat2.csv o=rsl2.csv\n\
    #END# kgchkcsv a=商品,日付,数量,金額 i=dat2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    商品,日付,数量,金額\n\
    A,20081201,1,10\n\
    A,20081202,2,\n\
    A,*,3,\n\
    B,20081201,4,40\n\
    B,20081203,50,\n\
\n\
例3: データの不備チェック、診断結果の出力\n\
\n\
CSVデータに不備な箇所がないかチェックのみを行い、CSVファイル診断結果を出力する。\n\
\n\
    $ mchkcsv -diagl i=dat1.csv o=rsl3.csv\n\
    #END# kgchkcsv -diagl i=dat1.csv o=rsl3.csv\n\
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
    # 1   商品\n\
    # 2   日付\n\
    # 3   数量\n\
    # 4   金額\n\
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
    #  項目番号[1] 項目名[商品]\n\
    #    NULL値の行数                : 0 \n\
    #    DQUOTEで囲われていない行数  : 5 (LineNo: 1 2 3 ... )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    #  項目番号[2] 項目名[日付]\n\
    #    NULL値の行数                : 0 \n\
    #    DQUOTEで囲われていない行数  : 5 (LineNo: 1 2 3 ... )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    #  項目番号[3] 項目名[数量]\n\
    #    NULL値の行数                : 0 \n\
    #    DQUOTEで囲われていない行数  : 5 (LineNo: 1 2 3 ... )\n\
    #    DQUOTEで囲われている行数    : 0 \n\
    #\n\
    #  項目番号[4] 項目名[金額]\n\
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
    # ?l : 先頭にBOMが含まれている\n\
    #  【対処方法】kgchkcsvにてBOMは除去される。\n\
    #-------------------------------------------------------------\n\
";

