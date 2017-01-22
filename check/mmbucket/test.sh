#!/bin/bash

. ../env

#name_kg_mcmd mbucket

#NULL
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mmbucket -nfn f=1,2       n=2,2 i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mmbucket -nfno f=x:xb,y:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out0nfno.csv

${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out1.csv    O=./outdat/out2.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out1x.csv   O=./outdat/out2x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat0snfn.csv o=./outdat/out1nfn.csv O=./outdat/out2nfn.csv

#基本
${pfxc}mmbucket      f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mmbucket -x   f=1:xb n=2 i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mmbucket -nfn f=1    n=2 i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}mmbucket -nfno f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out3nfno.csv
${pfxc}mmbucket -q   f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out3q.csv

#k=指定
${pfxc}mmbucket      k=id f=x:xb n=2 i=./indat/dat2s.csv    o=./outdat/out4.csv
${pfxc}mmbucket -x   k=0  f=1:xb n=2 i=./indat/dat2s.csv    o=./outdat/out4x.csv
${pfxc}mmbucket -nfn k=0  f=1    n=2 i=./indat/dat2snfn.csv o=./outdat/out4nfn.csv

#f=複数指定
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out5.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out5x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=3,2 i=./indat/dat2snfn.csv o=./outdat/out5nfn.csv

#O=のしてい
${pfxc}mmbucket      f=x:xb,y:yb n=3 O=./outdat/out7.csv    i=./indat/dat1.csv    o=./outdat/out6.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=3 O=./outdat/out7x.csv   i=./indat/dat1.csv    o=./outdat/out6x.csv
${pfxc}mmbucket -nfn f=1,2       n=3 O=./outdat/out7nfn.csv i=./indat/dat1nfn.csv o=./outdat/out6nfn.csv

#bufcount=2指定
${pfxc}mmbucket bufcount=2  k=id f=x:xb,y:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out45.csv

#結果一部null
${pfxc}mmbucket k=id f=x:xb,y:yb n=3,2 i=./indat/dat6s.csv    o=./outdat/out46.csv

#O=,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out9.csv    i=./indat/dat2s.csv    o=./outdat/out8.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out9x.csv   i=./indat/dat2s.csv    o=./outdat/out8x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out9nfn.csv i=./indat/dat2snfn.csv o=./outdat/out8nfn.csv

#F=0
${pfxc}mmbucket      f=x:xb,y:yb F=0 n=3,3 i=./indat/dat1.csv    o=./outdat/out44.csv
${pfxc}mmbucket -x   f=1:xb,2:yb F=0 n=3,3 i=./indat/dat1.csv    o=./outdat/out44x.csv
${pfxc}mmbucket -nfn f=1,2       F=0 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out44nfn.csv

#F=1
${pfxc}mmbucket      f=x:xb,y:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mmbucket -x   f=1:xb,2:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}mmbucket -nfn f=1,2       F=1 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

#F=2
${pfxc}mmbucket      f=x:xb,y:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}mmbucket -x   f=1:xb,2:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}mmbucket -nfn f=1,2       F=2 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

#F=1,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb  n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out12.csv
${pfxc}mmbucket -x   k=0   f=1:xb,2:yb n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out12x.csv
${pfxc}mmbucket -nfn k=0   f=1,2       n=3,3 F=1 i=./indat/dat2snfn.csv o=./outdat/out12nfn.csv

#F=2,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out13.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out13x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2snfn.csv o=./outdat/out13nfn.csv

#f=の指定数とn=の指定数が違う場合
${pfxc}mmbucket      f=x:xb,y:yb n=2 i=./indat/dat1.csv    o=./outdat/out14.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=2 i=./indat/dat1.csv    o=./outdat/out14x.csv
${pfxc}mmbucket -nfn f=1,2       n=2 i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

#部分的にNULL値が含まれている時
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out15.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out15x.csv
${pfxc}mmbucket -nfn f=1,2       n=2,2 i=./indat/dat3nfn.csv o=./outdat/out15nfn.csv

#部分的にNULL値が含まれている時k=
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out16.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out16x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat4snfn.csv o=./outdat/out16nfn.csv

