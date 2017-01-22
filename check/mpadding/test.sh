#!/bin/bash

. ../env
#name_kg_mcmd padding

#null data
${pfxc}mpadding       k=a f=b%n      i=./indat/dat0.csv    o=./outdat/out0.csv
${pfxc}mpadding -x    k=0 f=1%n      i=./indat/dat0.csv    o=./outdat/out0x.csv
${pfxc}mpadding -nfn  k=0 f=1%n      i=./indat/dat0nfn.csv    o=./outdat/out0nfn.csv
${pfxc}mpadding -nfno k=a f=b%n      i=./indat/dat0.csv    o=./outdat/out0nfno.csv


#int
${pfxc}mpadding f=b%n                      i=./indat/dat13s.csv         o=./outdat/out10.csv
${pfxc}mpadding f=1%n                      i=./indat/dat13s.csv -x      o=./outdat/out10x.csv
${pfxc}mpadding f=1%n                      i=./indat/dat13snfn.csv -nfn o=./outdat/out10nfn.csv

${pfxc}mpadding f=b%n -n                   i=./indat/dat13s.csv         o=./outdat/out11.csv
${pfxc}mpadding f=1%n -n                   i=./indat/dat13s.csv -x      o=./outdat/out11x.csv
${pfxc}mpadding f=1%n -n                   i=./indat/dat13snfn.csv -nfn o=./outdat/out11nfn.csv


${pfxc}mpadding f=b%n v=padding            i=./indat/dat13s.csv    o=./outdat/out12.csv
${pfxc}mpadding f=1%n v=padding            i=./indat/dat13s.csv -x    o=./outdat/out12x.csv
${pfxc}mpadding f=1%n v=padding            i=./indat/dat13snfn.csv -nfn   o=./outdat/out12nfn.csv


${pfxc}mpadding f=b%n S=-1 E=11            i=./indat/dat13s.csv    o=./outdat/out13.csv
${pfxc}mpadding f=1%n S=-1 E=11            i=./indat/dat13s.csv -x   o=./outdat/out13x.csv
${pfxc}mpadding f=1%n S=-1 E=11            i=./indat/dat13snfn.csv -nfn   o=./outdat/out13nfn.csv

${pfxc}mpadding f=b%n S=-1                 i=./indat/dat13s.csv    o=./outdat/out14.csv
${pfxc}mpadding f=1%n S=-1                 i=./indat/dat13s.csv -x   o=./outdat/out14x.csv
${pfxc}mpadding f=1%n S=-1                 i=./indat/dat13snfn.csv -nfn   o=./outdat/out14nfn.csv

${pfxc}mpadding f=b%n E=11                 i=./indat/dat13s.csv    o=./outdat/out15.csv
${pfxc}mpadding f=1%n E=11                 i=./indat/dat13s.csv -x    o=./outdat/out15x.csv
${pfxc}mpadding f=1%n E=11                 i=./indat/dat13snfn.csv -nfn   o=./outdat/out15nfn.csv

${pfxc}mpadding f=b%n S=1 E=10             i=./indat/dat13s.csv    o=./outdat/out16.csv
${pfxc}mpadding f=1%n S=1 E=10             i=./indat/dat13s.csv -x    o=./outdat/out16x.csv
${pfxc}mpadding f=1%n S=1 E=10             i=./indat/dat13snfn.csv -nfn   o=./outdat/out16nfn.csv

${pfxc}mpadding f=b%n S=1                  i=./indat/dat13s.csv    o=./outdat/out17.csv
${pfxc}mpadding f=1%n S=1                  i=./indat/dat13s.csv -x   o=./outdat/out17x.csv
${pfxc}mpadding f=1%n S=1                  i=./indat/dat13snfn.csv -nfn   o=./outdat/out17nfn.csv

${pfxc}mpadding f=b%n E=10                 i=./indat/dat13s.csv    o=./outdat/out18.csv
${pfxc}mpadding f=1%n E=10                 i=./indat/dat13s.csv -x   o=./outdat/out18x.csv
${pfxc}mpadding f=1%n E=10                 i=./indat/dat13snfn.csv -nfn   o=./outdat/out18nfn.csv

${pfxc}mpadding f=b%n S=-1 E=11 -n         i=./indat/dat13s.csv    o=./outdat/out19.csv
${pfxc}mpadding f=1%n S=-1 E=11 -n         i=./indat/dat13s.csv -x   o=./outdat/out19x.csv
${pfxc}mpadding f=1%n S=-1 E=11 -n         i=./indat/dat13snfn.csv -nfn   o=./outdat/out19nfn.csv

${pfxc}mpadding f=b%n S=-1 E=11 v=padding  i=./indat/dat13s.csv    o=./outdat/out20.csv
${pfxc}mpadding f=1%n S=-1 E=11 v=padding  i=./indat/dat13s.csv -x   o=./outdat/out20x.csv
${pfxc}mpadding f=1%n S=-1 E=11 v=padding  i=./indat/dat13snfn.csv -nfn   o=./outdat/out20nfn.csv

${pfxc}mpadding f=b%n S=1 E=10 -n          i=./indat/dat13s.csv    o=./outdat/out21.csv
${pfxc}mpadding f=1%n S=1 E=10 -n          i=./indat/dat13s.csv -x   o=./outdat/out21x.csv
${pfxc}mpadding f=1%n S=1 E=10 -n          i=./indat/dat13snfn.csv -nfn   o=./outdat/out21nfn.csv

${pfxc}mpadding f=b%n S=1 E=10 v=padding   i=./indat/dat13s.csv    o=./outdat/out22.csv
${pfxc}mpadding f=1%n S=1 E=10 v=padding   i=./indat/dat13s.csv -x   o=./outdat/out22x.csv
${pfxc}mpadding f=1%n S=1 E=10 v=padding   i=./indat/dat13snfn.csv -nfn   o=./outdat/out22nfn.csv

${pfxc}mpadding f=b%nr                     i=./indat/dat13sr.csv    o=./outdat/out23.csv
${pfxc}mpadding f=1%nr                     i=./indat/dat13sr.csv -x    o=./outdat/out23x.csv
${pfxc}mpadding f=1%nr                     i=./indat/dat13srnfn.csv -nfn   o=./outdat/out23nfn.csv

${pfxc}mpadding f=b%nr -n                  i=./indat/dat13sr.csv    o=./outdat/out24.csv
${pfxc}mpadding f=1%nr -n                  i=./indat/dat13sr.csv -x   o=./outdat/out24x.csv
${pfxc}mpadding f=1%nr -n                  i=./indat/dat13srnfn.csv -nfn   o=./outdat/out24nfn.csv

${pfxc}mpadding f=b%nr v=padding           i=./indat/dat13sr.csv    o=./outdat/out25.csv
${pfxc}mpadding f=1%nr v=padding           i=./indat/dat13sr.csv -x   o=./outdat/out25x.csv
${pfxc}mpadding f=1%nr v=padding           i=./indat/dat13srnfn.csv -nfn   o=./outdat/out25nfn.csv

${pfxc}mpadding f=b%nr E=-1 S=11           i=./indat/dat13sr.csv    o=./outdat/out26.csv
${pfxc}mpadding f=1%nr E=-1 S=11           i=./indat/dat13sr.csv -x   o=./outdat/out26x.csv
${pfxc}mpadding f=1%nr E=-1 S=11           i=./indat/dat13srnfn.csv -nfn   o=./outdat/out26nfn.csv

${pfxc}mpadding f=b%nr E=-1                i=./indat/dat13sr.csv    o=./outdat/out27.csv
${pfxc}mpadding f=1%nr E=-1                i=./indat/dat13sr.csv -x   o=./outdat/out27x.csv
${pfxc}mpadding f=1%nr E=-1                i=./indat/dat13srnfn.csv -nfn   o=./outdat/out27nfn.csv

${pfxc}mpadding f=b%nr S=11                i=./indat/dat13sr.csv    o=./outdat/out28.csv
${pfxc}mpadding f=1%nr S=11                i=./indat/dat13sr.csv -x   o=./outdat/out28x.csv
${pfxc}mpadding f=1%nr S=11                i=./indat/dat13srnfn.csv -nfn   o=./outdat/out28nfn.csv

${pfxc}mpadding f=b%nr E=1 S=10            i=./indat/dat13sr.csv    o=./outdat/out29.csv
${pfxc}mpadding f=1%nr E=1 S=10            i=./indat/dat13sr.csv -x   o=./outdat/out29x.csv
${pfxc}mpadding f=1%nr E=1 S=10            i=./indat/dat13srnfn.csv -nfn   o=./outdat/out29nfn.csv

${pfxc}mpadding f=b%nr E=1                 i=./indat/dat13sr.csv    o=./outdat/out30.csv
${pfxc}mpadding f=1%nr E=1                 i=./indat/dat13sr.csv -x   o=./outdat/out30x.csv
${pfxc}mpadding f=1%nr E=1                 i=./indat/dat13srnfn.csv -nfn   o=./outdat/out30nfn.csv

${pfxc}mpadding f=b%nr S=10                i=./indat/dat13sr.csv    o=./outdat/out31.csv
${pfxc}mpadding f=1%nr S=10                i=./indat/dat13sr.csv -x   o=./outdat/out31x.csv
${pfxc}mpadding f=1%nr S=10                i=./indat/dat13srnfn.csv -nfn   o=./outdat/out31nfn.csv

${pfxc}mpadding f=b%nr E=-1 S=11 -n        i=./indat/dat13sr.csv    o=./outdat/out32.csv
${pfxc}mpadding f=1%nr E=-1 S=11 -n        i=./indat/dat13sr.csv -x   o=./outdat/out32x.csv
${pfxc}mpadding f=1%nr E=-1 S=11 -n        i=./indat/dat13srnfn.csv -nfn   o=./outdat/out32nfn.csv

${pfxc}mpadding f=b%nr E=-1 S=11 v=padding i=./indat/dat13sr.csv    o=./outdat/out33.csv
${pfxc}mpadding f=1%nr E=-1 S=11 v=padding i=./indat/dat13sr.csv -x   o=./outdat/out33x.csv
${pfxc}mpadding f=1%nr E=-1 S=11 v=padding i=./indat/dat13srnfn.csv -nfn   o=./outdat/out33nfn.csv

${pfxc}mpadding f=b%nr E=1 S=10 -n         i=./indat/dat13sr.csv    o=./outdat/out34.csv
${pfxc}mpadding f=1%nr E=1 S=10 -n         i=./indat/dat13sr.csv -x   o=./outdat/out34x.csv
${pfxc}mpadding f=1%nr E=1 S=10 -n         i=./indat/dat13srnfn.csv -nfn   o=./outdat/out34nfn.csv

${pfxc}mpadding f=b%nr E=1 S=10 v=padding  i=./indat/dat13sr.csv    o=./outdat/out35.csv
${pfxc}mpadding f=1%nr E=1 S=10 v=padding  i=./indat/dat13sr.csv -x   o=./outdat/out35x.csv
${pfxc}mpadding f=1%nr E=1 S=10 v=padding  i=./indat/dat13srnfn.csv -nfn   o=./outdat/out35nfn.csv

#date
${pfxc}mpadding f=b%d                                 i=./indat/dat15s.csv    o=./outdat/out36.csv
${pfxc}mpadding f=1%d                                 i=./indat/dat15s.csv -x   o=./outdat/out36x.csv
${pfxc}mpadding f=1%d                                 i=./indat/dat15snfn.csv -nfn   o=./outdat/out36nfn.csv

${pfxc}mpadding f=b%d -n                              i=./indat/dat15s.csv    o=./outdat/out37.csv
${pfxc}mpadding f=1%d -n                              i=./indat/dat15s.csv -x   o=./outdat/out37x.csv
${pfxc}mpadding f=1%d -n                              i=./indat/dat15snfn.csv -nfn   o=./outdat/out37nfn.csv

${pfxc}mpadding f=b%d v=padding                       i=./indat/dat15s.csv    o=./outdat/out38.csv
${pfxc}mpadding f=1%d v=padding                       i=./indat/dat15s.csv -x   o=./outdat/out38x.csv
${pfxc}mpadding f=1%d v=padding                       i=./indat/dat15snfn.csv -nfn   o=./outdat/out38nfn.csv

${pfxc}mpadding f=b%d S=20100930 E=20101020           i=./indat/dat15s.csv    o=./outdat/out39.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020           i=./indat/dat15s.csv -x   o=./outdat/out39x.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020           i=./indat/dat15snfn.csv -nfn   o=./outdat/out39nfn.csv

${pfxc}mpadding f=b%d S=20100930                      i=./indat/dat15s.csv    o=./outdat/out40.csv
${pfxc}mpadding f=1%d S=20100930                      i=./indat/dat15s.csv -x   o=./outdat/out40x.csv
${pfxc}mpadding f=1%d S=20100930                      i=./indat/dat15snfn.csv -nfn   o=./outdat/out40nfn.csv

${pfxc}mpadding f=b%d E=20101020                      i=./indat/dat15s.csv    o=./outdat/out41.csv
${pfxc}mpadding f=1%d E=20101020                      i=./indat/dat15s.csv -x   o=./outdat/out41x.csv
${pfxc}mpadding f=1%d E=20101020                      i=./indat/dat15snfn.csv -nfn   o=./outdat/out41nfn.csv

${pfxc}mpadding f=b%d S=20101001 E=20101017           i=./indat/dat15s.csv    o=./outdat/out42.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017           i=./indat/dat15s.csv -x   o=./outdat/out42x.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017           i=./indat/dat15snfn.csv -nfn   o=./outdat/out42nfn.csv

${pfxc}mpadding f=b%d S=20101001                      i=./indat/dat15s.csv    o=./outdat/out43.csv
${pfxc}mpadding f=1%d S=20101001                      i=./indat/dat15s.csv -x   o=./outdat/out43x.csv
${pfxc}mpadding f=1%d S=20101001                      i=./indat/dat15snfn.csv -nfn   o=./outdat/out43nfn.csv

${pfxc}mpadding f=b%d E=20101017                      i=./indat/dat15s.csv    o=./outdat/out44.csv
${pfxc}mpadding f=1%d E=20101017                      i=./indat/dat15s.csv -x   o=./outdat/out44x.csv
${pfxc}mpadding f=1%d E=20101017                      i=./indat/dat15snfn.csv -nfn   o=./outdat/out44nfn.csv

