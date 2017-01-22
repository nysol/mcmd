#!/bin/bash

. ../env

#name_kg_mcmd newstr

#基本
${pfxc}mnewstr      a=文字列1 v=顧客No o=./outdat/out1.csv
${pfxc}mnewstr -x   a=文字列1 v=顧客No o=./outdat/out1x.csv
${pfxc}mnewstr -nfn           v=顧客No o=./outdat/out1nfn.csv

#行数指定
${pfxc}mnewstr      a=文字列1 v=顧客No l=20 o=./outdat/out2.csv
${pfxc}mnewstr -x   a=文字列1 v=顧客No l=20 o=./outdat/out2x.csv
${pfxc}mnewstr -nfn           v=顧客No l=20 o=./outdat/out2nfn.csv

#複数指定
${pfxc}mnewstr      a=文字列1,文字列2 v=顧客No,A0001 o=./outdat/out3.csv
${pfxc}mnewstr -x   a=文字列1,文字列2 v=顧客No,A0001 o=./outdat/out3x.csv
${pfxc}mnewstr -nfn                   v=顧客No,A0001 o=./outdat/out3nfn.csv

${pfxc}mnewstr      a=文字列1,文字列2 v=顧客No,A0001 l=15 o=./outdat/out4.csv
${pfxc}mnewstr -x   a=文字列1,文字列2 v=顧客No,A0001 l=15 o=./outdat/out4x.csv
${pfxc}mnewstr -nfn                   v=顧客No,A0001 l=15 o=./outdat/out4nfn.csv
