#!/bin/bash

. ../env
#name_kg_mcmd cut

#null data
${pfxc}mcut      f=顧客 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mcut -x   f=0    i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mcut -nfn f=0    i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#f=1つ
${pfxc}mcut      f=顧客 i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mcut -x   f=0    i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mcut -nfn f=0    i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

#f=2つ
${pfxc}mcut      f=顧客,数量 i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mcut -x   f=0,1       i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mcut -nfn f=0,1       i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

#-r,f=1つ
${pfxc}mcut      f=顧客 -r i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mcut -x   f=0    -r i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mcut -nfn f=0    -r i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

#-r,f=2つ
${pfxc}mcut      f=顧客,数量 -r i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}mcut -x   f=0,1       -r i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}mcut -nfn f=0,1       -r i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

#部分的にNULL
${pfxc}mcut      f=顧客,数量 i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mcut -x   f=0,1       i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mcut -nfn f=0,1       i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv

${pfxc}mcut      f=顧客,数量 -r i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mcut -x   f=0,1       -r i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mcut -nfn f=0,1       -r i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

#項目付加
${pfxc}mcut f=0:顧客,1:個数 -nfni i=./indat/dat3.csv o=./outdat/out7.csv
${pfxc}mcut f=0,1 -nfni i=./indat/dat3.csv o=./outdat/out47.csv
${pfxc}mcut f=0,2 -nfni -nfno i=./indat/dat3.csv o=./outdat/out48.csv

#項目ありデータを項目番号でアクセス&項目名変更
${pfxc}mcut f=0:お客さん,1:個数 -x i=./indat/dat1.csv o=./outdat/out8.csv

#項目付加でNULLデータ
#${pfxc}mcut f=1:顧客,2:個数 -nfni i=./indat/dat4.csv o=./outdat/out8.csv

#項目番号指定のルールについてチェックする
#NULL Data
${pfxc}mcut -x f=0-2 i=./indat/dat0.csv o=./outdat/out9x.csv

#-を使った複数指定
${pfxc}mcut -x f=0-2 i=./indat/dat1.csv o=./outdat/out10x.csv
${pfxc}mcut -x f=1-2 i=./indat/dat1.csv o=./outdat/out11x.csv

#-を使った複数指定(項目名逆順指定)
${pfxc}mcut -x f=2-0 i=./indat/dat1.csv o=./outdat/out12x.csv
${pfxc}mcut -x f=2-1 i=./indat/dat1.csv o=./outdat/out13x.csv

#複数項目の-を使った複数指定
${pfxc}mcut -x f=1-0,3-4 i=./indat/dat6.csv o=./outdat/out21x.csv

#基本指定と複数項目指定
${pfxc}mcut -x f=1,3-4 i=./indat/dat6.csv o=./outdat/out22x.csv
${pfxc}mcut -x f=1,4-3 i=./indat/dat6.csv o=./outdat/out23x.csv
${pfxc}mcut -x f=0-2,4 i=./indat/dat6.csv o=./outdat/out24x.csv
${pfxc}mcut -x f=2-0,4 i=./indat/dat6.csv o=./outdat/out25x.csv

#Lによる指定
${pfxc}mcut -x f=0L i=./indat/dat1.csv o=./outdat/out14x.csv
${pfxc}mcut -x f=1L i=./indat/dat1.csv o=./outdat/out15x.csv
${pfxc}mcut -x f=2L i=./indat/dat1.csv o=./outdat/out16x.csv

#Lによる指定と複数指定
${pfxc}mcut -x f=0L,1-2 i=./indat/dat6.csv o=./outdat/out26x.csv
${pfxc}mcut -x f=0-1,1L i=./indat/dat6.csv o=./outdat/out27x.csv
${pfxc}mcut -x f=0-1L   i=./indat/dat1.csv o=./outdat/out17x.csv
${pfxc}mcut -x f=1L-0   i=./indat/dat1.csv o=./outdat/out18x.csv
${pfxc}mcut -x f=0L-1L  i=./indat/dat1.csv o=./outdat/out19x.csv
${pfxc}mcut -x f=1L-0L  i=./indat/dat1.csv o=./outdat/out20x.csv

