#!/bin/bash

. ../env
#name_kg_mcmd newrand

#基本
${pfxc}mnewrand      a=乱数 S=1 -int o=./outdat/out0.csv
${pfxc}mnewrand -x   a=乱数 S=1 -int o=./outdat/out0x.csv
${pfxc}mnewrand -nfn        S=1 -int o=./outdat/out0nfn.csv

#最小指定
${pfxc}mnewrand      a=乱数 S=1 min=10 -int o=./outdat/out1.csv 
${pfxc}mnewrand -x   a=乱数 S=1 min=10 -int o=./outdat/out1x.csv
${pfxc}mnewrand -nfn        S=1 min=10 -int o=./outdat/out1nfn.csv

#最大指定
${pfxc}mnewrand      a=乱数 S=1 max=20 -int o=./outdat/out2.csv
${pfxc}mnewrand -x   a=乱数 S=1 max=20 -int o=./outdat/out2x.csv
${pfxc}mnewrand -nfn        S=1 max=20 -int o=./outdat/out2nfn.csv

#最小、最大指定
${pfxc}mnewrand      a=乱数 S=1 min=10 max=20 -int o=./outdat/out3.csv
${pfxc}mnewrand -x   a=乱数 S=1 min=10 max=20 -int o=./outdat/out3x.csv
${pfxc}mnewrand -nfn        S=1 min=10 max=20 -int o=./outdat/out3nfn.csv

#ライン数指定
${pfxc}mnewrand      a=乱数 S=1 min=10 max=20 l=20 -int o=./outdat/out4.csv
${pfxc}mnewrand -x   a=乱数 S=1 min=10 max=20 l=20 -int o=./outdat/out4x.csv
${pfxc}mnewrand -nfn        S=1 min=10 max=20 l=20 -int o=./outdat/out4nfn.csv

#実数乱数
${pfxc}mnewrand      a=乱数 S=1  o=./outdat/out12.csv
${pfxc}mnewrand -x   a=乱数 S=1  o=./outdat/out12x.csv
${pfxc}mnewrand -nfn        S=1 o=./outdat/out12nfn.csv

${pfxc}mnewrand      a=乱数 S=1 l=20 o=./outdat/out13.csv
${pfxc}mnewrand -x   a=乱数 S=1 l=20  o=./outdat/out13x.csv
${pfxc}mnewrand -nfn        S=1 l=20 o=./outdat/out13nfn.csv

#seed指定なし
${pfxc}mnewrand      a=乱数 -int o=./outdat/out5.csv
${pfxc}mnewrand -x   a=乱数 -int o=./outdat/out5x.csv
${pfxc}mnewrand -nfn        -int o=./outdat/out5nfn.csv

${pfxc}mnewrand      a=乱数 min=10 -int o=./outdat/out6.csv
${pfxc}mnewrand -x   a=乱数 min=10 -int o=./outdat/out6x.csv
${pfxc}mnewrand -nfn        min=10 -int o=./outdat/out6nfn.csv

${pfxc}mnewrand      a=乱数 max=20 -int o=./outdat/out7.csv
${pfxc}mnewrand -x   a=乱数 max=20 -int o=./outdat/out7x.csv
${pfxc}mnewrand -nfn        max=20 -int o=./outdat/out7nfn.csv

${pfxc}mnewrand      a=乱数 min=10 max=20 -int o=./outdat/out8.csv
${pfxc}mnewrand -x   a=乱数 min=10 max=20 -int o=./outdat/out8x.csv
${pfxc}mnewrand -nfn        min=10 max=20 -int o=./outdat/out8nfn.csv

${pfxc}mnewrand      a=乱数 min=10 max=20 l=20 -int o=./outdat/out9.csv
${pfxc}mnewrand -x   a=乱数 min=10 max=20 l=20 -int o=./outdat/out9x.csv
${pfxc}mnewrand -nfn        min=10 max=20 l=20 -int o=./outdat/out9nfn.csv

${pfxc}mnewrand      a=乱数  o=./outdat/out10.csv
${pfxc}mnewrand -x   a=乱数  o=./outdat/out10x.csv
${pfxc}mnewrand -nfn        o=./outdat/out10nfn.csv

${pfxc}mnewrand      a=乱数 l=20 o=./outdat/out11.csv
${pfxc}mnewrand -x   a=乱数 l=20  o=./outdat/out11x.csv
${pfxc}mnewrand -nfn       l=20 o=./outdat/out11nfn.csv
