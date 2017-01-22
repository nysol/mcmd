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
/// kgnrcommonHelp.h : kgnrcommon help
// =============================================================================
_titleL="参照ファイルの複数範囲条件による行撰択";
_docL="\
\n\
MNRCOMMON 参照ファイルの複数範囲条件による行撰択\n\
\n\
参照ファイルの範囲条件にマッチする入力ファイルの行を選択する。\n\
k=パラメータで指定した入力ファイルの項目値とK=パラメータで指定した参照ファイルの項目値が同じ行について、\n\
r=でパラメータで指定した項目値がR=パラメータで指定した2項目の値の範囲条件(項目1以上項目2未満)にマッチすれば選択する。\n\
数値として処理したい場合はr=パラメータの項目名のあとに%nをつけること。\n\
\n\
書式\n\
\n\
mnrcommon [k=] R= r= [K=] [u=] [-r] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  k=   入力データ上の突き合わせる項目名リスト(複数項目指定可)を指定する。\n\
       ここで指定した入力データの項目とK=パラメータで指定された参照データの項目が同じ行の項目結合が行われる。\n\
  m=   参照ファイル名を指定する。\n\
       このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  R=   参照ファイル上の範囲項目名(start,end)を指定する。\n\
       第一項目のNULL値は無限小，第二項目のNULL値は無限大として扱われる。\n\
  r=   範囲比較される入力ファイル上の項目名を指定する。[%n]\n\
       ここで指定した参照データの項目とk=パラメータで指定された入力データの項目が同じ行が選択される。\n\
       数値として処理したい場合はr=パラメータの項目名のあとに%nをつける。\n\
  K=   参照データ上の突き合わせる項目名リスト(複数項目指定可)\n\
       ここで指定した参照データの項目とk=パラメータで指定された入力データの項目が同じ行の項目結合が行われる。\n\
       参照データ上にk=パラメータで指定した入力データ上の項目と同名の項目が存在する場合は指定する必要はない。\n\
  u=   指定の条件に一致しない行を出力するファイル名。\n\
  -r   条件反転\n\
       R=パラメータで指定した行番号以外の行を選択する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
日付項目の値が20080203で、「金額」項目の値が5以上15未満の行、および40以上50未満の行を選択する。\n\
\n\
    $ more dat1.csv\n\
    日付,金額\n\
    20080123,10\n\
    20080203,10\n\
    20080203,20\n\
    20080203,45\n\
    200804l0,50\n\
    $ more ref1.csv\n\
    日付,金額F,金額T\n\
    20080203,5,15\n\
    20080203,40,50\n\
    $ mnrcommon k=日付 m=ref1.csv R=金額F,金額T r=金額%n i=dat1.csv o=rsl1.csv\n\
    #END# kgnrcommon R=金額F,金額T i=dat1.csv k=日付 m=ref1.csv o=rsl1.csv r=金額%n\n\
    $ more rsl1.csv\n\
    日付%0,金額\n\
    20080203,10\n\
    20080203,45\n\
\n\
例2: 条件反転\n\
\n\
-rを付けると選択条件は反転する。\n\
\n\
    $ mnrcommon k=日付 m=ref1.csv R=金額F,金額T r=金額%n -r i=dat1.csv o=rsl2.csv\n\
    #END# kgnrcommon -r R=金額F,金額T i=dat1.csv k=日付 m=ref1.csv o=rsl2.csv r=金額%n\n\
    $ more rsl2.csv\n\
    日付%0,金額\n\
    20080123,10\n\
    20080203,20\n\
    200804l0,50\n\
";

