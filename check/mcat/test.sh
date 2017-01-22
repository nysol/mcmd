#!/bin/bash

. ../env

#name_kg_mcmd cat

#nuldata1つのcat
${pfxc}mcat      i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mcat -x   i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mcat -nfn i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mcat -nfno  i=./indat/dat0.csv o=./outdat/out0nfno.csv

#nuldata2つのcat
${pfxc}mcat      i=./indat/dat0.csv,./indat/dat0.csv o=./outdat/out1.csv
${pfxc}mcat -x   i=./indat/dat0.csv,./indat/dat0.csv o=./outdat/out1x.csv
${pfxc}mcat -nfn i=./indat/dat0nfn.csv,./indat/dat0nfn.csv o=./outdat/out1nfn.csv

#基本(同一項目名)
${pfxc}mcat      i=./indat/dat1.csv,./indat/dat2.csv o=./outdat/out2.csv
${pfxc}mcat -x   i=./indat/dat1.csv,./indat/dat2.csv o=./outdat/out2x.csv
${pfxc}mcat -nfn i=./indat/dat1nfn.csv,./indat/dat2nfn.csv o=./outdat/out2nfn.csv
${pfxc}mcat -nfno i=./indat/dat1.csv,./indat/dat2.csv o=./outdat/out2nfno.csv

# -add_fnameオプション
${pfxc}mcat -add_fname  i=./indat/dat1.csv,./indat/dat2.csv o=./outdat/out43.csv

#nulldataを追加
${pfxc}mcat      i=./indat/dat1.csv,./indat/dat0.csv o=./outdat/out3.csv
${pfxc}mcat -x   i=./indat/dat1.csv,./indat/dat0.csv o=./outdat/out3x.csv
${pfxc}mcat -nfn i=./indat/dat1nfn.csv,./indat/dat0nfn.csv o=./outdat/out3nfn.csv

#nulldataに追加
${pfxc}mcat      i=./indat/dat0.csv,./indat/dat1.csv o=./outdat/out4.csv
${pfxc}mcat -x   i=./indat/dat0.csv,./indat/dat1.csv o=./outdat/out4x.csv
${pfxc}mcat -nfn i=./indat/dat0nfn.csv,./indat/dat1nfn.csv o=./outdat/out4nfn.csv

# f=指定
${pfxc}mcat      f=金額,日付 i=./indat/dat1.csv,./indat/dat2.csv o=./outdat/out5.csv
${pfxc}mcat -x   f=2,1       i=./indat/dat1.csv,./indat/dat2.csv o=./outdat/out5x.csv
${pfxc}mcat -nfn f=2,1       i=./indat/dat1nfn.csv,./indat/dat2nfn.csv o=./outdat/out5nfn.csv

#項目名違い1
${pfxc}mcat      -nostop i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out6.csv
${pfxc}mcat -x   -nostop i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out6x.csv
${pfxc}mcat -nfn -nostop i=./indat/dat1nfn.csv,./indat/dat3nfn.csv o=./outdat/out6nfn.csv

#項目名違い1 -force
${pfxc}mcat      -force i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out7.csv
${pfxc}mcat -x   -force i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out7x.csv
${pfxc}mcat -nfn -force i=./indat/dat1nfn.csv,./indat/dat3nfn.csv o=./outdat/out7nfn.csv

#項目名違い1 -skip
${pfxc}mcat      -skip i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out8.csv
${pfxc}mcat -x   -skip i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out8x.csv
${pfxc}mcat -nfn -skip i=./indat/dat1nfn.csv,./indat/dat3nfn.csv o=./outdat/out8nfn.csv

#項目名違い2
${pfxc}mcat      -nostop i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out9.csv
${pfxc}mcat -x   -nostop i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out9x.csv
${pfxc}mcat -nfn -nostop i=./indat/dat1nfn.csv,./indat/dat4nfn.csv o=./outdat/out9nfn.csv

#項目名違い2 -force
${pfxc}mcat      -force i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out10.csv
${pfxc}mcat -x   -force i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out10x.csv
${pfxc}mcat -nfn -force i=./indat/dat1nfn.csv,./indat/dat4nfn.csv o=./outdat/out10nfn.csv

#項目名違い2 -skip
${pfxc}mcat      -skip i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out11.csv
${pfxc}mcat -x   -skip i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out11x.csv
${pfxc}mcat -nfn -skip i=./indat/dat1nfn.csv,./indat/dat4nfn.csv o=./outdat/out11nfn.csv

#項目足らず
${pfxc}mcat      -nostop i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out12.csv
${pfxc}mcat -x   -nostop i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out12x.csv
${pfxc}mcat -nfn -nostop i=./indat/dat1nfn.csv,./indat/dat5nfn.csv o=./outdat/out12nfn.csv

#項目足らず
${pfxc}mcat      -force i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out13.csv
${pfxc}mcat -x   -force i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out13x.csv
${pfxc}mcat -nfn -force i=./indat/dat1nfn.csv,./indat/dat5nfn.csv o=./outdat/out13nfn.csv

#項目足らず
${pfxc}mcat      -skip i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out14.csv
${pfxc}mcat -x   -skip i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out14x.csv
${pfxc}mcat -nfn -skip i=./indat/dat1nfn.csv,./indat/dat5nfn.csv o=./outdat/out14nfn.csv


#-------------------
#以下,項目指定
#項目名違い1
${pfxc}mcat      -nostop f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out15.csv
${pfxc}mcat -x   -nostop f=0,1,2          i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out15x.csv
${pfxc}mcat -nfn -nostop f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat3nfn.csv o=./outdat/out15nfn.csv

