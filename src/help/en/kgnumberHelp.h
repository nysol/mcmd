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
/// kgnumberHelp.h : kgnumber help
// =============================================================================
_title="-";
_doc="\
\n\
MNUMBER - SERIALS\n\
\n\
Show the alphabetical sequence\n\
(A,B,...,Z,AA,AB,...,AZ,BA,BB,...,ZZ,AAA,AAB,...) and save the output in\n\
a new column defined at a= parameter.\n\
\n\
Format\n\
\n\
mnumber a= [e=] [I=] [k=] [s=] [S=] [-B] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
Parameters\n\
\n\
  a=   Specify the field name and the list of new serials.\n\
       [However, this parameter is not required when -nfn or -nfno options are specified]\n\
  e=   Process records with same Rank\n\
       Specify how to handle fields with same key same sort values.\n\
       Default setting is used(e=seq) with “No” attached as the field name of the sequence, if the parameter is not specified.\n\
       seq: Create sequential serial numbers or alphabets for records with same rank.\n\
       same: Records with equal numerical or alphabetical values receive the same rank order.\n\
       skip: Records with equal numerical or alphabetical values receive the same rank order,\n\
       number of subsequent rank is skipped for the following record.\n\
       Note: e={same/skip} must be specified with the s= parameter.\n\
  I=   Interval between the sequence.\n\
       However, a negative interval value cannot be specified for alphabet sequence.\n\
  k=   Generate sequential characters for the key field(s) (multiple fields can be specified)\n\
  s=   Specified field(s) (multiple fields can be specified) containing same rank values .\n\
       Note: This parameter must be declared with e={same/skip}.\n\
  S=   Starting No\n\
       Specify the starting value of the sequence.\n\
       Uppercase alphabet letters for the alphabet sequence.\n\
  -B   Assign same sequential number or alphabet to each key.\n\
       Records with the same key will each be assigned the same number (No) or alphabet.\n\
\n\
Examples\n\
\n\
Example 1: Sequential numbers\n\
\n\
Generate sequential numbers for each value in ascending order in the\n\
Customer column. Name the sequence as No in a new column.\n\
\n\
    $ more dat1.csv\n\
    Customer,Val,Sum\n\
    A,29,300\n\
    B,35,250\n\
    C,15,200\n\
    D,23,150\n\
    E,10,100\n\
    $ mnumber s=Customer a=No i=dat1.csv o=rsl1.csv\n\
    #END# kgnumber a=No i=dat1.csv o=rsl1.csv s=Customer\n\
    $ more rsl1.csv\n\
    Customer%0,Val,Sum,No\n\
    A,29,300,0\n\
    B,35,250,1\n\
    C,15,200,2\n\
    D,23,150,3\n\
    E,10,100,4\n\
