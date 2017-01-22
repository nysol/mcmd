#!/bin/bash

. ../env

#name_kg_mcmd selrand

#NULL
${pfxc}mselrand      k=顧客 c=2 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mselrand -x   k=1    c=2 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mselrand -nfn k=1    c=2 i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mselrand -nfno  k=顧客 c=2 i=./indat/dat0.csv    o=./outdat/out0nfno.csv

#基本
${pfxc}mselrand      c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mselrand -x   c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mselrand -nfn c=2 S=1 i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mselrand -nfno c=2 S=1 i=./indat/dat1s.csv o=./outdat/out1nfno.csv

${pfxc}mselrand      p=40 S=1 i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mselrand -x   p=40 S=1 i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mselrand -nfn p=40 S=1 i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mselrand -nfno p=40 S=1 i=./indat/dat1s.csv o=./outdat/out2nfno.csv

${pfxc}mselrand      c=1 S=1 i=./indat/dat1s.csv    o=./outdat/out3.csv    u=./outdat/out4.csv
${pfxc}mselrand -x   c=1 S=1 i=./indat/dat1s.csv    o=./outdat/out3x.csv   u=./outdat/out4x.csv
${pfxc}mselrand -nfn c=1 S=1 i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv u=./outdat/out4nfn.csv
${pfxc}mselrand -nfno c=1 S=1 i=./indat/dat1s.csv o=./outdat/out3nfno.csv u=./outdat/out4nfno.csv

${pfxc}mselrand      p=30 S=1 i=./indat/dat1s.csv    o=./outdat/out5.csv    u=./outdat/out6.csv
${pfxc}mselrand -x   p=30 S=1 i=./indat/dat1s.csv    o=./outdat/out5x.csv   u=./outdat/out6x.csv
${pfxc}mselrand -nfn p=30 S=1 i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv u=./outdat/out6nfn.csv
${pfxc}mselrand -nfno p=30 S=1 i=./indat/dat1s.csv o=./outdat/out5nfno.csv u=./outdat/out6nfno.csv

#k=あり
${pfxc}mselrand      k=顧客 c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}mselrand -x   k=0    c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mselrand -nfn k=0    c=2 S=1 i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv
${pfxc}mselrand -nfno k=顧客 c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out7nfno.csv
${pfxc}mselrand -q     k=顧客 c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out7q.csv
${pfxc}mselrand -q -x   k=0    c=2 S=1 i=./indat/dat1s.csv    o=./outdat/out7qx.csv

${pfxc}mselrand      k=顧客 p=40 S=1 i=./indat/dat1s.csv    o=./outdat/out8.csv
${pfxc}mselrand -x   k=0    p=40 S=1 i=./indat/dat1s.csv    o=./outdat/out8x.csv
${pfxc}mselrand -nfn k=0    p=40 S=1 i=./indat/dat1snfn.csv o=./outdat/out8nfn.csv
${pfxc}mselrand -nfno k=顧客 p=40 S=1 i=./indat/dat1s.csv    o=./outdat/out8nfno.csv

${pfxc}mselrand      k=顧客 c=4 S=1 i=./indat/dat1s.csv    o=./outdat/out9.csv    u=./outdat/out10.csv
${pfxc}mselrand -x   k=0    c=4 S=1 i=./indat/dat1s.csv    o=./outdat/out9x.csv   u=./outdat/out10x.csv
${pfxc}mselrand -nfn k=0    c=4 S=1 i=./indat/dat1snfn.csv o=./outdat/out9nfn.csv u=./outdat/out10nfn.csv
${pfxc}mselrand -nfno k=顧客 c=4 S=1 i=./indat/dat1s.csv    o=./outdat/out9nfno.csv    u=./outdat/out10nfno.csv

