#修正日は 20120308
#修正者は 樋口　寛視
#修正内容は 項目番号指定パラーメータをマイナス１する。（以前は1からの指定だったが、０からに変更になったため。）
#!/bin/bash

. ../env

#name_kg_mcmd hashavg

#NULLデータ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 i=./indat/dat0.csv    o=./outdat/out0nfno.csv

#基本
${pfxc}mhashavg      k=顧客 f=数量:数量平均 i=./indat/dat1.csv     o=./outdat/out1.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均    i=./indat/dat1.csv     o=./outdat/out1x.csv
${pfxc}mhashavg -nfn k=0    f=1             i=./indat/dat1nfn.csv  o=./outdat/out1nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量 i=./indat/dat1.csv     o=./outdat/out1nfno.csv

#f=の指定2つ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 i=./indat/dat1.csv    o=./outdat/out2nfno.csv

#k=の指定なし
${pfxc}mhashavg      f=数量:数量平均,金額:金額平均 i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mhashavg -x   f=1:数量平均,2:金額平均       i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mhashavg -nfn f=1,2                         i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}mhashavg -nfno f=数量,金額 i=./indat/dat1.csv    o=./outdat/out3nfno.csv

#k=の２つ
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均 i=./indat/dat2.csv    o=./outdat/out4.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均    i=./indat/dat2.csv    o=./outdat/out4x.csv
${pfxc}mhashavg -nfn k=0,1       f=2             i=./indat/dat2nfn.csv o=./outdat/out4nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量 i=./indat/dat2.csv    o=./outdat/out4nfno.csv

#k=の２つ,f=の２つ
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 i=./indat/dat2.csv    o=./outdat/out5nfno.csv

#k=の２つ,f=の２つ,-n
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 -n i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       -n i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         -n i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 -n i=./indat/dat2.csv    o=./outdat/out6nfno.csv

#部分的にNULLが入っているもの,k=の指定なし
${pfxc}mhashavg      f=数量:数量平均,金額:金額平均 i=./indat/dat3.csv     o=./outdat/out7.csv
${pfxc}mhashavg -x   f=1:数量平均,2:金額平均       i=./indat/dat3.csv     o=./outdat/out7x.csv
${pfxc}mhashavg -nfn f=1,2                         i=./indat/dat3nfn.csv  o=./outdat/out7nfn.csv
${pfxc}mhashavg -nfno f=数量,金額 i=./indat/dat3.csv     o=./outdat/out7nfno.csv

#部分的にNULLが入っているもの,k=の指定なし-n
${pfxc}mhashavg      f=数量:数量平均,金額:金額平均 -n i=./indat/dat3.csv     o=./outdat/out8.csv
${pfxc}mhashavg -x   f=1:数量平均,2:金額平均       -n i=./indat/dat3.csv     o=./outdat/out8x.csv
${pfxc}mhashavg -nfn f=1,2                         -n i=./indat/dat3nfn.csv  o=./outdat/out8nfn.csv
${pfxc}mhashavg -nfno f=数量,金額 -n i=./indat/dat3.csv     o=./outdat/out8nfno.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 i=./indat/dat3.csv    o=./outdat/out9.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       i=./indat/dat3.csv    o=./outdat/out9x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         i=./indat/dat3nfn.csv o=./outdat/out9nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 i=./indat/dat3.csv    o=./outdat/out9nfno.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 -n i=./indat/dat3.csv    o=./outdat/out10.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       -n i=./indat/dat3.csv    o=./outdat/out10x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         -n i=./indat/dat3nfn.csv o=./outdat/out10nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 -n i=./indat/dat3.csv    o=./outdat/out10nfno.csv

#部分的にNULLが入っているもの,k=指定２つ
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 i=./indat/dat4.csv    o=./outdat/out11.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       i=./indat/dat4.csv    o=./outdat/out11x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         i=./indat/dat4nfn.csv o=./outdat/out11nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 i=./indat/dat4.csv    o=./outdat/out11nfno.csv

#部分的にNULLが入っているもの,k=指定２つ,-n
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 -n i=./indat/dat4.csv     o=./outdat/out12.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       -n i=./indat/dat4.csv     o=./outdat/out12x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         -n i=./indat/dat4nfn.csv  o=./outdat/out12nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 -n i=./indat/dat4.csv     o=./outdat/out12nfno.csv

#キー項目にNULL
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 i=./indat/dat5.csv    o=./outdat/out13.csv
${pfxc}mhashavg -x   k=0    f=2:数量平均,3:金額平均       i=./indat/dat5.csv    o=./outdat/out13x.csv
${pfxc}mhashavg -nfn k=0    f=2,3                         i=./indat/dat5nfn.csv o=./outdat/out13nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 i=./indat/dat5.csv    o=./outdat/out13nfno.csv

