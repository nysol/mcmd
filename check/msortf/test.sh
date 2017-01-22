#!/bin/bash

. ../env

#name_kg_mcmd sortf

${pfxc}msortf      f=商品,日付,数量,金額 i=./indat/dat0.csv    o=./outdat/out01.csv
${pfxc}msortf -x   f=0,1,2,3             i=./indat/dat0.csv    o=./outdat/out01x.csv
${pfxc}msortf -nfn f=0,1,2,3             i=./indat/dat0nfn.csv o=./outdat/out01nfn.csv

${pfxc}msortf      f=商品 i=./indat/dat1.csv    o=./outdat/out02.csv
${pfxc}msortf -x   f=0    i=./indat/dat1.csv    o=./outdat/out02x.csv
${pfxc}msortf -nfn f=0    i=./indat/dat1nfn.csv o=./outdat/out02nfn.csv
${pfxc}msortf -nfno f=商品 i=./indat/dat1.csv    o=./outdat/out02nfno.csv

${pfxc}msortf      f=商品,日付 i=./indat/dat1.csv    o=./outdat/out03.csv
${pfxc}msortf -x   f=0,1       i=./indat/dat1.csv    o=./outdat/out03x.csv
${pfxc}msortf -nfn f=0,1       i=./indat/dat1nfn.csv o=./outdat/out03nfn.csv

${pfxc}msortf      f=商品,日付,数量 i=./indat/dat1.csv    o=./outdat/out04.csv
${pfxc}msortf -x   f=0,1,2          i=./indat/dat1.csv    o=./outdat/out04x.csv
${pfxc}msortf -nfn f=0,1,2          i=./indat/dat1nfn.csv o=./outdat/out04nfn.csv

${pfxc}msortf      f=商品,日付,数量,金額 i=./indat/dat1.csv    o=./outdat/out05.csv
${pfxc}msortf -x   f=0,1,2,3             i=./indat/dat1.csv    o=./outdat/out05x.csv
${pfxc}msortf -nfn f=0,1,2,3             i=./indat/dat1nfn.csv o=./outdat/out05nfn.csv

${pfxc}msortf      f=商品,数量%n,金額%n i=./indat/dat1.csv    o=./outdat/out06.csv
${pfxc}msortf -x   f=0,2%n,3%n          i=./indat/dat1.csv    o=./outdat/out06x.csv
${pfxc}msortf -nfn f=0,2%n,3%n          i=./indat/dat1nfn.csv o=./outdat/out06nfn.csv

${pfxc}msortf      f=金額%nr i=./indat/dat1.csv    o=./outdat/out07.csv
${pfxc}msortf -x   f=3%nr    i=./indat/dat1.csv    o=./outdat/out07x.csv
${pfxc}msortf -nfn f=3%nr    i=./indat/dat1nfn.csv o=./outdat/out07nfn.csv

${pfxc}msortf      f=数量%nr i=./indat/dat1.csv    o=./outdat/out08.csv
${pfxc}msortf -x   f=2%nr    i=./indat/dat1.csv    o=./outdat/out08x.csv
${pfxc}msortf -nfn f=2%nr    i=./indat/dat1nfn.csv o=./outdat/out08nfn.csv

${pfxc}msortf      f=数量%nr,金額%nr i=./indat/dat1.csv    o=./outdat/out09.csv
${pfxc}msortf -x   f=2%nr,3%nr       i=./indat/dat1.csv    o=./outdat/out09x.csv
${pfxc}msortf -nfn f=2%nr,3%nr       i=./indat/dat1nfn.csv o=./outdat/out09nfn.csv

${pfxc}msortf      f=数量%nr,金額%n i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}msortf -x   f=2%nr,3%n       i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}msortf -nfn f=2%nr,3%n       i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}msortf      f=数量%n,金額%nr i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}msortf -x   f=2%n,3%nr       i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}msortf -nfn f=2%n,3%nr       i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

${pfxc}msortf      f=商品%r i=./indat/dat1.csv    o=./outdat/out12.csv
${pfxc}msortf -x   f=0%r    i=./indat/dat1.csv    o=./outdat/out12x.csv
${pfxc}msortf -nfn f=0%r    i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv

