#!/bin/bash
#修正日は 20120308
#修正者は 樋口　寛視
#修正内容は 項目番号指定パラーメータをマイナス１する。（以前は1からの指定だったが、０からに変更になったため。）
. ../env

#name_kg_mcmd common

#NULL
${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out0.csv
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out0x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out0nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out1nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out2.csv
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out2x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out2nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out3.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out3x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out3nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out4.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out4x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out4nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out5.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out5x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out5nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out6.csv    u=./outdat/out7.csv
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out6x.csv   u=./outdat/out7x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out6nfn.csv u=./outdat/out7nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out8.csv    u=./outdat/out9.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out8x.csv   u=./outdat/out9x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out8nfn.csv u=./outdat/out9nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out10.csv    u=./outdat/out11.csv
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out10x.csv   u=./outdat/out11x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out10nfn.csv u=./outdat/out11nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out12.csv    u=./outdat/out13.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat1s.csv    o=./outdat/out12x.csv   u=./outdat/out13x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat1snfn.csv o=./outdat/out12nfn.csv u=./outdat/out13nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out14.csv    u=./outdat/out15.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat1s.csv    o=./outdat/out14x.csv   u=./outdat/out15x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat1snfn.csv o=./outdat/out14nfn.csv u=./outdat/out15nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out16.csv    u=./outdat/out17.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat0s.csv    m=./indat/dat3s.csv    o=./outdat/out16x.csv   u=./outdat/out17x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat0snfn.csv m=./indat/dat3snfn.csv o=./outdat/out16nfn.csv u=./outdat/out17nfn.csv -r

#基本
${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out18.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out18x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out18nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out19.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out19x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out19nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out20.csv    u=./outdat/out21.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out20x.csv   u=./outdat/out21x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out20nfn.csv u=./outdat/out21nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out22.csv    u=./outdat/out23.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out22x.csv   u=./outdat/out23x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out22nfn.csv u=./outdat/out23nfn.csv -r

#k=二つ
${pfxc}mcommon      k=顧客,日付       i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out24.csv
${pfxc}mcommon -x   k=0,3       K=0,2 i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out24x.csv
${pfxc}mcommon -nfn k=0,3       K=0,2 i=./indat/dat4snfn.csv m=./indat/dat5snfn.csv o=./outdat/out24nfn.csv

${pfxc}mcommon      k=顧客,日付       i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out25.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2 i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out25x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2 i=./indat/dat4snfn.csv m=./indat/dat5snfn.csv o=./outdat/out25nfn.csv -r

${pfxc}mcommon      k=顧客,日付       i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out26.csv    u=./outdat/out27.csv
${pfxc}mcommon -x   k=0,3       K=0,2 i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out26x.csv   u=./outdat/out27x.csv
${pfxc}mcommon -nfn k=0,3       K=0,2 i=./indat/dat4snfn.csv m=./indat/dat5snfn.csv o=./outdat/out26nfn.csv u=./outdat/out27nfn.csv

${pfxc}mcommon      k=顧客,日付       i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out28.csv    u=./outdat/out29.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2 i=./indat/dat4s.csv    m=./indat/dat5s.csv    o=./outdat/out28x.csv   u=./outdat/out29x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2 i=./indat/dat4snfn.csv m=./indat/dat5snfn.csv o=./outdat/out28nfn.csv u=./outdat/out29nfn.csv -r

#K=を指定
${pfxc}mcommon      k=顧客 K=顧客ID i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out30.csv
${pfxc}mcommon -x   k=0    K=0      i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out30x.csv
${pfxc}mcommon -nfn k=0    K=0      i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out30nfn.csv

${pfxc}mcommon      k=顧客 K=顧客ID i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out31.csv    -r
${pfxc}mcommon -x   k=0    K=0      i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out31x.csv   -r
${pfxc}mcommon -nfn k=0    K=0      i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out31nfn.csv -r

${pfxc}mcommon      k=顧客 K=顧客ID i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out32.csv    u=./outdat/out33.csv
${pfxc}mcommon -x   k=0    K=0      i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out32x.csv   u=./outdat/out33x.csv
${pfxc}mcommon -nfn k=0    K=0      i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out32nfn.csv u=./outdat/out33nfn.csv

${pfxc}mcommon      k=顧客 K=顧客ID i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out34.csv    u=./outdat/out35.csv    -r
${pfxc}mcommon -x   k=0    K=0      i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out34x.csv   u=./outdat/out35x.csv   -r
${pfxc}mcommon -nfn k=0    K=0      i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out34nfn.csv u=./outdat/out35nfn.csv -r

#k=,K=二つ
${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out36.csv
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out36x.csv
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out36nfn.csv

${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out37.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out37x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out37nfn.csv -r

${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out38.csv    u=./outdat/out39.csv
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out38x.csv   u=./outdat/out39x.csv
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out38nfn.csv u=./outdat/out39nfn.csv

${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out40.csv    u=./outdat/out41.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat4s.csv    m=./indat/dat6s.csv    o=./outdat/out40x.csv   u=./outdat/out41x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat4snfn.csv m=./indat/dat6snfn.csv o=./outdat/out40nfn.csv u=./outdat/out41nfn.csv -r

#kにNULL
${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out42.csv
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out42x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat3snfn.csv o=./outdat/out42nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out43.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out43x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat3snfn.csv o=./outdat/out43nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out44.csv    u=./outdat/out45.csv
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out44x.csv   u=./outdat/out45x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat3snfn.csv o=./outdat/out44nfn.csv u=./outdat/out45nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out46.csv    u=./outdat/out47.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat3s.csv    o=./outdat/out46x.csv   u=./outdat/out47x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat3snfn.csv o=./outdat/out46nfn.csv u=./outdat/out47nfn.csv -r

#KにNULL
${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out48.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out48x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat8snfn.csv o=./outdat/out48nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out49.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out49x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat8snfn.csv o=./outdat/out49nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out50.csv    u=./outdat/out51.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out50x.csv   u=./outdat/out51x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat8snfn.csv o=./outdat/out50nfn.csv u=./outdat/out51nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out52.csv    u=./outdat/out53.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat8s.csv    o=./outdat/out52x.csv   u=./outdat/out53x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat8snfn.csv o=./outdat/out52nfn.csv u=./outdat/out53nfn.csv -r

#k,KにNULL
${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out54.csv
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out54x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat8snfn.csv o=./outdat/out54nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out55.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out55x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat8snfn.csv o=./outdat/out55nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out56.csv    u=./outdat/out57.csv
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out56x.csv   u=./outdat/out57x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat8snfn.csv o=./outdat/out56nfn.csv u=./outdat/out57nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out58.csv    u=./outdat/out59.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat7s.csv    m=./indat/dat8s.csv    o=./outdat/out58x.csv   u=./outdat/out59x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat7snfn.csv m=./indat/dat8snfn.csv o=./outdat/out58nfn.csv u=./outdat/out59nfn.csv -r

#traが先に終わる
${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out60.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out60x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat9snfn.csv o=./outdat/out60nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out61.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out61x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat9snfn.csv o=./outdat/out61nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out62.csv    u=./outdat/out63.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out62x.csv   u=./outdat/out63x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat9snfn.csv o=./outdat/out62nfn.csv u=./outdat/out63nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out64.csv    u=./outdat/out65.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat9s.csv    o=./outdat/out64x.csv   u=./outdat/out65x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat9snfn.csv o=./outdat/out64nfn.csv u=./outdat/out65nfn.csv -r

#マスタが先に終わる
${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out66.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out66x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat10snfn.csv o=./outdat/out66nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out67.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out67x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat10snfn.csv o=./outdat/out67nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out68.csv    u=./outdat/out69.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out68x.csv   u=./outdat/out69x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat10snfn.csv o=./outdat/out68nfn.csv u=./outdat/out69nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out70.csv    u=./outdat/out71.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat10s.csv    o=./outdat/out70x.csv   u=./outdat/out71x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat10snfn.csv o=./outdat/out70nfn.csv u=./outdat/out71nfn.csv -r

#同時に終わる
${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out72.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out72x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat11snfn.csv o=./outdat/out72nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out73.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out73x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat11snfn.csv o=./outdat/out73nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out74.csv    u=./outdat/out75.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out74x.csv   u=./outdat/out75x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat11snfn.csv o=./outdat/out74nfn.csv u=./outdat/out75nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out76.csv    u=./outdat/out77.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat2s.csv    m=./indat/dat11s.csv    o=./outdat/out76x.csv   u=./outdat/out77x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat2snfn.csv m=./indat/dat11snfn.csv o=./outdat/out76nfn.csv u=./outdat/out77nfn.csv -r

#一件もマッチしない
${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out78.csv
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out78x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out78nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out79.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out79x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out79nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out80.csv    u=./outdat/out81.csv
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out80x.csv   u=./outdat/out81x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out80nfn.csv u=./outdat/out81nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out82.csv    u=./outdat/out83.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out82x.csv   u=./outdat/out83x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out82nfn.csv u=./outdat/out83nfn.csv -r

#全部マッチ
${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out84.csv
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out84x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat14snfn.csv o=./outdat/out84nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out85.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out85x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat14snfn.csv o=./outdat/out85nfn.csv -r

${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out86.csv    u=./outdat/out87.csv
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out86x.csv   u=./outdat/out87x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat14snfn.csv o=./outdat/out86nfn.csv u=./outdat/out87nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out88.csv    u=./outdat/out89.csv    -r
${pfxc}mcommon -x   k=0    i=./indat/dat12s.csv    m=./indat/dat14s.csv    o=./outdat/out88x.csv   u=./outdat/out89x.csv   -r
${pfxc}mcommon -nfn k=0    i=./indat/dat12snfn.csv m=./indat/dat14snfn.csv o=./outdat/out88nfn.csv u=./outdat/out89nfn.csv -r

#k,KにNULL(2つ)
${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat15s.csv    m=./indat/dat16s.csv    o=./outdat/out90.csv    u=./outdat/out91.csv
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat15s.csv    m=./indat/dat16s.csv    o=./outdat/out90x.csv   u=./outdat/out91x.csv
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat15snfn.csv m=./indat/dat16snfn.csv o=./outdat/out90nfn.csv u=./outdat/out91nfn.csv

${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat15s.csv    m=./indat/dat16s.csv    o=./outdat/out92.csv    u=./outdat/out93.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat15s.csv    m=./indat/dat16s.csv    o=./outdat/out92x.csv   u=./outdat/out93x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat15snfn.csv m=./indat/dat16snfn.csv o=./outdat/out92nfn.csv u=./outdat/out93nfn.csv -r


#ランダムデータ
#NULL
${pfxc}mcommon      k=顧客 i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out100.csv
${pfxc}mcommon -x   k=0    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out100x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out100nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat2.csv    m=./indat/dat1.csv    o=./outdat/out101.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2.csv    m=./indat/dat1.csv    o=./outdat/out101x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2nfn.csv m=./indat/dat1nfn.csv o=./outdat/out101nfn.csv

${pfxc}mcommon      k=顧客 i=./indat/dat0.csv    m=./indat/dat3.csv    o=./outdat/out102.csv
${pfxc}mcommon -x   k=0    i=./indat/dat0.csv    m=./indat/dat3.csv    o=./outdat/out102x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat0nfn.csv m=./indat/dat3nfn.csv o=./outdat/out102nfn.csv

#基本
${pfxc}mcommon      k=顧客 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out103.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out103x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out103nfn.csv


#k=二つ
${pfxc}mcommon      k=顧客,日付       i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out104.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out104x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2 i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out104nfn.csv -r

#K=を指定
${pfxc}mcommon      k=顧客 K=顧客ID i=./indat/dat4.csv    m=./indat/dat6.csv    o=./outdat/out105.csv    u=./outdat/out106.csv
${pfxc}mcommon -x   k=0    K=0      i=./indat/dat4.csv    m=./indat/dat6.csv    o=./outdat/out105x.csv   u=./outdat/out106x.csv
${pfxc}mcommon -nfn k=0    K=0      i=./indat/dat4nfn.csv m=./indat/dat6nfn.csv o=./outdat/out105nfn.csv u=./outdat/out106nfn.csv

#k=,K=二つ
${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat4.csv    m=./indat/dat6.csv    o=./outdat/out107.csv    u=./outdat/out108.csv    -r
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat4.csv    m=./indat/dat6.csv    o=./outdat/out107x.csv   u=./outdat/out108x.csv   -r
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat4nfn.csv m=./indat/dat6nfn.csv o=./outdat/out107nfn.csv u=./outdat/out108nfn.csv -r

#kにNULL
${pfxc}mcommon      k=顧客 i=./indat/dat7.csv    m=./indat/dat3.csv    o=./outdat/out109.csv
${pfxc}mcommon -x   k=0    i=./indat/dat7.csv    m=./indat/dat3.csv    o=./outdat/out109x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat7nfn.csv m=./indat/dat3nfn.csv o=./outdat/out109nfn.csv

#KにNULL
${pfxc}mcommon      k=顧客 i=./indat/dat2.csv    m=./indat/dat8.csv    o=./outdat/out110.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2.csv    m=./indat/dat8.csv    o=./outdat/out110x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2nfn.csv m=./indat/dat8nfn.csv o=./outdat/out110nfn.csv

#k,KにNULL
${pfxc}mcommon      k=顧客 i=./indat/dat7.csv    m=./indat/dat8.csv    o=./outdat/out111.csv
${pfxc}mcommon -x   k=0    i=./indat/dat7.csv    m=./indat/dat8.csv    o=./outdat/out111x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat7nfn.csv m=./indat/dat8nfn.csv o=./outdat/out111nfn.csv


#traが先に終わる
${pfxc}mcommon      k=顧客 i=./indat/dat2.csv    m=./indat/dat9.csv    o=./outdat/out112.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2.csv    m=./indat/dat9.csv    o=./outdat/out112x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2nfn.csv m=./indat/dat9nfn.csv o=./outdat/out112nfn.csv

#マスタが先に終わる
${pfxc}mcommon      k=顧客 i=./indat/dat2.csv    m=./indat/dat10.csv    o=./outdat/out113.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2.csv    m=./indat/dat10.csv    o=./outdat/out113x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2nfn.csv m=./indat/dat10nfn.csv o=./outdat/out113nfn.csv

#同時に終わる
${pfxc}mcommon      k=顧客 i=./indat/dat2.csv    m=./indat/dat11.csv    o=./outdat/out114.csv
${pfxc}mcommon -x   k=0    i=./indat/dat2.csv    m=./indat/dat11.csv    o=./outdat/out114x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat2nfn.csv m=./indat/dat11nfn.csv o=./outdat/out114nfn.csv


#一件もマッチしない
${pfxc}mcommon      k=顧客 i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out115.csv
${pfxc}mcommon -x   k=0    i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out115x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat12nfn.csv m=./indat/dat13nfn.csv o=./outdat/out115nfn.csv

#全部マッチ
${pfxc}mcommon      k=顧客 i=./indat/dat12.csv    m=./indat/dat14.csv    o=./outdat/out116.csv
${pfxc}mcommon -x   k=0    i=./indat/dat12.csv    m=./indat/dat14.csv    o=./outdat/out116x.csv
${pfxc}mcommon -nfn k=0    i=./indat/dat12nfn.csv m=./indat/dat14nfn.csv o=./outdat/out116nfn.csv

#k,KにNULL(2つ)
${pfxc}mcommon      k=顧客,日付 K=顧客ID,来店日 i=./indat/dat15.csv    m=./indat/dat16.csv    o=./outdat/out117.csv    u=./outdat/out118.csv
${pfxc}mcommon -x   k=0,3       K=0,2           i=./indat/dat15.csv    m=./indat/dat16.csv    o=./outdat/out117x.csv   u=./outdat/out118x.csv
${pfxc}mcommon -nfn k=0,3       K=0,2           i=./indat/dat15nfn.csv m=./indat/dat16nfn.csv o=./outdat/out117nfn.csv u=./outdat/out118nfn.csv
