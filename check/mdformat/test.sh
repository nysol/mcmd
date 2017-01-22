#!/bin/bash

. ../env
#name_kg_mcmd dformat
#null data
${pfxc}mdformat      f=fld c=a:%Y%m%d:b:%H%M%S i=./indat/dat0.csv o=./outdat/out0.csv
${pfxc}mdformat -x   f=1   c=a:%Y%m%d:b:%H%M%S i=./indat/dat0.csv o=./outdat/out0x.csv
${pfxc}mdformat -nfn f=1   c=a:%Y%m%d:b:%H%M%S i=./indat/dat0nfn.csv o=./outdat/out0nfn.csv


${pfxc}mdformat      f=fld,fld2 c=a:%Y%m%d:b:%H%M%S i=./indat/dat1.csv o=./outdat/out1.csv
${pfxc}mdformat -x   f=1,2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1.csv o=./outdat/out1x.csv
${pfxc}mdformat -nfn f=1,2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1nfn.csv o=./outdat/out1nfn.csv

${pfxc}mdformat      f=fld,fld2 c=%Y/%m/%d i=./indat/dat2.csv o=./outdat/out2.csv
${pfxc}mdformat -x   f=1,2      c=%Y/%m/%d i=./indat/dat2.csv o=./outdat/out2x.csv
${pfxc}mdformat -nfn f=1,2      c=%Y/%m/%d i=./indat/dat2nfn.csv o=./outdat/out2nfn.csv

${pfxc}mdformat      f=fld c=%H:%M:%S i=./indat/dat3.csv o=./outdat/out3.csv
${pfxc}mdformat -x   f=1   c=%H:%M:%S i=./indat/dat3.csv o=./outdat/out3x.csv
${pfxc}mdformat -nfn f=1   c=%H:%M:%S i=./indat/dat3nfn.csv o=./outdat/out3nfn.csv

${pfxc}mdformat      f=fld,fld2 c=%y/%m i=./indat/dat4.csv o=./outdat/out4.csv
${pfxc}mdformat -x   f=1,2      c=%y/%m i=./indat/dat4.csv o=./outdat/out4x.csv
${pfxc}mdformat -nfn f=1,2      c=%y/%m i=./indat/dat4nfn.csv o=./outdat/out4nfn.csv

${pfxc}mdformat      f=fld,fld2 c=%m/%d i=./indat/dat5.csv o=./outdat/out5.csv
${pfxc}mdformat -x   f=1,2      c=%m/%d i=./indat/dat5.csv o=./outdat/out5x.csv
${pfxc}mdformat -nfn f=1,2      c=%m/%d i=./indat/dat5nfn.csv o=./outdat/out5nfn.csv

${pfxc}mdformat      f=fld c=%H:%M i=./indat/dat6.csv o=./outdat/out6.csv
${pfxc}mdformat -x   f=1   c=%H:%M i=./indat/dat6.csv o=./outdat/out6x.csv
${pfxc}mdformat -nfn f=1   c=%H:%M i=./indat/dat6nfn.csv o=./outdat/out6nfn.csv


${pfxc}mdformat      f=fld c=@%H i=./indat/dat7.csv o=./outdat/out7.csv
${pfxc}mdformat -x   f=1   c=@%H i=./indat/dat7.csv o=./outdat/out7x.csv
${pfxc}mdformat -nfn f=1   c=@%H i=./indat/dat7nfn.csv o=./outdat/out7nfn.csv

${pfxc}mdformat      f=fld c=@%M@ i=./indat/dat8.csv o=./outdat/out8.csv
${pfxc}mdformat -x   f=1   c=@%M@ i=./indat/dat8.csv o=./outdat/out8x.csv
${pfxc}mdformat -nfn f=1   c=@%M@ i=./indat/dat8nfn.csv o=./outdat/out8nfn.csv

${pfxc}mdformat      f=fld c=%S@ i=./indat/dat9.csv o=./outdat/out9.csv
${pfxc}mdformat -x   f=1   c=%S@ i=./indat/dat9.csv o=./outdat/out9x.csv
${pfxc}mdformat -nfn f=1   c=%S@ i=./indat/dat9nfn.csv o=./outdat/out9nfn.csv


