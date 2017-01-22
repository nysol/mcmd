#!/bin/bash

. ../env

#name_kg_mcmd selstr

#NULL data
${pfxc}mselstr      f=商品 v=01,04,05 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mselstr -x   f=0    v=01,04,05 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mselstr -nfn f=0    v=01,04,05 i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mselstr -nfno f=商品 v=01,04,05 i=./indat/dat0.csv    o=./outdat/out0nfno.csv

${pfxc}mselstr      f=商品 v=01,04,05 i=./indat/dat0.csv    o=./outdat/out1.csv    u=./outdat/out2.csv
${pfxc}mselstr -x   f=0    v=01,04,05 i=./indat/dat0.csv    o=./outdat/out1x.csv   u=./outdat/out2x.csv
${pfxc}mselstr -nfn f=0    v=01,04,05 i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv u=./outdat/out2nfn.csv
${pfxc}mselstr -nfno f=商品 v=01,04,05 i=./indat/dat0.csv    o=./outdat/out1nfno.csv    u=./outdat/out2nfno.csv

#f=1つ
${pfxc}mselstr      f=商品 v=01,04,05 i=./indat/dat1.csv    o=./outdat/out3.csv 
${pfxc}mselstr -x   f=0    v=01,04,05 i=./indat/dat1.csv    o=./outdat/out3x.csv 
${pfxc}mselstr -nfn f=0    v=01,04,05 i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv 
${pfxc}mselstr -nfno f=商品 v=01,04,05 i=./indat/dat1.csv    o=./outdat/out3nfno.csv 

