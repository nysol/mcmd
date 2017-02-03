#!/bin/bash

. ../env
#name_kg_mcmd cross
#NULL
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}m2cross -x   k=0    s=1    f=2    i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2    i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat0s.csv   o=./outdat/out0nfno.csv

#基本f=2項目
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}m2cross -x   k=0    s=1    f=2    i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2    i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat1s.csv   o=./outdat/out1nfno.csv
${pfxc}m2cross -q     k=商品 s=日付 f=数量 i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}m2cross -q -nfn k=0    s=1    f=2    i=./indat/dat1snfn.csv o=./outdat/out1qnfn.csv

${pfxc}m2cross      k=商品 s=日付 f=数量 fixfld=000 i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}m2cross -x   k=0    s=1    f=2  fixfld=000   i=./indat/dat1s.csv    o=./outdat/out2x.csv


#s=逆ソート f=2項目
${pfxc}m2cross      k=商品 s=日付%r f=数量 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}m2cross -x   k=0    s=1%r    f=2    i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}m2cross -nfn k=0    s=1%r    f=2    i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付%r f=数量 i=./indat/dat1s.csv    o=./outdat/out3nfno.csv

#s=数字ソート f=2項目
${pfxc}m2cross      k=商品 s=日付%n f=数量 i=./indat/dat1s.csv    o=./outdat/out5.csv
${pfxc}m2cross -x   k=0    s=1%n    f=2    i=./indat/dat1s.csv    o=./outdat/out5x.csv
${pfxc}m2cross -nfn k=0    s=1%n    f=2    i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv

#s=数字逆ソート f=2項目
${pfxc}m2cross      k=商品 s=日付%nr f=数量 i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}m2cross -x   k=0    s=1%nr    f=2    i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}m2cross -nfn k=0    s=1%nr    f=2    i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv


#ランダムデータ
#NULL
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat0.csv    o=./outdat/out31.csv
${pfxc}m2cross -x   k=0    s=1    f=2    i=./indat/dat0.csv    o=./outdat/out31x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2    i=./indat/dat0nfn.csv o=./outdat/out31nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat0.csv   o=./outdat/out31nfno.csv

#基本f=2項目
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat1.csv    o=./outdat/out32.csv
${pfxc}m2cross -x   k=0    s=1    f=2    i=./indat/dat1.csv    o=./outdat/out32x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2    i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat1.csv   o=./outdat/out32nfno.csv
${pfxc}m2cross -q     k=商品 s=日付 f=数量 i=./indat/dat1.csv    o=./outdat/out32q.csv
${pfxc}m2cross -q -nfn k=0    s=1    f=2    i=./indat/dat1nfn.csv o=./outdat/out32qnfn.csv

#s=逆ソート f=2項目
${pfxc}m2cross      k=商品 s=日付%r f=数量 i=./indat/dat1.csv    o=./outdat/out34.csv
${pfxc}m2cross -x   k=0    s=1%r    f=2    i=./indat/dat1.csv    o=./outdat/out34x.csv
${pfxc}m2cross -nfn k=0    s=1%r    f=2    i=./indat/dat1nfn.csv o=./outdat/out34nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付%r f=数量 i=./indat/dat1.csv    o=./outdat/out34nfno.csv

#s=数字ソート f=2項目
${pfxc}m2cross      k=商品 s=日付%n f=数量 i=./indat/dat1.csv    o=./outdat/out36.csv
${pfxc}m2cross -x   k=0    s=1%n    f=2    i=./indat/dat1.csv    o=./outdat/out36x.csv
${pfxc}m2cross -nfn k=0    s=1%n    f=2    i=./indat/dat1nfn.csv o=./outdat/out36nfn.csv


#s=数字逆ソート f=2項目
${pfxc}m2cross      k=商品 s=日付%nr f=数量 i=./indat/dat1.csv    o=./outdat/out38.csv
${pfxc}m2cross -x   k=0    s=1%nr    f=2    i=./indat/dat1.csv    o=./outdat/out38x.csv
${pfxc}m2cross -nfn k=0    s=1%nr    f=2    i=./indat/dat1nfn.csv o=./outdat/out38nfn.csv


# k=NULLデータを含む
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat4.csv    o=./outdat/out42.csv
${pfxc}m2cross -x   k=0    s=1    f=2       i=./indat/dat4.csv    o=./outdat/out42x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2       i=./indat/dat4nfn.csv o=./outdat/out42nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat4.csv    o=./outdat/out42nfno.csv

# s=にNULL
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat5.csv    o=./outdat/out43.csv
${pfxc}m2cross -x   k=0    s=1    f=2       i=./indat/dat5.csv    o=./outdat/out43x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2       i=./indat/dat5nfn.csv o=./outdat/out43nfn.csv

#f=にNULL
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat6.csv    o=./outdat/out44.csv
${pfxc}m2cross -x   k=0    s=1    f=2       i=./indat/dat6.csv    o=./outdat/out44x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2       i=./indat/dat6nfn.csv o=./outdat/out44nfn.csv

#いろいろNULL
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat7.csv    o=./outdat/out45.csv
${pfxc}m2cross -x   k=0    s=1    f=2       i=./indat/dat7.csv    o=./outdat/out45x.csv
${pfxc}m2cross -nfn k=0    s=1    f=2       i=./indat/dat7nfn.csv o=./outdat/out45nfn.csv
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat7.csv    o=./outdat/out45nfno.csv

#いろいろNULL v=null
${pfxc}m2cross      k=商品 s=日付 f=数量 i=./indat/dat7.csv    o=./outdat/out46.csv v=null
${pfxc}m2cross -x   k=0    s=1    f=2       i=./indat/dat7.csv    o=./outdat/out46x.csv v=null
${pfxc}m2cross -nfn k=0    s=1    f=2       i=./indat/dat7nfn.csv o=./outdat/out46nfn.csv v=null
${pfxc}m2cross -nfno k=商品 s=日付 f=数量 i=./indat/dat7.csv    o=./outdat/out46nfno.csv v=null

#逆cross
${pfxc}m2cross     a=head,数量 f=1,11,13,2 i=./indat/dat10.csv    o=./outdat/out100.csv 
${pfxc}m2cross     a=head,数量 f=2-5 -x i=./indat/dat10.csv    o=./outdat/out100x.csv 
${pfxc}m2cross     a=head,数量 f=2-5 -nfn i=./indat/dat10nfn.csv    o=./outdat/out100nfn.csv 

${pfxc}m2cross     a=head,数量 f=1,11,13,2 i=./indat/dat11.csv    o=./outdat/out101.csv 
${pfxc}m2cross     a=head,数量 f=2-5 -x i=./indat/dat11.csv    o=./outdat/out101x.csv 
${pfxc}m2cross     a=head,数量 f=2-5 -nfn i=./indat/dat11nfn.csv    o=./outdat/out101nfn.csv 

${pfxc}m2cross     a=head,数量 f=1,11,13,2 v=null i=./indat/dat11.csv    o=./outdat/out102.csv 
${pfxc}m2cross     a=head,数量 f=2-5 v=null -x i=./indat/dat11.csv    o=./outdat/out102x.csv 
${pfxc}m2cross     a=head,数量 f=2-5 v=null -nfn i=./indat/dat11nfn.csv    o=./outdat/out102nfn.csv 



