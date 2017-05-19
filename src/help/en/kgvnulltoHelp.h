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
/// kgvnulltoHelp.h : kgvnullto help
// =============================================================================
_title="-";
_doc="\
\n\
MVNULLTO - REPLACE NULL IN VECTOR ELEMENTS\n\
\n\
Replace NULL elements in the vector with an ad hoc value. If NULL\n\
element exist in the vector, there will be consecutive delimiters of the\n\
elements. All the vectors described below contain NULL element. However,\n\
for ease of reading, `\\n' is added at the end of each vector. Reading\n\
from the top row, the 3rd element, 1st element, and 4th element are\n\
NULL.\n\
\n\
    a b  c\\n\n\
     a b\\n\n\
    a b c \\n\n\
\n\
Format\n\
\n\
mvnullto vf= [v=|-p] [O=] [-A]  i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  vf=   Specify the field name (i=on file) to replace NULL.\n\
        Multiple items can be specified.\n\
  -A    Instead of replacing the specified item, this option adds output as a new field.\n\
  v=    Specify the replacement string.\n\
  -p    Replace NULL with the previous element. It can not be specified with v=.\n\
  O=    Replace all non-NULL elements with the string specified here.\n\
        Non-NULL value will not be replaced unless specified.\n\
        When -A open is specified, the new field name must be specified after :(colon).\n\
        Example: f=quantity:substitution field name\n\
\n\
Examples\n\
\n\
Example1: Replace null characters to the character string ’null’ \n\
\n\
    $ more dat1.csv\n\
    items\n\
    b a  c\n\
     c c\n\
    e a   b \n\
    $ mvnullto vf=items v=null i=dat1.csv o=rsl1.csv\n\
    #END# kgvnullto i=dat1.csv o=rsl1.csv v=null vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    b a null c\n\
    null c c\n\
    e a null null b null\n\
\n\
Example 2: Use .(dot) as delimiting character\n\
\n\
    $ more dat2.csv\n\
    items\n\
    b.a..c\n\
    .c.c\n\
    e.a...b.\n\
    $ mvnullto vf=items v=null delim=. i=dat2.csv o=rsl2.csv\n\
    #END# kgvnullto delim=. i=dat2.csv o=rsl2.csv v=null vf=items\n\
    $ more rsl2.csv\n\
    items\n\
    b.a.null.c\n\
    null.c.c\n\
    e.a.null.null.b.null\n\
\n\
Example 3: Replace null with the previous value\n\
\n\
    $ mvnullto vf=items -p i=dat1.csv o=rsl3.csv\n\
    #END# kgvnullto -p i=dat1.csv o=rsl3.csv vf=items\n\
    $ more rsl3.csv\n\
    items\n\
    b a a c\n\
     c c\n\
    e a a a b b\n\
\n\
Example 4: Replace all values except null by specifying O=\n\
\n\
    $ mvnullto vf=items v=null O=X i=dat1.csv o=rsl4.csv\n\
    #END# kgvnullto O=X i=dat1.csv o=rsl4.csv v=null vf=items\n\
    $ more rsl4.csv\n\
    items\n\
    X X null X\n\
    null X X\n\
    X X null null X null\n\
";

