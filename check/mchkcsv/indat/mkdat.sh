
#項目番号指定のチェック用に項目名のないデータを作成する。
cp datchk.csv xxdatchknfn.csv
sed 1d <xxdatchknfn.csv >datchknfn.csv
svn add datchknfn.csv

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

cp dat6.csv xxdat6nfn.csv
sed 1d <xxdat6nfn.csv >dat6nfn.csv
svn add dat6nfn.csv

cp dat7.csv xxdat7nfn.csv
sed 1d <xxdat7nfn.csv >dat7nfn.csv
svn add dat7nfn.csv

cp dat8.csv xxdat8nfn.csv
sed 1d <xxdat8nfn.csv >dat8nfn.csv
svn add dat8nfn.csv

cp dat9.csv xxdat9nfn.csv
sed 1d <xxdat9nfn.csv >dat9nfn.csv
svn add dat9nfn.csv

cp dat10.csv xxdat10nfn.csv
sed 1d <xxdat10nfn.csv >dat10nfn.csv
svn add dat10nfn.csv

cp dat11.csv xxdat11nfn.csv
sed 1d <xxdat11nfn.csv >dat11nfn.csv
svn add dat11nfn.csv

rm -rf xx*
