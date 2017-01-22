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
/// kgsedHelp.h : kgsed help
// =============================================================================
_title="-";
_doc="\
\n\
MSED - REPLACE STRING MATCHING REGULAR EXPRESSION\n\
\n\
Replace string in the fields specified in the f= parameter with a string\n\
specified in the v= parameter for content that matches the regular\n\
expression specified in the c= parameter .\n\
\n\
Format\n\
\n\
msed c= f= v= [-A] [-g] [-W]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  f=   specify the target list of field name(s) (multiple fields can be specified) for parsing.\n\
  c=   Define the regular expression for string substitution.\n\
       Refer to usage of regular expressions.\n\
  v=   Specify the string to replace the substring that matches with the regular expression specified in the c= parameter.\n\
       It is possible to substitute match result with the following methods:\n\
       $& : Matched string\n\
       $` : Search for the string from the beginning of the target replacement character string, until a string is matched.\n\
       $' : After a matched string, substitute target replacement string with matched string till the end.\n\
       $N : partial string match for the N-th occurrance (N>=1).\n\
  -A   Instead of replacing the specified field, add field as a new column.\n\
  -g   Replace all matches of the regular expression.\n\
  -W   Replace wide character matches of the regular expression.\n\
\n\
Using regular expressions\n\
\n\
List of regular expression specified in the c= parameter is shown from\n\
Table to Table .\n\
\n\
  Regular expression   Description                                 Example of pattern   Example of c=,v=   Result\n\
  -------------------- ------------------------------------------- -------------------- ------------------ ----------\n\
  .                    Any character                               abbbcc               c=. v=X -g         XXXXXX\n\
  [abc]                either a,b, or c character                  abbbcc               c=[ac] v=X -g      XbbbXX\n\
  [^abc]               Any character other than a,b,c              abbbcc               c=[^ac] v=X -g     aXXXcc\n\
  [a-z]                Any character from a to z                   abbbcc               c=[a-b] v=X -g     XXXXcc\n\
  [^a-z]               Any character outside the range of a to z   abbbcc               c=[^a-b] v=X -g    abbbXX\n\
  \\t                   Tab character                                                                       \n\
  \\w                   Word string ([0-9a-zA-Z_])                  ab#cd&ef             c=\\w v=X -g        XX#XX&XX\n\
  \\W                   Characters other than Word string           ab#cd&ef             c=\\w v=X -g        abXcdXef\n\
  \\s                   Space character ([ \\t])                     ab cd ef             c=\\s v=X -g        abXcdXef\n\
  \\S                   Non-whitespace character                    ab cd ef             c=\\s v=X -g        XX XX XX\n\
  \\d                   Numeric constituent characters ([0-9])      ab12c0               c=\\d v=X -g        abXXcX\n\
  \\D                   Non-numeric constituent characters          ab12c0               c=\\d v=X -g        XX12X0\n\
\n\
  : Regular expression match with 1 character\n\
\n\
  Regular expression   Description                                   Example of pattern   Example of c=,v=   Result\n\
  -------------------- --------------------------------------------- -------------------- ------------------ --------\n\
  a*                   Zero or more repetition of a                  abbbcc               c=ab* v=X          Xcc\n\
  a+                   Repetition of one or more a                   abbbcc               c=ab+ v=X          Xcc\n\
  a?                   Single occurrence of a                        abbbcc               c=ab? v=X          Xbbcc\n\
  a{M,N}               Repetition of a more than M and less than N   abbbbbcc             c=ab{3,4} v=X      Xbcc\n\
  a{M}                 Repetition of a more than M times             abbbbbcc             c=ab{3} v=X        Xbbcc\n\
  a｜b                 a or b                                        abbbc                c=(ab)｜(bc) v=X   XbX\n\
  ?                    Shortest match after the repeat sign          abbbc                c=ab*? v=X         Xbbbc\n\
\n\
  : Repetition of regular expressions\n\
\n\
  Regular expression   Description                           Example of pattern   Example of c=,v=   Result\n\
  -------------------- ------------------------------------- -------------------- ------------------ ---------------\n\
  ^                    Match from the beginning              abac                 c=^a v=X -g        Xbac\n\
  $                    Match till the end                    acac                 c=c$ v=X -g        acaX\n\
  \\b                   Match starting characters of string   aac ba ac bac        c=\\ba v=X -g       Xac bX Xc bac\n\
  \\B                   Match within the string               aac ba ac bac        c=\\Ba v=X -g       aXc ba ac bXc\n\
\n\
  : Position of regular expression\n\
\n\
  Regular expression   Description                                Example of pattern   Example of c=,v=   Result\n\
  -------------------- ------------------------------------------ -------------------- ------------------ --------\n\
  (expr)               Grouping                                                                           \n\
  \\1,..,\\9             Back reference                             abbcababc            c=(ab)(bc)\\1 v=x   Xabc\n\
  (?=expr)             Position before matched string at expr                                             \n\
  (?!expr)             Position before unmatched string at expr                                           \n\
\n\
  : Others\n\
\n\
Examples\n\
\n\
Example 1: Basic Example\n\
\n\
Replace the 4-digit substring in the zipCode field starting 00 with\n\
####.\n\
\n\
    $ more dat1.csv\n\
    customer,zipCode\n\
    A,6230041\n\
    B,6240053\n\
    C,6330032\n\
    D,6230087\n\
    E,6530095\n\
    $ msed f=zipCode c=00.. v=#### i=dat1.csv o=rsl1.csv\n\
    #END# kgsed c=00.. f=zipCode i=dat1.csv o=rsl1.csv v=####\n\
    $ more rsl1.csv\n\
    customer,zipCode\n\
    A,623####\n\
    B,624####\n\
    C,633####\n\
    D,623####\n\
    E,653####\n\
\n\
Example 2: Specify field name\n\
\n\
Replace the 4-digit substring in the zipCode field starting 00 with\n\
####. Save output in column zipCode4.\n\
\n\
    $ msed f=zipCode:zipCode4 c='00\\d\\d' v=#### i=dat1.csv o=rsl2.csv\n\
    #END# kgsed c=00\\d\\d f=zipCode:zipCode4 i=dat1.csv o=rsl2.csv v=####\n\
    $ more rsl2.csv\n\
    customer,zipCode4\n\
    A,623####\n\
    B,624####\n\
    C,633####\n\
    D,623####\n\
    E,653####\n\
\n\
Example 3: Global replacement\n\
\n\
Global search using the regular expression - to replace value of 0 in\n\
zipCode.\n\
\n\
    $ msed f=zipCode c=0 v=- -g i=dat1.csv o=rsl3.csv\n\
    #END# kgsed -g c=0 f=zipCode i=dat1.csv o=rsl3.csv v=-\n\
    $ more rsl3.csv\n\
    customer,zipCode\n\
    A,623--41\n\
    B,624--53\n\
    C,633--32\n\
    D,623--87\n\
    E,653--95\n\
\n\
Example 4: Replace substring\n\
\n\
Delete fruit from the beginning of the string in item. Note that when\n\
first match (^) is specified, the substring within the word grapefruit\n\
in the last row is retained.\n\
\n\
    $ more dat2.csv\n\
    item,price\n\
    fruit:apple,100\n\
    fruit:peach,250\n\
    fruit:pineapple,300\n\
    fruit:orange,450\n\
    fruit:grapefruit,500\n\
    $ msed f=item c='^fruit' v= -g i=dat2.csv o=rsl4.csv\n\
    #END# kgsed -g c=^fruit f=item i=dat2.csv o=rsl4.csv v=\n\
    $ more rsl4.csv\n\
    item,price\n\
    :apple,100\n\
    :peach,250\n\
    :pineapple,300\n\
    :orange,450\n\
    :grapefruit,500\n\
\n\
Example 5: Substitution using match results\n\
\n\
Replaced 1 or more consecutive character strings of b using $& is\n\
defined in the v=.\n\
\n\
    $ more dat3.csv\n\
    str1\n\
    abc\n\
    abbc\n\
    ac\n\
    $ msed f=str1 c='b+' v='#$&#' i=dat3.csv o=rsl5.csv\n\
    #END# kgsed c=b+ f=str1 i=dat3.csv o=rsl5.csv v=#$&#\n\
    $ more rsl5.csv\n\
    str1\n\
    a#b#c\n\
    a#bb#c\n\
    ac\n\
\n\
Example 6: Combination of the global match\n\
\n\
When performing a global match, each match is evaluated against the\n\
contents defined at v=.\n\
\n\
    $ msed f=str1 c=b v='#$&#' -g i=dat3.csv o=rsl6.csv\n\
    #END# kgsed -g c=b f=str1 i=dat3.csv o=rsl6.csv v=#$&#\n\
    $ more rsl6.csv\n\
    str1\n\
    a#b#c\n\
    a#b##b#c\n\
    ac\n\
\n\
Example 7: Prefix substitution\n\
\n\
Replace the matching first character of b in the character string\n\
(prefix) using $`.\n\
\n\
    $ msed f=str1 c=b v='#$`#' i=dat3.csv o=rsl7.csv\n\
    #END# kgsed c=b f=str1 i=dat3.csv o=rsl7.csv v=#$`#\n\
    $ more rsl7.csv\n\
    str1\n\
    a#a#c\n\
    a#a#bc\n\
    ac\n\
\n\
Example 8: Suffix substitution\n\
\n\
Replace the matching last character of b in the character string\n\
(suffix) using $'.\n\
\n\
    $ msed f=str1 c=b v=\"#$'#\" i=dat3.csv o=rsl8.csv\n\
    #END# kgsed c=b f=str1 i=dat3.csv o=rsl8.csv v=#$'#\n\
    $ more rsl8.csv\n\
    str1\n\
    a#c#c\n\
    a#bc#bc\n\
    ac\n\
";

