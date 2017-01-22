#!/bin/bash

. ../env

#name_kg_mcmd selnum

#NULL data

#f=1つ 
${pfxc}mselnum      f=金額 c='(250,450]' i=./indat/dat0.csv    o=./outdat/out0.csv 
${pfxc}mselnum -x   f=2 c='(250,450]' i=./indat/dat0.csv    o=./outdat/out0x.csv 
${pfxc}mselnum -nfn f=2 c='(250,450]' i=./indat/dat0nfn.csv    o=./outdat/out0nfn.csv 


${pfxc}mselnum      f=金額 c='(250,450]' i=./indat/dat1s.csv    o=./outdat/out1.csv 
${pfxc}mselnum -x      f=2 c='(250,450]' i=./indat/dat1s.csv    o=./outdat/out1x.csv 
${pfxc}mselnum -nfn     f=2 c='(250,450]' i=./indat/dat1snfn.csv    o=./outdat/out1nfn.csv 

${pfxc}mselnum      f=金額 c='[250,450]' i=./indat/dat1s.csv    o=./outdat/out2.csv 
${pfxc}mselnum -x     f=2 c='[250,450]' i=./indat/dat1s.csv    o=./outdat/out2x.csv 
${pfxc}mselnum -nfn     f=2 c='[250,450]' i=./indat/dat1snfn.csv    o=./outdat/out2nfn.csv 

${pfxc}mselnum      f=金額 c='(250,450)' i=./indat/dat1s.csv    o=./outdat/out3.csv 
${pfxc}mselnum -x     f=2 c='(250,450)' i=./indat/dat1s.csv    o=./outdat/out3x.csv 
${pfxc}mselnum -nfn     f=2 c='(250,450)' i=./indat/dat1snfn.csv    o=./outdat/out3nfn.csv 

${pfxc}mselnum      f=金額 c='[250,450)' i=./indat/dat1s.csv    o=./outdat/out4.csv 
${pfxc}mselnum -x     f=2 c='[250,450)' i=./indat/dat1s.csv    o=./outdat/out4x.csv 
${pfxc}mselnum -nfn     f=2 c='[250,450)' i=./indat/dat1snfn.csv    o=./outdat/out4nfn.csv 

#f=2つ
${pfxc}mselnum      f=金額,定価 c='(150,500]' i=./indat/dat1s.csv    o=./outdat/out5.csv 
${pfxc}mselnum -x     f=2,3 c='(150,500]' i=./indat/dat1s.csv    o=./outdat/out5x.csv 
${pfxc}mselnum -nfn     f=2,3 c='(150,500]' i=./indat/dat1snfn.csv    o=./outdat/out5nfn.csv 

${pfxc}mselnum      f=金額,定価 c='[150,500]' i=./indat/dat1s.csv    o=./outdat/out6.csv 
${pfxc}mselnum -x     f=2,3 c='[150,500]' i=./indat/dat1s.csv    o=./outdat/out6x.csv 
${pfxc}mselnum -nfn     f=2,3 c='[150,500]' i=./indat/dat1snfn.csv    o=./outdat/out6nfn.csv 

${pfxc}mselnum      f=金額,定価 c='(150,500)' i=./indat/dat1s.csv    o=./outdat/out7.csv 
${pfxc}mselnum -x     f=2,3 c='(150,500)' i=./indat/dat1s.csv    o=./outdat/out7x.csv 
${pfxc}mselnum -nfn     f=2,3 c='(150,500)' i=./indat/dat1snfn.csv    o=./outdat/out7nfn.csv 

${pfxc}mselnum      f=金額,定価 c='[150,500)' i=./indat/dat1s.csv    o=./outdat/out8.csv 
${pfxc}mselnum -x     f=2,3 c='[150,500)' i=./indat/dat1s.csv    o=./outdat/out8x.csv 
${pfxc}mselnum -nfn     f=2,3 c='[150,500)' i=./indat/dat1snfn.csv    o=./outdat/out8nfn.csv 

#u=指定あり
${pfxc}mselnum      f=金額 c='(250,450]' i=./indat/dat1s.csv    o=./outdat/out9.csv u=./outdat/out10.csv
${pfxc}mselnum -x     f=2 c='(250,450]' i=./indat/dat1s.csv    o=./outdat/out9x.csv u=./outdat/out10x.csv
${pfxc}mselnum -nfn     f=2 c='(250,450]' i=./indat/dat1snfn.csv    o=./outdat/out9nfn.csv u=./outdat/out10nfn.csv

