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
/// kgkeybreakHelp.h : kgkeybreak help
// =============================================================================
_titleL="キーブレイク箇所";
_docL="\
\n\
MKEYBREAK キーブレイク箇所\n\
\n\
k=パラメータで指定した項目をキー項目について、先頭と終端に印を付ける。\n\
先頭はtop項目に、終端はbot項目に1を出力する。\n\
先頭/終端でない行はNULL値を出力する。\n\
\n\
書式\n\
\n\
mkeybreak k= [s=] [a=] [i=] [o=] [-assert_diffSize] [-assert_nullkey]\n\
[-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  k=   集計キーとなる項目名リスト（複数項目指定可）を指定する。\n\
  s=   ここで指定した項目(複数項目指定可)で並べ替えた後、先頭・終端に印を付ける。\n\
  a=   先頭と終端の印を出力する項目名を指定する。【デフォルト値:top,bot】\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
k1項目で並べ替えた後、k1キー項目の先頭(top項目)と終端(bottom項目)に印(1)をつける。\n\
\n\
    $ more dat1.csv\n\
    id,k1,k2,val\n\
    1,A,a,1\n\
    2,A,b,2\n\
    3,A,b,3\n\
    4,B,a,4\n\
    5,B,a,5\n\
    $ mkeybreak k=k1 i=dat1.csv o=rsl1.csv\n\
    #END# kgkeybreak i=dat1.csv k=k1 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    id,k1%0,k2,val,top,bot\n\
    1,A,a,1,1,\n\
    2,A,b,2,,\n\
    3,A,b,3,,1\n\
    4,B,a,4,1,\n\
    5,B,a,5,,1\n\
\n\
例2: 2項目キー\n\
\n\
k1・k2項目で並べ替えた後、k1キー項目の先頭(top項目)と終端(bottom項目)に印(1)をつける。\n\
\n\
    $ mkeybreak s=k1,k2 k=k1 i=dat1.csv o=rsl2.csv\n\
    #END# kgkeybreak i=dat1.csv k=k1 o=rsl2.csv s=k1,k2\n\
    $ more rsl2.csv\n\
    id,k1,k2,val,top,bot\n\
    1,A,a,1,1,\n\
    2,A,b,2,,\n\
    3,A,b,3,,1\n\
    4,B,a,4,1,\n\
    5,B,a,5,,1\n\
";

