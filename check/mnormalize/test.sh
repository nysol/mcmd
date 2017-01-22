#!/bin/bash

. ../env
#name_kg_mcmd normalize

#NULL
${pfxc}mnormalize      i=./indat/dat0s.csv    f=数量:数量基準値,金額:金額基準値 c=z o=./outdat/out0.csv
${pfxc}mnormalize -x   i=./indat/dat0s.csv    f=1:数量基準値,2:金額基準値       c=z o=./outdat/out0x.csv
${pfxc}mnormalize -nfn i=./indat/dat0snfn.csv f=1,2                             c=z o=./outdat/out0nfn.csv

${pfxc}mnormalize      i=./indat/dat5s.csv    f=数量:数量基準値 c=z o=./outdat/out35.csv

${pfxc}mnormalize      i=./indat/dat0s.csv    f=数量:数量基準値,金額:金額基準値 c=Z o=./outdat/out1.csv
${pfxc}mnormalize -x   i=./indat/dat0s.csv    f=1:数量基準値,2:金額基準値       c=Z o=./outdat/out1x.csv
${pfxc}mnormalize -nfn i=./indat/dat0snfn.csv f=1,2                             c=Z o=./outdat/out1nfn.csv

${pfxc}mnormalize      i=./indat/dat0s.csv    f=数量:数量基準値,金額:金額基準値 c=range o=./outdat/out2.csv
${pfxc}mnormalize -x   i=./indat/dat0s.csv    f=1:数量基準値,2:金額基準値       c=range o=./outdat/out2x.csv
${pfxc}mnormalize -nfn i=./indat/dat0snfn.csv f=1,2                             c=range o=./outdat/out2nfn.csv

