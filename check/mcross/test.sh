#!/bin/bash

. ../env
#name_kg_mcmd cross
#NULL
${pfxc}mcross      k=商品 s=日付 f=数量 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mcross -x   k=0    s=1    f=2    i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mcross -nfn k=0    s=1    f=2    i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量 i=./indat/dat0s.csv   o=./outdat/out0nfno.csv

#基本f=2項目
${pfxc}mcross      k=商品 s=日付 f=数量 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mcross -x   k=0    s=1    f=2    i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mcross -nfn k=0    s=1    f=2    i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量 i=./indat/dat1s.csv   o=./outdat/out1nfno.csv
${pfxc}mcross -q     k=商品 s=日付 f=数量 i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}mcross -q -nfn k=0    s=1    f=2    i=./indat/dat1snfn.csv o=./outdat/out1qnfn.csv

#基本f=2,3項目
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out2nfno.csv

#s=逆ソート f=2項目
${pfxc}mcross      k=商品 s=日付%r f=数量 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mcross -x   k=0    s=1%r    f=2    i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mcross -nfn k=0    s=1%r    f=2    i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}mcross -nfno k=商品 s=日付%r f=数量 i=./indat/dat1s.csv    o=./outdat/out3nfno.csv

#s=逆ソート f=2,3項目
${pfxc}mcross      k=商品 s=日付%r f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mcross -x   k=0    s=1%r    f=2,3       i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mcross -nfn k=0    s=1%r    f=2,3       i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv
${pfxc}mcross -nfno k=商品 s=日付%r f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out4nfno.csv

#s=数字ソート f=2項目
${pfxc}mcross      k=商品 s=日付%n f=数量 i=./indat/dat1s.csv    o=./outdat/out5.csv
${pfxc}mcross -x   k=0    s=1%n    f=2    i=./indat/dat1s.csv    o=./outdat/out5x.csv
${pfxc}mcross -nfn k=0    s=1%n    f=2    i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv

#s=数字ソート f=2,3項目
${pfxc}mcross      k=商品 s=日付%n f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out6.csv
${pfxc}mcross -x   k=0    s=1%n    f=2,3       i=./indat/dat1s.csv    o=./outdat/out6x.csv
${pfxc}mcross -nfn k=0    s=1%n    f=2,3       i=./indat/dat1snfn.csv o=./outdat/out6nfn.csv

#s=数字逆ソート f=2項目
${pfxc}mcross      k=商品 s=日付%nr f=数量 i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}mcross -x   k=0    s=1%nr    f=2    i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mcross -nfn k=0    s=1%nr    f=2    i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv

#s=数字逆ソート f=2,3項目
${pfxc}mcross      k=商品 s=日付%nr f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out8.csv
${pfxc}mcross -x   k=0    s=1%nr    f=2,3       i=./indat/dat1s.csv    o=./outdat/out8x.csv
${pfxc}mcross -nfn k=0    s=1%nr    f=2,3       i=./indat/dat1snfn.csv o=./outdat/out8nfn.csv

# f=2,3項目 a=のしてい
${pfxc}mcross      k=商品 s=日付 f=数量,金額 a=項目種別 i=./indat/dat1s.csv    o=./outdat/out9.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       a=項目種別 i=./indat/dat1s.csv    o=./outdat/out9x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3                  i=./indat/dat1snfn.csv o=./outdat/out9nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 a=項目種別 i=./indat/dat1s.csv    o=./outdat/out9nfno.csv

# k=NULLデータを含む
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat4s.csv    o=./outdat/out18.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat4s.csv    o=./outdat/out18x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat4snfn.csv o=./outdat/out18nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat4s.csv    o=./outdat/out18nfno.csv

# s=にNULL
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat5s.csv    o=./outdat/out19.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat5s.csv    o=./outdat/out19x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat5snfn.csv o=./outdat/out19nfn.csv

#f=にNULL
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat6s.csv    o=./outdat/out20.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat6s.csv    o=./outdat/out20x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat6snfn.csv o=./outdat/out20nfn.csv

