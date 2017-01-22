#!/bin/bash

. ../env

#name_kg_mcmd stats

#NULLデータ
${pfxc}mstats      i=./indat/dat0.csv    o=./outdat/out01.csv    f=数量,金額 c=count

#通常

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out02.csv    f=数量,金額 c=count
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out02x.csv    f=1,2 c=count
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out02nfn.csv    f=1,2 c=count
${pfxc}mstats -q    i=./indat/dat1s.csv    o=./outdat/out02q.csv    f=数量,金額 c=count
${pfxc}mstats -q -x i=./indat/dat1s.csv    o=./outdat/out02qx.csv    f=1,2 c=count

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out03.csv    f=数量,金額 c=ucount
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out03x.csv    f=1,2 c=ucount
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out03nfn.csv    f=1,2 c=ucount

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out04.csv    f=数量,金額 c=sum
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out04x.csv    f=1,2 c=sum
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out04nfn.csv    f=1,2 c=sum

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out05.csv    f=数量,金額 c=mean
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out05x.csv    f=1,2 c=mean
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out05nfn.csv    f=1,2 c=mean

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out06.csv    f=数量,金額 c=devsq
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out06x.csv    f=1,2 c=devsq
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out06nfn.csv    f=1,2 c=devsq

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out07.csv    f=数量,金額 c=var
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out07x.csv    f=1,2 c=var
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out07nfn.csv    f=1,2 c=var

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out08.csv    f=数量,金額 c=uvar
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out08x.csv    f=1,2 c=uvar
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out08nfn.csv    f=1,2 c=uvar

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out09.csv    f=数量,金額 c=sd
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out09x.csv    f=1,2 c=sd
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out09nfn.csv    f=1,2 c=sd

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out10.csv    f=数量,金額 c=usd
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out10x.csv    f=1,2 c=usd
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out10nfn.csv    f=1,2 c=usd

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out11.csv    f=数量,金額 c=USD
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out11x.csv    f=1,2 c=USD
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out11nfn.csv    f=1,2 c=USD

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out12.csv    f=数量,金額 c=cv
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out12x.csv    f=1,2 c=cv
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out12nfn.csv    f=1,2 c=cv

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out13.csv    f=数量,金額 c=mode
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out13x.csv    f=1,2 c=mode
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out13nfn.csv    f=1,2 c=mode

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out14.csv    f=数量,金額 c=min
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out14x.csv    f=1,2 c=min
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out14nfn.csv    f=1,2 c=min

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out15.csv    f=数量,金額 c=max
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out15x.csv    f=1,2 c=max
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out15nfn.csv    f=1,2 c=max

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out16.csv    f=数量,金額 c=range
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out16x.csv    f=1,2 c=range
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out16nfn.csv    f=1,2 c=range

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out17.csv    f=数量,金額 c=median
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out17x.csv    f=1,2 c=median
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out17nfn.csv    f=1,2 c=median

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out18.csv    f=数量,金額 c=qtile1
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out18x.csv    f=1,2 c=qtile1
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out18nfn.csv    f=1,2 c=qtile1

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out19.csv    f=数量,金額 c=qtile3
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out19x.csv    f=1,2 c=qtile3
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out19nfn.csv    f=1,2 c=qtile3

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out20.csv    f=数量,金額 c=qrange
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out20x.csv    f=1,2 c=qrange
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out20nfn.csv    f=1,2 c=qrange

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out21.csv    f=数量,金額 c=skew
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out21x.csv    f=1,2 c=skew
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out21nfn.csv    f=1,2 c=skew

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out22.csv    f=数量,金額 c=uskew
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out22x.csv    f=1,2 c=uskew
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out22nfn.csv    f=1,2 c=uskew

${pfxc}mstats	     i=./indat/dat1s.csv    o=./outdat/out23.csv    f=数量,金額 c=kurt
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out23x.csv    f=1,2 c=kurt
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out23nfn.csv    f=1,2 c=kurt

