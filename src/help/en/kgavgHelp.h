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
/// kgavgHelp.h : kgavg help
// =============================================================================
_title="-";
_doc="\
\n\
MAVG - CALCULATE AVERAGE\n\
\n\
Calculates the average values in column specified by the f= parameter.\n\
\n\
Format\n\
\n\
mavg f= [k=] [-n] [i=] [o=] [-option_assert_diffSize]\n\
[-option_assert_nullkey] [-option_assert_nullin]\n\
[-option_assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Specify the field(s) (multiple fields can be specified) with the values to be aggregated.\n\
       Use : (colon) to specify the new field name. Example: f=Quantity:AverageQuantity\n\
  k=   Specify the set of field name(s) (Multiple fields can be specified) as unit of aggregation.\n\
  -n   Output as NULL if the data consist at least one NULL value.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the average values of “Quantity” and “Amount” fields for each\n\
“Customer”, save the computed output in new columns named\n\
“AverageVolume” and “AverageAmount”.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,5\n\
    A,2,20\n\
    B,1,15\n\
    B,,10\n\
    B,5,20\n\
    $ mavg k=Customer f=Quantity:AvgQuantity,Amount:AvgAmount i=dat1.csv o=rsl1.csv\n\
    #END# kgavg f=Quantity:AvgQuantity,Amount:AvgAmount i=dat1.csv k=Customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    Customer%0,AvgQuantity,AvgAmount\n\
    A,1.5,12.5\n\
    B,3,15\n\
\n\
Example 2: Output consisting of NULL values\n\
\n\
Calculate the average values of “Quantity” and “Amount” fields for each\n\
“Customer”, save output in a new columns named “AverageVolume” and\n\
“AverageAmount”. When specifying the -n option, if a NULL value is\n\
included in the input, the result will return NULL value.\n\
\n\
    $ mavg k=Customer f=Quantity:AvgQuantity,Amount:AvgAmount -n i=dat1.csv o=rsl2.csv\n\
    #END# kgavg -n f=Quantity:AvgQuantity,Amount:AvgAmount i=dat1.csv k=Customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Customer%0,AvgQuantity,AvgAmount\n\
    A,1.5,12.5\n\
    B,,15\n\
\n\
Example 3: Calculate sum without key field\n\
\n\
Calculate the average values of “Quantity” and “Amount” fields, and save\n\
the outputs in columns “AvgQuantity” and “AvgAmount”.\n\
\n\
    $ mavg f=Quantity:AvgQuantity,Amount:AvgAmount i=dat1.csv o=rsl3.csv\n\
    #END# kgavg f=Quantity:AvgQuantity,Amount:AvgAmount i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    Customer,AvgQuantity,AvgAmount\n\
    B,2.25,14\n\
";

