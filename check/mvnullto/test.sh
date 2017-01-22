#!/bin/bash

. ../env

#name_kg_mcmd vnullto

#nullデータ
${pfxc}mvnullto      vf=tra1,tra2 v=unknown i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#通常データ
${pfxc}mvnullto      vf=tra1 v=unknown i=./indat/dat1.csv o=./outdat/out1.csv
${pfxc}mvnullto -x   vf=1    v=unknown i=./indat/dat1.csv o=./outdat/out1x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown i=./indat/dat1.csv o=./outdat/out2.csv
${pfxc}mvnullto -x   vf=2    v=unknown i=./indat/dat1.csv o=./outdat/out2x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown i=./indat/dat1.csv o=./outdat/out3.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown i=./indat/dat1.csv o=./outdat/out3x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

${pfxc}mvnullto      vf=tra1 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out4.csv
${pfxc}mvnullto -x   vf=1    v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out4x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown delim=_ i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out5.csv
${pfxc}mvnullto -x   vf=2    v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out5x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown delim=_ i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out6.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out6x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown delim=_ i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvnullto      vf=tra1 -p i=./indat/dat1.csv o=./outdat/out7.csv
${pfxc}mvnullto -x   vf=1    -p i=./indat/dat1.csv o=./outdat/out7x.csv
${pfxc}mvnullto -nfn vf=1    -p i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvnullto      vf=tra2 -p i=./indat/dat1.csv o=./outdat/out8.csv
${pfxc}mvnullto -x   vf=2    -p i=./indat/dat1.csv o=./outdat/out8x.csv
${pfxc}mvnullto -nfn vf=2    -p i=./indat/dat1nfn.csv o=./outdat/out8nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 -p i=./indat/dat1.csv o=./outdat/out9.csv
${pfxc}mvnullto -x   vf=1,2       -p i=./indat/dat1.csv o=./outdat/out9x.csv
${pfxc}mvnullto -nfn vf=1,2       -p i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv

${pfxc}mvnullto      vf=tra1 -p i=./indat/dat2.csv delim=_ o=./outdat/out10.csv
${pfxc}mvnullto -x   vf=1    -p i=./indat/dat2.csv delim=_ o=./outdat/out10x.csv
${pfxc}mvnullto -nfn vf=1    -p i=./indat/dat2nfn.csv delim=_ o=./outdat/out10nfn.csv

${pfxc}mvnullto      vf=tra2 -p i=./indat/dat2.csv delim=_ o=./outdat/out11.csv
${pfxc}mvnullto -x   vf=2    -p i=./indat/dat2.csv delim=_ o=./outdat/out11x.csv
${pfxc}mvnullto -nfn vf=2    -p i=./indat/dat2nfn.csv delim=_ o=./outdat/out11nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 -p i=./indat/dat2.csv delim=_ o=./outdat/out12.csv
${pfxc}mvnullto -x   vf=1,2       -p i=./indat/dat2.csv delim=_ o=./outdat/out12x.csv
${pfxc}mvnullto -nfn vf=1,2       -p i=./indat/dat2nfn.csv delim=_ o=./outdat/out12nfn.csv


${pfxc}mvnullto      vf=tra1 v=unknown O=known i=./indat/dat1.csv o=./outdat/out13.csv
${pfxc}mvnullto -x   vf=1    v=unknown O=known i=./indat/dat1.csv o=./outdat/out13x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown O=known i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown O=known i=./indat/dat1.csv o=./outdat/out14.csv
${pfxc}mvnullto -x   vf=2    v=unknown O=known i=./indat/dat1.csv o=./outdat/out14x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown O=known i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown O=known i=./indat/dat1.csv o=./outdat/out15.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown O=known i=./indat/dat1.csv o=./outdat/out15x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown O=known i=./indat/dat1nfn.csv o=./outdat/out15nfn.csv

