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
/// kgsep2Help.h : kgsep2 help
// =============================================================================
_titleL="連番-項目値表の出力を伴った行の分割";
_docL="\
\n\
MSEP2 連番-項目値表の出力を伴った行の分割\n\
\n\
k=で指定された項目の値別にデータを分割(separation)する。\n\
分割後のデータは自動的に採番される連番ファイル名に保存され、\n\
k=で指定された項目の値と分割後のファイル名との対応表が出力される。\n\
\n\
書式\n\
\n\
msep2 k= O= a= [-p] [i=] [o=] [-assert_nullkey] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   分割単位となる項目名リスト\n\
  O=   ここで指定されたディレクトに連番ファイル(0から始まる連番)を作成する。\n\
  o=   k=で指定した項目値と連番ファイル名との対応表をCSVで出力する。\n\
       指定しなければ標準出力に出力される。\n\
  a=   o=に出力されるファイル名の項目名を指定する。\n\
  -p   O=で指定したディレクトリがなければ強制作成する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
item項目別にデータを分割する。\n\
出力ファイル名は0から始まる連番であり、どの番号がどのキーに対応しているかがtable.csvに出力される。\n\
\n\
    $ more dat1.csv\n\
    item,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
    B,1\n\
    B,2\n\
    $ msep2 k=item O=./output a=fileName o=table.csv i=dat1.csv\n\
    #END# kgsep2 O=./output a=fileName i=dat1.csv k=item o=table.csv\n\
    $ ls ./output\n\
    0\n\
    1\n\
    $ more table.csv\n\
    item%0,fileName\n\
    A,./output/0\n\
    B,./output/1\n\
    $ more output/0\n\
    item%0,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
    $ more output/1\n\
    item%0,no\n\
    B,1\n\
    B,2\n\
\n\
例2: 複数キー項目\n\
\n\
複数のキー項目item,noを設定しても同様に各ファイル名は連番で作成される。\n\
table.csvに複数のキー項目と番号の対応表が出力されている。\n\
\n\
    $ more dat1.csv\n\
    item,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
    B,1\n\
    B,2\n\
    $ msep2 k=item,no O=./output2 a=fileName o=table.csv i=dat1.csv\n\
    #END# kgsep2 O=./output2 a=fileName i=dat1.csv k=item,no o=table.csv\n\
    $ ls ./output2\n\
    0\n\
    1\n\
    2\n\
    3\n\
    $ more table.csv\n\
    item%0,no%1,fileName\n\
    A,1,./output2/0\n\
    A,2,./output2/1\n\
    B,1,./output2/2\n\
    B,2,./output2/3\n\
    $ more output/0\n\
    item%0,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
";

