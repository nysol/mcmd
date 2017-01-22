#!/bin/bash

. ../env
#name_kg_mcmd paste

# 基本(null data)
${pfxc}mpaste      m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out1.csv
${pfxc}mpaste -x   m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out1x.csv
${pfxc}mpaste -nfn m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

${pfxc}mpaste      -n m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out2.csv
${pfxc}mpaste -x   -n m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out2x.csv
${pfxc}mpaste -nfn -n m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out2nfn.csv

${pfxc}mpaste      -N m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out3.csv
${pfxc}mpaste -x   -N m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out3x.csv
${pfxc}mpaste -nfn -N m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out3nfn.csv

${pfxc}mpaste      -N -n m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out4.csv
${pfxc}mpaste -x   -N -n m=./indat/dat1.csv    i=./indat/dat0.csv    o=./outdat/out4x.csv
${pfxc}mpaste -nfn -N -n m=./indat/dat1nfn.csv i=./indat/dat0nfn.csv o=./outdat/out4nfn.csv

# 基本
${pfxc}mpaste       m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out5.csv
${pfxc}mpaste -x    m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out5x.csv
${pfxc}mpaste -nfn  m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out5nfn.csv
${pfxc}mpaste -nfno  m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out5nfno.csv

${pfxc}mpaste      -n m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mpaste -x   -n m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mpaste -nfn -n m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv
${pfxc}mpaste -nfno -n m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out6nfno.csv

${pfxc}mpaste      -N m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out7.csv
${pfxc}mpaste -x   -N m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out7x.csv
${pfxc}mpaste -nfn -N m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv
${pfxc}mpaste -nfno -N m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out7nfno.csv

${pfxc}mpaste      -N -n m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}mpaste -x   -N -n m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out8x.csv
${pfxc}mpaste -nfn -N -n m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv
${pfxc}mpaste -nfno -N -n m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out8nfno.csv

# i=とm=を逆に
${pfxc}mpaste      m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out9.csv
${pfxc}mpaste -x   m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out9x.csv
${pfxc}mpaste -nfn m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out9nfn.csv
${pfxc}mpaste -nfno m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out9nfno.csv

${pfxc}mpaste      -n m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out10.csv
${pfxc}mpaste -x   -n m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out10x.csv
${pfxc}mpaste -nfn -n m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out10nfn.csv
${pfxc}mpaste -nfno -n m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out10nfno.csv

${pfxc}mpaste      -N m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out11.csv
${pfxc}mpaste -x   -N m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out11x.csv
${pfxc}mpaste -nfn -N m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out11nfn.csv
${pfxc}mpaste -nfno -N m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out11nfno.csv

${pfxc}mpaste      -N -n m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out12.csv
${pfxc}mpaste -x   -N -n m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out12x.csv
${pfxc}mpaste -nfn -N -n m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out12nfn.csv
${pfxc}mpaste -nfno -N -n m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out12nfno.csv

# 項目指定
${pfxc}mpaste      f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out13.csv
${pfxc}mpaste -x   f=0,1             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out13x.csv
${pfxc}mpaste -nfn f=0,1             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out13nfn.csv
${pfxc}mpaste -nfno  f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out13nfno.csv

${pfxc}mpaste      -n f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out14.csv
${pfxc}mpaste -x   -n f=0,1             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out14x.csv
${pfxc}mpaste -nfn -n f=0,1             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out14nfn.csv
${pfxc}mpaste -nfno -n f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out14nfno.csv

${pfxc}mpaste      -N f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out15.csv
${pfxc}mpaste -x   -N f=0,1             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out15x.csv
${pfxc}mpaste -nfn -N f=0,1             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv
${pfxc}mpaste -nfno  -N f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out15nfno.csv

${pfxc}mpaste      -N -n f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out16.csv
${pfxc}mpaste -x   -N -n f=0,1             m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out16x.csv
${pfxc}mpaste -nfn -N -n f=0,1             m=./indat/dat3nfn.csv i=./indat/dat2nfn.csv o=./outdat/out16nfn.csv
${pfxc}mpaste -nfno -N -n f=仕入価格,在庫数 m=./indat/dat3.csv    i=./indat/dat2.csv    o=./outdat/out16nfno.csv

# i=とm=を逆に+項目指定
${pfxc}mpaste      f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out17.csv
${pfxc}mpaste -x   f=2    m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out17x.csv
${pfxc}mpaste -nfn f=2    m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out17nfn.csv
${pfxc}mpaste -nfno f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out17nfno.csv

${pfxc}mpaste      -n f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out18.csv
${pfxc}mpaste -x   -n f=2    m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out18x.csv
${pfxc}mpaste -nfn -n f=2    m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out18nfn.csv
${pfxc}mpaste -nfno -n f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out18nfno.csv

${pfxc}mpaste      -N f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out19.csv
${pfxc}mpaste -x   -N f=2    m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out19x.csv
${pfxc}mpaste -nfn -N f=2    m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out19nfn.csv
${pfxc}mpaste -nfno -N f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out19nfno.csv

${pfxc}mpaste      -N -n f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out20.csv
${pfxc}mpaste -x   -N -n f=2    m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out20x.csv
${pfxc}mpaste -nfn -N -n f=2    m=./indat/dat2nfn.csv i=./indat/dat3nfn.csv o=./outdat/out20nfn.csv
${pfxc}mpaste -nfno -N -n f=金額 m=./indat/dat2.csv    i=./indat/dat3.csv    o=./outdat/out20nfno.csv

#ソートデータ
${pfxc}mpaste       m=./indat/dat3.csv    i=./indat/dat2s.csv    o=./outdat/out21.csv
${pfxc}mpaste      f=金額 m=./indat/dat2s.csv    i=./indat/dat3.csv    o=./outdat/out22.csv

