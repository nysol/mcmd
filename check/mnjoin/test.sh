#!/bin/bash

. ../env
#name_kg_mcmd njoin

#NULL(tra,mstのどちらかがNULLデータ)
${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out1.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out1x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat0snfn.csv o=./outdat/out1nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out2.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out2x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat2snfn.csv o=./outdat/out2nfn.csv
${pfxc}mnjoin -nfno  k=商品 m=./indat/dat1s.csv  i=./indat/dat2s.csv    o=./outdat/out2nfno.csv

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out3.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out3x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat0snfn.csv o=./outdat/out3nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out4.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out4x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat0snfn.csv o=./outdat/out4nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out5.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out5x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat2snfn.csv o=./outdat/out5nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out6.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out6x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat0snfn.csv o=./outdat/out6nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out7.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out7x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat0snfn.csv o=./outdat/out7nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out8.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out8x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat2snfn.csv o=./outdat/out8nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out9.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat0s.csv    o=./outdat/out9x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat0snfn.csv o=./outdat/out9nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out10.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat0s.csv    o=./outdat/out10x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat0snfn.csv o=./outdat/out10nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out11.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1s.csv    i=./indat/dat2s.csv    o=./outdat/out11x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1snfn.csv i=./indat/dat2snfn.csv o=./outdat/out11nfn.csv -n -N

#基本
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out12.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out12x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out12nfn.csv
${pfxc}mnjoin -q     k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out12q.csv
${pfxc}mnjoin -q -x  k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out12qx.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out13.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out13x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out13nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out14.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out14x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out14nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out15.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out15x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv -n -N

#f=２つ
${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out16.csv
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out16x.csv
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out16nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out17.csv    -n
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out17x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out17nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out18.csv    -N
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out18x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out18nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out19.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out19x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out19nfn.csv -n -N

#f=なし
${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out20.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out20x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out20nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out21.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out21x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out21nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out22.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out22x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out22nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out23.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out23x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out23nfn.csv -n -N

#k=二つ
${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out24.csv
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out24x.csv
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out24nfn.csv

${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out25.csv    -n
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out25x.csv   -n
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out25nfn.csv -n

${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out26.csv    -N
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out26x.csv   -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out26nfn.csv -N

${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out27.csv    -n -N
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out27x.csv   -n -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out27nfn.csv -n -N

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out28.csv
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out28x.csv
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out28nfn.csv

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out29.csv    -n
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out29x.csv   -n
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out29nfn.csv -n

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out30.csv    -N
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out30x.csv   -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out30nfn.csv -N

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out31.csv    -n -N
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out31x.csv   -n -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out31nfn.csv -n -N

#K=を指定
${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out32.csv
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out32x.csv
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out32nfn.csv

${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out33.csv    -n
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out33x.csv   -n
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out33nfn.csv -n

${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out34.csv    -N
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out34x.csv   -N
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out34nfn.csv -N

${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out35.csv    -n -N
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out35x.csv    -n -N
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out35nfn.csv -n -N

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out36.csv
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out36x.csv
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out36nfn.csv

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out37.csv    -n
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out37x.csv   -n
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out37nfn.csv -n

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out38.csv    -N
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out38x.csv   -N
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out38nfn.csv -N

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out39.csv    -n -N
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out39x.csv   -n -N
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3snfn.csv i=./indat/dat2snfn.csv o=./outdat/out39nfn.csv -n -N

#K=を指定２つ
${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out40.csv
${pfxc}mnjoin -x   k=0,1       K=0,3       f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out40x.csv
${pfxc}mnjoin -nfn k=0,1       K=0,3       f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out40nfn.csv

${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out41.csv    -n
${pfxc}mnjoin -x   k=0,1       K=0,3       f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out41x.csv   -n
${pfxc}mnjoin -nfn k=0,1       K=0,3       f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out41nfn.csv -n

${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out42.csv    -N
${pfxc}mnjoin -x   k=0,1       K=0,3       f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out42x.csv   -N
${pfxc}mnjoin -nfn k=0,1       K=0,3       f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out42nfn.csv -N

${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out43.csv    -n -N
${pfxc}mnjoin -x   k=0,1       K=0,3       f=1        m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out43x.csv   -n -N
${pfxc}mnjoin -nfn k=0,1       K=0,3       f=1        m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out43nfn.csv -n -N

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out44.csv
${pfxc}mnjoin -x   k=0,1       K=0,3       m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out44x.csv
${pfxc}mnjoin -nfn k=0,1       K=0,3       m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out44nfn.csv

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out45.csv    -n
${pfxc}mnjoin -x   k=0,1       K=0,3       m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out45x.csv   -n
${pfxc}mnjoin -nfn k=0,1       K=0,3       m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out45nfn.csv -n

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out46.csv    -N
${pfxc}mnjoin -x   k=0,1       K=0,3       m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out46x.csv   -N
${pfxc}mnjoin -nfn k=0,1       K=0,3       m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out46nfn.csv -N

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out47.csv    -n -N
${pfxc}mnjoin -x   k=0,1       K=0,3       m=./indat/dat4s.csv    i=./indat/dat2s.csv    o=./outdat/out47x.csv   -n -N
${pfxc}mnjoin -nfn k=0,1       K=0,3       m=./indat/dat4snfn.csv i=./indat/dat2snfn.csv o=./outdat/out47nfn.csv -n -N

#kにNULL
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out48.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out48x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out48nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out49.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out49x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out49nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out50.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out50x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out50nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out51.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out51x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out51nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out52.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out52x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out52nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out53.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out53x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out53nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out54.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out54x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out54nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out55.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3s.csv    i=./indat/dat5s.csv    o=./outdat/out55x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3snfn.csv i=./indat/dat5snfn.csv o=./outdat/out55nfn.csv -n -N

#KにNULL
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out56.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out56x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out56nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out57.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out57x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out57nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out58.csv    -N 
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out58x.csv   -N 
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out58nfn.csv -N 

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out59.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out59x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out59nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out60.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out60x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out60nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out61.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out61x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out61nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out62.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out62x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out62nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out63.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat2s.csv    o=./outdat/out63x.csv    -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat2snfn.csv o=./outdat/out63nfn.csv -n -N

#k,KにNULL
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out64.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out64x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out64nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out65.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out65x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out65nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out66.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out66x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out66nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out67.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out67x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out67nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out68.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out68x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out68nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out69.csv    -n
${pfxc}mnjoin -x   k=0   m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out69x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out69nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out70.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out70x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out70nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out71.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6s.csv    i=./indat/dat5s.csv    o=./outdat/out71x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6snfn.csv i=./indat/dat5snfn.csv o=./outdat/out71nfn.csv -n -N

#traが先に終わる
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out72.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out72x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out72nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out73.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out73x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out73nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out74.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out74x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out74nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out75.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out75x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out75nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out76.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out76x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out76nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out77.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out77x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out77nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out78.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out78x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out78nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out79.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat7s.csv    i=./indat/dat2s.csv    o=./outdat/out79x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat7snfn.csv i=./indat/dat2snfn.csv o=./outdat/out79nfn.csv -n -N

#マスタが先に終わる
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out80.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out80x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out80nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out81.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out81x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out81nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out82.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out82x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out82nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out83.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out83x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out83nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out84.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out84x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out84nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out85.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out85x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out85nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out86.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out86x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out86nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out87.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat8s.csv    i=./indat/dat2s.csv    o=./outdat/out87x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat8snfn.csv i=./indat/dat2snfn.csv o=./outdat/out87nfn.csv -n -N

#同時に終わる
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out88.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out88x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out88nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out89.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out89x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out89nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out90.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out90x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out90nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out91.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out91x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out91nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out92.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out92x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out92nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out93.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out93x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out93nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out94.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out94x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out94nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out95.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat9s.csv    i=./indat/dat2s.csv    o=./outdat/out95x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat9snfn.csv i=./indat/dat2snfn.csv o=./outdat/out95nfn.csv -n -N

#bufcount
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out96.csv bufcount=-2
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3s.csv    i=./indat/dat2s.csv    o=./outdat/out97.csv bufcount=2


#-----------------------------------------------------------------
# 以下ランダムデータ
#-----------------------------------------------------------------

#NULL(tra,mstのどちらかがNULLデータ)
${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out100.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out100x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out100nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out101.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out101x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat0nfn.csv o=./outdat/out101nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out102.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out102x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out102nfn.csv
${pfxc}mnjoin -nfno  k=商品 m=./indat/dat1.csv  i=./indat/dat2.csv    o=./outdat/out102nfno.csv

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out103.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out103x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out103nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out104.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out104x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat0nfn.csv o=./outdat/out104nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out105.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out105x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out105nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out106.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out106x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out106nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out107.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out107x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat0nfn.csv o=./outdat/out107nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out108.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out108x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out108nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out109.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out109x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out109nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out110.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out110x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat0nfn.csv o=./outdat/out110nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out111.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out111x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out111nfn.csv -n -N

#基本
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out112.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out112x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out112nfn.csv
${pfxc}mnjoin -q    k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out112q.csv
${pfxc}mnjoin -x -q k=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out112qx.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out113.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out113x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out113nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out114.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out114x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out114nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out115.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out115x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out115nfn.csv -n -N

#f=２つ
${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out116.csv
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out116x.csv
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out116nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out117.csv    -n
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out117x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out117nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out118.csv    -N
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out118x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out118nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out119.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1,2             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out119x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1,2             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out119nfn.csv -n -N

#f=なし
${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out120.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out120x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out120nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out121.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out121x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out121nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out122.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out122x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out122nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out123.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out123x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out123nfn.csv -n -N

#k=二つ
${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out124.csv
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out124x.csv
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out124nfn.csv

${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out125.csv    -n
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out125x.csv   -n
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out125nfn.csv -n

${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out126.csv    -N
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out126x.csv   -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out126nfn.csv -N

${pfxc}mnjoin      k=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out127.csv    -n -N
${pfxc}mnjoin -x   k=0,1 K=0,3 f=1        m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out127x.csv   -n -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 f=1        m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out127nfn.csv -n -N

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out128.csv
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out128x.csv
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out128nfn.csv

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out129.csv    -n
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out129x.csv   -n
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out129nfn.csv -n

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out130.csv    -N
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out130x.csv   -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out130nfn.csv -N

${pfxc}mnjoin      k=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out131.csv    -n -N
${pfxc}mnjoin -x   k=0,1 K=0,3 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out131x.csv   -n -N
${pfxc}mnjoin -nfn k=0,1 K=0,3 m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out131nfn.csv -n -N

#K=を指定
${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out132.csv
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out132x.csv
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out132nfn.csv

${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out133.csv    -n
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out133x.csv   -n
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out133nfn.csv -n

${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out134.csv    -N
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out134x.csv   -N
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out134nfn.csv -N

${pfxc}mnjoin      k=商品 K=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out135.csv    -n -N
${pfxc}mnjoin -x   k=0    K=0    f=1        m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out135x.csv    -n -N
${pfxc}mnjoin -nfn k=0    K=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out135nfn.csv -n -N

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out136.csv
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out136x.csv
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out136nfn.csv

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out137.csv    -n
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out137x.csv   -n
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out137nfn.csv -n

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out138.csv    -N
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out138x.csv   -N
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out138nfn.csv -N

${pfxc}mnjoin      k=商品 K=商品 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out139.csv    -n -N
${pfxc}mnjoin -x   k=0    K=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out139x.csv   -n -N
${pfxc}mnjoin -nfn k=0    K=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out139nfn.csv -n -N

#K=を指定２つ
${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out140.csv

${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out141.csv    -n

${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out142.csv    -N

${pfxc}mnjoin      k=商品,日付 K=商品,日付 f=仕入価格 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out143.csv    -n -N

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out144.csv

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out145.csv    -n

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out146.csv    -N

${pfxc}mnjoin      k=商品,日付 K=商品,日付 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out147.csv    -n -N

##ここまで済み

#kにNULL
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out148.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out148x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out148nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out149.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out149x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out149nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out150.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out150x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out150nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out151.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out151x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out151nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out152.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out152x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out152nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out153.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out153x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out153nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out154.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out154x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out154nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out155.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat3.csv    i=./indat/dat5.csv    o=./outdat/out155x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat3nfn.csv i=./indat/dat5nfn.csv o=./outdat/out155nfn.csv -n -N

#KにNULL
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out156.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out156x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out156nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out157.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out157x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out157nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out158.csv    -N 
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out158x.csv   -N 
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out158nfn.csv -N 

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out159.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out159x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out159nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out160.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out160x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out160nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out161.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out161x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out161nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out162.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out162x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out162nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out163.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out163x.csv    -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out163nfn.csv -n -N

#k,KにNULL
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out164.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out164x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out164nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out165.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out165x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out165nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out166.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out166x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out166nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out167.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out167x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out167nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out168.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out168x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out168nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out169.csv    -n
${pfxc}mnjoin -x   k=0   m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out169x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out169nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out170.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out170x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out170nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out171.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out171x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out171nfn.csv -n -N

#traが先に終わる
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out172.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out172x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out172nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out173.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out173x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out173nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out174.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out174x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out174nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out175.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out175x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out175nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out176.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out176x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out176nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out177.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out177x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out177nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out178.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out178x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out178nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out179.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat7.csv    i=./indat/dat2.csv    o=./outdat/out179x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat7nfn.csv i=./indat/dat2nfn.csv o=./outdat/out179nfn.csv -n -N

#マスタが先に終わる
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out180.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out180x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out180nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out181.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out181x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out181nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out182.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out182x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out182nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out183.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out183x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out183nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out184.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out184x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out184nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out185.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out185x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out185nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out186.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out186x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out186nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out187.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat8.csv    i=./indat/dat2.csv    o=./outdat/out187x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat8nfn.csv i=./indat/dat2nfn.csv o=./outdat/out187nfn.csv -n -N

#同時に終わる
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out188.csv
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out188x.csv
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out188nfn.csv

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out189.csv    -n
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out189x.csv   -n
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out189nfn.csv -n

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out190.csv    -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out190x.csv   -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out190nfn.csv -N

${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out191.csv    -n -N
${pfxc}mnjoin -x   k=0    f=1        m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out191x.csv   -n -N
${pfxc}mnjoin -nfn k=0    f=1        m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out191nfn.csv -n -N

${pfxc}mnjoin      k=商品 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out192.csv
${pfxc}mnjoin -x   k=0    m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out192x.csv
${pfxc}mnjoin -nfn k=0    m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out192nfn.csv

${pfxc}mnjoin      k=商品 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out193.csv    -n
${pfxc}mnjoin -x   k=0    m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out193x.csv   -n
${pfxc}mnjoin -nfn k=0    m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out193nfn.csv -n

${pfxc}mnjoin      k=商品 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out194.csv    -N
${pfxc}mnjoin -x   k=0    m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out194x.csv   -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out194nfn.csv -N

${pfxc}mnjoin      k=商品 m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out195.csv    -n -N
${pfxc}mnjoin -x   k=0    m=./indat/dat9.csv    i=./indat/dat2.csv    o=./outdat/out195x.csv   -n -N
${pfxc}mnjoin -nfn k=0    m=./indat/dat9nfn.csv i=./indat/dat2nfn.csv o=./outdat/out195nfn.csv -n -N

#bufcount
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out196.csv bufcount=-2
${pfxc}mnjoin      k=商品 f=仕入価格 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out197.csv bufcount=2