${pfxc}mvnullto      vf=tra1 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out16.csv
${pfxc}mvnullto -x   vf=1    v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out16x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out16nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out17.csv
${pfxc}mvnullto -x   vf=2    v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out17x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out18.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out18x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv

${pfxc}mvnullto      vf=tra1 -p O=known i=./indat/dat1.csv o=./outdat/out19.csv
${pfxc}mvnullto -x   vf=1    -p O=known i=./indat/dat1.csv o=./outdat/out19x.csv
${pfxc}mvnullto -nfn vf=1    -p O=known i=./indat/dat1nfn.csv o=./outdat/out19nfn.csv

${pfxc}mvnullto      vf=tra2 -p O=known i=./indat/dat1.csv o=./outdat/out20.csv
${pfxc}mvnullto -x   vf=2    -p O=known i=./indat/dat1.csv o=./outdat/out20x.csv
${pfxc}mvnullto -nfn vf=2    -p O=known i=./indat/dat1nfn.csv o=./outdat/out20nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 -p O=known i=./indat/dat1.csv o=./outdat/out21.csv
${pfxc}mvnullto -x   vf=1,2       -p O=known i=./indat/dat1.csv o=./outdat/out21x.csv
${pfxc}mvnullto -nfn vf=1,2       -p O=known i=./indat/dat1nfn.csv o=./outdat/out21nfn.csv

${pfxc}mvnullto      vf=tra1 -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out22.csv
${pfxc}mvnullto -x   vf=1    -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out22x.csv
${pfxc}mvnullto -nfn vf=1    -p O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out22nfn.csv

${pfxc}mvnullto      vf=tra2 -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out23.csv
${pfxc}mvnullto -x   vf=2    -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out23x.csv
${pfxc}mvnullto -nfn vf=2    -p O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out23nfn.csv

