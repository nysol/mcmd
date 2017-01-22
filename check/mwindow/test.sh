#!/bin/bash

. ../env

#name_kg_mcmd window


#NULLデータ
${pfxc}mwindow       wk=日付:date t=2 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mwindow -x    wk=0:date    t=2 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mwindow -nfn  wk=0         t=2 i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mwindow -nfno wk=日付      t=2 i=./indat/dat0.csv    o=./outdat/out0nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=2 i=./indat/dat0.csv    o=./outdat/out0nfnox.csv

#基本
${pfxc}mwindow       wk=日付:date t=2 i=./indat/dat1s.csv    o=./outdat/out1.csv
${pfxc}mwindow -x    wk=0:date    t=2 i=./indat/dat1s.csv    o=./outdat/out1x.csv
${pfxc}mwindow -nfn  wk=0         t=2 i=./indat/dat1snfn.csv o=./outdat/out1nfn.csv
${pfxc}mwindow -nfno wk=日付      t=2 i=./indat/dat1s.csv    o=./outdat/out1nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=2 i=./indat/dat1s.csv    o=./outdat/out1nfnox.csv
${pfxc}mwindow -q    wk=日付:date t=2 i=./indat/dat1s.csv    o=./outdat/out1q.csv
${pfxc}mwindow -q -x wk=0:date    t=2 i=./indat/dat1s.csv    o=./outdat/out1qx.csv

#t=0(t=1と同じ)
${pfxc}mwindow       wk=日付:date t=0 i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mwindow -x    wk=0:date    t=0 i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mwindow -nfn  wk=0         t=0 i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mwindow -nfno wk=日付      t=0 i=./indat/dat1s.csv    o=./outdat/out2nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=0 i=./indat/dat1s.csv    o=./outdat/out2nfnox.csv

#t=-1(t=1と同じ)
${pfxc}mwindow       wk=日付:date t=-1 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mwindow -x    wk=0:date    t=-1 i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mwindow -nfn  wk=0         t=-1 i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}mwindow -nfno wk=日付      t=-1 i=./indat/dat1s.csv    o=./outdat/out3nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=-1 i=./indat/dat1s.csv    o=./outdat/out3nfnox.csv

#t=1
${pfxc}mwindow       wk=日付:date t=1 i=./indat/dat1s.csv    o=./outdat/out4.csv
${pfxc}mwindow -x    wk=0:date    t=1 i=./indat/dat1s.csv    o=./outdat/out4x.csv
${pfxc}mwindow -nfn  wk=0         t=1 i=./indat/dat1snfn.csv o=./outdat/out4nfn.csv
${pfxc}mwindow -nfno wk=日付      t=1 i=./indat/dat1s.csv    o=./outdat/out4nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=1 i=./indat/dat1s.csv    o=./outdat/out4nfnox.csv

#t=100(範囲外データが出力されない)
${pfxc}mwindow       wk=日付:date t=100 i=./indat/dat1s.csv    o=./outdat/out5.csv
${pfxc}mwindow -x    wk=0:date    t=100 i=./indat/dat1s.csv    o=./outdat/out5x.csv
${pfxc}mwindow -nfn  wk=0         t=100 i=./indat/dat1snfn.csv o=./outdat/out5nfn.csv
${pfxc}mwindow -nfno wk=日付      t=100 i=./indat/dat1s.csv    o=./outdat/out5nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=100 i=./indat/dat1s.csv    o=./outdat/out5nfnox.csv

#-n指定(t=100)
${pfxc}mwindow      -n  wk=日付:date t=100 i=./indat/dat1s.csv    o=./outdat/out6.csv
${pfxc}mwindow -x   -n  wk=0:date    t=100 i=./indat/dat1s.csv    o=./outdat/out6x.csv
${pfxc}mwindow -nfn -n  wk=0         t=100 i=./indat/dat1snfn.csv o=./outdat/out6nfn.csv
${pfxc}mwindow -nfno -n wk=日付      t=100 i=./indat/dat1s.csv    o=./outdat/out6nfno.csv
${pfxc}mwindow -nfno -x -n wk=0      t=100 i=./indat/dat1s.csv    o=./outdat/out6nfnox.csv

