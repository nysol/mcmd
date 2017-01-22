#!/bin/bash

. ../env

#name_kg_mcmd avg

#NULLデータ
${pfxc}mavg         k=顧客 f=数量:数量平均,金額:金額平均 i=./indat/dat0s.csv    o=./outdat/out0.csv
${pfxc}mavg -x      k=0    f=1:数量平均,2:金額平均     i=./indat/dat0s.csv    o=./outdat/out0x.csv
${pfxc}mavg -nfn    k=1    f=2:数量平均,3:金額平均     i=./indat/dat0snfn.csv o=./outdat/out0nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量,金額               i=./indat/dat0s.csv    o=./outdat/out0nfno.csv
${pfxc}mavg -q      k=顧客  f=数量,金額               i=./indat/dat0s.csv    o=./outdat/out0q.csv
${pfxc}mavg -nfn -q k=1    f=2:数量平均,3:金額平均     i=./indat/dat0snfn.csv o=./outdat/out0qnfn.csv

#基本
${pfxc}mavg         k=顧客 f=数量:数量平均  i=./indat/dat1s.csv     o=./outdat/out1.csv
${pfxc}mavg -x      k=0   f=1:数量平均     i=./indat/dat1s.csv     o=./outdat/out1x.csv
${pfxc}mavg -nfn    k=0    f=1            i=./indat/dat1snfn.csv  o=./outdat/out1nfn.csv
${pfxc}mavg -nfno   k=顧客 f=数量          i=./indat/dat1s.csv     o=./outdat/out1nfno.csv
${pfxc}mavg -q      k=顧客 f=数量:数量平均  i=./indat/dat1s.csv      o=./outdat/out1q.csv
${pfxc}mavg -nfn -q k=0    f=1            i=./indat/dat1snfn.csv  o=./outdat/out1qnfn.csv

#基本(データにnull含む)
${pfxc}mavg         k=顧客 f=数量:数量平均  i=./indat/dat6s.csv    o=./outdat/out18.csv
${pfxc}mavg -x      k=0    f=1:数量平均    i=./indat/dat6s.csv    o=./outdat/out18x.csv
${pfxc}mavg -nfn    k=0    f=1            i=./indat/dat6snfn.csv o=./outdat/out18nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         i=./indat/dat6s.csv    o=./outdat/out18nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  i=./indat/dat6s.csv    o=./outdat/out18q.csv
${pfxc}mavg -nfn -q k=0    f=1            i=./indat/dat6snfn.csv o=./outdat/out18qnfn.csv

#f=の指定2つ
${pfxc}mavg         k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat1s.csv    o=./outdat/out2.csv
${pfxc}mavg -x      k=0    f=1:数量平均,2:金額平均      i=./indat/dat1s.csv    o=./outdat/out2x.csv
${pfxc}mavg -nfn    k=0    f=1,2                     i=./indat/dat1snfn.csv o=./outdat/out2nfn.csv
${pfxc}mavg -nfno   k=顧客 f=数量,金額                 i=./indat/dat1s.csv o=./outdat/out2nfno.csv
${pfxc}mavg -q      k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat1s.csv    o=./outdat/out2q.csv
${pfxc}mavg -q -nfn k=0    f=1,2                     i=./indat/dat1snfn.csv o=./outdat/out2qnfn.csv

#k=の指定なし
${pfxc}mavg         f=数量:数量平均,金額:金額平均  i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}mavg -x      f=1:数量平均,2:金額平均       i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}mavg -nfn    f=1,2                      i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv
${pfxc}mavg -nfno   f=数量,金額                 i=./indat/dat1s.csv  o=./outdat/out3nfno.csv
${pfxc}mavg -q      f=数量:数量平均,金額:金額平均  i=./indat/dat1s.csv    o=./outdat/out3q.csv
${pfxc}mavg -nfn -q f=1,2                      i=./indat/dat1snfn.csv o=./outdat/out3qnfn.csv

