#!/usr/bin/env bash



function cleandat {
	rm -f check.log
	rm -f diffcheck.log
	rm -f m*/xxdiff.log
	rm -f m*/xxendlog_ans.tx
	rm -f m*/xxendlog_ans.txt
	rm -f m*/xxanslog_ans.tx
	rm -f m*/xxanslog_ans.txt
	rm -rf m*/outdat/
}

cleandat

echo '# ================'  >./check.log
echo '# KGMOD CHECKER   ' >>./check.log
echo "# DATE: "`date`       >>./check.log
echo "# PATH: "`echo $PATH` >>./check.log
echo "# UNAME: "`uname -a`  >>./check.log
echo '# ================' >>./check.log
function rmnocheck {
	sed 's/answer\///' |
	awk 'BEGIN{
			while( getline xxx < "nocheck.txt" > 0 ){
				split(xxx,aa," ");
				nocheck[aa[1]" "aa[2]]=1;
			}
			oflg="false"
		}
	{
		if($1!="#"){
			if($1=="---"){
				cmd=$4;
				#print $0;
			}else{
				if($1=="Files" || $1=="ファイル"){
					idx=cmd" "$2;
					if(nocheck[idx]!=1) { 
						if(oflg=="false"){ 
							print "cmd "cmd;
							oflg=="true"
						}
						print $0;
					}
				}
				if($1=="Only"){
					idx=cmd" "$4;
					if(nocheck[idx]!=1) {
						if(oflg=="false"){ 
							print "cmd "cmd;
							oflg=="true"
						}
						print $0;
					}
				}
			}
		}
	}'
}

function mkarc {
	odir=check`date "+%Y%m%d"`
	rm -rf $odir
	mkdir -p $odir
	cp check.log $odir
	cp diffcheck.log $odir

	#実行ログの回収
	cat m*/out_endlog.txt >$odir/exelog.txt

	#アーカイブ作成
	tar zcvf $odir.tar.gz $odir
}

function nochecklog {
	if [ -e nocheck.log ]; then
		cat $1 | awk 'BEGIN{
			i=1
			while( getline xxx < "nocheck.log" > 0 ){
				split(xxx,aa," ");
				nocheck[i]=aa[1];
				i++;
			}
		}
		{
			noout=0
			for(j=1;j<i;j++){
				if($0 ~ nocheck[j]){
					noout=1
				}
			}
			if(noout==0){
				print $0
			}
		}'
	else
		cat $1
	fi
}

function doDiffLog {
	sed 's/ 20..\/..\/.. ..:..:..//' ans_endlog.txt |
	sed 's/\/usr\/local\/bin\///' |
	sed 's/\/opt\/local\/bin\///' |
	sed 's/  / /'                 |
	sed 's/# *: /# /'             |
	sed 's/ *$//'                 >xxendlog_ans.tx
	nochecklog xxendlog_ans.tx > xxendlog_ans.txt

	sed 's/ 20..\/..\/.. ..:..:..//' out_endlog.txt |
	sed 's/\/usr\/local\/bin\///' |
	sed 's/\/opt\/local\/bin\///' |
	sed 's/  / /'                 |
	sed 's/# *: /# /'                |
	sed 's/ *$//'                 >xxendlog_out.tx
	nochecklog xxendlog_out.tx > xxendlog_out.txt 
	
	diff -q xxendlog_ans.txt xxendlog_out.txt >> ../check.log
	diff    xxendlog_ans.txt xxendlog_out.txt  > ./xxdiff.log
}

function doDiffOut {
	diff -q -r answer outdat  >> ../check.log
	diff    -r  answer outdat  >> ./xxdiff.log
}


function sub {
	echo "--- checking ... $1" >> ./check.log
	cd $1
	rm -rf outdat
	bash run.sh
	doDiffLog $1
	doDiffOut
	cd ..
}

#function skip {
#0
sub maccum
sub marff2csv
sub mavg
sub mbest
sub mbucket
sub mcal
sub mcat
sub mchgnum
sub mchgstr
sub mchkcsv
#1
sub mcombi
sub mcommon
sub mcount
sub mcross
sub mcsv2arff
sub mcut
sub mdelnull
sub mduprec
sub mfldname
sub mfsort
#2
sub mhashavg
sub mhashsum
sub mjoin
sub mkeybreak
sub mmbucket
sub mmvavg
sub mmvsim
sub mmvstats
sub mnewnumber
sub mnewrand
#3
sub mnewstr
sub mnjoin
sub mnormalize
sub mnrcommon
sub mnrjoin
sub mnullto
sub mnumber
sub mpadding
sub mpaste
sub mproduct
#4
sub mrand
sub mrjoin
sub msed
sub msel
sub mselnum
sub mselrand
sub mselstr
sub msep
sub msep2
sub msetstr
#5
sub mshare
sub msim
sub mslide
sub msortf
sub mstats
sub msum
sub msummary
sub mtee
sub mtonull
sub mtra
#6
sub mtrafld
sub mtraflg
sub muniq
sub mvcat
sub mvcommon
sub mvcount
sub mvdelim
sub mvdelnull
sub mvjoin
sub mvnullto
#7
sub mvreplace
sub mvsort
sub mvuniq
sub mwindow
sub mdformat
sub mxml2csv
sub mshuffle

#}

# nocheckリストに登録されたコマンド&結果データについてはdiffが出るので削除
rmnocheck < check.log > diffcheck.log

# 結果アーカイブを作成
mkarc

# 結果を表示する
clear
cat diffcheck.log
grep -v '^---' diffcheck.log >xxng
echo '不一致の件数は'`wc -l <xxng`'件でした．'
echo '不一致がある場合は，該当のディレクトリのxxdiff.logを確認のこと'
echo 'チェックの結果は '$odir'.tar.gz に収められている(開発者への送付用)'