#wk=の指定2つ
${pfxc}mwindow       wk=日付:date,日付２:date2 t=3 i=./indat/dat1s.csv o=./outdat/out7.csv
${pfxc}mwindow -x    wk=0:date,2:date2 t=3 i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mwindow -nfn  wk=0,2            t=3 i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv
${pfxc}mwindow -nfno wk=日付,日付２    t=3 i=./indat/dat1s.csv    o=./outdat/out7nfno.csv
${pfxc}mwindow -nfno -x wk=0,2         t=3 i=./indat/dat1s.csv    o=./outdat/out7nfnox.csv

#-r指定(先頭行取得)
${pfxc}mwindow       -r wk=日付:date t=2 i=./indat/dat1s.csv    o=./outdat/out8.csv
${pfxc}mwindow -x    -r wk=0:date    t=2 i=./indat/dat1s.csv    o=./outdat/out8x.csv
${pfxc}mwindow -nfn  -r wk=0         t=2 i=./indat/dat1snfn.csv o=./outdat/out8nfn.csv
${pfxc}mwindow -nfno -r wk=日付      t=2 i=./indat/dat1s.csv    o=./outdat/out8nfno.csv
${pfxc}mwindow -nfno -x -r wk=0      t=2 i=./indat/dat1s.csv    o=./outdat/out8nfnox.csv

#-n(t=100),wk=の指定2つ
${pfxc}mwindow       -n wk=日付:date,日付２:date2 t=100 i=./indat/dat1s.csv o=./outdat/out9.csv
${pfxc}mwindow -x    -n wk=0:date,2:date2 t=100 i=./indat/dat1s.csv    o=./outdat/out9x.csv
${pfxc}mwindow -nfn  -n wk=0,2            t=100 i=./indat/dat1snfn.csv o=./outdat/out9nfn.csv
${pfxc}mwindow -nfno -n wk=日付,日付２    t=100 i=./indat/dat1s.csv    o=./outdat/out9nfno.csv
${pfxc}mwindow -nfno -x -n wk=0,2         t=100 i=./indat/dat1s.csv    o=./outdat/out9nfnox.csv

#-r(先頭行取得),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -n -r wk=日付:date,日付２:date2 t=100 i=./indat/dat1s.csv o=./outdat/out10.csv
${pfxc}mwindow -x    -n -r wk=0:date,2:date2 t=100 i=./indat/dat1s.csv    o=./outdat/out10x.csv
${pfxc}mwindow -nfn  -n -r wk=0,2            t=100 i=./indat/dat1snfn.csv o=./outdat/out10nfn.csv
${pfxc}mwindow -nfno -n -r wk=日付,日付２    t=100 i=./indat/dat1s.csv    o=./outdat/out10nfno.csv
${pfxc}mwindow -nfno -x -n -r wk=0,2         t=100 i=./indat/dat1s.csv    o=./outdat/out10nfnox.csv

#部分的にNULLが入っているもの
${pfxc}mwindow       wk=日付:date,日付２:date2 t=3 i=./indat/dat2s.csv o=./outdat/out18.csv
${pfxc}mwindow -x    wk=0:date,2:date2 t=3 i=./indat/dat2s.csv    o=./outdat/out18x.csv
${pfxc}mwindow -nfn  wk=0,2            t=3 i=./indat/dat2snfn.csv o=./outdat/out18nfn.csv
${pfxc}mwindow -nfno wk=日付,日付２    t=3 i=./indat/dat2s.csv    o=./outdat/out18nfno.csv
${pfxc}mwindow -nfno -x wk=0,2         t=3 i=./indat/dat2s.csv    o=./outdat/out18nfnox.csv

#wk=日付以外
${pfxc}mwindow       wk=日付:date,その他:other t=3 i=./indat/dat2s.csv o=./outdat/out11.csv
${pfxc}mwindow -x    wk=0:date,3:other t=3 i=./indat/dat2s.csv    o=./outdat/out11x.csv
${pfxc}mwindow -nfn  wk=0,3            t=3 i=./indat/dat2snfn.csv o=./outdat/out11nfn.csv
${pfxc}mwindow -nfno wk=日付,その他    t=3 i=./indat/dat2s.csv    o=./outdat/out11nfno.csv
${pfxc}mwindow -nfno -x wk=0,3         t=3 i=./indat/dat2s.csv    o=./outdat/out11nfnox.csv

