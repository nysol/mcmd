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
/// kgnewstrHelp.h : kgnewstr help
// =============================================================================
_title="-";
_doc="\
\n\
MNEWSTR - GENERATE FIXED STRING DATA\n\
\n\
Define the character string to generate at v= parameter, and pass the\n\
new column name at a= parameter. Multiple columns can be generated at a\n\
time.\n\
\n\
Format\n\
\n\
mnewstr a= [v=] [l=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=   Field name(s) of the new data.\n\
       Define multiple field names separated with a comma in between the field names.\n\
       This argument is not required when -nfn,-nfno options are specified.\n\
  v=   Specify the new character string to generate.\n\
       Define multiple field separated with a comma in between the values.\n\
       The number of fields must be the same as the number of field names defined at a=.\n\
  l=   Number of rows of random data to generate [default value:10].\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Generate a new dataset with characters strings custNo and A0001 printed\n\
in 5 rows, and name the fields as attribute and code respectively.\n\
\n\
    $ mnewstr a=attribute,code v=custNo,A0001 l=5 o=rsl1.csv\n\
    #END# kgnewstr a=attribute,code l=5 o=rsl1.csv v=custNo,A0001\n\
    $ more rsl1.csv\n\
    attribute,code\n\
    custNo,A0001\n\
    custNo,A0001\n\
    custNo,A0001\n\
    custNo,A0001\n\
    custNo,A0001\n\
";

