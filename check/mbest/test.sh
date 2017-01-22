#!/bin/bash

. ../env
#name_kg_mcmd best

#nullデータ
${pfxc}mbest          s=金額 R=1_3 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mbest -x       s=2   R=1_3 i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mbest -nfn     s=2   R=1_3 i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mbest -nfno    s=金額 R=1_3 i=./indat/dat0s.csv    o=./outdat/out0nfno.csv
${pfxc}mbest -q       s=金額 R=1_3 i=./indat/dat0s.csv    o=./outdat/out0q.csv
${pfxc}mbest -q -nfn  s=2   R=1_3 i=./indat/dat0snfn.csv o=./outdat/out0qnfn.csv

#基本
${pfxc}mbest          s=金額%nr R=1_3  i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mbest -x       s=2%nr   R=1_3  i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mbest -nfn     s=2%nr   R=1_3  i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mbest -nfno    s=金額%nr  R=1_3 i=./indat/dat1s.csv    o=./outdat/out1nfno.csv
${pfxc}mbest -q       s=金額%nr R=1_3  i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}mbest -q -nfn  s=2%nr   R=1_3  i=./indat/dat1snfn.csv o=./outdat/out1qnfn.csv

#複数指定
${pfxc}mbest         s=金額%nr R=1_2,4_5 i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mbest -x      s=2%nr   R=1_2,4_5 i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mbest -nfn    s=2%nr   R=1_2,4_5 i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mbest -q      s=金額%nr R=1_2,4_5 i=./indat/dat1s.csv    o=./outdat/out2q.csv
${pfxc}mbest -q -nfn s=2%nr   R=1_2,4_5 i=./indat/dat1snfn.csv o=./outdat/out2qnfn.csv

#MIN使用
${pfxc}mbest      s=金額%nr R=MIN_2 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mbest -x   s=2%nr   R=MIN_2 i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mbest -nfn s=2%nr   R=MIN_2 i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv

#MAX使用
${pfxc}mbest      s=金額%nr R=4_MAX i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mbest -x   s=2%nr   R=4_MAX i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mbest -nfn s=2%nr   R=4_MAX i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv

#MIN,MAX使用
${pfxc}mbest      s=金額%nr R=MIN_2,4_MAX i=./indat/dat1s.csv    o=./outdat/out5.csv
${pfxc}mbest -x   s=2%nr   R=MIN_2,4_MAX i=./indat/dat1s.csv    o=./outdat/out5x.csv
${pfxc}mbest -nfn s=2%nr   R=MIN_2,4_MAX i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv

#u=使用
${pfxc}mbest      s=金額%nr R=2 i=./indat/dat1s.csv    u=./outdat/out7.csv    o=./outdat/out6.csv
${pfxc}mbest -x   s=2%nr   R=2 i=./indat/dat1s.csv    u=./outdat/out7x.csv    o=./outdat/out6x.csv
${pfxc}mbest -nfn s=2%nr   R=2 i=./indat/dat1snfn.csv u=./outdat/out7nfn.csv o=./outdat/out6nfn.csv

#-r使用
${pfxc}mbest      s=金額%nr R=2 i=./indat/dat1s.csv    -r o=./outdat/out8.csv
${pfxc}mbest -x   s=2%nr   R=2 i=./indat/dat1s.csv    -r o=./outdat/out8x.csv
${pfxc}mbest -nfn s=2%nr   R=2 i=./indat/dat1snfn.csv -r o=./outdat/out8nfn.csv

#-r,u=使用
${pfxc}mbest      s=金額%nr R=2 i=./indat/dat1s.csv    u=./outdat/out10.csv    -r o=./outdat/out9.csv
${pfxc}mbest -x   s=2%nr   R=2 i=./indat/dat1s.csv    u=./outdat/out10x.csv   -r o=./outdat/out9x.csv
${pfxc}mbest -nfn s=2%nr   R=2 i=./indat/dat1snfn.csv u=./outdat/out10nfn.csv -r o=./outdat/out9nfn.csv

#k=使用
${pfxc}mbest      k=顧客 s=日付 R=2 i=./indat/dat2s.csv    o=./outdat/out11.csv
${pfxc}mbest -x   k=0   s=1　  R=2 i=./indat/dat2s.csv    o=./outdat/out11x.csv
${pfxc}mbest -nfn k=0   s=1    R=2 i=./indat/dat2snfn.csv o=./outdat/out11nfn.csv

