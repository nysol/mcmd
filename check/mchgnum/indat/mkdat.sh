
#項目番号指定のチェック用に項目名のないデータを作成する。
cp dat.csv xxdatnfn.csv
sed 1d <xxdatnfn.csv >datnfn.csv
svn add datnfn.csv

cp dat0.csv xxdat0nfn.csv
sed 1d <xxdat0nfn.csv >dat0nfn.csv
svn add dat0nfn.csv

cp dat1.csv xxdat1nfn.csv
sed 1d <xxdat1nfn.csv >dat1nfn.csv
svn add dat1nfn.csv

cp dat2.csv xxdat2nfn.csv
sed 1d <xxdat2nfn.csv >dat2nfn.csv
svn add dat2nfn.csv

cp dat3.csv xxdat3nfn.csv
sed 1d <xxdat3nfn.csv >dat3nfn.csv
svn add dat3nfn.csv

cp dat4.csv xxdat4nfn.csv
sed 1d <xxdat4nfn.csv >dat4nfn.csv
svn add dat4nfn.csv

rm -rf xx*
