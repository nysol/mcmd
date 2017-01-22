#!/bin/bash

. ../env

#name_kg_mcmd vcount

#nullデータ
${pfxc}mvcount      vf=items1:size1					i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mvcount -x   vf=0:size1							i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mvcount -nfn vf=0:size1							i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mvcount -nfno  vf=items1:size1			i=./indat/dat0.csv    o=./outdat/out0nfno.csv

${pfxc}mvcount      vf=items1:size1,items2:size2	i=./indat/dat0.csv    o=./outdat/out1.csv
${pfxc}mvcount -x   vf=0:size1,1:size2           	i=./indat/dat0.csv    o=./outdat/out1x.csv
${pfxc}mvcount -nfn vf=0:size1,1:size2	          i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv


#通常データ
${pfxc}mvcount      vf=items1:size1					i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mvcount -x   vf=0:size1							i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mvcount -nfn vf=0:size1							i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}mvcount -nfno vf=items1:size1					i=./indat/dat1.csv    o=./outdat/out2nfno.csv

${pfxc}mvcount      vf=items1:size1,items2:size2	i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mvcount -x   vf=0:size1,1:size2	          i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mvcount -nfn vf=0:size1,1:size2	          i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv


#DQを含むデータ 
${pfxc}mvcount      vf=items1:size1					i=./indat/dat2.csv    o=./outdat/out4.csv
${pfxc}mvcount -x   vf=0:size1							i=./indat/dat2.csv    o=./outdat/out4x.csv
${pfxc}mvcount -nfn vf=0:size1							i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv

${pfxc}mvcount      vf=items1:size1,items2:size2	i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mvcount -x   vf=0:size1,1:size2	          i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mvcount -nfn vf=0:size1,1:size2	          i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv


#ソートデータ
${pfxc}mvcount      vf=items1:size1					i=./indat/dat1s.csv    o=./outdat/out6.csv
${pfxc}mvcount -x   vf=0:size1							i=./indat/dat1s.csv    o=./outdat/out6x.csv
${pfxc}mvcount -nfn vf=0:size1							i=./indat/dat1snfn.csv o=./outdat/out6nfn.csv
${pfxc}mvcount -nfno vf=items1:size1					i=./indat/dat1s.csv    o=./outdat/out6nfno.csv

${pfxc}mvcount      vf=items1:size1,items2:size2	i=./indat/dat1s.csv    o=./outdat/out7.csv
${pfxc}mvcount -x   vf=0:size1,1:size2	          i=./indat/dat1s.csv    o=./outdat/out7x.csv
${pfxc}mvcount -nfn vf=0:size1,1:size2	          i=./indat/dat1snfn.csv o=./outdat/out7nfn.csv
