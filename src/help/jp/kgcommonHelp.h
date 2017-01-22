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
/// kgcommonHelp.h : kgcommon help
// =============================================================================
_titleL="参照ファイルによる行選択";
_docL="\
\n\
MCOMMON 参照ファイルによる行選択\n\
\n\
k=パラメータで指定した入力ファイルの項目値とm=パラメータで指定した参照ファイルの項目値を比較し、同じ値を持つ入力ファイルの行を選択する。\n\
\n\
書式\n\
\n\
mcommon  k= [K=] [u=] [-r] m=| i= [o=] [-assert_diffSize]\n\
[-assert_nullkey] [-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl][--version]\n\
\n\
パラメータ\n\
\n\
  k=   入力データ上の突き合わせる項目名リスト(複数項目指定可)\n\
       ここで指定した入力データの項目とK=パラメータで指定された参照データの項目が同じ行が選択される。\n\
       同じ値が複数行連続していてもよい。\n\
  m=   参照ファイル名を指定する。\n\
       またこのパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  K=   参照データ上の突き合わせる項目名リスト(複数項目指定可)\n\
       ここで指定した参照データの項目とk=パラメータで指定された入力データの項目が同じ行が選択される。\n\
       参照データ上にk=パラメータで指定した入力データ上の項目と同名の項目が存在する場合は指定する必要はない。\n\
       同じ値が複数行連続していてもよい。\n\
  u=   指定の条件に一致しない行を出力するファイル名。\n\
  -r   条件反転\n\
       k=パラメータで指定した入力ファイルの項目値と\n\
       m=パラメータで指定した参照ファイルの項目値を比較し、\n\
       同じ値を持たない入力ファイルの行を選択する。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
入力ファイルにある「顧客」項目と、参照ファイルにある「顧客」項目が同じ値を持つ入力ファイルの行を選択する。\n\
それ以外のデータはoth.csvに出力する。\n\
\n\
    $ more dat1.csv\n\
    顧客,数量\n\
    A,1\n\
    B,2\n\
    C,1\n\
    D,3\n\
    E,1\n\
    $ more ref1.csv\n\
    顧客,性別\n\
    A,女性\n\
    B,男性\n\
    E,女性\n\
    $ mcommon k=顧客 m=ref1.csv u=oth.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgcommon i=dat1.csv k=顧客 m=ref1.csv o=rsl1.csv u=oth.csv\n\
    $ more rsl1.csv\n\
    顧客%0,数量\n\
    A,1\n\
    B,2\n\
    E,1\n\
    $ more oth.csv\n\
    顧客%0,数量\n\
    C,1\n\
    D,3\n\
\n\
例2: 同じ値を持たない入力ファイルの行選択\n\
\n\
-rオプションを付けることで、条件が逆転し、参照ファイルにない「顧客」を選択することになる。\n\
\n\
    $ mcommon k=顧客 m=ref1.csv -r i=dat1.csv o=rsl2.csv\n\
    #END# kgcommon -r i=dat1.csv k=顧客 m=ref1.csv o=rsl2.csv\n\
    $ more rsl2.csv\n\
    顧客%0,数量\n\
    C,1\n\
    D,3\n\
\n\
例3: 結合キー項目名が異なる場合\n\
\n\
結合キーの項目名が異なる場合は、K=で指定する。\n\
\n\
    $ more ref2.csv\n\
    顧客ID,性別\n\
    A,女性\n\
    B,男性\n\
    E,女性\n\
    $ mcommon k=顧客 K=顧客ID i=dat1.csv m=ref2.csv o=rsl3.csv\n\
    #END# kgcommon K=顧客ID i=dat1.csv k=顧客 m=ref2.csv o=rsl3.csv\n\
    $ more rsl3.csv\n\
    顧客%0,数量\n\
    A,1\n\
    B,2\n\
    E,1\n\
\n\
例4: キー項目に重複行がある場合の例\n\
\n\
参照ファイルと入力ファイルのキー項目に重複行があっても選択可能。\n\
\n\
    $ more dat3.csv\n\
    顧客,数量\n\
    A,1\n\
    A,2\n\
    A,3\n\
    B,1\n\
    D,1\n\
    D,2\n\
    $ more ref3.csv\n\
    顧客\n\
    A\n\
    A\n\
    D\n\
    $ mcommon k=顧客 m=ref3.csv -r i=dat3.csv o=rsl4.csv\n\
    #END# kgcommon -r i=dat3.csv k=顧客 m=ref3.csv o=rsl4.csv\n\
    $ more rsl4.csv\n\
    顧客%0,数量\n\
    B,1\n\
";

