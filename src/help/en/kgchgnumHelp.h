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
/// kgchgnumHelp.h : kgchgnum help
// =============================================================================
_title="-";
_doc="\
\n\
MCHGNUM - SUBSTITUTE VALUES WITHIN NUMERICAL RANGE\n\
\n\
The field name for encoding is specified at f= parameter, number and\n\
range criteria is specified at the R= parameter, the substitution string\n\
specified in the v= parameter replaces the value in the defined field.\n\
\n\
Format\n\
\n\
mchgnum f= R= [O=|-F] [v=] [-A] [-r] [i=] [o=] [-option_assert_diffSize]\n\
[-option_assert_nullin] [-option_assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   Replace the specified field (multiple fields can be specified) according to the replacement string list\n\
       at v= parameter and the numerical ranges list at R= parameter.\n\
  R=   Specify the numerical range to be replaced (multiple fields can be specified)\n\
       (1.1,2.5 : more than 1.1 and less than 2.5).\n\
       Use MIN for minimum value, MAX for maximum value ( MIN, 2.5 : 2.5 or less).\n\
  O=   Out of range character strings\n\
       Specify the replacement string when values fall outside the numeric range list at the\n\
       R= parameter (returns NULL values in output when this parameter is not specified).\n\
  -F   Display out of range values in the column.\n\
       Retain the out of range values in the output even though the values fall outside the\n\
       specified numeric range defined in the R= parameter.\n\
  v=   Specify the replacement character string corresponding to the numerical range in the R= parameter.\n\
       More than 1 argument must be defined at R=.\n\
  -A   This option adds output to a new column instead of replacing the specified item.\n\
  -r   The range defined at R= parameter deals with ’ greater than  less than’.\n\
       For example, 1.1_2.5 represents “greater than 1.1 < less than 2.5”.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Encodes the numeric values in quantity column to character strings where\n\
values of less than but not equal to 10 are treated as low, 10 or more\n\
but less than 20 are treated as middle, values of 20 or more is treated\n\
as high.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity\n\
    A,5\n\
    B,10\n\
    C,15\n\
    D,2\n\
    E,50\n\
    $ mchgnum f=quantity R=MIN,10,20,MAX v=low,middle,high i=dat1.csv o=rsl1.csv\n\
    #END# kgchgnum R=MIN,10,20,MAX f=quantity i=dat1.csv o=rsl1.csv v=low,middle,high\n\
    $ more rsl1.csv\n\
    customer,quantity\n\
    A,low\n\
    B,middle\n\
    C,middle\n\
    D,low\n\
    E,high\n\
\n\
Example 2: Equal to paramter range\n\
\n\
Replace the numeric values in quantity column to character strings where\n\
10 or below is treated as low, more than 10 but less than or equal to 20\n\
is treated as middle, more than 20 is treated as high.\n\
\n\
    $ mchgnum f=quantity R=MIN,10,20,MAX v=low,middle,high -r i=dat1.csv o=rsl2.csv\n\
    #END# kgchgnum -r R=MIN,10,20,MAX f=quantity i=dat1.csv o=rsl2.csv v=low,middle,high\n\
    $ more rsl2.csv\n\
    customer,quantity\n\
    A,low\n\
    B,low\n\
    C,middle\n\
    D,low\n\
    E,high\n\
\n\
Example 3: Replace values out of the list of numeric range\n\
\n\
Replace numeric values in quantity column to character strings where 10\n\
or above and less than 20 is coded as low, 20 or above and less than 30\n\
is coded as middle, 30 or more is coded as high, values that are less\n\
than 10 is coded as out of range.\n\
\n\
    $ mchgnum f=quantity R=10,20,30,MAX v=low,middle,high O=\"out of range\" i=dat1.csv o=rsl3.csv\n\
    #END# kgchgnum O=out of range R=10,20,30,MAX f=quantity i=dat1.csv o=rsl3.csv v=low,middle,high\n\
    $ more rsl3.csv\n\
    customer,quantity\n\
    A,out of range\n\
    B,low\n\
    C,low\n\
    D,out of range\n\
    E,high\n\
\n\
Example 4: Add a new column\n\
\n\
Replace the numeric values in quantity column to character strings where\n\
values less than 10 is treated as low, 10 or above but less than 20 is\n\
treated as middle, 20 or above is treated as high. Store the output of\n\
replacement strings in a new column as evaluate.\n\
\n\
    $ mchgnum f=quantity:evaluate R=MIN,10,20,MAX v=low,middle,high -A i=dat1.csv o=rsl4.csv\n\
    #END# kgchgnum -A R=MIN,10,20,MAX f=quantity:evaluate i=dat1.csv o=rsl4.csv v=low,middle,high\n\
    $ more rsl4.csv\n\
    customer,quantity,evaluate\n\
    A,5,low\n\
    B,10,middle\n\
    C,15,middle\n\
    D,2,low\n\
    E,50,high\n\
\n\
Example 5: Display original values in column if out of defined range\n\
\n\
Replace the numeric values in quantity column to character strings where\n\
values of 10 or above but less than 20 is coded as low, 20 or above but\n\
less than 30 is coded as middle, 30 or above is coded as high. Retain\n\
original values in the output if the value is less than 10.\n\
\n\
    $ mchgnum f=quantity R=10,20,30,MAX v=low,middle,high -F i=dat1.csv o=rsl5.csv\n\
    #END# kgchgnum -F R=10,20,30,MAX f=quantity i=dat1.csv o=rsl5.csv v=low,middle,high\n\
    $ more rsl5.csv\n\
    customer,quantity\n\
    A,5\n\
    B,low\n\
    C,low\n\
    D,2\n\
    E,high\n\
";

