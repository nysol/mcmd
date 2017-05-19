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
/// kgselnumHelp.h : kgselnum help
// =============================================================================
_titleL="数値範囲による行選択";
_docL="\
\n\
MSELNUM 数値範囲による行選択\n\
\n\
f=で指定した項目の値が、 c=で指定した数値範囲にマッチする行を選択する。\n\
以下に示すように多様な選択条件を指定することが可能である。\n\
このコマンドで指定できないより複雑な条件(文字列マッチとの組み合せなど)\n\
を設定するのであればmselコマンドを利用すればよい。\n\
OR条件、AND条件およびキー指定についての詳細はmselstrコマンドを参照されたい。\n\
\n\
-   開区間、閉区間、半開区間、無限区間の制定が可能である。\n\
\n\
-   c=に複数の範囲を指定すれば、いずれかの範囲にマッチすれば選択される(OR条件)。\n\
\n\
-   f=に複数項目を指定すれば、いずれかの項目の値がマッチすれば選択される(OR条件)。\n\
\n\
-   f=のOR条件をAND条件に変更することも可能(-Fオプション)。\n\
\n\
-   k=を指定することでキー単位で選択することが可能。\n\
\n\
-   キー単位選択の場合、複数レコードのAND条件を指定可能(-Rオプション)。\n\
\n\
書式\n\
\n\
mselnum f= c= [k=] [u=] [-F] [-r] [-R] [i=] [o=] [bufcount=]\n\
[-assert_diffSize] [-assert_nullkey] [-assert_nullin] [-nfn] [-nfno]\n\
[-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   検索対象となる項目名リスト(複数項目指定可)を指定する。\n\
  c=   f=パラメータで指定した項目の値が、ここで指定した文字列リスト(複数範囲指定可)の1つにマッチすれば選択される。\n\
  k=   撰択する単位となるキー項目(複数項目指定可)を指定する。\n\
  o=   指定の条件に一致する行を出力するファイル名を指定する。\n\
  u=   指定の条件に一致しない行を出力するファイル名を指定する。\n\
  -F   f=パラメータで複数項目を指定した場合、その全ての値がマッチする行を撰択する。\n\
  -r   条件反転\n\
       選択ではなく削除する。\n\
  -R   k=パラメータを指定した場合、その全ての行がマッチすれば行を撰択する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
val項目が2以上5以下の行、すなわちid=2,5の行を選択する。\n\
\n\
    $ more dat1.csv\n\
    id,val\n\
    1,5.1\n\
    2,5\n\
    3,-2.0\n\
    4,\n\
    5,2.0\n\
    $ mselnum f=val c='[2,5]' i=dat1.csv o=rsl1.csv\n\
    #END# kgselnum c=[2,5] f=val i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,val\n\
    2,5\n\
    5,2.0\n\
\n\
例2: 片側範囲\n\
\n\
val項目が2以上の行、すなわちid=1,2,5の行を選択する。\n\
\n\
    $ mselnum f=val c='[2,]' i=dat1.csv o=rsl2.csv\n\
    #END# kgselnum c=[2,] f=val i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id,val\n\
    1,5.1\n\
    2,5\n\
    5,2.0\n\
";