#f=1
${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値 c=z o=./outdat/out3.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    f=1:数量基準値    c=z o=./outdat/out3x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv f=1               c=z o=./outdat/out3nfn.csv
${pfxc}mnormalize -nfno i=./indat/dat1s.csv    f=数量:数量基準値 c=z o=./outdat/out3nfno.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値 c=Z o=./outdat/out4.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    f=1:数量基準値    c=Z o=./outdat/out4x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv f=1               c=Z o=./outdat/out4nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値 c=range o=./outdat/out5.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    f=1:数量基準値    c=range o=./outdat/out5x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv f=1               c=range o=./outdat/out5nfn.csv

#f=複数
${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値,金額:金額基準値 c=z o=./outdat/out6.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    f=1:数量基準値,2:金額基準値       c=z o=./outdat/out6x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv f=1,2                             c=z o=./outdat/out6nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値,金額:金額基準値 c=Z o=./outdat/out7.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    f=1:数量基準値,2:金額基準値       c=Z o=./outdat/out7x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv f=1,2                             c=Z o=./outdat/out7nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値,金額:金額基準値 c=range o=./outdat/out8.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    f=1:数量基準値,2:金額基準値       c=range o=./outdat/out8x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv f=1,2                             c=range o=./outdat/out8nfn.csv

#k=あり
${pfxc}mnormalize      i=./indat/dat1s.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out9.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    k=0    f=2:金額基準値    c=z o=./outdat/out9x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv k=0    f=2               c=z o=./outdat/out9nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out10.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out10x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv k=0    f=2               c=Z o=./outdat/out10nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out11.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    k=0    f=2:金額基準値    c=range o=./outdat/out11x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv k=0    f=2               c=range o=./outdat/out11nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out12.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out12x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv k=0    f=2,1                             c=z o=./outdat/out12nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out13.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out13x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv k=0    f=2,1                             c=Z o=./outdat/out13nfn.csv

${pfxc}mnormalize      i=./indat/dat1s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out14.csv
${pfxc}mnormalize -x   i=./indat/dat1s.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out14x.csv
${pfxc}mnormalize -nfn i=./indat/dat1snfn.csv k=0    f=2,1                             c=range o=./outdat/out14nfn.csv

#k=にNULL有
${pfxc}mnormalize      i=./indat/dat2s.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out15.csv
${pfxc}mnormalize -x   i=./indat/dat2s.csv    k=0    f=2:金額基準値    c=z o=./outdat/out15x.csv
${pfxc}mnormalize -nfn i=./indat/dat2snfn.csv k=0    f=2               c=z o=./outdat/out15nfn.csv

${pfxc}mnormalize      i=./indat/dat2s.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out16.csv
${pfxc}mnormalize -x   i=./indat/dat2s.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out16x.csv
${pfxc}mnormalize -nfn i=./indat/dat2snfn.csv k=0    f=2               c=Z o=./outdat/out16nfn.csv

${pfxc}mnormalize      i=./indat/dat2s.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out17.csv
${pfxc}mnormalize -x   i=./indat/dat2s.csv    k=0    f=2:金額基準値    c=range o=./outdat/out17x.csv
${pfxc}mnormalize -nfn i=./indat/dat2snfn.csv k=0    f=2               c=range o=./outdat/out17nfn.csv

${pfxc}mnormalize      i=./indat/dat2s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out18.csv
${pfxc}mnormalize -x   i=./indat/dat2s.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out18x.csv
${pfxc}mnormalize -nfn i=./indat/dat2snfn.csv k=0    f=2,1                             c=z o=./outdat/out18nfn.csv

${pfxc}mnormalize      i=./indat/dat2s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out19.csv
${pfxc}mnormalize -x   i=./indat/dat2s.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out19x.csv
${pfxc}mnormalize -nfn i=./indat/dat2snfn.csv k=0    f=2,1                             c=Z o=./outdat/out19nfn.csv

${pfxc}mnormalize      i=./indat/dat2s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out20.csv
${pfxc}mnormalize -x   i=./indat/dat2s.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out20x.csv
${pfxc}mnormalize -nfn i=./indat/dat2snfn.csv k=0    f=2,1                             c=range o=./outdat/out20nfn.csv

#f=にNULLあり
${pfxc}mnormalize      i=./indat/dat3s.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out21.csv
${pfxc}mnormalize -x   i=./indat/dat3s.csv    k=0    f=2:金額基準値    c=z o=./outdat/out21x.csv
${pfxc}mnormalize -nfn i=./indat/dat3snfn.csv k=0    f=2               c=z o=./outdat/out21nfn.csv

${pfxc}mnormalize      i=./indat/dat3s.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out22.csv
${pfxc}mnormalize -x   i=./indat/dat3s.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out22x.csv
${pfxc}mnormalize -nfn i=./indat/dat3snfn.csv k=0    f=2               c=Z o=./outdat/out22nfn.csv

${pfxc}mnormalize      i=./indat/dat3s.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out23.csv
${pfxc}mnormalize -x   i=./indat/dat3s.csv    k=0    f=2:金額基準値    c=range o=./outdat/out23x.csv
${pfxc}mnormalize -nfn i=./indat/dat3snfn.csv k=0    f=2               c=range o=./outdat/out23nfn.csv

${pfxc}mnormalize      i=./indat/dat3s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out24.csv
${pfxc}mnormalize -x   i=./indat/dat3s.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out24x.csv
${pfxc}mnormalize -nfn i=./indat/dat3snfn.csv k=0    f=2,1                             c=z o=./outdat/out24nfn.csv

${pfxc}mnormalize      i=./indat/dat3s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out25.csv
${pfxc}mnormalize -x   i=./indat/dat3s.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out25x.csv
${pfxc}mnormalize -nfn i=./indat/dat3snfn.csv k=0    f=2,1                             c=Z o=./outdat/out25nfn.csv

${pfxc}mnormalize      i=./indat/dat3s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out26.csv
${pfxc}mnormalize -x   i=./indat/dat3s.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out26x.csv
${pfxc}mnormalize -nfn i=./indat/dat3snfn.csv k=0    f=2,1                             c=range o=./outdat/out26nfn.csv

#k=,f=にNULL有
${pfxc}mnormalize      i=./indat/dat4s.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out27.csv
${pfxc}mnormalize -x   i=./indat/dat4s.csv    k=0    f=2:金額基準値    c=z o=./outdat/out27x.csv
${pfxc}mnormalize -nfn i=./indat/dat4snfn.csv k=0    f=2               c=z o=./outdat/out27nfn.csv

${pfxc}mnormalize      i=./indat/dat4s.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out28.csv
${pfxc}mnormalize -x   i=./indat/dat4s.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out28x.csv
${pfxc}mnormalize -nfn i=./indat/dat4snfn.csv k=0    f=2               c=Z o=./outdat/out28nfn.csv

${pfxc}mnormalize      i=./indat/dat4s.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out29.csv
${pfxc}mnormalize -x   i=./indat/dat4s.csv    k=0    f=2:金額基準値    c=range o=./outdat/out29x.csv
${pfxc}mnormalize -nfn i=./indat/dat4snfn.csv k=0    f=2               c=range o=./outdat/out29nfn.csv

${pfxc}mnormalize      i=./indat/dat4s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out30.csv
${pfxc}mnormalize -x   i=./indat/dat4s.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out30x.csv
${pfxc}mnormalize -nfn i=./indat/dat4snfn.csv k=0    f=2,1                             c=z o=./outdat/out30nfn.csv

${pfxc}mnormalize      i=./indat/dat4s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out31.csv
${pfxc}mnormalize -x   i=./indat/dat4s.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out31x.csv
${pfxc}mnormalize -nfn i=./indat/dat4snfn.csv k=0    f=2,1                             c=Z o=./outdat/out31nfn.csv

${pfxc}mnormalize      i=./indat/dat4s.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out32.csv
${pfxc}mnormalize -x   i=./indat/dat4s.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out32x.csv
${pfxc}mnormalize -nfn i=./indat/dat4snfn.csv k=0    f=2,1                             c=range o=./outdat/out32nfn.csv

#f=がNULL
${pfxc}mnormalize      i=./indat/dat6s.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out36.csv
${pfxc}mnormalize      i=./indat/dat6s.csv    k=顧客 f=数量:数量基準値 c=range o=./outdat/out37.csv

#bufcount
${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値 c=z bufcount=2 o=./outdat/out33.csv
${pfxc}mnormalize      i=./indat/dat1s.csv    f=数量:数量基準値 c=z bufcount=-2 o=./outdat/out34.csv


#-----------------------------------------------------------------
# 以下ランダムデータ
#-----------------------------------------------------------------
#NULL
${pfxc}mnormalize      k=顧客 i=./indat/dat0.csv    f=数量:数量基準値,金額:金額基準値 c=z o=./outdat/out50.csv
${pfxc}mnormalize -x   k=0 i=./indat/dat0.csv    f=1:数量基準値,2:金額基準値       c=z o=./outdat/out50x.csv
${pfxc}mnormalize -nfn k=0 i=./indat/dat0nfn.csv f=1,2                             c=z o=./outdat/out50nfn.csv


${pfxc}mnormalize      k=顧客 i=./indat/dat0.csv    f=数量:数量基準値,金額:金額基準値 c=Z o=./outdat/out51.csv
${pfxc}mnormalize -x   k=0 i=./indat/dat0.csv    f=1:数量基準値,2:金額基準値       c=Z o=./outdat/out51x.csv
${pfxc}mnormalize -nfn k=0 i=./indat/dat0nfn.csv f=1,2                             c=Z o=./outdat/out51nfn.csv

${pfxc}mnormalize      k=顧客 i=./indat/dat0.csv    f=数量:数量基準値,金額:金額基準値 c=range o=./outdat/out52.csv
${pfxc}mnormalize -x   k=0 i=./indat/dat0.csv    f=1:数量基準値,2:金額基準値       c=range o=./outdat/out52x.csv
${pfxc}mnormalize -nfn k=0 i=./indat/dat0nfn.csv f=1,2                             c=range o=./outdat/out52nfn.csv

#k=あり
${pfxc}mnormalize      i=./indat/dat1.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out59.csv
${pfxc}mnormalize -x   i=./indat/dat1.csv    k=0    f=2:金額基準値    c=z o=./outdat/out59x.csv
${pfxc}mnormalize -nfn i=./indat/dat1nfn.csv k=0    f=2               c=z o=./outdat/out59nfn.csv

${pfxc}mnormalize      i=./indat/dat1.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out60.csv
${pfxc}mnormalize -x   i=./indat/dat1.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out60x.csv
${pfxc}mnormalize -nfn i=./indat/dat1nfn.csv k=0    f=2               c=Z o=./outdat/out60nfn.csv

${pfxc}mnormalize      i=./indat/dat1.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out61.csv
${pfxc}mnormalize -x   i=./indat/dat1.csv    k=0    f=2:金額基準値    c=range o=./outdat/out61x.csv
${pfxc}mnormalize -nfn i=./indat/dat1nfn.csv k=0    f=2               c=range o=./outdat/out61nfn.csv

${pfxc}mnormalize      i=./indat/dat1.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out62.csv
${pfxc}mnormalize -x   i=./indat/dat1.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out62x.csv
${pfxc}mnormalize -nfn i=./indat/dat1nfn.csv k=0    f=2,1                             c=z o=./outdat/out62nfn.csv

${pfxc}mnormalize      i=./indat/dat1.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out63.csv
${pfxc}mnormalize -x   i=./indat/dat1.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out63x.csv
${pfxc}mnormalize -nfn i=./indat/dat1nfn.csv k=0    f=2,1                             c=Z o=./outdat/out63nfn.csv

${pfxc}mnormalize      i=./indat/dat1.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out64.csv
${pfxc}mnormalize -x   i=./indat/dat1.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out64x.csv
${pfxc}mnormalize -nfn i=./indat/dat1nfn.csv k=0    f=2,1                             c=range o=./outdat/out64nfn.csv

#k=にNULL有
${pfxc}mnormalize      i=./indat/dat2.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out65.csv
${pfxc}mnormalize -x   i=./indat/dat2.csv    k=0    f=2:金額基準値    c=z o=./outdat/out65x.csv
${pfxc}mnormalize -nfn i=./indat/dat2nfn.csv k=0    f=2               c=z o=./outdat/out65nfn.csv

${pfxc}mnormalize      i=./indat/dat2.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out66.csv
${pfxc}mnormalize -x   i=./indat/dat2.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out66x.csv
${pfxc}mnormalize -nfn i=./indat/dat2nfn.csv k=0    f=2               c=Z o=./outdat/out66nfn.csv

${pfxc}mnormalize      i=./indat/dat2.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out67.csv
${pfxc}mnormalize -x   i=./indat/dat2.csv    k=0    f=2:金額基準値    c=range o=./outdat/out67x.csv
${pfxc}mnormalize -nfn i=./indat/dat2nfn.csv k=0    f=2               c=range o=./outdat/out67nfn.csv

${pfxc}mnormalize      i=./indat/dat2.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out68.csv
${pfxc}mnormalize -x   i=./indat/dat2.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out68x.csv
${pfxc}mnormalize -nfn i=./indat/dat2nfn.csv k=0    f=2,1                             c=z o=./outdat/out68nfn.csv

${pfxc}mnormalize      i=./indat/dat2.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out69.csv
${pfxc}mnormalize -x   i=./indat/dat2.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out69x.csv
${pfxc}mnormalize -nfn i=./indat/dat2nfn.csv k=0    f=2,1                             c=Z o=./outdat/out69nfn.csv

${pfxc}mnormalize      i=./indat/dat2.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out70.csv
${pfxc}mnormalize -x   i=./indat/dat2.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out70x.csv
${pfxc}mnormalize -nfn i=./indat/dat2nfn.csv k=0    f=2,1                             c=range o=./outdat/out70nfn.csv

#f=にNULLあり
${pfxc}mnormalize      i=./indat/dat3.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out71.csv
${pfxc}mnormalize -x   i=./indat/dat3.csv    k=0    f=2:金額基準値    c=z o=./outdat/out71x.csv
${pfxc}mnormalize -nfn i=./indat/dat3nfn.csv k=0    f=2               c=z o=./outdat/out71nfn.csv

${pfxc}mnormalize      i=./indat/dat3.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out72.csv
${pfxc}mnormalize -x   i=./indat/dat3.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out72x.csv
${pfxc}mnormalize -nfn i=./indat/dat3nfn.csv k=0    f=2               c=Z o=./outdat/out72nfn.csv

${pfxc}mnormalize      i=./indat/dat3.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out73.csv
${pfxc}mnormalize -x   i=./indat/dat3.csv    k=0    f=2:金額基準値    c=range o=./outdat/out73x.csv
${pfxc}mnormalize -nfn i=./indat/dat3nfn.csv k=0    f=2               c=range o=./outdat/out73nfn.csv

${pfxc}mnormalize      i=./indat/dat3.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out74.csv
${pfxc}mnormalize -x   i=./indat/dat3.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out74x.csv
${pfxc}mnormalize -nfn i=./indat/dat3nfn.csv k=0    f=2,1                             c=z o=./outdat/out74nfn.csv

${pfxc}mnormalize      i=./indat/dat3.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out75.csv
${pfxc}mnormalize -x   i=./indat/dat3.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out75x.csv
${pfxc}mnormalize -nfn i=./indat/dat3nfn.csv k=0    f=2,1                             c=Z o=./outdat/out75nfn.csv

${pfxc}mnormalize      i=./indat/dat3.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out76.csv
${pfxc}mnormalize -x   i=./indat/dat3.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out76x.csv
${pfxc}mnormalize -nfn i=./indat/dat3nfn.csv k=0    f=2,1                             c=range o=./outdat/out76nfn.csv

#k=,f=にNULL有
${pfxc}mnormalize      i=./indat/dat4.csv    k=顧客 f=金額:金額基準値 c=z o=./outdat/out77.csv
${pfxc}mnormalize -x   i=./indat/dat4.csv    k=0    f=2:金額基準値    c=z o=./outdat/out77x.csv
${pfxc}mnormalize -nfn i=./indat/dat4nfn.csv k=0    f=2               c=z o=./outdat/out77nfn.csv

${pfxc}mnormalize      i=./indat/dat4.csv    k=顧客 f=金額:金額基準値 c=Z o=./outdat/out78.csv
${pfxc}mnormalize -x   i=./indat/dat4.csv    k=0    f=2:金額基準値    c=Z o=./outdat/out78x.csv
${pfxc}mnormalize -nfn i=./indat/dat4nfn.csv k=0    f=2               c=Z o=./outdat/out78nfn.csv

${pfxc}mnormalize      i=./indat/dat4.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out79.csv
${pfxc}mnormalize -x   i=./indat/dat4.csv    k=0    f=2:金額基準値    c=range o=./outdat/out79x.csv
${pfxc}mnormalize -nfn i=./indat/dat4nfn.csv k=0    f=2               c=range o=./outdat/out79nfn.csv

${pfxc}mnormalize      i=./indat/dat4.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=z o=./outdat/out80.csv
${pfxc}mnormalize -x   i=./indat/dat4.csv    k=0    f=2:金額基準値,1:数量基準値       c=z o=./outdat/out80x.csv
${pfxc}mnormalize -nfn i=./indat/dat4nfn.csv k=0    f=2,1                             c=z o=./outdat/out80nfn.csv

${pfxc}mnormalize      i=./indat/dat4.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=Z o=./outdat/out81.csv
${pfxc}mnormalize -x   i=./indat/dat4.csv    k=0    f=2:金額基準値,1:数量基準値       c=Z o=./outdat/out81x.csv
${pfxc}mnormalize -nfn i=./indat/dat4nfn.csv k=0    f=2,1                             c=Z o=./outdat/out81nfn.csv

${pfxc}mnormalize      i=./indat/dat4.csv    k=顧客 f=金額:金額基準値,数量:数量基準値 c=range o=./outdat/out82.csv
${pfxc}mnormalize -x   i=./indat/dat4.csv    k=0    f=2:金額基準値,1:数量基準値       c=range o=./outdat/out82x.csv
${pfxc}mnormalize -nfn i=./indat/dat4nfn.csv k=0    f=2,1                             c=range o=./outdat/out82nfn.csv

#f=がNULL
${pfxc}mnormalize      i=./indat/dat6.csv    k=顧客 f=金額:金額基準値 c=range o=./outdat/out86.csv
${pfxc}mnormalize      i=./indat/dat6.csv    k=顧客 f=数量:数量基準値 c=range o=./outdat/out87.csv

