#!/bin/bash

. ../env

#name_kg_mcmd slide

#k=,f=指定
#ヘッダのみ
${pfxc}mslide          k=顧客  s=日付 f=日付:次日付 i=./indat/dat0s.csv    o=./outdat/out01.csv
${pfxc}mslide -nfno    k=顧客  s=日付 f=日付:次日付 i=./indat/dat0s.csv    o=./outdat/out01nfno.csv
${pfxc}mslide -x       k=0    s=1    f=1:次日付   i=./indat/dat0s.csv    o=./outdat/out01x.csv
${pfxc}mslide -nfn     k=0    s=1    f=1         i=./indat/dat0snfn.csv o=./outdat/out01nfn.csv
${pfxc}mslide -nfno -x k=0    s=1    f=1         i=./indat/dat0s.csv    o=./outdat/out01nfnox.csv

#通常
${pfxc}mslide          k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out02.csv
${pfxc}mslide -nfno    k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out02nfno.csv
${pfxc}mslide -x       k=0    s=1   f=1:次日付   i=./indat/dat1s.csv    o=./outdat/out02x.csv
${pfxc}mslide -nfn     k=0    s=1   f=1         i=./indat/dat1snfn.csv o=./outdat/out02nfn.csv
${pfxc}mslide -nfno -x k=0    s=1   f=1         i=./indat/dat1s.csv    o=./outdat/out02nfnox.csv
${pfxc}mslide -q       k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out02q.csv
${pfxc}mslide -q -x    k=0    s=1   f=1:次日付   i=./indat/dat1s.csv    o=./outdat/out02qx.csv

#nullあり
${pfxc}mslide          k=顧客 s=日付 f=日付:次日付 i=./indat/dat2s.csv    o=./outdat/out03.csv
${pfxc}mslide -nfno    k=顧客 s=日付 f=日付:次日付 i=./indat/dat2s.csv    o=./outdat/out03nfno.csv
${pfxc}mslide -x       k=0    s=1   f=1:次日付   i=./indat/dat2s.csv    o=./outdat/out03x.csv
${pfxc}mslide -nfn     k=0    s=1   f=1         i=./indat/dat2snfn.csv o=./outdat/out03nfn.csv
${pfxc}mslide -nfno -x k=0    s=1   f=1         i=./indat/dat2s.csv    o=./outdat/out03nfnox.csv

#f=指定
${pfxc}mslide          s=顧客 f=日付:次日付 i=./indat/dat0s.csv    o=./outdat/out04.csv
${pfxc}mslide -nfno    s=顧客 f=日付:次日付 i=./indat/dat0s.csv    o=./outdat/out04nfno.csv
${pfxc}mslide -x       s=0   f=1:次日付    i=./indat/dat0s.csv    o=./outdat/out04x.csv
${pfxc}mslide -nfn     s=0   f=1          i=./indat/dat0snfn.csv o=./outdat/out04nfn.csv
${pfxc}mslide -nfno -x s=0   f=1          i=./indat/dat0s.csv    o=./outdat/out04nfnox.csv

${pfxc}mslide          s=日付 f=日付:次日付 i=./indat/dat1ss.csv    o=./outdat/out05.csv
${pfxc}mslide -nfno    s=日付 f=日付:次日付 i=./indat/dat1ss.csv    o=./outdat/out05nfno.csv
${pfxc}mslide -x       s=1   f=1:次日付    i=./indat/dat1ss.csv    o=./outdat/out05x.csv
${pfxc}mslide -nfn     s=1   f=1          i=./indat/dat1ssnfn.csv o=./outdat/out05nfn.csv
${pfxc}mslide -nfno -x s=1   f=1          i=./indat/dat1ss.csv    o=./outdat/out05nfnox.csv

${pfxc}mslide          s=日付 f=日付:次日付 i=./indat/dat2ss.csv    o=./outdat/out06.csv
${pfxc}mslide -nfno    s=日付 f=日付:次日付 i=./indat/dat2ss.csv    o=./outdat/out06nfno.csv
${pfxc}mslide -x       s=1   f=1:次日付    i=./indat/dat2ss.csv    o=./outdat/out06x.csv
${pfxc}mslide -nfn     s=1   f=1          i=./indat/dat2ssnfn.csv o=./outdat/out06nfn.csv
${pfxc}mslide -nfno -x s=1   f=1          i=./indat/dat2ss.csv    o=./outdat/out06nfnox.csv

#k=,f=,-n指定
${pfxc}mslide          -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat0s.csv    o=./outdat/out07.csv
${pfxc}mslide -nfno    -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat0s.csv    o=./outdat/out07nfno.csv
${pfxc}mslide -x       -n k=0    s=1   f=1:次日付   i=./indat/dat0s.csv    o=./outdat/out07x.csv
${pfxc}mslide -nfn     -n k=0    s=1   f=1         i=./indat/dat0snfn.csv o=./outdat/out07nfn.csv
${pfxc}mslide -nfno -x -n k=0    s=1   f=1         i=./indat/dat0s.csv    o=./outdat/out07nfnox.csv

