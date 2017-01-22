#!/bin/bash

. ../env

#name_kg_mcmd number

#nullデータ
${pfxc}mnumber      s=顧客 a=番号 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mnumber -x   s=0 a=番号 i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mnumber -nfn s=0        i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mnumber -nfno s=顧客 a=番号 i=./indat/dat0s.csv    o=./outdat/out0nfno.csv

#基本
${pfxc}mnumber       s=金額%nr a=番号 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mnumber -x    s=2%nr    a=番号 i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mnumber -nfn  s=2%nr        i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mnumber -nfno s=金額%nr a=番号 i=./indat/dat1s.csv    o=./outdat/out1nfno.csv

${pfxc}mnumber      a=順位 e=seq s=金額%nr i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mnumber -x   a=順位 e=seq s=2%nr    i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mnumber -nfn        e=seq s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mnumber -nfno a=順位 e=seq s=金額%nr i=./indat/dat1s.csv    o=./outdat/out2nfno.csv

${pfxc}mnumber      a=順位 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mnumber -x   a=順位 e=same s=2%nr    i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mnumber -nfn        e=same s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}mnumber -nfno a=順位 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out3nfno.csv

${pfxc}mnumber      a=順位 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mnumber -x   a=順位 e=skip s=2%nr    i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mnumber -nfn        e=skip s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv
${pfxc}mnumber -nfno a=順位 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out4nfno.csv

${pfxc}mnumber      a=番号 S=10 s=金額%nr i=./indat/dat1s.csv    o=./outdat/out5.csv
${pfxc}mnumber -x   a=番号 S=10 s=2%nr i=./indat/dat1s.csv    o=./outdat/out5x.csv
${pfxc}mnumber -nfn        S=10 s=2%nr i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv
${pfxc}mnumber -nfno a=番号 S=10 s=金額%nr i=./indat/dat1s.csv    o=./outdat/out5nfno.csv

${pfxc}mnumber      a=得点 S=10 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out6.csv
${pfxc}mnumber -x   a=得点 S=10 e=same s=2%nr    i=./indat/dat1s.csv    o=./outdat/out6x.csv
${pfxc}mnumber -nfn        S=10 e=same s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out6nfn.csv
${pfxc}mnumber -nfno a=得点 S=10 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out6nfno.csv

${pfxc}mnumber      a=番号 S=20 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}mnumber -x   a=番号 S=20 e=skip s=2%nr    i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mnumber -nfn        S=20 e=skip s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv

${pfxc}mnumber      a=ランク S=H s=金額%nr i=./indat/dat1s.csv    o=./outdat/out8.csv
${pfxc}mnumber -x   a=ランク S=H s=2%nr i=./indat/dat1s.csv    o=./outdat/out8x.csv
${pfxc}mnumber -nfn          S=H s=2%nr  i=./indat/dat1snfn.csv o=./outdat/out8nfn.csv
${pfxc}mnumber -nfno a=ランク S=H s=金額%nr i=./indat/dat1s.csv    o=./outdat/out8nfno.csv

${pfxc}mnumber      a=ランク S=A e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out9.csv
${pfxc}mnumber -x   a=ランク S=A e=same s=2%nr    i=./indat/dat1s.csv    o=./outdat/out9x.csv
${pfxc}mnumber -nfn          S=A e=same s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out9nfn.csv
${pfxc}mnumber -nfno a=ランク S=A e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out9nfno.csv

${pfxc}mnumber      a=ランク S=X e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out10.csv
${pfxc}mnumber -x   a=ランク S=X e=skip s=2%nr   i=./indat/dat1s.csv    o=./outdat/out10x.csv
${pfxc}mnumber -nfn          S=X e=skip s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out10nfn.csv
${pfxc}mnumber -nfno a=ランク S=X e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out10nfno.csv

${pfxc}mnumber      a=番号 S=15 I=8 s=金額%nr  i=./indat/dat1s.csv    o=./outdat/out11.csv
${pfxc}mnumber -x   a=番号 S=15 I=8 s=2%nr i=./indat/dat1s.csv    o=./outdat/out11x.csv
${pfxc}mnumber -nfn        S=15 I=8 s=2%nr  i=./indat/dat1snfn.csv o=./outdat/out11nfn.csv
${pfxc}mnumber -nfno a=番号 S=15 I=8 s=金額%nr i=./indat/dat1s.csv    o=./outdat/out11nfno.csv

${pfxc}mnumber      a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out12.csv
${pfxc}mnumber -x   a=得点 S=10 I=5 e=same s=2%nr    i=./indat/dat1s.csv    o=./outdat/out12x.csv
${pfxc}mnumber -nfn        S=10 I=5 e=same s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out12nfn.csv
${pfxc}mnumber -nfno a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out12nfno.csv

${pfxc}mnumber      a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out13.csv
${pfxc}mnumber -x   a=番号 S=20 I=7 e=skip s=2%nr    i=./indat/dat1s.csv    o=./outdat/out13x.csv
${pfxc}mnumber -nfn        S=20 I=7 e=skip s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out13nfn.csv
${pfxc}mnumber -nfno a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out13nfno.csv

${pfxc}mnumber      a=ランク S=A I=3 s=金額%nr i=./indat/dat1s.csv    o=./outdat/out14.csv
${pfxc}mnumber -x   a=ランク S=A I=3 s=2%nr i=./indat/dat1s.csv    o=./outdat/out14x.csv
${pfxc}mnumber -nfn          S=A I=3 s=2%nr  i=./indat/dat1snfn.csv o=./outdat/out14nfn.csv
${pfxc}mnumber -nfno a=ランク S=A I=3 s=金額%nr i=./indat/dat1s.csv    o=./outdat/out14nfno.csv

${pfxc}mnumber      a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out15.csv
${pfxc}mnumber -x   a=ランク S=H I=5 e=same s=2%nr    i=./indat/dat1s.csv    o=./outdat/out15x.csv
${pfxc}mnumber -nfn          S=H I=5 e=same s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out15nfn.csv
${pfxc}mnumber -nfno a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat1s.csv    o=./outdat/out15nfno.csv

${pfxc}mnumber      a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out16.csv
${pfxc}mnumber -x   a=ランク S=X I=10 e=skip s=2%nr    i=./indat/dat1s.csv    o=./outdat/out16x.csv
${pfxc}mnumber -nfn          S=X I=10 e=skip s=2%nr    i=./indat/dat1snfn.csv o=./outdat/out16nfn.csv
${pfxc}mnumber -nfno a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat1s.csv    o=./outdat/out16nfno.csv

#k=使用
${pfxc}mnumber      k=日付 a=番号 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out17.csv
${pfxc}mnumber -x   k=0    a=番号 s=3%nr  i=./indat/dat2s.csv    o=./outdat/out17x.csv
${pfxc}mnumber -nfn k=0           s=3%nr i=./indat/dat2snfn.csv o=./outdat/out17nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out17nfno.csv

${pfxc}mnumber -q     k=日付 a=番号 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out17q.csv
${pfxc}mnumber -q -x   k=0    a=番号 s=3%nr  i=./indat/dat2s.csv    o=./outdat/out17qx.csv



${pfxc}mnumber      k=日付 a=順位 e=same s=金額%nr i=./indat/dat2s.csv    o=./outdat/out18.csv
${pfxc}mnumber -x   k=0    a=順位 e=same s=3%nr    i=./indat/dat2s.csv    o=./outdat/out18x.csv
${pfxc}mnumber -nfn k=0           e=same s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out18nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=same s=金額%nr i=./indat/dat2s.csv    o=./outdat/out18nfno.csv

${pfxc}mnumber      k=日付 a=順位 e=skip s=金額%nr i=./indat/dat2s.csv    o=./outdat/out19.csv
${pfxc}mnumber -x   k=0    a=順位 e=skip s=3%nr   i=./indat/dat2s.csv    o=./outdat/out19x.csv
${pfxc}mnumber -nfn k=0           e=skip s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out19nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=skip s=金額%nr i=./indat/dat2s.csv    o=./outdat/out19nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=10 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out20.csv
${pfxc}mnumber -x   k=0    a=番号 S=10 s=3%nr i=./indat/dat2s.csv    o=./outdat/out20x.csv
${pfxc}mnumber -nfn k=0           S=10 s=3%nr i=./indat/dat2snfn.csv o=./outdat/out20nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=10 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out20nfno.csv

