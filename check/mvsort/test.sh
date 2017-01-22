#!/bin/bash

. ../env

#name_kg_mcmd vsort

#nullデータ
${pfxc}mvsort      vf=items1 							i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvsort -x   vf=1 							i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvsort -nfn vf=1 							i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

${pfxc}mvsort      vf=items1%r							i=./indat/dat0.csv o=./outdat/out1.csv
${pfxc}mvsort -x   vf=1%r							i=./indat/dat0.csv o=./outdat/out1x.csv
${pfxc}mvsort -nfn vf=1%r							i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvsort      vf=items1%n							i=./indat/dat0.csv o=./outdat/out2.csv
${pfxc}mvsort -x   vf=1%n							i=./indat/dat0.csv o=./outdat/out2x.csv
${pfxc}mvsort -nfn vf=1%n							i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

${pfxc}mvsort      vf=items1%nr						i=./indat/dat0.csv o=./outdat/out3.csv
${pfxc}mvsort -x   vf=1%nr						i=./indat/dat0.csv o=./outdat/out3x.csv
${pfxc}mvsort -nfn vf=1%nr						i=./indat/dat0nfn.csv o=./outdat/out3nfn.csv

${pfxc}mvsort      vf=items1,items2 				i=./indat/dat0.csv o=./outdat/out4.csv
${pfxc}mvsort -x   vf=1,2 				i=./indat/dat0.csv o=./outdat/out4x.csv
${pfxc}mvsort -nfn vf=1,2 				i=./indat/dat0nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvsort      vf=items1%r,items2%r		i=./indat/dat0.csv o=./outdat/out5.csv
${pfxc}mvsort -x   vf=1%r,2%r		i=./indat/dat0.csv o=./outdat/out5x.csv
${pfxc}mvsort -nfn vf=1%r,2%r		i=./indat/dat0nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvsort      vf=items1%nr,items2%nr	i=./indat/dat0.csv o=./outdat/out6.csv
${pfxc}mvsort -x   vf=1%nr,2%nr	i=./indat/dat0.csv o=./outdat/out6x.csv
${pfxc}mvsort -nfn vf=1%nr,2%nr	i=./indat/dat0nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvsort      vf=items1,items2%n 			i=./indat/dat0.csv o=./outdat/out7.csv
${pfxc}mvsort -x   vf=1,2%n 			i=./indat/dat0.csv o=./outdat/out7x.csv
${pfxc}mvsort -nfn vf=1,2%n 			i=./indat/dat0nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvsort      vf=items1%r,items2%nr		i=./indat/dat0.csv o=./outdat/out8.csv
${pfxc}mvsort -x   vf=1%r,2%nr		i=./indat/dat0.csv o=./outdat/out8x.csv
${pfxc}mvsort -nfn vf=1%r,2%nr		i=./indat/dat0nfn.csv o=./outdat/out8nfn.csv

${pfxc}mvsort      vf=items1,items2%nr			i=./indat/dat0.csv o=./outdat/out9.csv
${pfxc}mvsort -x   vf=1,2%nr			i=./indat/dat0.csv o=./outdat/out9x.csv
${pfxc}mvsort -nfn vf=1,2%nr			i=./indat/dat0nfn.csv o=./outdat/out9nfn.csv

#通常データ
${pfxc}mvsort      vf=items1 							i=./indat/dat1.csv o=./outdat/out10.csv
${pfxc}mvsort -x   vf=1 							i=./indat/dat1.csv o=./outdat/out10x.csv
${pfxc}mvsort -nfn vf=1 							i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvsort      vf=items1%r							i=./indat/dat1.csv o=./outdat/out11.csv
${pfxc}mvsort -x   vf=1%r							i=./indat/dat1.csv o=./outdat/out11x.csv
${pfxc}mvsort -nfn vf=1%r							i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

${pfxc}mvsort      vf=items1%n							i=./indat/dat1.csv o=./outdat/out12.csv
${pfxc}mvsort -x   vf=1%n							i=./indat/dat1.csv o=./outdat/out12x.csv
${pfxc}mvsort -nfn vf=1%n							i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv

${pfxc}mvsort      vf=items1%nr						i=./indat/dat1.csv o=./outdat/out13.csv
${pfxc}mvsort -x   vf=1%nr						i=./indat/dat1.csv o=./outdat/out13x.csv
${pfxc}mvsort -nfn vf=1%nr						i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv

