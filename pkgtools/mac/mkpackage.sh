#パッケージ作成TOOL
TarSRC=$1
Fname=`basename $TarSRC`
Dname=`echo $Fname | sed 's/\.tar\.gz//g'`
Pver=`echo $Dname | sed 's/^nysol_mcmd-//g'`
nname=nysolcore-$Pver
ndname=nysol_mcmd-$Pver

sed s/###VERSION###/${Pver}/g  < Distribution.org.xml > Distribution.xml 

rm -rf build 
rm -rf nysol_mcmd-$Pver.dmg 
mkdir build
mkdir build/tarsrc
mkdir build/dist

tar xfvz $TarSRC -C ./build/tarsrc

CurD=`pwd`
cd ./build/tarsrc/$Dname
./configure
make
make DESTDIR=$CurD/build/dist install 
cd $CurD
cp License ./build/dist/


pkgbuild --identifier jp.nysolcore.pkg --version $Pver --root ./build/dist --install-location / ./build/$nname.pkg
productbuild  --distribution "Distribution.xml" --package-path ./build/ --resources ./build/ ./build/$ndname.pkg

hdiutil create -srcfolder ./build/$ndname.pkg $ndname.dmg


