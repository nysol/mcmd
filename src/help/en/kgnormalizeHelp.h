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
/// kgnormalizeHelp.h : kgnormalize help
// =============================================================================
_title="-";
_doc="\
\n\
MNORMALIZE - NORMALIZATION\n\
\n\
Specify the field at the f= parameter, and specify the normalization\n\
method at c= parameter.\n\
\n\
Format\n\
\n\
mnormalize c= f= [k=] [i=] [o=] [bufcount=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  c=   Specify the normalisation method listed as follows.\n\
       z : z score : zi = (xi − m)/u (xi: inumber of data, m :arithmetic mean, u :standard deviation)\n\
       Z : deviation value : Zi = 50 + 10 × zi\n\
       range : use linear conversion to transform minimum value 0 to maximum value 1 ri = (xi − minx)/(maxx − minx)\n\
  f=   Specify the field to normalize here.\n\
       Specify the new field name after :(colon). Example: f=quantity:quantityNorm\n\
  k=   Key field name(s) [aggregate key break processing]\n\
       The key field specified is used as the unit for normalization.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Normalize (z score) quantity and amount field based on each customer,\n\
label the column names of the output as qtyNominal and amtNorminal\n\
respectively.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mnormalize c=z k=customer f=quantity:qtyNominal,amount:amtNorminal i=dat1.csv o=rsl1.csv\n\
    #END# kgnormalize c=z f=quantity:qtyNominal,amount:amtNorminal i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,quantity,amount,qtyNominal,amtNorminal\n\
    A,1,10,-0.7071067812,-0.7071067812\n\
    A,2,20,0.7071067812,0.7071067812\n\
    B,1,15,-0.5773502692,0\n\
    B,3,10,1.154700538,-1\n\
    B,1,20,-0.5773502692,1\n\
\n\
Example 2: Deviation value\n\
\n\
    $ mnormalize c=Z k=customer f=quantity:qtyNominal,amount:amtNorminal i=dat1.csv o=rsl2.csv\n\
    #END# kgnormalize c=Z f=quantity:qtyNominal,amount:amtNorminal i=dat1.csv k=customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer%0,quantity,amount,qtyNominal,amtNorminal\n\
    A,1,10,42.92893219,42.92893219\n\
    A,2,20,57.07106781,57.07106781\n\
    B,1,15,44.22649731,50\n\
    B,3,10,61.54700538,40\n\
    B,1,20,44.22649731,60\n\
\n\
Example 3: Linear transformation from 0 to 1\n\
\n\
    $ mnormalize c=range k=customer f=quantity:qtyNominal,amount:amtNorminal i=dat1.csv o=rsl3.csv\n\
    #END# kgnormalize c=range f=quantity:qtyNominal,amount:amtNorminal i=dat1.csv k=customer o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer%0,quantity,amount,qtyNominal,amtNorminal\n\
    A,1,10,0,0\n\
    A,2,20,1,1\n\
    B,1,15,0,0.5\n\
    B,3,10,1,0\n\
    B,1,20,0,1\n\
";

