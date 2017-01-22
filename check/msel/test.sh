#!/bin/bash

. ../env

#name_kg_mcmd sel

#条件式に==を使ったVER.
${pfxc}msel      c='${金額}==500' i=./indat/dat.csv    o=./outdat/out01m.csv    u=./outdat/out01u.csv
${pfxc}msel -x   c='${6}==500'    i=./indat/dat.csv    o=./outdat/out01mx.csv   u=./outdat/out01ux.csv
${pfxc}msel -nfn c='${6}==500'    i=./indat/datnfn.csv o=./outdat/out01mnfn.csv u=./outdat/out01unfn.csv
${pfxc}msel -nfno c='${金額}==500'    i=./indat/dat.csv o=./outdat/out01mnfno.csv u=./outdat/out01unfno.csv


# u=なし
${pfxc}msel      c='${金額}==500' i=./indat/dat.csv    o=./outdat/out18m.csv

#-r
${pfxc}msel      -r c='${金額}==500' i=./indat/dat.csv    o=./outdat/out02m.csv    u=./outdat/out02u.csv
${pfxc}msel -x   -r c='${6}==500'    i=./indat/dat.csv    o=./outdat/out02mx.csv   u=./outdat/out02ux.csv
${pfxc}msel -nfn -r c='${6}==500'    i=./indat/datnfn.csv o=./outdat/out02mnfn.csv u=./outdat/out02unfn.csv
${pfxc}msel -nfno -r c='${金額}==500'    i=./indat/dat.csv o=./outdat/out02mnfno.csv u=./outdat/out02unfno.csv

#条件式に<を使ったVER．
${pfxc}msel      c='${金額}<500' i=./indat/dat.csv    o=./outdat/out03m.csv    u=./outdat/out03u.csv
${pfxc}msel -x   c='${6}<500'    i=./indat/dat.csv    o=./outdat/out03mx.csv   u=./outdat/out03ux.csv
${pfxc}msel -nfn c='${6}<500'    i=./indat/datnfn.csv o=./outdat/out03mnfn.csv u=./outdat/out03unfn.csv
${pfxc}msel -nfno c='${金額}<500'    i=./indat/dat.csv o=./outdat/out03mnfno.csv u=./outdat/out03unfno.csv

#条件式に<=を使ったVER．
${pfxc}msel      c='${金額}<=500' i=./indat/dat.csv    o=./outdat/out04m.csv    u=./outdat/out04u.csv
${pfxc}msel -x   c='${6}<=500'    i=./indat/dat.csv    o=./outdat/out04mx.csv   u=./outdat/out04ux.csv
${pfxc}msel -nfn c='${6}<=500'    i=./indat/datnfn.csv o=./outdat/out04mnfn.csv u=./outdat/out04unfn.csv
${pfxc}msel -nfno c='${金額}<=500'    i=./indat/dat.csv o=./outdat/out04mnfno.csv u=./outdat/out04unfno.csv

#条件式に>を使ったVER.
${pfxc}msel      c='${金額}>500' i=./indat/dat.csv    o=./outdat/out05m.csv    u=./outdat/out05u.csv
${pfxc}msel -x   c='${6}>500'    i=./indat/dat.csv    o=./outdat/out05mx.csv   u=./outdat/out05ux.csv
${pfxc}msel -nfn c='${6}>500'    i=./indat/datnfn.csv o=./outdat/out05mnfn.csv u=./outdat/out05unfn.csv
${pfxc}msel -nfno c='${金額}>500'    i=./indat/dat.csv o=./outdat/out05mnfno.csv u=./outdat/out05unfno.csv

#条件式に>=を使ったVER．
${pfxc}msel      c='${金額}>=500' i=./indat/dat.csv    o=./outdat/out06m.csv    u=./outdat/out06u.csv
${pfxc}msel -x   c='${6}>=500'    i=./indat/dat.csv    o=./outdat/out06mx.csv   u=./outdat/out06ux.csv
${pfxc}msel -nfn c='${6}>=500'    i=./indat/datnfn.csv o=./outdat/out06mnfn.csv u=./outdat/out06unfn.csv
${pfxc}msel -nfno c='${金額}>=500'    i=./indat/dat.csv o=./outdat/out06mnfno.csv u=./outdat/out06unfno.csv

