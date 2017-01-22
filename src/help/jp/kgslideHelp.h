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
/// kgslideHelp.h : kgslide help
// =============================================================================
_titleL="行ずらし";
_docL="\
\n\
MSLIDE 行ずらし\n\
\n\
指定した項目の値を指定した行数ずらして出力する。\n\
例えば、日別の株価データにおいて収益率(当日の株価/前日の株価)を計算するなど\n\
レコード間の演算を行いたい場合に利用する。\n\
\n\
書式\n\
\n\
mslide f= [s=] [k=key] [t=] [-r] [-n] [-l] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] rverb|[–help]| rverb|[–helpl]| [--version]\n\
\n\
  f=   ずらす対象となる項目名を指定する。複数項目指定可能。\n\
       t=を指定しないときは、コロンに続いて窓キーの項目名を指定しなければならない。\n\
  s=   ここで指定した項目(複数項目指定可)で並べ替えられた後、行をずらす。\n\
       -qオプションを指定しないとき、s=パラメータは必須。\n\
  k=   ここで指定された項目の値を単位に処理する。\n\
  t=   ずらす回数を指定する。省略すればt=1が設定される。\n\
  -r   逆方向に(上の値を下に)ずらす。\n\
  -n   次(前)の行がなくてもNULL値を出力する。\n\
  -l   最後にずらした結果のみを出力する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
    $ more dat1.csv\n\
    date,val\n\
    20130406,1\n\
    20130407,2\n\
    20130408,3\n\
    20130409,4\n\
    $ mslide s=date f=val:newVal i=dat1.csv o=rsl1.csv\n\
    #END# kgslide f=val:newVal i=dat1.csv o=rsl1.csv s=date\n\
    $ more rsl1.csv\n\
    date%0,val,newVal\n\
    20130406,1,2\n\
    20130407,2,3\n\
    20130408,3,4\n\
\n\
例2: 逆にずらした例\n\
\n\
    $ mslide s=date f=val:newVal -r i=dat1.csv o=rsl2.csv\n\
    #END# kgslide -r f=val:newVal i=dat1.csv o=rsl2.csv s=date\n\
    $ more rsl2.csv\n\
    date%0,val,newVal\n\
    20130407,2,1\n\
    20130408,3,2\n\
    20130409,4,3\n\
\n\
例3: 複数回指定した場合\n\
\n\
    $ mslide s=date f=val t=2 i=dat1.csv o=rsl3.csv\n\
    #END# kgslide f=val i=dat1.csv o=rsl3.csv s=date t=2\n\
    $ more rsl3.csv\n\
    date%0,val,val1,val2\n\
    20130406,1,2,3\n\
    20130407,2,3,4\n\
\n\
例4: 最後にずらした項目だけを出力する例\n\
\n\
    $ mslide s=date f=val t=2 -l i=dat1.csv o=rsl4.csv\n\
    #END# kgslide -l f=val i=dat1.csv o=rsl4.csv s=date t=2\n\
    $ more rsl4.csv\n\
    date%0,val,val2\n\
    20130406,1,3\n\
    20130407,2,4\n\
\n\
例5: 複数項目名を変更して出力する例\n\
\n\
    $ mslide s=date f=date:d_,val:v_ t=2 i=dat1.csv o=rsl5.csv\n\
    #END# kgslide f=date:d_,val:v_ i=dat1.csv o=rsl5.csv s=date t=2\n\
    $ more rsl5.csv\n\
    date%0,val,d_1,d_2,v_1,v_2\n\
    20130406,1,20130407,20130408,2,3\n\
    20130407,2,20130408,20130409,3,4\n\
";

