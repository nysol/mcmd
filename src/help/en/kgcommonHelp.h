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
/// kgcommonHelp.h : kgcommon help
// =============================================================================
_title="-";
_doc="\
\n\
MCOMMON - SELECT COMMON RECORDS IN REFERENCE FILE\n\
\n\
Compare records in the input file with the ones in the reference file,\n\
at which reference file is specified in m= parameter. Set the key\n\
parameter at k= for selecting records common in both files.\n\
\n\
Format\n\
\n\
mcommon  k= [K=] [u=] [-r] m=| i= [o=] [-option_assert_diffSize]\n\
[-option_assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  k=   List of key field(s) to match the input data (Multiple keys can be specified)\n\
       Records in the input file matching the key field(s) in the reference file specified at K= is selected.\n\
       Records with same key values will appear in consecutive rows.\n\
  m=   Specify reference file name\n\
       Standard input is used when this parameter is omitted (when i= option is specified).\n\
  K=   Key field(s) to match with from the reference data (Multiple keys can be specified).\n\
       Records in the reference file that matches the key field specified in the k= parameter is selected.\n\
       The parameter is not required if the key field is the same on both input data and reference file.\n\
       Records with same key values will therefore appear in consecutive rows.\n\
  u=   File name of output with unmatched records.\n\
  -r   Reverse selection\n\
       Compare the value specified at k= parameter from the input file\n\
       with the value from the reference file specified at m= parameter,\n\
       and select unmatched record(s) from the input file.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Select records with common customers in both input file and reference\n\
file. Save unmatched records to a separate file oth.csv.\n\
\n\
    $ more dat1.csv\n\
    Customer,Quantity\n\
    A,1\n\
    B,2\n\
    C,1\n\
    D,3\n\
    E,1\n\
    $ more ref1.csv\n\
    Customer,Gender\n\
    A,Female\n\
    B,Male\n\
    E,Female\n\
    $ mcommon k=Customer m=ref1.csv u=oth.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgcommon i=dat1.csv k=Customer m=ref1.csv o=rsl1.csv u=oth.csv\n\
    $ more rsl1.csv\n\
    Customer%0,Quantity\n\
    A,1\n\
    B,2\n\
    E,1\n\
    $ more oth.csv\n\
    Customer%0,Quantity\n\
    C,1\n\
    D,3\n\
\n\
Example 2: Select unmatched records from the input file\n\
\n\
Reverse selection criteria by using the -r option, the “Customer” not in\n\
the reference file are selected.\n\
\n\
    $ mcommon k=Customer m=ref1.csv -r i=dat1.csv o=rsl2.csv\n\
    #END# kgcommon -r i=dat1.csv k=Customer m=ref1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Customer%0,Quantity\n\
    C,1\n\
    D,3\n\
\n\
Example 3: Different names of join key\n\
\n\
If the join key field name in the reference file is different, specify\n\
the field name at ¥verb|K=|.\n\
\n\
    $ more ref2.csv\n\
    CustomerID,Gender\n\
    A,Female\n\
    B,Male\n\
    E,Female\n\
    $ mcommon k=Customer K=CustomerID i=dat1.csv m=ref2.csv o=rsl3.csv\n\
    #END# kgcommon K=CustomerID i=dat1.csv k=Customer m=ref2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    Customer%0,Quantity\n\
    A,1\n\
    B,2\n\
    E,1\n\
\n\
Example 4: Example with duplicate key fields\n\
\n\
Record selection with duplicate records in both input file and reference\n\
file.\n\
\n\
    $ more dat3.csv\n\
    Customer,Quantity \n\
    A,1\n\
    A,2\n\
    A,3\n\
    B,1\n\
    D,1\n\
    D,2\n\
    $ more ref3.csv\n\
    Customer\n\
    A\n\
    A\n\
    D\n\
    $ mcommon k=Customer m=ref3.csv -r i=dat3.csv o=rsl4.csv\n\
    #END# kgcommon -r i=dat3.csv k=Customer m=ref3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    Customer%0,Quantity \n\
    B,1\n\
";

