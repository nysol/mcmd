#!/bin/bash

. ../env

#name_kg_mcmd delnull

#null data
${pfxc}mdelnull      f=数量,金額 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mdelnull -x   f=1,2       i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mdelnull -nfn f=1,2       i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mdelnull -nfno f=数量,金額 i=./indat/dat0s.csv   o=./outdat/out0nfno.csv

${pfxc}mdelnull      f=数量,金額 i=./indat/dat0s.csv    o=./outdat/out1.csv    u=./outdat/out2.csv
${pfxc}mdelnull -x   f=1,2       i=./indat/dat0s.csv    o=./outdat/out1x.csv   u=./outdat/out2x.csv
${pfxc}mdelnull -nfn f=1,2       i=./indat/dat0snfn.csv o=./outdat/out1nfn.csv u=./outdat/out2nfn.csv

#f=1つ
${pfxc}mdelnull      f=数量 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mdelnull -x   f=1    i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mdelnull -nfn f=1    i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}mdelnull -nfno f=数量 i=./indat/dat1s.csv   o=./outdat/out3nfno.csv

#f=2つ
${pfxc}mdelnull      f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mdelnull -x   f=1,2       i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mdelnull -nfn f=1,2       i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv

#u=指定あり
${pfxc}mdelnull      f=数量 i=./indat/dat1s.csv    o=./outdat/out5.csv    u=./outdat/out6.csv
${pfxc}mdelnull -x   f=1    i=./indat/dat1s.csv    o=./outdat/out5x.csv   u=./outdat/out6x.csv
${pfxc}mdelnull -nfn f=1    i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv u=./outdat/out6nfn.csv
${pfxc}mdelnull -nfno f=数量 i=./indat/dat1s.csv    o=./outdat/out5nfno.csv    u=./outdat/out6nfno.csv

${pfxc}mdelnull      f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out7.csv    u=./outdat/out8.csv
${pfxc}mdelnull -x   f=1,2       i=./indat/dat1s.csv    o=./outdat/out7x.csv   u=./outdat/out8x.csv
${pfxc}mdelnull -nfn f=1,2       i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv u=./outdat/out8nfn.csv

#-rあり
${pfxc}mdelnull      f=数量 -r i=./indat/dat1s.csv    o=./outdat/out9.csv
${pfxc}mdelnull -x   f=1    -r i=./indat/dat1s.csv    o=./outdat/out9x.csv
${pfxc}mdelnull -nfn f=1    -r i=./indat/dat1snfn.csv o=./outdat/out9nfn.csv
${pfxc}mdelnull -nfno f=数量 -r i=./indat/dat1s.csv    o=./outdat/out9nfno.csv

${pfxc}mdelnull      f=数量,金額 -r i=./indat/dat1s.csv    o=./outdat/out10.csv
${pfxc}mdelnull -x   f=1,2       -r i=./indat/dat1s.csv    o=./outdat/out10x.csv
${pfxc}mdelnull -nfn f=1,2       -r i=./indat/dat1snfn.csv o=./outdat/out10nfn.csv
${pfxc}mdelnull -nfno f=数量,金額 -r i=./indat/dat1s.csv   o=./outdat/out10nfno.csv

#-rあり,u=指定あり
${pfxc}mdelnull      f=数量 -r i=./indat/dat1s.csv    o=./outdat/out11.csv    u=./outdat/out12.csv
${pfxc}mdelnull -x   f=1    -r i=./indat/dat1s.csv    o=./outdat/out11x.csv   u=./outdat/out12x.csv
${pfxc}mdelnull -nfn f=1    -r i=./indat/dat1snfn.csv o=./outdat/out11nfn.csv u=./outdat/out12nfn.csv
${pfxc}mdelnull -nfno f=数量 -r i=./indat/dat1s.csv    o=./outdat/out11nfno.csv    u=./outdat/out12nfno.csv

${pfxc}mdelnull      f=数量,金額 -r i=./indat/dat1s.csv    o=./outdat/out13.csv    u=./outdat/out14.csv
${pfxc}mdelnull -x   f=1,2       -r i=./indat/dat1s.csv    o=./outdat/out13x.csv   u=./outdat/out14x.csv
${pfxc}mdelnull -nfn f=1,2       -r i=./indat/dat1snfn.csv o=./outdat/out13nfn.csv u=./outdat/out14nfn.csv