#k=の２つ
${pfxc}mavg          k=顧客,日付 f=数量:数量平均 i=./indat/dat2s.csv    o=./outdat/out4.csv
${pfxc}mavg -x       k=0,1 f=2:数量平均        i=./indat/dat2s.csv    o=./outdat/out4x.csv
${pfxc}mavg -nfn     k=0,1 f=2                i=./indat/dat2snfn.csv o=./outdat/out4nfn.csv
${pfxc}mavg -nfno    k=顧客,日付 f=数量         i=./indat/dat2s.csv o=./outdat/out4nfno.csv
${pfxc}mavg -q       k=顧客,日付 f=数量:数量平均 i=./indat/dat2s.csv    o=./outdat/out4q.csv
${pfxc}mavg -q -nfn  k=0,1 f=2                i=./indat/dat2snfn.csv o=./outdat/out4qnfn.csv

#k=の２つ,f=の２つ
${pfxc}mavg         k=顧客,日付  f=数量:数量平均,金額:金額平均  i=./indat/dat2s.csv    o=./outdat/out5.csv
${pfxc}mavg -x      k=0,1       f=2:数量平均,3:金額平均      i=./indat/dat2s.csv    o=./outdat/out5x.csv
${pfxc}mavg -nfn    k=0,1       f=2,3                     i=./indat/dat2snfn.csv o=./outdat/out5nfn.csv
${pfxc}mavg -nfno   k=顧客,日付  f=数量,金額                 i=./indat/dat2s.csv o=./outdat/out5nfno.csv
${pfxc}mavg -q      k=顧客,日付  f=数量:数量平均,金額:金額平均  i=./indat/dat2s.csv    o=./outdat/out5q.csv
${pfxc}mavg -q -nfn k=0,1       f=2,3                      i=./indat/dat2snfn.csv o=./outdat/out5qnfn.csv


#k=の２つ,f=の２つ,-n
${pfxc}mavg         k=顧客,日付 f=数量:数量平均,金額:金額平均  -n i=./indat/dat2s.csv    o=./outdat/out6.csv
${pfxc}mavg -x      k=0,1      f=2:数量平均,3:金額平均      -n i=./indat/dat2s.csv    o=./outdat/out6x.csv
${pfxc}mavg -nfn    k=0,1      f=2,3                     -n i=./indat/dat2snfn.csv o=./outdat/out6nfn.csv
${pfxc}mavg -nfno   k=顧客,日付 f=数量,金額                 -n i=./indat/dat2s.csv  o=./outdat/out6nfno.csv
${pfxc}mavg -q      k=顧客,日付 f=数量:数量平均,金額:金額平均  -n i=./indat/dat2s.csv    o=./outdat/out6q.csv
${pfxc}mavg -q -nfn k=0,1      f=2,3                      -n i=./indat/dat2snfn.csv o=./outdat/out6qnfn.csv

#部分的にNULLが入っているもの,k=の指定なし
${pfxc}mavg         f=数量:数量平均,金額:金額平均 i=./indat/dat3s.csv    o=./outdat/out7.csv
${pfxc}mavg -x      f=1:数量平均,2:金額平均      i=./indat/dat3s.csv    o=./outdat/out7x.csv
${pfxc}mavg -nfn    f=1,2                     i=./indat/dat3snfn.csv o=./outdat/out7nfn.csv
${pfxc}mavg -nfno   f=数量,金額                i=./indat/dat3s.csv    o=./outdat/out7nfno.csv
${pfxc}mavg -q      f=数量:数量平均,金額:金額平均 i=./indat/dat3s.csv    o=./outdat/out7q.csv
${pfxc}mavg -q -nfn f=1,2                     i=./indat/dat3snfn.csv o=./outdat/out7qnfn.csv


#部分的にNULLが入っているもの,k=の指定なし-n
${pfxc}mavg         f=数量:数量平均,金額:金額平均 -n i=./indat/dat3s.csv    o=./outdat/out8.csv
${pfxc}mavg -x      f=1:数量平均,2:金額平均      -n i=./indat/dat3s.csv    o=./outdat/out8x.csv
${pfxc}mavg -nfn    f=1,2                      -n i=./indat/dat3snfn.csv o=./outdat/out8nfn.csv
${pfxc}mavg -nfno   f=数量,金額                 -n i=./indat/dat3s.csv o=./outdat/out8nfno.csv
${pfxc}mavg -q      f=数量:数量平均,金額:金額平均  -n i=./indat/dat3s.csv    o=./outdat/out8q.csv
${pfxc}mavg -q -nfn f=1,2                      -n i=./indat/dat3snfn.csv o=./outdat/out8qnfn.csv


