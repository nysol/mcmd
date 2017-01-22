#!/bin/bash

. ../env

#name_kg_mcmd vcat

#nullデータ
${pfxc}mvcat      vf=items* a=items				i=./indat/dat0.csv    o=./outdat/out1.csv
${pfxc}mvcat -x   vf=0-3    a=items				i=./indat/dat0.csv    o=./outdat/out1x.csv
${pfxc}mvcat -nfn vf=0-3    a=items				i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvcat      vf=items*	a=new   			i=./indat/dat0.csv    o=./outdat/out2.csv
${pfxc}mvcat -x   vf=0-3		a=new					i=./indat/dat0.csv    o=./outdat/out2x.csv
${pfxc}mvcat -nfn vf=0-3		a=new					i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

${pfxc}mvcat      vf=items* a=items -A		i=./indat/dat0.csv    o=./outdat/out3.csv
${pfxc}mvcat -x   vf=0-3    a=items -A		i=./indat/dat0.csv    o=./outdat/out3x.csv
${pfxc}mvcat -nfn vf=0-3    a=items -A		i=./indat/dat0nfn.csv o=./outdat/out3nfn.csv

${pfxc}mvcat      vf=items* a=new -A						i=./indat/dat0.csv    o=./outdat/out4.csv
${pfxc}mvcat -x   vf=0-3    a=new -A						i=./indat/dat0.csv    o=./outdat/out4x.csv
${pfxc}mvcat -nfn vf=0-3    a=new -A						i=./indat/dat0nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items	i=./indat/dat0.csv    o=./outdat/out5.csv
${pfxc}mvcat -x   vf=1,2           a=items	i=./indat/dat0.csv    o=./outdat/out5x.csv
${pfxc}mvcat -nfn vf=1,2           a=items	i=./indat/dat0nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvcat      vf=items2,items3	a=new	i=./indat/dat0.csv    o=./outdat/out6.csv
${pfxc}mvcat -x   vf=1,2						a=new	i=./indat/dat0.csv    o=./outdat/out6x.csv
${pfxc}mvcat -nfn vf=1,2						a=new	i=./indat/dat0nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items -A	i=./indat/dat0.csv    o=./outdat/out7.csv
${pfxc}mvcat -x   vf=1,2           a=items -A	i=./indat/dat0.csv    o=./outdat/out7x.csv
${pfxc}mvcat -nfn vf=1,2           a=items -A	i=./indat/dat0nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvcat      vf=items2,items3 -A a=new	i=./indat/dat0.csv    o=./outdat/out8.csv
${pfxc}mvcat -x   vf=1,2           -A a=new	i=./indat/dat0.csv    o=./outdat/out8x.csv
${pfxc}mvcat -nfn vf=1,2           -A a=new	i=./indat/dat0nfn.csv o=./outdat/out8nfn.csv

#通常データ
${pfxc}mvcat      vf=items* a=items				i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}mvcat -x   vf=0-3    a=items				i=./indat/dat1.csv    o=./outdat/out9x.csv
${pfxc}mvcat -nfn vf=0-3    a=items				i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv
${pfxc}mvcat -nfno vf=items* a=items				i=./indat/dat1.csv    o=./outdat/out9nfno.csv

${pfxc}mvcat      vf=items*			a=new		i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mvcat -x   vf=0-3  			a=new 	i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}mvcat -nfn vf=0-3  			a=new		i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}mvcat      vf=items* a=items -A		i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}mvcat -x   vf=0-3    a=items -A		i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}mvcat -nfn vf=0-3    a=items -A		i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

${pfxc}mvcat      vf=items* -A	a=new		i=./indat/dat1.csv    o=./outdat/out12.csv
${pfxc}mvcat -x   vf=0-3    -A	a=new		i=./indat/dat1.csv    o=./outdat/out12x.csv
${pfxc}mvcat -nfn vf=0-3    -A	a=new		i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items			i=./indat/dat1.csv    o=./outdat/out13.csv
${pfxc}mvcat -x   vf=1,2           a=items			i=./indat/dat1.csv    o=./outdat/out13x.csv
${pfxc}mvcat -nfn vf=1,2           a=items			i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv

${pfxc}mvcat      vf=items2,items3	a=new	i=./indat/dat1.csv    o=./outdat/out14.csv
${pfxc}mvcat -x   vf=1,2						a=new	i=./indat/dat1.csv    o=./outdat/out14x.csv
${pfxc}mvcat -nfn vf=1,2						a=new	i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items -A	i=./indat/dat1.csv    o=./outdat/out15.csv
${pfxc}mvcat -x   vf=1,2           a=items -A	i=./indat/dat1.csv    o=./outdat/out15x.csv
${pfxc}mvcat -nfn vf=1,2           a=items -A	i=./indat/dat1nfn.csv o=./outdat/out15nfn.csv

${pfxc}mvcat      vf=items2,items3 -A a=new	i=./indat/dat1.csv    o=./outdat/out16.csv
${pfxc}mvcat -x   vf=1,2           -A a=new	i=./indat/dat1.csv    o=./outdat/out16x.csv
${pfxc}mvcat -nfn vf=1,2           -A a=new	i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv

