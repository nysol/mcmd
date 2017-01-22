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
/// kgpasteHelp.h : kgpaste help
// =============================================================================
_title="-";
_doc="\
\n\
MPASTE - MATCH AND MERGE FIELDS FROM REFERENCE FILE\n\
\n\
Merge input file with the reference file for matching rows. If data is\n\
different in size, merge with data with smaller size. It is also\n\
possible to match all data with different sizes with the inclusion of\n\
null values by specifying -n and -N.\n\
\n\
Format\n\
\n\
mpaste [f=] -n -N m=| i= [o=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  f=   field name(s) (multiple fields can be specified) to merge with reference file.\n\
       All fields except the key field are merged.\n\
  m=   Reference file name.\n\
       Read from standard input when this parameter is noted defined (when i= is specified).\n\
  -n   Output NULL values when input data does not consist of reference data.\n\
  -N   Output NULL values when reference data does not consist of input data.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
    $ more dat1.csv\n\
    id1\n\
    1\n\
    2\n\
    3\n\
    4\n\
    $ more ref1.csv\n\
    id2\n\
    a\n\
    b\n\
    c\n\
    d\n\
    $ mpaste m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgpaste i=dat1.csv m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id1,id2\n\
    1,a\n\
    2,b\n\
    3,c\n\
    4,d\n\
\n\
Example 2: Example of merging data of different sizes\n\
\n\
If the number of rows in the input file is different from the reference\n\
file , merge records according to the smaller file.\n\
\n\
    $ more ref2.csv\n\
    id2\n\
    a\n\
    b\n\
    $ mpaste m=ref2.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgpaste i=dat1.csv m=ref2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id1,id2\n\
    1,a\n\
    2,b\n\
\n\
Example 3: Outer join\n\
\n\
If there are less number of rows in the reference file, NULL values will\n\
be assigned to records that did not match with the input file when -n\n\
option is specified.\n\
\n\
    $ mpaste m=ref2.csv -n i=dat1.csv o=rsl3.csv\n\
    #END# kgpaste -n i=dat1.csv m=ref2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id1,id2\n\
    1,a\n\
    2,b\n\
    3,\n\
    4,\n\
\n\
Example 4: Define fields to join\n\
\n\
    $ more ref3.csv\n\
    id2,val\n\
    a,R0\n\
    b,R1\n\
    c,R2\n\
    d,R3\n\
    $ mpaste f=val m=ref3.csv i=dat1.csv o=rsl4.csv\n\
    #END# kgpaste f=val i=dat1.csv m=ref3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id1,val\n\
    1,R0\n\
    2,R1\n\
    3,R2\n\
    4,R3\n\
";

