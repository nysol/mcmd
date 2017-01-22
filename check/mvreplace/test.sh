#!/bin/bash

. ../env

#name_kg_mcmd vreplace

#nullデータ
${pfxc}mvreplace      vf=items1 K=item f=taxo			m=./indat/ref0.csv i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1        m=./indat/ref0.csv i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   			m=./indat/ref0nfn.csv i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv


${pfxc}mvreplace      vf=items1 K=item f=taxo 			m=./indat/ref0.csv i=./indat/dat1.csv o=./outdat/out1.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1    			m=./indat/ref0.csv i=./indat/dat1.csv o=./outdat/out1x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1    			m=./indat/ref0nfn.csv i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mvreplace      vf=items1 K=item f=taxo		 	m=./indat/ref1.csv i=./indat/dat0.csv o=./outdat/out2.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   		 	m=./indat/ref1.csv i=./indat/dat0.csv o=./outdat/out2x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   		 	m=./indat/ref1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

#通常データ
${pfxc}mvreplace      vf=items1 K=item f=taxo			m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out3.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   			m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out3x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   			m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

${pfxc}mvreplace      vf=items1 K=item f=taxo	n=*	m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out4.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   	n=*	m=./indat/ref1.csv i=./indat/dat1.csv o=./outdat/out4x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   	n=*	m=./indat/ref1nfn.csv i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvreplace      vf=items1:items_ans K=item f=taxo			m=./indat/ref1.csv i=./indat/dat4.csv o=./outdat/out11.csv
${pfxc}mvreplace -x   vf=0:items_ans      K=0    f=1   			m=./indat/ref1.csv i=./indat/dat4.csv o=./outdat/out11x.csv
${pfxc}mvreplace -nfn vf=0:items_ans      K=0    f=1   			m=./indat/ref1nfn.csv i=./indat/dat4nfn.csv o=./outdat/out11nfn.csv

${pfxc}mvreplace      vf=items1:items_ans,items2:items_ans2 K=item f=taxo			m=./indat/ref1.csv i=./indat/dat5.csv o=./outdat/out12.csv
${pfxc}mvreplace -x   vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1.csv i=./indat/dat5.csv o=./outdat/out12x.csv
${pfxc}mvreplace -nfn vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1nfn.csv i=./indat/dat5nfn.csv o=./outdat/out12nfn.csv


${pfxc}mvreplace      -A vf=items1:items_ans K=item f=taxo			m=./indat/ref1.csv i=./indat/dat4.csv o=./outdat/out13.csv
${pfxc}mvreplace -x   -A vf=0:items_ans      K=0    f=1   			m=./indat/ref1.csv i=./indat/dat4.csv o=./outdat/out13x.csv
${pfxc}mvreplace -nfn -A vf=0:items_ans      K=0    f=1   			m=./indat/ref1nfn.csv i=./indat/dat4nfn.csv o=./outdat/out13nfn.csv

${pfxc}mvreplace      -A vf=items1:items_ans,items2:items_ans2 K=item f=taxo			m=./indat/ref1.csv i=./indat/dat5.csv o=./outdat/out14.csv
${pfxc}mvreplace -x   -A vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1.csv i=./indat/dat5.csv o=./outdat/out14x.csv
${pfxc}mvreplace -nfn -A vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1nfn.csv i=./indat/dat5nfn.csv o=./outdat/out14nfn.csv


#DQ,NULLを含むデータ 
${pfxc}mvreplace      vf=items1 K=item f=taxo							m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out5.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   						  m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out5x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   							m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv

${pfxc}mvreplace      vf=items1 K=item f=taxo	n=*					m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out6.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   	n=*					m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out6x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   	n=*					m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

${pfxc}mvreplace      vf=items1,items2 K=item f=taxo				m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out7.csv
${pfxc}mvreplace -x   vf=0,1           K=0    f=1    				m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out7x.csv
${pfxc}mvreplace -nfn vf=0,1           K=0    f=1    				m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv

${pfxc}mvreplace      vf=items1,items2 K=item f=taxo n=*		m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out8.csv
${pfxc}mvreplace -x   vf=0,1           K=0    f=1    n=*		m=./indat/ref2.csv i=./indat/dat2.csv o=./outdat/out8x.csv
${pfxc}mvreplace -nfn vf=0,1           K=0    f=1    n=*		m=./indat/ref2nfn.csv i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv

#delimオプション指定
${pfxc}mvreplace      vf=items1 K=item f=taxo delim=:	m=./indat/ref1.csv i=./indat/dat3.csv o=./outdat/out9.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1    delim=:	m=./indat/ref1.csv i=./indat/dat3.csv o=./outdat/out9x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1    delim=:	m=./indat/ref1nfn.csv i=./indat/dat3nfn.csv o=./outdat/out9nfn.csv



#ソート
#通常データ
${pfxc}mvreplace      vf=items1 K=item f=taxo			m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out23.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   			m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out23x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   			m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out23nfn.csv

${pfxc}mvreplace      vf=items1 K=item f=taxo	n=*	m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out24.csv
${pfxc}mvreplace -x   vf=0      K=0    f=1   	n=*	m=./indat/ref1s.csv i=./indat/dat1s.csv o=./outdat/out24x.csv
${pfxc}mvreplace -nfn vf=0      K=0    f=1   	n=*	m=./indat/ref1snfn.csv i=./indat/dat1snfn.csv o=./outdat/out24nfn.csv

${pfxc}mvreplace      vf=items1:items_ans K=item f=taxo			m=./indat/ref1s.csv i=./indat/dat4s.csv o=./outdat/out31.csv
${pfxc}mvreplace -x   vf=0:items_ans      K=0    f=1   			m=./indat/ref1s.csv i=./indat/dat4s.csv o=./outdat/out31x.csv
${pfxc}mvreplace -nfn vf=0:items_ans      K=0    f=1   			m=./indat/ref1snfn.csv i=./indat/dat4snfn.csv o=./outdat/out31nfn.csv

${pfxc}mvreplace      vf=items1:items_ans,items2:items_ans2 K=item f=taxo			m=./indat/ref1s.csv i=./indat/dat5s.csv o=./outdat/out32.csv
${pfxc}mvreplace -x   vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1s.csv i=./indat/dat5s.csv o=./outdat/out32x.csv
${pfxc}mvreplace -nfn vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1snfn.csv i=./indat/dat5snfn.csv o=./outdat/out32nfn.csv


${pfxc}mvreplace      -A vf=items1:items_ans K=item f=taxo			m=./indat/ref1s.csv i=./indat/dat4s.csv o=./outdat/out33.csv
${pfxc}mvreplace -x   -A vf=0:items_ans      K=0    f=1   			m=./indat/ref1s.csv i=./indat/dat4s.csv o=./outdat/out33x.csv
${pfxc}mvreplace -nfn -A vf=0:items_ans      K=0    f=1   			m=./indat/ref1snfn.csv i=./indat/dat4snfn.csv o=./outdat/out33snfn.csv

${pfxc}mvreplace      -A vf=items1:items_ans,items2:items_ans2 K=item f=taxo			m=./indat/ref1s.csv i=./indat/dat5s.csv o=./outdat/out34.csv
${pfxc}mvreplace -x   -A vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1s.csv i=./indat/dat5s.csv o=./outdat/out34x.csv
${pfxc}mvreplace -nfn -A vf=0:items_ans,1:items_ans2           K=0    f=1   			m=./indat/ref1snfn.csv i=./indat/dat5snfn.csv o=./outdat/out34nfn.csv
