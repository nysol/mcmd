#!/bin/bash

. ../env

#name_kg_mcmd vdelim

#nullデータ
${pfxc}mvdelim      vf=items1 v=- i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvdelim -x   vf=1 v=- i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvdelim -nfn vf=1 v=- i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv


${pfxc}mvdelim      vf=items1 v=	i=./indat/dat0.csv o=./outdat/out1.csv
${pfxc}mvdelim -x   vf=1 v=	i=./indat/dat0.csv o=./outdat/out1x.csv
${pfxc}mvdelim -nfn vf=1 v=	i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=-	i=./indat/dat0.csv o=./outdat/out2.csv
${pfxc}mvdelim -x   vf=1,2 v=-	i=./indat/dat0.csv o=./outdat/out2x.csv
${pfxc}mvdelim -nfn vf=1,2 v=-	i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=	i=./indat/dat0.csv o=./outdat/out3.csv
${pfxc}mvdelim -x   vf=1,2 v=	i=./indat/dat0.csv o=./outdat/out3x.csv
${pfxc}mvdelim -nfn vf=1,2 v=	i=./indat/dat0nfn.csv o=./outdat/out3nfn.csv

#通常データ
${pfxc}mvdelim      vf=items1 v=- i=./indat/dat1.csv o=./outdat/out4.csv
${pfxc}mvdelim -x   vf=1 v=- i=./indat/dat1.csv o=./outdat/out4x.csv
${pfxc}mvdelim -nfn vf=1 v=- i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvdelim      vf=items1 v=	i=./indat/dat1.csv o=./outdat/out5.csv
${pfxc}mvdelim -x   vf=1 v=	i=./indat/dat1.csv o=./outdat/out5x.csv
${pfxc}mvdelim -nfn vf=1 v=	i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvdelim      vf=items1 v=xxx i=./indat/dat1.csv o=./outdat/out6.csv
${pfxc}mvdelim -x   vf=1 v=xxx i=./indat/dat1.csv o=./outdat/out6x.csv
${pfxc}mvdelim -nfn vf=1 v=xxx i=./indat/dat1nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvdelim      vf=items1 v=, i=./indat/dat1.csv o=./outdat/out7.csv
${pfxc}mvdelim -x   vf=1 v=, i=./indat/dat1.csv o=./outdat/out7x.csv
${pfxc}mvdelim -nfn vf=1 v=, i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=-		i=./indat/dat1.csv o=./outdat/out8.csv
${pfxc}mvdelim -x   vf=1,2 v=-		i=./indat/dat1.csv o=./outdat/out8x.csv
${pfxc}mvdelim -nfn vf=1,2 v=-		i=./indat/dat1nfn.csv o=./outdat/out8nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=		i=./indat/dat1.csv o=./outdat/out9.csv
${pfxc}mvdelim -x   vf=1,2 v=		i=./indat/dat1.csv o=./outdat/out9x.csv
${pfxc}mvdelim -nfn vf=1,2 v=		i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=xxx	i=./indat/dat1.csv o=./outdat/out10.csv
${pfxc}mvdelim -x   vf=1,2 v=xxx i=./indat/dat1.csv o=./outdat/out10x.csv
${pfxc}mvdelim -nfn vf=1,2 v=xxx i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=,		i=./indat/dat1.csv o=./outdat/out11.csv
${pfxc}mvdelim -x   vf=1,2 v=,		i=./indat/dat1.csv o=./outdat/out11x.csv
${pfxc}mvdelim -nfn vf=1,2 v=,		i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv


${pfxc}mvdelim      vf=items1:xxa v=-		i=./indat/dat1.csv o=./outdat/out40.csv
${pfxc}mvdelim -x   vf=1:xxa v=-		i=./indat/dat1.csv o=./outdat/out40x.csv
${pfxc}mvdelim -nfn vf=1:xxa v=-		i=./indat/dat1nfn.csv o=./outdat/out40nfn.csv

${pfxc}mvdelim      vf=items1:xxa,items2 v=-		i=./indat/dat1.csv o=./outdat/out41.csv
${pfxc}mvdelim -x   vf=1:xxa,2 v=-		i=./indat/dat1.csv o=./outdat/out41x.csv
${pfxc}mvdelim -nfn vf=1:xxa,2 v=-		i=./indat/dat1nfn.csv o=./outdat/out41nfn.csv

${pfxc}mvdelim      vf=items1:xxa,items2:xxb v=-		i=./indat/dat1.csv o=./outdat/out42.csv
${pfxc}mvdelim -x   vf=1:xxa,2:xxb v=-		i=./indat/dat1.csv o=./outdat/out42x.csv
${pfxc}mvdelim -nfn vf=1:xxa,2:xxb v=-		i=./indat/dat1nfn.csv o=./outdat/out42nfn.csv