${pfxc}mselrand      k=顧客 p=50 S=1 i=./indat/dat1s.csv    o=./outdat/out11.csv    u=./outdat/out12.csv
${pfxc}mselrand -x   k=0    p=50 S=1 i=./indat/dat1s.csv    o=./outdat/out11x.csv   u=./outdat/out12x.csv
${pfxc}mselrand -nfn k=0    p=50 S=1 i=./indat/dat1snfn.csv o=./outdat/out11nfn.csv u=./outdat/out12nfn.csv
${pfxc}mselrand -nfno k=顧客 p=50 S=1 i=./indat/dat1s.csv    o=./outdat/out11nfno.csv    u=./outdat/out12nfno.csv

#NULLを含む
${pfxc}mselrand      k=顧客 c=2 S=1 i=./indat/dat2s.csv    o=./outdat/out13.csv
${pfxc}mselrand -x   k=0    c=2 S=1 i=./indat/dat2s.csv    o=./outdat/out13x.csv
${pfxc}mselrand -nfn k=0    c=2 S=1 i=./indat/dat2snfn.csv o=./outdat/out13nfn.csv
${pfxc}mselrand -nfno k=顧客 c=2 S=1 i=./indat/dat2s.csv    o=./outdat/out13nfno.csv

${pfxc}mselrand      k=顧客 p=40 S=1 i=./indat/dat2s.csv    o=./outdat/out14.csv
${pfxc}mselrand -x   k=0    p=40 S=1 i=./indat/dat2s.csv    o=./outdat/out14x.csv
${pfxc}mselrand -nfn k=0    p=40 S=1 i=./indat/dat2snfn.csv o=./outdat/out14nfn.csv
${pfxc}mselrand -nfno k=顧客 p=40 S=1 i=./indat/dat2s.csv    o=./outdat/out14nfno.csv

${pfxc}mselrand      k=顧客 c=1 S=1 i=./indat/dat2s.csv    o=./outdat/out15.csv    u=./outdat/out16.csv
${pfxc}mselrand -x   k=0    c=1 S=1 i=./indat/dat2s.csv    o=./outdat/out15x.csv   u=./outdat/out16x.csv
${pfxc}mselrand -nfn k=0    c=1 S=1 i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv u=./outdat/out16nfn.csv
${pfxc}mselrand -nfno k=顧客 c=1 S=1 i=./indat/dat2s.csv    o=./outdat/out15nfno.csv    u=./outdat/out16nfno.csv

${pfxc}mselrand      k=顧客 p=50 S=1 i=./indat/dat2s.csv    o=./outdat/out17.csv    u=./outdat/out18.csv
${pfxc}mselrand -x   k=0    p=50 S=1 i=./indat/dat2s.csv    o=./outdat/out17x.csv   u=./outdat/out18x.csv
${pfxc}mselrand -nfn k=0    p=50 S=1 i=./indat/dat2snfn.csv o=./outdat/out17nfn.csv u=./outdat/out18nfn.csv
${pfxc}mselrand -nfno k=顧客 p=50 S=1 i=./indat/dat2s.csv    o=./outdat/out17nfno.csv    u=./outdat/out18nfno.csv

#S=の指定なし
${pfxc}mselrand      k=顧客 c=2 i=./indat/dat1s.csv    o=./outdat/out19.csv
${pfxc}mselrand -x   k=0    c=2 i=./indat/dat1s.csv    o=./outdat/out19x.csv
${pfxc}mselrand -nfn k=0    c=2 i=./indat/dat1snfn.csv o=./outdat/out19nfn.csv

${pfxc}mselrand      k=顧客 p=40 i=./indat/dat1s.csv    o=./outdat/out20.csv
${pfxc}mselrand -x   k=0    p=40 i=./indat/dat1s.csv    o=./outdat/out20x.csv
${pfxc}mselrand -nfn k=0    p=40 i=./indat/dat1snfn.csv o=./outdat/out20nfn.csv

${pfxc}mselrand      k=顧客 c=1 i=./indat/dat1s.csv    o=./outdat/out21.csv    u=./outdat/out22.csv
${pfxc}mselrand -x   k=0    c=1 i=./indat/dat1s.csv    o=./outdat/out21x.csv   u=./outdat/out22x.csv
${pfxc}mselrand -nfn k=0    c=1 i=./indat/dat1snfn.csv o=./outdat/out21nfn.csv u=./outdat/out22nfn.csv

