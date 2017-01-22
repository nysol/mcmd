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
/// kgnulltoHelp.h : kgnullto help
// =============================================================================
_title="-";
_doc="\
\n\
MNULLTO - REPLACE NULL VALUES\n\
\n\
Replace NULL values in the field(s) specified at f= parameter with a\n\
character string defined at v= parameter.\n\
\n\
Format\n\
\n\
mnullto f= [v=|-p] [O=] [-A] [i=] [o=] [-assert_diffSize] [-nfn] [-nfno]\n\
[-x] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Replace null values in the field(s) (multiple fields can be specified).\n\
  v=   Replace null values with this string.\n\
  -p   Replace null values in the previous row.\n\
       This option cannot be specified with v= parameter.\n\
  O=   String to replace non-null values.\n\
       When this parameter is not specified, non-null values will not be replaced.\n\
  -A   Add replacement string as new column.\n\
       When -A option is specified, define the new field name using a colon (:) after the field name.\n\
       Example: f=quantity:ReplacementFieldName.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Replace NULL values in the ¥verb|birthday| field with the string\n\
“no value”.\n\
\n\
    $ more dat1.csv\n\
    customer,birthday\n\
    A,19690103\n\
    B,\n\
    C,19500501\n\
    D,\n\
    E,\n\
    $ mnullto f=birthday v=\"no value\" i=dat1.csv o=rsl1.csv\n\
    #END# kgnullto f=birthday i=dat1.csv o=rsl1.csv v=no value\n\
    $ more rsl1.csv\n\
    customer,birthday\n\
    A,19690103\n\
    B,no value\n\
    C,19500501\n\
    D,no value\n\
    E,no value\n\
\n\
Example 2: Replace non-NULL values\n\
\n\
Replace Null values in the birthday field with the string \"no value\" and\n\
change non-null values to the string ¥verb|“value”|, and rename the\n\
output column as entry.\n\
\n\
    $ mnullto f=birthday:entry v=\"no value\" O=\"value\" i=dat1.csv o=rsl2.csv\n\
    #END# kgnullto O=value f=birthday:entry i=dat1.csv o=rsl2.csv v=no value\n\
    $ more rsl2.csv\n\
    customer,entry\n\
    A,value\n\
    B,no value\n\
    C,value\n\
    D,no value\n\
    E,no value\n\
\n\
Example 3: Add new column\n\
\n\
Replace Null values in the birthday field with the string \"no value\" and\n\
change non-null values to the string \"value\". Output the replacement\n\
strings in a new column named entry.\n\
\n\
    $ mnullto f=birthday:entry v=\"no value\" O=\"value\" -A i=dat1.csv o=rsl3.csv\n\
    #END# kgnullto -A O=value f=birthday:entry i=dat1.csv o=rsl3.csv v=no value\n\
    $ more rsl3.csv\n\
    customer,birthday,entry\n\
    A,19690103,value\n\
    B,,no value\n\
    C,19500501,value\n\
    D,,no value\n\
    E,,no value\n\
\n\
Example 4: Replace values in previous row\n\
\n\
    $ more dat2.csv\n\
    id,date\n\
    A,19690103\n\
    B,\n\
    C,19500501\n\
    D,\n\
    E,\n\
    $ mnullto f=date -p i=dat2.csv o=rsl4.csv\n\
    #END# kgnullto -p f=date i=dat2.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id,date\n\
    A,19690103\n\
    B,19690103\n\
    C,19500501\n\
    D,19500501\n\
    E,19500501\n\
";

