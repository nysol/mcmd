#!/bin/bash

. ../env

#name_kg_mcmd tra



#基本
${pfxc}mtra      k=顧客 f=商品:トランザクション i=./indat/dat0s.csv    o=./outdat/out01.csv
${pfxc}mtra -x   k=0    f=1:トランザクション    i=./indat/dat0s.csv    o=./outdat/out01x.csv
${pfxc}mtra -nfn k=0    f=1:トランザクション    i=./indat/dat0snfn.csv o=./outdat/out01nfn.csv

${pfxc}mtra      k=顧客 f=商品:トランザクション i=./indat/dat1s.csv    o=./outdat/out02.csv
${pfxc}mtra -x   k=0    f=1:トランザクション    i=./indat/dat1s.csv    o=./outdat/out02x.csv
${pfxc}mtra -nfn k=0    f=1:トランザクション    i=./indat/dat1snfn.csv o=./outdat/out02nfn.csv
${pfxc}mtra -q     k=顧客 f=商品:トランザクション i=./indat/dat1s.csv    o=./outdat/out02q.csv
${pfxc}mtra -q -x   k=0    f=1:トランザクション    i=./indat/dat1s.csv    o=./outdat/out02qx.csv

#-r
${pfxc}mtra      -r f=トランザクション:商品 i=./indat/dat2s.csv o=./outdat/out03.csv
${pfxc}mtra -x   -r f=1:商品 i=./indat/dat2s.csv                o=./outdat/out03x.csv
${pfxc}mtra -nfn -r f=1:商品 i=./indat/dat2snfn.csv             o=./outdat/out03nfn.csv

${pfxc}mtra      -r f=トランザクション:商品 i=./indat/dat3s.csv o=./outdat/out04.csv
${pfxc}mtra -x   -r f=1:商品 i=./indat/dat3s.csv                o=./outdat/out04x.csv
${pfxc}mtra -nfn -r f=1:商品 i=./indat/dat3snfn.csv             o=./outdat/out04nfn.csv

#NULLを含むデータ
${pfxc}mtra      k=顧客 f=商品:トランザクション i=./indat/dat4s.csv    o=./outdat/out05.csv
${pfxc}mtra -x   k=0    f=1:トランザクション    i=./indat/dat4s.csv    o=./outdat/out05x.csv
${pfxc}mtra -nfn k=0    f=1:トランザクション    i=./indat/dat4snfn.csv o=./outdat/out05nfn.csv

${pfxc}mtra      -r f=商品:トランザクション i=./indat/dat4s.csv o=./outdat/out08.csv

#delimitor指定
${pfxc}mtra      delim=- k=顧客 f=商品:トランザクション i=./indat/dat1s.csv    o=./outdat/out06.csv
${pfxc}mtra -x   delim=- k=0    f=1:トランザクション    i=./indat/dat1s.csv    o=./outdat/out06x.csv
${pfxc}mtra -nfn delim=- k=0    f=1:トランザクション    i=./indat/dat1snfn.csv o=./outdat/out06nfn.csv
${pfxc}mtra      delim=, k=顧客 f=商品:トランザクション i=./indat/dat1s.csv    o=./outdat/out07.csv


#基本
${pfxc}mtra      k=顧客 f=商品:トランザクション i=./indat/dat0.csv    o=./outdat/out11.csv
${pfxc}mtra -x   k=0    f=1:トランザクション    i=./indat/dat0.csv    o=./outdat/out11x.csv
${pfxc}mtra -nfn k=0    f=1:トランザクション    i=./indat/dat0nfn.csv o=./outdat/out11nfn.csv

${pfxc}mtra      k=顧客 f=商品:トランザクション i=./indat/dat1.csv    o=./outdat/out12.csv
${pfxc}mtra -x   k=0    f=1:トランザクション    i=./indat/dat1.csv    o=./outdat/out12x.csv
${pfxc}mtra -nfn k=0    f=1:トランザクション    i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv
${pfxc}mtra -q     k=顧客 f=商品:トランザクション i=./indat/dat1.csv    o=./outdat/out12q.csv
${pfxc}mtra -q -x   k=0    f=1:トランザクション    i=./indat/dat1.csv    o=./outdat/out12qx.csv

#-r
${pfxc}mtra      -r f=トランザクション:商品 i=./indat/dat2.csv o=./outdat/out13.csv
${pfxc}mtra -x   -r f=1:商品 i=./indat/dat2.csv                o=./outdat/out13x.csv
${pfxc}mtra -nfn -r f=1:商品 i=./indat/dat2nfn.csv             o=./outdat/out13nfn.csv

${pfxc}mtra      -r f=トランザクション:商品 i=./indat/dat3.csv o=./outdat/out14.csv
${pfxc}mtra -x   -r f=1:商品 i=./indat/dat3.csv                o=./outdat/out14x.csv
${pfxc}mtra -nfn -r f=1:商品 i=./indat/dat3nfn.csv             o=./outdat/out14nfn.csv

#NULLを含むデータ
${pfxc}mtra      k=顧客 f=商品:トランザクション i=./indat/dat4.csv    o=./outdat/out15.csv
${pfxc}mtra -x   k=0    f=1:トランザクション    i=./indat/dat4.csv    o=./outdat/out15x.csv
${pfxc}mtra -nfn k=0    f=1:トランザクション    i=./indat/dat4nfn.csv o=./outdat/out15nfn.csv

${pfxc}mtra      -r f=商品:トランザクション i=./indat/dat4.csv o=./outdat/out18.csv

#delimitor指定
${pfxc}mtra      delim=- k=顧客 f=商品:トランザクション i=./indat/dat1.csv    o=./outdat/out16.csv
${pfxc}mtra -x   delim=- k=0    f=1:トランザクション    i=./indat/dat1.csv    o=./outdat/out16x.csv
${pfxc}mtra -nfn delim=- k=0    f=1:トランザクション    i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv
${pfxc}mtra      delim=, k=顧客 f=商品:トランザクション i=./indat/dat1.csv    o=./outdat/out17.csv



