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
/// kgarff2csvHelp.h : kgarff2csv help
// =============================================================================
_title="-";
_doc="\
\n\
MARFF2CSV - CONVERSION FROM ARFF TO CSV FORMAT \n\
\n\
Convert data from arff format (data format for WEKA) to csv format.\n\
\n\
arff format data\n\
\n\
The arff data format is described below.\n\
\n\
    @RELATION       Title\n\
\n\
    @ATTRIBUTE      Field name    string(character string)\n\
    @ATTRIBUTE      Field name    date(date format:format is optional.\n\
                                    If not defined, \"yyyy-MM-dd'T'HH:mm:ss\"）\n\
    @ATTRIBUTE      Quantity    numeric(number)\n\
    @ATTRIBUTE      Product    {A,B}(category field type)\n\
\n\
    @DATA(Actual data)\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
\n\
Format\n\
\n\
marff2csv [i=] [o=] [-option_assert_nullout] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Convert customer purchasing data in arff format to csv format.\n\
\n\
    $ more dat1.arff\n\
    @RELATION       Customer Purchase Data\n\
\n\
    @ATTRIBUTE      Customer    string\n\
    @ATTRIBUTE      Date    date yyyyMMdd\n\
    @ATTRIBUTE      Quantity    numeric\n\
    @ATTRIBUTE      Amount    numeric\n\
    @ATTRIBUTE      Product    {A,B}\n\
\n\
    @DATA\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
    $ marff2csv i=dat1.arff  o=rsl1.csv\n\
    #END# kgarff2csv i=dat1.arff o=rsl1.csv\n\
    $ more rsl1.csv\n\
    Customer,Date,Quantity,Amount,Product\n\
    No.1,20081201,1,10,A\n\
    No.2,20081202,2,20,A\n\
    No.3,20081203,3,30,A\n\
    No.4,20081201,4,40,B\n\
    No.5,20081203,5,50,B\n\
";