${pfxc}mvnullto      vf=tra1,tra2       -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out24.csv
${pfxc}mvnullto -x   vf=1,2       -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out24x.csv
${pfxc}mvnullto -nfn vf=1,2       -p O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out24nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown i=./indat/dat1.csv o=./outdat/out25.csv
${pfxc}mvnullto -x   -A vf=1:trax1    v=unknown i=./indat/dat1.csv o=./outdat/out25x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1    v=unknown i=./indat/dat1nfn.csv o=./outdat/out25nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown i=./indat/dat1.csv o=./outdat/out26.csv
${pfxc}mvnullto -x   -A vf=2:trax2 v=unknown i=./indat/dat1.csv o=./outdat/out26x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 v=unknown i=./indat/dat1nfn.csv o=./outdat/out26nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown i=./indat/dat1.csv o=./outdat/out27.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2       v=unknown i=./indat/dat1.csv o=./outdat/out27x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2       v=unknown i=./indat/dat1nfn.csv o=./outdat/out27nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out28.csv
${pfxc}mvnullto -x   -A vf=1:trax1 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out28x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 v=unknown delim=_ i=./indat/dat2nfn.csv o=./outdat/out28nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out29.csv
${pfxc}mvnullto -x   -A vf=2:trax2    v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out29x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2    v=unknown delim=_ i=./indat/dat2nfn.csv o=./outdat/out29nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out30.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2       v=unknown delim=_ i=./indat/dat2.csv o=./outdat/out30x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2       v=unknown delim=_ i=./indat/dat2nfn.csv o=./outdat/out30nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p i=./indat/dat1.csv o=./outdat/out31.csv
${pfxc}mvnullto -x   -A vf=1:trax1    -p i=./indat/dat1.csv o=./outdat/out31x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1    -p i=./indat/dat1nfn.csv o=./outdat/out31nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 -p i=./indat/dat1.csv o=./outdat/out32.csv
${pfxc}mvnullto -x   -A vf=2:trax2    -p i=./indat/dat1.csv o=./outdat/out32x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2    -p i=./indat/dat1nfn.csv o=./outdat/out32nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p i=./indat/dat1.csv o=./outdat/out34.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2       -p i=./indat/dat1.csv o=./outdat/out34x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2       -p i=./indat/dat1nfn.csv o=./outdat/out34nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p i=./indat/dat2.csv delim=_ o=./outdat/out35.csv
${pfxc}mvnullto -x   -A vf=1:trax1    -p i=./indat/dat2.csv delim=_ o=./outdat/out35x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1    -p i=./indat/dat2nfn.csv delim=_ o=./outdat/out35nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 -p i=./indat/dat2.csv delim=_ o=./outdat/out36.csv
${pfxc}mvnullto -x   -A vf=2:trax2 -p i=./indat/dat2.csv delim=_ o=./outdat/out36x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 -p i=./indat/dat2nfn.csv delim=_ o=./outdat/out36nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p i=./indat/dat2.csv delim=_ o=./outdat/out37.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 -p i=./indat/dat2.csv delim=_ o=./outdat/out37x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 -p i=./indat/dat2nfn.csv delim=_ o=./outdat/out37nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown O=known i=./indat/dat1.csv o=./outdat/out38.csv
${pfxc}mvnullto -x   -A vf=1:trax1 v=unknown O=known i=./indat/dat1.csv o=./outdat/out38x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 v=unknown O=known i=./indat/dat1nfn.csv o=./outdat/out38nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown O=known i=./indat/dat1.csv o=./outdat/out39.csv
${pfxc}mvnullto -x   -A vf=2:trax2 v=unknown O=known i=./indat/dat1.csv o=./outdat/out39x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 v=unknown O=known i=./indat/dat1nfn.csv o=./outdat/out39nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown O=known i=./indat/dat1.csv o=./outdat/out40.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 v=unknown O=known i=./indat/dat1.csv o=./outdat/out40x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 v=unknown O=known i=./indat/dat1nfn.csv o=./outdat/out40nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out41.csv
${pfxc}mvnullto -x   -A vf=1:trax1 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out41x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 v=unknown O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out41nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out42.csv
${pfxc}mvnullto -x   -A vf=2:trax2 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out42x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 v=unknown O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out42nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out43.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 v=unknown O=known delim=_ i=./indat/dat2.csv o=./outdat/out43x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 v=unknown O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out43nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p O=known i=./indat/dat1.csv o=./outdat/out44.csv
${pfxc}mvnullto -x   -A vf=1:trax1 -p O=known i=./indat/dat1.csv o=./outdat/out44x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 -p O=known i=./indat/dat1nfn.csv o=./outdat/out44nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 -p O=known i=./indat/dat1.csv o=./outdat/out45.csv
${pfxc}mvnullto -x   -A vf=2:trax2 -p O=known i=./indat/dat1.csv o=./outdat/out45x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 -p O=known i=./indat/dat1nfn.csv o=./outdat/out45nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p O=known i=./indat/dat1.csv o=./outdat/out46.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 -p O=known i=./indat/dat1.csv o=./outdat/out46x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 -p O=known i=./indat/dat1nfn.csv o=./outdat/out46nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out47.csv
${pfxc}mvnullto -x   -A vf=1:trax1 -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out47x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 -p O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out47nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2            -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out48.csv
${pfxc}mvnullto -x   -A vf=2:trax2            -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out48x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2            -p O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out48nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out49.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 -p O=known delim=_ i=./indat/dat2.csv o=./outdat/out49x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 -p O=known delim=_ i=./indat/dat2nfn.csv o=./outdat/out49nfn.csv





#ソートデータ
#通常データ
${pfxc}mvnullto      vf=tra1 v=unknown i=./indat/dat1s.csv o=./outdat/out51.csv
${pfxc}mvnullto -x   vf=1    v=unknown i=./indat/dat1s.csv o=./outdat/out51x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown i=./indat/dat1snfn.csv o=./outdat/out51nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown i=./indat/dat1s.csv o=./outdat/out52.csv
${pfxc}mvnullto -x   vf=2    v=unknown i=./indat/dat1s.csv o=./outdat/out52x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown i=./indat/dat1snfn.csv o=./outdat/out52nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown i=./indat/dat1s.csv o=./outdat/out53.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown i=./indat/dat1s.csv o=./outdat/out53x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown i=./indat/dat1snfn.csv o=./outdat/out53nfn.csv

