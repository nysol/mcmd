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
/// kgselrandHelp.h : kgselrand help
// =============================================================================
_titleL="ランダムに行を選択";
_docL="\
\n\
MSELRAND ランダムに行を選択\n\
\n\
c=パラメータもしくはp=パラメータで指定した行数をランダムに選択する(非復元抽出)。\n\
k=を指定した場合、同一キーの行から指定の行数をランダムに選択し、\n\
また同時に-Bオプションを指定すると、キー単位で選択する。\n\
\n\
乱数の生成にはメルセンヌ・ツイスター法を利用している\n\
(http://www.math.sci.hiroshima-u.ac.jp/ m-mat/MT/emt.html ,\n\
http://www.boost.org/doc/libs/1_54_0/doc/html/boost_random.html)。\n\
\n\
書式\n\
\n\
mselrand c=|p= [k=] [S=] [u=] [-B] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  c=   各キーの値毎に選択する行数を指定する。\n\
       p=パラメータを指定しない場合の指定は必ず指定する必要がある。\n\
  p=   各キーの値毎に選択する割合をパーセントで指定する。\n\
       c=パラメータを指定しない場合の指定は必ず指定する必要がある。\n\
  k=   指定する項目（複数項目指定可）の値が同じ行から、一定行数ランダムに選択する。\n\
  S=   同じ乱数の種は同じシーケンスの乱数をふる。\n\
       指定しない場合は、時刻に応じた異なる乱数の種が利用される。\n\
       指定可能な乱数の種(-2147483648〜2147483647)\n\
  u=   指定の条件に一致しない行を出力するファイル名を指定する。\n\
  -B   キー単位選択\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
一人の顧客につきランダムに1行を選択する。\n\
\n\
    $ more dat1.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    $ mselrand k=顧客 c=1 S=1 i=dat1.csv o=rsl1.csv\n\
    #END# kgselrand S=1 c=1 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
\n\
例2: ランダムに一定割合の行を選択\n\
\n\
一人の顧客につきランダムに50%の行を選択する。\n\
また、それ以外の不一致データはoth2.csvというファイルに出力する。\n\
\n\
    $ mselrand k=顧客 p=50 S=1 u=oth2.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgselrand S=1 i=dat1.csv k=顧客 o=rsl2.csv p=50 u=oth2.csv\n\
    $ more rsl2.csv\n\
    顧客%0,日付,金額\n\
    A,20081201,10\n\
    B,20081002,40\n\
    $ more oth2.csv\n\
    顧客%0,日付,金額\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081209,50\n\
\n\
例3: キー単位の選択\n\
\n\
以下の例は、顧客A,B,C,Dの4人からランダムに2人を選ぶ。\n\
顧客Dが選ばれると、顧客Dの行は全て出力される。\n\
\n\
    $ more dat2.csv\n\
    顧客,日付,金額\n\
    A,20081201,10\n\
    A,20081207,20\n\
    A,20081213,30\n\
    B,20081002,40\n\
    B,20081209,50\n\
    C,20081210,60\n\
    D,20081201,70\n\
    D,20081205,80\n\
    D,20081209,90\n\
    $ mselrand k=顧客 c=2 S=1 -B i=dat2.csv o=rsl3.csv\n\
    #END# kgselrand -B S=1 c=2 i=dat2.csv k=顧客 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客%0,日付,金額\n\
    C,20081210,60\n\
    D,20081201,70\n\
    D,20081205,80\n\
    D,20081209,90\n\
";

