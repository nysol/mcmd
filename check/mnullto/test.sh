#!/bin/bash
. ../env

#name_kg_mcmd nullto

#nullデータ
${pfxc}mnullto      f=生年月日:生年月日登録状況 v=値なし i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mnullto -x   f=1:生年月日登録状況        v=値なし i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mnullto -nfn f=1                         v=値なし i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況 v=値なし -A i=./indat/dat0.csv    o=./outdat/out1.csv
${pfxc}mnullto -x   f=1:生年月日登録状況        v=値なし -A i=./indat/dat0.csv    o=./outdat/out1x.csv
${pfxc}mnullto -nfn f=1                         v=値なし -A i=./indat/dat0nfn.csv o=./outdat/out1nfn.csv

#基本
${pfxc}mnullto      f=生年月日 v=値なし i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}mnullto -x   f=1        v=値なし i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}mnullto -nfn f=1        v=値なし i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv

${pfxc}mnullto      f=生年月日 v=値なし O=値あり i=./indat/dat1.csv    o=./outdat/out3.csv
${pfxc}mnullto -x   f=1        v=値なし O=値あり i=./indat/dat1.csv    o=./outdat/out3x.csv
${pfxc}mnullto -nfn f=1        v=値なし O=値あり i=./indat/dat1nfn.csv o=./outdat/out3nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況 v=値なし O=値あり i=./indat/dat1.csv    o=./outdat/out4.csv
${pfxc}mnullto -x   f=1:生年月日登録状況        v=値なし O=値あり i=./indat/dat1.csv    o=./outdat/out4x.csv
${pfxc}mnullto -nfn f=1                         v=値なし O=値あり i=./indat/dat1nfn.csv o=./outdat/out4nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況 v=値なし O=値あり -A i=./indat/dat1.csv    o=./outdat/out5.csv
${pfxc}mnullto -x   f=1:生年月日登録状況        v=値なし O=値あり -A i=./indat/dat1.csv    o=./outdat/out5x.csv
${pfxc}mnullto -nfn f=1                         v=値なし O=値あり -A i=./indat/dat1nfn.csv o=./outdat/out5nfn.csv

#f=複数
${pfxc}mnullto      f=生年月日,血液型 v=値なし i=./indat/dat2.csv    o=./outdat/out6.csv
${pfxc}mnullto -x   f=1,2             v=値なし i=./indat/dat2.csv    o=./outdat/out6x.csv
${pfxc}mnullto -nfn f=1,2             v=値なし i=./indat/dat2nfn.csv o=./outdat/out6nfn.csv

${pfxc}mnullto      f=生年月日,血液型 v=値なし O=値あり i=./indat/dat2.csv    o=./outdat/out7.csv
${pfxc}mnullto -x   f=1,2             v=値なし O=値あり i=./indat/dat2.csv    o=./outdat/out7x.csv
${pfxc}mnullto -nfn f=1,2             v=値なし O=値あり i=./indat/dat2nfn.csv o=./outdat/out7nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況,血液型:血液型登録状況 v=値なし O=値あり i=./indat/dat2.csv    o=./outdat/out8.csv
${pfxc}mnullto -x   f=1:生年月日登録状況,2:血液型登録状況             v=値なし O=値あり i=./indat/dat2.csv    o=./outdat/out8x.csv
${pfxc}mnullto -nfn f=1,2                                             v=値なし O=値あり i=./indat/dat2nfn.csv o=./outdat/out8nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況,血液型:血液型登録状況 v=値なし O=値あり -A i=./indat/dat2.csv    o=./outdat/out9.csv
${pfxc}mnullto -x   f=1:生年月日登録状況,2:血液型登録状況             v=値なし O=値あり -A i=./indat/dat2.csv    o=./outdat/out9x.csv
${pfxc}mnullto -nfn f=1,2                                             v=値なし O=値あり -A i=./indat/dat2nfn.csv o=./outdat/out9nfn.csv

# -p
${pfxc}mnullto      f=生年月日 -p i=./indat/dat1.csv    o=./outdat/out10.csv
${pfxc}mnullto -x   f=1        -p i=./indat/dat1.csv    o=./outdat/out10x.csv
${pfxc}mnullto -nfn f=1        -p i=./indat/dat1nfn.csv o=./outdat/out10nfn.csv

${pfxc}mnullto      f=生年月日 O=値あり -p i=./indat/dat1.csv    o=./outdat/out11.csv
${pfxc}mnullto -x   f=1        O=値あり -p i=./indat/dat1.csv    o=./outdat/out11x.csv
${pfxc}mnullto -nfn f=1        O=値あり -p i=./indat/dat1nfn.csv o=./outdat/out11nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況 O=値あり -p i=./indat/dat1.csv    o=./outdat/out12.csv
${pfxc}mnullto -x   f=1:生年月日登録状況        O=値あり -p i=./indat/dat1.csv    o=./outdat/out12x.csv
${pfxc}mnullto -nfn f=1                         O=値あり -p i=./indat/dat1nfn.csv o=./outdat/out12nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況 O=値あり -A -p i=./indat/dat1.csv    o=./outdat/out13.csv
${pfxc}mnullto -x   f=1:生年月日登録状況        O=値あり -A -p i=./indat/dat1.csv    o=./outdat/out13x.csv
${pfxc}mnullto -nfn f=1                         O=値あり -A -p i=./indat/dat1nfn.csv o=./outdat/out13nfn.csv



#ソートデータ

${pfxc}mnullto      f=生年月日,血液型 v=値なし i=./indat/dat2s.csv    o=./outdat/out16.csv
${pfxc}mnullto -x   f=1,2             v=値なし i=./indat/dat2s.csv    o=./outdat/out16x.csv
${pfxc}mnullto -nfn f=1,2             v=値なし i=./indat/dat2snfn.csv o=./outdat/out16nfn.csv

${pfxc}mnullto      f=生年月日,血液型 v=値なし O=値あり i=./indat/dat2s.csv    o=./outdat/out17.csv
${pfxc}mnullto -x   f=1,2             v=値なし O=値あり i=./indat/dat2s.csv    o=./outdat/out17x.csv
${pfxc}mnullto -nfn f=1,2             v=値なし O=値あり i=./indat/dat2snfn.csv o=./outdat/out17nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況,血液型:血液型登録状況 v=値なし O=値あり i=./indat/dat2s.csv    o=./outdat/out18.csv
${pfxc}mnullto -x   f=1:生年月日登録状況,2:血液型登録状況             v=値なし O=値あり i=./indat/dat2s.csv    o=./outdat/out18x.csv
${pfxc}mnullto -nfn f=1,2                                             v=値なし O=値あり i=./indat/dat2snfn.csv o=./outdat/out18nfn.csv

${pfxc}mnullto      f=生年月日:生年月日登録状況,血液型:血液型登録状況 v=値なし O=値あり -A i=./indat/dat2s.csv    o=./outdat/out19.csv
${pfxc}mnullto -x   f=1:生年月日登録状況,2:血液型登録状況             v=値なし O=値あり -A i=./indat/dat2s.csv    o=./outdat/out19x.csv
${pfxc}mnullto -nfn f=1,2                                             v=値なし O=値あり -A i=./indat/dat2snfn.csv o=./outdat/out19nfn.csv