#hashサイズ変更
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat0.csv    o=./outdat/out14.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       hs=101 i=./indat/dat0.csv    o=./outdat/out14x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         hs=101 i=./indat/dat0nfn.csv o=./outdat/out14nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 hs=101 i=./indat/dat0.csv    o=./outdat/out14nfno.csv

#基本
${pfxc}mhashavg      k=顧客 f=数量:数量平均 i=./indat/dat1.csv    hs=101 o=./outdat/out15.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均    i=./indat/dat1.csv    hs=101 o=./outdat/out15x.csv
${pfxc}mhashavg -nfn k=0    f=1             i=./indat/dat1nfn.csv hs=101 o=./outdat/out15nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量 i=./indat/dat1.csv    hs=101 o=./outdat/out15nfno.csv

#f=の指定2つ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat1.csv    o=./outdat/out16.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       hs=101 i=./indat/dat1.csv    o=./outdat/out16x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         hs=101 i=./indat/dat1nfn.csv o=./outdat/out16nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 hs=101 i=./indat/dat1.csv    o=./outdat/out16nfno.csv

#k=の指定なし
${pfxc}mhashavg      f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat1.csv    o=./outdat/out17.csv
${pfxc}mhashavg -x   f=1:数量平均,2:金額平均       hs=101 i=./indat/dat1.csv    o=./outdat/out17x.csv
${pfxc}mhashavg -nfn f=1,2                         hs=101 i=./indat/dat1nfn.csv o=./outdat/out17nfn.csv
${pfxc}mhashavg -nfno f=数量,金額 hs=101 i=./indat/dat1.csv    o=./outdat/out17nfno.csv

#k=の２つ
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均 hs=101 i=./indat/dat2.csv    o=./outdat/out18.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均    hs=101 i=./indat/dat2.csv    o=./outdat/out18x.csv
${pfxc}mhashavg -nfn k=0,1       f=2             hs=101 i=./indat/dat2nfn.csv o=./outdat/out18nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量 hs=101 i=./indat/dat2.csv    o=./outdat/out18nfno.csv

#k=の２つ,f=の２つ
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat2.csv    o=./outdat/out19.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       hs=101 i=./indat/dat2.csv    o=./outdat/out19x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         hs=101 i=./indat/dat2nfn.csv o=./outdat/out19nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 hs=101 i=./indat/dat2.csv    o=./outdat/out19nfno.csv

#k=の２つ,f=の２つ,-n
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 -n hs=101 i=./indat/dat2.csv    o=./outdat/out20.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       -n hs=101 i=./indat/dat2.csv    o=./outdat/out20x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         -n hs=101 i=./indat/dat2nfn.csv o=./outdat/out20nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 -n hs=101 i=./indat/dat2.csv    o=./outdat/out20nfno.csv

#部分的にNULLが入っているもの,k=の指定なし
${pfxc}mhashavg      f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat3.csv    o=./outdat/out21.csv
${pfxc}mhashavg -x   f=1:数量平均,2:金額平均       hs=101 i=./indat/dat3.csv    o=./outdat/out21x.csv
${pfxc}mhashavg -nfn f=1,2                         hs=101 i=./indat/dat3nfn.csv o=./outdat/out21nfn.csv
${pfxc}mhashavg -nfno f=数量,金額 hs=101 i=./indat/dat3.csv    o=./outdat/out21nfno.csv

#部分的にNULLが入っているもの,k=の指定なし-n
${pfxc}mhashavg      f=数量:数量平均,金額:金額平均 -n hs=101 i=./indat/dat3.csv    o=./outdat/out22.csv
${pfxc}mhashavg -x   f=1:数量平均,2:金額平均       -n hs=101 i=./indat/dat3.csv    o=./outdat/out22x.csv
${pfxc}mhashavg -nfn f=1,2                         -n hs=101 i=./indat/dat3nfn.csv o=./outdat/out22nfn.csv
${pfxc}mhashavg -nfno f=数量,金額 -n hs=101 i=./indat/dat3.csv    o=./outdat/out22nfno.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat3.csv    o=./outdat/out23.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       hs=101 i=./indat/dat3.csv    o=./outdat/out23x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         hs=101 i=./indat/dat3nfn.csv o=./outdat/out23nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 hs=101 i=./indat/dat3.csv    o=./outdat/out23nfno.csv

