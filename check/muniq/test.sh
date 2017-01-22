#!/bin/bash

. ../env

#name_kg_mcmd uniq

#null data 日付毎にUNIQ
${pfxc}muniq       k=日付  i=./indat/dat0s.csv o=./outdat/out1.csv
${pfxc}muniq -x    k=0     i=./indat/dat0s.csv o=./outdat/out1x.csv
${pfxc}muniq -nfn  k=0     i=./indat/dat0snfn.csv o=./outdat/out1nfn.csv
${pfxc}muniq -nfno k=日付  i=./indat/dat0s.csv o=./outdat/out1nfno.csv

#nulldata 日付+顧客でUNIQ
${pfxc}muniq   k=日付,顧客  i=./indat/dat0s.csv o=./outdat/out2.csv

#日付毎にUNIQ
${pfxc}muniq       k=日付  i=./indat/dat1s.csv o=./outdat/out3.csv
${pfxc}muniq -x    k=0     i=./indat/dat1s.csv o=./outdat/out3x.csv
${pfxc}muniq -nfn  k=0     i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}muniq -nfno k=日付  i=./indat/dat1s.csv o=./outdat/out3nfno.csv

#日付+顧客でUNIQ
${pfxc}muniq       k=日付,顧客  i=./indat/dat1s.csv o=./outdat/out4.csv
${pfxc}muniq -x    k=0,1        i=./indat/dat1s.csv o=./outdat/out4x.csv
${pfxc}muniq -nfn  k=0,1        i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv
${pfxc}muniq -nfno k=日付,顧客  i=./indat/dat1s.csv o=./outdat/out4nfno.csv

#nullを部分的に含むデータ 日付毎にUNIQ
${pfxc}muniq       k=日付 i=./indat/dat2s.csv o=./outdat/out5.csv
${pfxc}muniq -x    k=0    i=./indat/dat2s.csv o=./outdat/out5x.csv
${pfxc}muniq -nfn  k=0    i=./indat/dat2snfn.csv o=./outdat/out5nfn.csv
${pfxc}muniq -nfno k=日付 i=./indat/dat2s.csv o=./outdat/out5nfno.csv

#nullを部分的に含むデータ 日付+顧客でUNIQ
${pfxc}muniq       k=日付,顧客  i=./indat/dat2s.csv o=./outdat/out6.csv
${pfxc}muniq -x    k=0,1        i=./indat/dat2s.csv o=./outdat/out6x.csv
${pfxc}muniq -nfn  k=0,1        i=./indat/dat2snfn.csv o=./outdat/out6nfn.csv
${pfxc}muniq -nfno k=日付,顧客  i=./indat/dat2s.csv o=./outdat/out6nfno.csv

#nullを部分的に含むデータ 顧客毎にUNIQ
${pfxc}muniq       k=顧客 i=./indat/dat2s.csv o=./outdat/out7.csv
${pfxc}muniq -x    k=1    i=./indat/dat2s.csv o=./outdat/out7x.csv
${pfxc}muniq -nfn  k=1    i=./indat/dat2snfn.csv o=./outdat/out7nfn.csv
${pfxc}muniq -nfno k=顧客 i=./indat/dat2s.csv o=./outdat/out7nfno.csv



#ランダムデータ
#null data 日付毎にUNIQ
${pfxc}muniq       k=日付  i=./indat/dat0.csv o=./outdat/out11.csv
${pfxc}muniq -x    k=0     i=./indat/dat0.csv o=./outdat/out11x.csv
${pfxc}muniq -nfn  k=0     i=./indat/dat0nfn.csv o=./outdat/out11nfn.csv
${pfxc}muniq -nfno k=日付  i=./indat/dat0.csv o=./outdat/out11nfno.csv

#nulldata 日付+顧客でUNIQ
${pfxc}muniq   k=日付,顧客  i=./indat/dat0.csv o=./outdat/out12.csv

#日付毎にUNIQ
${pfxc}muniq       k=日付  i=./indat/dat1.csv o=./outdat/out13.csv
${pfxc}muniq -x    k=0     i=./indat/dat1.csv o=./outdat/out13x.csv
${pfxc}muniq -nfn  k=0     i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv
${pfxc}muniq -nfno k=日付  i=./indat/dat1.csv o=./outdat/out13nfno.csv

#日付+顧客でUNIQ
${pfxc}muniq       k=日付,顧客  i=./indat/dat1.csv o=./outdat/out14.csv
${pfxc}muniq -x    k=0,1        i=./indat/dat1.csv o=./outdat/out14x.csv
${pfxc}muniq -nfn  k=0,1        i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv
${pfxc}muniq -nfno k=日付,顧客  i=./indat/dat1.csv o=./outdat/out14nfno.csv

#nullを部分的に含むデータ 日付毎にUNIQ
${pfxc}muniq       k=日付 i=./indat/dat2.csv o=./outdat/out15.csv
${pfxc}muniq -x    k=0    i=./indat/dat2.csv o=./outdat/out15x.csv
${pfxc}muniq -nfn  k=0    i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv
${pfxc}muniq -nfno k=日付 i=./indat/dat2.csv o=./outdat/out15nfno.csv

#nullを部分的に含むデータ 日付+顧客でUNIQ
${pfxc}muniq       k=日付,顧客  i=./indat/dat2.csv o=./outdat/out16.csv
${pfxc}muniq -x    k=0,1        i=./indat/dat2.csv o=./outdat/out16x.csv
${pfxc}muniq -nfn  k=0,1        i=./indat/dat2nfn.csv o=./outdat/out16nfn.csv
${pfxc}muniq -nfno k=日付,顧客  i=./indat/dat2.csv o=./outdat/out16nfno.csv

#nullを部分的に含むデータ 顧客毎にUNIQ
${pfxc}muniq       k=顧客 i=./indat/dat2.csv o=./outdat/out17.csv
${pfxc}muniq -x    k=1    i=./indat/dat2.csv o=./outdat/out17x.csv
${pfxc}muniq -nfn  k=1    i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv
${pfxc}muniq -nfno k=顧客 i=./indat/dat2.csv o=./outdat/out17nfno.csv