${pfxc}mnumber      k=日付 a=得点 S=10 e=same s=金額%nr i=./indat/dat2s.csv    o=./outdat/out21.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 e=same s=3%nr    i=./indat/dat2s.csv    o=./outdat/out21x.csv
${pfxc}mnumber -nfn k=0           S=10 e=same s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out21nfn.csv
${pfxc}mnumber -nfno k=日付 a=得点 S=10 e=same s=金額%nr i=./indat/dat2s.csv   o=./outdat/out21nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=20 e=skip s=金額%nr i=./indat/dat2s.csv    o=./outdat/out22.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 e=skip s=3%nr    i=./indat/dat2s.csv    o=./outdat/out22x.csv
${pfxc}mnumber -nfn k=0           S=20 e=skip s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out22nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=20 e=skip s=金額%nr i=./indat/dat2s.csv   o=./outdat/out22nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=H s=金額%nr i=./indat/dat2s.csv    o=./outdat/out23.csv
${pfxc}mnumber -x   k=0    a=ランク S=H s=3%nr i=./indat/dat2s.csv    o=./outdat/out23x.csv
${pfxc}mnumber -nfn k=0             S=H s=3%nr i=./indat/dat2snfn.csv o=./outdat/out23nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=H s=金額%nr i=./indat/dat2s.csv    o=./outdat/out23nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=A e=same s=金額%nr i=./indat/dat2s.csv    o=./outdat/out24.csv
${pfxc}mnumber -x   k=0    a=ランク S=A e=same s=3%nr    i=./indat/dat2s.csv    o=./outdat/out24x.csv
${pfxc}mnumber -nfn k=0             S=A e=same s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out24nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=A e=same s=金額%nr i=./indat/dat2s.csv   o=./outdat/out24nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=X e=skip s=金額%nr i=./indat/dat2s.csv o=./outdat/out25.csv
${pfxc}mnumber -x   k=0    a=ランク S=X e=skip s=3%nr    i=./indat/dat2s.csv o=./outdat/out25x.csv
${pfxc}mnumber -nfn k=0             S=X e=skip s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out25nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=X e=skip s=金額%nr i=./indat/dat2s.csv o=./outdat/out25nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=15 I=8 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out26.csv
${pfxc}mnumber -x   k=0    a=番号 S=15 I=8 s=3%nr i=./indat/dat2s.csv    o=./outdat/out26x.csv
${pfxc}mnumber -nfn k=0           S=15 I=8 s=3%nr i=./indat/dat2snfn.csv o=./outdat/out26nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=15 I=8 s=金額%nr i=./indat/dat2s.csv   o=./outdat/out26nfno.csv

${pfxc}mnumber      k=日付 a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat2s.csv    o=./outdat/out27.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 I=5 e=same s=3%nr    i=./indat/dat2s.csv    o=./outdat/out27x.csv
${pfxc}mnumber -nfn k=0           S=10 I=5 e=same s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out27nfn.csv
${pfxc}mnumber -nfno k=日付 a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat2s.csv  o=./outdat/out27nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat2s.csv    o=./outdat/out28.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 I=7 e=skip s=3%nr   i=./indat/dat2s.csv    o=./outdat/out28x.csv
${pfxc}mnumber -nfn k=0           S=20 I=7 e=skip s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out28nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat2s.csv  o=./outdat/out28nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=A I=3 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out29.csv
${pfxc}mnumber -x   k=0    a=ランク S=A I=3 s=3%nr i=./indat/dat2s.csv    o=./outdat/out29x.csv
${pfxc}mnumber -nfn k=0             S=A I=3 s=3%nr i=./indat/dat2snfn.csv o=./outdat/out29nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=A I=3 s=金額%nr i=./indat/dat2s.csv    o=./outdat/out29nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat2s.csv    o=./outdat/out30.csv
${pfxc}mnumber -x   k=0    a=ランク S=H I=5 e=same s=3%nr    i=./indat/dat2s.csv    o=./outdat/out30x.csv
${pfxc}mnumber -nfn k=0             S=H I=5 e=same s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out30nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat2s.csv  o=./outdat/out30nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat2s.csv    o=./outdat/out31.csv
${pfxc}mnumber -x   k=0    a=ランク S=X I=10 e=skip s=3%nr    i=./indat/dat2s.csv    o=./outdat/out31x.csv
${pfxc}mnumber -nfn k=0             S=X I=10 e=skip s=3%nr    i=./indat/dat2snfn.csv o=./outdat/out31nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat2s.csv  o=./outdat/out31nfno.csv

#-B使用
${pfxc}mnumber      -B k=日付 a=番号 i=./indat/dat2s.csv    o=./outdat/out32.csv
${pfxc}mnumber -x   -B k=0    a=番号 i=./indat/dat2s.csv    o=./outdat/out32x.csv
${pfxc}mnumber -nfn -B k=0           i=./indat/dat2snfn.csv o=./outdat/out32nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=番号 i=./indat/dat2s.csv    o=./outdat/out32nfno.csv

${pfxc}mnumber      -B k=日付 a=番号 S=10 i=./indat/dat2s.csv    o=./outdat/out33.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=10 i=./indat/dat2s.csv    o=./outdat/out33x.csv
${pfxc}mnumber -nfn -B k=0           S=10 i=./indat/dat2snfn.csv o=./outdat/out33nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=番号 S=10 i=./indat/dat2s.csv    o=./outdat/out33nfno.csv

${pfxc}mnumber      -B k=日付 a=ランク S=H i=./indat/dat2s.csv    o=./outdat/out34.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=H i=./indat/dat2s.csv    o=./outdat/out34x.csv
${pfxc}mnumber -nfn -B k=0             S=H i=./indat/dat2snfn.csv o=./outdat/out34nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=ランク S=H i=./indat/dat2s.csv    o=./outdat/out34nfno.csv

${pfxc}mnumber      -B k=日付 a=番号 S=15 I=8 i=./indat/dat2s.csv    o=./outdat/out35.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=15 I=8 i=./indat/dat2s.csv    o=./outdat/out35x.csv
${pfxc}mnumber -nfn -B k=0           S=15 I=8 i=./indat/dat2snfn.csv o=./outdat/out35nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=番号 S=15 I=8 i=./indat/dat2s.csv    o=./outdat/out35nfno.csv

${pfxc}mnumber      -B k=日付 a=ランク S=A I=3 i=./indat/dat2s.csv    o=./outdat/out36.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=A I=3 i=./indat/dat2s.csv    o=./outdat/out36x.csv
${pfxc}mnumber -nfn -B k=0             S=A I=3 i=./indat/dat2snfn.csv o=./outdat/out36nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=ランク S=A I=3 i=./indat/dat2s.csv    o=./outdat/out36nfno.csv

#s=複数
${pfxc}mnumber      a=順位 e=seq s=顧客,金額%nr i=./indat/dat3s.csv    o=./outdat/out37.csv
${pfxc}mnumber -x   a=順位 e=seq s=0,2%nr       i=./indat/dat3s.csv    o=./outdat/out37x.csv
${pfxc}mnumber -nfn        e=seq s=0,2%nr       i=./indat/dat3snfn.csv o=./outdat/out37nfn.csv
${pfxc}mnumber -nfno a=順位 e=seq s=顧客,金額%nr i=./indat/dat3s.csv    o=./outdat/out37nfno.csv

${pfxc}mnumber      a=順位 e=same s=顧客,金額%nr i=./indat/dat3s.csv    o=./outdat/out38.csv
${pfxc}mnumber -x   a=順位 e=same s=0,2%nr       i=./indat/dat3s.csv    o=./outdat/out38x.csv
${pfxc}mnumber -nfn        e=same s=0,2%nr       i=./indat/dat3snfn.csv o=./outdat/out38nfn.csv
${pfxc}mnumber -nfno a=順位 e=same s=顧客,金額%nr i=./indat/dat3s.csv    o=./outdat/out38nfno.csv

