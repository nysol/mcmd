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
/// kgnewnumberHelp.h : kgnewnumber help
// =============================================================================
_title="-";
_doc="\
\n\
MNEWNUMBER - GENERATE LIST OF SEQUENTIAL NUMBERS\n\
\n\
Define the start value of the alphabetic sequence at the S= parameter,\n\
set the the interval of alphabet sequence at I= parameter, and define\n\
the column name of the sequence at a= parameter. The alphabet sequence\n\
uses 26 alphabetic characters in base-26 from A to Z\n\
(A,B,…,Z,AA,AB,…,AZ,BA,BB,…,ZZ,AAA,AAB,…).\n\
\n\
Format\n\
\n\
mnewnumber a= [I=] [S=] [l=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=   Specify the field name of the list of new serials.\n\
       This parameter is not required when -nfn,-nfno option is specified.\n\
  I=   Interval between the sequence of numbers [default value: 1]\n\
  S=   Starting value/alphabet(upper case letters) [default value:1]\n\
       Assign either alphabet or numbers as the starting value of the sequence.\n\
       A list of serial numbers is generated when the starting numeric value is specified.\n\
       An alphabet sequence is generated when the starting alphabet is specified (cannot be specified in lowercase).\n\
  l=   Number of rows to generate [default value:10]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Generate a dataset with 5 sequential numbers starting from 1 incremented\n\
by 1. Name the sequence as No..\n\
\n\
    $ mnewnumber a=No. I=1 S=1 l=5 o=rsl1.csv\n\
    #END# kgNewnumber I=1 S=1 a=No. l=5 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    No.\n\
    1\n\
    2\n\
    3\n\
    4\n\
    5\n\
\n\
Example 2: Change the starting number and interval \n\
\n\
Generate a dataset consisting of 5 sequential numbers starting from 10\n\
with an incremental interval of 5. Name the sequence as No..\n\
\n\
    $ mnewnumber a=No. I=5 S=10 l=5 o=rsl2.csv\n\
    #END# kgNewnumber I=5 S=10 a=No. l=5 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    No.\n\
    10\n\
    15\n\
    20\n\
    25\n\
    30\n\
\n\
Example 3: Generate series of alphabet\n\
\n\
Generate a dataset consisting of 5 alphabet sequence starting from A\n\
with 1 alphabet in between. Name the sequence as No..\n\
\n\
    $ mnewnumber a=No. I=1 S=A l=5 o=rsl3.csv\n\
    #END# kgNewnumber I=1 S=A a=No. l=5 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    No.\n\
    A\n\
    B\n\
    C\n\
    D\n\
    E\n\
\n\
Example 4: Generate data without header\n\
\n\
Generate a dataset consisting of 11 alphabet sequence starting from B\n\
with 3 alphabets in between. Exclude the header from the output.\n\
\n\
    $ mnewnumber  -nfn  I=3 l=11 S=B o=rsl4.csv\n\
    #END# kgNewnumber -nfn I=3 S=B l=11 o=rsl4.csv\n\
    $ more rsl4.csv\n\
    B\n\
    E\n\
    H\n\
    K\n\
    N\n\
    Q\n\
    T\n\
    W\n\
    Z\n\
    AC\n\
    AF\n\
";