${pfxc}mvdelim      -A vf=items1:xxa v=-		i=./indat/dat1.csv o=./outdat/out43.csv
${pfxc}mvdelim -x   -A vf=1:xxa v=-		i=./indat/dat1.csv o=./outdat/out43x.csv
${pfxc}mvdelim -nfn -A vf=1:xxa v=-		i=./indat/dat1nfn.csv o=./outdat/out43nfn.csv

${pfxc}mvdelim      -A vf=items1:xxa,items2:xxb v=-		i=./indat/dat1.csv o=./outdat/out44.csv
${pfxc}mvdelim -x   -A vf=1:xxa,2:xxb v=-		i=./indat/dat1.csv o=./outdat/out44x.csv
${pfxc}mvdelim -nfn -A vf=1:xxa,2:xxb v=-		i=./indat/dat1nfn.csv o=./outdat/out44nfn.csv


#DQ,NULLを含むデータ 
${pfxc}mvdelim      vf=items1 v=- i=./indat/dat2.csv    o=./outdat/out12.csv
${pfxc}mvdelim -x   vf=1      v=- i=./indat/dat2.csv    o=./outdat/out12x.csv
${pfxc}mvdelim -nfn vf=1      v=- i=./indat/dat2nfn.csv o=./outdat/out12nfn.csv

${pfxc}mvdelim      vf=items1 v= i=./indat/dat2.csv    o=./outdat/out13.csv
${pfxc}mvdelim -x   vf=1      v= i=./indat/dat2.csv    o=./outdat/out13x.csv
${pfxc}mvdelim -nfn vf=1      v= i=./indat/dat2nfn.csv o=./outdat/out13nfn.csv

${pfxc}mvdelim      vf=items1 v=xxx i=./indat/dat2.csv    o=./outdat/out14.csv
${pfxc}mvdelim -x   vf=1      v=xxx i=./indat/dat2.csv    o=./outdat/out14x.csv
${pfxc}mvdelim -nfn vf=1      v=xxx i=./indat/dat2nfn.csv o=./outdat/out14nfn.csv

${pfxc}mvdelim      vf=items1 v=, i=./indat/dat2.csv    o=./outdat/out15.csv
${pfxc}mvdelim -x   vf=1      v=, i=./indat/dat2.csv    o=./outdat/out15x.csv
${pfxc}mvdelim -nfn vf=1      v=, i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=- i=./indat/dat2.csv    o=./outdat/out16.csv
${pfxc}mvdelim -x   vf=1,2           v=- i=./indat/dat2.csv    o=./outdat/out16x.csv
${pfxc}mvdelim -nfn vf=1,2           v=- i=./indat/dat2nfn.csv o=./outdat/out16nfn.csv

${pfxc}mvdelim      vf=items1,items2 v= i=./indat/dat2.csv    o=./outdat/out17.csv
${pfxc}mvdelim -x   vf=1,2           v= i=./indat/dat2.csv    o=./outdat/out17x.csv
${pfxc}mvdelim -nfn vf=1,2          v= i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=xxx i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}mvdelim -x   vf=1,2          v=xxx i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}mvdelim -nfn vf=1,2          v=xxx i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv

${pfxc}mvdelim       vf=items1,items2 v=, i=./indat/dat2.csv    o=./outdat/out19.csv
${pfxc}mvdelim -x    vf=1,2           v=, i=./indat/dat2.csv    o=./outdat/out19x.csv
${pfxc}mvdelim -nfn  vf=1,2           v=, i=./indat/dat2nfn.csv o=./outdat/out19nfn.csv


#ソートデータ
${pfxc}mvdelim      vf=items1 v=- i=./indat/dat1s.csv o=./outdat/out24.csv
${pfxc}mvdelim -x   vf=1 v=- i=./indat/dat1s.csv o=./outdat/out24x.csv
${pfxc}mvdelim -nfn vf=1 v=- i=./indat/dat1snfn.csv o=./outdat/out24nfn.csv

${pfxc}mvdelim      vf=items1 v=	i=./indat/dat1s.csv o=./outdat/out25.csv
${pfxc}mvdelim -x   vf=1 v=	i=./indat/dat1s.csv o=./outdat/out25x.csv
${pfxc}mvdelim -nfn vf=1 v=	i=./indat/dat1snfn.csv o=./outdat/out25nfn.csv