${pfxc}mselrand      k=顧客 p=50 i=./indat/dat1s.csv    o=./outdat/out23.csv    u=./outdat/out24.csv
${pfxc}mselrand -x   k=0    p=50 i=./indat/dat1s.csv    o=./outdat/out23x.csv   u=./outdat/out24x.csv
${pfxc}mselrand -nfn k=0    p=50 i=./indat/dat1snfn.csv o=./outdat/out23nfn.csv u=./outdat/out24nfn.csv

#Bオプションあり
${pfxc}mselrand      S=1 -B  k=顧客 c=2 i=./indat/dat1s.csv  o=./outdat/out25.csv u=./outdat/out26.csv
${pfxc}mselrand -x   S=1 -B  k=0   c=2 i=./indat/dat1s.csv  o=./outdat/out25x.csv u=./outdat/out26x.csv
${pfxc}mselrand -nfn S=1 -B  k=0   c=2 i=./indat/dat1snfn.csv  o=./outdat/out25nfn.csv u=./outdat/out26nfn.csv

${pfxc}mselrand      S=1 -B  k=顧客 p=50 i=./indat/dat1s.csv  o=./outdat/out27.csv u=./outdat/out28.csv
${pfxc}mselrand -x   S=1 -B  k=0   p=50 i=./indat/dat1s.csv  o=./outdat/out27x.csv u=./outdat/out28x.csv
${pfxc}mselrand -nfn S=1 -B  k=0   p=50 i=./indat/dat1snfn.csv  o=./outdat/out27nfn.csv u=./outdat/out28nfn.csv

${pfxc}mselrand      -B  k=顧客 c=2 i=./indat/dat1s.csv  o=./outdat/out29.csv u=./outdat/out30.csv
${pfxc}mselrand -x   -B  k=0   c=2 i=./indat/dat1s.csv  o=./outdat/out29x.csv u=./outdat/out30x.csv
${pfxc}mselrand -nfn -B  k=0   c=2 i=./indat/dat1snfn.csv  o=./outdat/out29nfn.csv u=./outdat/out30nfn.csv


${pfxc}mselrand      -B  k=顧客 p=50 i=./indat/dat1s.csv  o=./outdat/out31.csv u=./outdat/out32.csv
${pfxc}mselrand -x   -B  k=0   p=50 i=./indat/dat1s.csv  o=./outdat/out31x.csv u=./outdat/out32x.csv
${pfxc}mselrand -nfn -B  k=0   p=50 i=./indat/dat1snfn.csv  o=./outdat/out31nfn.csv u=./outdat/out32nfn.csv


#ランダムデータ
#k=あり
${pfxc}mselrand      k=顧客 c=2 S=1 i=./indat/dat1.csv    o=./outdat/out37.csv
${pfxc}mselrand -x   k=0    c=2 S=1 i=./indat/dat1.csv    o=./outdat/out37x.csv
${pfxc}mselrand -nfn k=0    c=2 S=1 i=./indat/dat1nfn.csv o=./outdat/out37nfn.csv
${pfxc}mselrand -nfno k=顧客 c=2 S=1 i=./indat/dat1.csv    o=./outdat/out37nfno.csv
${pfxc}mselrand -q     k=顧客 c=2 S=1 i=./indat/dat1.csv    o=./outdat/out37q.csv
${pfxc}mselrand -q -x   k=0    c=2 S=1 i=./indat/dat1.csv    o=./outdat/out37qx.csv

${pfxc}mselrand      k=顧客 p=40 S=1 i=./indat/dat1.csv    o=./outdat/out38.csv
${pfxc}mselrand -x   k=0    p=40 S=1 i=./indat/dat1.csv    o=./outdat/out38x.csv
${pfxc}mselrand -nfn k=0    p=40 S=1 i=./indat/dat1nfn.csv o=./outdat/out38nfn.csv
${pfxc}mselrand -nfno k=顧客 p=40 S=1 i=./indat/dat1.csv    o=./outdat/out38nfno.csv

