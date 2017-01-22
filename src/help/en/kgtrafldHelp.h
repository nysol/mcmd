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
/// kgtrafldHelp.h : kgtrafld help
// =============================================================================
_title="-";
_doc="\
\n\
MTRAFLD - CONVERT TRANSACTION FIELD TO CROSS (PIVOT) TABLE\n\
\n\
Create item pairs from the fields specified at f=, concatenate the item\n\
pairs and save as a new vector field (also referred to as transaction\n\
field).\n\
\n\
Format\n\
\n\
mtrafld a= [f=] [delim=] [delim2=] [-r] [-valOnly]  [i=] [o=]\n\
[-assert_diffSize] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno]\n\
[-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=         Specify the transaction field name.\n\
  f=         List of field name(s) (Multiple fields can be specified) [required when -r is specified,\n\
             otherwise, this parameter is optional]\n\
             The field names specified here will be created as connected items and saved in the transaction field.\n\
             When -r option is specified, specify the field name to extract from the transaction data.\n\
             This parameter is optional when -r option is specified.\n\
             If the parameter is not specified, all field names are processed as value pairs.\n\
             However, whenf= is not defined, this command cannot read standard input (using pipe).\n\
  delim=     Specify the character to separate each transaction field item (default delimiter:\n\
             space if this parameter is not defined).\n\
  delim2=    Specify the character to separate value pairs and field name (default character: =).\n\
  -r         Reverse conversion\n\
             Convert transaction field to cross table.\n\
  -valOnly   When this option is specified, the item do not return the prefix “field name=” in the output.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Join the fields price and quantity to a string, rename output field as\n\
transaction.\n\
\n\
    $ more dat1.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,325,2\n\
    C,200,3\n\
    D,450,2\n\
    E,100,1\n\
    $ mtrafld a=transaction f=price,quantity i=dat1.csv o=rsl1.csv\n\
    #END# kgtrafld a=transaction f=price,quantity i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    customer,transaction\n\
    A,price=198 quantity=1\n\
    B,price=325 quantity=2\n\
    C,price=200 quantity=3\n\
    D,price=450 quantity=2\n\
    E,price=100 quantity=1\n\
\n\
Example 2: Basic Example 2\n\
\n\
Use -r option to revert the output results back to the original data.\n\
\n\
    $ mtrafld -r a=transaction f=price,quantity i=rsl1.csv o=rsl2.csv\n\
    #END# kgtrafld -r a=transaction f=price,quantity i=rsl1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,325,2\n\
    C,200,3\n\
    D,450,2\n\
    E,100,1\n\
\n\
Example 3: Specify the delimiter\n\
\n\
Price and quantity field is separated by “_” (underscore) character and\n\
connected by 1 character string. Use colon and name the output field as\n\
transaction.\n\
\n\
    $ mtrafld a=transaction f=price,quantity delim=_ delim2=':' i=dat1.csv o=rsl3.csv\n\
    #END# kgtrafld a=transaction delim2=: delim=_ f=price,quantity i=dat1.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    customer,transaction\n\
    A,price:198_quantity:1\n\
    B,price:325_quantity:2\n\
    C,price:200_quantity:3\n\
    D,price:450_quantity:2\n\
    E,price:100_quantity:1\n\
\n\
Example 4: When data contains NULL value\n\
\n\
    $ more dat2.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,,2\n\
    C,200,\n\
    D,450,2\n\
    E,,\n\
    $ mtrafld a=transaction f=price,quantity i=dat2.csv o=rsl4.csv\n\
    #END# kgtrafld a=transaction f=price,quantity i=dat2.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    customer,transaction\n\
    A,price=198 quantity=1\n\
    B,quantity=2\n\
    C,price=200\n\
    D,price=450 quantity=2\n\
    E,\n\
\n\
Example 5: When data contains NULL value 2\n\
\n\
Use -r option to revert the output results back to the original data.\n\
\n\
    $ mtrafld -r a=transaction f=price,quantity i=rsl4.csv o=rsl5.csv\n\
    #END# kgtrafld -r a=transaction f=price,quantity i=rsl4.csv o=rsl5.csv\n\
    $ more rsl5.csv\n\
    customer,price,quantity\n\
    A,198,1\n\
    B,,2\n\
    C,200,\n\
    D,450,2\n\
    E,,\n\
\n\
Example 6: Specify -valOnly option\n\
\n\
    $ mtrafld -valOnly f=price,quantity a=transaction i=dat2.csv o=rsl6.csv\n\
    #END# kgtrafld -valOnly a=transaction f=price,quantity i=dat2.csv o=rsl6.csv\n\
    $ more rsl6.csv\n\
    customer,transaction\n\
    A,198 1\n\
    B,2\n\
    C,200\n\
    D,450 2\n\
    E,\n\
";

