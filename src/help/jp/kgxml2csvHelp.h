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
_titleL="XMLからCSVへの変換";
_docL="\
\n\
MXML2CSV XMLからCSVへの変換\n\
\n\
xml形式のデータをcsv形式のデータに変換する。\n\
基本的な変換規則は、一行の単位となる要素(XMLタグ)と、\n\
項目に対応させる要素(もしくは属性)を、それぞれk=、f=によって指定する。\n\
項目の値としては、 要素で囲われたテキスト、要素が出現するかどうか、\n\
属性の値、属性が出現するかどうか、の4通りの方法を指定できる。\n\
\n\
XMLのパーサーとしてはSAXを用いているので、XMLのサイズ制約はない。\n\
XMLのエンコーディングがUTF-8以外であれば、UTF-8に変換されてCSVに出力される。\n\
XMLデータは、整形式XML文書(well-formed XML\n\
document)であることを前提としている。\n\
そうでない場合の処理結果は不定である。\n\
\n\
典型例を、表に示されたXMLデータを用いて示す。\n\
より詳細な解説は、次節で行うとして、ここでは概略について解説する。\n\
表は、 行の単位を要素<b>とし(このような要素のことを「キー要素」と呼ぶ)、\n\
項目として、要素bの属性attの値(CSV項目名b_att)、\n\
要素cの属性pの値(b_p)とフラグ(b_p_f)、\n\
そして要素dとa内のテキスト(dとa)を出力した結果である。\n\
ここで、フラグとは、指定した要素もしくは属性が、出現するかどうかを0-1で出力したものである。\n\
要素のテキスト出力は、指定した要素で囲われた範囲に出現する文字列を全て連結した文字列である。\n\
ただし、スペースと制御文字は出力されないことに注意する。\n\
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
  : キー:/a/b、項目:b@att,c@p,d,/a\n\
\n\
キー要素の指定方法\n\
\n\
一行の単位となるキー要素(k=パラメータで指定)は絶対パスで指定する。\n\
絶対パスは、ルート記号('/')から始めて、要素の階層を'/'記号で区切って表される。\n\
本コマンドにおけるキー要素の役割は、キー要素の終了タグが出現した時に、以下の２点を実行することにある。\n\
\n\
-   項目データを一行出力する。上記の例では、キー要素の終了タグ</b>が3回出現しており、\n\
    その度にCSVデータ一行が出力され改行される。\n\
\n\
-   項目データを初期化する。ただし、キー要素の外側にある項目要素の出力データは初期化しない。\n\
    表の要素aの出力において、テキストが連結されていくのは、\n\
    キー要素の終了タグが出現した時であっても、要素/aがキー要素/a/bより外側にあり、\n\
    出力データが初期化されないためである。\n\
\n\
要素の出力項目指定\n\
\n\
f=で要素をCSV項目として出力する場合、以下に示すフォーマットに従う。\n\
\n\
要素パス[%フラグ]:CSV項目名\n\
\n\
「項目名」は、出力されるCSVの項目名であり、必ず指定しなければならない。\n\
\n\
要素を項目として出力する方法は２通りある。\n\
一つは、指定の要素の開始タグと終了タグで囲われたテキストを出力する方法で、\n\
他方は、指定した要素が存在するかどうかを0-1値で出力する方法である。\n\
前者は、対象となる要素パスを指定し、 後者は、加えてフラグ%fを付与する。\n\
また要素パスの指定方法は、絶対パスと相対パスの２通りある。\n\
相対パスは、k=で指定された要素からのパスを指定する。\n\
以下、表のXMLについて、いくつかの要素パスの指定例を示す。\n\
\n\
-   k=/a/bにおいて、f=:Bと指定すると、相対パスは空でキー要素と同じ要素となる。CSVの項目名はBである。\n\
\n\
-   k=/a/bにおいて、f=c:Cとf=/a/b/c:Cは同じ意味である。\n\
    前者は相対パスによる指定、後者は絶対パスによる指定である。両者ともCSV項目名はCである。\n\
\n\
-   f=d:Dは要素dで囲われたテキストを出力し、\n\
    f=d%f:Dは要素dが存在するかどうかを出力する。CSV項目名はDである。\n\
\n\
-   k=/a/bにおいてf=/a:Aとした場合、\n\
    項目要素はキー要素の外側にあるため、a要素内に含まれるテキストが次々と結合される。\n\
    なぜならば、キー要素の終了タグが出現しても、項目要素の終了タグが出現しないために、その時点でデータがクリアされることがないためである。\n\
\n\
属性の出力項目指定\n\
\n\
f=で属性をCSV項目として出力する場合、以下に示すフォーマットに従う。\n\
\n\
要素パス@要素名[%フラグ]:CSV項目名\n\
\n\
「項目名」は、出力されるCSVの項目名であり、必ず指定しなければならない。\n\
\n\
要素パスの指定は、要素の出力項目指定と同様である。\n\
そして、属性名は、要素パスに続けて@で連結して指定する。\n\
要素名の後に%fを付けることで、その要素が存在するかどうかを0-1値で出力する。\n\
\n\
書式\n\
\n\
mxml2csv k= f= [i=] [o=] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help]\n\
[--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   一行の単位となる要素をルートからのパス名として指定する。\n\
       パスはルート記号’/’から始まり、要素を’/’でつなげることで指定する。\n\
       例: /article/sentence/chunk\n\
  f=   項目として出力する要素もしくは属性をカンマで区切って指定する。\n\
       フォーマットは以下のとおり。\n\
       要素パス[%フラグ]:CSV項目名\n\
       要素パス@要素名[%フラグ]:CSV項目名\n\
  i=   xmlデータファイル名を指定する。省略時は標準入力から読み込まれる。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
概要にて解説した例。 /a/bをキー要素として、5つのCSV項目を出力する。\n\
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
    $ mxml2csv k=/a/b f=@att:b_att,c@p:c_p,c@p%f:c_p_f,d:d,/a:a i=dat1.xml  o=rsl1.csv\n\
    #END# kgxml2csv f=@att:b_att,c@p:c_p,c@p%f:c_p_f,d:d,/a:a i=dat1.xml k=/a/b o=rsl1.csv\n\
    $ more rsl1.csv\n\
    b_att,c_p,c_p_f,d,a\n\
    bb1,pp1,1,text1,text1\n\
    bb2,,,text2,text1text2\n\
    ,pp3,1,text3,text1text2text3\n\
\n\
例2: 絶対パス\n\
\n\
基本例と同じ要素を絶対パスで指定する例。\n\
/a/bをキー要素として、5つのCSV項目を出力する。\n\
\n\
    $ mxml2csv k=/a/b f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml  o=rsl2.csv\n\
    #END# kgxml2csv f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml k=/a/b o=rsl2.csv\n\
    $ more rsl2.csv\n\
    b_att,c_p,c_p_f,d,a\n\
    bb1,pp1,1,text1,text1\n\
    bb2,,,text2,text1text2\n\
    ,pp3,1,text3,text1text2text3\n\
\n\
例3: キー要素の変更\n\
\n\
絶対パスの例でキー要素をaに変更した例。\n\
aの終了タグは一つしかないので、一行だけ出力されている。\n\
f=で指定した/a/b@attは、2回出現しているが、最後に出現した値が出力されている。\n\
\n\
    $ mxml2csv k=/a f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml o=rsl3.csv\n\
    #END# kgxml2csv f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a i=dat1.xml k=/a o=rsl3.csv\n\
    $ more rsl3.csv\n\
    b_att,c_p,c_p_f,d,a\n\
    bb2,pp3,1,text3,text1text2text3\n\
";

