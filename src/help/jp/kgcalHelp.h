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
_titleL="項目間演算";
_docL="\
\n\
MCAL 項目間演算\n\
\n\
c=パラメータで指定した計算式で計算をおこない、a=パラメータで指定した項目名に出力する。\n\
mcalが出力する項目は、プログラムの単純化のため、例外なく1つに限定している。\n\
計算式の詳細は後述の「式の構成要素」を参照のこと。\n\
\n\
書式\n\
\n\
mcal a= c= [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  a=   新たに計算結果の出力として追加される項目の名前を指定する。\n\
  c=   用意された関数を組み合わせて計算する式を指定する。\n\
\n\
利用例\n\
\n\
以下にmcalを使った簡単な例を示す。\n\
個々の関数や演算子についての詳細は、それぞれ個別に解説を用意しているので、そちらを参照されたい。\n\
\n\
    # 入力ファイル(dat1.csv)\n\
    顧客,数量,単価\n\
    A,3,10\n\
    B,1,15\n\
    C,2,20\n\
\n\
    $ mcal c='${数量}*${単価}' a=金額 i=dat1.csv\n\
    顧客,数量,単価,金額\n\
    A,3,10,30\n\
    B,1,15,15\n\
    C,2,20,40\n\
\n\
    $ mcal c='${数量}*${単価}<=30' a=金額30以下 i=dat1.csv\n\
    顧客,数量,単価,金額30以下\n\
    A,3,10,1\n\
    B,1,15,1\n\
    C,2,20,0\n\
\n\
    $ mcal c='if(top(),${単価},#{}+${単価})' a=単価累計 i=dat1.csv\n\
    顧客,数量,単価,単価累計\n\
    A,3,10,10\n\
    B,1,15,25\n\
    C,2,20,45\n\
\n\
定数\n\
\n\
  データ型      書式                     内容                                            例\n\
  ------------- ------------------------ ----------------------------------------------- -------------------\n\
  数値(num)     整数、実数の文字列表記   内部的には全て倍精度実数を利用                  20, 0.55, 1.5*e10\n\
  文字列(str)   “文字列”                 ダブルクオーテーションで括った文字列            \"abc\" \"日本語\"\n\
  日付(date)    0dyyyymmdd               先頭に“0d”を付けた年月日固定長                  0d20080923\n\
  時刻(time)    0tyyyymmddHHMMSS         先頭に“0t”を付けた年月日時分秒固定長            0t20080923121115\n\
                0tHHMMSS                 先頭に“0t”を付けた時分秒固定長                  0t121115\n\
                                         (内部的に本日の日付が補完される)                \n\
  論理(bool)    0b1, 0b0                 先頭に“0b”を付けた“1”(true)もしくは“0”(false)   0b1, 0b0\n\
\n\
  : 定数の書式一覧\n\
\n\
項目値\n\
\n\
CSVデータ上の項目名を指定するには表に示される通り、\n\
CSVデータをどのデータ型として扱うかによって異なってくる。\n\
CSVデータは全て文字列データであるために、それらをどのような型のデータとして扱うかはユーザの判断に任されている。\n\
\n\
  データ型      書式         CSVデータ内容                                       例\n\
  ------------- ------------ --------------------------------------------------- -------------------------\n\
  数値(num)     ${項目名}    整数、実数(指数表現含む) の文字列表記               ${amount}, ${株価}\n\
  文字列(str)   $s{項目名}   文字列                                              $s{gender}, $s{性別}\n\
  日付(date)    $d{項目名}   年月日固定長(yyyymmdd)                              $d{date}, $d{発注日}\n\
  時刻(time)    $t{項目名}   年月日時分秒の固定長(yyyymmddHHMMSS)                $d{time}, $d{出発時刻}\n\
                             時分秒(HHMMSS)の固定長                              \n\
                             (内部的に本日の日付が補完される)                    \n\
  論理(bool)    $b{項目名}   項目値の一文字目が“1”の時にtrue、“0”の時にfalse、   $b{condition}, $b{条件}\n\
                             その他の場合にはNULLと解釈される。                  \n\
\n\
  : 項目値の書式一覧\n\
\n\
前行の項目値\n\
\n\
項目値の指定に$の代わりに#を指定すると、前行の項目値となる。\n\
ただし、先頭行は前行がないのでNULLとなる。\n\
各データ型における指定方法をに示す。\n\
\n\
  データ型      書式         例\n\
  ------------- ------------ -------------------------\n\
  数値(num)     #{項目名}    #{amount}, #{株価}\n\
  文字列(str)   #s{項目名}   #s{gender}, #s{性別}\n\
  日付(date)    #d{項目名}   #d{date}, #d{発注日}\n\
  時刻(time)    #t{項目名}   #d{time}, #d{出発時刻}\n\
  論理(bool)    #b{項目名}   #b{condition}, #b{条件}\n\
\n\
  : 前行の項目値の書式一覧\n\
\n\
前行の結果項目値\n\
\n\
前行項目の指定において項目名を省略すると前行の計算結果項目の値となる。\n\
各データ型における指定方法をに示す。\n\
\n\
if関数とtop()関数とを組み合わせる事で、累計計算などが可能となる。\n\
以下に、金額項目の累計計算例を示す。\n\
\n\
$ mcal c='if(top(),${金額},${金額}+#{})' a=累計金額\n\
\n\
  データ型      書式   例\n\
  ------------- ------ ------\n\
  数値(num)     #{}    #{}\n\
  文字列(str)   #s{}   #s{}\n\
  日付(date)    #d{}   #d{}\n\
  時刻(time)    #t{}   #d{}\n\
  論理(bool)    #b{}   #b{}\n\
\n\
  : 前行の結果項目値の書式一覧\n\
\n\
算術演算子\n\
\n\
+や-などの算術演算子は数値型だけでなく、文字列型や日付型のデータに対しても定義されている。\n\
それらの一覧を表に示す。\n\
\n\
  演算子    書式            内容                 例\n\
  --------- --------------- -------------------- ---------------------------\n\
  加算(+)   num₁ + num₂     数値の足し算         1.5+2.3 (3.8)\n\
            str₁ + str₂     文字列の結合         \"150\"+\"円\" (\"150円\")\n\
            date + num      num日後の日付        0d20121130+2 (0d20121202)\n\
            time + num      num秒後の時刻        0t095959+2 (0t100001)\n\
  減算(-)   num₁ − num₂     数値の引き算         1.5-2.3 (-1.8)\n\
            str₁ − str₂     部分文字列の削除     \"aababa\"-\"a\" (\"bb\")\n\
                            (貪欲マッチによる)   \"aababa\"-\"aba\" (\"aba\")\n\
            date − num      num日前の日付        0d20121202-2 (0d20121130)\n\
            time − num      num秒前の時刻        0t100001-2 (0t095959)\n\
            date₁ − date₂   日付差               0d20121202-0d20121130 (2)\n\
            time₁ − time₂   時刻差               0t095959-0t100001 (-2)\n\
  乗算(*)   num₁ * num₂     掛け算               10*2 (20)\n\
  除算(/)   num₁/num₂       割り算               10/2 (5)\n\
  剰余(%)   num₁%num₂       剰余                 10%3 (1)\n\
  累乗(^)   num₁^num₂       累乗                 10^3 (1000)\n\
\n\
  : 算術演算子一覧\n\
\n\
例の括弧内は結果を表す(内容は定数の表記で示している)。\n\
\n\
比較演算子\n\
\n\
比較演算は同一のデータ型の値同士でのみ適用可能である。\n\
全てのデータ型に共通した書式であり、以下では数値型についてのみ(例では文字型につても)表に示す。\n\
文字型、日付型、時刻型においても同様に利用できる。\n\
\n\
  比較内容     書式           例\n\
  ------------ -------------- ------------------------------------\n\
  等しい       num₁ = =num₂   1.5==1.5(0b1), \"abc\"==\"abcd\" (0b0)\n\
  等しくない   num₁!=num₂     1.5!=1.5(0b0), \"abc\"==\"abcd\" (0b1)\n\
  より大きい   num₁ > num₂    10>5(0b1), \"abc\">\"abcd\" (0b0)\n\
  より小さい   num₁ < num₂    10<5(0b0), \"abc\"<\"abcd\" (0b1)\n\
  以上         num₁ > =num₂   10>=10(0b1), \"a\">\"\" (0b1) \n\
  以下         num₁ < =num₂   8<=9(0b1), \"a\"<=\"a\" (0b1)\n\
\n\
  : 比較演算子一覧\n\
\n\
例の括弧内は結果を表す(内容は定数の表記で示している)。\n\
\n\
論理演算子\n\
\n\
3つの論理演算子(論理積、論理和、排他的論理和)が利用でき、それぞれの書式を表に示す。\n\
また、それぞれの演算における真偽(1:真,0:偽)の組み合せとその結果を表,表,表に示す。\n\
\n\
  内容           書式             例\n\
  -------------- ---------------- ------------------------------------\n\
  論理積         bool₁&&bool₂     \"abc\"==\"abc\" && \"xyz\"==\"abc\" (0b0)\n\
  論理和         bool₁||bool₂     \"abc\"==\"abc\" || \"xyz\"==\"abc\" (0b1)\n\
  排他的論理和   bool₁ ^^ bool₂   \"abc\"==\"abc\" ^^ \"xyz\"==\"abc\" (0b1)\n\
\n\
  : 論理演算子一覧\n\
\n\
例の括弧内は結果を表す(内容は定数の表記で示している)。\n\
\n\
   bool₁   bool₂   結果\n\
  ------- ------- ------\n\
     1       1      1\n\
     1       0      0\n\
     0       1      0\n\
     0       0      0\n\
   null      1     null\n\
   null      0      0\n\
   null    null    null\n\
\n\
  : 排他的論理和\n\
\n\
   bool₁   bool₂   結果\n\
  ------- ------- ------\n\
     1       1      1\n\
     1       0      1\n\
     0       1      1\n\
     0       0      0\n\
   null      1      1\n\
   null      0     null\n\
   null    null    null\n\
\n\
  : 排他的論理和\n\
\n\
   bool₁   bool₂   結果\n\
  ------- ------- ------\n\
     1       1      0\n\
     1       0      1\n\
     0       1      1\n\
     0       0      0\n\
   null      1     null\n\
   null      0     null\n\
   null    null    null\n\
\n\
  : 排他的論理和\n\
\n\
関数\n\
\n\
以下では、数値関連()、三角関数関連()、 文字列関連()、正規表現関連()、\n\
日付時間関連()、論理関数()、 行/項目情報関連()、NULL値関連()、\n\
そして型変換関連()の9つに分けて解説する。\n\
\n\
       関数名                              機能           出力型\n\
  ---- ----------------------------------- -------------- --------\n\
       sum(num₁, num₂, …)                  合計           num\n\
       avg(num₁, num₂, …)                  平均           num\n\
       sqsum(num₁, num₂, …)                平方和         num\n\
       min(num₁, num₂, …)                  最小値         num\n\
       max(num₁, num₂, …)                  最大値         num\n\
       product(num₁, num₂, …)              積             num\n\
       factorial(num)                      階乗           num\n\
       gcd(num₁,num₂)                      最大公約数     num\n\
       lcm(num₁,num₂)                      最小公倍数     num\n\
       sqrt(num)                           平方根         num\n\
       abs(num)                            絶対値         num\n\
       sign(num)                           符号           num\n\
       int(num)                            整数部         num\n\
       fract(num)                          小数部         num\n\
       round(num,基準値)                   四捨五入       num\n\
       floor(num，基準値)                  切り捨て       num\n\
       ceil(num，基準値)                   切り上げ       num\n\
       power(num，指数)                    累乗           num\n\
       exp(num)                            指数関数       num\n\
       log(num，底)                        対数           num\n\
       ln(num)                             自然対数       num\n\
       log2(num)                           底が2の対数    num\n\
       log10(num)                          常用対数       num\n\
       dist(タイプ,num₁, num₂, …)          距離           num\n\
       distgps(緯度1,経度1,緯度2,経度2)    GPS距離        num\n\
       heron(num₁, num₂, …)                三角形の面積   num\n\
       rand([乱数の種])                    一様乱数       num\n\
       randi(最小値, 最大値[, 乱数の種])   整数一様乱数   num\n\
       nrand(平均, 標準偏差[, 乱数の種])   正規乱数       num\n\
       pi()                                円周率         num\n\
       e()                                 ネイピア数     num\n\
       format()                            書式付き出力   str\n\
\n\
  : 数値関連関数一覧\n\
\n\
       関数名             機能                                 出力範囲\n\
  ---- ------------------ ------------------------------------ ----------\n\
       acos(num)          コサインの逆関数                     0 π\n\
       asin(num)          サインの逆関数                       −π π\n\
       atan(num)          タンジェントの逆関数                 −π π\n\
       atan2(num₁,num₂)   座標(num₁, num₂)の角度               −π π\n\
       cos(r)             コサイン                             −1.0 1.0\n\
       sin(r)             サイン                               −1.0 1.0\n\
       tan(r)             タンジェント                         −∞ ∞\n\
       degree(r)          角度                                 −π π\n\
       radian(角度)       度数を入力したときのラジアンを出力   −π π\n\
       cosh(r)            双曲線余弦                           0 ∞\n\
       sinh(r)            双曲線正弦                           −∞ ∞\n\
       tanh(r)            双曲線逆正接                         −1.0 1.0\n\
\n\
  : 三角関数関連関数一覧\n\
\n\
rはラジアンを表した数値。\n\
\n\
       関数名                                 機能                 出力型\n\
  ---- -------------------------------------- -------------------- --------\n\
       cat(token, str₁, str₂, …)              文字列併合           str\n\
       length(str)                            文字列長             num\n\
       fixlen(str, 長さ, 位置, padding文字)   固定長変換           str\n\
       right(str,長さ)                        末尾切り出し         str\n\
       left(str,長さ)                         先頭切り出し         str\n\
       mid(str, 開始位置, 長さ)               部分文字列切り出し   str\n\
       toupper(str)                           小文字大文字変更     str\n\
       tolower(str)                           大文字小文字変更     str\n\
       capitalize(str)                        先頭文字大文字変換   str\n\
       match(検索文字列,str₁, str₂, …)        検索                 bool\n\
       hasspace(str)                          空白類文字検索       bool\n\
\n\
  : 文字列関連関数一覧\n\
\n\
       関数名                              機能                           出力型\n\
  ---- ----------------------------------- ------------------------------ --------\n\
       regexm(str,正規表現)                全体マッチ                     bool\n\
       regexs(str,正規表現)                マッチ                         bool\n\
       regexrep(str,正規表現,置換文字列)   マッチ文字列の置換             str\n\
       regexlen(str,正規表現)              マッチ文字数                   num\n\
       regexpos(str,正規表現)              開始位置                       num\n\
       regexstr(str,正規表現)              マッチ文字列                   str\n\
       regexpfx(str,正規表現)              マッチ文字列のプレフィックス   str\n\
       regexsfx(str,正規表現)              マッチ文字列のサフィックス     str\n\
\n\
  : 正規表現関連関数一覧\n\
\n\
       関数名           機能               出力型\n\
  ---- ---------------- ------------------ -------------------\n\
       today()          本日の日付         date\n\
       now()            現在時刻           time\n\
       tseconds(time)   経過秒数           num\n\
       leapyear(dt)     閏年判定           bool\n\
       year(dt)         西暦年             num\n\
       month(dt)        月                 num\n\
       day(dt)          日                 num\n\
       week(dt)         週番号             num\n\
       dow(dt)          曜日               num\n\
       time(time)       時分秒             str\n\
       date(time)       年月日             str\n\
       hour(time)       時                 num\n\
       minute(time)     分                 num\n\
       second(time)     秒                 num\n\
       age(dt₁, dt₂)    年令               num\n\
       diff(dt₁, dt₂)   期間               num\n\
       uxt(dt)          UNIX時変換         num(UNIX時刻)\n\
       julian(dt)       ユリウス通日変換   num(ユリウス通日)\n\
\n\
  : 日付時間関連関数一覧\n\
\n\
dtは、date,timeの何れかを表す。\n\
\n\
       関数名                   機能       出力型\n\
  ---- ------------------------ ---------- --------\n\
       and(bool₁, bool₂, …)     論理積     bool\n\
       or(bool₁, bool₂, …)      論理和     bool\n\
       not(bool)                否定       bool\n\
       if(bool, num₁, num₂)     条件選択   num\n\
       if(bool, str₁, str₂)                str\n\
       if(bool, date₁, date₂)              date\n\
       if(bool, time₁, time₂)              time\n\
\n\
  : 論理関連関数一覧\n\
\n\
       関数名                   機能                       出力型\n\
  ---- ------------------------ -------------------------- --------\n\
       line()                   現在処理中の行番号を返す   num\n\
       top()                    先頭行                     bool\n\
       bottom()                 終端行                     bool\n\
       fldsize()                項目数                     num\n\
       argsize(str₁, str₂, …)   引数の数                   num\n\
\n\
  : 行/項目情報関連関数一覧\n\
\n\
       関数名                       機能         出力型\n\
  ---- ---------------------------- ------------ --------\n\
       nulln()                      NULL値       num\n\
       nulls()                                   str\n\
       nulld()                                   date\n\
       nullt()                                   time\n\
       nullb()                                   bool\n\
       isnull(num)                  NULL値判定   bool\n\
       isnull(str)                               bool\n\
       isnull(date)                              bool\n\
       isnull(time)                              bool\n\
       isnull(bool)                              bool\n\
       countnull(num₁, num₂, …)     NULL値の数   num\n\
       countnull(str₁, str₂, …)                  num\n\
       countnull(date₁, date₂, …)                num\n\
       countnull(time₁, time₂, …)                num\n\
       countnull(bool₁, bool₂, …)                num\n\
\n\
  : NULL値関連関数一覧\n\
\n\
         num         str         date        time        bool\n\
  ------ ----------- ----------- ----------- ----------- ----------\n\
  num                n2s(num)                            n2b(num)\n\
  str    s2n(str)                s2d(str)    s2t(str)    s2b(str)\n\
  date               d2s(date)               d2t(date)   \n\
  time               t2s(time)   t2d(time)               \n\
  bool   b2n(bool)   b2s(bool)                           \n\
\n\
  : 型変換関連関数一覧\n\
\n\
各セルの関数は、「行ラベル→列ラベル」の変換関数を示している。\n\
空白セルは、そのような変換関数が定義されていないことを意味する。\n\
";

