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
/// kgvcatHelp.h : kgvcat help
// =============================================================================
_title="-";
_doc="\
\n\
MVCAT - COMBINE VECTORS\n\
\n\
Merge multiple vectors into one vector.\n\
\n\
Format\n\
\n\
mvcat vf= a= [-A] [i=] [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  vf=   Merge specified field names of vectors (from the input file i=).\n\
        Wildcard can be substituted for a character within the field name.\n\
  a=    Field name of the merged vector.\n\
  -A    Add results as a new field. If this option is not specified, the original field (vf=) will be removed.\n\
\n\
Examples\n\
\n\
Example 1: Merge vectors using wild character\n\
\n\
    $ more dat1.csv\n\
    items1,items2,items3,items4\n\
    b a c,b,x,y\n\
    c c,,x,y\n\
    e a a,a a a,x,y\n\
    $ mvcat vf=items* a=items i=dat1.csv o=rsl1.csv\n\
    #END# kgvcat a=items i=dat1.csv o=rsl1.csv vf=items*\n\
    $ more rsl1.csv\n\
    items\n\
    b a c b x y\n\
    c c x y\n\
    e a a a a a x y\n\
";

