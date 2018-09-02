#!/bin/bash
. ../env

#name_kg_mcmd nrcommon

#NULLデータ
${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out0.csv
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out0x.csv
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out0nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out1.csv
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out1x.csv
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat3.csv    o=./outdat/out2.csv
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat3.csv    o=./outdat/out2x.csv
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat3nfn.csv o=./outdat/out2nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out3.csv    -r
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out3x.csv   -r
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out3nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out4.csv    -r
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out4x.csv   -r
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1nfn.csv o=./outdat/out4nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat3s.csv    o=./outdat/out5.csv    -r
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat3s.csv    o=./outdat/out5x.csv   -r
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat3snfn.csv o=./outdat/out5nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out6.csv    u=./outdat/out7.csv
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out6.csv    u=./outdat/out7x.csv
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out6nfn.csv u=./outdat/out7nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out8.csv    u=./outdat/out9.csv
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out8x.csv   u=./outdat/out9x.csv
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1nfn.csv o=./outdat/out8nfn.csv u=./outdat/out9nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat3s.csv    o=./outdat/out10.csv    u=./outdat/out11.csv
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat3s.csv    o=./outdat/out10x.csv   u=./outdat/out11x.csv
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat3snfn.csv o=./outdat/out10nfn.csv u=./outdat/out11nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out12.csv    u=./outdat/out13.csv    -r
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat1.csv    o=./outdat/out12x.csv   u=./outdat/out13x.csv   -r
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat1nfn.csv o=./outdat/out12nfn.csv u=./outdat/out13nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out14.csv    u=./outdat/out15.csv    -r
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat1.csv    o=./outdat/out14x.csv   u=./outdat/out15x.csv   -r
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat1nfn.csv o=./outdat/out14nfn.csv u=./outdat/out15nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat0.csv    m=./indat/dat3s.csv    o=./outdat/out16.csv    u=./outdat/out17.csv    -r
${pfxc}mnrcommon -x   R=1,2         rf=2%n    i=./indat/dat0.csv    m=./indat/dat3s.csv    o=./outdat/out16x.csv   u=./outdat/out17x.csv   -r
${pfxc}mnrcommon -nfn R=1,2         rf=2%n    i=./indat/dat0nfn.csv m=./indat/dat3snfn.csv o=./outdat/out16nfn.csv u=./outdat/out17nfn.csv -r

#基本
${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out18.csv    u=./outdat/out19.csv
${pfxc}mnrcommon -x   R=0,1         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out18x.csv   u=./outdat/out19x.csv
${pfxc}mnrcommon -nfn R=0,1         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out18nfn.csv u=./outdat/out19nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out20.csv    u=./outdat/out21.csv    -r
${pfxc}mnrcommon -x   R=0,1         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out20x.csv   u=./outdat/out21x.csv   -r
${pfxc}mnrcommon -nfn R=0,1         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out20nfn.csv u=./outdat/out21nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out22.csv    u=./outdat/out23.csv
${pfxc}mnrcommon -x   R=0,1         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out22x.csv   u=./outdat/out23x.csv
${pfxc}mnrcommon -nfn R=0,1         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out22nfn.csv u=./outdat/out23nfn.csv

${pfxc}mnrcommon      R=金額F,金額T rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out24.csv    u=./outdat/out25.csv    -r
${pfxc}mnrcommon -x   R=0,1         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out24x.csv   u=./outdat/out25x.csv   -r
${pfxc}mnrcommon -nfn R=0,1         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out24nfn.csv u=./outdat/out25nfn.csv -r

${pfxc}mnrcommon      R=金額F%n,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out26.csv    u=./outdat/out27.csv
${pfxc}mnrcommon -x   R=0%n,1         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out26x.csv   u=./outdat/out27x.csv
${pfxc}mnrcommon -nfn R=0%n,1         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out26nfn.csv u=./outdat/out27nfn.csv

${pfxc}mnrcommon      R=金額F%n,金額T rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out28.csv    u=./outdat/out29.csv    -r
${pfxc}mnrcommon -x   R=0%n,1         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out28x.csv   u=./outdat/out29x.csv   -r
${pfxc}mnrcommon -nfn R=0%n,1         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out28nfn.csv u=./outdat/out29nfn.csv -r

${pfxc}mnrcommon      R=金額F%n,金額T rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out30.csv    u=./outdat/out31.csv
${pfxc}mnrcommon -x   R=0%n,1         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out30x.csv   u=./outdat/out31x.csv
${pfxc}mnrcommon -nfn R=0%n,1         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out30nfn.csv u=./outdat/out31nfn.csv

${pfxc}mnrcommon      R=金額F%n,金額T rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out32.csv    u=./outdat/out33.csv    -r
${pfxc}mnrcommon -x   R=0%n,1         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out32x.csv   u=./outdat/out33x.csv   -r
${pfxc}mnrcommon -nfn R=0%n,1         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out32nfn.csv u=./outdat/out33nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T%e rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out34.csv    u=./outdat/out35.csv
${pfxc}mnrcommon -x   R=0,1%e         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out34x.csv   u=./outdat/out35x.csv
${pfxc}mnrcommon -nfn R=0,1%e         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out34nfn.csv u=./outdat/out35nfn.csv

${pfxc}mnrcommon      R=金額F,金額T%e rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out36.csv    u=./outdat/out37.csv    -r
${pfxc}mnrcommon -x   R=0,1%e         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out36x.csv   u=./outdat/out37x.csv   -r
${pfxc}mnrcommon -nfn R=0,1%e         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out36nfn.csv u=./outdat/out37nfn.csv -r

${pfxc}mnrcommon      R=金額F,金額T%e rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out38.csv    u=./outdat/out39.csv
${pfxc}mnrcommon -x   R=0,1%e         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out38x.csv   u=./outdat/out39x.csv
${pfxc}mnrcommon -nfn R=0,1%e         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out38nfn.csv u=./outdat/out39nfn.csv

${pfxc}mnrcommon      R=金額F,金額T%e rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out40.csv    u=./outdat/out41.csv    -r
${pfxc}mnrcommon -x   R=0,1%e         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out40x.csv   u=./outdat/out41x.csv   -r
${pfxc}mnrcommon -nfn R=0,1%e         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out40nfn.csv u=./outdat/out41nfn.csv -r

${pfxc}mnrcommon      R=金額F%n,金額T%e rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out42.csv    u=./outdat/out43.csv
${pfxc}mnrcommon -x   R=0%n,1%e         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out42x.csv   u=./outdat/out43x.csv
${pfxc}mnrcommon -nfn R=0%n,1%e         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out42nfn.csv u=./outdat/out43nfn.csv

${pfxc}mnrcommon      R=金額F%n,金額T%e rf=金額%n i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out44.csv    u=./outdat/out45.csv    -r
${pfxc}mnrcommon -x   R=0%n,1%e         rf=1%n    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out44x.csv   u=./outdat/out45x.csv   -r
${pfxc}mnrcommon -nfn R=0%n,1%e         rf=1%n    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out44nfn.csv u=./outdat/out45nfn.csv -r

${pfxc}mnrcommon      R=金額F%n,金額T%e rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out46.csv    u=./outdat/out47.csv
${pfxc}mnrcommon -x   R=0%n,1%e         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out46x.csv   u=./outdat/out47x.csv
${pfxc}mnrcommon -nfn R=0%n,1%e         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out46nfn.csv u=./outdat/out47nfn.csv

${pfxc}mnrcommon      R=金額F%n,金額T%e rf=金額 i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out48.csv    u=./outdat/out49.csv    -r
${pfxc}mnrcommon -x   R=0%n,1%e         rf=1    i=./indat/dat4.csv    m=./indat/dat5.csv    o=./outdat/out48x.csv   u=./outdat/out49x.csv   -r
${pfxc}mnrcommon -nfn R=0%n,1%e         rf=1    i=./indat/dat4nfn.csv m=./indat/dat5nfn.csv o=./outdat/out48nfn.csv u=./outdat/out49nfn.csv -r

#k=有
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out50.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out50x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out50nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out51.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out51x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out51nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out52.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out52x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out52nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out53.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out53x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out53nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out54.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out54x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out54nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out55.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out55x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out55nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out56.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out56x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out56nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out57.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out57x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out57nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out58.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out58x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out58nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out59.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out59x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out59nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out60.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out60x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out60nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out61.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out61x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out61nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out62.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out62x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out62nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out63.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out63x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out63nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out64.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out64x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out64nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out65.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat2s.csv    m=./indat/dat3s.csv    o=./outdat/out65x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat2snfn.csv m=./indat/dat3snfn.csv o=./outdat/out65nfn.csv -r

#k=二つ
${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out66.csv    u=./outdat/out67.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out66x.csv   u=./outdat/out67x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out66nfn.csv u=./outdat/out67nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out68.csv    u=./outdat/out69.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out68x.csv   u=./outdat/out69x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out68nfn.csv u=./outdat/out69nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out70.csv    u=./outdat/out71.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out70x.csv   u=./outdat/out71x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out70nfn.csv u=./outdat/out71nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out72.csv    u=./outdat/out73.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out72x.csv   u=./outdat/out73x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out72nfn.csv u=./outdat/out73nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out74.csv    u=./outdat/out75.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out74x.csv   u=./outdat/out75x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out74nfn.csv u=./outdat/out75nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out76.csv    u=./outdat/out77.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out76x.csv   u=./outdat/out77x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out76nfn.csv u=./outdat/out77nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out78.csv    u=./outdat/out79.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out78x.csv   u=./outdat/out79x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out78nfn.csv u=./outdat/out79nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out80.csv    u=./outdat/out81.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out80x.csv   u=./outdat/out81x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out80nfn.csv u=./outdat/out81nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out82.csv    u=./outdat/out83.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out82x.csv   u=./outdat/out83x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out82nfn.csv u=./outdat/out83nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out84.csv    u=./outdat/out85.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out84x.csv   u=./outdat/out85x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out84nfn.csv u=./outdat/out85nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out86.csv    u=./outdat/out87.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out86x.csv   u=./outdat/out87x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out86nfn.csv u=./outdat/out87nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out88.csv    u=./outdat/out89.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out88x.csv   u=./outdat/out89x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out88nfn.csv u=./outdat/out89nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out90.csv    u=./outdat/out91.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out90x.csv   u=./outdat/out91x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out90nfn.csv u=./outdat/out91nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out92.csv    u=./outdat/out93.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out92x.csv   u=./outdat/out93x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out92nfn.csv u=./outdat/out93nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out94.csv    u=./outdat/out95.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out94x.csv   u=./outdat/out95x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out94nfn.csv u=./outdat/out95nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out96.csv    u=./outdat/out97.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6s.csv    m=./indat/dat7s.csv    o=./outdat/out96x.csv   u=./outdat/out97x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6snfn.csv m=./indat/dat7snfn.csv o=./outdat/out96nfn.csv u=./outdat/out97nfn.csv -r

#R=にNULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out98.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out98x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out98nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out99.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out99x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out99nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out100.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out100x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out100nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out101.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out101x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out101nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out102.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out102x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out102nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out103.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out103x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out103nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out104.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out104x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out104nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out105.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out105x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out105nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out106.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out106x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out106nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out107.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out107x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out107nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out108.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out108x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out108nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out109.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out109x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out109nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out110.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out110x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out110nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out111.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out111x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out111nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out112.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out112x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out112nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out113.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat8s.csv    m=./indat/dat9s.csv    o=./outdat/out113x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat8snfn.csv m=./indat/dat9snfn.csv o=./outdat/out113nfn.csv -r

#rf=にNULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out114.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out114x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out114nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out115.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out115x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out115nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out116.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out116x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out116nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out117.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out117x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out117nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out118.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out118x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out118nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out119.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out119x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out119nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out120.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out120x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out120nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out121.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out121x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out121nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out122.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out122x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out122nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out123.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out123x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out123nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out124.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out124x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out124nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out125.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out125x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out125nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out126.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out126x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out126nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out127.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out127x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out127nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out128.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out128x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out128nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out129.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat11s.csv    o=./outdat/out129x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat11snfn.csv o=./outdat/out129nfn.csv -r

#rf=,R=にNULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out130.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out130x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out130nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out131.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out131x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out131nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額   i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out132.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2      i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out132x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2      i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out132nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out133.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out133x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out133nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out134.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out134x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out134nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out135.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out135x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out135nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out136.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out136x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out136nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out137.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out137x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out137nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out138.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out138x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out138nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out139.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out139x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out139nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out140.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out140x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out140nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out141.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out141x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out141nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out142.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out142x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out142nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out143.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out143x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out143nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out144.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out144x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out144nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out145.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10s.csv    m=./indat/dat9s.csv    o=./outdat/out145x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10snfn.csv m=./indat/dat9snfn.csv o=./outdat/out145nfn.csv -r

#ここまでOK
#k=NULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out146.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out146x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out146nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out147.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out147x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out147nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out148.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out148x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out148nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out149.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat12s.csv    m=./indat/dat13s.csv    o=./outdat/out149x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat12snfn.csv m=./indat/dat13snfn.csv o=./outdat/out149nfn.csv -r

#k=NULL二つ
${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out150.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out150x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat14snfn.csv m=./indat/dat15snfn.csv o=./outdat/out150nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out151.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out151x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat14snfn.csv m=./indat/dat15snfn.csv o=./outdat/out151nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out152.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out152x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat14snfn.csv m=./indat/dat15snfn.csv o=./outdat/out152nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out153.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat14s.csv    m=./indat/dat15s.csv    o=./outdat/out153x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat14snfn.csv m=./indat/dat15snfn.csv o=./outdat/out153nfn.csv -r



#-----------------------------------------------------------------
# 以下ランダムデータ
#-----------------------------------------------------------------
#k=有
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out250.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out250x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out250nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out251.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out251x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out251nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out252.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out252x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out252nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out253.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out253x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out253nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out254.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out254x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out254nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out255.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out255x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out255nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out256.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out256x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out256nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out257.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out257x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out257nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out258.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out258x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out258nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out259.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out259x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out259nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out260.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out260x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out260nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out261.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out261x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out261nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out262.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out262x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out262nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out263.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out263x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out263nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out264.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out264x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out264nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out265.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat2.csv    m=./indat/dat3.csv    o=./outdat/out265x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat2nfn.csv m=./indat/dat3nfn.csv o=./outdat/out265nfn.csv -r

#k=二つ
${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out266.csv    u=./outdat/out267.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out266x.csv   u=./outdat/out267x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out266nfn.csv u=./outdat/out267nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out268.csv    u=./outdat/out269.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out268x.csv   u=./outdat/out269x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out268nfn.csv u=./outdat/out269nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out270.csv    u=./outdat/out271.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out270x.csv   u=./outdat/out271x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out270nfn.csv u=./outdat/out271nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out272.csv    u=./outdat/out273.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out272x.csv   u=./outdat/out273x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out272nfn.csv u=./outdat/out273nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out274.csv    u=./outdat/out275.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out274x.csv   u=./outdat/out275x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out274nfn.csv u=./outdat/out275nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out276.csv    u=./outdat/out277.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out276x.csv   u=./outdat/out277x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out276nfn.csv u=./outdat/out277nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out278.csv    u=./outdat/out279.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out278x.csv   u=./outdat/out279x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out278nfn.csv u=./outdat/out279nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out280.csv    u=./outdat/out281.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out280x.csv   u=./outdat/out281x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out280nfn.csv u=./outdat/out281nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out282.csv    u=./outdat/out283.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out282x.csv   u=./outdat/out283x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out282nfn.csv u=./outdat/out283nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out284.csv    u=./outdat/out285.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out284x.csv   u=./outdat/out285x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out284nfn.csv u=./outdat/out285nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out286.csv    u=./outdat/out287.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out286x.csv   u=./outdat/out287x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out286nfn.csv u=./outdat/out287nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T%e rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out288.csv    u=./outdat/out289.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3%e         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out288x.csv   u=./outdat/out289x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3%e         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out288nfn.csv u=./outdat/out289nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out290.csv    u=./outdat/out291.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out290x.csv   u=./outdat/out291x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out290nfn.csv u=./outdat/out291nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out292.csv    u=./outdat/out293.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out292x.csv   u=./outdat/out293x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3%n    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out292nfn.csv u=./outdat/out293nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out294.csv    u=./outdat/out295.csv
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out294x.csv   u=./outdat/out295x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out294nfn.csv u=./outdat/out295nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out296.csv    u=./outdat/out297.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6.csv    m=./indat/dat7.csv    o=./outdat/out296x.csv   u=./outdat/out297x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2%n,3%e         rf=3    i=./indat/dat6nfn.csv m=./indat/dat7nfn.csv o=./outdat/out296nfn.csv u=./outdat/out297nfn.csv -r

#R=にNULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out298.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out298x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out298nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out299.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out299x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out299nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out300.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out300x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out300nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out301.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out301x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out301nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out302.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out302x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out302nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out303.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out303x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out303nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out304.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out304x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out304nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out305.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out305x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out305nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out306.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out306x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out306nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out307.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out307x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out307nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out308.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out308x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out308nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out309.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out309x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out309nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out310.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out310x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out310nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out311.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out311x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out311nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out312.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out312x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out312nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out313.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat8.csv    m=./indat/dat9.csv    o=./outdat/out313x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat8nfn.csv m=./indat/dat9nfn.csv o=./outdat/out313nfn.csv -r

#rf=にNULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out314.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out314x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out314nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out315.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out315x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out315nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out316.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out316x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out316nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out317.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out317x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out317nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out318.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out318x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out318nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out319.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out319x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out319nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out320.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out320x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out320nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out321.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out321x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out321nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out322.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out322x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out322nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out323.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out323x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out323nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out324.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out324x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out324nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out325.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out325x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out325nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out326.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out326x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out326nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out327.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out327x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out327nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out328.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out328x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out328nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out329.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat11.csv    o=./outdat/out329x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat11nfn.csv o=./outdat/out329nfn.csv -r

#rf=,R=にNULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out330.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out330x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out330nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out331.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out331x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out331nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額   i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out332.csv
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2      i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out332x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2      i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out332nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out333.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out333x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out333nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out334.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out334x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out334nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out335.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out335x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out335nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out336.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out336x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out336nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out337.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out337x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out337nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out338.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out338x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out338nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out339.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out339x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out339nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out340.csv
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out340x.csv
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out340nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out341.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out341x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out341nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out342.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out342x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out342nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額%n i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out343.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out343x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2%n    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out343nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out344.csv
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out344x.csv
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out344nfn.csv

${pfxc}mnrcommon      k=日付 R=金額F%n,金額T%e rf=金額 i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out345.csv    -r
${pfxc}mnrcommon -x   k=0    R=1%n,2%e         rf=2    i=./indat/dat10.csv    m=./indat/dat9.csv    o=./outdat/out345x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1%n,2%e         rf=2    i=./indat/dat10nfn.csv m=./indat/dat9nfn.csv o=./outdat/out345nfn.csv -r

#ここまでOK
#k=NULL
${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out346.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out346x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat12nfn.csv m=./indat/dat13nfn.csv o=./outdat/out346nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額%n i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out347.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2%n    i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out347x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2%n    i=./indat/dat12nfn.csv m=./indat/dat13nfn.csv o=./outdat/out347nfn.csv -r

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out348.csv 
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out348x.csv 
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat12nfn.csv m=./indat/dat13nfn.csv o=./outdat/out348nfn.csv 

${pfxc}mnrcommon      k=日付 R=金額F,金額T rf=金額 i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out349.csv    -r
${pfxc}mnrcommon -x   k=0    R=1,2         rf=2    i=./indat/dat12.csv    m=./indat/dat13.csv    o=./outdat/out349x.csv   -r
${pfxc}mnrcommon -nfn k=0    R=1,2         rf=2    i=./indat/dat12nfn.csv m=./indat/dat13nfn.csv o=./outdat/out349nfn.csv -r

#k=NULL二つ
${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out350.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out350x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat14nfn.csv m=./indat/dat15nfn.csv o=./outdat/out350nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額%n i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out351.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3%n    i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out351x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3%n    i=./indat/dat14nfn.csv m=./indat/dat15nfn.csv o=./outdat/out351nfn.csv -r

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out352.csv
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out352x.csv
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat14nfn.csv m=./indat/dat15nfn.csv o=./outdat/out352nfn.csv

${pfxc}mnrcommon      k=顧客,日付 R=金額F,金額T rf=金額 i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out353.csv    -r
${pfxc}mnrcommon -x   k=0,1       R=2,3         rf=3    i=./indat/dat14.csv    m=./indat/dat15.csv    o=./outdat/out353x.csv   -r
${pfxc}mnrcommon -nfn k=0,1       R=2,3         rf=3    i=./indat/dat14nfn.csv m=./indat/dat15nfn.csv o=./outdat/out353nfn.csv -r




