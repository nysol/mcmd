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
/// kgvsortHelp.h : kgvsort help
// =============================================================================
_title="-";
_doc="\
\n\
MVSORT - SORT VECTORS\n\
\n\
This command sort series of vectors in column. The vector in the fields\n\
shown in Table shows multiple character strings separated by space\n\
delimiter. Table - highlight examples sorting vectors.\n\
\n\
Format\n\
\n\
mvsort vf= [-A]  [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  vf=   Specify the field name(s) of vectors for sorting. Multiple fields can be specified.\n\
        Add n after % after field name to sort in ascending numerical order.\n\
        Add r after % after field name to sort in reverse order.\n\
        Add both n and r to sort in descending numerical order.\n\
\n\
Examples\n\
\n\
Example 1: Sort multiple vectors\n\
\n\
Sort item1 data series in ascending order and item2 in numerical\n\
ascending order.\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,10 2\n\
    c c,2 5 3\n\
    e a a,1\n\
    $ mvsort vf=items1%r,items2%n i=dat1.csv o=rsl1.csv\n\
    #END# kgvsort i=dat1.csv o=rsl1.csv vf=items1%r,items2%n\n\
    $ more rsl1.csv\n\
    items1,items2\n\
    c b a,2 10\n\
    c c,2 3 5\n\
    e a a,1\n\
";

