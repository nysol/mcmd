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
/// kgvcountHelp.h : kgvcount help
// =============================================================================
_title="-";
_doc="\
\n\
MVCOUNT - CALCULATE VECTOR SIZE\n\
\n\
Calculate the size of vector (number of elements in a vector) .\n\
\n\
Format\n\
\n\
mvcount vf= [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  vf=   Specify the field names (from input file i=) of vectors to count the number of elements.\n\
        Field name(s) of result(s) can be defined with : followed after the vector name.\n\
        Multiple vectors can be specified.\n\
\n\
Examples\n\
\n\
Example 1: Count multiple vectors\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,b\n\
    c c,\n\
    e a a,a a a\n\
    $ mvcount vf=items1:size1,items2:size2 i=dat1.csv o=rsl1.csv\n\
    #END# kgVcount i=dat1.csv o=rsl1.csv vf=items1:size1,items2:size2\n\
    $ more rsl1.csv\n\
    items1,items2,size1,size2\n\
    b a c,b,3,1\n\
    c c,,2,0\n\
    e a a,a a a,3,3\n\
";

