#!/bin/bash

. ../env

#name_kg_mcmd bucket

#NULL
${pfxc}mbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mbucket -nfn f=2,3       n=2,2 i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mbucket -nfno  f=x:xb,y:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out0nfno.csv

${pfxc}mbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out1.csv    O=./outdat/out2.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out1x.csv   O=./outdat/out2x.csv
${pfxc}mbucket -nfn f=2,3       n=2,2 i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv O=./outdat/out2nfn.csv

#基本
${pfxc}mbucket      f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mbucket -x   f=1:xb n=2 i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mbucket -nfn f=1    n=2 i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}mbucket -nfno f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out3nfno.csv

#項目が同じ値
${pfxc}mbucket      f=x:xb n=2 i=./indat/dat7.csv    o=./outdat/out53.csv
${pfxc}mbucket  -rng f=x:xb n=2 i=./indat/dat7.csv    o=./outdat/out55.csv

#k=指定
${pfxc}mbucket         k=id f=x:xb n=2 i=./indat/dat2s.csv    o=./outdat/out4.csv
${pfxc}mbucket -x      k=0  f=1:xb n=2 i=./indat/dat2s.csv    o=./outdat/out4x.csv
${pfxc}mbucket -nfn    k=0  f=1    n=2 i=./indat/dat2snfn.csv o=./outdat/out4nfn.csv
${pfxc}mbucket -nfno   k=id f=x:xb n=2 i=./indat/dat2s.csv    o=./outdat/out4nfno.csv
${pfxc}mbucket -q      k=id f=x:xb n=2 i=./indat/dat2s.csv    o=./outdat/out4q.csv
${pfxc}mbucket -q -nfn k=0  f=1    n=2 i=./indat/dat2snfn.csv o=./outdat/out4qnfn.csv

#f=複数指定
${pfxc}mbucket         k=id f=x:xb,y:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out5.csv
${pfxc}mbucket -x      k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out5x.csv
${pfxc}mbucket -nfn    k=0  f=1,2       n=3,2 i=./indat/dat2snfn.csv o=./outdat/out5nfn.csv
${pfxc}mbucket -q      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out5q.csv
${pfxc}mbucket -q -nfn k=0  f=1,2       n=3,2 i=./indat/dat2snfn.csv o=./outdat/out5qnfn.csv

#O=の指定
${pfxc}mbucket      f=x:xb,y:yb n=3 O=./outdat/out7.csv    i=./indat/dat1.csv    o=./outdat/out6.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=3 O=./outdat/out7x.csv   i=./indat/dat1.csv    o=./outdat/out6x.csv
${pfxc}mbucket -nfn f=1,2       n=3 O=./outdat/out7nfn.csv i=./indat/dat1nfn.csv o=./outdat/out6nfn.csv
${pfxc}mbucket -nfno f=x:xb,y:yb n=3 O=./outdat/out7nfno.csv  i=./indat/dat1.csv  o=./outdat/out6nfno.csv

#O=,k=のしてい
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out9.csv    i=./indat/dat2s.csv    o=./outdat/out8.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out9x.csv   i=./indat/dat2s.csv    o=./outdat/out8x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out9nfn.csv i=./indat/dat2snfn.csv o=./outdat/out8nfn.csv
${pfxc}mbucket -nfno k=id f=x:xb,y:yb n=2,2 O=./outdat/out9nfno.csv i=./indat/dat2s.csv    o=./outdat/out8nfno.csv

#F=0
${pfxc}mbucket      f=x:xb,y:yb F=0 n=3,3 i=./indat/dat1.csv    o=./outdat/out44.csv
${pfxc}mbucket -x   f=1:xb,2:yb F=0 n=3,3 i=./indat/dat1.csv    o=./outdat/out44x.csv
${pfxc}mbucket -nfn f=1,2       F=0 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out44nfn.csv
${pfxc}mbucket -nfno  f=x:xb,y:yb F=0 n=3,3 i=./indat/dat1.csv    o=./outdat/out44nfno.csv

#F=1
${pfxc}mbucket      f=x:xb,y:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mbucket -x   f=1:xb,2:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}mbucket -nfn f=1,2       F=1 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv
${pfxc}mbucket -nfno f=x:xb,y:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out10nfno.csv

