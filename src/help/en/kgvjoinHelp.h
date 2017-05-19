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
/// kgvjoinHelp.h : kgvjoin help
// =============================================================================
_title="-";
_doc="\
\n\
MVJOIN - JOIN REFERENCE VECTOR ELEMENTS \n\
\n\
Join vector elements with corresponding taxonomy elements from reference\n\
file with the same key. A vector field is shown in Table where the\n\
column item includes multiple elements separated by a space delimiter.\n\
\n\
Format\n\
\n\
mvjoin vf= [-A] K= f= [n=] m=| i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  vf=   Field name of vector (from i= input file) for joining.\n\
        Multiple fields can be specified. Sorting of the vectors is not required.\n\
  m=    Reference file.\n\
  K=    Specify key field in reference file (m=) where corresponding taxonomy elements are joined to the vector.\n\
        The sequence of vector should be unique, sorting is not required.\n\
        The output may differ if the string sequence is not unique.\n\
  f=    Field name of vector (element) for joining.\n\
  n=    Specify the replacement character when the key elements do not match in vf= and K= .\n\
        The vector (element) will not be joined with the reference file when this option not specified.\n\
\n\
Examples\n\
\n\
Example 1: Combine vector with elements from reference file\n\
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
    $ mvjoin vf=items K=item m=ref1.csv f=taxo i=dat1.csv o=rsl1.csv\n\
    #END# kgVjoin K=item f=taxo i=dat1.csv m=ref1.csv o=rsl1.csv vf=items\n\
    $ more rsl1.csv\n\
    items\n\
    b a c X X Y Z Z\n\
    c c Z Z Z Z\n\
    e a a X Y X Y\n\
\n\
Example 2: Join elements to multiple fields\n\
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
    $ mvjoin vf=items1,items2 K=item m=ref2.csv f=taxo i=dat2.csv o=rsl2.csv\n\
    #END# kgVjoin K=item f=taxo i=dat2.csv m=ref2.csv o=rsl2.csv vf=items1,items2\n\
    $ more rsl2.csv\n\
    items1,items2\n\
    b a c X X Y,b b X X\n\
    c c Y Y,a d X Y\n\
    e a a X X,a a X X\n\
";

