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
/// kgpasteHelp.h : kgpaste help
// =============================================================================
_titleL="参照ファイル項目の行番号マッチング結合";
_docL="\
\n\
MPASTE 参照ファイル項目の行番号マッチング結合\n\
\n\
入力ファイルと参照ファイルを行番号でマッチングさせて結合する。\n\
データ件数が異なる場合は、少い方のデータに合わせる。\n\
-nや-Nを指定することでマッチングできな行もNULL値で結合することが可能である。\n\
\n\
書式\n\
\n\
mpaste [f=] -n -N m=| i= [o=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  f=   結合する参照ファイル上の項目名リスト(複数項目指定可)。\n\
       省略するとキー項目を除いた全ての項目が結合される。\n\
  m=   参照ファイル名を指定する。\n\
       このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  -n   入力ファイルにあって参照ファイルにない場合にNULL値を出力する。\n\
  -N   参照ファイルにあって入力ファイルにない場合にNULL値を出力する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
    $ more dat1.csv\n\
    id1\n\
    1\n\
    2\n\
    3\n\
    4\n\
    $ more ref1.csv\n\
    id2\n\
    a\n\
    b\n\
    c\n\
    d\n\
    $ mpaste m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgpaste i=dat1.csv m=ref1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id1,id2\n\
    1,a\n\
    2,b\n\
    3,c\n\
    4,d\n\
\n\
例2: 行数が異なる例\n\
\n\
入力ファイルと参照ファイルで行数が異なる場合は、少いファイルの行数に合わせる。\n\
\n\
    $ more ref2.csv\n\
    id2\n\
    a\n\
    b\n\
    $ mpaste m=ref2.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgpaste i=dat1.csv m=ref2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    id1,id2\n\
    1,a\n\
    2,b\n\
\n\
例3: 外部結合\n\
\n\
-nを指定すると、参照ファイルの行数が少なくても、対応しない入力ファイルの行もNULL値を結合して出力する。\n\
\n\
    $ mpaste m=ref2.csv -n i=dat1.csv o=rsl3.csv\n\
    #END# kgpaste -n i=dat1.csv m=ref2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    id1,id2\n\
    1,a\n\
    2,b\n\
    3,\n\
    4,\n\
\n\
例4: 結合項目を指定\n\
\n\
    $ more ref3.csv\n\
    id2,val\n\
    a,R0\n\
    b,R1\n\
    c,R2\n\
    d,R3\n\
    $ mpaste f=val m=ref3.csv i=dat1.csv o=rsl4.csv\n\
    #END# kgpaste f=val i=dat1.csv m=ref3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    id1,val\n\
    1,R0\n\
    2,R1\n\
    3,R2\n\
    4,R3\n\
";

