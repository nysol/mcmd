#!/bin/bash

. ../env
#name_kg_mcmd csv2arff

#NULL
${pfxc}mcsv2arff n=数量,金額 d=商品 i=./indat/dat0.csv o=./outdat/out0.csv

#sを指定
${pfxc}mcsv2arff s=顧客 i=./indat/dat1.csv o=./outdat/out1.csv
#dを指定
${pfxc}mcsv2arff d=商品 i=./indat/dat1.csv o=./outdat/out2.csv
#Dを指定
${pfxc}mcsv2arff D=日付 i=./indat/dat1.csv o=./outdat/out3.csv
#nを指定
${pfxc}mcsv2arff n=数量,金額 i=./indat/dat1.csv o=./outdat/out4.csv

#すべて指定を指定
${pfxc}mcsv2arff s=顧客 d=商品 D=日付 n=数量,金額 i=./indat/dat1.csv o=./outdat/out5.csv
#Tもしてい
${pfxc}mcsv2arff s=顧客 d=商品 D=日付 n=数量,金額 T=顧客購買データ i=./indat/dat1.csv o=./outdat/out6.csv

#Tに半角
${pfxc}mcsv2arff s=顧客 d=商品 D=日付 n=数量,金額 T='顧客 購買データ' i=./indat/dat1.csv o=./outdat/out12.csv
${pfxc}mcsv2arff s=顧客 d=商品 D=日付 n=数量,金額 T='顧客　購買データ' i=./indat/dat1.csv o=./outdat/out13.csv

#Dで%tを使用
${pfxc}mcsv2arff s=顧客 d=商品 D=日付%t n=数量,金額 T=顧客購買データ i=./indat/dat2.csv o=./outdat/out7.csv

#Dで%tとなしが混在
${pfxc}mcsv2arff s=顧客 d=商品 D=日付,日時%t n=数量,金額 T=顧客購買データ i=./indat/dat3.csv o=./outdat/out8.csv

#部分的にNULL
${pfxc}mcsv2arff s=顧客 d=商品 D=日付,日時%t n=数量,金額 T=顧客購買データ i=./indat/dat4.csv o=./outdat/out9.csv

#sを複数指定
${pfxc}mcsv2arff s=顧客,商品 D=日付 n=数量,金額 i=./indat/dat1.csv o=./outdat/out10.csv

#D指定%t指定なしで対象の日付が8桁でない
${pfxc}mcsv2arff D=日付 n=数量,金額 i=./indat/dat5.csv o=./outdat/out11.csv

#ソートデータ
${pfxc}mcsv2arff s=顧客 d=商品 D=日付 n=数量,金額 i=./indat/dat1s.csv o=./outdat/out14.csv
