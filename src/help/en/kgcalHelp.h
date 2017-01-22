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
/// kgcalHelp.h : kgcal help
// =============================================================================
_title="-";
_doc="\
\n\
MCAL - COMPUTATION BETWEEN COLUMNS\n\
\n\
Define the computation formula at the c= parameter, and name the new\n\
data attribute at the a= parameter. The output of mcal is limited to 1\n\
result without exception to simplify the program. For details of the\n\
calculation formula, please refer to the section on “Components in the\n\
expression\".\n\
\n\
Format\n\
\n\
mcal a= c= [i=] [o=] [-option_assert_diffSize] [-option_assert_nullkey]\n\
[-option_assert_nullin] [-option_assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
Parameters\n\
\n\
  a=   Specify the new column name to store the calculated field.\n\
  c=   Define an expression with a combination of calculation functions available.\n\
\n\
Examples\n\
\n\
Basic usage of mcal is illustrated in the following example. For more\n\
information on the explanation and usage of individual functions and\n\
operators, please refer to the corresponding reference.\n\
\n\
    # Input data (dat1.csv)\n\
    customer,quantity,unitprice\n\
    A,3,10\n\
    B,1,15\n\
    C,2,20\n\
\n\
    $ mcal c='${quantity}*${unitprice}' a=amount i=dat1.csv\n\
    customer,unit price,amount\n\
    A,3,10,30\n\
    B,1,15,15\n\
    C,2,20,40\n\
\n\
    $ mcal c='${quantity}*${unitprice}<=30' a=amountbelow30 i=dat1.csv\n\
    customer,unit price,amountbelow30\n\
    A,3,10,1\n\
    B,1,15,1\n\
    C,2,20,0\n\
\n\
    $ mcal c='if(top(),${unit price},#{}+${unitprice})' a=AccumUnitprice i=dat1.csv\n\
    customer,unitprice,AccumUnitprice\n\
    A,3,10,10\n\
    B,1,15,25\n\
    C,2,20,45\n\