#ワイルドカード指定
#NULL Data
${pfxc}mcut f="数量*" i=./indat/dat5.csv o=./outdat/out21.csv
${pfxc}mcut f="数量0?" i=./indat/dat5.csv o=./outdat/out22.csv
${pfxc}mcut f=顧客,"数量*" i=./indat/dat5.csv o=./outdat/out23.csv
${pfxc}mcut f="数量*",顧客 i=./indat/dat5.csv o=./outdat/out24.csv
${pfxc}mcut f=顧客,"数量0?" i=./indat/dat5.csv o=./outdat/out25.csv
${pfxc}mcut f="数量0?",顧客 i=./indat/dat5.csv o=./outdat/out26.csv

#基本
${pfxc}mcut f="数量*" i=./indat/dat6.csv o=./outdat/out27.csv
${pfxc}mcut f="数量0?" i=./indat/dat6.csv o=./outdat/out28.csv
${pfxc}mcut f=顧客,"数量*" i=./indat/dat6.csv o=./outdat/out29.csv
${pfxc}mcut f="数量*",顧客 i=./indat/dat6.csv o=./outdat/out30.csv
${pfxc}mcut f=顧客,"数量0?" i=./indat/dat6.csv o=./outdat/out31.csv
${pfxc}mcut f="数量0?",顧客 i=./indat/dat6.csv o=./outdat/out32.csv

#項目名の置換
#NULL Data
${pfxc}mcut f=顧客,"数量4:2009年度&" i=./indat/dat5.csv o=./outdat/out33.csv
${pfxc}mcut f="数量4:2009年度&",顧客 i=./indat/dat5.csv o=./outdat/out34.csv
${pfxc}mcut f=顧客,"数量*:2009年度&" i=./indat/dat5.csv o=./outdat/out35.csv
${pfxc}mcut f="数量*:2009年度&",顧客 i=./indat/dat5.csv o=./outdat/out36.csv
${pfxc}mcut f=顧客,"数量0?:2009年度&" i=./indat/dat5.csv o=./outdat/out37.csv
${pfxc}mcut f="数量0?:2009年度&",顧客 i=./indat/dat5.csv o=./outdat/out38.csv


#基本
${pfxc}mcut f=顧客,"数量4:2009年度&" i=./indat/dat6.csv o=./outdat/out41.csv
${pfxc}mcut f="数量4:2009年度&",顧客 i=./indat/dat6.csv o=./outdat/out42.csv
${pfxc}mcut f=顧客,"数量*:2009年度&" i=./indat/dat6.csv o=./outdat/out43.csv
${pfxc}mcut f="数量*:2009年度&",顧客 i=./indat/dat6.csv o=./outdat/out44.csv
${pfxc}mcut f=顧客,"数量0?:2009年度&" i=./indat/dat6.csv o=./outdat/out45.csv
${pfxc}mcut f="数量0?:2009年度&",顧客 i=./indat/dat6.csv o=./outdat/out46.csv

#ソートデータ
${pfxc}mcut f=顧客,"数量4:2009年度&" i=./indat/dat6s.csv o=./outdat/out49.csv
${pfxc}mcut f=顧客,"数量*" i=./indat/dat6s.csv o=./outdat/out50.csv
${pfxc}mcut -x f=0L,1-2 i=./indat/dat6s.csv o=./outdat/out51.csv
${pfxc}mcut -x f=0-1,1L i=./indat/dat6s.csv o=./outdat/out52.csv


#エラー処理
${pfxc}mcut f= i=./indat/dat1.csv o=kgError
${pfxc}mcut f=顧客,数量,金額 -r i=./indat/dat1.csv o=kgError

