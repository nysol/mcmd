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
/// kgvcatHelp.h : kgvcat help
// =============================================================================
_titleL="ベクトルの併合";
_docL="\
\n\
MVCAT ベクトルの併合\n\
\n\
複数のベクトルを併合して新しいベクトルを生成する。\n\
\n\
書式\n\
\n\
mvcat vf= a= [-A] [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  vf=   併合する複数のベクトル項目名(i=ファイル上)を指定する。\n\
        項目名にワイルドカードを使うことができる。\n\
  a=    併合後の項目名を指定する。\n\
  -A    新しい項目として追加する。このオプションを指定しなければ、併合元の項目(vf=)は削除される。\n\
\n\
利用例\n\
\n\
例1: ワイルドカードを利用した例\n\
\n\
    $ more dat1.csv\n\
    items1,items2,items3,items4\n\
    b a c,b,x,y\n\
    c c,,x,y\n\
    e a a,a a a,x,y\n\
    $ mvcat vf=items* a=items i=dat1.csv o=rsl1.csv\n\
    #END# kgvcat a=items i=dat1.csv o=rsl1.csv vf=items*\n\
    $ more rsl1.csv\n\
    items\n\
    b a c b x y\n\
    c c x y\n\
    e a a a a a x y\n\
";

