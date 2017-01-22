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
/// kgproductHelp.h : kgproduct help
// =============================================================================
_title="-";
_doc="\
\n\
MPRODUCT - CARTESIAN JOIN WITH REFERENCE FILE\n\
\n\
Combine every row of column specified at f= parameter from the reference\n\
file at the m= parameter with every record from the input file.\n\
\n\
Format\n\
\n\
mproduct [f=] m=| i= [o=] [bufcount=] [-assert_diffSize]\n\
[-assert_nullin] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  f=   Combine field name(s) (multiple fields can be specified) from reference file.\n\
       All field(s) are combine if this parameter is not specified.\n\
  m=   Specify reference file name.\n\
       Read from standard input if this parameter is not defined (when i= is specified).\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Combine the ¥verb|date| column from reference file to the\n\
¥verb|customer| column from the input file.\n\
\n\
    $ more dat1.csv\n\
    customer\n\
    A\n\
    B\n\
    $ more ref1.csv\n\
    date\n\
    20090101\n\
    20090201\n\
    20090301\n\
    $ mproduct f=date m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgproduct f=date i=dat1.csv m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,date\n\
    A,20090101\n\
    A,20090201\n\
    A,20090301\n\
    B,20090101\n\
    B,20090201\n\
    B,20090301\n\
";