${pfxc}mselrand      k=顧客 c=4 S=1 i=./indat/dat1.csv    o=./outdat/out39.csv    u=./outdat/out40.csv
${pfxc}mselrand -x   k=0    c=4 S=1 i=./indat/dat1.csv    o=./outdat/out39x.csv   u=./outdat/out40x.csv
${pfxc}mselrand -nfn k=0    c=4 S=1 i=./indat/dat1nfn.csv o=./outdat/out39nfn.csv u=./outdat/out40nfn.csv
${pfxc}mselrand -nfno k=顧客 c=4 S=1 i=./indat/dat1.csv    o=./outdat/out39nfno.csv    u=./outdat/out40nfno.csv

${pfxc}mselrand      k=顧客 p=50 S=1 i=./indat/dat1.csv    o=./outdat/out41.csv    u=./outdat/out42.csv
${pfxc}mselrand -x   k=0    p=50 S=1 i=./indat/dat1.csv    o=./outdat/out41x.csv   u=./outdat/out42x.csv
${pfxc}mselrand -nfn k=0    p=50 S=1 i=./indat/dat1nfn.csv o=./outdat/out41nfn.csv u=./outdat/out42nfn.csv
${pfxc}mselrand -nfno k=顧客 p=50 S=1 i=./indat/dat1.csv    o=./outdat/out41nfno.csv    u=./outdat/out42nfno.csv

#NULLを含む
${pfxc}mselrand      k=顧客 c=2 S=1 i=./indat/dat2.csv    o=./outdat/out43.csv
${pfxc}mselrand -x   k=0    c=2 S=1 i=./indat/dat2.csv    o=./outdat/out43x.csv
${pfxc}mselrand -nfn k=0    c=2 S=1 i=./indat/dat2nfn.csv o=./outdat/out43nfn.csv
${pfxc}mselrand -nfno k=顧客 c=2 S=1 i=./indat/dat2.csv    o=./outdat/out43nfno.csv

${pfxc}mselrand      k=顧客 p=40 S=1 i=./indat/dat2.csv    o=./outdat/out44.csv
${pfxc}mselrand -x   k=0    p=40 S=1 i=./indat/dat2.csv    o=./outdat/out44x.csv
${pfxc}mselrand -nfn k=0    p=40 S=1 i=./indat/dat2nfn.csv o=./outdat/out44nfn.csv
${pfxc}mselrand -nfno k=顧客 p=40 S=1 i=./indat/dat2.csv    o=./outdat/out44nfno.csv

${pfxc}mselrand      k=顧客 c=1 S=1 i=./indat/dat2.csv    o=./outdat/out45.csv    u=./outdat/out46.csv
${pfxc}mselrand -x   k=0    c=1 S=1 i=./indat/dat2.csv    o=./outdat/out45x.csv   u=./outdat/out46x.csv
${pfxc}mselrand -nfn k=0    c=1 S=1 i=./indat/dat2nfn.csv o=./outdat/out45nfn.csv u=./outdat/out46nfn.csv
${pfxc}mselrand -nfno k=顧客 c=1 S=1 i=./indat/dat2.csv    o=./outdat/out45nfno.csv    u=./outdat/out46nfno.csv

${pfxc}mselrand      k=顧客 p=50 S=1 i=./indat/dat2.csv    o=./outdat/out47.csv    u=./outdat/out48.csv
${pfxc}mselrand -x   k=0    p=50 S=1 i=./indat/dat2.csv    o=./outdat/out47x.csv   u=./outdat/out48x.csv
${pfxc}mselrand -nfn k=0    p=50 S=1 i=./indat/dat2nfn.csv o=./outdat/out47nfn.csv u=./outdat/out48nfn.csv
${pfxc}mselrand -nfno k=顧客 p=50 S=1 i=./indat/dat2.csv    o=./outdat/out47nfno.csv    u=./outdat/out48nfno.csv