#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mavg         k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat3s.csv    o=./outdat/out9.csv
${pfxc}mavg -x      k=0 f=1:数量平均,2:金額平均         i=./indat/dat3s.csv    o=./outdat/out9x.csv
${pfxc}mavg -nfn    k=0 f=1,2                        i=./indat/dat3snfn.csv o=./outdat/out9nfn.csv
${pfxc}mavg -nfno   k=顧客 f=数量,金額                 i=./indat/dat3s.csv o=./outdat/out9nfno.csv
${pfxc}mavg -q      k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat3s.csv    o=./outdat/out9q.csv
${pfxc}mavg -q -nfn k=0 f=1,2                        i=./indat/dat3snfn.csv o=./outdat/out9qnfn.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mavg         k=顧客  f=数量:数量平均,金額:金額平均 -n i=./indat/dat3s.csv    o=./outdat/out10.csv
${pfxc}mavg -x      k=0    f=1:数量平均,2:金額平均      -n i=./indat/dat3s.csv    o=./outdat/out10x.csv
${pfxc}mavg -nfn    k=0    f=1,2                     -n i=./indat/dat3snfn.csv o=./outdat/out10nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量,金額                -n i=./indat/dat3s.csv o=./outdat/out10nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均,金額:金額平均 -n i=./indat/dat3s.csv    o=./outdat/out10q.csv
${pfxc}mavg -q -nfn k=0    f=1,2                     -n i=./indat/dat3snfn.csv o=./outdat/out10qnfn.csv


#部分的にNULLが入っているもの,k=指定２つ
${pfxc}mavg         k=顧客,日付 f=数量:数量平均,金額:金額平均 i=./indat/dat4s.csv    o=./outdat/out11.csv
${pfxc}mavg -x      k=0,1      f=2:数量平均,3:金額平均      i=./indat/dat4s.csv    o=./outdat/out11x.csv
${pfxc}mavg -nfn    k=0,1      f=2,3                     i=./indat/dat4snfn.csv o=./outdat/out11nfn.csv
${pfxc}mavg -nfno   k=顧客,日付 f=数量,金額                 i=./indat/dat4s.csv o=./outdat/out11nfno.csv
${pfxc}mavg -q      k=顧客,日付 f=数量:数量平均,金額:金額平均 i=./indat/dat4s.csv    o=./outdat/out11q.csv
${pfxc}mavg -q -nfn k=0,1      f=2,3                     i=./indat/dat4snfn.csv o=./outdat/out11qnfn.csv

#部分的にNULLが入っているもの,k=指定２つ,-n
${pfxc}mavg         k=顧客,日付 f=数量:数量平均,金額:金額平均 -n i=./indat/dat4s.csv    o=./outdat/out12.csv
${pfxc}mavg -x      k=0,1      f=2:数量平均,3:金額平均      -n i=./indat/dat4s.csv    o=./outdat/out12x.csv
${pfxc}mavg -nfn    k=0,1      f=2,3                     -n i=./indat/dat4snfn.csv o=./outdat/out12nfn.csv
${pfxc}mavg -nfno   k=顧客,日付 f=数量,金額                 -n i=./indat/dat4s.csv o=./outdat/out12nfno.csv
${pfxc}mavg -q      k=顧客,日付 f=数量:数量平均,金額:金額平均 -n i=./indat/dat4s.csv    o=./outdat/out12q.csv
${pfxc}mavg -q -nfn k=0,1      f=2,3                     -n i=./indat/dat4snfn.csv o=./outdat/out12qnfn.csv

#キー項目にNULL
${pfxc}mavg         k=顧客  f=数量:数量平均,金額:金額平均 i=./indat/dat5s.csv     o=./outdat/out13.csv
${pfxc}mavg -x      k=0    f=2:数量平均,3:金額平均      i=./indat/dat5s.csv     o=./outdat/out13x.csv
${pfxc}mavg -nfn    k=0    f=2,3                      i=./indat/dat5snfn.csv  o=./outdat/out13nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量,金額                 i=./indat/dat5s.csv     o=./outdat/out13nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均,金額:金額平均  i=./indat/dat5s.csv     o=./outdat/out13q.csv
${pfxc}mavg -q -nfn k=0    f=2,3                      i=./indat/dat5snfn.csv  o=./outdat/out13qnfn.csv

