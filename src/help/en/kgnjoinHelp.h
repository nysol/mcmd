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
/// kgnjoinHelp.h : kgnjoin help
// =============================================================================
_title="-";
_doc="\
\n\
MNJOIN - NATURAL JOIN WITH REFERENCE FILE\n\
\n\
A natural join selects rows from input data and reference file that have\n\
equal values in columns defined at k= parameter, the reference file is\n\
specified at the m= parameter, fields in the reference file specified at\n\
f= parameter is added through natural join. The difference with mjoin\n\
command is that key field(s) in the reference field is not unique.\n\
\n\
Given that the input data has n records with a certain key value, and\n\
the reference file has m records with the same key value, n × m records\n\
will be generated. In addition, if f= is not defined, all fields except\n\
the key field will be added.\n\
\n\
Format\n\
\n\
mnjoin k= [f=] [K=] [-n] [-N] m=| i= [o=] [bufcount=] [-nfn] [-nfno]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   key field name(s) from the input data for matching\n\
       This key field is specified in the input data and at the K= parameter.\n\
       Join rows when this fields matches with the fields from the reference data.\n\
  f=   Specify the field name(s) to join from the reference file.\n\
       When this parameter is not defined, all fields except the key field will be joined.\n\
  m=   Reference file name.\n\
       Read from standard input if this parameter is not set. (when i= is specified)\n\
  K=   Key field name(s) from the reference data for matching\n\
       This key field(s) from reference data is compared with the key field(s) from input data specified at k= parameter,\n\
       fields where records with common key are joined.\n\
       This parameter is not required if the field name in reference file is the same as the one defined at the k=parameter.\n\
  -n   Output NULL values when reference data does not consist of input data.\n\
  -N   Output NULL values when input data does not consist of reference data.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example \n\
\n\
The item field in the input file is compared with the item field from\n\
the reference file, add cost field for records with the same value.\n\
There are two records where item=A in both input file and reference\n\
file, therefore, 2×2=4 rows of item=A is written to the output file.\n\
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
    A,70\n\
    B,300\n\
    E,200\n\
    $ mnjoin k=item f=cost m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgnjoin f=cost i=dat1.csv k=item m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    item%0,date,price,cost\n\
    A,20081201,100,50\n\
    A,20081201,100,70\n\
    A,20081213,98,50\n\
    A,20081213,98,70\n\
    B,20081002,400,300\n\
    B,20081209,450,300\n\
\n\
Example 2: Ouput unmatched data\n\
\n\
Use -n to print records in the input data that do not match with those\n\
in the reference file (row where item=\"C\"), and use -N to print records\n\
in the reference file that do not match with those in the input file\n\
(row where item=\"E\").\n\
\n\
    $ more ref2.csv\n\
    item,cost\n\
    A,50\n\
    B,300\n\
    E,200\n\
    $ mnjoin k=item f=cost m=ref2.csv -n -N i=dat1.csv o=rsl2.csv\n\
    #END# kgnjoin -N -n f=cost i=dat1.csv k=item m=ref2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    item%0,date,price,cost\n\
    A,20081201,100,50\n\
    A,20081213,98,50\n\
    B,20081002,400,300\n\
    B,20081209,450,300\n\
    C,20081201,100,\n\
    E,,,200\n\
";