#いろいろNULL
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat7s.csv    o=./outdat/out21.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat7s.csv    o=./outdat/out21x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat7snfn.csv o=./outdat/out21nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat7s.csv    o=./outdat/out21nfno.csv

#いろいろNULL v=null
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat7s.csv    o=./outdat/out30.csv v=null
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat7s.csv    o=./outdat/out30x.csv v=null
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat7snfn.csv o=./outdat/out30nfn.csv v=null
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat7s.csv    o=./outdat/out30nfno.csv v=null

#k=2つ
${pfxc}mcross      k=顧客,商品 s=日付 f=数量 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out22.csv
${pfxc}mcross -x   k=0,1       s=2    f=3    a=項目種類 i=./indat/dat8s.csv    o=./outdat/out22x.csv
${pfxc}mcross -nfn k=0,1       s=2    f=3               i=./indat/dat8snfn.csv o=./outdat/out22nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付 f=数量,金額 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out23.csv
${pfxc}mcross -x   k=0,1       s=2    f=3,4       a=項目種類 i=./indat/dat8s.csv    o=./outdat/out23x.csv
${pfxc}mcross -nfn k=0,1       s=2    f=3,4                  i=./indat/dat8snfn.csv o=./outdat/out23nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%r f=数量 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out24.csv
${pfxc}mcross -x   k=0,1       s=2%r    f=3    a=項目種類 i=./indat/dat8s.csv    o=./outdat/out24x.csv
${pfxc}mcross -nfn k=0,1       s=2%r    f=3               i=./indat/dat8snfn.csv o=./outdat/out24nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%r f=数量,金額 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out25.csv
${pfxc}mcross -x   k=0,1       s=2%r    f=3,4       a=項目種類 i=./indat/dat8s.csv    o=./outdat/out25x.csv
${pfxc}mcross -nfn k=0,1       s=2%r    f=3,4                  i=./indat/dat8snfn.csv o=./outdat/out25nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%n f=数量 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out26.csv
${pfxc}mcross -x   k=0,1       s=2%n    f=3    a=項目種類 i=./indat/dat8s.csv    o=./outdat/out26x.csv
${pfxc}mcross -nfn k=0,1       s=2%n    f=3               i=./indat/dat8snfn.csv o=./outdat/out26nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%n f=数量,金額 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out27.csv
${pfxc}mcross -x   k=0,1       s=2%n    f=3,4       a=項目種類 i=./indat/dat8s.csv    o=./outdat/out27x.csv
${pfxc}mcross -nfn k=0,1       s=2%n    f=3,4                  i=./indat/dat8snfn.csv o=./outdat/out27nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%nr f=数量 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out28.csv
${pfxc}mcross -x   k=0,1       s=2%nr    f=3    a=項目種類 i=./indat/dat8s.csv    o=./outdat/out28x.csv
${pfxc}mcross -nfn k=0,1       s=2%nr    f=3               i=./indat/dat8snfn.csv o=./outdat/out28nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%nr f=数量,金額 a=項目種類 i=./indat/dat8s.csv    o=./outdat/out29.csv
${pfxc}mcross -x   k=0,1       s=2%nr    f=3,4       a=項目種類 i=./indat/dat8s.csv    o=./outdat/out29x.csv
${pfxc}mcross -nfn k=0,1       s=2%nr    f=3,4                  i=./indat/dat8snfn.csv o=./outdat/out29nfn.csv


#k=の指定なし
${pfxc}mcross      s=日付 f=数量 a=項目種類 i=./indat/dat3.csv    o=./outdat/out10.csv
${pfxc}mcross -x   s=1    f=2    a=項目種類 i=./indat/dat3.csv    o=./outdat/out10x.csv
${pfxc}mcross -nfn s=1    f=2               i=./indat/dat3nfn.csv o=./outdat/out10nfn.csv
${pfxc}mcross -nfno s=日付 f=数量 a=項目種類 i=./indat/dat3.csv    o=./outdat/out10nfno.csv

${pfxc}mcross      s=日付 f=数量,金額 a=項目種類 i=./indat/dat3.csv    o=./outdat/out11.csv
${pfxc}mcross -x   s=1    f=2,3       a=項目種類 i=./indat/dat3.csv    o=./outdat/out11x.csv
${pfxc}mcross -nfn s=1    f=2,3                  i=./indat/dat3nfn.csv o=./outdat/out11nfn.csv

