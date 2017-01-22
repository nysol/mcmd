#!/bin/bash

. ../env

#name_kg_mcmd rand

#NULL
${pfxc}mrand      a=乱数 S=2 -int i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mrand -x   a=乱数 S=2 -int i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mrand -nfn        S=2 -int i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 -int i=./indat/dat0.csv    o=./outdat/out0nfno.csv

#基本
${pfxc}mrand      a=乱数 S=2 -int i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mrand -x   a=乱数 S=2 -int i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mrand -nfn        S=2 -int i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 -int i=./indat/dat1.csv    o=./outdat/out1nfno.csv

#最小指定
${pfxc}mrand      a=乱数 S=2 min=10 -int i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mrand -x   a=乱数 S=2 min=10 -int i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mrand -nfn        S=2 min=10 -int i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 min=10 -int i=./indat/dat1.csv    o=./outdat/out2nfno.csv

#最大指定
${pfxc}mrand      a=乱数 S=2 max=20 -int i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mrand -x   a=乱数 S=2 max=20 -int i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mrand -nfn        S=2 max=20 -int i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 max=20 -int i=./indat/dat1.csv    o=./outdat/out3nfno.csv

#最小、最大指定
${pfxc}mrand      a=乱数 S=2 min=10 max=20 -int i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}mrand -x   a=乱数 S=2 min=10 max=20 -int i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}mrand -nfn        S=2 min=10 max=20 -int i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 min=10 max=20 -int i=./indat/dat1.csv    o=./outdat/out4nfno.csv

#NULL行あり
${pfxc}mrand      a=乱数 S=2 -int i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mrand -x   a=乱数 S=2 -int i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mrand -nfn        S=2 -int i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 -int i=./indat/dat2.csv    o=./outdat/out5nfno.csv

#最小指定
${pfxc}mrand      a=乱数 S=2 min=10 -int i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mrand -x   a=乱数 S=2 min=10 -int i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mrand -nfn        S=2 min=10 -int i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 min=10 -int i=./indat/dat2.csv    o=./outdat/out6nfno.csv

#最大指定
${pfxc}mrand      a=乱数 S=2 max=20 -int i=./indat/dat2.csv    o=./outdat/out7.csv
${pfxc}mrand -x   a=乱数 S=2 max=20 -int i=./indat/dat2.csv    o=./outdat/out7x.csv
${pfxc}mrand -nfn        S=2 max=20 -int i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 max=20 -int i=./indat/dat2.csv    o=./outdat/out7nfno.csv

#最小、最大指定
${pfxc}mrand      a=乱数 S=2 min=10 max=20 -int i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}mrand -x   a=乱数 S=2 min=10 max=20 -int i=./indat/dat2.csv    o=./outdat/out8x.csv
${pfxc}mrand -nfn        S=2 min=10 max=20 -int i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv
${pfxc}mrand -nfno a=乱数 S=2 min=10 max=20 -int i=./indat/dat2.csv    o=./outdat/out8nfno.csv

#seed指定なし
${pfxc}mrand      a=乱数 -int i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}mrand -x   a=乱数 -int i=./indat/dat1.csv    o=./outdat/out9x.csv
${pfxc}mrand -nfn        -int i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv
${pfxc}mrand -nfno a=乱数 -int i=./indat/dat1.csv    o=./outdat/out9nfno.csv

${pfxc}mrand      a=乱数 -int i=./indat/dat1.csv    min=10 o=./outdat/out10.csv
${pfxc}mrand -x   a=乱数 -int i=./indat/dat1.csv    min=10 o=./outdat/out10x.csv
${pfxc}mrand -nfn        -int i=./indat/dat1nfn.csv min=10 o=./outdat/out10nfn.csv
${pfxc}mrand -nfno a=乱数 -int i=./indat/dat1.csv    min=10 o=./outdat/out10nfno.csv

${pfxc}mrand      a=乱数 -int i=./indat/dat1.csv    max=20 o=./outdat/out11.csv
${pfxc}mrand -x   a=乱数 -int i=./indat/dat1.csv    max=20 o=./outdat/out11x.csv
${pfxc}mrand -nfn       -int i=./indat/dat1nfn.csv max=20 o=./outdat/out11nfn.csv
${pfxc}mrand -nfno a=乱数 -int i=./indat/dat1.csv    max=20 o=./outdat/out11nfno.csv

${pfxc}mrand      a=乱数 -int i=./indat/dat1.csv    min=10 max=20 o=./outdat/out12.csv
${pfxc}mrand -x   a=乱数 -int i=./indat/dat1.csv    min=10 max=20 o=./outdat/out12x.csv
${pfxc}mrand -nfn        -int i=./indat/dat1nfn.csv min=10 max=20 o=./outdat/out12nfn.csv
${pfxc}mrand -nfno a=乱数 -int i=./indat/dat1.csv    min=10 max=20 o=./outdat/out12nfno.csv

${pfxc}mrand      a=乱数 i=./indat/dat1.csv    o=./outdat/out15.csv
${pfxc}mrand -x   a=乱数 i=./indat/dat1.csv    o=./outdat/out15x.csv
${pfxc}mrand -nfn        i=./indat/dat1nfn.csv o=./outdat/out15nfn.csv
${pfxc}mrand -nfno a=乱数  i=./indat/dat1.csv   o=./outdat/out15nfno.csv

#実数指定
${pfxc}mrand      a=乱数 S=2 i=./indat/dat1.csv    o=./outdat/out13.csv

#k=あり
${pfxc}mrand k=顧客       a=乱数 S=2 -int  i=./indat/dat3s.csv    o=./outdat/out14.csv
${pfxc}mrand k=0    -x    a=乱数 S=2 -int  i=./indat/dat3s.csv    o=./outdat/out14x.csv
${pfxc}mrand k=0    -nfn  a=乱数 S=2 -int  i=./indat/dat3snfn.csv    o=./outdat/out14nfn.csv
${pfxc}mrand k=顧客       a=乱数 S=2       i=./indat/dat3s.csv    o=./outdat/out16.csv
${pfxc}mrand k=0    -x    a=乱数 S=2       i=./indat/dat3s.csv    o=./outdat/out16x.csv
${pfxc}mrand k=0    -nfn  a=乱数 S=2       i=./indat/dat3snfn.csv    o=./outdat/out16nfn.csv

${pfxc}mrand k=顧客      a=乱数 S=2 -int  i=./indat/dat3.csv    o=./outdat/out17.csv
${pfxc}mrand k=0    -x   a=乱数 S=2 -int  i=./indat/dat3.csv    o=./outdat/out17x.csv
${pfxc}mrand k=0    -nfn a=乱数 S=2 -int  i=./indat/dat3nfn.csv    o=./outdat/out17nfn.csv
${pfxc}mrand k=顧客 -q   a=乱数 S=2 -int  i=./indat/dat3.csv    o=./outdat/out17q.csv
${pfxc}mrand k=顧客      a=乱数 S=2       i=./indat/dat3.csv    o=./outdat/out18.csv
${pfxc}mrand k=0   -x   a=乱数 S=2       i=./indat/dat3.csv    o=./outdat/out18x.csv
${pfxc}mrand k=0   -nfn a=乱数 S=2       i=./indat/dat3nfn.csv    o=./outdat/out18nfn.csv
${pfxc}mrand k=顧客 -q   a=乱数 S=2       i=./indat/dat3.csv    o=./outdat/out18q.csv







