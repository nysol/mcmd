#!/bin/bash

. ../env

#name_kg_mcmd vcommon

#nullデータ
${pfxc}mvcommon      vf=items1,items2 K=item  m=./indat/ref0.csv    i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mvcommon -x   vf=0,1 K=0  m=./indat/ref0.csv    i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0  m=./indat/ref0nfn.csv i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

${pfxc}mvcommon      vf=items1,items2 K=item  m=./indat/ref0.csv    i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mvcommon -x   vf=0,1 K=0  m=./indat/ref0.csv    i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0  m=./indat/ref0nfn.csv i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvcommon      vf=items1,items2 K=item  m=./indat/ref1.csv    i=./indat/dat0.csv    o=./outdat/out2.csv
${pfxc}mvcommon -x   vf=0,1 K=0  m=./indat/ref1.csv    i=./indat/dat0.csv    o=./outdat/out2x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0  m=./indat/ref1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

#通常データ
${pfxc}mvcommon      vf=items1 K=item m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mvcommon -x   vf=0 K=0 m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mvcommon -nfn vf=0 K=0 m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

${pfxc}mvcommon      vf=items1,items2 K=item m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}mvcommon -x   vf=0,1 K=0 m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0 m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvcommon      vf=items1 K=item -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out5.csv
${pfxc}mvcommon -x   vf=0 K=0 -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out5x.csv
${pfxc}mvcommon -nfn vf=0 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv


${pfxc}mvcommon      vf=items1,items2 K=item -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out6.csv
${pfxc}mvcommon -x   vf=0,1 K=0 -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out6x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvcommon      -A vf=items1:new1 K=item m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out7.csv
${pfxc}mvcommon -x   -A vf=0:new1 K=0 m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out7x.csv
${pfxc}mvcommon -nfn -A vf=0:new1 K=0 m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvcommon      -A vf=items1:new1,items2:new2 K=item m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out8.csv
${pfxc}mvcommon -x   -A vf=0:new1,1:new2 K=0 m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out8x.csv
${pfxc}mvcommon -nfn -A vf=0:new1,1:new2 K=0 m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out8nfn.csv

${pfxc}mvcommon      vf=items1,items2:new2 K=item m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}mvcommon -x   vf=0,1:new2 K=0 m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out9x.csv
${pfxc}mvcommon -nfn vf=0,1:new2 K=0 m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv

${pfxc}mvcommon      -A vf=items1:new1 K=item -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mvcommon -x   -A vf=0:new1 K=0 -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}mvcommon -nfn -A vf=0:new1 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvcommon      -A vf=items1:new1,items2:new2 K=item -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}mvcommon -x   -A vf=0:new1,1:new2 K=0 -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}mvcommon -nfn -A vf=0:new1,1:new2 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

${pfxc}mvcommon      vf=items1:new1,items2:new2 K=item -r m=./indat/ref1.csv    i=./indat/dat1.csv    o=./outdat/out12.csv
${pfxc}mvcommon -x   vf=0,1:new2 K=0 -r m=./indat/ref1.csv   i=./indat/dat1.csv    o=./outdat/out12x.csv
${pfxc}mvcommon -nfn vf=0,1:new2 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv

#DQ,NULLを含むデータ 
${pfxc}mvcommon      vf=items1 K=item m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out13.csv
${pfxc}mvcommon -x   vf=0 K=0 m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out13x.csv
${pfxc}mvcommon -nfn vf=0 K=0 m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out13nfn.csv

${pfxc}mvcommon      vf=items1,items2 K=item m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out14.csv
${pfxc}mvcommon -x   vf=0,1 K=0 m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out14x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0 m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out14nfn.csv

${pfxc}mvcommon      vf=items1 K=item -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out15.csv
${pfxc}mvcommon -x   vf=0 K=0 -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out15x.csv
${pfxc}mvcommon -nfn vf=0 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv

${pfxc}mvcommon      vf=items1,items2 K=item -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out16.csv
${pfxc}mvcommon -x   vf=0,1 K=0 -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out16x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out16nfn.csv

${pfxc}mvcommon      -A vf=items1:new1 K=item m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out17.csv
${pfxc}mvcommon -x   -A vf=0:new1 K=0 m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out17x.csv
${pfxc}mvcommon -nfn -A vf=0:new1 K=0 m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv

${pfxc}mvcommon      -A vf=items1:new1,items2:new2 K=item m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}mvcommon -x   -A vf=0:new1,1:new2 K=0 m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}mvcommon -nfn -A vf=0:new1,1:new2 K=0 m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv

${pfxc}mvcommon      vf=items1,items2:new2 K=item m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out19.csv
${pfxc}mvcommon -x   vf=0,1:new2 K=0 m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out19x.csv
${pfxc}mvcommon -nfn vf=0,1:new2 K=0 m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out19nfn.csv

${pfxc}mvcommon      -A vf=items1:new1 K=item -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out20.csv
${pfxc}mvcommon -x   -A vf=0:new1 K=0 -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out20x.csv
${pfxc}mvcommon -nfn -A vf=0:new1 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out20nfn.csv

${pfxc}mvcommon      -A vf=items1:new1,items2:new2 K=item -r 	m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out21.csv
${pfxc}mvcommon -x   -A vf=0:new1,1:new2 K=0 -r 	m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out21x.csv
${pfxc}mvcommon -nfn -A vf=0:new1,1:new2 K=0 -r 	m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out21nfn.csv

${pfxc}mvcommon      vf=items1:new1,items2:new2 K=item -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out22.csv
${pfxc}mvcommon -x   vf=0:new1,1:new2 K=0 -r m=./indat/ref1.csv    i=./indat/dat2.csv    o=./outdat/out22x.csv
${pfxc}mvcommon -nfn vf=0:new1,1:new2 K=0 -r m=./indat/ref1nfn.csv i=./indat/dat2nfn.csv o=./outdat/out22nfn.csv



#ソートデータ
${pfxc}mvcommon      vf=items1 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out33.csv
${pfxc}mvcommon -x   vf=0 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out33x.csv
${pfxc}mvcommon -nfn vf=0 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out33nfn.csv

${pfxc}mvcommon      vf=items1,items2 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out34.csv
${pfxc}mvcommon -x   vf=0,1 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out34x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out34nfn.csv

${pfxc}mvcommon      vf=items1 K=item -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out35.csv
${pfxc}mvcommon -x   vf=0 K=0 -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out35x.csv
${pfxc}mvcommon -nfn vf=0 K=0 -r m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out35nfn.csv


${pfxc}mvcommon      vf=items1,items2 K=item -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out36.csv
${pfxc}mvcommon -x   vf=0,1 K=0 -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out36x.csv
${pfxc}mvcommon -nfn vf=0,1 K=0 -r m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out36nfn.csv

${pfxc}mvcommon      -A vf=items1:new1 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out37.csv
${pfxc}mvcommon -x   -A vf=0:new1 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out37x.csv
${pfxc}mvcommon -nfn -A vf=0:new1 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out37nfn.csv

${pfxc}mvcommon      -A vf=items1:new1,items2:new2 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out38.csv
${pfxc}mvcommon -x   -A vf=0:new1,1:new2 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out38x.csv
${pfxc}mvcommon -nfn -A vf=0:new1,1:new2 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out38nfn.csv

${pfxc}mvcommon      vf=items1:new1,items2:new2 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out39.csv
${pfxc}mvcommon -x   vf=0:new1,1:new2 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out39x.csv
${pfxc}mvcommon -nfn vf=0:new1,1:new2 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out39nfn.csv

${pfxc}mvcommon      -A vf=items1:new1 K=item -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out40.csv
${pfxc}mvcommon -x   -A vf=0:new1 K=0 -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out40x.csv
${pfxc}mvcommon -nfn -A vf=0:new1 K=0 -r m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out40nfn.csv

${pfxc}mvcommon      -A vf=items1:new1,items2:new2 K=item -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out41.csv
${pfxc}mvcommon -x   -A vf=0:new1,1:new2 K=0 -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out41x.csv
${pfxc}mvcommon -nfn -A vf=0:new1,1:new2 K=0 -r m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out41nfn.csv

${pfxc}mvcommon      vf=items1,items2:new2 K=item -r m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out42.csv
${pfxc}mvcommon -x   vf=0,1:new2 K=0 -r m=./indat/ref1s.csv   i=./indat/dat1s.csv    o=./outdat/out42x.csv
${pfxc}mvcommon -nfn vf=0,1:new2 K=0 -r m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out42nfn.csv

${pfxc}mvcommon      -A vf=items2:new2 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out43.csv
${pfxc}mvcommon -x   -A vf=1:new2 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out43x.csv
${pfxc}mvcommon -nfn -A vf=1:new2 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out43nfn.csv


${pfxc}mvcommon      vf=items2 K=item m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out44.csv
${pfxc}mvcommon -x   vf=1 K=0 m=./indat/ref1s.csv    i=./indat/dat1s.csv    o=./outdat/out44x.csv
${pfxc}mvcommon -nfn vf=1 K=0 m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out44nfn.csv

