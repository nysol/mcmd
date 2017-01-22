#!/bin/bash

. ../env

#name_kg_mcmd combi

#NULL
${pfxc}mcombi      k=顧客 s=商品 f=商品  n=2 a=商品1,商品2 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mcombi -x   k=0   s=1    f=1    n=2 a=商品1,商品2 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mcombi -nfn k=0   s=1    f=1    n=2              i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#基本
${pfxc}mcombi         k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mcombi -x      k=0   s=1    f=1   n=2 a=商品1,商品2 i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mcombi -nfn    k=0   s=1    f=1   n=2              i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mcombi -q      k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}mcombi -q -nfn k=0   s=1    f=1   n=2              i=./indat/dat1snfn.csv o=./outdat/out1qnfn.csv

${pfxc}mcombi         k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 -p i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mcombi -x      k=0   s=1    f=1   n=2 a=商品1,商品2 -p i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mcombi -nfn    k=0   s=1    f=1   n=2              -p i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mcombi -q      k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 -p i=./indat/dat1s.csv    o=./outdat/out2q.csv
${pfxc}mcombi -q -nfn k=0   s=1    f=1   n=2              -p i=./indat/dat1snfn.csv o=./outdat/out2qnfn.csv

# kなし
${pfxc}mcombi         f=商品 s=商品 n=2 a=商品1,商品2 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mcombi -x      f=1   s=1    n=2 a=商品1,商品2 i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mcombi -nfn    f=1   s=1    n=2              i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}mcombi -q      f=商品 s=商品 n=2 a=商品1,商品2 i=./indat/dat1s.csv    o=./outdat/out3q.csv
${pfxc}mcombi -q -nfn f=1   s=1    n=2              i=./indat/dat1snfn.csv o=./outdat/out3qnfn.csv

${pfxc}mcombi         f=商品 s=商品 n=2 a=商品1,商品2 -p i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mcombi -x      f=1   s=1    n=2 a=商品1,商品2 -p i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mcombi -nfn    f=1   s=1    n=2              -p i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv
${pfxc}mcombi -q      f=商品 s=商品 n=2 a=商品1,商品2 -p i=./indat/dat1s.csv    o=./outdat/out4q.csv
${pfxc}mcombi -q -nfn f=1   s=1    n=2              -p i=./indat/dat1snfn.csv o=./outdat/out4qnfn.csv