${pfxc}mslide          -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out08.csv
${pfxc}mslide -nfno    -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out08nfno.csv
${pfxc}mslide -x       -n k=0   s=1    f=1:次日付   i=./indat/dat1s.csv    o=./outdat/out08x.csv
${pfxc}mslide -nfn     -n k=0   s=1    f=1         i=./indat/dat1snfn.csv o=./outdat/out08nfn.csv
${pfxc}mslide -nfno -x -n k=0   s=1    f=1         i=./indat/dat1s.csv    o=./outdat/out08nfnox.csv

${pfxc}mslide          -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2s.csv    o=./outdat/out09.csv
${pfxc}mslide -nfno    -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2s.csv    o=./outdat/out09nfno.csv
${pfxc}mslide -x       -n k=0   s=1    f=1:次日付   i=./indat/dat2s.csv    o=./outdat/out09x.csv
${pfxc}mslide -nfn     -n k=0   s=1    f=1         i=./indat/dat2snfn.csv o=./outdat/out09nfn.csv
${pfxc}mslide -nfno -x -n k=0   s=1    f=1         i=./indat/dat2s.csv    o=./outdat/out09nfnox.csv

#f=,-n指定
${pfxc}mslide          -n s=日付 f=日付:次日付 i=./indat/dat1ss.csv    o=./outdat/out10.csv
${pfxc}mslide -nfno    -n s=日付 f=日付:次日付 i=./indat/dat1ss.csv    o=./outdat/out10nfno.csv
${pfxc}mslide -x       -n s=1   f=1:次日付    i=./indat/dat1ss.csv    o=./outdat/out10x.csv
${pfxc}mslide -nfn     -n s=1   f=1          i=./indat/dat1ssnfn.csv o=./outdat/out10nfn.csv
${pfxc}mslide -nfno -x -n s=1   f=1          i=./indat/dat1ss.csv    o=./outdat/out10nfnox.csv

${pfxc}mslide          -n s=日付 f=日付:次日付 i=./indat/dat2ss.csv    o=./outdat/out11.csv
${pfxc}mslide -nfno    -n s=日付 f=日付:次日付 i=./indat/dat2ss.csv    o=./outdat/out11nfno.csv
${pfxc}mslide -x       -n s=1   f=1:次日付    i=./indat/dat2ss.csv    o=./outdat/out11x.csv
${pfxc}mslide -nfn     -n s=1   f=1          i=./indat/dat2ssnfn.csv o=./outdat/out11nfn.csv
${pfxc}mslide -nfno -x -n s=1   f=1          i=./indat/dat2ss.csv    o=./outdat/out11nfnox.csv

#f=,-r指定
${pfxc}mslide          -r s=日付 f=日付:次日付 i=./indat/dat1ss.csv    o=./outdat/out12.csv
${pfxc}mslide -nfno    -r s=日付 f=日付:次日付 i=./indat/dat1ss.csv    o=./outdat/out12nfno.csv
${pfxc}mslide -x       -r s=1   f=1:次日付    i=./indat/dat1ss.csv    o=./outdat/out12x.csv
${pfxc}mslide -nfn     -r s=1   f=1          i=./indat/dat1ssnfn.csv o=./outdat/out12nfn.csv
${pfxc}mslide -nfno -x -r s=1   f=1          i=./indat/dat1ss.csv    o=./outdat/out12nfnox.csv

${pfxc}mslide          -r s=日付 f=日付:次日付 i=./indat/dat2ss.csv    o=./outdat/out13.csv
${pfxc}mslide -nfno    -r s=日付 f=日付:次日付 i=./indat/dat2ss.csv    o=./outdat/out13nfno.csv
${pfxc}mslide -x       -r s=1   f=1:次日付    i=./indat/dat2ss.csv    o=./outdat/out13x.csv
${pfxc}mslide -nfn     -r s=1   f=1          i=./indat/dat2ssnfn.csv o=./outdat/out13nfn.csv
${pfxc}mslide -nfno -x -r s=1   f=1          i=./indat/dat2ss.csv    o=./outdat/out13nfnox.csv

#k=,f=,-r指定
${pfxc}mslide          -r k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out14.csv
${pfxc}mslide -nfno    -r k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out14nfno.csv
${pfxc}mslide -x       -r k=0   s=1    f=1:次日付   i=./indat/dat1s.csv    o=./outdat/out14x.csv
${pfxc}mslide -nfn     -r k=0   s=1    f=1         i=./indat/dat1snfn.csv o=./outdat/out14nfn.csv
${pfxc}mslide -nfno -x -r k=0   s=1    f=1         i=./indat/dat1s.csv    o=./outdat/out14nfnox.csv