#部分的にNULL値が含まれている時,F=1
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out17.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out17x.csv
${pfxc}mmbucket -nfn f=1,2       n=2,2 F=1 i=./indat/dat3nfn.csv o=./outdat/out17nfn.csv

#部分的にNULL値が含まれている時,F=2
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out18.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out18x.csv
${pfxc}mmbucket -nfn f=1,2       n=2,2 F=2 i=./indat/dat3nfn.csv o=./outdat/out18nfn.csv

#部分的にNULL値が含まれている時,O=
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 O=./outdat/out20.csv    i=./indat/dat3.csv    o=./outdat/out19.csv
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 O=./outdat/out20x.csv   i=./indat/dat3.csv    o=./outdat/out19x.csv
${pfxc}mmbucket -nfn f=1,2       n=2,2 O=./outdat/out20nfn.csv i=./indat/dat3nfn.csv o=./outdat/out19nfn.csv

#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out21.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out21x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5snfn.csv o=./outdat/out21nfn.csv

#ここ以降は-msパラメータを使用した場合
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out22.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out22x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=2,2 i=./indat/dat0snfn.csv o=./outdat/out22nfn.csv -ms

${pfxc}mmbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out23.csv    O=./outdat/out24.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0s.csv    o=./outdat/out23x.csv   O=./outdat/out24x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=2,2 i=./indat/dat0snfn.csv o=./outdat/out23nfn.csv O=./outdat/out24nfn.csv -ms

#基本
${pfxc}mmbucket      f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out25.csv    -ms
${pfxc}mmbucket -x   f=1:xb n=2 i=./indat/dat1.csv    o=./outdat/out25x.csv   -ms
${pfxc}mmbucket -nfn f=1    n=2 i=./indat/dat1nfn.csv o=./outdat/out25nfn.csv -ms

#k=指定
${pfxc}mmbucket      k=id f=x:xb n=2 i=./indat/dat2s.csv    o=./outdat/out26.csv    -ms
${pfxc}mmbucket -x   k=0 f=1:xb  n=2 i=./indat/dat2s.csv    o=./outdat/out26x.csv   -ms
${pfxc}mmbucket -nfn k=0 f=1     n=2 i=./indat/dat2snfn.csv o=./outdat/out26nfn.csv -ms

#f=複数指定
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out27.csv    -ms
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out27x.csv   -ms
${pfxc}mmbucket -nfn k=0  f=1,2       n=3,2 i=./indat/dat2snfn.csv o=./outdat/out27nfn.csv -ms

#O=のしてい
${pfxc}mmbucket      f=x:xb,y:yb n=3 O=./outdat/out29.csv    i=./indat/dat1.csv    o=./outdat/out28.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=3 O=./outdat/out29x.csv   i=./indat/dat1.csv    o=./outdat/out28x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=3 O=./outdat/out29nfn.csv i=./indat/dat1nfn.csv o=./outdat/out28nfn.csv -ms

#O=,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out31.csv    i=./indat/dat2s.csv    o=./outdat/out30.csv    -ms
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out31x.csv   i=./indat/dat2s.csv    o=./outdat/out30x.csv   -ms
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out31nfn.csv i=./indat/dat2snfn.csv o=./outdat/out30nfn.csv -ms

#F=1
${pfxc}mmbucket      f=x:xb,y:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out32.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out32x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       F=1 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv -ms

#F=2
${pfxc}mmbucket      f=x:xb,y:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out33.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out33x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       F=2 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out33nfn.csv -ms

#F=1,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out34.csv    -ms
${pfxc}mmbucket -x   k=0 f=1:xb,2:yb  n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out34x.csv   -ms
${pfxc}mmbucket -nfn k=0 f=1,2        n=3,3 F=1 i=./indat/dat2snfn.csv o=./outdat/out34nfn.csv -ms

#F=2,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out35.csv    -ms
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out35x.csv   -ms
${pfxc}mmbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2snfn.csv o=./outdat/out35nfn.csv -ms

#f=の指定数とn=の指定数が違う場合
${pfxc}mmbucket      f=x:xb,y:yb n=2 i=./indat/dat1.csv    o=./outdat/out36.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2 i=./indat/dat1.csv    o=./outdat/out36x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=2 i=./indat/dat1nfn.csv o=./outdat/out36nfn.csv -ms

