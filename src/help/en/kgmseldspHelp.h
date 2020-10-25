﻿/* ////////// LICENSE INFO ////////////////////

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
_titleL="複数選択入力プログラム";
_docL="\
\n\
mmseldsp 複数選択入力プログラム\n\
\n\
x=,y=で指定した座標に\n\
i=で指定したファイル内容もしくはstr=で指定した文字列で\n\
選択画面を表示し、\n\
入力した内容をo=指定したファイルに出力する\n\
f=を指定するとヘッダ行としてして出力する\n\
\n\
書式\n\
\n\
mseldsp x= y= i=|seldata= o= [f=] [height=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  x=   表示開始位置x\n\
  y=   表示開始位置y\n\
  i=   表示する選択内容（ファイル名）\n\
  f= 項目名\n\
  o= 出力ファイル\n\
  seldata= 表示する選択内容（文字列）\n\
\n\
";

