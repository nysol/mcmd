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
/// kgselnumHelp.h : kgselnum help
// =============================================================================
_title="-";
_doc="\
\n\
MSELNUM - SELECT RECORDS MATCHING RANGE\n\
\n\
This command selects records that matches the range specified at c= with\n\
the values in the column specified at the f= parameter. Various\n\
selection criteria can be specified as arguments in the parameters as\n\
follows. Use msel command to query complex selection criteria such as\n\
matching against a combination of string characters. For more\n\
information about OR, AND conditions for key field, refer to mselstr\n\
command.\n\
\n\
-   Range types include open range, closed range, inclusive and\n\
    exclusive bounds and infinite range.\n\
\n\
-   c=specify multiple range and select records that matches either\n\
    range (OR condition).\n\
\n\
-   f=specify multiple fields at which the values matches either range\n\
    (OR condition).\n\
\n\
-   f=change the logical operator from OR to AND with the -F option.\n\
\n\
-   k=specify key value as the selection unit.\n\
\n\
-   Use AND logical operator to select records based on the key value\n\
    with the -R option.\n\
\n\
Format\n\
\n\
mselnum f= c= [k=] [u=] [-F] [-r] [-R] [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-nfn] [-nfno]\n\
[-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Field name of target query (allow multiple fields).\n\
  c=   Select row(s) where the data array specified at f= parameter matches with the specified range\n\
       at this parameter (allow multiple ranges).\n\
  k=   Key field(s) as unit of selection (Multiple range can be specified).\n\
  o=   Records matching the condition will be printed to this output file.\n\
  u=   Records that do not match the condition will be printed to this output file.\n\
  -F   Select all records that matches the defined value if multiple items are defined at f= parameter.\n\
  -r   Reverse selection\n\
       Select records excluded from the selection condition.\n\
  -R   Select if all rows with the same key specified at k= parameter matches the criteria.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Select rows where val is greater than 2 and below 5, i.e. records\n\
matching id=2,5 are selected.\n\
\n\
    $ more dat1.csv\n\
    id,val\n\
    1,5.1\n\
    2,5\n\
    3,-2.0\n\
    4,\n\
    5,2.0\n\
    $ mselnum f=val c='[2,5]' i=dat1.csv o=rsl1.csv\n\
    #END# kgselnum c=[2,5] f=val i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,val\n\
    2,5\n\
    5,2.0\n\
\n\
Example 2: Greater than range\n\
\n\
Select rows where val is greater than 2, i.e. records where id=1,2,5.\n\
\n\
    $ mselnum f=val c='[2,]' i=dat1.csv o=rsl2.csv\n\
    #END# kgselnum c=[2,] f=val i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,val\n\
    1,5.1\n\
    2,5\n\
    5,2.0\n\
";

