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
/// kgtonullHelp.h : kgtonull help
// =============================================================================
_title="-";
_doc="\
\n\
MTONULL - SUBSTITUTE VALUE FOR NULL\n\
\n\
Specify the target field parameter at f= , substitute the value at the\n\
v= parameter with NULL in the data. Select the methods for finding\n\
patterns using exact string matching (the default) or substring matching\n\
(-sub option).\n\
\n\
Format\n\
\n\
mtonull f= v= [-sub] [-W] [i=] [o=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   specify list of field name(s) (multiple fields can be specified) where the values are replaced .\n\
  v=   Specify the character string value (multiple items can be specified) for matching the field defined at f= parameter.\n\
       Replace the matched values with NULL.\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Replace 0 with NULL value in columns quantity and price.\n\
\n\
    $ more dat1.csv\n\
    item,quantity,price\n\
    A,0,1\n\
    B,1,0\n\
    C,2,200\n\
    D,3,0\n\
    E,0,298\n\
    $ mtonull f=quantity,price v=0 i=dat1.csv o=rsl1.csv\n\
    #END# kgtonull f=quantity,price i=dat1.csv o=rsl1.csv v=0\n\
    $ more rsl1.csv\n\
    item,quantity,price\n\
    A,,1\n\
    B,1,\n\
    C,2,200\n\
    D,3,\n\
    E,,298\n\
\n\
Example 2: Replace a specified number with NULL value\n\
\n\
Replace 0 or 1 with NULL value in columns quantity and price.\n\
\n\
    $ mtonull f=quantity,price v=0,1 i=dat1.csv o=rsl2.csv\n\
    #END# kgtonull f=quantity,price i=dat1.csv o=rsl2.csv v=0,1\n\
    $ more rsl2.csv\n\
    item,quantity,price\n\
    A,,\n\
    B,,\n\
    C,2,200\n\
    D,3,\n\
    E,,298\n\
\n\
Example 3: Substitute substring match\n\
\n\
Replace with a NULL value where quantity and price columns contain 0.\n\
\n\
    $ mtonull -sub f=quantity,price v=0 i=dat1.csv o=rsl3.csv\n\
    #END# kgtonull -sub f=quantity,price i=dat1.csv o=rsl3.csv v=0\n\
    $ more rsl3.csv\n\
    item,quantity,price\n\
    A,,1\n\
    B,1,\n\
    C,2,\n\
    D,3,\n\
    E,,298\n\
\n\
Example 4: Substitute character string\n\
\n\
Replace the string in the item field that matches character string\n\
apple, orange, pineapple with NULL value.\n\
\n\
    $ more dat2.csv\n\
    item,price\n\
    fruit:apple,100\n\
    fruit:peach,250\n\
    fruit:grape,300\n\
    fruit:pineapple,450\n\
    fruit:orange,500\n\
    $ mtonull f=item v=apple,orange,pineapple -sub i=dat2.csv o=rsl4.csv\n\
    #END# kgtonull -sub f=item i=dat2.csv o=rsl4.csv v=apple,orange,pineapple\n\
    $ more rsl4.csv\n\
    item,price\n\
    ,100\n\
    fruit:peach,250\n\
    fruit:grape,300\n\
    ,450\n\
    ,500\n\
";

