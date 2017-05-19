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
/// kgdataHelp.h : kgdata help
// =============================================================================
_titleL="データセットの出力";
_docL="\
\n\
MDATA データセットの出力\n\
\n\
様々なデータセットを生成する。データセットの詳細は以下を参照のこと。\n\
\n\
書式\n\
\n\
mdata [O=] -iris|-man0|-man1|-tutorial_en|-tutorial_jp|-yakiniku_en|-yakiniku_jp\n\
[--help] [--helpl] [--version]\n\
\n\
パラメータ\n\
\n\
  O=            出力ファイル名。省略時は標準出力に出力される。\n\
                -tutorial_jpもしくは-tutorial_enが指定された場合はディレクトリ名となり、\n\
                省略した場合は、O=tutorial_jpもしくはO=tutorial_enが指定されたことになる。\n\
  -iris         萼片と花びらの大きさによって、アヤメの種類の分類モデルの構築を目的に構成されるデータセット\n\
                項目名:SepalLength,SepalWidth,PetalLength,PetalWidth,Species(ガク長,ガク幅,花びら長,花びら幅,種)\n\
                http://archive.ics.uci.edu/ml/datasets/Iris?ref=datanews.io\n\
  man0          本マニュアルの図で使われている5行データ\n\
                項目名: 顧客,金額\n\
  man1          本マニュアルの図で使われている8行データ\n\
                項目名: 顧客,日付,商品\n\
  yakiniku_jp   焼肉店の販売データ(http://okayamafs.com/より提供された焼肉店 https://r.gnavi.co.jp/c032802/の販売データ)。\n\
                項目名: 日付,時間,レシート,商品,単価,数量,金額\n\
                注1) 時間は注文時刻で、同じレシート内でも追加注文時はその時の時刻が記録されている。\n\
                注2) 金額=単価×数量\n\
  yakiniku_en   焼肉店の注文データの英語版\n\
                項目名: date,time,receipt,item,price,quantity,totalAmount\n\
  tutorial_jp   チュートリアルで利用されるスーパーマーケットの擬似購買データ。\n\
                dat.csv: 購買履歴データ\n\
                項目名:店,日付,時間,レシート,顧客,商品,大分類,中分類,小分類,細分類,メーカー,ブランド,\n\
                仕入単価,単価,数量,金額,仕入金額,粗利金額\n\
                syo.csv: 商品マスター\n\
                項目名: 商品,商品名,大分類,中分類,小分類,細分類,メーカー,ブランド,仕入単価\n\
                cust.csv: 顧客マスター\n\
                項目名: 顧客,生年月日,性別\n\
                jicfs1,2,4,6.csv: 商品分類マスター\n\
                項目名: 大分類,大分類名(中分類,中分類名)(小分類,小分類名)(細分類,細分類名)\n\
  tutorial_en   tutorial_jpデータセットの英語版\n\
                dat.csv: 購買履歴データ\n\
                項目名:shop,date,time,receipt,customer,product,CategoryCode1,CategoryCode2,CategoryCode4,\n\
                CategoryCode6,manufacturer,brand,unitCost,unitPrice,quantity,amount,costAmount,profit\n\
                syo.csv: 商品マスター\n\
                項目名: product,productName,CategoryCode1,CategoryCode2,CategoryCode4,CategoryCode6,\n\
                manufacturer,brand,unitCost\n\
                cust.csv: 顧客マスター\n\
                項目名: customer,dob,gender\n\
                jicfs1,2,4,6.csv: 商品分類マスター\n\
                項目名: CategoryCode1,Category1(CategoryCode2,Category2)(CategoryCode4,Category4)\n\
                (CategoryCode6,Category6)\n\
\n\
利用例\n\
\n\
例1 irisデータセットの出力\n\
\n\
irisデータセットを標準出力に出力する。\n\
\n\
    $ mdata -iris\n\
    SepalLength,SepalWidth,PetalLength,PetalWidth,Species\n\
    5.1,3.5,1.4,0.2,setosa\n\
    4.9,3,1.4,0.2,setosa\n\
    4.7,3.2,1.3,0.2,setosa\n\
    4.6,3.1,1.5,0.2,setosa\n\
             :\n\
\n\
例2 チュートリアルデータセットの出力\n\
\n\
チュートリアルデータセットを全てファイル出力する。\n\
\n\
    $ mdata -tutorial_en\n\
    #END# mdata -tutorial_en\n\
\n\
    $ ls -l tutorial_en\n\
    total 4704\n\
    -rw-r--r--  1 nysol  staff    20673  8 22 08:14 cust.csv\n\
    -rw-r--r--  1 nysol  staff  2281312  8 22 08:14 dat.csv\n\
    -rw-r--r--  1 nysol  staff      128  8 22 08:14 jicfs1.csv\n\
    -rw-r--r--  1 nysol  staff      529  8 22 08:14 jicfs2.csv\n\
    -rw-r--r--  1 nysol  staff     6630  8 22 08:14 jicfs4.csv\n\
    -rw-r--r--  1 nysol  staff    36400  8 22 08:14 jicfs6.csv\n\
    -rw-r--r--  1 nysol  staff    46466  8 22 08:14 syo.csv\n\
\n\
    $ more tutorial_en/dat.csv\n\
    customer,dob,gender\n\
    00000A,19711107,female\n\
    00000B,19461025,female\n\
    00000C,19660307,female\n\
             :\n\
\n\
例3 焼肉データを出力\n\
\n\
    $ mdata -yakiniku_jp\n\
    日付,時間,レシート,商品,単価,数量,金額\n\
    20070701,1123,10000,焼肉ヘルシーセット,1410,1,1410\n\
    20070701,1152,10001,和牛焼肉弁当,1240,1,1240\n\
    20070701,1202,10002,ランチコーヒー,130,2,260\n\
                 :\n\
    $ mdata -yakiniku_en\n\
    date,time,receipt,item,price,quantity,totalAmount\n\
    20070701,1123,10000,Low-fat BBQ set,1410,1,1410\n\
    20070701,1152,10001,Japanese grilled beef lunch box,1240,1,1240\n\
    20070701,1202,10002,Lunchtime coffee,130,2,260\n\
             :\n\
";

