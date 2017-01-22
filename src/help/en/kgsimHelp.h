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
/// kgsimHelp.h : kgsim help
// =============================================================================
_title="-";
_doc="\
\n\
MSIM - CALCULATE SIMILARITY BETWEEN TWO VARIABLES\n\
\n\
Find out the degree of similarity between two variable fields (distance)\n\
at f= parameter, specify the degree of similarity (distance) function at\n\
c= parameter to derive the similarity matrix.\n\
\n\
Format\n\
\n\
msim c= f= [a=] [k=] [n=] [-d] [i=] [o=] [bufcount=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   Field(s) (multiple items can be specified) specified here is used as the unit of calculation.\n\
  f=   Field names for the calculation of degree of similarities between two fields.\n\
  c=   Specify the similarity measure(s) (distance) (multiple fields can be specified).\n\
       As shown in the example below, the field name of the similarity measure results can be defined by using a : (colon).\n\
       If the name of field is not defined with colon, the type of degree of similarity (distance) is used as the field name.\n\
       Example: msim f=x,y,z c=pearson:Pearson product-moment correlation coefficient,\n\
       euclid:Euclidean distance,cosine:Cosine\n\
       Similarity measure=covar|ucovar|pearson|spearman|kendall|euclid|cosine|\n\
         cityblock|hamming|chi|phi|jaccard|supportr|lift|confMax|\n\
         confMin|yuleQ|yuleY|kappa|oddsRatio|convMax|convMin\n\
  a=   Specify the field name that indicates the name of the two variables.\n\
       Specify the two arguments with a comma. Field names fld1,fld2 are used if a= is not defined.\n\
  -d   Output as diagonal matrix and upper triangular matrix.\n\
       Only the lower triangular matrix of similarity matrix is shown if -d option is not specified,\n\
       but both upper triangular matrix and diagonal matrix are shown by when -d option is specified.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the cosine and Pearson’s product-moment correlation\n\
coefficient for the combination of two items among x, y, z fields.\n\
\n\
    $ more dat1.csv\n\
    x,y,z\n\
    14,0.17,-14\n\
    11,0.2,-1\n\
    32,0.15,-2\n\
    13,0.33,-2\n\
    $ msim c=pearson,cosine f=x,y,z i=dat1.csv o=rsl1.csv\n\
    #END# kgsim c=pearson,cosine f=x,y,z i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    fld1,fld2,pearson,cosine\n\
    x,y,-0.5088704666,0.7860308044\n\
    x,z,0.1963041929,-0.5338153343\n\
    y,z,0.3311001423,-0.5524409416\n\
\n\
Example 2: Output diagonal matrix, the upper triangular matrix\n\
\n\
Calculate the cosine and Pearson’s product-moment correlation\n\
coefficient for the combination of two items between x, y, z fields\n\
(with d option).\n\
\n\
    $ msim c=pearson,cosine f=x,y,z -d i=dat1.csv o=rsl2.csv\n\
    #END# kgsim -d c=pearson,cosine f=x,y,z i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    fld1,fld2,pearson,cosine\n\
    x,x,1,1\n\
    x,y,-0.5088704666,0.7860308044\n\
    x,z,0.1963041929,-0.5338153343\n\
    y,x,-0.5088704666,0.7860308044\n\
    y,y,1,1\n\
    y,z,0.3311001423,-0.5524409416\n\
    z,x,0.1963041929,-0.5338153343\n\
    z,y,0.3311001423,-0.5524409416\n\
    z,z,1,1\n\
\n\
Example 3: Calculation based on key unit\n\
\n\
Calculate using key field as unit.\n\
\n\
    $ more dat2.csv\n\
    key,x,y,z\n\
    A,14,0.17,-14\n\
    A,11,0.2,-1\n\
    A,32,0.15,-2\n\
    B,13,0.33,-2\n\
    B,10,0.8,-5\n\
    B,15,0.45,-9\n\
    $ msim k=key c=pearson,cosine f=x,y,z i=dat2.csv o=rsl3.csv\n\
    #END# kgsim c=pearson,cosine f=x,y,z i=dat2.csv k=key o=rsl3.csv\n\
    $ more rsl3.csv\n\
    key%0,fld1,fld2,pearson,cosine\n\
    A,x,y,-0.8746392857,0.8472573627\n\
    A,x,z,0.3164384831,-0.521983618\n\
    A,y,z,0.1830936883,-0.6719258683\n\
    B,x,y,-0.7919009884,0.8782575583\n\
    B,x,z,-0.471446429,-0.9051543403\n\
    B,y,z,-0.1651896746,-0.8514129252\n\
\n\
Example 4: Specify the type of degree of similarity\n\
\n\
Using the data with 01 values, compute the phi coefficient and Hamming\n\
distance.\n\
\n\
    $ more dat3.csv\n\
    x,y,z\n\
    1,1,0\n\
    1,0,1\n\
    1,0,1\n\
    0,1,1\n\
    $ msim c=hamming,phi f=x,y,z i=dat3.csv o=rsl4.csv\n\
    #END# kgsim c=hamming,phi f=x,y,z i=dat3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    fld1,fld2,hamming,phi\n\
    x,y,0.75,-0.5773502692\n\
    x,z,0.5,-0.3333333333\n\
    y,z,0.75,-0.5773502692\n\
\n\
Example 5: Rename the column containing degree of similarity\n\
\n\
Using the data with 01 values, compute the phi coefficient and Hamming\n\
distance and change the output field name.\n\
\n\
    $ msim c=hamming:HammingDist,phi:PhiCoeff a=variable1,variable2 f=x,y,z i=dat3.csv o=rsl5.csv\n\
    #END# kgsim a=variable1,variable2 c=hamming:HammingDist,phi:PhiCoeff f=x,y,z i=dat3.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    variable1,variable2,HammingDist,PhiCoeff\n\
    x,y,0.75,-0.5773502692\n\
    x,z,0.5,-0.3333333333\n\
    y,z,0.75,-0.5773502692\n\
";

