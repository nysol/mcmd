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
/// kgduprecHelp.h : kgduprec help
// =============================================================================
_title="-";
_doc="\
\n\
MDUPREC - DUPLICATE RECORD\n\
\n\
Duplicate each record. Specify the number of rows to duplicate at n=,\n\
and duplicate records based on the field specified at f= parameter.\n\
\n\
Format\n\
\n\
mduprec f=|n= [i=] [o=] [-assert_diffSize] [-assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Duplicate records based on the values in the field name.\n\
       Duplicate the number of rows for each record based on the numeric values in the column.\n\
  n=   Number of records to duplicate\n\
       Specify the number of rows to duplicate for each record.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Generate multiple records of the data based on the numeric value in the\n\
“Quantity” field. Records containing NULL values will not be duplicated.\n\
\n\
    $ more dat1.csv\n\
    store,val\n\
    A,2\n\
    B,\n\
    C,5\n\
    $ mduprec f=val i=dat1.csv o=rsl1.csv\n\
    #END# kgduprec f=val i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    store,val\n\
    A,2\n\
    A,2\n\
    C,5\n\
    C,5\n\
    C,5\n\
    C,5\n\
    C,5\n\
\n\
Example 2: Define the number of rows to duplicate\n\
\n\
Duplicate two rows (n=2) for each record in the dataset.\n\
\n\
    $ mduprec n=2 i=dat1.csv o=rsl2.csv\n\
    #END# kgduprec i=dat1.csv n=2 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    store,val\n\
    A,2\n\
    A,2\n\
    B,\n\
    B,\n\
    C,5\n\
    C,5\n\
";

