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
/// kginputHelp.h : kginput help
// =============================================================================
_titleL="画面入力";
_docL="\
\n\
MINPUT 画面入力\n\
\n\
座標x=,y=で指定したターミナル上の位置にlen=で指定した長さの入力枠を表示し、\n\
入力した内容をo=で指定したファイルに出力する。\n\
入力画面でエンターキーを押すと、終了ステータス0を返して終了し、\n\
エスケープキーを押すと、終了ステータス1を返して終了する。\n\
いずれのキーで終了しても、そこまでに入力した内容はファイルに出力される。\n\
\n\
出力されるCSVファイルは、一項目一行のデータとなる。\n\
入力枠に何も入力せずに終了した場合は、null値が出力される(すなわち改行だけが出力される)。\n\
f=を指定すれば、項目名を出力できる。\n\
f=を省略すれば、項目名ヘッダーは出力されない。\n\
\n\
座標は左上がx=1,y=1である(エスケープシーケンスの仕様)。\n\
x=もしくはy=で指定した値が1より小さい場合は、1を指定したものとして動作する。\n\
またターミナルの範囲を超えた座標が指定された場合の動作は不定である。\n\
\n\
書式\n\
\n\
minput x= y= len= [f=]  o= [-nfn] [-nfno] [-x] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  x=     x軸(左から右への横方向)表示開始位置(1以上の値)を指定する。\n\
  y=     y軸(上から下への縦方向)表示開始位置(1以上の値)を指定する。\n\
  len=   入力欄の半角文字数\n\
  f=     出力項目名\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
ターミナルのx=10,y=5の位置に幅12文字の入力領域を示し、入力枠に“abcd”と入力してenterキーを押し、入力結果をrsl1.csvに保存する。\n\
\n\
    $ minput x=10 y=5 len=12 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    abcd\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |\n\
    |\n\
    |\n\
    |          [abcd        ]\n\
    |\n\
    |\n\
\n\
例2: 項目名を指定する基本例\n\
\n\
例1と同様でf=で項目名を指定する。\n\
\n\
    $ minput x=10 y=5 len=12 f=name o=rsl1.csv\n\
    $ more rsl1.csv\n\
    name\n\
    abcd\n\
\n\
例3: 終了ステータスを判定する例\n\
\n\
例1と同じパラメータで実行し、終了ステータスを判定して異なる動作をするスクリプトの例。\n\
\n\
    $ more scp.sh\n\
    rm -f rsl2.csv\n\
    clear\n\
    minput x=10 y=5 len=12 o=rsl2.csv\n\
    if [ $? = 0 ] ; then\n\
      clear ; echo \"end by enter key\"\n\
    else\n\
      clear ; echo \"end by escape key\"\n\
    fi\n\
\n\
    # abcdと入力後enterキーを入力した場合の結果\n\
    $ bash scp.sh\n\
    end by enter key\n\
    $ more rsl2.csv\n\
    abcd\n\
\n\
    # abcdと入力後escapeキーを入力した場合の結果\n\
    $ bash scp.sh\n\
    end by escape key\n\
    $ more rsl2.csv\n\
    abcd\n\
";

