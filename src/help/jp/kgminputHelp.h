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
/// kgminputHelp.h : kgminput help
// =============================================================================
_titleL="画面フォーム入力";
_docL="\
\n\
MMINPUT 画面フォーム入力\n\
\n\
i=で与えられたテキストファイルを画面フォームとして読み込み、データ入力画面を表示する。\n\
画面フォーム上の文字列は、そのままのイメージで画面出力され、角括弧([])で囲われた領域は\n\
自由入力欄として表示される。入力欄は複数あってもよい。\n\
利用者が入力したデータはCSVとしてo=で指定したファイルに出力する。\n\
出力されるデータは一行データで、入力欄が複数ある場合は、複数項目のCSVとして出力される。\n\
\n\
入力枠に何も入力せずに終了した場合は、null値が出力される。\n\
f=を指定すれば、項目名を出力できる。\n\
f=を省略すれば、項目名ヘッダーは出力されない。\n\
\n\
またターミナルの範囲を超えた文字列や入力枠が指定された場合の動作は不定である。\n\
\n\
書式\n\
\n\
mminput i= [f=]  o= [-nfn] [-nfno] [-x] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  i=   画面フォームのテキストファイル名\n\
  f=   出力項目名\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
名前と住所を入力する画面を表示し、項目名name,addressとしてrsl1.csvに出力する。\n\
\n\
    $ more screen.txt\n\
\n\
         name   :[               ]\n\
         address:[               ]\n\
\n\
    $ mminput i=screen.txt f=name,address o=rsl1.csv\n\
    $ more rsl1.csv\n\
    name,address\n\
    Taro,Japan\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |     name   :[Taro           ]\n\
    |     address:[Japan          ]\n\
    |\n\
\n\
例2: 終了ステータスを判定する例\n\
\n\
例1と同じパラメータで実行し、終了ステータスを判定して異なる動作をするスクリプトの例。\n\
\n\
    $ more scp.sh\n\
    rm -f rsl3.csv\n\
    clear\n\
    mminput i=screen.txt f=name,address o=rsl3.csv\n\
    if [ $? = 0 ] ; then\n\
      clear ; echo \"end by enter key\"\n\
    else\n\
      clear ; echo \"end by escape key\"\n\
    fi\n\
\n\
    # TaroとJapanを入力後enterキーを入力した場合の結果\n\
    $ bash scp.sh\n\
    end by enter key\n\
    $ more rsl3.csv\n\
    name,address\n\
    Taro,Japan\n\
\n\
    # TaroとJapanを入力後escapeキーを入力した場合の結果\n\
    $ bash scp.sh\n\
    end by escape key\n\
    $ more rsl3.csv\n\
    name,address\n\
    Taro,Japan\n\
";

