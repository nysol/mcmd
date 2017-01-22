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
/// kgnrjoinHelp.h : kgnrjoin help
// =============================================================================
_titleL="参照ファイルの複数範囲条件による自然結合";
_docL="\
\n\
MNRJOIN 参照ファイルの複数範囲条件による自然結合\n\
\n\
範囲により参照ファイルの項目を結合(join)する。\n\
r=パラメータで指定した項目値が、m=パラメータで指定した参照ファイルの\n\
R=パラメータで指定した2項目の値の範囲条件(項目1以上項目2未満)に\n\
マッチすればf=パラメータの項目を結合する。\n\
マッチする行が複数あれば、それらの行全てが出力され、ちょうど自然結合のような動きをする。\n\
範囲比較される値は、デフォルトで文字列と見なされる。\n\
数値として処理したい場合はr=パラメータの項目名のあとに%nをつける。\n\
\n\
書式\n\
\n\
mnrjoin  R= r= [k=] [K=] [f=] [-n] [-N] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=   結合する参照ファイル上の項目名リスト(複数項目指定可)を指定する。\n\
       省略するとK=で指定された項目以外の項目を全て結合する。\n\
  m=   参照ファイル名を指定する。\n\
       このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  R=   範囲項目名リスト(二項目限定)\n\
       参照ファイル上の範囲項目名(start,end)を指定する。\n\
       第一項目のNULL値は無限小，第二項目のNULL値は無限大として扱われる。\n\
  r=   範囲比較される項目名[%n]\n\
       入力ファイル上の項目名を指定する。\n\
       数値として処理したい場合はr=パラメータの項目名のあとに%nをつける。\n\
  k=   入力データ上の突き合わせる項目名リスト(複数項目指定可)\n\
       ここで指定した入力データの項目とK=パラメータで指定された参照データの項目が同じ行の項目結合が行われる。\n\
  K=   参照データ上の突き合わせる項目名リスト(複数項目指定可)\n\
       ここで指定した参照データの項目とk=パラメータで指定された入力データの項目が同じ行の項目結合が行われる。\n\
       参照データ上にk=パラメータで指定した入力データ上の項目と同名の項目が存在する場合は指定する必要はない。\n\
  -n   参照データにない入力データをNULL値として出力するフラグ。\n\
  -N   入力データにない参照データをNULL値として出力するフラグ。\n\
\n\
例えば、パラメータをk=key K=Key r=val%n R=range i=dat.csv m=ref.csvと指定するのであれば、\n\
dat.csvデータは、msortf f=key,val%nの条件で、また\n\
ref.csvデータは、msortf f=Key,range%nの条件によって並べ替えておかなければならない。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
日付項目の値が20080203で、「金額」項目の値が5以上15未満の入力データ行にはavg=150を、\n\
40以上50未満の行にはavg=200を結合する。\n\
\n\
    $ more dat1.csv\n\
    date,price\n\
    20080123,10\n\
    20080123,20\n\
    20080203,10\n\
    20080203,35\n\
    200804l0,50\n\
    $ more ref1.csv\n\
    date,priceF,priceT,avg\n\
    20080203,5,15,150\n\
    20080203,40,50,200\n\
    $ mnrjoin k=date f=avg m=ref1.csv R=priceF,priceT r=price%n i=dat1.csv o=rsl1.csv\n\
    #END# kgnrjoin R=priceF,priceT f=avg i=dat1.csv k=date m=ref1.csv o=rsl1.csv r=price%n\n\
    $ more rsl1.csv\n\
    date%0,price,avg\n\
    20080203,10,150\n\
\n\
例2: 未結合データ出力\n\
\n\
-nを指定することで、参照ファイルにマッチしない入力ファイルの行(avg=がNULL値の行)も出力し、\n\
-Nを指定することで、入力ファイルにマッチしない参照ファイルの行(price=がNULL値の行)も出力する。\n\
いわゆる外部結合である。\n\
\n\
    $ mnrjoin k=date f=avg m=ref1.csv R=priceF,priceT r=price%n -n -N i=dat1.csv o=rsl2.csv\n\
    #END# kgnrjoin -N -n R=priceF,priceT f=avg i=dat1.csv k=date m=ref1.csv o=rsl2.csv r=price%n\n\
    $ more rsl2.csv\n\
    date%0,price,avg\n\
    20080123,10,\n\
    20080123,20,\n\
    20080203,10,150\n\
    20080203,35,\n\
    20080203,,200\n\
    200804l0,50,\n\
";