${pfxc}mdformat      f=fld c=*%Y i=./indat/dat10.csv o=./outdat/out10.csv
${pfxc}mdformat -x   f=1   c=*%Y i=./indat/dat10.csv o=./outdat/out10x.csv
${pfxc}mdformat -nfn f=1   c=*%Y i=./indat/dat10nfn.csv o=./outdat/out10nfn.csv

${pfxc}mdformat      f=fld c=*%m* i=./indat/dat11.csv o=./outdat/out11.csv
${pfxc}mdformat -x   f=1   c=*%m* i=./indat/dat11.csv o=./outdat/out11x.csv
${pfxc}mdformat -nfn f=1   c=*%m* i=./indat/dat11nfn.csv o=./outdat/out11nfn.csv

${pfxc}mdformat      f=fld c=%d* i=./indat/dat12.csv o=./outdat/out12.csv
${pfxc}mdformat -x   f=1   c=%d* i=./indat/dat12.csv o=./outdat/out12x.csv
${pfxc}mdformat -nfn f=1   c=%d* i=./indat/dat12nfn.csv o=./outdat/out12nfn.csv

${pfxc}mdformat      f=fld c=*%y i=./indat/dat13.csv o=./outdat/out13.csv
${pfxc}mdformat -x   f=1   c=*%y i=./indat/dat13.csv o=./outdat/out13x.csv
${pfxc}mdformat -nfn f=1   c=*%y i=./indat/dat13nfn.csv o=./outdat/out13nfn.csv


${pfxc}mdformat      f=fld:nfld,fld2:nfld2 c=a:%Y%m%d:b:%H%M%S i=./indat/dat1.csv o=./outdat/out14.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1.csv o=./outdat/out14x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1nfn.csv o=./outdat/out14nfn.csv

${pfxc}mdformat      f=fld:nfld,fld2:nfld2  c=%Y/%m/%d i=./indat/dat2.csv o=./outdat/out15.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2.csv o=./outdat/out15x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2nfn.csv o=./outdat/out15nfn.csv

${pfxc}mdformat      f=fld:nfld c=%H:%M:%S i=./indat/dat3.csv o=./outdat/out16.csv
${pfxc}mdformat -x   f=1:nfld   c=%H:%M:%S i=./indat/dat3.csv o=./outdat/out16x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%H:%M:%S i=./indat/dat3nfn.csv o=./outdat/out16nfn.csv

${pfxc}mdformat      f=fld:nfld,fld2:nfld2 c=%y/%m i=./indat/dat4.csv o=./outdat/out17.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4.csv o=./outdat/out17x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4nfn.csv o=./outdat/out17nfn.csv

${pfxc}mdformat      f=fld:nfld,fld2:nfld2 c=%m/%d i=./indat/dat5.csv o=./outdat/out18.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5.csv o=./outdat/out18x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5nfn.csv o=./outdat/out18nfn.csv

${pfxc}mdformat      f=fld:nfld c=%H:%M i=./indat/dat6.csv o=./outdat/out19.csv
${pfxc}mdformat -x   f=1:nfld   c=%H:%M i=./indat/dat6.csv o=./outdat/out19x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%H:%M i=./indat/dat6nfn.csv o=./outdat/out19nfn.csv


${pfxc}mdformat      f=fld:nfld c=@%H i=./indat/dat7.csv o=./outdat/out20.csv
${pfxc}mdformat -x   f=1:nfld   c=@%H i=./indat/dat7.csv o=./outdat/out20x.csv
${pfxc}mdformat -nfn f=1:nfld   c=@%H i=./indat/dat7nfn.csv o=./outdat/out20nfn.csv

${pfxc}mdformat      f=fld:nfld c=@%M@ i=./indat/dat8.csv o=./outdat/out21.csv
${pfxc}mdformat -x   f=1:nfld   c=@%M@ i=./indat/dat8.csv o=./outdat/out21x.csv
${pfxc}mdformat -nfn f=1:nfld   c=@%M@ i=./indat/dat8nfn.csv o=./outdat/out21nfn.csv

${pfxc}mdformat      f=fld:nfld c=%S@ i=./indat/dat9.csv o=./outdat/out22.csv
${pfxc}mdformat -x   f=1:nfld   c=%S@ i=./indat/dat9.csv o=./outdat/out22x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%S@ i=./indat/dat9nfn.csv o=./outdat/out22nfn.csv

