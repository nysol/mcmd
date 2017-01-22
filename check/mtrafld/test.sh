#!/bin/bash

. ../env

#name_kg_mcmd trafld

#基本
${pfxc}mtrafld      i=./indat/dat0.csv    f=金額,数量 a=トランザクション o=./outdat/out01.csv
${pfxc}mtrafld -x   i=./indat/dat0.csv    f=1,2       a=トランザクション o=./outdat/out01x.csv
${pfxc}mtrafld -nfn i=./indat/dat0nfn.csv f=1,2                          o=./outdat/out01nfn.csv

${pfxc}mtrafld      i=./indat/dat1.csv    f=金額,数量 a=トランザクション o=./outdat/out02.csv
${pfxc}mtrafld -x   i=./indat/dat1.csv    f=1,2       a=トランザクション o=./outdat/out02x.csv
${pfxc}mtrafld -nfn i=./indat/dat1nfn.csv f=1,2                          o=./outdat/out02nfn.csv

${pfxc}mtrafld      i=./indat/dat1.csv    f=数量,金額 a=トランザクション o=./outdat/out03.csv
${pfxc}mtrafld -x   i=./indat/dat1.csv    f=2,1       a=トランザクション o=./outdat/out03x.csv
${pfxc}mtrafld -nfn i=./indat/dat1nfn.csv f=2,1       a=トランザクション o=./outdat/out03nfn.csv

#-r
${pfxc}mtrafld      -r i=./indat/dat2.csv    f=金額,数量 a=トランザクション o=./outdat/out04.csv
${pfxc}mtrafld -x   -r i=./indat/dat2.csv    f=金額,数量 a=1                o=./outdat/out04x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat2nfn.csv f=金額,数量 a=1                o=./outdat/out04nfn.csv

${pfxc}mtrafld      -r i=./indat/dat3.csv    f=金額,数量 a=トランザクション o=./outdat/out05.csv
${pfxc}mtrafld -x   -r i=./indat/dat3.csv    f=金額,数量 a=1               o=./outdat/out05x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat3nfn.csv f=金額,数量 a=1                o=./outdat/out05nfn.csv

${pfxc}mtrafld      -r i=./indat/dat3.csv    f=数量,金額 a=トランザクション o=./outdat/out06.csv
${pfxc}mtrafld -x   -r i=./indat/dat3.csv    f=数量,金額 a=1                o=./outdat/out06x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat3nfn.csv f=数量,金額 a=1                o=./outdat/out06nfn.csv

${pfxc}mtrafld      -r i=./indat/dat3.csv    a=トランザクション o=./outdat/out07.csv
${pfxc}mtrafld -x   -r i=./indat/dat3.csv    a=1                o=./outdat/out07x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat3nfn.csv a=1                o=./outdat/out07nfn.csv

#NULLを含むデータ
${pfxc}mtrafld      i=./indat/dat4.csv    f=金額,数量 a=トランザクション o=./outdat/out08.csv
${pfxc}mtrafld -x   i=./indat/dat4.csv    f=1,2       a=トランザクション o=./outdat/out08x.csv
${pfxc}mtrafld -nfn i=./indat/dat4nfn.csv f=1,2       a=トランザクション o=./outdat/out08nfn.csv

${pfxc}mtrafld      -r i=./indat/dat5.csv    f=金額,数量 a=トランザクション o=./outdat/out09.csv
${pfxc}mtrafld -x   -r i=./indat/dat5.csv    f=金額,数量 a=1                o=./outdat/out09x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat5nfn.csv f=金額,数量 a=1                o=./outdat/out09nfn.csv

${pfxc}mtrafld      -r i=./indat/dat5.csv    a=トランザクション o=./outdat/out10.csv
${pfxc}mtrafld -x   -r i=./indat/dat5.csv    a=1                o=./outdat/out10x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat5nfn.csv a=1                o=./outdat/out10nfn.csv

#delimitor指定
${pfxc}mtrafld      i=./indat/dat1.csv    f=金額,数量 a=トランザクション delim=_ delim2=':' o=./outdat/out11.csv
${pfxc}mtrafld -x   i=./indat/dat1.csv    f=1,2       a=トランザクション delim=_ delim2=':' o=./outdat/out11x.csv
${pfxc}mtrafld -nfn i=./indat/dat1nfn.csv f=1,2       a=トランザクション delim=_ delim2=':' o=./outdat/out11nfn.csv

# -valOnly
${pfxc}mtrafld      i=./indat/dat1.csv    f=金額,数量 a=トランザクション -valOnly o=./outdat/out12.csv
${pfxc}mtrafld -x   i=./indat/dat1.csv    f=1,2       a=トランザクション -valOnly o=./outdat/out12x.csv
${pfxc}mtrafld -nfn i=./indat/dat1nfn.csv f=1,2                          -valOnly o=./outdat/out12nfn.csv



#ソートデータ
${pfxc}mtrafld      i=./indat/dat1s.csv    f=金額,数量 a=トランザクション o=./outdat/out13.csv
${pfxc}mtrafld -x   i=./indat/dat1s.csv    f=1,2       a=トランザクション o=./outdat/out13x.csv
${pfxc}mtrafld -nfn i=./indat/dat1snfn.csv f=1,2                          o=./outdat/out13nfn.csv

${pfxc}mtrafld      -r i=./indat/dat3s.csv    f=金額,数量 a=トランザクション o=./outdat/out14.csv
${pfxc}mtrafld -x   -r i=./indat/dat3s.csv    f=金額,数量 a=1               o=./outdat/out14x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat3snfn.csv f=金額,数量 a=1                o=./outdat/out14nfn.csv

${pfxc}mtrafld      -r i=./indat/dat3.csv    a=トランザクション o=./outdat/out15.csv
${pfxc}mtrafld -x   -r i=./indat/dat3.csv    a=1                o=./outdat/out15x.csv
${pfxc}mtrafld -nfn -r i=./indat/dat3nfn.csv a=1                o=./outdat/out15nfn.csv