#部分的にNULLが入っているもの,r(先頭行取得),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -n -r wk=日付:date,日付２:date2 t=100 i=./indat/dat2s.csv o=./outdat/out12.csv
${pfxc}mwindow -x    -n -r wk=0:date,2:date2 t=100 i=./indat/dat2s.csv    o=./outdat/out12x.csv
${pfxc}mwindow -nfn  -n -r wk=0,2            t=100 i=./indat/dat2snfn.csv o=./outdat/out12nfn.csv
${pfxc}mwindow -nfno -n -r wk=日付,日付２    t=100 i=./indat/dat2s.csv    o=./outdat/out12nfno.csv
${pfxc}mwindow -nfno -n -r -x wk=0,2         t=100 i=./indat/dat2s.csv    o=./outdat/out12nfnox.csv

#キー項目指定
${pfxc}mwindow       k=分類 wk=日付:date t=2 i=./indat/dat3s.csv    o=./outdat/out13.csv
${pfxc}mwindow -x    k=0 wk=1:date       t=2 i=./indat/dat3s.csv o=./outdat/out13x.csv
${pfxc}mwindow -nfn  k=0 wk=1            t=2 i=./indat/dat3snfn.csv    o=./outdat/out13nfn.csv
${pfxc}mwindow -nfno k=分類 wk=日付:date t=2 i=./indat/dat3s.csv    o=./outdat/out13nfno.csv
${pfxc}mwindow -nfno -x k=0 wk=1         t=2 i=./indat/dat3s.csv    o=./outdat/out13nfnox.csv

#キー項目指定(2つ)
${pfxc}mwindow       k=分類,分類２ wk=日付:date t=2 i=./indat/dat4s.csv    o=./outdat/out14.csv
${pfxc}mwindow -x    k=0,1         wk=2:date    t=2 i=./indat/dat4s.csv o=./outdat/out14x.csv
${pfxc}mwindow -nfn  k=0,1         wk=2         t=2 i=./indat/dat4snfn.csv o=./outdat/out14nfn.csv
${pfxc}mwindow -nfno k=分類,分類２ wk=日付:date t=2 i=./indat/dat4s.csv    o=./outdat/out14nfno.csv
${pfxc}mwindow -nfno -x k=0,1      wk=2         t=2 i=./indat/dat4s.csv    o=./outdat/out14nfnox.csv

#キー項目指定(2つ),-r(先頭行取得)
#-r(先頭行取得),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -r k=分類,分類２ wk=日付:date t=3 i=./indat/dat4s.csv    o=./outdat/out15.csv
${pfxc}mwindow -x    -r k=0,1         wk=2:date    t=3 i=./indat/dat4s.csv o=./outdat/out15x.csv
${pfxc}mwindow -nfn  -r k=0,1         wk=2         t=3 i=./indat/dat4snfn.csv o=./outdat/out15nfn.csv
${pfxc}mwindow -nfno -r k=分類,分類２ wk=日付:date t=3 i=./indat/dat4s.csv    o=./outdat/out15nfno.csv
${pfxc}mwindow -nfno -x -r k=0,1      wk=2         t=3 i=./indat/dat4s.csv    o=./outdat/out15nfnox.csv

#キー項目指定(2つ),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -n k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4s.csv    o=./outdat/out16.csv
${pfxc}mwindow -x    -n k=0,1         wk=2:date,3:val     t=3 i=./indat/dat4s.csv o=./outdat/out16x.csv
${pfxc}mwindow -nfn  -n k=0,1         wk=2,3              t=3 i=./indat/dat4snfn.csv o=./outdat/out16nfn.csv
${pfxc}mwindow -nfno -n k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4s.csv    o=./outdat/out16nfno.csv
${pfxc}mwindow -nfno -x -n k=0,1      wk=2,3              t=3 i=./indat/dat4s.csv    o=./outdat/out16nfnox.csv

#キー項目指定(2つ),-n(指定行数に満たない場合も出力),-r(先頭行取得),wk=の指定2つ
${pfxc}mwindow       -n -r k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4s.csv    o=./outdat/out17.csv
${pfxc}mwindow -x    -n -r k=0,1         wk=2:date,3:val     t=3 i=./indat/dat4s.csv o=./outdat/out17x.csv
${pfxc}mwindow -nfn  -n -r k=0,1         wk=2,3              t=3 i=./indat/dat4snfn.csv o=./outdat/out17nfn.csv
${pfxc}mwindow -nfno -n -r k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4s.csv    o=./outdat/out17nfno.csv
${pfxc}mwindow -nfno -x -n -r k=0,1      wk=2,3              t=3 i=./indat/dat4s.csv    o=./outdat/out17nfnox.csv

