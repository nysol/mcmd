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
/// kgselstrHelp.h : kgselstr help
// =============================================================================
_title="-";
_doc="\
\n\
MSELSTR - SELECT RECORDS MATCHING QUERY STRING\n\
\n\
For records where the values in fields f= match with the string\n\
specified at v= are selected.\n\
\n\
Format\n\
\n\
mselstr f= v= [k=]  [u=] [-F] [-r] [-R] [-sub] [-head] [-tail] [-W] [i=]\n\
[o=] [bufcount=] [-assert_diffSize] [-assert_nullkey] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=      Target field name for query (allow multiple fields).\n\
  v=      Select rows(s) where the string specified at f= parameter matches any of the specified string(s) (allow multiple fields).\n\
  k=      Select records based on the defined key field (allow multiple fields).\n\
  o=      Print record(s) matching query to specified output file.\n\
  u=      Print unmatched record(s) to this output file.\n\
  -F      Match all character strings specified at the f= parameter.\n\
  -r      Reverse selection\n\
          Remove record matching records.\n\
  -R      Returns rows that match all character strings specified at the k= parameter.\n\
  -sub    Search for substring that matches the part of the string pattern.\n\
          Select records based on substring match specified in v= parameter,\n\
          against the string specified column(s) at the f= parameter.\n\
  -head   Match beginning of string\n\
  -tail   Match end of string\n\
  -W      Match a sequence of wide-character substring when -sub,-head,-tail option is specified.\n\
\n\
Examples\n\
\n\
Example 1: Basic example\n\
\n\
Select records matching apple and orange in the Product field , print\n\
matching results to rsl1.csv file. Unmatched records such as\n\
pineapplejuice will be saved to other.csv file using the parameter\n\
u=oth1.csv.\n\
\n\
    $ more dat1.csv\n\
    Product,Amount\n\
    apple,100\n\
    milk,350\n\
    orange,100\n\
    pineapplejuice,500\n\
    wine,1000\n\
    $ mselstr f=Product v=apple,orange u=oth1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgselstr f=Product i=dat1.csv o=rsl1.csv u=oth1.csv v=apple,orange\n\
    $ more rsl1.csv\n\
    Product,Amount\n\
    apple,100\n\
    orange,100\n\
    $ more oth1.csv\n\
    Product,Amount\n\
    milk,350\n\
    pineapplejuice,500\n\
    wine,1000\n\
\n\
Example 2: Remove records\n\
\n\
Contrary to example 1, remove records matching keywords apple and orange\n\
using the -r option, the output is saved to rsl2.csv file.\n\
\n\
    $ mselstr f=Product  v=apple,orange -r i=dat1.csv o=rsl2.csv\n\
    #END# kgselstr -r f=Product i=dat1.csv o=rsl2.csv v=apple,orange\n\
    $ more rsl2.csv\n\
    Product,Amount\n\
    milk,350\n\
    pineapplejuice,500\n\
    wine,1000\n\
\n\
Example 3: Select based on the key unit\n\
\n\
Select all records of customer who have purchased oranges by specifying\n\
Customer at the k= parameter. Save unmatched records to oth2.csv.\n\
\n\
    $ more dat2.csv\n\
    Customer,Product,Amount\n\
    A,apple,100\n\
    A,milk,350\n\
    B,orange,100\n\
    B,orange,100\n\
    B,pineapple,500\n\
    B,wine,1000\n\
    C,apple,100\n\
    C,orange,100\n\
    $ mselstr k=Customer f=Product v=orange u=oth2.csv i=dat2.csv o=rsl3.csv\n\
    #END# kgselstr f=Product i=dat2.csv k=Customer o=rsl3.csv u=oth2.csv v=orange\n\
    $ more rsl3.csv\n\
    Customer%0,Product,Amount\n\
    B,orange,100\n\
    B,orange,100\n\
    B,pineapple,500\n\
    B,wine,1000\n\
    C,apple,100\n\
    C,orange,100\n\
    $ more oth2.csv\n\
    Customer%0,Product,Amount\n\
    A,apple,100\n\
    A,milk,350\n\
\n\
Example 4: Partial match\n\
\n\
Select records where the Product field contain the keyword apple, and\n\
save the output to a file named rsl4.csv. Records with partial match\n\
such as pine(apple)juice will also be saved in the output file rsl4.csv.\n\
\n\
    $ mselstr f=Product v=apple -sub i=dat1.csv o=rsl4.csv\n\
    #END# kgselstr -sub f=Product i=dat1.csv o=rsl4.csv v=apple\n\
    $ more rsl4.csv\n\
    Product,Amount\n\
    apple,100\n\
    pineapplejuice,500\n\
\n\
Example 5: Wide character substring match\n\
\n\
Select records where the Product field contains wide characters “柿”,\n\
“桃”, and “葡萄”.\n\
\n\
Matching maybe based on single byte character if the query string\n\
includes wide character, the query string maybe interpreted as multibyte\n\
character for matching. Therefore, it is necessary indicate wide\n\
character in the query string with -W option.\n\
\n\
    $ more dat3.csv\n\
    Product,Amount\n\
    fruit:柿,100\n\
    fruit:桃,250\n\
    fruit:葡萄,300\n\
    fruit:梨,450\n\
    fruit:苺,500\n\
    $ mselstr f=Product v=柿,桃,葡萄 -sub -W i=dat3.csv o=rsl5.csv\n\
    #END# kgselstr -W -sub f=Product i=dat3.csv o=rsl5.csv v=柿,桃,葡萄\n\
    $ more rsl5.csv\n\
    Product,Amount\n\
    fruit:柿,100\n\
    fruit:桃,250\n\
    fruit:葡萄,300\n\
\n\
Example 6: Select product(s) with consecutive purchases in 2013.\n\
\n\
Use the -F option to select transactions where the date of purchase and\n\
the previous date of purchase for the product both took place in 2013.\n\
Save the query results to an output file rsl6.csv. Save unmatched\n\
records to oth3.csv.\n\
\n\
    $ more dat4.csv\n\
    Customer,Product,Amount,Gender,Date,PreviousDate\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    C,apple,100,2,2013/02/14,NULL\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    D,orange,100,2,2011/10/28,NULL\n\
    $ mselstr f=Date,PreviousDate -F -sub v=2013 u=oth3.csv i=dat4.csv o=rsl6.csv\n\
    #END# kgselstr -F -sub f=Date,PreviousDate i=dat4.csv o=rsl6.csv u=oth3.csv v=2013\n\
    $ more rsl6.csv\n\
    Customer,Product,Amount,Gender,Date,PreviousDate\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    $ more oth3.csv\n\
    Customer,Product,Amount,Gender,Date,PreviousDate\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    C,apple,100,2,2013/02/14,NULL\n\
    D,orange,100,2,2011/10/28,NULL\n\
\n\
Example 7: Extract all transactions of customers who have consecutive purchases in 2013\n\
\n\
Use k= parameter to select all transactions of customers who have\n\
purchased a product with date of purchase and date of previous purchase\n\
both took place in 2013. Save unmatched records to a file oth4.csv.\n\
\n\
    $ mselstr k=Customer f=Date,PreviousDate -F -sub v=2013 u=oth4.csv i=dat4.csv o=rsl7.csv\n\
    #END# kgselstr -F -sub f=Date,PreviousDate i=dat4.csv k=Customer o=rsl7.csv u=oth4.csv v=2013\n\
    $ more rsl7.csv\n\
    Customer%0,Product,Amount,Gender,Date,PreviousDate\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    C,apple,100,2,2013/02/14,NULL\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    $ more oth4.csv\n\
    Customer%0,Product,Amount,Gender,Date,PreviousDate\n\
    D,orange,100,2,2011/10/28,NULL\n\
\n\
Example 8: Select new customer(s) who purchased in 2013\n\
\n\
Use the -R option to select all transactions of new customer(s) who made\n\
their first purchase in 2013, where date of previous purchase is NULL.\n\
Write the query results to an output file ¥verb|rsl8.csv|, and save\n\
unmatched records to oth5.csv.\n\
\n\
    $ mselstr k=Customer f=Date,PreviousDate -F -R -sub v=2013,NULL u=oth5.csv i=dat4.csv o=rsl8.csv\n\
    #END# kgselstr -F -R -sub f=Date,PreviousDate i=dat4.csv k=Customer o=rsl8.csv u=oth5.csv v=2013,NULL\n\
    $ more rsl8.csv\n\
    Customer%0,Product,Amount,Gender,Date,PreviousDate\n\
    C,apple,100,2,2013/02/14,NULL\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    $ more oth5.csv\n\
    Customer%0,Product,Amount,Gender,Date,PreviousDate\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    D,orange,100,2,2011/10/28,NULL\n\
";

