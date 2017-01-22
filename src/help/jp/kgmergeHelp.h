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
/// kgmergeHelp.h : kgmerge help
// =============================================================================
_titleL="マッチング併合";
_docL="\
\n\
MMERGE マッチング併合\n\
\n\
指定した複数のファイルについて、指定した項目(「併合キー項目」と呼ぶ)の順序を保ちながら併合する。\n\
それぞれのファイルは指定した項目で事前に並べ替えておかなければならない。\n\
項目ごとに文字の昇順ソート,文字の降順ソート,数値の昇順ソート、数値の降順ソートが可能。\n\
\n\
書式\n\
\n\
mmerge [k=] [pways=]  [i=] [o=] [-nfn] [-nfno] [-x] [tmpPath=] [--help][--version]\n\
\n\
パラメータ\n\
\n\
  k=       併合キー項目名リスト(複数項目指定可能)を指定する。\n\
           併合キー項目の並び順は、数値/文字列、昇順/降順の組み合せで4通り指定できる。\n\
           指定方法はmsortfコマンドと同様に%に続けてnとrを以下の通り組み合わせる。\n\
           文字列昇順:項目名(%指定なし)、文字列逆順:項目名%r、数値昇順:項目名%n、数値降順:項目名%nr。\n\
           【重要】i=で指定したファイルは全てここで指定した項目/並び順で並べ替えておかなければならない。\n\
  pways=   複数ファイルをマージする場合に、同時にオープンするファイル数を指定できる。【デフォルト値:32】\n\
           2以上100以下の範囲で指定可能。\n\
\n\
利用例\n\
\n\
例1: 文字列昇順ソートでファイル併合する例\n\
\n\
    $ more in1\n\
    fld1,fld2,fld3\n\
    p,q,3\n\
    x,y,1\n\
    x,y,5\n\
    $ more in2\n\
    fld1,fld2,fld3\n\
    a,c,2\n\
    a,c,4\n\
    $ mmerge k=fld1,fld2 i=in1,in2 o=rsl1.csv\n\
    xxscp: line 3: mmerge: command not found\n\
    $ more rsl1.csv\n\
    rsl1.csv: No such file or directory\n\
\n\
例2: 数字列昇順ソートでファイル併合する例\n\
\n\
    $ more in3\n\
    fld1,fld2,fld3\n\
    p,q,2\n\
    x,y,4\n\
    x,y,5\n\
    $ more in4\n\
    fld1,fld2,fld3\n\
    a,c,1\n\
    a,c,3\n\
    p,q,3\n\
    x,y,5\n\
    x,y,6\n\
    $ mmerge k=fld3%n,fld1 i=in3,in4 o=rsl2.csv\n\
    xxscp: line 3: mmerge: command not found\n\
    $ more rsl2.csv\n\
    rsl2.csv: No such file or directory\n\
";