${pfxc}mvnullto      vf=tra1 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out54.csv
${pfxc}mvnullto -x   vf=1    v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out54x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown delim=_ i=./indat/dat2snfn.csv o=./outdat/out54nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out55.csv
${pfxc}mvnullto -x   vf=2    v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out55x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown delim=_ i=./indat/dat2snfn.csv o=./outdat/out55nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out56.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out56x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown delim=_ i=./indat/dat2snfn.csv o=./outdat/out56nfn.csv

${pfxc}mvnullto      vf=tra1 -p i=./indat/dat1s.csv o=./outdat/out57.csv
${pfxc}mvnullto -x   vf=1    -p i=./indat/dat1s.csv o=./outdat/out57x.csv
${pfxc}mvnullto -nfn vf=1    -p i=./indat/dat1snfn.csv o=./outdat/out57nfn.csv

${pfxc}mvnullto      vf=tra2 -p i=./indat/dat1s.csv o=./outdat/out58.csv
${pfxc}mvnullto -x   vf=2    -p i=./indat/dat1s.csv o=./outdat/out58x.csv
${pfxc}mvnullto -nfn vf=2    -p i=./indat/dat1snfn.csv o=./outdat/out58nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 -p i=./indat/dat1s.csv o=./outdat/out59.csv
${pfxc}mvnullto -x   vf=1,2       -p i=./indat/dat1s.csv o=./outdat/out59x.csv
${pfxc}mvnullto -nfn vf=1,2       -p i=./indat/dat1snfn.csv o=./outdat/out59nfn.csv

${pfxc}mvnullto      vf=tra1 -p i=./indat/dat2s.csv delim=_ o=./outdat/out60.csv
${pfxc}mvnullto -x   vf=1    -p i=./indat/dat2s.csv delim=_ o=./outdat/out60x.csv
${pfxc}mvnullto -nfn vf=1    -p i=./indat/dat2snfn.csv delim=_ o=./outdat/out60nfn.csv

${pfxc}mvnullto      vf=tra2 -p i=./indat/dat2s.csv delim=_ o=./outdat/out61.csv
${pfxc}mvnullto -x   vf=2    -p i=./indat/dat2s.csv delim=_ o=./outdat/out61x.csv
${pfxc}mvnullto -nfn vf=2    -p i=./indat/dat2snfn.csv delim=_ o=./outdat/out61nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 -p i=./indat/dat2s.csv delim=_ o=./outdat/out62.csv
${pfxc}mvnullto -x   vf=1,2       -p i=./indat/dat2s.csv delim=_ o=./outdat/out62x.csv
${pfxc}mvnullto -nfn vf=1,2       -p i=./indat/dat2snfn.csv delim=_ o=./outdat/out62nfn.csv


${pfxc}mvnullto      vf=tra1 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out63.csv
${pfxc}mvnullto -x   vf=1    v=unknown O=known i=./indat/dat1s.csv o=./outdat/out63x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown O=known i=./indat/dat1snfn.csv o=./outdat/out63nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out64.csv
${pfxc}mvnullto -x   vf=2    v=unknown O=known i=./indat/dat1s.csv o=./outdat/out64x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown O=known i=./indat/dat1snfn.csv o=./outdat/out64nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out65.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown O=known i=./indat/dat1s.csv o=./outdat/out65x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown O=known i=./indat/dat1snfn.csv o=./outdat/out65nfn.csv

${pfxc}mvnullto      vf=tra1 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out66.csv
${pfxc}mvnullto -x   vf=1    v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out66x.csv
${pfxc}mvnullto -nfn vf=1    v=unknown O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out66nfn.csv

