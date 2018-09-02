#!/bin/bash

. ../env
#name_kg_mcmd nrjoin

#NULLデータ
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out0.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out0x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out0nfn.csv
${pfxc}mnrjoin -nfno     k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out0nfno.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out1nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out2.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out2x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out2nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out3.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out3x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out3nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out4.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out4x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out4nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out5.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out5x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out5nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out6.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out6x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out6nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out7.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out7x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out7nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out8.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out8x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out8nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out9.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out9x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out9nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out10.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out10x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out10nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out11.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out11x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out11nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat15s.csv    m=./indat/dat16s.csv    o=./outdat/out174.csv

#基本
${pfxc}mnrjoin      R=金額F,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out12.csv
${pfxc}mnrjoin -x   R=0,1         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out12x.csv
${pfxc}mnrjoin -nfn R=0,1         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out12nfn.csv
${pfxc}mnrjoin -nfno R=金額F,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out12nfno.csv

${pfxc}mnrjoin      R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out13.csv    -n
${pfxc}mnrjoin -x   R=0,1         rf=1%n    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out13x.csv   -n
${pfxc}mnrjoin -nfn R=0,1         rf=1%n    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out13nfn.csv -n

${pfxc}mnrjoin      R=金額F,金額T rf=金額%n f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out14.csv    -N
${pfxc}mnrjoin -x   R=0,1         rf=1%n    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out14x.csv   -N
${pfxc}mnrjoin -nfn R=0,1         rf=1%n    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out14nfn.csv -N

${pfxc}mnrjoin      R=金額F,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out15.csv    -N -n
${pfxc}mnrjoin -x   R=0,1         rf=1%n    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out15x.csv   -N -n
${pfxc}mnrjoin -nfn R=0,1         rf=1%n    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out15nfn.csv -N -n

${pfxc}mnrjoin      R=金額F,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out16.csv
${pfxc}mnrjoin -x   R=0,1         rf=1    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out16x.csv
${pfxc}mnrjoin -nfn R=0,1         rf=1    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out16nfn.csv

${pfxc}mnrjoin      R=金額F,金額T rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out17.csv    -n
${pfxc}mnrjoin -x   R=0,1         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out17x.csv   -n
${pfxc}mnrjoin -nfn R=0,1         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out17nfn.csv -n

${pfxc}mnrjoin      R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out18.csv    -N
${pfxc}mnrjoin -x   R=0,1         rf=1    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out18x.csv   -N
${pfxc}mnrjoin -nfn R=0,1         rf=1    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out18nfn.csv -N

${pfxc}mnrjoin      R=金額F,金額T rf=金額 f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out19.csv    -n -N
${pfxc}mnrjoin -x   R=0,1         rf=1    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out19x.csv   -n -N
${pfxc}mnrjoin -nfn R=0,1         rf=1    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out19nfn.csv -n -N

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額%n f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out20.csv
${pfxc}mnrjoin -x   R=0%n,1         rf=1%n    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out20x.csv
${pfxc}mnrjoin -nfn R=0%n,1         rf=1%n    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out20nfn.csv

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out21.csv    -n
${pfxc}mnrjoin -x   R=0%n,1         rf=1%n    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out21x.csv   -n
${pfxc}mnrjoin -nfn R=0%n,1         rf=1%n    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out21nfn.csv -n

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out22.csv    -N
${pfxc}mnrjoin -x   R=0%n,1         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out22x.csv   -N
${pfxc}mnrjoin -nfn R=0%n,1         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out22nfn.csv -N

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out23.csv    -n -N
${pfxc}mnrjoin -x   R=0%n,1         rf=1%n    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out23x.csv   -n -N
${pfxc}mnrjoin -nfn R=0%n,1         rf=1%n    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out23nfn.csv -n -N

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額 f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out24.csv 
${pfxc}mnrjoin -x   R=0%n,1         rf=1    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out24x.csv 
${pfxc}mnrjoin -nfn R=0%n,1         rf=1    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out24nfn.csv 

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額 f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out25.csv    -n
${pfxc}mnrjoin -x   R=0%n,1         rf=1    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out25x.csv   -n
${pfxc}mnrjoin -nfn R=0%n,1         rf=1    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out25nfn.csv -n

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out26.csv    -N
${pfxc}mnrjoin -x   R=0%n,1         rf=1    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out26x.csv   -N
${pfxc}mnrjoin -nfn R=0%n,1         rf=1    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out26nfn.csv -N