${pfxc}mpadding f=b%d S=20100930 E=20101020 -n        i=./indat/dat15s.csv    o=./outdat/out45.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 -n        i=./indat/dat15s.csv -x   o=./outdat/out45x.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 -n        i=./indat/dat15snfn.csv -nfn   o=./outdat/out45nfn.csv

${pfxc}mpadding f=b%d S=20100930 E=20101020 v=padding i=./indat/dat15s.csv    o=./outdat/out46.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 v=padding i=./indat/dat15s.csv -x   o=./outdat/out46x.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 v=padding i=./indat/dat15snfn.csv -nfn   o=./outdat/out46nfn.csv

${pfxc}mpadding f=b%d S=20101001 E=20101017 -n        i=./indat/dat15s.csv    o=./outdat/out47.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 -n        i=./indat/dat15s.csv -x   o=./outdat/out47x.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 -n        i=./indat/dat15snfn.csv -nfn   o=./outdat/out47nfn.csv

${pfxc}mpadding f=b%d S=20101001 E=20101017 v=padding i=./indat/dat15s.csv    o=./outdat/out48.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 v=padding i=./indat/dat15s.csv -x   o=./outdat/out48x.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 v=padding i=./indat/dat15snfn.csv -nfn   o=./outdat/out48nfn.csv

${pfxc}mpadding f=b%dr                                 i=./indat/dat15sr.csv    o=./outdat/out49.csv
${pfxc}mpadding f=1%dr                                 i=./indat/dat15sr.csv -x   o=./outdat/out49x.csv
${pfxc}mpadding f=1%dr                                 i=./indat/dat15srnfn.csv -nfn   o=./outdat/out49nfn.csv

${pfxc}mpadding f=b%dr -n                              i=./indat/dat15sr.csv    o=./outdat/out50.csv
${pfxc}mpadding f=1%dr -n                              i=./indat/dat15sr.csv -x   o=./outdat/out50x.csv
${pfxc}mpadding f=1%dr -n                              i=./indat/dat15srnfn.csv -nfn   o=./outdat/out50nfn.csv

${pfxc}mpadding f=b%dr v=padding                       i=./indat/dat15sr.csv    o=./outdat/out51.csv
${pfxc}mpadding f=1%dr v=padding                       i=./indat/dat15sr.csv -x   o=./outdat/out51x.csv
${pfxc}mpadding f=1%dr v=padding                       i=./indat/dat15srnfn.csv -nfn   o=./outdat/out51nfn.csv

${pfxc}mpadding f=b%dr S=20101020 E=20100930           i=./indat/dat15sr.csv    o=./outdat/out52.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930           i=./indat/dat15sr.csv -x   o=./outdat/out52x.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930           i=./indat/dat15srnfn.csv -nfn   o=./outdat/out52nfn.csv

${pfxc}mpadding f=b%dr S=20101020                      i=./indat/dat15sr.csv    o=./outdat/out53.csv
${pfxc}mpadding f=1%dr S=20101020                      i=./indat/dat15sr.csv -x   o=./outdat/out53x.csv
${pfxc}mpadding f=1%dr S=20101020                      i=./indat/dat15srnfn.csv -nfn   o=./outdat/out53nfn.csv

${pfxc}mpadding f=b%dr E=20100930                      i=./indat/dat15sr.csv    o=./outdat/out54.csv
${pfxc}mpadding f=1%dr E=20100930                      i=./indat/dat15sr.csv -x   o=./outdat/out54x.csv
${pfxc}mpadding f=1%dr E=20100930                      i=./indat/dat15srnfn.csv -nfn   o=./outdat/out54nfn.csv

${pfxc}mpadding f=b%dr S=20101017 E=20101001           i=./indat/dat15sr.csv    o=./outdat/out55.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001           i=./indat/dat15sr.csv -x   o=./outdat/out55x.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001           i=./indat/dat15srnfn.csv -nfn   o=./outdat/out55nfn.csv

${pfxc}mpadding f=b%dr S=20101017                      i=./indat/dat15sr.csv    o=./outdat/out56.csv
${pfxc}mpadding f=1%dr S=20101017                      i=./indat/dat15sr.csv -x   o=./outdat/out56x.csv
${pfxc}mpadding f=1%dr S=20101017                      i=./indat/dat15srnfn.csv -nfn   o=./outdat/out56nfn.csv

${pfxc}mpadding f=b%dr E=20101001                      i=./indat/dat15sr.csv    o=./outdat/out57.csv
${pfxc}mpadding f=1%dr E=20101001                      i=./indat/dat15sr.csv -x   o=./outdat/out57x.csv
${pfxc}mpadding f=1%dr E=20101001                      i=./indat/dat15srnfn.csv -nfn   o=./outdat/out57nfn.csv

${pfxc}mpadding f=b%dr S=20101020 E=20100930 -n        i=./indat/dat15sr.csv    o=./outdat/out58.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 -n        i=./indat/dat15sr.csv -x   o=./outdat/out58x.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 -n        i=./indat/dat15srnfn.csv -nfn   o=./outdat/out58nfn.csv

${pfxc}mpadding f=b%dr S=20101020 E=20100930 v=padding i=./indat/dat15sr.csv    o=./outdat/out59.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 v=padding i=./indat/dat15sr.csv -x   o=./outdat/out59x.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 v=padding i=./indat/dat15srnfn.csv -nfn   o=./outdat/out59nfn.csv

${pfxc}mpadding f=b%dr S=20101017 E=20101001 -n        i=./indat/dat15sr.csv    o=./outdat/out60.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 -n        i=./indat/dat15sr.csv -x   o=./outdat/out60x.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 -n        i=./indat/dat15srnfn.csv -nfn   o=./outdat/out60nfn.csv

${pfxc}mpadding f=b%dr S=20101017 E=20101001 v=padding i=./indat/dat15sr.csv    o=./outdat/out61.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 v=padding i=./indat/dat15sr.csv -x   o=./outdat/out61x.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 v=padding i=./indat/dat15srnfn.csv -nfn   o=./outdat/out61nfn.csv

#time
${pfxc}mpadding f=b%t                             i=./indat/dat17s.csv    o=./outdat/out62.csv
${pfxc}mpadding f=1%t                             i=./indat/dat17s.csv -x   o=./outdat/out62x.csv
${pfxc}mpadding f=1%t                             i=./indat/dat17snfn.csv -nfn   o=./outdat/out62nfn.csv

${pfxc}mpadding f=b%t -n                          i=./indat/dat17s.csv    o=./outdat/out63.csv
${pfxc}mpadding f=1%t -n                          i=./indat/dat17s.csv -x   o=./outdat/out63x.csv
${pfxc}mpadding f=1%t -n                          i=./indat/dat17snfn.csv -nfn   o=./outdat/out63nfn.csv

${pfxc}mpadding f=b%t v=padding                   i=./indat/dat17s.csv    o=./outdat/out64.csv
${pfxc}mpadding f=1%t v=padding                   i=./indat/dat17s.csv -x   o=./outdat/out64x.csv
${pfxc}mpadding f=1%t v=padding                   i=./indat/dat17snfn.csv -nfn   o=./outdat/out64nfn.csv

${pfxc}mpadding f=b%t S=101048 E=101111           i=./indat/dat17s.csv    o=./outdat/out65.csv
${pfxc}mpadding f=1%t S=101048 E=101111           i=./indat/dat17s.csv -x   o=./outdat/out65x.csv
${pfxc}mpadding f=1%t S=101048 E=101111           i=./indat/dat17snfn.csv -nfn   o=./outdat/out65nfn.csv

${pfxc}mpadding f=b%t S=101048                    i=./indat/dat17s.csv    o=./outdat/out66.csv
${pfxc}mpadding f=1%t S=101048                    i=./indat/dat17s.csv -x   o=./outdat/out66x.csv
${pfxc}mpadding f=1%t S=101048                    i=./indat/dat17snfn.csv -nfn   o=./outdat/out66nfn.csv

${pfxc}mpadding f=b%t E=101111                    i=./indat/dat17s.csv    o=./outdat/out67.csv
${pfxc}mpadding f=1%t E=101111                    i=./indat/dat17s.csv -x   o=./outdat/out67x.csv
${pfxc}mpadding f=1%t E=101111                    i=./indat/dat17snfn.csv -nfn   o=./outdat/out67nfn.csv

${pfxc}mpadding f=b%t S=101050 E=101109           i=./indat/dat17s.csv    o=./outdat/out68.csv
${pfxc}mpadding f=1%t S=101050 E=101109           i=./indat/dat17s.csv -x   o=./outdat/out68x.csv
${pfxc}mpadding f=1%t S=101050 E=101109           i=./indat/dat17snfn.csv -nfn   o=./outdat/out68nfn.csv

${pfxc}mpadding f=b%t S=101050                    i=./indat/dat17s.csv    o=./outdat/out69.csv
${pfxc}mpadding f=1%t S=101050                    i=./indat/dat17s.csv -x   o=./outdat/out69x.csv
${pfxc}mpadding f=1%t S=101050                    i=./indat/dat17snfn.csv -nfn   o=./outdat/out69nfn.csv

${pfxc}mpadding f=b%t E=101109                    i=./indat/dat17s.csv    o=./outdat/out70.csv
${pfxc}mpadding f=1%t E=101109                    i=./indat/dat17s.csv -x   o=./outdat/out70x.csv
${pfxc}mpadding f=1%t E=101109                    i=./indat/dat17snfn.csv -nfn   o=./outdat/out70nfn.csv

${pfxc}mpadding f=b%t S=101048 E=101111 -n        i=./indat/dat17s.csv    o=./outdat/out71.csv
${pfxc}mpadding f=1%t S=101048 E=101111 -n        i=./indat/dat17s.csv -x   o=./outdat/out71x.csv
${pfxc}mpadding f=1%t S=101048 E=101111 -n        i=./indat/dat17snfn.csv -nfn   o=./outdat/out71nfn.csv

${pfxc}mpadding f=b%t S=101048 E=101111 v=padding i=./indat/dat17s.csv    o=./outdat/out72.csv
${pfxc}mpadding f=1%t S=101048 E=101111 v=padding i=./indat/dat17s.csv -x   o=./outdat/out72x.csv
${pfxc}mpadding f=1%t S=101048 E=101111 v=padding i=./indat/dat17snfn.csv -nfn   o=./outdat/out72nfn.csv

${pfxc}mpadding f=b%t S=101050 E=101109 -n        i=./indat/dat17s.csv    o=./outdat/out73.csv
${pfxc}mpadding f=1%t S=101050 E=101109 -n        i=./indat/dat17s.csv -x   o=./outdat/out73x.csv
${pfxc}mpadding f=1%t S=101050 E=101109 -n        i=./indat/dat17snfn.csv -nfn   o=./outdat/out73nfn.csv

${pfxc}mpadding f=b%t S=101050 E=101109 v=padding i=./indat/dat17s.csv    o=./outdat/out74.csv
${pfxc}mpadding f=1%t S=101050 E=101109 v=padding i=./indat/dat17s.csv -x   o=./outdat/out74x.csv
${pfxc}mpadding f=1%t S=101050 E=101109 v=padding i=./indat/dat17snfn.csv -nfn   o=./outdat/out74nfn.csv

${pfxc}mpadding f=b%tr                              i=./indat/dat17sr.csv    o=./outdat/out75.csv
${pfxc}mpadding f=1%tr                              i=./indat/dat17sr.csv -x   o=./outdat/out75x.csv
${pfxc}mpadding f=1%tr                              i=./indat/dat17srnfn.csv -nfn   o=./outdat/out75nfn.csv

${pfxc}mpadding f=b%tr -n                           i=./indat/dat17sr.csv    o=./outdat/out76.csv
${pfxc}mpadding f=1%tr -n                           i=./indat/dat17sr.csv -x   o=./outdat/out76x.csv
${pfxc}mpadding f=1%tr -n                           i=./indat/dat17srnfn.csv -nfn   o=./outdat/out76nfn.csv

${pfxc}mpadding f=b%tr v=padding                    i=./indat/dat17sr.csv    o=./outdat/out77.csv
${pfxc}mpadding f=1%tr v=padding                    i=./indat/dat17sr.csv -x   o=./outdat/out77x.csv
${pfxc}mpadding f=1%tr v=padding                    i=./indat/dat17srnfn.csv -nfn   o=./outdat/out77nfn.csv

${pfxc}mpadding f=b%tr S=101111 E=101048            i=./indat/dat17sr.csv    o=./outdat/out78.csv
${pfxc}mpadding f=1%tr S=101111 E=101048            i=./indat/dat17sr.csv -x   o=./outdat/out78x.csv
${pfxc}mpadding f=1%tr S=101111 E=101048            i=./indat/dat17srnfn.csv -nfn   o=./outdat/out78nfn.csv

${pfxc}mpadding f=b%tr S=101111                     i=./indat/dat17sr.csv    o=./outdat/out79.csv
${pfxc}mpadding f=1%tr S=101111                     i=./indat/dat17sr.csv -x   o=./outdat/out79x.csv
${pfxc}mpadding f=1%tr S=101111                     i=./indat/dat17srnfn.csv -nfn   o=./outdat/out79nfn.csv

${pfxc}mpadding f=b%tr E=101048                     i=./indat/dat17sr.csv    o=./outdat/out80.csv
${pfxc}mpadding f=1%tr E=101048                     i=./indat/dat17sr.csv -x   o=./outdat/out80x.csv
${pfxc}mpadding f=1%tr E=101048                     i=./indat/dat17srnfn.csv -nfn   o=./outdat/out80nfn.csv

${pfxc}mpadding f=b%tr S=101109 E=101050            i=./indat/dat17sr.csv    o=./outdat/out81.csv
${pfxc}mpadding f=1%tr S=101109 E=101050            i=./indat/dat17sr.csv -x   o=./outdat/out81x.csv
${pfxc}mpadding f=1%tr S=101109 E=101050            i=./indat/dat17srnfn.csv -nfn   o=./outdat/out81nfn.csv

${pfxc}mpadding f=b%tr S=101109                     i=./indat/dat17sr.csv    o=./outdat/out82.csv
${pfxc}mpadding f=1%tr S=101109                     i=./indat/dat17sr.csv -x   o=./outdat/out82x.csv
${pfxc}mpadding f=1%tr S=101109                     i=./indat/dat17srnfn.csv -nfn   o=./outdat/out82nfn.csv

${pfxc}mpadding f=b%tr E=101050                     i=./indat/dat17sr.csv    o=./outdat/out83.csv
${pfxc}mpadding f=1%tr E=101050                     i=./indat/dat17sr.csv -x   o=./outdat/out83x.csv
${pfxc}mpadding f=1%tr E=101050                     i=./indat/dat17srnfn.csv -nfn   o=./outdat/out83nfn.csv

