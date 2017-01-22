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
/// kgtraflgHelp.h : kgtraflg help
// =============================================================================
_title="-";
_doc="\
\n\
MTRAFLG - CONVERT CROSS (PIVOT) TABLE TO TRANSACTION FIELDS\n\
\n\
Check whether the field(s) specified in the f= parameter contains NULL\n\
value. Fields with non-NULL values are connected as one item and saved\n\
as a new vector.\n\
\n\
Format\n\
\n\
mtraflg a= f= [delim=] [-r]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=       Specify the transaction field name.\n\
  f=       Check the values in the specified field name(s) (multiple fields can be specified) to create transaction data.\n\
           (-r option is specified, extract list of values as the field name of the transaction data)\n\
  delim=   Specify the character to separate each transaction field item (Default character is space if this parameter is omitted).\n\
           Character string should not be used. 1 byte character can be specified.\n\
  -r       Reverse conversion\n\
           Convert transaction based data to vertically structured data.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Create a string of vector from the list of non-null values in column egg\n\
and milk.\n\
\n\
    $ more dat1.csv\n\
    customer,egg,milk\n\
    A,1,1\n\
    B,,1\n\
    C,1,\n\
    D,1,1\n\
    $ mtraflg f=egg,milk a=transaction i=dat1.csv o=rsl1.csv\n\
    #END# kgtraflg a=transaction f=egg,milk i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,transaction\n\
    A,egg milk\n\
    B,milk\n\
    C,egg\n\
    D,egg milk\n\
\n\
Example 2: Basic Example 2\n\
\n\
Use -r option to revert the output results back to the original data.\n\
\n\
    $ mtraflg -r f=egg,milk a=transaction i=rsl1.csv o=rsl2.csv\n\
    #END# kgtraflg -r a=transaction f=egg,milk i=rsl1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer,egg,milk\n\
    A,1,1\n\
    B,,1\n\
    C,1,\n\
    D,1,1\n\
\n\
Example 3: Specify the delimiter\n\
\n\
Combine items using the “-” (hyphen) as delimiter. Save output in column\n\
named transaction.\n\
\n\
    $ mtraflg f=egg,milk a=transaction delim=- i=dat1.csv o=rsl3.csv\n\
    #END# kgtraflg a=transaction delim=- f=egg,milk i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer,transaction\n\
    A,egg-milk\n\
    B,milk\n\
    C,egg\n\
    D,egg-milk\n\
";

