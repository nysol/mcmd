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
/// kgcsv2arffHelp.h : kgcsv2arff help
// =============================================================================
_titleL="CSVからjson形式への変換";
_docL="\
\n\
MCSV2JSOn CSVからJSON形式への変換\n\
\n\
csv形式のデータからjson形式のデータへ変換する。\n\
\n\
書式\n\
\n\
mcsv2json f=|h=|p= [k=] i= [o=] [-flat] [-assert_nullin] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   出力fld項目（配列）\n\
  h=   出力fld項目（object）\n\
  p=   出力fld項目（pair）\n\
  k=   単位となる項目(複数項目指定可)名リストを指定する。\n\
  s=   ここで指定した項目(複数項目指定可)で並べ替えられる\n\
  -flat 平らにする\n\
\n\
利用例\n\
\n\
";

