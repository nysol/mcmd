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
/// kgtraHelp.h : kgtra help
// =============================================================================
_title="-";
_doc="\
\n\
MTRA - CONVERT VERTICAL DATA TO VECTOR\n\
\n\
Connect the items from the specified fields in f=, and save the string\n\
of items as a vector in a new column (referred to as transaction field).\n\
Specify the delimiter character of the items at delim=.\n\
\n\
Format\n\
\n\
mtra f= [s=] [k=] [delim=] [-r]   [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=       Specify field(s) (multiple fields can be specified) where the transaction fields are connected as an item.\n\
           NULL values will not be included in the vector.\n\
  k=       Key field name(s) (multiple items can be specified) of the character string pattern.\n\
           -r option cannot be specified with this parameter.\n\
  delim=   Specify the delimiting character (Space is used as the default delimiter).\n\
  -r       Reverse conversion\n\
           Convert transaction items column to vertically structured data.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Combine the corresponding item for each customer in a string using a\n\
space as the delimiter, and save output in the column named transaction.\n\
\n\
    $ more dat1.csv\n\
    customer,item\n\
    A,a\n\
    A,b\n\
    B,c\n\
    B,d\n\
    B,e\n\
    $ mtra k=customer f=item:transaction i=dat1.csv o=rsl1.csv\n\
    #END# kgtra f=item:transaction i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,transaction\n\
    A,a b\n\
    B,c d e\n\
\n\
Example 2: Use hyphen (-) as item delimiter\n\
\n\
    $ mtra k=customer f=item:transaction delim=- i=dat1.csv o=rsl2.csv\n\
    #END# kgtra delim=- f=item:transaction i=dat1.csv k=customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer%0,transaction\n\
    A,a-b\n\
    B,c-d-e\n\
\n\
Example 3: Convert items in descending sort order\n\
\n\
    $ mtra k=customer s=item%r f=item:transaction i=dat1.csv o=rsl3.csv\n\
    #END# kgtra f=item:transaction i=dat1.csv k=customer o=rsl3.csv s=item%r\n\
    $ more rsl3.csv\n\
    customer%0,transaction\n\
    A,b a\n\
    B,e d c\n\
";

