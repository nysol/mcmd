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
/// kgcountHelp.h : kgcount help
// =============================================================================
_title="-";
_doc="\
\n\
MCOUNT - COUNT THE NUMBER OF ROWS\n\
\n\
Count the number of rows and store the results in a new column defined\n\
in a= parameter. Counting is carried out by each aggregate key when k=\n\
parameter is specified. Otherwise, if k= is not specified, all rows are\n\
counted.\n\
\n\
Format\n\
\n\
mcount a= [k=] [i=] [o=] [-nfn] [-nfno] [-option_assert_diffSize]\n\
[-option_assert_nullkey] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  a=   Specify the new field name to be added.\n\
       This parameter is not required when nfn option is specified.\n\
  k=   Key item(s) (Multiple keys can be specified) [aggregate key break processing]\n\
       Count the number of instances for incremental rows based on the key field(s) defined.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Count the number of rows by date, and save the results in a new column\n\
count.\n\
\n\
    $ more dat1.csv\n\
    date\n\
    20090109\n\
    20090109\n\
    20090109\n\
    20090110\n\
    20090110\n\
    $ mcount k=date a=count i=dat1.csv o=rsl1.csv\n\
    #END# kgcount a=count i=dat1.csv k=date o=rsl1.csv\n\
    $ more rsl1.csv\n\
    date%0,count\n\
    20090109,3\n\
    20090110,2\n\
\n\
Example 2: Count without aggregate key\n\
\n\
Count the number of rows without specifying the aggregate key.\n\
\n\
    $ mcount a=count i=dat1.csv o=rsl2.csv\n\
    #END# kgcount a=count i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    date,count\n\
    20090110,5\n\
";

