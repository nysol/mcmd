#!/bin/bash
# error行以降は途中でテスト結果記録が出なくなるので修正した。

. ../env
#name_kg_mcmd fldname

${pfxc}mfldname       f=顧客:cust,10月:Oct. i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mfldname -x    f=0:cust,2:Oct.       i=./indat/dat0.csv    o=./outdat/out0x.csv

#f=指定
${pfxc}mfldname       f=顧客:cust,10月:Oct. i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mfldname -x    f=0:cust,2:Oct.       i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mfldname -q      f=顧客:cust,10月:Oct. i=./indat/dat1.csv    o=./outdat/out1q.csv
${pfxc}mfldname -q -x   f=0:cust,2:Oct.       i=./indat/dat1.csv    o=./outdat/out1qx.csv

#n=指定
${pfxc}mfldname       n=x,y,z i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mfldname -x    n=x,y,z i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mfldname -nfni n=x,y,z i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}mfldname -q    n=x,y,z i=./indat/dat1.csv    o=./outdat/out2q.csv

#-nfno指定
${pfxc}mfldname  -nfno i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mfldname  -x -nfno    i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mfldname  -nfni -nfno i=./indat/dat1nfn.csv    o=./outdat/out3nfn.csv


${pfxc}mfldname -nfn n=x,y,z i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv

#ソートデータ
#f=指定
${pfxc}mfldname       f=顧客:cust,10月:Oct. i=./indat/dat1s.csv    o=./outdat/out6.csv
${pfxc}mfldname -x    f=0:cust,2:Oct.       i=./indat/dat1s.csv    o=./outdat/out6x.csv
${pfxc}mfldname -q      f=顧客:cust,10月:Oct. i=./indat/dat1s.csv    o=./outdat/out6q.csv
${pfxc}mfldname -q -x   f=0:cust,2:Oct.       i=./indat/dat1s.csv    o=./outdat/out6qx.csv

#n=指定
${pfxc}mfldname       n=x,y,z i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}mfldname -x    n=x,y,z i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mfldname -nfni n=x,y,z i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv
${pfxc}mfldname -q    n=x,y,z i=./indat/dat1s.csv    o=./outdat/out7q.csv


# error
#${pfxc}mfldname -nfni f=1:cust,3:Oct.       i=./indat/dat1nfn.csv
#${pfxc}mfldname   n=xxx,yyy  i=./indat/dat1.csv
#${pfxc}mfldname   i=./indat/dat1.csv
#${pfxc}mfldname -nfn    f=0:cust,2:Oct.     i=./indat/dat1nfn.csv    o=./outdat/out4nfn.csv

#headerが出力されない