${pfxc}mnumber      a=順位 e=skip s=顧客,金額%nr i=./indat/dat3s.csv    o=./outdat/out39.csv
${pfxc}mnumber -x   a=順位 e=skip s=0,2%nr       i=./indat/dat3s.csv    o=./outdat/out39x.csv
${pfxc}mnumber -nfn        e=skip s=0,2%nr       i=./indat/dat3snfn.csv o=./outdat/out39nfn.csv
${pfxc}mnumber -nfno a=順位 e=skip s=顧客,金額%nr i=./indat/dat3s.csv    o=./outdat/out39nfno.csv

${pfxc}mnumber      k=日付 a=順位 s=顧客,金額%nr i=./indat/dat4s.csv    o=./outdat/out40.csv
${pfxc}mnumber -x   k=0    a=順位 s=1,3%nr       i=./indat/dat4s.csv    o=./outdat/out40x.csv
${pfxc}mnumber -nfn k=0           s=1,3%nr       i=./indat/dat4snfn.csv o=./outdat/out40nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 s=顧客,金額%nr i=./indat/dat4s.csv    o=./outdat/out40nfno.csv

${pfxc}mnumber      k=日付 a=順位 e=same s=顧客,金額%nr i=./indat/dat4s.csv    o=./outdat/out41.csv
${pfxc}mnumber -x   k=0    a=順位 e=same s=1,3%nr       i=./indat/dat4s.csv    o=./outdat/out41x.csv
${pfxc}mnumber -nfn k=0           e=same s=1,3%nr       i=./indat/dat4snfn.csv o=./outdat/out41nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=same s=顧客,金額%nr i=./indat/dat4s.csv    o=./outdat/out41nfno.csv

${pfxc}mnumber      k=日付 a=順位 e=skip s=顧客,金額%nr i=./indat/dat4s.csv    o=./outdat/out42.csv
${pfxc}mnumber -x   k=0    a=順位 e=skip s=1,3%nr       i=./indat/dat4s.csv    o=./outdat/out42x.csv
${pfxc}mnumber -nfn k=0           e=skip s=1,3%nr       i=./indat/dat4snfn.csv o=./outdat/out42nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=skip s=顧客,金額%nr i=./indat/dat4s.csv    o=./outdat/out42nfno.csv

#NULL混在
${pfxc}mnumber      a=番号 s=金額%nr i=./indat/dat5s.csv    o=./outdat/out43.csv
${pfxc}mnumber -x   a=番号 s=2%nr i=./indat/dat5s.csv    o=./outdat/out43x.csv
${pfxc}mnumber -nfn       s=2%nr i=./indat/dat5snfn.csv o=./outdat/out43nfn.csv

${pfxc}mnumber      a=順位 e=seq s=金額%nr i=./indat/dat5s.csv    o=./outdat/out44.csv
${pfxc}mnumber -x   a=順位 e=seq s=2%nr    i=./indat/dat5s.csv    o=./outdat/out44x.csv
${pfxc}mnumber -nfn        e=seq s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out44nfn.csv

${pfxc}mnumber      a=順位 e=same s=金額%nr i=./indat/dat5s.csv    o=./outdat/out45.csv
${pfxc}mnumber -x   a=順位 e=same s=2%nr    i=./indat/dat5s.csv    o=./outdat/out45x.csv
${pfxc}mnumber -nfn        e=same s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out45nfn.csv

${pfxc}mnumber      a=順位 e=skip s=金額%nr i=./indat/dat5s.csv    o=./outdat/out46.csv
${pfxc}mnumber -x   a=順位 e=skip s=2%nr    i=./indat/dat5s.csv    o=./outdat/out46x.csv
${pfxc}mnumber -nfn        e=skip s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out46nfn.csv

${pfxc}mnumber      a=番号 S=10 s=金額%nr i=./indat/dat5s.csv    o=./outdat/out47.csv
${pfxc}mnumber -x   a=番号 S=10 s=2%nr i=./indat/dat5s.csv    o=./outdat/out47x.csv
${pfxc}mnumber -nfn        S=10 s=2%nr i=./indat/dat5snfn.csv o=./outdat/out47nfn.csv

${pfxc}mnumber      a=得点 S=10 e=same s=金額%nr i=./indat/dat5s.csv    o=./outdat/out48.csv
${pfxc}mnumber -x   a=得点 S=10 e=same s=2%nr    i=./indat/dat5s.csv    o=./outdat/out48x.csv
${pfxc}mnumber -nfn        S=10 e=same s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out48nfn.csv

${pfxc}mnumber      a=番号 S=20 e=skip s=金額%nr i=./indat/dat5s.csv    o=./outdat/out49.csv
${pfxc}mnumber -x   a=番号 S=20 e=skip s=2%nr    i=./indat/dat5s.csv    o=./outdat/out49x.csv
${pfxc}mnumber -nfn        S=20 e=skip s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out49nfn.csv

${pfxc}mnumber      a=ランク S=H s=金額%nr i=./indat/dat5s.csv    o=./outdat/out50.csv
${pfxc}mnumber -x   a=ランク S=H s=2%nr i=./indat/dat5s.csv    o=./outdat/out50x.csv
${pfxc}mnumber -nfn          S=H s=2%nr i=./indat/dat5snfn.csv o=./outdat/out50nfn.csv

${pfxc}mnumber      a=ランク S=A e=same s=金額%nr i=./indat/dat5s.csv    o=./outdat/out51.csv
${pfxc}mnumber -x   a=ランク S=A e=same s=2%nr    i=./indat/dat5s.csv    o=./outdat/out51x.csv
${pfxc}mnumber -nfn          S=A e=same s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out51nfn.csv

${pfxc}mnumber      a=ランク S=X e=skip s=金額%nr i=./indat/dat5s.csv    o=./outdat/out52.csv
${pfxc}mnumber -x   a=ランク S=X e=skip s=2%nr    i=./indat/dat5s.csv    o=./outdat/out52x.csv
${pfxc}mnumber -nfn          S=X e=skip s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out52nfn.csv

${pfxc}mnumber      a=番号 S=15 I=8 s=金額%nr i=./indat/dat5s.csv    o=./outdat/out53.csv
${pfxc}mnumber -x   a=番号 S=15 I=8 s=2%nr i=./indat/dat5s.csv    o=./outdat/out53x.csv
${pfxc}mnumber -nfn        S=15 I=8 s=2%nr i=./indat/dat5snfn.csv o=./outdat/out53nfn.csv

${pfxc}mnumber      a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat5s.csv    o=./outdat/out54.csv
${pfxc}mnumber -x   a=得点 S=10 I=5 e=same s=2%nr    i=./indat/dat5s.csv    o=./outdat/out54x.csv
${pfxc}mnumber -nfn        S=10 I=5 e=same s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out54nfn.csv

${pfxc}mnumber      a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat5s.csv    o=./outdat/out55.csv
${pfxc}mnumber -x   a=番号 S=20 I=7 e=skip s=2%nr    i=./indat/dat5s.csv    o=./outdat/out55x.csv
${pfxc}mnumber -nfn        S=20 I=7 e=skip s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out55nfn.csv

${pfxc}mnumber      a=ランク S=A I=3 s=金額%nr i=./indat/dat5s.csv    o=./outdat/out56.csv
${pfxc}mnumber -x   a=ランク S=A I=3 s=2%nr i=./indat/dat5s.csv    o=./outdat/out56x.csv
${pfxc}mnumber -nfn          S=A I=3 s=2%nr i=./indat/dat5snfn.csv o=./outdat/out56nfn.csv

${pfxc}mnumber      a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat5s.csv    o=./outdat/out57.csv
${pfxc}mnumber -x   a=ランク S=H I=5 e=same s=2%nr    i=./indat/dat5s.csv    o=./outdat/out57x.csv
${pfxc}mnumber -nfn          S=H I=5 e=same s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out57nfn.csv

${pfxc}mnumber      a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat5s.csv    o=./outdat/out58.csv
${pfxc}mnumber -x   a=ランク S=X I=10 e=skip s=2%nr    i=./indat/dat5s.csv    o=./outdat/out58x.csv
${pfxc}mnumber -nfn          S=X I=10 e=skip s=2%nr    i=./indat/dat5snfn.csv o=./outdat/out58nfn.csv