${pfxc}mpadding f=b%tr S=101111 E=101048 -n         i=./indat/dat17sr.csv    o=./outdat/out84.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 -n         i=./indat/dat17sr.csv -x   o=./outdat/out84x.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 -n         i=./indat/dat17srnfn.csv -nfn   o=./outdat/out84nfn.csv

${pfxc}mpadding f=b%tr S=101111 E=101048 v=padding  i=./indat/dat17sr.csv    o=./outdat/out85.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 v=padding  i=./indat/dat17sr.csv -x   o=./outdat/out85x.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 v=padding  i=./indat/dat17srnfn.csv -nfn   o=./outdat/out85nfn.csv

${pfxc}mpadding f=b%tr S=101109 E=101050 -n         i=./indat/dat17sr.csv    o=./outdat/out86.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 -n         i=./indat/dat17sr.csv -x   o=./outdat/out86x.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 -n         i=./indat/dat17srnfn.csv -nfn   o=./outdat/out86nfn.csv

${pfxc}mpadding f=b%tr S=101109 E=101050 v=padding  i=./indat/dat17sr.csv    o=./outdat/out87.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 v=padding  i=./indat/dat17sr.csv -x   o=./outdat/out87x.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 v=padding  i=./indat/dat17srnfn.csv -nfn   o=./outdat/out87nfn.csv


#ここまでoK
#k=有り
#int
${pfxc}mpadding k=a f=b%n                      i=./indat/dat14s.csv         o=./outdat/out90.csv
${pfxc}mpadding k=0 f=1%n                      i=./indat/dat14s.csv -x      o=./outdat/out90x.csv
${pfxc}mpadding k=0 f=1%n                      i=./indat/dat14snfn.csv -nfn o=./outdat/out90nfn.csv

${pfxc}mpadding k=a f=b%n -n                   i=./indat/dat14s.csv         o=./outdat/out91.csv
${pfxc}mpadding k=0 f=1%n -n                   i=./indat/dat14s.csv -x      o=./outdat/out91x.csv
${pfxc}mpadding k=0 f=1%n -n                   i=./indat/dat14snfn.csv -nfn o=./outdat/out91nfn.csv


${pfxc}mpadding k=a f=b%n v=padding            i=./indat/dat14s.csv    o=./outdat/out92.csv
${pfxc}mpadding k=0 f=1%n v=padding            i=./indat/dat14s.csv -x    o=./outdat/out92x.csv
${pfxc}mpadding k=0 f=1%n v=padding            i=./indat/dat14snfn.csv -nfn   o=./outdat/out92nfn.csv


${pfxc}mpadding k=a f=b%n S=-1 E=11            i=./indat/dat14s.csv    o=./outdat/out93.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11            i=./indat/dat14s.csv -x   o=./outdat/out93x.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11            i=./indat/dat14snfn.csv -nfn   o=./outdat/out93nfn.csv

${pfxc}mpadding k=a f=b%n S=-1                 i=./indat/dat14s.csv    o=./outdat/out94.csv
${pfxc}mpadding k=0 f=1%n S=-1                 i=./indat/dat14s.csv -x   o=./outdat/out94x.csv
${pfxc}mpadding k=0 f=1%n S=-1                 i=./indat/dat14snfn.csv -nfn   o=./outdat/out94nfn.csv

${pfxc}mpadding k=a f=b%n E=11                 i=./indat/dat14s.csv    o=./outdat/out95.csv
${pfxc}mpadding k=0 f=1%n E=11                 i=./indat/dat14s.csv -x    o=./outdat/out95x.csv
${pfxc}mpadding k=0 f=1%n E=11                 i=./indat/dat14snfn.csv -nfn   o=./outdat/out95nfn.csv

${pfxc}mpadding k=a f=b%n S=1 E=10             i=./indat/dat14s.csv    o=./outdat/out96.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10             i=./indat/dat14s.csv -x    o=./outdat/out96x.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10             i=./indat/dat14snfn.csv -nfn   o=./outdat/out96nfn.csv

${pfxc}mpadding k=a f=b%n S=1                  i=./indat/dat14s.csv    o=./outdat/out97.csv
${pfxc}mpadding k=0 f=1%n S=1                  i=./indat/dat14s.csv -x   o=./outdat/out97x.csv
${pfxc}mpadding k=0 f=1%n S=1                  i=./indat/dat14snfn.csv -nfn   o=./outdat/out97nfn.csv

${pfxc}mpadding k=a f=b%n E=10                 i=./indat/dat14s.csv    o=./outdat/out98.csv
${pfxc}mpadding k=0 f=1%n E=10                 i=./indat/dat14s.csv -x   o=./outdat/out98x.csv
${pfxc}mpadding k=0 f=1%n E=10                 i=./indat/dat14snfn.csv -nfn   o=./outdat/out98nfn.csv

${pfxc}mpadding k=a f=b%n S=-1 E=11 -n         i=./indat/dat14s.csv    o=./outdat/out99.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 -n         i=./indat/dat14s.csv -x   o=./outdat/out99x.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 -n         i=./indat/dat14snfn.csv -nfn   o=./outdat/out99nfn.csv

${pfxc}mpadding k=a f=b%n S=-1 E=11 v=padding  i=./indat/dat14s.csv    o=./outdat/out100.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 v=padding  i=./indat/dat14s.csv -x   o=./outdat/out100x.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 v=padding  i=./indat/dat14snfn.csv -nfn   o=./outdat/out100nfn.csv

${pfxc}mpadding k=a f=b%n S=1 E=10 -n          i=./indat/dat14s.csv    o=./outdat/out101.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 -n          i=./indat/dat14s.csv -x   o=./outdat/out101x.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 -n          i=./indat/dat14snfn.csv -nfn   o=./outdat/out101nfn.csv

${pfxc}mpadding k=a f=b%n S=1 E=10 v=padding   i=./indat/dat14s.csv    o=./outdat/out102.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 v=padding   i=./indat/dat14s.csv -x   o=./outdat/out102x.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 v=padding   i=./indat/dat14snfn.csv -nfn   o=./outdat/out102nfn.csv

${pfxc}mpadding k=a f=b%nr                     i=./indat/dat14sr.csv    o=./outdat/out103.csv
${pfxc}mpadding k=0 f=1%nr                     i=./indat/dat14sr.csv -x    o=./outdat/out103x.csv
${pfxc}mpadding k=0 f=1%nr                     i=./indat/dat14srnfn.csv -nfn   o=./outdat/out103nfn.csv

${pfxc}mpadding k=a f=b%nr -n                  i=./indat/dat14sr.csv    o=./outdat/out104.csv
${pfxc}mpadding k=0 f=1%nr -n                  i=./indat/dat14sr.csv -x   o=./outdat/out104x.csv
${pfxc}mpadding k=0 f=1%nr -n                  i=./indat/dat14srnfn.csv -nfn   o=./outdat/out104nfn.csv

${pfxc}mpadding k=a f=b%nr v=padding           i=./indat/dat14sr.csv    o=./outdat/out105.csv
${pfxc}mpadding k=0 f=1%nr v=padding           i=./indat/dat14sr.csv -x   o=./outdat/out105x.csv
${pfxc}mpadding k=0 f=1%nr v=padding           i=./indat/dat14srnfn.csv -nfn   o=./outdat/out105nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1 S=11           i=./indat/dat14sr.csv    o=./outdat/out106.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11           i=./indat/dat14sr.csv -x   o=./outdat/out106x.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11           i=./indat/dat14srnfn.csv -nfn   o=./outdat/out106nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1                i=./indat/dat14sr.csv    o=./outdat/out107.csv
${pfxc}mpadding k=0 f=1%nr E=-1                i=./indat/dat14sr.csv -x   o=./outdat/out107x.csv
${pfxc}mpadding k=0 f=1%nr E=-1                i=./indat/dat14srnfn.csv -nfn   o=./outdat/out107nfn.csv

${pfxc}mpadding k=a f=b%nr S=11                i=./indat/dat14sr.csv    o=./outdat/out108.csv
${pfxc}mpadding k=0 f=1%nr S=11                i=./indat/dat14sr.csv -x   o=./outdat/out108x.csv
${pfxc}mpadding k=0 f=1%nr S=11                i=./indat/dat14srnfn.csv -nfn   o=./outdat/out108nfn.csv

${pfxc}mpadding k=a f=b%nr E=1 S=10            i=./indat/dat14sr.csv    o=./outdat/out109.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10            i=./indat/dat14sr.csv -x   o=./outdat/out109x.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10            i=./indat/dat14srnfn.csv -nfn   o=./outdat/out109nfn.csv

${pfxc}mpadding k=a f=b%nr E=1                 i=./indat/dat14sr.csv    o=./outdat/out110.csv
${pfxc}mpadding k=0 f=1%nr E=1                 i=./indat/dat14sr.csv -x   o=./outdat/out110x.csv
${pfxc}mpadding k=0 f=1%nr E=1                 i=./indat/dat14srnfn.csv -nfn   o=./outdat/out110nfn.csv

${pfxc}mpadding k=a f=b%nr S=10                i=./indat/dat14sr.csv    o=./outdat/out111.csv
${pfxc}mpadding k=0 f=1%nr S=10                i=./indat/dat14sr.csv -x   o=./outdat/out111x.csv
${pfxc}mpadding k=0 f=1%nr S=10                i=./indat/dat14srnfn.csv -nfn   o=./outdat/out111nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1 S=11 -n        i=./indat/dat14sr.csv    o=./outdat/out112.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 -n        i=./indat/dat14sr.csv -x   o=./outdat/out112x.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 -n        i=./indat/dat14srnfn.csv -nfn   o=./outdat/out112nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1 S=11 v=padding i=./indat/dat14sr.csv    o=./outdat/out113.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 v=padding i=./indat/dat14sr.csv -x   o=./outdat/out113x.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 v=padding i=./indat/dat14srnfn.csv -nfn   o=./outdat/out113nfn.csv

${pfxc}mpadding k=a f=b%nr E=1 S=10 -n         i=./indat/dat14sr.csv    o=./outdat/out114.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 -n         i=./indat/dat14sr.csv -x   o=./outdat/out114x.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 -n         i=./indat/dat14srnfn.csv -nfn   o=./outdat/out114nfn.csv

${pfxc}mpadding k=a f=b%nr E=1 S=10 v=padding  i=./indat/dat14sr.csv    o=./outdat/out115.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 v=padding  i=./indat/dat14sr.csv -x   o=./outdat/out115x.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 v=padding  i=./indat/dat14srnfn.csv -nfn   o=./outdat/out115nfn.csv

#date
${pfxc}mpadding k=a f=b%d                                 i=./indat/dat16s.csv    o=./outdat/out116.csv
${pfxc}mpadding k=0 f=1%d                                 i=./indat/dat16s.csv -x   o=./outdat/out116x.csv
${pfxc}mpadding k=0 f=1%d                                 i=./indat/dat16snfn.csv -nfn   o=./outdat/out116nfn.csv

${pfxc}mpadding k=a f=b%d -n                              i=./indat/dat16s.csv    o=./outdat/out117.csv
${pfxc}mpadding k=0 f=1%d -n                              i=./indat/dat16s.csv -x   o=./outdat/out117x.csv
${pfxc}mpadding k=0 f=1%d -n                              i=./indat/dat16snfn.csv -nfn   o=./outdat/out117nfn.csv

${pfxc}mpadding k=a f=b%d v=padding                       i=./indat/dat16s.csv    o=./outdat/out118.csv
${pfxc}mpadding k=0 f=1%d v=padding                       i=./indat/dat16s.csv -x   o=./outdat/out118x.csv
${pfxc}mpadding k=0 f=1%d v=padding                       i=./indat/dat16snfn.csv -nfn   o=./outdat/out118nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024 E=20131107           i=./indat/dat16s.csv    o=./outdat/out119.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107           i=./indat/dat16s.csv -x   o=./outdat/out119x.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107           i=./indat/dat16snfn.csv -nfn   o=./outdat/out119nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024                      i=./indat/dat16s.csv    o=./outdat/out120.csv
${pfxc}mpadding k=0 f=1%d S=20131024                      i=./indat/dat16s.csv -x   o=./outdat/out120x.csv
${pfxc}mpadding k=0 f=1%d S=20131024                      i=./indat/dat16snfn.csv -nfn   o=./outdat/out120nfn.csv

${pfxc}mpadding k=a f=b%d E=20131107                      i=./indat/dat16s.csv    o=./outdat/out121.csv
${pfxc}mpadding k=0 f=1%d E=20131107                      i=./indat/dat16s.csv -x   o=./outdat/out121x.csv
${pfxc}mpadding k=0 f=1%d E=20131107                      i=./indat/dat16snfn.csv -nfn   o=./outdat/out121nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101 E=20131103           i=./indat/dat16s.csv    o=./outdat/out122.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103           i=./indat/dat16s.csv -x   o=./outdat/out122x.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103           i=./indat/dat16snfn.csv -nfn   o=./outdat/out122nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101                      i=./indat/dat16s.csv    o=./outdat/out123.csv
${pfxc}mpadding k=0 f=1%d S=20131101                      i=./indat/dat16s.csv -x   o=./outdat/out123x.csv
${pfxc}mpadding k=0 f=1%d S=20131101                      i=./indat/dat16snfn.csv -nfn   o=./outdat/out123nfn.csv

${pfxc}mpadding k=a f=b%d E=20131103                      i=./indat/dat16s.csv    o=./outdat/out124.csv
${pfxc}mpadding k=0 f=1%d E=20131103                      i=./indat/dat16s.csv -x   o=./outdat/out124x.csv
${pfxc}mpadding k=0 f=1%d E=20131103                      i=./indat/dat16snfn.csv -nfn   o=./outdat/out124nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024 E=20131107 -n        i=./indat/dat16s.csv    o=./outdat/out125.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 -n        i=./indat/dat16s.csv -x   o=./outdat/out125x.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 -n        i=./indat/dat16snfn.csv -nfn   o=./outdat/out125nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024 E=20131107 v=padding i=./indat/dat16s.csv    o=./outdat/out126.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 v=padding i=./indat/dat16s.csv -x   o=./outdat/out126x.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 v=padding i=./indat/dat16snfn.csv -nfn   o=./outdat/out126nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101 E=20131103 -n        i=./indat/dat16s.csv    o=./outdat/out127.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 -n        i=./indat/dat16s.csv -x   o=./outdat/out127x.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 -n        i=./indat/dat16snfn.csv -nfn   o=./outdat/out127nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101 E=20131103 v=padding i=./indat/dat16s.csv    o=./outdat/out128.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 v=padding i=./indat/dat16s.csv -x   o=./outdat/out128x.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 v=padding i=./indat/dat16snfn.csv -nfn   o=./outdat/out128nfn.csv

