#!/bin/bash

. ../env

#name_kg_mcmd fsort

#nullデータ
${pfxc}mfsort f=i* 							i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mfsort f=i* -r						i=./indat/dat0.csv o=./outdat/out1.csv
${pfxc}mfsort f=i* -n						i=./indat/dat0.csv o=./outdat/out2.csv
${pfxc}mfsort f=i* -n -r				i=./indat/dat0.csv o=./outdat/out3.csv

#通常データ
${pfxc}mfsort f=i* 							i=./indat/dat1.csv o=./outdat/out4.csv
${pfxc}mfsort f=i* -r						i=./indat/dat1.csv o=./outdat/out5.csv
${pfxc}mfsort f=i* -n						i=./indat/dat1.csv o=./outdat/out6.csv
${pfxc}mfsort f=i* -n -r				i=./indat/dat1.csv o=./outdat/out7.csv



#通常データ
${pfxc}mfsort f=i* 							i=./indat/dat1s.csv o=./outdat/out8.csv
${pfxc}mfsort f=i* -r						i=./indat/dat1s.csv o=./outdat/out9.csv
${pfxc}mfsort f=i* -n						i=./indat/dat1s.csv o=./outdat/out10.csv
${pfxc}mfsort f=i* -n -r				i=./indat/dat1s.csv o=./outdat/out11.csv