#ランダムデータ
#基本
${pfxc}mwindow       wk=日付:date t=2 i=./indat/dat1.csv    o=./outdat/out31.csv
${pfxc}mwindow -x    wk=0:date    t=2 i=./indat/dat1.csv    o=./outdat/out31x.csv
${pfxc}mwindow -nfn  wk=0         t=2 i=./indat/dat1nfn.csv o=./outdat/out31nfn.csv
${pfxc}mwindow -nfno wk=日付      t=2 i=./indat/dat1.csv    o=./outdat/out31nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=2 i=./indat/dat1.csv    o=./outdat/out31nfnox.csv
${pfxc}mwindow -q    wk=日付:date t=2 i=./indat/dat1.csv    o=./outdat/out31q.csv
${pfxc}mwindow -q -x wk=0:date    t=2 i=./indat/dat1.csv    o=./outdat/out31qx.csv

#t=0(t=1と同じ)
${pfxc}mwindow       wk=日付:date t=0 i=./indat/dat1.csv    o=./outdat/out32.csv
${pfxc}mwindow -x    wk=0:date    t=0 i=./indat/dat1.csv    o=./outdat/out32x.csv
${pfxc}mwindow -nfn  wk=0         t=0 i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv
${pfxc}mwindow -nfno wk=日付      t=0 i=./indat/dat1.csv    o=./outdat/out32nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=0 i=./indat/dat1.csv    o=./outdat/out32nfnox.csv

#t=-1(t=1と同じ)
${pfxc}mwindow       wk=日付:date t=-1 i=./indat/dat1.csv    o=./outdat/out33.csv
${pfxc}mwindow -x    wk=0:date    t=-1 i=./indat/dat1.csv    o=./outdat/out33x.csv
${pfxc}mwindow -nfn  wk=0         t=-1 i=./indat/dat1nfn.csv o=./outdat/out33nfn.csv
${pfxc}mwindow -nfno wk=日付      t=-1 i=./indat/dat1.csv    o=./outdat/out33nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=-1 i=./indat/dat1.csv    o=./outdat/out33nfnox.csv

#t=1
${pfxc}mwindow       wk=日付:date t=1 i=./indat/dat1.csv    o=./outdat/out34.csv
${pfxc}mwindow -x    wk=0:date    t=1 i=./indat/dat1.csv    o=./outdat/out34x.csv
${pfxc}mwindow -nfn  wk=0         t=1 i=./indat/dat1nfn.csv o=./outdat/out34nfn.csv
${pfxc}mwindow -nfno wk=日付      t=1 i=./indat/dat1.csv    o=./outdat/out34nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=1 i=./indat/dat1.csv    o=./outdat/out34nfnox.csv

#t=100(範囲外データが出力されない)
${pfxc}mwindow       wk=日付:date t=100 i=./indat/dat1.csv    o=./outdat/out35.csv
${pfxc}mwindow -x    wk=0:date    t=100 i=./indat/dat1.csv    o=./outdat/out35x.csv
${pfxc}mwindow -nfn  wk=0         t=100 i=./indat/dat1nfn.csv o=./outdat/out35nfn.csv
${pfxc}mwindow -nfno wk=日付      t=100 i=./indat/dat1.csv    o=./outdat/out35nfno.csv
${pfxc}mwindow -nfno -x wk=0      t=100 i=./indat/dat1.csv    o=./outdat/out35nfnox.csv

#-n指定(t=100)
${pfxc}mwindow      -n  wk=日付:date t=100 i=./indat/dat1.csv    o=./outdat/out36.csv
${pfxc}mwindow -x   -n  wk=0:date    t=100 i=./indat/dat1.csv    o=./outdat/out36x.csv
${pfxc}mwindow -nfn -n  wk=0         t=100 i=./indat/dat1nfn.csv o=./outdat/out36nfn.csv
${pfxc}mwindow -nfno -n wk=日付      t=100 i=./indat/dat1.csv    o=./outdat/out36nfno.csv
${pfxc}mwindow -nfno -x -n wk=0      t=100 i=./indat/dat1.csv    o=./outdat/out36nfnox.csv

#wk=の指定2つ
${pfxc}mwindow       wk=日付:date,日付２:date2 t=3 i=./indat/dat1.csv o=./outdat/out37.csv
${pfxc}mwindow -x    wk=0:date,2:date2 t=3 i=./indat/dat1.csv    o=./outdat/out37x.csv
${pfxc}mwindow -nfn  wk=0,2            t=3 i=./indat/dat1nfn.csv o=./outdat/out37nfn.csv
${pfxc}mwindow -nfno wk=日付,日付２    t=3 i=./indat/dat1.csv    o=./outdat/out37nfno.csv
${pfxc}mwindow -nfno -x wk=0,2         t=3 i=./indat/dat1.csv    o=./outdat/out37nfnox.csv

