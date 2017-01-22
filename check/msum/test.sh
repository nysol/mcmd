#!/bin/bash

. ../env

#name_kg_mcmd sum

${pfxc}msum      k=顧客 f=数量,金額 i=./indat/dat0s.csv    o=./outdat/out01.csv
${pfxc}msum -x   k=0    f=1,2       i=./indat/dat0s.csv    o=./outdat/out01x.csv
${pfxc}msum -nfn k=0    f=1,2       i=./indat/dat0snfn.csv o=./outdat/out01nfn.csv

${pfxc}msum      k=顧客 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out02.csv
${pfxc}msum -x   k=0    f=1,2       i=./indat/dat1s.csv    o=./outdat/out02x.csv
${pfxc}msum -nfn k=0    f=1,2       i=./indat/dat1snfn.csv o=./outdat/out02nfn.csv
${pfxc}msum -q     k=顧客 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out02q.csv
${pfxc}msum -q -x   k=0    f=1,2       i=./indat/dat1s.csv    o=./outdat/out02qx.csv


${pfxc}msum      k=顧客 f=金額,数量 i=./indat/dat1s.csv    o=./outdat/out03.csv
${pfxc}msum -x   k=0    f=2,1       i=./indat/dat1s.csv    o=./outdat/out03x.csv
${pfxc}msum -nfn k=0    f=2,1       i=./indat/dat1snfn.csv o=./outdat/out03nfn.csv

${pfxc}msum      f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out04.csv
${pfxc}msum -x   f=1,2       i=./indat/dat1s.csv    o=./outdat/out04x.csv
${pfxc}msum -nfn f=1,2       i=./indat/dat1snfn.csv o=./outdat/out04nfn.csv

#null混在データ
${pfxc}msum      k=顧客 f=数量,金額 i=./indat/dat2s.csv    o=./outdat/out05.csv
${pfxc}msum -x   k=0    f=1,2       i=./indat/dat2s.csv    o=./outdat/out05x.csv
${pfxc}msum -nfn k=0    f=1,2       i=./indat/dat2snfn.csv o=./outdat/out05nfn.csv

${pfxc}msum      f=数量,金額 i=./indat/dat2s.csv    o=./outdat/out06.csv
${pfxc}msum -x   f=1,2       i=./indat/dat2s.csv    o=./outdat/out06x.csv
${pfxc}msum -nfn f=1,2       i=./indat/dat2snfn.csv o=./outdat/out06nfn.csv

#null混在データ with -n
${pfxc}msum      -n k=顧客 f=数量,金額 i=./indat/dat2s.csv    o=./outdat/out07.csv
${pfxc}msum -x   -n k=0    f=1,2       i=./indat/dat2s.csv    o=./outdat/out07x.csv
${pfxc}msum -nfn -n k=0    f=1,2       i=./indat/dat2snfn.csv o=./outdat/out07nfn.csv

${pfxc}msum      -n f=数量,金額 i=./indat/dat2s.csv    o=./outdat/out08.csv
${pfxc}msum -x   -n f=1,2       i=./indat/dat2s.csv    o=./outdat/out08x.csv
${pfxc}msum -nfn -n f=1,2       i=./indat/dat2snfn.csv o=./outdat/out08nfn.csv


# ランダムデータ
${pfxc}msum      k=顧客 f=数量,金額 i=./indat/dat0.csv    o=./outdat/out51.csv
${pfxc}msum -x   k=0    f=1,2       i=./indat/dat0.csv    o=./outdat/out51x.csv
${pfxc}msum -nfn k=0    f=1,2       i=./indat/dat0nfn.csv o=./outdat/out51nfn.csv

${pfxc}msum      k=顧客 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out52.csv
${pfxc}msum -x   k=0    f=1,2       i=./indat/dat1.csv    o=./outdat/out52x.csv
${pfxc}msum -nfn k=0    f=1,2       i=./indat/dat1nfn.csv o=./outdat/out52nfn.csv
${pfxc}msum -q     k=顧客 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out52q.csv
${pfxc}msum -q -x   k=0    f=1,2       i=./indat/dat1.csv    o=./outdat/out52qx.csv

${pfxc}msum      k=顧客 f=金額,数量 i=./indat/dat1.csv    o=./outdat/out53.csv
${pfxc}msum -x   k=0    f=2,1       i=./indat/dat1.csv    o=./outdat/out53x.csv
${pfxc}msum -nfn k=0    f=2,1       i=./indat/dat1nfn.csv o=./outdat/out53nfn.csv

${pfxc}msum      k=顧客 f=数量,金額 i=./indat/dat2.csv    o=./outdat/out55.csv
${pfxc}msum -x   k=0    f=1,2       i=./indat/dat2.csv    o=./outdat/out55x.csv
${pfxc}msum -nfn k=0    f=1,2       i=./indat/dat2nfn.csv o=./outdat/out55nfn.csv

#null混在データ with -n
${pfxc}msum      -n k=顧客 f=数量,金額 i=./indat/dat2.csv    o=./outdat/out57.csv
${pfxc}msum -x   -n k=0    f=1,2       i=./indat/dat2.csv    o=./outdat/out57x.csv
${pfxc}msum -nfn -n k=0    f=1,2       i=./indat/dat2nfn.csv o=./outdat/out57nfn.csv
