#!/bin/bash

. ../env

#name_kg_mcmd accum

#NULLデータ
${pfxc}maccum      k=顧客  s=日付 f=数量:数量累計,金額:金額累計  i=./indat/dat0.csv     o=./outdat/out0.csv
${pfxc}maccum -x   k=0    s=1    f=2:数量累計,3:金額累計      i=./indat/dat0.csv     o=./outdat/out0x.csv
${pfxc}maccum -nfn k=0    s=1    f=2,3                     i=./indat/dat0nfn.csv  o=./outdat/out0nfn.csv
${pfxc}maccum -nfno k=顧客 s=日付 f=数量:数量累計,金額:金額累計  i=./indat/dat0.csv     o=./outdat/out0nfno.csv
${pfxc}maccum      k=顧客  s=日付 f=数量:数量累計,金額:金額累計  i=./indat/dat0s.csv     o=./outdat/out0s.csv

#基本
${pfxc}maccum      k=顧客   s=日付  f=数量:数量累計  i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}maccum -x   k=0     s=1     f=2:数量累計    i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}maccum -nfn k=0     s=1     f=2            i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv
${pfxc}maccum -nfno k=顧客  s=日付  f=数量:数量累計  i=./indat/dat1.csv    o=./outdat/out1nfno.csv
${pfxc}maccum      k=顧客   s=日付  f=数量:数量累計  i=./indat/dat1s.csv    o=./outdat/out1s.csv

#f=の指定2つ
${pfxc}maccum      k=顧客   s=日付  f=数量:数量累計,金額:金額累計   i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}maccum -x   k=0     s=1     f=2:数量累計,3:金額累計       i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}maccum -nfn k=0     s=1     f=2,3                       i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}maccum -nfno k=顧客   s=日付  f=数量:数量累計,金額:金額累計  i=./indat/dat1.csv    o=./outdat/out2nfno.csv
${pfxc}maccum      k=顧客   s=日付  f=数量:数量累計,金額:金額累計   i=./indat/dat1s.csv    o=./outdat/out2s.csv

#k=の指定なし
${pfxc}maccum       s=日付 f=数量:数量累計,金額:金額累計 i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}maccum -x    s=1   f=2:数量累計,3:金額累計      i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}maccum -nfn  s=1   f=2,3                     i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}maccum -nfno s=日付 f=数量:数量累計,金額:金額累計 i=./indat/dat1.csv    o=./outdat/out3nfno.csv
${pfxc}maccum       s=日付 f=数量:数量累計,金額:金額累計 i=./indat/dat1s.csv    o=./outdat/out3s.csv

#k=の２つ
${pfxc}maccum      k=顧客,日付  s=時間 f=数量:数量累計  i=./indat/dat3.csv    o=./outdat/out4.csv
${pfxc}maccum -x   k=0,1       s=2   f=3:数量累計    i=./indat/dat3.csv    o=./outdat/out4x.csv
${pfxc}maccum -nfn k=0,1       s=2   f=3            i=./indat/dat3nfn.csv o=./outdat/out4nfn.csv
${pfxc}maccum -nfno k=顧客,日付 s=時間 f=数量:数量累計  i=./indat/dat3.csv    o=./outdat/out4nfno.csv
${pfxc}maccum      k=顧客,日付  s=時間 f=数量:数量累計  i=./indat/dat3s.csv    o=./outdat/out4s.csv

#k=の２つ,f=の２つ
${pfxc}maccum      k=顧客,日付  s=時間 f=数量:数量累計,金額:金額累計 i=./indat/dat3.csv    o=./outdat/out5.csv
${pfxc}maccum -x   k=0,1      s=2  f=3:数量累計,4:金額累計       i=./indat/dat3.csv    o=./outdat/out5x.csv
${pfxc}maccum -nfn k=0,1      s=2  f=3,4                         i=./indat/dat3nfn.csv o=./outdat/out5nfn.csv
${pfxc}maccum -nfno k=顧客,日付 s=時間 f=数量:数量累計,金額:金額累計 i=./indat/dat3.csv    o=./outdat/out5nfno.csv
${pfxc}maccum      k=顧客,日付  s=時間 f=数量:数量累計,金額:金額累計 i=./indat/dat3s.csv    o=./outdat/out5s.csv

