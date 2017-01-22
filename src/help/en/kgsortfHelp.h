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
/// kgsortfHelp.h : kgsortf help
// =============================================================================
_title="-";
_doc="\
\n\
MSORTF - SORT RECORDS\n\
\n\
Sort records according to the field defined at f= parameter.\n\
This commands uses quicksort algorithm and it is not a stable sort\n\
(original order is retained for rows with same key value).\n\
\n\
Format\n\
\n\
msortf f= [pways=] [maxlines=] [blocks=] [threadCnt=] [-noflg] [i=] [o=]\n\
[-assert_diffSize] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Specify the column name where record values will be sorted accordingly.\n\
       Four types of sequence order can be specified namely numeric, string, ascending, descending.\n\
       Specify %n after the field name, followed by n or r.\n\
       Character string ascending order:field name (% is not specified), character string descending order:f=field%r,\n\
       numeric ascending order:f=field%n, numeric descending order:f=field%nr.\n\
\n\
Examples\n\
\n\
Example 1: Basic example\n\
\n\
Sort by item and date.\n\
\n\
    $ more dat1.csv\n\
    item,date,quantity,price\n\
    B,20081201,4,40\n\
    A,20081201,10,200\n\
    A,20081201,10,100\n\
    B,20081203,5,50\n\
    B,20081201,2,500\n\
    A,20081201,3,300\n\
    $ msortf f=item,date i=dat1.csv o=rsl1.csv\n\
    #END# kgsortf f=item,date i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    item,date,quantity,price\n\
    A,20081201,10,200\n\
    A,20081201,10,100\n\
    A,20081201,3,300\n\
    B,20081201,4,40\n\
    B,20081201,2,500\n\
    B,20081203,5,50\n\
\n\
Example 2: Sort by quantity in descending order and price in ascending order.\n\
\n\
    $ msortf f=quantity%nr,price%n i=dat1.csv o=rsl2.csv\n\
    #END# kgsortf f=quantity%nr,price%n i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    item,date,quantity,price\n\
    A,20081201,10,100\n\
    A,20081201,10,200\n\
    B,20081203,5,50\n\
    B,20081201,4,40\n\
    A,20081201,3,300\n\
    B,20081201,2,500\n\
";

