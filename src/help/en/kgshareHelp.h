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
/// kgshareHelp.h : kgshare help
// =============================================================================
_title="-";
_doc="\
\n\
MSHARE - CALCULATE COMPOSITION RATIO\n\
\n\
Calculate the composition ratio of the fields specified in f=, and add\n\
results as a new field.\n\
\n\
Format\n\
\n\
mshare f= [k=]  [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Calculate share value of field(s) (multiple fields can be specified) specified here.\n\
       Specify the new field name using : (colon). Example: f=Quantity:volume share.\n\
  k=   Specify the list of field name(s) (multiple items can be specified) as the unit to calculate share.\n\
       If the key is omitted, all lines are assumed to have the same key value.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the share of “quantity” and “amount” fields for each\n\
“customer”. Save the output in columns “volume share” and \"share\n\
amount”.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mshare k=customer f=quantity:qtyShare,amount:amountShare i=dat1.csv o=rsl1.csv\n\
    #END# kgshare f=quantity:qtyShare,amount:amountShare i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,quantity,amount,qtyShare,amountShare\n\
    A,1,10,0.3333333333,0.3333333333\n\
    A,2,20,0.6666666667,0.6666666667\n\
    B,1,15,0.2,0.3333333333\n\
    B,3,10,0.6,0.2222222222\n\
    B,1,20,0.2,0.4444444444\n\
";