${pfxc}mslide          -r k=顧客 s=日付 f=日付:次日付  i=./indat/dat2s.csv    o=./outdat/out15.csv
${pfxc}mslide -nfno    -r k=顧客 s=日付 f=日付:次日付  i=./indat/dat2s.csv    o=./outdat/out15nfno.csv
${pfxc}mslide -x       -r k=0   s=1    f=1:次日付    i=./indat/dat2s.csv    o=./outdat/out15x.csv
${pfxc}mslide -nfn     -r k=0   s=1    f=1          i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv
${pfxc}mslide -nfno -x -r k=0   s=1    f=1          i=./indat/dat2s.csv    o=./outdat/out15nfnox.csv

#k=,f=,-r,-n指定
${pfxc}mslide          -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out16.csv
${pfxc}mslide -nfno    -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1s.csv    o=./outdat/out16nfno.csv
${pfxc}mslide -x       -r -n k=0   s=1    f=1:次日付   i=./indat/dat1s.csv    o=./outdat/out16x.csv
${pfxc}mslide -nfn     -r -n k=0   s=1    f=1         i=./indat/dat1snfn.csv o=./outdat/out16nfn.csv
${pfxc}mslide -nfno -x -r -n k=0   s=1    f=1         i=./indat/dat1s.csv    o=./outdat/out16nfnox.csv

${pfxc}mslide          -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2s.csv    o=./outdat/out17.csv
${pfxc}mslide -nfno    -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2s.csv    o=./outdat/out17nfno.csv
${pfxc}mslide -x       -r -n k=0   s=1    f=1:次日付   i=./indat/dat2s.csv    o=./outdat/out17x.csv
${pfxc}mslide -nfn     -r -n k=0   s=1    f=1         i=./indat/dat2snfn.csv o=./outdat/out17nfn.csv
${pfxc}mslide -nfno -x -r -n k=0   s=1    f=1         i=./indat/dat2s.csv    o=./outdat/out17nfnox.csv

#f=,-r,t=3指定
${pfxc}mslide          -r t=3 s=日付 f=日付:次日付 i=./indat/dat3ss.csv    o=./outdat/out18.csv
${pfxc}mslide -nfno    -r t=3 s=日付 f=日付:次日付 i=./indat/dat3ss.csv    o=./outdat/out18nfno.csv
${pfxc}mslide -x       -r t=3 s=1   f=1:次日付    i=./indat/dat3ss.csv    o=./outdat/out18x.csv
${pfxc}mslide -nfn     -r t=3 s=1   f=1          i=./indat/dat3ssnfn.csv o=./outdat/out18nfn.csv
${pfxc}mslide -nfno -x -r t=3 s=1   f=1          i=./indat/dat3ss.csv    o=./outdat/out18nfnox.csv

#k=,f=,-r,t=3指定
${pfxc}mslide          -r t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out19.csv
${pfxc}mslide -nfno    -r t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out19nfno.csv
${pfxc}mslide -x       -r t=3 k=0    s=1   f=1:次日付   i=./indat/dat3s.csv    o=./outdat/out19x.csv
${pfxc}mslide -nfn     -r t=3 k=0    s=1   f=1         i=./indat/dat3snfn.csv o=./outdat/out19nfn.csv
${pfxc}mslide -nfno -x -r t=3 k=0    s=1   f=1         i=./indat/dat3s.csv    o=./outdat/out19nfnox.csv

#k=,f=,-r,-n,t=3指定
${pfxc}mslide          -r -n t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out20.csv
${pfxc}mslide -nfno    -r -n t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out20nfno.csv
${pfxc}mslide -x       -r -n t=3 k=0    s=1   f=1:次日付   i=./indat/dat3s.csv    o=./outdat/out20x.csv
${pfxc}mslide -nfn     -r -n t=3 k=0    s=1   f=1         i=./indat/dat3snfn.csv o=./outdat/out20nfn.csv
${pfxc}mslide -nfno -x -r -n t=3 k=0    s=1   f=1         i=./indat/dat3s.csv    o=./outdat/out20nfnox.csv

#f=,-r,t=3,-l指定
${pfxc}mslide          -r -l t=3 s=日付 f=日付:次日付 i=./indat/dat3ss.csv    o=./outdat/out21.csv
${pfxc}mslide -nfno    -r -l t=3 s=日付 f=日付:次日付 i=./indat/dat3ss.csv    o=./outdat/out21nfno.csv
${pfxc}mslide -x       -r -l t=3 s=1   f=1:次日付    i=./indat/dat3ss.csv    o=./outdat/out21x.csv
${pfxc}mslide -nfn     -r -l t=3 s=1   f=1          i=./indat/dat3ssnfn.csv o=./outdat/out21nfn.csv
${pfxc}mslide -nfno -x -r -l t=3 s=1   f=1          i=./indat/dat3ss.csv    o=./outdat/out21nfnox.csv