${pfxc}mnrjoin      R=金額F%n,金額T rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out27.csv    -n -N
${pfxc}mnrjoin -x   R=0%n,1         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out27x.csv   -n -N
${pfxc}mnrjoin -nfn R=0%n,1         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out27nfn.csv -n -N

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out28.csv
${pfxc}mnrjoin -x   R=0,1%e         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out28x.csv
${pfxc}mnrjoin -nfn R=0,1%e         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out28nfn.csv

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額%n f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out29.csv    -n
${pfxc}mnrjoin -x   R=0,1%e         rf=1%n    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out29x.csv   -n
${pfxc}mnrjoin -nfn R=0,1%e         rf=1%n    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out29nfn.csv -n

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out30.csv    -N
${pfxc}mnrjoin -x   R=0,1%e         rf=1%n    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out30x.csv   -N
${pfxc}mnrjoin -nfn R=0,1%e         rf=1%n    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out30nfn.csv -N

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out31.csv    -n -N
${pfxc}mnrjoin -x   R=0,1%e         rf=1%n    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out31x.csv   -n -N
${pfxc}mnrjoin -nfn R=0,1%e         rf=1%n    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out31nfn.csv -n -N

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out32.csv
${pfxc}mnrjoin -x   R=0,1%e         rf=1    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out32x.csv
${pfxc}mnrjoin -nfn R=0,1%e         rf=1    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out32nfn.csv

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out33.csv    -n
${pfxc}mnrjoin -x   R=0,1%e         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out33x.csv   -n
${pfxc}mnrjoin -nfn R=0,1%e         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out33nfn.csv -n

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額 f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out34.csv    -N
${pfxc}mnrjoin -x   R=0,1%e         rf=1    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out34x.csv   -N
${pfxc}mnrjoin -nfn R=0,1%e         rf=1    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out34nfn.csv -N

${pfxc}mnrjoin      R=金額F,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out35.csv    -n -N
${pfxc}mnrjoin -x   R=0,1%e         rf=1    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out35x.csv    -n -N
${pfxc}mnrjoin -nfn R=0,1%e         rf=1    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out35nfn.csv -n -N

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out36.csv
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1%n    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out36x.csv
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1%n    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out36nfn.csv

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out37.csv    -n
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1%n    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out37x.csv   -n
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1%n    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out37nfn.csv -n

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out38.csv    -N
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out38x.csv   -N
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out38nfn.csv -N

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額%n f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out39.csv    -n -N
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1%n    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out39x.csv   -n -N
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1%n    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out39nfn.csv -n -N

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out40.csv
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1    f=2        i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out40x.csv
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1    f=2        i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out40nfn.csv

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out41.csv    -n
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1    f=2,0            i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out41x.csv   -n
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1    f=2,0            i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out41nfn.csv -n

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out42.csv    -N
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1    f=2,0,1                i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out42x.csv   -N
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1    f=2,0,1                i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out42nfn.csv -N

${pfxc}mnrjoin      R=金額F%n,金額T%e rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out43.csv    -n -N
${pfxc}mnrjoin -x   R=0%n,1%e         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out43x.csv   -n -N
${pfxc}mnrjoin -nfn R=0%n,1%e         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out43nfn.csv -n -N

#k=有
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out44.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out44x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out44nfn.csv
${pfxc}mnrjoin -q   k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out44q.csv
${pfxc}mnrjoin -q -x k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out44qx.csv