#S=の指定なし
${pfxc}mselrand      k=顧客 c=2 i=./indat/dat1.csv    o=./outdat/out49.csv
${pfxc}mselrand -x   k=0    c=2 i=./indat/dat1.csv    o=./outdat/out49x.csv
${pfxc}mselrand -nfn k=0    c=2 i=./indat/dat1nfn.csv o=./outdat/out49nfn.csv

${pfxc}mselrand      k=顧客 p=40 i=./indat/dat1.csv    o=./outdat/out50.csv
${pfxc}mselrand -x   k=0    p=40 i=./indat/dat1.csv    o=./outdat/out50x.csv
${pfxc}mselrand -nfn k=0    p=40 i=./indat/dat1nfn.csv o=./outdat/out50nfn.csv

${pfxc}mselrand      k=顧客 c=1 i=./indat/dat1.csv    o=./outdat/out51.csv    u=./outdat/out52.csv
${pfxc}mselrand -x   k=0    c=1 i=./indat/dat1.csv    o=./outdat/out51x.csv   u=./outdat/out52x.csv
${pfxc}mselrand -nfn k=0    c=1 i=./indat/dat1nfn.csv o=./outdat/out51nfn.csv u=./outdat/out52nfn.csv

${pfxc}mselrand      k=顧客 p=50 i=./indat/dat1.csv    o=./outdat/out53.csv    u=./outdat/out54.csv
${pfxc}mselrand -x   k=0    p=50 i=./indat/dat1.csv    o=./outdat/out53x.csv   u=./outdat/out54x.csv
${pfxc}mselrand -nfn k=0    p=50 i=./indat/dat1nfn.csv o=./outdat/out53nfn.csv u=./outdat/out54nfn.csv

#Bオプションあり
${pfxc}mselrand      S=1 -B  k=顧客 c=2 i=./indat/dat1.csv  o=./outdat/out55.csv u=./outdat/out56.csv
${pfxc}mselrand -x   S=1 -B  k=0   c=2 i=./indat/dat1.csv  o=./outdat/out55x.csv u=./outdat/out56x.csv
${pfxc}mselrand -nfn S=1 -B  k=0   c=2 i=./indat/dat1nfn.csv  o=./outdat/out55nfn.csv u=./outdat/out56nfn.csv

${pfxc}mselrand      S=1 -B  k=顧客 p=50 i=./indat/dat1.csv  o=./outdat/out57.csv u=./outdat/out58.csv
${pfxc}mselrand -x   S=1 -B  k=0   p=50 i=./indat/dat1.csv  o=./outdat/out57x.csv u=./outdat/out58x.csv
${pfxc}mselrand -nfn S=1 -B  k=0   p=50 i=./indat/dat1nfn.csv  o=./outdat/out57nfn.csv u=./outdat/out58nfn.csv

${pfxc}mselrand      -B  k=顧客 c=2 i=./indat/dat1.csv  o=./outdat/out59.csv u=./outdat/out60.csv
${pfxc}mselrand -x   -B  k=0   c=2 i=./indat/dat1.csv  o=./outdat/out59x.csv u=./outdat/out60x.csv
${pfxc}mselrand -nfn -B  k=0   c=2 i=./indat/dat1nfn.csv  o=./outdat/out59nfn.csv u=./outdat/out60nfn.csv


${pfxc}mselrand      -B  k=顧客 p=50 i=./indat/dat1.csv  o=./outdat/out61.csv u=./outdat/out62.csv
${pfxc}mselrand -x   -B  k=0   p=50 i=./indat/dat1.csv  o=./outdat/out61x.csv u=./outdat/out62x.csv
${pfxc}mselrand -nfn -B  k=0   p=50 i=./indat/dat1nfn.csv  o=./outdat/out61nfn.csv u=./outdat/out62nfn.csv