${pfxc}mvsort      vf=items1,items2 				i=./indat/dat1.csv o=./outdat/out14.csv
${pfxc}mvsort -x   vf=1,2 				i=./indat/dat1.csv o=./outdat/out14x.csv
${pfxc}mvsort -nfn vf=1,2 				i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

${pfxc}mvsort      vf=items1%r,items2%r		i=./indat/dat1.csv o=./outdat/out15.csv
${pfxc}mvsort -x   vf=1%r,2%r		i=./indat/dat1.csv o=./outdat/out15x.csv
${pfxc}mvsort -nfn vf=1%r,2%r		i=./indat/dat1nfn.csv o=./outdat/out15nfn.csv

${pfxc}mvsort      vf=items1%n,items2%n		i=./indat/dat1.csv o=./outdat/out16.csv
${pfxc}mvsort -x   vf=1%n,2%n		i=./indat/dat1.csv o=./outdat/out16x.csv
${pfxc}mvsort -nfn vf=1%n,2%n		i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv

${pfxc}mvsort      vf=items1%nr,items2%nr	i=./indat/dat1.csv o=./outdat/out17.csv
${pfxc}mvsort -x   vf=1%nr,2%nr	i=./indat/dat1.csv o=./outdat/out17x.csv
${pfxc}mvsort -nfn vf=1%nr,2%nr	i=./indat/dat1nfn.csv o=./outdat/out17nfn.csv

${pfxc}mvsort      vf=items1,items2%n 			i=./indat/dat1.csv o=./outdat/out18.csv
${pfxc}mvsort -x   vf=1,2%n 			i=./indat/dat1.csv o=./outdat/out18x.csv
${pfxc}mvsort -nfn vf=1,2%n 			i=./indat/dat1nfn.csv o=./outdat/out18nfn.csv

${pfxc}mvsort      vf=items1%r,items2%nr		i=./indat/dat1.csv o=./outdat/out19.csv
${pfxc}mvsort -x   vf=1%r,2%nr		i=./indat/dat1.csv o=./outdat/out19x.csv
${pfxc}mvsort -nfn vf=1%r,2%nr		i=./indat/dat1nfn.csv o=./outdat/out19nfn.csv

${pfxc}mvsort      vf=items1,items2%nr			i=./indat/dat1.csv o=./outdat/out20.csv
${pfxc}mvsort -x   vf=1,2%nr			i=./indat/dat1.csv o=./outdat/out20x.csv
${pfxc}mvsort -nfn vf=1,2%nr			i=./indat/dat1nfn.csv o=./outdat/out20nfn.csv





${pfxc}mvsort      vf=items1:itm1 							i=./indat/dat1.csv o=./outdat/out36.csv
${pfxc}mvsort -x   vf=1:itm1 							i=./indat/dat1.csv o=./outdat/out36x.csv
${pfxc}mvsort -nfn vf=1:itm1 							i=./indat/dat1nfn.csv o=./outdat/out36nfn.csv

${pfxc}mvsort      vf=items1%r:itm1							i=./indat/dat1.csv o=./outdat/out37.csv
${pfxc}mvsort -x   vf=1%r:itm1							i=./indat/dat1.csv o=./outdat/out37x.csv
${pfxc}mvsort -nfn vf=1%r:itm1							i=./indat/dat1nfn.csv o=./outdat/out37nfn.csv

${pfxc}mvsort      vf=items1%n:itm1							i=./indat/dat1.csv o=./outdat/out38.csv
${pfxc}mvsort -x   vf=1%n:itm1							i=./indat/dat1.csv o=./outdat/out38x.csv
${pfxc}mvsort -nfn vf=1%n							i=./indat/dat1nfn.csv o=./outdat/out38nfn.csv

${pfxc}mvsort      vf=items1%nr:itm1						i=./indat/dat1.csv o=./outdat/out39.csv
${pfxc}mvsort -x   vf=1%nr:itm1						i=./indat/dat1.csv o=./outdat/out39x.csv
${pfxc}mvsort -nfn vf=1%nr:itm1						i=./indat/dat1nfn.csv o=./outdat/out39nfn.csv

${pfxc}mvsort      vf=items1:itm1,items2:itm2 				i=./indat/dat1.csv o=./outdat/out40.csv
${pfxc}mvsort -x   vf=1:itm1,2:itm2 				i=./indat/dat1.csv o=./outdat/out40x.csv
${pfxc}mvsort -nfn vf=1:itm1,2:itm2 				i=./indat/dat1nfn.csv o=./outdat/out40nfn.csv

