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
/// kgwindowHelp.h : kgwindow help
// =============================================================================
_title="-";
_doc="\
\n\
MWINDOW - GENERATE SLIDING WINDOW\n\
\n\
Replicate original records and shift specified fields. A fixed window\n\
with constant width is set when calculating moving averages for time\n\
series data. The first element of moving average is obtained by taking\n\
the average of the initial fixed subset of the number series. The subset\n\
is shifted forward and included the next number following the original\n\
subset in the series. This method is known as sliding window\n\
calculation.\n\
\n\
Format\n\
\n\
mwindow wk= t= [k=key] [-r] [-n] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  wk=    Specify an unique value from the field name in the input data that identifies the window.\n\
         After the specified field is sorted, the sliding window is created,\n\
         %r is added for descending sort order, %n is added for numeric sorting.\n\
         When sorting in numeric descending order, %nr is added.\n\
         It is necessary to define the field name of window key after a colon. Multiple fields can be specified.\n\
  t=     Specify the window size (number of rows).\n\
  k=     Specify the unit for the generation of windows.\n\
  -r     Use the first row of data as baseline of sliding window. By default, the last row of data is used as baseline.\n\
  -n     Print all window intervals even though the window size less than the defined parameter at t=.\n\
  i=     Input file name\n\
  -nfn   Input data without field header in the first row.\n\
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
    $ mwindow wk=date:win t=2 i=dat1.csv o=rsl1.csv\n\
    #END# kgwindow i=dat1.csv o=rsl1.csv t=2 wk=date:win\n\
    $ more rsl1.csv\n\
    win%0,date,val\n\
    20130407,20130406,1\n\
    20130407,20130407,2\n\
    20130408,20130407,2\n\
    20130408,20130408,3\n\
    20130409,20130408,3\n\
    20130409,20130409,4\n\
\n\
Example 2: Use first row as baseline data\n\
\n\
    $ mwindow wk=date:win t=3 -r i=dat1.csv o=rsl2.csv\n\
    #END# kgwindow -r i=dat1.csv o=rsl2.csv t=3 wk=date:win\n\
    $ more rsl2.csv\n\
    win%0,date,val\n\
    20130406,20130406,1\n\
    20130406,20130407,2\n\
    20130406,20130408,3\n\
    20130407,20130407,2\n\
    20130407,20130408,3\n\
    20130407,20130409,4\n\
\n\
Example 3: Print all window intervals even if the window size is less than the defined parameter\n\
\n\
    $ mwindow wk=date:win t=3 -r -n i=dat1.csv o=rsl3.csv\n\
    #END# kgwindow -n -r i=dat1.csv o=rsl3.csv t=3 wk=date:win\n\
    $ more rsl3.csv\n\
    win%0,date,val\n\
    20130406,20130406,1\n\
    20130406,20130407,2\n\
    20130406,20130408,3\n\
    20130407,20130407,2\n\
    20130407,20130408,3\n\
    20130407,20130409,4\n\
    20130408,20130408,3\n\
    20130408,20130409,4\n\
    20130409,20130409,4\n\
\n\
Example 4: Example of specifying key field\n\
\n\
    $ more dat2.csv\n\
    store,date,val\n\
    a,20130406,1\n\
    a,20130407,2\n\
    a,20130408,3\n\
    a,20130409,4\n\
    b,20130406,11\n\
    b,20130407,12\n\
    b,20130408,13\n\
    b,20130409,14\n\
    $ mwindow k=store wk=date:win t=2 i=dat2.csv o=rsl4.csv\n\
    #END# kgwindow i=dat2.csv k=store o=rsl4.csv t=2 wk=date:win\n\
    $ more rsl4.csv\n\
    win%1,store%0,date,val\n\
    20130407,a,20130406,1\n\
    20130407,a,20130407,2\n\
    20130408,a,20130407,2\n\
    20130408,a,20130408,3\n\
    20130409,a,20130408,3\n\
    20130409,a,20130409,4\n\
    20130407,b,20130406,11\n\
    20130407,b,20130407,12\n\
    20130408,b,20130407,12\n\
    20130408,b,20130408,13\n\
    20130409,b,20130408,13\n\
    20130409,b,20130409,14\n\
\n\
Example 5: Find out the moving averages between current day and previous day\n\
\n\
In the above example, moving average is calculated based on the last day\n\
of the window. mslide can be used for instances to calculate the moving\n\
averages of current day and previous day. The example is as follows:\n\
\n\
    $ mslide f=date:date2 -q i=dat1.csv o=rsl5.csv\n\
    #END# kgslide -q f=date:date2 i=dat1.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    date,val,date2\n\
    20130406,1,20130407\n\
    20130407,2,20130408\n\
    20130408,3,20130409\n\
\n\
Example 6: Find out the moving averages from the previous day\n\
\n\
    $ mwindow wk=date2:win t=2 i=rsl5.csv o=rsl6.csv\n\
    #END# kgwindow i=rsl5.csv o=rsl6.csv t=2 wk=date2:win\n\
    $ more rsl6.csv\n\
    win%0,date,val,date2\n\
    20130408,20130406,1,20130407\n\
    20130408,20130407,2,20130408\n\
    20130409,20130407,2,20130408\n\
    20130409,20130408,3,20130409\n\
";

