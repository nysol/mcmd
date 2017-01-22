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
_titleL="正規表現による文字列置換";
_docL="\
\n\
MSED 正規表現による文字列置換\n\
\n\
f=パラメータで指定した項目について、\n\
c=パラメータで指定した正規表現に一致する内容を\n\
v=パラメータ指定した文字列で置換する。\n\
\n\
書式\n\
\n\
msed c= f= v= [-A] [-g] [-W]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   置換対象となる項目名リスト(複数項目指定可)を指定する。\n\
  c=   置換したい文字列についての正規表現を指定する。\n\
       正規表現の使用方法参照\n\
  v=   c=パラメータで指定した正規表現にマッチした部分文字列が、\n\
       ここで指定した文字列に置換される。\n\
       マッチ結果を用いた置換も可能で、指定方法は以下の通り。\n\
       $& : マッチした文字列\n\
       $` : 置換対象文字列の先頭から、マッチした文字列の直前までの文字列\n\
       $' : マッチした文字列の直後から、置換対象文字列の最後までの文字列\n\
       $N : N番目の部分マッチ文字列(N>=1)\n\
  -A   このオプションにより、指定した項目を置き換えるのではなく、\n\
       新たに項目が追加される。\n\
  -g   正規表現にマッチする全ての部分文字列を置換対象とする。\n\
  -W   ワイド文字として正規表現による文字列置換を行う。\n\
\n\
正規表現の使用方法\n\
\n\
c=パラメータで指定する正規表現を表から表に示す。\n\
\n\
  正規表現   意味                           値例       c=,v=例           結果例\n\
  ---------- ------------------------------ ---------- ----------------- ----------\n\
  .          任意の一文字                   abbbcc     c=. v=X -g        XXXXXX\n\
  [abc]      a,b,cのいずれか一文字          abbbcc     c=[ac] v=X -g     XbbbXX\n\
  [^abc]     a,b,c以外の任意の一文字        abbbcc     c=[^ac] v=X -g    aXXXcc\n\
  [a-z]      aからzの範囲の任意の一文字     abbbcc     c=[a-b] v=X -g    XXXXcc\n\
  [^a-z]     aからzの範囲外の任意の一文字   abbbcc     c=[^a-b] v=X -g   abbbXX\n\
  \\t         タブ文字                                                    \n\
  \\w         単語構成文字([0-9a-zA-Z_])     ab#cd&ef   c=\\w v=X -g       XX#XX&XX\n\
  \\W         単語構成文字以外               ab#cd&ef   c=\\w v=X -g       abXcdXef\n\
  \\s         空白文字([ \\t])                ab cd ef   c=\\s v=X -g       abXcdXef\n\
  \\S         空白文字以外                   ab cd ef   c=\\s v=X -g       XX XX XX\n\
  \\d         数字構成文字文字([0-9])        ab12c0     c=\\d v=X -g       abXXcX\n\
  \\D         数字構成文字文字以外           ab12c0     c=\\d v=X -g       XX12X0\n\
\n\
  : 正規表現1文字マッチ\n\
\n\
  正規表現   意味                                   値例       c=,v=例            結果例\n\
  ---------- -------------------------------------- ---------- ------------------ --------\n\
  a*         aの0個以上の繰り返し                   abbbcc     c=ab* v=X          Xcc\n\
  a+         aの1個以上の繰り返し                   abbbcc     c=ab+ v=X          Xcc\n\
  a?         aの0個または1個の出現                  abbbcc     c=ab? v=X          Xbbcc\n\
  a{M,N}     aのM個以上N個以下の繰り返し            abbbbbcc   c=ab{3,4} v=X      Xbcc\n\
  a{M}       aのM個以上の繰り返し                   abbbbbcc   c=ab{3} v=X        Xbbcc\n\
  a｜b       aまたはb                               abbbc      c=(ab)｜(bc) v=X   XbX\n\
  ?          繰り返し記号の後ろに付けて最短マッチ   abbbc      c=ab*? v=X         Xbbbc\n\
\n\
  : 正規表現繰り返し\n\
\n\
  正規表現   意味                         値例            c=,v=例        結果例\n\
  ---------- ---------------------------- --------------- -------------- ---------------\n\
  ^          行頭にマッチする             abac            c=^a v=X -g    Xbac\n\
  $          行末にマッチする             acac            c=c$ v=X -g    acaX\n\
  \\b         単語頭または単語末にマッチ   aac ba ac bac   c=\\ba v=X -g   Xac bX Xc bac\n\
  \\B         単語中にマッチ               aac ba ac bac   c=\\Ba v=X -g   aXc ba ac bXc\n\
\n\
  : 正規表現位置指定\n\
\n\
  正規表現   意味                                 値例        c=,v=例            結果例\n\
  ---------- ------------------------------------ ----------- ------------------ --------\n\
  (expr)     グループ化                                                          \n\
  \\1,..,\\9   後方参照                             abbcababc   c=(ab)(bc)\\1 v=x   Xabc\n\
  (?=expr)   exprにマッチする直前位置にマッチ                                    \n\
  (?!expr)   exprにマッチしない直前位置にマッチ                                  \n\
\n\
  : その他\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
zipCode項目の値が00から始まる4桁文字列を####に置換する。\n\
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
例2: 項目名指定\n\
\n\
zipCodeの値が00から始まる4桁の数字を####に置換し、zipCode4という項目名で出力する。\n\
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
例3: グローバル置換\n\
\n\
zipCodeの値が0を全て-にグローバル置換する。\n\
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
例4: 部分置換\n\
\n\
itemの先頭のfruitを削除する。\n\
先頭一致(^)を指定しているので、最後の行のgrapefruitは削除されていないことに注意する。\n\
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
例5: マッチ結果を用いた置換\n\
\n\
v=の中で$&を用いれば、マッチした文字列(連続したb)に置き換わる。\n\
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
例6: グローバルマッチとの組み合せ\n\
\n\
グローバルマッチにすると、個々のマッチ毎にv=の内容が評価される。\n\
\n\
    $ msed f=str1 c=b v='#$&#' -g i=dat3.csv o=rsl6.csv\n\
    #END# kgsed -g c=b f=str1 i=dat3.csv o=rsl6.csv v=#$&#\n\
    $ more rsl6.csv\n\
    str1\n\
    a#b#c\n\
    a#b##b#c\n\
    ac\n\
\n\
例7: プレフィックス置換\n\
\n\
$`にて、マッチした箇所の前の文字列(プレフィックス)に置換される。\n\
\n\
    $ msed f=str1 c=b v='#$`#' i=dat3.csv o=rsl7.csv\n\
    #END# kgsed c=b f=str1 i=dat3.csv o=rsl7.csv v=#$`#\n\
    $ more rsl7.csv\n\
    str1\n\
    a#a#c\n\
    a#a#bc\n\
    ac\n\
\n\
例8: サフィックス置換\n\
\n\
$'にて、マッチした箇所の後の文字列(サフィックス)に置換される。\n\
\n\
    $ msed f=str1 c=b v=\"#$'#\" i=dat3.csv o=rsl8.csv\n\
    #END# kgsed c=b f=str1 i=dat3.csv o=rsl8.csv v=#$'#\n\
    $ more rsl8.csv\n\
    str1\n\
    a#c#c\n\
    a#bc#bc\n\
    ac\n\
";