${pfxc}msortf      f=商品%nr i=./indat/dat1.csv    o=./outdat/out13.csv
${pfxc}msortf -x   f=0%nr    i=./indat/dat1.csv    o=./outdat/out13x.csv
${pfxc}msortf -nfn f=0%nr    i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv

${pfxc}msortf      f=商品%r,日付 i=./indat/dat1.csv    o=./outdat/out14.csv
${pfxc}msortf -x   f=0%r,1       i=./indat/dat1.csv    o=./outdat/out14x.csv
${pfxc}msortf -nfn f=0%r,1       i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

${pfxc}msortf      f=商品,日付%r i=./indat/dat1.csv    o=./outdat/out15.csv
${pfxc}msortf -x   f=0,1%r       i=./indat/dat1.csv    o=./outdat/out15x.csv
${pfxc}msortf -nfn f=0,1%r       i=./indat/dat1nfn.csv o=./outdat/out15nfn.csv

${pfxc}msortf      f=商品%r,日付%r i=./indat/dat1.csv    o=./outdat/out16.csv
${pfxc}msortf -x   f=0%r,1%r       i=./indat/dat1.csv    o=./outdat/out16x.csv
${pfxc}msortf -nfn f=0%r,1%r       i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv

${pfxc}msortf      f=商品 i=./indat/dat2.csv    o=./outdat/out17.csv
${pfxc}msortf -x   f=0    i=./indat/dat2.csv    o=./outdat/out17x.csv
${pfxc}msortf -nfn f=0    i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv

${pfxc}msortf      f=商品,日付 i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}msortf -x   f=0,1       i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}msortf -nfn f=0,1       i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv

${pfxc}msortf      f=商品,日付,数量 i=./indat/dat2.csv    o=./outdat/out19.csv
${pfxc}msortf -x   f=0,1,2          i=./indat/dat2.csv    o=./outdat/out19x.csv
${pfxc}msortf -nfn f=0,1,2          i=./indat/dat2nfn.csv o=./outdat/out19nfn.csv

${pfxc}msortf      f=商品,日付,数量,金額 i=./indat/dat2.csv    o=./outdat/out20.csv
${pfxc}msortf -x   f=0,1,2,3             i=./indat/dat2.csv    o=./outdat/out20x.csv
${pfxc}msortf -nfn f=0,1,2,3             i=./indat/dat2nfn.csv o=./outdat/out20nfn.csv

${pfxc}msortf      f=商品,数量%n,金額%n i=./indat/dat2.csv    o=./outdat/out21.csv
${pfxc}msortf -x   f=0,2%n,3%n          i=./indat/dat2.csv    o=./outdat/out21x.csv
${pfxc}msortf -nfn f=0,2%n,3%n          i=./indat/dat2nfn.csv o=./outdat/out21nfn.csv

${pfxc}msortf      f=金額%nr i=./indat/dat2.csv    o=./outdat/out22.csv
${pfxc}msortf -x   f=3%nr    i=./indat/dat2.csv    o=./outdat/out22x.csv
${pfxc}msortf -nfn f=3%nr    i=./indat/dat2nfn.csv o=./outdat/out22nfn.csv

${pfxc}msortf      f=数量%nr i=./indat/dat2.csv    o=./outdat/out23.csv
${pfxc}msortf -x   f=2%nr    i=./indat/dat2.csv    o=./outdat/out23x.csv
${pfxc}msortf -nfn f=2%nr    i=./indat/dat2nfn.csv o=./outdat/out23nfn.csv

${pfxc}msortf      f=数量%nr,金額%nr i=./indat/dat2.csv    o=./outdat/out24.csv
${pfxc}msortf -x   f=2%nr,3%nr       i=./indat/dat2.csv    o=./outdat/out24x.csv
${pfxc}msortf -nfn f=2%nr,3%nr       i=./indat/dat2nfn.csv o=./outdat/out24nfn.csv