${pfxc}mdformat      f=fld:nfld c=*%Y i=./indat/dat10.csv o=./outdat/out23.csv
${pfxc}mdformat -x   f=1:nfld   c=*%Y i=./indat/dat10.csv o=./outdat/out23x.csv
${pfxc}mdformat -nfn f=1:nfld   c=*%Y i=./indat/dat10nfn.csv o=./outdat/out23nfn.csv

${pfxc}mdformat      f=fld:nfld c=*%m* i=./indat/dat11.csv o=./outdat/out24.csv
${pfxc}mdformat -x   f=1:nfld   c=*%m* i=./indat/dat11.csv o=./outdat/out24x.csv
${pfxc}mdformat -nfn f=1:nfld   c=*%m* i=./indat/dat11nfn.csv o=./outdat/out24nfn.csv

${pfxc}mdformat      f=fld:nfld c=%d* i=./indat/dat12.csv o=./outdat/out25.csv
${pfxc}mdformat -x   f=1:nfld   c=%d* i=./indat/dat12.csv o=./outdat/out25x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%d* i=./indat/dat12nfn.csv o=./outdat/out25nfn.csv

${pfxc}mdformat      f=fld:nfld c=*%y i=./indat/dat13.csv o=./outdat/out26.csv
${pfxc}mdformat -x   f=1:nfld   c=*%y i=./indat/dat13.csv o=./outdat/out26x.csv
${pfxc}mdformat -nfn f=1:nfld   c=*%y i=./indat/dat13nfn.csv o=./outdat/out26nfn.csv