#-Fあり
${pfxc}mdelnull      f=数量,金額 -F i=./indat/dat2s.csv    o=./outdat/out15.csv  
${pfxc}mdelnull -x   f=1,2       -F i=./indat/dat2s.csv    o=./outdat/out15x.csv  
${pfxc}mdelnull -nfn f=1,2       -F i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv  
${pfxc}mdelnull -nfno f=数量,金額 -F i=./indat/dat2s.csv    o=./outdat/out15nfno.csv  

${pfxc}mdelnull      f=数量,金額 -F i=./indat/dat2s.csv    o=./outdat/out16.csv    u=./outdat/out17.csv
${pfxc}mdelnull -x   f=1,2       -F i=./indat/dat2s.csv    o=./outdat/out16x.csv   u=./outdat/out17x.csv
${pfxc}mdelnull -nfn f=1,2       -F i=./indat/dat2snfn.csv o=./outdat/out16nfn.csv u=./outdat/out17nfn.csv

${pfxc}mdelnull      f=数量,金額 -F -r i=./indat/dat2s.csv    o=./outdat/out18.csv
${pfxc}mdelnull -x   f=1,2       -F -r i=./indat/dat2s.csv    o=./outdat/out18x.csv
${pfxc}mdelnull -nfn f=1,2       -F -r i=./indat/dat2snfn.csv o=./outdat/out18nfn.csv

${pfxc}mdelnull      f=数量,金額 -F -r i=./indat/dat2s.csv    o=./outdat/out19.csv    u=./outdat/out20.csv
${pfxc}mdelnull -x   f=1,2       -F -r i=./indat/dat2s.csv    o=./outdat/out19x.csv   u=./outdat/out20x.csv
${pfxc}mdelnull -nfn f=1,2       -F -r i=./indat/dat2snfn.csv o=./outdat/out19nfn.csv u=./outdat/out20nfn.csv

#k=あり
${pfxc}mdelnull       k=顧客 f=数量 i=./indat/dat1s.csv    o=./outdat/out21.csv
${pfxc}mdelnull -x    k=0    f=1    i=./indat/dat1s.csv    o=./outdat/out21x.csv
${pfxc}mdelnull -nfn  k=0    f=1    i=./indat/dat1snfn.csv o=./outdat/out21nfn.csv
${pfxc}mdelnull -nfno k=顧客 f=数量 i=./indat/dat1s.csv    o=./outdat/out21nfno.csv
${pfxc}mdelnull -q      k=顧客 f=数量 i=./indat/dat1s.csv    o=./outdat/out21q.csv
${pfxc}mdelnull -q -nfn k=0    f=1    i=./indat/dat1snfn.csv o=./outdat/out21qnfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out22.csv
${pfxc}mdelnull -x   k=0    f=1,2       i=./indat/dat1s.csv    o=./outdat/out22x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       i=./indat/dat1snfn.csv o=./outdat/out22nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat1s.csv    o=./outdat/out23.csv    u=./outdat/out24.csv
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat1s.csv    o=./outdat/out23x.csv   u=./outdat/out24x.csv
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat1snfn.csv o=./outdat/out23nfn.csv u=./outdat/out24nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out25.csv    u=./outdat/out26.csv
${pfxc}mdelnull -x   k=0    f=1,2       i=./indat/dat1s.csv    o=./outdat/out25x.csv   u=./outdat/out26x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       i=./indat/dat1snfn.csv o=./outdat/out25nfn.csv u=./outdat/out26nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -r i=./indat/dat1s.csv    o=./outdat/out27.csv
${pfxc}mdelnull -x   k=0    f=1    -r i=./indat/dat1s.csv    o=./outdat/out27x.csv
${pfxc}mdelnull -nfn k=0    f=1    -r i=./indat/dat1snfn.csv o=./outdat/out27nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -r i=./indat/dat1s.csv    o=./outdat/out28.csv
${pfxc}mdelnull -x   k=0    f=1,2       -r i=./indat/dat1s.csv    o=./outdat/out28x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -r i=./indat/dat1snfn.csv o=./outdat/out28nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -r i=./indat/dat1s.csv    o=./outdat/out29.csv    u=./outdat/out30.csv
${pfxc}mdelnull -x   k=0    f=1    -r i=./indat/dat1s.csv    o=./outdat/out29x.csv   u=./outdat/out30x.csv
${pfxc}mdelnull -nfn k=0    f=1    -r i=./indat/dat1snfn.csv o=./outdat/out29nfn.csv u=./outdat/out30nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -r i=./indat/dat1s.csv    o=./outdat/out31.csv    u=./outdat/out32.csv
${pfxc}mdelnull -x   k=0    f=1,2       -r i=./indat/dat1s.csv    o=./outdat/out31x.csv   u=./outdat/out32x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -r i=./indat/dat1snfn.csv o=./outdat/out31nfn.csv u=./outdat/out32nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F i=./indat/dat2s.csv    o=./outdat/out33.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F i=./indat/dat2s.csv    o=./outdat/out33x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F i=./indat/dat2snfn.csv o=./outdat/out33nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F i=./indat/dat2s.csv    o=./outdat/out34.csv    u=./outdat/out35.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F i=./indat/dat2s.csv    o=./outdat/out34x.csv   u=./outdat/out35x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F i=./indat/dat2snfn.csv o=./outdat/out34nfn.csv u=./outdat/out35nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F -r i=./indat/dat2s.csv    o=./outdat/out36.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F -r i=./indat/dat2s.csv    o=./outdat/out36x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F -r i=./indat/dat2snfn.csv o=./outdat/out36nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F -r i=./indat/dat2s.csv    o=./outdat/out37.csv    u=./outdat/out38.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F -r i=./indat/dat2s.csv    o=./outdat/out37x.csv   u=./outdat/out38x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F -r i=./indat/dat2snfn.csv o=./outdat/out37nfn.csv u=./outdat/out38nfn.csv