#k=,u=使用
${pfxc}mbest      k=顧客 s=日付 R=2_3 u=./outdat/out13.csv    i=./indat/dat2s.csv    o=./outdat/out12.csv
${pfxc}mbest -x   k=0   s=1    R=2_3 u=./outdat/out13x.csv   i=./indat/dat2s.csv    o=./outdat/out12x.csv
${pfxc}mbest -nfn k=0   s=1    R=2_3 u=./outdat/out13nfn.csv i=./indat/dat2snfn.csv o=./outdat/out12nfn.csv

#k=,-r使用
${pfxc}mbest      k=顧客 s=日付  R=1_2 -r i=./indat/dat2s.csv o=./outdat/out14.csv
${pfxc}mbest -x   k=0   s=1    R=1_2 -r i=./indat/dat2s.csv o=./outdat/out14x.csv
${pfxc}mbest -nfn k=0   s=1    R=1_2 -r i=./indat/dat2s.csv o=./outdat/out14nfn.csv

#k=,-r,u=使用
${pfxc}mbest      k=顧客 s=日付  R=1 -r u=./outdat/out16.csv    i=./indat/dat2s.csv    o=./outdat/out15.csv
${pfxc}mbest -x   k=0   s=1    R=1 -r u=./outdat/out16x.csv   i=./indat/dat2s.csv    o=./outdat/out15x.csv
${pfxc}mbest -nfn k=0   s=1    R=1 -r u=./outdat/out16nfn.csv i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv

#大小逆
${pfxc}mbest      s=金額%nr R=2_1,MAX_4 i=./indat/dat1s.csv    o=./outdat/out17.csv
${pfxc}mbest -x   s=2%nr   R=2_1,MAX_4 i=./indat/dat1s.csv    o=./outdat/out17x.csv
${pfxc}mbest -nfn s=2%nr   R=2_1,MAX_4 i=./indat/dat1snfn.csv o=./outdat/out17nfn.csv

#部分NULL文字
${pfxc}mbest      k=顧客 s=日付 R=1 u=./outdat/out19.csv    i=./indat/dat3s.csv    o=./outdat/out18.csv
${pfxc}mbest -x   k=0   s=1  R=1 u=./outdat/out19x.csv   i=./indat/dat3s.csv    o=./outdat/out18x.csv
${pfxc}mbest -nfn k=0   s=1 R=1 u=./outdat/out19nfn.csv i=./indat/dat3snfn.csv o=./outdat/out18nfn.csv

#R指定なし
${pfxc}mbest   s=金額%nr              i=./indat/dat1s.csv    o=./outdat/out58.csv
${pfxc}mbest   s=金額%nr from=0       i=./indat/dat1s.csv    o=./outdat/out20.csv
${pfxc}mbest   s=金額%nr from=1       i=./indat/dat1s.csv    o=./outdat/out21.csv
${pfxc}mbest   s=金額%nr from=5       i=./indat/dat1s.csv    o=./outdat/out22.csv
${pfxc}mbest   s=金額%nr from=2 to=5  i=./indat/dat1s.csv    o=./outdat/out23.csv
${pfxc}mbest   s=金額%nr from=MIN i=./indat/dat1s.csv    o=./outdat/out24.csv
${pfxc}mbest   s=金額%nr to=MAX   i=./indat/dat1s.csv    o=./outdat/out25.csv
${pfxc}mbest   s=金額%nr from=1 size=3   i=./indat/dat1s.csv    o=./outdat/out26.csv





#ランダムデータ
#nullデータ
${pfxc}mbest       s=金額 R=1_3 i=./indat/dat0.csv    o=./outdat/out27.csv
${pfxc}mbest -x    s=2   R=1_3 i=./indat/dat0.csv    o=./outdat/out27x.csv
${pfxc}mbest -nfn  s=2   R=1_3 i=./indat/dat0nfn.csv o=./outdat/out27nfn.csv
${pfxc}mbest -nfno s=金額 R=1_3 i=./indat/dat0.csv    o=./outdat/out27nfno.csv
${pfxc}mbest -q       s=金額 R=1_3 i=./indat/dat0s.csv    o=./outdat/out27q.csv
${pfxc}mbest -q -nfn  s=2   R=1_3 i=./indat/dat0snfn.csv o=./outdat/out27qnfn.csv

