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
/// kghashsumHelp.h : kghashsum help
// =============================================================================
_title="-";
_doc="\
\n\
MHASHSUM - COMPUTE TOTAL SUM USING HASH\n\
\n\
Calculate the hash total value of the column specified at the f=\n\
parameter for each line item based on the key specified at the k=\n\
parameter.\n\
The processing speed of this command is faster than msum since key\n\
fields do not require prior sorting. However, variation in length of\n\
keys (different length of strings in field) will slow down the\n\
processing speed.\n\
User shall assess the usage of mhashsum and msum based on the contents\n\
of the data (Refer to “Benchmark” in the second half of this manual).\n\
\n\
Format\n\
\n\
mhashsum f= [hs=] [k=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  ----- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- --\n\
  f=    Compute the sum of of values in the column specified (Multiple fields can be specified)                                                                                \n\
        Specify the new field name after colon “:”. Example f=Quantity:TotalQuantity.                                                                                          \n\
  k=    Calculate the sum on the data series based on the key field(s) (Multiple keys can be specified.)                                                                       \n\
        This command do not use aggregate key break processing, prior sorting is not required.                                                                                 \n\
  hs=   Hash size [Default value: 199999]                                                                                                                                      \n\
        User shall specify the key size for data processing based on speed and memory consumption optimisation requirements. Prime number should be used as hash table size.   \n\
        The processing speed will slow down if the hash table is not big enough for data with large key size.                                                                  \n\
        A larger hash table will speed up processing but will also require more memory (Refer to “Benchmark” in the second half of this manual).                               \n\
        Estimating memory requirements: K*(24+F*16) byte, K: key size, F: number of fields specified f= parameter.                                                             \n\
  -n    Return NULL in output if there are null values in f=.                                                                                                                  \n\
  ----- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- --\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Calculate the total Quantity and total Amount for each Customer using\n\
the hash function.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity,Amount\n\
    A,1,\n\
    B,,15\n\
    A,2,20\n\
    B,3,10\n\
    B,1,20\n\
    $ mhashsum k=Customer f=Quantity,Amount i=dat1.csv o=rsl1.csv\n\
    #END# kghashsum f=Quantity,Amount i=dat1.csv k=Customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    Customer,Quantity,Amount\n\
    A,3,20\n\
    B,4,45\n\
\n\
Example 2: NULL value in output\n\
\n\
The output returns NULL if NULL value is present in Quantity and Amount.\n\
Use -n option to print the null value.\n\
\n\
    $ mhashsum k=Customer f=Quantity,Amount -n i=dat1.csv o=rsl2.csv\n\
    #END# kghashsum -n f=Quantity,Amount i=dat1.csv k=Customer o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Customer,Quantity,Amount\n\
    A,3,\n\
    B,,45\n\
";

