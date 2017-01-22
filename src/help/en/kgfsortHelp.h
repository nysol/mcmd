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
/// kgfsortHelp.h : kgfsort help
// =============================================================================
_title="-";
_doc="\
\n\
MFSORT - SORT FIELD\n\
\n\
Sort according to the values of the specified fields at f= within each\n\
record (in default ascending order by character string). Note that this\n\
does not change the sequence of field names.\n\
\n\
Format\n\
\n\
mfsort f= [-r] [-n] [i=] [o=] [-assert_diffSize] [-assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Specify multiple fields where data items are sorted. The result remains the same when one field is defined.\n\
  -n   Arrange in numerical order.\n\
  -r   Arrange in reverse order.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Arrange the values in v1,v2,v3 in ascending order for each record, and\n\
output the data items in sequential order corresponding to fields\n\
v1,v2,v3.\n\
\n\
    $ more dat1.csv\n\
    id,v1,v2,v3\n\
    1,b,a,c\n\
    2,a,b,a\n\
    3,b,,e\n\
    $ mfsort f=v* i=dat1.csv o=rsl1.csv\n\
    #END# kgfsort f=v* i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,v1,v2,v3\n\
    1,a,b,c\n\
    2,a,a,b\n\
    3,,b,e\n\
\n\
Example 2: Descending Order\n\
\n\
Add -r to arrange in descending order.\n\
\n\
    $ mfsort f=v* -r i=dat1.csv o=rsl2.csv\n\
    #END# kgfsort -r f=v* i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,v1,v2,v3\n\
    1,c,b,a\n\
    2,b,a,a\n\
    3,e,b,\n\
";

