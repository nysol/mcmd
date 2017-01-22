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
/// kgbestHelp.h : kgbest help
// =============================================================================
_titleL="指定行の選択";
_docL="\
\n\
MBEST 指定行の選択\n\
\n\
指定した行番号の行を選択する。\n\
行番号は0から始まることに注意する(項目名行は除いて、データ本体の先頭行が0行目)。\n\
行番号はfrom=とto=(もしくはsize=)で指定する。\n\
\n\
書式\n\
\n\
mbest s= [R=] [from=] [to=|size=] [k=] [u=] [-r] [i=] [o=]\n\
[-assert_diffSize] [-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  s=      ここで指定した項目(複数項目指定可)で並べ替えられた後、指定した行が選択される。\n\
          -qオプションを指定しないとき、s=パラメータは必須。\n\
  from=   選択する開始行番号(0以上の整数)【デフォルト値:0】\n\
  to=     選択する終了行番号(0以上の整数)【デフォルト値:0】\n\
          「from=の値」<=「to=の値」でなければならない。\n\
  size=   選択する行数【デフォルト値:1】\n\
          to=とsize=の両方を同時に指定することはできない。\n\
  k=      指定列の項目(複数項目指定可)が同じ値の行ごとに、from=,to=,size=で指定した行番号の行を選択する。\n\
          -x,-nfnオプション使用時は、項目番号(0〜)で指定可能。\n\
  u=      不一致データ出力ファイル名\n\
          指定の条件に一致しない行を出力するファイル名。\n\
  -r      条件反転\n\
          from=,to=(size=)パラメータで指定した行番号以外の行を選択する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
この例では、「数量」と「金額」項目値の大きい順（降順）に並べ替えている。\n\
from=,to=,size=を指定しなければ先頭行(0行目)のみ選択する\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,20,5200 \n\
    B,18,4000   \n\
    C,15,3500 \n\
    D,10,2000 \n\
    E,3,800 \n\
    $ mbest s=数量%nr,金額%nr i=dat1.csv o=rsl1.csv\n\
    #END# kgbest i=dat1.csv o=rsl1.csv s=数量%nr,金額%nr\n\
    $ more rsl1.csv\n\
    顧客,数量%0nr,金額%1nr\n\
    A,20,5200 \n\
\n\
例2: 基本例2\n\
\n\
「顧客」で並べ替えた後、先頭行(0行目)から3行選択する\n\
\n\
    $ mbest s=顧客 from=0 size=3 i=dat1.csv o=rsl2.csv\n\
    #END# kgbest from=0 i=dat1.csv o=rsl2.csv s=顧客 size=3\n\
    $ more rsl2.csv\n\
    顧客%0,数量,金額\n\
    A,20,5200 \n\
    B,18,4000   \n\
    C,15,3500 \n\
\n\
例3: 基本例3\n\
\n\
並べ替えを行わず(もとのレコード順序を維持したまま)、0行目から1行目まで選択する\n\
\n\
    $ mbest -q from=0 to=1 i=dat1.csv o=rsl3.csv\n\
    #END# kgbest -q from=0 i=dat1.csv o=rsl3.csv to=1\n\
    $ more rsl3.csv\n\
    顧客,数量,金額\n\
    A,20,5200 \n\
    B,18,4000   \n\
\n\
例4: 条件反転\n\
\n\
顧客の初回来店日以外の行を選択する。\n\
初回来店日はfvd.csvというファイルに出力する。\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    $ mbest s=顧客,日付 k=顧客 -r u=fvd.csv i=dat2.csv o=rsl4.csv\n\
    #END# kgbest -r i=dat2.csv k=顧客 o=rsl4.csv s=顧客,日付 u=fvd.csv\n\
    $ more rsl4.csv\n\
    顧客,日付,金額\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
    $ more fvd.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
";

