#!/bin/bash

. ../env

#name_kg_mcmd sed

#NULL
${pfxc}msed      f=郵便番号 c=00.. v=#### i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}msed -x   f=1        c=00.. v=#### i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}msed -nfn f=1        c=00.. v=#### i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#基本
${pfxc}msed      f=郵便番号 c=00.. v=#### i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}msed -x   f=1        c=00.. v=#### i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}msed -nfn f=1        c=00.. v=#### i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

#-A
${pfxc}msed      f=郵便番号:郵便番号下4桁隠 c=00.. v=#### -A i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}msed -x   f=1:郵便番号下4桁隠        c=00.. v=#### -A i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}msed -nfn f=1:郵便番号下4桁隠        c=00.. v=#### -A i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

#-g
${pfxc}msed      f=郵便番号 c=0 v=- i=./indat/dat1.csv    o=./outdat/out3.csv    -g
${pfxc}msed -x   f=1        c=0 v=- i=./indat/dat1.csv    o=./outdat/out3x.csv   -g
${pfxc}msed -nfn f=1        c=0 v=- i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv -g

#正規表現
${pfxc}msed      f=郵便番号 c=[0-9]* v=郵便番号 i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}msed -x   f=1        c=[0-9]* v=郵便番号 i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}msed -nfn f=1        c=[0-9]* v=郵便番号 i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

${pfxc}msed      f=郵便番号 c=[01] v=@ i=./indat/dat1.csv    o=./outdat/out5.csv    -g
${pfxc}msed -x   f=1        c=[01] v=@ i=./indat/dat1.csv    o=./outdat/out5x.csv   -g
${pfxc}msed -nfn f=1        c=[01] v=@ i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv -g

${pfxc}msed      f=郵便番号 c=^63 v=zz  i=./indat/dat1.csv    o=./outdat/out6.csv
${pfxc}msed -x   f=1        c=^63 v=zz  i=./indat/dat1.csv    o=./outdat/out6x.csv
${pfxc}msed -nfn f=1        c=^63 v=zz  i=./indat/dat1nfn.csv o=./outdat/out6nfn.csv

${pfxc}msed      f=郵便番号 c=1$ v=--  i=./indat/dat1.csv    o=./outdat/out7.csv
${pfxc}msed -x   f=1        c=1$ v=--  i=./indat/dat1.csv    o=./outdat/out7x.csv
${pfxc}msed -nfn f=1        c=1$ v=--  i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv

#-w使用
${pfxc}msed      f=商品 c=果物 v=01 -W i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}msed -x   f=0    c=果物 v=01 -W i=./indat/dat2.csv    o=./outdat/out8x.csv
${pfxc}msed -nfn f=0    c=果物 v=01 -W i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv

${pfxc}msed      f=商品 c=^果物 v=F -W i=./indat/dat2.csv    o=./outdat/out9.csv
${pfxc}msed -x   f=0    c=^果物 v=F -W i=./indat/dat2.csv    o=./outdat/out9x.csv
${pfxc}msed -nfn f=0    c=^果物 v=F -W i=./indat/dat2nfn.csv o=./outdat/out9nfn.csv

${pfxc}msed      f=商品 c=葡萄$ v=ぶどう -W i=./indat/dat2.csv    o=./outdat/out10.csv
${pfxc}msed -x   f=0    c=葡萄$ v=ぶどう -W i=./indat/dat2.csv    o=./outdat/out10x.csv
${pfxc}msed -nfn f=0    c=葡萄$ v=ぶどう -W i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv

${pfxc}msed      f=商品 c=[物梨] v=＠ -W -g i=./indat/dat2.csv    o=./outdat/out11.csv
${pfxc}msed -x   f=0    c=[物梨] v=＠ -W -g i=./indat/dat2.csv    o=./outdat/out11x.csv
${pfxc}msed -nfn f=0    c=[物梨] v=＠ -W -g i=./indat/dat2nfn.csv o=./outdat/out11nfn.csv

# マッチ文字列による置換1
${pfxc}msed      f=郵便番号 c=00. v='#$&#' i=./indat/dat1.csv    o=./outdat/out12.csv
${pfxc}msed -x   f=1        c=00. v='#$&#' i=./indat/dat1.csv    o=./outdat/out12x.csv
${pfxc}msed -nfn f=1        c=00. v='#$&#' i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv

# マッチ文字列による置換2
${pfxc}msed      f=郵便番号 c=00. v='#$`#' i=./indat/dat1.csv    o=./outdat/out13.csv
${pfxc}msed -x   f=1        c=00. v='#$`#' i=./indat/dat1.csv    o=./outdat/out13x.csv
${pfxc}msed -nfn f=1        c=00. v='#$`#' i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv

# マッチ文字列による置換3           
${pfxc}msed      f=郵便番号 c=00. v=#\$\'# i=./indat/dat1.csv    o=./outdat/out14.csv
${pfxc}msed -x   f=1        c=00. v=#\$\'# i=./indat/dat1.csv    o=./outdat/out14x.csv
${pfxc}msed -nfn f=1        c=00. v=#\$\'# i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

#ソートデータ
${pfxc}msed      f=郵便番号 c=00.. v=#### i=./indat/dat1s.csv    o=./outdat/out15.csv
${pfxc}msed -x   f=1        c=00.. v=#### i=./indat/dat1s.csv    o=./outdat/out15x.csv