#k=,f=,-r,t=3,-l指定
${pfxc}mslide          -r -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out22.csv
${pfxc}mslide -nfno    -r -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out22nfno.csv
${pfxc}mslide -x       -r -l t=3 k=0   s=1    f=1:次日付   i=./indat/dat3s.csv    o=./outdat/out22x.csv
${pfxc}mslide -nfn     -r -l t=3 k=0   s=1    f=1         i=./indat/dat3snfn.csv o=./outdat/out22nfn.csv
${pfxc}mslide -nfno -x -r -l t=3 k=0   s=1    f=1         i=./indat/dat3s.csv    o=./outdat/out22nfnox.csv

#k=,f=,-r,-n,t=3,-l指定
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out23.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3s.csv    o=./outdat/out23nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0    s=1   f=1:次日付   i=./indat/dat3s.csv    o=./outdat/out23x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0    s=1   f=1         i=./indat/dat3snfn.csv o=./outdat/out23nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0    s=1   f=1         i=./indat/dat3s.csv    o=./outdat/out23nfnox.csv

#k=,f=,-r,-n,t=3,-l指定
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付 i=./indat/dat3s.csv    o=./outdat/out24.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付 i=./indat/dat3s.csv    o=./outdat/out24nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0   s=1    f=1   i=./indat/dat3s.csv    o=./outdat/out24x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0   s=1    f=1   i=./indat/dat3snfn.csv o=./outdat/out24nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0   s=1    f=1   i=./indat/dat3s.csv    o=./outdat/out24nfnox.csv

#t=3,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3ss.csv    o=./outdat/out25.csv
${pfxc}mslide -nfno    t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3ss.csv    o=./outdat/out25nfno.csv
${pfxc}mslide -x       t=3 s=1    f=1,0                  i=./indat/dat3ss.csv    o=./outdat/out25x.csv
${pfxc}mslide -nfn     t=3 s=1    f=1,0                  i=./indat/dat3ssnfn.csv o=./outdat/out25nfn.csv
${pfxc}mslide -nfno -x t=3 s=1    f=1,0                  i=./indat/dat3ss.csv    o=./outdat/out25nfnox.csv

#t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out26.csv
${pfxc}mslide -nfno    t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out26nfno.csv
${pfxc}mslide -x       t=3 k=0   s=1    f=1,0                 i=./indat/dat3s.csv    o=./outdat/out26x.csv
${pfxc}mslide -nfn     t=3 k=0   s=1    f=1,0                 i=./indat/dat3snfn.csv o=./outdat/out26nfn.csv
${pfxc}mslide -nfno -x t=3 k=0   s=1    f=1,0                 i=./indat/dat3s.csv    o=./outdat/out26nfnox.csv

#-r,t=3,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -r t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3ss.csv    o=./outdat/out27.csv
${pfxc}mslide -nfno    -r t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3ss.csv    o=./outdat/out27nfno.csv
${pfxc}mslide -x       -r t=3 s=1    f=1,0                  i=./indat/dat3ss.csv    o=./outdat/out27x.csv
${pfxc}mslide -nfn     -r t=3 s=1    f=1,0                  i=./indat/dat3ssnfn.csv o=./outdat/out27nfn.csv
${pfxc}mslide -nfno -x -r t=3 s=1    f=1,0                  i=./indat/dat3ss.csv    o=./outdat/out27nfnox.csv

#-l,t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out28.csv
${pfxc}mslide -nfno    -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out28nfno.csv
${pfxc}mslide -x       -l t=3 k=0    s=1   f=1,0                 i=./indat/dat3s.csv    o=./outdat/out28x.csv
${pfxc}mslide -nfn     -l t=3 k=0    s=1   f=1,0                 i=./indat/dat3snfn.csv o=./outdat/out28nfn.csv
${pfxc}mslide -nfno -x -l t=3 k=0    s=1   f=1,0                 i=./indat/dat3s.csv    o=./outdat/out28nfnox.csv

#-r,-l,t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -r -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out29.csv
${pfxc}mslide -nfno    -r -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out29nfno.csv
${pfxc}mslide -x       -r -l t=3 k=0   s=1    f=1,0                 i=./indat/dat3s.csv    o=./outdat/out29x.csv
${pfxc}mslide -nfn     -r -l t=3 k=0   s=1    f=1,0                 i=./indat/dat3snfn.csv o=./outdat/out29nfn.csv
${pfxc}mslide -nfno -x -r -l t=3 k=0   s=1    f=1,0                 i=./indat/dat3s.csv    o=./outdat/out29nfnox.csv

#-r,-n,-l,t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out30.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3s.csv    o=./outdat/out30nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0   s=1   f=1,0                  i=./indat/dat3s.csv    o=./outdat/out30x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0   s=1   f=1,0                  i=./indat/dat3snfn.csv o=./outdat/out30nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0   s=1   f=1,0                  i=./indat/dat3s.csv    o=./outdat/out30nfnox.csv

