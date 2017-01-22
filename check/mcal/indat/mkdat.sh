
#項目番号指定のチェック用に項目名のないデータを作成する。
cp dat.csv xxdatnfn.csv
sed 1d <xxdatnfn.csv >datnfn.csv
svn add datnfn.csv

cp dat3.csv xxdat3nfn.csv
sed 1d <xxdat3nfn.csv >dat3nfn.csv
svn add dat3nfn.csv

cp dat_cal.csv xxdat_calnfn.csv
sed 1d <xxdat_calnfn.csv >dat_calnfn.csv
svn add dat_calnfn.csv

cp dat_cal2.csv xxdat_cal2nfn.csv
sed 1d <xxdat_cal2nfn.csv >dat_cal2nfn.csv
svn add dat_cal2nfn.csv

cp regedat.csv xxregedatnfn.csv
sed 1d <xxregedatnfn.csv >regedatnfn.csv
svn add regedatnfn.csv

rm -rf xx*
