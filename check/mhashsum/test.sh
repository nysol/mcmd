#修正日は 20120308
#修正者は 樋口　寛視
#修正内容は 項目番号指定パラーメータをマイナス１する。（以前は1からの指定だったが、０からに変更になったため。）
#!/bin/bash

. ../env

#name_kg_mcmd hashsum

#nullデータ
${pfxc}mhashsum      k=顧客 f=数量,金額 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mhashsum -x   k=0    f=1,2       i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

${pfxc}mhashsum      k=顧客 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mhashsum -x   k=0    f=1,2       i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mhashsum      k=顧客 f=金額,数量 i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mhashsum -x   k=0    f=1,2       i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

${pfxc}mhashsum      f=数量,金額 i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mhashsum -x   f=1,2       i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mhashsum -nfn f=1,2       i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

#null混在データ
${pfxc}mhashsum      k=顧客 f=数量,金額 i=./indat/dat2.csv    o=./outdat/out4.csv
${pfxc}mhashsum -x   k=0    f=1,2       i=./indat/dat2.csv    o=./outdat/out4x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv

${pfxc}mhashsum      f=数量,金額 i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mhashsum -x   f=1,2       i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mhashsum -nfn f=1,2       i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv

#null混在データ with -n
${pfxc}mhashsum      -n k=顧客 f=数量,金額 i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mhashsum -x   -n k=0    f=1,2       i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mhashsum -nfn -n k=0    f=1,2       i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

${pfxc}mhashsum      -n f=数量,金額 i=./indat/dat2.csv    o=./outdat/out7.csv
${pfxc}mhashsum -x   -n f=1,2       i=./indat/dat2.csv    o=./outdat/out7x.csv
${pfxc}mhashsum -nfn -n f=1,2       i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv

#ハッシュサイズ変更
${pfxc}mhashsum      k=顧客 f=数量,金額 hs=101 i=./indat/dat0.csv    o=./outdat/out8.csv
${pfxc}mhashsum -x   k=0    f=1,2       hs=101 i=./indat/dat0.csv    o=./outdat/out8x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       hs=101 i=./indat/dat0nfn.csv o=./outdat/out8nfn.csv

${pfxc}mhashsum      k=顧客 f=数量,金額 hs=101 i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}mhashsum -x   k=0    f=1,2       hs=101 i=./indat/dat1.csv    o=./outdat/out9x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       hs=101 i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv

${pfxc}mhashsum      k=顧客 f=金額,数量 hs=101 i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mhashsum -x   k=0    f=1,2       hs=101 i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       hs=101 i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}mhashsum      f=数量,金額 hs=101 i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}mhashsum -x   f=1,2       hs=101 i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}mhashsum -nfn f=1,2       hs=101 i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

#null混在データ
${pfxc}mhashsum      k=顧客 f=数量,金額 hs=101 i=./indat/dat2.csv    o=./outdat/out12.csv
${pfxc}mhashsum -x   k=0    f=1,2       hs=101 i=./indat/dat2.csv    o=./outdat/out12x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       hs=101 i=./indat/dat2nfn.csv o=./outdat/out12nfn.csv

${pfxc}mhashsum      f=数量,金額 hs=101 i=./indat/dat2.csv    o=./outdat/out13.csv
${pfxc}mhashsum -x   f=1,2       hs=101 i=./indat/dat2.csv    o=./outdat/out13x.csv
${pfxc}mhashsum -nfn f=1,2       hs=101 i=./indat/dat2nfn.csv o=./outdat/out13nfn.csv

#null混在データ with -n
${pfxc}mhashsum      -n k=顧客 f=数量,金額 hs=101 i=./indat/dat2.csv    o=./outdat/out14.csv
${pfxc}mhashsum -x   -n k=0    f=1,2       hs=101 i=./indat/dat2.csv    o=./outdat/out14x.csv
${pfxc}mhashsum -nfn -n k=0    f=1,2       hs=101 i=./indat/dat2nfn.csv o=./outdat/out14nfn.csv

${pfxc}mhashsum      -n f=数量,金額 hs=101 i=./indat/dat2.csv    o=./outdat/out15.csv
${pfxc}mhashsum -x   -n f=1,2       hs=101 i=./indat/dat2.csv    o=./outdat/out15x.csv
${pfxc}mhashsum -nfn -n f=1,2       hs=101 i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv


${pfxc}mhashsum      k=顧客 f=数量,金額 i=./indat/dat1s.csv    o=./outdat/out16.csv
${pfxc}mhashsum -x   k=0    f=1,2       i=./indat/dat1s.csv    o=./outdat/out16x.csv
${pfxc}mhashsum -nfn k=0    f=1,2       i=./indat/dat1snfn.csv o=./outdat/out16nfn.csv