#-r,-n,-l,t=3,k=,f=複数項目名指定(f=3項目指定)
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付,顧客:次顧客,値 i=./indat/dat3s.csv    o=./outdat/out31.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付,顧客:次顧客,値 i=./indat/dat3s.csv    o=./outdat/out31nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0   s=1   f=1,0:次顧客,2       i=./indat/dat3s.csv    o=./outdat/out31x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0   s=1   f=1,0,2             i=./indat/dat3snfn.csv o=./outdat/out31nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0   s=1   f=1,0:次顧客,2       i=./indat/dat3s.csv    o=./outdat/out31nfnox.csv

#-l,t=3,f=複数項目名指定(f=3項目指定)
${pfxc}mslide          -l t=3 s=日付  f=日付,顧客:次顧客,値 i=./indat/dat3ss.csv    o=./outdat/out32.csv
${pfxc}mslide -nfno    -l t=3 s=日付  f=日付,顧客:次顧客,値 i=./indat/dat3ss.csv    o=./outdat/out32nfno.csv
${pfxc}mslide -x       -l t=3 s=1    f=1,0:次顧客,2       i=./indat/dat3ss.csv    o=./outdat/out32x.csv
${pfxc}mslide -nfn     -l t=3 s=1    f=1,0,2             i=./indat/dat3ssnfn.csv o=./outdat/out32nfn.csv
${pfxc}mslide -nfno -x -l t=3 s=1    f=1,0:次顧客,2       i=./indat/dat3ss.csv    o=./outdat/out32nfnox.csv




#ランダムデーラ

#k=,f=指定
#ヘッダのみ
${pfxc}mslide          k=顧客  s=日付 f=日付:次日付 i=./indat/dat0.csv    o=./outdat/out101.csv
${pfxc}mslide -nfno    k=顧客  s=日付 f=日付:次日付 i=./indat/dat0.csv    o=./outdat/out101nfno.csv
${pfxc}mslide -x       k=0    s=1    f=1:次日付   i=./indat/dat0.csv    o=./outdat/out101x.csv
${pfxc}mslide -nfn     k=0    s=1    f=1         i=./indat/dat0nfn.csv o=./outdat/out101nfn.csv
${pfxc}mslide -nfno -x k=0    s=1    f=1         i=./indat/dat0.csv    o=./outdat/out101nfnox.csv

#通常
${pfxc}mslide          k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out102.csv
${pfxc}mslide -nfno    k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out102nfno.csv
${pfxc}mslide -x       k=0    s=1   f=1:次日付   i=./indat/dat1.csv    o=./outdat/out102x.csv
${pfxc}mslide -nfn     k=0    s=1   f=1         i=./indat/dat1nfn.csv o=./outdat/out102nfn.csv
${pfxc}mslide -nfno -x k=0    s=1   f=1         i=./indat/dat1.csv    o=./outdat/out102nfnox.csv
${pfxc}mslide -q         k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out102q.csv
${pfxc}mslide -q -x       k=0    s=1   f=1:次日付   i=./indat/dat1.csv    o=./outdat/out102qx.csv


#nullあり
${pfxc}mslide          k=顧客 s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out103.csv
${pfxc}mslide -nfno    k=顧客 s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out103nfno.csv
${pfxc}mslide -x       k=0    s=1   f=1:次日付   i=./indat/dat2.csv    o=./outdat/out103x.csv
${pfxc}mslide -nfn     k=0    s=1   f=1         i=./indat/dat2nfn.csv o=./outdat/out103nfn.csv
${pfxc}mslide -nfno -x k=0    s=1   f=1         i=./indat/dat2.csv    o=./outdat/out103nfnox.csv


${pfxc}mslide          s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out105.csv
${pfxc}mslide -nfno    s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out105nfno.csv
${pfxc}mslide -x       s=1   f=1:次日付    i=./indat/dat1.csv    o=./outdat/out105x.csv
${pfxc}mslide -nfn     s=1   f=1          i=./indat/dat1nfn.csv o=./outdat/out105nfn.csv
${pfxc}mslide -nfno -x s=1   f=1          i=./indat/dat1.csv    o=./outdat/out105nfnox.csv

${pfxc}mslide          s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out106.csv
${pfxc}mslide -nfno    s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out106nfno.csv
${pfxc}mslide -x       s=1   f=1:次日付    i=./indat/dat2.csv    o=./outdat/out106x.csv
${pfxc}mslide -nfn     s=1   f=1          i=./indat/dat2nfn.csv o=./outdat/out106nfn.csv
${pfxc}mslide -nfno -x s=1   f=1          i=./indat/dat2.csv    o=./outdat/out106nfnox.csv

#k=,f=,-n指定
${pfxc}mslide          -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out108.csv
${pfxc}mslide -nfno    -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out108nfno.csv
${pfxc}mslide -x       -n k=0   s=1    f=1:次日付   i=./indat/dat1.csv    o=./outdat/out108x.csv
${pfxc}mslide -nfn     -n k=0   s=1    f=1         i=./indat/dat1nfn.csv o=./outdat/out108nfn.csv
${pfxc}mslide -nfno -x -n k=0   s=1    f=1         i=./indat/dat1.csv    o=./outdat/out108nfnox.csv

