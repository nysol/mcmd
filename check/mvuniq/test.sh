#!/bin/bash

. ../env

#name_kg_mcmd vuniq

#nullデータ
${pfxc}mvuniq      vf=items1 							i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvuniq -x   vf=1 							i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvuniq -nfn vf=1 							i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv


${pfxc}mvuniq      vf=items1 -n						i=./indat/dat0.csv o=./outdat/out1.csv
${pfxc}mvuniq -x   vf=1 -n						i=./indat/dat0.csv o=./outdat/out1x.csv
${pfxc}mvuniq -nfn vf=1 -n						i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvuniq      vf=items1,items2 i=./indat/dat0.csv o=./outdat/out2.csv
${pfxc}mvuniq -x   vf=1,2	          i=./indat/dat0.csv o=./outdat/out2x.csv
${pfxc}mvuniq -nfn vf=1,2           i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

${pfxc}mvuniq      vf=items1,items2 -n i=./indat/dat0.csv o=./outdat/out3.csv
${pfxc}mvuniq -x   vf=1,2           -n i=./indat/dat0.csv o=./outdat/out3x.csv
${pfxc}mvuniq -nfn vf=1,2           -n i=./indat/dat0nfn.csv o=./outdat/out3nfn.csv

#通常データ
${pfxc}mvuniq      vf=items1 i=./indat/dat1.csv o=./outdat/out4.csv
${pfxc}mvuniq -x   vf=1      i=./indat/dat1.csv o=./outdat/out4x.csv
${pfxc}mvuniq -nfn vf=1      i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvuniq      vf=items1 -n i=./indat/dat1.csv o=./outdat/out5.csv
${pfxc}mvuniq -x   vf=1      -n i=./indat/dat1.csv o=./outdat/out5x.csv
${pfxc}mvuniq -nfn vf=1      -n i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvuniq      vf=items1,items2 i=./indat/dat1.csv o=./outdat/out6.csv
${pfxc}mvuniq -x   vf=1,2	          i=./indat/dat1.csv o=./outdat/out6x.csv
${pfxc}mvuniq -nfn vf=1,2           i=./indat/dat1nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvuniq      vf=items1,items2 -n i=./indat/dat1.csv o=./outdat/out7.csv
${pfxc}mvuniq -x   vf=1,2           -n i=./indat/dat1.csv o=./outdat/out7x.csv
${pfxc}mvuniq -nfn vf=1,2           -n i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvuniq      vf=items1:it1 i=./indat/dat1.csv o=./outdat/out16.csv
${pfxc}mvuniq -x   vf=1:it1      i=./indat/dat1.csv o=./outdat/out16x.csv
${pfxc}mvuniq -nfn vf=1:it1      i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv

${pfxc}mvuniq      vf=items1:it1 -n i=./indat/dat1.csv o=./outdat/out17.csv
${pfxc}mvuniq -x   vf=1:it1      -n i=./indat/dat1.csv o=./outdat/out17x.csv
${pfxc}mvuniq -nfn vf=1:it1      -n i=./indat/dat1nfn.csv o=./outdat/out17nfn.csv

${pfxc}mvuniq      -A vf=items1:it1 i=./indat/dat1.csv o=./outdat/out18.csv
${pfxc}mvuniq -x   -A vf=1:it1      i=./indat/dat1.csv o=./outdat/out18x.csv
${pfxc}mvuniq -nfn -A vf=1:it1      i=./indat/dat1nfn.csv o=./outdat/out18nfn.csv

${pfxc}mvuniq      -A vf=items1:it1 -n i=./indat/dat1.csv o=./outdat/out19.csv
${pfxc}mvuniq -x   -A vf=1:it1      -n i=./indat/dat1.csv o=./outdat/out19x.csv
${pfxc}mvuniq -nfn -A vf=1:it1      -n i=./indat/dat1nfn.csv o=./outdat/out19nfn.csv


${pfxc}mvuniq      vf=items1,items2 i=./indat/dat1.csv o=./outdat/out20.csv
${pfxc}mvuniq -x   vf=1,2	          i=./indat/dat1.csv o=./outdat/out20x.csv
${pfxc}mvuniq -nfn vf=1,2           i=./indat/dat1nfn.csv o=./outdat/out20nfn.csv

