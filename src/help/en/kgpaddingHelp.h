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
/// kgpaddingHelp.h : kgpadding help
// =============================================================================
_title="-";
_doc="\
\n\
MPADDING - ROW PADDING\n\
\n\
Fill in values in between the records specified at f= parameter based on\n\
the key field specified at k= parameter. When v= parameter is specified,\n\
create padding records in between records with the specified string\n\
other than the fields specified at k=,f=. Create padding with null\n\
values when -n option is specified. (Note: previous item value will be\n\
used as padding if both v= and -n parameters are not specified)\n\
\n\
Format\n\
\n\
mpadding [k=] f= [v=] [S=] [E=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Create padding with integer values (type=int) between records in no\n\
column. Insert 4,5 between 3 and 6, and 7 between 6 and 8.\n\
\n\
    $ more dat1.csv\n\
    no\n\
    3\n\
    6\n\
    8\n\
    $ mpadding f=no%n i=dat1.csv o=rsl1.csv\n\
    #END# kgpadding f=no%n i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    no%0n\n\
    3\n\
    4\n\
    5\n\
    6\n\
    7\n\
    8\n\
\n\
Example 2: Specify the starting and ending value\n\
\n\
Insert padding between records as well as before and after the first and\n\
last records from the input data. Specify the starting and ending range\n\
at S=,E=.\n\
\n\
    $ mpadding f=no%n S=1 E=10 i=dat1.csv o=rsl2.csv\n\
    #END# kgpadding E=10 S=1 f=no%n i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    no%0n\n\
    1\n\
    2\n\
    3\n\
    4\n\
    5\n\
    6\n\
    7\n\
    8\n\
    9\n\
    10\n\
\n\
Example 3: Padding with date\n\
\n\
Create padding to fill in values between dates (type=date) in the date\n\
column. Create padding values in columns other than those specified at\n\
k=,f=.\n\
\n\
    $ more dat2.csv\n\
    date,dummy\n\
    20130929,a\n\
    20131002,b\n\
    20131004,c\n\
    $ mpadding f=date%d i=dat2.csv o=rsl3.csv\n\
    #END# kgpadding f=date%d i=dat2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    date%0,dummy\n\
    20130929,a\n\
    20130930,a\n\
    20131001,a\n\
    20131002,b\n\
    20131003,b\n\
    20131004,c\n\
\n\
Example 4: Specify character string for padding\n\
\n\
Specify the character string padding value at v=.\n\
\n\
    $ mpadding f=date%d v=padding i=dat2.csv o=rsl4.csv\n\
    #END# kgpadding f=date%d i=dat2.csv o=rsl4.csv v=padding\n\
    $ more rsl4.csv\n\
    date%0,dummy\n\
    20130929,a\n\
    20130930,padding\n\
    20131001,padding\n\
    20131002,b\n\
    20131003,padding\n\
    20131004,c\n\
\n\
Example 5: Specify NULL value as padding character\n\
\n\
NULL value can be used as padding when the -n option is specified.\n\
\n\
    $ mpadding f=date%d -n i=dat2.csv o=rsl5.csv\n\
    #END# kgpadding -n f=date%d i=dat2.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    date%0,dummy\n\
    20130929,a\n\
    20130930,\n\
    20131001,\n\
    20131002,b\n\
    20131003,\n\
    20131004,c\n\
";

