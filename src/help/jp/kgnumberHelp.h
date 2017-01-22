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
/// kgnumberHelp.h : kgnumber help
// =============================================================================
_titleL="連番";
_docL="\
\n\
MNUMBER 連番\n\
\n\
数字連番もしくはアルファベット連番(A,B,...,Z,AA,AB,...,AZ,BA,BB,...,ZZ,AAA,AAB,...)ををふり、a=パラメータで指定した項目名で出力する。\n\
\n\
書式\n\
\n\
mnumber a= [e=] [I=] [k=] [s=] [S=] [-B] [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  a=   新たに追加される項目の名前を指定する。【但し、-nfn,-nfnoオプション指定時は必要なし】\n\
  e=   同Rankの処理方法\n\
       同一キー同一ソート項目値への処理方法を指定する。\n\
       指定しない場合は、デフォルトとして(e=seq)並び順でNoもしくは文字列が付け加えられる。\n\
       seq:同Rankの場合は並び順でNoもしくはアルファベット連番を付け加える。\n\
       same:同Rankの場合は同じNoもしくはアルファベットを付け加える。\n\
       skip:同Rankの場合は同じNoを振り、\n\
       次のNoはスキップするようにNoもしくはアルファベット連番を付け加える。\n\
       (注意)e={same/skip}を指定する場合は、s=パラメータを同時に指定しなければならない。\n\
  I=   連番の間隔を指定する。\n\
  k=   連番もしくは連文字をふる単位となる項目名リスト(複数項目指定可)を指定する。【集計キーブレイク処理】\n\
       (注意）指定する場合は事前にk=パラメータで指定する連番、\n\
       もしくは連文字をふる単位となる項目順に並べ替えておく必要がある。\n\
  s=   ここで指定した項目(複数項目指定可)で並べ替えられた後、連番が追加される。\n\
       -Bオプション指定時以外は必須。\n\
  S=   開始No\n\
       連番の開始Noを指定する。\n\
       大文字のアルファベットが指定された場合はアルファベット連番となる。\n\
       ただし、アルファベット連番の場合、間隔(I=)に負の値は指定できない。\n\
  -B   キー毎に連番もしくはアルファベット連番をふる。\n\
       あるキー内では全行同じNoもしくはアルファベットがふられる。\n\
\n\
利用例\n\
\n\
例1: 数字の連番\n\
\n\
Customer項目名順（昇順）に連番を振り「No」という項目名で出力する。\n\
\n\
    $ more dat1.csv\n\
    Customer,Val,Sum\n\
    A,29,300\n\
    B,35,250\n\
    C,15,200\n\
    D,23,150\n\
    E,10,100\n\
    $ mnumber s=Customer a=No i=dat1.csv o=rsl1.csv\n\
    #END# kgnumber a=No i=dat1.csv o=rsl1.csv s=Customer\n\
    $ more rsl1.csv\n\
    Customer%0,Val,Sum,No\n\
    A,29,300,0\n\
    B,35,250,1\n\
    C,15,200,2\n\
    D,23,150,3\n\
    E,10,100,4\n\
\n\
例2: Date項目順の連番\n\
\n\
Date項目順（昇順）に連番をふる。その際、同じDateには同じNoを振り「No」という項目名で出力する。\n\
\n\
    $ more dat2.csv\n\
    Date\n\
    20090101\n\
    20090101\n\
    20090102\n\
    20090103\n\
    20090103\n\
    $ mnumber k=Date a=No -B i=dat2.csv o=rsl2.csv\n\
    #END# kgnumber -B a=No i=dat2.csv k=Date o=rsl2.csv\n\
    $ more rsl2.csv\n\
    Date%0,No\n\
    20090101,0\n\
    20090101,0\n\
    20090102,1\n\
    20090103,2\n\
    20090103,2\n\
\n\
例3: Sum項目順の連番(同Rankは同じアルファベットをふる)\n\
\n\
Sum項目の多い順（降順）にアルファベットのAから順に連文字を振り「Rank」という項目名で出力する。\n\
また、同Rankの場合は同じアルファベット文字を振ることにする。\n\
\n\
    $ more dat3.csv\n\
    Customer,Val,Sum\n\
    A,3,300\n\
    B,1,250\n\
    C,2,250\n\
    D,1,150\n\
    E,1,100\n\
    $ mnumber a=Rank e=same s=Sum%nr S=A  i=dat3.csv o=rsl3.csv\n\
    #END# kgnumber S=A a=Rank e=same i=dat3.csv o=rsl3.csv s=Sum%nr\n\
    $ more rsl3.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,A\n\
    B,1,250,B\n\
    C,2,250,B\n\
    D,1,150,C\n\
    E,1,100,D\n\
\n\
例4: Sum項目順の連番(同Rankは並び順でNoをふる)\n\
\n\
Sum項目の多い順（降順）に連番を振り「Rank」という項目名で出力する。\n\
その際、同Rankの場合は並び順でNoを振ることにする。\n\
\n\
    $ mnumber a=Rank e=seq s=Sum%nr i=dat3.csv o=rsl4.csv\n\
    #END# kgnumber a=Rank e=seq i=dat3.csv o=rsl4.csv s=Sum%nr\n\
    $ more rsl4.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,0\n\
    B,1,250,1\n\
    C,2,250,2\n\
    D,1,150,3\n\
    E,1,100,4\n\
\n\
例5: Sum項目順の連番(同Rankは同じNoをふる)\n\
\n\
Sum項目の多い順（降順）に連番を振り「Rank」という項目名で出力する。\n\
その際、同Rankの場合は同じNoを振ることにする。\n\
\n\
    $ mnumber a=Rank e=same s=Sum%nr i=dat3.csv o=rsl5.csv\n\
    #END# kgnumber a=Rank e=same i=dat3.csv o=rsl5.csv s=Sum%nr\n\
    $ more rsl5.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,0\n\
    B,1,250,1\n\
    C,2,250,1\n\
    D,1,150,2\n\
    E,1,100,3\n\
\n\
例6: Sum項目順の連番(同Rankの場合は同じRankNoを振り、次のNoはスキップ)\n\
\n\
Sum項目の多い順（降順）に連番を振り「Rank」という項目名で出力する。\n\
その際、同Rankの場合は同じRankNoを振り、次のNoはスキップするようにNoを振ることにする。\n\
\n\
    $ mnumber a=Rank e=skip s=Sum%nr i=dat3.csv o=rsl6.csv\n\
    #END# kgnumber a=Rank e=skip i=dat3.csv o=rsl6.csv s=Sum%nr\n\
    $ more rsl6.csv\n\
    Customer,Val,Sum%0nr,Rank\n\
    A,3,300,0\n\
    B,1,250,1\n\
    C,2,250,1\n\
    D,1,150,3\n\
    E,1,100,4\n\
\n\
例7: 10から始まる連番\n\
\n\
Sum項目の小さい順（昇順）に10から始まる連番を振り「Score」という項目名で出力する。\n\
その際、同Rankの場合は同じRankNoを振り、次のNoはスキップするようにNoを振ることにする。\n\
\n\
    $ more dat4.csv\n\
    Customer,Val,Sum\n\
    A,1,100\n\
    B,1,150\n\
    C,1,250\n\
    D,2,250\n\
    E,3,300\n\
    $ mnumber a=Score e=same s=Sum%n S=10 i=dat4.csv o=rsl7.csv\n\
    #END# kgnumber S=10 a=Score e=same i=dat4.csv o=rsl7.csv s=Sum%n\n\
    $ more rsl7.csv\n\
    Customer,Val,Sum%0n,Score\n\
    A,1,100,10\n\
    B,1,150,11\n\
    C,1,250,12\n\
    D,2,250,12\n\
    E,3,300,13\n\
\n\
例8: 10から始まる5つ飛びの連番\n\
\n\
Sum項目の小さい順番（昇順）に10から始まる5つ飛びの連番を振り「Score」という項目名で出力する。\n\
また、同Rankの場合は同じNoを振ることにする。\n\
\n\
    $ mnumber a=Score e=same s=Sum%n S=10 I=5 i=dat4.csv o=rsl8.csv\n\
    #END# kgnumber I=5 S=10 a=Score e=same i=dat4.csv o=rsl8.csv s=Sum%n\n\
    $ more rsl8.csv\n\
    Customer,Val,Sum%0n,Score\n\
    A,1,100,10\n\
    B,1,150,15\n\
    C,1,250,20\n\
    D,2,250,20\n\
    E,3,300,25\n\
";

