#!/bin/bash

. ../env

#name_kg_mcmd chgnum

#NULLデータ
${pfxc}mchgnum      f=数量 R=MIN,10,20,MAX v=小,中,大 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mchgnum -x   f=1    R=MIN,10,20,MAX v=小,中,大 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mchgnum -nfn f=2    R=MIN,10,20,MAX v=小,中,大 i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#基本
${pfxc}mchgnum      f=数量 R=MIN,10,20,MAX v=小,中,大 i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mchgnum -x   f=1    R=MIN,10,20,MAX v=小,中,大 i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mchgnum -nfn f=1    R=MIN,10,20,MAX v=小,中,大 i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

#一致なし
${pfxc}mchgnum      f=数量 R=MAX,100,200 v=小,大 i=./indat/dat1.csv    o=./outdat/out23.csv

#-r使用
${pfxc}mchgnum      f=数量 R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mchgnum -x   f=1    R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mchgnum -nfn f=1    R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

#O=使用
${pfxc}mchgnum      f=数量 R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mchgnum -x   f=1    R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mchgnum -nfn f=1    R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

#-A使用
${pfxc}mchgnum      f=数量:数量評価 R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}mchgnum -x   f=1:数量評価    R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}mchgnum -nfn f=1             R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

#-F使用
${pfxc}mchgnum      f=数量 R=10,20,30,MAX v=小,中,大 -F i=./indat/dat1.csv    o=./outdat/out5.csv
${pfxc}mchgnum -x   f=1    R=10,20,30,MAX v=小,中,大 -F i=./indat/dat1.csv    o=./outdat/out5x.csv
${pfxc}mchgnum -nfn f=1    R=10,20,30,MAX v=小,中,大 -F i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv

#f=複数指定
${pfxc}mchgnum      f=数量1,数量2 R=MIN,10,20,MAX v=小,中,大 i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mchgnum -x   f=1,2         R=MIN,10,20,MAX v=小,中,大 i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mchgnum -nfn f=1,2         R=MIN,10,20,MAX v=小,中,大 i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

#-r使用 f=複数指定
${pfxc}mchgnum      f=数量1,数量2 R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat2.csv    o=./outdat/out7.csv
${pfxc}mchgnum -x   f=1,2         R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat2.csv    o=./outdat/out7x.csv
${pfxc}mchgnum -nfn f=1,2         R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv

#O=使用 f=複数指定
${pfxc}mchgnum      f=数量1,数量2 R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}mchgnum -x   f=1,2         R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat2.csv    o=./outdat/out8x.csv
${pfxc}mchgnum -nfn f=1,2         R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv

#-A使用 f=複数指定
${pfxc}mchgnum      f=数量1:数量評価1,数量2:数量評価2 R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat2.csv    o=./outdat/out9.csv
${pfxc}mchgnum -x   f=1:数量評価1,2:数量評価2         R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat2.csv    o=./outdat/out9x.csv
${pfxc}mchgnum -nfn f=1,2                             R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat2nfn.csv o=./outdat/out9nfn.csv

#-F使用 f=複数指定
${pfxc}mchgnum      f=数量1,数量2 R=10,20,30,MAX v=小,中,大 -F i=./indat/dat2.csv    o=./outdat/out10.csv
${pfxc}mchgnum -x   f=1,2         R=10,20,30,MAX v=小,中,大 -F i=./indat/dat2.csv    o=./outdat/out10x.csv
${pfxc}mchgnum -nfn f=1,2         R=10,20,30,MAX v=小,中,大 -F i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv

#部分NULLデータ使用
${pfxc}mchgnum      f=数量 R=MIN,10,20,MAX v=小,中,大 i=./indat/dat3.csv    o=./outdat/out11.csv
${pfxc}mchgnum -x   f=1    R=MIN,10,20,MAX v=小,中,大 i=./indat/dat3.csv    o=./outdat/out11x.csv
${pfxc}mchgnum -nfn f=1    R=MIN,10,20,MAX v=小,中,大 i=./indat/dat3nfn.csv o=./outdat/out11nfn.csv

#部分NULLデータ使用 -r使用
${pfxc}mchgnum      f=数量 R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat3.csv    o=./outdat/out12.csv
${pfxc}mchgnum -x   f=1    R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat3.csv    o=./outdat/out12x.csv
${pfxc}mchgnum -nfn f=1    R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat3nfn.csv o=./outdat/out12nfn.csv

#部分NULLデータ使用 O=使用
${pfxc}mchgnum      f=数量 R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat3.csv    o=./outdat/out13.csv
${pfxc}mchgnum -x   f=1    R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat3.csv    o=./outdat/out13x.csv
${pfxc}mchgnum -nfn f=1    R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat3nfn.csv o=./outdat/out13nfn.csv