${pfxc}mvuniq      vf=items1,items2 -n i=./indat/dat1.csv o=./outdat/out21.csv
${pfxc}mvuniq -x   vf=1,2           -n i=./indat/dat1.csv o=./outdat/out21x.csv
${pfxc}mvuniq -nfn vf=1,2           -n i=./indat/dat1nfn.csv o=./outdat/out21nfn.csv

${pfxc}mvuniq      -A vf=items1:itx1,items2:itx2 i=./indat/dat1.csv o=./outdat/out22.csv
${pfxc}mvuniq -x   -A vf=1:itx1,2:itx2	          i=./indat/dat1.csv o=./outdat/out22x.csv
${pfxc}mvuniq -nfn -A vf=1:itx1,2:itx2           i=./indat/dat1nfn.csv o=./outdat/out22nfn.csv

${pfxc}mvuniq      -A vf=items1:itx1,items2:itx2 -n i=./indat/dat1.csv o=./outdat/out23.csv
${pfxc}mvuniq -x   -A vf=1:itx1,2:itx2           -n i=./indat/dat1.csv o=./outdat/out23x.csv
${pfxc}mvuniq -nfn -A vf=1:itx1,2:itx2           -n i=./indat/dat1nfn.csv o=./outdat/out23nfn.csv



#DQ,NULLを含むデータ 
${pfxc}mvuniq      vf=items1 i=./indat/dat2.csv o=./outdat/out8.csv
${pfxc}mvuniq -x   vf=1      i=./indat/dat2.csv o=./outdat/out8x.csv
${pfxc}mvuniq -nfn vf=1      i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv

${pfxc}mvuniq      vf=items1 -n i=./indat/dat2.csv o=./outdat/out9.csv
${pfxc}mvuniq -x   vf=1      -n i=./indat/dat2.csv o=./outdat/out9x.csv
${pfxc}mvuniq -nfn vf=1      -n i=./indat/dat2nfn.csv o=./outdat/out9nfn.csv

${pfxc}mvuniq      vf=items1,items2 i=./indat/dat2.csv o=./outdat/out10.csv
${pfxc}mvuniq -x   vf=1,2	          i=./indat/dat2.csv o=./outdat/out10x.csv
${pfxc}mvuniq -nfn vf=1,2           i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvuniq      vf=items1,items2 -n i=./indat/dat2.csv o=./outdat/out11.csv
${pfxc}mvuniq -x   vf=1,2           -n i=./indat/dat2.csv o=./outdat/out11x.csv
${pfxc}mvuniq -nfn vf=1,2           -n i=./indat/dat2nfn.csv o=./outdat/out11nfn.csv

#delimオプション
${pfxc}mvuniq      vf=items1 delim=: i=./indat/dat3.csv o=./outdat/out12.csv
${pfxc}mvuniq -x   vf=0      delim=: i=./indat/dat3.csv o=./outdat/out12x.csv
${pfxc}mvuniq -nfn vf=0      delim=: i=./indat/dat3nfn.csv o=./outdat/out12nfn.csv

${pfxc}mvuniq      vf=items1 delim=: -n	i=./indat/dat3.csv o=./outdat/out14.csv
${pfxc}mvuniq -x   vf=0      delim=: -n	i=./indat/dat3.csv o=./outdat/out14x.csv
${pfxc}mvuniq -nfn vf=0      delim=: -n	i=./indat/dat3nfn.csv o=./outdat/out14nfn.csv

${pfxc}mvuniq      vf=items1 delim=, -n	i=./indat/dat4.csv o=./outdat/out15.csv
${pfxc}mvuniq -x   vf=0      delim=, -n	i=./indat/dat4.csv o=./outdat/out15x.csv
${pfxc}mvuniq -nfn vf=0      delim=, -n	i=./indat/dat4nfn.csv o=./outdat/out15nfn.csv



#ソートデータ
#通常データ
${pfxc}mvuniq      vf=items1 i=./indat/dat1s.csv o=./outdat/out34.csv
${pfxc}mvuniq -x   vf=1      i=./indat/dat1s.csv o=./outdat/out34x.csv
${pfxc}mvuniq -nfn vf=1      i=./indat/dat1snfn.csv o=./outdat/out34nfn.csv

