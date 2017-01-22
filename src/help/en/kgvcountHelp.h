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
An example is shown in Table - .\n\
\n\
in.csv\n\
\n\
   no  items\n\
\n\
   1   a b c\n\
   2   a d\n\
   3   b f e f\n\
   4   \n\
\n\
  : Basic example\n\
\n\
mvcount vf=items:size i=in.csv\n\
\n\
  no   items     size\n\
  ---- --------- ------\n\
  1    a b c     3\n\
  2    a d       2\n\
  3    b f e f   4\n\
  4              0\n\
\n\
  : Basic example\n\
\n\
Format\n\
\n\
mvcount vf= [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
  vf=   Specify the field names (from input file i=) of vectors to count the number of elements.\n\
        Field name(s) of result(s) can be defined with : followed after the vector name.\n\
        Multiple vectors can be specified.\n\
";

