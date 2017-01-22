#!/bin/bash
#ファイルパス指定方法として、「./」を追加
. ../env

#name_kg_mcmd share

# nullデータ
${pfxc}mshare      k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat0s.csv    o=./outdat/out01.csv
${pfxc}mshare -x   k=0    f=1:数量シェア,2:金額シェア       i=./indat/dat0s.csv    o=./outdat/out01x.csv
${pfxc}mshare -nfn k=0    f=1,2                             i=./indat/dat0snfn.csv o=./outdat/out01nfn.csv

# 基本
${pfxc}mshare      k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat1s.csv    o=./outdat/out02.csv
${pfxc}mshare -x   k=0    f=1:数量シェア,2:金額シェア       i=./indat/dat1s.csv    o=./outdat/out02x.csv
${pfxc}mshare -nfn k=0    f=1,2                             i=./indat/dat1snfn.csv o=./outdat/out02nfn.csv

#null項目
${pfxc}mshare      k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat2s.csv    o=./outdat/out03.csv
${pfxc}mshare -x   k=0    f=1:数量シェア,2:金額シェア       i=./indat/dat2s.csv    o=./outdat/out03x.csv
${pfxc}mshare -nfn k=0    f=1,2                             i=./indat/dat2snfn.csv o=./outdat/out03nfn.csv

# 基本+nokey
${pfxc}mshare             f=数量:数量シェア,金額:金額シェア i=./indat/dat1s.csv    o=./outdat/out04.csv
${pfxc}mshare -x          f=1:数量シェア,2:金額シェア       i=./indat/dat1s.csv    o=./outdat/out04x.csv
${pfxc}mshare -nfn        f=1,2                             i=./indat/dat1snfn.csv o=./outdat/out04nfn.csv

#null項目+nokey
${pfxc}mshare             f=数量:数量シェア,金額:金額シェア i=./indat/dat2s.csv    o=./outdat/out05.csv
${pfxc}mshare -x          f=1:数量シェア,2:金額シェア       i=./indat/dat2s.csv    o=./outdat/out05x.csv
${pfxc}mshare -nfn        f=1,2                             i=./indat/dat2snfn.csv o=./outdat/out05nfn.csv

# ランダムデータ
# 基本
${pfxc}mshare      k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat1.csv    o=./outdat/out06.csv
${pfxc}mshare -x   k=0    f=1:数量シェア,2:金額シェア       i=./indat/dat1.csv    o=./outdat/out06x.csv
${pfxc}mshare -nfn k=0    f=1,2                             i=./indat/dat1nfn.csv o=./outdat/out06nfn.csv

#null項目
${pfxc}mshare      k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat2.csv    o=./outdat/out07.csv
${pfxc}mshare -x   k=0    f=1:数量シェア,2:金額シェア       i=./indat/dat2.csv    o=./outdat/out07x.csv
${pfxc}mshare -nfn k=0    f=1,2                             i=./indat/dat2nfn.csv o=./outdat/out07nfn.csv

# 基本+nokey
${pfxc}mshare             f=数量:数量シェア,金額:金額シェア i=./indat/dat1.csv    o=./outdat/out08.csv
${pfxc}mshare -x          f=1:数量シェア,2:金額シェア       i=./indat/dat1.csv    o=./outdat/out08x.csv
${pfxc}mshare -nfn        f=1,2                             i=./indat/dat1nfn.csv o=./outdat/out08nfn.csv

#null項目+nokey
${pfxc}mshare             f=数量:数量シェア,金額:金額シェア i=./indat/dat2.csv    o=./outdat/out09.csv
${pfxc}mshare -x          f=1:数量シェア,2:金額シェア       i=./indat/dat2.csv    o=./outdat/out09x.csv
${pfxc}mshare -nfn        f=1,2                             i=./indat/dat2nfn.csv o=./outdat/out09nfn.csv





# エラー終了
${pfxc}mshare                                               i=./indat/dat1s.csv o=kgError
${pfxc}mshare      k=顧客                                   i=./indat/dat1s.csv o=kgError
${pfxc}mshare -x   k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat1s.csv o=kgError
${pfxc}mshare -nfn k=顧客 f=数量:数量シェア,金額:金額シェア i=./indat/dat1s.csv o=kgError
${pfxc}mshare      k=1    f=2,3                             i=./indat/dat1s.csv o=kgError



