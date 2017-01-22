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
/// kgbestHelp.h : kgbest help
// =============================================================================
_title="-";
_doc="\
\n\
MBEST - SELECT ROWS \n\
\n\
Select records based on the specified row numbers. Note that row number\n\
starts at 0 (the first row of data starts at row 0 excluding the row of\n\
field names). Define the row numbers at from= and to= parameters (and\n\
size= parameter in some instances).\n\
\n\
Format\n\
\n\
mbest s= [R=] [from=] [to=|size=] [k=] [u=] [-r] [i=] [o=]\n\
[-option_assert_diffSize] [-option_assert_nullkey] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  s=      After sorted by specified field(s) (multiple fields can be specified), the rows are selected.\n\
          s= parameter is required if -q option is not specified.\n\
  from=   Define the start of row number (integers greater than 0) [default value: 0]\n\
  to=     Define the end of row number (integers greater than 0) [default value: 0]\n\
          Where [value of from= ] <= [value of to=] .\n\
  size=   Number of rows to select [default value: 1]\n\
          to= and size= cannot be specified at the same time.\n\
  k=      Key field (accept multiple key fields) [aggregate key break processing]\n\
          Records with same key values will be selected based on the defined rows at from=,to=,size=.\n\
          -x,-nfn options can be used to specify the field number (0〜).\n\
  u=      Output file of unmatched records.\n\
          Unmatched records the do not match the criteria is written to the defined file.\n\
  -r      Reverse selection\n\
          Select the rows other than the ones defined at the parameter from=,to=(size=).\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
This example assumed that the “quantity” and “amount” fields are sorted\n\
from the largest value (descending order). Records are selected from the\n\
first row (line 0) by default if from=,to=,size= parameters are not\n\
specified.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,20,5200 \n\
    B,18,4000   \n\
    C,15,3500 \n\
    D,10,2000 \n\
    E,3,800 \n\
    $ mbest s=Quantity%nr,Amount%nr i=dat1.csv o=rsl1.csv\n\
    #END# kgbest i=dat1.csv o=rsl1.csv s=Quantity%nr,Amount%nr\n\
    $ more rsl1.csv\n\
    Customer,Quantity%0nr,Amount%1nr\n\
    A,20,5200 \n\
\n\
Example 2: Basic Example 2\n\
\n\
After sorting by “customers”, select 3 rows from the first row (line 0).\n\
\n\
    $ mbest s=Customer from=0 size=3 i=dat1.csv o=rsl2.csv\n\
    #END# kgbest from=0 i=dat1.csv o=rsl2.csv s=Customer size=3\n\
    $ more rsl2.csv\n\
    Customer%0,Quantity,Amount\n\
    A,20,5200 \n\
    B,18,4000   \n\
    C,15,3500 \n\
\n\
Example 3: Basic Example 3\n\
\n\
Without sorting (in the original order), select from line 0 to line 1.\n\
\n\
    $ mbest -q from=0 to=1 i=dat1.csv o=rsl3.csv\n\
    #END# kgbest -q from=0 i=dat1.csv o=rsl3.csv to=1\n\
    $ more rsl3.csv\n\
    Customer,Quantity,Amount\n\
    A,20,5200 \n\
    B,18,4000   \n\
\n\
Example 4: Reverse Selection\n\
\n\
Select records other than customers’ first visit to store. Save the\n\
records of customers’ first visit to the file fvd.csv.\n\
\n\
    $ more dat2.csv\n\
    Customer,Date,Amount\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    $ mbest s=Customer,Date k=Customer -r u=fvd.csv i=dat2.csv o=rsl4.csv\n\
    #END# kgbest -r i=dat2.csv k=Customer o=rsl4.csv s=Customer,Date u=fvd.csv\n\
    $ more rsl4.csv\n\
    Customer,Date,Amount\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    $ more fvd.csv\n\
    Customer,Date,Amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
";

