#修正日は 20120308
#修正者は 樋口　寛視
#修正内容は 項目番号指定パラーメータをマイナス１する。（以前は1からの指定だったが、０からに変更になったため。）
#!/bin/bash

. ../env

#name_kg_mcmd sim

${pfxc}msim      i=./indat/dat1.csv    o=./outdat/out01.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   i=./indat/dat1.csv    o=./outdat/out01x.csv   f=0,1,2 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn i=./indat/dat1nfn.csv o=./outdat/out01nfn.csv f=0,1,2 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfno i=./indat/dat1.csv    o=./outdat/out01nfno.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

#以下４行マニュアルの実行例
${pfxc}msim      i=./indat/dat1.csv    o=./outdat/out02.csv    f=x,y,z c=pearson,cosine -d
${pfxc}msim -x   i=./indat/dat1.csv    o=./outdat/out02x.csv   f=0,1,2 c=pearson,cosine -d
${pfxc}msim -nfn i=./indat/dat1nfn.csv o=./outdat/out02nfn.csv f=0,1,2 c=pearson,cosine -d

${pfxc}msim      i=./indat/dat2s.csv    o=./outdat/out03.csv    f=x,y,z c=pearson,cosine k=key
${pfxc}msim -x   i=./indat/dat2s.csv    o=./outdat/out03x.csv   f=1,2,3 c=pearson,cosine k=0
${pfxc}msim -nfn i=./indat/dat2snfn.csv o=./outdat/out03nfn.csv f=1,2,3 c=pearson,cosine k=0

${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out04.csv    f=x,y,z c=hamming,phi
${pfxc}msim -x   i=./indat/dat4.csv    o=./outdat/out04x.csv   f=0,1,2 c=hamming,phi
${pfxc}msim -nfn i=./indat/dat4nfn.csv o=./outdat/out04nfn.csv f=0,1,2 c=hamming,phi

${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out05.csv    f=x,y,z c=hamming:ハミング距離,phi:ファイ係数 a=変数1,変数2
${pfxc}msim -x   i=./indat/dat4.csv    o=./outdat/out05x.csv   f=0,1,2 c=hamming:ハミング距離,phi:ファイ係数 a=変数1,変数2
${pfxc}msim -nfn i=./indat/dat4nfn.csv o=./outdat/out05nfn.csv f=0,1,2 c=hamming:ハミング距離,phi:ファイ係数

#01変数
${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out06.csv    f=x,y,z c=hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   i=./indat/dat4.csv    o=./outdat/out06x.csv   f=0,1,2 c=hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn i=./indat/dat4nfn.csv o=./outdat/out06nfn.csv f=0,1,2 c=hamming,chi,phi,jaccard,support,lift

${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out12.csv    f=x,y,z c=oddsRatio,yuleQ,yuleY,kappa,convMax,convMin
${pfxc}msim      i=./indat/dat5s.csv    o=./outdat/out14.csv    f=x,y,z c=oddsRatio,yuleQ,yuleY,kappa,convMax,convMin
${pfxc}msim      i=./indat/dat3s.csv    o=./outdat/out15.csv    f=x,y,z c=oddsRatio,yuleQ,yuleY,kappa,convMax,convMin

#precision=3
${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out13.csv    f=x,y,z c=oddsRatio,yuleQ,yuleY,kappa,convMax,convMin precision=3

#bufcount=3
${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out16.csv    f=x,y,z c=oddsRatio,yuleQ,yuleY,kappa,convMax,convMin bufcount=3
${pfxc}msim      i=./indat/dat4.csv    o=./outdat/out17.csv    f=x,y,z c=oddsRatio,yuleQ,yuleY,kappa,convMax,convMin bufcount=-3

#01変数 null値
${pfxc}msim      k=key i=./indat/dat5s.csv    o=./outdat/out07.csv    f=x,y,z c=hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat5s.csv    o=./outdat/out07x.csv   f=1,2,3 c=hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat5snfn.csv o=./outdat/out07nfn.csv f=1,2,3 c=hamming,chi,phi,jaccard,support,lift

# 数値,k=
${pfxc}msim      k=key i=./indat/dat2s.csv    o=./outdat/out08.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat2s.csv    o=./outdat/out08x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat2snfn.csv o=./outdat/out08nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

# 数値,k=,-d
${pfxc}msim      -d k=key i=./indat/dat2s.csv    o=./outdat/out09.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   -d k=0   i=./indat/dat2s.csv    o=./outdat/out09x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn -d k=0   i=./indat/dat2snfn.csv o=./outdat/out09nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

#数値 nullデータ
${pfxc}msim      k=key i=./indat/dat3s.csv    o=./outdat/out10.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat3s.csv    o=./outdat/out10x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat3snfn.csv o=./outdat/out10nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

#nullデータ
${pfxc}msim      k=key i=./indat/dat0s.csv    o=./outdat/out11.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat0s.csv    o=./outdat/out11x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat0snfn.csv o=./outdat/out11nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift



#ランダムデータ
${pfxc}msim      i=./indat/dat2.csv    o=./outdat/out23.csv    f=x,y,z c=pearson,cosine k=key
${pfxc}msim -x   i=./indat/dat2.csv    o=./outdat/out23x.csv   f=1,2,3 c=pearson,cosine k=0
${pfxc}msim -nfn i=./indat/dat2nfn.csv o=./outdat/out23nfn.csv f=1,2,3 c=pearson,cosine k=0


#01変数 null値
${pfxc}msim      k=key i=./indat/dat5.csv    o=./outdat/out27.csv    f=x,y,z c=hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat5.csv    o=./outdat/out27x.csv   f=1,2,3 c=hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat5nfn.csv o=./outdat/out27nfn.csv f=1,2,3 c=hamming,chi,phi,jaccard,support,lift

# 数値,k=
${pfxc}msim      k=key i=./indat/dat2.csv    o=./outdat/out28.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat2.csv    o=./outdat/out28x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat2nfn.csv o=./outdat/out28nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

# 数値,k=,-d
${pfxc}msim      -d k=key i=./indat/dat2.csv    o=./outdat/out29.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   -d k=0   i=./indat/dat2.csv    o=./outdat/out29x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn -d k=0   i=./indat/dat2nfn.csv o=./outdat/out29nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

#数値 nullデータ
${pfxc}msim      k=key i=./indat/dat3.csv    o=./outdat/out30.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat3.csv    o=./outdat/out30x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat3nfn.csv o=./outdat/out30nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

#nullデータ
${pfxc}msim      k=key i=./indat/dat0.csv    o=./outdat/out31.csv    f=x,y,z c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -x   k=0   i=./indat/dat0.csv    o=./outdat/out31x.csv   f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift
${pfxc}msim -nfn k=0   i=./indat/dat0nfn.csv o=./outdat/out31nfn.csv f=1,2,3 c=covar,ucovar,pearson,spearman,kendall,euclid,cosine,cityblock,hamming,chi,phi,jaccard,support,lift