#部分的にNULLが入っているもの,k=の指定なし
${pfxc}maccum       s=日付  f=数量:数量累計,金額:金額累計 i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}maccum -x    s=1    f=2:数量累計,3:金額累計      i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}maccum -nfn  s=1    f=2,3                      i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv
${pfxc}maccum -nfno s=日付  f=数量:数量累計,金額:金額累計 i=./indat/dat2.csv    o=./outdat/out6nfno.csv
${pfxc}maccum       s=日付  f=数量:数量累計,金額:金額累計 i=./indat/dat2s.csv    o=./outdat/out6s.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}maccum      k=顧客 s=日付  f=数量:数量累計,金額:金額累計 i=./indat/dat2.csv    o=./outdat/out7.csv
${pfxc}maccum -x   k=0   s=1     f=2:数量累計,3:金額累計     i=./indat/dat2.csv    o=./outdat/out7x.csv
${pfxc}maccum -nfn k=0   s=1     f=2,3                     i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv
${pfxc}maccum -nfno k=顧客 s=日付 f=数量:数量累計,金額:金額累計 i=./indat/dat2.csv    o=./outdat/out7nfno.csv
${pfxc}maccum      k=顧客 s=日付  f=数量:数量累計,金額:金額累計 i=./indat/dat2s.csv    o=./outdat/out7s.csv

#部分的にNULLが入っているもの,k=指定２つ
${pfxc}maccum      k=顧客,日付 s=時間 f=数量:数量累計,金額:金額累計 i=./indat/dat4.csv    o=./outdat/out8.csv
${pfxc}maccum -x   k=0,1      s=2 f=3:数量累計,4:金額累計       i=./indat/dat4.csv    o=./outdat/out8x.csv
${pfxc}maccum -nfn k=0,1      s=2 f=3,4                         i=./indat/dat4nfn.csv o=./outdat/out8nfn.csv
${pfxc}maccum -nfno k=顧客,日付 s=時間 f=数量:数量累計,金額:金額累計 i=./indat/dat4.csv    o=./outdat/out8nfno.csv
${pfxc}maccum      k=顧客,日付 s=時間 f=数量:数量累計,金額:金額累計 i=./indat/dat4s.csv    o=./outdat/out8s.csv


# ソーテイング機能
${pfxc}maccum      k=顧客   s=日付%n  f=数量:数量累計,金額:金額累計   i=./indat/dat1.csv    o=./outdat/out9.csv
${pfxc}maccum -x   k=0     s=1%n     f=2:数量累計,3:金額累計       i=./indat/dat1.csv    o=./outdat/out9x.csv
${pfxc}maccum -nfn k=0     s=1%n     f=2,3                       i=./indat/dat1nfn.csv o=./outdat/out9nfn.csv
${pfxc}maccum -nfno k=顧客   s=日付%n  f=数量:数量累計,金額:金額累計  i=./indat/dat1.csv    o=./outdat/out9nfno.csv

${pfxc}maccum      k=顧客   s=日付%nr  f=数量:数量累計,金額:金額累計   i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}maccum -x   k=0     s=1%nr     f=2:数量累計,3:金額累計       i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}maccum -nfn k=0     s=1%nr     f=2,3                       i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv
${pfxc}maccum -nfno k=顧客   s=日付%nr  f=数量:数量累計,金額:金額累計  i=./indat/dat1.csv    o=./outdat/out10nfno.csv

${pfxc}maccum      k=顧客   s=日付%r  f=数量:数量累計,金額:金額累計   i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}maccum -x   k=0     s=1%r     f=2:数量累計,3:金額累計       i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}maccum -nfn k=0     s=1%r     f=2,3                       i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv
${pfxc}maccum -nfno k=顧客   s=日付%r  f=数量:数量累計,金額:金額累計  i=./indat/dat1.csv    o=./outdat/out11nfno.csv

${pfxc}maccum      k=顧客   s=日付,時間 f=数量:数量累計,金額:金額累計   i=./indat/dat4.csv    o=./outdat/out12.csv
${pfxc}maccum -x   k=0     s=1,2     f=3:数量累計,4:金額累計       i=./indat/dat4.csv    o=./outdat/out12x.csv
${pfxc}maccum -nfn k=0     s=1,2     f=3,4                       i=./indat/dat4nfn.csv o=./outdat/out12nfn.csv
${pfxc}maccum -nfno k=顧客   s=日付,時間  f=数量:数量累計,金額:金額累計  i=./indat/dat4.csv    o=./outdat/out12nfno.csv


${pfxc}maccum      -q k=顧客   s=日付%n  f=数量:数量累計,金額:金額累計   i=./indat/dat1.csv    o=./outdat/out13.csv
${pfxc}maccum -x   -q k=0     s=1%n     f=2:数量累計,3:金額累計       i=./indat/dat1.csv    o=./outdat/out13x.csv
${pfxc}maccum -nfn -q k=0     s=1%n     f=2,3                       i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv
${pfxc}maccum -nfno -q k=顧客   s=日付%n  f=数量:数量累計,金額:金額累計  i=./indat/dat1.csv    o=./outdat/out13nfno.csv


