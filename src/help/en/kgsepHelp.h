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
/// kgsepHelp.h : kgsep help
// =============================================================================
_title="-";
_doc="\
\n\
MSEP - PARTITION RECORDS\n\
\n\
Define the file name and location the save the separate records at the\n\
d= parameter. Since it is possible to embed the ${fieldname} in the file\n\
name specified, as a result, the data can be split into separate files\n\
for corresponding fields. For example, the argument d=./out/${date}.csv\n\
specifies the out directory in the current directory, and the file is\n\
created from corresponding values in the date field.\n\
\n\
Format\n\
\n\
msep d= [-p] [f=]  [i=] [-assert_nullin] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  d=   Specify the field name used for splitting to different data files.\n\
       String specify here will be added as file name for each record.\n\
       Embed field name as ${field name}.\n\
  -p   Create the new directory name specify at the d= parameter which does not currently exist.\n\
\n\
Examples \n\
\n\
Example 1: Basic Example\n\
\n\
Create a directory named dat, and separate the data according to the\n\
date value in the directory.\n\
\n\
    $ more dat1.csv\n\
    item,date,quantity,price\n\
    A,20081201,1,10\n\
    B,20081201,4,40\n\
    A,20081202,2,20\n\
    A,20081203,3,30\n\
    B,20081203,5,50\n\
    $ msep d='./dat/${date}.csv' -p i=dat1.csv\n\
    #END# kgsep -p d=./dat/${date}.csv i=dat1.csv\n\
    $ ls ./dat\n\
    20081201.csv\n\
    20081202.csv\n\
    20081203.csv\n\
    $ more ./dat/20081201.csv\n\
    item,date%0,quantity,price\n\
    A,20081201,1,10\n\
    B,20081201,4,40\n\
    $ more ./dat/20081202.csv\n\
    item,date%0,quantity,price\n\
    A,20081202,2,20\n\
    $ more ./dat/20081203.csv\n\
    item,date%0,quantity,price\n\
    A,20081203,3,30\n\
    B,20081203,5,50\n\
    $ more ./dat/B.csv\n\
    ./dat/B.csv: No such file or directory\n\
";

