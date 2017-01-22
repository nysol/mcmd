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
/// kgcutHelp.h : kgcut help
// =============================================================================
_titleL="項目の選択";
_docL="\
\n\
MCUT 項目の選択\n\
\n\
指定した項目を選択する。\n\
-rオプションを付けると、指定した項目を削除する。\n\
\n\
書式\n\
\n\
mcut f= [-r] [-nfni] [i=] [o=] [-assert_diffSize] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=      抜き出す項目名\n\
          項目名をコロンで区切ることで、出力項目名を変更することができる。\n\
          ex. f=a:A,b:B\n\
  -r      項目削除スイッチ\n\
          f=で指定した項目を削除し、それ以外の項目が抜き出される。\n\
  -nfni   入力データの１行目を項目名行とみなさない。よって項目番号で指定しなければならない。\n\
          以下のように、新項目名を組み合わせて指定することで項目名行を追加出力することが可能となる。\n\
          例）f=0:日付,2:店,3:数量\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「顧客」と「金額」項目を選択する。ただし、「金額」項目は「売上」と名前を変更して出力している。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量,金額\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mcut f=顧客,金額:売上 i=dat1.csv o=rsl1.csv\n\
    #END# kgcut f=顧客,金額:売上 i=dat1.csv o=rsl1.csv\n\
    $ more rsl1.csv\n\
    顧客,売上\n\
    A,10\n\
    A,20\n\
    B,15\n\
    B,10\n\
    B,20\n\
\n\
例2: 項目削除\n\
\n\
-rを指定することで、項目を削除できる。\n\
\n\
    $ mcut f=顧客,金額 -r i=dat1.csv o=rsl2.csv\n\
    #END# kgcut -r f=顧客,金額 i=dat1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    数量\n\
    1\n\
    2\n\
    1\n\
    3\n\
    1\n\
\n\
例3: 項目名なしデータ\n\
\n\
ヘッダなし入力ファイルから、0,2番目の項目を選択し、\n\
「顧客」と「金額」という名前で出力する。\n\
\n\
    $ more dat2.csv\n\
    A,1,10\n\
    A,2,20\n\
    B,1,15\n\
    B,3,10\n\
    B,1,20\n\
    $ mcut f=0:顧客,2:金額 -nfni i=dat2.csv o=rsl3.csv\n\
    #END# kgcut -nfni f=0:顧客,2:金額 i=dat2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客,金額\n\
    A,10\n\
    A,20\n\
    B,15\n\
    B,10\n\
    B,20\n\
";

