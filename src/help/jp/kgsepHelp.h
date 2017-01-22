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
/// kgsepHelp.h : kgsep help
// =============================================================================
_titleL="レコードの分割";
_docL="\
\n\
MSEP レコードの分割\n\
\n\
d=パラメータで指定したファイル名のデータに各レコードを出力する。\n\
指定するファイル名に項目名を埋め込むことができるので、結果としてレコード分割することになる。\n\
埋め込むファイル名は${項目名}によって指定する。\n\
例えば、d=./out/${date}.csvと指定すれば、カレントディレクトリの下のoutディレクトリの下に、\n\
date項目の値別にファイルが作成されることになる。\n\
\n\
内部的には、埋め込んだ項目の値をキーとして認識し、並べ替えが行われた後レコードが分割される。\n\
\n\
書式\n\
\n\
msep d= [-p] [f=]  [i=] [-assert_nullin] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  d=   異なるデータファイルに分割する項目名を指定する。\n\
       ここで指定した文字列をファイル名として各レコードが追記されていく。\n\
       項目名は${項目名}によって埋め込む。\n\
  -p   d= パラメータで指定したディレクトリ名が存在しなければ作成する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
datという名前のディレクトリを作成し、\n\
そのディレクトリに日付項目値dateごとに異なるファイルに出力する。\n\
\n\
    $ more dat1.csv\n\
    item,date,quantity,price\n\
    A,20081201,1,10\n\
    B,20081201,4,40\n\
    A,20081202,2,20\n\
    A,20081203,3,30\n\
    B,20081203,5,50\n\
    $ msep d='./dat/${date}.csv' -p i=dat1.csv\n\
    #END# kgsep -p d=./dat/${date}.csv i=dat1.csv\n\
    $ ls ./dat\n\
    20081201.csv\n\
    20081202.csv\n\
    20081203.csv\n\
    $ more ./dat/20081201.csv\n\
    item,date%0,quantity,price\n\
    A,20081201,1,10\n\
    B,20081201,4,40\n\
    $ more ./dat/20081202.csv\n\
    item,date%0,quantity,price\n\
    A,20081202,2,20\n\
    $ more ./dat/20081203.csv\n\
    item,date%0,quantity,price\n\
    A,20081203,3,30\n\
    B,20081203,5,50\n\
";

