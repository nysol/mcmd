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
tutorialで利用されるデータやパターン認識の分野で有名なirisデータセットなど多様なデータセットを生成する。\n\
このコマンドはパラメータの与え方が、他のコマンドと全く異なることに注意する。\n\
\n\
書式\n\
\n\
mdata データセット名/パラメータ1/パラメータ2/...\n\
\n\
パラメータ\n\
\n\
データセット名とそれに対するパラメータを“/”で区切ることで指定する。\n\
データセットの一覧と内容は表に示すとおりである。\n\
パラメータの与え方はそれぞれのデータセットによって異なり、その方法も同表に示されている。\n\
\n\
  データセット名   内容                                             パラメータ\n\
  ---------------- ------------------------------------------------ ------------------------------------------------------\n\
  iris             萼片と花びらの大きさによって、アヤメの種類の     なし\n\
                   分類モデルの構築を目的に構成されるデータセット   \n\
  man0             本マニュアルの図で使われているデータ             なし\n\
  man1             本マニュアルの図で使われているデータ             なし\n\
  tutorial_jp      チュートリアルで利用されるスーパーマーケットの   データ名を指定すると各データが標準出力に出力される。\n\
                   擬似購買データ。顧客マスターや商品マスターなど   指定しないと全てのファイルがtutorial_jp\n\
                   複数のデータファイルから構成される。             ディレクトリの下に生成される。\n\
                                                                    データ名とその内容は以下のとおり。\n\
                                                                    dat:購買データ\n\
                                                                    syo:商品マスター\n\
                                                                    cust:顧客マスター\n\
                                                                    jicfs1,jicfs2,jicfs4,jicfs6:商品分類マスター\n\
  tutorial_en      tutorial_jpデータセットの英語版                  tutorial_jpに同じ\n\
\n\
  : データセット名とその内容\n\
\n\
利用例\n\
\n\
例1 irisデータセットの出力\n\
\n\
irisデータセットを標準出力に出力する。\n\
\n\
    $ mdata iris\n\
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
    $ mdata tutorial_en\n\
    #END# mdata tutorial_en\n\
\n\
    $ ls -l tutorial_en\n\
    total 4704\n\
    -rw-r--r--  1 hamuro  staff    20673  8 22 08:14 cust.csv\n\
    -rw-r--r--  1 hamuro  staff  2281312  8 22 08:14 dat.csv\n\
    -rw-r--r--  1 hamuro  staff      128  8 22 08:14 jicfs1.csv\n\
    -rw-r--r--  1 hamuro  staff      529  8 22 08:14 jicfs2.csv\n\
    -rw-r--r--  1 hamuro  staff     6630  8 22 08:14 jicfs4.csv\n\
    -rw-r--r--  1 hamuro  staff    36400  8 22 08:14 jicfs6.csv\n\
    -rw-r--r--  1 hamuro  staff    46466  8 22 08:14 syo.csv\n\
\n\
    $ more tutorial_en/dat.csv\n\
    customer,dob,gender\n\
    00000A,19711107,female\n\
    00000B,19461025,female\n\
    00000C,19660307,female\n\
             :\n\
\n\
例3 チュートリアルデータを個別に出力\n\
\n\
商品マスターデータを標準出力に出力する。\n\
\n\
    $ mdata tutorial_en/syo\n\
    product,productName,Code1Desc,Code2Desc,Code4Desc,Code6Desc,manufacturer,brand,unitCost\n\
    0000000,Processed_Seafood_2,1,11,1197,119705,0495,049502,310\n\
    0000001,Other_Yogurt_Drink_2,1,14,1404,140497,1658,165801,215\n\
    0000002,Carbonic_Flavor_3,1,14,1403,140305,1911,191100,406\n\
                 :\n\
";