#条件式に<>を使ったVER．
${pfxc}msel      c='${金額}!=500' i=./indat/dat.csv    o=./outdat/out07m.csv    u=./outdat/out07u.csv
${pfxc}msel -x   c='${6}!=500'    i=./indat/dat.csv    o=./outdat/out07mx.csv   u=./outdat/out07ux.csv
${pfxc}msel -nfn c='${6}!=500'    i=./indat/datnfn.csv o=./outdat/out07mnfn.csv u=./outdat/out07unfn.csv
${pfxc}msel -nfno c='${金額}!=500'    i=./indat/dat.csv o=./outdat/out07mnfno.csv u=./outdat/out07unfno.csv

#条件式に-eqを使ったVER．
${pfxc}msel      c='$s{金額}=="500"' i=./indat/dat.csv    o=./outdat/out08m.csv    u=./outdat/out08u.csv
${pfxc}msel -x   c='$s{6}=="500"'    i=./indat/dat.csv    o=./outdat/out08mx.csv   u=./outdat/out08ux.csv
${pfxc}msel -nfn c='$s{6}=="500"'    i=./indat/datnfn.csv o=./outdat/out08mnfn.csv u=./outdat/out08unfn.csv
${pfxc}msel -nfno c='$s{金額}=="500"'    i=./indat/dat.csv o=./outdat/out08mnfno.csv u=./outdat/out08unfno.csv

#条件式に-gtを使ったVER．
${pfxc}msel      c='$s{金額}>"500"' i=./indat/dat.csv    o=./outdat/out09m.csv    u=./outdat/out09u.csv
${pfxc}msel -x   c='$s{6}>"500"'    i=./indat/dat.csv    o=./outdat/out09mx.csv   u=./outdat/out09ux.csv
${pfxc}msel -nfn c='$s{6}>"500"'    i=./indat/datnfn.csv o=./outdat/out09mnfn.csv u=./outdat/out09unfn.csv
${pfxc}msel -nfno c='$s{金額}>"500"'    i=./indat/dat.csv o=./outdat/out09mnfno.csv u=./outdat/out09unfno.csv

#条件式に-geを使ったVER．
${pfxc}msel      c='$s{金額}>="500"' i=./indat/dat.csv    o=./outdat/out10m.csv    u=./outdat/out10u.csv
${pfxc}msel -x   c='$s{6}>="500"'    i=./indat/dat.csv    o=./outdat/out10mx.csv   u=./outdat/out10ux.csv
${pfxc}msel -nfn c='$s{6}>="500"'    i=./indat/datnfn.csv o=./outdat/out10mnfn.csv u=./outdat/out10unfn.csv
${pfxc}msel -nfno c='$s{金額}>="500"'    i=./indat/dat.csv o=./outdat/out10mnfno.csv u=./outdat/out10unfno.csv

#条件式に-ltを使ったVER．
${pfxc}msel      c='$s{金額}<"500"' i=./indat/dat.csv    o=./outdat/out11m.csv    u=./outdat/out11u.csv
${pfxc}msel -x   c='$s{6}<"500"'    i=./indat/dat.csv    o=./outdat/out11mx.csv   u=./outdat/out11ux.csv
${pfxc}msel -nfn c='$s{6}<"500"'    i=./indat/datnfn.csv o=./outdat/out11mnfn.csv u=./outdat/out11unfn.csv
${pfxc}msel -nfno c='$s{金額}<"500"'    i=./indat/dat.csv o=./outdat/out11mnfno.csv u=./outdat/out11unfno.csv

#条件式に-leを使ったVER．
${pfxc}msel      c='$s{金額}<"500"' i=./indat/dat.csv    o=./outdat/out12m.csv    u=./outdat/out12u.csv
${pfxc}msel -x   c='$s{6}<"500"'    i=./indat/dat.csv    o=./outdat/out12mx.csv   u=./outdat/out12ux.csv
${pfxc}msel -nfn c='$s{6}<"500"'    i=./indat/datnfn.csv o=./outdat/out12mnfn.csv u=./outdat/out12unfn.csv
${pfxc}msel -nfno c='$s{金額}<"500"'    i=./indat/dat.csv o=./outdat/out12mnfno.csv u=./outdat/out12unfno.csv

