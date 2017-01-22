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
/// kgrjoinHelp.h : kgrjoin help
// =============================================================================
_title="-";
_doc="\
\n\
MRJOIN - JOIN REFERENCE FILE ACCORDING TO SPECIFIED RANGE\n\
\n\
Join fields from reference file according to specified range.\n\
\n\
The value specified at r= parameter from the input data is matched with\n\
the range (value that falls above the first row and less than the next\n\
row) from the reference file, and subsequently joined with the value\n\
from the field specified at f= parameter. Use mnrjoin to join with\n\
complex conditions using range values. Consider using chgnum if there\n\
are not a lot of range.\n\
\n\
Format\n\
\n\
mrjoin r= [k=] [K=] [R=] [f=] [-n] [-lo] [m=]  [i=] [o=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-assert_nullout]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=    The field name(s) (multiple fields can be specified) to join from the reference file.\n\
        When this is not defined, the all fields except the key specified at K= will be joined.\n\
  m=    Reference file name.\n\
        Read from standard input if this parameter is not set (when i= is specified).\n\
  r=    Field name of the range for comparison [%n]\n\
        Specify the field name from the input file.\n\
        After the specified field is sorted (multiple fields can be specified), fields are joined\n\
        The value is interpreted as numeric range when %n is specified, otherwise,\n\
        it is treated as character range.\n\
        The specified field should not contain NULL values or the data may not be processed properly.\n\
  R=    Field name containing range values in the reference file.\n\
        When this parameter is not defined, the range is processed at r= parameter by default.\n\
  k=    Key field name(s) (multiple fields can be specified) from the input data for comparison\n\
        Join records with same key fields in the input data k= and reference data K=.\n\
  K=    Key field name(s) (multiple fields can be specified) from the reference data for comparison\n\
        This key field(s) from reference data is compared with the key field(s) from the input data specified at k= parameter,\n\
        fields where records with common key are joined.\n\
        This parameter is not required if the field name name is the same as the one defined at the k= parameter.\n\
  -n    Output NULL values when reference data does not consist of input data.\n\
  -lo   left-open interval\n\
        The range with left open interval specified at R= parameter (greater than - below).\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Join category field low, middle,high to corresponding price range.\n\
\n\
    $ more dat1.csv\n\
    price\n\
    8\n\
    15\n\
    35\n\
    50\n\
    90\n\
    200\n\
    $ more ref1.csv\n\
    range,category\n\
    10,low\n\
    35,middle\n\
    80,high\n\
    100,\n\
    $ mrjoin r=price%n m=ref1.csv R=range f=category i=dat1.csv o=rsl1.csv\n\
    #END# kgrjoin R=range f=category i=dat1.csv m=ref1.csv o=rsl1.csv r=price%n\n\
    $ more rsl1.csv\n\
    price%0n,category\n\
    15,low\n\
    35,middle\n\
    50,middle\n\
    90,high\n\
\n\
Example 2: Basic Example 2\n\
\n\
    $ mrjoin -lo r=price%n m=ref1.csv R=range f=category i=dat1.csv o=rsl2.csv\n\
    #END# kgrjoin -lo R=range f=category i=dat1.csv m=ref1.csv o=rsl2.csv r=price%n\n\
    $ more rsl2.csv\n\
    price%0n,category\n\
    15,low\n\
    35,low\n\
    50,middle\n\
    90,high\n\
\n\
Example 3: Basic Example 3\n\
\n\
    $ mrjoin -n r=price%n m=ref1.csv R=range f=category i=dat1.csv o=rsl3.csv\n\
    #END# kgrjoin -n R=range f=category i=dat1.csv m=ref1.csv o=rsl3.csv r=price%n\n\
    $ more rsl3.csv\n\
    price%0n,category\n\
    8,\n\
    15,low\n\
    35,middle\n\
    50,middle\n\
    90,high\n\
    200,\n\
\n\
Example 4: Join with different ranges for corresponding products\n\
\n\
    $ more dat2.csv\n\
    item,price\n\
    A,10\n\
    A,20\n\
    B,10\n\
    B,20\n\
    $ more ref2.csv\n\
    item,price,category\n\
    A,10,low\n\
    A,15,high\n\
    A,100,\n\
    B,10,low\n\
    B,35,high\n\
    B,100,\n\
    $ mrjoin k=item r=price%n m=ref2.csv f=category i=dat2.csv o=rsl4.csv\n\
    #END# kgrjoin f=category i=dat2.csv k=item m=ref2.csv o=rsl4.csv r=price%n\n\
    $ more rsl4.csv\n\
    item%0,price%1n,category\n\
    A,10,low\n\
    A,20,high\n\
    B,10,low\n\
    B,20,low\n\
";

