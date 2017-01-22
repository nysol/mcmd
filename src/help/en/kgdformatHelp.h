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
/// kgdformatHelp.h : kgdformat help
// =============================================================================
_title="EXTRACT";
_doc="\
\n\
MDFORMAT EXTRACT DATE TIME\n\
\n\
CSV data that was exported from other systems often contains forward\n\
slash and colon symbol in date columns, in addition, date and time are\n\
stored in single digit (Example: 2014/7 / 18 1:57). Sorting and range\n\
specification processing on these kind of items in MCMD is not possible.\n\
\n\
For ease of processing data and time formatted data Date Time Format,\n\
the mdformat command extracts the date, hour, minute, and second on\n\
fields specified in f= parameter according to the format specified in\n\
the c= parameter.\n\
\n\
Format\n\
\n\
mdformat c= f= [-A]  [i=] [o=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  f=   Specify the field name for extraction (multiple items can be specified).\n\
  c=   Specify string format according to the specified format.\n\
  -A   Specify the new column name and save output results in new column.\n\
\n\
Conversion Specification of Character Format\n\
\n\
Table shows the possible character conversion formats that can be\n\
defined in c= parameter.\n\
\n\
llll Conversion Characters & Description\n\
%Y & Number representing year (4 digits)\n\
%y & Number representing year (2 digits)\n\
%m & Number representing month (2 digits)\n\
%d & Number representing day (2 digits)\n\
%H & Time (2 digits)\n\
%M & Minute (2 digits)\n\
%S & Second (2 digits)\n\
\n\
Examples \n\
\n\
Example 1: Basic Example\n\
\n\
Extract and convert time and date information from fld field. Save the\n\
converted format as “a:yearmonthday:b:timeminutesecond”, by specifying\n\
“a:%Y%m%d:b:%H%M%S” in the c= parameter.\n\
\n\
    $ more dat1.csv\n\
    fld\n\
    a:20120304:b:121212\n\
    a:20101204:b:011309\n\
    $ mdformat f=fld c=a:%Y%m%d:b:%H%M%S i=dat1.csv o=rsl1.csv\n\
    #END# kgdformat c=a:%Y%m%d:b:%H%M%S f=fld i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    fld\n\
    20120304121212\n\
    20101204011309\n\
\n\
Example 2: Add Results to New Column\n\
\n\
Store results in fld2 from format conversion in fld1 field, specify the\n\
format by “%Y/%m/%d” in c= parameter. Use -A option to save results in\n\
f2 field.\n\
\n\
    $ more dat2.csv\n\
    fld,fld2\n\
    2010/11/20,2010/11/21\n\
    2010/1/1,2010/1/2\n\
    2011/01/01,2010/01/02\n\
    2010/1/01,2010/1/02\n\
    $ mdformat f=fld:f1,fld2:f2 c=%Y/%m/%d i=dat2.csv -A o=rsl2.csv\n\
    #END# kgdformat -A c=%Y/%m/%d f=fld:f1,fld2:f2 i=dat2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    fld,fld2,f1,f2\n\
    2010/11/20,2010/11/21,20101120,20101121\n\
    2010/1/1,2010/1/2,20100101,20100102\n\
    2011/01/01,2010/01/02,20110101,20100102\n\
    2010/1/01,2010/1/02,20100101,20100102\n\
\n\
Example 3: Case of failed extraction\n\
\n\
The date format in fld field is saved as “Year Month Day\n\
Time:Minute:Second”, “%Y %m %d %H:%M:%S” is specified in c= parameter.\n\
However, it failed since the format is different in different rows.\n\
\n\
    $ more dat3.csv\n\
    fld\n\
    2010 11 20 12:34:56\n\
\n\
    2011 01 01 23:34:56\n\
    2010  1 01 123455\n\
    $ mdformat f=fld:f1 c='%Y %m %d %H:%M:%S' i=dat3.csv -A o=rsl3.csv\n\
    #END# kgdformat -A c=%Y %m %d %H:%M:%S f=fld:f1 i=dat3.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    fld,f1\n\
    2010 11 20 12:34:56,20101120123456\n\
    ,\n\
    2011 01 01 23:34:56,20110101233456\n\
    2010  1 01 123455,\n\
";