#条件式に-neを使ったVER．
${pfxc}msel      c='$s{金額}!="500"' i=./indat/dat.csv    o=./outdat/out13m.csv    u=./outdat/out13u.csv
${pfxc}msel -x   c='$s{6}!="500"'    i=./indat/dat.csv    o=./outdat/out13mx.csv   u=./outdat/out13ux.csv
${pfxc}msel -nfn c='$s{6}!="500"'    i=./indat/datnfn.csv o=./outdat/out13mnfn.csv u=./outdat/out13unfn.csv
${pfxc}msel -nfno c='$s{金額}!="500"'    i=./indat/dat.csv o=./outdat/out13mnfno.csv u=./outdat/out13unfno.csv

#条件式に||を使ったVER．
${pfxc}msel      c='$s{金額}<"300" || $s{金額}>="500"' i=./indat/dat.csv    o=./outdat/out14m.csv    u=./outdat/out14u.csv
${pfxc}msel -x   c='$s{6}<"300" || $s{6}>="500"'       i=./indat/dat.csv    o=./outdat/out14mx.csv   u=./outdat/out14ux.csv
${pfxc}msel -nfn c='$s{6}<"300" || $s{6}>="500"'       i=./indat/datnfn.csv o=./outdat/out14mnfn.csv u=./outdat/out14unfn.csv
${pfxc}msel -nfno c='$s{金額}<"300" || $s{金額}>="500"'       i=./indat/dat.csv o=./outdat/out14mnfno.csv u=./outdat/out14unfno.csv

# -r
${pfxc}msel      -r c='$s{金額}<"300" || $s{金額}>="500"' i=./indat/dat.csv    o=./outdat/out15m.csv    u=./outdat/out15u.csv
${pfxc}msel -x   -r c='$s{6}<"300" || $s{6}>="500"'       i=./indat/dat.csv    o=./outdat/out15mx.csv   u=./outdat/out15ux.csv
${pfxc}msel -nfn -r c='$s{6}<"300" || $s{6}>="500"'       i=./indat/datnfn.csv o=./outdat/out15mnfn.csv u=./outdat/out15unfn.csv
${pfxc}msel -nfno -r c='$s{金額}<"300" || $s{金額}>="500"'       i=./indat/dat.csv o=./outdat/out15mnfno.csv u=./outdat/out15unfno.csv

#条件式に&&を使ったVER．
${pfxc}msel      c='$s{金額}>"300" && $s{金額}<="500"' i=./indat/dat.csv    o=./outdat/out16m.csv    u=./outdat/out16u.csv
${pfxc}msel -x   c='$s{6}>"300" && $s{6}<="500"'       i=./indat/dat.csv    o=./outdat/out16mx.csv   u=./outdat/out16ux.csv
${pfxc}msel -nfn c='$s{6}>"300" && $s{6}<="500"'       i=./indat/datnfn.csv o=./outdat/out16mnfn.csv u=./outdat/out16unfn.csv
${pfxc}msel -nfno c='$s{金額}>"300" && $s{金額}<="500"'       i=./indat/dat.csv o=./outdat/out16mnfno.csv u=./outdat/out16unfno.csv

#-r 
${pfxc}msel      -r c='$s{金額}>"300" && $s{金額}<="500"' i=./indat/dat.csv    o=./outdat/out17m.csv    u=./outdat/out17u.csv
${pfxc}msel -x   -r c='$s{6}>"300" && $s{6}<="500"'       i=./indat/dat.csv    o=./outdat/out17mx.csv   u=./outdat/out17ux.csv
${pfxc}msel -nfn -r c='$s{6}>"300" && $s{6}<="500"'       i=./indat/datnfn.csv o=./outdat/out17mnfn.csv u=./outdat/out17unfn.csv
${pfxc}msel -nfno -r c='$s{金額}>"300" && $s{金額}<="500"'       i=./indat/dat.csv o=./outdat/out17mnfno.csv u=./outdat/out17unfno.csv

#ソートデータ
${pfxc}msel      c='${金額}<500' i=./indat/dats.csv    o=./outdat/out19.csv    u=./outdat/out19u.csv
${pfxc}msel -x   c='${6}<500'    i=./indat/dats.csv    o=./outdat/out19x.csv   u=./outdat/out19ux.csv

${pfxc}msel      -r c='${金額}<500' i=./indat/dats.csv    o=./outdat/out20.csv    u=./outdat/out20u.csv
${pfxc}msel -x   -r c='${6}<500'    i=./indat/dats.csv    o=./outdat/out20x.csv   u=./outdat/out20ux.csv




