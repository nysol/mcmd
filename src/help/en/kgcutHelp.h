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
/// kgcutHelp.h : kgcut help
// =============================================================================
_title="-";
_doc="\
\n\
MCUT - SELECT COLUMN\n\
\n\
Extract the specified column(s). The specified column is removed with -r\n\
option.\n\
\n\
Format\n\
\n\
mcut f= [-r] [-nfni] [i=] [o=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=      Define name of column to be extracted\n\
          New column name for can be specified by defining the field name, followed by colon and the new field name.\n\
          ex. f=a:A,b:B\n\
  -r      Field removal switch\n\
          Remove all columns defined in the f= parameter.\n\
  -nfni   When header is not present in first row of the input data, position number of column is used to identify corresponding field(s).\n\
          New column name(s) for each column can be specified in the output file as follows.\n\
          Example f=0:date,2:store,3:quantity\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Extract customer and amount information from the data file dat1.csv\n\
Rename the column “amount ” to “sales” in the output.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mcut f=customer,amount:sales i=dat1.csv o=rsl1.csv\n\
    #END# kgcut f=customer,amount:sales i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,sales\n\
    A,10\n\
    A,20\n\
    B,15\n\
    B,10\n\
    B,20\n\
\n\
Example 2: Remove columns\n\
\n\
Remove columns customer and amount specified at -r.\n\
\n\
    $ mcut f=customer,amount -r i=dat1.csv o=rsl2.csv\n\
    #END# kgcut -r f=customer,amount i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    quantity\n\
    1\n\
    2\n\
    1\n\
    3\n\
    1\n\
\n\
Example 3: Data without field names\n\
\n\
Select columns 0, 2 from an input file without field header, add\n\
customer and amount as field names in the output file.\n\
\n\
    $ mcut f=0:customer,2:amount -nfni i=dat1.csv o=rsl3.csv\n\
    #END# kgcut -nfni f=0:customer,2:amount i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer,amount\n\
    customer,amount\n\
    A,10\n\
    A,20\n\
    B,15\n\
    B,10\n\
    B,20\n\
";