#-r指定(先頭行取得)
${pfxc}mwindow       -r wk=日付:date t=2 i=./indat/dat1.csv    o=./outdat/out38.csv
${pfxc}mwindow -x    -r wk=0:date    t=2 i=./indat/dat1.csv    o=./outdat/out38x.csv
${pfxc}mwindow -nfn  -r wk=0         t=2 i=./indat/dat1nfn.csv o=./outdat/out38nfn.csv
${pfxc}mwindow -nfno -r wk=日付      t=2 i=./indat/dat1.csv    o=./outdat/out38nfno.csv
${pfxc}mwindow -nfno -x -r wk=0      t=2 i=./indat/dat1.csv    o=./outdat/out38nfnox.csv

#-n(t=100),wk=の指定2つ
${pfxc}mwindow       -n wk=日付:date,日付２:date2 t=100 i=./indat/dat1.csv o=./outdat/out39.csv
${pfxc}mwindow -x    -n wk=0:date,2:date2 t=100 i=./indat/dat1.csv    o=./outdat/out39x.csv
${pfxc}mwindow -nfn  -n wk=0,2            t=100 i=./indat/dat1nfn.csv o=./outdat/out39nfn.csv
${pfxc}mwindow -nfno -n wk=日付,日付２    t=100 i=./indat/dat1.csv    o=./outdat/out39nfno.csv
${pfxc}mwindow -nfno -x -n wk=0,2         t=100 i=./indat/dat1.csv    o=./outdat/out39nfnox.csv

#-r(先頭行取得),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -n -r wk=日付:date,日付２:date2 t=100 i=./indat/dat1.csv o=./outdat/out40.csv
${pfxc}mwindow -x    -n -r wk=0:date,2:date2 t=100 i=./indat/dat1.csv    o=./outdat/out40x.csv
${pfxc}mwindow -nfn  -n -r wk=0,2            t=100 i=./indat/dat1nfn.csv o=./outdat/out40nfn.csv
${pfxc}mwindow -nfno -n -r wk=日付,日付２    t=100 i=./indat/dat1.csv    o=./outdat/out40nfno.csv
${pfxc}mwindow -nfno -x -n -r wk=0,2         t=100 i=./indat/dat1.csv    o=./outdat/out40nfnox.csv

#部分的にNULLが入っているもの
${pfxc}mwindow       wk=日付:date,日付２:date2 t=3 i=./indat/dat2.csv o=./outdat/out48.csv
${pfxc}mwindow -x    wk=0:date,2:date2 t=3 i=./indat/dat2.csv    o=./outdat/out48x.csv
${pfxc}mwindow -nfn  wk=0,2            t=3 i=./indat/dat2nfn.csv o=./outdat/out48nfn.csv
${pfxc}mwindow -nfno wk=日付,日付２    t=3 i=./indat/dat2.csv    o=./outdat/out48nfno.csv
${pfxc}mwindow -nfno -x wk=0,2         t=3 i=./indat/dat2.csv    o=./outdat/out48nfnox.csv

#wk=日付以外
${pfxc}mwindow       wk=日付:date,その他:other t=3 i=./indat/dat2.csv o=./outdat/out41.csv
${pfxc}mwindow -x    wk=0:date,3:other t=3 i=./indat/dat2.csv    o=./outdat/out41x.csv
${pfxc}mwindow -nfn  wk=0,3            t=3 i=./indat/dat2nfn.csv o=./outdat/out41nfn.csv
${pfxc}mwindow -nfno wk=日付,その他    t=3 i=./indat/dat2.csv    o=./outdat/out41nfno.csv
${pfxc}mwindow -nfno -x wk=0,3         t=3 i=./indat/dat2.csv    o=./outdat/out41nfnox.csv

