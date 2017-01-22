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
/// kgmvsimHelp.h : kgmvsim help
// =============================================================================
_title="-";
_doc="\
\n\
MMVSIM - SLIDING WINDOWS SIMILARITY MEAUSRE\n\
\n\
Compute the similarity measure (bivariate statistics) using settings of\n\
sliding window. This is the sliding windows version of the msim command.\n\
The main difference between the two is that msim can only carry out\n\
similarity calculation for 1 target object, whereas mmvsim quantifies\n\
similarity between two objects.\n\
\n\
Format\n\
\n\
mmvsim [s=] [k=] f= c= a= [t=] [skip=] -n  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  s=      After the specified field is sorted (multiple fields can be specified), a variety of similarity computation is carried out.\n\
          s= parameter is required if -q is not specified.\n\
  k=      Aggregate records using the specified field name(s) (multiple fields can be specified).\n\
  f=      Field name(s) (multiple fields can be specified) for computation .\n\
  t=      Integer intervals that is greater than 1.\n\
  c=      Define measures of similarity (one from the following).\n\
          covar|ucovar|pearson|spearman|kendall|euclid|\n\
          cosine|cityblock|hamming|chi|phi|jaccard|support|lift\n\
          Refer to msim command for detailed definition.\n\
  skip=   Specify the number of rows to hide from the top in the output [default value:skip=(value of t= -1)]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the Pearson product-moment correlation coefficient for 3\n\
window intervals for fields x,y.\n\
\n\
    $ more dat1.csv\n\
    t,x,y\n\
    1,14,0.17\n\
    2,11,0.2\n\
    3,32,0.15\n\
    4,13,0.33\n\
    5,8,0.1\n\
    6,19,0.56\n\
    $ mmvsim s=t t=3 c=pearson f=x,y a=sim i=dat1.csv o=rsl1.csv\n\
    #END# kgmvsim a=sim c=pearson f=x,y i=dat1.csv o=rsl1.csv s=t t=3\n\
    $ more rsl1.csv\n\
    t%0,x,y,sim\n\
    3,32,0.15,-0.8746392857\n\
    4,13,0.33,-0.6515529194\n\
    5,8,0.1,-0.1164257338\n\
    6,19,0.56,0.9986254289\n\
";