${pfxc}msortf      f=数量%nr,金額%n i=./indat/dat2.csv    o=./outdat/out25.csv
${pfxc}msortf -x   f=2%nr,3%n       i=./indat/dat2.csv    o=./outdat/out25x.csv
${pfxc}msortf -nfn f=2%nr,3%n       i=./indat/dat2nfn.csv o=./outdat/out25nfn.csv

${pfxc}msortf      f=数量%n,金額%nr i=./indat/dat2.csv    o=./outdat/out26.csv
${pfxc}msortf -x   f=2%n,3%nr       i=./indat/dat2.csv    o=./outdat/out26x.csv
${pfxc}msortf -nfn f=2%n,3%nr       i=./indat/dat2nfn.csv o=./outdat/out26nfn.csv

${pfxc}msortf      f=商品%r i=./indat/dat2.csv    o=./outdat/out27.csv
${pfxc}msortf -x   f=0%r    i=./indat/dat2.csv    o=./outdat/out27x.csv
${pfxc}msortf -nfn f=0%r    i=./indat/dat2nfn.csv o=./outdat/out27nfn.csv

${pfxc}msortf      f=商品%nr i=./indat/dat2.csv    o=./outdat/out28.csv
${pfxc}msortf -x   f=0%nr    i=./indat/dat2.csv    o=./outdat/out28x.csv
${pfxc}msortf -nfn f=0%nr    i=./indat/dat2nfn.csv o=./outdat/out28nfn.csv

${pfxc}msortf      f=商品%r,日付 i=./indat/dat2.csv    o=./outdat/out29.csv
${pfxc}msortf -x   f=0%r,1       i=./indat/dat2.csv    o=./outdat/out29x.csv
${pfxc}msortf -nfn f=0%r,1       i=./indat/dat2nfn.csv o=./outdat/out29nfn.csv

${pfxc}msortf      f=商品,日付%r i=./indat/dat2.csv    o=./outdat/out30.csv
${pfxc}msortf -x   f=0,1%r       i=./indat/dat2.csv    o=./outdat/out30x.csv
${pfxc}msortf -nfn f=0,1%r       i=./indat/dat2nfn.csv o=./outdat/out30nfn.csv

${pfxc}msortf      f=商品%r,日付%r i=./indat/dat2.csv    o=./outdat/out31.csv
${pfxc}msortf -x   f=0%r,1%r       i=./indat/dat2.csv    o=./outdat/out31x.csv
${pfxc}msortf -nfn f=0%r,1%r       i=./indat/dat2nfn.csv o=./outdat/out31nfn.csv

# blocks=1指定 
${pfxc}msortf blocks=1     f=商品 i=./indat/dat2.csv    o=./outdat/out31-1.csv

# pways=1
${pfxc}msortf pways=3     f=商品%r,日付%r i=./indat/dat2.csv    o=./outdat/out36.csv

#1万行データ
#文字列昇順
${pfxc}msortf      f=item i=./indat/dat3.csv    o=./outdat/out32.csv
#文字列降順
${pfxc}msortf      f=item%r i=./indat/dat3.csv    o=./outdat/out33.csv
#数値昇順
${pfxc}msortf      f=item%n i=./indat/dat3n.csv    o=./outdat/out34.csv
#数値降順
${pfxc}msortf      f=item%nr i=./indat/dat3n.csv    o=./outdat/out35.csv

#1万行データ既にソート済
${pfxc}msortf      f=item i=./indat/dat5.csv    o=./outdat/out42.csv
${pfxc}msortf      f=item%r i=./indat/dat6.csv    o=./outdat/out43.csv

#maxlines=100指定
${pfxc}msortf maxlines=100    f=item i=./indat/dat3.csv    o=./outdat/out37.csv

#nullありデータ
${pfxc}msortf      f=item    i=./indat/dat4.csv  o=./outdat/out38.csv
${pfxc}msortf      f=item%r  i=./indat/dat4.csv  o=./outdat/out39.csv
${pfxc}msortf      f=item%n  i=./indat/dat4.csv  o=./outdat/out40.csv
${pfxc}msortf      f=item%nr i=./indat/dat4.csv  o=./outdat/out41.csv

${pfxc}msortf      f=日付,金額%nr    i=./indat/dat7.csv  o=./outdat/out44.csv


