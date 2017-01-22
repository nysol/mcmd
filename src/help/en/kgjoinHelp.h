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
/// kgjoinHelp.h : kgjoin help
// =============================================================================
_title="-";
_doc="\
\n\
MJOIN - JOIN FIELD(S) FROM REFERENCE FILE\n\
\n\
Compare the key field(s) from the input file specified at the k=\n\
parameter with the ones from the reference file, field from the\n\
reference file specified at f= parameter are joined for records with\n\
common key values in both files. The key fields from the reference file\n\
must be unique. Use the mnjoin command when there are more than one\n\
record with the same key values in the reference file. If f= is not set,\n\
all columns are joined except the key field in reference file.\n\
\n\
Format\n\
\n\
mjoin k= [f=] [K=] [-n] [-N] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   Specify the key field name from input data field and at the K= parameter.\n\
       Join records with the same field(s) from reference data.\n\
       Set to NULL value when key fields do not match with the fields from reference file specified at K=.\n\
  f=   Field name of the reference file to join.\n\
       When this parameter is not set, all fields except the key field will be joined.\n\
  m=   Specify list of reference file(s).\n\
       Read from standard input when this parameter is not set (used when input data is specified at i=).\n\
  K=   List of field names from reference data for matching.\n\
       Specify key field(s) from reference data to join with records with the key field from\n\
       the input data defined at the k= parameter.\n\
       Set to NULL value when key fields do not match with the fields from input file specified at k=.\n\
       The key field(s) name from the reference file does not need to be the same as the k= parameter.\n\
  -n   Output NULL values when reference data does not consist of input data.\n\
  -N   Output NULL values when input data does not consist of reference data.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Join the field cost from the reference file for records where the values\n\
of the item column from the input file is the same as the values in item\n\
column in the reference file.\n\
\n\
    $ more dat1.csv\n\
    item,date,price\n\
    A,20081201,100\n\
    A,20081213,98\n\
    B,20081002,400\n\
    B,20081209,450\n\
    C,20081201,100\n\
    $ more ref1.csv\n\
    item,cost\n\
    A,50\n\
    B,300\n\
    E,200\n\
    $ mjoin k=item f=cost m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgjoin f=cost i=dat1.csv k=item m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    item%0,date,price,cost\n\
    A,20081201,100,50\n\
    A,20081213,98,50\n\
    B,20081002,400,300\n\
    B,20081209,450,300\n\
\n\
Example 2: Output unmatched data\n\
\n\
Join the cost field for records with common key values in the item field\n\
from the input file and reference file, join cost item. At the same\n\
time, join all keys from the reference file if the value in the\n\
reference file is not in input data range, and set as NULL values.\n\
\n\
    $ mjoin k=item f=cost m=ref1.csv -n -N i=dat1.csv o=rsl2.csv\n\
    #END# kgjoin -N -n f=cost i=dat1.csv k=item m=ref1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    item%0,date,price,cost\n\
    A,20081201,100,50\n\
    A,20081213,98,50\n\
    B,20081002,400,300\n\
    B,20081209,450,300\n\
    C,20081201,100,\n\
    E,,,200\n\
";