${pfxc}mvsort      vf=items1%r:itm1,items2%r:itm2		i=./indat/dat1.csv o=./outdat/out41.csv
${pfxc}mvsort -x   vf=1%r:itm1,2%r:itm2		i=./indat/dat1.csv o=./outdat/out41x.csv
${pfxc}mvsort -nfn vf=1%r:itm1,2%r:itm2		i=./indat/dat1nfn.csv o=./outdat/out41nfn.csv

${pfxc}mvsort      vf=items1%n:itm1,items2%n:itm2		i=./indat/dat1.csv o=./outdat/out42.csv
${pfxc}mvsort -x   vf=1%n:itm1,2%n:itm2		i=./indat/dat1.csv o=./outdat/out42x.csv
${pfxc}mvsort -nfn vf=1%n:itm1,2%n:itm2		i=./indat/dat1nfn.csv o=./outdat/out42nfn.csv

${pfxc}mvsort      vf=items1%nr:itm1,items2%nr:itm2	i=./indat/dat1.csv o=./outdat/out43.csv
${pfxc}mvsort -x   vf=1%nr:itm1,2%nr:itm2	i=./indat/dat1.csv o=./outdat/out43x.csv
${pfxc}mvsort -nfn vf=1%nr:itm1,2%nr:itm1	i=./indat/dat1nfn.csv o=./outdat/out43nfn.csv

${pfxc}mvsort      vf=items1:itm1,items2%n:itm2 			i=./indat/dat1.csv o=./outdat/out44.csv
${pfxc}mvsort -x   vf=1:itm1,2%n:itm2 			i=./indat/dat1.csv o=./outdat/out44x.csv
${pfxc}mvsort -nfn vf=1:itm1,2%n:itm2 			i=./indat/dat1nfn.csv o=./outdat/out44nfn.csv

${pfxc}mvsort      vf=items1%r:itm1,items2%nr:itm2		i=./indat/dat1.csv o=./outdat/out45.csv
${pfxc}mvsort -x   vf=1%r:itm1,2%nr:itm2		i=./indat/dat1.csv o=./outdat/out45x.csv
${pfxc}mvsort -nfn vf=1%r:itm1,2%nr:itm2		i=./indat/dat1nfn.csv o=./outdat/out45nfn.csv

${pfxc}mvsort      vf=items1:itm1,items2%nr:itm2			i=./indat/dat1.csv o=./outdat/out46.csv
${pfxc}mvsort -x   vf=1:itm1,2%nr:itm2			i=./indat/dat1.csv o=./outdat/out46x.csv
${pfxc}mvsort -nfn vf=1:itm1,2%nr:itm2			i=./indat/dat1nfn.csv o=./outdat/out46nfn.csv


${pfxc}mvsort      -A vf=items1:itm1 							i=./indat/dat1.csv o=./outdat/out47.csv
${pfxc}mvsort -x   -A vf=1:itm1 							i=./indat/dat1.csv o=./outdat/out47x.csv
${pfxc}mvsort -nfn -A vf=1:itm1 							i=./indat/dat1nfn.csv o=./outdat/out47nfn.csv

${pfxc}mvsort      -A vf=items1%r:itm1							i=./indat/dat1.csv o=./outdat/out48.csv
${pfxc}mvsort -x   -A vf=1%r:itm1							i=./indat/dat1.csv o=./outdat/out48x.csv
${pfxc}mvsort -nfn -A vf=1%r:itm1							i=./indat/dat1nfn.csv o=./outdat/out48nfn.csv

${pfxc}mvsort      -A vf=items1%n:itm1							i=./indat/dat1.csv o=./outdat/out49.csv
${pfxc}mvsort -x   -A vf=1%n:itm1							i=./indat/dat1.csv o=./outdat/out49x.csv
${pfxc}mvsort -nfn -A vf=1%n							i=./indat/dat1nfn.csv o=./outdat/out49nfn.csv

${pfxc}mvsort      -A vf=items1%nr:itm1						i=./indat/dat1.csv o=./outdat/out50.csv
${pfxc}mvsort -x   -A vf=1%nr:itm1						i=./indat/dat1.csv o=./outdat/out50x.csv
${pfxc}mvsort -nfn -A vf=1%nr:itm1						i=./indat/dat1nfn.csv o=./outdat/out50nfn.csv