\n\
Example 2: Serialize the Date column\n\
\n\
Sequentially number items in the Date column according to earliest date\n\
to latest date. Use same sequence number (No) for same Date. Save the\n\
sequence in a new column named \"No\".\n\
\n\
    $ more dat2.csv\n\
    Date\n\
    20090101\n\
    20090101\n\
    20090102\n\
    20090103\n\
    20090103\n\
    $ mnumber k=Date a=No -B i=dat2.csv o=rsl2.csv\n\
    #END# kgnumber -B a=No i=dat2.csv k=Date o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Date%0,No\n\
    20090101,0\n\
    20090101,0\n\
    20090102,1\n\
    20090103,2\n\
    20090103,2\n\
\n\
Example 3: Serialize the Sum column (use same alphabet for same Rank order)\n\
\n\
Create a alphabetical sequence according to the Sum column which is\n\
arranged in descending order. Save the sequence in a new column named\n\
“Rank”. Assign the same alphabet character to items with the same\n\
values.\n\
\n\
    $ more dat3.csv\n\
    Customer,Val,Sum\n\
    A,3,300\n\
    B,1,250\n\
    C,2,250\n\
    D,1,150\n\
    E,1,100\n\
    $ mnumber a=Rank e=same s=Sum%nr S=A  i=dat3.csv o=rsl3.csv\n\
    #END# kgnumber S=A a=Rank e=same i=dat3.csv o=rsl3.csv s=Sum%nr\n\
    $ more rsl3.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,A\n\
    B,1,250,B\n\
    C,2,250,B\n\
    D,1,150,C\n\
    E,1,100,D\n\
\n\
Example 4: Serialize the Sum column (sequential numbers for same Rank order)\n\
\n\
Number records sequentially according to Sum column (sum arranged in\n\
descending order), and save serials in the \"Rank\" column. For items with\n\
same rank order, assign sequential numbers according to sort order.\n\
\n\
    $ mnumber a=Rank e=seq s=Sum%nr i=dat3.csv o=rsl4.csv\n\
    #END# kgnumber a=Rank e=seq i=dat3.csv o=rsl4.csv s=Sum%nr\n\
    $ more rsl4.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,0\n\
    B,1,250,1\n\
    C,2,250,2\n\
    D,1,150,3\n\
    E,1,100,4\n\
\n\
Example 5: Serialize the Sum column (Same No for same Rank)\n\
\n\
Number records sequentially according to Sum column (sum arranged in\n\
descending order), and save the numbers in the “Rank” column. Assign the\n\
same No to records with the same Rank order.\n\
\n\
    $ mnumber a=Rank e=same s=Sum%nr i=dat3.csv o=rsl5.csv\n\
    #END# kgnumber a=Rank e=same i=dat3.csv o=rsl5.csv s=Sum%nr\n\
    $ more rsl5.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,0\n\
    B,1,250,1\n\
    C,2,250,1\n\
    D,1,150,2\n\
    E,1,100,3\n\
\n\
Example 6: Serialize the Sum column (duplicate numbers for same Rank and skip number for next record)\n\
\n\
Number records sequentially according to Sum column (sum arranged in\n\
descending order), and save the numbers is the “Rank” column. Assign\n\
same RankNo number to records with same rank order, subsequent No is\n\
skipped for the following record.\n\
\n\
    $ mnumber a=Rank e=skip s=Sum%nr i=dat3.csv o=rsl6.csv\n\
    #END# kgnumber a=Rank e=skip i=dat3.csv o=rsl6.csv s=Sum%nr\n\
    $ more rsl6.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,0\n\
    B,1,250,1\n\
    C,2,250,1\n\
    D,1,150,3\n\
    E,1,100,4\n\
\n\
Example 7: Number sequence starting from 10\n\
\n\
Serialize the Sum column sequentially from 10 with items, where values\n\
of sum is arranged in ascending order. Save the serials in the \"Score\"\n\
column. Assign same RankNo to records with same Rank order , subsequent\n\
No is skipped for the following record.\n\
\n\
    $ more dat4.csv\n\
    Customer,Val,Sum\n\
    A,1,100\n\
    B,1,150\n\
    C,1,250\n\
    D,2,250\n\
    E,3,300\n\
    $ mnumber a=Score e=same s=Sum%n S=10 i=dat4.csv o=rsl7.csv\n\
    #END# kgnumber S=10 a=Score e=same i=dat4.csv o=rsl7.csv s=Sum%n\n\
    $ more rsl7.csv\n\
    Customer,Val,Sum%0n,Score\n\
    A,1,100,10\n\
    B,1,150,11\n\
    C,1,250,12\n\
    D,2,250,12\n\
    E,3,300,13\n\
\n\
Example 8: Start sequence from 10 with an interval of 5\n\
\n\
Number the Sum column sequentially from 10 at an interval of 5, where\n\
values of sum is arranged in ascending order. Save the serials in the\n\
“Score” column. Assign the same number to records with the same Rank\n\
order.\n\
\n\
    $ mnumber a=Score e=same s=Sum%n S=10 I=5 i=dat4.csv o=rsl8.csv\n\
    #END# kgnumber I=5 S=10 a=Score e=same i=dat4.csv o=rsl8.csv s=Sum%n\n\
    $ more rsl8.csv\n\
    Customer,Val,Sum%0n,Score\n\
    A,1,100,10\n\
    B,1,150,15\n\
    C,1,250,20\n\
    D,2,250,20\n\
    E,3,300,25\n\
";

