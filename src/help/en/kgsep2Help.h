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
/// kgsep2Help.h : kgsep2 help
// =============================================================================
_title="-";
_doc="\
\n\
MSEP2 - SEPARATE RECORDS AND RETURN FIELDS TABLE \n\
\n\
Separate the data according to the value of the field(s) specified in\n\
k=. Partitioned data is automatically stored in numbered file name\n\
sequence. A table is created with the list of keys specified at k= and\n\
the corresponding file name for each key.\n\
\n\
Format\n\
\n\
msep2 k= O= a= [-p] [i=] [o=] [-assert_nullkey] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   List of field name(s) as unit of division.\n\
  O=   Create list of sequentially numbered file (serial number starting from 0) in the specified directory.\n\
  o=   Correspondence table with sequentially numbered file names and values specified as key at k= is output as CSV file.\n\
       Output is printed to standard output if this parameter is not specified.\n\
  a=   Field name of the path of output specified at o=.\n\
  -p   Force create directory specified by pathname at O=.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Split the data by corresponding values in item field. Output file names\n\
are sequential numbers starting from 0. The key and corresponding number\n\
is printed to table.csv.\n\
\n\
    $ more dat1.csv\n\
    item,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
    B,1\n\
    B,2\n\
    $ msep2 k=item O=./output a=fileName o=table.csv i=dat1.csv\n\
    #END# kgsep2 O=./output a=fileName i=dat1.csv k=item o=table.csv\n\
    $ ls ./output\n\
    0\n\
    1\n\
    $ more table.csv\n\
    item%0,fileName\n\
    A,./output/0\n\
    B,./output/1\n\
    $ more output/0\n\
    item%0,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
    $ more output/1\n\
    item%0,no\n\
    B,1\n\
    B,2\n\
\n\
Example 2: Multiple key fields\n\
\n\
Each file name is created according to the sequential number using\n\
item,no as the composite key field. The key field and its corresponding\n\
sequential file names are printed to table.csv.\n\
\n\
    $ more dat1.csv\n\
    item,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
    B,1\n\
    B,2\n\
    $ msep2 k=item,no O=./output2 a=fileName o=table.csv i=dat1.csv\n\
    #END# kgsep2 O=./output2 a=fileName i=dat1.csv k=item,no o=table.csv\n\
    $ ls ./output2\n\
    0\n\
    1\n\
    2\n\
    3\n\
    $ more table.csv\n\
    item%0,no%1,fileName\n\
    A,1,./output2/0\n\
    A,2,./output2/1\n\
    B,1,./output2/2\n\
    B,2,./output2/3\n\
    $ more output/0\n\
    item%0,no\n\
    A,1\n\
    A,1\n\
    A,2\n\
";