${pfxc}mstats      i=./indat/dat1s.csv    o=./outdat/out24.csv    f=数量,金額 c=ukurt
${pfxc}mstats -x   i=./indat/dat1s.csv    o=./outdat/out24x.csv    f=1,2 c=ukurt
${pfxc}mstats -nfn i=./indat/dat1snfn.csv    o=./outdat/out24nfn.csv    f=1,2 c=ukurt

#k=あり
${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out25.csv    f=数量,金額 c=count
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out25x.csv    f=1,2 c=count
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out25nfn.csv    f=1,2 c=count

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out26.csv    f=数量,金額 c=ucount
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out26x.csv    f=1,2 c=ucount
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out26nfn.csv    f=1,2 c=ucount

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out27.csv    f=数量,金額 c=sum
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out27x.csv    f=1,2 c=sum
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out27nfn.csv    f=1,2 c=sum

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out28.csv    f=数量,金額 c=mean
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out28x.csv    f=1,2 c=mean
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out28nfn.csv    f=1,2 c=mean

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out29.csv    f=数量,金額 c=devsq
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out29x.csv    f=1,2 c=devsq
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out29nfn.csv    f=1,2 c=devsq

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out30.csv    f=数量,金額 c=var
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out30x.csv    f=1,2 c=var
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out30nfn.csv    f=1,2 c=var

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out31.csv    f=数量,金額 c=uvar
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out31x.csv    f=1,2 c=uvar
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out31nfn.csv    f=1,2 c=uvar

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out32.csv    f=数量,金額 c=sd
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out32x.csv    f=1,2 c=sd
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out32nfn.csv    f=1,2 c=sd

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out33.csv    f=数量,金額 c=usd
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out33x.csv    f=1,2 c=usd
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out33nfn.csv    f=1,2 c=usd

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out34.csv    f=数量,金額 c=USD
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out34x.csv    f=1,2 c=USD
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out34nfn.csv    f=1,2 c=USD

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out35.csv    f=数量,金額 c=cv
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out35x.csv    f=1,2 c=cv
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out35nfn.csv    f=1,2 c=cv

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out36.csv    f=数量,金額 c=mode
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out36x.csv    f=1,2 c=mode
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out36nfn.csv    f=1,2 c=mode

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out37.csv    f=数量,金額 c=min
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out37x.csv    f=1,2 c=min
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out37nfn.csv    f=1,2 c=min

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out38.csv    f=数量,金額 c=max
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out38x.csv    f=1,2 c=max
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out38nfn.csv    f=1,2 c=max

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out39.csv    f=数量,金額 c=range
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out39x.csv    f=1,2 c=range
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out39nfn.csv    f=1,2 c=range

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out40.csv    f=数量,金額 c=median
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out40x.csv    f=1,2 c=median
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out40nfn.csv    f=1,2 c=median

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out41.csv    f=数量,金額 c=qtile1
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out41x.csv    f=1,2 c=qtile1
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out41nfn.csv    f=1,2 c=qtile1

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out42.csv    f=数量,金額 c=qtile3
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out42x.csv    f=1,2 c=qtile3
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out42nfn.csv    f=1,2 c=qtile3

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out43.csv    f=数量,金額 c=qrange
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out43x.csv    f=1,2 c=qrange
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out43nfn.csv    f=1,2 c=qrange

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out44.csv    f=数量,金額 c=skew
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out44x.csv    f=1,2 c=skew
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out44nfn.csv    f=1,2 c=skew

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out45.csv    f=数量,金額 c=uskew
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out45x.csv    f=1,2 c=uskew
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out45nfn.csv    f=1,2 c=uskew

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out46.csv    f=数量,金額 c=kurt
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out46x.csv    f=1,2 c=kurt
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out46nfn.csv    f=1,2 c=kurt

${pfxc}mstats      k=顧客 i=./indat/dat1s.csv    o=./outdat/out47.csv    f=数量,金額 c=ukurt
${pfxc}mstats -x   k=0    i=./indat/dat1s.csv    o=./outdat/out47x.csv    f=1,2 c=ukurt
${pfxc}mstats -nfn k=0    i=./indat/dat1snfn.csv    o=./outdat/out47nfn.csv    f=1,2 c=ukurt



#ランダムデータ

#k=あり
${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out125.csv    f=数量,金額 c=count
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out125x.csv    f=1,2 c=count
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out125nfn.csv    f=1,2 c=count
${pfxc}mstats -q    k=顧客 i=./indat/dat1.csv    o=./outdat/out125q.csv    f=数量,金額 c=count
${pfxc}mstats -q -x k=0    i=./indat/dat1.csv    o=./outdat/out125qx.csv    f=1,2 c=count

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out126.csv    f=数量,金額 c=ucount
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out126x.csv    f=1,2 c=ucount
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out126nfn.csv    f=1,2 c=ucount

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out127.csv    f=数量,金額 c=sum
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out127x.csv    f=1,2 c=sum
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out127nfn.csv    f=1,2 c=sum

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out128.csv    f=数量,金額 c=mean
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out128x.csv    f=1,2 c=mean
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out128nfn.csv    f=1,2 c=mean

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out129.csv    f=数量,金額 c=devsq
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out129x.csv    f=1,2 c=devsq
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out129nfn.csv    f=1,2 c=devsq

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out130.csv    f=数量,金額 c=var
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out130x.csv    f=1,2 c=var
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out130nfn.csv    f=1,2 c=var

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out131.csv    f=数量,金額 c=uvar
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out131x.csv    f=1,2 c=uvar
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out131nfn.csv    f=1,2 c=uvar

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out132.csv    f=数量,金額 c=sd
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out132x.csv    f=1,2 c=sd
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out132nfn.csv    f=1,2 c=sd

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out133.csv    f=数量,金額 c=usd
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out133x.csv    f=1,2 c=usd
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out133nfn.csv    f=1,2 c=usd

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out134.csv    f=数量,金額 c=USD
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out134x.csv    f=1,2 c=USD
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out134nfn.csv    f=1,2 c=USD

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out135.csv    f=数量,金額 c=cv
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out135x.csv    f=1,2 c=cv
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out135nfn.csv    f=1,2 c=cv

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out136.csv    f=数量,金額 c=mode
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out136x.csv    f=1,2 c=mode
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out136nfn.csv    f=1,2 c=mode

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out137.csv    f=数量,金額 c=min
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out137x.csv    f=1,2 c=min
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out137nfn.csv    f=1,2 c=min

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out138.csv    f=数量,金額 c=max
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out138x.csv    f=1,2 c=max
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out138nfn.csv    f=1,2 c=max

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out139.csv    f=数量,金額 c=range
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out139x.csv    f=1,2 c=range
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out139nfn.csv    f=1,2 c=range

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out140.csv    f=数量,金額 c=median
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out140x.csv    f=1,2 c=median
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out140nfn.csv    f=1,2 c=median

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out141.csv    f=数量,金額 c=qtile1
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out141x.csv    f=1,2 c=qtile1
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out141nfn.csv    f=1,2 c=qtile1

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out142.csv    f=数量,金額 c=qtile3
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out142x.csv    f=1,2 c=qtile3
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out142nfn.csv    f=1,2 c=qtile3

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out143.csv    f=数量,金額 c=qrange
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out143x.csv    f=1,2 c=qrange
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out143nfn.csv    f=1,2 c=qrange

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out144.csv    f=数量,金額 c=skew
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out144x.csv    f=1,2 c=skew
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out144nfn.csv    f=1,2 c=skew

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out145.csv    f=数量,金額 c=uskew
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out145x.csv    f=1,2 c=uskew
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out145nfn.csv    f=1,2 c=uskew

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out146.csv    f=数量,金額 c=kurt
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out146x.csv    f=1,2 c=kurt
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out146nfn.csv    f=1,2 c=kurt

${pfxc}mstats      k=顧客 i=./indat/dat1.csv    o=./outdat/out147.csv    f=数量,金額 c=ukurt
${pfxc}mstats -x   k=0    i=./indat/dat1.csv    o=./outdat/out147x.csv    f=1,2 c=ukurt
${pfxc}mstats -nfn k=0    i=./indat/dat1nfn.csv    o=./outdat/out147nfn.csv    f=1,2 c=ukurt