#基本
${pfxc}mbest       s=金額%nr R=1_3  i=./indat/dat1.csv    o=./outdat/out28.csv
${pfxc}mbest -x    s=2%nr   R=1_3  i=./indat/dat1.csv    o=./outdat/out28x.csv
${pfxc}mbest -nfn  s=2%nr   R=1_3  i=./indat/dat1nfn.csv o=./outdat/out28nfn.csv
${pfxc}mbest -nfno s=金額%nr  R=1_3 i=./indat/dat1.csv    o=./outdat/out28nfno.csv
${pfxc}mbest -q       s=金額%nr R=1_3  i=./indat/dat1.csv    o=./outdat/out28q.csv
${pfxc}mbest -q -nfn  s=2%nr   R=1_3  i=./indat/dat1nfn.csv o=./outdat/out28qnfn.csv

#複数指定
${pfxc}mbest      s=金額%nr R=1_2,4_5 i=./indat/dat1.csv    o=./outdat/out29.csv
${pfxc}mbest -x   s=2%nr   R=1_2,4_5 i=./indat/dat1.csv    o=./outdat/out29x.csv
${pfxc}mbest -nfn s=2%nr   R=1_2,4_5 i=./indat/dat1nfn.csv o=./outdat/out29nfn.csv
${pfxc}mbest -q      s=金額%nr R=1_2,4_5 i=./indat/dat1.csv    o=./outdat/out29q.csv
${pfxc}mbest -q -nfn s=2%nr   R=1_2,4_5 i=./indat/dat1nfn.csv o=./outdat/out29qnfn.csv

#MIN使用
${pfxc}mbest      s=金額%nr R=MIN_2 i=./indat/dat1.csv    o=./outdat/out30.csv
${pfxc}mbest -x   s=2%nr   R=MIN_2 i=./indat/dat1.csv    o=./outdat/out30x.csv
${pfxc}mbest -nfn s=2%nr   R=MIN_2 i=./indat/dat1nfn.csv o=./outdat/out30nfn.csv

#MAX使用
${pfxc}mbest      s=金額%nr R=4_MAX i=./indat/dat1.csv    o=./outdat/out31.csv
${pfxc}mbest -x   s=2%nr   R=4_MAX i=./indat/dat1.csv    o=./outdat/out31x.csv
${pfxc}mbest -nfn s=2%nr   R=4_MAX i=./indat/dat1nfn.csv o=./outdat/out31nfn.csv

#MIN,MAX使用
${pfxc}mbest      s=金額%nr R=MIN_2,4_MAX i=./indat/dat1.csv    o=./outdat/out32.csv
${pfxc}mbest -x   s=2%nr   R=MIN_2,4_MAX i=./indat/dat1.csv    o=./outdat/out32x.csv
${pfxc}mbest -nfn s=2%nr   R=MIN_2,4_MAX i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv

#u=使用
${pfxc}mbest      s=金額%nr R=2 i=./indat/dat1.csv    u=./outdat/out36.csv    o=./outdat/out35.csv
${pfxc}mbest -x   s=2%nr   R=2 i=./indat/dat1.csv    u=./outdat/out36x.csv    o=./outdat/out35x.csv
${pfxc}mbest -nfn s=2%nr   R=2 i=./indat/dat1nfn.csv u=./outdat/out36nfn.csv o=./outdat/out35nfn.csv

#-r使用
${pfxc}mbest      s=金額%nr R=2 i=./indat/dat1.csv    -r o=./outdat/out37.csv
${pfxc}mbest -x   s=2%nr   R=2 i=./indat/dat1.csv    -r o=./outdat/out37x.csv
${pfxc}mbest -nfn s=2%nr   R=2 i=./indat/dat1nfn.csv -r o=./outdat/out37nfn.csv

