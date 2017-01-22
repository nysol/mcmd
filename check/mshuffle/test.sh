#!/bin/bash

. ../env
#name_kg_mcmd shuffle

#
${pfxc}mshuffle      f=店 n=3 i=./indat/dat1.csv    d=./outdat/out1
${pfxc}mshuffle -x   f=0  n=3 i=./indat/dat1.csv    d=./outdat/outx1
${pfxc}mshuffle -nfn f=0  n=3 i=./indat/dat1nfn.csv d=./outdat/outnfn1


${pfxc}mshuffle      f=細分類,店 n=3  i=./indat/dat1.csv    d=./outdat/out2
${pfxc}mshuffle -x   f=4,0      n=3  i=./indat/dat1.csv    d=./outdat/outx2
${pfxc}mshuffle -nfn f=4,0      n=3  i=./indat/dat1nfn.csv d=./outdat/outnfn2
