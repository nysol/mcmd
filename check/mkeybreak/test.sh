#!/bin/bash

. ../env

#name_kg_mcmd keybreak

#NULLデータ
${pfxc}mkeybreak       k=顧客 s=seq%n  i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mkeybreak -x    k=0   s=3%n i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mkeybreak -nfn  k=0   s=3%n i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mkeybreak -nfno k=顧客 s=seq%n i=./indat/dat0s.csv o=./outdat/out0nfno.csv

#基本
${pfxc}mkeybreak       k=顧客 s=seq%n i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mkeybreak -x    k=0   s=3%n i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mkeybreak -nfn  k=0   s=3%n i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mkeybreak -nfno k=顧客 s=seq%n i=./indat/dat1s.csv o=./outdat/out1nfno.csv
${pfxc}mkeybreak -q      k=顧客 i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}mkeybreak -q -nfn  k=0  i=./indat/dat1snfn.csv o=./outdat/out1qnfn.csv


#基本
${pfxc}mkeybreak       k=顧客 s=seq%n i=./indat/dat2s.csv    o=./outdat/out2.csv
${pfxc}mkeybreak -x    k=0   s=3%n i=./indat/dat2s.csv    o=./outdat/out2x.csv
${pfxc}mkeybreak -nfn  k=0   s=3%n i=./indat/dat2snfn.csv o=./outdat/out2nfn.csv
${pfxc}mkeybreak -nfno k=顧客 s=seq%n i=./indat/dat2s.csv o=./outdat/out2nfno.csv

${pfxc}mkeybreak       k=顧客 s=seq%n a=s,e  i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mkeybreak -x    k=0   s=3%n a=s,e  i=./indat/dat1s.csv    o=./outdat/out3x.csv

${pfxc}mkeybreak       k=顧客 s=seq%n a=s  i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mkeybreak       k=顧客 s=seq%n a=,e  i=./indat/dat1s.csv    o=./outdat/out5.csv


#ランダムデータ
${pfxc}mkeybreak       k=顧客 s=seq%n  i=./indat/dat0.csv    o=./outdat/out6.csv
${pfxc}mkeybreak -x    k=0   s=3%n i=./indat/dat0.csv    o=./outdat/out6x.csv
${pfxc}mkeybreak -nfn  k=0   s=3%n i=./indat/dat0nfn.csv o=./outdat/out6nfn.csv
${pfxc}mkeybreak -nfno k=顧客  s=seq%n i=./indat/dat0.csv o=./outdat/out6nfno.csv

#基本
${pfxc}mkeybreak       k=顧客 s=seq%n i=./indat/dat1.csv    o=./outdat/out7.csv
${pfxc}mkeybreak -x    k=0   s=3%n i=./indat/dat1.csv    o=./outdat/out7x.csv
${pfxc}mkeybreak -nfn  k=0   s=3%n i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv
${pfxc}mkeybreak -nfno k=顧客 s=seq%n i=./indat/dat1.csv o=./outdat/out7nfno.csv
${pfxc}mkeybreak -q      k=顧客 s=seq%n i=./indat/dat1.csv    o=./outdat/out7q.csv
${pfxc}mkeybreak -q -nfn  k=0   s=3%n i=./indat/dat1nfn.csv o=./outdat/out7qnfn.csv


#基本
${pfxc}mkeybreak       k=顧客 s=seq%n i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}mkeybreak -x    k=0   s=3%n i=./indat/dat2.csv    o=./outdat/out8x.csv
${pfxc}mkeybreak -nfn  k=0   s=3%n i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv
${pfxc}mkeybreak -nfno k=顧客 s=seq%n i=./indat/dat2.csv o=./outdat/out8nfno.csv

${pfxc}mkeybreak       k=顧客 s=seq%n a=s,e  i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}mkeybreak -x    k=0   s=3%n a=s,e  i=./indat/dat1.csv    o=./outdat/out9x.csv

${pfxc}mkeybreak       k=顧客 s=seq%n a=s  i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mkeybreak       k=顧客 s=seq%n a=,e  i=./indat/dat1.csv    o=./outdat/out11.csv
