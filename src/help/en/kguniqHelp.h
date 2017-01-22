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
_title="-";
_doc="\
\n\
MUNIQ - UNIQUE RECORDS\n\
\n\
Remove duplicate values and create unique records.\n\
\n\
Format\n\
\n\
muniq [k=]  [i=] [o=] [-assert_diffSize] [-assert_nullkey] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Remove duplicate records in the date field.\n\
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
Example 2: Delete duplicate rows in multiple columns\n\
\n\
Remove duplicate records based on unique values in date and customer\n\
field.\n\
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

