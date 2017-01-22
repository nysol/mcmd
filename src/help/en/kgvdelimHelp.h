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
/// kgvdelimHelp.h : kgvdelim help
// =============================================================================
_title="-";
_doc="\
\n\
MVDELIM - CHANGE VECTOR DELIMITER\n\
\n\
Change delimiter used to separate between string of characters in a\n\
vector. However, the delimiter will be removed if an empty string is\n\
specified as the delimiter.\n\
\n\
Some examples are shown in Table - . When comma is used as delimiter, a\n\
pair of double quotation marks is added to the vector (Table). If a null\n\
character is specified as delimiter at v=, the delimiter between\n\
characters will be removed (Table ).\n\
\n\
Alphabet and chinese characters can be used as delimiter as shown in\n\
Table . Since the character type delimiter is read as character string\n\
as part of the vector by other commands such as mvsort, character type\n\
delimiter can be specified in delim=.\n\
\n\
ll\n\
\n\
in.csv\n\
\n\
   no  items     \n\
  ---- --------- --\n\
   1   b a a     \n\
   2   a a b b   \n\
   3   a b b a   \n\
   4   a b c     \n\
\n\
  : Use comma as a delimiter.\n\
\n\
vf=items v=- i=in.csv\n\
\n\
  no   items\n\
\n\
  1    b-a-a\n\
  2    a-a-b-b\n\
  3    a-b-b-a\n\
  4    a-b-c\n\
\n\
  : Use comma as a delimiter.\n\
\n\
vf=items v=, i=in.csv\n\
\n\
  no   items\n\
\n\
  1    “b,a,a”\n\
  2    “a,a,b,b”\n\
  3    “a,b,b,a”\n\
  4    “a,b,c”\n\
\n\
  : Use comma as a delimiter.\n\
\n\
ll\n\
\n\
vf=items v= i=in.csv\n\
\n\
  no   items\n\
\n\
  1    baa\n\
  2    aabb\n\
  3    abba\n\
  4    abc\n\
\n\
  : Specify more than one character\n\
\n\
vf=items v=xx i=in.csv\n\
\n\
  no   items\n\
\n\
  1    bxxaxxa\n\
  2    axxaxxbxxb\n\
  3    axxbxxbxxa\n\
  4    axxbxxc\n\
\n\
  : Specify more than one character\n\
\n\
Format\n\
\n\
mvdelim vf= v= [-A]  [i=] [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
  vf=   Field name of vector to replace the delimiter. Multiple fields can be specified.\n\
  v=    Define new delimiter. If the parameter is not defined, the delimiter is treated as an empty character.\n\
";

