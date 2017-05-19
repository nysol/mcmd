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
/// kgvdelimHelp.h : kgvdelim help
// =============================================================================
_title="-";
_doc="\
\n\
MVDELIM - CHANGE VECTOR DELIMITER\n\
\n\
Change delimiter used to separate between string of characters in a\n\
vector. However, the delimiter will be removed if an empty string is\n\
specified as the delimiter.\n\
\n\
Format\n\
\n\
mvdelim vf= v= [-A]  [i=] [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  vf=   Field name of vector to replace the delimiter. Multiple fields can be specified.\n\
  v=    Define new delimiter. If the parameter is not defined, the delimiter is treated as an empty character.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Replace the default space delimiter to _(underscore).\n\
\n\
    $ more dat1.csv\n\
    item1\n\
    b a c\n\
    c c\n\
    e a a\n\
    $ mvdelim vf=item1 v=_ i=dat1.csv o=rsl1.csv\n\
    #END# kgvdelim i=dat1.csv o=rsl1.csv v=_ vf=item1\n\
    $ more rsl1.csv\n\
    item1\n\
    b_a_c\n\
    c_c\n\
    e_a_a\n\
\n\
Example 2: Comma\n\
\n\
In CSV data with comma delimited characters, when the delimiter of\n\
vector is replaced as comma, the entire vector is enclosed in double\n\
quotes to differentiate from the delimiter of CSV.\n\
\n\
    $ mvdelim vf=item1 v=, i=dat1.csv o=rsl2.csv\n\
    #END# kgvdelim i=dat1.csv o=rsl2.csv v=, vf=item1\n\
    $ more rsl2.csv\n\
    item1\n\
    \"b,a,c\"\n\
    \"c,c\"\n\
    \"e,a,a\"\n\
";

