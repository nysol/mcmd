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
/// kgnewstrHelp.h : kgnewstr help
// =============================================================================
_titleL="固定文字列データの新規生成";
_docL="\
\n\
MNEWSTR 固定文字列データの新規生成\n\
\n\
v=パラメータで指定した文字列データを新規作成し、a=パラメータで指定した項目名で出力する。\n\
一度に複数の項目を生成することも可能。\n\
\n\
書式\n\
\n\
mnewstr a= [v=] [l=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=   新規に作成するデータの項目名を指定する。\n\
       複数の項目を生成する場合は、項目名をカンマで区切る。\n\
       -nfn,-nfnoオプション指定時は指定の必要はない。\n\
  v=   新しく作成する文字列を指定する。\n\
       複数の項目を生成する場合は、値をカンマで区切る。a=で指定した個数と同数でなければならない。\n\
  l=   新規作成する乱数データの行数を指定する。【デフォルト値:10】\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
custNoとA0001という文字列データを5行作成し、attribute,codeという名前の項目名で出力する。\n\
\n\
    $ mnewstr a=attribute,code v=custNo,A0001 l=5 o=rsl1.csv\n\
    #END# kgnewstr a=attribute,code l=5 o=rsl1.csv v=custNo,A0001\n\
    $ more rsl1.csv\n\
    attribute,code\n\
    custNo,A0001\n\
    custNo,A0001\n\
    custNo,A0001\n\
    custNo,A0001\n\
    custNo,A0001\n\
";

