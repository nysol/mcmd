#!/bin/bash

. ../env

#name_kg_mcmd traflg

${pfxc}mtraflg      f=来店,購入 a=トランザクション i=./indat/dat0.csv    o=./outdat/out00.csv
${pfxc}mtraflg -x   f=1,2       a=トランザクション i=./indat/dat0.csv    o=./outdat/out00x.csv
${pfxc}mtraflg -nfn f=1,2                          i=./indat/dat0nfn.csv o=./outdat/out00nfn.csv

#基本
${pfxc}mtraflg      f=来店,購入 a=トランザクション i=./indat/dat1.csv    o=./outdat/out01.csv
${pfxc}mtraflg -x   f=1,2       a=トランザクション i=./indat/dat1.csv    o=./outdat/out01x.csv
${pfxc}mtraflg -nfn f=1,2                          i=./indat/dat1nfn.csv o=./outdat/out01nfn.csv

${pfxc}mtraflg      -r f=来店,購入 a=トランザクション i=./indat/dat2.csv    o=./outdat/out02.csv
${pfxc}mtraflg -x   -r f=来店,購入 a=1                i=./indat/dat2.csv    o=./outdat/out02x.csv
${pfxc}mtraflg -nfn -r f=来店,購入 a=1                i=./indat/dat2nfn.csv o=./outdat/out02nfn.csv

#区切り文字指定
${pfxc}mtraflg      delim=- f=来店,購入 a=トランザクション i=./indat/dat1.csv    o=./outdat/out03.csv
${pfxc}mtraflg -x   delim=- f=1,2       a=トランザクション i=./indat/dat1.csv    o=./outdat/out03x.csv
${pfxc}mtraflg -nfn delim=- f=1,2                          i=./indat/dat1nfn.csv o=./outdat/out03nfn.csv



${pfxc}mtraflg      f=来店,購入 a=トランザクション i=./indat/dat1s.csv    o=./outdat/out04.csv
${pfxc}mtraflg -x   f=1,2       a=トランザクション i=./indat/dat1s.csv    o=./outdat/out04x.csv
${pfxc}mtraflg -nfn f=1,2                          i=./indat/dat1snfn.csv o=./outdat/out04nfn.csv

${pfxc}mtraflg      -r f=来店,購入 a=トランザクション i=./indat/dat2s.csv    o=./outdat/out05.csv
${pfxc}mtraflg -x   -r f=来店,購入 a=1                i=./indat/dat2s.csv    o=./outdat/out05x.csv
${pfxc}mtraflg -nfn -r f=来店,購入 a=1                i=./indat/dat2snfn.csv o=./outdat/out05nfn.csv
