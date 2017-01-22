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
/// kgteeHelp.h : kgtee help
// =============================================================================
_title="-";
_doc="\
\n\
MTEE - COPY TO MULTIPLE OUTPUT FILES\n\
\n\
Contents of input data are copied directly to multiple files and\n\
standard output.\n\
\n\
Format\n\
\n\
mtee [o=] [-nostdout] [i=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  o=          Output file names. The contents in the input file is duplicated into multiple files.\n\
              When this parameter is not defined, mtee copies input to standard output.\n\
  -nostdout   Copy to output file but not to standard output.\n\
\n\
Examples\n\
\n\
Example 1: Basic Examples\n\
\n\
Copy dat1.csv file to two files rsl1.csv and rsl2.csv In addition,\n\
display output on screen through standard output.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    $ mtee i=dat1.csv o=rsl1.csv,rsl2.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    #END# kgtee i=dat1.csv o=rsl1.csv,rsl2.csv\n\
    $ more rsl1.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    $ more rsl2.csv\n\
    customer,quantity,price\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
\n\
Example 2: Do not print to standard output \n\
\n\
When -nostdout is specified, the command only copy the two files\n\
rsl1.csv and rsl2.csv but not to standard output.\n\
\n\
    $ mtee i=dat1.csv o=rsl1.csv,rsl2,csv -nostdout\n\
    #END# kgtee -nostdout i=dat1.csv o=rsl1.csv,rsl2,csv\n\
";