${pfxc}mvnullto      vf=tra2 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out67.csv
${pfxc}mvnullto -x   vf=2    v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out67x.csv
${pfxc}mvnullto -nfn vf=2    v=unknown O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out67nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out68.csv
${pfxc}mvnullto -x   vf=1,2       v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out68x.csv
${pfxc}mvnullto -nfn vf=1,2       v=unknown O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out68nfn.csv

${pfxc}mvnullto      vf=tra1 -p O=known i=./indat/dat1s.csv o=./outdat/out69.csv
${pfxc}mvnullto -x   vf=1    -p O=known i=./indat/dat1s.csv o=./outdat/out69x.csv
${pfxc}mvnullto -nfn vf=1    -p O=known i=./indat/dat1snfn.csv o=./outdat/out69nfn.csv

${pfxc}mvnullto      vf=tra2 -p O=known i=./indat/dat1s.csv o=./outdat/out70.csv
${pfxc}mvnullto -x   vf=2    -p O=known i=./indat/dat1s.csv o=./outdat/out70x.csv
${pfxc}mvnullto -nfn vf=2    -p O=known i=./indat/dat1snfn.csv o=./outdat/out70nfn.csv

${pfxc}mvnullto      vf=tra1,tra2 -p O=known i=./indat/dat1s.csv o=./outdat/out71.csv
${pfxc}mvnullto -x   vf=1,2       -p O=known i=./indat/dat1s.csv o=./outdat/out71x.csv
${pfxc}mvnullto -nfn vf=1,2       -p O=known i=./indat/dat1snfn.csv o=./outdat/out71nfn.csv

${pfxc}mvnullto      vf=tra1 -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out72.csv
${pfxc}mvnullto -x   vf=1    -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out72x.csv
${pfxc}mvnullto -nfn vf=1    -p O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out72nfn.csv

${pfxc}mvnullto      vf=tra2 -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out73.csv
${pfxc}mvnullto -x   vf=2    -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out73x.csv
${pfxc}mvnullto -nfn vf=2    -p O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out73nfn.csv

${pfxc}mvnullto      vf=tra1,tra2       -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out74.csv
${pfxc}mvnullto -x   vf=1,2       -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out74x.csv
${pfxc}mvnullto -nfn vf=1,2       -p O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out74nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown i=./indat/dat1s.csv o=./outdat/out75.csv
${pfxc}mvnullto -x   -A vf=1:trax1    v=unknown i=./indat/dat1s.csv o=./outdat/out75x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1    v=unknown i=./indat/dat1snfn.csv o=./outdat/out75nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown i=./indat/dat1s.csv o=./outdat/out76.csv
${pfxc}mvnullto -x   -A vf=2:trax2 v=unknown i=./indat/dat1s.csv o=./outdat/out76x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 v=unknown i=./indat/dat1snfn.csv o=./outdat/out76nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown i=./indat/dat1s.csv o=./outdat/out77.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2       v=unknown i=./indat/dat1s.csv o=./outdat/out77x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2       v=unknown i=./indat/dat1snfn.csv o=./outdat/out77nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out78.csv
${pfxc}mvnullto -x   -A vf=1:trax1 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out78x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 v=unknown delim=_ i=./indat/dat2snfn.csv o=./outdat/out78nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out79.csv
${pfxc}mvnullto -x   -A vf=2:trax2    v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out79x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2    v=unknown delim=_ i=./indat/dat2snfn.csv o=./outdat/out79nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out80.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2       v=unknown delim=_ i=./indat/dat2s.csv o=./outdat/out80x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2       v=unknown delim=_ i=./indat/dat2snfn.csv o=./outdat/out80nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p i=./indat/dat1s.csv o=./outdat/out81.csv
${pfxc}mvnullto -x   -A vf=1:trax1    -p i=./indat/dat1s.csv o=./outdat/out81x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1    -p i=./indat/dat1snfn.csv o=./outdat/out81nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 -p i=./indat/dat1s.csv o=./outdat/out82.csv
${pfxc}mvnullto -x   -A vf=2:trax2    -p i=./indat/dat1s.csv o=./outdat/out82x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2    -p i=./indat/dat1snfn.csv o=./outdat/out82nfn.csv


