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
/// kgcrossHelp.h : kgcross help
// =============================================================================
_title="-";
_doc="\
\n\
MCROSS - CROSSTAB\n\
\n\
Build a crosstab. Transpose the fields specified at s= parameter\n\
horizontally, itemize the array of data specified at the f= parameter to\n\
the corresponding key specified at k=.\n\
\n\
Format\n\
\n\
mcross f= s= [a=] [k=] [v=] [i=] [o=] [-option_assert_diffSize]\n\
[-option_assert_nullkey] [-option_assert_nullin]\n\
[-option_assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Field name specified will become cross tab fact cell.\n\
       When multiple fields are specified, the variables will be transposed to multiple rows.\n\
       The fld field is created to identify multiple rows of the field.\n\
       Specify the name of field at f= as the column variable.\n\
       Use a= parameter to rename the field fld.\n\
  s=   Field names of transposed field.\n\
       The data series in the field becomes column name of transposed rows.\n\
  a=   Specify the field name to transpose the row of field names.\n\
       The field name is set to fld by default when this parameter is not defined.\n\
  k=   Key field name [aggregate key break processing]\n\
       Key to transpose data into horizontal rows.\n\
  v=   Null value replacement string\n\
       Replace null character with a character defined at v= parameter.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Expand the array of date horizontally and itemize quantity to the\n\
corresponding item.\n\
\n\
    $ more dat1.csv\n\
    item,date,quantity,price\n\
    A,20081201,1,10\n\
    A,20081202,2,20\n\
    A,20081203,3,30\n\
    B,20081201,4,40\n\
    B,20081203,5,50\n\
    $ mcross k=item f=quantity s=date i=dat1.csv o=rsl1.csv\n\
    #END# kgcross f=quantity i=dat1.csv k=item o=rsl1.csv s=date\n\
    $ more rsl1.csv\n\
    item%0,fld,20081201,20081202,20081203\n\
    A,quantity,1,2,3\n\
    B,quantity,4,,5\n\
\n\
Example 2: Restore the original input data\n\
\n\
Restore the output from Example 1 to the original input data with\n\
mcross.\n\
\n\
    $ more rsl1.csv\n\
    item%0,fld,20081201,20081202,20081203\n\
    A,quantity,1,2,3\n\
    B,quantity,4,,5\n\
    $ mcross k=item f=2008* s=fld a=date i=rsl1.csv o=rsl2.csv\n\
    #END# kgcross a=date f=2008* i=rsl1.csv k=item o=rsl2.csv s=fld\n\
    $ more rsl2.csv\n\
    item%0,date,quantity\n\
    A,20081201,1\n\
    A,20081202,2\n\
    A,20081203,3\n\
    B,20081201,4\n\
    B,20081202,\n\
    B,20081203,5\n\
\n\
Example 3: Crosstab with multiple fields\n\
\n\
Display crosstab results on two fields quantity,price.\n\
\n\
    $ mcross k=item f=quantity,price s=date i=dat1.csv o=rsl3.csv\n\
    #END# kgcross f=quantity,price i=dat1.csv k=item o=rsl3.csv s=date\n\
    $ more rsl3.csv\n\
    item%0,fld,20081201,20081202,20081203\n\
    A,quantity,1,2,3\n\
    A,price,10,20,30\n\
    B,quantity,4,,5\n\
    B,price,40,,50\n\
\n\
Example 4: Reverse data sequence\n\
\n\
Restore the sequence of the items that was expanded horizontally.\n\
\n\
    $ mcross k=item f=quantity,price s=date%r i=dat1.csv o=rsl4.csv\n\
    #END# kgcross f=quantity,price i=dat1.csv k=item o=rsl4.csv s=date%r\n\
    $ more rsl4.csv\n\
    item%0,fld,20081203,20081202,20081201\n\
    A,quantity,3,2,1\n\
    A,price,30,20,10\n\
    B,quantity,5,,4\n\
    B,price,50,,40\n\
";

