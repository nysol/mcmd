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
/// kgdspHelp.h : kgdsp help
// =============================================================================
_titleL="画面表示";
_docL="\
\n\
MDSP 画面表示\n\
\n\
座標x=,y=で指定したターミナル上の位置にstr=で指定した文字列を表示する。\n\
i=でファイル名を指定すると、その内容を表示する。\n\
str=とi=の両方が指定されればi=が優先される。\n\
i=が複数行ある場合、全ての行がx=で指定した座標位置から表示される。\n\
\n\
fc=で文字列の色を指定でき、またbg=で文字列の背景の色を指定できる。\n\
指定できる色は、black, red, green, yellow, blue, magenda, cyan,\n\
white、の8色である。\n\
fc=のデフォルトはblackで、bg=のデフォルトはwhiteである。\n\
また-boldを指定することで強調表示が可能である。\n\
\n\
書式\n\
\n\
mdsp x= y= str=|i= [fc=] [bg=] [-bold]  [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  x=      x軸(左から右への横方向)表示開始位置(1以上の値)を指定する。\n\
  y=      y軸(上から下への縦方向)表示開始位置(1以上の値)を指定する。\n\
  str=    表示する文字列\n\
  i=      表示する内容のファイル名\n\
  fc=     文字色\n\
  bg=     背景色\n\
  -bold   強調表示\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
ターミナルのx=10,y=5の位置に文字列abcdを表示する。\n\
\n\
    $ mdsp x=10 y=5 str=abcd\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |\n\
    |\n\
    |\n\
    |          abcd\n\
    |\n\
    |\n\
\n\
例2: ファイルで指定する場合\n\
\n\
ターミナルのx=10,y=5の位置にdat.txtの内容を表示する。\n\
\n\
    $ more dat.txt\n\
    abcd\n\
    efg\n\
    $ mdsp x=10 y=5 i=dat.txt\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |\n\
    |\n\
    |\n\
    |          abcd\n\
    |          efg\n\
    |\n\
\n\
例3: 色をつける例\n\
\n\
ターミナルのx=10,y=5の位置に文字列abcdを、\n\
文字の色を赤、背景を青にして表示する。\n\
\n\
    $ mdsp x=10 y=5 str=abcd fc=red bc=blue\n\
\n\
    以下、画面イメージ\n\
    +--------------------------------------\n\
    |\n\
    |\n\
    |\n\
    |\n\
    |          abcd\n\
    |\n\
    |\n\
";