#-Rあり
${pfxc}mdelnull      k=顧客 f=数量 -R i=./indat/dat3s.csv    o=./outdat/out39.csv
${pfxc}mdelnull -x   k=0    f=1    -R i=./indat/dat3s.csv    o=./outdat/out39x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R i=./indat/dat3snfn.csv o=./outdat/out39nfn.csv
${pfxc}mdelnull -nfno k=顧客 f=数量 -R i=./indat/dat3s.csv    o=./outdat/out39nfno.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R i=./indat/dat3s.csv    o=./outdat/out40.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R i=./indat/dat3s.csv    o=./outdat/out40x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R i=./indat/dat3snfn.csv o=./outdat/out40nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R i=./indat/dat3s.csv    o=./outdat/out41.csv    u=./outdat/out42.csv
${pfxc}mdelnull -x   k=0    f=1    -R i=./indat/dat3s.csv    o=./outdat/out41x.csv   u=./outdat/out42x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R i=./indat/dat3snfn.csv o=./outdat/out41nfn.csv u=./outdat/out42nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R i=./indat/dat3s.csv    o=./outdat/out43.csv    u=./outdat/out44.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R i=./indat/dat3s.csv    o=./outdat/out43x.csv   u=./outdat/out44x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R i=./indat/dat3snfn.csv o=./outdat/out43nfn.csv u=./outdat/out44nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R -r i=./indat/dat3s.csv    o=./outdat/out45.csv
${pfxc}mdelnull -x   k=0    f=1    -R -r i=./indat/dat3s.csv    o=./outdat/out45x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R -r i=./indat/dat3snfn.csv o=./outdat/out45nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -r i=./indat/dat3s.csv o=./outdat/out46.csv
${pfxc}mdelnull -x   k=0    f=1,2  -R -r i=./indat/dat3s.csv    o=./outdat/out46x.csv
${pfxc}mdelnull -nfn k=0    f=1,2  -R -r i=./indat/dat3snfn.csv o=./outdat/out46nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R -r i=./indat/dat3s.csv    o=./outdat/out47.csv    u=./outdat/out48.csv
${pfxc}mdelnull -x   k=0    f=1    -R -r i=./indat/dat3s.csv    o=./outdat/out47x.csv   u=./outdat/out48x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R -r i=./indat/dat3snfn.csv o=./outdat/out47nfn.csv u=./outdat/out48nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -r i=./indat/dat3s.csv    o=./outdat/out49.csv    u=./outdat/out50.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -r i=./indat/dat3s.csv    o=./outdat/out49x.csv   u=./outdat/out50x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -r i=./indat/dat3snfn.csv o=./outdat/out49nfn.csv u=./outdat/out50nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F i=./indat/dat4s.csv    o=./outdat/out51.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F i=./indat/dat4s.csv    o=./outdat/out51x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F i=./indat/dat4snfn.csv o=./outdat/out51nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F i=./indat/dat4s.csv    o=./outdat/out52.csv    u=./outdat/out53.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F i=./indat/dat4s.csv    o=./outdat/out52x.csv   u=./outdat/out53x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F i=./indat/dat4snfn.csv o=./outdat/out52nfn.csv u=./outdat/out53nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F -r i=./indat/dat4s.csv    o=./outdat/out54.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F -r i=./indat/dat4s.csv    o=./outdat/out54x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F -r i=./indat/dat4snfn.csv o=./outdat/out54nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F -r i=./indat/dat4s.csv    o=./outdat/out55.csv    u=./outdat/out56.csv
${pfxc}mdelnull -x   k=0    f=1,2      -R -F -r i=./indat/dat4s.csv    o=./outdat/out55x.csv   u=./outdat/out56x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F -r i=./indat/dat4snfn.csv o=./outdat/out55nfn.csv u=./outdat/out56nfn.csv

