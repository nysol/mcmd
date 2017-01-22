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
/// kgmbucketHelp.h : kgmbucket help
// =============================================================================
_title="-";
_doc="\
\n\
MMBUCKET - MULTI-DIMENSIONAL UNIFORM BUCKET PARTITION\n\
\n\
Segment numerical values in multiple fields specified at f= into equal\n\
sized buckets. For example, set f=a,b,c and n=5, mbucket command\n\
segments fields a,b,c into 5 equal buckets. Whereas mmbucket allocate\n\
items a,b,c into 3 dimensional space for each bucket (bucket number\n\
becomes 5³ = 125 ) such that each interval is distributed as evenly as\n\
possible.\n\
\n\
Format\n\
\n\
mmbucket f= n= [F=] [k=] [O=] [-ms] [-r] [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=    Values in this field(s) (multiple fields can be specified) is(are) partitioned.\n\
        When there are multiple fields, the number of dimensions is determined based on equal number of buckets.\n\
        When 1 field is specified, the result is the same as using mbucket.\n\
        -x,-nfn options can be used to specify field number (0〜).\n\
  n=    Each bucket size corresponds to a field specified at f=.\n\
        The number of items defined here is the same as the number of fields specified at f=.\n\
        However, if there is only 1 number specified, the same partition number is applied to other field.\n\
  F=    Ouput format [default value: 1]\n\
        Output format of bucket name.\n\
        0: Display bucket number.\n\
        1: Display value range of buckets.\n\
        2: Display both bucket number and value range.\n\
  k=    Unique key field(s) (multiple fields can be specified) to retrieve rows of data for partitioning into buckets.\n\
  O=    Specifies the output file with numeric range of each bucket from the items specified in the f= parameter.\n\
  -ms   When partitioning buckets for each field sequentially, the first item is changed multiple times\n\
        during the bucket partition trial.\n\
        For further information, refer to the “Introduction to Algorithms” to find out the best possible solution.\n\
  -r    Display bucket number in reverse order.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Partition the number of records in column x,y into two multi-dimentional\n\
equal subsets. At the same time, save the numeric range of each bucket\n\
in the file named rng.csv.\n\
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
    $ mmbucket f=x:xb,y:yb n=2,2 O=rng.csv i=dat1.csv o=rsl1.csv\n\
    calculating on dimension ... #0 #1 done. VAR=30 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=28 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=28\n\
    #END# kgmbucket O=rng.csv f=x:xb,y:yb i=dat1.csv n=2,2 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,x,y,xb,yb\n\
    A,2,7,1,2\n\
    B,6,7,2,2\n\
    C,5,6,2,2\n\
    D,7,5,2,2\n\
    E,6,4,2,1\n\
    F,1,3,1,1\n\
    G,3,3,1,1\n\
    H,4,2,2,1\n\
    I,7,2,2,1\n\
    J,2,1,1,1\n\
    $ more rng.csv\n\
    fieldName,bucketNo,rangeFrom,rangeTo\n\
    x,1,,3.5\n\
    x,2,3.5,\n\
    y,1,,4.5\n\
    y,2,4.5,\n\
\n\
Example 2: Outupt Format\n\
\n\
Partition the number of records in column x,y into two multi-dimentional\n\
equal subsets based on the id field. The output format shall display the\n\
both the bucket number and numeric range.\n\
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
    $ mmbucket k=id f=x:xb,y:yb n=2,2 F=2 i=dat2.csv o=rsl2.csv\n\
    calculating on dimension ... #0 #1 done. VAR=3 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=3\n\
    calculating on dimension ... #0 #1 done. VAR=3 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=3\n\
    calculating on dimension ... #0 #1 done. VAR=6 updated!\n\
    calculating on dimension ... #0 #1 done. VAR=6\n\
    #END# kgmbucket F=2 f=x:xb,y:yb i=dat2.csv k=id n=2,2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id%0,x,y,xb,yb\n\
    A,2,7,1:_3.5,2:6.5_\n\
    A,6,7,2:3.5_,2:6.5_\n\
    A,5,6,2:3.5_,1:_6.5\n\
    B,7,5,2:3.5_,2:4.5_\n\
    B,6,4,2:3.5_,1:_4.5\n\
    B,1,3,1:_3.5,1:_4.5\n\
    C,3,3,1:_3.5,2:1.5_\n\
    C,4,2,2:3.5_,2:1.5_\n\
    C,7,2,2:3.5_,2:1.5_\n\
    C,2,1,1:_3.5,1:_1.5\n\
";