${pfxc}mvsort      -A vf=items1:itm1,items2:itm2 				i=./indat/dat1.csv o=./outdat/out51.csv
${pfxc}mvsort -x   -A vf=1:itm1,2:itm2 				i=./indat/dat1.csv o=./outdat/out51x.csv
${pfxc}mvsort -nfn -A vf=1:itm1,2:itm2 				i=./indat/dat1nfn.csv o=./outdat/out51nfn.csv

${pfxc}mvsort      -A vf=items1%r:itm1,items2%r:itm2		i=./indat/dat1.csv o=./outdat/out52.csv
${pfxc}mvsort -x   -A vf=1%r:itm1,2%r:itm2		i=./indat/dat1.csv o=./outdat/out52x.csv
${pfxc}mvsort -nfn -A vf=1%r:itm1,2%r:itm2		i=./indat/dat1nfn.csv o=./outdat/out52nfn.csv

${pfxc}mvsort      -A vf=items1%n:itm1,items2%n:itm2		i=./indat/dat1.csv o=./outdat/out53.csv
${pfxc}mvsort -x   -A vf=1%n:itm1,2%n:itm2		i=./indat/dat1.csv o=./outdat/out53x.csv
${pfxc}mvsort -nfn -A vf=1%n:itm1,2%n:itm2		i=./indat/dat1nfn.csv o=./outdat/out53nfn.csv

${pfxc}mvsort      -A vf=items1%nr:itm1,items2%nr:itm2	i=./indat/dat1.csv o=./outdat/out54.csv
${pfxc}mvsort -x   -A vf=1%nr:itm1,2%nr:itm2	i=./indat/dat1.csv o=./outdat/out54x.csv
${pfxc}mvsort -nfn -A vf=1%nr:itm1,2%nr:itm1	i=./indat/dat1nfn.csv o=./outdat/out54nfn.csv

${pfxc}mvsort      -A vf=items1:itm1,items2%n:itm2 			i=./indat/dat1.csv o=./outdat/out55.csv
${pfxc}mvsort -x   -A vf=1:itm1,2%n:itm2 			i=./indat/dat1.csv o=./outdat/out55x.csv
${pfxc}mvsort -nfn -A vf=1:itm1,2%n:itm2 			i=./indat/dat1nfn.csv o=./outdat/out55nfn.csv

${pfxc}mvsort      -A vf=items1%r:itm1,items2%nr:itm2		i=./indat/dat1.csv o=./outdat/out56.csv
${pfxc}mvsort -x   -A vf=1%r:itm1,2%nr:itm2		i=./indat/dat1.csv o=./outdat/out56x.csv
${pfxc}mvsort -nfn -A vf=1%r:itm1,2%nr:itm2		i=./indat/dat1nfn.csv o=./outdat/out56nfn.csv

${pfxc}mvsort      -A vf=items1:itm1,items2%nr:itm2			i=./indat/dat1.csv o=./outdat/out57.csv
${pfxc}mvsort -x   -A vf=1:itm1,2%nr:itm2			i=./indat/dat1.csv o=./outdat/out57x.csv
${pfxc}mvsort -nfn -A vf=1:itm1,2%nr:itm2			i=./indat/dat1nfn.csv o=./outdat/out57nfn.csv

#DQを含むデータ 
${pfxc}mvsort      vf=items1 							i=./indat/dat2.csv o=./outdat/out21.csv
${pfxc}mvsort -x   vf=1 							i=./indat/dat2.csv o=./outdat/out21x.csv
${pfxc}mvsort -nfn vf=1 							i=./indat/dat2nfn.csv o=./outdat/out21nfn.csv

${pfxc}mvsort      vf=items1%r							i=./indat/dat2.csv o=./outdat/out22.csv
${pfxc}mvsort -x   vf=1%r							i=./indat/dat2.csv o=./outdat/out22x.csv
${pfxc}mvsort -nfn vf=1%r							i=./indat/dat2nfn.csv o=./outdat/out22nfn.csv

${pfxc}mvsort      vf=items1%n							i=./indat/dat2.csv o=./outdat/out23.csv
${pfxc}mvsort -x   vf=1%n							i=./indat/dat2.csv o=./outdat/out23x.csv
${pfxc}mvsort -nfn vf=1%n							i=./indat/dat2nfn.csv o=./outdat/out23nfn.csv

${pfxc}mvsort      vf=items1%nr						i=./indat/dat2.csv o=./outdat/out24.csv
${pfxc}mvsort -x   vf=1%nr						i=./indat/dat2.csv o=./outdat/out24x.csv
${pfxc}mvsort -nfn vf=1%nr						i=./indat/dat2nfn.csv o=./outdat/out24nfn.csv