#F=2
${pfxc}mbucket      f=x:xb,y:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}mbucket -x   f=1:xb,2:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}mbucket -nfn f=1,2       F=2 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv
${pfxc}mbucket -nfno f=x:xb,y:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out11nfno.csv

#F=1,k=のしてい
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out12.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out12x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=1 i=./indat/dat2snfn.csv o=./outdat/out12nfn.csv

#F=2,k=のしてい
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out13.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out13x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2snfn.csv o=./outdat/out13nfn.csv

#f=の指定数とn=の指定数が違う場合
${pfxc}mbucket      f=x:xb,y:yb n=2 i=./indat/dat1.csv    o=./outdat/out14.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2 i=./indat/dat1.csv    o=./outdat/out14x.csv
${pfxc}mbucket -nfn f=1,2       n=2 i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

#部分的にNULL値が含まれている時
${pfxc}mbucket      f=x:xb,y:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out15.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out15x.csv
${pfxc}mbucket -nfn f=1,2       n=2,2 i=./indat/dat3nfn.csv o=./outdat/out15nfn.csv

#部分的にNULL値が含まれている時k=
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out16.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out16x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat4snfn.csv o=./outdat/out16nfn.csv

#部分的にNULL値が含まれている時,F=1
${pfxc}mbucket      f=x:xb,y:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out17.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out17x.csv
${pfxc}mbucket -nfn f=1,2       n=2,2 F=1 i=./indat/dat3nfn.csv o=./outdat/out17nfn.csv

#部分的にNULL値が含まれている時,F=2
${pfxc}mbucket      f=x:xb,y:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out18.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out18x.csv
${pfxc}mbucket -nfn f=1,2       n=2,2 F=2 i=./indat/dat3nfn.csv o=./outdat/out18nfn.csv

#部分的にNULL値が含まれている時,O=
${pfxc}mbucket      f=x:xb,y:yb n=2,2 O=./outdat/out20.csv    i=./indat/dat3.csv    o=./outdat/out19.csv
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 O=./outdat/out20x.csv   i=./indat/dat3.csv    o=./outdat/out19x.csv
${pfxc}mbucket -nfn f=1,2       n=2,2 O=./outdat/out20nfn.csv i=./indat/dat3nfn.csv o=./outdat/out19nfn.csv

#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out21.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out21x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5snfn.csv o=./outdat/out21nfn.csv

#precision=5の指定
${pfxc}mbucket      f=x:xb,y:yb n=3 O=./outdat/out46.csv    i=./indat/dat6.csv    o=./outdat/out45.csv precision=5
${pfxc}mbucket -x   f=1:xb,2:yb n=3 O=./outdat/out46x.csv   i=./indat/dat6.csv    o=./outdat/out45x.csv precision=5
${pfxc}mbucket -nfn f=1,2       n=3 O=./outdat/out46nfn.csv i=./indat/dat6nfn.csv o=./outdat/out45nfn.csv precision=5
${pfxc}mbucket -nfno f=x:xb,y:yb n=3 O=./outdat/out46nfno.csv  i=./indat/dat6.csv  o=./outdat/out45nfno.csv precision=5

${pfxc}mbucket      f=x:xb,y:yb F=1 n=3,3 i=./indat/dat6.csv    o=./outdat/out47.csv precision=5
${pfxc}mbucket -x   f=1:xb,2:yb F=1 n=3,3 i=./indat/dat6.csv    o=./outdat/out47x.csv precision=5
${pfxc}mbucket -nfn f=1,2       F=1 n=3,3 i=./indat/dat6nfn.csv o=./outdat/out47nfn.csv precision=5
${pfxc}mbucket -nfno f=x:xb,y:yb F=1 n=3,3 i=./indat/dat6.csv    o=./outdat/out47nfno.csv precision=5