${pfxc}mselnum      f=金額 c='[250,450]' i=./indat/dat1s.csv    o=./outdat/out11.csv u=./outdat/out12.csv 
${pfxc}mselnum -x     f=2 c='[250,450]' i=./indat/dat1s.csv    o=./outdat/out11x.csv u=./outdat/out12x.csv 
${pfxc}mselnum -nfn     f=2 c='[250,450]' i=./indat/dat1snfn.csv    o=./outdat/out11nfn.csv u=./outdat/out12nfn.csv 

${pfxc}mselnum      f=金額 c='(250,450)' i=./indat/dat1s.csv    o=./outdat/out13.csv u=./outdat/out14.csv
${pfxc}mselnum -x     f=2 c='(250,450)' i=./indat/dat1s.csv    o=./outdat/out13x.csv u=./outdat/out14x.csv
${pfxc}mselnum -nfn     f=2 c='(250,450)' i=./indat/dat1snfn.csv    o=./outdat/out13nfn.csv u=./outdat/out14nfn.csv

${pfxc}mselnum      f=金額 c='[250,450)' i=./indat/dat1s.csv    o=./outdat/out15.csv u=./outdat/out16.csv
${pfxc}mselnum -x     f=2 c='[250,450)' i=./indat/dat1s.csv    o=./outdat/out15x.csv u=./outdat/out16x.csv
${pfxc}mselnum -nfn     f=2 c='[250,450)' i=./indat/dat1snfn.csv    o=./outdat/out15nfn.csv u=./outdat/out16nfn.csv

#-rあり
${pfxc}mselnum      f=金額 c='(250,450]' -r i=./indat/dat1s.csv    o=./outdat/out17.csv
${pfxc}mselnum -x     f=2 c='(250,450]' -r i=./indat/dat1s.csv    o=./outdat/out17x.csv
${pfxc}mselnum -nfn     f=2 c='(250,450]' -r i=./indat/dat1snfn.csv    o=./outdat/out17nfn.csv

${pfxc}mselnum      f=金額 c='[250,450]' -r i=./indat/dat1s.csv    o=./outdat/out18.csv 
${pfxc}mselnum -x     f=2 c='[250,450]' -r i=./indat/dat1s.csv    o=./outdat/out18x.csv 
${pfxc}mselnum -nfn     f=2 c='[250,450]' -r i=./indat/dat1snfn.csv    o=./outdat/out18nfn.csv 

${pfxc}mselnum      f=金額 c='(250,450)' -r i=./indat/dat1s.csv    o=./outdat/out19.csv 
${pfxc}mselnum -x     f=2 c='(250,450)' -r i=./indat/dat1s.csv    o=./outdat/out19x.csv 
${pfxc}mselnum -nfn     f=2 c='(250,450)' -r i=./indat/dat1snfn.csv    o=./outdat/out19nfn.csv 

${pfxc}mselnum      f=金額 c='[250,450)' -r i=./indat/dat1s.csv    o=./outdat/out20.csv 
${pfxc}mselnum -x     f=2 c='[250,450)' -r i=./indat/dat1s.csv    o=./outdat/out20x.csv 
${pfxc}mselnum -nfn     f=2 c='[250,450)' -r i=./indat/dat1snfn.csv    o=./outdat/out20nfn.csv 

#-rあり,u=指定あり
${pfxc}mselnum      f=金額 c='(250,450]' -r i=./indat/dat1s.csv    o=./outdat/out21.csv u=./outdat/out22.csv
${pfxc}mselnum -x     f=2 c='(250,450]' -r i=./indat/dat1s.csv    o=./outdat/out21x.csv u=./outdat/out22x.csv
${pfxc}mselnum -nfn     f=2 c='(250,450]' -r i=./indat/dat1snfn.csv    o=./outdat/out21nfn.csv u=./outdat/out22nfn.csv

${pfxc}mselnum      f=金額 c='[250,450]' -r i=./indat/dat1s.csv    o=./outdat/out23.csv u=./outdat/out24.csv 
${pfxc}mselnum -x     f=2 c='[250,450]' -r i=./indat/dat1s.csv    o=./outdat/out23x.csv u=./outdat/out24x.csv 
${pfxc}mselnum -nfn     f=2 c='[250,450]' -r i=./indat/dat1snfn.csv    o=./outdat/out23nfn.csv u=./outdat/out24nfn.csv 

${pfxc}mselnum      f=金額 c='(250,450)' -r i=./indat/dat1s.csv    o=./outdat/out25.csv u=./outdat/out26.csv
${pfxc}mselnum -x     f=2 c='(250,450)' -r i=./indat/dat1s.csv    o=./outdat/out25x.csv u=./outdat/out26x.csv
${pfxc}mselnum -nfn     f=2 c='(250,450)' -r i=./indat/dat1snfn.csv    o=./outdat/out25nfn.csv u=./outdat/out26nfn.csv

