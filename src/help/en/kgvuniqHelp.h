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
/// kgvuniqHelp.h : kgvuniq help
// =============================================================================
_title="-";
_doc="\
\n\
MVUNIQ - UNIQUE VECTOR ELEMENTS\n\
\n\
This command merges duplicate elements in a vector. However, since the\n\
merging process uses a tree structure, the sequence of elements in the\n\
output maybe not be in order.\n\
\n\
When -n option is specified, the command reads the vector as a\n\
sequential series. The vector series is scanned from the beginning of\n\
the string, and output unique character strings in the vector.\n\
\n\
Format\n\
\n\
mvuniq vf= [-A] [-n] [i=] [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
  vf=   Specify the target field name(s) of vectors.\n\
        Multiple field name(s) of vectors can be specified.\n\
  -n    Merges same elements adjacent to each other in the vector.\n\
\n\
Examples\n\
\n\
Example 1: Merges vector elements in multiple fields\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,1 1\n\
    c c,2 2 3\n\
    e a a,3 1\n\
    $ mvuniq vf=items1,items2 i=dat1.csv o=rsl1.csv\n\
    #END# kgvuniq i=dat1.csv o=rsl1.csv vf=items1,items2\n\
    $ more rsl1.csv\n\
    items1,items2\n\
    a b c,1\n\
    c,2 3\n\
    a e,1 3\n\
";

