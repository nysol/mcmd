#!/bin/bash

. ../env

#name_kg_mcmd rjoin

#nullデータ
${pfxc}mrjoin      rf=金額%n m=./indat/ref0n.csv    R=範囲 f=分類 i=./indat/dat0n.csv    o=./outdat/out0.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0n.csv    R=0    f=1    i=./indat/dat0n.csv    o=./outdat/out0x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nnfn.csv R=0    f=1    i=./indat/dat0nnfn.csv o=./outdat/out0nfn.csv

${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat0n.csv    o=./outdat/out1.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat0n.csv    o=./outdat/out1x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    f=1    i=./indat/dat0nnfn.csv o=./outdat/out1nfn.csv

${pfxc}mrjoin      rf=金額%n m=./indat/ref0n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out2.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out2x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nnfn.csv R=0    f=1    i=./indat/dat1nnfn.csv o=./outdat/out2nfn.csv

${pfxc}mrjoin      rf=金額%n m=./indat/ref0n.csv    R=範囲 f=分類 i=./indat/dat0n.csv    o=./outdat/out3.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0n.csv    R=0    f=1    i=./indat/dat0n.csv    o=./outdat/out3x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nnfn.csv R=0    f=1    i=./indat/dat0nnfn.csv o=./outdat/out3nfn.csv -n

${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat0n.csv    o=./outdat/out4.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat0n.csv    o=./outdat/out4x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    f=1    i=./indat/dat0nnfn.csv o=./outdat/out4nfn.csv -n

${pfxc}mrjoin      rf=金額%n m=./indat/ref0n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out5.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out5x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nnfn.csv R=0    f=1    i=./indat/dat1nnfn.csv o=./outdat/out5nfn.csv -n

#基本
${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out6.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out6x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    f=1    i=./indat/dat1nnfn.csv o=./outdat/out6nfn.csv
${pfxc}mrjoin -q      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out6q.csv
${pfxc}mrjoin -q -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out6qx.csv

#-n
${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out7.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out7x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    f=1    i=./indat/dat1nnfn.csv o=./outdat/out7nfn.csv -n

#-lo
${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out8.csv    -lo
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out8x.csv   -lo
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    f=1    i=./indat/dat1nnfn.csv o=./outdat/out8nfn.csv -lo

#-lo -n
${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 f=分類 i=./indat/dat1n.csv    o=./outdat/out9.csv    -lo -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    f=1    i=./indat/dat1n.csv    o=./outdat/out9x.csv   -lo -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    f=1    i=./indat/dat1nnfn.csv o=./outdat/out9nfn.csv -lo -n

#f=省略
${pfxc}mrjoin      rf=金額%n m=./indat/ref1n.csv    R=範囲 i=./indat/dat1n.csv    o=./outdat/out10.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1n.csv    R=0    i=./indat/dat1n.csv    o=./outdat/out10x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nnfn.csv R=0    i=./indat/dat1nnfn.csv o=./outdat/out10nfn.csv

#文字順
${pfxc}mrjoin      rf=金額 m=./indat/ref2s.csv    R=範囲 f=分類 i=./indat/dat2s.csv    o=./outdat/out11.csv
${pfxc}mrjoin -x   rf=0    m=./indat/ref2s.csv    R=0    f=1    i=./indat/dat2s.csv    o=./outdat/out11x.csv
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2snfn.csv R=0    f=1    i=./indat/dat2snfn.csv o=./outdat/out11nfn.csv
${pfxc}mrjoin -nfno rf=金額 m=./indat/ref2s.csv    R=範囲 f=分類 i=./indat/dat2s.csv    o=./outdat/out11nfno.csv

${pfxc}mrjoin      rf=金額 m=./indat/ref2s.csv    R=範囲 f=分類 i=./indat/dat2s.csv    o=./outdat/out12.csv    -n
${pfxc}mrjoin -x   rf=0    m=./indat/ref2s.csv    R=0    f=1    i=./indat/dat2s.csv    o=./outdat/out12x.csv   -n
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2snfn.csv R=0    f=1    i=./indat/dat2snfn.csv o=./outdat/out12nfn.csv -n

${pfxc}mrjoin      rf=金額 m=./indat/ref2s.csv    R=範囲 f=分類 i=./indat/dat2s.csv    o=./outdat/out13.csv    -lo
${pfxc}mrjoin -x   rf=0    m=./indat/ref2s.csv    R=0    f=1    i=./indat/dat2s.csv    o=./outdat/out13x.csv   -lo
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2snfn.csv R=0    f=1    i=./indat/dat2snfn.csv o=./outdat/out13nfn.csv -lo

${pfxc}mrjoin      rf=金額 m=./indat/ref2s.csv    R=範囲 f=分類 i=./indat/dat2s.csv    o=./outdat/out14.csv    -lo -n
${pfxc}mrjoin -x   rf=0    m=./indat/ref2s.csv    R=0    f=1    i=./indat/dat2s.csv    o=./outdat/out14x.csv   -lo -n
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2snfn.csv R=0    f=1    i=./indat/dat2snfn.csv o=./outdat/out14nfn.csv -lo -n

${pfxc}mrjoin      rf=金額 m=./indat/ref2s.csv    R=範囲 i=./indat/dat2s.csv    o=./outdat/out15.csv
${pfxc}mrjoin -x   rf=0    m=./indat/ref2s.csv    R=0    i=./indat/dat2s.csv    o=./outdat/out15x.csv
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2snfn.csv R=0    i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv

#範囲に含まれないデータがある場合
${pfxc}mrjoin      rf=金額 m=./indat/ref9s.csv    R=範囲 f=分類 i=./indat/dat2s.csv    o=./outdat/out72.csv

#k=指定
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類 i=./indat/dat3n.csv    o=./outdat/out16.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2    i=./indat/dat3n.csv    o=./outdat/out16x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2    i=./indat/dat3nnfn.csv o=./outdat/out16nfn.csv
${pfxc}mrjoin -q     k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類 i=./indat/dat3n.csv    o=./outdat/out16q.csv
${pfxc}mrjoin -q -x  k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2    i=./indat/dat3n.csv    o=./outdat/out16qx.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out17.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out17x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out17nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out18.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out18x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out18nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out19.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out19x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out19nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類 i=./indat/dat4s.csv    o=./outdat/out20.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2    i=./indat/dat4s.csv    o=./outdat/out20x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2    i=./indat/dat4snfn.csv o=./outdat/out20nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out21.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out21x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out21nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out22.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out22x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out22nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out23.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out23x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out23nfn.csv -lo -n

#R=指定なし
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    f=分類 i=./indat/dat3n.csv    o=./outdat/out24.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    f=2    i=./indat/dat3n.csv    o=./outdat/out24x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv f=2    i=./indat/dat3nnfn.csv o=./outdat/out24nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out25.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    f=2,3         i=./indat/dat3n.csv    o=./outdat/out25x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out25nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out26.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    f=2,3         i=./indat/dat3n.csv    o=./outdat/out26x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out26nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out27.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    f=2,3         i=./indat/dat3n.csv    o=./outdat/out27x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out27nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    f=分類 i=./indat/dat4s.csv    o=./outdat/out28.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    f=2    i=./indat/dat4s.csv    o=./outdat/out28x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv f=2    i=./indat/dat4snfn.csv o=./outdat/out28nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out29.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    f=2,3         i=./indat/dat4s.csv    o=./outdat/out29x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv f=2,3         i=./indat/dat4snfn.csv o=./outdat/out29nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out30.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    f=2,3         i=./indat/dat4s.csv    o=./outdat/out30x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv f=2,3         i=./indat/dat4snfn.csv o=./outdat/out30nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out31.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    f=2,3         i=./indat/dat4s.csv    o=./outdat/out31x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv f=2,3         i=./indat/dat4snfn.csv o=./outdat/out31nfn.csv -lo -n

#k=,K=指定
${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類 i=./indat/dat3n.csv    o=./outdat/out32.csv
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2    i=./indat/dat3n.csv    o=./outdat/out32x.csv
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2    i=./indat/dat3nnfn.csv o=./outdat/out32nfn.csv

${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out33.csv    -n
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out33x.csv   -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out33nfn.csv -n

${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out34.csv    -lo
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out34x.csv   -lo
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out34nfn.csv -lo

${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out35.csv    -lo -n
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out35x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out35nfn.csv -lo -n

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類 i=./indat/dat4s.csv    o=./outdat/out36.csv
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4s.csv    R=1    f=2    i=./indat/dat4s.csv    o=./outdat/out36x.csv
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4snfn.csv R=1   f=2   i=./indat/dat4snfn.csv o=./outdat/out36nfn.csv

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out37.csv    -n
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out37x.csv   -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out37nfn.csv -n

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out38.csv    -lo
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out38x.csv   -lo
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out38nfn.csv -lo

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out39.csv    -lo -n
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out39x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out39nfn.csv -lo -n

#ここまでOK
#k=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類 i=./indat/dat5n.csv    o=./outdat/out40.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2    i=./indat/dat5n.csv    o=./outdat/out40x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2    i=./indat/dat5nnfn.csv o=./outdat/out40nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat5n.csv    o=./outdat/out41.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat5n.csv    o=./outdat/out41x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat5nnfn.csv o=./outdat/out41nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat5n.csv    o=./outdat/out42.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat5n.csv    o=./outdat/out42x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat5nnfn.csv o=./outdat/out42nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat5n.csv    o=./outdat/out43.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat5n.csv    o=./outdat/out43x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat5nnfn.csv o=./outdat/out43nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類 i=./indat/dat6s.csv    o=./outdat/out44.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2    i=./indat/dat6s.csv    o=./outdat/out44x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2    i=./indat/dat6snfn.csv o=./outdat/out44nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat6s.csv    o=./outdat/out45.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat6s.csv    o=./outdat/out45x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat6snfn.csv o=./outdat/out45nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat6s.csv    o=./outdat/out46.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat6s.csv    o=./outdat/out46x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat6snfn.csv o=./outdat/out46nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat6s.csv    o=./outdat/out47.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat6s.csv    o=./outdat/out47x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat6snfn.csv o=./outdat/out47nfn.csv -lo -n

#K=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類 i=./indat/dat3n.csv    o=./outdat/out48.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2    i=./indat/dat3n.csv    o=./outdat/out48x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2    i=./indat/dat3nnfn.csv o=./outdat/out48nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out49.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out49x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out49nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out50.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out50x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out50nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類,ランク i=./indat/dat3n.csv    o=./outdat/out51.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2,3         i=./indat/dat3n.csv    o=./outdat/out51x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2,3         i=./indat/dat3nnfn.csv o=./outdat/out51nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類 i=./indat/dat4s.csv    o=./outdat/out52.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2    i=./indat/dat4s.csv    o=./outdat/out52x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2    i=./indat/dat4snfn.csv o=./outdat/out52nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out53.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out53x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out53nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out54.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out54x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out54nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類,ランク i=./indat/dat4s.csv    o=./outdat/out55.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2,3         i=./indat/dat4s.csv    o=./outdat/out55x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2,3         i=./indat/dat4snfn.csv o=./outdat/out55nfn.csv -lo -n

#K=,K=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類 i=./indat/dat5n.csv    o=./outdat/out56.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2    i=./indat/dat5n.csv    o=./outdat/out56x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2    i=./indat/dat5nnfn.csv o=./outdat/out56nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類,ランク i=./indat/dat5n.csv    o=./outdat/out57.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2,3         i=./indat/dat5n.csv    o=./outdat/out57x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2,3         i=./indat/dat5nnfn.csv o=./outdat/out57nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類,ランク i=./indat/dat5n.csv    o=./outdat/out58.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2,3         i=./indat/dat5n.csv    o=./outdat/out58x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2,3         i=./indat/dat5nnfn.csv o=./outdat/out58nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5n.csv    R=金額 f=分類,ランク i=./indat/dat5n.csv    o=./outdat/out59.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5n.csv    R=1    f=2,3         i=./indat/dat5n.csv    o=./outdat/out59x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nnfn.csv R=1    f=2,3         i=./indat/dat5nnfn.csv o=./outdat/out59nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類 i=./indat/dat6s.csv    o=./outdat/out60.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2    i=./indat/dat6s.csv    o=./outdat/out60x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2    i=./indat/dat6snfn.csv o=./outdat/out60nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類,ランク i=./indat/dat6s.csv    o=./outdat/out61.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2,3         i=./indat/dat6s.csv    o=./outdat/out61x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2,3         i=./indat/dat6snfn.csv o=./outdat/out61nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類,ランク i=./indat/dat6s.csv    o=./outdat/out62.csv   -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2,3         i=./indat/dat6s.csv    o=./outdat/out62x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2,3         i=./indat/dat6snfn.csv o=./outdat/out62nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6s.csv    R=金額 f=分類,ランク i=./indat/dat6s.csv    o=./outdat/out63.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6s.csv    R=1    f=2,3         i=./indat/dat6s.csv    o=./outdat/out63x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6snfn.csv R=1    f=2,3         i=./indat/dat6snfn.csv o=./outdat/out63nfn.csv -lo -n

#rf=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類 i=./indat/dat7n.csv    o=./outdat/out64.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2    i=./indat/dat7n.csv    o=./outdat/out64x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2    i=./indat/dat7nnfn.csv o=./outdat/out64nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat7n.csv    o=./outdat/out65.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat7n.csv    o=./outdat/out65x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat7nnfn.csv o=./outdat/out65nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat7n.csv    o=./outdat/out66.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat7n.csv    o=./outdat/out66x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat7nnfn.csv o=./outdat/out66nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3n.csv    R=金額 f=分類,ランク i=./indat/dat7n.csv    o=./outdat/out67.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3n.csv    R=1    f=2,3         i=./indat/dat7n.csv    o=./outdat/out67x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nnfn.csv R=1    f=2,3         i=./indat/dat7nnfn.csv o=./outdat/out67nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類 i=./indat/dat8s.csv    o=./outdat/out68.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2    i=./indat/dat8s.csv    o=./outdat/out68x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2    i=./indat/dat8snfn.csv o=./outdat/out68nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat8s.csv    o=./outdat/out69.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat8s.csv    o=./outdat/out69x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat8snfn.csv o=./outdat/out69nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat8s.csv    o=./outdat/out70.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat8s.csv    o=./outdat/out70x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat8snfn.csv o=./outdat/out70nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4s.csv    R=金額 f=分類,ランク i=./indat/dat8s.csv    o=./outdat/out71.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4s.csv    R=1    f=2,3         i=./indat/dat8s.csv    o=./outdat/out71x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4snfn.csv R=1    f=2,3         i=./indat/dat8snfn.csv o=./outdat/out71nfn.csv -lo -n

#---------------------------------
#ランダムデータ
#---------------------------------
#nullデータ
${pfxc}mrjoin      rf=金額%n m=./indat/ref0.csv    R=範囲 f=分類 i=./indat/dat0.csv    o=./outdat/out100.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0.csv    R=0    f=1    i=./indat/dat0.csv    o=./outdat/out100x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nfn.csv R=0    f=1    i=./indat/dat0nfn.csv o=./outdat/out100nfn.csv

${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat0.csv    o=./outdat/out101.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat0.csv    o=./outdat/out101x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    f=1    i=./indat/dat0nfn.csv o=./outdat/out101nfn.csv

${pfxc}mrjoin      rf=金額%n m=./indat/ref0.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out102.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out102x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nfn.csv R=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out102nfn.csv

${pfxc}mrjoin      rf=金額%n m=./indat/ref0.csv    R=範囲 f=分類 i=./indat/dat0.csv    o=./outdat/out103.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0.csv    R=0    f=1    i=./indat/dat0.csv    o=./outdat/out103x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nfn.csv R=0    f=1    i=./indat/dat0nfn.csv o=./outdat/out103nfn.csv -n

${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat0.csv    o=./outdat/out104.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat0.csv    o=./outdat/out104x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    f=1    i=./indat/dat0nfn.csv o=./outdat/out104nfn.csv -n

${pfxc}mrjoin      rf=金額%n m=./indat/ref0.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out105.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref0.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out105x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref0nfn.csv R=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out105nfn.csv -n

#基本
${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out106.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out106x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out106nfn.csv
${pfxc}mrjoin -q      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out106q.csv
${pfxc}mrjoin -q -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out106qx.csv

#-n
${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out107.csv    -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out107x.csv   -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out107nfn.csv -n

#-lo
${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out108.csv    -lo
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out108x.csv   -lo
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out108nfn.csv -lo

#-lo -n
${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 f=分類 i=./indat/dat1.csv    o=./outdat/out109.csv    -lo -n
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    f=1    i=./indat/dat1.csv    o=./outdat/out109x.csv   -lo -n
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out109nfn.csv -lo -n

#f=省略
${pfxc}mrjoin      rf=金額%n m=./indat/ref1.csv    R=範囲 i=./indat/dat1.csv    o=./outdat/out110.csv
${pfxc}mrjoin -x   rf=0%n    m=./indat/ref1.csv    R=0    i=./indat/dat1.csv    o=./outdat/out110x.csv
${pfxc}mrjoin -nfn rf=0%n    m=./indat/ref1nfn.csv R=0    i=./indat/dat1nfn.csv o=./outdat/out110nfn.csv

#文字順
${pfxc}mrjoin      rf=金額 m=./indat/ref2.csv    R=範囲 f=分類 i=./indat/dat2.csv    o=./outdat/out111.csv
${pfxc}mrjoin -x   rf=0    m=./indat/ref2.csv    R=0    f=1    i=./indat/dat2.csv    o=./outdat/out111x.csv
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2nfn.csv R=0    f=1    i=./indat/dat2nfn.csv o=./outdat/out111nfn.csv
${pfxc}mrjoin -nfno rf=金額 m=./indat/ref2.csv    R=範囲 f=分類 i=./indat/dat2.csv    o=./outdat/out111nfno.csv

${pfxc}mrjoin      rf=金額 m=./indat/ref2.csv    R=範囲 f=分類 i=./indat/dat2.csv    o=./outdat/out112.csv    -n
${pfxc}mrjoin -x   rf=0    m=./indat/ref2.csv    R=0    f=1    i=./indat/dat2.csv    o=./outdat/out112x.csv   -n
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2nfn.csv R=0    f=1    i=./indat/dat2nfn.csv o=./outdat/out112nfn.csv -n

${pfxc}mrjoin      rf=金額 m=./indat/ref2.csv    R=範囲 f=分類 i=./indat/dat2.csv    o=./outdat/out113.csv    -lo
${pfxc}mrjoin -x   rf=0    m=./indat/ref2.csv    R=0    f=1    i=./indat/dat2.csv    o=./outdat/out113x.csv   -lo
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2nfn.csv R=0    f=1    i=./indat/dat2nfn.csv o=./outdat/out113nfn.csv -lo

${pfxc}mrjoin      rf=金額 m=./indat/ref2.csv    R=範囲 f=分類 i=./indat/dat2.csv    o=./outdat/out114.csv    -lo -n
${pfxc}mrjoin -x   rf=0    m=./indat/ref2.csv    R=0    f=1    i=./indat/dat2.csv    o=./outdat/out114x.csv   -lo -n
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2nfn.csv R=0    f=1    i=./indat/dat2nfn.csv o=./outdat/out114nfn.csv -lo -n

${pfxc}mrjoin      rf=金額 m=./indat/ref2.csv    R=範囲 i=./indat/dat2.csv    o=./outdat/out115.csv
${pfxc}mrjoin -x   rf=0    m=./indat/ref2.csv    R=0    i=./indat/dat2.csv    o=./outdat/out115x.csv
${pfxc}mrjoin -nfn rf=0    m=./indat/ref2nfn.csv R=0    i=./indat/dat2nfn.csv o=./outdat/out115nfn.csv

#範囲に含まれないデータがある場合
${pfxc}mrjoin      rf=金額 m=./indat/ref9.csv    R=範囲 f=分類 i=./indat/dat2.csv    o=./outdat/out172.csv

#k=指定
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類 i=./indat/dat3.csv    o=./outdat/out116.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2    i=./indat/dat3.csv    o=./outdat/out116x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2    i=./indat/dat3nfn.csv o=./outdat/out116nfn.csv
${pfxc}mrjoin -q     k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類 i=./indat/dat3.csv    o=./outdat/out116q.csv
${pfxc}mrjoin -q -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2    i=./indat/dat3.csv    o=./outdat/out116qx.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out117.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out117x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out117nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out118.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out118x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out118nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out119.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out119x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out119nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類 i=./indat/dat4.csv    o=./outdat/out120.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2    i=./indat/dat4.csv    o=./outdat/out120x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2    i=./indat/dat4nfn.csv o=./outdat/out120nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out121.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out121x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out121nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out122.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out122x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out122nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out123.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out123x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out123nfn.csv -lo -n

#R=指定なし
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    f=分類 i=./indat/dat3.csv    o=./outdat/out124.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    f=2    i=./indat/dat3.csv    o=./outdat/out124x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv f=2    i=./indat/dat3nfn.csv o=./outdat/out124nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    f=分類,ランク i=./indat/dat3.csv    o=./outdat/out125.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    f=2,3         i=./indat/dat3.csv    o=./outdat/out125x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv f=2,3         i=./indat/dat3nfn.csv o=./outdat/out125nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    f=分類,ランク i=./indat/dat3.csv    o=./outdat/out126.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    f=2,3         i=./indat/dat3.csv    o=./outdat/out126x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv f=2,3         i=./indat/dat3nfn.csv o=./outdat/out126nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    f=分類,ランク i=./indat/dat3.csv    o=./outdat/out127.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    f=2,3         i=./indat/dat3.csv    o=./outdat/out127x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv f=2,3         i=./indat/dat3nfn.csv o=./outdat/out127nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    f=分類 i=./indat/dat4.csv    o=./outdat/out128.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    f=2    i=./indat/dat4.csv    o=./outdat/out128x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv f=2    i=./indat/dat4nfn.csv o=./outdat/out128nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    f=分類,ランク i=./indat/dat4.csv    o=./outdat/out129.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    f=2,3         i=./indat/dat4.csv    o=./outdat/out129x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv f=2,3         i=./indat/dat4nfn.csv o=./outdat/out129nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    f=分類,ランク i=./indat/dat4.csv    o=./outdat/out130.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    f=2,3         i=./indat/dat4.csv    o=./outdat/out130x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv f=2,3         i=./indat/dat4nfn.csv o=./outdat/out130nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    f=分類,ランク i=./indat/dat4.csv    o=./outdat/out131.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    f=2,3         i=./indat/dat4.csv    o=./outdat/out131x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv f=2,3         i=./indat/dat4nfn.csv o=./outdat/out131nfn.csv -lo -n

#k=,K=指定
${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類 i=./indat/dat3.csv    o=./outdat/out132.csv
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2    i=./indat/dat3.csv    o=./outdat/out132x.csv
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2    i=./indat/dat3nfn.csv o=./outdat/out132nfn.csv

${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out133.csv    -n
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out133x.csv   -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out133nfn.csv -n

${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out134.csv    -lo
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out134x.csv   -lo
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out134nfn.csv -lo

${pfxc}mrjoin      k=商品 K=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out135.csv    -lo -n
${pfxc}mrjoin -x   k=0    K=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out135x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out135nfn.csv -lo -n

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類 i=./indat/dat4.csv    o=./outdat/out136.csv
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4.csv    R=1    f=2    i=./indat/dat4.csv    o=./outdat/out136x.csv
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4nfn.csv R=1   f=2   i=./indat/dat4nfn.csv o=./outdat/out136nfn.csv

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out137.csv    -n
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out137x.csv   -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out137nfn.csv -n

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out138.csv    -lo
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out138x.csv   -lo
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out138nfn.csv -lo

${pfxc}mrjoin      k=商品 K=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out139.csv    -lo -n
${pfxc}mrjoin -x   k=0    K=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out139x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    K=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out139nfn.csv -lo -n

#ここまでOK
#k=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類 i=./indat/dat5.csv    o=./outdat/out140.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2    i=./indat/dat5.csv    o=./outdat/out140x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2    i=./indat/dat5nfn.csv o=./outdat/out140nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat5.csv    o=./outdat/out141.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat5.csv    o=./outdat/out141x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat5nfn.csv o=./outdat/out141nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat5.csv    o=./outdat/out142.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat5.csv    o=./outdat/out142x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat5nfn.csv o=./outdat/out142nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat5.csv    o=./outdat/out143.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat5.csv    o=./outdat/out143x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat5nfn.csv o=./outdat/out143nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類 i=./indat/dat6.csv    o=./outdat/out144.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2    i=./indat/dat6.csv    o=./outdat/out144x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2    i=./indat/dat6nfn.csv o=./outdat/out144nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat6.csv    o=./outdat/out145.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat6.csv    o=./outdat/out145x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat6nfn.csv o=./outdat/out145nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat6.csv    o=./outdat/out146.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat6.csv    o=./outdat/out146x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat6nfn.csv o=./outdat/out146nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat6.csv    o=./outdat/out147.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat6.csv    o=./outdat/out147x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat6nfn.csv o=./outdat/out147nfn.csv -lo -n

#K=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類 i=./indat/dat3.csv    o=./outdat/out148.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2    i=./indat/dat3.csv    o=./outdat/out148x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2    i=./indat/dat3nfn.csv o=./outdat/out148nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out149.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out149x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out149nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out150.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out150x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out150nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類,ランク i=./indat/dat3.csv    o=./outdat/out151.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2,3         i=./indat/dat3.csv    o=./outdat/out151x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2,3         i=./indat/dat3nfn.csv o=./outdat/out151nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類 i=./indat/dat4.csv    o=./outdat/out152.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2    i=./indat/dat4.csv    o=./outdat/out152x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2    i=./indat/dat4nfn.csv o=./outdat/out152nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out153.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out153x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out153nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out154.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out154x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out154nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類,ランク i=./indat/dat4.csv    o=./outdat/out155.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2,3         i=./indat/dat4.csv    o=./outdat/out155x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2,3         i=./indat/dat4nfn.csv o=./outdat/out155nfn.csv -lo -n

#K=,K=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類 i=./indat/dat5.csv    o=./outdat/out156.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2    i=./indat/dat5.csv    o=./outdat/out156x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2    i=./indat/dat5nfn.csv o=./outdat/out156nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類,ランク i=./indat/dat5.csv    o=./outdat/out157.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2,3         i=./indat/dat5.csv    o=./outdat/out157x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2,3         i=./indat/dat5nfn.csv o=./outdat/out157nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類,ランク i=./indat/dat5.csv    o=./outdat/out158.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2,3         i=./indat/dat5.csv    o=./outdat/out158x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2,3         i=./indat/dat5nfn.csv o=./outdat/out158nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref5.csv    R=金額 f=分類,ランク i=./indat/dat5.csv    o=./outdat/out159.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref5.csv    R=1    f=2,3         i=./indat/dat5.csv    o=./outdat/out159x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref5nfn.csv R=1    f=2,3         i=./indat/dat5nfn.csv o=./outdat/out159nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類 i=./indat/dat6.csv    o=./outdat/out160.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2    i=./indat/dat6.csv    o=./outdat/out160x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2    i=./indat/dat6nfn.csv o=./outdat/out160nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類,ランク i=./indat/dat6.csv    o=./outdat/out161.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2,3         i=./indat/dat6.csv    o=./outdat/out161x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2,3         i=./indat/dat6nfn.csv o=./outdat/out161nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類,ランク i=./indat/dat6.csv    o=./outdat/out162.csv   -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2,3         i=./indat/dat6.csv    o=./outdat/out162x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2,3         i=./indat/dat6nfn.csv o=./outdat/out162nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref6.csv    R=金額 f=分類,ランク i=./indat/dat6.csv    o=./outdat/out163.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref6.csv    R=1    f=2,3         i=./indat/dat6.csv    o=./outdat/out163x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref6nfn.csv R=1    f=2,3         i=./indat/dat6nfn.csv o=./outdat/out163nfn.csv -lo -n

#rf=にNULL
${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類 i=./indat/dat7.csv    o=./outdat/out164.csv
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2    i=./indat/dat7.csv    o=./outdat/out164x.csv
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2    i=./indat/dat7nfn.csv o=./outdat/out164nfn.csv

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat7.csv    o=./outdat/out165.csv    -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat7.csv    o=./outdat/out165x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat7nfn.csv o=./outdat/out165nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat7.csv    o=./outdat/out166.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat7.csv    o=./outdat/out166x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat7nfn.csv o=./outdat/out166nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額%n m=./indat/ref3.csv    R=金額 f=分類,ランク i=./indat/dat7.csv    o=./outdat/out167.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1%n    m=./indat/ref3.csv    R=1    f=2,3         i=./indat/dat7.csv    o=./outdat/out167x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1%n    m=./indat/ref3nfn.csv R=1    f=2,3         i=./indat/dat7nfn.csv o=./outdat/out167nfn.csv -lo -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類 i=./indat/dat8.csv    o=./outdat/out168.csv
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2    i=./indat/dat8.csv    o=./outdat/out168x.csv
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2    i=./indat/dat8nfn.csv o=./outdat/out168nfn.csv

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat8.csv    o=./outdat/out169.csv    -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat8.csv    o=./outdat/out169x.csv   -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat8nfn.csv o=./outdat/out169nfn.csv -n

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat8.csv    o=./outdat/out170.csv    -lo
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat8.csv    o=./outdat/out170x.csv   -lo
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat8nfn.csv o=./outdat/out170nfn.csv -lo

${pfxc}mrjoin      k=商品 rf=金額 m=./indat/ref4.csv    R=金額 f=分類,ランク i=./indat/dat8.csv    o=./outdat/out171.csv    -lo -n
${pfxc}mrjoin -x   k=0    rf=1    m=./indat/ref4.csv    R=1    f=2,3         i=./indat/dat8.csv    o=./outdat/out171x.csv   -lo -n
${pfxc}mrjoin -nfn k=0    rf=1    m=./indat/ref4nfn.csv R=1    f=2,3         i=./indat/dat8nfn.csv o=./outdat/out171nfn.csv -lo -n
