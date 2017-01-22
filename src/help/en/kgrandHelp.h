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
/// kgrandHelp.h : kgrand help
// =============================================================================
_title="-";
_doc="\
\n\
MRAND - GENERATE RANDOM NUMBERS\n\
\n\
Generate random number from the range 0.0 to 0.1, or generate random\n\
integers from a defined range. Define output column name at a=\n\
parameter.\n\
\n\
This command uses Mersenne twister (developed in 1937) as pseudo random\n\
number generator.\n\
(http://www.math.sci.hiroshima-u.ac.jp/ m-mat/MT/emt.html ,\n\
http://www.boost.org/doc/libs/1_54_0/doc/html/boost_random.html).\n\
\n\
Format\n\
\n\
mrand [k=] a= [max=] [min=] [S=] [-int] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  k=     Same random number is generated for same key value at the specified key field.\n\
  a=     New column name. [However, this parameter is not required when -nfn,-nfno option is specified]\n\
  max=   Maximum value of random number [default value: INT_MAX]\n\
         Integer up to 0\\UTF{FF5E}2^32 [21 billion] ).\n\
         -int must be specified with this parameter.\n\
  min=   Minimum value of random number [default=0].\n\
         Integer up to 0\\UTF{FF5E}2^32 [21 billion]).\n\
         -int must be specified with this parameter.\n\
  S=     Random seed [default value: current time]\n\
         The same random seed generates the same random number\n\
         When S= is not specified, the default setting of random seed is set to the current time.\n\
         Random seed value can be specified between -2147483648〜2147483647.\n\
  -int   Generate random integers.\n\
\n\
Examples\n\
\n\
Example 1: Basic example\n\
\n\
Generate random real numbers between 0.0 to 1.0.\n\
\n\
    $ more dat1.csv\n\
    Customer\n\
    A\n\
    B\n\
    C\n\
    D\n\
    E\n\
    $ mrand a=rand i=dat1.csv o=rsl1.csv\n\
    #END# kgrand a=rand i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    Customer,rand\n\
    A,0.6892393918\n\
    B,0.1042782064\n\
    C,0.07767942664\n\
    D,0.6829032891\n\
    E,0.9111980933\n\
\n\
Example 2: Basic Example 2\n\
\n\
Generate random integers with -int.\n\
\n\
    $ mrand a=rand -int i=dat1.csv o=rsl2.csv\n\
    #END# kgrand -int a=rand i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Customer,rand\n\
    A,646494551\n\
    B,1824612880\n\
    C,1125031143\n\
    D,741644395\n\
    E,532560940\n\
\n\
Example 3: Specify the minimum and maximum value of the random number\n\
\n\
Generate a random number with a minimum value of 10 and maximum value of\n\
100. Add the random numbers to a new column named rand.\n\
\n\
    $ mrand a=rand -int min=10 max=100 S=1 i=dat1.csv o=rsl3.csv\n\
    #END# kgrand -int S=1 a=rand i=dat1.csv max=100 min=10 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    Customer,rand\n\
    A,47\n\
    B,100\n\
    C,75\n\
    D,94\n\
    E,10\n\
\n\
Example 4: Generate random number by key\n\
\n\
Given 4 customers A,B,C,D, same random number is generated for same\n\
customer.\n\
\n\
    $ more dat2.csv\n\
    Customer\n\
    A\n\
    A\n\
    A\n\
    B\n\
    B\n\
    C\n\
    D\n\
    D\n\
    D\n\
    $ mrand k=Customer -int min=0 max=1 a=rand i=dat2.csv o=rsl4.csv\n\
    #END# kgrand -int a=rand i=dat2.csv k=Customer max=1 min=0 o=rsl4.csv\n\
    $ more rsl4.csv\n\
    Customer%0,rand\n\
    A,0\n\
    A,0\n\
    A,0\n\
    B,0\n\
    B,0\n\
    C,0\n\
    D,0\n\
    D,0\n\
    D,0\n\
";

