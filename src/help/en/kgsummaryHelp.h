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
/// kgsummaryHelp.h : kgsummary help
// =============================================================================
_title="CALCULATE";
_doc="\
\n\
MSUMMARY CALCULATE STATISTICS FOR 1 VARIABLE \n\
\n\
Calculate the type of statistics specified at c= parameter for fields\n\
specified at f= parameter.\n\
\n\
Format\n\
\n\
msummary c= f= [a=] [k=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   Compute statistics based on the key field(s) specified (multiple fields can be specified).\n\
  f=   Field lists for computation of statistical summary (multiple fields can be specified).\n\
       When -x,-nfn option is specified, specify the field number (0 ).\n\
  c=   Statistics (multiple fields can be specified)\n\
       Specify list of statistics delimited by comma.\n\
       Statistics list:\n\
       sum/mean/count/ucount/devsq/var/uvar/sd/usd/cv/min/qtile1/median/qtile3/max/\n\
       range/qrange/mode/skew/uskew/kurt/ukurt\n\
  -a   New column name.\n\
       Results from calculation on column(s) specified at f= parameter (default is fld).\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Find out the median and average “quantity” and “amount” by each\n\
customer. Save the output in a new column named “type”.\n\
\n\
    $ more dat1.csv\n\
    customer,quantity,amount\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ msummary k=customer f=quantity,amount c=median:medianval,mean:meanval a=type i=dat1.csv o=rsl1.csv\n\
    #END# kgsummary a=type c=median:medianval,mean:meanval f=quantity,amount i=dat1.csv k=customer o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer%0,type,medianval,meanval\n\
    A,quantity,1.5,1.5\n\
    A,amount,15,15\n\
    B,quantity,1,1.666666667\n\
    B,amount,15,15\n\
";