${pfxc}mnumber      k=日付 a=番号 s=金額%nr i=./indat/dat6s.csv    o=./outdat/out59.csv
${pfxc}mnumber -x   k=0    a=番号 s=3%nr i=./indat/dat6s.csv    o=./outdat/out59x.csv
${pfxc}mnumber -nfn k=0          s=3%nr i=./indat/dat6snfn.csv o=./outdat/out59nfn.csv

${pfxc}mnumber      k=日付 a=順位 e=same s=金額%nr i=./indat/dat6s.csv    o=./outdat/out60.csv
${pfxc}mnumber -x   k=0    a=順位 e=same s=3%nr   i=./indat/dat6s.csv    o=./outdat/out60x.csv
${pfxc}mnumber -nfn k=0           e=same s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out60nfn.csv

${pfxc}mnumber      k=日付 a=順位 e=skip s=金額%nr i=./indat/dat6s.csv    o=./outdat/out61.csv
${pfxc}mnumber -x   k=0    a=順位 e=skip s=3%nr    i=./indat/dat6s.csv    o=./outdat/out61x.csv
${pfxc}mnumber -nfn k=0           e=skip s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out61nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=10 s=金額%nr i=./indat/dat6s.csv    o=./outdat/out62.csv
${pfxc}mnumber -x   k=0    a=番号 S=10 s=3%nr i=./indat/dat6s.csv    o=./outdat/out62x.csv
${pfxc}mnumber -nfn k=0           S=10 s=3%nr i=./indat/dat6snfn.csv o=./outdat/out62nfn.csv

${pfxc}mnumber      k=日付 a=得点 S=10 e=same s=金額%nr i=./indat/dat6s.csv    o=./outdat/out63.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 e=same s=3%nr    i=./indat/dat6s.csv    o=./outdat/out63x.csv
${pfxc}mnumber -nfn k=0           S=10 e=same s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out63nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=20 e=skip s=金額%nr i=./indat/dat6s.csv    o=./outdat/out64.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 e=skip s=3%nr   i=./indat/dat6s.csv    o=./outdat/out64x.csv
${pfxc}mnumber -nfn k=0           S=20 e=skip s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out64nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=H s=金額%nr i=./indat/dat6s.csv    o=./outdat/out65.csv
${pfxc}mnumber -x   k=0    a=ランク S=H s=3%nr i=./indat/dat6s.csv    o=./outdat/out65x.csv
${pfxc}mnumber -nfn k=0             S=H s=3%nr i=./indat/dat6snfn.csv o=./outdat/out65nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=A e=same s=金額%nr i=./indat/dat6s.csv    o=./outdat/out66.csv
${pfxc}mnumber -x   k=0    a=ランク S=A e=same s=3%nr    i=./indat/dat6s.csv    o=./outdat/out66x.csv
${pfxc}mnumber -nfn k=0             S=A e=same s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out66nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=X e=skip s=金額%nr i=./indat/dat6s.csv    o=./outdat/out67.csv
${pfxc}mnumber -x   k=0    a=ランク S=X e=skip s=3%nr    i=./indat/dat6s.csv    o=./outdat/out67x.csv
${pfxc}mnumber -nfn k=0             S=X e=skip s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out67nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=15 I=8 s=金額%nr i=./indat/dat6s.csv    o=./outdat/out68.csv
${pfxc}mnumber -x   k=0    a=番号 S=15 I=8 s=3%nr i=./indat/dat6s.csv    o=./outdat/out68x.csv
${pfxc}mnumber -nfn k=0           S=15 I=8 s=3%nr i=./indat/dat6snfn.csv o=./outdat/out68nfn.csv

${pfxc}mnumber      k=日付 a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat6s.csv    o=./outdat/out69.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 I=5 e=same s=3%nr    i=./indat/dat6s.csv    o=./outdat/out69x.csv
${pfxc}mnumber -nfn k=0           S=10 I=5 e=same s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out69nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat6s.csv    o=./outdat/out70.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 I=7 e=skip s=3%nr    i=./indat/dat6s.csv    o=./outdat/out70x.csv
${pfxc}mnumber -nfn k=0           S=20 I=7 e=skip s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out70nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=A I=3 s=金額%nr i=./indat/dat6s.csv    o=./outdat/out71.csv
${pfxc}mnumber -x   k=0    a=ランク S=A I=3 s=3%nr i=./indat/dat6s.csv    o=./outdat/out71x.csv
${pfxc}mnumber -nfn k=0             S=A I=3 s=3%nr i=./indat/dat6snfn.csv o=./outdat/out71nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat6s.csv    o=./outdat/out72.csv
${pfxc}mnumber -x   k=0    a=ランク S=H I=5 e=same s=3%nr    i=./indat/dat6s.csv    o=./outdat/out72x.csv
${pfxc}mnumber -nfn k=0             S=H I=5 e=same s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out72nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat6s.csv    o=./outdat/out73.csv
${pfxc}mnumber -x   k=0    a=ランク S=X I=10 e=skip s=3%nr    i=./indat/dat6s.csv    o=./outdat/out73x.csv
${pfxc}mnumber -nfn k=0             S=X I=10 e=skip s=3%nr    i=./indat/dat6snfn.csv o=./outdat/out73nfn.csv

#-B使用
${pfxc}mnumber      -B k=日付 a=番号 i=./indat/dat6s.csv    o=./outdat/out74.csv
${pfxc}mnumber -x   -B k=0    a=番号 i=./indat/dat6s.csv    o=./outdat/out74x.csv
${pfxc}mnumber -nfn -B k=0           i=./indat/dat6snfn.csv o=./outdat/out74nfn.csv

${pfxc}mnumber      -B k=日付 a=番号 S=10 i=./indat/dat6s.csv    o=./outdat/out75.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=10 i=./indat/dat6s.csv    o=./outdat/out75x.csv
${pfxc}mnumber -nfn -B k=0           S=10 i=./indat/dat6snfn.csv o=./outdat/out75nfn.csv

${pfxc}mnumber      -B k=日付 a=ランク S=H i=./indat/dat6s.csv    o=./outdat/out76.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=H i=./indat/dat6s.csv    o=./outdat/out76x.csv
${pfxc}mnumber -nfn -B k=0             S=H i=./indat/dat6snfn.csv o=./outdat/out76nfn.csv

${pfxc}mnumber      -B k=日付 a=番号 S=15 I=8 i=./indat/dat6s.csv    o=./outdat/out77.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=15 I=8 i=./indat/dat6s.csv    o=./outdat/out77x.csv
${pfxc}mnumber -nfn -B k=0           S=15 I=8 i=./indat/dat6snfn.csv o=./outdat/out77nfn.csv

${pfxc}mnumber      -B k=日付 a=ランク S=A I=3 i=./indat/dat6s.csv    o=./outdat/out78.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=A I=3 i=./indat/dat6s.csv    o=./outdat/out78x.csv
${pfxc}mnumber -nfn -B k=0             S=A I=3 i=./indat/dat6snfn.csv o=./outdat/out78nfn.csv


#-----------------------------------------------------------------
# 以下ランダムデータ
#-----------------------------------------------------------------
#nullデータ
${pfxc}mnumber      s=顧客 a=番号 i=./indat/dat0.csv    o=./outdat/out100.csv
${pfxc}mnumber -x   s=0 a=番号 i=./indat/dat0.csv    o=./outdat/out100x.csv
${pfxc}mnumber -nfn s=0        i=./indat/dat0nfn.csv o=./outdat/out100nfn.csv
${pfxc}mnumber -nfno s=顧客 a=番号 i=./indat/dat0.csv    o=./outdat/out100nfno.csv

#基本
${pfxc}mnumber       s=金額%nr a=番号 i=./indat/dat1.csv    o=./outdat/out101.csv
${pfxc}mnumber -x    s=2%nr    a=番号 i=./indat/dat1.csv    o=./outdat/out101x.csv
${pfxc}mnumber -nfn  s=2%nr        i=./indat/dat1nfn.csv o=./outdat/out101nfn.csv
${pfxc}mnumber -nfno s=金額%nr a=番号 i=./indat/dat1.csv    o=./outdat/out101nfno.csv

