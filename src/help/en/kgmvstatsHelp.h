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
/// kgmvstatsHelp.h : kgmvstats help
// =============================================================================
_title="-";
_doc="\
\n\
MMVSTATS - COMPUTE STATISTICS OF SLIDING WINDOW\n\
\n\
Calculate various statistics (1 variable) for sliding windows. This a\n\
variant of the mstats command with functionality to compute sliding\n\
windows.\n\
\n\
Format\n\
\n\
mmvstats [s=] [k=] f= [t=] c= [skip=] -n  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  s=      After the specified field is sorted (multiple fields can be specified), various statistics is computed.\n\
          s= parameter is required when -q is not specified.\n\
  k=      Aggregate records using the specified field name(s) (multiple fields can be specified).\n\
  f=      Field name(s) (multiple fields can be specified) for computation .\n\
  t=      Integer interval greater than 1.\n\
  c=      Type of statistics (specify one of the following list)\n\
          sum|mean|devsq|var|uvar|sd|usd|cv|min|\n\
          |max|range|skew|uskew|kurt|ukurt\n\
          Refer to mstats for detailed definitions.\n\
  skip=   Specify the number of rows to hide from the top in the output.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate sum of sliding window. The first row is not printed as there\n\
is less than the required nubmer of intervals for computation.\n\
\n\
    $ more dat1.csv\n\
    id,value\n\
    1,5\n\
    2,1\n\
    3,3\n\
    4,4\n\
    5,4\n\
    6,6\n\
    7,1\n\
    8,4\n\
    9,7\n\
    $ mmvstats s=id f=value t=2 c=sum i=dat1.csv o=rsl1.csv\n\
    #END# kgmvstats c=sum f=value i=dat1.csv o=rsl1.csv s=id t=2\n\
    $ more rsl1.csv\n\
    id%0,value\n\
    2,6\n\
    3,4\n\
    4,7\n\
    5,8\n\
    6,10\n\
    7,7\n\
    8,5\n\
    9,11\n\
";

