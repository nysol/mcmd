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
/// kghashavgHelp.h : kghashavg help
// =============================================================================
_title="-";
_doc="\
\n\
MHASHAVG - COMPUTE AVERAGE WITH HASH FUNCTION\n\
\n\
Calculate the average of data series specified at f= parameter based on\n\
the key at k= with hash function.\n\
\n\
The processing speed of this command is faster than mavg since the key\n\
fields do not have require prior sorting. However, variation in key\n\
lengths (different length of strings in field) will slow down the\n\
processing speed.\n\
\n\
Format\n\
\n\
mhashavg f= [hs=] [k=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=    Calculate the average of the field name (Multiple fields can be specified) .\n\
        Specify the new field name after colon “:”. Example: f=Quantity:AverageQuantity.\n\
  k=    Calculate the average on the data series based on the key field(s) (Multiple keys can be specified).\n\
        This command do not use aggregate key break processing, prior sorting is not required.\n\
  hs=   Hash size (Default value: 199999)\n\
        Refer to run:mhashsum.pdf for related information.\n\
  -n    Return NULL in output if there are null values in f=.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the average Quantity and average Amount for each Customer.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,\n\
    B,,15\n\
    A,2,20\n\
    B,3,10\n\
    B,1,20\n\
    $ mhashavg k=Customer f=Quantity,Amount i=dat1.csv o=rsl1.csv\n\
    #END# kghashavg f=Quantity,Amount i=dat1.csv k=Customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    Customer,Quantity,Amount\n\
    A,1.5,20\n\
    B,2,15\n\
\n\
Example 2: NULL value in output\n\
\n\
The output returns NULL if there NULL value is present in Quantity and\n\
Amount. Use -n option to print the null value.\n\
\n\
    $ mhashavg k=Customer f=Quantity,Amount -n i=dat1.csv o=rsl2.csv\n\
    #END# kghashavg -n f=Quantity,Amount i=dat1.csv k=Customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Customer,Quantity,Amount\n\
    A,1.5,\n\
    B,,15\n\
";

