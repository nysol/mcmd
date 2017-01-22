#修正日は 20120308
#修正者は 樋口　寛視
#修正内容は 項目番号指定パラーメータをマイナス１する。（以前は1からの指定だったが、０からに変更になったため。）
#!/bin/bash

. ../env

#name_kg_mcmd count

#NULL
${pfxc}mcount      k=日付 a=連番 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mcount -x   k=0    a=連番 i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mcount -nfn k=0           i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mcount -nfno k=日付 i=./indat/dat0s.csv    o=./outdat/out0nfno.csv

#基本
${pfxc}mcount      k=日付 a=連番 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mcount -x   k=0    a=連番 i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mcount -nfn k=0           i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mcount -nfno k=日付       i=./indat/dat1s.csv    o=./outdat/out1nfno.csv
${pfxc}mcount -q     k=日付 a=連番 i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}mcount -q -nfn k=0           i=./indat/dat1snfn.csv o=./outdat/out1qnfn.csv

#k=なし
${pfxc}mcount      a=連番 i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mcount -x   a=連番 i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mcount -nfn        i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mcount -nfno       i=./indat/dat1s.csv    o=./outdat/out2nfno.csv

#k=二つ
${pfxc}mcount      k=日付,顧客 a=連番 i=./indat/dat2s.csv    o=./outdat/out3.csv
${pfxc}mcount -x   k=0,1       a=連番 i=./indat/dat2s.csv    o=./outdat/out3x.csv
${pfxc}mcount -nfn k=0,1              i=./indat/dat2snfn.csv o=./outdat/out3nfn.csv
${pfxc}mcount -nfno k=日付,顧客 i=./indat/dat2s.csv    o=./outdat/out3nfno.csv

#k=でNULLあり
${pfxc}mcount      k=日付 a=連番 i=./indat/dat3s.csv o=./outdat/out4.csv
${pfxc}mcount -x   k=0    a=連番 i=./indat/dat3s.csv o=./outdat/out4x.csv
${pfxc}mcount -nfn k=0           i=./indat/dat3snfn.csv o=./outdat/out4nfn.csv
${pfxc}mcount -nfno k=日付 i=./indat/dat3s.csv o=./outdat/out4nfno.csv

#k=２つでNULLあり
${pfxc}mcount      k=日付,顧客 a=連番 i=./indat/dat4s.csv    o=./outdat/out5.csv
${pfxc}mcount -x   k=0,1       a=連番 i=./indat/dat4s.csv    o=./outdat/out5x.csv
${pfxc}mcount -nfn k=0,1              i=./indat/dat4snfn.csv o=./outdat/out5nfn.csv
${pfxc}mcount -nfno k=日付,顧客 i=./indat/dat4s.csv    o=./outdat/out5nfno.csv

#k=なしでNULLあり
${pfxc}mcount      a=連番 i=./indat/dat4s.csv    o=./outdat/out6.csv
${pfxc}mcount -x   a=連番 i=./indat/dat4s.csv    o=./outdat/out6x.csv
${pfxc}mcount -nfn        i=./indat/dat4snfn.csv o=./outdat/out6nfn.csv
${pfxc}mcount -nfno i=./indat/dat4s.csv    o=./outdat/out6nfno.csv


#ランダムデータ

#NULL
${pfxc}mcount      k=日付 a=連番 i=./indat/dat0.csv    o=./outdat/out7.csv
${pfxc}mcount -x   k=0    a=連番 i=./indat/dat0.csv    o=./outdat/out7x.csv
${pfxc}mcount -nfn k=0           i=./indat/dat0nfn.csv o=./outdat/out7nfn.csv
${pfxc}mcount -nfno k=日付 i=./indat/dat0.csv    o=./outdat/out7nfno.csv

#基本
${pfxc}mcount      k=日付 a=連番 i=./indat/dat1.csv    o=./outdat/out8.csv
${pfxc}mcount -x   k=0    a=連番 i=./indat/dat1.csv    o=./outdat/out8x.csv
${pfxc}mcount -nfn k=0           i=./indat/dat1nfn.csv o=./outdat/out8nfn.csv
${pfxc}mcount -nfno k=日付       i=./indat/dat1.csv    o=./outdat/out8nfno.csv
${pfxc}mcount -q     k=日付 a=連番 i=./indat/dat1.csv    o=./outdat/out8q.csv
${pfxc}mcount -q -nfn k=0           i=./indat/dat1nfn.csv o=./outdat/out8qnfn.csv

#k=なし
${pfxc}mcount      a=連番 i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}mcount -x   a=連番 i=./indat/dat1.csv    o=./outdat/out9x.csv
${pfxc}mcount -nfn        i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv
${pfxc}mcount -nfno       i=./indat/dat1.csv    o=./outdat/out9nfno.csv

#k=二つ
${pfxc}mcount      k=日付,顧客 a=連番 i=./indat/dat2.csv    o=./outdat/out10.csv
${pfxc}mcount -x   k=0,1       a=連番 i=./indat/dat2.csv    o=./outdat/out10x.csv
${pfxc}mcount -nfn k=0,1              i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv
${pfxc}mcount -nfno k=日付,顧客 i=./indat/dat2.csv    o=./outdat/out10nfno.csv

#k=でNULLあり
${pfxc}mcount      k=日付 a=連番 i=./indat/dat3.csv o=./outdat/out11.csv
${pfxc}mcount -x   k=0    a=連番 i=./indat/dat3.csv o=./outdat/out11x.csv
${pfxc}mcount -nfn k=0           i=./indat/dat3nfn.csv o=./outdat/out11nfn.csv
${pfxc}mcount -nfno k=日付 i=./indat/dat3.csv o=./outdat/out11nfno.csv

#k=２つでNULLあり
${pfxc}mcount      k=日付,顧客 a=連番 i=./indat/dat4.csv    o=./outdat/out12.csv
${pfxc}mcount -x   k=0,1       a=連番 i=./indat/dat4.csv    o=./outdat/out12x.csv
${pfxc}mcount -nfn k=0,1              i=./indat/dat4nfn.csv o=./outdat/out12nfn.csv
${pfxc}mcount -nfno k=日付,顧客 i=./indat/dat4.csv    o=./outdat/out12nfno.csv

#k=なしでNULLあり
${pfxc}mcount      a=連番 i=./indat/dat4.csv    o=./outdat/out13.csv
${pfxc}mcount -x   a=連番 i=./indat/dat4.csv    o=./outdat/out13x.csv
${pfxc}mcount -nfn        i=./indat/dat4nfn.csv o=./outdat/out13nfn.csv
${pfxc}mcount -nfno i=./indat/dat4.csv    o=./outdat/out13nfno.csv


