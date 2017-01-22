#!/bin/bash

. ../env

#name_kg_mcmd vjoin

#nullデータ
${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref0.csv i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref0.csv i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref0nfn.csv i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref0.csv i=./indat/dat1.csv o=./outdat/out1.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref0.csv i=./indat/dat1.csv o=./outdat/out1x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref0nfn.csv i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref1.csv i=./indat/dat0.csv o=./outdat/out2.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref1.csv i=./indat/dat0.csv o=./outdat/out2x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

#通常データ
${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out3.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out3x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv


${pfxc}mvjoin      vf=items1 K=item f=taxo n=* m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out4.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 n=* m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out4x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 n=* m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv


#DQ,NULLを含むデータ 
${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out5.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out5x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv


${pfxc}mvjoin      vf=items1 K=item f=taxo n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out6.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out6x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 n=* m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvjoin      vf=items1,items2 K=item f=taxo m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out7.csv
${pfxc}mvjoin -x   vf=0,1 K=0 f=1 m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out7x.csv
${pfxc}mvjoin -nfn vf=0,1 K=0 f=1 m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv


${pfxc}mvjoin      vf=items1,items2 K=item f=taxo n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out8.csv
${pfxc}mvjoin -x   vf=0,1 K=0 f=1 n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out8x.csv
${pfxc}mvjoin -nfn vf=0,1 K=0 f=1 n=* m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv

#追加
${pfxc}mvjoin      -A vf=items1:itx K=item f=taxo n=* m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out9.csv
${pfxc}mvjoin -x   -A vf=0:itx K=0 f=1 n=* m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out9x.csv
${pfxc}mvjoin -nfn -A vf=0:itx K=0 f=1 n=* m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv

${pfxc}mvjoin      vf=items1:itx,items2:it2x K=item f=taxo n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out10.csv
${pfxc}mvjoin -x   vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out10x.csv
${pfxc}mvjoin -nfn vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvjoin      -A vf=items1:itx,items2:it2x K=item f=taxo n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out11.csv
${pfxc}mvjoin -x   -A vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out11x.csv
${pfxc}mvjoin -nfn -A vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out11nfn.csv

${pfxc}mvjoin      vf=items2 K=item f=taxo n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out12.csv
${pfxc}mvjoin -x   vf=1 K=0 f=1 n=* m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out12x.csv
${pfxc}mvjoin -nfn vf=1 K=0 f=1 n=* m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out12nfn.csv


#ソートデータ
#通常データ
${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out13.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out13x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out13nfn.csv


${pfxc}mvjoin      vf=items1 K=item f=taxo n=* m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out14.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 n=* m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out14x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 n=* m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out14nfn.csv


#DQ,NULLを含むデータ 
${pfxc}mvjoin      vf=items1 K=item f=taxo m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out15.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out15x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out15nfn.csv


${pfxc}mvjoin      vf=items1 K=item f=taxo n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out16.csv
${pfxc}mvjoin -x   vf=0 K=0 f=1 n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out16x.csv
${pfxc}mvjoin -nfn vf=0 K=0 f=1 n=* m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out16nfn.csv

${pfxc}mvjoin      vf=items1,items2 K=item f=taxo m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out17.csv
${pfxc}mvjoin -x   vf=0,1 K=0 f=1 m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out17x.csv
${pfxc}mvjoin -nfn vf=0,1 K=0 f=1 m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out17nfn.csv


${pfxc}mvjoin      vf=items1,items2 K=item f=taxo n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out18.csv
${pfxc}mvjoin -x   vf=0,1 K=0 f=1 n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out18x.csv
${pfxc}mvjoin -nfn vf=0,1 K=0 f=1 n=* m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out18nfn.csv


#追加
${pfxc}mvjoin      -A vf=items1:itx K=item f=taxo n=* m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out19.csv
${pfxc}mvjoin -x   -A vf=0:itx K=0 f=1 n=* m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out19x.csv
${pfxc}mvjoin -nfn -A vf=0:itx K=0 f=1 n=* m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out19nfn.csv

${pfxc}mvjoin      vf=items1:itx,items2:it2x K=item f=taxo n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out20.csv
${pfxc}mvjoin -x   vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out20x.csv
${pfxc}mvjoin -nfn vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out20nfn.csv

${pfxc}mvjoin      -A vf=items1:itx,items2:it2x K=item f=taxo n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out21.csv
${pfxc}mvjoin -x   -A vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out21x.csv
${pfxc}mvjoin -nfn -A vf=0:itx,1:it2x K=0 f=1 n=* m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out21nfn.csv

${pfxc}mvjoin      vf=items2 K=item f=taxo n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out22.csv
${pfxc}mvjoin -x   vf=1 K=0 f=1 n=* m=./indat/ref2s.csv i=./indat/dat2s.csv o=./outdat/out22x.csv
${pfxc}mvjoin -nfn vf=1 K=0 f=1 n=* m=./indat/ref2snfn.csv i=./indat/dat2snfn.csv o=./outdat/out22nfn.csv