${pfxc}mcross      s=日付%r f=数量 a=項目種類 i=./indat/dat3.csv    o=./outdat/out12.csv
${pfxc}mcross -x   s=1%r    f=2    a=項目種類 i=./indat/dat3.csv    o=./outdat/out12x.csv
${pfxc}mcross -nfn s=1%r    f=2               i=./indat/dat3nfn.csv o=./outdat/out12nfn.csv

${pfxc}mcross      s=日付%r f=数量,金額 a=項目種類 i=./indat/dat3.csv    o=./outdat/out13.csv
${pfxc}mcross -x   s=1%r    f=2,3       a=項目種類 i=./indat/dat3.csv    o=./outdat/out13x.csv
${pfxc}mcross -nfn s=1%r    f=2,3                  i=./indat/dat3nfn.csv o=./outdat/out13nfn.csv

${pfxc}mcross      s=日付%n f=数量 a=項目種類 i=./indat/dat3.csv    o=./outdat/out14.csv
${pfxc}mcross -x   s=1%n    f=2    a=項目種類 i=./indat/dat3.csv    o=./outdat/out14x.csv
${pfxc}mcross -nfn s=1%n    f=2               i=./indat/dat3nfn.csv o=./outdat/out14nfn.csv

${pfxc}mcross      s=日付%n f=数量,金額 a=項目種類 i=./indat/dat3.csv    o=./outdat/out15.csv
${pfxc}mcross -x   s=1%n    f=2,3       a=項目種類 i=./indat/dat3.csv    o=./outdat/out15x.csv
${pfxc}mcross -nfn s=1%n    f=2,3                  i=./indat/dat3nfn.csv o=./outdat/out15nfn.csv

${pfxc}mcross      s=日付%nr f=数量 a=項目種類 i=./indat/dat3.csv    o=./outdat/out16.csv
${pfxc}mcross -x   s=1%nr    f=2    a=項目種類 i=./indat/dat3.csv    o=./outdat/out16x.csv
${pfxc}mcross -nfn s=1%nr    f=2               i=./indat/dat3nfn.csv o=./outdat/out16nfn.csv

${pfxc}mcross      s=日付%nr f=数量,金額 a=項目種類 i=./indat/dat3.csv    o=./outdat/out17.csv
${pfxc}mcross -x   s=1%nr    f=2,3       a=項目種類 i=./indat/dat3.csv    o=./outdat/out17x.csv
${pfxc}mcross -nfn s=1%nr    f=2,3                  i=./indat/dat3nfn.csv o=./outdat/out17nfn.csv



#ランダムデータ
#NULL
${pfxc}mcross      k=商品 s=日付 f=数量 i=./indat/dat0.csv    o=./outdat/out31.csv
${pfxc}mcross -x   k=0    s=1    f=2    i=./indat/dat0.csv    o=./outdat/out31x.csv
${pfxc}mcross -nfn k=0    s=1    f=2    i=./indat/dat0nfn.csv o=./outdat/out31nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量 i=./indat/dat0.csv   o=./outdat/out31nfno.csv

#基本f=2項目
${pfxc}mcross      k=商品 s=日付 f=数量 i=./indat/dat1.csv    o=./outdat/out32.csv
${pfxc}mcross -x   k=0    s=1    f=2    i=./indat/dat1.csv    o=./outdat/out32x.csv
${pfxc}mcross -nfn k=0    s=1    f=2    i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量 i=./indat/dat1.csv   o=./outdat/out32nfno.csv
${pfxc}mcross -q     k=商品 s=日付 f=数量 i=./indat/dat1.csv    o=./outdat/out32q.csv
${pfxc}mcross -q -nfn k=0    s=1    f=2    i=./indat/dat1nfn.csv o=./outdat/out32qnfn.csv

#基本f=2,3項目
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out33.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat1.csv    o=./outdat/out33x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat1nfn.csv o=./outdat/out33nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out33nfno.csv

