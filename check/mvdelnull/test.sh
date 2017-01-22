#!/bin/bash

. ../env

#name_kg_mcmd vdelnull

#nullデータ
${pfxc}mvdelnull      vf=tra1,tra2 i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvdelnull -x   vf=1,2 i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvdelnull -nfn vf=1,2 i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#通常データ
${pfxc}mvdelnull      vf=tra1      i=./indat/dat1.csv o=./outdat/out1.csv
${pfxc}mvdelnull -x   vf=1      i=./indat/dat1.csv o=./outdat/out1x.csv
${pfxc}mvdelnull -nfn vf=1      i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv


${pfxc}mvdelnull      vf=tra2      i=./indat/dat1.csv o=./outdat/out2.csv
${pfxc}mvdelnull -x   vf=2      i=./indat/dat1.csv o=./outdat/out2x.csv
${pfxc}mvdelnull -nfn vf=2      i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

${pfxc}mvdelnull      vf=tra1,tra2 i=./indat/dat1.csv o=./outdat/out3.csv
${pfxc}mvdelnull -x   vf=1,2       i=./indat/dat1.csv o=./outdat/out3x.csv
${pfxc}mvdelnull -nfn vf=1,2       i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

${pfxc}mvdelnull      vf=tra1   delim=_ i=./indat/dat2.csv o=./outdat/out4.csv
${pfxc}mvdelnull -x   vf=1      delim=_ i=./indat/dat2.csv o=./outdat/out4x.csv
${pfxc}mvdelnull -nfn vf=1      delim=_ i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvdelnull      vf=tra2   delim=_ i=./indat/dat2.csv o=./outdat/out5.csv
${pfxc}mvdelnull -x   vf=2      delim=_ i=./indat/dat2.csv o=./outdat/out5x.csv
${pfxc}mvdelnull -nfn vf=2      delim=_ i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvdelnull      vf=tra1,tra2 delim=_ i=./indat/dat2.csv o=./outdat/out6.csv
${pfxc}mvdelnull -x   vf=1,2       delim=_ i=./indat/dat2.csv o=./outdat/out6x.csv
${pfxc}mvdelnull -nfn vf=1,2       delim=_ i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv


${pfxc}mvdelnull      -A vf=tra1:trax1         i=./indat/dat1.csv o=./outdat/out7.csv
${pfxc}mvdelnull -x   -A vf=1:trax1            i=./indat/dat1.csv o=./outdat/out7x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1            i=./indat/dat1nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvdelnull      -A vf=tra2:trax2         i=./indat/dat1.csv o=./outdat/out8.csv
${pfxc}mvdelnull -x   -A vf=2:trax2            i=./indat/dat1.csv o=./outdat/out8x.csv
${pfxc}mvdelnull -nfn -A vf=2:trax2            i=./indat/dat1nfn.csv o=./outdat/out8nfn.csv

${pfxc}mvdelnull      -A vf=tra1:trax1,tra2:trax2 i=./indat/dat1.csv o=./outdat/out9.csv
${pfxc}mvdelnull -x   -A vf=1:trax1,2:trax2       i=./indat/dat1.csv o=./outdat/out9x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1,2:trax2       i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv

${pfxc}mvdelnull      -A vf=tra1:trax1         delim=_ i=./indat/dat2.csv o=./outdat/out10.csv
${pfxc}mvdelnull -x   -A vf=1:trax1            delim=_ i=./indat/dat2.csv o=./outdat/out10x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1            delim=_ i=./indat/dat2nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvdelnull      -A vf=tra2:trax2         delim=_ i=./indat/dat2.csv o=./outdat/out11.csv
${pfxc}mvdelnull -x   -A vf=2:trax2            delim=_ i=./indat/dat2.csv o=./outdat/out11x.csv
${pfxc}mvdelnull -nfn -A vf=2:trax2            delim=_ i=./indat/dat2nfn.csv o=./outdat/out11nfn.csv

${pfxc}mvdelnull      -A vf=tra1:trax1,tra2:trax2 delim=_ i=./indat/dat2.csv o=./outdat/out12.csv
${pfxc}mvdelnull -x   -A vf=1:trax1,2:trax2       delim=_ i=./indat/dat2.csv o=./outdat/out12x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1,2:trax2       delim=_ i=./indat/dat2nfn.csv o=./outdat/out12nfn.csv



#通常データ
${pfxc}mvdelnull      vf=tra1   i=./indat/dat1s.csv o=./outdat/out21.csv
${pfxc}mvdelnull -x   vf=1      i=./indat/dat1s.csv o=./outdat/out21x.csv
${pfxc}mvdelnull -nfn vf=1      i=./indat/dat1snfn.csv o=./outdat/out21nfn.csv


