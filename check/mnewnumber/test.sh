#!/bin/bash

. ../env
#name_kg_mcmd newnumber

#基本
${pfxc}mnewnumber       a=追加 o=./outdat/out0.csv
${pfxc}mnewnumber -x    a=追加 o=./outdat/out0x.csv
${pfxc}mnewnumber -nfn         o=./outdat/out0nfn.csv
${pfxc}mnewnumber -nfno        o=./outdat/out0nfno.csv

#間隔指定
${pfxc}mnewnumber       a=追加 I=2 o=./outdat/out1.csv
${pfxc}mnewnumber -x    a=追加 I=2 o=./outdat/out1x.csv
${pfxc}mnewnumber -nfn         I=2 o=./outdat/out1nfn.csv
${pfxc}mnewnumber -nfno        I=2 o=./outdat/out1nfno.csv

#ライン指定
${pfxc}mnewnumber       a=追加 l=15 I=2 o=./outdat/out2.csv
${pfxc}mnewnumber -x    a=追加 l=15 I=2 o=./outdat/out2x.csv
${pfxc}mnewnumber -nfn         l=15 I=2 o=./outdat/out2nfn.csv
${pfxc}mnewnumber -nfno        l=15 I=2 o=./outdat/out2nfno.csv

#開始番号指定
${pfxc}mnewnumber       a=追加 l=20 I=2 S=20 o=./outdat/out3.csv
${pfxc}mnewnumber -x    a=追加 l=20 I=2 S=20 o=./outdat/out3x.csv
${pfxc}mnewnumber -nfn         l=20 I=2 S=20 o=./outdat/out3nfn.csv
${pfxc}mnewnumber -nfno        l=20 I=2 S=20 o=./outdat/out3nfno.csv

#アルファベット指定
${pfxc}mnewnumber       a=追加 S=A o=./outdat/out4.csv
${pfxc}mnewnumber -x    a=追加 S=A o=./outdat/out4x.csv
${pfxc}mnewnumber -nfn         S=A o=./outdat/out4nfn.csv
${pfxc}mnewnumber -nfno        S=A o=./outdat/out4nfno.csv

${pfxc}mnewnumber       a=追加 I=5 S=B o=./outdat/out5.csv
${pfxc}mnewnumber -x    a=追加 I=5 S=B o=./outdat/out5x.csv
${pfxc}mnewnumber -nfn         I=5 S=B o=./outdat/out5nfn.csv
${pfxc}mnewnumber -nfno        I=5 S=B o=./outdat/out5nfno.csv

${pfxc}mnewnumber       a=追加 I=3 l=15 S=B o=./outdat/out6.csv
${pfxc}mnewnumber -x    a=追加 I=3 l=15 S=B o=./outdat/out6x.csv
${pfxc}mnewnumber -nfn         I=3 l=15 S=B o=./outdat/out6nfn.csv
${pfxc}mnewnumber -nfno        I=3 l=15 S=B o=./outdat/out6nfno.csv

#paramaters error
#${pfxc}mnewnumber o=./outdat/out7.csv
#S= is digits or alphaz (kgNewnumber);
#${pfxc}mnewnumber -nfno        S=a o=./outdat/out8nfno.csv
