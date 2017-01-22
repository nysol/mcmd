#!/bin/bash

. ../env

#name_kg_mcmd mvstats

${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=sum  o=./outdat/out1.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=mean o=./outdat/out2.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=devsq  o=./outdat/out3.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=var o=./outdat/out4.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=uvar o=./outdat/out5.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=sd o=./outdat/out6.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=usd  o=./outdat/out7.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=cv o=./outdat/out8.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=min o=./outdat/out9.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=max  o=./outdat/out10.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=range o=./outdat/out11.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=skew  o=./outdat/out12.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=uskew o=./outdat/out13.csv s=id
${pfxc}mmvstats	     i=./indat/dat2s.csv  t=5   f=value2 c=kurt  o=./outdat/out14.csv s=id
${pfxc}mmvstats       i=./indat/dat2s.csv  t=5   f=value2 c=ukurt o=./outdat/out15.csv s=id

${pfxc}mmvstats -x      i=./indat/dat2s.csv  t=5   f=3 c=sum  o=./outdat/out1x.csv s=1
${pfxc}mmvstats -q      i=./indat/dat2s.csv  t=5   f=value2 c=sum  o=./outdat/out1q.csv s=id
${pfxc}mmvstats -nfn    i=./indat/dat2snfn.csv  t=5   f=3 c=sum  o=./outdat/out1nfn.csv s=1

${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=sum   skip=2 o=./outdat/out16.csv s=id 
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=mean  skip=2 o=./outdat/out17.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=devsq skip=2 o=./outdat/out18.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=var   skip=2 o=./outdat/out19.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=uvar  skip=2 o=./outdat/out20.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=sd    skip=2 o=./outdat/out21.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=usd   skip=2 o=./outdat/out22.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=cv    skip=2 o=./outdat/out23.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=min   skip=2 o=./outdat/out24.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=max   skip=2 o=./outdat/out25.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=range skip=2 o=./outdat/out26.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=skew  skip=2 o=./outdat/out27.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=uskew skip=2 o=./outdat/out28.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=kurt  skip=2 o=./outdat/out29.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2s.csv  t=4   f=value c=ukurt skip=2 o=./outdat/out30.csv s=id

${pfxc}mmvstats -x   k=0 i=./indat/dat2s.csv  t=4   f=2 c=sum   skip=2 o=./outdat/out16x.csv s=1 
${pfxc}mmvstats -q   k=key i=./indat/dat2s.csv  t=4 f=value c=sum   skip=2 o=./outdat/out16q.csv s=id 
${pfxc}mmvstats -nfn k=0 i=./indat/dat2snfn.csv  t=4   f=2 c=sum   skip=2 o=./outdat/out16nfn.csv s=1 



${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=sum  o=./outdat/out31.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=mean o=./outdat/out32.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=devsq  o=./outdat/out33.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=var o=./outdat/out34.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=uvar o=./outdat/out35.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=sd o=./outdat/out36.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=usd  o=./outdat/out37.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=cv o=./outdat/out38.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=min o=./outdat/out39.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=max  o=./outdat/out40.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=range o=./outdat/out41.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=skew  o=./outdat/out42.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=uskew o=./outdat/out43.csv s=id
${pfxc}mmvstats	     i=./indat/dat2.csv  t=5   f=value2 c=kurt  o=./outdat/out44.csv s=id
${pfxc}mmvstats       i=./indat/dat2.csv  t=5   f=value2 c=ukurt o=./outdat/out45.csv s=id

${pfxc}mmvstats -x     i=./indat/dat2.csv  t=5   f=3 c=sum  o=./outdat/out31x.csv s=1
${pfxc}mmvstats -q     i=./indat/dat2.csv  t=5   f=value2 c=sum  o=./outdat/out31q.csv s=id
${pfxc}mmvstats -nfn   i=./indat/dat2nfn.csv  t=5   f=3 c=sum  o=./outdat/out31nfn.csv s=1


${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=sum   skip=2 o=./outdat/out46.csv s=id 
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=mean  skip=2 o=./outdat/out47.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=devsq skip=2 o=./outdat/out48.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=var   skip=2 o=./outdat/out49.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=uvar  skip=2 o=./outdat/out50.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=sd    skip=2 o=./outdat/out51.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=usd   skip=2 o=./outdat/out52.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=cv    skip=2 o=./outdat/out53.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=min   skip=2 o=./outdat/out54.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=max   skip=2 o=./outdat/out55.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=range skip=2 o=./outdat/out56.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=skew  skip=2 o=./outdat/out57.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=uskew skip=2 o=./outdat/out58.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=kurt  skip=2 o=./outdat/out59.csv s=id
${pfxc}mmvstats k=key i=./indat/dat2.csv  t=4   f=value c=ukurt skip=2 o=./outdat/out60.csv s=id

${pfxc}mmvstats -x   k=0 i=./indat/dat2.csv  t=4   f=2 c=sum   skip=2 o=./outdat/out46x.csv s=1 
${pfxc}mmvstats -q   k=key i=./indat/dat2.csv  t=4   f=value c=sum   skip=2 o=./outdat/out46q.csv s=id 
${pfxc}mmvstats -nfn k=0 i=./indat/dat2nfn.csv  t=4   f=2 c=sum   skip=2 o=./outdat/out46nfn.csv s=1 


