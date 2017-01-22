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
/// kgsetstrHelp.h : kgsetstr help
// =============================================================================
_title="-";
_doc="\
\n\
MSETSTR - ADD STRING COLUMN\n\
\n\
Add specified string as new field(s) in all rows. More than one fields\n\
can be added.\n\
\n\
Format\n\
\n\
msetstr v= a=  [i=] [o=] [-assert_diffSize] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  v=   List of character strings to add.\n\
       NULL value is added if the value is not specified.\n\
  a=   Add field name.\n\
       The number of string and field name of specified at v= must be the same number. v=.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the date by setting a reference date (defined as January 01,\n\
2007) and add the string “20070101” in all lines and save the output as\n\
a new column named “ReferenceDate”.\n\
\n\
    $ more dat1.csv\n\
    customer,date\n\
    A,20081202\n\
    A,20081204\n\
    B,20081203\n\
    $ msetstr v=20070101 a=ReferenceDate i=dat1.csv o=rsl1.csv\n\
    #END# kgsetstr a=ReferenceDate i=dat1.csv o=rsl1.csv v=20070101\n\
    $ more rsl1.csv\n\
    customer,date,ReferenceDate\n\
    A,20081202,20070101\n\
    A,20081204,20070101\n\
    B,20081203,20070101\n\
\n\
Example 2: Add multiple fields\n\
\n\
    $ msetstr v=20070101,20070201 a=RefDate1,RefDate2 i=dat1.csv o=rsl2.csv\n\
    #END# kgsetstr a=RefDate1,RefDate2 i=dat1.csv o=rsl2.csv v=20070101,20070201\n\
    $ more rsl2.csv\n\
    customer,date,RefDate1,RefDate2\n\
    A,20081202,20070101,20070201\n\
    A,20081204,20070101,20070201\n\
    B,20081203,20070101,20070201\n\
\n\
Example 3: Add column with null values\n\
\n\
    $ msetstr v= a=NewColumn i=dat1.csv o=rsl3.csv\n\
    #END# kgsetstr a=NewColumn i=dat1.csv o=rsl3.csv v=\n\
    $ more rsl3.csv\n\
    customer,date,NewColumn\n\
    A,20081202,\n\
    A,20081204,\n\
    B,20081203,\n\
";

