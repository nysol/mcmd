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
/// kgselHelp.h : kgsel help
// =============================================================================
_title="-";
_doc="\
\n\
MSEL - SELECT RECORDS WITH CONDITIONS\n\
\n\
Define the computation criteria at c= parameter, the record is selected\n\
if condition returns true. All operators and functions available in mcal\n\
command can be used in the conditional function. For more details,\n\
please refer to mcal.\n\
\n\
Format\n\
\n\
msel c=  [u=] [-r] [i=] [o=] [-assert_diffSize] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  c=   Define the expression using combinations of operators and functions.\n\
       Refer to mcal for more details.\n\
  o=   Records matching the condition will be printed to this output file.\n\
  u=   Records that do not match the condition will be printed to this output file.\n\
  -r   Reverse selection\n\
       Select records excluded from the selection condition defined in c=\n\
\n\
Examples\n\
\n\
Example 1: Basic example\n\
\n\
Select records where “Amount” is greater than 40. Write the unmatched\n\
records to a different output file file unmatch1.csv.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,30\n\
    B,3,40\n\
    B,1,50\n\
    $ msel c='${Amount}>40' u=unmatch1.csv i=dat1.csv o=match1.csv\n\
    #END# kgsel c=${Amount}>40 i=dat1.csv o=match1.csv u=unmatch1.csv\n\
    $ more match1.csv\n\
    Customer,Quantity,Amount\n\
    B,1,50\n\
    $ more unmatch1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,30\n\
    B,3,40\n\
\n\
Example 2: Selecting records with null value(s)\n\
\n\
No records will be selected when the condition defined c= returned a\n\
null value. Records that do not match the condition will be written to a\n\
separate file defined in u=.\n\
\n\
In the following example, the first three rows of data from column b are\n\
-1, null, and 1. When selecting records where b is greater than 0, the\n\
query record with a null value will be treated as an exception saved in\n\
the unmatched records file.\n\
\n\
    $ more dat2.csv\n\
    a,b\n\
    A,-1\n\
    B,\n\
    C,1\n\
    $ msel c='${b}>0' i=dat2.csv o=match2.csv u=unmatch2.csv\n\
    #END# kgsel c=${b}>0 i=dat2.csv o=match2.csv u=unmatch2.csv\n\
    $ more match2.csv\n\
    a,b\n\
    C,1\n\
    $ more unmatch2.csv\n\
    a,b\n\
    A,-1\n\
    B,\n\
\n\
Example 3: Specify -r option\n\
\n\
Null value is always evaluated as a unknown value regardless of the\n\
condition. Thus, records with null value is not selected.\n\
\n\
In the following example, the reverse selection parameter -r is used\n\
with the same condition in the previous example. Even though the\n\
selection criteria is inverted, the query record with a null value will\n\
be treated as an exception saved in the unmatched records file as in the\n\
previous example.\n\
\n\
    $ msel -r c='${b}>0' i=dat2.csv o=match3.csv u=unmatch3.csv\n\
    #END# kgsel -r c=${b}>0 i=dat2.csv o=match3.csv u=unmatch3.csv\n\
    $ more match3.csv\n\
    a,b\n\
    A,-1\n\
    $ more unmatch3.csv\n\
    a,b\n\
    B,\n\
    C,1\n\
";

