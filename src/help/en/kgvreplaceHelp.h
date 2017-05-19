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
/// kgvreplaceHelp.h : kgvreplace help
// =============================================================================
_title="-";
_doc="\
\n\
MVREPLACE - REPLACE AN ELEMENT IN VECTOR\n\
\n\
Replace vector data with corresponding taxonomy character in the\n\
reference file joined by key. Table shows items in a vector with\n\
sequential elements separated by a space.\n\
\n\
Format\n\
\n\
mvreplace vf= K= f= [n=] m= [-A]  i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  vf=   Specify the field name of vector (from input file i=).\n\
        Multiple fields can be specified. Sorting on vectors is not required.\n\
  m=    Reference file\n\
  K=    Key field in reference file (m=) where corresponding taxonomy elements are joined with vector items.\n\
        The sequence of the vector is unique, sorting is not required.\n\
        The output may differ if the string sequence is not unique.\n\
  f=    Field name of vector for joining.\n\
  n=    Specify the replacement character when the elements that do not match in vf= and K= .\n\
        The element will not be joined with the reference file when this option not specified.\n\
\n\
Examples\n\
\n\
Example 1: Replace elements in a vector\n\
\n\
    $ more dat1.csv\n\
    items\n\
    b a c\n\
    c c\n\
    e a a\n\
    $ more ref1.csv\n\
    item,taxo\n\
    a,X Y\n\
    b,X\n\
    c,Z Z\n\
    $ mvreplace vf=items K=item m=ref1.csv f=taxo i=dat1.csv o=rsl1.csv\n\
    #END# kgVreplace K=item f=taxo i=dat1.csv m=ref1.csv o=rsl1.csv vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    X X Y Z Z\n\
    Z Z Z Z\n\
    e X Y X Y\n\
\n\
Example 2: Replace character in multiple elements\n\
\n\
    $ more dat2.csv\n\
    items1,items2\n\
    b a c,b b\n\
    c c,a d\n\
    e a a,a a\n\
    $ more ref2.csv\n\
    item,taxo\n\
    a,X\n\
    b,X\n\
    c,Y\n\
    d,Y\n\
    $ mvreplace vf=items1,items2 K=item m=ref2.csv f=taxo i=dat2.csv o=rsl2.csv\n\
    #END# kgVreplace K=item f=taxo i=dat2.csv m=ref2.csv o=rsl2.csv vf=items1,items2\n\
    $ more rsl2.csv\n\
    items1,items2\n\
    X X Y,X X\n\
    Y Y,X Y\n\
    e X X,X X\n\
";

