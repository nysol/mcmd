#!/bin/bash

. ../env

#name_kg_mcmd sep2

#NULL
mkdir -p ./outdat/sep0
mkdir -p ./outdat/sep0x
mkdir -p ./outdat/sep0nfn
${pfxc}msep2      k=商品 a=fileName O=./outdat/sep0    o=./outdat/tbl0.csv    i=./indat/dat0s.csv
${pfxc}msep2 -x   k=0    a=fileName O=./outdat/sep0x   o=./outdat/tbl0x.csv   i=./indat/dat0s.csv
${pfxc}msep2 -nfn k=0    a=fileName O=./outdat/sep0nfn o=./outdat/tbl0nfn.csv i=./indat/dat0snfn.csv

#基本
mkdir -p ./outdat/sep1
mkdir -p ./outdat/sep1x
mkdir -p ./outdat/sep1nfn
mkdir -p ./outdat/sep1q
mkdir -p ./outdat/sep1qx
${pfxc}msep2      k=日付 a=fileName O=./outdat/sep1    o=./outdat/tbl1.csv    i=./indat/dat1s.csv
${pfxc}msep2 -x   k=1    a=fileName O=./outdat/sep1x   o=./outdat/tbl1x.csv   i=./indat/dat1s.csv
${pfxc}msep2 -nfn k=1    a=fileName O=./outdat/sep1nfn o=./outdat/tbl1nfn.csv i=./indat/dat1snfn.csv
${pfxc}msep2 -q     k=日付 a=fileName O=./outdat/sep1q    o=./outdat/tbl1q.csv    i=./indat/dat1s.csv
${pfxc}msep2 -q -x   k=1    a=fileName O=./outdat/sep1qx   o=./outdat/tbl1qx.csv   i=./indat/dat1s.csv

mkdir -p ./outdat/sep2
mkdir -p ./outdat/sep2x
mkdir -p ./outdat/sep2nfn
${pfxc}msep2      k=商品,日付 a=fileName O=./outdat/sep2    o=./outdat/tbl2.csv    i=./indat/dat2s.csv
${pfxc}msep2 -x   k=0,1       a=fileName O=./outdat/sep2x   o=./outdat/tbl2x.csv   i=./indat/dat2s.csv
${pfxc}msep2 -nfn k=0,1       a=fileName O=./outdat/sep2nfn o=./outdat/tbl2nfn.csv i=./indat/dat2snfn.csv

#-p使用
${pfxc}msep2      -p k=商品,日付 a=fileName O=./outdat/sep3    o=./outdat/tbl3.csv    i=./indat/dat2s.csv
${pfxc}msep2 -x   -p k=0,1       a=fileName O=./outdat/sep3x   o=./outdat/tbl3x.csv   i=./indat/dat2s.csv
${pfxc}msep2 -nfn -p k=0,1       a=fileName O=./outdat/sep3nfn o=./outdat/tbl3nfn.csv i=./indat/dat2snfn.csv



#ランダムデータ
#基本
mkdir -p ./outdat/sep1r
mkdir -p ./outdat/sep1rx
mkdir -p ./outdat/sep1rnfn
${pfxc}msep2      k=日付 a=fileName O=./outdat/sep1r    o=./outdat/tbl1r.csv    i=./indat/dat1.csv
${pfxc}msep2 -x   k=1    a=fileName O=./outdat/sep1rx   o=./outdat/tbl1rx.csv   i=./indat/dat1.csv
${pfxc}msep2 -nfn k=1    a=fileName O=./outdat/sep1rnfn o=./outdat/tbl1rnfn.csv i=./indat/dat1nfn.csv
${pfxc}msep2 -q     k=日付 a=fileName O=./outdat/sep1rq    o=./outdat/tbl1rq.csv    i=./indat/dat1.csv
${pfxc}msep2 -q -x   k=1    a=fileName O=./outdat/sep1rqx   o=./outdat/tbl1rqx.csv   i=./indat/dat1.csv

mkdir -p ./outdat/sep2r
mkdir -p ./outdat/sep2rx
mkdir -p ./outdat/sep2rnfn
${pfxc}msep2      k=商品,日付 a=fileName O=./outdat/sep2r    o=./outdat/tbl2r.csv    i=./indat/dat2.csv
${pfxc}msep2 -x   k=0,1       a=fileName O=./outdat/sep2rx   o=./outdat/tbl2rx.csv   i=./indat/dat2.csv
${pfxc}msep2 -nfn k=0,1       a=fileName O=./outdat/sep2rnfn o=./outdat/tbl2rnfn.csv i=./indat/dat2nfn.csv

#-p使用
${pfxc}msep2      -p k=商品,日付 a=fileName O=./outdat/sep3r    o=./outdat/tbl3r.csv    i=./indat/dat2.csv
${pfxc}msep2 -x   -p k=0,1       a=fileName O=./outdat/sep3rx   o=./outdat/tbl3rx.csv   i=./indat/dat2.csv
${pfxc}msep2 -nfn -p k=0,1       a=fileName O=./outdat/sep3rnfn o=./outdat/tbl3rnfn.csv i=./indat/dat2nfn.csv