#f=2つ
${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 i=./indat/dat2.csv    o=./outdat/out4.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 i=./indat/dat2.csv    o=./outdat/out4x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 i=./indat/dat2.csv    o=./outdat/out4nfno.csv

#u=指定あり
${pfxc}mselstr      f=商品 v=01,04,05 i=./indat/dat1.csv    o=./outdat/out5.csv    u=./outdat/out6.csv 
${pfxc}mselstr -x   f=0    v=01,04,05 i=./indat/dat1.csv    o=./outdat/out5x.csv   u=./outdat/out6x.csv 
${pfxc}mselstr -nfn f=0    v=01,04,05 i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv u=./outdat/out6nfn.csv 
${pfxc}mselstr -nfno f=商品 v=01,04,05 i=./indat/dat1.csv    o=./outdat/out5nfno.csv    u=./outdat/out6nfno.csv 

${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 i=./indat/dat2.csv    o=./outdat/out7.csv    u=./outdat/out8.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 i=./indat/dat2.csv    o=./outdat/out7x.csv   u=./outdat/out8x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv u=./outdat/out8nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 i=./indat/dat2.csv    o=./outdat/out7nfno.csv    u=./outdat/out8nfno.csv

#-rあり
${pfxc}mselstr      f=商品 v=01,04,05 -r i=./indat/dat1.csv    o=./outdat/out9.csv 
${pfxc}mselstr -x   f=0    v=01,04,05 -r i=./indat/dat1.csv    o=./outdat/out9x.csv 
${pfxc}mselstr -nfn f=0    v=01,04,05 -r i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv 
${pfxc}mselstr -nfno f=商品 v=01,04,05 -r i=./indat/dat1.csv    o=./outdat/out9nfno.csv 

${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 -r i=./indat/dat2.csv    o=./outdat/out10.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 -r i=./indat/dat2.csv    o=./outdat/out10x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 -r i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 -r i=./indat/dat2.csv    o=./outdat/out10nfno.csv

#-rあり,u=指定あり
${pfxc}mselstr      f=商品 v=01,04,05 -r i=./indat/dat1.csv    o=./outdat/out11.csv    u=./outdat/out12.csv
${pfxc}mselstr -x   f=0    v=01,04,05 -r i=./indat/dat1.csv    o=./outdat/out11x.csv   u=./outdat/out12x.csv
${pfxc}mselstr -nfn f=0    v=01,04,05 -r i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv u=./outdat/out12nfn.csv
${pfxc}mselstr -nfno f=商品 v=01,04,05 -r i=./indat/dat1.csv    o=./outdat/out11nfno.csv    u=./outdat/out12nfno.csv

${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 -r i=./indat/dat2.csv    o=./outdat/out13.csv    u=./outdat/out14.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 -r i=./indat/dat2.csv    o=./outdat/out13x.csv   u=./outdat/out14x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 -r i=./indat/dat2nfn.csv o=./outdat/out13nfn.csv u=./outdat/out14nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 -r i=./indat/dat2.csv    o=./outdat/out13nfno.csv    u=./outdat/out14nfno.csv

#-Fあり
${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 -F i=./indat/dat2.csv    o=./outdat/out15.csv  
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 -F i=./indat/dat2.csv    o=./outdat/out15x.csv  
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 -F i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv  
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 -F i=./indat/dat2.csv    o=./outdat/out15nfno.csv  

${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 -F i=./indat/dat2.csv    o=./outdat/out16.csv    u=./outdat/out17.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 -F i=./indat/dat2.csv    o=./outdat/out16x.csv   u=./outdat/out17x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 -F i=./indat/dat2nfn.csv o=./outdat/out16nfn.csv u=./outdat/out17nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 -F i=./indat/dat2.csv    o=./outdat/out16nfno.csv    u=./outdat/out17nfno.csv

${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 -F -r i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 -F -r i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 -F -r i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 -F -r i=./indat/dat2.csv    o=./outdat/out18nfno.csv

${pfxc}mselstr      f=受注日,発送日 v=20090103,20090105 -F -r i=./indat/dat2.csv    o=./outdat/out19.csv    u=./outdat/out20.csv
${pfxc}mselstr -x   f=0,1           v=20090103,20090105 -F -r i=./indat/dat2.csv    o=./outdat/out19x.csv   u=./outdat/out20x.csv
${pfxc}mselstr -nfn f=0,1           v=20090103,20090105 -F -r i=./indat/dat2nfn.csv o=./outdat/out19nfn.csv u=./outdat/out20nfn.csv
${pfxc}mselstr -nfno f=受注日,発送日 v=20090103,20090105 -F -r i=./indat/dat2.csv    o=./outdat/out19nfno.csv    u=./outdat/out20nfno.csv

#k=あり
${pfxc}mselstr      k=顧客 f=商品 v=01,03 i=./indat/dat3s.csv    o=./outdat/out21.csv    u=./outdat/out22.csv
${pfxc}mselstr -x   k=0    f=1    v=01,03 i=./indat/dat3s.csv    o=./outdat/out21x.csv   u=./outdat/out22x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,03 i=./indat/dat3snfn.csv o=./outdat/out21nfn.csv u=./outdat/out22nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=01,03 i=./indat/dat3s.csv    o=./outdat/out21nfno.csv    u=./outdat/out22nfno.csv
${pfxc}mselstr -q     k=顧客 f=商品 v=01,03 i=./indat/dat3s.csv    o=./outdat/out21q.csv    u=./outdat/out22q.csv
${pfxc}mselstr -q -x   k=0    f=1    v=01,03 i=./indat/dat3s.csv    o=./outdat/out21qx.csv   u=./outdat/out22qx.csv

${pfxc}mselstr      k=顧客 f=商品 v=01,03 -r i=./indat/dat3s.csv    o=./outdat/out23.csv    u=./outdat/out24.csv
${pfxc}mselstr -x   k=0    f=1    v=01,03 -r i=./indat/dat3s.csv    o=./outdat/out23x.csv   u=./outdat/out24x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,03 -r i=./indat/dat3snfn.csv o=./outdat/out23nfn.csv u=./outdat/out24nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=01,03 -r i=./indat/dat3s.csv    o=./outdat/out23nfno.csv    u=./outdat/out24nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 i=./indat/dat4s.csv    o=./outdat/out25.csv    u=./outdat/out26.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 i=./indat/dat4s.csv    o=./outdat/out25x.csv   u=./outdat/out26x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 i=./indat/dat4snfn.csv o=./outdat/out25nfn.csv u=./outdat/out26nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 i=./indat/dat4s.csv    o=./outdat/out25nfno.csv    u=./outdat/out26nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -r i=./indat/dat4s.csv    o=./outdat/out27.csv    u=./outdat/out28.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat4s.csv    o=./outdat/out27x.csv   u=./outdat/out28x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat4snfn.csv o=./outdat/out27nfn.csv u=./outdat/out28nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 -r i=./indat/dat4s.csv    o=./outdat/out27nfno.csv    u=./outdat/out28nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F i=./indat/dat4s.csv    o=./outdat/out29.csv    u=./outdat/out30.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat4s.csv    o=./outdat/out29x.csv   u=./outdat/out30x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat4snfn.csv o=./outdat/out29nfn.csv u=./outdat/out30nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 -F i=./indat/dat4s.csv    o=./outdat/out29nfno.csv    u=./outdat/out30nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F -r i=./indat/dat4s.csv    o=./outdat/out31.csv    u=./outdat/out32.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat4s.csv    o=./outdat/out31x.csv   u=./outdat/out32x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat4snfn.csv o=./outdat/out31nfn.csv u=./outdat/out32nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 -F -r i=./indat/dat4s.csv    o=./outdat/out31nfno.csv    u=./outdat/out32nfno.csv

#-Rあり
${pfxc}mselstr      k=顧客 f=商品 v=04,05 -R i=./indat/dat3s.csv    o=./outdat/out33.csv    u=./outdat/out34.csv
${pfxc}mselstr -x   k=0    f=1    v=04,05 -R i=./indat/dat3s.csv    o=./outdat/out33x.csv   u=./outdat/out34x.csv
${pfxc}mselstr -nfn k=0    f=1    v=04,05 -R i=./indat/dat3snfn.csv o=./outdat/out33nfn.csv u=./outdat/out34nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=04,05 -R i=./indat/dat3s.csv    o=./outdat/out33nfno.csv    u=./outdat/out34nfno.csv

${pfxc}mselstr      k=顧客 f=商品 v=04,05 -R -r i=./indat/dat3s.csv    o=./outdat/out35.csv    u=./outdat/out36.csv
${pfxc}mselstr -x   k=0    f=1    v=04,05 -R -r i=./indat/dat3s.csv    o=./outdat/out35x.csv   u=./outdat/out36x.csv
${pfxc}mselstr -nfn k=0    f=1    v=04,05 -R -r i=./indat/dat3snfn.csv o=./outdat/out35nfn.csv u=./outdat/out36nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=04,05 -R -r i=./indat/dat3s.csv    o=./outdat/out35nfno.csv    u=./outdat/out36nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R i=./indat/dat4s.csv    o=./outdat/out37.csv    u=./outdat/out38.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat4s.csv    o=./outdat/out37x.csv   u=./outdat/out38x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat4snfn.csv o=./outdat/out37nfn.csv u=./outdat/out38nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R i=./indat/dat4s.csv    o=./outdat/out37nfno.csv    u=./outdat/out38nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4s.csv    o=./outdat/out39.csv    u=./outdat/out40.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4s.csv    o=./outdat/out39x.csv   u=./outdat/out40x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4snfn.csv o=./outdat/out39nfn.csv u=./outdat/out40nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4s.csv    o=./outdat/out39nfno.csv    u=./outdat/out40nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4s.csv    o=./outdat/out41.csv    u=./outdat/out42.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4s.csv    o=./outdat/out41x.csv   u=./outdat/out42x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4snfn.csv o=./outdat/out41nfn.csv u=./outdat/out42nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4s.csv    o=./outdat/out41nfno.csv    u=./outdat/out42nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4s.csv    o=./outdat/out43.csv    u=./outdat/out44.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4s.csv    o=./outdat/out43x.csv   u=./outdat/out44x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4snfn.csv o=./outdat/out43nfn.csv u=./outdat/out44nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4s.csv    o=./outdat/out43nfno.csv    u=./outdat/out44nfno.csv

#bufcount=2指定
${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub bufcount=2 i=./indat/dat3s.csv    o=./outdat/out161.csv    u=./outdat/out162.csv
${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub bufcount=-2 i=./indat/dat3s.csv    o=./outdat/out163.csv    u=./outdat/out164.csv

#ここまでOK

#部分=マッチ
${pfxc}mselstr      f=商品 v=1,4,5 -sub i=./indat/dat1.csv    o=./outdat/out45.csv    u=./outdat/out46.csv
${pfxc}mselstr -x   f=0    v=1,4,5 -sub i=./indat/dat1.csv    o=./outdat/out45x.csv   u=./outdat/out46x.csv
${pfxc}mselstr -nfn f=0    v=1,4,5 -sub i=./indat/dat1nfn.csv o=./outdat/out45nfn.csv u=./outdat/out46nfn.csv
${pfxc}mselstr -nfno f=商品 v=1,4,5 -sub i=./indat/dat1.csv    o=./outdat/out45nfno.csv    u=./outdat/out46nfno.csv

${pfxc}mselstr      f=商品 v=1,4,5 -sub -r i=./indat/dat1.csv    o=./outdat/out47.csv    u=./outdat/out48.csv
${pfxc}mselstr -x   f=0    v=1,4,5 -sub -r i=./indat/dat1.csv    o=./outdat/out47x.csv   u=./outdat/out48x.csv
${pfxc}mselstr -nfn f=0    v=1,4,5 -sub -r i=./indat/dat1nfn.csv o=./outdat/out47nfn.csv u=./outdat/out48nfn.csv

${pfxc}mselstr      f=受注日,発送日 v=03,05 -sub  i=./indat/dat2.csv    o=./outdat/out49.csv    u=./outdat/out50.csv
${pfxc}mselstr -x   f=1,2           v=03,05 -sub  i=./indat/dat2.csv    o=./outdat/out49x.csv   u=./outdat/out50x.csv
${pfxc}mselstr -nfn f=1,2           v=03,05 -sub  i=./indat/dat2nfn.csv o=./outdat/out49nfn.csv u=./outdat/out50nfn.csv

${pfxc}mselstr      f=受注日,発送日 v=03,05 -sub -r i=./indat/dat2.csv    o=./outdat/out51.csv    u=./outdat/out52.csv
${pfxc}mselstr -x   f=1,2           v=03,05 -sub -r i=./indat/dat2.csv    o=./outdat/out51x.csv   u=./outdat/out52x.csv
${pfxc}mselstr -nfn f=1,2           v=03,05 -sub -r i=./indat/dat2nfn.csv o=./outdat/out51nfn.csv u=./outdat/out52nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub i=./indat/dat3s.csv    o=./outdat/out53.csv    u=./outdat/out54.csv
${pfxc}mselstr -x   k=0    f=1    v=1,3 -sub i=./indat/dat3s.csv    o=./outdat/out53x.csv   u=./outdat/out54x.csv
${pfxc}mselstr -nfn k=0    f=1    v=1,3 -sub i=./indat/dat3snfn.csv o=./outdat/out53nfn.csv u=./outdat/out54nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub -r i=./indat/dat3s.csv    o=./outdat/out55.csv    u=./outdat/out56.csv
${pfxc}mselstr -x   k=0    f=1    v=1,3 -sub -r i=./indat/dat3s.csv    o=./outdat/out55x.csv   u=./outdat/out56x.csv
${pfxc}mselstr -nfn k=0    f=1    v=1,3 -sub -r i=./indat/dat3snfn.csv o=./outdat/out55nfn.csv u=./outdat/out56nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=4,5 -sub -R i=./indat/dat3s.csv    o=./outdat/out57.csv    u=./outdat/out58.csv
${pfxc}mselstr -x   k=0    f=1    v=4,5 -sub -R i=./indat/dat3s.csv    o=./outdat/out57x.csv   u=./outdat/out58x.csv
${pfxc}mselstr -nfn k=0    f=1    v=4,5 -sub -R i=./indat/dat3snfn.csv o=./outdat/out57nfn.csv u=./outdat/out58nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=4,5 -sub -R -r i=./indat/dat3s.csv    o=./outdat/out59.csv    u=./outdat/out60.csv
${pfxc}mselstr -x   k=0    f=1    v=4,5 -sub -R -r i=./indat/dat3s.csv    o=./outdat/out59x.csv   u=./outdat/out60x.csv
${pfxc}mselstr -nfn k=0    f=1    v=4,5 -sub -R -r i=./indat/dat3snfn.csv o=./outdat/out59nfn.csv u=./outdat/out60nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=06 -sub i=./indat/dat4s.csv    o=./outdat/out61.csv    u=./outdat/out62.csv
${pfxc}mselstr -x   k=0    f=1,2           v=06 -sub i=./indat/dat4s.csv    o=./outdat/out61x.csv   u=./outdat/out62x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=06 -sub i=./indat/dat4snfn.csv o=./outdat/out61nfn.csv u=./outdat/out62nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=06 -sub -r i=./indat/dat4s.csv    o=./outdat/out63.csv    u=./outdat/out64.csv
${pfxc}mselstr -x   k=0    f=1,2           v=06 -sub -r i=./indat/dat4s.csv    o=./outdat/out63x.csv   u=./outdat/out64x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=06 -sub -r i=./indat/dat4snfn.csv o=./outdat/out63nfn.csv u=./outdat/out64nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=0101,0102 -sub -F i=./indat/dat4s.csv    o=./outdat/out65.csv    u=./outdat/out66.csv
${pfxc}mselstr -x   k=0    f=1,2           v=0101,0102 -sub -F i=./indat/dat4s.csv    o=./outdat/out65x.csv   u=./outdat/out66x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=0101,0102 -sub -F i=./indat/dat4snfn.csv o=./outdat/out65nfn.csv u=./outdat/out66nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=0101,0102 -sub -F -r i=./indat/dat4s.csv    o=./outdat/out67.csv    u=./outdat/out68.csv
${pfxc}mselstr -x   k=0    f=1,2           v=0101,0102 -sub -F -r i=./indat/dat4s.csv    o=./outdat/out67x.csv   u=./outdat/out68x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=0101,0102 -sub -F -r i=./indat/dat4snfn.csv o=./outdat/out67nfn.csv u=./outdat/out68nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R i=./indat/dat4s.csv    o=./outdat/out69.csv    u=./outdat/out70.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R i=./indat/dat4s.csv    o=./outdat/out69x.csv   u=./outdat/out70x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R i=./indat/dat4snfn.csv o=./outdat/out69nfn.csv u=./outdat/out70nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R -r i=./indat/dat4s.csv    o=./outdat/out71.csv    u=./outdat/out72.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R -r i=./indat/dat4s.csv    o=./outdat/out71x.csv   u=./outdat/out72x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R -r i=./indat/dat4snfn.csv o=./outdat/out71nfn.csv u=./outdat/out72nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R -F i=./indat/dat4s.csv    o=./outdat/out73.csv    u=./outdat/out74.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R -F i=./indat/dat4s.csv    o=./outdat/out73x.csv   u=./outdat/out74x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R -F i=./indat/dat4snfn.csv o=./outdat/out73nfn.csv u=./outdat/out74nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R -F -r i=./indat/dat4s.csv    o=./outdat/out75.csv    u=./outdat/out76.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R -F -r i=./indat/dat4s.csv    o=./outdat/out75x.csv   u=./outdat/out76x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R -F -r i=./indat/dat4snfn.csv o=./outdat/out75nfn.csv u=./outdat/out76nfn.csv

#部分=マッチ:ワイド文字
${pfxc}mselstr      f=商品 v='柿,桃,葡萄' -sub i=./indat/dat5.csv    o=./outdat/out77.csv    u=./outdat/out78.csv
${pfxc}mselstr -x   f=0    v='柿,桃,葡萄' -sub i=./indat/dat5.csv    o=./outdat/out77x.csv   u=./outdat/out78x.csv
${pfxc}mselstr -nfn f=0    v='柿,桃,葡萄' -sub i=./indat/dat5nfn.csv o=./outdat/out77nfn.csv u=./outdat/out78nfn.csv
${pfxc}mselstr -nfno f=商品 v='柿,桃,葡萄' -sub i=./indat/dat5.csv    o=./outdat/out77nfno.csv    u=./outdat/out78nfno.csv

${pfxc}mselstr      f=商品 v='柿,桃,葡萄' -sub -r i=./indat/dat5.csv    o=./outdat/out79.csv    u=./outdat/out80.csv
${pfxc}mselstr -x   f=0    v='柿,桃,葡萄' -sub -r i=./indat/dat5.csv    o=./outdat/out79x.csv   u=./outdat/out80x.csv
${pfxc}mselstr -nfn f=0    v='柿,桃,葡萄' -sub -r i=./indat/dat5nfn.csv o=./outdat/out79nfn.csv u=./outdat/out80nfn.csv

${pfxc}mselstr      f=受注日,発送日 v=０３,０５ -sub  i=./indat/dat6.csv    o=./outdat/out81.csv    u=./outdat/out82.csv
${pfxc}mselstr -x   f=1,2           v=０３,０５ -sub  i=./indat/dat6.csv    o=./outdat/out81x.csv   u=./outdat/out82x.csv
${pfxc}mselstr -nfn f=1,2           v=０３,０５ -sub  i=./indat/dat6nfn.csv o=./outdat/out81nfn.csv u=./outdat/out82nfn.csv

${pfxc}mselstr      f=受注日,発送日 v=０３,０５ -sub -r i=./indat/dat6.csv    o=./outdat/out83.csv    u=./outdat/out84.csv
${pfxc}mselstr -x   f=1,2           v=０３,０５ -sub -r i=./indat/dat6.csv    o=./outdat/out83x.csv   u=./outdat/out84x.csv
${pfxc}mselstr -nfn f=1,2           v=０３,０５ -sub -r i=./indat/dat6nfn.csv o=./outdat/out83nfn.csv u=./outdat/out84nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='柿,葡萄' -sub -W i=./indat/dat7s.csv    o=./outdat/out85.csv    u=./outdat/out86.csv
${pfxc}mselstr -x   k=0    f=1    v='柿,葡萄' -sub -W i=./indat/dat7s.csv    o=./outdat/out85x.csv   u=./outdat/out86x.csv
${pfxc}mselstr -nfn k=0    f=1    v='柿,葡萄' -sub -W i=./indat/dat7snfn.csv o=./outdat/out85nfn.csv u=./outdat/out86nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='柿,葡萄' -sub -W -r i=./indat/dat7s.csv    o=./outdat/out87.csv    u=./outdat/out88.csv
${pfxc}mselstr -x   k=0    f=1    v='柿,葡萄' -sub -W -r i=./indat/dat7s.csv    o=./outdat/out87x.csv   u=./outdat/out88x.csv
${pfxc}mselstr -nfn k=0    f=1    v='柿,葡萄' -sub -W -r i=./indat/dat7snfn.csv o=./outdat/out87nfn.csv u=./outdat/out88nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='梨,苺' -sub -W -R i=./indat/dat7s.csv    o=./outdat/out89.csv    u=./outdat/out90.csv
${pfxc}mselstr -x   k=0    f=1    v='梨,苺' -sub -W -R i=./indat/dat7s.csv    o=./outdat/out89x.csv   u=./outdat/out90x.csv
${pfxc}mselstr -nfn k=0    f=1    v='梨,苺' -sub -W -R i=./indat/dat7snfn.csv o=./outdat/out89nfn.csv u=./outdat/out90nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='梨,苺' -sub -W -R -r i=./indat/dat7s.csv    o=./outdat/out91.csv    u=./outdat/out92.csv
${pfxc}mselstr -x   k=0    f=1    v='梨,苺' -sub -W -R -r i=./indat/dat7s.csv    o=./outdat/out91x.csv   u=./outdat/out92x.csv
${pfxc}mselstr -nfn k=0    f=1    v='梨,苺' -sub -W -R -r i=./indat/dat7snfn.csv o=./outdat/out91nfn.csv u=./outdat/out92nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０６ -sub -W i=./indat/dat8s.csv    o=./outdat/out93.csv    u=./outdat/out94.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０６ -sub -W i=./indat/dat8s.csv    o=./outdat/out93x.csv   u=./outdat/out94x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０６ -sub -W i=./indat/dat8snfn.csv o=./outdat/out93nfn.csv u=./outdat/out94nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０６ -sub -W -r i=./indat/dat8s.csv    o=./outdat/out95.csv    u=./outdat/out96.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０６ -sub -W -r i=./indat/dat8s.csv    o=./outdat/out95x.csv   u=./outdat/out96x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０６ -sub -W -r i=./indat/dat8snfn.csv o=./outdat/out95nfn.csv u=./outdat/out96nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=１０１,１０２ -sub -W -F i=./indat/dat8s.csv    o=./outdat/out97.csv    u=./outdat/out98.csv
${pfxc}mselstr -x   k=0    f=1,2           v=１０１,１０２ -sub -W -F i=./indat/dat8s.csv    o=./outdat/out97x.csv   u=./outdat/out98x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=１０１,１０２ -sub -W -F i=./indat/dat8snfn.csv o=./outdat/out97nfn.csv u=./outdat/out98nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=１０１,１０２ -sub -W -F -r i=./indat/dat8s.csv    o=./outdat/out99.csv    u=./outdat/out100.csv
${pfxc}mselstr -x   k=0    f=1,2           v=１０１,１０２ -sub -W -F -r i=./indat/dat8s.csv    o=./outdat/out99x.csv   u=./outdat/out100x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=１０１,１０２ -sub -W -F -r i=./indat/dat8snfn.csv o=./outdat/out99nfn.csv u=./outdat/out100nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R i=./indat/dat8s.csv    o=./outdat/out101.csv    u=./outdat/out102.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R i=./indat/dat8s.csv    o=./outdat/out101x.csv   u=./outdat/out102x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R i=./indat/dat8snfn.csv o=./outdat/out101nfn.csv u=./outdat/out102nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R -r i=./indat/dat8s.csv    o=./outdat/out103.csv    u=./outdat/out104.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -r i=./indat/dat8s.csv    o=./outdat/out103x.csv   u=./outdat/out104x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -r i=./indat/dat8snfn.csv o=./outdat/out103nfn.csv u=./outdat/out104nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R -F i=./indat/dat8s.csv    o=./outdat/out105.csv    u=./outdat/out106.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F i=./indat/dat8s.csv    o=./outdat/out105x.csv   u=./outdat/out106x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F i=./indat/dat8snfn.csv o=./outdat/out105nfn.csv u=./outdat/out106nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R -F -r i=./indat/dat8s.csv    o=./outdat/out107.csv    u=./outdat/out108.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F -r i=./indat/dat8s.csv    o=./outdat/out107x.csv   u=./outdat/out108x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F -r i=./indat/dat8snfn.csv o=./outdat/out107nfn.csv u=./outdat/out108nfn.csv

#前方=マッチ:ワイド文字
${pfxc}mselstr      f=商品 v='果物' -head -W i=./indat/dat5.csv    o=./outdat/out133.csv    u=./outdat/out134.csv
${pfxc}mselstr -x   f=0    v='果物' -head -W i=./indat/dat5.csv    o=./outdat/out133x.csv   u=./outdat/out134x.csv
${pfxc}mselstr -nfn f=0    v='果物' -head -W i=./indat/dat5nfn.csv o=./outdat/out133nfn.csv u=./outdat/out134nfn.csv
${pfxc}mselstr -nfno f=商品    v='果物' -head  -W i=./indat/dat5.csv o=./outdat/out133nfno.csv u=./outdat/out134nfno.csv

${pfxc}mselstr      f=商品 v='果物' -head -W -r i=./indat/dat5.csv    o=./outdat/out135.csv    u=./outdat/out136.csv
${pfxc}mselstr -x   f=0    v='果物' -head -W -r i=./indat/dat5.csv    o=./outdat/out135x.csv   u=./outdat/out136x.csv
${pfxc}mselstr -nfn f=0    v='果物' -head -W -r i=./indat/dat5nfn.csv o=./outdat/out135nfn.csv u=./outdat/out136nfn.csv
${pfxc}mselstr -nfno f=商品    v='果物' -head  -W -r i=./indat/dat5.csv o=./outdat/out135nfno.csv u=./outdat/out136nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１０１,０１０２ -head -W -F i=./indat/dat8s.csv    o=./outdat/out137.csv    u=./outdat/out138.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０１０１,０１０２ -head -W -F i=./indat/dat8s.csv    o=./outdat/out137x.csv   u=./outdat/out138x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０１０１,０１０２ -head -W -F i=./indat/dat8snfn.csv o=./outdat/out137nfn.csv u=./outdat/out138nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=０１０１,０１０２ -head -W -F i=./indat/dat8s.csv    o=./outdat/out137nfno.csv    u=./outdat/out138nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -head -W -R i=./indat/dat11s.csv    o=./outdat/out139.csv    u=./outdat/out140.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -head -W -R -r i=./indat/dat11s.csv    o=./outdat/out141.csv    u=./outdat/out142.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０９,０１ -head -W -R -F i=./indat/dat11s.csv    o=./outdat/out143.csv    u=./outdat/out144.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０９,０１ -head -W -R -F -r i=./indat/dat11s.csv    o=./outdat/out145.csv    u=./outdat/out146.csv

#前方マッチ
${pfxc}mselstr      f=商品 v='果物' -head i=./indat/dat5.csv    o=./outdat/out165.csv    u=./outdat/out166.csv

#後方=マッチ:ワイド文字
${pfxc}mselstr      f=商品 v='梨,苺' -tail -W i=./indat/dat5.csv    o=./outdat/out147.csv    u=./outdat/out148.csv
${pfxc}mselstr -x   f=0    v='梨,苺' -tail -W i=./indat/dat5.csv    o=./outdat/out147x.csv   u=./outdat/out148x.csv
${pfxc}mselstr -nfn f=0    v='梨,苺' -tail -W i=./indat/dat5nfn.csv o=./outdat/out147nfn.csv u=./outdat/out148nfn.csv
${pfxc}mselstr -nfno f=商品    v='梨,苺' -tail  -W i=./indat/dat5.csv o=./outdat/out147nfno.csv u=./outdat/out148nfno.csv

${pfxc}mselstr      f=商品 v='梨,苺' -tail -W -r i=./indat/dat5.csv    o=./outdat/out149.csv    u=./outdat/out150.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１０１,０１０２ -tail -W -F i=./indat/dat8s.csv    o=./outdat/out151.csv    u=./outdat/out152.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -tail -W -R i=./indat/dat11s.csv    o=./outdat/out153.csv    u=./outdat/out154.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -tail -W -R -r i=./indat/dat11s.csv    o=./outdat/out155.csv    u=./outdat/out156.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１,０３,０４,０５ -tail -W -R -F i=./indat/dat11s.csv    o=./outdat/out157.csv    u=./outdat/out158.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１,０３,０４,０５ -tail -W -R -F -r i=./indat/dat11s.csv  o=./outdat/out159.csv    u=./outdat/out160.csv

#後方マッチ
${pfxc}mselstr      f=商品 v='梨,苺' -tail  i=./indat/dat5.csv    o=./outdat/out167.csv    u=./outdat/out168.csv


#ここまでOK
#k=にNULL
${pfxc}mselstr      k=顧客 f=商品 v=01 i=./indat/dat9s.csv    o=./outdat/out109.csv    u=./outdat/out110.csv
${pfxc}mselstr -x   k=0    f=1    v=01 i=./indat/dat9s.csv    o=./outdat/out109x.csv   u=./outdat/out110x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01 i=./indat/dat9snfn.csv o=./outdat/out109nfn.csv u=./outdat/out110nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=01 -r i=./indat/dat9s.csv    o=./outdat/out111.csv    u=./outdat/out112.csv
${pfxc}mselstr -x   k=0    f=1    v=01 -r i=./indat/dat9s.csv    o=./outdat/out111x.csv   u=./outdat/out112x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01 -r i=./indat/dat9snfn.csv o=./outdat/out111nfn.csv u=./outdat/out112nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=01,04,05 -R i=./indat/dat9s.csv    o=./outdat/out113.csv    u=./outdat/out114.csv
${pfxc}mselstr -x   k=0    f=1    v=01,04,05 -R i=./indat/dat9s.csv    o=./outdat/out113x.csv   u=./outdat/out114x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,04,05 -R i=./indat/dat9snfn.csv o=./outdat/out113nfn.csv u=./outdat/out114nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=01,04,05 -R -r i=./indat/dat9s.csv    o=./outdat/out115.csv    u=./outdat/out116.csv
${pfxc}mselstr -x   k=0    f=1    v=01,04,05 -R -r i=./indat/dat9s.csv    o=./outdat/out115x.csv   u=./outdat/out116x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,04,05 -R -r i=./indat/dat9snfn.csv o=./outdat/out115nfn.csv u=./outdat/out116nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 i=./indat/dat10s.csv    o=./outdat/out117.csv    u=./outdat/out118.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 i=./indat/dat10s.csv    o=./outdat/out117x.csv   u=./outdat/out118x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 i=./indat/dat10snfn.csv o=./outdat/out117nfn.csv u=./outdat/out118nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -r i=./indat/dat10s.csv    o=./outdat/out119.csv    u=./outdat/out120.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat10s.csv    o=./outdat/out119x.csv   u=./outdat/out120x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat10snfn.csv o=./outdat/out119nfn.csv u=./outdat/out120nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F i=./indat/dat10s.csv    o=./outdat/out121.csv    u=./outdat/out122.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat10s.csv    o=./outdat/out121x.csv   u=./outdat/out122x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat10snfn.csv o=./outdat/out121nfn.csv u=./outdat/out122nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F -r i=./indat/dat10s.csv    o=./outdat/out123.csv    u=./outdat/out124.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat10s.csv    o=./outdat/out123x.csv   u=./outdat/out124x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat10snfn.csv o=./outdat/out123nfn.csv u=./outdat/out124nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R i=./indat/dat10s.csv    o=./outdat/out125.csv    u=./outdat/out126.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat10s.csv    o=./outdat/out125x.csv   u=./outdat/out126x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat10snfn.csv o=./outdat/out125nfn.csv u=./outdat/out126nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat10s.csv    o=./outdat/out127.csv    u=./outdat/out128.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat10s.csv    o=./outdat/out127x.csv   u=./outdat/out128x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat10snfn.csv o=./outdat/out127nfn.csv u=./outdat/out128nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat10s.csv    o=./outdat/out129.csv    u=./outdat/out130.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat10s.csv    o=./outdat/out129x.csv   u=./outdat/out130x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat10snfn.csv o=./outdat/out129nfn.csv u=./outdat/out130nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat10s.csv    o=./outdat/out131.csv    u=./outdat/out132.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat10s.csv    o=./outdat/out131x.csv   u=./outdat/out132x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat10snfn.csv o=./outdat/out131nfn.csv u=./outdat/out132nfn.csv

#----------------------
# k=のランダムデータ
#----------------------
#k=あり
${pfxc}mselstr      k=顧客 f=商品 v=01,03 i=./indat/dat3.csv    o=./outdat/out221.csv    u=./outdat/out222.csv
${pfxc}mselstr -x   k=0    f=1    v=01,03 i=./indat/dat3.csv    o=./outdat/out221x.csv   u=./outdat/out222x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,03 i=./indat/dat3nfn.csv o=./outdat/out221nfn.csv u=./outdat/out222nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=01,03 i=./indat/dat3.csv    o=./outdat/out221nfno.csv    u=./outdat/out222nfno.csv
${pfxc}mselstr -q     k=顧客 f=商品 v=01,03 i=./indat/dat3.csv    o=./outdat/out221q.csv    u=./outdat/out222q.csv
${pfxc}mselstr -q -x   k=0    f=1    v=01,03 i=./indat/dat3.csv    o=./outdat/out221qx.csv   u=./outdat/out222qx.csv

${pfxc}mselstr      k=顧客 f=商品 v=01,03 -r i=./indat/dat3.csv    o=./outdat/out223.csv    u=./outdat/out224.csv
${pfxc}mselstr -x   k=0    f=1    v=01,03 -r i=./indat/dat3.csv    o=./outdat/out223x.csv   u=./outdat/out224x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,03 -r i=./indat/dat3nfn.csv o=./outdat/out223nfn.csv u=./outdat/out224nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=01,03 -r i=./indat/dat3.csv    o=./outdat/out223nfno.csv    u=./outdat/out224nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 i=./indat/dat4.csv    o=./outdat/out225.csv    u=./outdat/out226.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 i=./indat/dat4.csv    o=./outdat/out225x.csv   u=./outdat/out226x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 i=./indat/dat4nfn.csv o=./outdat/out225nfn.csv u=./outdat/out226nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 i=./indat/dat4.csv    o=./outdat/out225nfno.csv    u=./outdat/out226nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -r i=./indat/dat4.csv    o=./outdat/out227.csv    u=./outdat/out228.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat4.csv    o=./outdat/out227x.csv   u=./outdat/out228x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat4nfn.csv o=./outdat/out227nfn.csv u=./outdat/out228nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 -r i=./indat/dat4.csv    o=./outdat/out227nfno.csv    u=./outdat/out228nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F i=./indat/dat4.csv    o=./outdat/out229.csv    u=./outdat/out230.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat4.csv    o=./outdat/out229x.csv   u=./outdat/out230x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat4nfn.csv o=./outdat/out229nfn.csv u=./outdat/out230nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 -F i=./indat/dat4.csv    o=./outdat/out229nfno.csv    u=./outdat/out230nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F -r i=./indat/dat4.csv    o=./outdat/out231.csv    u=./outdat/out232.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat4.csv    o=./outdat/out231x.csv   u=./outdat/out232x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat4nfn.csv o=./outdat/out231nfn.csv u=./outdat/out232nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090101,20090102 -F -r i=./indat/dat4.csv    o=./outdat/out231nfno.csv    u=./outdat/out232nfno.csv

#-Rあり
${pfxc}mselstr      k=顧客 f=商品 v=04,05 -R i=./indat/dat3.csv    o=./outdat/out233.csv    u=./outdat/out234.csv
${pfxc}mselstr -x   k=0    f=1    v=04,05 -R i=./indat/dat3.csv    o=./outdat/out233x.csv   u=./outdat/out234x.csv
${pfxc}mselstr -nfn k=0    f=1    v=04,05 -R i=./indat/dat3nfn.csv o=./outdat/out233nfn.csv u=./outdat/out234nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=04,05 -R i=./indat/dat3.csv    o=./outdat/out233nfno.csv    u=./outdat/out234nfno.csv

${pfxc}mselstr      k=顧客 f=商品 v=04,05 -R -r i=./indat/dat3.csv    o=./outdat/out235.csv    u=./outdat/out236.csv
${pfxc}mselstr -x   k=0    f=1    v=04,05 -R -r i=./indat/dat3.csv    o=./outdat/out235x.csv   u=./outdat/out236x.csv
${pfxc}mselstr -nfn k=0    f=1    v=04,05 -R -r i=./indat/dat3nfn.csv o=./outdat/out235nfn.csv u=./outdat/out236nfn.csv
${pfxc}mselstr -nfno k=顧客 f=商品 v=04,05 -R -r i=./indat/dat3.csv    o=./outdat/out235nfno.csv    u=./outdat/out236nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R i=./indat/dat4.csv    o=./outdat/out237.csv    u=./outdat/out238.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat4.csv    o=./outdat/out237x.csv   u=./outdat/out238x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat4nfn.csv o=./outdat/out237nfn.csv u=./outdat/out238nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R i=./indat/dat4.csv    o=./outdat/out37nfno.csv    u=./outdat/out38nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4.csv    o=./outdat/out239.csv    u=./outdat/out240.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4.csv    o=./outdat/out239x.csv   u=./outdat/out240x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4nfn.csv o=./outdat/out239nfn.csv u=./outdat/out240nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat4.csv    o=./outdat/out239nfno.csv    u=./outdat/out240nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4.csv    o=./outdat/out241.csv    u=./outdat/out242.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4.csv    o=./outdat/out241x.csv   u=./outdat/out242x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4nfn.csv o=./outdat/out241nfn.csv u=./outdat/out242nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat4.csv    o=./outdat/out241nfno.csv    u=./outdat/out242nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4.csv    o=./outdat/out243.csv    u=./outdat/out244.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4.csv    o=./outdat/out243x.csv   u=./outdat/out244x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4nfn.csv o=./outdat/out243nfn.csv u=./outdat/out244nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat4.csv    o=./outdat/out243nfno.csv    u=./outdat/out244nfno.csv

#bufcount=2指定
${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub bufcount=2 i=./indat/dat3.csv    o=./outdat/out361.csv    u=./outdat/out362.csv
${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub bufcount=-2 i=./indat/dat3.csv    o=./outdat/out363.csv    u=./outdat/out364.csv


${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub i=./indat/dat3.csv    o=./outdat/out253.csv    u=./outdat/out254.csv
${pfxc}mselstr -x   k=0    f=1    v=1,3 -sub i=./indat/dat3.csv    o=./outdat/out253x.csv   u=./outdat/out254x.csv
${pfxc}mselstr -nfn k=0    f=1    v=1,3 -sub i=./indat/dat3nfn.csv o=./outdat/out253nfn.csv u=./outdat/out254nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=1,3 -sub -r i=./indat/dat3.csv    o=./outdat/out255.csv    u=./outdat/out256.csv
${pfxc}mselstr -x   k=0    f=1    v=1,3 -sub -r i=./indat/dat3.csv    o=./outdat/out255x.csv   u=./outdat/out256x.csv
${pfxc}mselstr -nfn k=0    f=1    v=1,3 -sub -r i=./indat/dat3nfn.csv o=./outdat/out255nfn.csv u=./outdat/out256nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=4,5 -sub -R i=./indat/dat3.csv    o=./outdat/out257.csv    u=./outdat/out258.csv
${pfxc}mselstr -x   k=0    f=1    v=4,5 -sub -R i=./indat/dat3.csv    o=./outdat/out257x.csv   u=./outdat/out258x.csv
${pfxc}mselstr -nfn k=0    f=1    v=4,5 -sub -R i=./indat/dat3nfn.csv o=./outdat/out257nfn.csv u=./outdat/out258nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=4,5 -sub -R -r i=./indat/dat3.csv    o=./outdat/out259.csv    u=./outdat/out260.csv
${pfxc}mselstr -x   k=0    f=1    v=4,5 -sub -R -r i=./indat/dat3.csv    o=./outdat/out259x.csv   u=./outdat/out260x.csv
${pfxc}mselstr -nfn k=0    f=1    v=4,5 -sub -R -r i=./indat/dat3nfn.csv o=./outdat/out259nfn.csv u=./outdat/out260nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=06 -sub i=./indat/dat4.csv    o=./outdat/out261.csv    u=./outdat/out262.csv
${pfxc}mselstr -x   k=0    f=1,2           v=06 -sub i=./indat/dat4.csv    o=./outdat/out261x.csv   u=./outdat/out262x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=06 -sub i=./indat/dat4nfn.csv o=./outdat/out261nfn.csv u=./outdat/out262nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=06 -sub -r i=./indat/dat4.csv    o=./outdat/out263.csv    u=./outdat/out264.csv
${pfxc}mselstr -x   k=0    f=1,2           v=06 -sub -r i=./indat/dat4.csv    o=./outdat/out263x.csv   u=./outdat/out264x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=06 -sub -r i=./indat/dat4nfn.csv o=./outdat/out263nfn.csv u=./outdat/out264nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=0101,0102 -sub -F i=./indat/dat4.csv    o=./outdat/out265.csv    u=./outdat/out266.csv
${pfxc}mselstr -x   k=0    f=1,2           v=0101,0102 -sub -F i=./indat/dat4.csv    o=./outdat/out265x.csv   u=./outdat/out266x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=0101,0102 -sub -F i=./indat/dat4nfn.csv o=./outdat/out265nfn.csv u=./outdat/out266nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=0101,0102 -sub -F -r i=./indat/dat4.csv    o=./outdat/out267.csv    u=./outdat/out268.csv
${pfxc}mselstr -x   k=0    f=1,2           v=0101,0102 -sub -F -r i=./indat/dat4.csv    o=./outdat/out267x.csv   u=./outdat/out268x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=0101,0102 -sub -F -r i=./indat/dat4nfn.csv o=./outdat/out267nfn.csv u=./outdat/out268nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R i=./indat/dat4.csv    o=./outdat/out269.csv    u=./outdat/out270.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R i=./indat/dat4.csv    o=./outdat/out269x.csv   u=./outdat/out270x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R i=./indat/dat4nfn.csv o=./outdat/out269nfn.csv u=./outdat/out270nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R -r i=./indat/dat4.csv    o=./outdat/out271.csv    u=./outdat/out272.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R -r i=./indat/dat4.csv    o=./outdat/out271x.csv   u=./outdat/out272x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R -r i=./indat/dat4nfn.csv o=./outdat/out271nfn.csv u=./outdat/out272nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R -F i=./indat/dat4.csv    o=./outdat/out273.csv    u=./outdat/out274.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R -F i=./indat/dat4.csv    o=./outdat/out273x.csv   u=./outdat/out274x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R -F i=./indat/dat4nfn.csv o=./outdat/out273nfn.csv u=./outdat/out274nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=03,04,05,06 -sub -R -F -r i=./indat/dat4.csv    o=./outdat/out275.csv    u=./outdat/out276.csv
${pfxc}mselstr -x   k=0    f=1,2           v=03,04,05,06 -sub -R -F -r i=./indat/dat4.csv    o=./outdat/out275x.csv   u=./outdat/out276x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=03,04,05,06 -sub -R -F -r i=./indat/dat4nfn.csv o=./outdat/out275nfn.csv u=./outdat/out276nfn.csv


${pfxc}mselstr      k=顧客 f=商品 v='柿,葡萄' -sub -W i=./indat/dat7.csv    o=./outdat/out285.csv    u=./outdat/out286.csv
${pfxc}mselstr -x   k=0    f=1    v='柿,葡萄' -sub -W i=./indat/dat7.csv    o=./outdat/out285x.csv   u=./outdat/out286x.csv
${pfxc}mselstr -nfn k=0    f=1    v='柿,葡萄' -sub -W i=./indat/dat7nfn.csv o=./outdat/out285nfn.csv u=./outdat/out286nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='柿,葡萄' -sub -W -r i=./indat/dat7.csv    o=./outdat/out287.csv    u=./outdat/out288.csv
${pfxc}mselstr -x   k=0    f=1    v='柿,葡萄' -sub -W -r i=./indat/dat7.csv    o=./outdat/out287x.csv   u=./outdat/out288x.csv
${pfxc}mselstr -nfn k=0    f=1    v='柿,葡萄' -sub -W -r i=./indat/dat7nfn.csv o=./outdat/out287nfn.csv u=./outdat/out288nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='梨,苺' -sub -W -R i=./indat/dat7.csv    o=./outdat/out289.csv    u=./outdat/out290.csv
${pfxc}mselstr -x   k=0    f=1    v='梨,苺' -sub -W -R i=./indat/dat7.csv    o=./outdat/out289x.csv   u=./outdat/out290x.csv
${pfxc}mselstr -nfn k=0    f=1    v='梨,苺' -sub -W -R i=./indat/dat7nfn.csv o=./outdat/out289nfn.csv u=./outdat/out290nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v='梨,苺' -sub -W -R -r i=./indat/dat7.csv    o=./outdat/out291.csv    u=./outdat/out292.csv
${pfxc}mselstr -x   k=0    f=1    v='梨,苺' -sub -W -R -r i=./indat/dat7.csv    o=./outdat/out291x.csv   u=./outdat/out292x.csv
${pfxc}mselstr -nfn k=0    f=1    v='梨,苺' -sub -W -R -r i=./indat/dat7nfn.csv o=./outdat/out291nfn.csv u=./outdat/out292nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０６ -sub -W i=./indat/dat8.csv    o=./outdat/out293.csv    u=./outdat/out294.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０６ -sub -W i=./indat/dat8.csv    o=./outdat/out293x.csv   u=./outdat/out294x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０６ -sub -W i=./indat/dat8nfn.csv o=./outdat/out293nfn.csv u=./outdat/out294nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０６ -sub -W -r i=./indat/dat8.csv    o=./outdat/out295.csv    u=./outdat/out296.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０６ -sub -W -r i=./indat/dat8.csv    o=./outdat/out295x.csv   u=./outdat/out296x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０６ -sub -W -r i=./indat/dat8nfn.csv o=./outdat/out295nfn.csv u=./outdat/out296nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=１０１,１０２ -sub -W -F i=./indat/dat8.csv    o=./outdat/out297.csv    u=./outdat/out298.csv
${pfxc}mselstr -x   k=0    f=1,2           v=１０１,１０２ -sub -W -F i=./indat/dat8.csv    o=./outdat/out297x.csv   u=./outdat/out298x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=１０１,１０２ -sub -W -F i=./indat/dat8nfn.csv o=./outdat/out297nfn.csv u=./outdat/out298nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=１０１,１０２ -sub -W -F -r i=./indat/dat8.csv    o=./outdat/out299.csv    u=./outdat/out300.csv
${pfxc}mselstr -x   k=0    f=1,2           v=１０１,１０２ -sub -W -F -r i=./indat/dat8.csv    o=./outdat/out299x.csv   u=./outdat/out300x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=１０１,１０２ -sub -W -F -r i=./indat/dat8nfn.csv o=./outdat/out299nfn.csv u=./outdat/out300nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R i=./indat/dat8.csv    o=./outdat/out301.csv    u=./outdat/out302.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R i=./indat/dat8.csv    o=./outdat/out301x.csv   u=./outdat/out302x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R i=./indat/dat8nfn.csv o=./outdat/out301nfn.csv u=./outdat/out302nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R -r i=./indat/dat8.csv    o=./outdat/out303.csv    u=./outdat/out304.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -r i=./indat/dat8.csv    o=./outdat/out303x.csv   u=./outdat/out304x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -r i=./indat/dat8nfn.csv o=./outdat/out303nfn.csv u=./outdat/out304nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R -F i=./indat/dat8.csv    o=./outdat/out305.csv    u=./outdat/out306.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F i=./indat/dat8.csv    o=./outdat/out305x.csv   u=./outdat/out306x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F i=./indat/dat8nfn.csv o=./outdat/out305nfn.csv u=./outdat/out306nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -sub -W -R -F -r i=./indat/dat8.csv    o=./outdat/out307.csv    u=./outdat/out308.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F -r i=./indat/dat8.csv    o=./outdat/out307x.csv   u=./outdat/out308x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０３,０４,０５,０６ -sub -W -R -F -r i=./indat/dat8nfn.csv o=./outdat/out307nfn.csv u=./outdat/out308nfn.csv


${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１０１,０１０２ -head -W -F i=./indat/dat8.csv    o=./outdat/out337.csv    u=./outdat/out338.csv
${pfxc}mselstr -x   k=0    f=1,2           v=０１０１,０１０２ -head -W -F i=./indat/dat8.csv    o=./outdat/out337x.csv   u=./outdat/out338x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=０１０１,０１０２ -head -W -F i=./indat/dat8nfn.csv o=./outdat/out337nfn.csv u=./outdat/out338nfn.csv
${pfxc}mselstr -nfno k=顧客 f=受注日,発送日 v=０１０１,０１０２ -head -W -F i=./indat/dat8.csv    o=./outdat/out337nfno.csv    u=./outdat/out338nfno.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -head -W -R i=./indat/dat11.csv    o=./outdat/out339.csv    u=./outdat/out340.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -head -W -R -r i=./indat/dat11.csv    o=./outdat/out341.csv    u=./outdat/out342.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０９,０１ -head -W -R -F i=./indat/dat11.csv    o=./outdat/out343.csv    u=./outdat/out344.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０９,０１ -head -W -R -F -r i=./indat/dat11.csv    o=./outdat/out345.csv    u=./outdat/out346.csv


${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１０１,０１０２ -tail -W -F i=./indat/dat8.csv    o=./outdat/out351.csv    u=./outdat/out352.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -tail -W -R i=./indat/dat11.csv    o=./outdat/out353.csv    u=./outdat/out354.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０３,０４,０５,０６ -tail -W -R -r i=./indat/dat11.csv    o=./outdat/out355.csv    u=./outdat/out356.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１,０３,０４,０５ -tail -W -R -F i=./indat/dat11.csv    o=./outdat/out357.csv    u=./outdat/out358.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=０１,０３,０４,０５ -tail -W -R -F -r i=./indat/dat11.csv  o=./outdat/out359.csv    u=./outdat/out360.csv


#ここまでOK
#k=にNULL
${pfxc}mselstr      k=顧客 f=商品 v=01 i=./indat/dat9.csv    o=./outdat/out309.csv    u=./outdat/out310.csv
${pfxc}mselstr -x   k=0    f=1    v=01 i=./indat/dat9.csv    o=./outdat/out309x.csv   u=./outdat/out310x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01 i=./indat/dat9nfn.csv o=./outdat/out309nfn.csv u=./outdat/out310nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=01 -r i=./indat/dat9.csv    o=./outdat/out311.csv    u=./outdat/out312.csv
${pfxc}mselstr -x   k=0    f=1    v=01 -r i=./indat/dat9.csv    o=./outdat/out311x.csv   u=./outdat/out312x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01 -r i=./indat/dat9nfn.csv o=./outdat/out311nfn.csv u=./outdat/out312nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=01,04,05 -R i=./indat/dat9.csv    o=./outdat/out313.csv    u=./outdat/out314.csv
${pfxc}mselstr -x   k=0    f=1    v=01,04,05 -R i=./indat/dat9.csv    o=./outdat/out313x.csv   u=./outdat/out314x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,04,05 -R i=./indat/dat9nfn.csv o=./outdat/out313nfn.csv u=./outdat/out314nfn.csv

${pfxc}mselstr      k=顧客 f=商品 v=01,04,05 -R -r i=./indat/dat9.csv    o=./outdat/out315.csv    u=./outdat/out316.csv
${pfxc}mselstr -x   k=0    f=1    v=01,04,05 -R -r i=./indat/dat9.csv    o=./outdat/out315x.csv   u=./outdat/out316x.csv
${pfxc}mselstr -nfn k=0    f=1    v=01,04,05 -R -r i=./indat/dat9nfn.csv o=./outdat/out315nfn.csv u=./outdat/out316nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 i=./indat/dat10.csv    o=./outdat/out317.csv    u=./outdat/out318.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 i=./indat/dat10.csv    o=./outdat/out317x.csv   u=./outdat/out318x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 i=./indat/dat10nfn.csv o=./outdat/out317nfn.csv u=./outdat/out318nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -r i=./indat/dat10.csv    o=./outdat/out319.csv    u=./outdat/out320.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat10.csv    o=./outdat/out319x.csv   u=./outdat/out320x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -r i=./indat/dat10nfn.csv o=./outdat/out319nfn.csv u=./outdat/out320nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F i=./indat/dat10.csv    o=./outdat/out321.csv    u=./outdat/out322.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat10.csv    o=./outdat/out321x.csv   u=./outdat/out322x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F i=./indat/dat10nfn.csv o=./outdat/out321nfn.csv u=./outdat/out322nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090101,20090102 -F -r i=./indat/dat10.csv    o=./outdat/out323.csv    u=./outdat/out324.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat10.csv    o=./outdat/out323x.csv   u=./outdat/out324x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090101,20090102 -F -r i=./indat/dat10nfn.csv o=./outdat/out323nfn.csv u=./outdat/out324nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R i=./indat/dat10.csv    o=./outdat/out325.csv    u=./outdat/out326.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat10.csv    o=./outdat/out325x.csv   u=./outdat/out326x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R i=./indat/dat10nfn.csv o=./outdat/out325nfn.csv u=./outdat/out326nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat10.csv    o=./outdat/out327.csv    u=./outdat/out328.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat10.csv    o=./outdat/out327x.csv   u=./outdat/out328x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -r i=./indat/dat10nfn.csv o=./outdat/out327nfn.csv u=./outdat/out328nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat10.csv    o=./outdat/out329.csv    u=./outdat/out330.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat10.csv    o=./outdat/out329x.csv   u=./outdat/out330x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F i=./indat/dat10nfn.csv o=./outdat/out329nfn.csv u=./outdat/out330nfn.csv

${pfxc}mselstr      k=顧客 f=受注日,発送日 v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat10.csv    o=./outdat/out331.csv    u=./outdat/out332.csv
${pfxc}mselstr -x   k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat10.csv    o=./outdat/out331x.csv   u=./outdat/out332x.csv
${pfxc}mselstr -nfn k=0    f=1,2           v=20090103,20090104,20090105,20090106 -R -F -r i=./indat/dat10nfn.csv o=./outdat/out331nfn.csv u=./outdat/out332nfn.csv


