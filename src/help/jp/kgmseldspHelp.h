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
/// kgmseldspHelp.h : kgmseldsp help
// =============================================================================
_titleL="複数選択画面入力";
_docL="\
\n\
MMSELDSP 複数選択画面入力\n\
\n\
座標x=,y=で指定したターミナル上の位置にi=、\n\
もしくはseldata=で指定した文字列リストの選択画面を表示し、\n\
ユーザが選んだ文字列をo=で指定したファイルに出力する。\n\
mseldspコマンドでは、利用者は一つの選択肢しか選択できないが、\n\
mmseldspは複数の選択肢を選択できる。\n\
選ばれた複数の文字列は、複数行のCSV項目として出力される。\n\
入力枠に何も入力せずに終了した場合は、null値が出力される(すなわち改行だけが出力される)。\n\
f=を指定すれば、項目名を出力できる。\n\
f=を省略すれば、項目名ヘッダーは出力されない。\n\
選択肢の数が多くて画面をはみ出る場合は、height=で\n\
スクロール窓の行数を指定すればよい。\n\
\n\
選択画面でエンターキーを押すと、終了ステータス0を返して終了し、\n\
エスケープキーを押すと、終了ステータス1を返して終了する。\n\
いずれのキーで終了しても、選択画面で選ばれた内容はファイルに出力される。\n\
\n\
座標は左上がx=1,y=1である(エスケープシーケンスの仕様)。\n\
x=もしくはy=で指定した値が1より小さい場合は、1を指定したものとして動作する。\n\
またターミナルの範囲を超えた座標が指定された場合の動作は不定である。\n\
\n\
書式\n\
\n\
mmseldsp x= y= [height=] i=|seldata= o= [-nfn] [-nfno] [-x] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  x=         x軸(左から右への横方向)表示開始位置(1以上の値)を指定する。\n\
  y=         y軸(上から下への縦方向)表示開始位置(1以上の値)を指定する。\n\
  height=    選択肢を表示する行数。\n\
  i=         選択肢の文字列を項目として持つCSVファイル名\n\
  f=         選択肢の文字列を項目として持つCSVファイル名\n\
  seldata=   カンマで区切られた選択肢の文字列リスト\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
ターミナルのx=10,y=2の位置にsel.txtの内容を表示し、\n\
利用者が選んだ文字列をrsl1.txtに出力する。\n\
\n\
    $ more sel.txt\n\
    apple\n\
    pineapple\n\
    grape\n\
    orange\n\
    $ mmseldsp x=10 y=2 i=sel.txt o=rsl1.txt\n\
    # 利用者が一行目を選んだとする。\n\
    $ mose rsl1.txt\n\
    apple\n\
    orange\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |          apple    \n\
    |          pineapple\n\
    |          grape\n\
    |          orange   \n\
    |\n\
\n\
例2: 引数で与える例\n\
\n\
例1と同様で、選択肢の文字列をseldata=で与える。\n\
\n\
    $ mmseldsp x=10 y=2 seldata=apple,pineapple,grape,orange o=rsl2.txt\n\
    # 利用者が二行目を選んだとする。\n\
    $ mose rsl2.txt\n\
    apple\n\
    grape\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |\n\
    |          apple    \n\
    |          pineapple\n\
    |          grape    \n\
    |          orange\n\
    |\n\
\n\
例3: 終了ステータスを判定する例\n\
\n\
例2と同じパラメータで実行し、終了ステータスを判定して異なる動作をするスクリプトの例。\n\
\n\
    $ more scp.sh\n\
    rm -f rsl3.csv\n\
    clear\n\
    mmseldsp x=10 y=2 seldata=apple,pineapple,grape,orange o=rsl3.csv\n\
    if [ $? = 0 ] ; then\n\
      clear ; echo \"end by enter key\"\n\
    else\n\
      clear ; echo \"end by escape key\"\n\
    fi\n\
\n\
    # appleを選択後enterキーを入力した場合の結果\n\
    $ bash scp.sh\n\
    end by enter key\n\
    $ more rsl3.csv\n\
    apple\n\
\n\
    # appleを選択後escapeキーを入力した場合の結果\n\
    $ bash scp.sh\n\
    end by escape key\n\
    $ more rsl3.csv\n\
    apple\n\
";

