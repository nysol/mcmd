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
/// kgmvavgHelp.h : kgmvavg help
// =============================================================================
_title="-";
_doc="\
\n\
MMVAVG - CALCULATE MOVING AVERAGE\n\
\n\
Calculate the moving average. The three different ways to calculate\n\
moving average include simple moving average (SMA), weighted moving\n\
average (WMA), and exponential moving average (EMA).\n\
\n\
Format\n\
\n\
mmvavg [s=] [k=] [n=] f= [t=] [-exp|-w] [alpha=] [skip=] [i=] [o=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [precision=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  s=       After the specified field is sorted (multiple fields can be specified), moving average is calculated.\n\
           s= parameter is required when -q option is not specified.\n\
  k=       Aggregate records using the specified field name(s) (multiple fields can as unit of calculation.\n\
  f=       Compute the moving averages of the field(s) (multiple fields can be specified).\n\
  t=       Interval numbers of integers greater than 1.\n\
           When -exp is used with alpha=, the t= parameter do not need to be defined.\n\
  -w       Linear weighted moving average.\n\
  -exp     Exponential smoothing moving average.\n\
  alpha=   Use a real number as smoothing coefficient when -exp is specified.\n\
           The default value of alpha is alpha=2/(value of = t+1)。\n\
  skip=    Specify the number of rows to hide from the top in the output.\n\
           Default value: skip=(value of t= -1), skip=0 when -exp is specified.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
The first row is not printed as there is less than the number of\n\
required intervals for computation.\n\
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
    $ mmvavg s=id f=value t=2 i=dat1.csv o=rsl1.csv\n\
    #END# kgmvavg f=value i=dat1.csv o=rsl1.csv s=id t=2\n\
    $ more rsl1.csv\n\
    id%0,value\n\
    2,3\n\
    3,2\n\
    4,3.5\n\
    5,4\n\
    6,5\n\
    7,3.5\n\
    8,2.5\n\
    9,5.5\n\
\n\
Example 2: Basic Example 2\n\
\n\
The first row is not printed as there is less than the number of\n\
required intervals for computation.\n\
\n\
    $ mmvavg s=id f=value t=2 -w i=dat1.csv o=rsl2.csv\n\
    #END# kgmvavg -w f=value i=dat1.csv o=rsl2.csv s=id t=2\n\
    $ more rsl2.csv\n\
    id%0,value\n\
    2,2.333333333\n\
    3,2.333333333\n\
    4,3.666666667\n\
    5,4\n\
    6,5.333333333\n\
    7,2.666666667\n\
    8,3\n\
    9,6\n\
\n\
Example 3: Basic Example 3\n\
\n\
Exponential smoothing moving average (-exp) includes the first row in\n\
the output.\n\
\n\
    $ mmvavg s=id f=value t=2 -exp i=dat1.csv o=rsl3.csv\n\
    #END# kgmvavg -exp f=value i=dat1.csv o=rsl3.csv s=id t=2\n\
    $ more rsl3.csv\n\
    id%0,value\n\
    1,5\n\
    2,2.333333333\n\
    3,2.777777778\n\
    4,3.592592593\n\
    5,3.864197531\n\
    6,5.288065844\n\
    7,2.429355281\n\
    8,3.47645176\n\
    9,5.82548392\n\
\n\
Example 4: An example of assigning key\n\
\n\
    $ more dat2.csv\n\
    id,key,value\n\
    1,a,5\n\
    2,a,1\n\
    3,a,3\n\
    4,a,4\n\
    5,a,4\n\
    6,b,6\n\
    7,b,1\n\
    8,b,4\n\
    9,b,7\n\
    $ mmvavg s=key,id k=key f=value t=2 i=dat2.csv o=rsl4.csv\n\
    #END# kgmvavg f=value i=dat2.csv k=key o=rsl4.csv s=key,id t=2\n\
    $ more rsl4.csv\n\
    id,key,value\n\
    2,a,3\n\
    3,a,2\n\
    4,a,3.5\n\
    5,a,4\n\
    7,b,3.5\n\
    8,b,2.5\n\
    9,b,5.5\n\
\n\
Example 5: Display all records including those that are less than the defined intervals \n\
\n\
    $ more dat3.csv\n\
    key,value\n\
    a,1\n\
    a,2\n\
    a,3\n\
    a,4\n\
    a,5\n\
    b,6\n\
    b,1\n\
    b,4\n\
    b,7\n\
    $ mmvavg -q k=key f=value t=2 skip=0 i=dat3.csv o=rsl5.csv\n\
    #END# kgmvavg -q f=value i=dat3.csv k=key o=rsl5.csv skip=0 t=2\n\
    $ more rsl5.csv\n\
    key,value\n\
    a,1\n\
    a,1.5\n\
    a,2.5\n\
    a,3.5\n\
    a,4.5\n\
    b,6\n\
    b,3.5\n\
    b,2.5\n\
    b,5.5\n\
";