${pfxc}mvdelim      vf=items1 v=xxx i=./indat/dat1s.csv o=./outdat/out26.csv
${pfxc}mvdelim -x   vf=1 v=xxx i=./indat/dat1s.csv o=./outdat/out26x.csv
${pfxc}mvdelim -nfn vf=1 v=xxx i=./indat/dat1snfn.csv o=./outdat/out26nfn.csv

${pfxc}mvdelim      vf=items1 v=, i=./indat/dat1s.csv o=./outdat/out27.csv
${pfxc}mvdelim -x   vf=1 v=, i=./indat/dat1s.csv o=./outdat/out27x.csv
${pfxc}mvdelim -nfn vf=1 v=, i=./indat/dat1snfn.csv o=./outdat/out27nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=-		i=./indat/dat1s.csv o=./outdat/out28.csv
${pfxc}mvdelim -x   vf=1,2 v=-		i=./indat/dat1s.csv o=./outdat/out28x.csv
${pfxc}mvdelim -nfn vf=1,2 v=-		i=./indat/dat1snfn.csv o=./outdat/out28nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=		i=./indat/dat1s.csv o=./outdat/out29.csv
${pfxc}mvdelim -x   vf=1,2 v=		i=./indat/dat1s.csv o=./outdat/out29x.csv
${pfxc}mvdelim -nfn vf=1,2 v=		i=./indat/dat1snfn.csv o=./outdat/out29nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=xxx	i=./indat/dat1s.csv o=./outdat/out30.csv
${pfxc}mvdelim -x   vf=1,2 v=xxx i=./indat/dat1s.csv o=./outdat/out30x.csv
${pfxc}mvdelim -nfn vf=1,2 v=xxx i=./indat/dat1snfn.csv o=./outdat/out30nfn.csv

${pfxc}mvdelim      vf=items1,items2 v=,		i=./indat/dat1s.csv o=./outdat/out31.csv
${pfxc}mvdelim -x   vf=1,2 v=,		i=./indat/dat1s.csv o=./outdat/out31x.csv
${pfxc}mvdelim -nfn vf=1,2 v=,		i=./indat/dat1snfn.csv o=./outdat/out31nfn.csv

${pfxc}mvdelim      vf=items2 v=	i=./indat/dat1s.csv o=./outdat/out32.csv
${pfxc}mvdelim -x   vf=2 v=	i=./indat/dat1s.csv o=./outdat/out32x.csv
${pfxc}mvdelim -nfn vf=2 v=	i=./indat/dat1snfn.csv o=./outdat/out32nfn.csv


${pfxc}mvdelim      vf=items1:xxa v=-		i=./indat/dat1s.csv o=./outdat/out60.csv
${pfxc}mvdelim -x   vf=1:xxa v=-		i=./indat/dat1s.csv o=./outdat/out60x.csv
${pfxc}mvdelim -nfn vf=1:xxa v=-		i=./indat/dat1snfn.csv o=./outdat/out60nfn.csv

${pfxc}mvdelim      vf=items1:xxa,items2 v=-		i=./indat/dat1s.csv o=./outdat/out61.csv
${pfxc}mvdelim -x   vf=1:xxa,2 v=-		i=./indat/dat1s.csv o=./outdat/out61x.csv
${pfxc}mvdelim -nfn vf=1:xxa,2 v=-		i=./indat/dat1snfn.csv o=./outdat/out61nfn.csv

${pfxc}mvdelim      vf=items1:xxa,items2:xxb v=-		i=./indat/dat1s.csv o=./outdat/out62.csv
${pfxc}mvdelim -x   vf=1:xxa,2:xxb v=-		i=./indat/dat1s.csv o=./outdat/out62x.csv
${pfxc}mvdelim -nfn vf=1:xxa,2:xxb v=-		i=./indat/dat1snfn.csv o=./outdat/out62nfn.csv


${pfxc}mvdelim      -A vf=items1:xxa v=-		i=./indat/dat1s.csv o=./outdat/out63.csv
${pfxc}mvdelim -x   -A vf=1:xxa v=-		i=./indat/dat1s.csv o=./outdat/out63x.csv
${pfxc}mvdelim -nfn -A vf=1:xxa v=-		i=./indat/dat1snfn.csv o=./outdat/out63nfn.csv

${pfxc}mvdelim      -A vf=items1:xxa,items2:xxb v=-		i=./indat/dat1s.csv o=./outdat/out64.csv
${pfxc}mvdelim -x   -A vf=1:xxa,2:xxb v=-		i=./indat/dat1s.csv o=./outdat/out64x.csv
${pfxc}mvdelim -nfn -A vf=1:xxa,2:xxb v=-		i=./indat/dat1snfn.csv o=./outdat/out64nfn.csv