#precision=0を指定
${pfxc}mavg         k=顧客 f=数量:数量平均  precision=0  i=./indat/dat1s.csv    o=./outdat/out14.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=0  i=./indat/dat1s.csv    o=./outdat/out14x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=0  i=./indat/dat1snfn.csv o=./outdat/out14nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=0  i=./indat/dat1s.csv    o=./outdat/out14nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  precision=0  i=./indat/dat1s.csv    o=./outdat/out14q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=0  i=./indat/dat1snfn.csv o=./outdat/out14qnfn.csv

#precision=1を指定
${pfxc}mavg         k=顧客  f=数量:数量平均 precision=1  i=./indat/dat1s.csv    o=./outdat/out15.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=1  i=./indat/dat1s.csv    o=./outdat/out15x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=1  i=./indat/dat1snfn.csv o=./outdat/out15nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=1   i=./indat/dat1s.csv   o=./outdat/out15nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均 precision=1   i=./indat/dat1s.csv    o=./outdat/out15q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=1  i=./indat/dat1snfn.csv o=./outdat/out15qnfn.csv

#precision=2を指定
${pfxc}mavg         k=顧客  f=数量:数量平均 precision=2  i=./indat/dat1s.csv    o=./outdat/out16.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=2  i=./indat/dat1s.csv    o=./outdat/out16x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=2  i=./indat/dat1snfn.csv o=./outdat/out16nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=2  i=./indat/dat1s.csv    o=./outdat/out16nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  precision=2  i=./indat/dat1s.csv    o=./outdat/out16q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=2  i=./indat/dat1snfn.csv o=./outdat/out16qnfn.csv

#precision=100を指定
${pfxc}mavg         k=顧客  f=数量:数量平均 precision=100 i=./indat/dat1s.csv     o=./outdat/out17.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=100 i=./indat/dat1s.csv     o=./outdat/out17x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=100 i=./indat/dat1snfn.csv  o=./outdat/out17nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=100 i=./indat/dat1s.csv     o=./outdat/out17nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  precision=100 i=./indat/dat1s.csv     o=./outdat/out17q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=100  i=./indat/dat1snfn.csv o=./outdat/out17qnfn.csv

# 以下ランダムデータ

#NULLデータ
${pfxc}mavg         k=顧客 f=数量:数量平均,金額:金額平均 i=./indat/dat0.csv    o=./outdat/out19.csv
${pfxc}mavg -x      k=0    f=1:数量平均,2:金額平均     i=./indat/dat0.csv    o=./outdat/out19x.csv
${pfxc}mavg -nfn    k=1    f=2:数量平均,3:金額平均     i=./indat/dat0nfn.csv o=./outdat/out19nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量,金額               i=./indat/dat0.csv    o=./outdat/out19nfno.csv
${pfxc}mavg -q      k=顧客  f=数量,金額               i=./indat/dat0.csv    o=./outdat/out19q.csv
${pfxc}mavg -nfn -q k=1    f=2:数量平均,3:金額平均     i=./indat/dat0nfn.csv o=./outdat/out19qnfn.csv

#基本
${pfxc}mavg         k=顧客 f=数量:数量平均 i=./indat/dat1.csv    o=./outdat/out20.csv
${pfxc}mavg -x      k=0   f=1:数量平均    i=./indat/dat1.csv    o=./outdat/out20x.csv
${pfxc}mavg -nfn    k=0    f=1             i=./indat/dat1nfn.csv o=./outdat/out20nfn.csv
${pfxc}mavg -nfno   k=顧客 f=数量 i=./indat/dat1.csv o=./outdat/out20nfno.csv
${pfxc}mavg -q      k=顧客 f=数量:数量平均 i=./indat/dat1.csv    o=./outdat/out20q.csv
${pfxc}mavg -nfn -q k=0    f=1             i=./indat/dat1nfn.csv o=./outdat/out20qnfn.csv

