#!/bin/bash

. ../env

#name_kg_mcmd sep

#NULL
${pfxc}msep      d=./outdat/'${日付}.csv' i=./indat/dat0s.csv
${pfxc}msep -x   d=./outdat/'${1}x.csv'   i=./indat/dat0s.csv
${pfxc}msep -nfn d=./outdat/'${1}nfn.csv' i=./indat/dat0snfn.csv

#基本
${pfxc}msep      d=./outdat/'out${日付}.csv' i=./indat/dat1s.csv
${pfxc}msep -x   d=./outdat/'out${1}x.csv'   i=./indat/dat1s.csv
${pfxc}msep -nfn d=./outdat/'out${1}nfn.csv' i=./indat/dat1snfn.csv
${pfxc}msep -q     d=./outdat/'out${日付}q.csv' i=./indat/dat1s.csv
${pfxc}msep -q -x   d=./outdat/'out${1}qx.csv'   i=./indat/dat1s.csv

${pfxc}msep      d=./outdat/'out-${商品}-${日付}.csv' i=./indat/dat2s.csv
${pfxc}msep -x   d=./outdat/'out-${0}-${1}x.csv'      i=./indat/dat2s.csv
${pfxc}msep -nfn d=./outdat/'out-${0}-${1}nfn.csv'    i=./indat/dat2snfn.csv

#-p使用
${pfxc}msep      d=./outdat/'${商品}/out${日付}.csv' -p i=./indat/dat2s.csv
${pfxc}msep -x   d=./outdat/'${0}/out${1}x.csv'      -p i=./indat/dat2s.csv
${pfxc}msep -nfn d=./outdat/'${0}/out${1}nfn.csv'    -p i=./indat/dat2snfn.csv



#基本
${pfxc}msep      d=./outdat/'outr${日付}.csv' i=./indat/dat1.csv
${pfxc}msep -x   d=./outdat/'outr${1}x.csv'   i=./indat/dat1.csv
${pfxc}msep -nfn d=./outdat/'outr${1}nfn.csv' i=./indat/dat1nfn.csv
${pfxc}msep -q     d=./outdat/'outr${日付}q.csv' i=./indat/dat1.csv
${pfxc}msep -q -x   d=./outdat/'outr${1}qx.csv'   i=./indat/dat1.csv

${pfxc}msep      d=./outdat/'outr-${商品}-${日付}.csv' i=./indat/dat2.csv
${pfxc}msep -x   d=./outdat/'outr-${0}-${1}x.csv'      i=./indat/dat2.csv
${pfxc}msep -nfn d=./outdat/'outr-${0}-${1}nfn.csv'    i=./indat/dat2nfn.csv

#-p使用
${pfxc}msep      d=./outdat/'${商品}/outr${日付}.csv' -p i=./indat/dat2.csv
${pfxc}msep -x   d=./outdat/'${0}/outr${1}x.csv'      -p i=./indat/dat2.csv
${pfxc}msep -nfn d=./outdat/'${0}/outr${1}nfn.csv'    -p i=./indat/dat2nfn.csv