${pfxc}mnumber      a=順位 e=seq s=金額%nr i=./indat/dat1.csv    o=./outdat/out102.csv
${pfxc}mnumber -x   a=順位 e=seq s=2%nr    i=./indat/dat1.csv    o=./outdat/out102x.csv
${pfxc}mnumber -nfn        e=seq s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out102nfn.csv
${pfxc}mnumber -nfno a=順位 e=seq s=金額%nr i=./indat/dat1.csv    o=./outdat/out102nfno.csv

${pfxc}mnumber      a=順位 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out103.csv
${pfxc}mnumber -x   a=順位 e=same s=2%nr    i=./indat/dat1.csv    o=./outdat/out103x.csv
${pfxc}mnumber -nfn        e=same s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out103nfn.csv
${pfxc}mnumber -nfno a=順位 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out103nfno.csv

${pfxc}mnumber      a=順位 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out104.csv
${pfxc}mnumber -x   a=順位 e=skip s=2%nr    i=./indat/dat1.csv    o=./outdat/out104x.csv
${pfxc}mnumber -nfn        e=skip s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out104nfn.csv
${pfxc}mnumber -nfno a=順位 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out104nfno.csv

${pfxc}mnumber      a=番号 S=10 s=金額%nr i=./indat/dat1.csv    o=./outdat/out105.csv
${pfxc}mnumber -x   a=番号 S=10 s=2%nr i=./indat/dat1.csv    o=./outdat/out105x.csv
${pfxc}mnumber -nfn        S=10 s=2%nr i=./indat/dat1nfn.csv o=./outdat/out105nfn.csv
${pfxc}mnumber -nfno a=番号 S=10 s=金額%nr i=./indat/dat1.csv    o=./outdat/out105nfno.csv

${pfxc}mnumber      a=得点 S=10 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out106.csv
${pfxc}mnumber -x   a=得点 S=10 e=same s=2%nr    i=./indat/dat1.csv    o=./outdat/out106x.csv
${pfxc}mnumber -nfn        S=10 e=same s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out106nfn.csv
${pfxc}mnumber -nfno a=得点 S=10 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out106nfno.csv

${pfxc}mnumber      a=番号 S=20 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out107.csv
${pfxc}mnumber -x   a=番号 S=20 e=skip s=2%nr    i=./indat/dat1.csv    o=./outdat/out107x.csv
${pfxc}mnumber -nfn        S=20 e=skip s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out107nfn.csv

${pfxc}mnumber      a=ランク S=H s=金額%nr i=./indat/dat1.csv    o=./outdat/out108.csv
${pfxc}mnumber -x   a=ランク S=H s=2%nr i=./indat/dat1.csv    o=./outdat/out108x.csv
${pfxc}mnumber -nfn          S=H s=2%nr  i=./indat/dat1nfn.csv o=./outdat/out108nfn.csv
${pfxc}mnumber -nfno a=ランク S=H s=金額%nr i=./indat/dat1.csv    o=./outdat/out108nfno.csv

${pfxc}mnumber      a=ランク S=A e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out109.csv
${pfxc}mnumber -x   a=ランク S=A e=same s=2%nr    i=./indat/dat1.csv    o=./outdat/out109x.csv
${pfxc}mnumber -nfn          S=A e=same s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out109nfn.csv
${pfxc}mnumber -nfno a=ランク S=A e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out109nfno.csv

${pfxc}mnumber      a=ランク S=X e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out110.csv
${pfxc}mnumber -x   a=ランク S=X e=skip s=2%nr   i=./indat/dat1.csv    o=./outdat/out110x.csv
${pfxc}mnumber -nfn          S=X e=skip s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out110nfn.csv
${pfxc}mnumber -nfno a=ランク S=X e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out110nfno.csv

${pfxc}mnumber      a=番号 S=15 I=8 s=金額%nr  i=./indat/dat1.csv    o=./outdat/out111.csv
${pfxc}mnumber -x   a=番号 S=15 I=8 s=2%nr i=./indat/dat1.csv    o=./outdat/out111x.csv
${pfxc}mnumber -nfn        S=15 I=8 s=2%nr  i=./indat/dat1nfn.csv o=./outdat/out111nfn.csv
${pfxc}mnumber -nfno a=番号 S=15 I=8 s=金額%nr i=./indat/dat1.csv    o=./outdat/out111nfno.csv

${pfxc}mnumber      a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out112.csv
${pfxc}mnumber -x   a=得点 S=10 I=5 e=same s=2%nr    i=./indat/dat1.csv    o=./outdat/out112x.csv
${pfxc}mnumber -nfn        S=10 I=5 e=same s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out112nfn.csv
${pfxc}mnumber -nfno a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out112nfno.csv

${pfxc}mnumber      a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out113.csv
${pfxc}mnumber -x   a=番号 S=20 I=7 e=skip s=2%nr    i=./indat/dat1.csv    o=./outdat/out113x.csv
${pfxc}mnumber -nfn        S=20 I=7 e=skip s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out113nfn.csv
${pfxc}mnumber -nfno a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out113nfno.csv

${pfxc}mnumber      a=ランク S=A I=3 s=金額%nr i=./indat/dat1.csv    o=./outdat/out114.csv
${pfxc}mnumber -x   a=ランク S=A I=3 s=2%nr i=./indat/dat1.csv    o=./outdat/out114x.csv
${pfxc}mnumber -nfn          S=A I=3 s=2%nr  i=./indat/dat1nfn.csv o=./outdat/out114nfn.csv
${pfxc}mnumber -nfno a=ランク S=A I=3 s=金額%nr i=./indat/dat1.csv    o=./outdat/out114nfno.csv

${pfxc}mnumber      a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out115.csv
${pfxc}mnumber -x   a=ランク S=H I=5 e=same s=2%nr    i=./indat/dat1.csv    o=./outdat/out115x.csv
${pfxc}mnumber -nfn          S=H I=5 e=same s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out115nfn.csv
${pfxc}mnumber -nfno a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat1.csv    o=./outdat/out115nfno.csv

${pfxc}mnumber      a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out116.csv
${pfxc}mnumber -x   a=ランク S=X I=10 e=skip s=2%nr    i=./indat/dat1.csv    o=./outdat/out116x.csv
${pfxc}mnumber -nfn          S=X I=10 e=skip s=2%nr    i=./indat/dat1nfn.csv o=./outdat/out116nfn.csv
${pfxc}mnumber -nfno a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat1.csv    o=./outdat/out116nfno.csv

#k=使用
${pfxc}mnumber      k=日付 a=番号 s=金額%nr i=./indat/dat2.csv    o=./outdat/out117.csv
${pfxc}mnumber -x   k=0    a=番号 s=3%nr  i=./indat/dat2.csv    o=./outdat/out117x.csv
${pfxc}mnumber -nfn k=0           s=3%nr i=./indat/dat2nfn.csv o=./outdat/out117nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 s=金額%nr i=./indat/dat2.csv    o=./outdat/out117nfno.csv
${pfxc}mnumber -q     k=日付 a=番号 s=金額%nr i=./indat/dat2.csv    o=./outdat/out117q.csv
${pfxc}mnumber -q -x  k=0    a=番号 s=3%nr  i=./indat/dat2.csv    o=./outdat/out117qx.csv


${pfxc}mnumber      k=日付 a=順位 e=same s=金額%nr i=./indat/dat2.csv    o=./outdat/out118.csv
${pfxc}mnumber -x   k=0    a=順位 e=same s=3%nr    i=./indat/dat2.csv    o=./outdat/out118x.csv
${pfxc}mnumber -nfn k=0           e=same s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out118nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=same s=金額%nr i=./indat/dat2.csv    o=./outdat/out118nfno.csv