#部分的にNULLが入っているもの,k=指定一つ
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 -n hs=101 i=./indat/dat3.csv    o=./outdat/out24.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均,2:金額平均       -n hs=101 i=./indat/dat3.csv    o=./outdat/out24x.csv
${pfxc}mhashavg -nfn k=0    f=1,2                         -n hs=101 i=./indat/dat3nfn.csv o=./outdat/out24nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 -n hs=101 i=./indat/dat3.csv    o=./outdat/out24nfno.csv

#部分的にNULLが入っているもの,k=指定２つ
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat4.csv    o=./outdat/out25.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       hs=101 i=./indat/dat4.csv    o=./outdat/out25x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         hs=101 i=./indat/dat4nfn.csv o=./outdat/out25nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 hs=101 i=./indat/dat4.csv    o=./outdat/out25nfno.csv

#部分的にNULLが入っているもの,k=指定２つ,-n
${pfxc}mhashavg      k=顧客,日付 f=数量:数量平均,金額:金額平均 -n hs=101 i=./indat/dat4.csv    o=./outdat/out26.csv
${pfxc}mhashavg -x   k=0,1       f=2:数量平均,3:金額平均       -n hs=101 i=./indat/dat4.csv    o=./outdat/out26x.csv
${pfxc}mhashavg -nfn k=0,1       f=2,3                         -n hs=101 i=./indat/dat4nfn.csv o=./outdat/out26nfn.csv
${pfxc}mhashavg -nfno k=顧客,日付 f=数量,金額 -n hs=101 i=./indat/dat4.csv    o=./outdat/out26nfno.csv

#キー項目にNULL
${pfxc}mhashavg      k=顧客 f=数量:数量平均,金額:金額平均 hs=101 i=./indat/dat5.csv    o=./outdat/out27.csv
${pfxc}mhashavg -x   k=0    f=2:数量平均,3:金額平均       hs=101 i=./indat/dat5.csv    o=./outdat/out27x.csv
${pfxc}mhashavg -nfn k=0    f=2,3                         hs=101 i=./indat/dat5nfn.csv o=./outdat/out27nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量,金額 hs=101 i=./indat/dat5.csv    o=./outdat/out27nfno.csv

#precision=0指定
${pfxc}mhashavg      k=顧客 f=数量:数量平均 precision=0 i=./indat/dat1.csv     o=./outdat/out28.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均 precision=0 i=./indat/dat1.csv     o=./outdat/out28x.csv
${pfxc}mhashavg -nfn k=0    f=1 precision=0 i=./indat/dat1nfn.csv  o=./outdat/out28nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量 precision=0 i=./indat/dat1.csv o=./outdat/out28nfno.csv

#precision=1指定
${pfxc}mhashavg      k=顧客 f=数量:数量平均 precision=1 i=./indat/dat1.csv     o=./outdat/out29.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均 precision=1 i=./indat/dat1.csv     o=./outdat/out29x.csv
${pfxc}mhashavg -nfn k=0    f=1 precision=1 i=./indat/dat1nfn.csv  o=./outdat/out29nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量 precision=1 i=./indat/dat1.csv o=./outdat/out29nfno.csv

#precision=2指定
${pfxc}mhashavg      k=顧客 f=数量:数量平均 precision=2 i=./indat/dat1.csv     o=./outdat/out30.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均 precision=2 i=./indat/dat1.csv     o=./outdat/out30x.csv
${pfxc}mhashavg -nfn k=0    f=1 precision=2 i=./indat/dat1nfn.csv  o=./outdat/out30nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量 precision=2 i=./indat/dat1.csv o=./outdat/out30nfno.csv

#precision=100指定
${pfxc}mhashavg      k=顧客 f=数量:数量平均 precision=100 i=./indat/dat1.csv     o=./outdat/out31.csv
${pfxc}mhashavg -x   k=0    f=1:数量平均 precision=100 i=./indat/dat1.csv     o=./outdat/out31x.csv
${pfxc}mhashavg -nfn k=0    f=1 precision=100 i=./indat/dat1nfn.csv  o=./outdat/out31nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=数量 precision=100 i=./indat/dat1.csv o=./outdat/out31nfno.csv


#ソートデータ
${pfxc}mhashavg      k=顧客 f=金額:金額平均 i=./indat/dat1s.csv     o=./outdat/out32.csv
${pfxc}mhashavg -x   k=0    f=2:金額平均    i=./indat/dat1s.csv     o=./outdat/out32x.csv
${pfxc}mhashavg -nfn k=0    f=2             i=./indat/dat1snfn.csv  o=./outdat/out32nfn.csv
${pfxc}mhashavg -nfno k=顧客 f=金額 i=./indat/dat1s.csv     o=./outdat/out32nfno.csv
