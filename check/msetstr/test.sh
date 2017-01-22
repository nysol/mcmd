#!/bin/bash

. ../env

#name_kg_mcmd setstr

#NULL data
${pfxc}msetstr      v=20070101 a=基準日 i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}msetstr -x   v=20070101 a=基準日 i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}msetstr -nfn v=20070101          i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv

#基本
${pfxc}msetstr      v=20070101 a=基準日 i=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}msetstr -x   v=20070101 a=基準日 i=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}msetstr -nfn v=20070101          i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

#複数
${pfxc}msetstr      v=20070101,200701,2007 a=基準日,基準月,基準年 i=./indat/dat1.csv    o=./outdat/out2.csv
${pfxc}msetstr -x   v=20070101,200701,2007 a=基準日,基準月,基準年 i=./indat/dat1.csv    o=./outdat/out2x.csv
${pfxc}msetstr -nfn v=20070101,200701,2007                        i=./indat/dat1nfn.csv o=./outdat/out2nfn.csv



${pfxc}msetstr      v=20070101,200701,2007 a=基準日,基準月,基準年 i=./indat/dat1s.csv    o=./outdat/out3.csv
${pfxc}msetstr -x   v=20070101,200701,2007 a=基準日,基準月,基準年 i=./indat/dat1s.csv    o=./outdat/out3x.csv
${pfxc}msetstr -nfn v=20070101,200701,2007                        i=./indat/dat1snfn.csv o=./outdat/out3nfn.csv


${pfxc}msetstr      v=20070101,200701,2007 a=基準日,基準月,基準年 i=./indat/dat1ss.csv    o=./outdat/out4.csv
${pfxc}msetstr -x   v=20070101,200701,2007 a=基準日,基準月,基準年 i=./indat/dat1ss.csv    o=./outdat/out4x.csv
