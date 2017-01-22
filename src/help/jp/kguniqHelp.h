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
/// kguniqHelp.h : kguniq help
// =============================================================================
_titleL="レコードの単一化";
_docL="\
\n\
MUNIQ レコードの単一化\n\
\n\
値が重複した行を単一化する。\n\
\n\
書式\n\
\n\
muniq [k=]  [i=] [o=] [-assert_diffSize] [-assert_nullkey] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   行を単一化する単位となる項目名リストを指定する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
date項目を単位に重複行を削除し単一にする。\n\
\n\
    $ more dat1.csv\n\
    date,customer\n\
    20081201,A\n\
    20081202,A\n\
    20081202,B\n\
    20081202,B\n\
    20081203,C\n\
    $ muniq k=date i=dat1.csv o=rsl1.csv\n\
    #END# kguniq i=dat1.csv k=date o=rsl1.csv\n\
    $ more rsl1.csv\n\
    date%0,customer\n\
    20081201,A\n\
    20081202,B\n\
    20081203,C\n\
\n\
例2: 複数の項目での重複行の削除\n\
\n\
dateとcustomer項目を単位に重複行を削除し単一にする。\n\
\n\
    $ muniq k=date,customer i=dat1.csv o=rsl2.csv\n\
    #END# kguniq i=dat1.csv k=date,customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    date%0,customer%1\n\
    20081201,A\n\
    20081202,A\n\
    20081202,B\n\
    20081203,C\n\
";

