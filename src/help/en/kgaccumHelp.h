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
/// kgaccumHelp.h : kgaccum help
// =============================================================================
_title="CUMULATIVE";
_doc="\
\n\
MACCUM CUMULATIVE CALCULATION\n\
\n\
Calculates the cumulative value for the column specified at f= parameter\n\
and save the result in a new column. Cumulative calculation is carried\n\
by the key unit when k= is specified.\n\
\n\
Format\n\
\n\
maccum f= s= [k=]  [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the cumulative values of “Quantity” and “Amount” fields for\n\
each “Customer”, save output as new data attributes in new columns named\n\
“AccumQuantity” and “AccumlAmount”.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ maccum s=Customer f=Quantity:AccumQuantity,Amount:AccumAmount i=dat1.csv o=rsl1.csv\n\
    #END# kgaccum f=Quantity:AccumQuantity,Amount:AccumAmount i=dat1.csv o=rsl1.csv s=Customer\n\
    $ more rsl1.csv\n\
    Customer%0,Quantity,Amount,AccumQuantity,AccumAmount\n\
    A,1,10,1,10\n\
    A,2,20,3,30\n\
    B,1,15,4,45\n\
    B,3,10,7,55\n\
    B,1,20,8,75\n\
\n\
Example 2: Specify Calculation by Key\n\
\n\
Calculates the cumulative value of “Quantity” and “Amount” fields for\n\
each “Customer”, and save the output in new columns named\n\
“AccumQuantity” and “AccumAmount”.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ maccum k=Customer s=Customer f=Quantity:AccumQuantity,Amount:AccumAmount i=dat1.csv o=rsl2.csv\n\
    #END# kgaccum f=Quantity:AccumQuantity,Amount:AccumAmount i=dat1.csv k=Customer o=rsl2.csv s=Customer\n\
    $ more rsl2.csv\n\
    Customer,Quantity,Amount,AccumQuantity,AccumAmount\n\
    A,1,10,1,10\n\
    A,2,20,3,30\n\
    B,1,15,1,15\n\
    B,3,10,4,25\n\
    B,1,20,5,45\n\
\n\
Example 3: Cumulative computation with NULL values\n\
\n\
Calculate the cumulative values of “Quantity” and “Amount” item, and\n\
save the output as new columns named “AccumQuantity” and “AccumAmount”.\n\
NULL values are ignored. Records with NULL values will be retained in\n\
the output.\n\
\n\
    $ more dat2.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,,20\n\
    B,1,15\n\
    B,3,\n\
    B,1,20\n\
    $ maccum s=Customer f=Quantity:AccumQuantity,Amount:AccumAmount i=dat2.csv o=rsl3.csv\n\
    #END# kgaccum f=Quantity:AccumQuantity,Amount:AccumAmount i=dat2.csv o=rsl3.csv s=Customer\n\
    $ more rsl3.csv\n\
    Customer%0,Quantity,Amount,AccumQuantity,AccumAmount\n\
    A,1,10,1,10\n\
    A,,20,,30\n\
    B,1,15,2,45\n\
    B,3,,5,\n\
    B,1,20,6,65\n\
";