${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2 c=a:%Y%m%d:b:%H%M%S i=./indat/dat1.csv o=./outdat/out27.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1.csv o=./outdat/out27x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1nfn.csv o=./outdat/out27nfn.csv

${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2  c=%Y/%m/%d i=./indat/dat2.csv o=./outdat/out28.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2.csv o=./outdat/out28x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2nfn.csv o=./outdat/out28nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%H:%M:%S i=./indat/dat3.csv o=./outdat/out29.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%H:%M:%S i=./indat/dat3.csv o=./outdat/out29x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%H:%M:%S i=./indat/dat3nfn.csv o=./outdat/out29nfn.csv

${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2 c=%y/%m i=./indat/dat4.csv o=./outdat/out30.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4.csv o=./outdat/out30x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4nfn.csv o=./outdat/out30nfn.csv

${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2 c=%m/%d i=./indat/dat5.csv o=./outdat/out31.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5.csv o=./outdat/out31x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5nfn.csv o=./outdat/out31nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%H:%M i=./indat/dat6.csv o=./outdat/out32.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%H:%M i=./indat/dat6.csv o=./outdat/out32x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%H:%M i=./indat/dat6nfn.csv o=./outdat/out32nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=@%H i=./indat/dat7.csv o=./outdat/out33.csv
${pfxc}mdformat -x   -A f=1:nfld   c=@%H i=./indat/dat7.csv o=./outdat/out33x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=@%H i=./indat/dat7nfn.csv o=./outdat/out33nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=@%M@ i=./indat/dat8.csv o=./outdat/out34.csv
${pfxc}mdformat -x   -A f=1:nfld   c=@%M@ i=./indat/dat8.csv o=./outdat/out34x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=@%M@ i=./indat/dat8nfn.csv o=./outdat/out34nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%S@ i=./indat/dat9.csv o=./outdat/out35.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%S@ i=./indat/dat9.csv o=./outdat/out35x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%S@ i=./indat/dat9nfn.csv o=./outdat/out35nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=*%Y i=./indat/dat10.csv o=./outdat/out36.csv
${pfxc}mdformat -x   -A f=1:nfld   c=*%Y i=./indat/dat10.csv o=./outdat/out36x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=*%Y i=./indat/dat10nfn.csv o=./outdat/out36nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=*%m* i=./indat/dat11.csv o=./outdat/out37.csv
${pfxc}mdformat -x   -A f=1:nfld   c=*%m* i=./indat/dat11.csv o=./outdat/out37x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=*%m* i=./indat/dat11nfn.csv o=./outdat/out37nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%d* i=./indat/dat12.csv o=./outdat/out38.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%d* i=./indat/dat12.csv o=./outdat/out38x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%d* i=./indat/dat12nfn.csv o=./outdat/out38nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=*%y i=./indat/dat13.csv o=./outdat/out39.csv
${pfxc}mdformat -x   -A f=1:nfld   c=*%y i=./indat/dat13.csv o=./outdat/out39x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=*%y i=./indat/dat13nfn.csv o=./outdat/out39nfn.csv




#ソートデータ
${pfxc}mdformat      f=fld,fld2 c=a:%Y%m%d:b:%H%M%S i=./indat/dat1s.csv o=./outdat/out51.csv
${pfxc}mdformat -x   f=1,2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1s.csv o=./outdat/out51x.csv
${pfxc}mdformat -nfn f=1,2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1snfn.csv o=./outdat/out51nfn.csv

${pfxc}mdformat      f=fld,fld2 c=%Y/%m/%d i=./indat/dat2s.csv o=./outdat/out52.csv
${pfxc}mdformat -x   f=1,2      c=%Y/%m/%d i=./indat/dat2s.csv o=./outdat/out52x.csv
${pfxc}mdformat -nfn f=1,2      c=%Y/%m/%d i=./indat/dat2snfn.csv o=./outdat/out52nfn.csv

${pfxc}mdformat      f=fld c=%H:%M:%S i=./indat/dat3s.csv o=./outdat/out53.csv
${pfxc}mdformat -x   f=1   c=%H:%M:%S i=./indat/dat3s.csv o=./outdat/out53x.csv
${pfxc}mdformat -nfn f=1   c=%H:%M:%S i=./indat/dat3snfn.csv o=./outdat/out53nfn.csv

${pfxc}mdformat      f=fld,fld2 c=%y/%m i=./indat/dat4s.csv o=./outdat/out54.csv
${pfxc}mdformat -x   f=1,2      c=%y/%m i=./indat/dat4s.csv o=./outdat/out54x.csv
${pfxc}mdformat -nfn f=1,2      c=%y/%m i=./indat/dat4snfn.csv o=./outdat/out54nfn.csv

${pfxc}mdformat      f=fld,fld2 c=%m/%d i=./indat/dat5s.csv o=./outdat/out55.csv
${pfxc}mdformat -x   f=1,2      c=%m/%d i=./indat/dat5s.csv o=./outdat/out55x.csv
${pfxc}mdformat -nfn f=1,2      c=%m/%d i=./indat/dat5snfn.csv o=./outdat/out55nfn.csv

${pfxc}mdformat      f=fld c=%H:%M i=./indat/dat6s.csv o=./outdat/out56.csv
${pfxc}mdformat -x   f=1   c=%H:%M i=./indat/dat6s.csv o=./outdat/out56x.csv
${pfxc}mdformat -nfn f=1   c=%H:%M i=./indat/dat6snfn.csv o=./outdat/out56nfn.csv


${pfxc}mdformat      f=fld c=@%H i=./indat/dat7s.csv o=./outdat/out57.csv
${pfxc}mdformat -x   f=1   c=@%H i=./indat/dat7s.csv o=./outdat/out57x.csv
${pfxc}mdformat -nfn f=1   c=@%H i=./indat/dat7snfn.csv o=./outdat/out57nfn.csv

${pfxc}mdformat      f=fld c=@%M@ i=./indat/dat8s.csv o=./outdat/out58.csv
${pfxc}mdformat -x   f=1   c=@%M@ i=./indat/dat8s.csv o=./outdat/out58x.csv
${pfxc}mdformat -nfn f=1   c=@%M@ i=./indat/dat8snfn.csv o=./outdat/out58nfn.csv

${pfxc}mdformat      f=fld c=%S@ i=./indat/dat9s.csv o=./outdat/out59.csv
${pfxc}mdformat -x   f=1   c=%S@ i=./indat/dat9s.csv o=./outdat/out59x.csv
${pfxc}mdformat -nfn f=1   c=%S@ i=./indat/dat9snfn.csv o=./outdat/out59nfn.csv


${pfxc}mdformat      f=fld c=*%Y i=./indat/dat10s.csv o=./outdat/out60.csv
${pfxc}mdformat -x   f=1   c=*%Y i=./indat/dat10s.csv o=./outdat/out60x.csv
${pfxc}mdformat -nfn f=1   c=*%Y i=./indat/dat10snfn.csv o=./outdat/out60nfn.csv

${pfxc}mdformat      f=fld c=*%m* i=./indat/dat11s.csv o=./outdat/out61.csv
${pfxc}mdformat -x   f=1   c=*%m* i=./indat/dat11s.csv o=./outdat/out61x.csv
${pfxc}mdformat -nfn f=1   c=*%m* i=./indat/dat11snfn.csv o=./outdat/out61nfn.csv

${pfxc}mdformat      f=fld c=%d* i=./indat/dat12s.csv o=./outdat/out62.csv
${pfxc}mdformat -x   f=1   c=%d* i=./indat/dat12s.csv o=./outdat/out62x.csv
${pfxc}mdformat -nfn f=1   c=%d* i=./indat/dat12snfn.csv o=./outdat/out62nfn.csv

${pfxc}mdformat      f=fld c=*%y i=./indat/dat13s.csv o=./outdat/out63.csv
${pfxc}mdformat -x   f=1   c=*%y i=./indat/dat13s.csv o=./outdat/out63x.csv
${pfxc}mdformat -nfn f=1   c=*%y i=./indat/dat13snfn.csv o=./outdat/out63nfn.csv


${pfxc}mdformat      f=fld:nfld,fld2:nfld2 c=a:%Y%m%d:b:%H%M%S i=./indat/dat1s.csv o=./outdat/out64.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1s.csv o=./outdat/out64x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1snfn.csv o=./outdat/out64nfn.csv

${pfxc}mdformat      f=fld:nfld,fld2:nfld2  c=%Y/%m/%d i=./indat/dat2s.csv o=./outdat/out65.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2s.csv o=./outdat/out65x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2snfn.csv o=./outdat/out65nfn.csv

${pfxc}mdformat      f=fld:nfld c=%H:%M:%S i=./indat/dat3s.csv o=./outdat/out66.csv
${pfxc}mdformat -x   f=1:nfld   c=%H:%M:%S i=./indat/dat3s.csv o=./outdat/out66x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%H:%M:%S i=./indat/dat3snfn.csv o=./outdat/out66nfn.csv

${pfxc}mdformat      f=fld:nfld,fld2:nfld2 c=%y/%m i=./indat/dat4s.csv o=./outdat/out67.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4s.csv o=./outdat/out67x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4snfn.csv o=./outdat/out67nfn.csv

${pfxc}mdformat      f=fld:nfld,fld2:nfld2 c=%m/%d i=./indat/dat5s.csv o=./outdat/out68.csv
${pfxc}mdformat -x   f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5s.csv o=./outdat/out68x.csv
${pfxc}mdformat -nfn f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5snfn.csv o=./outdat/out68nfn.csv

${pfxc}mdformat      f=fld:nfld c=%H:%M i=./indat/dat6s.csv o=./outdat/out69.csv
${pfxc}mdformat -x   f=1:nfld   c=%H:%M i=./indat/dat6s.csv o=./outdat/out69x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%H:%M i=./indat/dat6snfn.csv o=./outdat/out69nfn.csv


${pfxc}mdformat      f=fld:nfld c=@%H i=./indat/dat7s.csv o=./outdat/out70.csv
${pfxc}mdformat -x   f=1:nfld   c=@%H i=./indat/dat7s.csv o=./outdat/out70x.csv
${pfxc}mdformat -nfn f=1:nfld   c=@%H i=./indat/dat7snfn.csv o=./outdat/out70nfn.csv

${pfxc}mdformat      f=fld:nfld c=@%M@ i=./indat/dat8s.csv o=./outdat/out71.csv
${pfxc}mdformat -x   f=1:nfld   c=@%M@ i=./indat/dat8s.csv o=./outdat/out71x.csv
${pfxc}mdformat -nfn f=1:nfld   c=@%M@ i=./indat/dat8snfn.csv o=./outdat/out71nfn.csv

${pfxc}mdformat      f=fld:nfld c=%S@ i=./indat/dat9s.csv o=./outdat/out72.csv
${pfxc}mdformat -x   f=1:nfld   c=%S@ i=./indat/dat9s.csv o=./outdat/out72x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%S@ i=./indat/dat9snfn.csv o=./outdat/out72nfn.csv

${pfxc}mdformat      f=fld:nfld c=*%Y i=./indat/dat10s.csv o=./outdat/out73.csv
${pfxc}mdformat -x   f=1:nfld   c=*%Y i=./indat/dat10s.csv o=./outdat/out73x.csv
${pfxc}mdformat -nfn f=1:nfld   c=*%Y i=./indat/dat10snfn.csv o=./outdat/out73nfn.csv

${pfxc}mdformat      f=fld:nfld c=*%m* i=./indat/dat11s.csv o=./outdat/out74.csv
${pfxc}mdformat -x   f=1:nfld   c=*%m* i=./indat/dat11s.csv o=./outdat/out74x.csv
${pfxc}mdformat -nfn f=1:nfld   c=*%m* i=./indat/dat11snfn.csv o=./outdat/out74nfn.csv

${pfxc}mdformat      f=fld:nfld c=%d* i=./indat/dat12s.csv o=./outdat/out75.csv
${pfxc}mdformat -x   f=1:nfld   c=%d* i=./indat/dat12s.csv o=./outdat/out75x.csv
${pfxc}mdformat -nfn f=1:nfld   c=%d* i=./indat/dat12snfn.csv o=./outdat/out75nfn.csv

${pfxc}mdformat      f=fld:nfld c=*%y i=./indat/dat13s.csv o=./outdat/out76.csv
${pfxc}mdformat -x   f=1:nfld   c=*%y i=./indat/dat13s.csv o=./outdat/out76x.csv
${pfxc}mdformat -nfn f=1:nfld   c=*%y i=./indat/dat13snfn.csv o=./outdat/out76nfn.csv


${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2 c=a:%Y%m%d:b:%H%M%S i=./indat/dat1s.csv o=./outdat/out77.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1s.csv o=./outdat/out77x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2      c=a:%Y%m%d:b:%H%M%S i=./indat/dat1snfn.csv o=./outdat/out77nfn.csv

${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2  c=%Y/%m/%d i=./indat/dat2s.csv o=./outdat/out78.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2s.csv o=./outdat/out78x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2       c=%Y/%m/%d i=./indat/dat2snfn.csv o=./outdat/out78nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%H:%M:%S i=./indat/dat3s.csv o=./outdat/out79.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%H:%M:%S i=./indat/dat3s.csv o=./outdat/out79x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%H:%M:%S i=./indat/dat3snfn.csv o=./outdat/out79nfn.csv

${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2 c=%y/%m i=./indat/dat4s.csv o=./outdat/out80.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4s.csv o=./outdat/out80x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2      c=%y/%m i=./indat/dat4snfn.csv o=./outdat/out80nfn.csv

${pfxc}mdformat      -A f=fld:nfld,fld2:nfld2 c=%m/%d i=./indat/dat5s.csv o=./outdat/out81.csv
${pfxc}mdformat -x   -A f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5s.csv o=./outdat/out81x.csv
${pfxc}mdformat -nfn -A f=1:nfld,2:nfld2      c=%m/%d i=./indat/dat5snfn.csv o=./outdat/out81nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%H:%M i=./indat/dat6s.csv o=./outdat/out82.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%H:%M i=./indat/dat6s.csv o=./outdat/out82x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%H:%M i=./indat/dat6snfn.csv o=./outdat/out82nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=@%H i=./indat/dat7s.csv o=./outdat/out83.csv
${pfxc}mdformat -x   -A f=1:nfld   c=@%H i=./indat/dat7s.csv o=./outdat/out83x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=@%H i=./indat/dat7snfn.csv o=./outdat/out83nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=@%M@ i=./indat/dat8s.csv o=./outdat/out84.csv
${pfxc}mdformat -x   -A f=1:nfld   c=@%M@ i=./indat/dat8s.csv o=./outdat/out84x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=@%M@ i=./indat/dat8snfn.csv o=./outdat/out84nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%S@ i=./indat/dat9s.csv o=./outdat/out85.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%S@ i=./indat/dat9s.csv o=./outdat/out85x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%S@ i=./indat/dat9snfn.csv o=./outdat/out85nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=*%Y i=./indat/dat10s.csv o=./outdat/out86.csv
${pfxc}mdformat -x   -A f=1:nfld   c=*%Y i=./indat/dat10s.csv o=./outdat/out86x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=*%Y i=./indat/dat10snfn.csv o=./outdat/out86nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=*%m* i=./indat/dat11s.csv o=./outdat/out87.csv
${pfxc}mdformat -x   -A f=1:nfld   c=*%m* i=./indat/dat11s.csv o=./outdat/out87x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=*%m* i=./indat/dat11snfn.csv o=./outdat/out87nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=%d* i=./indat/dat12s.csv o=./outdat/out88.csv
${pfxc}mdformat -x   -A f=1:nfld   c=%d* i=./indat/dat12s.csv o=./outdat/out88x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=%d* i=./indat/dat12snfn.csv o=./outdat/out88nfn.csv

${pfxc}mdformat      -A f=fld:nfld c=*%y i=./indat/dat13s.csv o=./outdat/out89.csv
${pfxc}mdformat -x   -A f=1:nfld   c=*%y i=./indat/dat13s.csv o=./outdat/out89x.csv
${pfxc}mdformat -nfn -A f=1:nfld   c=*%y i=./indat/dat13snfn.csv o=./outdat/out89nfn.csv



#フォーマットエラーデータ
${pfxc}mdformat      f=fld c=%Y%m%d i=./indat/dat14.csv o=./outdat/out100.csv
${pfxc}mdformat -x   f=1   c=%Y%m%d i=./indat/dat14.csv o=./outdat/out100x.csv
${pfxc}mdformat -nfn f=1   c=%Y%m%d i=./indat/dat14nfn.csv o=./outdat/out100nfn.csv

${pfxc}mdformat      f=fld2 c='(%Y)' i=./indat/dat14.csv o=./outdat/out101.csv
${pfxc}mdformat -x   f=2   c='(%Y)' i=./indat/dat14.csv o=./outdat/out101x.csv
${pfxc}mdformat -nfn f=2   c='(%Y)' i=./indat/dat14nfn.csv o=./outdat/out101nfn.csv

${pfxc}mdformat      f=fld2 c='(%y)' i=./indat/dat14.csv o=./outdat/out102.csv
${pfxc}mdformat -x   f=2   c='(%y)' i=./indat/dat14.csv o=./outdat/out102x.csv
${pfxc}mdformat -nfn f=2   c='(%y)' i=./indat/dat14nfn.csv o=./outdat/out102nfn.csv

${pfxc}mdformat      f=fld2 c='(%m)' i=./indat/dat14.csv o=./outdat/out103.csv
${pfxc}mdformat -x   f=2   c='(%m)' i=./indat/dat14.csv o=./outdat/out103x.csv
${pfxc}mdformat -nfn f=2   c='(%m)' i=./indat/dat14nfn.csv o=./outdat/out103nfn.csv

${pfxc}mdformat      f=fld2 c='(%d)' i=./indat/dat14.csv o=./outdat/out104.csv
${pfxc}mdformat -x   f=2   c='(%d)' i=./indat/dat14.csv o=./outdat/out104x.csv
${pfxc}mdformat -nfn f=2   c='(%d)' i=./indat/dat14nfn.csv o=./outdat/out104nfn.csv

${pfxc}mdformat      f=fld2 c='(%H)' i=./indat/dat14.csv o=./outdat/out105.csv
${pfxc}mdformat -x   f=2   c='(%H)' i=./indat/dat14.csv o=./outdat/out105x.csv
${pfxc}mdformat -nfn f=2   c='(%H)' i=./indat/dat14nfn.csv o=./outdat/out105nfn.csv

${pfxc}mdformat      f=fld2 c='(%M)' i=./indat/dat14.csv o=./outdat/out106.csv
${pfxc}mdformat -x   f=2   c='(%M)' i=./indat/dat14.csv o=./outdat/out106x.csv
${pfxc}mdformat -nfn f=2   c='(%M)' i=./indat/dat14nfn.csv o=./outdat/out106nfn.csv

${pfxc}mdformat      f=fld2 c='(%S)' i=./indat/dat14.csv o=./outdat/out107.csv
${pfxc}mdformat -x   f=2   c='(%S)' i=./indat/dat14.csv o=./outdat/out107x.csv
${pfxc}mdformat -nfn f=2   c='(%S)' i=./indat/dat14nfn.csv o=./outdat/out107nfn.csv

${pfxc}mdformat      f=fld3 c='%m/%d' i=./indat/dat14.csv o=./outdat/out108.csv
${pfxc}mdformat -x   f=3   c='%m/%d' i=./indat/dat14.csv o=./outdat/out108x.csv
${pfxc}mdformat -nfn f=3   c='%m/%d' i=./indat/dat14nfn.csv o=./outdat/out108nfn.csv