${pfxc}mbucket      f=x:xb,y:yb F=2 n=3,3 i=./indat/dat6.csv    o=./outdat/out48.csv precision=5
${pfxc}mbucket -x   f=1:xb,2:yb F=2 n=3,3 i=./indat/dat6.csv    o=./outdat/out48x.csv precision=5
${pfxc}mbucket -nfn f=1,2       F=2 n=3,3 i=./indat/dat6nfn.csv o=./outdat/out48nfn.csv precision=5
${pfxc}mbucket -nfno f=x:xb,y:yb F=2 n=3,3 i=./indat/dat6.csv    o=./outdat/out48nfno.csv precision=5

${pfxc}mbucket  f=x:xb,y:yb n=3,3 O=./outdat/out50.csv  i=./indat/dat6.csv  o=./outdat/out49.csv precision=5 -rng	

#bufcount=-1の指定
${pfxc}mbucket      f=x:xb,y:yb n=3 O=./outdat/out52.csv    i=./indat/dat6.csv    o=./outdat/out51.csv precision=5 bufcount=-1
${pfxc}mbucket -x   f=1:xb,2:yb n=3 O=./outdat/out52x.csv   i=./indat/dat6.csv    o=./outdat/out51x.csv precision=5 bufcount=-1
${pfxc}mbucket -nfn f=1,2       n=3 O=./outdat/out52nfn.csv i=./indat/dat6nfn.csv o=./outdat/out51nfn.csv precision=5 bufcount=-1
${pfxc}mbucket -nfno f=x:xb,y:yb n=3 O=./outdat/out52nfno.csv  i=./indat/dat6.csv  o=./outdat/out51nfno.csv precision=5 bufcount=-1

#ここ以降は-rngパラメータを使用した場合

#NULL
${pfxc}mbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out22.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out22x.csv   -rng
${pfxc}mbucket -nfn f=2,3       n=2,2 i=./indat/dat0nfn.csv o=./outdat/out22nfn.csv -rng

${pfxc}mbucket      f=x:xb,y:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out23.csv    O=./outdat/out24.csv -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat0.csv    o=./outdat/out23x.csv   O=./outdat/out24x.csv -rng
${pfxc}mbucket -nfn f=2,3       n=2,2 i=./indat/dat0nfn.csv o=./outdat/out23nfn.csv O=./outdat/out24nfn.csv -rng

#基本
${pfxc}mbucket      f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out25.csv    -rng
${pfxc}mbucket -x   f=1:xb n=2 i=./indat/dat1.csv    o=./outdat/out25x.csv   -rng
${pfxc}mbucket -nfn f=1    n=2 i=./indat/dat1nfn.csv o=./outdat/out25nfn.csv -rng
${pfxc}mbucket -nfno f=x:xb n=2 i=./indat/dat1.csv    o=./outdat/out25nfno.csv    -rng

#k=指定
${pfxc}mbucket      k=id f=x:xb n=2 i=./indat/dat2s.csv    o=./outdat/out26.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb n=2 i=./indat/dat2s.csv    o=./outdat/out26x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1    n=2 i=./indat/dat2snfn.csv o=./outdat/out26nfn.csv -rng

#f=複数指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out27.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2s.csv    o=./outdat/out27x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=3,2 i=./indat/dat2snfn.csv o=./outdat/out27nfn.csv -rng

#O=の指定
${pfxc}mbucket      f=x:xb,y:yb n=3 O=./outdat/out29.csv    i=./indat/dat1.csv    o=./outdat/out28.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=3 O=./outdat/out29x.csv   i=./indat/dat1.csv    o=./outdat/out28x.csv   -rng
${pfxc}mbucket -nfn f=1,2       n=3 O=./outdat/out29nfn.csv i=./indat/dat1nfn.csv o=./outdat/out28nfn.csv -rng

#O=,k=の指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out31.csv    i=./indat/dat2s.csv    o=./outdat/out30.csv -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out31x.csv   i=./indat/dat2s.csv    o=./outdat/out30x.csv -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out31nfn.csv i=./indat/dat2snfn.csv o=./outdat/out30nfn.csv -rng

#F=1
${pfxc}mbucket      f=x:xb,y:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out32.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb F=1 n=3,3 i=./indat/dat1.csv    o=./outdat/out32x.csv   -rng
${pfxc}mbucket -nfn f=1,2       F=1 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv -rng

