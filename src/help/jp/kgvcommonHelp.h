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
/// kgvcommonHelp.h : kgvcommon help
// =============================================================================
_titleL="ベクトル要素の参照選択";
_docL="\
\n\
MVCOMMON ベクトル要素の参照選択\n\
\n\
ベクトルから、参照ファイルで指定された要素を選択する。\n\
\n\
書式\n\
\n\
mvcommon vf= [-A] K= [-r] m=| i= [o=] [delim=] [-assert_diffSize]\n\
[-assert_nullin] [-assert_nullout] [-nfn] [-nfno] [-x] [-q] [tmpPath=]\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  vf=   結合キーとなるアイテム集合の項目名(i=ファイル上)を指定する。\n\
        複数項目指定可能。アイテムはソーティングされている必要はない。\n\
        結果の項目名を変更したいときは、:(コロン)に続けて新項目名を指定する。\n\
        例) f=数量:置換後の項目名\n\
  -A    vf=で:(コロン)に続けて指定した項目名で、新たな項目が追加される。\n\
        なお-Aオプションを指定した場合、vf=パラメータで指定するすべての\n\
        項目に新項目名を指定しなければならない。\n\
  m=    参照ファイルを指定する。\n\
        このパラメータが省略された時には標準入力が用いられる。(i=指定ありの場合)\n\
  K=    参照ファイル(m=)上の結合キーとなるアイテムの項目名を指定する。\n\
  -r    vf=とK=の要素がマッチしない要素を選択する。\n\
\n\
利用例\n\
\n\
例1: 複数項目に対して結合する例\n\
\n\
    $ more dat1.csv\n\
    items1,items2\n\
    b a c,b b\n\
    c c,a d\n\
    e a a,a a\n\
    $ more ref1.csv\n\
    item\n\
    a\n\
    c\n\
    e\n\
    $ mvcommon vf=items1,items2 K=item m=ref1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgvcommon K=item i=dat1.csv m=ref1.csv o=rsl1.csv vf=items1,items2\n\
    $ more rsl1.csv\n\
    items1,items2\n\
    a c,\n\
    c c,a\n\
    e a a,a a\n\
\n\
例2: 項目名を変更する例\n\
\n\
item2に新項目名new2を指定しているので、 項目名が変更され出力される。\n\
\n\
    $ mvcommon vf=items1,items2:new2 K=item m=ref1.csv i=dat1.csv o=rsl2.csv\n\
    #END# kgvcommon K=item i=dat1.csv m=ref1.csv o=rsl2.csv vf=items1,items2:new2\n\
    $ more rsl2.csv\n\
    items1,new2\n\
    a c,\n\
    c c,a\n\
    e a a,a a\n\
\n\
例3: 項目を追加する例\n\
\n\
item1に新項目名new1を、 item2に新項目名new2を指定し、\n\
-Aオプションを付けているので 新項目new1とnew2が追加され出力される。\n\
\n\
    $ mvcommon vf=items1:new1,items2:new2 -A K=item m=ref1.csv i=dat1.csv o=rsl3.csv\n\
    #END# kgvcommon -A K=item i=dat1.csv m=ref1.csv o=rsl3.csv vf=items1:new1,items2:new2\n\
    $ more rsl3.csv\n\
    items1,items2,new1,new2\n\
    b a c,b b,a c,\n\
    c c,a d,c c,a\n\
    e a a,a a,e a a,a a\n\
";

