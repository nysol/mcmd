#!/usr/bin/env bash

. ../env

#name_kg_mcmd tonull

#空データ
${pfxc}mtonull      f=数量,金額 v=0   i=./indat/dat0.csv    o=./outdat/out01.csv
${pfxc}mtonull -x   f=1,2       v=0   i=./indat/dat0.csv    o=./outdat/out01x.csv
${pfxc}mtonull -nfn f=1,2       v=0   i=./indat/dat0nfn.csv o=./outdat/out01nfn.csv

#基本
${pfxc}mtonull      f=数量,金額 v=0   i=./indat/dat1.csv    o=./outdat/out02.csv
${pfxc}mtonull -x   f=1,2       v=0   i=./indat/dat1.csv    o=./outdat/out02x.csv
${pfxc}mtonull -nfn f=1,2       v=0   i=./indat/dat1nfn.csv o=./outdat/out02nfn.csv

${pfxc}mtonull      f=数量,金額 v=0,1 i=./indat/dat1.csv    o=./outdat/out03.csv
${pfxc}mtonull -x   f=1,2       v=0,1 i=./indat/dat1.csv    o=./outdat/out03x.csv
${pfxc}mtonull -nfn f=1,2       v=0,1 i=./indat/dat1nfn.csv o=./outdat/out03nfn.csv

#部分マッチ
${pfxc}mtonull      f=数量,金額 v=0 -sub i=./indat/dat1.csv    o=./outdat/out04.csv
${pfxc}mtonull -x   f=1,2       v=0 -sub i=./indat/dat1.csv    o=./outdat/out04x.csv
${pfxc}mtonull -nfn f=1,2       v=0 -sub i=./indat/dat1nfn.csv o=./outdat/out04nfn.csv

#漢字部分マッチ with -w
${pfxc}mtonull      f=商品 v='柿,苺,梨' -sub -W i=./indat/dat2.csv    o=./outdat/out05.csv
${pfxc}mtonull -x   f=0    v='柿,苺,梨' -sub -W i=./indat/dat2.csv    o=./outdat/out05x.csv
${pfxc}mtonull -nfn f=0    v='柿,苺,梨' -sub -W i=./indat/dat2nfn.csv o=./outdat/out05nfn.csv

#漢字部分マッチ
${pfxc}mtonull      f=商品 v='柿,苺,梨' -sub i=./indat/dat2.csv    o=./outdat/out06.csv
${pfxc}mtonull -x   f=0    v='柿,苺,梨' -sub i=./indat/dat2.csv    o=./outdat/out06x.csv
${pfxc}mtonull -nfn f=0    v='柿,苺,梨' -sub i=./indat/dat2nfn.csv o=./outdat/out06nfn.csv


#ソートデータ
${pfxc}mtonull      f=数量,金額 v=0   i=./indat/dat1s.csv    o=./outdat/out12.csv
${pfxc}mtonull -x   f=1,2       v=0   i=./indat/dat1s.csv    o=./outdat/out12x.csv
${pfxc}mtonull -nfn f=1,2       v=0   i=./indat/dat1snfn.csv o=./outdat/out12nfn.csv
