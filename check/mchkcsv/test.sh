#!/bin/bash
#>の行を#でコメントアウトした。
#make test後のファイルにエラーらしきものが出力されたため。
#>の標準出力でうまくいかなかったのでo=に変更した。
. ../env
#name_kg_mcmd chkcsv

#NULLデータ
${pfxc}mchkcsv      i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mchkcsv -x   i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mchkcsv -nfn i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mchkcsv -nfno i=./indat/dat0.csv    o=./outdat/out0nfno.csv

${pfxc}mchkcsv  i=./indat/dat14.csv o=./outdat/out61.csv
${pfxc}mchkcsv -diagl i=./indat/dat14.csv o=./outdat/out62.csv
${pfxc}mchkcsv -diag i=./indat/dat14.csv o=./outdat/out62n.csv

${pfxc}mchkcsv      a=顧客,数量 i=./indat/dat0.csv    o=./outdat/out1.csv
${pfxc}mchkcsv -x   a=1,2       i=./indat/dat0.csv    o=./outdat/out1x.csv
${pfxc}mchkcsv -nfn a=1,2       i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

${pfxc}mchkcsv -diagl   i=./indat/dat0nfn.csv    o=./outdat/out57.csv
${pfxc}mchkcsv -diagl   i=./indat/dat0.csv    o=./outdat/out58.csv
${pfxc}mchkcsv -diag   i=./indat/dat0nfn.csv    o=./outdat/out57n.csv
${pfxc}mchkcsv -diag   i=./indat/dat0.csv    o=./outdat/out58n.csv

#通常
${pfxc}mchkcsv      i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mchkcsv -x   i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mchkcsv -nfn i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}mchkcsv -nfno i=./indat/dat1.csv    o=./outdat/out2nfno.csv

${pfxc}mchkcsv      i=./indat/dat1.csv    o=./outdat/out3.csv    -r
${pfxc}mchkcsv -x   i=./indat/dat1.csv    o=./outdat/out3x.csv   -r
${pfxc}mchkcsv -nfn i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv -r

${pfxc}mchkcsv      i=./indat/dat1.csv    a=顧客ID,日付 o=./outdat/out4.csv
${pfxc}mchkcsv -x   i=./indat/dat1.csv    a=顧客ID,日付 o=./outdat/out4x.csv
${pfxc}mchkcsv -nfn i=./indat/dat1nfn.csv a=顧客ID,日付 o=./outdat/out4nfn.csv

${pfxc}mchkcsv i=./indat/dat1.csv a=顧客ID,日付 -r o=./outdat/out5.csv
${pfxc}mchkcsv i=./indat/dat1.csv -diag  o=./outdat/out6n.csv 
${pfxc}mchkcsv i=./indat/dat1.csv -diagl o=./outdat/out6.csv 

# 同じ項目名
${pfxc}mchkcsv i=./indat/dat2.csv o=./outdat/out7.csv
${pfxc}mchkcsv i=./indat/dat2.csv o=./outdat/out8.csv -r
${pfxc}mchkcsv i=./indat/dat2.csv a=顧客ID,商品ID,数量 o=./outdat/out9.csv
${pfxc}mchkcsv i=./indat/dat2.csv a=顧客ID,商品ID,数量 -r o=./outdat/out10.csv
${pfxc}mchkcsv i=./indat/dat2.csv -diag  o=./outdat/out11n.csv 
${pfxc}mchkcsv i=./indat/dat2.csv -diagl o=./outdat/out11.csv 

# 項目名の不正文字（,%*?:&\\）
${pfxc}mchkcsv i=./indat/dat3.csv o=./outdat/out12.csv
${pfxc}mchkcsv i=./indat/dat3.csv o=./outdat/out13.csv -r
${pfxc}mchkcsv i=./indat/dat3.csv a=顧客ID,商品ID,数量 o=./outdat/out14.csv
${pfxc}mchkcsv i=./indat/dat3.csv a=顧客ID,商品ID,数量 -r o=./outdat/out15.csv
${pfxc}mchkcsv i=./indat/dat3.csv -diag o=./outdat/out16n.csv 
${pfxc}mchkcsv i=./indat/dat3.csv -diagl o=./outdat/out16.csv 

#TAB
${pfxc}mchkcsv i=./indat/dat4.csv o=./outdat/out17.csv
${pfxc}mchkcsv i=./indat/dat4.csv o=./outdat/out18.csv -r
${pfxc}mchkcsv i=./indat/dat4.csv a=顧客ID,日付,商品ID o=./outdat/out19.csv
${pfxc}mchkcsv i=./indat/dat4.csv a=顧客ID,日付,商品ID -r o=./outdat/out20.csv
${pfxc}mchkcsv i=./indat/dat4.csv -diag  o=./outdat/out21n.csv 
${pfxc}mchkcsv i=./indat/dat4.csv -diagl o=./outdat/out21.csv 

#CRLF
${pfxc}mchkcsv i=./indat/dat5.csv o=./outdat/out22.csv
${pfxc}mchkcsv i=./indat/dat5.csv o=./outdat/out23.csv -r
${pfxc}mchkcsv i=./indat/dat5.csv a=顧客ID,日付,商品ID o=./outdat/out24.csv
${pfxc}mchkcsv i=./indat/dat5.csv a=顧客ID,日付,商品ID -r o=./outdat/out25.csv
${pfxc}mchkcsv i=./indat/dat5.csv -diag  o=./outdat/out26n.csv 
${pfxc}mchkcsv i=./indat/dat5.csv -diagl o=./outdat/out26.csv

