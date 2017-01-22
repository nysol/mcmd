#!/bin/bash

. ../env

#name_kg_mcmd summary

# nullデータ
${pfxc}msummary      i=./indat/dat0s.csv    o=./outdat/out01.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   i=./indat/dat0s.csv    o=./outdat/out01x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn i=./indat/dat0snfn.csv o=./outdat/out01nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

#基本
${pfxc}msummary      i=./indat/dat1s.csv    o=./outdat/out02.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   i=./indat/dat1s.csv    o=./outdat/out02x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn i=./indat/dat1snfn.csv o=./outdat/out02nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfno i=./indat/dat1s.csv    o=./outdat/out02nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -q     i=./indat/dat1s.csv    o=./outdat/out02q.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -q -x   i=./indat/dat1s.csv    o=./outdat/out02qx.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

#項目名変更
${pfxc}msummary      i=./indat/dat1s.csv    o=./outdat/out03.csv    a=変数 f=数量,金額 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -x   i=./indat/dat1s.csv    o=./outdat/out03x.csv   a=変数 f=1,2       c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -nfn i=./indat/dat1snfn.csv o=./outdat/out03nfn.csv        f=1,2       c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -nfno i=./indat/dat1s.csv    o=./outdat/out03nfno.csv    a=変数 f=数量,金額 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度

# nullを含むデータ
${pfxc}msummary      i=./indat/dat2s.csv    o=./outdat/out04.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   i=./indat/dat2s.csv    o=./outdat/out04x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn i=./indat/dat2snfn.csv o=./outdat/out04nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

# k=指定あり
${pfxc}msummary      k=顧客 i=./indat/dat0s.csv    o=./outdat/out05.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   k=0    i=./indat/dat0s.csv    o=./outdat/out05x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn k=0    i=./indat/dat0snfn.csv o=./outdat/out05nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

${pfxc}msummary      k=顧客 i=./indat/dat1s.csv    o=./outdat/out06.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   k=0    i=./indat/dat1s.csv    o=./outdat/out06x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn k=0    i=./indat/dat1snfn.csv o=./outdat/out06nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfno k=顧客 i=./indat/dat1s.csv    o=./outdat/out06nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

${pfxc}msummary      k=顧客 i=./indat/dat1s.csv    o=./outdat/out07.csv    a=変数 f=数量,金額 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -x   k=0    i=./indat/dat1s.csv    o=./outdat/out07x.csv   a=変数 f=1,2 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -nfn k=0    i=./indat/dat1snfn.csv o=./outdat/out07nfn.csv        f=1,2 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -nfno k=顧客 i=./indat/dat1s.csv    o=./outdat/out07nfno.csv    a=変数 f=数量,金額 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度

${pfxc}msummary      k=顧客 i=./indat/dat2s.csv    o=./outdat/out08.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   k=0    i=./indat/dat2s.csv    o=./outdat/out08x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn k=0    i=./indat/dat2snfn.csv o=./outdat/out08nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfno k=顧客 i=./indat/dat2s.csv    o=./outdat/out08nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

# f=の項目名を変更
${pfxc}msummary      k=顧客 i=./indat/dat1s.csv    o=./outdat/out09.csv    f=数量:xxx,金額:価格 c=count,sum

# precision=5
${pfxc}msummary      k=顧客 i=./indat/dat2s.csv    o=./outdat/out10.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5
${pfxc}msummary -x   k=0    i=./indat/dat2s.csv    o=./outdat/out10x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5
${pfxc}msummary -nfn k=0    i=./indat/dat2snfn.csv o=./outdat/out10nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5
${pfxc}msummary -nfno k=顧客 i=./indat/dat2s.csv    o=./outdat/out10nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5





#ランダムデータ

# k=指定あり
${pfxc}msummary      k=顧客 i=./indat/dat0.csv    o=./outdat/out25.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   k=0    i=./indat/dat0.csv    o=./outdat/out25x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn k=0    i=./indat/dat0nfn.csv o=./outdat/out25nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

${pfxc}msummary      k=顧客 i=./indat/dat1.csv    o=./outdat/out26.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   k=0    i=./indat/dat1.csv    o=./outdat/out26x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn k=0    i=./indat/dat1nfn.csv o=./outdat/out26nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfno k=顧客 i=./indat/dat1.csv    o=./outdat/out26nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -q     k=顧客 i=./indat/dat1.csv    o=./outdat/out26q.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -q -x   k=0    i=./indat/dat1.csv    o=./outdat/out26qx.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

${pfxc}msummary      k=顧客 i=./indat/dat1.csv    o=./outdat/out27.csv    a=変数 f=数量,金額 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -x   k=0    i=./indat/dat1.csv    o=./outdat/out27x.csv   a=変数 f=1,2 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -nfn k=0    i=./indat/dat1nfn.csv o=./outdat/out27nfn.csv        f=1,2 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度
${pfxc}msummary -nfno k=顧客 i=./indat/dat1.csv    o=./outdat/out27nfno.csv    a=変数 f=数量,金額 c=count:件数,ucount:ユニーク件数,sum:合計,mean:算術平均,devsq:偏差平方和,var:分散,uvar:不偏分散,sd:標準偏差,usd:不偏標準偏差,cv:変動係数,mode:最頻値,min:最小値,max:最大値,range:範囲,median:中央値,qtile1:第1四分位点,qtile3:第3四分位点,qrange:四分位範囲,skew:歪度,uskew:不偏歪度,kurt:尖度,ukurt:不偏尖度

${pfxc}msummary      k=顧客 i=./indat/dat2.csv    o=./outdat/out28.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -x   k=0    i=./indat/dat2.csv    o=./outdat/out28x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfn k=0    i=./indat/dat2nfn.csv o=./outdat/out28nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt
${pfxc}msummary -nfno k=顧客 i=./indat/dat2.csv    o=./outdat/out28nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt

# f=の項目名を変更
${pfxc}msummary      k=顧客 i=./indat/dat1.csv    o=./outdat/out29.csv    f=数量:xxx,金額:価格 c=count,sum

# precision=5
${pfxc}msummary      k=顧客 i=./indat/dat2.csv    o=./outdat/out30.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5
${pfxc}msummary -x   k=0    i=./indat/dat2.csv    o=./outdat/out30x.csv   f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5
${pfxc}msummary -nfn k=0    i=./indat/dat2nfn.csv o=./outdat/out30nfn.csv f=1,2       c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5
${pfxc}msummary -nfno k=顧客 i=./indat/dat2.csv    o=./outdat/out30nfno.csv    f=数量,金額 c=count,ucount,sum,mean,devsq,var,uvar,sd,usd,cv,mode,min,max,range,median,qtile1,qtile3,qrange,skew,uskew,kurt,ukurt precision=5

