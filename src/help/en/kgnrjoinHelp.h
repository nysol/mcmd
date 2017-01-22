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
/// kgnrjoinHelp.h : kgnrjoin help
// =============================================================================
_title="-";
_doc="\
\n\
MNRJOIN - NATURAL JOIN WITHIN MULTIPLE RANGES WITH REFERENCE FILE\n\
\n\
Join columns according to the range of values in the column from\n\
reference file. The field specified at r= parameter is matched with the\n\
the range of values defined as two arguments at the R= parameter in the\n\
reference file defined at the m= parameter. the field(s) specified atf=\n\
parameter are joined for records with the same value.\n\
\n\
If there are more than one match for each record, natural join returns\n\
output for all rows. The range of values is compared as character\n\
strings by default. Attach %n after the field name at the r= parameter\n\
to process as numerical values.\n\
\n\
Format\n\
\n\
mnrjoin  R= r= [k=] [K=] [f=] [-n] [-N] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   The field name(s) (multiple fields can be specified) to join from the reference file.\n\
       When this is not defined, the all fields except the key specified at K= will be joined.\n\
  m=   Reference file name.\n\
       Read from standard input if this parameter is not set (when i= is specified).\n\
  R=   Field names of the range (limit to 2 fields).\n\
       Field names (start,end) of the range in reference file.\n\
       If the first field is NULL, the range is any number less than the ending value of the range.\n\
       If the second field is NULL, the range is any number greater than the starting value of the range.\n\
  r=   Compare the values in this field [%n] against the range.\n\
       Field name in the input file.\n\
       Add %n after the field name in the r= parameter to process as numerical values.\n\
  k=   Key field name(s) (multiple fields can be specified) from the input data for comparison\n\
       Join records with same key fields in the input data k= and reference data K=.\n\
  K=   Key field name(s) (multiple fields can be specified) from the reference data for comparison\n\
       This key field(s) from reference data is compared with the key field(s) from the input data\n\
       specified at k= parameter, fields where records with common key are joined.\n\
       This parameter is not required if the field name name is the same as the one defined at the k= parameter.\n\
  -n   Output NULL values when reference data does not consist of input data.\n\
  -N   Output NULL values when input data does not consist of reference data.\n\
\n\
For example, given the parameters\n\
k=key K=Key r=val%n R=range i=dat.csv m=ref.csv, if the sort criteria\n\
for the input data dat.csv is carried out by msortf f=key,val%n, the\n\
sort criteria for ref.csv should follow accordingly as\n\
msortf f=Key,range%n.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
For records where the value of date field is 20080203, select those\n\
records in the input data where amount field is more than 5 but less\n\
than 15 and join field where avg=150. For records where amount field is\n\
more than 40 but less than 50, join field avg=200.\n\
\n\
    $ more dat1.csv\n\
    date,price\n\
    20080123,10\n\
    20080123,20\n\
    20080203,10\n\
    20080203,35\n\
    200804l0,50\n\
    $ more ref1.csv\n\
    date,priceF,priceT,avg\n\
    20080203,5,15,150\n\
    20080203,40,50,200\n\
    $ mnrjoin k=date f=avg m=ref1.csv R=priceF,priceT r=price%n i=dat1.csv o=rsl1.csv\n\
    #END# kgnrjoin R=priceF,priceT f=avg i=dat1.csv k=date m=ref1.csv o=rsl1.csv r=price%n\n\
    $ more rsl1.csv\n\
    date%0,price,avg\n\
    20080203,10,150\n\
\n\
Example 2: Output unmatched data\n\
\n\
Use -n to return all records in the input data even if they do not match\n\
with those in the reference file (row where avg= Null), and use -N to\n\
return records in the reference file even if they do not match with\n\
those in the input file (rows where price= null). This is known as\n\
outer-join.\n\
\n\
    $ mnrjoin k=date f=avg m=ref1.csv R=priceF,priceT r=price%n -n -N i=dat1.csv o=rsl2.csv\n\
    #END# kgnrjoin -N -n R=priceF,priceT f=avg i=dat1.csv k=date m=ref1.csv o=rsl2.csv r=price%n\n\
    $ more rsl2.csv\n\
    date%0,price,avg\n\
    20080123,10,\n\
    20080123,20,\n\
    20080203,10,150\n\
    20080203,35,\n\
    20080203,,200\n\
    200804l0,50,\n\
";

