#!/bin/bash

. ../env

#name_kg_mcmd tee

${pfxc}mtee      i=./indat/dat0.csv    o=./outdat/out01.csv,./outdat/out02.csv       >./outdat/out03.csv
${pfxc}mtee -x   i=./indat/dat0.csv    o=./outdat/out01x.csv,./outdat/out02x.csv     >./outdat/out03x.csv
${pfxc}mtee -nfn i=./indat/dat0nfn.csv o=./outdat/out01nfn.csv,./outdat/out02nfn.csv >./outdat/out03nfn.csv

${pfxc}mtee      i=./indat/dat1.csv    o=./outdat/out04.csv,./outdat/out05.csv       >./outdat/out06.csv
${pfxc}mtee -x   i=./indat/dat1.csv    o=./outdat/out04x.csv,./outdat/out05x.csv     >./outdat/out06x.csv
${pfxc}mtee -nfn i=./indat/dat1nfn.csv o=./outdat/out04nfn.csv,./outdat/out05nfn.csv >./outdat/out06nfn.csv

${pfxc}mtee      -nostdout i=./indat/dat1.csv    o=./outdat/out07.csv,./outdat/out08.csv,./outdat/out09.csv
${pfxc}mtee -x   -nostdout i=./indat/dat1.csv    o=./outdat/out07x.csv,./outdat/out08x.csv,./outdat/out09x.csv
${pfxc}mtee -nfn -nostdout i=./indat/dat1nfn.csv o=./outdat/out07nfn.csv,./outdat/out08nfn.csv,./outdat/out09nfn.csv


${pfxc}mtee      i=./indat/dat1s.csv    o=./outdat/out14.csv,./outdat/out15.csv       >./outdat/out16.csv
${pfxc}mtee -x   i=./indat/dat1s.csv    o=./outdat/out14x.csv,./outdat/out15x.csv     >./outdat/out16x.csv
${pfxc}mtee -nfn i=./indat/dat1snfn.csv o=./outdat/out14nfn.csv,./outdat/out15nfn.csv >./outdat/out16nfn.csv