${pfxc}mvsort      vf=items1,items2 				i=./indat/dat2.csv o=./outdat/out25.csv
${pfxc}mvsort -x   vf=1,2 				i=./indat/dat2.csv o=./outdat/out25x.csv
${pfxc}mvsort -nfn vf=1,2 				i=./indat/dat2nfn.csv o=./outdat/out25nfn.csv

${pfxc}mvsort      vf=items1%r,items2%r		i=./indat/dat2.csv o=./outdat/out26.csv
${pfxc}mvsort -x   vf=1%r,2%r		i=./indat/dat2.csv o=./outdat/out26x.csv
${pfxc}mvsort -nfn vf=1%r,2%r		i=./indat/dat2nfn.csv o=./outdat/out26nfn.csv

${pfxc}mvsort      vf=items1%n,items2%n		i=./indat/dat2.csv o=./outdat/out27.csv
${pfxc}mvsort -x   vf=1%n,2%n		i=./indat/dat2.csv o=./outdat/out27x.csv
${pfxc}mvsort -nfn vf=1%n,2%n		i=./indat/dat2nfn.csv o=./outdat/out27nfn.csv

${pfxc}mvsort      vf=items1%nr,items2%nr	i=./indat/dat2.csv o=./outdat/out28.csv
${pfxc}mvsort -x   vf=1%nr,2%nr	i=./indat/dat2.csv o=./outdat/out28x.csv
${pfxc}mvsort -nfn vf=1%nr,2%nr	i=./indat/dat2nfn.csv o=./outdat/out28nfn.csv

${pfxc}mvsort      vf=items1,items2%n 			i=./indat/dat2.csv o=./outdat/out29.csv
${pfxc}mvsort -x   vf=1,2%n 			i=./indat/dat2.csv o=./outdat/out29x.csv
${pfxc}mvsort -nfn vf=1,2%n 			i=./indat/dat2nfn.csv o=./outdat/out29nfn.csv

${pfxc}mvsort      vf=items1%r,items2%nr		i=./indat/dat2.csv o=./outdat/out30.csv
${pfxc}mvsort -x   vf=1%r,2%nr		i=./indat/dat2.csv o=./outdat/out30x.csv
${pfxc}mvsort -nfn vf=1%r,2%nr		i=./indat/dat2nfn.csv o=./outdat/out30nfn.csv

${pfxc}mvsort      vf=items1,items2%nr			i=./indat/dat2.csv o=./outdat/out31.csv
${pfxc}mvsort -x   vf=1,2%nr			i=./indat/dat2.csv o=./outdat/out31x.csv
${pfxc}mvsort -nfn vf=1,2%nr			i=./indat/dat2nfn.csv o=./outdat/out31nfn.csv

#delimオプション指定
${pfxc}mvsort      vf=items1 	delim=: 	i=./indat/dat3.csv o=./outdat/out33.csv
${pfxc}mvsort -x   vf=1 	delim=: 	i=./indat/dat3.csv o=./outdat/out33x.csv
${pfxc}mvsort -nfn vf=1 	delim=: 	i=./indat/dat3nfn.csv o=./outdat/out33nfn.csv

${pfxc}mvsort      vf=items2%n 	delim=: 	i=./indat/dat3.csv o=./outdat/out34.csv
${pfxc}mvsort -x   vf=2%n 	delim=: 	i=./indat/dat3.csv o=./outdat/out34x.csv
${pfxc}mvsort -nfn vf=2%n 	delim=: 	i=./indat/dat3nfn.csv o=./outdat/out34nfn.csv

${pfxc}mvsort      vf=items2%nr 	delim=: 	i=./indat/dat3.csv o=./outdat/out35.csv
${pfxc}mvsort -x   vf=2%nr 	delim=: 	i=./indat/dat3.csv o=./outdat/out35x.csv
${pfxc}mvsort -nfn vf=2%nr 	delim=: 	i=./indat/dat3nfn.csv o=./outdat/out35nfn.csv



#ソートデータ
#通常データ
${pfxc}mvsort      vf=items1 							i=./indat/dat1s.csv o=./outdat/out110.csv
${pfxc}mvsort -x   vf=1 							i=./indat/dat1s.csv o=./outdat/out110x.csv
${pfxc}mvsort -nfn vf=1 							i=./indat/dat1snfn.csv o=./outdat/out110nfn.csv