#delimオプション指定
${pfxc}mvcat      vf=items* a=items	delim=/	i=./indat/dat1.csv    o=./outdat/out25.csv
${pfxc}mvcat      vf=items* a=items	delim=,	i=./indat/dat1.csv    o=./outdat/out26.csv
${pfxc}mvcat      vf=items* a=items	delim=/	i=./indat/dat1.csv    o=./outdat/out27.csv

#nullを部分的に含むデータ 
${pfxc}mvcat      vf=items* a=items				i=./indat/dat2.csv    o=./outdat/out17.csv
${pfxc}mvcat -x   vf=0-3    a=items				i=./indat/dat2.csv    o=./outdat/out17x.csv
${pfxc}mvcat -nfn vf=0-3    a=items				i=./indat/dat2nfn.csv o=./outdat/out17nfn.csv

${pfxc}mvcat      vf=items*	a=new							i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}mvcat -x   vf=0-3		a=new							i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}mvcat -nfn vf=0-3		a=new							i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv

${pfxc}mvcat      vf=items* a=items -A		i=./indat/dat2.csv    o=./outdat/out19.csv
${pfxc}mvcat -x   vf=0-3    a=items -A		i=./indat/dat2.csv    o=./outdat/out19x.csv
${pfxc}mvcat -nfn vf=0-3    a=items -A		i=./indat/dat2nfn.csv o=./outdat/out19nfn.csv

${pfxc}mvcat      vf=items* -A		a=new	i=./indat/dat2.csv    o=./outdat/out20.csv
${pfxc}mvcat -x   vf=0-3    -A		a=new	i=./indat/dat2.csv    o=./outdat/out20x.csv
${pfxc}mvcat -nfn vf=0-3    -A		a=new	i=./indat/dat2nfn.csv o=./outdat/out20nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items	i=./indat/dat2.csv    o=./outdat/out21.csv
${pfxc}mvcat -x   vf=1,2           a=items	i=./indat/dat2.csv    o=./outdat/out21x.csv
${pfxc}mvcat -nfn vf=1,2           a=items	i=./indat/dat2nfn.csv o=./outdat/out21nfn.csv

${pfxc}mvcat      vf=items2,items3	a=new	i=./indat/dat2.csv    o=./outdat/out22.csv
${pfxc}mvcat -x   vf=1,2						a=new	i=./indat/dat2.csv    o=./outdat/out22x.csv
${pfxc}mvcat -nfn vf=1,2						a=new	i=./indat/dat2nfn.csv o=./outdat/out22nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items -A	i=./indat/dat2.csv    o=./outdat/out23.csv
${pfxc}mvcat -x   vf=1,2           a=items -A	i=./indat/dat2.csv    o=./outdat/out23x.csv
${pfxc}mvcat -nfn vf=1,2           a=items -A	i=./indat/dat2nfn.csv o=./outdat/out23nfn.csv

${pfxc}mvcat      vf=items2,items3 -A		a=new			i=./indat/dat2.csv    o=./outdat/out24.csv
${pfxc}mvcat -x   vf=1,2           -A		a=new			i=./indat/dat2.csv    o=./outdat/out24x.csv
${pfxc}mvcat -nfn vf=1,2           -A		a=new			i=./indat/dat2nfn.csv o=./outdat/out24nfn.csv






#ソートデータ
${pfxc}mvcat      vf=items* a=items				i=./indat/dat1s.csv    o=./outdat/out30.csv
${pfxc}mvcat -x   vf=0-3    a=items				i=./indat/dat1s.csv    o=./outdat/out30x.csv
${pfxc}mvcat -nfn vf=0-3    a=items				i=./indat/dat1snfn.csv o=./outdat/out30nfn.csv
${pfxc}mvcat -nfno vf=items* a=items				i=./indat/dat1s.csv    o=./outdat/out30nfno.csv

${pfxc}mvcat      vf=items* -A	a=new		i=./indat/dat1s.csv    o=./outdat/out31.csv
${pfxc}mvcat -x   vf=0-3    -A	a=new		i=./indat/dat1s.csv    o=./outdat/out31x.csv
${pfxc}mvcat -nfn vf=0-3    -A	a=new		i=./indat/dat1snfn.csv o=./outdat/out31nfn.csv

${pfxc}mvcat      vf=items2,items3 a=items			i=./indat/dat1s.csv    o=./outdat/out32.csv
${pfxc}mvcat -x   vf=1,2           a=items			i=./indat/dat1s.csv    o=./outdat/out32x.csv
${pfxc}mvcat -nfn vf=1,2           a=items			i=./indat/dat1snfn.csv o=./outdat/out32nfn.csv

${pfxc}mvcat      vf=items2,items3 -A a=new	i=./indat/dat1s.csv    o=./outdat/out33.csv
${pfxc}mvcat -x   vf=1,2           -A a=new	i=./indat/dat1s.csv    o=./outdat/out33x.csv
${pfxc}mvcat -nfn vf=1,2           -A a=new	i=./indat/dat1snfn.csv o=./outdat/out33nfn.csv

