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
/// kgnormalizeHelp.h : kgnormalize help
// =============================================================================
_titleL="基準化";
_docL="\
\n\
MNORMALIZE 基準化\n\
\n\
f=パラメータで指定した項目を、c=パラメータで指定した基準化の方法で基準化する。\n\
\n\
書式\n\
\n\
mnormalize c= f= [k=] [i=] [o=] [bufcount=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  c=   以下に示す基準化の方法のいずれかを指定する。\n\
       z : z得点 : zi = (xi − m)/u (xi: i番目のデータ, m :算術平均, u :標準偏差)\n\
       Z : 偏差値 : Zi = 50 + 10 × zi\n\
       range : 最小値を0,最大値を1に線形変換 ri = (xi − minx)/(maxx − minx)\n\
  f=   ここで指定された項目が基準化される。\n\
       :(コロン）で新項目名を指定する必要がある。例）f=数量:数量基準値\n\
  k=   キー項目名リスト\n\
       ここで指定された項目を単位に基準化を行う。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」を単位にして「数量」と「金額」項目を基準化（z得点）し、\n\
「数量基準値」と「金額基準値」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mnormalize c=z k=顧客 f=数量:数量基準値,金額:金額基準値 i=dat1.csv o=rsl1.csv\n\
    #END# kgnormalize c=z f=数量:数量基準値,金額:金額基準値 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客%0,数量,金額,数量基準値,金額基準値\n\
    A,1,10,-0.7071067812,-0.7071067812\n\
    A,2,20,0.7071067812,0.7071067812\n\
    B,1,15,-0.5773502692,0\n\
    B,3,10,1.154700538,-1\n\
    B,1,20,-0.5773502692,1\n\
\n\
例2: 偏差値\n\
\n\
    $ mnormalize c=Z k=顧客 f=数量:数量基準値,金額:金額基準値 i=dat1.csv o=rsl2.csv\n\
    #END# kgnormalize c=Z f=数量:数量基準値,金額:金額基準値 i=dat1.csv k=顧客 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客%0,数量,金額,数量基準値,金額基準値\n\
    A,1,10,42.92893219,42.92893219\n\
    A,2,20,57.07106781,57.07106781\n\
    B,1,15,44.22649731,50\n\
    B,3,10,61.54700538,40\n\
    B,1,20,44.22649731,60\n\
\n\
例3: 0から1への線形変換\n\
\n\
    $ mnormalize c=range k=顧客 f=数量:数量基準値,金額:金額基準値 i=dat1.csv o=rsl3.csv\n\
    #END# kgnormalize c=range f=数量:数量基準値,金額:金額基準値 i=dat1.csv k=顧客 o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客%0,数量,金額,数量基準値,金額基準値\n\
    A,1,10,0,0\n\
    A,2,20,1,1\n\
    B,1,15,0,0.5\n\
    B,3,10,1,0\n\
    B,1,20,0,1\n\
";