${pfxc}mpadding k=a f=b%dr                                 i=./indat/dat16sr.csv    o=./outdat/out129.csv
${pfxc}mpadding k=0 f=1%dr                                 i=./indat/dat16sr.csv -x   o=./outdat/out129x.csv
${pfxc}mpadding k=0 f=1%dr                                 i=./indat/dat16srnfn.csv -nfn   o=./outdat/out129nfn.csv

${pfxc}mpadding k=a f=b%dr -n                              i=./indat/dat16sr.csv    o=./outdat/out130.csv
${pfxc}mpadding k=0 f=1%dr -n                              i=./indat/dat16sr.csv -x   o=./outdat/out130x.csv
${pfxc}mpadding k=0 f=1%dr -n                              i=./indat/dat16srnfn.csv -nfn   o=./outdat/out130nfn.csv

${pfxc}mpadding k=a f=b%dr v=padding                       i=./indat/dat16sr.csv    o=./outdat/out131.csv
${pfxc}mpadding k=0 f=1%dr v=padding                       i=./indat/dat16sr.csv -x   o=./outdat/out131x.csv
${pfxc}mpadding k=0 f=1%dr v=padding                       i=./indat/dat16srnfn.csv -nfn   o=./outdat/out131nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107 E=20131024           i=./indat/dat16sr.csv    o=./outdat/out132.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024           i=./indat/dat16sr.csv -x   o=./outdat/out132x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024           i=./indat/dat16srnfn.csv -nfn   o=./outdat/out132nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107                      i=./indat/dat16sr.csv    o=./outdat/out133.csv
${pfxc}mpadding k=0 f=1%dr S=20131107                      i=./indat/dat16sr.csv -x   o=./outdat/out133x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107                      i=./indat/dat16srnfn.csv -nfn   o=./outdat/out133nfn.csv

${pfxc}mpadding k=a f=b%dr E=20131024                      i=./indat/dat16sr.csv    o=./outdat/out134.csv
${pfxc}mpadding k=0 f=1%dr E=20131024                      i=./indat/dat16sr.csv -x   o=./outdat/out134x.csv
${pfxc}mpadding k=0 f=1%dr E=20131024                      i=./indat/dat16srnfn.csv -nfn   o=./outdat/out134nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103 E=20131101           i=./indat/dat16sr.csv    o=./outdat/out135.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101           i=./indat/dat16sr.csv -x   o=./outdat/out135x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101           i=./indat/dat16srnfn.csv -nfn   o=./outdat/out135nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103                      i=./indat/dat16sr.csv    o=./outdat/out136.csv
${pfxc}mpadding k=0 f=1%dr S=20131103                      i=./indat/dat16sr.csv -x   o=./outdat/out136x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103                      i=./indat/dat16srnfn.csv -nfn   o=./outdat/out136nfn.csv

${pfxc}mpadding k=a f=b%dr E=20131101                      i=./indat/dat16sr.csv    o=./outdat/out137.csv
${pfxc}mpadding k=0 f=1%dr E=20131101                      i=./indat/dat16sr.csv -x   o=./outdat/out137x.csv
${pfxc}mpadding k=0 f=1%dr E=20131101                      i=./indat/dat16srnfn.csv -nfn   o=./outdat/out137nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107 E=20131024 -n        i=./indat/dat16sr.csv    o=./outdat/out138.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 -n        i=./indat/dat16sr.csv -x   o=./outdat/out138x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 -n        i=./indat/dat16srnfn.csv -nfn   o=./outdat/out138nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107 E=20131024 v=padding i=./indat/dat16sr.csv    o=./outdat/out139.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 v=padding i=./indat/dat16sr.csv -x   o=./outdat/out139x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 v=padding i=./indat/dat16srnfn.csv -nfn   o=./outdat/out139nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103 E=20131101 -n        i=./indat/dat16sr.csv    o=./outdat/out140.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 -n        i=./indat/dat16sr.csv -x   o=./outdat/out140x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 -n        i=./indat/dat16srnfn.csv -nfn   o=./outdat/out140nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103 E=20131101 v=padding i=./indat/dat16sr.csv    o=./outdat/out141.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 v=padding i=./indat/dat16sr.csv -x   o=./outdat/out141x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 v=padding i=./indat/dat16srnfn.csv -nfn   o=./outdat/out141nfn.csv

#time
${pfxc}mpadding k=a f=b%t                             i=./indat/dat18s.csv    o=./outdat/out142.csv
${pfxc}mpadding k=0 f=1%t                             i=./indat/dat18s.csv -x   o=./outdat/out142x.csv
${pfxc}mpadding k=0 f=1%t                             i=./indat/dat18snfn.csv -nfn   o=./outdat/out142nfn.csv

${pfxc}mpadding k=a f=b%t -n                          i=./indat/dat18s.csv    o=./outdat/out143.csv
${pfxc}mpadding k=0 f=1%t -n                          i=./indat/dat18s.csv -x   o=./outdat/out143x.csv
${pfxc}mpadding k=0 f=1%t -n                          i=./indat/dat18snfn.csv -nfn   o=./outdat/out143nfn.csv

${pfxc}mpadding k=a f=b%t v=padding                   i=./indat/dat18s.csv    o=./outdat/out144.csv
${pfxc}mpadding k=0 f=1%t v=padding                   i=./indat/dat18s.csv -x   o=./outdat/out144x.csv
${pfxc}mpadding k=0 f=1%t v=padding                   i=./indat/dat18snfn.csv -nfn   o=./outdat/out144nfn.csv

${pfxc}mpadding k=a f=b%t S=131020 E=131110           i=./indat/dat18s.csv    o=./outdat/out145.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110           i=./indat/dat18s.csv -x   o=./outdat/out145x.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110           i=./indat/dat18snfn.csv -nfn   o=./outdat/out145nfn.csv

${pfxc}mpadding k=a f=b%t S=131020                    i=./indat/dat18s.csv    o=./outdat/out146.csv
${pfxc}mpadding k=0 f=1%t S=131020                    i=./indat/dat18s.csv -x   o=./outdat/out146x.csv
${pfxc}mpadding k=0 f=1%t S=131020                    i=./indat/dat18snfn.csv -nfn   o=./outdat/out146nfn.csv

${pfxc}mpadding k=a f=b%t E=131110                    i=./indat/dat18s.csv    o=./outdat/out147.csv
${pfxc}mpadding k=0 f=1%t E=131110                    i=./indat/dat18s.csv -x   o=./outdat/out147x.csv
${pfxc}mpadding k=0 f=1%t E=131110                    i=./indat/dat18snfn.csv -nfn   o=./outdat/out147nfn.csv

${pfxc}mpadding k=a f=b%t S=131101 E=131103           i=./indat/dat18s.csv    o=./outdat/out148.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103           i=./indat/dat18s.csv -x   o=./outdat/out148x.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103           i=./indat/dat18snfn.csv -nfn   o=./outdat/out148nfn.csv

${pfxc}mpadding k=a f=b%t S=131101                    i=./indat/dat18s.csv    o=./outdat/out149.csv
${pfxc}mpadding k=0 f=1%t S=131101                    i=./indat/dat18s.csv -x   o=./outdat/out149x.csv
${pfxc}mpadding k=0 f=1%t S=131101                    i=./indat/dat18snfn.csv -nfn   o=./outdat/out149nfn.csv

${pfxc}mpadding k=a f=b%t E=131103                    i=./indat/dat18s.csv    o=./outdat/out150.csv
${pfxc}mpadding k=0 f=1%t E=131103                    i=./indat/dat18s.csv -x   o=./outdat/out150x.csv
${pfxc}mpadding k=0 f=1%t E=131103                    i=./indat/dat18snfn.csv -nfn   o=./outdat/out150nfn.csv

${pfxc}mpadding k=a f=b%t S=131020 E=131110 -n        i=./indat/dat18s.csv    o=./outdat/out151.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 -n        i=./indat/dat18s.csv -x   o=./outdat/out151x.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 -n        i=./indat/dat18snfn.csv -nfn   o=./outdat/out151nfn.csv

${pfxc}mpadding k=a f=b%t S=131020 E=131110 v=padding i=./indat/dat18s.csv    o=./outdat/out152.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 v=padding i=./indat/dat18s.csv -x   o=./outdat/out152x.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 v=padding i=./indat/dat18snfn.csv -nfn   o=./outdat/out152nfn.csv

${pfxc}mpadding k=a f=b%t S=131101 E=131103 -n        i=./indat/dat18s.csv    o=./outdat/out153.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 -n        i=./indat/dat18s.csv -x   o=./outdat/out153x.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 -n        i=./indat/dat18snfn.csv -nfn   o=./outdat/out153nfn.csv

${pfxc}mpadding k=a f=b%t S=131101 E=131103 v=padding i=./indat/dat18s.csv    o=./outdat/out154.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 v=padding i=./indat/dat18s.csv -x   o=./outdat/out154x.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 v=padding i=./indat/dat18snfn.csv -nfn   o=./outdat/out154nfn.csv

${pfxc}mpadding k=a f=b%tr                              i=./indat/dat18sr.csv    o=./outdat/out155.csv
${pfxc}mpadding k=0 f=1%tr                              i=./indat/dat18sr.csv -x   o=./outdat/out155x.csv
${pfxc}mpadding k=0 f=1%tr                              i=./indat/dat18srnfn.csv -nfn   o=./outdat/out155nfn.csv

${pfxc}mpadding k=a f=b%tr -n                           i=./indat/dat18sr.csv    o=./outdat/out156.csv
${pfxc}mpadding k=0 f=1%tr -n                           i=./indat/dat18sr.csv -x   o=./outdat/out156x.csv
${pfxc}mpadding k=0 f=1%tr -n                           i=./indat/dat18srnfn.csv -nfn   o=./outdat/out156nfn.csv

${pfxc}mpadding k=a f=b%tr v=padding                    i=./indat/dat18sr.csv    o=./outdat/out157.csv
${pfxc}mpadding k=0 f=1%tr v=padding                    i=./indat/dat18sr.csv -x   o=./outdat/out157x.csv
${pfxc}mpadding k=0 f=1%tr v=padding                    i=./indat/dat18srnfn.csv -nfn   o=./outdat/out157nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110 E=131020            i=./indat/dat18sr.csv    o=./outdat/out158.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020            i=./indat/dat18sr.csv -x   o=./outdat/out158x.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020            i=./indat/dat18srnfn.csv -nfn   o=./outdat/out158nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110                     i=./indat/dat18sr.csv    o=./outdat/out159.csv
${pfxc}mpadding k=0 f=1%tr S=131110                     i=./indat/dat18sr.csv -x   o=./outdat/out159x.csv
${pfxc}mpadding k=0 f=1%tr S=131110                     i=./indat/dat18srnfn.csv -nfn   o=./outdat/out159nfn.csv

${pfxc}mpadding k=a f=b%tr E=131020                     i=./indat/dat18sr.csv    o=./outdat/out160.csv
${pfxc}mpadding k=0 f=1%tr E=131020                     i=./indat/dat18sr.csv -x   o=./outdat/out160x.csv
${pfxc}mpadding k=0 f=1%tr E=131020                     i=./indat/dat18srnfn.csv -nfn   o=./outdat/out160nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103 E=131101            i=./indat/dat18sr.csv    o=./outdat/out161.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101            i=./indat/dat18sr.csv -x   o=./outdat/out161x.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101            i=./indat/dat18srnfn.csv -nfn   o=./outdat/out161nfn.csv

${pfxc}mpadding k=a f=b%tr S=131101                     i=./indat/dat18sr.csv    o=./outdat/out162.csv
${pfxc}mpadding k=0 f=1%tr S=131101                     i=./indat/dat18sr.csv -x   o=./outdat/out162x.csv
${pfxc}mpadding k=0 f=1%tr S=131101                     i=./indat/dat18srnfn.csv -nfn   o=./outdat/out162nfn.csv

${pfxc}mpadding k=a f=b%tr E=131103                     i=./indat/dat18sr.csv    o=./outdat/out163.csv
${pfxc}mpadding k=0 f=1%tr E=131103                     i=./indat/dat18sr.csv -x   o=./outdat/out163x.csv
${pfxc}mpadding k=0 f=1%tr E=131103                     i=./indat/dat18srnfn.csv -nfn   o=./outdat/out163nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110 E=131020 -n         i=./indat/dat18sr.csv    o=./outdat/out164.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 -n         i=./indat/dat18sr.csv -x   o=./outdat/out164x.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 -n         i=./indat/dat18srnfn.csv -nfn   o=./outdat/out164nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110 E=131020 v=padding  i=./indat/dat18sr.csv    o=./outdat/out165.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 v=padding  i=./indat/dat18sr.csv -x   o=./outdat/out165x.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 v=padding  i=./indat/dat18srnfn.csv -nfn   o=./outdat/out165nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103 E=131101 -n         i=./indat/dat18sr.csv    o=./outdat/out166.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 -n         i=./indat/dat18sr.csv -x   o=./outdat/out166x.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 -n         i=./indat/dat18srnfn.csv -nfn   o=./outdat/out166nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103 E=131101 v=padding  i=./indat/dat18sr.csv    o=./outdat/out167.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 v=padding  i=./indat/dat18sr.csv -x   o=./outdat/out167x.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 v=padding  i=./indat/dat18srnfn.csv -nfn   o=./outdat/out167nfn.csv


#key1行
${pfxc}mpadding k=a f=b%n S=0         i=./indat/dat10s.csv    o=./outdat/out168.csv
${pfxc}mpadding k=a f=b%n S=0 E=6     i=./indat/dat10s.csv    o=./outdat/out169.csv
${pfxc}mpadding k=a f=b%n E=6     i=./indat/dat10s.csv        o=./outdat/out170.csv

#dataに日付以外のフォーマットがある場合
${pfxc}mpadding k=a f=b%t i=./indat/dat11s.csv    o=./outdat/out171.csv
${pfxc}mpadding k=a f=b%t i=./indat/dat12s.csv    o=./outdat/out172.csv

