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
/// kgfsortHelp.h : kgfsort help
// =============================================================================
_titleL="項目ソート";
_docL="\
\n\
MFSORT 項目ソート\n\
\n\
各行でf=で指定した複数項目の値を並べ替え(デフォルトでは文字列昇順)、その順序で出力する。\n\
項目名の並びは変化しないことに注意する。\n\
\n\
書式\n\
\n\
mfsort f= [-r] [-n] [i=] [o=] [-assert_diffSize] [-assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   ソート対象となる項目を複数指定する。単一の項目を指定してもよいが、結果は変わらない。\n\
  -n   数値順に並べる。\n\
  -r   逆順に並べる。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
各行においてv1,v2,v3の値を昇順にならべ、その順番でv1,v2,v3項目として出力する。\n\
\n\
    $ more dat1.csv\n\
    id,v1,v2,v3\n\
    1,b,a,c\n\
    2,a,b,a\n\
    3,b,,e\n\
    $ mfsort f=v* i=dat1.csv o=rsl1.csv\n\
    #END# kgfsort f=v* i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,v1,v2,v3\n\
    1,a,b,c\n\
    2,a,a,b\n\
    3,,b,e\n\
\n\
例2: 降順\n\
\n\
降順にしたければ-rを付ける。\n\
\n\
    $ mfsort f=v* -r i=dat1.csv o=rsl2.csv\n\
    #END# kgfsort -r f=v* i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,v1,v2,v3\n\
    1,c,b,a\n\
    2,b,a,a\n\
    3,e,b,\n\
";

