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
/// kgselstrHelp.h : kgselstr help
// =============================================================================
_titleL="文字列による行選択";
_docL="\
\n\
MSELSTR 文字列による行選択\n\
\n\
f=で指定した項目の値が、v=で指定した文字列に一致すれば、その行を選択する。\n\
\n\
書式\n\
\n\
mselstr f= v= [k=]  [u=] [-F] [-r] [-R] [-sub] [-head] [-tail] [-W] [i=]\n\
[o=] [bufcount=] [-assert_diffSize] [-assert_nullkey] [-assert_nullin]\n\
[-nfn] [-nfno] [-x] [-q] [tmpPath=] [--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  f=      検索対象となる項目名リスト(複数項目指定可)を指定する。\n\
  v=      f=パラメータで指定した項目の値が、ここで指定した文字列リスト(複数項目指定可)の1つにマッチすれば選択される。\n\
  k=      選択する単位となるキー項目(複数項目指定可)を指定する。\n\
  o=      指定の条件に一致する行を出力するファイル名を指定する。\n\
  u=      指定の条件に一致しない行を出力するファイル名を指定する。\n\
  -F      f= パラメータで複数項目を指定した場合、その全ての値がマッチする行を撰択する。\n\
  -r      条件反転\n\
          選択ではなく削除する。\n\
  -R      k= パラメータを指定した場合、その全ての行がマッチすれば行を撰択する。\n\
  -sub    検索を完全一致ではなく部分文字列マッチで比較する。\n\
          すなわち、f=パラメータで指定した項目の値に、\n\
          v=パラメータで指定の文字列が部分文字列として含まれていればその行を撰択する。\n\
  -head   先頭文字列マッチオプション\n\
  -tail   末尾文字列マッチオプション\n\
  -W      -sub,-head,-tailオプションが指定されているときにワイド文字として部分文字列マッチをおこなう。\n\
\n\
利用例\n\
\n\
例1: 基本例\n\
\n\
「商品」項目の値がapple、orangeに完全一致する行を選択し、\n\
rsl1.csvに出力する。\n\
u=oth1.csvを指定すれば、それ以外の行はoth1.csvに出力する。\n\
pineapplejuiceは完全一致ではないので、oth1.csvに出力される。\n\
\n\
    $ more dat1.csv\n\
    商品,金額\n\
    apple,100\n\
    milk,350\n\
    orange,100\n\
    pineapplejuice,500\n\
    wine,1000\n\
    $ mselstr f=商品 v=apple,orange u=oth1.csv i=dat1.csv o=rsl1.csv\n\
    #END# kgselstr f=商品 i=dat1.csv o=rsl1.csv u=oth1.csv v=apple,orange\n\
    $ more rsl1.csv\n\
    商品,金額\n\
    apple,100\n\
    orange,100\n\
    $ more oth1.csv\n\
    商品,金額\n\
    milk,350\n\
    pineapplejuice,500\n\
    wine,1000\n\
\n\
例2: 行の削除\n\
\n\
-rオプションを指定することで、例1とは逆に、商品項目の値がapple、orangeに完全一致する行を削除し、\n\
rsl2.csvに出力する。\n\
\n\
    $ mselstr f=商品  v=apple,orange -r i=dat1.csv o=rsl2.csv\n\
    #END# kgselstr -r f=商品 i=dat1.csv o=rsl2.csv v=apple,orange\n\
    $ more rsl2.csv\n\
    商品,金額\n\
    milk,350\n\
    pineapplejuice,500\n\
    wine,1000\n\
\n\
例3: キー単位での選択\n\
\n\
orangeを購入したことのある顧客を選択する\n\
k=顧客を指定することで、orangeを購入したことのある顧客の他に購入した商品の行を含めて選択する。\n\
それ以外の行はoth2.csvに出力する。\n\
\n\
    $ more dat2.csv\n\
    顧客,商品,金額\n\
    A,apple,100\n\
    A,milk,350\n\
    B,orange,100\n\
    B,orange,100\n\
    B,pineapple,500\n\
    B,wine,1000\n\
    C,apple,100\n\
    C,orange,100\n\
    $ mselstr k=顧客 f=商品 v=orange u=oth2.csv i=dat2.csv o=rsl3.csv\n\
    #END# kgselstr f=商品 i=dat2.csv k=顧客 o=rsl3.csv u=oth2.csv v=orange\n\
    $ more rsl3.csv\n\
    顧客%0,商品,金額\n\
    B,orange,100\n\
    B,orange,100\n\
    B,pineapple,500\n\
    B,wine,1000\n\
    C,apple,100\n\
    C,orange,100\n\
    $ more oth2.csv\n\
    顧客%0,商品,金額\n\
    A,apple,100\n\
    A,milk,350\n\
\n\
例4: 部分一致\n\
\n\
「商品」項目の値がappleに部分一致するの行を選択し、 rsl4.csvに出力する。\n\
部分一致であるためpine(apple)juiceもrsl4.csvに出力される。\n\
\n\
    $ mselstr f=商品 v=apple -sub i=dat1.csv o=rsl4.csv\n\
    #END# kgselstr -sub f=商品 i=dat1.csv o=rsl4.csv v=apple\n\
    $ more rsl4.csv\n\
    商品,金額\n\
    apple,100\n\
    pineapplejuice,500\n\
\n\
例5: ワイド文字の部分一致\n\
\n\
「商品」項目の値がワイド文字の「柿」、「桃」、「葡萄」の行を選択(部分一致)\n\
選択項目にワイド文字が使用されている場合にバイト単位のマッチングを使用すると、\n\
マルチバイト文字をまたいだ文字列にマッチングする可能性がある。\n\
その為、ワイド文字が選択項目に含まれる場合は-Wオプションを使用して、\n\
ワイド文字を使用していることを意図的に示す必要がある。\n\
\n\
    $ more dat3.csv\n\
    商品,金額\n\
    果物:柿,100\n\
    果物:桃,250\n\
    果物:葡萄,300\n\
    果物:梨,450\n\
    果物:苺,500\n\
    $ mselstr f=商品 v=柿,桃,葡萄 -sub -W i=dat3.csv o=rsl5.csv\n\
    #END# kgselstr -W -sub f=商品 i=dat3.csv o=rsl5.csv v=柿,桃,葡萄\n\
    $ more rsl5.csv\n\
    商品,金額\n\
    果物:柿,100\n\
    果物:桃,250\n\
    果物:葡萄,300\n\
\n\
例6: 商品の購入日と前回の購入日が2013年の商品データを選択\n\
\n\
-Fオプションを指定することで、同じ商品を2013年内に購入したことのある(購入日と前回購入日両方が2013年)商品行を選択し、\n\
rsl6.csvに出力する。 それ以外の行はoth3.csvに出力する。\n\
\n\
    $ more dat4.csv\n\
    顧客,商品,金額,性別,購入日,前回購入日\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    C,apple,100,2,2013/02/14,NULL\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    D,orange,100,2,2011/10/28,NULL\n\
    $ mselstr f=購入日,前回購入日 -F -sub v=2013 u=oth3.csv i=dat4.csv o=rsl6.csv\n\
    #END# kgselstr -F -sub f=購入日,前回購入日 i=dat4.csv o=rsl6.csv u=oth3.csv v=2013\n\
    $ more rsl6.csv\n\
    顧客,商品,金額,性別,購入日,前回購入日\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    $ more oth3.csv\n\
    顧客,商品,金額,性別,購入日,前回購入日\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    C,apple,100,2,2013/02/14,NULL\n\
    D,orange,100,2,2011/10/28,NULL\n\
\n\
例7: 商品の購入日と前回の購入日が2013年の顧客データの抽出\n\
\n\
k=顧客を指定することで、同じ商品を2013年内に購入したことのある顧客の他に購入した商品の行を含めて選択する。\n\
それ以外の行はoth4.csvに出力する。\n\
\n\
    $ mselstr k=顧客 f=購入日,前回購入日 -F -sub v=2013 u=oth4.csv i=dat4.csv o=rsl7.csv\n\
    #END# kgselstr -F -sub f=購入日,前回購入日 i=dat4.csv k=顧客 o=rsl7.csv u=oth4.csv v=2013\n\
    $ more rsl7.csv\n\
    顧客%0,商品,金額,性別,購入日,前回購入日\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    C,apple,100,2,2013/02/14,NULL\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    $ more oth4.csv\n\
    顧客%0,商品,金額,性別,購入日,前回購入日\n\
    D,orange,100,2,2011/10/28,NULL\n\
\n\
例8: 2013年度の新規顧客情報の抽出\n\
\n\
-Rオプションを指定することで、購入日、前回購入日両方が2013年,NULL(前回購入なし)の顧客情報を抽出する。\n\
つまり2013年の新規顧客データを選択し、rsl8.csvに出力する。\n\
それ以外の行は oth5.csvに出力する。\n\
\n\
    $ mselstr k=顧客 f=購入日,前回購入日 -F -R -sub v=2013,NULL u=oth5.csv i=dat4.csv o=rsl8.csv\n\
    #END# kgselstr -F -R -sub f=購入日,前回購入日 i=dat4.csv k=顧客 o=rsl8.csv u=oth5.csv v=2013,NULL\n\
    $ more rsl8.csv\n\
    顧客%0,商品,金額,性別,購入日,前回購入日\n\
    C,apple,100,2,2013/02/14,NULL\n\
    C,orange,100,2,2013/02/14,2013/01/31\n\
    $ more oth5.csv\n\
    顧客%0,商品,金額,性別,購入日,前回購入日\n\
    A,apple,100,1,2013/01/04,2013/01/01\n\
    A,milk,350,1,2013/04/04,2011/05/06\n\
    B,orange,100,2,2012/11/11,2011/12/12\n\
    B,orange,100,2,2013/05/30,2012/11/11\n\
    B,pineapple,500,2,2013/04/15,2013/04/01\n\
    B,wine,1000,2,2012/12/24,2011/12/24\n\
    D,orange,100,2,2011/10/28,NULL\n\
";