${pfxc}mvsort      vf=items1%r							i=./indat/dat1s.csv o=./outdat/out111.csv
${pfxc}mvsort -x   vf=1%r							i=./indat/dat1s.csv o=./outdat/out111x.csv
${pfxc}mvsort -nfn vf=1%r							i=./indat/dat1snfn.csv o=./outdat/out111nfn.csv

${pfxc}mvsort      vf=items1%n							i=./indat/dat1s.csv o=./outdat/out112.csv
${pfxc}mvsort -x   vf=1%n							i=./indat/dat1s.csv o=./outdat/out112x.csv
${pfxc}mvsort -nfn vf=1%n							i=./indat/dat1snfn.csv o=./outdat/out112nfn.csv

${pfxc}mvsort      vf=items1%nr						i=./indat/dat1s.csv o=./outdat/out113.csv
${pfxc}mvsort -x   vf=1%nr						i=./indat/dat1s.csv o=./outdat/out113x.csv
${pfxc}mvsort -nfn vf=1%nr						i=./indat/dat1snfn.csv o=./outdat/out113nfn.csv

${pfxc}mvsort      vf=items1,items2 				i=./indat/dat1s.csv o=./outdat/out114.csv
${pfxc}mvsort -x   vf=1,2 				i=./indat/dat1s.csv o=./outdat/out114x.csv
${pfxc}mvsort -nfn vf=1,2 				i=./indat/dat1snfn.csv o=./outdat/out114nfn.csv

${pfxc}mvsort      vf=items1%r,items2%r		i=./indat/dat1s.csv o=./outdat/out115.csv
${pfxc}mvsort -x   vf=1%r,2%r		i=./indat/dat1s.csv o=./outdat/out115x.csv
${pfxc}mvsort -nfn vf=1%r,2%r		i=./indat/dat1snfn.csv o=./outdat/out115nfn.csv

${pfxc}mvsort      vf=items1%n,items2%n		i=./indat/dat1s.csv o=./outdat/out116.csv
${pfxc}mvsort -x   vf=1%n,2%n		i=./indat/dat1s.csv o=./outdat/out116x.csv
${pfxc}mvsort -nfn vf=1%n,2%n		i=./indat/dat1snfn.csv o=./outdat/out116nfn.csv

${pfxc}mvsort      vf=items1%nr,items2%nr	i=./indat/dat1s.csv o=./outdat/out117.csv
${pfxc}mvsort -x   vf=1%nr,2%nr	i=./indat/dat1s.csv o=./outdat/out117x.csv
${pfxc}mvsort -nfn vf=1%nr,2%nr	i=./indat/dat1snfn.csv o=./outdat/out117nfn.csv

${pfxc}mvsort      vf=items1,items2%n 			i=./indat/dat1s.csv o=./outdat/out118.csv
${pfxc}mvsort -x   vf=1,2%n 			i=./indat/dat1s.csv o=./outdat/out118x.csv
${pfxc}mvsort -nfn vf=1,2%n 			i=./indat/dat1snfn.csv o=./outdat/out118nfn.csv

${pfxc}mvsort      vf=items1%r,items2%nr		i=./indat/dat1s.csv o=./outdat/out119.csv
${pfxc}mvsort -x   vf=1%r,2%nr		i=./indat/dat1s.csv o=./outdat/out119x.csv
${pfxc}mvsort -nfn vf=1%r,2%nr		i=./indat/dat1snfn.csv o=./outdat/out119nfn.csv

${pfxc}mvsort      vf=items1,items2%nr			i=./indat/dat1s.csv o=./outdat/out120.csv
${pfxc}mvsort -x   vf=1,2%nr			i=./indat/dat1s.csv o=./outdat/out120x.csv
${pfxc}mvsort -nfn vf=1,2%nr			i=./indat/dat1snfn.csv o=./outdat/out120nfn.csv



${pfxc}mvsort      vf=items1:itm1 							i=./indat/dat1s.csv o=./outdat/out136.csv
${pfxc}mvsort -x   vf=1:itm1 							i=./indat/dat1s.csv o=./outdat/out136x.csv
${pfxc}mvsort -nfn vf=1:itm1 							i=./indat/dat1snfn.csv o=./outdat/out136nfn.csv

${pfxc}mvsort      vf=items1%r:itm1							i=./indat/dat1s.csv o=./outdat/out137.csv
${pfxc}mvsort -x   vf=1%r:itm1							i=./indat/dat1s.csv o=./outdat/out137x.csv
${pfxc}mvsort -nfn vf=1%r:itm1							i=./indat/dat1snfn.csv o=./outdat/out137nfn.csv

