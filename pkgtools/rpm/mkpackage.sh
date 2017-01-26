#!/usr/bin/env bash
#引数１にまとめられたソースファイル名を指定する

TarSRC=$1
Fname=`basename $TarSRC`
Dname=`echo $Fname | sed 's/\.tar\.gz//g'`
Pver=`echo $Dname | sed 's/^nysol_mcmd-//g'`

ARCH=`arch`
if [ `echo $ARCH|grep ^i` ]; then
	Arch="i386"
else
	Arch="x86_64"
fi

echo "%_topdir ${HOME}/rpm"   >  ~/.rpmmacros
echo "%_buildshell /bin/bash" >> ~/.rpmmacros
mkdir -p ${HOME}/rpm
mkdir -p ${HOME}/rpm/${Arch}
mkdir -p ${HOME}/rpm/BUILD
mkdir -p ${HOME}/rpm/SOURCES
mkdir -p ${HOME}/rpm/RPMS/${Arch}
mkdir -p ${HOME}/rpm/SPECS
mkdir -p ${HOME}/rpm/SRPMS

cp $TarSRC ${HOME}/rpm/SOURCES/

LICENSE='cat ../License'

sed "s/##VERSION##/$Pver/" <mcmd.spec |
sed "s/##SOURCEFILE##/$Fname/">${HOME}/rpm/SPECS/mcmd.spec

(cd ${HOME}/rpm/SPECS && rpmbuild -bb mcmd.spec)
cp ${HOME}/rpm/RPMS/${Arch}/nysol*${version}-${revision}* .