#部分NULLデータ使用 -A使用
${pfxc}mchgnum      f=数量:数量評価 R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat3.csv    o=./outdat/out14.csv
${pfxc}mchgnum -x   f=1:数量評価    R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat3.csv    o=./outdat/out14x.csv
${pfxc}mchgnum -nfn f=1             R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat3nfn.csv o=./outdat/out14nfn.csv

#部分NULLデータ使用 -F使用
${pfxc}mchgnum      f=数量 R=10,20,30,MAX v=小,中,大 -F i=./indat/dat3.csv    o=./outdat/out15.csv
${pfxc}mchgnum -x   f=1    R=10,20,30,MAX v=小,中,大 -F i=./indat/dat3.csv    o=./outdat/out15x.csv
${pfxc}mchgnum -nfn f=1    R=10,20,30,MAX v=小,中,大 -F i=./indat/dat3nfn.csv o=./outdat/out15nfn.csv

#f=複数指定 部分NULLデータ使用
${pfxc}mchgnum      f=数量1,数量2 R=MIN,10,20,MAX v=小,中,大 i=./indat/dat4.csv    o=./outdat/out16.csv
${pfxc}mchgnum -x   f=1,2         R=MIN,10,20,MAX v=小,中,大 i=./indat/dat4.csv    o=./outdat/out16x.csv
${pfxc}mchgnum -nfn f=1,2         R=MIN,10,20,MAX v=小,中,大 i=./indat/dat4nfn.csv o=./outdat/out16nfn.csv

#-r使用 f=複数指定 部分NULLデータ使用
${pfxc}mchgnum      f=数量1,数量2 R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat4.csv    o=./outdat/out17.csv
${pfxc}mchgnum -x   f=1,2         R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat4.csv    o=./outdat/out17x.csv
${pfxc}mchgnum -nfn f=1,2         R=MIN,10,20,MAX v=小,中,大 -r i=./indat/dat4nfn.csv o=./outdat/out17nfn.csv

#O=使用 f=複数指定 部分NULLデータ使用
${pfxc}mchgnum      f=数量1,数量2 R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat4.csv    o=./outdat/out18.csv
${pfxc}mchgnum -x   f=1,2         R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat4.csv    o=./outdat/out18x.csv
${pfxc}mchgnum -nfn f=1,2         R=10,20,30,MAX v=小,中,大 O=範囲外 i=./indat/dat4nfn.csv o=./outdat/out18nfn.csv

#-A使用 f=複数指定 部分NULLデータ使用
${pfxc}mchgnum      f=数量1:数量評価1,数量2:数量評価2 R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat4.csv    o=./outdat/out19.csv
${pfxc}mchgnum -x   f=1:数量評価1,2:数量評価2         R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat4.csv    o=./outdat/out19x.csv
${pfxc}mchgnum -nfn f=1,2                             R=MIN,10,20,MAX v=小,中,大 -A i=./indat/dat4nfn.csv o=./outdat/out19nfn.csv

#-F使用 f=複数指定 部分NULLデータ使用
${pfxc}mchgnum      f=数量1,数量2 R=10,20,30,MAX v=小,中,大 -F i=./indat/dat4.csv    o=./outdat/out20.csv
${pfxc}mchgnum -x   f=1,2         R=10,20,30,MAX v=小,中,大 -F i=./indat/dat4.csv    o=./outdat/out20x.csv
${pfxc}mchgnum -nfn f=1,2         R=10,20,30,MAX v=小,中,大 -F i=./indat/dat4nfn.csv o=./outdat/out20nfn.csv

#-V未使用
${pfxc}mchgnum      f=数量 R=MIN,10,20,30,MAX i=./indat/dat1.csv    o=./outdat/out21.csv
${pfxc}mchgnum -x   f=1    R=MIN,10,20,30,MAX i=./indat/dat1.csv    o=./outdat/out21x.csv
${pfxc}mchgnum -nfn f=1    R=MIN,10,20,30,MAX i=./indat/dat1nfn.csv o=./outdat/out21nfn.csv

${pfxc}mchgnum      f=数量1,数量2 R=MIN,10,20,30,MAX i=./indat/dat2.csv    o=./outdat/out22.csv
${pfxc}mchgnum -x   f=1,2         R=MIN,10,20,30,MAX i=./indat/dat2.csv    o=./outdat/out22x.csv
${pfxc}mchgnum -nfn f=1,2         R=MIN,10,20,30,MAX i=./indat/dat2nfn.csv o=./outdat/out22nfn.csv