#------------------------------------------------------
#ランダムデータ
#------------------------------------------------------

#int
${pfxc}mpadding f=b%n                      i=./indat/dat13.csv         o=./outdat/out210.csv
${pfxc}mpadding f=1%n                      i=./indat/dat13.csv -x      o=./outdat/out210x.csv
${pfxc}mpadding f=1%n                      i=./indat/dat13nfn.csv -nfn o=./outdat/out210nfn.csv

${pfxc}mpadding f=b%n -n                   i=./indat/dat13.csv         o=./outdat/out211.csv
${pfxc}mpadding f=1%n -n                   i=./indat/dat13.csv -x      o=./outdat/out211x.csv
${pfxc}mpadding f=1%n -n                   i=./indat/dat13nfn.csv -nfn o=./outdat/out211nfn.csv


${pfxc}mpadding f=b%n v=padding            i=./indat/dat13.csv    o=./outdat/out212.csv
${pfxc}mpadding f=1%n v=padding            i=./indat/dat13.csv -x    o=./outdat/out212x.csv
${pfxc}mpadding f=1%n v=padding            i=./indat/dat13nfn.csv -nfn   o=./outdat/out212nfn.csv


${pfxc}mpadding f=b%n S=-1 E=11            i=./indat/dat13.csv    o=./outdat/out213.csv
${pfxc}mpadding f=1%n S=-1 E=11            i=./indat/dat13.csv -x   o=./outdat/out213x.csv
${pfxc}mpadding f=1%n S=-1 E=11            i=./indat/dat13nfn.csv -nfn   o=./outdat/out213nfn.csv

${pfxc}mpadding f=b%n S=-1                 i=./indat/dat13.csv    o=./outdat/out214.csv
${pfxc}mpadding f=1%n S=-1                 i=./indat/dat13.csv -x   o=./outdat/out214x.csv
${pfxc}mpadding f=1%n S=-1                 i=./indat/dat13nfn.csv -nfn   o=./outdat/out214nfn.csv

${pfxc}mpadding f=b%n E=11                 i=./indat/dat13.csv    o=./outdat/out215.csv
${pfxc}mpadding f=1%n E=11                 i=./indat/dat13.csv -x    o=./outdat/out215x.csv
${pfxc}mpadding f=1%n E=11                 i=./indat/dat13nfn.csv -nfn   o=./outdat/out215nfn.csv

${pfxc}mpadding f=b%n S=1 E=10             i=./indat/dat13.csv    o=./outdat/out216.csv
${pfxc}mpadding f=1%n S=1 E=10             i=./indat/dat13.csv -x    o=./outdat/out216x.csv
${pfxc}mpadding f=1%n S=1 E=10             i=./indat/dat13nfn.csv -nfn   o=./outdat/out216nfn.csv

${pfxc}mpadding f=b%n S=1                  i=./indat/dat13.csv    o=./outdat/out217.csv
${pfxc}mpadding f=1%n S=1                  i=./indat/dat13.csv -x   o=./outdat/out217x.csv
${pfxc}mpadding f=1%n S=1                  i=./indat/dat13nfn.csv -nfn   o=./outdat/out217nfn.csv

${pfxc}mpadding f=b%n E=10                 i=./indat/dat13.csv    o=./outdat/out218.csv
${pfxc}mpadding f=1%n E=10                 i=./indat/dat13.csv -x   o=./outdat/out218x.csv
${pfxc}mpadding f=1%n E=10                 i=./indat/dat13nfn.csv -nfn   o=./outdat/out218nfn.csv

${pfxc}mpadding f=b%n S=-1 E=11 -n         i=./indat/dat13.csv    o=./outdat/out219.csv
${pfxc}mpadding f=1%n S=-1 E=11 -n         i=./indat/dat13.csv -x   o=./outdat/out219x.csv
${pfxc}mpadding f=1%n S=-1 E=11 -n         i=./indat/dat13nfn.csv -nfn   o=./outdat/out219nfn.csv

${pfxc}mpadding f=b%n S=-1 E=11 v=padding  i=./indat/dat13.csv    o=./outdat/out220.csv
${pfxc}mpadding f=1%n S=-1 E=11 v=padding  i=./indat/dat13.csv -x   o=./outdat/out220x.csv
${pfxc}mpadding f=1%n S=-1 E=11 v=padding  i=./indat/dat13nfn.csv -nfn   o=./outdat/out220nfn.csv

${pfxc}mpadding f=b%n S=1 E=10 -n          i=./indat/dat13.csv    o=./outdat/out221.csv
${pfxc}mpadding f=1%n S=1 E=10 -n          i=./indat/dat13.csv -x   o=./outdat/out221x.csv
${pfxc}mpadding f=1%n S=1 E=10 -n          i=./indat/dat13nfn.csv  -nfn  o=./outdat/out221nfn.csv

${pfxc}mpadding f=b%n S=1 E=10 v=padding   i=./indat/dat13.csv    o=./outdat/out222.csv
${pfxc}mpadding f=1%n S=1 E=10 v=padding   i=./indat/dat13.csv -x   o=./outdat/out222x.csv
${pfxc}mpadding f=1%n S=1 E=10 v=padding   i=./indat/dat13nfn.csv -nfn   o=./outdat/out222nfn.csv

${pfxc}mpadding f=b%nr                     i=./indat/dat13.csv    o=./outdat/out223.csv
${pfxc}mpadding f=1%nr                     i=./indat/dat13.csv -x    o=./outdat/out223x.csv
${pfxc}mpadding f=1%nr                     i=./indat/dat13nfn.csv -nfn   o=./outdat/out223nfn.csv

${pfxc}mpadding f=b%nr -n                  i=./indat/dat13.csv    o=./outdat/out224.csv
${pfxc}mpadding f=1%nr -n                  i=./indat/dat13.csv -x   o=./outdat/out224x.csv
${pfxc}mpadding f=1%nr -n                  i=./indat/dat13nfn.csv -nfn   o=./outdat/out224nfn.csv

${pfxc}mpadding f=b%nr v=padding           i=./indat/dat13.csv    o=./outdat/out225.csv
${pfxc}mpadding f=1%nr v=padding           i=./indat/dat13.csv -x   o=./outdat/out225x.csv
${pfxc}mpadding f=1%nr v=padding           i=./indat/dat13nfn.csv -nfn   o=./outdat/out225nfn.csv

${pfxc}mpadding f=b%nr E=-1 S=11           i=./indat/dat13.csv    o=./outdat/out226.csv
${pfxc}mpadding f=1%nr E=-1 S=11           i=./indat/dat13.csv -x   o=./outdat/out226x.csv
${pfxc}mpadding f=1%nr E=-1 S=11           i=./indat/dat13nfn.csv -nfn   o=./outdat/out226nfn.csv

${pfxc}mpadding f=b%nr E=-1                i=./indat/dat13.csv    o=./outdat/out227.csv
${pfxc}mpadding f=1%nr E=-1                i=./indat/dat13.csv -x   o=./outdat/out227x.csv
${pfxc}mpadding f=1%nr E=-1                i=./indat/dat13nfn.csv -nfn   o=./outdat/out227nfn.csv

${pfxc}mpadding f=b%nr S=11                i=./indat/dat13.csv    o=./outdat/out228.csv
${pfxc}mpadding f=1%nr S=11                i=./indat/dat13.csv -x   o=./outdat/out228x.csv
${pfxc}mpadding f=1%nr S=11                i=./indat/dat13nfn.csv -nfn   o=./outdat/out228nfn.csv

${pfxc}mpadding f=b%nr E=1 S=10            i=./indat/dat13.csv    o=./outdat/out229.csv
${pfxc}mpadding f=1%nr E=1 S=10            i=./indat/dat13.csv -x   o=./outdat/out229x.csv
${pfxc}mpadding f=1%nr E=1 S=10            i=./indat/dat13nfn.csv -nfn   o=./outdat/out229nfn.csv

${pfxc}mpadding f=b%nr E=1                 i=./indat/dat13.csv    o=./outdat/out230.csv
${pfxc}mpadding f=1%nr E=1                 i=./indat/dat13.csv -x   o=./outdat/out230x.csv
${pfxc}mpadding f=1%nr E=1                 i=./indat/dat13nfn.csv -nfn   o=./outdat/out230nfn.csv

${pfxc}mpadding f=b%nr S=10                i=./indat/dat13.csv    o=./outdat/out231.csv
${pfxc}mpadding f=1%nr S=10                i=./indat/dat13.csv -x   o=./outdat/out231x.csv
${pfxc}mpadding f=1%nr S=10                i=./indat/dat13nfn.csv -nfn   o=./outdat/out231nfn.csv

${pfxc}mpadding f=b%nr E=-1 S=11 -n        i=./indat/dat13.csv    o=./outdat/out232.csv
${pfxc}mpadding f=1%nr E=-1 S=11 -n        i=./indat/dat13.csv -x   o=./outdat/out232x.csv
${pfxc}mpadding f=1%nr E=-1 S=11 -n        i=./indat/dat13nfn.csv -nfn   o=./outdat/out232nfn.csv

${pfxc}mpadding f=b%nr E=-1 S=11 v=padding i=./indat/dat13.csv    o=./outdat/out233.csv
${pfxc}mpadding f=1%nr E=-1 S=11 v=padding i=./indat/dat13.csv -x   o=./outdat/out233x.csv
${pfxc}mpadding f=1%nr E=-1 S=11 v=padding i=./indat/dat13nfn.csv -nfn   o=./outdat/out233nfn.csv

${pfxc}mpadding f=b%nr E=1 S=10 -n         i=./indat/dat13.csv    o=./outdat/out234.csv
${pfxc}mpadding f=1%nr E=1 S=10 -n         i=./indat/dat13.csv -x   o=./outdat/out234x.csv
${pfxc}mpadding f=1%nr E=1 S=10 -n         i=./indat/dat13nfn.csv -nfn   o=./outdat/out234nfn.csv

${pfxc}mpadding f=b%nr E=1 S=10 v=padding  i=./indat/dat13.csv    o=./outdat/out235.csv
${pfxc}mpadding f=1%nr E=1 S=10 v=padding  i=./indat/dat13.csv -x   o=./outdat/out235x.csv
${pfxc}mpadding f=1%nr E=1 S=10 v=padding  i=./indat/dat13nfn.csv -nfn   o=./outdat/out235nfn.csv

#date
${pfxc}mpadding f=b%d                                 i=./indat/dat15.csv    o=./outdat/out236.csv
${pfxc}mpadding f=1%d                                 i=./indat/dat15.csv -x   o=./outdat/out236x.csv
${pfxc}mpadding f=1%d                                 i=./indat/dat15nfn.csv -nfn   o=./outdat/out236nfn.csv

${pfxc}mpadding f=b%d -n                              i=./indat/dat15.csv    o=./outdat/out237.csv
${pfxc}mpadding f=1%d -n                              i=./indat/dat15.csv -x   o=./outdat/out237x.csv
${pfxc}mpadding f=1%d -n                              i=./indat/dat15nfn.csv -nfn   o=./outdat/out237nfn.csv

${pfxc}mpadding f=b%d v=padding                       i=./indat/dat15.csv    o=./outdat/out238.csv
${pfxc}mpadding f=1%d v=padding                       i=./indat/dat15.csv -x   o=./outdat/out238x.csv
${pfxc}mpadding f=1%d v=padding                       i=./indat/dat15nfn.csv -nfn   o=./outdat/out238nfn.csv

${pfxc}mpadding f=b%d S=20100930 E=20101020           i=./indat/dat15.csv    o=./outdat/out239.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020           i=./indat/dat15.csv -x   o=./outdat/out239x.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020           i=./indat/dat15nfn.csv -nfn   o=./outdat/out239nfn.csv

${pfxc}mpadding f=b%d S=20100930                      i=./indat/dat15.csv    o=./outdat/out240.csv
${pfxc}mpadding f=1%d S=20100930                      i=./indat/dat15.csv -x   o=./outdat/out240x.csv
${pfxc}mpadding f=1%d S=20100930                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out240nfn.csv

${pfxc}mpadding f=b%d E=20101020                      i=./indat/dat15.csv    o=./outdat/out241.csv
${pfxc}mpadding f=1%d E=20101020                      i=./indat/dat15.csv -x   o=./outdat/out241x.csv
${pfxc}mpadding f=1%d E=20101020                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out241nfn.csv

${pfxc}mpadding f=b%d S=20101001 E=20101017           i=./indat/dat15.csv    o=./outdat/out242.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017           i=./indat/dat15.csv -x   o=./outdat/out242x.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017           i=./indat/dat15nfn.csv -nfn   o=./outdat/out242nfn.csv

${pfxc}mpadding f=b%d S=20101001                      i=./indat/dat15.csv    o=./outdat/out243.csv
${pfxc}mpadding f=1%d S=20101001                      i=./indat/dat15.csv -x   o=./outdat/out243x.csv
${pfxc}mpadding f=1%d S=20101001                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out243nfn.csv

${pfxc}mpadding f=b%d E=20101017                      i=./indat/dat15.csv    o=./outdat/out244.csv
${pfxc}mpadding f=1%d E=20101017                      i=./indat/dat15.csv -x   o=./outdat/out244x.csv
${pfxc}mpadding f=1%d E=20101017                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out244nfn.csv

${pfxc}mpadding f=b%d S=20100930 E=20101020 -n        i=./indat/dat15.csv    o=./outdat/out245.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 -n        i=./indat/dat15.csv -x   o=./outdat/out245x.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 -n        i=./indat/dat15nfn.csv -nfn   o=./outdat/out245nfn.csv

${pfxc}mpadding f=b%d S=20100930 E=20101020 v=padding i=./indat/dat15.csv    o=./outdat/out246.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 v=padding i=./indat/dat15.csv -x   o=./outdat/out246x.csv
${pfxc}mpadding f=1%d S=20100930 E=20101020 v=padding i=./indat/dat15nfn.csv -nfn   o=./outdat/out246nfn.csv

${pfxc}mpadding f=b%d S=20101001 E=20101017 -n        i=./indat/dat15.csv    o=./outdat/out247.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 -n        i=./indat/dat15.csv -x   o=./outdat/out247x.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 -n        i=./indat/dat15nfn.csv -nfn   o=./outdat/out247nfn.csv

${pfxc}mpadding f=b%d S=20101001 E=20101017 v=padding i=./indat/dat15.csv    o=./outdat/out248.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 v=padding i=./indat/dat15.csv -x   o=./outdat/out248x.csv
${pfxc}mpadding f=1%d S=20101001 E=20101017 v=padding i=./indat/dat15nfn.csv -nfn   o=./outdat/out248nfn.csv

