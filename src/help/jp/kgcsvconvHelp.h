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
/// kgcsvconvHelp.h : kgcsvconv help
// =============================================================================
_titleL="CSVを多様なフォーマットに変換";
_docL="\
\n\
MCSVCONV CSVを多様なフォーマットに変換\n\
\n\
CSVデータを多様なフォーマットに変換する。\n\
変換したいデータフォーマットのルールを記述したテキストファイルを用意し、\n\
ルールキーワードに従って指定したCSVのデータ項目を出力する。\n\
ルールファイルに記述できる項目名指定や出力タイミング指定は以下のとおりである。\n\
\n\
項目名キーワード\n\
\n\
    項目名を%で括ると、CSV上の対応する項目の値に置き換えられる。ex.\n\
    %項目名%\n\
\n\
出力タイミングキーワード\n\
\n\
    CSVデータの出力タイミングを決めるためのキーワードは以下の3種類ある。\n\
\n\
LINEDATA\n\
\n\
    %LINEDATA〜%LINEENDで囲われた項目名キーワード及びその他の文字列は、CSVの各行が読み込まれる度に出力される。\n\
\n\
KEYHEAD\n\
\n\
    %KEYHEAD〜%KEYENDで囲われた項目名キーワード及びその他の文字列は、k=で指定されたキー項目がキーブレイクした時にのみ出力される。LINEDATAより前に出力される。\n\
\n\
KEYFOOT\n\
\n\
    %KEYFOOT〜%KEYENDで囲われた項目名キーワード及びその他の文字列は、k=で指定されたキー項目がキーブレイクした時にのみ出力される。LINEDATAより後に出力される。\n\
\n\
キーワド前後\n\
\n\
    上述の出力タイミングキーワードで囲われたブロックが出現する前の文字列、および最後のブロック以降の文字列は、CSVの読み込み前、および読み込み後に一度だけ出力される。\n\
\n\
k=で複数の項目を指定した場合、KEYHADとKEYFOOTは更に細かなタイミング制御も可能である。\n\
%KEYHEAD1のように、番号を後ろに付けることで、k=の何番目の項目がキーブレイクしたかを指定できる。\n\
例えば、k=A,B,Cにおいて%KEYHEAD1であれば、\n\
キー項目Aがキーブレイクしたタイミングで出力され、\n\
また%KEYHEAD2であれば、キー項目A,Bがキーブレイクしたタイミングで出力される。\n\
そして%KEYHEAD3もしくは単に%KEYHEADであれば、全てのキー項目A,B,Cがキーブレイクしたタイミングで出力される。\n\
\n\
出力タイミング制御キーワードを記載した行は、それ以外の文字を記述することはできない。\n\
\n\
書式\n\
\n\
mcsvconv [k=] [s=] m=  i= [o=] [-assert_nullin] [-nfn] [-nfno] [-x] [-q]\n\
[tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   キー項目名リスト。\n\
  s=   k=で指定した項目の値が同じ行の中での並べ替え順を決める項目名リスト。\n\
  m=   ルールファイル名\n\
\n\
利用例\n\
\n\
例1: 基本例1\n\
\n\
CSVの2項目key1,v1をスペース区切りで出力する。\n\
\n\
    $ more dat1.csv\n\
    key1,key2,v1,v2\n\
    A,X,1,a\n\
    A,Y,2,b\n\
    A,Y,3,c\n\
    B,X,4,d\n\
    B,Y,5,e\n\
    $ more form1.txt\n\
    $ mcsvconv m=form1.txt i=dat1.csv o=rsl1.txt\n\
    #END# kgcsvconv i=dat1.csv m=form1.txt o=rsl1.txt\n\
    $ more rsl1.txt\n\
    A 1\n\
    A 2\n\
    A 3\n\
    B 4\n\
    B 5\n\
\n\
例2: 基本例2\n\
\n\
2行にズラして出力する。\n\
\n\
    $ more dat1.csv\n\
    key1,key2,v1,v2\n\
    A,X,1,a\n\
    A,Y,2,b\n\
    A,Y,3,c\n\
    B,X,4,d\n\
    B,Y,5,e\n\
    $ more form2.txt\n\
           %key2% %v2%\n\
    $ mcsvconv m=form2.txt i=dat1.csv o=rsl2.txt\n\
    #END# kgcsvconv i=dat1.csv m=form2.txt o=rsl2.txt\n\
    $ more rsl2.txt\n\
    A 1\n\
           X a\n\
    A 2\n\
           Y b\n\
    A 3\n\
           Y c\n\
    B 4\n\
           X d\n\
    B 5\n\
           Y e\n\
\n\
例3: keyを指定した例\n\
\n\
    $ more dat1.csv\n\
    key1,key2,v1,v2\n\
    A,X,1,a\n\
    A,Y,2,b\n\
    A,Y,3,c\n\
    B,X,4,d\n\
    B,Y,5,e\n\
    $ more form3.txt\n\
    Head Area\n\
    KeyHead=%key1% %key2% %v1% %v2%\n\
    KeyFoot=%key1% %key2% %v1% %v2%\n\
    Foot Area\n\
    $ mcsvconv k=key1 m=form3.txt i=dat1.csv o=rsl3.txt\n\
    #END# kgcsvconv i=dat1.csv k=key1 m=form3.txt o=rsl3.txt\n\
    $ more rsl3.txt\n\
    Head Area\n\
    KeyHead=A X 1 a\n\
    1-a\n\
    2-b\n\
    3-c\n\
    KeyFoot=A Y 3 c\n\
    KeyHead=B X 4 d\n\
    4-d\n\
    5-e\n\
    KeyFoot=B Y 5 e\n\
    Foot Area\n\
\n\
例4: texデータとして出力する例\n\
\n\
    $ more dat1.csv\n\
    key1,key2,v1,v2\n\
    A,X,1,a\n\
    A,Y,2,b\n\
    A,Y,3,c\n\
    B,X,4,d\n\
    B,Y,5,e\n\
    $ more form3.txt\n\
    Head Area\n\
    KeyHead=%key1% %key2% %v1% %v2%\n\
    KeyFoot=%key1% %key2% %v1% %v2%\n\
    Foot Area\n\
    $ mcsvconv k=key1 m=form4.txt i=dat1.csv o=rsl4.tex\n\
    #END# kgcsvconv i=dat1.csv k=key1 m=form4.txt o=rsl4.tex\n\
    $ more rsl4.tex\n\
    \\documentclass{article}\n\
    \\begin{document}\n\
    \\begin{table}\n\
    \\begin{tabular}{l|l|r|r}\n\
    \\hline\n\
    key1 & key2 & v1 & v2 \\\\\n\
    \\hline\n\
    A & X & 1 & a \\\\\n\
      & X & 1 & a \\\\\n\
      & Y & 2 & b \\\\\n\
      & Y & 3 & c \\\\\n\
    \\hline\n\
    B & X & 4 & d \\\\\n\
      & X & 4 & d \\\\\n\
      & Y & 5 & e \\\\\n\
    \\hline\n\
    \\end{tabular}\n\
    \\end{table}\n\
    \\end{document}\n\
";

