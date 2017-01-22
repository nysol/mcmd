#!/bin/bash

. ../env

#name_kg_mcmd mvavg
#NULL
${pfxc}mmvavg       f=v1,v2 s=id t=2 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mmvavg -x    f=1,2   s=0 t=2 i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mmvavg -nfn  f=1,2   s=0 t=2 i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mmvavg -nfno f=v1,v2 s=id t=2 i=./indat/dat0s.csv    o=./outdat/out0nfno.csv

#NULL含むデータ
${pfxc}mmvavg        f=v1,v2 s=id  t=2 i=./indat/dat2s.csv    o=./outdat/out11.csv
${pfxc}mmvavg        f=v1,v2 s=id t=3 i=./indat/dat3s.csv    o=./outdat/out13.csv
${pfxc}mmvavg  -exp  f=v1,v2 s=id t=3 i=./indat/dat3s.csv    o=./outdat/out14.csv

#通常
${pfxc}mmvavg      f=v1,v2 s=id t=2 i=./indat/dat1s.csv    o=./outdat/out01.csv
${pfxc}mmvavg -x   f=2,3   s=0 t=2 i=./indat/dat1s.csv    o=./outdat/out01x.csv
${pfxc}mmvavg -nfn f=2,3   s=0 t=2 i=./indat/dat1snfn.csv o=./outdat/out01nfn.csv
${pfxc}mmvavg -nfno f=v1,v2 s=id t=2 i=./indat/dat1s.csv   o=./outdat/out01nfno.csv
${pfxc}mmvavg -q     f=v1,v2 s=id t=2 i=./indat/dat1s.csv    o=./outdat/out01q.csv
${pfxc}mmvavg -q -nfn f=2,3   s=0 t=2 i=./indat/dat1snfn.csv o=./outdat/out01qnfn.csv

${pfxc}mmvavg      f=v1,v2 s=id t=2 -w   i=./indat/dat1s.csv    o=./outdat/out02.csv

${pfxc}mmvavg      f=v1,v2 s=id t=2 -exp i=./indat/dat1s.csv    o=./outdat/out03.csv

${pfxc}mmvavg         k=k f=v1,v2 s=id t=2 i=./indat/dat1s.csv     o=./outdat/out04.csv
${pfxc}mmvavg -x      k=1 f=2,3 s=0 t=2    i=./indat/dat1s.csv     o=./outdat/out04x.csv
${pfxc}mmvavg -nfn    k=1 f=2,3 s=0 t=2    i=./indat/dat1snfn.csv  o=./outdat/out04nfn.csv
${pfxc}mmvavg -q      k=k f=v1,v2 s=id t=2 i=./indat/dat1s.csv     o=./outdat/out04q.csv
${pfxc}mmvavg -q -nfn k=1 f=2,3 s=0 t=2    i=./indat/dat1snfn.csv  o=./outdat/out04qnfn.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 skip=0 i=./indat/dat1s.csv    o=./outdat/out05.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -w i=./indat/dat1s.csv    o=./outdat/out06.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -w skip=0 i=./indat/dat1s.csv    o=./outdat/out07.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -exp i=./indat/dat1s.csv    o=./outdat/out08.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -exp skip=1 i=./indat/dat1s.csv    o=./outdat/out09.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -exp alpha=5 i=./indat/dat1s.csv    o=./outdat/out10.csv

#-wオプション指定
${pfxc}mmvavg -w  f=v1,v2 s=id t=2 i=./indat/dat2s.csv    o=./outdat/out12.csv



# ランダムデータ
${pfxc}mmvavg         k=k f=v1,v2 s=id t=2 i=./indat/dat1.csv    o=./outdat/out15.csv
${pfxc}mmvavg -x      k=1 f=2,3 s=0 t=2 i=./indat/dat1.csv    o=./outdat/out15x.csv
${pfxc}mmvavg -nfn    k=1 f=2,3 s=0 t=2    i=./indat/dat1nfn.csv  o=./outdat/out15nfn.csv
${pfxc}mmvavg -q      k=k f=v1,v2 s=id t=2 i=./indat/dat1.csv     o=./outdat/out15q.csv
${pfxc}mmvavg -q -nfn k=1 f=2,3 s=0 t=2    i=./indat/dat1nfn.csv  o=./outdat/out15qnfn.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 skip=0 i=./indat/dat1.csv    o=./outdat/out16.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -w i=./indat/dat1.csv    o=./outdat/out17.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -w skip=0 i=./indat/dat1.csv    o=./outdat/out18.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -exp i=./indat/dat1.csv    o=./outdat/out19.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -exp skip=1 i=./indat/dat1.csv    o=./outdat/out20.csv

${pfxc}mmvavg      k=k f=v1,v2 s=id t=2 -exp alpha=5 i=./indat/dat1.csv    o=./outdat/out21.csv