${pfxc}mnumber      k=日付 a=順位 e=skip s=金額%nr i=./indat/dat2.csv    o=./outdat/out119.csv
${pfxc}mnumber -x   k=0    a=順位 e=skip s=3%nr   i=./indat/dat2.csv    o=./outdat/out119x.csv
${pfxc}mnumber -nfn k=0           e=skip s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out119nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=skip s=金額%nr i=./indat/dat2.csv    o=./outdat/out119nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=10 s=金額%nr i=./indat/dat2.csv    o=./outdat/out120.csv
${pfxc}mnumber -x   k=0    a=番号 S=10 s=3%nr i=./indat/dat2.csv    o=./outdat/out120x.csv
${pfxc}mnumber -nfn k=0           S=10 s=3%nr i=./indat/dat2nfn.csv o=./outdat/out120nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=10 s=金額%nr i=./indat/dat2.csv    o=./outdat/out120nfno.csv

${pfxc}mnumber      k=日付 a=得点 S=10 e=same s=金額%nr i=./indat/dat2.csv    o=./outdat/out121.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 e=same s=3%nr    i=./indat/dat2.csv    o=./outdat/out121x.csv
${pfxc}mnumber -nfn k=0           S=10 e=same s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out121nfn.csv
${pfxc}mnumber -nfno k=日付 a=得点 S=10 e=same s=金額%nr i=./indat/dat2.csv   o=./outdat/out121nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=20 e=skip s=金額%nr i=./indat/dat2.csv    o=./outdat/out122.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 e=skip s=3%nr    i=./indat/dat2.csv    o=./outdat/out122x.csv
${pfxc}mnumber -nfn k=0           S=20 e=skip s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out122nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=20 e=skip s=金額%nr i=./indat/dat2.csv   o=./outdat/out122nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=H s=金額%nr i=./indat/dat2.csv    o=./outdat/out123.csv
${pfxc}mnumber -x   k=0    a=ランク S=H s=3%nr i=./indat/dat2.csv    o=./outdat/out123x.csv
${pfxc}mnumber -nfn k=0             S=H s=3%nr i=./indat/dat2nfn.csv o=./outdat/out123nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=H s=金額%nr i=./indat/dat2.csv    o=./outdat/out123nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=A e=same s=金額%nr i=./indat/dat2.csv    o=./outdat/out124.csv
${pfxc}mnumber -x   k=0    a=ランク S=A e=same s=3%nr    i=./indat/dat2.csv    o=./outdat/out124x.csv
${pfxc}mnumber -nfn k=0             S=A e=same s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out124nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=A e=same s=金額%nr i=./indat/dat2.csv   o=./outdat/out124nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=X e=skip s=金額%nr i=./indat/dat2.csv o=./outdat/out125.csv
${pfxc}mnumber -x   k=0    a=ランク S=X e=skip s=3%nr    i=./indat/dat2.csv o=./outdat/out125x.csv
${pfxc}mnumber -nfn k=0             S=X e=skip s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out125nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=X e=skip s=金額%nr i=./indat/dat2.csv o=./outdat/out125nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=15 I=8 s=金額%nr i=./indat/dat2.csv    o=./outdat/out126.csv
${pfxc}mnumber -x   k=0    a=番号 S=15 I=8 s=3%nr i=./indat/dat2.csv    o=./outdat/out126x.csv
${pfxc}mnumber -nfn k=0           S=15 I=8 s=3%nr i=./indat/dat2nfn.csv o=./outdat/out126nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=15 I=8 s=金額%nr i=./indat/dat2.csv   o=./outdat/out126nfno.csv

${pfxc}mnumber      k=日付 a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat2.csv    o=./outdat/out127.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 I=5 e=same s=3%nr    i=./indat/dat2.csv    o=./outdat/out127x.csv
${pfxc}mnumber -nfn k=0           S=10 I=5 e=same s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out127nfn.csv
${pfxc}mnumber -nfno k=日付 a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat2.csv  o=./outdat/out127nfno.csv

${pfxc}mnumber      k=日付 a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat2.csv    o=./outdat/out128.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 I=7 e=skip s=3%nr   i=./indat/dat2.csv    o=./outdat/out128x.csv
${pfxc}mnumber -nfn k=0           S=20 I=7 e=skip s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out128nfn.csv
${pfxc}mnumber -nfno k=日付 a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat2.csv  o=./outdat/out128nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=A I=3 s=金額%nr i=./indat/dat2.csv    o=./outdat/out129.csv
${pfxc}mnumber -x   k=0    a=ランク S=A I=3 s=3%nr i=./indat/dat2.csv    o=./outdat/out129x.csv
${pfxc}mnumber -nfn k=0             S=A I=3 s=3%nr i=./indat/dat2nfn.csv o=./outdat/out129nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=A I=3 s=金額%nr i=./indat/dat2.csv    o=./outdat/out129nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat2.csv    o=./outdat/out130.csv
${pfxc}mnumber -x   k=0    a=ランク S=H I=5 e=same s=3%nr    i=./indat/dat2.csv    o=./outdat/out130x.csv
${pfxc}mnumber -nfn k=0             S=H I=5 e=same s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out130nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat2.csv  o=./outdat/out130nfno.csv

${pfxc}mnumber      k=日付 a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat2.csv    o=./outdat/out131.csv
${pfxc}mnumber -x   k=0    a=ランク S=X I=10 e=skip s=3%nr    i=./indat/dat2.csv    o=./outdat/out131x.csv
${pfxc}mnumber -nfn k=0             S=X I=10 e=skip s=3%nr    i=./indat/dat2nfn.csv o=./outdat/out131nfn.csv
${pfxc}mnumber -nfno k=日付 a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat2.csv  o=./outdat/out131nfno.csv

#-B使用
${pfxc}mnumber      -B k=日付 a=番号 i=./indat/dat2.csv    o=./outdat/out132.csv
${pfxc}mnumber -x   -B k=0    a=番号 i=./indat/dat2.csv    o=./outdat/out132x.csv
${pfxc}mnumber -nfn -B k=0           i=./indat/dat2nfn.csv o=./outdat/out132nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=番号 i=./indat/dat2.csv    o=./outdat/out132nfno.csv

${pfxc}mnumber      -B k=日付 a=番号 S=10 i=./indat/dat2.csv    o=./outdat/out133.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=10 i=./indat/dat2.csv    o=./outdat/out133x.csv
${pfxc}mnumber -nfn -B k=0           S=10 i=./indat/dat2nfn.csv o=./outdat/out133nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=番号 S=10 i=./indat/dat2.csv    o=./outdat/out133nfno.csv

${pfxc}mnumber      -B k=日付 a=ランク S=H i=./indat/dat2.csv    o=./outdat/out134.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=H i=./indat/dat2.csv    o=./outdat/out134x.csv
${pfxc}mnumber -nfn -B k=0             S=H i=./indat/dat2nfn.csv o=./outdat/out134nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=ランク S=H i=./indat/dat2.csv    o=./outdat/out134nfno.csv

${pfxc}mnumber      -B k=日付 a=番号 S=15 I=8 i=./indat/dat2.csv    o=./outdat/out135.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=15 I=8 i=./indat/dat2.csv    o=./outdat/out135x.csv
${pfxc}mnumber -nfn -B k=0           S=15 I=8 i=./indat/dat2nfn.csv o=./outdat/out135nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=番号 S=15 I=8 i=./indat/dat2.csv    o=./outdat/out135nfno.csv

${pfxc}mnumber      -B k=日付 a=ランク S=A I=3 i=./indat/dat2.csv    o=./outdat/out136.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=A I=3 i=./indat/dat2.csv    o=./outdat/out136x.csv
${pfxc}mnumber -nfn -B k=0             S=A I=3 i=./indat/dat2nfn.csv o=./outdat/out136nfn.csv
${pfxc}mnumber -nfno -B k=日付 a=ランク S=A I=3 i=./indat/dat2.csv    o=./outdat/out136nfno.csv

#s=複数
${pfxc}mnumber      a=順位 e=seq s=顧客,金額%nr i=./indat/dat3.csv    o=./outdat/out137.csv
${pfxc}mnumber -x   a=順位 e=seq s=0,2%nr       i=./indat/dat3.csv    o=./outdat/out137x.csv
${pfxc}mnumber -nfn        e=seq s=0,2%nr       i=./indat/dat3nfn.csv o=./outdat/out137nfn.csv
${pfxc}mnumber -nfno a=順位 e=seq s=顧客,金額%nr i=./indat/dat3.csv    o=./outdat/out137nfno.csv

