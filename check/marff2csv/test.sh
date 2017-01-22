#!/bin/bash

. ../env
#name_kg_mcmd arff2csv

${pfxc}marff2csv       i=./indat/dat1.arff o=./outdat/out01.csv
${pfxc}marff2csv -x    i=./indat/dat1.arff o=./outdat/out01x.csv
${pfxc}marff2csv -nfn  i=./indat/dat1.arff o=./outdat/out01nfn.csv
${pfxc}marff2csv -nfno i=./indat/dat1.arff o=./outdat/out01nfno.csv

${pfxc}marff2csv       i=./indat/dat2.arff o=./outdat/out02.csv
${pfxc}marff2csv -x    i=./indat/dat2.arff o=./outdat/out02x.csv
${pfxc}marff2csv -nfn  i=./indat/dat2.arff o=./outdat/out02nfn.csv
${pfxc}marff2csv -nfno i=./indat/dat2.arff o=./outdat/out02nfno.csv
