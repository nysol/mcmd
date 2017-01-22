#!/bin/bash

. ../env

#name_kg_mcmd chgstr

#NULLデータ
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mchgstr -x   f=1    c=01:A,03:B,05:C i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mchgstr -nfn f=1    c=01:A,03:B,05:C i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#基本
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mchgstr -x   f=0    c=01:A,03:B,05:C i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mchgstr -nfn f=0    c=01:A,03:B,05:C i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv
${pfxc}mchgstr -nfno f=商品 c=01:A,03:B,05:C i=./indat/dat1.csv    o=./outdat/out1nfno.csv

#O=使用
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C O=対象外 i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mchgstr -x   f=0    c=01:A,03:B,05:C O=対象外 i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mchgstr -nfn f=0    c=01:A,03:B,05:C O=対象外 i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv
${pfxc}mchgstr -nfno f=商品 c=01:A,03:B,05:C O=対象外 i=./indat/dat1.csv    o=./outdat/out2nfno.csv

#O=,-A使用
${pfxc}mchgstr      f=商品:商品情報 c=01:A,03:B,05:C O=対象外 -A i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mchgstr -x   f=0:商品情報    c=01:A,03:B,05:C O=対象外 -A i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mchgstr -nfn f=0             c=01:A,03:B,05:C O=対象外 -A i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv
${pfxc}mchgstr -nfno f=商品:商品情報 c=01:A,03:B,05:C O=対象外 -A i=./indat/dat1.csv    o=./outdat/out3nfno.csv

#-F使用
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C -F i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}mchgstr -x   f=0    c=01:A,03:B,05:C -F i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}mchgstr -nfn f=0    c=01:A,03:B,05:C -F i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv
${pfxc}mchgstr -nfno f=商品 c=01:A,03:B,05:C -F i=./indat/dat1.csv    o=./outdat/out4nfno.csv

#-sub使用
${pfxc}mchgstr      f=商品 c=01:A O=対象外 -sub i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mchgstr -x   f=0    c=01:A O=対象外 -sub i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mchgstr -nfn f=0    c=01:A O=対象外 -sub i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv
${pfxc}mchgstr -nfno f=商品 c=01:A O=対象外 -sub i=./indat/dat2.csv    o=./outdat/out5nfno.csv

#-sub,-w使用
${pfxc}mchgstr      f=商品 c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat3.csv    o=./outdat/out6.csv
${pfxc}mchgstr -x   f=0    c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat3.csv    o=./outdat/out6x.csv
${pfxc}mchgstr -nfn f=0    c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat3nfn.csv o=./outdat/out6nfn.csv
${pfxc}mchgstr -nfno f=商品 c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat3.csv    o=./outdat/out6nfno.csv

#f=複数
${pfxc}mchgstr      f=商品1,商品2 c=01:A,03:B,05:C i=./indat/dat4.csv    o=./outdat/out7.csv
${pfxc}mchgstr -x   f=0,1         c=01:A,03:B,05:C i=./indat/dat4.csv    o=./outdat/out7x.csv
${pfxc}mchgstr -nfn f=0,1         c=01:A,03:B,05:C i=./indat/dat4nfn.csv o=./outdat/out7nfn.csv

#f=複数,O=使用
${pfxc}mchgstr      f=商品1,商品2 c=01:A,03:B,05:C O=対象外 i=./indat/dat4.csv    o=./outdat/out8.csv
${pfxc}mchgstr -x   f=0,1         c=01:A,03:B,05:C O=対象外 i=./indat/dat4.csv    o=./outdat/out8x.csv
${pfxc}mchgstr -nfn f=0,1         c=01:A,03:B,05:C O=対象外 i=./indat/dat4nfn.csv o=./outdat/out8nfn.csv

