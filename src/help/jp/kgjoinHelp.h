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
/// kgjoinHelp.h : kgjoin help
// =============================================================================
_titleL="参照ファイルの項目結合";
_docL="\
\n\
MJOIN 参照ファイルの項目結合\n\
\n\
k=パラメータで指定した入力ファイルの項目値と参照ファイルの項目値を比較し、\n\
同じ値を持つf=パラメータで指定した参照ファイルの項目値を結合する。\n\
参照ファイルのキー項目は単一化されている必要がある。\n\
参照ファイルに同じキー項目の値が複数ある場合は、mnjoinコマンドを利用すればよい。\n\
また、f=を省略すると、参照ファイルのキー項目以外全ての項目を結合する。\n\
\n\
書式\n\
\n\
mjoin k= [f=] [K=] [-n] [-N] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   ここで指定した入力データの項目とK=パラメータで指定された\n\
       参照データの項目が同じ行の項目結合が行われる。\n\
       NULL値は，参照ファイルのK=で指定した項目のどの値にもマッチしない値として扱われる。\n\
  f=   結合する参照ファイル上の項目名リストを指定する。\n\
       省略するとキー項目を除いた全ての項目が結合される。\n\
  m=   参照ファイル名を指定する。\n\
       このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  K=   参照データ上の突き合わせる項目名リスト\n\
       ここで指定した参照データの項目とk=パラメータで指定された入力データの項目が同じ行の項目結合が行われる。\n\
       NULL値は，入力ファイルのk=で指定した項目のどの値にもマッチしない値として扱われる。\n\
       参照データ上にk=パラメータで指定した入力データ上の 項目と同名の項目が存在する場合は指定する必要はない。\n\
  -n   参照データにない入力データをNULL値として出力するフラグ。\n\
  -N   入力データにない参照データをNULL値として出力するフラグ。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
入力ファイルにあるitem項目と、\n\
参照ファイルにあるitem項目を比較し同じ値の場合、cost項目を結合する。\n\
\n\
    $ more dat1.csv\n\
    item,date,price\n\
    A,20081201,100\n\
    A,20081213,98\n\
    B,20081002,400\n\
    B,20081209,450\n\
    C,20081201,100\n\
    $ more ref1.csv\n\
    item,cost\n\
    A,50\n\
    B,300\n\
    E,200\n\
    $ mjoin k=item f=cost m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgjoin f=cost i=dat1.csv k=item m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    item%0,date,price,cost\n\
    A,20081201,100,50\n\
    A,20081213,98,50\n\
    B,20081002,400,300\n\
    B,20081209,450,300\n\
\n\
例2: 未結合データ出力\n\
\n\
入力ファイルにあるitem項目と、\n\
参照ファイルにあるitem項目を比較し同じ値の場合、cost項目を結合する。\n\
その際、参照データにない入力データと参照データにない範囲データをNULL値として出力する。\n\
\n\
    $ mjoin k=item f=cost m=ref1.csv -n -N i=dat1.csv o=rsl2.csv\n\
    #END# kgjoin -N -n f=cost i=dat1.csv k=item m=ref1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    item%0,date,price,cost\n\
    A,20081201,100,50\n\
    A,20081213,98,50\n\
    B,20081002,400,300\n\
    B,20081209,450,300\n\
    C,20081201,100,\n\
    E,,,200\n\
";