${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out45.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out45x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out45nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out46.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out46x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out46nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out47.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out47x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out47nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out48.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out48x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1,2               i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out48nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out49.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out49x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out49nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out50.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out50x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out50nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out51.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out51x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out51nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out52.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out52x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out52nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out53.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out53x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out53nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out54.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out54x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out54nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out55.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out55x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out55nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out56.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out56x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out56nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out57.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out57x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out57nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out58.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out58x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out58nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out59.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out59x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out59nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out60.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out60x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out60nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out61.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out61x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out61nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out62.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out62x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out62nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out63.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out63x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out63nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out64.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out64x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out64nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out65.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out65x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out65nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out66.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out66x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out66nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out67.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out67x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out67nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out68.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out68x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out68nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out69.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out69x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out69nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out70.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out70x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out70nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out71.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out71x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out71nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out72.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out72x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out72nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out73.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1            i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out73x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1            i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out73nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out74.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out74x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out74nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out75.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out75x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out75nfn.csv -n -N

#k=二つ
${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out76.csv
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out76x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out76nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out77.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3%n    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out77x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3%n    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out77nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額%n f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out78.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3%n    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out78x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3%n    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out78nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out79.csv    -N -n
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3%n    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out79x.csv   -N -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3%n    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out79nfn.csv -N -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out80.csv
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out80x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out80nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out81.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out81x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out81nfn.csv -n



${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out82.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out82x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out82nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額 f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out83.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out83x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out83nfn.csv -n -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out84.csv
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3%n    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out84x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3%n    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out84nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out85.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3%n    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out85x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3%n    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out85nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out86.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out86x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out86nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out87.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3%n    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out87x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3%n    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out87nfn.csv -n -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額 f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out88.csv 
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out88x.csv 
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out88nfn.csv 

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out89.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out89x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out89nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out90.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out90x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out90nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out91.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out91x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out91nfn.csv -n -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out92.csv
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out92x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out92nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額%n f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out93.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3%n    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out93x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3%n    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out93nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out94.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3%n    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out94x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3%n    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out94nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out95.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3%n    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out95x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3%n    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out95nfn.csv -n -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out96.csv
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out96x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out96nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out97.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out97x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out97nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額 f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out98.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out98x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out98nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out99.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out99x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out99nfn.csv -n -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out100.csv
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3%n    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out100x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3%n    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out100nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out101.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3%n    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out101x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3%n    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out101nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out102.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out102x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out102nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out103.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3%n    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out103x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3%n    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out103nfn.csv -n -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out104.csv
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3    f=4        i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out104x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3    f=4        i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out104nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out105.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3    f=4,2            i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out105x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3    f=4,2            i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out105nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out106.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3    f=4,2,3                i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out106x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3    f=4,2,3                i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out106nfn.csv -N

${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out107.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out107x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out107nfn.csv -n -N

#ここまでOK
#R=にNULL
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out108.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out108x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out108nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out109.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3        i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out109x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out109nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out110.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out110x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out110nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out111.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out111x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out111nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out112.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1,2               i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out112x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out112nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out113.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out113x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out113nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out114.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out114x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out114nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out115.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out115x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out115nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out116.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out116x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out116nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out117.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out117x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out117nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out118.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out118x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out118nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out119.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out119x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out119nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out120.csv 
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3        i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out120x.csv 
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out120nfn.csv 

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out121.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out121x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out121nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out122.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out122x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out122nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out123.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out123x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out123nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out124.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out124x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out124nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out125.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out125x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out125nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out126.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out126x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out126nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out127.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out127x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out127nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out128.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out128x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out128nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out129.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out129x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out129nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out130.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3        i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out130x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out130nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out131.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out131x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out131nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out132.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out132x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out132nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out133.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out133x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out133nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out134.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out134x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out134nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out135.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out135x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out135nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out136.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3       i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out136x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out136nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out137.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1            i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out137x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1            i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out137nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out138.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out138x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out138nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out139.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out139x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out139nfn.csv -n -N

#rf=にNULL
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out140.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out140x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out140nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out141.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out141x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out141nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out142.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out142x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out142nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out143.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out143x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out143nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out144.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out144x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out144nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out145.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out145x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out145nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out146.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out146x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out146nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out147.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out147x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out147nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out148.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out148x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out148nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out149.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out149x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out149nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out150.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out150x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out150nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out151.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out151x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out151nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out152.csv 
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out152x.csv 
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out152nfn.csv 

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out153.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out153x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out153nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out154.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out154x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out154nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out155.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2   i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out155x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out155nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out156.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out156x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out156nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out157.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out157x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out157nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out158.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out158x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out158nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out159.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out159x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out159nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out160.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out160x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out160nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out161.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out161x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out161nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out162.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out162x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out162nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out163.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out163x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out163nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out164.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out164x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out164nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out165.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out165x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out165nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out166.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out166x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out166nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out167.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out167x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out167nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out168.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out168x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out168nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out169.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1            i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out169x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1            i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out169nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out170.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out170x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out170nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out171.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out171x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out171nfn.csv -n -N

#K=指定
${pfxc}mnrjoin  K=日付1   k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat12s.csv    o=./outdat/out172.csv

#参照にinputより範囲が小さいもの
${pfxc}mnrjoin      R=金額F,金額T rf=金額%n i=./indat/dat13.csv    m=./indat/dat14.csv    o=./outdat/out173.csv

${pfxc}mnrjoin k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat17s.csv    o=./outdat/out176.csv    -N
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat18s.csv m=./indat/dat19s.csv -N o=./outdat/out177.csv
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat20s.csv m=./indat/dat21s.csv -N o=./outdat/out178.csv
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat18s.csv m=./indat/dat21s.csv -N o=./outdat/out179.csv
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat20s.csv m=./indat/dat19s.csv -N o=./outdat/out180.csv

#-----------------------------------------------------------------
# 以下ランダムデータ
#-----------------------------------------------------------------
#NULLデータ
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out200.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out200x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out200nfn.csv
${pfxc}mnrjoin -nfno     k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out200nfno.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out203.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out203x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out203nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat1.csv    o=./outdat/out207.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat1.csv    o=./outdat/out207x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat1nfn.csv o=./outdat/out207nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat3.csv    o=./outdat/out211.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat3.csv    o=./outdat/out211x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat3nfn.csv o=./outdat/out211nfn.csv -N -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat15.csv    m=./indat/dat16.csv    o=./outdat/out374.csv

#基本
#k=有
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out244.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out244x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out244nfn.csv
${pfxc}mnrjoin -q     k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out244q.csv
${pfxc}mnrjoin -q -x  k=0    R=1,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out244qx.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out245.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out245x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out245nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out250.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out250x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out250nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out255.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out255x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out255nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out256.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out256x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out256nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out261.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out261x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out261nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out266.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out266x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out266nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out271.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out271x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out271nfn.csv -n -N


${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out272.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out272x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out272nfn.csv

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額%n f=平均金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out277.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3%n    f=4        i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out277x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3%n    f=4        i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out277nfn.csv -n

${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out282.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2,3         rf=3    f=4        i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out282x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2,3         rf=3    f=4        i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out282nfn.csv -N


${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T rf=金額%n f=平均金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out287.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3         rf=3%n    f=4        i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out287x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3         rf=3%n    f=4        i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out287nfn.csv -n -N


${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out292.csv
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out292x.csv
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out292nfn.csv


${pfxc}mnrjoin      k=顧客,日付 R=金額F,金額T%e rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out297.csv    -n
${pfxc}mnrjoin -x   k=0,1       R=2,3%e         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out297x.csv   -n
${pfxc}mnrjoin -nfn k=0,1       R=2,3%e         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out297nfn.csv -n


${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out302.csv    -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out302x.csv   -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out302nfn.csv -N


${pfxc}mnrjoin      k=顧客,日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out307.csv    -n -N
${pfxc}mnrjoin -x   k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out307x.csv   -n -N
${pfxc}mnrjoin -nfn k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out307nfn.csv -n -N

#ここまでOK
#R=にNULL
${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out308.csv
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out308x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out308nfn.csv

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out313.csv    -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out313x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out313nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out318.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out318x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out318nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out323.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out323x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out323nfn.csv -n -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out328.csv
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out328x.csv
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1,2                i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out328nfn.csv


${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n f=平均金額,金額F,金額T i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out333.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out333x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2%n    f=3,1,2                i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out333nfn.csv -n

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額,金額F,金額T i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out338.csv    -N
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out338x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3,1,2                i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out338nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T rf=金額%n f=平均金額,金額F,金額T i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out343.csv    -N -n
${pfxc}mnrjoin -x   k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out343x.csv   -N -n
${pfxc}mnrjoin -nfn k=0    R=1,2         rf=2%n    f=3,1,2                i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out343nfn.csv -N -n


${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額%n f=平均金額,金額F i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out348.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out348x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2%n    f=3,1            i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out348nfn.csv


${pfxc}mnrjoin      k=日付 R=金額F%n,金額T rf=金額 f=平均金額,金額F i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out353.csv    -n
${pfxc}mnrjoin -x   k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out353x.csv   -n
${pfxc}mnrjoin -nfn k=0    R=1%n,2         rf=2    f=3,1            i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out353nfn.csv -n


${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額%n f=平均金額,金額F i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out358.csv    -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out358x.csv   -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2%n    f=3,1            i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out358nfn.csv -N

${pfxc}mnrjoin      k=日付 R=金額F,金額T%e rf=金額 f=平均金額,金額F i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out363.csv    -n -N
${pfxc}mnrjoin -x   k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out363x.csv   -n -N
${pfxc}mnrjoin -nfn k=0    R=1,2%e         rf=2    f=3,1            i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out363nfn.csv -n -N


${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額 f=平均金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out368.csv
${pfxc}mnrjoin -x   k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out368x.csv
${pfxc}mnrjoin -nfn k=0    R=1%n,2%e         rf=2    f=3        i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out368nfn.csv

#K=指定
${pfxc}mnrjoin  K=日付1   k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat12.csv    o=./outdat/out372.csv

${pfxc}mnrjoin      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat17.csv    o=./outdat/out376.csv    -N
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat18.csv m=./indat/dat19.csv -N o=./outdat/out377.csv
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat20.csv m=./indat/dat21.csv -N o=./outdat/out378.csv
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat18.csv m=./indat/dat21.csv -N o=./outdat/out379.csv
${pfxc}mnrjoin k=日付 R=金額F,金額T rf=金額 f=平均金額 i=./indat/dat20.csv m=./indat/dat19.csv -N o=./outdat/out380.csv