#f=複数,O=,-A使用
${pfxc}mchgstr      f=商品1:商品情報1,商品2:商品情報2 c=01:A,03:B,05:C O=対象外 -A i=./indat/dat4.csv    o=./outdat/out9.csv
${pfxc}mchgstr -x   f=0:商品情報1,1:商品情報2         c=01:A,03:B,05:C O=対象外 -A i=./indat/dat4.csv    o=./outdat/out9x.csv
${pfxc}mchgstr -nfn f=0,1                             c=01:A,03:B,05:C O=対象外 -A i=./indat/dat4nfn.csv o=./outdat/out9nfn.csv

#f=複数,-F使用
${pfxc}mchgstr      f=商品1,商品2 c=01:A,03:B,05:C -F i=./indat/dat4.csv    o=./outdat/out10.csv
${pfxc}mchgstr -x   f=0,1         c=01:A,03:B,05:C -F i=./indat/dat4.csv    o=./outdat/out10x.csv
${pfxc}mchgstr -nfn f=0,1         c=01:A,03:B,05:C -F i=./indat/dat4nfn.csv o=./outdat/out10nfn.csv

#f=複数,O=,-sub使用
${pfxc}mchgstr      f=商品,金額 c=01:A,00:000 O=対象外 -sub i=./indat/dat2.csv    o=./outdat/out11.csv
${pfxc}mchgstr -x   f=0,1       c=01:A,00:000 O=対象外 -sub i=./indat/dat2.csv    o=./outdat/out11x.csv
${pfxc}mchgstr -nfn f=0,1       c=01:A,00:000 O=対象外 -sub i=./indat/dat2nfn.csv o=./outdat/out11nfn.csv

#f=複数,O=,-sub,-w使用
${pfxc}mchgstr      f=商品1,商品2 c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat5.csv    o=./outdat/out12.csv
${pfxc}mchgstr -x   f=0,1         c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat5.csv    o=./outdat/out12x.csv
${pfxc}mchgstr -nfn f=0,1         c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat5nfn.csv o=./outdat/out12nfn.csv

#NULLを部分的に含む
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C i=./indat/dat6.csv    o=./outdat/out13.csv
${pfxc}mchgstr -x   f=0    c=01:A,03:B,05:C i=./indat/dat6.csv    o=./outdat/out13x.csv
${pfxc}mchgstr -nfn f=0    c=01:A,03:B,05:C i=./indat/dat6nfn.csv o=./outdat/out13nfn.csv

#O=使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C O=対象外 i=./indat/dat6.csv    o=./outdat/out14.csv
${pfxc}mchgstr -x   f=0    c=01:A,03:B,05:C O=対象外 i=./indat/dat6.csv    o=./outdat/out14x.csv
${pfxc}mchgstr -nfn f=0    c=01:A,03:B,05:C O=対象外 i=./indat/dat6nfn.csv o=./outdat/out14nfn.csv

#O=,-A使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品:商品情報 c=01:A,03:B,05:C O=対象外 -A i=./indat/dat6.csv    o=./outdat/out15.csv
${pfxc}mchgstr -x   f=0:商品情報    c=01:A,03:B,05:C O=対象外 -A i=./indat/dat6.csv    o=./outdat/out15x.csv
${pfxc}mchgstr -nfn f=0             c=01:A,03:B,05:C O=対象外 -A i=./indat/dat6nfn.csv o=./outdat/out15nfn.csv

#-F使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品 c=01:A,03:B,05:C -F i=./indat/dat6.csv    o=./outdat/out16.csv
${pfxc}mchgstr -x   f=0    c=01:A,03:B,05:C -F i=./indat/dat6.csv    o=./outdat/out16x.csv
${pfxc}mchgstr -nfn f=0    c=01:A,03:B,05:C -F i=./indat/dat6nfn.csv o=./outdat/out16nfn.csv

#-sub使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品 c=01:A O=対象外 -sub i=./indat/dat7.csv    o=./outdat/out17.csv
${pfxc}mchgstr -x   f=0    c=01:A O=対象外 -sub i=./indat/dat7.csv    o=./outdat/out17x.csv
${pfxc}mchgstr -nfn f=0    c=01:A O=対象外 -sub i=./indat/dat7nfn.csv o=./outdat/out17nfn.csv

