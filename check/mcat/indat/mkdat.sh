
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

cp dat5.csv xxdat5nfn.csv
sed 1d <xxdat5nfn.csv >dat5nfn.csv
svn add dat5nfn.csv

cp ./data1-1/dat1.csv ./data1-1/xxdat1nfn.csv
sed 1d <./data1-1/xxdat1nfn.csv >./data1-1/dat1nfn.csv
svn add dat1nfn.csv

cp ./data1-1/dat2.csv ./data1-1/xxdat2nfn.csv
sed 1d <./data1-1/xxdat2nfn.csv >./data1-1/dat2nfn.csv
svn add dat2nfn.csv

cp ./data1-1/dat3.csv ./data1-1/xxdat3nfn.csv
sed 1d <./data1-1/xxdat3nfn.csv >./data1-1/dat3nfn.csv
svn add dat3nfn.csv

cp ./data1-2/dat1.csv ./data1-2/xxdat1nfn.csv
sed 1d <./data1-2/xxdat1nfn.csv >./data1-2/dat1nfn.csv
svn add dat1nfn.csv

cp ./data1-2/dat2.csv ./data1-2/xxdat2nfn.csv
sed 1d <./data1-2/xxdat2nfn.csv >./data1-2/dat2nfn.csv
svn add dat2nfn.csv

cp ./data1-2/dat3.csv ./data1-2/xxdat3nfn.csv
sed 1d <./data1-2/xxdat3nfn.csv >./data1-2/dat3nfn.csv
svn add dat3nfn.csv

cp ./data2/dat1.csv ./data2/xxdat1nfn.csv
sed 1d <./data2/xxdat1nfn.csv >./data2/dat1nfn.csv
svn add dat1nfn.csv

cp ./data2/dat2.csv ./data2/xxdat2nfn.csv
sed 1d <./data2/xxdat2nfn.csv >./data2/dat2nfn.csv
svn add dat2nfn.csv

cp ./data2/dat3.csv ./data2/xxdat3nfn.csv
sed 1d <./data2/xxdat3nfn.csv >./data2/dat3nfn.csv
svn add dat3nfn.csv

cp ./data2/dat4.csv ./data2/xxdat4nfn.csv
sed 1d <./data2/xxdat4nfn.csv >./data2/dat4nfn.csv
svn add dat4nfn.csv

cp ./data2/dat5.csv ./data2/xxdat5nfn.csv
sed 1d <./data2/xxdat5nfn.csv >./data2/dat5nfn.csv
svn add dat5nfn.csv

rm -rf xx*
rm -rf ./data1-1/xx*
rm -rf ./data1-2/xx*
rm -rf ./data2/xx*