${pfxc}mselnum      f=金額 c='[250,450)' -r i=./indat/dat1s.csv    o=./outdat/out27.csv u=./outdat/out28.csv
${pfxc}mselnum -x     f=2 c='[250,450)' -r i=./indat/dat1s.csv    o=./outdat/out27x.csv u=./outdat/out28x.csv
${pfxc}mselnum -nfn     f=2 c='[250,450)' -r i=./indat/dat1snfn.csv    o=./outdat/out27nfn.csv u=./outdat/out28nfn.csv

#-Fあり
${pfxc}mselnum      f=金額,定価 c='[300,450]' -F i=./indat/dat1s.csv    o=./outdat/out29.csv 
${pfxc}mselnum -x     f=2,3 c='[300,450]' -F i=./indat/dat1s.csv    o=./outdat/out29x.csv 
${pfxc}mselnum -nfn     f=2,3 c='[300,450]' -F i=./indat/dat1snfn.csv    o=./outdat/out29nfn.csv 

#k=あり
${pfxc}mselnum k=顧客 f=金額 c='(250,350]' i=./indat/dat1s.csv    o=./outdat/out30.csv 
${pfxc}mselnum -x k=0 f=2 c='(250,350]' i=./indat/dat1s.csv    o=./outdat/out30x.csv 
${pfxc}mselnum -nfn k=0 f=2 c='(250,350]' i=./indat/dat1snfn.csv    o=./outdat/out30nfn.csv 
${pfxc}mselnum -q k=顧客 f=金額 c='(250,350]' i=./indat/dat1s.csv    o=./outdat/out30q.csv 
${pfxc}mselnum -q -x k=0 f=2 c='(250,350]' i=./indat/dat1s.csv    o=./outdat/out30qx.csv 

#k=あり -Rあり
${pfxc}mselnum k=顧客 f=金額 c='(100,300]' -R i=./indat/dat1s.csv    o=./outdat/out31.csv 
${pfxc}mselnum -x k=0 f=2 c='(100,300]' -R i=./indat/dat1s.csv    o=./outdat/out31x.csv 
${pfxc}mselnum -nfn k=0 f=2 c='(100,300]' -R i=./indat/dat1snfn.csv    o=./outdat/out31nfn.csv 

${pfxc}mselnum k=顧客 f=金額 c='[100,300]' -R i=./indat/dat1s.csv    o=./outdat/out32.csv 
${pfxc}mselnum -x k=0 f=2 c='[100,300]' -R i=./indat/dat1s.csv    o=./outdat/out32x.csv 
${pfxc}mselnum -nfn k=0 f=2 c='[100,300]' -R i=./indat/dat1snfn.csv    o=./outdat/out32nfn.csv 


#ランダムデータ
#k=あり
${pfxc}mselnum k=顧客 f=金額 c='(250,350]' i=./indat/dat1.csv    o=./outdat/out33.csv 
${pfxc}mselnum -x k=0 f=2 c='(250,350]' i=./indat/dat1.csv    o=./outdat/out33x.csv 
${pfxc}mselnum -nfn k=0 f=2 c='(250,350]' i=./indat/dat1nfn.csv    o=./outdat/out33nfn.csv 
${pfxc}mselnum -q -x k=0 f=2 c='(250,350]' i=./indat/dat1.csv    o=./outdat/out33qx.csv 
${pfxc}mselnum -q -nfn k=0 f=2 c='(250,350]' i=./indat/dat1nfn.csv    o=./outdat/out33qnfn.csv 

#k=あり -Rあり
${pfxc}mselnum k=顧客 f=金額 c='(100,300]' -R i=./indat/dat1.csv    o=./outdat/out34.csv 
${pfxc}mselnum -x k=0 f=2 c='(100,300]' -R i=./indat/dat1.csv    o=./outdat/out34x.csv 
${pfxc}mselnum -nfn k=0 f=2 c='(100,300]' -R i=./indat/dat1nfn.csv    o=./outdat/out34nfn.csv 

${pfxc}mselnum k=顧客 f=金額 c='[100,300]' -R i=./indat/dat1.csv    o=./outdat/out35.csv 
${pfxc}mselnum -x k=0 f=2 c='[100,300]' -R i=./indat/dat1.csv    o=./outdat/out35x.csv 
${pfxc}mselnum -nfn k=0 f=2 c='[100,300]' -R i=./indat/dat1nfn.csv    o=./outdat/out35nfn.csv 


