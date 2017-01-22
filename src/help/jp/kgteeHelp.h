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
/// kgteeHelp.h : kgtee help
// =============================================================================
_titleL="複数ファイルへのコピー";
_docL="\
\n\
MTEE 複数ファイルへのコピー\n\
\n\
入力データの内容を標準出力および複数ファイルへそのままコピー出力する。\n\
\n\
書式\n\
\n\
mtee [o=] [-nostdout] [i=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  o=          ここで指定された複数のファイルに入力ファイルと同一内容が出力される。\n\
              またこのパラメータが省略された時には標準出力にのみ出力される。\n\
  -nostdout   標準出力には出力しない場合に指定する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
dat1.csvファイルをrsl1.csvとrsl2.csvという２つのファイルにコピーする。\n\
また、標準出力に出力されるので、画面上に内容が出力される。\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    $ mtee i=dat1.csv o=rsl1.csv,rsl2.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    #END# kgtee i=dat1.csv o=rsl1.csv,rsl2.csv\n\
    $ more rsl1.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    $ more rsl2.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
\n\
例2: 標準出力なし\n\
\n\
-nostdoutを指定すると、rsl1.csvとrsl2.csvという２つのファイルにコピーのみ行い、\n\
標準出力には出力しない。\n\
\n\
    $ mtee i=dat1.csv o=rsl1.csv,rsl2,csv -nostdout\n\
    #END# kgtee -nostdout i=dat1.csv o=rsl1.csv,rsl2,csv\n\
";

