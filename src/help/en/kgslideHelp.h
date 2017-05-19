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
/// kgslideHelp.h : kgslide help
// =============================================================================
_title="-";
_doc="\
\n\
MSLIDE - SLIDE DATA SERIES\n\
\n\
Shift data series in the specified column to a new column by specified\n\
number of times. For example, the function can be used to calculate\n\
difference between data items in the same field such as deriving the\n\
rate of return using daily stock price data (today’s stock\n\
price/previous day’s stock price)\n\
\n\
Format\n\
\n\
mslide f= [s=] [k=key] [t=] [-r] [-n] [-l] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
  f=   Field name for sliding records. Multiple fields can be specified.\n\
       The If you do not specify t=, the field name can be specified by f=fieldname:newfieldname.\n\
  s=   After the specified field is sorted (multiple fields can be specified), records are shifted.\n\
       s= parameter is required when -q option is not specified.\n\
  k=   Specify the field for shifting of records.\n\
  t=   Number of times (rows) to shift. Default value is t=1 if this parameter is not defined.\n\
  -r   Shift records in the opposite direction (shift the first record below).\n\
  -n   Print a null value if next (or previous) line is not available.\n\
  -l   Print results from the final shift.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
    $ more dat1.csv\n\
    date,val\n\
    20130406,1\n\
    20130407,2\n\
    20130408,3\n\
    20130409,4\n\
    $ mslide s=date f=val:newVal i=dat1.csv o=rsl1.csv\n\
    #END# kgslide f=val:newVal i=dat1.csv o=rsl1.csv s=date\n\
    $ more rsl1.csv\n\
    date%0,val,newVal\n\
    20130406,1,2\n\
    20130407,2,3\n\
    20130408,3,4\n\
\n\
Example 2: Slide rows in reverse direction\n\
\n\
    $ mslide s=date f=val:newVal -r i=dat1.csv o=rsl2.csv\n\
    #END# kgslide -r f=val:newVal i=dat1.csv o=rsl2.csv s=date\n\
    $ more rsl2.csv\n\
    date%0,val,newVal\n\
    20130407,2,1\n\
    20130408,3,2\n\
    20130409,4,3\n\
\n\
Example 3: Slide records more than once\n\
\n\
    $ mslide s=date f=val t=2 i=dat1.csv o=rsl3.csv\n\
    #END# kgslide f=val i=dat1.csv o=rsl3.csv s=date t=2\n\
    $ more rsl3.csv\n\
    date%0,val,val1,val2\n\
    20130406,1,2,3\n\
    20130407,2,3,4\n\
\n\
Example 4: Display output from the last column shifted\n\
\n\
    $ mslide s=date f=val t=2 -l i=dat1.csv o=rsl4.csv\n\
    #END# kgslide -l f=val i=dat1.csv o=rsl4.csv s=date t=2\n\
    $ more rsl4.csv\n\
    date%0,val,val2\n\
    20130406,1,3\n\
    20130407,2,4\n\
\n\
Example 5: Change multiple field names\n\
\n\
    $ mslide s=date f=date:d_,val:v_ t=2 i=dat1.csv o=rsl5.csv\n\
    #END# kgslide f=date:d_,val:v_ i=dat1.csv o=rsl5.csv s=date t=2\n\
    $ more rsl5.csv\n\
    date%0,val,d_1,d_2,v_1,v_2\n\
    20130406,1,20130407,20130408,2,3\n\
    20130407,2,20130408,20130409,3,4\n\
";

