#!/bin/bash

. ../env

#name_kg_mcmd mvsim

${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out0.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out1.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out2.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out3.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out4.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out5.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out6.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1s.csv    o=./outdat/out7.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out8.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out9.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out10.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out11.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out12.csv    f=x,y c=support s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out13.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out14.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out15.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out16.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out17.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out18.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2s.csv    o=./outdat/out19.csv    f=x,y c=convMin s=id


${pfxc}mmvsim -x      t=4 a=rls i=./indat/dat1s.csv   o=./outdat/out0x.csv    f=0,1 c=covar s=3
${pfxc}mmvsim -q      t=4 a=rls i=./indat/dat1s.csv   o=./outdat/out0q.csv    f=x,y c=covar
${pfxc}mmvsim -nfn    t=4 a=rls i=./indat/dat1snfn.csv o=./outdat/out0nfn.csv  f=0,1 c=covar s=3

# k=
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out20.csv    f=x,y c=covar s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out21.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out22.csv    f=x,y c=pearson s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out23.csv    f=x,y c=spearman s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out24.csv    f=x,y c=kendall s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out25.csv    f=x,y c=euclid s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out26.csv    f=x,y c=cosine s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3s.csv  skip=2  o=./outdat/out27.csv    f=x,y c=cityblock s=id


${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out28.csv    f=x,y c=hamming s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out29.csv    f=x,y c=chi s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out30.csv    f=x,y c=phi s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out31.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out32.csv    f=x,y c=support s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out33.csv    f=x,y c=lift s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out34.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out35.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out36.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out37.csv    f=x,y c=kappa s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out38.csv    f=x,y c=convMax s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out39.csv    f=x,y c=convMin s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out40.csv    f=x,y c=confMax s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4s.csv  skip=2  o=./outdat/out41.csv    f=x,y c=confMin s=id


${pfxc}mmvsim -x   k=0   t=4 a=rls i=./indat/dat3s.csv  skip=2     o=./outdat/out20x.csv    f=1,2 c=covar s=4
${pfxc}mmvsim -q   k=key t=4 a=rls i=./indat/dat3s.csv  skip=2     o=./outdat/out20q.csv    f=x,y c=covar s=4
${pfxc}mmvsim -nfn k=0   t=4 a=rls i=./indat/dat3snfn.csv  skip=2  o=./outdat/out20nfn.csv  f=1,2 c=covar s=4


# t＝3
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out42.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out43.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out44.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out45.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out46.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out47.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out48.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3s.csv   o=./outdat/out49.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out50.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out51.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out52.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out53.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out54.csv    f=x,y c=support s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out55.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out56.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out57.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out58.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out59.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out60.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out61.csv    f=x,y c=convMin s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out62.csv    f=x,y c=confMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4s.csv   o=./outdat/out63.csv    f=x,y c=confMin s=id

# NULLデータ
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out64.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out65.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out67.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out68.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out69.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out70.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out71.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv   o=./outdat/out72.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out73.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out74.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out75.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out76.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out77.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out78.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out79.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5s.csv -n   o=./outdat/out80.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim -x   t=3 a=rls i=./indat/dat5s.csv     o=./outdat/out64x.csv    f=1,2 c=covar s=4
${pfxc}mmvsim -q   t=3 a=rls i=./indat/dat5s.csv     o=./outdat/out64q.csv    f=x,y c=covar s=id
${pfxc}mmvsim -nfn t=3 a=rls i=./indat/dat5snfn.csv  o=./outdat/out64nfn.csv    f=1,2 c=covar s=4

${pfxc}mmvsim -x   -n t=3 a=rls i=./indat/dat5s.csv     o=./outdat/out73x.csv    f=1,2 c=covar s=4
${pfxc}mmvsim -q   -n t=3 a=rls i=./indat/dat5s.csv     o=./outdat/out73q.csv    f=x,y c=covar s=id
${pfxc}mmvsim -nfn -n t=3 a=rls i=./indat/dat5snfn.csv  o=./outdat/out73nfn.csv    f=1,2 c=covar s=4


${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out81.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out82.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out83.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out84.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out85.csv    f=x,y c=support s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out86.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out87.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out88.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out89.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out90.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out91.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out92.csv    f=x,y c=convMin s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out93.csv    f=x,y c=confMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv   o=./outdat/out94.csv    f=x,y c=confMin s=id


${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out95.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out96.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out97.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out98.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out99.csv    f=x,y c=support s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out100.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out101.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out102.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out103.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out104.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out105.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out106.csv    f=x,y c=convMin s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out107.csv    f=x,y c=confMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out108.csv    f=x,y c=confMin s=id



#ランダムデータ
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out200.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out201.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out202.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out203.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out204.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out205.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out206.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat1.csv    o=./outdat/out207.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out208.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out209.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out210.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out211.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out212.csv    f=x,y c=support s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out213.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out214.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out215.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out216.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out217.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out218.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=4 a=rls i=./indat/dat2.csv    o=./outdat/out219.csv    f=x,y c=convMin s=id

${pfxc}mmvsim -x   t=4 a=rls i=./indat/dat1.csv    o=./outdat/out200x.csv    f=0,1 c=covar s=3
${pfxc}mmvsim -q   t=4 a=rls i=./indat/dat1.csv    o=./outdat/out200q.csv    f=x,y c=covar s=id
${pfxc}mmvsim -nfn t=4 a=rls i=./indat/dat1nfn.csv o=./outdat/out200nfn.csv  f=0,1 c=covar s=3



# k=
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out220.csv    f=x,y c=covar s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out221.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out222.csv    f=x,y c=pearson s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out223.csv    f=x,y c=spearman s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out224.csv    f=x,y c=kendall s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out225.csv    f=x,y c=euclid s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out226.csv    f=x,y c=cosine s=id
${pfxc}mmvsim k=key t=4 a=rls i=./indat/dat3.csv  skip=2  o=./outdat/out227.csv    f=x,y c=cityblock s=id


${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out228.csv    f=x,y c=hamming s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out229.csv    f=x,y c=chi s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out230.csv    f=x,y c=phi s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out231.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out232.csv    f=x,y c=support s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out233.csv    f=x,y c=lift s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out234.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out235.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out236.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out237.csv    f=x,y c=kappa s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out238.csv    f=x,y c=convMax s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out239.csv    f=x,y c=convMin s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out240.csv    f=x,y c=confMax s=id
${pfxc}mmvsim k=key t=5 a=rls i=./indat/dat4.csv  skip=2  o=./outdat/out241.csv    f=x,y c=confMin s=id


${pfxc}mmvsim -x   k=0   t=4 a=rls i=./indat/dat3.csv  skip=2     o=./outdat/out220x.csv    f=1,2 c=covar s=4
${pfxc}mmvsim -q   k=key t=4 a=rls i=./indat/dat3.csv  skip=2     o=./outdat/out220q.csv    f=x,y c=covar s=4
${pfxc}mmvsim -nfn k=0   t=4 a=rls i=./indat/dat3nfn.csv  skip=2  o=./outdat/out220nfn.csv  f=1,2 c=covar s=4


# t＝3
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out242.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out243.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out244.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out245.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out246.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out247.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out248.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat3.csv   o=./outdat/out249.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out250.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out251.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out252.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out253.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out254.csv    f=x,y c=support s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out255.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out256.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out257.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out258.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out259.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out260.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out261.csv    f=x,y c=convMin s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out262.csv    f=x,y c=confMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat4.csv   o=./outdat/out263.csv    f=x,y c=confMin s=id

# NULLデータ
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out264.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out265.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out267.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out268.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out269.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out270.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out271.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv   o=./outdat/out272.csv    f=x,y c=cityblock s=id

${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out273.csv    f=x,y c=covar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out274.csv    f=x,y c=ucovar s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out275.csv    f=x,y c=pearson s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out276.csv    f=x,y c=spearman s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out277.csv    f=x,y c=kendall s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out278.csv    f=x,y c=euclid s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out279.csv    f=x,y c=cosine s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat5.csv -n   o=./outdat/out280.csv    f=x,y c=cityblock s=id


${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out281.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out282.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out283.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out284.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out285.csv    f=x,y c=support s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out286.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out287.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out288.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out289.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out290.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out291.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out292.csv    f=x,y c=convMin s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out293.csv    f=x,y c=confMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv   o=./outdat/out294.csv    f=x,y c=confMin s=id


${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out295.csv    f=x,y c=hamming s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out296.csv    f=x,y c=chi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out297.csv    f=x,y c=phi s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out298.csv    f=x,y c=jaccard s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out299.csv    f=x,y c=support s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out300.csv    f=x,y c=lift s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out301.csv    f=x,y c=oddsRatio s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out302.csv    f=x,y c=yuleQ s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out303.csv    f=x,y c=yuleY s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out304.csv    f=x,y c=kappa s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6.csv -n   o=./outdat/out305.csv    f=x,y c=convMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out306.csv    f=x,y c=convMin s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out307.csv    f=x,y c=confMax s=id
${pfxc}mmvsim t=3 a=rls i=./indat/dat6s.csv -n   o=./outdat/out308.csv    f=x,y c=confMin s=id


${pfxc}mmvsim -x   t=3 a=rls i=./indat/dat5.csv     o=./outdat/out264x.csv    f=1,2 c=covar s=4
${pfxc}mmvsim -q   t=3 a=rls i=./indat/dat5.csv     o=./outdat/out264q.csv    f=x,y c=covar s=id
${pfxc}mmvsim -nfn t=3 a=rls i=./indat/dat5nfn.csv  o=./outdat/out264nfn.csv    f=1,2 c=covar s=4

${pfxc}mmvsim -x   -n t=3 a=rls i=./indat/dat5.csv     o=./outdat/out273x.csv    f=1,2 c=covar s=4
${pfxc}mmvsim -q   -n t=3 a=rls i=./indat/dat5.csv     o=./outdat/out273q.csv    f=x,y c=covar s=id
${pfxc}mmvsim -nfn -n t=3 a=rls i=./indat/dat5nfn.csv  o=./outdat/out273nfn.csv    f=1,2 c=covar s=4