${pfxc}mvsort      vf=items1%n:itm1							i=./indat/dat1s.csv o=./outdat/out138.csv
${pfxc}mvsort -x   vf=1%n:itm1							i=./indat/dat1s.csv o=./outdat/out138x.csv
${pfxc}mvsort -nfn vf=1%n							i=./indat/dat1snfn.csv o=./outdat/out138nfn.csv

${pfxc}mvsort      vf=items1%nr:itm1						i=./indat/dat1s.csv o=./outdat/out139.csv
${pfxc}mvsort -x   vf=1%nr:itm1						i=./indat/dat1s.csv o=./outdat/out139x.csv
${pfxc}mvsort -nfn vf=1%nr:itm1						i=./indat/dat1snfn.csv o=./outdat/out139nfn.csv

${pfxc}mvsort      vf=items1:itm1,items2:itm2 				i=./indat/dat1s.csv o=./outdat/out140.csv
${pfxc}mvsort -x   vf=1:itm1,2:itm2 				i=./indat/dat1s.csv o=./outdat/out140x.csv
${pfxc}mvsort -nfn vf=1:itm1,2:itm2 				i=./indat/dat1snfn.csv o=./outdat/out140nfn.csv

${pfxc}mvsort      vf=items1%r:itm1,items2%r:itm2		i=./indat/dat1s.csv o=./outdat/out141.csv
${pfxc}mvsort -x   vf=1%r:itm1,2%r:itm2		i=./indat/dat1s.csv o=./outdat/out141x.csv
${pfxc}mvsort -nfn vf=1%r:itm1,2%r:itm2		i=./indat/dat1snfn.csv o=./outdat/out141nfn.csv

${pfxc}mvsort      vf=items1%n:itm1,items2%n:itm2		i=./indat/dat1s.csv o=./outdat/out142.csv
${pfxc}mvsort -x   vf=1%n:itm1,2%n:itm2		i=./indat/dat1s.csv o=./outdat/out142x.csv
${pfxc}mvsort -nfn vf=1%n:itm1,2%n:itm2		i=./indat/dat1snfn.csv o=./outdat/out142nfn.csv

${pfxc}mvsort      vf=items1%nr:itm1,items2%nr:itm2	i=./indat/dat1s.csv o=./outdat/out143.csv
${pfxc}mvsort -x   vf=1%nr:itm1,2%nr:itm2	i=./indat/dat1s.csv o=./outdat/out143x.csv
${pfxc}mvsort -nfn vf=1%nr:itm1,2%nr:itm1	i=./indat/dat1snfn.csv o=./outdat/out143nfn.csv

${pfxc}mvsort      vf=items1:itm1,items2%n:itm2 			i=./indat/dat1s.csv o=./outdat/out144.csv
${pfxc}mvsort -x   vf=1:itm1,2%n:itm2 			i=./indat/dat1s.csv o=./outdat/out144x.csv
${pfxc}mvsort -nfn vf=1:itm1,2%n:itm2 			i=./indat/dat1snfn.csv o=./outdat/out144nfn.csv

${pfxc}mvsort      vf=items1%r:itm1,items2%nr:itm2		i=./indat/dat1s.csv o=./outdat/out145.csv
${pfxc}mvsort -x   vf=1%r:itm1,2%nr:itm2		i=./indat/dat1s.csv o=./outdat/out145x.csv
${pfxc}mvsort -nfn vf=1%r:itm1,2%nr:itm2		i=./indat/dat1snfn.csv o=./outdat/out145nfn.csv

${pfxc}mvsort      vf=items1:itm1,items2%nr:itm2			i=./indat/dat1s.csv o=./outdat/out146.csv
${pfxc}mvsort -x   vf=1:itm1,2%nr:itm2			i=./indat/dat1s.csv o=./outdat/out146x.csv
${pfxc}mvsort -nfn vf=1:itm1,2%nr:itm2			i=./indat/dat1snfn.csv o=./outdat/out146nfn.csv


${pfxc}mvsort      -A vf=items1:itm1 							i=./indat/dat1s.csv o=./outdat/out147.csv
${pfxc}mvsort -x   -A vf=1:itm1 							i=./indat/dat1s.csv o=./outdat/out147x.csv
${pfxc}mvsort -nfn -A vf=1:itm1 							i=./indat/dat1snfn.csv o=./outdat/out147nfn.csv