#部分的にNULLが入っているもの,r(先頭行取得),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -n -r wk=日付:date,日付２:date2 t=100 i=./indat/dat2.csv o=./outdat/out42.csv
${pfxc}mwindow -x    -n -r wk=0:date,2:date2 t=100 i=./indat/dat2.csv    o=./outdat/out42x.csv
${pfxc}mwindow -nfn  -n -r wk=0,2            t=100 i=./indat/dat2nfn.csv o=./outdat/out42nfn.csv
${pfxc}mwindow -nfno -n -r wk=日付,日付２    t=100 i=./indat/dat2.csv    o=./outdat/out42nfno.csv
${pfxc}mwindow -nfno -n -r -x wk=0,2         t=100 i=./indat/dat2.csv    o=./outdat/out42nfnox.csv

#キー項目指定
${pfxc}mwindow       k=分類 wk=日付:date t=2 i=./indat/dat3.csv    o=./outdat/out43.csv
${pfxc}mwindow -x    k=0 wk=1:date       t=2 i=./indat/dat3.csv o=./outdat/out43x.csv
${pfxc}mwindow -nfn  k=0 wk=1            t=2 i=./indat/dat3nfn.csv    o=./outdat/out43nfn.csv
${pfxc}mwindow -nfno k=分類 wk=日付:date t=2 i=./indat/dat3.csv    o=./outdat/out43nfno.csv
${pfxc}mwindow -nfno -x k=0 wk=1         t=2 i=./indat/dat3.csv    o=./outdat/out43nfnox.csv

#キー項目指定(2つ)
${pfxc}mwindow       k=分類,分類２ wk=日付:date t=2 i=./indat/dat4.csv    o=./outdat/out44.csv
${pfxc}mwindow -x    k=0,1         wk=2:date    t=2 i=./indat/dat4.csv o=./outdat/out44x.csv
${pfxc}mwindow -nfn  k=0,1         wk=2         t=2 i=./indat/dat4nfn.csv o=./outdat/out44nfn.csv
${pfxc}mwindow -nfno k=分類,分類２ wk=日付:date t=2 i=./indat/dat4.csv    o=./outdat/out44nfno.csv
${pfxc}mwindow -nfno -x k=0,1      wk=2         t=2 i=./indat/dat4.csv    o=./outdat/out44nfnox.csv

#キー項目指定(2つ),-r(先頭行取得)
#-r(先頭行取得),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -r k=分類,分類２ wk=日付:date t=3 i=./indat/dat4.csv    o=./outdat/out45.csv
${pfxc}mwindow -x    -r k=0,1         wk=2:date    t=3 i=./indat/dat4.csv o=./outdat/out45x.csv
${pfxc}mwindow -nfn  -r k=0,1         wk=2         t=3 i=./indat/dat4nfn.csv o=./outdat/out45nfn.csv
${pfxc}mwindow -nfno -r k=分類,分類２ wk=日付:date t=3 i=./indat/dat4.csv    o=./outdat/out45nfno.csv
${pfxc}mwindow -nfno -x -r k=0,1      wk=2         t=3 i=./indat/dat4.csv    o=./outdat/out45nfnox.csv

#キー項目指定(2つ),-n(指定行数に満たない場合も出力),wk=の指定2つ
${pfxc}mwindow       -n k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4.csv    o=./outdat/out46.csv
${pfxc}mwindow -x    -n k=0,1         wk=2:date,3:val     t=3 i=./indat/dat4.csv o=./outdat/out46x.csv
${pfxc}mwindow -nfn  -n k=0,1         wk=2,3              t=3 i=./indat/dat4nfn.csv o=./outdat/out46nfn.csv
${pfxc}mwindow -nfno -n k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4.csv    o=./outdat/out46nfno.csv
${pfxc}mwindow -nfno -x -n k=0,1      wk=2,3              t=3 i=./indat/dat4.csv    o=./outdat/out46nfnox.csv

#キー項目指定(2つ),-n(指定行数に満たない場合も出力),-r(先頭行取得),wk=の指定2つ
${pfxc}mwindow       -n -r k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4.csv    o=./outdat/out47.csv
${pfxc}mwindow -x    -n -r k=0,1         wk=2:date,3:val     t=3 i=./indat/dat4.csv o=./outdat/out47x.csv
${pfxc}mwindow -nfn  -n -r k=0,1         wk=2,3              t=3 i=./indat/dat4nfn.csv o=./outdat/out47nfn.csv
${pfxc}mwindow -nfno -n -r k=分類,分類２ wk=日付:date,値:val t=3 i=./indat/dat4.csv    o=./outdat/out47nfno.csv
${pfxc}mwindow -nfno -x -n -r k=0,1      wk=2,3              t=3 i=./indat/dat4.csv    o=./outdat/out47nfnox.csv