${pfxc}mpadding f=b%dr                                 i=./indat/dat15.csv    o=./outdat/out249.csv
${pfxc}mpadding f=1%dr                                 i=./indat/dat15.csv -x   o=./outdat/out249x.csv
${pfxc}mpadding f=1%dr                                 i=./indat/dat15nfn.csv -nfn   o=./outdat/out249nfn.csv

${pfxc}mpadding f=b%dr -n                              i=./indat/dat15.csv    o=./outdat/out250.csv
${pfxc}mpadding f=1%dr -n                              i=./indat/dat15.csv -x   o=./outdat/out250x.csv
${pfxc}mpadding f=1%dr -n                              i=./indat/dat15nfn.csv -nfn   o=./outdat/out250nfn.csv

${pfxc}mpadding f=b%dr v=padding                       i=./indat/dat15.csv    o=./outdat/out251.csv
${pfxc}mpadding f=1%dr v=padding                       i=./indat/dat15.csv -x   o=./outdat/out251x.csv
${pfxc}mpadding f=1%dr v=padding                       i=./indat/dat15nfn.csv -nfn   o=./outdat/out251nfn.csv

${pfxc}mpadding f=b%dr S=20101020 E=20100930           i=./indat/dat15.csv    o=./outdat/out252.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930           i=./indat/dat15.csv -x   o=./outdat/out252x.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930           i=./indat/dat15nfn.csv -nfn   o=./outdat/out252nfn.csv

${pfxc}mpadding f=b%dr S=20101020                      i=./indat/dat15.csv    o=./outdat/out253.csv
${pfxc}mpadding f=1%dr S=20101020                      i=./indat/dat15.csv -x   o=./outdat/out253x.csv
${pfxc}mpadding f=1%dr S=20101020                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out253nfn.csv

${pfxc}mpadding f=b%dr E=20100930                      i=./indat/dat15.csv    o=./outdat/out254.csv
${pfxc}mpadding f=1%dr E=20100930                      i=./indat/dat15.csv -x   o=./outdat/out254x.csv
${pfxc}mpadding f=1%dr E=20100930                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out254nfn.csv

${pfxc}mpadding f=b%dr S=20101017 E=20101001           i=./indat/dat15.csv    o=./outdat/out255.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001           i=./indat/dat15.csv -x   o=./outdat/out255x.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001           i=./indat/dat15nfn.csv -nfn   o=./outdat/out255nfn.csv

${pfxc}mpadding f=b%dr S=20101017                      i=./indat/dat15.csv    o=./outdat/out256.csv
${pfxc}mpadding f=1%dr S=20101017                      i=./indat/dat15.csv -x   o=./outdat/out256x.csv
${pfxc}mpadding f=1%dr S=20101017                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out256nfn.csv

${pfxc}mpadding f=b%dr E=20101001                      i=./indat/dat15.csv    o=./outdat/out257.csv
${pfxc}mpadding f=1%dr E=20101001                      i=./indat/dat15.csv -x   o=./outdat/out257x.csv
${pfxc}mpadding f=1%dr E=20101001                      i=./indat/dat15nfn.csv -nfn   o=./outdat/out257nfn.csv

${pfxc}mpadding f=b%dr S=20101020 E=20100930 -n        i=./indat/dat15.csv    o=./outdat/out258.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 -n        i=./indat/dat15.csv -x   o=./outdat/out258x.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 -n        i=./indat/dat15nfn.csv -nfn   o=./outdat/out258nfn.csv

${pfxc}mpadding f=b%dr S=20101020 E=20100930 v=padding i=./indat/dat15.csv    o=./outdat/out259.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 v=padding i=./indat/dat15.csv -x   o=./outdat/out259x.csv
${pfxc}mpadding f=1%dr S=20101020 E=20100930 v=padding i=./indat/dat15nfn.csv -nfn   o=./outdat/out259nfn.csv

${pfxc}mpadding f=b%dr S=20101017 E=20101001 -n        i=./indat/dat15.csv    o=./outdat/out260.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 -n        i=./indat/dat15.csv -x   o=./outdat/out260x.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 -n        i=./indat/dat15nfn.csv -nfn   o=./outdat/out260nfn.csv

${pfxc}mpadding f=b%dr S=20101017 E=20101001 v=padding i=./indat/dat15.csv    o=./outdat/out261.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 v=padding i=./indat/dat15.csv -x   o=./outdat/out261x.csv
${pfxc}mpadding f=1%dr S=20101017 E=20101001 v=padding i=./indat/dat15nfn.csv -nfn   o=./outdat/out261nfn.csv

#time
${pfxc}mpadding f=b%t                             i=./indat/dat17.csv    o=./outdat/out262.csv
${pfxc}mpadding f=1%t                             i=./indat/dat17.csv -x   o=./outdat/out262x.csv
${pfxc}mpadding f=1%t                             i=./indat/dat17nfn.csv -nfn   o=./outdat/out262nfn.csv

${pfxc}mpadding f=b%t -n                          i=./indat/dat17.csv    o=./outdat/out263.csv
${pfxc}mpadding f=1%t -n                          i=./indat/dat17.csv -x   o=./outdat/out263x.csv
${pfxc}mpadding f=1%t -n                          i=./indat/dat17nfn.csv -nfn   o=./outdat/out263nfn.csv

${pfxc}mpadding f=b%t v=padding                   i=./indat/dat17.csv    o=./outdat/out264.csv
${pfxc}mpadding f=1%t v=padding                   i=./indat/dat17.csv -x   o=./outdat/out264x.csv
${pfxc}mpadding f=1%t v=padding                   i=./indat/dat17nfn.csv -nfn   o=./outdat/out264nfn.csv

${pfxc}mpadding f=b%t S=101048 E=101111           i=./indat/dat17.csv    o=./outdat/out265.csv
${pfxc}mpadding f=1%t S=101048 E=101111           i=./indat/dat17.csv -x   o=./outdat/out265x.csv
${pfxc}mpadding f=1%t S=101048 E=101111           i=./indat/dat17nfn.csv -nfn   o=./outdat/out265nfn.csv

${pfxc}mpadding f=b%t S=101048                    i=./indat/dat17.csv    o=./outdat/out266.csv
${pfxc}mpadding f=1%t S=101048                    i=./indat/dat17.csv -x   o=./outdat/out266x.csv
${pfxc}mpadding f=1%t S=101048                    i=./indat/dat17nfn.csv -nfn   o=./outdat/out266nfn.csv

${pfxc}mpadding f=b%t E=101111                    i=./indat/dat17.csv    o=./outdat/out267.csv
${pfxc}mpadding f=1%t E=101111                    i=./indat/dat17.csv -x   o=./outdat/out267x.csv
${pfxc}mpadding f=1%t E=101111                    i=./indat/dat17nfn.csv -nfn   o=./outdat/out267nfn.csv

${pfxc}mpadding f=b%t S=101050 E=101109           i=./indat/dat17.csv    o=./outdat/out268.csv
${pfxc}mpadding f=1%t S=101050 E=101109           i=./indat/dat17.csv -x   o=./outdat/out268x.csv
${pfxc}mpadding f=1%t S=101050 E=101109           i=./indat/dat17nfn.csv -nfn   o=./outdat/out268nfn.csv

${pfxc}mpadding f=b%t S=101050                    i=./indat/dat17.csv    o=./outdat/out269.csv
${pfxc}mpadding f=1%t S=101050                    i=./indat/dat17.csv -x   o=./outdat/out269x.csv
${pfxc}mpadding f=1%t S=101050                    i=./indat/dat17nfn.csv -nfn   o=./outdat/out269nfn.csv

${pfxc}mpadding f=b%t E=101109                    i=./indat/dat17.csv    o=./outdat/out270.csv
${pfxc}mpadding f=1%t E=101109                    i=./indat/dat17.csv -x   o=./outdat/out270x.csv
${pfxc}mpadding f=1%t E=101109                    i=./indat/dat17nfn.csv -nfn   o=./outdat/out270nfn.csv

${pfxc}mpadding f=b%t S=101048 E=101111 -n        i=./indat/dat17.csv    o=./outdat/out271.csv
${pfxc}mpadding f=1%t S=101048 E=101111 -n        i=./indat/dat17.csv -x   o=./outdat/out271x.csv
${pfxc}mpadding f=1%t S=101048 E=101111 -n        i=./indat/dat17nfn.csv -nfn   o=./outdat/out271nfn.csv

${pfxc}mpadding f=b%t S=101048 E=101111 v=padding i=./indat/dat17.csv    o=./outdat/out272.csv
${pfxc}mpadding f=1%t S=101048 E=101111 v=padding i=./indat/dat17.csv -x   o=./outdat/out272x.csv
${pfxc}mpadding f=1%t S=101048 E=101111 v=padding i=./indat/dat17nfn.csv -nfn   o=./outdat/out272nfn.csv

${pfxc}mpadding f=b%t S=101050 E=101109 -n        i=./indat/dat17.csv    o=./outdat/out273.csv
${pfxc}mpadding f=1%t S=101050 E=101109 -n        i=./indat/dat17.csv -x   o=./outdat/out273x.csv
${pfxc}mpadding f=1%t S=101050 E=101109 -n        i=./indat/dat17nfn.csv -nfn   o=./outdat/out273nfn.csv

${pfxc}mpadding f=b%t S=101050 E=101109 v=padding i=./indat/dat17.csv    o=./outdat/out274.csv
${pfxc}mpadding f=1%t S=101050 E=101109 v=padding i=./indat/dat17.csv -x   o=./outdat/out274x.csv
${pfxc}mpadding f=1%t S=101050 E=101109 v=padding i=./indat/dat17nfn.csv -nfn   o=./outdat/out274nfn.csv

${pfxc}mpadding f=b%tr                              i=./indat/dat17.csv    o=./outdat/out275.csv
${pfxc}mpadding f=1%tr                              i=./indat/dat17.csv -x   o=./outdat/out275x.csv
${pfxc}mpadding f=1%tr                              i=./indat/dat17nfn.csv -nfn   o=./outdat/out275nfn.csv

${pfxc}mpadding f=b%tr -n                           i=./indat/dat17.csv    o=./outdat/out276.csv
${pfxc}mpadding f=1%tr -n                           i=./indat/dat17.csv -x   o=./outdat/out276x.csv
${pfxc}mpadding f=1%tr -n                           i=./indat/dat17nfn.csv -nfn   o=./outdat/out276nfn.csv

${pfxc}mpadding f=b%tr v=padding                    i=./indat/dat17.csv    o=./outdat/out277.csv
${pfxc}mpadding f=1%tr v=padding                    i=./indat/dat17.csv -x   o=./outdat/out277x.csv
${pfxc}mpadding f=1%tr v=padding                    i=./indat/dat17nfn.csv -nfn   o=./outdat/out277nfn.csv

${pfxc}mpadding f=b%tr S=101111 E=101048            i=./indat/dat17.csv    o=./outdat/out278.csv
${pfxc}mpadding f=1%tr S=101111 E=101048            i=./indat/dat17.csv -x   o=./outdat/out278x.csv
${pfxc}mpadding f=1%tr S=101111 E=101048            i=./indat/dat17nfn.csv -nfn   o=./outdat/out278nfn.csv

${pfxc}mpadding f=b%tr S=101111                     i=./indat/dat17.csv    o=./outdat/out279.csv
${pfxc}mpadding f=1%tr S=101111                     i=./indat/dat17.csv -x   o=./outdat/out279x.csv
${pfxc}mpadding f=1%tr S=101111                     i=./indat/dat17nfn.csv -nfn   o=./outdat/out279nfn.csv

${pfxc}mpadding f=b%tr E=101048                     i=./indat/dat17.csv    o=./outdat/out280.csv
${pfxc}mpadding f=1%tr E=101048                     i=./indat/dat17.csv -x   o=./outdat/out280x.csv
${pfxc}mpadding f=1%tr E=101048                     i=./indat/dat17nfn.csv -nfn   o=./outdat/out280nfn.csv

${pfxc}mpadding f=b%tr S=101109 E=101050            i=./indat/dat17.csv    o=./outdat/out281.csv
${pfxc}mpadding f=1%tr S=101109 E=101050            i=./indat/dat17.csv -x   o=./outdat/out281x.csv
${pfxc}mpadding f=1%tr S=101109 E=101050            i=./indat/dat17nfn.csv -nfn   o=./outdat/out281nfn.csv

${pfxc}mpadding f=b%tr S=101109                     i=./indat/dat17.csv    o=./outdat/out282.csv
${pfxc}mpadding f=1%tr S=101109                     i=./indat/dat17.csv -x   o=./outdat/out282x.csv
${pfxc}mpadding f=1%tr S=101109                     i=./indat/dat17nfn.csv -nfn   o=./outdat/out282nfn.csv

${pfxc}mpadding f=b%tr E=101050                     i=./indat/dat17.csv    o=./outdat/out283.csv
${pfxc}mpadding f=1%tr E=101050                     i=./indat/dat17.csv -x   o=./outdat/out283x.csv
${pfxc}mpadding f=1%tr E=101050                     i=./indat/dat17nfn.csv -nfn   o=./outdat/out283nfn.csv

${pfxc}mpadding f=b%tr S=101111 E=101048 -n         i=./indat/dat17.csv    o=./outdat/out284.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 -n         i=./indat/dat17.csv -x   o=./outdat/out284x.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 -n         i=./indat/dat17nfn.csv -nfn   o=./outdat/out284nfn.csv

${pfxc}mpadding f=b%tr S=101111 E=101048 v=padding  i=./indat/dat17.csv    o=./outdat/out285.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 v=padding  i=./indat/dat17.csv -x   o=./outdat/out285x.csv
${pfxc}mpadding f=1%tr S=101111 E=101048 v=padding  i=./indat/dat17nfn.csv -nfn   o=./outdat/out285nfn.csv

${pfxc}mpadding f=b%tr S=101109 E=101050 -n         i=./indat/dat17.csv    o=./outdat/out286.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 -n         i=./indat/dat17.csv -x   o=./outdat/out286x.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 -n         i=./indat/dat17nfn.csv -nfn   o=./outdat/out286nfn.csv

${pfxc}mpadding f=b%tr S=101109 E=101050 v=padding  i=./indat/dat17.csv    o=./outdat/out287.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 v=padding  i=./indat/dat17.csv -x   o=./outdat/out287x.csv
${pfxc}mpadding f=1%tr S=101109 E=101050 v=padding  i=./indat/dat17nfn.csv -nfn   o=./outdat/out287nfn.csv

