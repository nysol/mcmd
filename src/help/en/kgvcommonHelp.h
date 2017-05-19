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
/// kgvcommonHelp.h : kgvcommon help
// =============================================================================
_title="-";
_doc="\
\n\
MVCOMMON - SELECT COMMON ELEMENTS OF VECTOR\n\
\n\
Within the vector, select common elements specified in reference file.\n\
\n\
Format\n\
\n\
mvcommon vf= [A=] K= [-r] m= | i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  vf=   Specify the field name(s) of vector (from i= input file) for matching.\n\
        Multiple fields can be specified. Sorting on vectors is not required.\n\
        Output of vector series can be defined with colon followed after the vector name.\n\
  m=    Reference file.\n\
  K=    Join key of reference file (m=) where corresponding taxonomy elements are joined to the vector.\n\
  -r    Select records where key elements that do no match in vf= and K= .\n\
\n\
Examples\n\
\n\
Example 1: Match common elements in multiple vectors\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,b b\n\
    c c,a d\n\
    e a a,a a\n\
    $ more ref1.csv\n\
    item\n\
    a\n\
    c\n\
    e\n\
    $ mvcommon vf=items1,items2 K=item m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgvcommon K=item i=dat1.csv m=ref1.csv o=rsl1.csv vf=items1,items2\n\
    $ more rsl1.csv\n\
    items1,items2\n\
    a c,\n\
    c c,a\n\
    e a a,a a\n\
\n\
Example 2: Print output to a new column\n\
\n\
Define new column name for item2 as new2.\n\
\n\
    $ mvcommon vf=items1,items2:new2 K=item m=ref1.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgvcommon K=item i=dat1.csv m=ref1.csv o=rsl2.csv vf=items1,items2:new2\n\
    $ more rsl2.csv\n\
    items1,items2,new2\n\
    a c,b b,\n\
    c c,a d,a\n\
    e a a,a a,a a\n\
";