#k=にNULL混在
${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat5s.csv    o=./outdat/out57.csv
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat5s.csv    o=./outdat/out57x.csv
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat5snfn.csv o=./outdat/out57nfn.csv
${pfxc}mdelnull -nfno k=顧客 f=数量 i=./indat/dat5s.csv    o=./outdat/out57nfno.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat5s.csv    o=./outdat/out58.csv
${pfxc}mdelnull -x   k=0    f=1,2       i=./indat/dat5s.csv    o=./outdat/out58x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       i=./indat/dat5snfn.csv o=./outdat/out58nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat5s.csv    o=./outdat/out59.csv    u=./outdat/out60.csv
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat5s.csv    o=./outdat/out59x.csv   u=./outdat/out60x.csv
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat5snfn.csv o=./outdat/out59nfn.csv u=./outdat/out60nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat5s.csv    o=./outdat/out61.csv    u=./outdat/out62.csv
${pfxc}mdelnull -x   k=0    f=1,2       i=./indat/dat5s.csv    o=./outdat/out61x.csv   u=./outdat/out62x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       i=./indat/dat5snfn.csv o=./outdat/out61nfn.csv u=./outdat/out62nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -r i=./indat/dat5s.csv    o=./outdat/out63.csv
${pfxc}mdelnull -x   k=0    f=1    -r i=./indat/dat5s.csv    o=./outdat/out63x.csv
${pfxc}mdelnull -nfn k=0    f=1    -r i=./indat/dat5snfn.csv o=./outdat/out63nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -r i=./indat/dat5s.csv    o=./outdat/out64.csv
${pfxc}mdelnull -x   k=0    f=1,2       -r i=./indat/dat5s.csv    o=./outdat/out64x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -r i=./indat/dat5snfn.csv o=./outdat/out64nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -r i=./indat/dat5s.csv    o=./outdat/out65.csv    u=./outdat/out66.csv
${pfxc}mdelnull -x   k=0    f=1    -r i=./indat/dat5s.csv    o=./outdat/out65x.csv   u=./outdat/out66x.csv
${pfxc}mdelnull -nfn k=0    f=1    -r i=./indat/dat5snfn.csv o=./outdat/out65nfn.csv u=./outdat/out66nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -r i=./indat/dat5s.csv    o=./outdat/out67.csv    u=./outdat/out68.csv
${pfxc}mdelnull -x   k=0    f=1,2       -r i=./indat/dat5s.csv    o=./outdat/out67x.csv   u=./outdat/out68x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -r i=./indat/dat5snfn.csv o=./outdat/out67nfn.csv u=./outdat/out68nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F i=./indat/dat6s.csv    o=./outdat/out69.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F i=./indat/dat6s.csv    o=./outdat/out69x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F i=./indat/dat6snfn.csv o=./outdat/out69nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F i=./indat/dat6s.csv    o=./outdat/out70.csv    u=./outdat/out71.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F i=./indat/dat6s.csv    o=./outdat/out70x.csv   u=./outdat/out71x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F i=./indat/dat6snfn.csv o=./outdat/out70nfn.csv u=./outdat/out71nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F -r i=./indat/dat6s.csv    o=./outdat/out72.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F -r i=./indat/dat6s.csv    o=./outdat/out72x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F -r i=./indat/dat6snfn.csv o=./outdat/out72nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F -r i=./indat/dat6s.csv    o=./outdat/out73.csv    u=./outdat/out74.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F -r i=./indat/dat6s.csv    o=./outdat/out73x.csv   u=./outdat/out74x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F -r i=./indat/dat6snfn.csv o=./outdat/out73nfn.csv u=./outdat/out74nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R i=./indat/dat7s.csv    o=./outdat/out75.csv
${pfxc}mdelnull -x   k=0    f=1    -R i=./indat/dat7s.csv    o=./outdat/out75x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R i=./indat/dat7snfn.csv o=./outdat/out75nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R i=./indat/dat7s.csv    o=./outdat/out76.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R i=./indat/dat7s.csv    o=./outdat/out76x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R i=./indat/dat7snfn.csv o=./outdat/out76nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R i=./indat/dat7s.csv    o=./outdat/out77.csv    u=./outdat/out78.csv
${pfxc}mdelnull -x   k=0    f=1    -R i=./indat/dat7s.csv    o=./outdat/out77x.csv   u=./outdat/out78x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R i=./indat/dat7snfn.csv o=./outdat/out77nfn.csv u=./outdat/out78nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R i=./indat/dat7s.csv    o=./outdat/out79.csv    u=./outdat/out80.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R i=./indat/dat7s.csv    o=./outdat/out79x.csv   u=./outdat/out80x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R i=./indat/dat7snfn.csv o=./outdat/out79nfn.csv u=./outdat/out80nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R -r i=./indat/dat7s.csv    o=./outdat/out81.csv
${pfxc}mdelnull -x   k=0    f=1    -R -r i=./indat/dat7s.csv    o=./outdat/out81x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R -r i=./indat/dat7snfn.csv o=./outdat/out81nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -r i=./indat/dat7s.csv    o=./outdat/out82.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -r i=./indat/dat7s.csv    o=./outdat/out82x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -r i=./indat/dat7snfn.csv o=./outdat/out82nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R -r i=./indat/dat7s.csv    o=./outdat/out83.csv    u=./outdat/out84.csv
${pfxc}mdelnull -x   k=0    f=1    -R -r i=./indat/dat7s.csv    o=./outdat/out83x.csv   u=./outdat/out84x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R -r i=./indat/dat7snfn.csv o=./outdat/out83nfn.csv u=./outdat/out84nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -r i=./indat/dat7s.csv    o=./outdat/out85.csv    u=./outdat/out86.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -r i=./indat/dat7s.csv    o=./outdat/out85x.csv   u=./outdat/out86x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -r i=./indat/dat7snfn.csv o=./outdat/out85nfn.csv u=./outdat/out86nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F i=./indat/dat8s.csv    o=./outdat/out87.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F i=./indat/dat8s.csv    o=./outdat/out87x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F i=./indat/dat8snfn.csv o=./outdat/out87nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F i=./indat/dat8s.csv    o=./outdat/out88.csv    u=./outdat/out89.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F i=./indat/dat8s.csv    o=./outdat/out88x.csv   u=./outdat/out89x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F i=./indat/dat8snfn.csv o=./outdat/out88nfn.csv u=./outdat/out89nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F -r i=./indat/dat8s.csv    o=./outdat/out90.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F -r i=./indat/dat8s.csv    o=./outdat/out90x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F -r i=./indat/dat8snfn.csv o=./outdat/out90nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F -r i=./indat/dat8s.csv    o=./outdat/out91.csv    u=./outdat/out92.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F -r i=./indat/dat8s.csv    o=./outdat/out91x.csv   u=./outdat/out92x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F -r i=./indat/dat8snfn.csv o=./outdat/out91nfn.csv u=./outdat/out92nfn.csv

#k=にNULL混在 bufcount=-1
${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat5s.csv    o=./outdat/out93.csv bufcount=-1
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat5s.csv    o=./outdat/out93x.csv bufcount=-1
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat5snfn.csv o=./outdat/out93nfn.csv bufcount=-1
${pfxc}mdelnull -nfno k=顧客 f=数量 i=./indat/dat5s.csv    o=./outdat/out93nfno.csv bufcount=-1


#ランダムデータ
${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat0.csv    o=./outdat/out99.csv
${pfxc}mdelnull -x   k=0   f=1,2       i=./indat/dat0.csv    o=./outdat/out99x.csv
${pfxc}mdelnull -nfn k=0   f=1,2       i=./indat/dat0nfn.csv o=./outdat/out99nfn.csv

#k=あり
${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat1.csv    o=./outdat/out100.csv
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat1.csv    o=./outdat/out100x.csv
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out100nfn.csv
${pfxc}mdelnull -q      k=顧客 f=数量 i=./indat/dat1.csv    o=./outdat/out100q.csv
${pfxc}mdelnull -q -nfn k=0    f=1    i=./indat/dat1nfn.csv o=./outdat/out100qnfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out101.csv    u=./outdat/out102.csv
${pfxc}mdelnull -x   k=0    f=1,2       i=./indat/dat1.csv    o=./outdat/out101x.csv   u=./outdat/out102x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       i=./indat/dat1nfn.csv o=./outdat/out101nfn.csv u=./outdat/out102nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -r i=./indat/dat1.csv    o=./outdat/out103.csv
${pfxc}mdelnull -x   k=0    f=1    -r i=./indat/dat1.csv    o=./outdat/out103x.csv
${pfxc}mdelnull -nfn k=0    f=1    -r i=./indat/dat1nfn.csv o=./outdat/out103nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -r i=./indat/dat1.csv    o=./outdat/out104.csv    u=./outdat/out105.csv
${pfxc}mdelnull -x   k=0    f=1,2       -r i=./indat/dat1.csv    o=./outdat/out104x.csv   u=./outdat/out105x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -r i=./indat/dat1nfn.csv o=./outdat/out104nfn.csv u=./outdat/out105nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F i=./indat/dat2.csv    o=./outdat/out106.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F i=./indat/dat2.csv    o=./outdat/out106x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F i=./indat/dat2nfn.csv o=./outdat/out106nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F -r i=./indat/dat2.csv    o=./outdat/out107.csv    u=./outdat/out108.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F -r i=./indat/dat2.csv    o=./outdat/out107x.csv   u=./outdat/out108x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F -r i=./indat/dat2nfn.csv o=./outdat/out107nfn.csv u=./outdat/out108nfn.csv

#-Rあり
${pfxc}mdelnull      k=顧客 f=数量 -R i=./indat/dat3.csv    o=./outdat/out109.csv
${pfxc}mdelnull -x   k=0    f=1    -R i=./indat/dat3.csv    o=./outdat/out109x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R i=./indat/dat3nfn.csv o=./outdat/out109nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R i=./indat/dat3.csv    o=./outdat/out110.csv    u=./outdat/out111.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R i=./indat/dat3.csv    o=./outdat/out110x.csv   u=./outdat/out111x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R i=./indat/dat3nfn.csv o=./outdat/out110nfn.csv u=./outdat/out111nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R -r i=./indat/dat3.csv    o=./outdat/out112.csv
${pfxc}mdelnull -x   k=0    f=1    -R -r i=./indat/dat3.csv    o=./outdat/out112x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R -r i=./indat/dat3nfn.csv o=./outdat/out112nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -r i=./indat/dat3.csv    o=./outdat/out113.csv    u=./outdat/out114.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -r i=./indat/dat3.csv    o=./outdat/out113x.csv   u=./outdat/out114x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -r i=./indat/dat3nfn.csv o=./outdat/out113nfn.csv u=./outdat/out114nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F i=./indat/dat4.csv    o=./outdat/out115.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F i=./indat/dat4.csv    o=./outdat/out115x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F i=./indat/dat4nfn.csv o=./outdat/out115nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F -r i=./indat/dat4.csv    o=./outdat/out116.csv    u=./outdat/out117.csv
${pfxc}mdelnull -x   k=0    f=1,2      -R -F -r i=./indat/dat4.csv    o=./outdat/out116x.csv   u=./outdat/out117x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F -r i=./indat/dat4nfn.csv o=./outdat/out116nfn.csv u=./outdat/out117nfn.csv

#k=にNULL混在
${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat5.csv    o=./outdat/out118.csv
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat5.csv    o=./outdat/out118x.csv
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat5nfn.csv o=./outdat/out118nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 i=./indat/dat5.csv    o=./outdat/out119.csv    u=./outdat/out120.csv
${pfxc}mdelnull -x   k=0    f=1,2       i=./indat/dat5.csv    o=./outdat/out119x.csv   u=./outdat/out120x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       i=./indat/dat5nfn.csv o=./outdat/out119nfn.csv u=./outdat/out120nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -r i=./indat/dat5.csv    o=./outdat/out121.csv
${pfxc}mdelnull -x   k=0    f=1    -r i=./indat/dat5.csv    o=./outdat/out121x.csv
${pfxc}mdelnull -nfn k=0    f=1    -r i=./indat/dat5nfn.csv o=./outdat/out121nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -r i=./indat/dat5.csv    o=./outdat/out122.csv    u=./outdat/out123.csv
${pfxc}mdelnull -x   k=0    f=1,2       -r i=./indat/dat5.csv    o=./outdat/out122x.csv   u=./outdat/out123x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -r i=./indat/dat5nfn.csv o=./outdat/out122nfn.csv u=./outdat/out123nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F i=./indat/dat6.csv    o=./outdat/out124.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F i=./indat/dat6.csv    o=./outdat/out124x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F i=./indat/dat6nfn.csv o=./outdat/out124nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -F -r i=./indat/dat6.csv    o=./outdat/out125.csv    u=./outdat/out126.csv
${pfxc}mdelnull -x   k=0    f=1,2       -F -r i=./indat/dat6.csv    o=./outdat/out125x.csv   u=./outdat/out126x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -F -r i=./indat/dat6nfn.csv o=./outdat/out125nfn.csv u=./outdat/out126nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R i=./indat/dat7.csv    o=./outdat/out127.csv
${pfxc}mdelnull -x   k=0    f=1    -R i=./indat/dat7.csv    o=./outdat/out127x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R i=./indat/dat7nfn.csv o=./outdat/out127nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R i=./indat/dat7.csv    o=./outdat/out128.csv    u=./outdat/out129.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R i=./indat/dat7.csv    o=./outdat/out128x.csv   u=./outdat/out129x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R i=./indat/dat7nfn.csv o=./outdat/out128nfn.csv u=./outdat/out129nfn.csv

${pfxc}mdelnull      k=顧客 f=数量 -R -r i=./indat/dat7.csv    o=./outdat/out130.csv
${pfxc}mdelnull -x   k=0    f=1    -R -r i=./indat/dat7.csv    o=./outdat/out130x.csv
${pfxc}mdelnull -nfn k=0    f=1    -R -r i=./indat/dat7nfn.csv o=./outdat/out130nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -r i=./indat/dat7.csv    o=./outdat/out131.csv    u=./outdat/out132.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -r i=./indat/dat7.csv    o=./outdat/out131x.csv   u=./outdat/out132x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -r i=./indat/dat7nfn.csv o=./outdat/out131nfn.csv u=./outdat/out132nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F i=./indat/dat8.csv    o=./outdat/out133.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F i=./indat/dat8.csv    o=./outdat/out133x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F i=./indat/dat8nfn.csv o=./outdat/out133nfn.csv

${pfxc}mdelnull      k=顧客 f=数量,金額 -R -F -r i=./indat/dat8.csv    o=./outdat/out134.csv    u=./outdat/out135.csv
${pfxc}mdelnull -x   k=0    f=1,2       -R -F -r i=./indat/dat8.csv    o=./outdat/out134x.csv   u=./outdat/out135x.csv
${pfxc}mdelnull -nfn k=0    f=1,2       -R -F -r i=./indat/dat8nfn.csv o=./outdat/out134nfn.csv u=./outdat/out135nfn.csv

#k=にNULL混在 bufcount=-1
${pfxc}mdelnull      k=顧客 f=数量 i=./indat/dat5.csv    o=./outdat/out136.csv bufcount=-1
${pfxc}mdelnull -x   k=0    f=1    i=./indat/dat5.csv    o=./outdat/out136x.csv bufcount=-1
${pfxc}mdelnull -nfn k=0    f=1    i=./indat/dat5nfn.csv o=./outdat/out136nfn.csv bufcount=-1