${pfxc}mnumber      a=順位 e=same s=顧客,金額%nr i=./indat/dat3.csv    o=./outdat/out138.csv
${pfxc}mnumber -x   a=順位 e=same s=0,2%nr       i=./indat/dat3.csv    o=./outdat/out138x.csv
${pfxc}mnumber -nfn        e=same s=0,2%nr       i=./indat/dat3nfn.csv o=./outdat/out138nfn.csv
${pfxc}mnumber -nfno a=順位 e=same s=顧客,金額%nr i=./indat/dat3.csv    o=./outdat/out138nfno.csv

${pfxc}mnumber      a=順位 e=skip s=顧客,金額%nr i=./indat/dat3.csv    o=./outdat/out139.csv
${pfxc}mnumber -x   a=順位 e=skip s=0,2%nr       i=./indat/dat3.csv    o=./outdat/out139x.csv
${pfxc}mnumber -nfn        e=skip s=0,2%nr       i=./indat/dat3nfn.csv o=./outdat/out139nfn.csv
${pfxc}mnumber -nfno a=順位 e=skip s=顧客,金額%nr i=./indat/dat3.csv    o=./outdat/out139nfno.csv

${pfxc}mnumber      k=日付 a=順位 s=顧客,金額%nr i=./indat/dat4.csv    o=./outdat/out140.csv
${pfxc}mnumber -x   k=0    a=順位 s=1,3%nr       i=./indat/dat4.csv    o=./outdat/out140x.csv
${pfxc}mnumber -nfn k=0           s=1,3%nr       i=./indat/dat4nfn.csv o=./outdat/out140nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 s=顧客,金額%nr i=./indat/dat4.csv    o=./outdat/out140nfno.csv

${pfxc}mnumber      k=日付 a=順位 e=same s=顧客,金額%nr i=./indat/dat4.csv    o=./outdat/out141.csv
${pfxc}mnumber -x   k=0    a=順位 e=same s=1,3%nr       i=./indat/dat4.csv    o=./outdat/out141x.csv
${pfxc}mnumber -nfn k=0           e=same s=1,3%nr       i=./indat/dat4nfn.csv o=./outdat/out141nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=same s=顧客,金額%nr i=./indat/dat4.csv    o=./outdat/out141nfno.csv

${pfxc}mnumber      k=日付 a=順位 e=skip s=顧客,金額%nr i=./indat/dat4.csv    o=./outdat/out142.csv
${pfxc}mnumber -x   k=0    a=順位 e=skip s=1,3%nr       i=./indat/dat4.csv    o=./outdat/out142x.csv
${pfxc}mnumber -nfn k=0           e=skip s=1,3%nr       i=./indat/dat4nfn.csv o=./outdat/out142nfn.csv
${pfxc}mnumber -nfno k=日付 a=順位 e=skip s=顧客,金額%nr i=./indat/dat4.csv    o=./outdat/out142nfno.csv

#NULL混在
${pfxc}mnumber      a=番号 s=金額%nr i=./indat/dat5.csv    o=./outdat/out143.csv
${pfxc}mnumber -x   a=番号 s=2%nr i=./indat/dat5.csv    o=./outdat/out143x.csv
${pfxc}mnumber -nfn       s=2%nr i=./indat/dat5nfn.csv o=./outdat/out143nfn.csv

${pfxc}mnumber      a=順位 e=seq s=金額%nr i=./indat/dat5.csv    o=./outdat/out144.csv
${pfxc}mnumber -x   a=順位 e=seq s=2%nr    i=./indat/dat5.csv    o=./outdat/out144x.csv
${pfxc}mnumber -nfn        e=seq s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out144nfn.csv

${pfxc}mnumber      a=順位 e=same s=金額%nr i=./indat/dat5.csv    o=./outdat/out145.csv
${pfxc}mnumber -x   a=順位 e=same s=2%nr    i=./indat/dat5.csv    o=./outdat/out145x.csv
${pfxc}mnumber -nfn        e=same s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out145nfn.csv

${pfxc}mnumber      a=順位 e=skip s=金額%nr i=./indat/dat5.csv    o=./outdat/out146.csv
${pfxc}mnumber -x   a=順位 e=skip s=2%nr    i=./indat/dat5.csv    o=./outdat/out146x.csv
${pfxc}mnumber -nfn        e=skip s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out146nfn.csv

${pfxc}mnumber      a=番号 S=10 s=金額%nr i=./indat/dat5.csv    o=./outdat/out147.csv
${pfxc}mnumber -x   a=番号 S=10 s=2%nr i=./indat/dat5.csv    o=./outdat/out147x.csv
${pfxc}mnumber -nfn        S=10 s=2%nr i=./indat/dat5nfn.csv o=./outdat/out147nfn.csv

${pfxc}mnumber      a=得点 S=10 e=same s=金額%nr i=./indat/dat5.csv    o=./outdat/out148.csv
${pfxc}mnumber -x   a=得点 S=10 e=same s=2%nr    i=./indat/dat5.csv    o=./outdat/out148x.csv
${pfxc}mnumber -nfn        S=10 e=same s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out148nfn.csv

${pfxc}mnumber      a=番号 S=20 e=skip s=金額%nr i=./indat/dat5.csv    o=./outdat/out149.csv
${pfxc}mnumber -x   a=番号 S=20 e=skip s=2%nr    i=./indat/dat5.csv    o=./outdat/out149x.csv
${pfxc}mnumber -nfn        S=20 e=skip s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out149nfn.csv

${pfxc}mnumber      a=ランク S=H s=金額%nr i=./indat/dat5.csv    o=./outdat/out150.csv
${pfxc}mnumber -x   a=ランク S=H s=2%nr i=./indat/dat5.csv    o=./outdat/out150x.csv
${pfxc}mnumber -nfn          S=H s=2%nr i=./indat/dat5nfn.csv o=./outdat/out150nfn.csv

${pfxc}mnumber      a=ランク S=A e=same s=金額%nr i=./indat/dat5.csv    o=./outdat/out151.csv
${pfxc}mnumber -x   a=ランク S=A e=same s=2%nr    i=./indat/dat5.csv    o=./outdat/out151x.csv
${pfxc}mnumber -nfn          S=A e=same s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out151nfn.csv

${pfxc}mnumber      a=ランク S=X e=skip s=金額%nr i=./indat/dat5.csv    o=./outdat/out152.csv
${pfxc}mnumber -x   a=ランク S=X e=skip s=2%nr    i=./indat/dat5.csv    o=./outdat/out152x.csv
${pfxc}mnumber -nfn          S=X e=skip s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out152nfn.csv

${pfxc}mnumber      a=番号 S=15 I=8 s=金額%nr i=./indat/dat5.csv    o=./outdat/out153.csv
${pfxc}mnumber -x   a=番号 S=15 I=8 s=2%nr i=./indat/dat5.csv    o=./outdat/out153x.csv
${pfxc}mnumber -nfn        S=15 I=8 s=2%nr i=./indat/dat5nfn.csv o=./outdat/out153nfn.csv

${pfxc}mnumber      a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat5.csv    o=./outdat/out154.csv
${pfxc}mnumber -x   a=得点 S=10 I=5 e=same s=2%nr    i=./indat/dat5.csv    o=./outdat/out154x.csv
${pfxc}mnumber -nfn        S=10 I=5 e=same s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out154nfn.csv

${pfxc}mnumber      a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat5.csv    o=./outdat/out155.csv
${pfxc}mnumber -x   a=番号 S=20 I=7 e=skip s=2%nr    i=./indat/dat5.csv    o=./outdat/out155x.csv
${pfxc}mnumber -nfn        S=20 I=7 e=skip s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out155nfn.csv

${pfxc}mnumber      a=ランク S=A I=3 s=金額%nr i=./indat/dat5.csv    o=./outdat/out156.csv
${pfxc}mnumber -x   a=ランク S=A I=3 s=2%nr i=./indat/dat5.csv    o=./outdat/out156x.csv
${pfxc}mnumber -nfn          S=A I=3 s=2%nr i=./indat/dat5nfn.csv o=./outdat/out156nfn.csv