#k=有り
#int
${pfxc}mpadding k=a f=b%n                      i=./indat/dat14.csv         o=./outdat/out290.csv
${pfxc}mpadding k=0 f=1%n                      i=./indat/dat14.csv -x      o=./outdat/out290x.csv
${pfxc}mpadding k=0 f=1%n                      i=./indat/dat14nfn.csv -nfn o=./outdat/out290nfn.csv

${pfxc}mpadding k=a f=b%n -n                   i=./indat/dat14.csv         o=./outdat/out291.csv
${pfxc}mpadding k=0 f=1%n -n                   i=./indat/dat14.csv -x      o=./outdat/out291x.csv
${pfxc}mpadding k=0 f=1%n -n                   i=./indat/dat14nfn.csv -nfn o=./outdat/out291nfn.csv


${pfxc}mpadding k=a f=b%n v=padding            i=./indat/dat14.csv    o=./outdat/out292.csv
${pfxc}mpadding k=0 f=1%n v=padding            i=./indat/dat14.csv -x    o=./outdat/out292x.csv
${pfxc}mpadding k=0 f=1%n v=padding            i=./indat/dat14nfn.csv -nfn   o=./outdat/out292nfn.csv


${pfxc}mpadding k=a f=b%n S=-1 E=11            i=./indat/dat14.csv    o=./outdat/out293.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11            i=./indat/dat14.csv -x   o=./outdat/out293x.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11            i=./indat/dat14nfn.csv -nfn   o=./outdat/out293nfn.csv

${pfxc}mpadding k=a f=b%n S=-1                 i=./indat/dat14.csv    o=./outdat/out294.csv
${pfxc}mpadding k=0 f=1%n S=-1                 i=./indat/dat14.csv -x   o=./outdat/out294x.csv
${pfxc}mpadding k=0 f=1%n S=-1                 i=./indat/dat14nfn.csv -nfn   o=./outdat/out294nfn.csv

${pfxc}mpadding k=a f=b%n E=11                 i=./indat/dat14.csv    o=./outdat/out295.csv
${pfxc}mpadding k=0 f=1%n E=11                 i=./indat/dat14.csv -x    o=./outdat/out295x.csv
${pfxc}mpadding k=0 f=1%n E=11                 i=./indat/dat14nfn.csv -nfn   o=./outdat/out295nfn.csv

${pfxc}mpadding k=a f=b%n S=1 E=10             i=./indat/dat14.csv    o=./outdat/out296.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10             i=./indat/dat14.csv -x    o=./outdat/out296x.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10             i=./indat/dat14nfn.csv -nfn   o=./outdat/out296nfn.csv

${pfxc}mpadding k=a f=b%n S=1                  i=./indat/dat14.csv    o=./outdat/out297.csv
${pfxc}mpadding k=0 f=1%n S=1                  i=./indat/dat14.csv -x   o=./outdat/out297x.csv
${pfxc}mpadding k=0 f=1%n S=1                  i=./indat/dat14nfn.csv -nfn   o=./outdat/out297nfn.csv

${pfxc}mpadding k=a f=b%n E=10                 i=./indat/dat14.csv    o=./outdat/out298.csv
${pfxc}mpadding k=0 f=1%n E=10                 i=./indat/dat14.csv -x   o=./outdat/out298x.csv
${pfxc}mpadding k=0 f=1%n E=10                 i=./indat/dat14nfn.csv -nfn   o=./outdat/out298nfn.csv

${pfxc}mpadding k=a f=b%n S=-1 E=11 -n         i=./indat/dat14.csv    o=./outdat/out299.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 -n         i=./indat/dat14.csv -x   o=./outdat/out299x.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 -n         i=./indat/dat14nfn.csv -nfn   o=./outdat/out299nfn.csv

${pfxc}mpadding k=a f=b%n S=-1 E=11 v=padding  i=./indat/dat14.csv    o=./outdat/out300.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 v=padding  i=./indat/dat14.csv -x   o=./outdat/out300x.csv
${pfxc}mpadding k=0 f=1%n S=-1 E=11 v=padding  i=./indat/dat14nfn.csv -nfn   o=./outdat/out300nfn.csv

${pfxc}mpadding k=a f=b%n S=1 E=10 -n          i=./indat/dat14.csv    o=./outdat/out301.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 -n          i=./indat/dat14.csv -x   o=./outdat/out301x.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 -n          i=./indat/dat14nfn.csv -nfn   o=./outdat/out301nfn.csv

${pfxc}mpadding k=a f=b%n S=1 E=10 v=padding   i=./indat/dat14.csv    o=./outdat/out302.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 v=padding   i=./indat/dat14.csv -x   o=./outdat/out302x.csv
${pfxc}mpadding k=0 f=1%n S=1 E=10 v=padding   i=./indat/dat14nfn.csv -nfn   o=./outdat/out302nfn.csv

${pfxc}mpadding k=a f=b%nr                     i=./indat/dat14.csv    o=./outdat/out303.csv
${pfxc}mpadding k=0 f=1%nr                     i=./indat/dat14.csv -x    o=./outdat/out303x.csv
${pfxc}mpadding k=0 f=1%nr                     i=./indat/dat14nfn.csv -nfn   o=./outdat/out303nfn.csv

${pfxc}mpadding k=a f=b%nr -n                  i=./indat/dat14.csv    o=./outdat/out304.csv
${pfxc}mpadding k=0 f=1%nr -n                  i=./indat/dat14.csv -x   o=./outdat/out304x.csv
${pfxc}mpadding k=0 f=1%nr -n                  i=./indat/dat14nfn.csv -nfn   o=./outdat/out304nfn.csv

${pfxc}mpadding k=a f=b%nr v=padding           i=./indat/dat14.csv    o=./outdat/out305.csv
${pfxc}mpadding k=0 f=1%nr v=padding           i=./indat/dat14.csv -x   o=./outdat/out305x.csv
${pfxc}mpadding k=0 f=1%nr v=padding           i=./indat/dat14nfn.csv -nfn   o=./outdat/out305nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1 S=11           i=./indat/dat14.csv    o=./outdat/out306.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11           i=./indat/dat14.csv -x   o=./outdat/out306x.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11           i=./indat/dat14nfn.csv -nfn   o=./outdat/out306nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1                i=./indat/dat14.csv    o=./outdat/out307.csv
${pfxc}mpadding k=0 f=1%nr E=-1                i=./indat/dat14.csv -x   o=./outdat/out307x.csv
${pfxc}mpadding k=0 f=1%nr E=-1                i=./indat/dat14nfn.csv -nfn   o=./outdat/out307nfn.csv

${pfxc}mpadding k=a f=b%nr S=11                i=./indat/dat14.csv    o=./outdat/out308.csv
${pfxc}mpadding k=0 f=1%nr S=11                i=./indat/dat14.csv -x   o=./outdat/out308x.csv
${pfxc}mpadding k=0 f=1%nr S=11                i=./indat/dat14nfn.csv -nfn   o=./outdat/out308nfn.csv

${pfxc}mpadding k=a f=b%nr E=1 S=10            i=./indat/dat14.csv    o=./outdat/out309.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10            i=./indat/dat14.csv -x   o=./outdat/out309x.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10            i=./indat/dat14nfn.csv -nfn   o=./outdat/out309nfn.csv

${pfxc}mpadding k=a f=b%nr E=1                 i=./indat/dat14.csv    o=./outdat/out310.csv
${pfxc}mpadding k=0 f=1%nr E=1                 i=./indat/dat14.csv -x   o=./outdat/out310x.csv
${pfxc}mpadding k=0 f=1%nr E=1                 i=./indat/dat14nfn.csv -nfn   o=./outdat/out310nfn.csv

${pfxc}mpadding k=a f=b%nr S=10                i=./indat/dat14.csv    o=./outdat/out311.csv
${pfxc}mpadding k=0 f=1%nr S=10                i=./indat/dat14.csv -x   o=./outdat/out311x.csv
${pfxc}mpadding k=0 f=1%nr S=10                i=./indat/dat14nfn.csv -nfn   o=./outdat/out311nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1 S=11 -n        i=./indat/dat14.csv    o=./outdat/out312.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 -n        i=./indat/dat14.csv -x   o=./outdat/out312x.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 -n        i=./indat/dat14nfn.csv -nfn   o=./outdat/out312nfn.csv

${pfxc}mpadding k=a f=b%nr E=-1 S=11 v=padding i=./indat/dat14.csv    o=./outdat/out313.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 v=padding i=./indat/dat14.csv -x   o=./outdat/out313x.csv
${pfxc}mpadding k=0 f=1%nr E=-1 S=11 v=padding i=./indat/dat14nfn.csv -nfn   o=./outdat/out313nfn.csv

${pfxc}mpadding k=a f=b%nr E=1 S=10 -n         i=./indat/dat14.csv    o=./outdat/out314.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 -n         i=./indat/dat14.csv -x   o=./outdat/out314x.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 -n         i=./indat/dat14nfn.csv -nfn   o=./outdat/out314nfn.csv

${pfxc}mpadding k=a f=b%nr E=1 S=10 v=padding  i=./indat/dat14.csv    o=./outdat/out315.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 v=padding  i=./indat/dat14.csv -x   o=./outdat/out315x.csv
${pfxc}mpadding k=0 f=1%nr E=1 S=10 v=padding  i=./indat/dat14nfn.csv -nfn   o=./outdat/out315nfn.csv

#date
${pfxc}mpadding k=a f=b%d                                 i=./indat/dat16.csv    o=./outdat/out316.csv
${pfxc}mpadding k=0 f=1%d                                 i=./indat/dat16.csv -x   o=./outdat/out316x.csv
${pfxc}mpadding k=0 f=1%d                                 i=./indat/dat16nfn.csv -nfn   o=./outdat/out316nfn.csv

${pfxc}mpadding k=a f=b%d -n                              i=./indat/dat16.csv    o=./outdat/out317.csv
${pfxc}mpadding k=0 f=1%d -n                              i=./indat/dat16.csv -x   o=./outdat/out317x.csv
${pfxc}mpadding k=0 f=1%d -n                              i=./indat/dat16nfn.csv -nfn   o=./outdat/out317nfn.csv

${pfxc}mpadding k=a f=b%d v=padding                       i=./indat/dat16.csv    o=./outdat/out318.csv
${pfxc}mpadding k=0 f=1%d v=padding                       i=./indat/dat16.csv -x   o=./outdat/out318x.csv
${pfxc}mpadding k=0 f=1%d v=padding                       i=./indat/dat16nfn.csv -nfn   o=./outdat/out318nfn.csv



${pfxc}mpadding k=a f=b%d S=20131024 E=20131107           i=./indat/dat16.csv    o=./outdat/out319.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107           i=./indat/dat16.csv -x   o=./outdat/out319x.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107           i=./indat/dat16nfn.csv -nfn   o=./outdat/out319nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024                      i=./indat/dat16.csv    o=./outdat/out320.csv
${pfxc}mpadding k=0 f=1%d S=20131024                      i=./indat/dat16.csv -x   o=./outdat/out320x.csv
${pfxc}mpadding k=0 f=1%d S=20131024                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out320nfn.csv

${pfxc}mpadding k=a f=b%d E=20131107                      i=./indat/dat16.csv    o=./outdat/out321.csv
${pfxc}mpadding k=0 f=1%d E=20131107                      i=./indat/dat16.csv -x   o=./outdat/out321x.csv
${pfxc}mpadding k=0 f=1%d E=20131107                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out321nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101 E=20131103           i=./indat/dat16.csv    o=./outdat/out322.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103           i=./indat/dat16.csv -x   o=./outdat/out322x.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103           i=./indat/dat16nfn.csv -nfn   o=./outdat/out322nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101                      i=./indat/dat16.csv    o=./outdat/out323.csv
${pfxc}mpadding k=0 f=1%d S=20131101                      i=./indat/dat16.csv -x   o=./outdat/out323x.csv
${pfxc}mpadding k=0 f=1%d S=20131101                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out323nfn.csv

${pfxc}mpadding k=a f=b%d E=20131103                      i=./indat/dat16.csv    o=./outdat/out324.csv
${pfxc}mpadding k=0 f=1%d E=20131103                      i=./indat/dat16.csv -x   o=./outdat/out324x.csv
${pfxc}mpadding k=0 f=1%d E=20131103                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out324nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024 E=20131107 -n        i=./indat/dat16.csv    o=./outdat/out325.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 -n        i=./indat/dat16.csv -x   o=./outdat/out325x.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 -n        i=./indat/dat16nfn.csv -nfn   o=./outdat/out325nfn.csv

${pfxc}mpadding k=a f=b%d S=20131024 E=20131107 v=padding i=./indat/dat16.csv    o=./outdat/out326.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 v=padding i=./indat/dat16.csv -x   o=./outdat/out326x.csv
${pfxc}mpadding k=0 f=1%d S=20131024 E=20131107 v=padding i=./indat/dat16nfn.csv -nfn   o=./outdat/out326nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101 E=20131103 -n        i=./indat/dat16.csv    o=./outdat/out327.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 -n        i=./indat/dat16.csv -x   o=./outdat/out327x.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 -n        i=./indat/dat16nfn.csv -nfn   o=./outdat/out327nfn.csv

${pfxc}mpadding k=a f=b%d S=20131101 E=20131103 v=padding i=./indat/dat16.csv    o=./outdat/out328.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 v=padding i=./indat/dat16.csv -x   o=./outdat/out328x.csv
${pfxc}mpadding k=0 f=1%d S=20131101 E=20131103 v=padding i=./indat/dat16nfn.csv -nfn   o=./outdat/out328nfn.csv

${pfxc}mpadding k=a f=b%dr                                 i=./indat/dat16.csv    o=./outdat/out329.csv
${pfxc}mpadding k=0 f=1%dr                                 i=./indat/dat16.csv -x   o=./outdat/out329x.csv
${pfxc}mpadding k=0 f=1%dr                                 i=./indat/dat16nfn.csv -nfn   o=./outdat/out329nfn.csv

${pfxc}mpadding k=a f=b%dr -n                              i=./indat/dat16.csv    o=./outdat/out330.csv
${pfxc}mpadding k=0 f=1%dr -n                              i=./indat/dat16.csv -x   o=./outdat/out330x.csv
${pfxc}mpadding k=0 f=1%dr -n                              i=./indat/dat16nfn.csv -nfn   o=./outdat/out330nfn.csv