#基本(データにnull含む)
${pfxc}mavg         k=顧客 f=数量:数量平均  i=./indat/dat6.csv    o=./outdat/out21.csv
${pfxc}mavg -x      k=0    f=1:数量平均    i=./indat/dat6.csv    o=./outdat/out21x.csv
${pfxc}mavg -nfn    k=0    f=1            i=./indat/dat6nfn.csv o=./outdat/out21nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         i=./indat/dat6.csv    o=./outdat/out21nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  i=./indat/dat6.csv    o=./outdat/out21q.csv
${pfxc}mavg -nfn -q k=0    f=1            i=./indat/dat6nfn.csv o=./outdat/out21qnfn.csv

#f=の指定2つ
${pfxc}mavg         k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat1.csv    o=./outdat/out22.csv
${pfxc}mavg -x      k=0    f=1:数量平均,2:金額平均      i=./indat/dat1.csv    o=./outdat/out22x.csv
${pfxc}mavg -nfn    k=0    f=1,2                     i=./indat/dat1nfn.csv o=./outdat/out22nfn.csv
${pfxc}mavg -nfno   k=顧客 f=数量,金額                 i=./indat/dat1.csv o=./outdat/out22nfno.csv
${pfxc}mavg -q      k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat1.csv    o=./outdat/out22q.csv
${pfxc}mavg -q -nfn k=0    f=1,2                     i=./indat/dat1nfn.csv o=./outdat/out22qnfn.csv


#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mavg         k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat3.csv    o=./outdat/out23.csv
${pfxc}mavg -x      k=0 f=1:数量平均,2:金額平均         i=./indat/dat3.csv    o=./outdat/out23x.csv
${pfxc}mavg -nfn    k=0 f=1,2                        i=./indat/dat3nfn.csv o=./outdat/out23nfn.csv
${pfxc}mavg -nfno   k=顧客 f=数量,金額                 i=./indat/dat3.csv o=./outdat/out23nfno.csv
${pfxc}mavg -q      k=顧客 f=数量:数量平均,金額:金額平均  i=./indat/dat3.csv    o=./outdat/out23q.csv
${pfxc}mavg -q -nfn k=0 f=1,2                        i=./indat/dat3nfn.csv o=./outdat/out23qnfn.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mavg         k=顧客  f=数量:数量平均,金額:金額平均 -n i=./indat/dat3.csv    o=./outdat/out24.csv
${pfxc}mavg -x      k=0    f=1:数量平均,2:金額平均      -n i=./indat/dat3.csv    o=./outdat/out24x.csv
${pfxc}mavg -nfn    k=0    f=1,2                     -n i=./indat/dat3nfn.csv o=./outdat/out24nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量,金額                -n i=./indat/dat3.csv o=./outdat/out24nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均,金額:金額平均 -n i=./indat/dat3.csv    o=./outdat/out24q.csv
${pfxc}mavg -q -nfn k=0    f=1,2                     -n i=./indat/dat3nfn.csv o=./outdat/out24qnfn.csv


#部分的にNULLが入っているもの,k=指定２つ
${pfxc}mavg         k=顧客,日付 f=数量:数量平均,金額:金額平均 i=./indat/dat4.csv    o=./outdat/out25.csv
${pfxc}mavg -x      k=0,1      f=2:数量平均,3:金額平均      i=./indat/dat4.csv    o=./outdat/out25x.csv
${pfxc}mavg -nfn    k=0,1      f=2,3                     i=./indat/dat4nfn.csv o=./outdat/out25nfn.csv
${pfxc}mavg -nfno   k=顧客,日付 f=数量,金額                 i=./indat/dat4.csv o=./outdat/out25nfno.csv
${pfxc}mavg -q      k=顧客,日付 f=数量:数量平均,金額:金額平均 i=./indat/dat4.csv    o=./outdat/out25q.csv
${pfxc}mavg -q -nfn k=0,1      f=2,3                     i=./indat/dat4nfn.csv o=./outdat/out25qnfn.csv