${pfxc}mvuniq      vf=items1 -n i=./indat/dat1s.csv o=./outdat/out35.csv
${pfxc}mvuniq -x   vf=1      -n i=./indat/dat1s.csv o=./outdat/out35x.csv
${pfxc}mvuniq -nfn vf=1      -n i=./indat/dat1snfn.csv o=./outdat/out35nfn.csv

${pfxc}mvuniq      vf=items1,items2 i=./indat/dat1s.csv o=./outdat/out36.csv
${pfxc}mvuniq -x   vf=1,2	          i=./indat/dat1s.csv o=./outdat/out36x.csv
${pfxc}mvuniq -nfn vf=1,2           i=./indat/dat1snfn.csv o=./outdat/out36nfn.csv

${pfxc}mvuniq      vf=items1,items2 -n i=./indat/dat1s.csv o=./outdat/out37.csv
${pfxc}mvuniq -x   vf=1,2           -n i=./indat/dat1s.csv o=./outdat/out37x.csv
${pfxc}mvuniq -nfn vf=1,2           -n i=./indat/dat1snfn.csv o=./outdat/out37nfn.csv

${pfxc}mvuniq      vf=items1:it1 i=./indat/dat1s.csv o=./outdat/out46.csv
${pfxc}mvuniq -x   vf=1:it1      i=./indat/dat1s.csv o=./outdat/out46x.csv
${pfxc}mvuniq -nfn vf=1:it1      i=./indat/dat1snfn.csv o=./outdat/out46nfn.csv

${pfxc}mvuniq      vf=items1:it1 -n i=./indat/dat1s.csv o=./outdat/out47.csv
${pfxc}mvuniq -x   vf=1:it1      -n i=./indat/dat1s.csv o=./outdat/out47x.csv
${pfxc}mvuniq -nfn vf=1:it1      -n i=./indat/dat1snfn.csv o=./outdat/out47nfn.csv

${pfxc}mvuniq      -A vf=items1:it1 i=./indat/dat1s.csv o=./outdat/out48.csv
${pfxc}mvuniq -x   -A vf=1:it1      i=./indat/dat1s.csv o=./outdat/out48x.csv
${pfxc}mvuniq -nfn -A vf=1:it1      i=./indat/dat1snfn.csv o=./outdat/out48nfn.csv

${pfxc}mvuniq      -A vf=items1:it1 -n i=./indat/dat1s.csv o=./outdat/out49.csv
${pfxc}mvuniq -x   -A vf=1:it1      -n i=./indat/dat1s.csv o=./outdat/out49x.csv
${pfxc}mvuniq -nfn -A vf=1:it1      -n i=./indat/dat1snfn.csv o=./outdat/out49nfn.csv


${pfxc}mvuniq      vf=items1,items2 i=./indat/dat1s.csv o=./outdat/out50.csv
${pfxc}mvuniq -x   vf=1,2	          i=./indat/dat1s.csv o=./outdat/out50x.csv
${pfxc}mvuniq -nfn vf=1,2           i=./indat/dat1snfn.csv o=./outdat/out50nfn.csv

${pfxc}mvuniq      vf=items1,items2 -n i=./indat/dat1s.csv o=./outdat/out51.csv
${pfxc}mvuniq -x   vf=1,2           -n i=./indat/dat1s.csv o=./outdat/out51x.csv
${pfxc}mvuniq -nfn vf=1,2           -n i=./indat/dat1snfn.csv o=./outdat/out51nfn.csv

${pfxc}mvuniq      -A vf=items1:itx1,items2:itx2 i=./indat/dat1s.csv o=./outdat/out52.csv
${pfxc}mvuniq -x   -A vf=1:itx1,2:itx2	          i=./indat/dat1s.csv o=./outdat/out52x.csv
${pfxc}mvuniq -nfn -A vf=1:itx1,2:itx2           i=./indat/dat1snfn.csv o=./outdat/out52nfn.csv

${pfxc}mvuniq      -A vf=items1:itx1,items2:itx2 -n i=./indat/dat1s.csv o=./outdat/out53.csv
${pfxc}mvuniq -x   -A vf=1:itx1,2:itx2           -n i=./indat/dat1s.csv o=./outdat/out53x.csv
${pfxc}mvuniq -nfn -A vf=1:itx1,2:itx2           -n i=./indat/dat1snfn.csv o=./outdat/out53nfn.csv

