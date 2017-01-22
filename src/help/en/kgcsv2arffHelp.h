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
/// kgcsv2arffHelp.h : kgcsv2arff help
// =============================================================================
_title="-";
_doc="\
\n\
MCSV2ARFF - CONVERT CSV TO ARFF FORMAT\n\
\n\
Convert csv formatted data into arff file (data format for WEKA). User\n\
must specify the type of attribute for arff, for instance, d= defines\n\
category format field, n= defines numeric format field, s= defines\n\
string format field, and finally, D= defines date format field. The date\n\
format includes time information when attached %t to date format field\n\
name.\n\
\n\
Format\n\
\n\
mcsv2arff n=|d=|D=|s= [T=] i= [o=] [-option_assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  n=   Numeric field name(s) (multiple items can be specified).\n\
  d=   Category field name(s) (multiple items can be specified).\n\
  D=   List of date (time) field name(s) (multiple items can be specified). [%t]\n\
       When %t is not specified：yyyyMMdd\n\
       When %t is specified　　　：yyyyMMddHHmmss\n\
  s=   Character string field names (multiple items can be specified).\n\
  T=   Title in character string.\n\
\n\
Examples\n\
\n\
Example 1: Convert csv format data to arff format\n\
\n\
Convert data to arff format and define “customer” field as string type,\n\
“product” field as category type, “date” field as date type (exclude\n\
time), “quantity” and “amount” fields as numeric attributes.\n\
\n\
    $ more dat1.csv\n\
    customer,product,date,quantity,amount\n\
    No.1,A,20081201,1,10\n\
    No.2,A,20081202,2,20\n\
    No.3,A,20081203,3,30\n\
    No.4,B,20081201,4,40\n\
    No.5,B,20081203,5,50\n\
    $ mcsv2arff s=customer d=product D=date n=quantity,amount T=Customer_Purchase_Data i=dat1.csv  o=rsl1.csv\n\
    #END# kgcsv2arff D=date T=Customer_Purchase_Data d=product i=dat1.csv n=quantity,amount o=rsl1.csv s=customer\n\
    $ more rsl1.csv\n\
    @RELATION	Customer_Purchase_Data\n\
\n\
    @ATTRIBUTE	customer	string\n\
    @ATTRIBUTE	date	date yyyyMMdd\n\
    @ATTRIBUTE	quantity	numeric\n\
    @ATTRIBUTE	amount	numeric\n\
    @ATTRIBUTE	product	{A,B}\n\
\n\
    @DATA\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
\n\
Example 2: Convert csv format data to arff format (include time in the date attribute)\n\
\n\
Specify the date with the time information by adding %t such that\n\
D=date%t.\n\
\n\
    $ more dat2.csv\n\
    customer,product,date,quantity,amount\n\
    No.1,A,20081201102030,1,10\n\
    No.2,A,20081202123010,2,20\n\
    No.3,A,20081203153010,3,30\n\
    No.4,B,20081201174010,4,40\n\
    No.5,B,20081203133010,5,50\n\
    $ mcsv2arff s=customer d=product D=date%t n=quantity,amount T=Customer_Purchase_Data i=dat2.csv  o=rsl2.csv\n\
    #END# kgcsv2arff D=date%t T=Customer_Purchase_Data d=product i=dat2.csv n=quantity,amount o=rsl2.csv s=customer\n\
    $ more rsl2.csv\n\
    @RELATION	Customer_Purchase_Data\n\
\n\
    @ATTRIBUTE	customer	string\n\
    @ATTRIBUTE	date	date yyyyMMddHHmmss\n\
    @ATTRIBUTE	quantity	numeric\n\
    @ATTRIBUTE	amount	numeric\n\
    @ATTRIBUTE	product	{A,B}\n\
\n\
    @DATA\n\
    No.1,20081201102030,1,10,A\n\
    No.2,20081202123010,2,20,A\n\
    No.3,20081203153010,3,30,A\n\
    No.4,20081201174010,4,40,B\n\
    No.5,20081203133010,5,50,B\n\
";

