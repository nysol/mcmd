#!/bin/bash

. ../env

#name_kg_mcmd product

#直積結合
#NULL
${pfxc}mproduct      f=日付 m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mproduct -x   f=0    m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mproduct -nfn f=0    m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

${pfxc}mproduct      f=日付 m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out1.csv
${pfxc}mproduct -x   f=0    m=./indat/dat1.csv    i=./indat/dat2.csv    o=./outdat/out1x.csv
${pfxc}mproduct -nfn f=0    m=./indat/dat1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out1nfn.csv

${pfxc}mproduct      f=日付 m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out2.csv
${pfxc}mproduct -x   f=0    m=./indat/dat3.csv    i=./indat/dat0.csv    o=./outdat/out2x.csv
${pfxc}mproduct -nfn f=0    m=./indat/dat3nfn.csv i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

#基本
${pfxc}mproduct      f=日付 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out3.csv
${pfxc}mproduct -x   f=0    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out3x.csv
${pfxc}mproduct -nfn f=0    m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out3nfn.csv
${pfxc}mproduct -nfno f=日付 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out3nfno.csv

${pfxc}mproduct      f=日付,天気 m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out4.csv
${pfxc}mproduct -x   f=0,1       m=./indat/dat4.csv    i=./indat/dat2.csv    o=./outdat/out4x.csv
${pfxc}mproduct -nfn f=0,1       m=./indat/dat4nfn.csv i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv

#NULLあり
${pfxc}mproduct      f=日付,天気 m=./indat/dat4.csv    i=./indat/dat5.csv    o=./outdat/out5.csv
${pfxc}mproduct -x   f=0,1       m=./indat/dat4.csv    i=./indat/dat5.csv    o=./outdat/out5x.csv
${pfxc}mproduct -nfn f=0,1       m=./indat/dat4nfn.csv i=./indat/dat5nfn.csv o=./outdat/out5nfn.csv

${pfxc}mproduct      f=日付,天気 m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mproduct -x   f=0,1       m=./indat/dat6.csv    i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mproduct -nfn f=0,1       m=./indat/dat6nfn.csv i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

${pfxc}mproduct      f=日付,天気 m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out7.csv
${pfxc}mproduct -x   f=0,1       m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out7x.csv
${pfxc}mproduct -nfn f=0,1       m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out7nfn.csv

#bufcount
${pfxc}mproduct      f=日付 bufcount=2 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}mproduct      f=日付 bufcount=-2 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out9.csv


${pfxc}mproduct      m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out10.csv
${pfxc}mproduct -x   m=./indat/dat6.csv    i=./indat/dat5.csv    o=./outdat/out10x.csv
${pfxc}mproduct -nfn m=./indat/dat6nfn.csv i=./indat/dat5nfn.csv o=./outdat/out10nfn.csv

#sortデータ
${pfxc}mproduct      f=日付 m=./indat/dat3.csv    i=./indat/dat2s.csv    o=./outdat/out11.csv