${pfxc}mslide          -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out109.csv
${pfxc}mslide -nfno    -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out109nfno.csv
${pfxc}mslide -x       -n k=0   s=1    f=1:次日付   i=./indat/dat2.csv    o=./outdat/out109x.csv
${pfxc}mslide -nfn     -n k=0   s=1    f=1         i=./indat/dat2nfn.csv o=./outdat/out109nfn.csv
${pfxc}mslide -nfno -x -n k=0   s=1    f=1         i=./indat/dat2.csv    o=./outdat/out109nfnox.csv

#f=,-n指定
${pfxc}mslide          -n s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out110.csv
${pfxc}mslide -nfno    -n s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out110nfno.csv
${pfxc}mslide -x       -n s=1   f=1:次日付    i=./indat/dat1.csv    o=./outdat/out110x.csv
${pfxc}mslide -nfn     -n s=1   f=1          i=./indat/dat1nfn.csv o=./outdat/out110nfn.csv
${pfxc}mslide -nfno -x -n s=1   f=1          i=./indat/dat1.csv    o=./outdat/out110nfnox.csv

${pfxc}mslide          -n s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out111.csv
${pfxc}mslide -nfno    -n s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out111nfno.csv
${pfxc}mslide -x       -n s=1   f=1:次日付    i=./indat/dat2.csv    o=./outdat/out111x.csv
${pfxc}mslide -nfn     -n s=1   f=1          i=./indat/dat2nfn.csv o=./outdat/out111nfn.csv
${pfxc}mslide -nfno -x -n s=1   f=1          i=./indat/dat2.csv    o=./outdat/out111nfnox.csv

#f=,-r指定
${pfxc}mslide          -r s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out112.csv
${pfxc}mslide -nfno    -r s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out112nfno.csv
${pfxc}mslide -x       -r s=1   f=1:次日付    i=./indat/dat1.csv    o=./outdat/out112x.csv
${pfxc}mslide -nfn     -r s=1   f=1          i=./indat/dat1nfn.csv o=./outdat/out112nfn.csv
${pfxc}mslide -nfno -x -r s=1   f=1          i=./indat/dat1.csv    o=./outdat/out112nfnox.csv

${pfxc}mslide          -r s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out113.csv
${pfxc}mslide -nfno    -r s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out113nfno.csv
${pfxc}mslide -x       -r s=1   f=1:次日付    i=./indat/dat2.csv    o=./outdat/out113x.csv
${pfxc}mslide -nfn     -r s=1   f=1          i=./indat/dat2nfn.csv o=./outdat/out113nfn.csv
${pfxc}mslide -nfno -x -r s=1   f=1          i=./indat/dat2.csv    o=./outdat/out113nfnox.csv

#k=,f=,-r指定
${pfxc}mslide          -r k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out114.csv
${pfxc}mslide -nfno    -r k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out114nfno.csv
${pfxc}mslide -x       -r k=0   s=1    f=1:次日付   i=./indat/dat1.csv    o=./outdat/out114x.csv
${pfxc}mslide -nfn     -r k=0   s=1    f=1         i=./indat/dat1nfn.csv o=./outdat/out114nfn.csv
${pfxc}mslide -nfno -x -r k=0   s=1    f=1         i=./indat/dat1.csv    o=./outdat/out114nfnox.csv

${pfxc}mslide          -r k=顧客 s=日付 f=日付:次日付  i=./indat/dat2.csv    o=./outdat/out115.csv
${pfxc}mslide -nfno    -r k=顧客 s=日付 f=日付:次日付  i=./indat/dat2.csv    o=./outdat/out115nfno.csv
${pfxc}mslide -x       -r k=0   s=1    f=1:次日付    i=./indat/dat2.csv    o=./outdat/out115x.csv
${pfxc}mslide -nfn     -r k=0   s=1    f=1          i=./indat/dat2nfn.csv o=./outdat/out115nfn.csv
${pfxc}mslide -nfno -x -r k=0   s=1    f=1          i=./indat/dat2.csv    o=./outdat/out115nfnox.csv

#k=,f=,-r,-n指定
${pfxc}mslide          -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out116.csv
${pfxc}mslide -nfno    -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat1.csv    o=./outdat/out116nfno.csv
${pfxc}mslide -x       -r -n k=0   s=1    f=1:次日付   i=./indat/dat1.csv    o=./outdat/out116x.csv
${pfxc}mslide -nfn     -r -n k=0   s=1    f=1         i=./indat/dat1nfn.csv o=./outdat/out116nfn.csv
${pfxc}mslide -nfno -x -r -n k=0   s=1    f=1         i=./indat/dat1.csv    o=./outdat/out116nfnox.csv

