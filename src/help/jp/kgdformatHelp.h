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
/// kgdformatHelp.h : kgdformat help
// =============================================================================
_titleL="日付時刻抽出";
_docL="\
\n\
MDFORMAT 日付時刻抽出\n\
\n\
他のシステムからエクスポートしたCSVデータでは、\n\
日付時刻項目にスラッシュ記号やコロン記号が入っていることが多く、\n\
また月日や時が1桁で格納されている場合もある (例:2014/7/18 1:57)。\n\
このような項目をそのままMCMDで扱おうとすると、\n\
並べ替えや範囲指定がうまくいかない。\n\
\n\
mdformatコマンドを使うことで、 f=パラメータで指定した項目から、\n\
c=パラメータで指定したフォーマットに従って\n\
年月日・時分秒を抽出し、MCMDで扱うことが容易な 日付型や時刻型\n\
に変換することができる。\n\
\n\
書式\n\
\n\
mdformat c= f= [-A]  [i=] [o=] [-assert_diffSize] [-assert_nullin]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  f=   抽出対象となる項目名リスト(複数項目指定可)を指定する。\n\
  c=   文字列のフォーマットを指定する。フォーマットの変換指定文字参照\n\
  -A   このオプションにより、指定した項目を置き換えるのではなく、新たに項目が追加される。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
fld項目から日付・時刻を抽出し変換する。\n\
fld項目には「a:年月日:b:時分秒」の形式で日付・時刻が格納されているので、\n\
c=パラメータには「a:%Y%m%d:b:%H%M%S」と指定している。\n\
\n\
    $ more dat1.csv\n\
    fld\n\
    a:20120304:b:121212\n\
    a:20101204:b:011309\n\
    $ mdformat f=fld c=a:%Y%m%d:b:%H%M%S i=dat1.csv o=rsl1.csv\n\
    #END# kgdformat c=a:%Y%m%d:b:%H%M%S f=fld i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    fld\n\
    20120304121212\n\
    20101204011309\n\
\n\
例2: 項目の追加\n\
\n\
fld1項目、fld2項目には「年/月/日」形式で日付が格納されているので、\n\
c=パラメータには「%Y/%m/%d」と指定している。\n\
-Aオプションを使用し、変換結果を新たなf1、f2項目に抽出する。\n\
\n\
    $ more dat2.csv\n\
    fld,fld2\n\
    2010/11/20,2010/11/21\n\
    2010/1/1,2010/1/2\n\
    2011/01/01,2010/01/02\n\
    2010/1/01,2010/1/02\n\
    $ mdformat f=fld:f1,fld2:f2 c=%Y/%m/%d i=dat2.csv -A o=rsl2.csv\n\
    #END# kgdformat -A c=%Y/%m/%d f=fld:f1,fld2:f2 i=dat2.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    fld,fld2,f1,f2\n\
    2010/11/20,2010/11/21,20101120,20101121\n\
    2010/1/1,2010/1/2,20100101,20100102\n\
    2011/01/01,2010/01/02,20110101,20100102\n\
    2010/1/01,2010/1/02,20100101,20100102\n\
\n\
例3: 抽出がうまくいかない例\n\
\n\
fld項目には「年 月 日 時:分:秒」形式で日付が格納されているので、\n\
c=パラメータには「%Y %m %d %H:%M:%S」と指定している。\n\
しかし形式が異なる行は抽出に失敗している。\n\
\n\
    $ more dat3.csv\n\
    fld\n\
    2010 11 20 12:34:56\n\
\n\
    2011 01 01 23:34:56\n\
    2010  1 01 123455\n\
    $ mdformat f=fld:f1 c='%Y %m %d %H:%M:%S' i=dat3.csv -A o=rsl3.csv\n\
    #END# kgdformat -A c=%Y %m %d %H:%M:%S f=fld:f1 i=dat3.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    fld,f1\n\
    2010 11 20 12:34:56,20101120123456\n\
    ,\n\
    2011 01 01 23:34:56,20110101233456\n\
    2010  1 01 123455,\n\
";