#-sub,-w使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品 c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat8.csv    o=./outdat/out18.csv
${pfxc}mchgstr -x   f=0    c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat8.csv    o=./outdat/out18x.csv
${pfxc}mchgstr -nfn f=0    c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat8nfn.csv o=./outdat/out18nfn.csv

#f=複数 NULLを部分的に含む
${pfxc}mchgstr      f=商品1,商品2 c=01:A,03:B,05:C i=./indat/dat9.csv    o=./outdat/out19.csv
${pfxc}mchgstr -x   f=0,1         c=01:A,03:B,05:C i=./indat/dat9.csv    o=./outdat/out19x.csv
${pfxc}mchgstr -nfn f=0,1         c=01:A,03:B,05:C i=./indat/dat9nfn.csv o=./outdat/out19nfn.csv

#f=複数,O=使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品1,商品2 c=01:A,03:B,05:C O=対象外 i=./indat/dat9.csv    o=./outdat/out20.csv
${pfxc}mchgstr -x   f=0,1         c=01:A,03:B,05:C O=対象外 i=./indat/dat9.csv    o=./outdat/out20x.csv
${pfxc}mchgstr -nfn f=0,1         c=01:A,03:B,05:C O=対象外 i=./indat/dat9nfn.csv o=./outdat/out20nfn.csv

#f=複数,O=,-A使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品1:商品情報1,商品2:商品情報2 c=01:A,03:B,05:C O=対象外 -A i=./indat/dat9.csv    o=./outdat/out21.csv
${pfxc}mchgstr -x   f=0:商品情報1,1:商品情報2         c=01:A,03:B,05:C O=対象外 -A i=./indat/dat9.csv    o=./outdat/out21x.csv
${pfxc}mchgstr -nfn f=0,1                             c=01:A,03:B,05:C O=対象外 -A i=./indat/dat9nfn.csv o=./outdat/out21nfn.csv

#f=複数,-F使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品1,商品2 c=01:A,03:B,05:C -F i=./indat/dat9.csv    o=./outdat/out22.csv
${pfxc}mchgstr -x   f=0,1         c=01:A,03:B,05:C -F i=./indat/dat9.csv    o=./outdat/out22x.csv
${pfxc}mchgstr -nfn f=0,1         c=01:A,03:B,05:C -F i=./indat/dat9nfn.csv o=./outdat/out22nfn.csv

#f=複数,O=,-sub使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品,金額 c=01:A,00:000 O=対象外 -sub i=./indat/dat7.csv    o=./outdat/out23.csv
${pfxc}mchgstr -x   f=0,1       c=01:A,00:000 O=対象外 -sub i=./indat/dat7.csv    o=./outdat/out23x.csv
${pfxc}mchgstr -nfn f=0,1       c=01:A,00:000 O=対象外 -sub i=./indat/dat7nfn.csv o=./outdat/out23nfn.csv

#f=複数,O=,-sub,-w使用 NULLを部分的に含む
${pfxc}mchgstr      f=商品1,商品2 c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat10.csv    o=./outdat/out24.csv
${pfxc}mchgstr -x   f=0,1         c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat10.csv    o=./outdat/out24x.csv
${pfxc}mchgstr -nfn f=0,1         c='柿:01,桃:02,葡萄:03' O=対象外 -sub -W i=./indat/dat10nfn.csv o=./outdat/out24nfn.csv

#f= (KG_MAX_STR_LEN 100000)
${pfxc}mchgstr      f=item c=abc:A,klm:B,no:C i=./indat/dat11.csv -sub O="not much"   o=./outdat/out25.csv
${pfxc}mchgstr -x   f=0    c=abc:A,klm:B,no:C i=./indat/dat11.csv -sub O="not much"   o=./outdat/out25x.csv
${pfxc}mchgstr -nfn f=0    c=abc:A,klm:B,no:C i=./indat/dat11nfn.csv -sub O="not much" o=./outdat/out25nfn.csv
${pfxc}mchgstr -nfno f=item c=abc:A,klm:B,no:C i=./indat/dat11.csv -sub O="not much"   o=./outdat/out25nfno.csv