#項目名違い1 -force
${pfxc}mcat      -force f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out16.csv
${pfxc}mcat -x   -force f=0,1,2          i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out16x.csv
${pfxc}mcat -nfn -force f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat3nfn.csv o=./outdat/out16nfn.csv

#項目名違い1 -skip
${pfxc}mcat      -skip f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out17.csv
${pfxc}mcat -x   -skip f=0,1,2          i=./indat/dat1.csv,./indat/dat3.csv       o=./outdat/out17x.csv
${pfxc}mcat -nfn -skip f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat3nfn.csv o=./outdat/out17nfn.csv

#項目名違い2
${pfxc}mcat      -nostop f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out18.csv
${pfxc}mcat -x   -nostop f=0,1,2          i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out18x.csv
${pfxc}mcat -nfn -nostop f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat4nfn.csv o=./outdat/out18nfn.csv

#項目名違い2 -force
${pfxc}mcat      -force f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out19.csv
${pfxc}mcat -x   -force f=0,1,2          i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out19x.csv
${pfxc}mcat -nfn -force f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat4nfn.csv o=./outdat/out19nfn.csv

#項目名違い2 -skip
${pfxc}mcat      -skip f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out20.csv
${pfxc}mcat -x   -skip f=0,1,2          i=./indat/dat1.csv,./indat/dat4.csv       o=./outdat/out20x.csv
${pfxc}mcat -nfn -skip f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat4nfn.csv o=./outdat/out20nfn.csv

#項目足らず
${pfxc}mcat      -nostop f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out21.csv
${pfxc}mcat -x   -nostop f=0,1,2          i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out21x.csv
${pfxc}mcat -nfn -nostop f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat5nfn.csv o=./outdat/out21nfn.csv

#項目足らず
${pfxc}mcat      -force f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out22.csv
${pfxc}mcat -x   -force f=0,1,2          i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out22x.csv
${pfxc}mcat -nfn -force f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat5nfn.csv o=./outdat/out22nfn.csv

#項目足らず
${pfxc}mcat      -skip f=顧客,日付,金額 i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out23.csv
${pfxc}mcat -x   -skip f=0,1,2          i=./indat/dat1.csv,./indat/dat5.csv       o=./outdat/out23x.csv
${pfxc}mcat -nfn -skip f=0,1,2          i=./indat/dat1nfn.csv,./indat/dat5nfn.csv o=./outdat/out23nfn.csv

# ないファイル指定1
${pfxc}mcat      -skip_fnf i=./indat/dat1.csv,nothing,./indat/dat2.csv o=./outdat/out24.csv
${pfxc}mcat -x   -skip_fnf i=./indat/dat1.csv,nothing,./indat/dat2.csv o=./outdat/out24x.csv
${pfxc}mcat -nfn -skip_fnf i=./indat/dat1nfn.csv,nothing,./indat/dat2nfn.csv o=./outdat/out24nfn.csv

# ないファイル指定2
${pfxc}mcat      -skip_fnf i=nothing,./indat/dat1.csv,./indat/dat2.csv o=./outdat/out25.csv
${pfxc}mcat -x   -skip_fnf i=nothing,./indat/dat1.csv,./indat/dat2.csv o=./outdat/out25x.csv
${pfxc}mcat -nfn -skip_fnf i=nothing,./indat/dat1nfn.csv,./indat/dat2nfn.csv o=./outdat/out25nfn.csv

#ワイルドカード使用
${pfxc}mcat      i=./indat/data1-1/*.csv    o=./outdat/out26.csv
${pfxc}mcat      i=./indat/data1-*/dat1.csv o=./outdat/out27.csv
${pfxc}mcat      i=./indat/data1-*/*.csv    o=./outdat/out28.csv

#ワイルドカード使用(*)+(-c,-n)
${pfxc}mcat      -nostop i=./indat/data2/*.csv    o=./outdat/out29.csv
${pfxc}mcat      -nostop i=./indat/data*/dat3.csv o=./outdat/out30.csv
${pfxc}mcat      -nostop i=./indat/data*/*.csv    o=./outdat/out31.csv
${pfxc}mcat      -nostop i=./indat/*/*.csv        o=./outdat/out32.csv

#ワイルドカード(*)で複数
${pfxc}mcat      i=./indat/*-1/*.csv,./indat/*-2/*.csv      o=./outdat/out33.csv
${pfxc}mcat      -nostop i=./indat/data1*/*.csv,./indat/data2/*.csv o=./outdat/out34.csv

#ワイルドカード使用(?)
${pfxc}mcat      i=./indat/data1-1/dat?.csv    o=./outdat/out35.csv
${pfxc}mcat      i=./indat/data1-?/dat1.csv    o=./outdat/out36.csv
${pfxc}mcat      i=./indat/data1-?/dat?.csv    o=./outdat/out37.csv
${pfxc}mcat      i=./indat/data1-1/dat?.csv,./indat/data1-2/dat?.csv o=./outdat/out38.csv
${pfxc}mcat      -nostop i=./indat/data?/dat?.csv    o=./outdat/out39.csv

#ワイルドカード使用(*,?)
${pfxc}mcat      i=./indat/data1*/dat?.csv    o=./outdat/out40.csv
${pfxc}mcat      i=./indat/*-1/dat?.csv,./indat/*-2/dat?.csv o=./outdat/out41.csv
${pfxc}mcat      i=./indat/*-*/dat?.csv    o=./outdat/out42.csv

