
#項目番号指定のチェック用に項目名のないデータを作成する。
cp dat1.csv xxdat1nfn.csv
sed 1d <xxdat1nfn.csv >dat1nfn.csv
svn add dat1nfn.csv

rm -rf xx*