${pfxc}mvdelnull      vf=tra2      i=./indat/dat1s.csv o=./outdat/out22.csv
${pfxc}mvdelnull -x   vf=2      i=./indat/dat1s.csv o=./outdat/out22x.csv
${pfxc}mvdelnull -nfn vf=2      i=./indat/dat1snfn.csv o=./outdat/out22nfn.csv

${pfxc}mvdelnull      vf=tra1,tra2 i=./indat/dat1s.csv o=./outdat/out23.csv
${pfxc}mvdelnull -x   vf=1,2       i=./indat/dat1s.csv o=./outdat/out23x.csv
${pfxc}mvdelnull -nfn vf=1,2       i=./indat/dat1snfn.csv o=./outdat/out23nfn.csv

${pfxc}mvdelnull      vf=tra1   delim=_ i=./indat/dat2s.csv o=./outdat/out24.csv
${pfxc}mvdelnull -x   vf=1      delim=_ i=./indat/dat2s.csv o=./outdat/out24x.csv
${pfxc}mvdelnull -nfn vf=1      delim=_ i=./indat/dat2snfn.csv o=./outdat/out24nfn.csv

${pfxc}mvdelnull      vf=tra2   delim=_ i=./indat/dat2s.csv o=./outdat/out25.csv
${pfxc}mvdelnull -x   vf=2      delim=_ i=./indat/dat2s.csv o=./outdat/out25x.csv
${pfxc}mvdelnull -nfn vf=2      delim=_ i=./indat/dat2snfn.csv o=./outdat/out25nfn.csv

${pfxc}mvdelnull      vf=tra1,tra2 delim=_ i=./indat/dat2s.csv o=./outdat/out26.csv
${pfxc}mvdelnull -x   vf=1,2       delim=_ i=./indat/dat2s.csv o=./outdat/out26x.csv
${pfxc}mvdelnull -nfn vf=1,2       delim=_ i=./indat/dat2snfn.csv o=./outdat/out26nfn.csv


${pfxc}mvdelnull      -A vf=tra1:trax1         i=./indat/dat1s.csv o=./outdat/out27.csv
${pfxc}mvdelnull -x   -A vf=1:trax1            i=./indat/dat1s.csv o=./outdat/out27x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1            i=./indat/dat1snfn.csv o=./outdat/out27nfn.csv

${pfxc}mvdelnull      -A vf=tra2:trax2         i=./indat/dat1s.csv o=./outdat/out28.csv
${pfxc}mvdelnull -x   -A vf=2:trax2            i=./indat/dat1s.csv o=./outdat/out28x.csv
${pfxc}mvdelnull -nfn -A vf=2:trax2            i=./indat/dat1snfn.csv o=./outdat/out28nfn.csv

${pfxc}mvdelnull      -A vf=tra1:trax1,tra2:trax2 i=./indat/dat1s.csv o=./outdat/out29.csv
${pfxc}mvdelnull -x   -A vf=1:trax1,2:trax2       i=./indat/dat1s.csv o=./outdat/out29x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1,2:trax2       i=./indat/dat1snfn.csv o=./outdat/out29nfn.csv

${pfxc}mvdelnull      -A vf=tra1:trax1         delim=_ i=./indat/dat2s.csv o=./outdat/out30.csv
${pfxc}mvdelnull -x   -A vf=1:trax1            delim=_ i=./indat/dat2s.csv o=./outdat/out30x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1            delim=_ i=./indat/dat2snfn.csv o=./outdat/out30nfn.csv

${pfxc}mvdelnull      -A vf=tra2:trax2         delim=_ i=./indat/dat2s.csv o=./outdat/out31.csv
${pfxc}mvdelnull -x   -A vf=2:trax2            delim=_ i=./indat/dat2s.csv o=./outdat/out31x.csv
${pfxc}mvdelnull -nfn -A vf=2:trax2            delim=_ i=./indat/dat2snfn.csv o=./outdat/out31nfn.csv

${pfxc}mvdelnull      -A vf=tra1:trax1,tra2:trax2 delim=_ i=./indat/dat2s.csv o=./outdat/out32.csv
${pfxc}mvdelnull -x   -A vf=1:trax1,2:trax2       delim=_ i=./indat/dat2s.csv o=./outdat/out32x.csv
${pfxc}mvdelnull -nfn -A vf=1:trax1,2:trax2       delim=_ i=./indat/dat2snfn.csv o=./outdat/out32nfn.csv


