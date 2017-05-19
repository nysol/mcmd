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
/// kgvdelnullHelp.h : kgvdelnull help
// =============================================================================
_title="-";
_doc="\
\n\
MVDELNULL - REMOVE A NULL ELEMENT IN VECTOR \n\
\n\
Remove all NULL elements in the vector. If NULL element exist in vector,\n\
there will be consecutive delimiters of the elements. All vectors shown\n\
below contains NULL elements. However, for ease of reading, `\\n' is\n\
added at the end of each vector. Reading from the top row, the 3rd\n\
element, 1st element, 4th element are NULL.\n\
\n\
    a b  c\\n\n\
     a b\\n\n\
    a b c \\n\n\
\n\
Format\n\
\n\
mvdelnull vf= [-A]  i= [o=] [delim=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  vf=   Specify the field name (from input file i= ) which contains NULL element for removal.\n\
        Multiple files can be specified.\n\
  -A    Instead of replacing the specified item, this option\n\
        adds output as a new field.\n\
        When -A open is specified, the new field name must be specified after :(colon).\n\
        Example: f=quantity:substitution field name\n\
\n\
Examples\n\
\n\
Example 1: Basic example of removing null characters\n\
\n\
    $ more dat1.csv\n\
    items\n\
    b a  c\n\
     c c\n\
    e a   b \n\
    $ mvdelnull vf=items i=dat1.csv o=rsl1.csv\n\
    #END# kgvdelnull i=dat1.csv o=rsl1.csv vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    b a c\n\
    c c\n\
    e a b\n\
\n\
Example 2: Example of using .(dot) as delimiting character\n\
\n\
    $ more dat2.csv\n\
    items\n\
    b.a..c\n\
    .c.c\n\
    e.a...b.\n\
    $ mvdelnull vf=items delim=. i=dat2.csv o=rsl2.csv\n\
    #END# kgvdelnull delim=. i=dat2.csv o=rsl2.csv vf=items\n\
    $ more rsl2.csv\n\
    items\n\
    b.a.c\n\
    c.c\n\
    e.a.b\n\
\n\
Example 3: Add output as an new field by specifying -A\n\
\n\
    $ mvdelnull vf=items:new -A i=dat1.csv o=rsl3.csv\n\
    #END# kgvdelnull -A i=dat1.csv o=rsl3.csv vf=items:new\n\
    $ more rsl3.csv\n\
    items,new\n\
    b a  c,b a c\n\
     c c,c c\n\
    e a   b ,e a b\n\
";