${pfxc}mslide          -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out117.csv
${pfxc}mslide -nfno    -r -n k=顧客 s=日付 f=日付:次日付 i=./indat/dat2.csv    o=./outdat/out117nfno.csv
${pfxc}mslide -x       -r -n k=0   s=1    f=1:次日付   i=./indat/dat2.csv    o=./outdat/out117x.csv
${pfxc}mslide -nfn     -r -n k=0   s=1    f=1         i=./indat/dat2nfn.csv o=./outdat/out117nfn.csv
${pfxc}mslide -nfno -x -r -n k=0   s=1    f=1         i=./indat/dat2.csv    o=./outdat/out117nfnox.csv

#f=,-r,t=3指定
${pfxc}mslide          -r t=3 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out118.csv
${pfxc}mslide -nfno    -r t=3 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out118nfno.csv
${pfxc}mslide -x       -r t=3 s=1   f=1:次日付    i=./indat/dat3.csv    o=./outdat/out118x.csv
${pfxc}mslide -nfn     -r t=3 s=1   f=1          i=./indat/dat3nfn.csv o=./outdat/out118nfn.csv
${pfxc}mslide -nfno -x -r t=3 s=1   f=1          i=./indat/dat3.csv    o=./outdat/out118nfnox.csv

#k=,f=,-r,t=3指定
${pfxc}mslide          -r t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out119.csv
${pfxc}mslide -nfno    -r t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out119nfno.csv
${pfxc}mslide -x       -r t=3 k=0    s=1   f=1:次日付   i=./indat/dat3.csv    o=./outdat/out119x.csv
${pfxc}mslide -nfn     -r t=3 k=0    s=1   f=1         i=./indat/dat3nfn.csv o=./outdat/out119nfn.csv
${pfxc}mslide -nfno -x -r t=3 k=0    s=1   f=1         i=./indat/dat3.csv    o=./outdat/out119nfnox.csv

#k=,f=,-r,-n,t=3指定
${pfxc}mslide          -r -n t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out120.csv
${pfxc}mslide -nfno    -r -n t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out120nfno.csv
${pfxc}mslide -x       -r -n t=3 k=0    s=1   f=1:次日付   i=./indat/dat3.csv    o=./outdat/out120x.csv
${pfxc}mslide -nfn     -r -n t=3 k=0    s=1   f=1         i=./indat/dat3nfn.csv o=./outdat/out120nfn.csv
${pfxc}mslide -nfno -x -r -n t=3 k=0    s=1   f=1         i=./indat/dat3.csv    o=./outdat/out120nfnox.csv

#f=,-r,t=3,-l指定
${pfxc}mslide          -r -l t=3 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out121.csv
${pfxc}mslide -nfno    -r -l t=3 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out121nfno.csv
${pfxc}mslide -x       -r -l t=3 s=1   f=1:次日付    i=./indat/dat3.csv    o=./outdat/out121x.csv
${pfxc}mslide -nfn     -r -l t=3 s=1   f=1          i=./indat/dat3nfn.csv o=./outdat/out121nfn.csv
${pfxc}mslide -nfno -x -r -l t=3 s=1   f=1          i=./indat/dat3.csv    o=./outdat/out121nfnox.csv

#k=,f=,-r,t=3,-l指定
${pfxc}mslide          -r -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out122.csv
${pfxc}mslide -nfno    -r -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out122nfno.csv
${pfxc}mslide -x       -r -l t=3 k=0   s=1    f=1:次日付   i=./indat/dat3.csv    o=./outdat/out122x.csv
${pfxc}mslide -nfn     -r -l t=3 k=0   s=1    f=1         i=./indat/dat3nfn.csv o=./outdat/out122nfn.csv
${pfxc}mslide -nfno -x -r -l t=3 k=0   s=1    f=1         i=./indat/dat3.csv    o=./outdat/out122nfnox.csv

#k=,f=,-r,-n,t=3,-l指定
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out123.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付:次日付 i=./indat/dat3.csv    o=./outdat/out123nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0    s=1   f=1:次日付   i=./indat/dat3.csv    o=./outdat/out123x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0    s=1   f=1         i=./indat/dat3nfn.csv o=./outdat/out123nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0    s=1   f=1         i=./indat/dat3.csv    o=./outdat/out123nfnox.csv

#k=,f=,-r,-n,t=3,-l指定
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付 i=./indat/dat3.csv    o=./outdat/out124.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付 i=./indat/dat3.csv    o=./outdat/out124nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0   s=1    f=1   i=./indat/dat3.csv    o=./outdat/out124x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0   s=1    f=1   i=./indat/dat3nfn.csv o=./outdat/out124nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0   s=1    f=1   i=./indat/dat3.csv    o=./outdat/out124nfnox.csv

#t=3,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out125.csv
${pfxc}mslide -nfno    t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out125nfno.csv
${pfxc}mslide -x       t=3 s=1    f=1,0                  i=./indat/dat3.csv    o=./outdat/out125x.csv
${pfxc}mslide -nfn     t=3 s=1    f=1,0                  i=./indat/dat3nfn.csv o=./outdat/out125nfn.csv
${pfxc}mslide -nfno -x t=3 s=1    f=1,0                  i=./indat/dat3.csv    o=./outdat/out125nfnox.csv

