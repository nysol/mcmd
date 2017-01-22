#!/bin/bash

rm -rf ./outdat
mkdir -p ./outdat

touch out_endlog.txt
rm out_endlog.txt
bash test.sh > out_endlog.txt 2>&1  
