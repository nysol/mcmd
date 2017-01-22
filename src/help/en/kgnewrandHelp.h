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
/// kgnewrandHelp.h : kgnewrand help
// =============================================================================
_title="-";
_doc="\
\n\
MNEWRAND - GENERATE DATASET WITH RANDOM NUMBERS\n\
\n\
Generate real random numbers from the range of 0.0 to 1.0. Use the -int\n\
option to generate randomized sequences of integers.\n\
\n\
This command uses Mersenne Twister to generate random numbers.\n\
(http://www.math.sci.hiroshima-u.ac.jp/ m-mat/MT/emt.html ,\n\
http://www.boost.org/doc/libs/1_54_0/doc/html/boost_random.html)。\n\
\n\
Format\n\
\n\
mnewrand a= [max=] [min=] [S=] [l=] [-int] [o=] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=     Name of column in the new dataset created.\n\
         This parameter is not required when -nfn,-nfno options are specified.\n\
  max=   Maximum value of random number [default value: INT_MAX]\n\
         -int must be specified with this parameter.\n\
  min=   Minimum value of random number [default value: 0]\n\
         -int must be specified with this parameter.\n\
  S=     Random seed [default value: current time]\n\
  l=     Number of lines [default value: 10]\n\
         Generate a new dataset with random numbers according to the number of rows specified.\n\
  -int   Generate random integers.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Generate 10 rows of random integers. Use a fixed random seed so that it\n\
will always return the same sequence of random numbers.\n\
\n\
    $ mnewrand a=rand S=1 o=rsl1.csv\n\
    #END# kgnewrand S=1 a=rand o=rsl1.csv\n\
    $ more rsl1.csv\n\
    rand\n\
    0.4170219984\n\
    0.9971848081\n\
    0.7203244893\n\
    0.9325573612\n\
    0.0001143810805\n\
    0.1281244478\n\
    0.3023325677\n\
    0.9990405154\n\
    0.1467558926\n\
    0.2360889763\n\
\n\
Example 2: Random Integers\n\
\n\
Use random seed 1 to generate 5 rows of random integers with minimum\n\
value of 10 and maximum value of 100.\n\
\n\
    $ mnewrand a=rand -int max=1000 min=0 l=5 S=1 o=rsl2.csv\n\
    #END# kgnewrand -int S=1 a=rand l=5 max=1000 min=0 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    rand\n\
    417\n\
    998\n\
    721\n\
    933\n\
    0\n\
\n\
Example 3: Generate Output without Header\n\
\n\
Specify -nfn option to generate random number data without header.\n\
\n\
    $ mnewrand -nfn l=5 S=1 o=rsl3.csv\n\
    #END# kgnewrand -nfn S=1 l=5 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    0.4170219984\n\
    0.9971848081\n\
    0.7203244893\n\
    0.9325573612\n\
    0.0001143810805\n\
";