#F=2
${pfxc}mbucket      f=x:xb,y:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out33.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb F=2 n=3,3 i=./indat/dat1.csv    o=./outdat/out33x.csv   -rng
${pfxc}mbucket -nfn f=1,2       F=2 n=3,3 i=./indat/dat1nfn.csv o=./outdat/out33nfn.csv -rng

#F=1,k=の指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out34.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=1 i=./indat/dat2s.csv    o=./outdat/out34x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=1 i=./indat/dat2snfn.csv o=./outdat/out34nfn.csv -rng

#F=2,k=の指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out35.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2s.csv    o=./outdat/out35x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2snfn.csv o=./outdat/out35nfn.csv -rng

#f=の指定数とn=の指定数が違う場合
${pfxc}mbucket      f=x:xb,y:yb n=2 i=./indat/dat1.csv    o=./outdat/out36.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2 i=./indat/dat1.csv    o=./outdat/out36x.csv   -rng
${pfxc}mbucket -nfn f=1,2       n=2 i=./indat/dat1nfn.csv o=./outdat/out36nfn.csv -rng

#部分的にNULL値が含まれている時
${pfxc}mbucket      f=x:xb,y:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out37.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 i=./indat/dat3.csv    o=./outdat/out37x.csv   -rng
${pfxc}mbucket -nfn f=1,2       n=2,2 i=./indat/dat3nfn.csv o=./outdat/out37nfn.csv -rng

#部分的にNULL値が含まれている時k=
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4s.csv    o=./outdat/out38.csv    -rng
${pfxc}mbucket -x   k=0 f=1:xb,2:yb  n=2,2 i=./indat/dat4s.csv    o=./outdat/out38x.csv   -rng
${pfxc}mbucket -nfn k=0 f=1,2        n=2,2 i=./indat/dat4snfn.csv o=./outdat/out38nfn.csv -rng

#部分的にNULL値が含まれている時,F=1
${pfxc}mbucket      f=x:xb,y:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out39.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 F=1 i=./indat/dat3.csv    o=./outdat/out39x.csv   -rng
${pfxc}mbucket -nfn f=1,2       n=2,2 F=1 i=./indat/dat3nfn.csv o=./outdat/out39nfn.csv -rng

#部分的にNULL値が含まれている時,F=2
${pfxc}mbucket      f=x:xb,y:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out40.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 F=2 i=./indat/dat3.csv    o=./outdat/out40x.csv   -rng
${pfxc}mbucket -nfn f=1,2       n=2,2 F=2 i=./indat/dat3nfn.csv o=./outdat/out40nfn.csv -rng

#部分的にNULL値が含まれている時,O=
${pfxc}mbucket      f=x:xb,y:yb n=2,2 O=./outdat/out42.csv    i=./indat/dat3.csv    o=./outdat/out41.csv    -rng
${pfxc}mbucket -x   f=1:xb,2:yb n=2,2 O=./outdat/out42x.csv   i=./indat/dat3.csv    o=./outdat/out41x.csv   -rng
${pfxc}mbucket -nfn f=1,2       n=2,2 O=./outdat/out42nfn.csv i=./indat/dat3nfn.csv o=./outdat/out41nfn.csv -rng

#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out43.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5s.csv    o=./outdat/out43x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5snfn.csv o=./outdat/out43nfn.csv -rng

#maxとminが同じデータ
${pfxc}mbucket      f=x:xb n=2 i=./indat/dat8.csv    o=./outdat/out54.csv





#ランダムデータ
#k=指定
${pfxc}mbucket      k=id f=x:xb n=2 i=./indat/dat2.csv    o=./outdat/out56.csv
${pfxc}mbucket -x   k=0  f=1:xb n=2 i=./indat/dat2.csv    o=./outdat/out56x.csv
${pfxc}mbucket -nfn k=0  f=1    n=2 i=./indat/dat2nfn.csv o=./outdat/out56nfn.csv
${pfxc}mbucket -nfno k=id f=x:xb n=2 i=./indat/dat2.csv    o=./outdat/out56nfno.csv
${pfxc}mbucket -q      k=id f=x:xb n=2 i=./indat/dat2.csv    o=./outdat/out56q.csv
${pfxc}mbucket -q -nfn k=0  f=1    n=2 i=./indat/dat2nfn.csv o=./outdat/out56qnfn.csv

