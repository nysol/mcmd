#!/bin/bash

. ../env
#name_kg_mcmd duprec
#null data
${pfxc}mduprec      f=数量 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mduprec -x   f=1    i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mduprec -nfn f=1    i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mduprec -nfno f=数量 i=./indat/dat0.csv    o=./outdat/out0nfno.csv

#基本
${pfxc}mduprec      f=数量 i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mduprec -x   f=1    i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mduprec -nfn f=1    i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv
${pfxc}mduprec -nfno f=数量 i=./indat/dat1.csv    o=./outdat/out1nfno.csv

#f=のデータにNULL混在
${pfxc}mduprec      f=数量 i=./indat/dat2.csv    o=./outdat/out2.csv
${pfxc}mduprec -x   f=1    i=./indat/dat2.csv    o=./outdat/out2x.csv
${pfxc}mduprec -nfn f=1    i=./indat/dat2nfn.csv o=./outdat/out2nfn.csv
${pfxc}mduprec -nfno f=数量 i=./indat/dat2.csv    o=./outdat/out2nfno.csv

#n=3
${pfxc}mduprec       n=3  i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mduprec -x    n=3    i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mduprec -nfn  n=3    i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}mduprec -nfno n=3 i=./indat/dat1.csv    o=./outdat/out3nfno.csv

#ソートデータ
${pfxc}mduprec       n=3  i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mduprec -x    n=3  i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mduprec -nfn  n=3  i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv
