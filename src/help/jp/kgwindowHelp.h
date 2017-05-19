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
/// kgwindowHelp.h : kgwindow help
// =============================================================================
_titleL="スライド窓の生成";
_docL="\
\n\
MWINDOW スライド窓の生成\n\
\n\
複数行をずらしながら複製していく。\n\
移動平均の計算など、時系列データにおいて一定幅の窓を設定し、\n\
その窓をずらしながらその窓を単位に何らかの処理(例えば平均)をする目的に利用する。\n\
このような窓をスライド窓(sliding window)と呼ぶ。\n\
\n\
書式\n\
\n\
mwindow wk= t= [k=key] [-r] [-n] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  wk=    出力データにおいて、窓をユニークに識別する値となる入力データ上の項目を指定する。\n\
         ここで指定した項目で並べ替えられたのちスライド窓を生成していくが、\n\
         降順で並べ替えるときは%r、数値として並べ替えるときは%nと追加する。\n\
         数値の降順で並べ替えるときは%nrと追加すればよい。\n\
         またコロンに続いて窓キーの項目名を指定しなければならない。複数項目を指定することもできる。\n\
  t=     窓のサイズ(行数)を指定する。\n\
  k=     ここで指定された項目の値を単位に窓の生成を行う。\n\
  -r     窓における基準行を先頭行とする。指定がなければ最終行となる。\n\
  -n     窓のサイズがt=で指定した行数に満たなくても出力する。\n\
  i=     入力ファイル名\n\
  -nfn   入力データの1行目を項目名行とみなさない。\n\
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
    $ mwindow wk=date:win t=2 i=dat1.csv o=rsl1.csv\n\
    #END# kgwindow i=dat1.csv o=rsl1.csv t=2 wk=date:win\n\
    $ more rsl1.csv\n\
    win%0,date,val\n\
    20130407,20130406,1\n\
    20130407,20130407,2\n\
    20130408,20130407,2\n\
    20130408,20130408,3\n\
    20130409,20130408,3\n\
    20130409,20130409,4\n\
\n\
例2: 基準行を先頭にした例\n\
\n\
    $ mwindow wk=date:win t=3 -r i=dat1.csv o=rsl2.csv\n\
    #END# kgwindow -r i=dat1.csv o=rsl2.csv t=3 wk=date:win\n\
    $ more rsl2.csv\n\
    win%0,date,val\n\
    20130406,20130406,1\n\
    20130406,20130407,2\n\
    20130406,20130408,3\n\
    20130407,20130407,2\n\
    20130407,20130408,3\n\
    20130407,20130409,4\n\
\n\
例3: 指定行数に満たない窓も出力する例\n\
\n\
    $ mwindow wk=date:win t=3 -r -n i=dat1.csv o=rsl3.csv\n\
    #END# kgwindow -n -r i=dat1.csv o=rsl3.csv t=3 wk=date:win\n\
    $ more rsl3.csv\n\
    win%0,date,val\n\
    20130406,20130406,1\n\
    20130406,20130407,2\n\
    20130406,20130408,3\n\
    20130407,20130407,2\n\
    20130407,20130408,3\n\
    20130407,20130409,4\n\
    20130408,20130408,3\n\
    20130408,20130409,4\n\
    20130409,20130409,4\n\
\n\
例4: キー項目を指定した例\n\
\n\
    $ more dat2.csv\n\
    store,date,val\n\
    a,20130406,1\n\
    a,20130407,2\n\
    a,20130408,3\n\
    a,20130409,4\n\
    b,20130406,11\n\
    b,20130407,12\n\
    b,20130408,13\n\
    b,20130409,14\n\
    $ mwindow k=store wk=date:win t=2 i=dat2.csv o=rsl4.csv\n\
    #END# kgwindow i=dat2.csv k=store o=rsl4.csv t=2 wk=date:win\n\
    $ more rsl4.csv\n\
    win%1,store%0,date,val\n\
    20130407,a,20130406,1\n\
    20130407,a,20130407,2\n\
    20130408,a,20130407,2\n\
    20130408,a,20130408,3\n\
    20130409,a,20130408,3\n\
    20130409,a,20130409,4\n\
    20130407,b,20130406,11\n\
    20130407,b,20130407,12\n\
    20130408,b,20130407,12\n\
    20130408,b,20130408,13\n\
    20130409,b,20130408,13\n\
    20130409,b,20130409,14\n\
\n\
例5: 前日までの移動平均を求める\n\
\n\
冒頭に示した移動平均の例では、窓における最終日を基準として平均を計算している。\n\
時に、基準日を前日として移動平均を計算したいケースがある。\n\
そういった場合はmslideで1日日付をずらしてから本コマンドを使えばよい。\n\
その例を以下に示す。\n\
\n\
    $ mslide f=date:date2 s=date i=dat1.csv o=rsl5.csv\n\
    #END# kgslide f=date:date2 i=dat1.csv o=rsl5.csv s=date\n\
    $ more rsl5.csv\n\
    date%0,val,date2\n\
    20130406,1,20130407\n\
    20130407,2,20130408\n\
    20130408,3,20130409\n\
    $ mwindow wk=date2:win t=2 i=rsl5.csv o=rsl6.csv\n\
    #END# kgwindow i=rsl5.csv o=rsl6.csv t=2 wk=date2:win\n\
    $ more rsl6.csv\n\
    win%0,date,val,date2\n\
    20130408,20130406,1,20130407\n\
    20130408,20130407,2,20130408\n\
    20130409,20130407,2,20130408\n\
    20130409,20130408,3,20130409\n\
";

