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
/// kgxml2csvHelp.h : kgxml2csv help
// =============================================================================
_title="-";
_doc="\
\n\
MXML2CSV - CONVERT XML TO CSV \n\
\n\
Convert XML formatted data to CSV. The basic rule of conversion is by\n\
specifying the element as unit of each record (XML tag) and the element\n\
corresponding to the column (or attribute) at the parameters k=, f=. The\n\
value of the column can be specified in four ways : text bounded by\n\
elements, presence of elements, the value of the attribute, presence of\n\
attributes.\n\
\n\
When SAX is used as the parser of XML, there is no size constraints of\n\
XML. If other encoding besides UTF-8 is used in the XML file, the XML\n\
file is converted to UTF-8 and output as CSV. XML data should be\n\
structured in a complete, well-formed XML document. Otherwise, the\n\
program may return unexpected processing results.\n\
\n\
Table shows a typical format of XML data. More details are explained in\n\
the next section, however, a brief outline is illustrated as follows.\n\
\n\
Table shows the returned output. Element <b> is used as the key unit of\n\
each record (the element is referred to as “key element”). The column is\n\
defined by the attribute of element b for the value of att (CSV column\n\
name b_att). The attributes of element c includes the value of p (b_p)\n\
and flag (b_p_f), as well as the text inside element d and a (d, a).\n\
\n\
Here, the flag indicates the presence of specified elements or\n\
attributes by the value 0-1 in the output. The text output of the\n\
element includes the concatenation of all strings in the range within\n\
specified element. However, note that the spaces and the control\n\
characters are not included in the output.\n\
\n\
    <a att=\"aa\">\n\
      <b att=\"bb1\">\n\
        <c p=\"pp1\" q=\"qq1\"/>\n\
        <d>text1</d>\n\
      </b>\n\
      <b att=\"bb2\">\n\
        <c q=\"qq2\"></c>\n\
        <d>text2</d>\n\
      </b>\n\
      <b>\n\
        <c p=\"pp3\"/>\n\
        <d>text3</d>\n\
      </b>\n\
    </a>\n\
\n\
  b_att   c_p   c_p_f   d       a\n\
  ------- ----- ------- ------- -----------------\n\
  bb1     pp1   1       text1   text1\n\
  bb2                   text2   text1text2\n\
          pp3   1       text3   text1text2text3\n\
\n\
  : key:/a/b, item:b@att,c@p,d,/a\n\
\n\
Specifying the key element\n\
\n\
Specify the key element as the key unit of each record (specified in the\n\
parameter k=) with an absolute path. The absolute path is defined from\n\
the root directory starting from the symbol ('/'), the hierarchy of\n\
elements is separated by the sign '/'. The role of the key elements in\n\
this command is to perform the following two functions corresponding to\n\
the end tag of the key elements.\n\
\n\
-   Output one row of column data. In the example above, the end tag of\n\
    the key elements </b> has appeared three times, one row of CSV data\n\
    is inserted as a new line for every instance in the output.\n\
\n\
-   Initialize the column data. However, it does not initialize the\n\
    column elements outside the key elements in the output data. In\n\
    Table , the text in the output of element a will be consolidated,\n\
    even when the end tag of the key elements has emerged, the element\n\
    /a is outside the key elements /a/b. As a result, the output data is\n\
    not initialized.\n\
\n\
Specifying the elements in output column \n\
\n\
If the element defined at f= is returned as a CSV field in the output,\n\
follow the format shown below.\n\
\n\
Element path[%flag]: CSV field name\n\
\n\
“Field name” is the column name in the CSV output which must be\n\
specified.\n\
\n\
There are two methods to display elements as columns in the output. The\n\
first method is to return the text enclosed by the opening and closing\n\
tags of the specified element. The other method is to return 0-1 value\n\
to indicate whether the specified element exists. The target element\n\
path is defined in the former method, and the the flag %f is added when\n\
using the latter method.\n\
\n\
The two methods of specifying the element path include absolute and\n\
relative paths. A relative path can be specified by defining the path\n\
from elements at k=. Table shows examples on how to specify the element\n\
paths of the XML data.\n\
\n\
-   Given k=/a/b, when f=:B is specified, the key elements is the same\n\
    when relative path is nil. B is the column name of CSV.\n\
\n\
-   Given k=/a/b, f=c:C and f=/a/b/c:C performs the same function. The\n\
    former is specified by relative path, while the latter by an\n\
    absolute path. The CSV field name is defined as C for both methods.\n\
\n\
-   f=d:D returns the text within the element d.\n\
    f=d%f:D returns output when element \\verbd| exists. The field name\n\
    of CSV is D.\n\
\n\
-   When k=/a/b, it is assumed that f=/a:A, the column element is\n\
    outside the key element, the text contained in the element a are\n\
    combined in sequential order. The end tag of the key element exists,\n\
    however, the end tag of the field element does not exists, this is\n\
    because data is not cleared at the time.\n\
\n\
Specifying attributes in output column\n\
\n\
If the attribute defined at f= is returned as a CSV column, use the\n\
format shown below.\n\
\n\
Element path@Element name[%flag]:CSV field name\n\
\n\
“Field name” is the column name in the CSV output which must be\n\
specified.\n\
\n\
The method of specifying the element path is the same as specifying the\n\
elements in the output field. The attribute name is specified after the\n\
element path connected with @. By adding %f after the element name, the\n\
presence of the element can be indicated by 0-1 value in the output.\n\
\n\
Format\n\
\n\
mxml2csv k= f= [i=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
Examples\n\
\n\
Example 1: Basic example\n\
\n\
The example below is illustrated in the summary above. Output the 5 CSV\n\
fields with /a/b set as the key elements.\n\
\n\
    $ more dat1.xml\n\
    <a att=\"aa\">\n\
      <b att=\"bb1\">\n\
        <c p=\"pp1\" q=\"qq1\"/>\n\
        <d>text1</d>\n\
      </b>\n\
      <b att=\"bb2\">\n\
        <c q=\"qq2\"></c>\n\
        <d>text2</d>\n\
      </b>\n\
      <b>\n\
        <c p=\"pp3\"/>\n\
        <d>text3</d>\n\
      </b>\n\
    </a>\n\
    $ mxml2csv k=/a/b f=@att:b_att,c@p:c_p,c@p%f:c_p_f,d:d,/a:a i=dat1.xml o=rsl1.csv\n\
    #END# kgxml2csv f=@att:b_att,c@p:c_p,c@p%f:c_p_f,d:d,/a:a i=dat1.xml k=/a/b o=rsl1.csv\n\
    $ more rsl1.csv\n\
    b_att,c_p,c_p_f,d,a\n\
    bb1,pp1,1,text1,text1\n\
    bb2,,,text2,text1text2\n\
    ,pp3,1,text3,text1text2text3\n\
\n\
Example 2: Absolute path\n\
\n\
Specification of same element as in the basic example with an absolute\n\
path. Output the 5 CSV fields with /a/b as the key elements.\n\
\n\
    $ mxml2csv k=/a/b f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml  \n\
    o=rsl2.csv\n\
    #END# kgxml2csv f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml \n\
    k=/a/b o=rsl2.csv\n\
    $ more rsl2.csv\n\
    b_att,c_p,c_p_f,d,a\n\
    bb1,pp1,1,text1,text1\n\
    bb2,,,text2,text1text2\n\
    ,pp3,1,text3,text1text2text3\n\
\n\
Example 3: Changing key elements\n\
\n\
Example of changing a key element to a using an absolute path. Since\n\
there is only one end tag a, one row of record will be returned as\n\
output. /a/b@att specified at f= appeared twice, the last value is\n\
returned as output.\n\
\n\
    $ mxml2csv k=/a f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml \n\
    o=rsl3.csv\n\
    #END# kgxml2csv f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml \n\
    k=/a o=rsl3.csv\n\
    $ more rsl3.csv\n\
    b_att,c_p,c_p_f,d,a\n\
    bb2,pp3,1,text3,text1text2text3\n\
";