#f=複数指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out57.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out57x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=3,2 i=./indat/dat2nfn.csv o=./outdat/out57nfn.csv
${pfxc}mbucket -q      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out57q.csv
${pfxc}mbucket -q -nfn k=0  f=1,2       n=3,2 i=./indat/dat2nfn.csv o=./outdat/out57qnfn.csv

#O=,k=のしてい
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out59.csv    i=./indat/dat2.csv    o=./outdat/out58.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out59x.csv   i=./indat/dat2.csv    o=./outdat/out58x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out59nfn.csv i=./indat/dat2nfn.csv o=./outdat/out58nfn.csv
${pfxc}mbucket -nfno k=id f=x:xb,y:yb n=2,2 O=./outdat/out59nfno.csv i=./indat/dat2.csv    o=./outdat/out58nfno.csv

#F=1,k=のしてい
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=1 i=./indat/dat2.csv    o=./outdat/out60.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=1 i=./indat/dat2.csv    o=./outdat/out60x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=1 i=./indat/dat2nfn.csv o=./outdat/out60nfn.csv

#F=2,k=のしてい
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2.csv    o=./outdat/out61.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2.csv    o=./outdat/out61x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2nfn.csv o=./outdat/out61nfn.csv

#部分的にNULL値が含まれている時k=
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4.csv    o=./outdat/out62.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 i=./indat/dat4.csv    o=./outdat/out62x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 i=./indat/dat4nfn.csv o=./outdat/out62nfn.csv

#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5.csv    o=./outdat/out63.csv
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5.csv    o=./outdat/out63x.csv
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5nfn.csv o=./outdat/out63nfn.csv

#k=指定
${pfxc}mbucket      k=id f=x:xb n=2 i=./indat/dat2.csv    o=./outdat/out64.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb n=2 i=./indat/dat2.csv    o=./outdat/out64x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1    n=2 i=./indat/dat2nfn.csv o=./outdat/out64nfn.csv -rng

#f=複数指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out65.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,2 i=./indat/dat2.csv    o=./outdat/out65x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=3,2 i=./indat/dat2nfn.csv o=./outdat/out65nfn.csv -rng

#O=,k=の指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 O=./outdat/out67.csv    i=./indat/dat2.csv    o=./outdat/out66.csv -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 O=./outdat/out67x.csv   i=./indat/dat2.csv    o=./outdat/out66x.csv -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 O=./outdat/out67nfn.csv i=./indat/dat2nfn.csv o=./outdat/out66nfn.csv -rng

#F=1,k=の指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=1 i=./indat/dat2.csv    o=./outdat/out68.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=1 i=./indat/dat2.csv    o=./outdat/out68x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=1 i=./indat/dat2nfn.csv o=./outdat/out68nfn.csv -rng

#F=2,k=の指定
${pfxc}mbucket      k=id f=x:xb,y:yb n=3,3 F=2 i=./indat/dat2.csv    o=./outdat/out69.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=3,3 F=2 i=./indat/dat2.csv    o=./outdat/out69x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=3,3 F=2 i=./indat/dat2nfn.csv o=./outdat/out69nfn.csv -rng

#部分的にNULL値が含まれている時k=
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 i=./indat/dat4.csv    o=./outdat/out70.csv    -rng
${pfxc}mbucket -x   k=0 f=1:xb,2:yb  n=2,2 i=./indat/dat4.csv    o=./outdat/out70x.csv   -rng
${pfxc}mbucket -nfn k=0 f=1,2        n=2,2 i=./indat/dat4nfn.csv o=./outdat/out70nfn.csv -rng


#部分的にNULL値が含まれている時,key項目にNULL
${pfxc}mbucket      k=id f=x:xb,y:yb n=2,2 F=2 i=./indat/dat5.csv    o=./outdat/out71.csv    -rng
${pfxc}mbucket -x   k=0  f=1:xb,2:yb n=2,2 F=2 i=./indat/dat5.csv    o=./outdat/out71x.csv   -rng
${pfxc}mbucket -nfn k=0  f=1,2       n=2,2 F=2 i=./indat/dat5nfn.csv o=./outdat/out71nfn.csv -rng


