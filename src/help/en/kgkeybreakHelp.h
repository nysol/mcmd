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
/// kgkeybreakHelp.h : kgkeybreak help
// =============================================================================
_title="KEYBREAK";
_doc="\
\n\
MKEYBREAK KEYBREAK POINT\n\
\n\
Add an indicator to first rows and last rows of each key specified at k=\n\
parameter. The first row is indicated as 1 in the top field, and the\n\
same indicator is added to last row in the bot column. Records that are\n\
not in the first row nor last row will appear as NULL values.\n\
\n\
Format\n\
\n\
mkeybreak k= [s=] [a=] [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Sort the records by ¥verb|k1| field, add an indicator (1) to the first\n\
record (top field) and last record (bottom field) where k1 is key field.\n\
\n\
    $ more dat1.csv\n\
    id,k1,k2,val\n\
    1,A,a,1\n\
    2,A,b,2\n\
    3,A,b,3\n\
    4,B,a,4\n\
    5,B,a,5\n\
    $ mkeybreak k=k1 i=dat1.csv o=rsl1.csv\n\
    #END# kgkeybreak i=dat1.csv k=k1 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,k1%0,k2,val,top,bot\n\
    1,A,a,1,1,\n\
    2,A,b,2,,\n\
    3,A,b,3,,1\n\
    4,B,a,4,1,\n\
    5,B,a,5,,1\n\
\n\
Example 2: 2 key fields\n\
\n\
After fields k1 and k2 are sorted, the beginning of key field k1\n\
(topfield) and end (bottomfield) is marked (1).\n\
\n\
    $ mkeybreak s=k1,k2 k=k1 i=dat1.csv o=rsl2.csv\n\
    #END# kgkeybreak i=dat1.csv k=k1 o=rsl2.csv s=k1,k2\n\
    $ more rsl2.csv\n\
    id,k1,k2,val,top,bot\n\
    1,A,a,1,1,\n\
    2,A,b,2,,\n\
    3,A,b,3,,1\n\
    4,B,a,4,1,\n\
    5,B,a,5,,1\n\
";

