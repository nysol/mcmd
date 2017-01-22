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
/// kgchgstrHelp.h : kgchgstr help
// =============================================================================
_title="-";
_doc="\
\n\
MCHGSTR - SUBSTITUTE STRING\n\
\n\
Replace the field(s) specified in the f= parameter with the string\n\
according to the replacement criteria specified in the c= parameter.\n\
\n\
Format\n\
\n\
mchgstr c= f= [O=] [-A] [-F] [-sub] [-W]  [i=] [o=]\n\
[-option_assert_diffSize] [-option_assert_nullin]\n\
[-option_assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  c=     Specify the replacement character string to be replaced.\n\
  f=     Specify the field(s) (multiple fields can be specified) where the character string is replaced\n\
         according to the replacement criteria specified in the verb|c=| parameter.\n\
  O=     Specify the replacement string if the values does not match any substitution criteria specified in the c= parameter\n\
         (returns NULL values when this parameter is not specified).\n\
  -A     This option adds output in a new column instead of replacing the specified item.\n\
  -F     Retain values in output even though values fall outside the specified numeric range defined in the R= parameter.\n\
  -sub   Compare using substring match rather than exact match.\n\
         Search the values specified in the f= parameter,\n\
         and replace the string with the criteria specified in c=.\n\
  -W     Match wide-character substring with -sub option.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Replace values in the column from \"01\" to \"A\", \"03\" to \"B\", \"04\" to \"C\".\n\
Other values that do not match the criteria are returned as NULL values\n\
in the output.\n\
\n\
    $ more dat1.csv\n\
    id,item\n\
    1,01\n\
    2,02\n\
    3,03\n\
    4,04\n\
    5,05\n\
    $ mchgstr f=item c=01:A,03:B,05:C i=dat1.csv o=rsl1.csv\n\
    #END# kgchgstr c=01:A,03:B,05:C f=item i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,item\n\
    1,A\n\
    2,\n\
    3,B\n\
    4,\n\
    5,C\n\
\n\
Example 2: Replace values outside the criteria\n\
\n\
Use the O= parameter to replace character string that do not match the\n\
substitution criteria to \"out of range\" in the output.\n\
\n\
    $ mchgstr f=item c=01:A,03:B,05:C O=\"out of range\" i=dat1.csv o=rsl2.csv\n\
    #END# kgchgstr O=out of range c=01:A,03:B,05:C f=item i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,item\n\
    1,A\n\
    2,out of range\n\
    3,B\n\
    4,out of range\n\
    5,C\n\
\n\
Example 3: Example 3: Add new column in output\n\
\n\
Define the name of new column (item info) in output with -A option.\n\
\n\
    $ mchgstr f=item:\"item info\" c=01:A,03:B,05:C O=\"out of range\" -A i=dat1.csv o=rsl3.csv\n\
    #END# kgchgstr -A O=out of range c=01:A,03:B,05:C f=item:item info i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id,item,item info\n\
    1,01,A\n\
    2,02,out of range\n\
    3,03,B\n\
    4,04,out of range\n\
    5,05,C\n\
\n\
Example 4: Display original value in field falls outside the criteria\n\
\n\
When -F option is specified, output value of the field remains the same\n\
if it does not match any of the substitution criteria.\n\
\n\
    $ mchgstr f=item c=01:A,03:B,05:C -F i=dat1.csv o=rsl4.csv\n\
    #END# kgchgstr -F c=01:A,03:B,05:C f=item i=dat1.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id,item\n\
    1,A\n\
    2,02\n\
    3,B\n\
    4,04\n\
    5,C\n\
\n\
Example 5: Replace matching substrings\n\
\n\
Replace substring with -sub option specified. In following example,\n\
values where item field contains \"01\" will be substituted with \"A\".\n\
\n\
    $ more dat2.csv\n\
    id,item\n\
    1,0111\n\
    2,0121\n\
    3,0231\n\
    4,0241\n\
    5,0151\n\
    $ mchgstr f=item c=01:A -sub i=dat2.csv o=rsl5.csv\n\
    #END# kgchgstr -sub c=01:A f=item i=dat2.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    id,item\n\
    1,A11\n\
    2,A21\n\
    3,\n\
    4,\n\
    5,A51\n\
\n\
Example 6: Wide character substring match\n\
\n\
Use the option -W to replace wide-characters strings. However, if you\n\
are using UTF-8 encoding, it is not necessary to define -W. Refer to the\n\
section “Multibyte characters” for details.\n\
\n\
    $ more dat3.csv\n\
    id,city\n\
    1,奈良市\n\
    2,下市町\n\
    3,十津川村\n\
    4,五條市\n\
    5,山添村\n\
    $ mchgstr f=city c=市:01,町:02,村:02 -sub -W i=dat3.csv o=rsl6.csv\n\
    #END# kgchgstr -W -sub c=市:01,町:02,村:02 f=city i=dat3.csv o=rsl6.csv\n\
    $ more rsl6.csv\n\
    id,city\n\
    1,奈良01\n\
    2,下0102\n\
    3,十津川02\n\
    4,五條01\n\
    5,山添02\n\
";

