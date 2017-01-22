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
/// kgnrcommonHelp.h : kgnrcommon help
// =============================================================================
_title="-";
_doc="\
\n\
MNRCOMMON - SELECT RECORDS WITHIN SPECIFIED RANGE(S) FROM REFERENCE FILE\n\
\n\
Select the record in the input file that matches the records within the\n\
defined range(s) defined from the reference file. k= parameter specifies\n\
the key field name from the input file to match with the key defined in\n\
K= from the reference file. The selection criteria is based on the data\n\
series from the input file defined in r= parameter for records that\n\
falls within the data range in the reference file defined in the R=\n\
parameter. Add %n after the item name if the field defined at r=\n\
parameter is a numerical value.\n\
\n\
Format\n\
\n\
mnrcommon [k=] R= r= [K=] [u=] [-r] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  k=   Key item(s) to match in the input file (Multiple keys can be specified).\n\
       The key(s) specified will be matched with the key field(s) at K= parameter from the reference file.\n\
  m=   Specify name of reference file.\n\
       Data is read from standard input if this parameter is not defined. (when i= is specified)\n\
  R=   Define the value range (start,end) in the reference file.\n\
       If the first argument is NULL means less than, if the second argument is NULL means more than.\n\
  r=   Field name of input file for range comparison. [%n]\n\
       Records in the input file that matches the key field specified in the k= parameter in the reference data is selected.\n\
       when processing as numeric value, %n will be added to field name defined at r= parameter.\n\
  K=   Key field(s) in the reference data for matching (Multiple keys can be specified)\n\
       The key specified will be matched with the key field defined in k= parameter from the input file.\n\
       Records in the input file that matches the key field specified in the k= parameter in the reference data is selected.\n\
  u=   Write unmatched records to this output file.\n\
  -r   Reverse selection\n\
       Select records that is not within the data range defined at R= parameter.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Select records where the transaction date is 20080203 with transaction\n\
“Amount” greater than 5 and less than 15 or greater than 40 and less\n\
than 50.\n\
\n\
    $ more dat1.csv\n\
    Date,Amount\n\
    20080123,10\n\
    20080203,10\n\
    20080203,20\n\
    20080203,45\n\
    200804l0,50\n\
    $ more ref1.csv\n\
    Date,AmountF,AmountT\n\
    20080203,5,15\n\
    20080203,40,50\n\
    $ mnrcommon k=Date m=ref1.csv R=AmountF,AmountT r=Amount%n i=dat1.csv o=rsl1.csv\n\
    #END# kgnrcommon R=AmountF,AmountT i=dat1.csv k=Date m=ref1.csv o=rsl1.csv r=Amount%n\n\
    $ more rsl1.csv\n\
    Date%0,Amount\n\
    20080203,10\n\
    20080203,45\n\
\n\
Example 2: Reverse selection\n\
\n\
Add -r option to reverse selection criteria.\n\
\n\
    $ mnrcommon k=Date m=ref1.csv R=AmountF,AmountT r=Amount%n -r i=dat1.csv o=rsl2.csv\n\
    #END# kgnrcommon -r R=AmountF,AmountT i=dat1.csv k=Date m=ref1.csv o=rsl2.csv r=Amount%n\n\
    $ more rsl2.csv\n\
    Date%0,Amount\n\
    20080123,10\n\
    20080203,20\n\
    200804l0,50\n\
";