\n\
CONSTANT\n\
\n\
  Data type               Format                        Description                                                  Example             \n\
  ----------------------- ----------------------------- ------------------------------------------------------------ ------------------- --\n\
  Numerical Value(num)    integer, real number string   Double precision floating point numbers is used internally   20, 0.55, 1.5*e10   \n\
  Character string(str)   “Character string”            Character string enclosed in double quotes                   \"abc\" \"日本語\"      \n\
  Date (date)             0dyyyymmdd                    Add “0d” before fixed length year month day                  0d20080923          \n\
  Time (time)             0tyyyymmddHHMMSS              Add “0t” before fixed length year, month, date,              0t20080923121115    \n\
                                                        time, minute and second                                                          \n\
                          0tHHMMSS                      add “0t” before fixed length time, minute and second         0t121115            \n\
                                                        (current date stored internally)                                                 \n\
  Boolean (bool)          0b1, 0b0                      Add “0b” before “1”(true) and “0”(false)                     0b1, 0b0            \n\
\n\
  : Summary of constant attributes\n\
\n\
FIELD VALUE\n\
\n\
Table shows the different data formats in the data field, the type of\n\
CSV data varies depends on how it is used and defined by the user.\n\
\n\
  Data                    Format          Content of CSV Data                                          Example                        \n\
  ----------------------- --------------- ------------------------------------------------------------ ------------------------------ --\n\
  Numerical value(num)    ${fieldname}    Integer, real number (including floating Numerical string    ${amount}, ${stockprice}       \n\
  Character string(str)   $s{fieldname}   Character string                                             $s{gender}, $s{gender}         \n\
  Date(date)              $d{fieldname}   Fixed length year month day (yyyymmdd)                       $d{date}, $d{orderdate}        \n\
  Time(time)              $t{fieldname}   Fixed length year month day minute second (yyyymmddHHMMSS)   $d{time}, $d{departuretime}    \n\
                                          Fixed length hour minute second (HHMMSS)                                                    \n\
                                          (current date stored internally)                                                            \n\
  Boolean(bool)           $b{fieldname}   The value is expressed as “1” if true and “0” if false、     $b{condition}, $b{condition}   \n\
                                          Other cases treated as NULL                                                                 \n\
\n\
  : Format of field\n\
\n\
VALUE FROM PREVIOUS ROW \n\
\n\
Use the # symbol instead of $ to refer to values from a field in the\n\
previous row. However, the function will return null when used on the\n\
first record since there is no record preceding the first record. The\n\
specification of each data type is shown in below.\n\
\n\
  Data type               Format          Example                        \n\
  ----------------------- --------------- ------------------------------ --\n\
  Numeric(num)            #{fieldname}    #{amount}, #{stockprice}       \n\
  Character string(str)   #s{fieldname}   #s{gender}, #s{gender}         \n\
  Date(date)              #d{fieldname}   #d{date}, #d{releasedate}      \n\
  Time(time)              #t{fieldname}   #d{time}, #d{departuretime}    \n\
  Boolean(bool)           #b{fieldname}   #b{condition}, #b{condition}   \n\
\n\
  : Specification of retrieving values from previous row\n\
\n\
VALUES FROM NEXT ROW\n\
\n\
Use the expression to obtain value from the previous record without\n\
specifying the field name to obtain the value in the next record. The\n\
specification of the data types are shown in .\n\
\n\
It is possible to calculate total by combining if function with top()\n\
function. The cumulative calculation on the amount field is shown below.\n\
\n\
$ mcal c='if(top(),${amount},${amount}+#{})' a=cumulativeAmount\n\
\n\
  Data Type               Format   Example\n\
  ----------------------- -------- ---------\n\
  Numeric(num)            #{}      #{}\n\
  Character String(str)   #s{}     #s{}\n\
  Date(date)              #d{}     #d{}\n\
  Time(time)              #t{}     #d{}\n\
  Boolean(bool)           #b{}     #b{}\n\
\n\
  : Specification to retrieve values from previous row\n\
\n\
ARITHMETIC OPERATORS\n\
\n\
The + and - arithmetic operators can be used on numeric format strings\n\
as well as date and character format strings. The data format is shown\n\
in Table .\n\
\n\
  Operator             Format          Description                     Example\n\
  -------------------- --------------- ------------------------------- ---------------------------\n\
  Addition(+)          num₁ + num₂     Addition of numeric values      1.5+2.3 (3.8)\n\
                       str₁ + str₂     Join character strings          \"150\"+\"円\" (\"150円\")\n\
                       date + num      num days after date             0d20121130+2 (0d20121202)\n\
                       time + num      num seconds after time          0t095959+2 (0t100001)\n\
  Substraction(-)      num₁ − num₂     Subtraction of numeric values   1.5-2.3 (-1.8)\n\
                       str₁ − str₂     Remove substring                \"aababa\"-\"a\" (\"bb\")\n\
                                       (by greedy match algorithm)     \"aababa\"-\"aba\" (\"aba\")\n\
                       date − num      num days before date            0d20121202-2 (0d20121130)\n\
                       time − num      num seconds before time         0t100001-2 (0t095959)\n\
                       date₁ − date₂   Date difference                 0d20121202-0d20121130 (2)\n\
                       time₁ − time₂   Time difference                 0t095959-0t100001 (-2)\n\
  Multiplication (*)   num₁ * num₂     multiply                        10*2 (20)\n\
  Division (/)         num₁/num₂       divide                          10/2 (5)\n\
  Remainder (%)        num₁%num₂       remainder                       10%3 (1)\n\
  Power (^)            num₁^num₂       power                           10^3 (1000)\n\
\n\
  : Summary of arithmetic operators\n\
\n\
The results of the examples are shown in parentheses (the content is\n\
shown using constant numbers).\n\
\n\
COMPARISON OPERATORS \n\
\n\
The comparison operators can only be used on data of the same type.\n\
Table shows the list of operators for numeric format data. Similarly,\n\
the operators shown in the table below can be applied to character\n\
format, date format, time format data.\n\
\n\
  Details of comparison   Format         Example\n\
  ----------------------- -------------- ------------------------------------\n\
  Equal                   num₁ = =num₂   1.5==1.5(0b1), \"abc\"==\"abcd\" (0b0)\n\
  Not equal               num₁!=num₂     1.5!=1.5(0b0), \"abc\"==\"abcd\" (0b1)\n\
  Greater than            num₁ > num₂    10>5(0b1), \"abc\">\"abcd\" (0b0)\n\
  Less than               num₁ < num₂    10<5(0b0), \"abc\"<\"abcd\" (0b1)\n\
  Above                   num₁ > =num₂   10>=10(0b1), \"a\">\"\" (0b1) \n\
  Below                   num₁ < =num₂   8<=9(0b1), \"a\"<=\"a\" (0b1)\n\
\n\
  : Summary of comparison operators\n\
\n\
The results of the examples are shown in parentheses (the content is\n\
shown using constant numbers).\n\
\n\
LOGICAL OPERATOR\n\
\n\
The usage of the three logical operators (conjunction, disjunction,\n\
exclusive or) is shown in Table . In addition the results of the\n\
combination of boolean values (1:true, 0:false) are shown in Table\n\
,Table and Table .\n\
\n\
  Description    Format           Example\n\
  -------------- ---------------- ------------------------------------\n\
  Conjunction    bool₁&&bool₂     \"abc\"==\"abc\" && \"xyz\"==\"abc\" (0b0)\n\
  Disjunction    bool₁||bool₂     \"abc\"==\"abc\" || \"xyz\"==\"abc\" (0b1)\n\
  Exclusive or   bool₁ ^^ bool₂   \"abc\"==\"abc\" ^^ \"xyz\"==\"abc\" (0b1)\n\
\n\
  : Summary of logical operators\n\
\n\
The results of the examples are shown in parentheses (the content is\n\
shown using constant numbers).\n\
\n\
   bool₁   bool₂   Result\n\
  ------- ------- --------\n\
     1       1       1\n\
     1       0       0\n\
     0       1       0\n\
     0       0       0\n\
   null      1      null\n\
   null      0       0\n\
   null    null     null\n\
\n\
  : Exclusive Or\n\
\n\
   bool₁   bool₂   Result\n\
  ------- ------- --------\n\
     1       1       1\n\
     1       0       1\n\
     0       1       1\n\
     0       0       0\n\
   null      1       1\n\
   null      0      null\n\
   null    null     null\n\
\n\
  : Exclusive Or\n\
\n\
   bool₁   bool₂   Result\n\
  ------- ------- --------\n\
     1       1       0\n\
     1       0       1\n\
     0       1       1\n\
     0       0       0\n\
   null      1      null\n\
   null      0      null\n\
   null    null     null\n\
\n\
  : Exclusive Or\n\
\n\
FUNCTION\n\
\n\
The following highlights the 9 types of functions in relation to numeric\n\
strings (), trigonometric function (), character strings (), regular\n\
expression (), date / time (), logical (), row/column information (),\n\
Null value (), data type conversion ().\n\
\n\
  Section   Function name                                          Function                  Output type\n\
  --------- ------------------------------------------------------ ------------------------- -------------\n\
            sum(num₁, num₂, …)                                     Sum                       num\n\
            avg(num₁, num₂, …)                                     Average                   num\n\
            sqsum(num₁, num₂, …)                                   Sum of squares            num\n\
            min(num₁, num₂, …)                                     Minimum value             num\n\
            max(num₁, num₂, …)                                     Maximum value             num\n\
            product(num₁, num₂, …)                                 Product                   num\n\
            factorial(num)                                         Factorial                 num\n\
            gcd(num₁,num₂)                                         Greatest common divisor   num\n\
            lcm(num₁,num₂)                                         Least common multiple     num\n\
            sqrt(num)                                              Square root               num\n\
            abs(num)                                               Absolute value            num\n\
            sign(num)                                              Sign                      num\n\
            int(num)                                               Integer part              num\n\
            fract(num)                                             Fraction part             num\n\
            round(num,nominal value)                               Rounding up               num\n\
            floor(num,nominal value)                               Rounding down             num\n\
            ceil(num,nominal value)                                Ceiling                   num\n\
            power(num,exponent)                                    Power                     num\n\
            exp(num)                                               Exponential function      num\n\
            log(num,base)                                          logarithm                 num\n\
            ln(num)                                                Natural logarithm         num\n\
            log2(num)                                              Binary logarithm          num\n\
            log10(num)                                             Common logarithm          num\n\
            dist(type,num₁, num₂, …)                               Distance                  num\n\
            distgps(latitude1,longtitude1,latitude2,longtitude2)   GPS distance              num\n\
            heron(num₁, num₂, …)                                   Heron’s formula           num\n\
            rand([random seed])                                    Uniform random number     num\n\
            randi(minimum value, maximum value[, random seed])     Uniform random number     num\n\
            nrand(minimum value, maximum value[, random seed])     Normal random number      num\n\
            pi()                                                   Pi                        num\n\
            e()                                                    Napier’s constant         num\n\
            format()                                               Format output             str\n\
\n\
  : Summary of numerical functions\n\
\n\
  Section   Function Name      Function                                        Output range\n\
  --------- ------------------ ----------------------------------------------- --------------\n\
            acos(num)          Inverse cosine                                  0 π\n\
            asin(num)          Inverse sine                                    −π π\n\
            atan(num)          Inverse tangent                                 −π π\n\
            atan2(num₁,num₂)   Angle of coordinates (num₁, num₂)               −π π\n\
            cos(r)             Cosine                                          −1.0 1.0\n\
            sin(r)             Sine                                            −1.0 1.0\n\
            tan(r)             Tangent                                         −∞ ∞\n\
            degree(r)          Degree                                          −π π\n\
            radian(angle)      Enter angle as input, return radian as output   −π π\n\
            cosh(r)            Hyperbolic cosine                               0 ∞\n\
            sinh(r)            Hyperbolic sine                                 −∞ ∞\n\
            tanh(r)            Hyperbolic tangent                              −1.0 1.0\n\
\n\
  : List of trigonometric functions\n\
\n\
Radian is represented by the variable r.\n\
\n\
  Section   Function name                                   Function                                          Output format\n\
  --------- ----------------------------------------------- ------------------------------------------------- ---------------\n\
            cat(token, str₁, str₂, …)                       Merge character string                            str\n\
            length(str)                                     Length of character string                        num\n\
            fixlen(str,length,position,padding character)   Fixed length conversion                           str\n\
            right(str,length)                               Extract substring from the end                    str\n\
            left(str,length)                                Extract substring from the beginning              str\n\
            mid(str,starting position,length)               Extract substring                                 str\n\
            toupper(str)                                    Convert characters from lowercase to uppercase    str\n\
            tolower(str)                                    Converts characters from uppercase to lowercase   str\n\
            capitalize(str)                                 Capitalize the first character                    str\n\
            match(search string,str₁, str₂, …)              Search for matched strings                        bool\n\
            hasspace(str)                                   Search for white-space characters                 bool\n\
\n\
  : Character string related functions\n\
\n\
  Section   Function name                                         Function                            Output format\n\
  --------- ----------------------------------------------------- ----------------------------------- ---------------\n\
            regexm(str,regular expression)                        Match whole string                  bool\n\
            regexs(str,regular expression)                        Match                               bool\n\
            regexrep(str,regular expression,replacement string)   Replace matching character string   str\n\
            regexlen(str,regular expression)                      Match number of characters          num\n\
            regexpos(str,regular expression)                      Start position of character         num\n\
            regexstr(str,regular expression)                      Match character string              str\n\
            regexpfx(str,regular expression)                      Match prefix of character string    str\n\
            regexsfx(str,regular expression)                      Match suffix of character string    str\n\
\n\
  : Regular expression related functions\n\
\n\
  Section   Function Name    Function                Output\n\
  --------- ---------------- ----------------------- -----------------\n\
            today()          Today’s date            date\n\
            now()            Current time            time\n\
            tseconds(time)   Seconds elapsed         num\n\
            leapyear(dt)     Decide leap year        bool\n\
            year(dt)         Gregorian calendar      num\n\
            month(dt)        Month                   num\n\
            day(dt)          Day                     num\n\
            week(dt)         Week number             num\n\
            dow(dt)          Day of week             num\n\
            time(time)       Hour minute second      str\n\
            date(time)       Year month day          str\n\
            hour(time)       Hour                    num\n\
            minute(time)     Minute                  num\n\
            second(time)     Second                  num\n\
            age(dt₁, dt₂)    Age                     num\n\
            diff(dt₁, dt₂)   Period                  num\n\
            uxt(dt)          Convert to UNIX time    num(UNIX time)\n\
            julian(dt)       Convert to Julian day   num(Julian day)\n\
\n\
  : Date and Time Related Functions\n\
\n\
dt represents either date or time.\n\
\n\
  Section   Function Name            Function                  Output\n\
  --------- ------------------------ ------------------------- --------\n\
            and(bool₁, bool₂, …)     Conjunction               bool\n\
            or(bool₁, bool₂, …)      Disjunction               bool\n\
            not(bool)                NOT                       bool\n\
            if(bool, num₁, num₂)     Check logical condition   num\n\
            if(bool, str₁, str₂)                               str\n\
            if(bool, date₁, date₂)                             date\n\
            if(bool, time₁, time₂)                             time\n\
\n\
  : Logical Functions\n\
\n\
  Section   Function Name            Function                            Output Format\n\
  --------- ------------------------ ----------------------------------- ---------------\n\
            line()                   Return the processing line number   num\n\
            top()                    Top row                             bool\n\
            bottom()                 Last row                            bool\n\
            fldsize()                Number of fields                    num\n\
            argsize(str₁, str₂, …)   Number of arguments                 num\n\
\n\
  : Row/column related functions\n\
\n\
  Section   Function Name                Function                Output Format\n\
  --------- ---------------------------- ----------------------- ---------------\n\
            nulln()                      NULL value              num\n\
            nulls()                                              str\n\
            nulld()                                              date\n\
            nullt()                                              time\n\
            nullb()                                              bool\n\
            isnull(num)                  NULL value check        bool\n\
            isnull(str)                                          bool\n\
            isnull(date)                                         bool\n\
            isnull(time)                                         bool\n\
            isnull(bool)                                         bool\n\
            countnull(num₁, num₂, …)     Number of NULL values   num\n\
            countnull(str₁, str₂, …)                             num\n\
            countnull(date₁, date₂, …)                           num\n\
            countnull(time₁, time₂, …)                           num\n\
            countnull(bool₁, bool₂, …)                           num\n\
\n\
  : NULL value related functions\n\
\n\
         num         str         date        time        bool\n\
  ------ ----------- ----------- ----------- ----------- ----------\n\
  num                n2s(num)                            n2b(num)\n\
  str    s2n(str)                s2d(str)    s2t(str)    s2b(str)\n\
  date               d2s(date)               d2t(date)   \n\
  time               t2s(time)   t2d(time)               \n\
  bool   b2n(bool)   b2s(bool)                           \n\
\n\
  : Type conversion related functions\n\
\n\
Each cell corresponds to the conversion function from the labels in the\n\
top row to labels in the left column.\n\
Empty cells means that conversion function is not available.\n\
";

