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
/// kgcombiHelp.h : kgcombi help
// =============================================================================
_title="-";
_doc="\
\n\
MCOMBI - COMPUTE COMBINATION\n\
\n\
f= parameter specifys the set of fields, n= parameter defines the\n\
combination, and a=parameter specifies the output field name.\n\
Permutation output is possible by specifying -p option.\n\
\n\
Format\n\
\n\
mcombi a= f= n= [s=] [k=] [-p] [-dup] [i=] [o=]\n\
[-option_assert_diffSize] [-option_assert_nullin] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=     Name of the field to be added.\n\
  f=     Compute the combinations for the set of field name(s) (multiple fields can be specified) specified .\n\
         Enumerate all combinations of the array of values in the fields specified.\n\
  n=     Number of combinations.\n\
         When you increase the number of combinations, note that the number of output records will increase exponentially.\n\
  s=     After sorted by specified field (multiple fields can be specified), combinations of items specified in field f= are enumerated.\n\
  k=     List of key field name(s) (multiple fields can be specified)\n\
         Compute combinations based on the list of key field name(s).\n\
  -p     Compute the permutations.\n\
  -dup   Output combinations with the same value.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Enumerate all combinations of two items in the item field for each\n\
customer, and save the output in item1,item2. Fields not specified at\n\
k=,f= (item field in this case) remains after the key field column.\n\
\n\
    $ more dat1.csv\n\
    customer,item\n\
    A,a1\n\
    A,a2\n\
    A,a3\n\
    B,a4\n\
    B,a5\n\
    $ mcombi k=customer f=item n=2 a=item1,item2 i=dat1.csv o=rsl1.csv\n\
    #END# kgcombi a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,item,item1,item2\n\
    A,a3,a1,a2\n\
    A,a3,a1,a3\n\
    A,a3,a2,a3\n\
    B,a5,a4,a5\n\
\n\
Example 2: Basic Example 2\n\
\n\
When you specify the -dup option, the output includes combination of the\n\
same field.\n\
\n\
    $ mcombi k=customer f=item n=2 a=item1,item2 i=dat1.csv o=rsl2.csv -dup\n\
    #END# kgcombi -dup a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer%0,item,item1,item2\n\
    A,a3,a1,a1\n\
    A,a3,a1,a2\n\
    A,a3,a1,a3\n\
    A,a3,a2,a2\n\
    A,a3,a2,a3\n\
    A,a3,a3,a3\n\
    B,a5,a4,a4\n\
    B,a5,a4,a5\n\
    B,a5,a5,a5\n\
\n\
Example 3: Compute permutation\n\
\n\
Enumerate permutation of two items in the item field for each customer,\n\
and save the output in column item1,item2.\n\
\n\
    $ mcombi k=customer f=item n=2 a=item1,item2 -p i=dat1.csv o=rsl3.csv\n\
    #END# kgcombi -p a=item1,item2 f=item i=dat1.csv k=customer n=2 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer%0,item,item1,item2\n\
    A,a3,a1,a2\n\
    A,a3,a2,a1\n\
    A,a3,a1,a3\n\
    A,a3,a3,a1\n\
    A,a3,a2,a3\n\
    A,a3,a3,a2\n\
    B,a5,a4,a5\n\
    B,a5,a5,a4\n\
";