# k２つ
${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3  i=./indat/dat2s.csv    o=./outdat/out5.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2    n=3 a=商品1,商品2,商品3 i=./indat/dat2s.csv    o=./outdat/out5x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2    n=3                   i=./indat/dat2snfn.csv o=./outdat/out5nfn.csv

${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 -p i=./indat/dat2s.csv    o=./outdat/out6.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2    n=3 a=商品1,商品2,商品3 -p i=./indat/dat2s.csv    o=./outdat/out6x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2    n=3                   -p i=./indat/dat2snfn.csv o=./outdat/out6nfn.csv

#組み合わせが少ない
${pfxc}mcombi      k=顧客 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}mcombi -x   k=0   s=1    f=1   n=3 a=商品1,商品2,商品3 i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mcombi -nfn k=0   s=1    f=1   n=3                   i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv

${pfxc}mcombi      k=顧客 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat1s.csv    -p o=./outdat/out8.csv
${pfxc}mcombi -x   k=0   s=1    f=1   n=3 a=商品1,商品2,商品3 i=./indat/dat1s.csv    -p o=./outdat/out8x.csv
${pfxc}mcombi -nfn k=0   s=1    f=1   n=3                   i=./indat/dat1snfn.csv -p o=./outdat/out8nfn.csv

#f=にNULL
${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat3s.csv    o=./outdat/out9.csv
${pfxc}mcombi -x   k=0,1     s=2    f=2   n=3  a=商品1,商品2,商品3 i=./indat/dat3s.csv    o=./outdat/out9x.csv
${pfxc}mcombi -nfn k=0,1     s=2    f=2   n=3                    i=./indat/dat3snfn.csv o=./outdat/out9nfn.csv

${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat3s.csv    -p o=./outdat/out10.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2   n=3 a=商品1,商品2,商品3 i=./indat/dat3s.csv    -p o=./outdat/out10x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2   n=3                   i=./indat/dat3snfn.csv -p o=./outdat/out10nfn.csv

#k=にもNULL
${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat4s.csv    o=./outdat/out11.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2   n=3 a=商品1,商品2,商品3 i=./indat/dat4s.csv    o=./outdat/out11x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2   n=3                   i=./indat/dat4snfn.csv o=./outdat/out11nfn.csv

${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat4s.csv    -p o=./outdat/out12.csv
${pfxc}mcombi -x   k=0,1     s=2    f=2    n=3 a=商品1,商品2,商品3 i=./indat/dat4s.csv    -p o=./outdat/out12x.csv
${pfxc}mcombi -nfn k=0,1     s=2    f=2    n=3                   i=./indat/dat4snfn.csv -p o=./outdat/out12nfn.csv


#ランダムデータ
#基本
${pfxc}mcombi         k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 i=./indat/dat1.csv    o=./outdat/out13.csv
${pfxc}mcombi -x      k=0   s=1    f=1   n=2 a=商品1,商品2 i=./indat/dat1.csv    o=./outdat/out13x.csv
${pfxc}mcombi -nfn    k=0   s=1    f=1   n=2              i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv
${pfxc}mcombi -q      k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 i=./indat/dat1.csv    o=./outdat/out13q.csv
${pfxc}mcombi -q -nfn k=0   s=1    f=1   n=2              i=./indat/dat1nfn.csv o=./outdat/out13qnfn.csv

${pfxc}mcombi         k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 -p i=./indat/dat1.csv    o=./outdat/out14.csv
${pfxc}mcombi -x      k=0   s=1    f=1   n=2 a=商品1,商品2 -p i=./indat/dat1.csv    o=./outdat/out14x.csv
${pfxc}mcombi -nfn    k=0   s=1    f=1   n=2              -p i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv
${pfxc}mcombi -q      k=顧客 s=商品 f=商品 n=2 a=商品1,商品2 -p i=./indat/dat1.csv    o=./outdat/out14q.csv
${pfxc}mcombi -q -nfn k=0   s=1    f=1   n=2              -p i=./indat/dat1nfn.csv o=./outdat/out14qnfn.csv

# kなし
${pfxc}mcombi         f=商品 s=商品 n=2 a=商品1,商品2 i=./indat/dat1.csv    o=./outdat/out15.csv
${pfxc}mcombi -x      f=1   s=1    n=2 a=商品1,商品2 i=./indat/dat1.csv    o=./outdat/out15x.csv
${pfxc}mcombi -nfn    f=1   s=1    n=2              i=./indat/dat1nfn.csv o=./outdat/out15nfn.csv
${pfxc}mcombi -q      f=商品 s=商品 n=2 a=商品1,商品2 i=./indat/dat1.csv    o=./outdat/out15q.csv
${pfxc}mcombi -q -nfn f=1   s=1    n=2              i=./indat/dat1nfn.csv o=./outdat/out15qnfn.csv

${pfxc}mcombi         f=商品 s=商品 n=2 a=商品1,商品2 -p i=./indat/dat1.csv    o=./outdat/out16.csv
${pfxc}mcombi -x      f=1   s=1    n=2 a=商品1,商品2 -p i=./indat/dat1.csv    o=./outdat/out16x.csv
${pfxc}mcombi -nfn    f=1   s=1    n=2              -p i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv
${pfxc}mcombi -q      f=商品 s=商品 n=2 a=商品1,商品2 -p i=./indat/dat1.csv    o=./outdat/out16q.csv
${pfxc}mcombi -q -nfn f=1   s=1    n=2              -p i=./indat/dat1nfn.csv o=./outdat/out16qnfn.csv

# k２つ
${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3  i=./indat/dat2.csv    o=./outdat/out17.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2    n=3 a=商品1,商品2,商品3 i=./indat/dat2.csv    o=./outdat/out17x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2    n=3                   i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv

${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 -p i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2    n=3 a=商品1,商品2,商品3 -p i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2    n=3                   -p i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv

#組み合わせが少ない
${pfxc}mcombi      k=顧客 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat1.csv    o=./outdat/out19.csv
${pfxc}mcombi -x   k=0   s=1    f=1   n=3 a=商品1,商品2,商品3 i=./indat/dat1.csv    o=./outdat/out19x.csv
${pfxc}mcombi -nfn k=0   s=1    f=1   n=3                   i=./indat/dat1nfn.csv o=./outdat/out19nfn.csv

${pfxc}mcombi      k=顧客 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat1.csv    -p o=./outdat/out20.csv
${pfxc}mcombi -x   k=0   s=1    f=1   n=3 a=商品1,商品2,商品3 i=./indat/dat1.csv    -p o=./outdat/out20x.csv
${pfxc}mcombi -nfn k=0   s=1    f=1   n=3                   i=./indat/dat1nfn.csv -p o=./outdat/out20nfn.csv

#f=にNULL
${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat3.csv    o=./outdat/out21.csv
${pfxc}mcombi -x   k=0,1     s=2    f=2   n=3  a=商品1,商品2,商品3 i=./indat/dat3.csv    o=./outdat/out21x.csv
${pfxc}mcombi -nfn k=0,1     s=2    f=2   n=3                    i=./indat/dat3nfn.csv o=./outdat/out21nfn.csv

${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat3.csv    -p o=./outdat/out22.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2   n=3 a=商品1,商品2,商品3 i=./indat/dat3.csv    -p o=./outdat/out22x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2   n=3                   i=./indat/dat3nfn.csv -p o=./outdat/out22nfn.csv

#k=にもNULL
${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat4.csv    o=./outdat/out23.csv
${pfxc}mcombi -x   k=0,1      s=2   f=2   n=3 a=商品1,商品2,商品3 i=./indat/dat4.csv    o=./outdat/out23x.csv
${pfxc}mcombi -nfn k=0,1      s=2   f=2   n=3                   i=./indat/dat4nfn.csv o=./outdat/out23nfn.csv

${pfxc}mcombi      k=顧客,日付 s=商品 f=商品 n=3 a=商品1,商品2,商品3 i=./indat/dat4.csv    -p o=./outdat/out24.csv
${pfxc}mcombi -x   k=0,1     s=2    f=2    n=3 a=商品1,商品2,商品3 i=./indat/dat4.csv    -p o=./outdat/out24x.csv
${pfxc}mcombi -nfn k=0,1     s=2    f=2    n=3                   i=./indat/dat4nfn.csv -p o=./outdat/out24nfn.csv