${pfxc}mpadding k=a f=b%dr v=padding                       i=./indat/dat16.csv    o=./outdat/out331.csv
${pfxc}mpadding k=0 f=1%dr v=padding                       i=./indat/dat16.csv -x   o=./outdat/out331x.csv
${pfxc}mpadding k=0 f=1%dr v=padding                       i=./indat/dat16nfn.csv -nfn   o=./outdat/out331nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107 E=20131024           i=./indat/dat16.csv    o=./outdat/out332.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024           i=./indat/dat16.csv -x   o=./outdat/out332x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024           i=./indat/dat16nfn.csv -nfn   o=./outdat/out332nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107                      i=./indat/dat16.csv    o=./outdat/out333.csv
${pfxc}mpadding k=0 f=1%dr S=20131107                      i=./indat/dat16.csv -x   o=./outdat/out333x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out333nfn.csv

${pfxc}mpadding k=a f=b%dr E=20131024                      i=./indat/dat16.csv    o=./outdat/out334.csv
${pfxc}mpadding k=0 f=1%dr E=20131024                      i=./indat/dat16.csv -x   o=./outdat/out334x.csv
${pfxc}mpadding k=0 f=1%dr E=20131024                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out334nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103 E=20131101           i=./indat/dat16.csv    o=./outdat/out335.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101           i=./indat/dat16.csv -x   o=./outdat/out335x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101           i=./indat/dat16nfn.csv -nfn   o=./outdat/out335nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103                      i=./indat/dat16.csv    o=./outdat/out336.csv
${pfxc}mpadding k=0 f=1%dr S=20131103                      i=./indat/dat16.csv -x   o=./outdat/out336x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out336nfn.csv

${pfxc}mpadding k=a f=b%dr E=20131101                      i=./indat/dat16.csv    o=./outdat/out337.csv
${pfxc}mpadding k=0 f=1%dr E=20131101                      i=./indat/dat16.csv -x   o=./outdat/out337x.csv
${pfxc}mpadding k=0 f=1%dr E=20131101                      i=./indat/dat16nfn.csv -nfn   o=./outdat/out337nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107 E=20131024 -n        i=./indat/dat16.csv    o=./outdat/out338.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 -n        i=./indat/dat16.csv -x   o=./outdat/out338x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 -n        i=./indat/dat16nfn.csv -nfn   o=./outdat/out338nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131107 E=20131024 v=padding i=./indat/dat16.csv    o=./outdat/out339.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 v=padding i=./indat/dat16.csv -x   o=./outdat/out339x.csv
${pfxc}mpadding k=0 f=1%dr S=20131107 E=20131024 v=padding i=./indat/dat16nfn.csv -nfn   o=./outdat/out339nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103 E=20131101 -n        i=./indat/dat16.csv    o=./outdat/out340.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 -n        i=./indat/dat16.csv -x   o=./outdat/out340x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 -n        i=./indat/dat16nfn.csv -nfn   o=./outdat/out340nfn.csv

${pfxc}mpadding k=a f=b%dr S=20131103 E=20131101 v=padding i=./indat/dat16.csv    o=./outdat/out341.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 v=padding i=./indat/dat16.csv -x   o=./outdat/out341x.csv
${pfxc}mpadding k=0 f=1%dr S=20131103 E=20131101 v=padding i=./indat/dat16nfn.csv -nfn   o=./outdat/out341nfn.csv

#time
${pfxc}mpadding k=a f=b%t                             i=./indat/dat18.csv    o=./outdat/out342.csv
${pfxc}mpadding k=0 f=1%t                             i=./indat/dat18.csv -x   o=./outdat/out342x.csv
${pfxc}mpadding k=0 f=1%t                             i=./indat/dat18nfn.csv -nfn   o=./outdat/out342nfn.csv

${pfxc}mpadding k=a f=b%t -n                          i=./indat/dat18.csv    o=./outdat/out343.csv
${pfxc}mpadding k=0 f=1%t -n                          i=./indat/dat18.csv -x   o=./outdat/out343x.csv
${pfxc}mpadding k=0 f=1%t -n                          i=./indat/dat18nfn.csv -nfn   o=./outdat/out343nfn.csv

${pfxc}mpadding k=a f=b%t v=padding                   i=./indat/dat18.csv    o=./outdat/out344.csv
${pfxc}mpadding k=0 f=1%t v=padding                   i=./indat/dat18.csv -x   o=./outdat/out344x.csv
${pfxc}mpadding k=0 f=1%t v=padding                   i=./indat/dat18nfn.csv -nfn   o=./outdat/out344nfn.csv

${pfxc}mpadding k=a f=b%t S=131020 E=131110           i=./indat/dat18.csv    o=./outdat/out345.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110           i=./indat/dat18.csv -x   o=./outdat/out345x.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110           i=./indat/dat18nfn.csv -nfn   o=./outdat/out345nfn.csv

${pfxc}mpadding k=a f=b%t S=131020                    i=./indat/dat18.csv    o=./outdat/out346.csv
${pfxc}mpadding k=0 f=1%t S=131020                    i=./indat/dat18.csv -x   o=./outdat/out346x.csv
${pfxc}mpadding k=0 f=1%t S=131020                    i=./indat/dat18nfn.csv -nfn   o=./outdat/out346nfn.csv

${pfxc}mpadding k=a f=b%t E=131110                    i=./indat/dat18.csv    o=./outdat/out347.csv
${pfxc}mpadding k=0 f=1%t E=131110                    i=./indat/dat18.csv -x   o=./outdat/out347x.csv
${pfxc}mpadding k=0 f=1%t E=131110                    i=./indat/dat18nfn.csv -nfn   o=./outdat/out347nfn.csv

${pfxc}mpadding k=a f=b%t S=131101 E=131103           i=./indat/dat18.csv    o=./outdat/out348.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103           i=./indat/dat18.csv -x   o=./outdat/out348x.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103           i=./indat/dat18nfn.csv -nfn   o=./outdat/out348nfn.csv

${pfxc}mpadding k=a f=b%t S=131101                    i=./indat/dat18.csv    o=./outdat/out349.csv
${pfxc}mpadding k=0 f=1%t S=131101                    i=./indat/dat18.csv -x   o=./outdat/out349x.csv
${pfxc}mpadding k=0 f=1%t S=131101                    i=./indat/dat18nfn.csv -nfn   o=./outdat/out349nfn.csv

${pfxc}mpadding k=a f=b%t E=131103                    i=./indat/dat18.csv    o=./outdat/out350.csv
${pfxc}mpadding k=0 f=1%t E=131103                    i=./indat/dat18.csv -x   o=./outdat/out350x.csv
${pfxc}mpadding k=0 f=1%t E=131103                    i=./indat/dat18nfn.csv -nfn   o=./outdat/out350nfn.csv

${pfxc}mpadding k=a f=b%t S=131020 E=131110 -n        i=./indat/dat18.csv    o=./outdat/out351.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 -n        i=./indat/dat18.csv -x   o=./outdat/out351x.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 -n        i=./indat/dat18nfn.csv -nfn   o=./outdat/out351nfn.csv

${pfxc}mpadding k=a f=b%t S=131020 E=131110 v=padding i=./indat/dat18.csv    o=./outdat/out352.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 v=padding i=./indat/dat18.csv -x   o=./outdat/out352x.csv
${pfxc}mpadding k=0 f=1%t S=131020 E=131110 v=padding i=./indat/dat18nfn.csv -nfn   o=./outdat/out352nfn.csv

${pfxc}mpadding k=a f=b%t S=131101 E=131103 -n        i=./indat/dat18.csv    o=./outdat/out353.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 -n        i=./indat/dat18.csv -x   o=./outdat/out353x.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 -n        i=./indat/dat18nfn.csv -nfn   o=./outdat/out353nfn.csv

${pfxc}mpadding k=a f=b%t S=131101 E=131103 v=padding i=./indat/dat18.csv    o=./outdat/out354.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 v=padding i=./indat/dat18.csv -x   o=./outdat/out354x.csv
${pfxc}mpadding k=0 f=1%t S=131101 E=131103 v=padding i=./indat/dat18nfn.csv -nfn   o=./outdat/out354nfn.csv

${pfxc}mpadding k=a f=b%tr                              i=./indat/dat18.csv    o=./outdat/out355.csv
${pfxc}mpadding k=0 f=1%tr                              i=./indat/dat18.csv -x   o=./outdat/out355x.csv
${pfxc}mpadding k=0 f=1%tr                              i=./indat/dat18nfn.csv -nfn   o=./outdat/out355nfn.csv

${pfxc}mpadding k=a f=b%tr -n                           i=./indat/dat18.csv    o=./outdat/out356.csv
${pfxc}mpadding k=0 f=1%tr -n                           i=./indat/dat18.csv -x   o=./outdat/out356x.csv
${pfxc}mpadding k=0 f=1%tr -n                           i=./indat/dat18nfn.csv -nfn   o=./outdat/out356nfn.csv

${pfxc}mpadding k=a f=b%tr v=padding                    i=./indat/dat18.csv    o=./outdat/out357.csv
${pfxc}mpadding k=0 f=1%tr v=padding                    i=./indat/dat18.csv -x   o=./outdat/out357x.csv
${pfxc}mpadding k=0 f=1%tr v=padding                    i=./indat/dat18nfn.csv -nfn   o=./outdat/out357nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110 E=131020            i=./indat/dat18.csv    o=./outdat/out358.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020            i=./indat/dat18.csv -x   o=./outdat/out358x.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020            i=./indat/dat18nfn.csv -nfn   o=./outdat/out358nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110                     i=./indat/dat18.csv    o=./outdat/out359.csv
${pfxc}mpadding k=0 f=1%tr S=131110                     i=./indat/dat18.csv -x   o=./outdat/out359x.csv
${pfxc}mpadding k=0 f=1%tr S=131110                     i=./indat/dat18nfn.csv -nfn   o=./outdat/out359nfn.csv

${pfxc}mpadding k=a f=b%tr E=131020                     i=./indat/dat18.csv    o=./outdat/out360.csv
${pfxc}mpadding k=0 f=1%tr E=131020                     i=./indat/dat18.csv -x   o=./outdat/out360x.csv
${pfxc}mpadding k=0 f=1%tr E=131020                     i=./indat/dat18nfn.csv -nfn   o=./outdat/out360nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103 E=131101            i=./indat/dat18.csv    o=./outdat/out361.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101            i=./indat/dat18.csv -x   o=./outdat/out361x.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101            i=./indat/dat18nfn.csv -nfn   o=./outdat/out361nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103                     i=./indat/dat18.csv    o=./outdat/out362.csv
${pfxc}mpadding k=0 f=1%tr S=131103                     i=./indat/dat18.csv -x   o=./outdat/out362x.csv
${pfxc}mpadding k=0 f=1%tr S=131103                     i=./indat/dat18nfn.csv -nfn   o=./outdat/out362nfn.csv

${pfxc}mpadding k=a f=b%tr E=131101                     i=./indat/dat18.csv    o=./outdat/out363.csv
${pfxc}mpadding k=0 f=1%tr E=131101                     i=./indat/dat18.csv -x   o=./outdat/out363x.csv
${pfxc}mpadding k=0 f=1%tr E=131101                     i=./indat/dat18nfn.csv -nfn   o=./outdat/out363nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110 E=131020 -n         i=./indat/dat18.csv    o=./outdat/out364.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 -n         i=./indat/dat18.csv -x   o=./outdat/out364x.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 -n         i=./indat/dat18nfn.csv -nfn   o=./outdat/out364nfn.csv

${pfxc}mpadding k=a f=b%tr S=131110 E=131020 v=padding  i=./indat/dat18.csv    o=./outdat/out365.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 v=padding  i=./indat/dat18.csv -x   o=./outdat/out365x.csv
${pfxc}mpadding k=0 f=1%tr S=131110 E=131020 v=padding  i=./indat/dat18nfn.csv -nfn   o=./outdat/out365nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103 E=131101 -n         i=./indat/dat18.csv    o=./outdat/out366.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 -n         i=./indat/dat18.csv -x   o=./outdat/out366x.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 -n         i=./indat/dat18nfn.csv -nfn   o=./outdat/out366nfn.csv

${pfxc}mpadding k=a f=b%tr S=131103 E=131101 v=padding  i=./indat/dat18.csv    o=./outdat/out367.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 v=padding  i=./indat/dat18.csv -x   o=./outdat/out367x.csv
${pfxc}mpadding k=0 f=1%tr S=131103 E=131101 v=padding  i=./indat/dat18nfn.csv -nfn   o=./outdat/out367nfn.csv



#NULLを含むデータ
${pfxc}mpadding k=a f=b%n            i=./indat/dat19.csv    o=./outdat/out400.csv
${pfxc}mpadding k=a f=b%n S=-1 E=11 i=./indat/dat19.csv    o=./outdat/out401.csv
${pfxc}mpadding k=a f=b%n S=-1      i=./indat/dat19.csv    o=./outdat/out402.csv
${pfxc}mpadding k=a f=b%n E=11      i=./indat/dat19.csv    o=./outdat/out403.csv
${pfxc}mpadding k=a f=b%n -q        i=./indat/dat19.csv    o=./outdat/out404.csv


${pfxc}mpadding k=a f=b%d                       i=./indat/dat20.csv    o=./outdat/out405.csv
${pfxc}mpadding k=a f=b%d S=20100930 E=20101020 i=./indat/dat20.csv    o=./outdat/out406.csv
${pfxc}mpadding k=a f=b%d S=20100930            i=./indat/dat20.csv    o=./outdat/out407.csv
${pfxc}mpadding k=a f=b%d E=20101020            i=./indat/dat20.csv    o=./outdat/out408.csv
${pfxc}mpadding k=a f=b%d -q                    i=./indat/dat20.csv    o=./outdat/out409.csv


${pfxc}mpadding k=a f=b%t                   i=./indat/dat21.csv    o=./outdat/out410.csv
${pfxc}mpadding k=a f=b%t S=101048 E=101111 i=./indat/dat21.csv    o=./outdat/out411.csv
${pfxc}mpadding k=a f=b%t S=101048          i=./indat/dat21.csv    o=./outdat/out412.csv
${pfxc}mpadding k=a f=b%t E=101111          i=./indat/dat21.csv    o=./outdat/out413.csv
${pfxc}mpadding k=a f=b%t -q                i=./indat/dat21.csv    o=./outdat/out414.csv