#s=逆ソート f=2項目
${pfxc}mcross      k=商品 s=日付%r f=数量 i=./indat/dat1.csv    o=./outdat/out34.csv
${pfxc}mcross -x   k=0    s=1%r    f=2    i=./indat/dat1.csv    o=./outdat/out34x.csv
${pfxc}mcross -nfn k=0    s=1%r    f=2    i=./indat/dat1nfn.csv o=./outdat/out34nfn.csv
${pfxc}mcross -nfno k=商品 s=日付%r f=数量 i=./indat/dat1.csv    o=./outdat/out34nfno.csv

#s=逆ソート f=2,3項目
${pfxc}mcross      k=商品 s=日付%r f=数量,金額 i=./indat/dat1.csv    o=./outdat/out35.csv
${pfxc}mcross -x   k=0    s=1%r    f=2,3       i=./indat/dat1.csv    o=./outdat/out35x.csv
${pfxc}mcross -nfn k=0    s=1%r    f=2,3       i=./indat/dat1nfn.csv o=./outdat/out35nfn.csv
${pfxc}mcross -nfno k=商品 s=日付%r f=数量,金額 i=./indat/dat1.csv    o=./outdat/out35nfno.csv

#s=数字ソート f=2項目
${pfxc}mcross      k=商品 s=日付%n f=数量 i=./indat/dat1.csv    o=./outdat/out36.csv
${pfxc}mcross -x   k=0    s=1%n    f=2    i=./indat/dat1.csv    o=./outdat/out36x.csv
${pfxc}mcross -nfn k=0    s=1%n    f=2    i=./indat/dat1nfn.csv o=./outdat/out36nfn.csv

#s=数字ソート f=2,3項目
${pfxc}mcross      k=商品 s=日付%n f=数量,金額 i=./indat/dat1.csv    o=./outdat/out37.csv
${pfxc}mcross -x   k=0    s=1%n    f=2,3       i=./indat/dat1.csv    o=./outdat/out37x.csv
${pfxc}mcross -nfn k=0    s=1%n    f=2,3       i=./indat/dat1nfn.csv o=./outdat/out37nfn.csv

#s=数字逆ソート f=2項目
${pfxc}mcross      k=商品 s=日付%nr f=数量 i=./indat/dat1.csv    o=./outdat/out38.csv
${pfxc}mcross -x   k=0    s=1%nr    f=2    i=./indat/dat1.csv    o=./outdat/out38x.csv
${pfxc}mcross -nfn k=0    s=1%nr    f=2    i=./indat/dat1nfn.csv o=./outdat/out38nfn.csv

#s=数字逆ソート f=2,3項目
${pfxc}mcross      k=商品 s=日付%nr f=数量,金額 i=./indat/dat1.csv    o=./outdat/out39.csv
${pfxc}mcross -x   k=0    s=1%nr    f=2,3       i=./indat/dat1.csv    o=./outdat/out39x.csv
${pfxc}mcross -nfn k=0    s=1%nr    f=2,3       i=./indat/dat1nfn.csv o=./outdat/out39nfn.csv

# f=2,3項目 a=のしてい
${pfxc}mcross      k=商品 s=日付 f=数量,金額 a=項目種別 i=./indat/dat1.csv    o=./outdat/out40.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       a=項目種別 i=./indat/dat1.csv    o=./outdat/out40x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3                  i=./indat/dat1nfn.csv o=./outdat/out40nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 a=項目種別 i=./indat/dat1.csv    o=./outdat/out40nfno.csv



# k=NULLデータを含む
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat4.csv    o=./outdat/out42.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat4.csv    o=./outdat/out42x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat4nfn.csv o=./outdat/out42nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat4.csv    o=./outdat/out42nfno.csv

# s=にNULL
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat5.csv    o=./outdat/out43.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat5.csv    o=./outdat/out43x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat5nfn.csv o=./outdat/out43nfn.csv

#f=にNULL
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat6.csv    o=./outdat/out44.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat6.csv    o=./outdat/out44x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat6nfn.csv o=./outdat/out44nfn.csv

#いろいろNULL
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat7.csv    o=./outdat/out45.csv
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat7.csv    o=./outdat/out45x.csv
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat7nfn.csv o=./outdat/out45nfn.csv
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat7.csv    o=./outdat/out45nfno.csv

