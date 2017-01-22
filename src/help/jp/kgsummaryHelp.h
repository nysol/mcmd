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
/// kgsummaryHelp.h : kgsummary help
// =============================================================================
_titleL="1変数の統計量の計算";
_docL="\
\n\
MSUMMARY 1変数の統計量の計算\n\
\n\
f=パラメータで指定した集計項目で\n\
c=パラメータで指定した統計量の計算をする。\n\
\n\
書式\n\
\n\
msummary c= f= [a=] [k=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  k=   キー項目名リスト(複数項目指定可)【集計キーブレイク処理】\n\
       ここで指定された項目を単位として集計する。\n\
       指定する場合は事前に指定する集計の単位となる項目順に並べ替えておく必要がある。\n\
  f=   集計項目名リスト(複数項目指定可)\n\
       ここで指定された項目の値が集計される。\n\
       -x,-nfnオプション使用時は、項目番号(0～)で指定。\n\
  c=   統計量リスト(複数項目指定可)\n\
       出力する統計量をコンマで区切って指定する。\n\
       統計量リスト:\n\
       sum/mean/count/ucount/devsq/var/uvar/sd/usd/cv/min/qtile1/median/qtile3/max/\n\
       range/qrange/mode/skew/uskew/kurt/ukurt\n\
  -a   新項目名\n\
       f=パラメータで指定した項目名をデータとして出力する際の項目名(省略時はfld)を指定する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位に「数量」と「金額」項目の中央値・平均値を求める。\n\
統計量を求めた項目名は「変数」という項目に出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ msummary k=顧客 f=数量,金額 c=median:中央値,mean:平均値 a=変数 i=dat1.csv o=rsl1.csv\n\
    #END# kgsummary a=変数 c=median:中央値,mean:平均値 f=数量,金額 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,変数,中央値,平均値\n\
    A,数量,1.5,1.5\n\
    A,金額,15,15\n\
    B,数量,1,1.666666667\n\
    B,金額,15,15\n\
";

