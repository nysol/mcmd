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
/// kgfldnameHelp.h : kgfldname help
// =============================================================================
_title="-";
_doc="\
\n\
MFLDNAME - RENAME FIELD\n\
\n\
Specify the field to rename at f=, and the new column name at n=. Add\n\
the -q option to revert to the field header names as appeared in Ver. 1,\n\
and removes the sort order symbols appended to field names in output for\n\
2.0 commands.\n\
\n\
Format\n\
\n\
mfldname f=|n= [-nfni] [i=] [o=] [-assert_diffSize] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=      Specify the field name to change (current field name:new field name).\n\
          The original field name will not change if this parameter is not set.\n\
  n=      Specify the new target column name.\n\
          The number of item names must be the same as the number of columns in the data.\n\
  -nfni   Field name not present in input data. This option cannot be used with f=.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Change column name from “customer” to “cust”, and “october” to “oct”.\n\
\n\
    $ more dat1.csv\n\
    customer,itemID,october\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
    $ mfldname f=customer:cust,october:oct. i=dat1.csv o=rsl1.csv\n\
    #END# kgfldname f=customer:cust,october:oct. i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    cust,itemID,oct.\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
\n\
Example 2: Rename column\n\
\n\
Change field names to x,y,z.\n\
\n\
    $ mfldname n=x,y,z i=dat1.csv o=rsl2.csv\n\
    #END# kgfldname i=dat1.csv n=x,y,z o=rsl2.csv\n\
    $ more rsl2.csv\n\
    x,y,z\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
\n\
Example 3: Data without field names\n\
\n\
    $ more dat2.csv\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
    $ mfldname -nfni n=x,y,z i=dat2.csv o=rsl3.csv\n\
    #END# kgfldname -nfni i=dat2.csv n=x,y,z o=rsl3.csv\n\
    $ more rsl3.csv\n\
    x,y,z\n\
    a,xx,11\n\
    b,yy,122\n\
    c,zz,\n\
\n\
Example 4: Remove sort order symbols in field names\n\
\n\
    $ more dat3.csv\n\
    customer%r,itemID,october\n\
    c,zz,\n\
    b,yy,122\n\
    a,xx,11\n\
    $ mfldname -q  i=dat3.csv o=rsl4.csv\n\
    #END# kgfldname -q i=dat3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    customer,itemID,october\n\
    c,zz,\n\
    b,yy,122\n\
    a,xx,11\n\
";