#いろいろNULL v=null
${pfxc}mcross      k=商品 s=日付 f=数量,金額 i=./indat/dat7.csv    o=./outdat/out46.csv v=null
${pfxc}mcross -x   k=0    s=1    f=2,3       i=./indat/dat7.csv    o=./outdat/out46x.csv v=null
${pfxc}mcross -nfn k=0    s=1    f=2,3       i=./indat/dat7nfn.csv o=./outdat/out46nfn.csv v=null
${pfxc}mcross -nfno k=商品 s=日付 f=数量,金額 i=./indat/dat7.csv    o=./outdat/out46nfno.csv v=null

#k=2つ
${pfxc}mcross      k=顧客,商品 s=日付 f=数量 a=項目種類 i=./indat/dat8.csv    o=./outdat/out47.csv
${pfxc}mcross -x   k=0,1       s=2    f=3    a=項目種類 i=./indat/dat8.csv    o=./outdat/out47x.csv
${pfxc}mcross -nfn k=0,1       s=2    f=3               i=./indat/dat8nfn.csv o=./outdat/out47nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付 f=数量,金額 a=項目種類 i=./indat/dat8.csv    o=./outdat/out48.csv
${pfxc}mcross -x   k=0,1       s=2    f=3,4       a=項目種類 i=./indat/dat8.csv    o=./outdat/out48x.csv
${pfxc}mcross -nfn k=0,1       s=2    f=3,4                  i=./indat/dat8nfn.csv o=./outdat/out48nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%r f=数量 a=項目種類 i=./indat/dat8.csv    o=./outdat/out49.csv
${pfxc}mcross -x   k=0,1       s=2%r    f=3    a=項目種類 i=./indat/dat8.csv    o=./outdat/out49x.csv
${pfxc}mcross -nfn k=0,1       s=2%r    f=3               i=./indat/dat8nfn.csv o=./outdat/out49nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%r f=数量,金額 a=項目種類 i=./indat/dat8.csv    o=./outdat/out50.csv
${pfxc}mcross -x   k=0,1       s=2%r    f=3,4       a=項目種類 i=./indat/dat8.csv    o=./outdat/out50x.csv
${pfxc}mcross -nfn k=0,1       s=2%r    f=3,4                  i=./indat/dat8nfn.csv o=./outdat/out50nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%n f=数量 a=項目種類 i=./indat/dat8.csv    o=./outdat/out51.csv
${pfxc}mcross -x   k=0,1       s=2%n    f=3    a=項目種類 i=./indat/dat8.csv    o=./outdat/out51x.csv
${pfxc}mcross -nfn k=0,1       s=2%n    f=3               i=./indat/dat8nfn.csv o=./outdat/out51nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%n f=数量,金額 a=項目種類 i=./indat/dat8.csv    o=./outdat/out52.csv
${pfxc}mcross -x   k=0,1       s=2%n    f=3,4       a=項目種類 i=./indat/dat8.csv    o=./outdat/out52x.csv
${pfxc}mcross -nfn k=0,1       s=2%n    f=3,4                  i=./indat/dat8nfn.csv o=./outdat/out52nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%nr f=数量 a=項目種類 i=./indat/dat8.csv    o=./outdat/out53.csv
${pfxc}mcross -x   k=0,1       s=2%nr    f=3    a=項目種類 i=./indat/dat8.csv    o=./outdat/out53x.csv
${pfxc}mcross -nfn k=0,1       s=2%nr    f=3               i=./indat/dat8nfn.csv o=./outdat/out53nfn.csv

${pfxc}mcross      k=顧客,商品 s=日付%nr f=数量,金額 a=項目種類 i=./indat/dat8.csv    o=./outdat/out54.csv
${pfxc}mcross -x   k=0,1       s=2%nr    f=3,4       a=項目種類 i=./indat/dat8.csv    o=./outdat/out54x.csv
${pfxc}mcross -nfn k=0,1       s=2%nr    f=3,4                  i=./indat/dat8nfn.csv o=./outdat/out54nfn.csv


