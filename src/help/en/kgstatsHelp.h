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
/// kgstatsHelp.h : kgstats help
// =============================================================================
_title="-";
_doc="\
\n\
MSTATS - CALCULATE STATISTICS OF 1 VARIABLE\n\
\n\
Specify the numeric fields in the parameter f=, and calculate the\n\
statistics specified in the parameter c=. Specify the aggregate key unit\n\
at k=. NULL value in the specified field(s) at f= are ignored. However,\n\
if all records include NULL values, NULL values will be included in the\n\
output.\n\
\n\
Format\n\
\n\
mstats c= f= [k=] [-n]  [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   Compute aggregate statistics on the key field(s) specified (multiple fields can be specified).\n\
  f=   Fields for which statistics are computed (multiple fields can be specified).\n\
  c=   Statistics (select one from the list below)\n\
       sum|mean|count|ucount|devsq|var|uvar|sd|usd|USD|cv|min|qtile1|\n\
       median|qtile3|max|range|qrange|mode|skew|uskew|kurt|ukurt\n\
\n\
Examples\n\
\n\
Example 1: Basic \n\
\n\
Calculate the statistical sum of “quantity” and “amount” field for each\n\
“customer”.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,amount\n\
    A,1,10\n\
    B,5,20\n\
    B,2,10\n\
    C,1,15\n\
    C,3,10\n\
    C,1,21\n\
    $ mstats k=customer f=quantity,amount c=sum i=dat1.csv o=rsl1.csv\n\
    #END# kgstats c=sum f=quantity,amount i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,quantity,amount\n\
    A,1,10\n\
    B,7,30\n\
    C,5,46\n\
\n\
Example 2: Basic Example 2\n\
\n\
Calculate the statistical maximum value.\n\
\n\
    $ mstats k=customer f=quantity,amount c=max i=dat1.csv o=rsl2.csv\n\
    #END# kgstats c=max f=quantity,amount i=dat1.csv k=customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer%0,quantity,amount\n\
    A,1,10\n\
    B,5,20\n\
    C,3,21\n\
";