#部分的にNULLが入っているもの,k=指定２つ,-n
${pfxc}mavg         k=顧客,日付 f=数量:数量平均,金額:金額平均 -n i=./indat/dat4.csv    o=./outdat/out26.csv
${pfxc}mavg -x      k=0,1      f=2:数量平均,3:金額平均      -n i=./indat/dat4.csv    o=./outdat/out26x.csv
${pfxc}mavg -nfn    k=0,1      f=2,3                     -n i=./indat/dat4nfn.csv o=./outdat/out26nfn.csv
${pfxc}mavg -nfno   k=顧客,日付 f=数量,金額                 -n i=./indat/dat4.csv o=./outdat/out26nfno.csv
${pfxc}mavg -q      k=顧客,日付 f=数量:数量平均,金額:金額平均 -n i=./indat/dat4.csv    o=./outdat/out26q.csv
${pfxc}mavg -q -nfn k=0,1      f=2,3                     -n i=./indat/dat4nfn.csv o=./outdat/out26qnfn.csv

#キー項目にNULL
${pfxc}mavg         k=顧客  f=数量:数量平均,金額:金額平均 i=./indat/dat5.csv     o=./outdat/out27.csv
${pfxc}mavg -x      k=0    f=2:数量平均,3:金額平均      i=./indat/dat5.csv     o=./outdat/out27x.csv
${pfxc}mavg -nfn    k=0    f=2,3                      i=./indat/dat5nfn.csv  o=./outdat/out27nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量,金額                 i=./indat/dat5.csv     o=./outdat/out27nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均,金額:金額平均  i=./indat/dat5.csv     o=./outdat/out27q.csv
${pfxc}mavg -q -nfn k=0    f=2,3                      i=./indat/dat5nfn.csv  o=./outdat/out27qnfn.csv

#precision=0を指定
${pfxc}mavg         k=顧客 f=数量:数量平均  precision=0  i=./indat/dat1.csv    o=./outdat/out28.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=0  i=./indat/dat1.csv    o=./outdat/out28x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=0  i=./indat/dat1nfn.csv o=./outdat/out28nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=0  i=./indat/dat1.csv    o=./outdat/out28nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  precision=0  i=./indat/dat1.csv    o=./outdat/out28q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=0  i=./indat/dat1nfn.csv o=./outdat/out28qnfn.csv

#precision=1を指定
${pfxc}mavg         k=顧客  f=数量:数量平均 precision=1  i=./indat/dat1.csv    o=./outdat/out29.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=1  i=./indat/dat1.csv    o=./outdat/out29x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=1  i=./indat/dat1nfn.csv o=./outdat/out29nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=1   i=./indat/dat1.csv   o=./outdat/out29nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均 precision=1   i=./indat/dat1.csv    o=./outdat/out29q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=1  i=./indat/dat1nfn.csv o=./outdat/out29qnfn.csv

#precision=2を指定
${pfxc}mavg         k=顧客  f=数量:数量平均 precision=2  i=./indat/dat1.csv    o=./outdat/out30.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=2  i=./indat/dat1.csv    o=./outdat/out30x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=2  i=./indat/dat1nfn.csv o=./outdat/out30nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=2  i=./indat/dat1.csv    o=./outdat/out30nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  precision=2  i=./indat/dat1.csv    o=./outdat/out30q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=2  i=./indat/dat1nfn.csv o=./outdat/out30qnfn.csv

#precision=100を指定
${pfxc}mavg         k=顧客  f=数量:数量平均 precision=100 i=./indat/dat1.csv     o=./outdat/out31.csv
${pfxc}mavg -x      k=0    f=1:数量平均    precision=100 i=./indat/dat1.csv     o=./outdat/out31x.csv
${pfxc}mavg -nfn    k=0    f=1            precision=100 i=./indat/dat1nfn.csv  o=./outdat/out31nfn.csv
${pfxc}mavg -nfno   k=顧客  f=数量         precision=100 i=./indat/dat1.csv     o=./outdat/out31nfno.csv
${pfxc}mavg -q      k=顧客  f=数量:数量平均  precision=100 i=./indat/dat1.csv     o=./outdat/out31q.csv
${pfxc}mavg -q -nfn k=0    f=1            precision=100  i=./indat/dat1nfn.csv o=./outdat/out31qnfn.csv