#-r,u=使用
${pfxc}mbest      s=金額%nr R=2 i=./indat/dat1.csv    u=./outdat/out39.csv    -r o=./outdat/out38.csv
${pfxc}mbest -x   s=2%nr   R=2 i=./indat/dat1.csv    u=./outdat/out39x.csv   -r o=./outdat/out38x.csv
${pfxc}mbest -nfn s=2%nr   R=2 i=./indat/dat1nfn.csv u=./outdat/out39nfn.csv -r o=./outdat/out38nfn.csv

#k=使用
${pfxc}mbest      k=顧客 s=日付 R=2 i=./indat/dat2.csv    o=./outdat/out40.csv
${pfxc}mbest -x   k=0   s=1　  R=2 i=./indat/dat2.csv    o=./outdat/out40x.csv
${pfxc}mbest -nfn k=0   s=1    R=2 i=./indat/dat2nfn.csv o=./outdat/out40nfn.csv

#k=,u=使用
${pfxc}mbest      k=顧客 s=日付 R=2_3 u=./outdat/out42.csv    i=./indat/dat2.csv    o=./outdat/out41.csv
${pfxc}mbest -x   k=0   s=1    R=2_3 u=./outdat/out42x.csv   i=./indat/dat2.csv    o=./outdat/out41x.csv
${pfxc}mbest -nfn k=0   s=1    R=2_3 u=./outdat/out42nfn.csv i=./indat/dat2nfn.csv o=./outdat/out41nfn.csv

#k=,-r使用
${pfxc}mbest      k=顧客 s=日付  R=1_2 -r i=./indat/dat2.csv o=./outdat/out43.csv
${pfxc}mbest -x   k=0   s=1    R=1_2 -r i=./indat/dat2.csv o=./outdat/out43x.csv
${pfxc}mbest -nfn k=0   s=1    R=1_2 -r i=./indat/dat2.csv o=./outdat/out43nfn.csv

#k=,-r,u=使用
${pfxc}mbest      k=顧客 s=日付  R=1 -r u=./outdat/out45.csv    i=./indat/dat2.csv    o=./outdat/out44.csv
${pfxc}mbest -x   k=0   s=1    R=1 -r u=./outdat/out45x.csv   i=./indat/dat2.csv    o=./outdat/out44x.csv
${pfxc}mbest -nfn k=0   s=1    R=1 -r u=./outdat/out45nfn.csv i=./indat/dat2nfn.csv o=./outdat/out44nfn.csv

#大小逆
${pfxc}mbest      s=金額%nr R=2_1,MAX_4 i=./indat/dat1.csv    o=./outdat/out46.csv
${pfxc}mbest -x   s=2%nr   R=2_1,MAX_4 i=./indat/dat1.csv    o=./outdat/out46x.csv
${pfxc}mbest -nfn s=2%nr   R=2_1,MAX_4 i=./indat/dat1nfn.csv o=./outdat/out46nfn.csv

#部分NULL文字
${pfxc}mbest      k=顧客 s=日付 R=1 u=./outdat/out48.csv    i=./indat/dat3.csv    o=./outdat/out47.csv
${pfxc}mbest -x   k=0   s=1  R=1 u=./outdat/out48x.csv   i=./indat/dat3.csv    o=./outdat/out47x.csv
${pfxc}mbest -nfn k=0   s=1 R=1 u=./outdat/out48nfn.csv i=./indat/dat3nfn.csv o=./outdat/out47nfn.csv

#R指定なし
${pfxc}mbest   s=金額%nr              i=./indat/dat1.csv    o=./outdat/out50.csv
${pfxc}mbest   s=金額%nr from=0       i=./indat/dat1.csv    o=./outdat/out51.csv
${pfxc}mbest   s=金額%nr from=1       i=./indat/dat1.csv    o=./outdat/out52.csv
${pfxc}mbest   s=金額%nr from=5       i=./indat/dat1.csv    o=./outdat/out53.csv
${pfxc}mbest   s=金額%nr from=2 to=5  i=./indat/dat1.csv    o=./outdat/out54.csv

${pfxc}mbest   s=金額%nr from=MIN i=./indat/dat1.csv    o=./outdat/out55.csv
${pfxc}mbest   s=金額%nr to=MAX   i=./indat/dat1.csv    o=./outdat/out56.csv

${pfxc}mbest   s=金額%nr from=1 size=3   i=./indat/dat1.csv    o=./outdat/out57.csv


