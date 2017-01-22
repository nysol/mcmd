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
/// kgselrandHelp.h : kgselrand help
// =============================================================================
_title="-";
_doc="\
\n\
MSELRAND - RANDOM SAMPLING\n\
\n\
Random selection of records based on the number of rows set at c= and p=\n\
parameters (random sampling without replacement). When k= is specified,\n\
a defined number of records with same key are randomly selected, when\n\
option -B specified at the same time, records are selected based in the\n\
key.\n\
\n\
This command used Mersenne twister (developed in 1937) as pseudo random\n\
number generator\n\
(http://www.math.sci.hiroshima-u.ac.jp/ m-mat/MT/emt.html ,\n\
http://www.boost.org/doc/libs/1_54_0/doc/html/boost_random.html).\n\
\n\
Format\n\
\n\
mselrand c=|p= [k=] [S=] [u=] [-B] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  c=   Select row(s) based on the number of keys and field specified.\n\
       This parameter must be specified when p= is not specified.\n\
  p=   Define the percentage of records for selection based on each key value.\n\
       This parameter must be specified if c= parameter is not specified.\n\
  k=   Select certain number of rows randomly from records with same key (Allow multiple fields).\n\
  S=   The same random seed generates the same row selection sequence.\n\
       The default setting of random seed is set to the current time if the random seed is not specified.\n\
       Range of random seed value is between -2147483648 - 2147483647.\n\
  u=   Print unmatched records to this output file.\n\
  -B   Selection based on key unit.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Randomly select 1 transaction for each customer.\n\
\n\
    $ more dat1.csv\n\
    Customer,Date,Amount\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    $ mselrand k=Customer c=1 S=1 i=dat1.csv o=rsl1.csv\n\
    #END# kgselrand S=1 c=1 i=dat1.csv k=Customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    Customer%0,Date,Amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
\n\
Example 2: Randomly select a percentage of records\n\
\n\
Select 50% of each customers’ records at random. Save other records to a\n\
separate file oth.csv.\n\
\n\
    $ mselrand k=Customer p=50 S=1 u=oth2.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgselrand S=1 i=dat1.csv k=Customer o=rsl2.csv p=50 u=oth2.csv\n\
    $ more rsl2.csv\n\
    Customer%0,Date,Amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    $ more oth2.csv\n\
    Customer%0,Date,Amount\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
\n\
Example 3: Select records by same key\n\
\n\
In the following example, select two out of the four customers A,B,C,D\n\
at random. Customer C,D is selected, and all records of customer C,D is\n\
printed to the output.\n\
\n\
    $ more dat2.csv\n\
    Customer,Date,Amount\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081210,60\n\
    D,20081201,70\n\
    D,20081205,80\n\
    D,20081209,90\n\
    $ mselrand k=Customer c=2 S=1 -B i=dat2.csv o=rsl3.csv\n\
    #END# kgselrand -B S=1 c=2 i=dat2.csv k=Customer o=rsl3.csv\n\
    $ more rsl3.csv\n\
    Customer%0,Date,Amount\n\
    C,20081210,60\n\
    D,20081201,70\n\
    D,20081205,80\n\
    D,20081209,90\n\
";