${pfxc}mnumber      a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat5.csv    o=./outdat/out157.csv
${pfxc}mnumber -x   a=ランク S=H I=5 e=same s=2%nr    i=./indat/dat5.csv    o=./outdat/out157x.csv
${pfxc}mnumber -nfn          S=H I=5 e=same s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out157nfn.csv

${pfxc}mnumber      a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat5.csv    o=./outdat/out158.csv
${pfxc}mnumber -x   a=ランク S=X I=10 e=skip s=2%nr    i=./indat/dat5.csv    o=./outdat/out158x.csv
${pfxc}mnumber -nfn          S=X I=10 e=skip s=2%nr    i=./indat/dat5nfn.csv o=./outdat/out158nfn.csv

${pfxc}mnumber      k=日付 a=番号 s=金額%nr i=./indat/dat6.csv    o=./outdat/out159.csv
${pfxc}mnumber -x   k=0    a=番号 s=3%nr i=./indat/dat6.csv    o=./outdat/out159x.csv
${pfxc}mnumber -nfn k=0          s=3%nr i=./indat/dat6nfn.csv o=./outdat/out159nfn.csv

${pfxc}mnumber      k=日付 a=順位 e=same s=金額%nr i=./indat/dat6.csv    o=./outdat/out160.csv
${pfxc}mnumber -x   k=0    a=順位 e=same s=3%nr   i=./indat/dat6.csv    o=./outdat/out160x.csv
${pfxc}mnumber -nfn k=0           e=same s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out160nfn.csv

${pfxc}mnumber      k=日付 a=順位 e=skip s=金額%nr i=./indat/dat6.csv    o=./outdat/out161.csv
${pfxc}mnumber -x   k=0    a=順位 e=skip s=3%nr    i=./indat/dat6.csv    o=./outdat/out161x.csv
${pfxc}mnumber -nfn k=0           e=skip s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out161nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=10 s=金額%nr i=./indat/dat6.csv    o=./outdat/out162.csv
${pfxc}mnumber -x   k=0    a=番号 S=10 s=3%nr i=./indat/dat6.csv    o=./outdat/out162x.csv
${pfxc}mnumber -nfn k=0           S=10 s=3%nr i=./indat/dat6nfn.csv o=./outdat/out162nfn.csv

${pfxc}mnumber      k=日付 a=得点 S=10 e=same s=金額%nr i=./indat/dat6.csv    o=./outdat/out163.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 e=same s=3%nr    i=./indat/dat6.csv    o=./outdat/out163x.csv
${pfxc}mnumber -nfn k=0           S=10 e=same s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out163nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=20 e=skip s=金額%nr i=./indat/dat6.csv    o=./outdat/out164.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 e=skip s=3%nr   i=./indat/dat6.csv    o=./outdat/out164x.csv
${pfxc}mnumber -nfn k=0           S=20 e=skip s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out164nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=H s=金額%nr i=./indat/dat6.csv    o=./outdat/out165.csv
${pfxc}mnumber -x   k=0    a=ランク S=H s=3%nr i=./indat/dat6.csv    o=./outdat/out165x.csv
${pfxc}mnumber -nfn k=0             S=H s=3%nr i=./indat/dat6nfn.csv o=./outdat/out165nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=A e=same s=金額%nr i=./indat/dat6.csv    o=./outdat/out166.csv
${pfxc}mnumber -x   k=0    a=ランク S=A e=same s=3%nr    i=./indat/dat6.csv    o=./outdat/out166x.csv
${pfxc}mnumber -nfn k=0             S=A e=same s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out166nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=X e=skip s=金額%nr i=./indat/dat6.csv    o=./outdat/out167.csv
${pfxc}mnumber -x   k=0    a=ランク S=X e=skip s=3%nr    i=./indat/dat6.csv    o=./outdat/out167x.csv
${pfxc}mnumber -nfn k=0             S=X e=skip s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out167nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=15 I=8 s=金額%nr i=./indat/dat6.csv    o=./outdat/out168.csv
${pfxc}mnumber -x   k=0    a=番号 S=15 I=8 s=3%nr i=./indat/dat6.csv    o=./outdat/out168x.csv
${pfxc}mnumber -nfn k=0           S=15 I=8 s=3%nr i=./indat/dat6nfn.csv o=./outdat/out168nfn.csv

${pfxc}mnumber      k=日付 a=得点 S=10 I=5 e=same s=金額%nr i=./indat/dat6.csv    o=./outdat/out169.csv
${pfxc}mnumber -x   k=0    a=得点 S=10 I=5 e=same s=3%nr    i=./indat/dat6.csv    o=./outdat/out169x.csv
${pfxc}mnumber -nfn k=0           S=10 I=5 e=same s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out169nfn.csv

${pfxc}mnumber      k=日付 a=番号 S=20 I=7 e=skip s=金額%nr i=./indat/dat6.csv    o=./outdat/out170.csv
${pfxc}mnumber -x   k=0    a=番号 S=20 I=7 e=skip s=3%nr    i=./indat/dat6.csv    o=./outdat/out170x.csv
${pfxc}mnumber -nfn k=0           S=20 I=7 e=skip s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out170nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=A I=3 s=金額%nr i=./indat/dat6.csv    o=./outdat/out171.csv
${pfxc}mnumber -x   k=0    a=ランク S=A I=3 s=3%nr i=./indat/dat6.csv    o=./outdat/out171x.csv
${pfxc}mnumber -nfn k=0             S=A I=3 s=3%nr i=./indat/dat6nfn.csv o=./outdat/out171nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=H I=5 e=same s=金額%nr i=./indat/dat6.csv    o=./outdat/out172.csv
${pfxc}mnumber -x   k=0    a=ランク S=H I=5 e=same s=3%nr    i=./indat/dat6.csv    o=./outdat/out172x.csv
${pfxc}mnumber -nfn k=0             S=H I=5 e=same s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out172nfn.csv

${pfxc}mnumber      k=日付 a=ランク S=X I=10 e=skip s=金額%nr i=./indat/dat6.csv    o=./outdat/out173.csv
${pfxc}mnumber -x   k=0    a=ランク S=X I=10 e=skip s=3%nr    i=./indat/dat6.csv    o=./outdat/out173x.csv
${pfxc}mnumber -nfn k=0             S=X I=10 e=skip s=3%nr    i=./indat/dat6nfn.csv o=./outdat/out173nfn.csv

#-B使用
${pfxc}mnumber      -B k=日付 a=番号 i=./indat/dat6.csv    o=./outdat/out174.csv
${pfxc}mnumber -x   -B k=0    a=番号 i=./indat/dat6.csv    o=./outdat/out174x.csv
${pfxc}mnumber -nfn -B k=0           i=./indat/dat6nfn.csv o=./outdat/out174nfn.csv

${pfxc}mnumber      -B k=日付 a=番号 S=10 i=./indat/dat6.csv    o=./outdat/out175.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=10 i=./indat/dat6.csv    o=./outdat/out175x.csv
${pfxc}mnumber -nfn -B k=0           S=10 i=./indat/dat6nfn.csv o=./outdat/out175nfn.csv

${pfxc}mnumber      -B k=日付 a=ランク S=H i=./indat/dat6.csv    o=./outdat/out176.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=H i=./indat/dat6.csv    o=./outdat/out176x.csv
${pfxc}mnumber -nfn -B k=0             S=H i=./indat/dat6nfn.csv o=./outdat/out176nfn.csv

${pfxc}mnumber      -B k=日付 a=番号 S=15 I=8 i=./indat/dat6.csv    o=./outdat/out177.csv
${pfxc}mnumber -x   -B k=0    a=番号 S=15 I=8 i=./indat/dat6.csv    o=./outdat/out177x.csv
${pfxc}mnumber -nfn -B k=0           S=15 I=8 i=./indat/dat6nfn.csv o=./outdat/out177nfn.csv

${pfxc}mnumber      -B k=日付 a=ランク S=A I=3 i=./indat/dat6.csv    o=./outdat/out178.csv
${pfxc}mnumber -x   -B k=0    a=ランク S=A I=3 i=./indat/dat6.csv    o=./outdat/out178x.csv
${pfxc}mnumber -nfn -B k=0             S=A I=3 i=./indat/dat6nfn.csv o=./outdat/out178nfn.csv