${pfxc}mvsort      -A vf=items1%r:itm1							i=./indat/dat1s.csv o=./outdat/out148.csv
${pfxc}mvsort -x   -A vf=1%r:itm1							i=./indat/dat1s.csv o=./outdat/out148x.csv
${pfxc}mvsort -nfn -A vf=1%r:itm1							i=./indat/dat1snfn.csv o=./outdat/out148nfn.csv

${pfxc}mvsort      -A vf=items1%n:itm1							i=./indat/dat1s.csv o=./outdat/out149.csv
${pfxc}mvsort -x   -A vf=1%n:itm1							i=./indat/dat1s.csv o=./outdat/out149x.csv
${pfxc}mvsort -nfn -A vf=1%n							i=./indat/dat1snfn.csv o=./outdat/out149nfn.csv

${pfxc}mvsort      -A vf=items1%nr:itm1						i=./indat/dat1s.csv o=./outdat/out150.csv
${pfxc}mvsort -x   -A vf=1%nr:itm1						i=./indat/dat1s.csv o=./outdat/out150x.csv
${pfxc}mvsort -nfn -A vf=1%nr:itm1						i=./indat/dat1snfn.csv o=./outdat/out150nfn.csv

${pfxc}mvsort      -A vf=items1:itm1,items2:itm2 				i=./indat/dat1s.csv o=./outdat/out151.csv
${pfxc}mvsort -x   -A vf=1:itm1,2:itm2 				i=./indat/dat1s.csv o=./outdat/out151x.csv
${pfxc}mvsort -nfn -A vf=1:itm1,2:itm2 				i=./indat/dat1snfn.csv o=./outdat/out151nfn.csv

${pfxc}mvsort      -A vf=items1%r:itm1,items2%r:itm2		i=./indat/dat1s.csv o=./outdat/out152.csv
${pfxc}mvsort -x   -A vf=1%r:itm1,2%r:itm2		i=./indat/dat1s.csv o=./outdat/out152x.csv
${pfxc}mvsort -nfn -A vf=1%r:itm1,2%r:itm2		i=./indat/dat1snfn.csv o=./outdat/out152nfn.csv

${pfxc}mvsort      -A vf=items1%n:itm1,items2%n:itm2		i=./indat/dat1s.csv o=./outdat/out153.csv
${pfxc}mvsort -x   -A vf=1%n:itm1,2%n:itm2		i=./indat/dat1s.csv o=./outdat/out153x.csv
${pfxc}mvsort -nfn -A vf=1%n:itm1,2%n:itm2		i=./indat/dat1snfn.csv o=./outdat/out153nfn.csv

${pfxc}mvsort      -A vf=items1%nr:itm1,items2%nr:itm2	i=./indat/dat1s.csv o=./outdat/out154.csv
${pfxc}mvsort -x   -A vf=1%nr:itm1,2%nr:itm2	i=./indat/dat1s.csv o=./outdat/out154x.csv
${pfxc}mvsort -nfn -A vf=1%nr:itm1,2%nr:itm1	i=./indat/dat1snfn.csv o=./outdat/out154nfn.csv

${pfxc}mvsort      -A vf=items1:itm1,items2%n:itm2 			i=./indat/dat1s.csv o=./outdat/out155.csv
${pfxc}mvsort -x   -A vf=1:itm1,2%n:itm2 			i=./indat/dat1s.csv o=./outdat/out155x.csv
${pfxc}mvsort -nfn -A vf=1:itm1,2%n:itm2 			i=./indat/dat1snfn.csv o=./outdat/out155nfn.csv

${pfxc}mvsort      -A vf=items1%r:itm1,items2%nr:itm2		i=./indat/dat1s.csv o=./outdat/out156.csv
${pfxc}mvsort -x   -A vf=1%r:itm1,2%nr:itm2		i=./indat/dat1s.csv o=./outdat/out156x.csv
${pfxc}mvsort -nfn -A vf=1%r:itm1,2%nr:itm2		i=./indat/dat1snfn.csv o=./outdat/out156nfn.csv

${pfxc}mvsort      -A vf=items1:itm1,items2%nr:itm2			i=./indat/dat1s.csv o=./outdat/out157.csv
${pfxc}mvsort -x   -A vf=1:itm1,2%nr:itm2			i=./indat/dat1s.csv o=./outdat/out157x.csv
${pfxc}mvsort -nfn -A vf=1:itm1,2%nr:itm2			i=./indat/dat1snfn.csv o=./outdat/out157nfn.csv



