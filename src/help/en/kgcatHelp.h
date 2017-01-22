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
/// kgcatHelp.h : kgcat help
// =============================================================================
_title="-";
_doc="\
\n\
MCAT - CONCATENATE\n\
\n\
Merge all records in the files specified at i= parameter according to\n\
the order of files. If a wild card is used to specify file names, the\n\
files will be merged in alphabetical order of the file name.\n\
\n\
Format\n\
\n\
mcat [f=] [-skip_fnf] [-nostop|-skip|-force] [i=] [o=] [-add_fname]\n\
[-stdin] [-option_assert_diffSize] [-option_assert_nullin] [-nfn]\n\
[-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  i=           Specify list of input file names.\n\
               Read multiple CSV files separated by comma delimiter. Wild card characters can be used in file name.\n\
  f=           Specify the field name(s) to concatenate.\n\
               If f= is not specified, the field names defaults to the first file defined in the i= parameter.\n\
  -skip_fnf    If a specified file in the i= parameter does not exist, the program will bypass the error.\n\
               However, the program returns an error if all files cannot be found.\n\
  -nostop      -nostop,-skip,-force are parameters for controlling exceptions when header is not present.\n\
               -nostop flag returns null if field name is not specified. When -nfn flag is used with stop flag,\n\
               the program terminates if the number of items in the data is different than the parameter defined.\n\
  -skip        Files are not concatenated if field name(s) is not specified.\n\
               When -nfn flag is used with -skip flag, files are not concatenated if the number of data items are different.\n\
  -force       Force concatenation of files using location of fields when header is not present.\n\
               Print output to null if item number is not available.\n\
  -stdin       Merge from standard input.\n\
  -add_fname   Add file name in the last column.\n\
               Standard input will be named as /dev/stdin.\n\
               The field name for this option is fixed as \"fileName\",\n\
               error will be returned if input data contains the same field name.\n\
\n\
Examples\n\
\n\
Example 1: Concatenate files with the same header\n\
\n\
    $ more dat1.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    $ more dat2.csv\n\
    customer,date,amount\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    $ mcat i=dat1.csv,dat2.csv o=rsl1.csv\n\
    #END# kgcat i=dat1.csv,dat2.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
\n\
Example 2: Concatenate files with different header\n\
\n\
The first file dat1.csv defined at i= contains columns\n\
“customer,date,amount”. However, since “amount” is not present in\n\
dat3.csv, it will return an error. Nevertheless, the contents in the\n\
first file dat1.csv is merged and saved in the output.\n\
\n\
    $ more dat3.csv\n\
    customer,date,quantity\n\
    A,20081201,3\n\
    B,20081002,1\n\
    $ mcat i=dat1.csv,dat3.csv o=rsl2.csv\n\
    #ERROR# field name [amount] not found on file [dat3.csv] (kgcat)\n\
    $ more rsl2.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
\n\
Example 3: Concatenate files with different header2\n\
\n\
When previous example is attached with -nostop option, the command will\n\
continue processing and return NULL value for the data item not found.\n\
Other options such as skip,force handle conditions when the field name\n\
is not found. For details, refer to the description of parameters.\n\
\n\
    $ more dat3.csv\n\
    customer,date,quantity\n\
    A,20081201,3\n\
    B,20081002,1\n\
    $ mcat -nostop i=dat1.csv,dat3.csv o=rsl3.csv\n\
    #END# kgcat -nostop i=dat1.csv,dat3.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081201,\n\
    B,20081002,\n\
\n\
Example 4: Concatenate specific field names from input files\n\
\n\
Merge field names specified at f=.\n\
\n\
    $ mcat f=customer,date i=dat2.csv,dat3.csv o=rsl4.csv\n\
    #END# kgcat f=customer,date i=dat2.csv,dat3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    customer,date\n\
    A,20081207\n\
    A,20081213\n\
    B,20081209\n\
    A,20081201\n\
    B,20081002\n\
\n\
Example 5: Merge from standard input\n\
\n\
Read file dat2.csv from standard input by specifying -stdin option.\n\
\n\
    $ mcat -stdin i=dat1.csv o=rsl5.csv <dat2.csv\n\
    #END# kgcat -stdin i=dat1.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    customer,date,amount\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    A,20081201,10\n\
    B,20081002,40\n\
\n\
Example 6: Add file name as new column\n\
\n\
When -add_fname is specified, the original file name fileName is added\n\
as a new column. File name of standard input is /dev/stdin.\n\
\n\
    $ mcat -add_fname -stdin i=dat1.csv o=rsl6.csv <dat2.csv\n\
    #END# kgcat -add_fname -stdin i=dat1.csv o=rsl6.csv\n\
    $ more rsl6.csv\n\
    customer,date,amount,fileName\n\
    A,20081207,20,/dev/stdin\n\
    A,20081213,30,/dev/stdin\n\
    B,20081209,50,/dev/stdin\n\
    A,20081201,10,dat1.csv\n\
    B,20081002,40,dat1.csv\n\
\n\
Example 7: Specify wild card\n\
\n\
Specifying wild card dat*.csv to concatenate the three CSV files\n\
dat1.csv,dat2.csv,dat3.csv in the current directory.\n\
\n\
    $ more dat1.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    $ more dat2.csv\n\
    customer,date,amount\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    $ more dat3.csv\n\
    customer,date,quantity\n\
    A,20081201,3\n\
    B,20081002,1\n\
    $ mcat -force i=dat*.csv o=rsl7.csv\n\
    #END# kgcat -force i=dat*.csv o=rsl7.csv\n\
    $ more rsl7.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    A,20081201,3\n\
    B,20081002,1\n\
\n\
Example 8: Concatenate the same file multiple times\n\
\n\
Same file can be specified more than one time.\n\
\n\
    $ mcat i=dat1.csv,dat1.csv,dat1.csv o=rsl8.csv\n\
    #END# kgcat i=dat1.csv,dat1.csv,dat1.csv o=rsl8.csv\n\
    $ more rsl8.csv\n\
    customer,date,amount\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081201,10\n\
    B,20081002,40\n\
    A,20081201,10\n\
    B,20081002,40\n\
";

