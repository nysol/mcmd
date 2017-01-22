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
/// kgdelnullHelp.h : kgdelnull help
// =============================================================================
_title="-";
_doc="\
\n\
MDELNULL - REMOVE ROWS WITH NULL VALUES\n\
\n\
Remove the row if values defined at f= parameter contain null value(s).\n\
\n\
Format\n\
\n\
mdelnull f= [k=] [u=] [-F] [-r] [-R]  [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Search NULL values in specified field name(s) (Multiple fields can be specified).\n\
  k=   Remove records with null values based on the same key field(s) defined (multiple fields can be specified).\n\
  u=   Print unmatched records to the output file specified.\n\
  -F   AND condition for multiple fields\n\
       Records consisting of null values in multiple fields defined at f= parameter will be selected and removed.\n\
  -r   Reverse selection\n\
       Selected records are not removed.\n\
  -R   AND condition for multiple records\n\
       Remove all records if the field with the same key field specified at the k= parameter contains NULL values.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Remove records where Quantity and Amount contain null values. Save\n\
records with null values to a separate file oth.csv.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,,20\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
    $ mdelnull f=Quantity,Amount u=oth.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgdelnull f=Quantity,Amount i=dat1.csv o=rsl1.csv u=oth.csv\n\
    $ more rsl1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    B,1,15\n\
    C,1,20\n\
    $ more oth.csv\n\
    Customer,Quantity,Amount\n\
    A,,20\n\
    B,3,\n\
\n\
Example 2: Select rows with NULL values\n\
\n\
Select records with NULL values by specifying -r.\n\
\n\
    $ mdelnull f=Quantity,Amount -r i=dat1.csv o=rsl2.csv\n\
    #END# kgdelnull -r f=Quantity,Amount i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Customer,Quantity,Amount\n\
    A,,20\n\
    B,3,\n\
\n\
Example 3: Remove records with the same key if any record contains NULL values\n\
\n\
Remove based on the aggregate key specified at k=. Remove records where\n\
Quantity and Amount contain null values for each customer.\n\
\n\
    $ mdelnull k=Customer f=Quantity,Amount i=dat1.csv o=rsl3.csv\n\
    #END# kgdelnull f=Quantity,Amount i=dat1.csv k=Customer o=rsl3.csv\n\
    $ more rsl3.csv\n\
    Customer%0,Quantity,Amount\n\
    C,1,20\n\
\n\
Example 4: AND condition between fields\n\
\n\
Remove the record where both Quantity and Amount fields contain null\n\
values.\n\
\n\
    $ more dat2.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,,\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
    $ mdelnull f=Quantity,Amount -F i=dat2.csv o=rsl4.csv\n\
    #END# kgdelnull -F f=Quantity,Amount i=dat2.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
\n\
Example 5: AND condition between records\n\
\n\
Remove the Customer record if all values in Quantity is NULL.\n\
\n\
    $ mdelnull k=Customer f=Quantity -R i=dat1.csv o=rsl5.csv\n\
    #END# kgdelnull -R f=Quantity i=dat1.csv k=Customer o=rsl5.csv\n\
    $ more rsl5.csv\n\
    Customer%0,Quantity,Amount\n\
    A,1,10\n\
    A,,20\n\
    B,1,15\n\
    B,3,\n\
    C,1,20\n\
";