#LFなし
${pfxc}mchkcsv i=./indat/dat6.csv o=./outdat/out27.csv
${pfxc}mchkcsv i=./indat/dat6.csv o=./outdat/out28.csv -r
${pfxc}mchkcsv i=./indat/dat6.csv a=顧客ID,日付,商品ID o=./outdat/out29.csv
${pfxc}mchkcsv i=./indat/dat6.csv a=顧客ID,日付,商品ID -r o=./outdat/out30.csv
${pfxc}mchkcsv i=./indat/dat6.csv -diag  o=./outdat/out31n.csv 
${pfxc}mchkcsv i=./indat/dat6.csv -diagl o=./outdat/out31.csv 

#項目数が違う
${pfxc}mchkcsv i=./indat/dat7.csv o=./outdat/out32.csv
${pfxc}mchkcsv i=./indat/dat7.csv o=./outdat/out33.csv -r
${pfxc}mchkcsv i=./indat/dat7.csv a=顧客ID,日付,商品ID o=./outdat/out34.csv
${pfxc}mchkcsv i=./indat/dat7.csv a=顧客ID,日付,商品ID -r o=./outdat/out35.csv
${pfxc}mchkcsv i=./indat/dat7.csv -diag  o=./outdat/out36n.csv 
${pfxc}mchkcsv i=./indat/dat7.csv -diagl o=./outdat/out36.csv

#DQが入っている
${pfxc}mchkcsv i=./indat/dat8.csv o=./outdat/out37.csv
${pfxc}mchkcsv i=./indat/dat8.csv o=./outdat/out38.csv -r
${pfxc}mchkcsv i=./indat/dat8.csv a=顧客ID,日付,商品ID o=./outdat/out39.csv
${pfxc}mchkcsv i=./indat/dat8.csv a=顧客ID,日付,商品ID -r o=./outdat/out40.csv
${pfxc}mchkcsv i=./indat/dat8.csv -diag  o=./outdat/out41n.csv 
${pfxc}mchkcsv i=./indat/dat8.csv -diagl o=./outdat/out41.csv 

#DQで囲われている中にさらにDQが入っている
${pfxc}mchkcsv i=./indat/dat9.csv o=./outdat/out42.csv
${pfxc}mchkcsv i=./indat/dat9.csv o=./outdat/out43.csv -r
${pfxc}mchkcsv i=./indat/dat9.csv a=顧客ID,日付,商品ID o=./outdat/out44.csv
${pfxc}mchkcsv i=./indat/dat9.csv a=顧客ID,日付,商品ID -r o=./outdat/out45.csv
${pfxc}mchkcsv i=./indat/dat9.csv -diag  o=./outdat/out46n.csv 
${pfxc}mchkcsv i=./indat/dat9.csv -diagl o=./outdat/out46.csv 

#0x00あり
${pfxc}mchkcsv i=./indat/dat10.csv o=./outdat/out47.csv
${pfxc}mchkcsv i=./indat/dat10.csv o=./outdat/out48.csv -r
${pfxc}mchkcsv i=./indat/dat10.csv a=顧客ID,日付,商品ID o=./outdat/out49.csv
${pfxc}mchkcsv i=./indat/dat10.csv a=顧客ID,日付,商品ID -r o=./outdat/out50.csv
${pfxc}mchkcsv i=./indat/dat10.csv -diag o=./outdat/out51n.csv 
${pfxc}mchkcsv i=./indat/dat10.csv -diagl o=./outdat/out51.csv 

#0x01などあり
${pfxc}mchkcsv i=./indat/dat11.csv o=./outdat/out52.csv
${pfxc}mchkcsv i=./indat/dat11.csv o=./outdat/out53.csv -r
${pfxc}mchkcsv i=./indat/dat11.csv a=顧客ID,日付,商品ID o=./outdat/out54.csv
${pfxc}mchkcsv i=./indat/dat11.csv a=顧客ID,日付,商品ID -r o=./outdat/out55.csv
${pfxc}mchkcsv i=./indat/dat11.csv -diag o=./outdat/out56n.csv 
${pfxc}mchkcsv i=./indat/dat11.csv -diagl o=./outdat/out56.csv

#\nあり
${pfxc}mchkcsv      i=./indat/dat12.csv    o=./outdat/out59.csv
#\rあり
${pfxc}mchkcsv      i=./indat/dat13.csv    o=./outdat/out60.csv
${pfxc}mchkcsv -diag  i=./indat/dat13.csv    o=./outdat/out63n.csv
${pfxc}mchkcsv -diagl  i=./indat/dat13.csv    o=./outdat/out63.csv
#最終行改行なし
${pfxc}mchkcsv      i=./indat/dat15.csv    o=./outdat/out64.csv
${pfxc}mchkcsv -diag  i=./indat/dat15.csv    o=./outdat/out65n.csv
${pfxc}mchkcsv -diagl  i=./indat/dat15.csv    o=./outdat/out65.csv