#部分的にNULL値が含まれている時
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out37.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out37x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=2,2 i=./indat/dat3nfn.csv o=./outdat/out37nfn.csv -ms

#部分的にNULL値が含まれている時k=
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out38.csv    -ms
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out38x.csv   -ms
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat4snfn.csv o=./outdat/out38nfn.csv -ms

#部分的にNULL値が含まれている時,F=1
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out39.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out39x.csv   -ms
${pfxc}mmbucket -nfn f=1,2b      n=2,2 F=1 i=./indat/dat3nfn.csv o=./outdat/out39nfn.csv -ms

#部分的にNULL値が含まれている時,F=2
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out40.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out40x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=2,2 F=2 i=./indat/dat3nfn.csv o=./outdat/out40nfn.csv -ms

#部分的にNULL値が含まれている時,O=
${pfxc}mmbucket      f=x:xb,y:yb n=2,2 O=./outdat/out42.csv    i=./indat/dat3.csv    o=./outdat/out41.csv    -ms
${pfxc}mmbucket -x   f=1:xb,2:yb n=2,2 O=./outdat/out42x.csv   i=./indat/dat3.csv    o=./outdat/out41x.csv   -ms
${pfxc}mmbucket -nfn f=1,2       n=2,2 O=./outdat/out42nfn.csv i=./indat/dat3nfn.csv o=./outdat/out41nfn.csv -ms

#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out43.csv    -ms
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out43x.csv   -ms
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5snfn.csv o=./outdat/out43nfn.csv -ms


#ランダムデータ
#NULL
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out47.csv    O=./outdat/out48.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out47x.csv   O=./outdat/out48x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat0nfn.csv o=./outdat/out47nfn.csv O=./outdat/out48nfn.csv

#k=指定
${pfxc}mmbucket      k=id f=x:xb n=2 i=./indat/dat2.csv    o=./outdat/out49.csv
${pfxc}mmbucket -x   k=0  f=1:xb n=2 i=./indat/dat2.csv    o=./outdat/out49x.csv
${pfxc}mmbucket -nfn k=0  f=1    n=2 i=./indat/dat2nfn.csv o=./outdat/out49nfn.csv
${pfxc}mmbucket -q   k=id f=x:xb n=2 i=./indat/dat2.csv    o=./outdat/out49q.csv

#f=複数指定
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out50.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out50x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=3,2 i=./indat/dat2nfn.csv o=./outdat/out50nfn.csv

#bufcount=2指定
${pfxc}mmbucket bufcount=2  k=id f=x:xb,y:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out51.csv

#結果一部null
${pfxc}mmbucket k=id f=x:xb,y:yb n=3,2 i=./indat/dat6.csv    o=./outdat/out52.csv

#O=,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out54.csv    i=./indat/dat2.csv    o=./outdat/out53.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out54x.csv   i=./indat/dat2.csv    o=./outdat/out53x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out54nfn.csv i=./indat/dat2nfn.csv o=./outdat/out53nfn.csv

#F=1,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb  n=3,3 F=1 i=./indat/dat2.csv    o=./outdat/out55.csv
${pfxc}mmbucket -x   k=0   f=1:xb,2:yb n=3,3 F=1 i=./indat/dat2.csv    o=./outdat/out55x.csv
${pfxc}mmbucket -nfn k=0   f=1,2       n=3,3 F=1 i=./indat/dat2nfn.csv o=./outdat/out55nfn.csv

#F=2,k=のしてい
${pfxc}mmbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2.csv    o=./outdat/out56.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2.csv    o=./outdat/out56x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2nfn.csv o=./outdat/out56nfn.csv

#部分的にNULL値が含まれている時k=
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4.csv    o=./outdat/out57.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat4.csv    o=./outdat/out57x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat4nfn.csv o=./outdat/out57nfn.csv


#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mmbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5.csv    o=./outdat/out58.csv
${pfxc}mmbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5.csv    o=./outdat/out58x.csv
${pfxc}mmbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5nfn.csv o=./outdat/out58nfn.csv