#t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out126.csv
${pfxc}mslide -nfno    t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out126nfno.csv
${pfxc}mslide -x       t=3 k=0   s=1    f=1,0                 i=./indat/dat3.csv    o=./outdat/out126x.csv
${pfxc}mslide -nfn     t=3 k=0   s=1    f=1,0                 i=./indat/dat3nfn.csv o=./outdat/out126nfn.csv
${pfxc}mslide -nfno -x t=3 k=0   s=1    f=1,0                 i=./indat/dat3.csv    o=./outdat/out126nfnox.csv

#-r,t=3,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -r t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out127.csv
${pfxc}mslide -nfno    -r t=3 s=日付  f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out127nfno.csv
${pfxc}mslide -x       -r t=3 s=1    f=1,0                  i=./indat/dat3.csv    o=./outdat/out127x.csv
${pfxc}mslide -nfn     -r t=3 s=1    f=1,0                  i=./indat/dat3nfn.csv o=./outdat/out127nfn.csv
${pfxc}mslide -nfno -x -r t=3 s=1    f=1,0                  i=./indat/dat3.csv    o=./outdat/out127nfnox.csv

#-l,t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out128.csv
${pfxc}mslide -nfno    -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out128nfno.csv
${pfxc}mslide -x       -l t=3 k=0    s=1   f=1,0                 i=./indat/dat3.csv    o=./outdat/out128x.csv
${pfxc}mslide -nfn     -l t=3 k=0    s=1   f=1,0                 i=./indat/dat3nfn.csv o=./outdat/out128nfn.csv
${pfxc}mslide -nfno -x -l t=3 k=0    s=1   f=1,0                 i=./indat/dat3.csv    o=./outdat/out128nfnox.csv

#-r,-l,t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -r -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out129.csv
${pfxc}mslide -nfno    -r -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out129nfno.csv
${pfxc}mslide -x       -r -l t=3 k=0   s=1    f=1,0                 i=./indat/dat3.csv    o=./outdat/out129x.csv
${pfxc}mslide -nfn     -r -l t=3 k=0   s=1    f=1,0                 i=./indat/dat3nfn.csv o=./outdat/out129nfn.csv
${pfxc}mslide -nfno -x -r -l t=3 k=0   s=1    f=1,0                 i=./indat/dat3.csv    o=./outdat/out129nfnox.csv

#-r,-n,-l,t=3,k=,f=複数項目名指定(f=2項目指定)
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out130.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付:次日付,顧客:次顧客 i=./indat/dat3.csv    o=./outdat/out130nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0   s=1   f=1,0                  i=./indat/dat3.csv    o=./outdat/out130x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0   s=1   f=1,0                  i=./indat/dat3nfn.csv o=./outdat/out130nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0   s=1   f=1,0                  i=./indat/dat3.csv    o=./outdat/out130nfnox.csv

#-r,-n,-l,t=3,k=,f=複数項目名指定(f=3項目指定)
${pfxc}mslide          -r -n -l t=3 k=顧客 s=日付 f=日付,顧客:次顧客,値 i=./indat/dat3.csv    o=./outdat/out131.csv
${pfxc}mslide -nfno    -r -n -l t=3 k=顧客 s=日付 f=日付,顧客:次顧客,値 i=./indat/dat3.csv    o=./outdat/out131nfno.csv
${pfxc}mslide -x       -r -n -l t=3 k=0   s=1   f=1,0:次顧客,2       i=./indat/dat3.csv    o=./outdat/out131x.csv
${pfxc}mslide -nfn     -r -n -l t=3 k=0   s=1   f=1,0,2             i=./indat/dat3nfn.csv o=./outdat/out131nfn.csv
${pfxc}mslide -nfno -x -r -n -l t=3 k=0   s=1   f=1,0:次顧客,2       i=./indat/dat3.csv    o=./outdat/out131nfnox.csv

#-l,t=3,f=複数項目名指定(f=3項目指定)
${pfxc}mslide          -l t=3 s=日付  f=日付,顧客:次顧客,値 i=./indat/dat3.csv    o=./outdat/out132.csv
${pfxc}mslide -nfno    -l t=3 s=日付  f=日付,顧客:次顧客,値 i=./indat/dat3.csv    o=./outdat/out132nfno.csv
${pfxc}mslide -x       -l t=3 s=1    f=1,0:次顧客,2       i=./indat/dat3.csv    o=./outdat/out132x.csv
${pfxc}mslide -nfn     -l t=3 s=1    f=1,0,2             i=./indat/dat3nfn.csv o=./outdat/out132nfn.csv
${pfxc}mslide -nfno -x -l t=3 s=1    f=1,0:次顧客,2       i=./indat/dat3.csv    o=./outdat/out132nfnox.csv