${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p i=./indat/dat1s.csv o=./outdat/out84.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2       -p i=./indat/dat1s.csv o=./outdat/out84x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2       -p i=./indat/dat1snfn.csv o=./outdat/out84nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p i=./indat/dat2s.csv delim=_ o=./outdat/out85.csv
${pfxc}mvnullto -x   -A vf=1:trax1    -p i=./indat/dat2s.csv delim=_ o=./outdat/out85x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1    -p i=./indat/dat2snfn.csv delim=_ o=./outdat/out85nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 -p i=./indat/dat2s.csv delim=_ o=./outdat/out86.csv
${pfxc}mvnullto -x   -A vf=2:trax2 -p i=./indat/dat2s.csv delim=_ o=./outdat/out86x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 -p i=./indat/dat2snfn.csv delim=_ o=./outdat/out86nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p i=./indat/dat2s.csv delim=_ o=./outdat/out87.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 -p i=./indat/dat2s.csv delim=_ o=./outdat/out87x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 -p i=./indat/dat2snfn.csv delim=_ o=./outdat/out87nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out88.csv
${pfxc}mvnullto -x   -A vf=1:trax1 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out88x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 v=unknown O=known i=./indat/dat1snfn.csv o=./outdat/out88nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out89.csv
${pfxc}mvnullto -x   -A vf=2:trax2 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out89x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 v=unknown O=known i=./indat/dat1snfn.csv o=./outdat/out89nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out90.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 v=unknown O=known i=./indat/dat1s.csv o=./outdat/out90x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 v=unknown O=known i=./indat/dat1snfn.csv o=./outdat/out90nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out91.csv
${pfxc}mvnullto -x   -A vf=1:trax1 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out91x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 v=unknown O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out91nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out92.csv
${pfxc}mvnullto -x   -A vf=2:trax2 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out92x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 v=unknown O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out92nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out93.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 v=unknown O=known delim=_ i=./indat/dat2s.csv o=./outdat/out93x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 v=unknown O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out93nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p O=known i=./indat/dat1s.csv o=./outdat/out94.csv
${pfxc}mvnullto -x   -A vf=1:trax1 -p O=known i=./indat/dat1s.csv o=./outdat/out94x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 -p O=known i=./indat/dat1snfn.csv o=./outdat/out94nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2 -p O=known i=./indat/dat1s.csv o=./outdat/out95.csv
${pfxc}mvnullto -x   -A vf=2:trax2 -p O=known i=./indat/dat1s.csv o=./outdat/out95x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2 -p O=known i=./indat/dat1snfn.csv o=./outdat/out95nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p O=known i=./indat/dat1s.csv o=./outdat/out96.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 -p O=known i=./indat/dat1s.csv o=./outdat/out96x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 -p O=known i=./indat/dat1snfn.csv o=./outdat/out96nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1 -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out97.csv
${pfxc}mvnullto -x   -A vf=1:trax1 -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out97x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1 -p O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out97nfn.csv

${pfxc}mvnullto      -A vf=tra2:trax2            -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out98.csv
${pfxc}mvnullto -x   -A vf=2:trax2            -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out98x.csv
${pfxc}mvnullto -nfn -A vf=2:trax2            -p O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out98nfn.csv

${pfxc}mvnullto      -A vf=tra1:trax1,tra2:trax2 -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out99.csv
${pfxc}mvnullto -x   -A vf=1:trax1,2:trax2 -p O=known delim=_ i=./indat/dat2s.csv o=./outdat/out99x.csv
${pfxc}mvnullto -nfn -A vf=1:trax1,2:trax2 -p O=known delim=_ i=./indat/dat2snfn.csv o=./outdat/out99nfn.csv



