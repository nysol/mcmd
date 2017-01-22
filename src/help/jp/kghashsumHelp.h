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
/// kghashsumHelp.h : kghashsum help
// =============================================================================
_titleL="ハッシュ法による項目値の合計";
_docL="\
\n\
MHASHSUM ハッシュ法による項目値の合計\n\
\n\
hash法を使ってk=パラメータで指定した項目を単位にして、f=パラメータで指定した項目値を合計する。\n\
msumとの違いは、キー項目の並べ替えが必要ないため、その分処理速度が速い。\n\
ただし、キーのサイズ(キー項目のとる値の種類数)が多い場合は処理速度が遅くなる。\n\
msumとmhashsumのどちらを利用するかはデータの内容からユーザーが判断する(後半に示す「ベンチマーク」参照)。\n\
\n\
書式\n\
\n\
mhashsum f= [hs=] [k=] [-n]  [i=] [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x]\n\
[-q] [tmpPath=] [precision=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=    ここで指定された項目(複数項目指定可)が合計される。\n\
        :(コロン）で新項目名を指定可能。例）f=数量:数量合計\n\
  k=    ここで指定された項目(複数項目指定可)をキーとして集計する。\n\
  hs=   ハッシュサイズ【デフォルト:199999】\n\
        処理対象データのキーサイズから，ユーザが消費メモリ量と速度を判断して指定する。指定する値としては素数がよい。\n\
        キーサイズが大きいデータに対してハッシュサイズが十分な大きさでなければ処理速度が遅くなる。\n\
        ハッシュサイズが十分に大きいと処理速度は速いが、\n\
        その分多くのメモリが必要になる(後半に示す「ベンチマーク」参照)。\n\
        必要なメモリ量の目安: K*(24+F*16) byte, K:キーのサイズ, F:f=で指定した項目数\n\
  -n    NULL値が1つでも含まれていると結果もNULL値とする。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」項目を単位にして、「数量」と「金額」項目の合計を計算する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,\n\
    B,,15\n\
    A,2,20\n\
    B,3,10\n\
    B,1,20\n\
    $ mhashsum k=顧客 f=数量,金額 i=dat1.csv o=rsl1.csv\n\
    #END# kghashsum f=数量,金額 i=dat1.csv k=顧客 o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客,数量,金額\n\
    A,3,20\n\
    B,4,45\n\
\n\
例2: NULL値出力\n\
\n\
-nオプションを指定することで、NULL値が含まれている場合は、結果もNULL値として出力する。\n\
\n\
    $ mhashsum k=顧客 f=数量,金額 -n i=dat1.csv o=rsl2.csv\n\
    #END# kghashsum -n f=数量,金額 i=dat1.csv k=顧客 o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客,数量,金額\n\
    A,3,\n\
    B,,45\n\
";

