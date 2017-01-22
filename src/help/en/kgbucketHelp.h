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
/// kgbucketHelp.h : kgbucket help
// =============================================================================
_title="-";
_doc="\
\n\
MBUCKET - PARTITION DATA INTO UNIFORM BUCKETS\n\
\n\
Partition numerical data field(s) specified at f= into a number of\n\
segments specified by n=. There are two ways to compute the bucket\n\
intervals. The first method is to compute an uniform spread of data\n\
points for each partition (referred to as partition of uniform buckets).\n\
The second method is to compute uniform interval ranges across\n\
partitions (referred to as partition of uniform ranges). Data is\n\
partitioned into equal interval ranges when the -rng option is\n\
specified. Otherwise, data will be partitioned uniformly across buckets\n\
if this option is not specified. When multiple fields are defined at f=,\n\
the data buckets are generated separately for each field.\n\
\n\
Format\n\
\n\
mbucket f= n= [-rng] [-r] [F=] [k=] [O=] [i=] [o=] [bufcount=]\n\
[-option_assert_diffSize] [-option_assert_nullkey]\n\
[-option_assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=     Partitioning is based on the value specified in this field (multiple fields can be specified).\n\
         Target partition field name:new field name\n\
  n=     Number of buckets\n\
         Specify the number of buckets to be partitioned for the field(s) defined in f= parameter(s).\n\
         If 1 is defined, the command will partition by the number of items specified in f= parameter.\n\
  F=     Output format [default value: 0]\n\
         Output format of bucket label.\n\
         0:Display bucket numbers\n\
         1:Display value range of buckets\n\
         2:Display both bucket numbers and value range of buckets.\n\
  k=     Key field(s) to retrieve rows of data incrementally for bucket partitions (multiple keys can be specified).\n\
  O=     Output file with values range of bucket\n\
         Specify output file name with values range of bucket on the field name(s) defined in parameter f=.\n\
  -rng   Define equal value of bucket range\n\
         Divide buckets by the specified value range.\n\
  -r     Print bucket numbers in reverse order.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Partition x and y into two subsets of equal extent and save the output\n\
file as rng.csv\n\
\n\
    $ more dat1.csv\n\
    id,x,y\n\
    A,2,7\n\
    B,6,7\n\
    C,5,6\n\
    D,7,5\n\
    E,6,4\n\
    F,1,3\n\
    G,3,3\n\
    H,4,2\n\
    I,7,2\n\
    J,2,1\n\
    $ mbucket f=x:xb,y:yb n=2 O=rng1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgbucket O=rng1.csv f=x:xb,y:yb i=dat1.csv n=2 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,x,y,xb,yb\n\
    A,2,7,1,2\n\
    B,6,7,2,2\n\
    C,5,6,2,2\n\
    D,7,5,2,2\n\
    E,6,4,2,2\n\
    F,1,3,1,1\n\
    G,3,3,1,1\n\
    H,4,2,1,1\n\
    I,7,2,2,1\n\
    J,2,1,1,1\n\
    $ more rng1.csv\n\
    fieldName,bucketNo,rangeFrom,rangeTo\n\
    x,1,,4.5\n\
    x,2,4.5,\n\
    y,1,,3.5\n\
    y,2,3.5,\n\
\n\
Example 2: Partition by equal range\n\
\n\
Use -rng option to partition the data by uniform value ranges.\n\
\n\
    $ mbucket f=x:xb,y:yb n=2 -rng O=rng2.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgbucket -rng O=rng2.csv f=x:xb,y:yb i=dat1.csv n=2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,x,y,xb,yb\n\
    A,2,7,1,2\n\
    B,6,7,2,2\n\
    C,5,6,2,2\n\
    D,7,5,2,2\n\
    E,6,4,2,2\n\
    F,1,3,1,1\n\
    G,3,3,1,1\n\
    H,4,2,2,1\n\
    I,7,2,2,1\n\
    J,2,1,1,1\n\
    $ more rng2.csv\n\
    fieldName,bucketNo,rangeFrom,rangeTo\n\
    x,1,,4\n\
    x,2,4,\n\
    y,1,,4\n\
    y,2,4,\n\
\n\
Example 3: Example using key field\n\
\n\
Partition x and y into two subsets of equal extent using “id” as the key\n\
parameter. By specifying n=2,3, field x is divided into 2 buckets, and\n\
field y is divided into 3 buckets. Include bucket numbers and value\n\
range of buckets in the output file (F=2).\n\
\n\
    $ more dat2.csv\n\
    id,x,y\n\
    A,2,7\n\
    A,6,7\n\
    A,5,6\n\
    B,7,5\n\
    B,6,4\n\
    B,1,3\n\
    C,3,3\n\
    C,4,2\n\
    C,7,2\n\
    C,2,1\n\
    $ mbucket k=id f=x:xb,y:yb n=2,3 F=2 i=dat2.csv o=rsl3.csv\n\
    #END# kgbucket F=2 f=x:xb,y:yb i=dat2.csv k=id n=2,3 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id%0,x,y,xb,yb\n\
    A,2,7,1:_3.5,2:6.5_\n\
    A,6,7,2:3.5_,2:6.5_\n\
    A,5,6,2:3.5_,1:_6.5\n\
    B,7,5,2:3.5_,3:4.5_\n\
    B,6,4,2:3.5_,2:3.5_4.5\n\
    B,1,3,1:_3.5,1:_3.5\n\
    C,3,3,1:_3.5,3:2.5_\n\
    C,4,2,2:3.5_,2:1.5_2.5\n\
    C,7,2,2:3.5_,2:1.5_2.5\n\
    C,2,1,1:_3.5,1:_1.5\n\
";

