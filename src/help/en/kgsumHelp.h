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
/// kgsumHelp.h : kgsum help
// =============================================================================
_title="-";
_doc="\
\n\
MSUM - SUM OF COLUMN\n\
\n\
Aggregate the sum of values in the records at the specified field\n\
defined at f= parameter for records with the same key value defined at\n\
k=.\n\
\n\
Format\n\
\n\
msum f= [k=] [-n] [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   Specify list of field name(s) (multiple fields can be specified) as aggregate unit.\n\
  f=   Aggregate the values specified at the field(s) (multiple items can be specified). Records with NULL values are ignored.\n\
  -n   If NULL exist in the field defined at f=, the result will return NULL.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the total value of “quantity” and “amount” for each\n\
“customer”. Save the output with field names “total quantity” and “total\n\
amount”.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ msum k=customer f=quantity:quantitySum,amount:amountSum i=dat1.csv o=rsl1.csv\n\
    #END# kgsum f=quantity:quantitySum,amount:amountSum i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,quantitySum,amountSum\n\
    A,3,30\n\
    B,5,45\n\
";

