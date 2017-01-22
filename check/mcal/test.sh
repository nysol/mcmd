#!/bin/bash


. ../env
#name_kg_mcmd cal


#---------------------------------------------------------------
#演算子関連
#---------------------------------------------------------------
${pfxc}mcal c='${金額}+100' a="百円増" i=./indat/dat.csv o=./outdat/out1001.csv
${pfxc}mcal c='${金額}-100' a="百円引" i=./indat/dat.csv o=./outdat/out1002.csv
${pfxc}mcal c='${金額}*3' a="三倍金額" i=./indat/dat.csv o=./outdat/out1003.csv
${pfxc}mcal c='${金額}/${数量}' a="単価" i=./indat/dat.csv o=./outdat/out1004.csv
${pfxc}mcal c='${金額}<=500' a="500円以下" i=./indat/dat.csv o=./outdat/out1005.csv
${pfxc}mcal c='${金額}<500' a="500未満" i=./indat/dat.csv o=./outdat/out1006.csv
${pfxc}mcal c='${金額}>=500' a="500円以上" i=./indat/dat.csv o=./outdat/out1007.csv
${pfxc}mcal c='${金額}>500' a="500円より大きい" i=./indat/dat.csv o=./outdat/out1008.csv
${pfxc}mcal c='${金額}!=500' a="500円ではないもの" i=./indat/dat.csv o=./outdat/out1009.csv
${pfxc}mcal c='${金額}==500' a="500円のもの" i=./indat/dat.csv o=./outdat/out1010.csv
${pfxc}mcal c='$d{日付} <= 0d20020531' a="上半期" i=./indat/dat.csv o=./outdat/out1011.csv
${pfxc}mcal c='$d{日付} < 0d20020601' a="上半期" i=./indat/dat.csv o=./outdat/out1012.csv
${pfxc}mcal c='$d{日付} >= 0d20020601' a="下半期" i=./indat/dat.csv o=./outdat/out1013.csv
${pfxc}mcal c='$d{日付} > 0d20020531' a="下半期" i=./indat/dat.csv o=./outdat/out1014.csv
${pfxc}mcal c='$d{日付} == 0d20020926' a="９月２６日" i=./indat/dat.csv o=./outdat/out1015.csv
${pfxc}mcal c='$d{日付} != 0d20020926' a="９月２６日以外" i=./indat/dat.csv o=./outdat/out1016.csv
${pfxc}mcal c='${金額}>=500 || ${金額}<=300' a="300円以下、500円以上" i=./indat/dat.csv o=./outdat/out1017.csv
${pfxc}mcal c='${金額}<=500 && ${金額}>=300' a="300円以上、500円以下" i=./indat/dat.csv o=./outdat/out1018.csv
${pfxc}mcal c='($s{店} == "A")' a="A店であるかどうか" i=./indat/dat.csv o=./outdat/out1019.csv
${pfxc}mcal c='((${金額}/${数量})*12)'  a="1ダース価格" i=./indat/dat.csv o=./outdat/out1020.csv

#-----------------------------------------------------------------------------
#関数(日付時間関連)
#-----------------------------------------------------------------------------
${pfxc}mcal c='age(0d19791106,$d{日付})' a="年齢" i=./indat/dat.csv o=./outdat/out1021.csv
${pfxc}mcal c='year($d{日付})' a="年" i=./indat/dat.csv o=./outdat/out1022-1.csv
${pfxc}mcal c='month($d{日付})' a="月" i=./indat/dat.csv o=./outdat/out1022-2.csv
${pfxc}mcal c='day($d{日付})' a="日" i=./indat/dat.csv o=./outdat/out1022-3.csv
${pfxc}mcal c='dowe($d{日付})' a="曜日" i=./indat/dat.csv o=./outdat/out1022-4.csv
${pfxc}mcal c='dow($d{日付})' a="曜日" i=./indat/dat.csv o=./outdat/out1022-5.csv
${pfxc}mcal c='$d{日付}+92' a="半年後日付" i=./indat/dat.csv o=./outdat/out1023.csv
${pfxc}mcal c='($d{日付} - 0d20010101)' a="21世紀以後の日数" i=./indat/dat.csv o=./outdat/out1024.csv
${pfxc}mcal c='hour($t{時間})' a="時" i=./indat/dat.csv o=./outdat/out1025-1.csv
${pfxc}mcal c='minute($t{時間})' a=分 i=./indat/dat.csv o=./outdat/out1025-2.csv
${pfxc}mcal c='second($t{時間})' a="秒" i=./indat/dat.csv o=./outdat/out1025-3.csv
${pfxc}mcal c='right(t2s(($t{時間}+10)),6)' a="時間2" i=./indat/dat.csv o=./outdat/out1026.csv
${pfxc}mcal c='(0t055015 - $t{時間})' a="時間差" i=./indat/dat.csv o=./outdat/out1027.csv
${pfxc}mcal c='today()' a="今日の日付" i=./indat/dat.csv o=./outdat/out1028.csv
${pfxc}mcal c='right(t2s(now()),6)' a="今の時間" i=./indat/dat.csv o=./outdat/out1029.csv

#--------------------------------------------------------------------------
#関数(数値関連)
#--------------------------------------------------------------------------
${pfxc}mcal c='ceil(${金額},10)' a="1の位を切り上げ" i=./indat/dat.csv o=./outdat/out1030.csv
${pfxc}mcal c='floor(${金額},10)' a="１の位を切り捨て" i=./indat/dat.csv o=./outdat/out1031.csv
${pfxc}mcal c='round(${金額},10)' a="1の位四捨五入" i=./indat/dat.csv o=./outdat/out1032.csv
${pfxc}mcal c='sqrt(${金額})' a="金額の平方根"  i=./indat/dat.csv o=./outdat/out1033.csv
${pfxc}mcal c='${金額}-400' a="新金額" i=./indat/dat.csv o=./outdat/out1034-1.csv 
${pfxc}mcal c='abs(${金額})' a="金額絶対値" i=./indat/dat6.csv o=./outdat/out1034.csv
${pfxc}mcal c='power(${数量},3)' a="数量巾乗" i=./indat/dat.csv o=./outdat/out1035.csv
${pfxc}mcal c='sum(${金額},10,20,"-n")' a=金額＋ i=./indat/dat.csv o=./outdat/out1036.csv
${pfxc}mcal c='sum(${金額},10,20)' a=金額＋ i=./indat/dat.csv o=./outdat/out1059.csv
${pfxc}mcal c='exp(${数量})' a="金額巾" i=./indat/dat.csv o=./outdat/out1037.csv
${pfxc}mcal c='ln(${数量})' a="数量自然対数" i=./indat/dat.csv o=./outdat/out1038.csv
${pfxc}mcal c='log(${数量},5)' a="数量対数５" i=./indat/dat.csv o=./outdat/out1039.csv
${pfxc}mcal c='log2(${数量})' a="数量対数2" i=./indat/dat.csv o=./outdat/out1040.csv
${pfxc}mcal c='log10(${数量})' a="数量対数10" i=./indat/dat.csv o=./outdat/out1041.csv
${pfxc}mcal c='pi()' a="pi" i=./indat/dat.csv o=./outdat/out1042.csv
${pfxc}mcal c='randi(100,110,2)' a="乱数" i=./indat/dat.csv o=./outdat/out1043.csv
${pfxc}mcal c='nrand(100,20,2)' a="乱数" i=./indat/dat.csv o=./outdat/out1044.csv
${pfxc}mcal c='round(${数値2},1)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-1.csv
${pfxc}mcal c='round(${数値2},0.001)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-2.csv
${pfxc}mcal c='round(${数値2},0.000001)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-3.csv
${pfxc}mcal c='floor(${数値2},0.1)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-4.csv
${pfxc}mcal c='floor(${数値2},0.000001)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-5.csv
${pfxc}mcal c='floor(${数値2},1)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-6.csv
${pfxc}mcal c='floor(${数値2},10)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-7.csv
${pfxc}mcal c='floor(${数値2},1000)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-8.csv
${pfxc}mcal c='ceil(${数値2},0.1)' a=新数値 i=./indat/dat3.csv o=./outdat/out1044-9.csv
${pfxc}mcal c='ceil(${数値2},0.000001)' a=新数値 i=./indat/dat3.csv o=./outdat/out1044-10.csv
${pfxc}mcal c='ceil(${数値2},1)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-11.csv
${pfxc}mcal c='ceil(${数値2},10)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-12.csv
${pfxc}mcal c='ceil(${数値2},1000)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-13.csv
${pfxc}mcal c='round(${数値2},0.1)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-14.csv
${pfxc}mcal c='round(${数値2},0.000001)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-15.csv
${pfxc}mcal c='round(${数値2},1)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-16.csv
${pfxc}mcal c='round(${数値2},10)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-17.csv
${pfxc}mcal c='round(${数値2},1000)' a="新数値" i=./indat/dat3.csv o=./outdat/out1044-18.csv
${pfxc}mcal c='min(${数値1},${数値2},"-n")' a="数値min" i=./indat/dat3.csv o=./outdat/out1044-19.csv
${pfxc}mcal c='min(${数値?},"-n")' a="数値min" i=./indat/dat3.csv o=./outdat/out1044-20.csv
${pfxc}mcal c='max(${数値1},${数値2},"-n")' a="数値max" i=./indat/dat3.csv o=./outdat/out1044-21.csv
${pfxc}mcal c='max(${数値*},"-n")' a="数値max" i=./indat/dat3.csv o=./outdat/out1044-22.csv
${pfxc}mcal c='min(${数値1},${数値2})' a="数値min" i=./indat/dat3.csv o=./outdat/out1044-23.csv
${pfxc}mcal c='min(${数値?})' a="数値min" i=./indat/dat3.csv o=./outdat/out1044-24.csv
${pfxc}mcal c='max(${数値1},${数値2})' a="数値max" i=./indat/dat3.csv o=./outdat/out1044-25.csv
${pfxc}mcal c='max(${数値*})' a="数値max" i=./indat/dat3.csv o=./outdat/out1044-26.csv


#---------------------------------------------------------------
# 文字列関連
#---------------------------------------------------------------
${pfxc}mcal c='cat("/",$s{日付},$s{時間})' a="日時" i=./indat/dat.csv o=./outdat/out1045.csv
${pfxc}mcal c='length($s{商品})' a="商品バイト数" i=./indat/dat.csv o=./outdat/out1046.csv
${pfxc}mcal c='fixlen("N",5,"R","Y")' a="固定長文" i=./indat/dat.csv o=./outdat/out1047.csv
${pfxc}mcal c='regexpos($s{正規},"BB")' a="正規マッチ" i=./indat/regedat.csv o=./outdat/out1048.csv
${pfxc}mcal c='regexlen($s{正規},"AC")' a="マッチ文字数" i=./indat/regedat.csv o=./outdat/out1050.csv

#---------------------------------------------------------------
#論理関連
#---------------------------------------------------------------
${pfxc}mcal c='if(${金額}>400,"Y","N")' a="400円より大きいか否か" i=./indat/dat.csv o=./outdat/out1051.csv
${pfxc}mcal c='not(${金額}>400)' a="400円より大きいか" i=./indat/dat.csv o=./outdat/out1052.csv

#---------------------------------------------------------------
#行項目関連
#---------------------------------------------------------------
${pfxc}mcal c='line()' a="処理番号" i=./indat/dat.csv o=./outdat/out1053.csv
${pfxc}mcal c='fldsize()' a="項目数" i=./indat/dat.csv o=./outdat/out1054.csv
${pfxc}mcal c='top()' a="先頭の商品" i=./indat/dat.csv o=./outdat/out1058.csv

#mcal新機能チェックスクリプト
#定数指定チェック
${pfxc}mcal c='(10>9) || (9<10)' i=./indat/dat_cal2.csv a=x o=./outdat/out01.csv
${pfxc}mcal c='(3>2) || (3<2)' i=./indat/dat_cal2.csv a=x o=./outdat/out02.csv
${pfxc}mcal c='(10>9) && (10<9)' i=./indat/dat_cal2.csv a=x o=./outdat/out03.csv
${pfxc}mcal c='if(top(),1,1+#{})' i=./indat/dat_cal2.csv a=x o=./outdat/out04.csv
${pfxc}mcal c='1+#{}' i=./indat/dat_cal2.csv a=x o=./outdat/out05.csv

#変数指定チェック
${pfxc}mcal c='${num1}+#{num1}' i=./indat/dat_cal.csv a=x o=./outdat/out06.csv

${pfxc}mcal c='year(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out07.csv

${pfxc}mcal c='month(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out74.csv

${pfxc}mcal c='monthe(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out75.csv

${pfxc}mcal c='monthes(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out76.csv

${pfxc}mcal c='day(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out77.csv

${pfxc}mcal c='week(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out78.csv

${pfxc}mcal c='dow(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out79.csv

${pfxc}mcal c='dowe(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out80.csv

${pfxc}mcal c='dowes(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out81.csv

${pfxc}mcal c='hours(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out82.csv

${pfxc}mcal c='minutes(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out83.csv

${pfxc}mcal c='seconds(0t20081014121010)' i=./indat/dat_cal2.csv a=x o=./outdat/out84.csv


${pfxc}mcal c='year(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out85.csv

${pfxc}mcal c='month(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out86.csv

${pfxc}mcal c='monthe(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out87.csv

${pfxc}mcal c='monthes(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out88.csv

${pfxc}mcal c='day(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out89.csv

${pfxc}mcal c='week(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out90.csv

${pfxc}mcal c='dow(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out91.csv

${pfxc}mcal c='dowe(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out92.csv

${pfxc}mcal c='dowes(0d20081014)' i=./indat/dat_cal2.csv a=x o=./outdat/out93.csv


${pfxc}mcal c='line()' i=./indat/dat_cal2.csv a=x o=./outdat/out94.csv

${pfxc}mcal c='fldsize()' i=./indat/dat_cal2.csv a=x o=./outdat/out95.csv

${pfxc}mcal c='top()' i=./indat/dat_cal.csv a=x o=./outdat/out96.csv


${pfxc}mcal c='heron(1,1,5,1,5,3)' i=./indat/dat_cal2.csv a=x o=./outdat/out97.csv

${pfxc}mcal c='dist("euclid",1,2,3,4,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out98.csv

${pfxc}mcal c='dist("cityblock",1,2,3,4,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out99.csv

${pfxc}mcal c='dist("hamming","1","2","3","4","1","3","3","5")' i=./indat/dat_cal2.csv a=x o=./outdat/out100.csv


${pfxc}mcal c='radian(180)' i=./indat/dat_cal2.csv a=x o=./outdat/out101.csv
${pfxc}mcal c='degree(pi())' i=./indat/dat_cal2.csv a=x o=./outdat/out102.csv
${pfxc}mcal c='radian(degree(pi()))' i=./indat/dat_cal2.csv a=x o=./outdat/out103.csv

${pfxc}mcal c='asin(0.7143)' i=./indat/dat_cal2.csv a=x o=./outdat/out104.csv
${pfxc}mcal c='acos(0.7143)' i=./indat/dat_cal2.csv a=x o=./outdat/out105.csv
${pfxc}mcal c='atan(0.7143)' i=./indat/dat_cal2.csv a=x o=./outdat/out106.csv
${pfxc}mcal c='atan2(1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out107.csv
${pfxc}mcal c='sin(1.047)' i=./indat/dat_cal2.csv a=x o=./outdat/out108.csv
${pfxc}mcal c='cos(1.047)' i=./indat/dat_cal2.csv a=x o=./outdat/out109.csv
${pfxc}mcal c='tan(1.047)' i=./indat/dat_cal2.csv a=x o=./outdat/out110.csv
${pfxc}mcal c='sinh(1.047)' i=./indat/dat_cal2.csv a=x o=./outdat/out111.csv
${pfxc}mcal c='cosh(1.047)' i=./indat/dat_cal2.csv a=x o=./outdat/out112.csv
${pfxc}mcal c='tanh(1.047)' i=./indat/dat_cal2.csv a=x o=./outdat/out113.csv

${pfxc}mcal c='product(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out114.csv
${pfxc}mcal c='product(1,2,3,4,0)' i=./indat/dat_cal2.csv a=x o=./outdat/out115.csv

${pfxc}mcal c='sign(-10)' i=./indat/dat_cal2.csv a=x o=./outdat/out116.csv
${pfxc}mcal c='sign(10)' i=./indat/dat_cal2.csv a=x o=./outdat/out117.csv
${pfxc}mcal c='sign(0)' i=./indat/dat_cal2.csv a=x o=./outdat/out118.csv

${pfxc}mcal c='gcd(12,16)' i=./indat/dat_cal2.csv a=x o=./outdat/out119.csv
${pfxc}mcal c='gcd(-12,16)' i=./indat/dat_cal2.csv a=x o=./outdat/out120.csv
${pfxc}mcal c='gcd(-12,-16)' i=./indat/dat_cal2.csv a=x o=./outdat/out121.csv
${pfxc}mcal c='gcd(0,16)' i=./indat/dat_cal2.csv a=x o=./outdat/out122.csv
${pfxc}mcal c='lcm(0,16)' i=./indat/dat_cal2.csv a=x o=./outdat/out123.csv
${pfxc}mcal c='lcm(12,16)' i=./indat/dat_cal2.csv a=x o=./outdat/out124.csv
${pfxc}mcal c='lcm(-12,16)' i=./indat/dat_cal2.csv a=x o=./outdat/out125.csv

${pfxc}mcal c='factorial(5)' i=./indat/dat_cal2.csv a=x o=./outdat/out126.csv
${pfxc}mcal c='factorial(0)' i=./indat/dat_cal2.csv a=x o=./outdat/out127.csv
${pfxc}mcal c='factorial(-0.5)*factorial(-0.5)' i=./indat/dat_cal2.csv a=x o=./outdat/out128.csv

${pfxc}mcal c='hasspace("abcdef")' i=./indat/dat_cal2.csv a=x o=./outdat/out129.csv
${pfxc}mcal c='hasspace("abc def")' i=./indat/dat_cal2.csv a=x o=./outdat/out130.csv

${pfxc}mcal c='isnull("a*")' i=./indat/dat_cal2.csv a=x o=./outdat/out131.csv
${pfxc}mcal c='isnull("*")' i=./indat/dat_cal2.csv a=x o=./outdat/out132.csv

${pfxc}mcal c='matchas("bc","a","xy","abc")' i=./indat/dat_cal2.csv a=x o=./outdat/out133.csv
${pfxc}mcal c='matchas("bc","abc","bcd")' i=./indat/dat_cal2.csv a=x o=./outdat/out134.csv
${pfxc}mcal c='matchs("bc","a","xy","abc")' i=./indat/dat_cal2.csv a=x o=./outdat/out135.csv
${pfxc}mcal c='matchs("bc","a","ac")' i=./indat/dat_cal2.csv a=x o=./outdat/out136.csv

${pfxc}mcal c='capitalize("aBcD!")' i=./indat/dat_cal2.csv a=x o=./outdat/out137.csv
${pfxc}mcal c='tolower("aBcD!")' i=./indat/dat_cal2.csv a=x o=./outdat/out138.csv
${pfxc}mcal c='toupper("aBcD!")' i=./indat/dat_cal2.csv a=x o=./outdat/out139.csv

${pfxc}mcal c='fixlen("abc",2,"L","#")' i=./indat/dat_cal2.csv a=x o=./outdat/out140.csv
${pfxc}mcal c='fixlen("abc",2,"R","#")' i=./indat/dat_cal2.csv a=x o=./outdat/out141.csv
${pfxc}mcal c='fixlen("abc",5,"L"," ")' i=./indat/dat_cal2.csv a=x o=./outdat/out142.csv
${pfxc}mcal c='fixlen("abc",5,"R"," ")' i=./indat/dat_cal2.csv a=x o=./outdat/out143.csv
${pfxc}mcal c='fixlen("abc",5,"L","#")' i=./indat/dat_cal2.csv a=x o=./outdat/out144.csv
${pfxc}mcal c='fixlen("abc",5,"R","#")' i=./indat/dat_cal2.csv a=x o=./outdat/out145.csv

${pfxc}mcal c='regexstr("aaabcccddbd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out146.csv
${pfxc}mcal c='regexpfx("aaabcccddbd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out147.csv
${pfxc}mcal c='regexsfx("aaabcccddbd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out148.csv

${pfxc}mcal c='regexpos("aaabcddbd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out149.csv
${pfxc}mcal c='regexpos("acccccbabccd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out150.csv
${pfxc}mcal c='regexpos("accdaabcccccbabccd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out151.csv

${pfxc}mcal c='regexlen("abcbd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out152.csv
${pfxc}mcal c='regexlen("abcccccbabccd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out153.csv
${pfxc}mcal c='regexlen("abccdaabcccccbabccd","bc+")' i=./indat/dat_cal2.csv a=x o=./outdat/out154.csv

${pfxc}mcal c='regexrepw("あああ","あ+","い")' i=./indat/dat_cal2.csv a=x o=./outdat/out155.csv
${pfxc}mcal c='regexrepw("あああ","あ","い")' i=./indat/dat_cal2.csv a=x o=./outdat/out156.csv

${pfxc}mcal c='regexrep("abcbd","bc","x")' i=./indat/dat_cal2.csv a=x o=./outdat/out157.csv
${pfxc}mcal c='regexrep("abcbd","b[cd]","x")' i=./indat/dat_cal2.csv a=x o=./outdat/out158.csv
${pfxc}mcal c='regexrep("abbc","b","x")' i=./indat/dat_cal2.csv a=x o=./outdat/out159.csv

${pfxc}mcal c='regexm("abc","a")' i=./indat/dat_cal2.csv a=x o=./outdat/out160.csv
#ワイド文字の場合は一致する
${pfxc}mcal c='regexm("あああ","あ+")' i=./indat/dat_cal2.csv a=x o=./outdat/out161.csv
${pfxc}mcal c='regexmw("あああ","あ+")' i=./indat/dat_cal2.csv a=x o=./outdat/out162.csv
${pfxc}mcal c='regexm("aaa","a+")' i=./indat/dat_cal2.csv a=x o=./outdat/out163.csv

${pfxc}mcal c='regexs("あああ","あ")' i=./indat/dat_cal2.csv a=x o=./outdat/out164.csv
${pfxc}mcal c='regexsw("あああ","あ")' i=./indat/dat_cal2.csv a=x o=./outdat/out165.csv
${pfxc}mcal c='regexs("aaa","a+")' i=./indat/dat_cal2.csv a=x o=./outdat/out166.csv
${pfxc}mcal c='regexs("aaa","b")' i=./indat/dat_cal2.csv a=x o=./outdat/out167.csv

${pfxc}mcal c='nrand(100,10)' i=./indat/dat_cal2.csv a=x o=./outdat/out168.csv
${pfxc}mcal c='nrand(0,1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out169.csv
${pfxc}mcal c='randi(1,4)' i=./indat/dat_cal2.csv a=x o=./outdat/out170.csv
${pfxc}mcal c='randi(1,4,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out171.csv

${pfxc}mcal c='leftw("ＡＢxＣ",3)' i=./indat/dat_cal2.csv a=x o=./outdat/out172.csv
${pfxc}mcal c='left("abcde",2)' i=./indat/dat_cal2.csv a=x o=./outdat/out173.csv
${pfxc}mcal c='rightw("ＡＢxＣ",3)' i=./indat/dat_cal2.csv a=x o=./outdat/out174.csv
${pfxc}mcal c='right("abcde",2)' i=./indat/dat_cal2.csv a=x o=./outdat/out175.csv

${pfxc}mcal c='midw("ＡＢxＣ",2,10)' i=./indat/dat_cal2.csv a=x o=./outdat/out176.csv
${pfxc}mcal c='midw("ＡＢxＣ",1,2)' i=./indat/dat_cal2.csv a=x o=./outdat/out177.csv
${pfxc}mcal c='mid("abcde",2,10)' i=./indat/dat_cal2.csv a=x o=./outdat/out178.csv
${pfxc}mcal c='mid("abcde",0,2)' i=./indat/dat_cal2.csv a=x o=./outdat/out179.csv

${pfxc}mcal c='length("ＡＢxＣ")' i=./indat/dat_cal2.csv a=x o=./outdat/out180.csv
${pfxc}mcal c='length("abc")' i=./indat/dat_cal2.csv a=x o=./outdat/out181.csv
${pfxc}mcal c='lengthw("ＡＢxＣ")' i=./indat/dat_cal2.csv a=x o=./outdat/out182.csv
${pfxc}mcal c='lengthw("abc")' i=./indat/dat_cal2.csv a=x o=./outdat/out183.csv

${pfxc}mcal c='sqsum(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out184.csv
${pfxc}mcal c='sqrt(0)' i=./indat/dat_cal2.csv a=x o=./outdat/out185.csv
${pfxc}mcal c='sqrt(-1)' i=./indat/dat_cal2.csv a=x o=./outdat/out186.csv
${pfxc}mcal c='sqrt(2)' i=./indat/dat_cal2.csv a=x o=./outdat/out187.csv
${pfxc}mcal c='abs(-2)' i=./indat/dat_cal2.csv a=x o=./outdat/out188.csv
${pfxc}mcal c='abs(2)' i=./indat/dat_cal2.csv a=x o=./outdat/out189.csv
${pfxc}mcal c='abs(0)' i=./indat/dat_cal2.csv a=x o=./outdat/out190.csv
${pfxc}mcal c='exp(0)' i=./indat/dat_cal2.csv a=x o=./outdat/out191.csv
${pfxc}mcal c='exp(1)' i=./indat/dat_cal2.csv a=x o=./outdat/out192.csv
${pfxc}mcal c='exp(-2)' i=./indat/dat_cal2.csv a=x o=./outdat/out193.csv
${pfxc}mcal c='log(2,8)' i=./indat/dat_cal2.csv a=x o=./outdat/out194.csv
${pfxc}mcal c='log2(8)' i=./indat/dat_cal2.csv a=x o=./outdat/out195.csv
${pfxc}mcal c='log(10,1000)' i=./indat/dat_cal2.csv a=x o=./outdat/out196.csv
${pfxc}mcal c='log10(1000)' i=./indat/dat_cal2.csv a=x o=./outdat/out197.csv
${pfxc}mcal c='pi()' i=./indat/dat_cal2.csv a=x o=./outdat/out198.csv
${pfxc}mcal c='e()' i=./indat/dat_cal2.csv a=x o=./outdat/out200.csv
${pfxc}mcal c='power(10,2)' i=./indat/dat_cal2.csv a=x o=./outdat/out201.csv
${pfxc}mcal c='power(10,-2)' i=./indat/dat_cal2.csv a=x o=./outdat/out202.csv
${pfxc}mcal c='power(10,1000)' i=./indat/dat_cal2.csv a=x o=./outdat/out203.csv
${pfxc}mcal c='round(-2.1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out204.csv
${pfxc}mcal c='floor(-2.1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out205.csv
${pfxc}mcal c='ceil(-2.1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out206.csv
${pfxc}mcal c='round(2.1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out207.csv
${pfxc}mcal c='floor(2.1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out208.csv
${pfxc}mcal c='ceil(2.1,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out209.csv
${pfxc}mcal c='round(2.5,1)' i=./indat/dat_cal2.csv a=x o=./outdat/out210.csv

${pfxc}mcal c='sqsum(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out211.csv
${pfxc}mcal c='min(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out212.csv
${pfxc}mcal c='max(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out213.csv
${pfxc}mcal c='avg(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out214.csv
${pfxc}mcal c='sum(1,2,3,4,5)' i=./indat/dat_cal2.csv a=x o=./outdat/out215.csv
${pfxc}mcal c='fract(12.5)' i=./indat/dat_cal2.csv a=x o=./outdat/out216.csv
${pfxc}mcal c='int(12.5)' i=./indat/dat_cal2.csv a=x o=./outdat/out217.csv

${pfxc}mcal c='format(uxt(0t20070207000000),"%.0f")' i=./indat/dat_cal2.csv a=x o=./outdat/out218.csv
${pfxc}mcal c='uxt2t(uxt(0t20070207000000))' i=./indat/dat_cal2.csv a=x o=./outdat/out219.csv
${pfxc}mcal c='uxt2t(1170774000)' i=./indat/dat_cal2.csv a=x o=./outdat/out220.csv
${pfxc}mcal c='uxt2t(0)' i=./indat/dat_cal2.csv a=x o=./outdat/out221.csv

${pfxc}mcal c='format(julian(0t20090101000000),"%f")' i=./indat/dat_cal2.csv a=x o=./outdat/out222.csv
${pfxc}mcal c='format(julian(0d20090101),"%.0f")' i=./indat/dat_cal2.csv a=x o=./outdat/out223.csv
${pfxc}mcal c='julian2d(julian(0d20090101))' i=./indat/dat_cal2.csv a=x o=./outdat/out224.csv
${pfxc}mcal c='julian(0d20090101)' i=./indat/dat_cal2.csv a=x o=./outdat/out225.csv
${pfxc}mcal c='julian2t(2454832.5)' i=./indat/dat_cal2.csv a=x o=./outdat/out226.csv
${pfxc}mcal c='julian2t(julian(0t20090101000000))' i=./indat/dat_cal2.csv a=x o=./outdat/out227.csv
${pfxc}mcal c='julian(0t20090101000000)' i=./indat/dat_cal2.csv a=x o=./outdat/out228.csv

${pfxc}mcal c='0b0 ^^ 0b1' i=./indat/dat_cal2.csv a=x o=./outdat/out229.csv
${pfxc}mcal c='0b1 ^^ 0b0' i=./indat/dat_cal2.csv a=x o=./outdat/out230.csv
${pfxc}mcal c='0b1 ^^ 0b1' i=./indat/dat_cal2.csv a=x o=./outdat/out231.csv
${pfxc}mcal c='0b0 ^^ 0b0' i=./indat/dat_cal2.csv a=x o=./outdat/out232.csv
${pfxc}mcal c='and(0b1,0b1,0b1,0b1)' i=./indat/dat_cal2.csv a=x o=./outdat/out233.csv
${pfxc}mcal c='and(0b1,0b0,0b0,0b0)' i=./indat/dat_cal2.csv a=x o=./outdat/out234.csv
${pfxc}mcal c='or(0b0,0b0,0b0,0b0)' i=./indat/dat_cal2.csv a=x o=./outdat/out235.csv
${pfxc}mcal c='or(0b1,0b0,0b0,0b0)' i=./indat/dat_cal2.csv a=x o=./outdat/out236.csv
${pfxc}mcal c='not(0b0)' i=./indat/dat_cal2.csv a=x o=./outdat/out237.csv
${pfxc}mcal c='not(0b1)' i=./indat/dat_cal2.csv a=x o=./outdat/out238.csv

${pfxc}mcal c='(10>9) || (10<9)' i=./indat/dat_cal2.csv a=x o=./outdat/out239.csv
${pfxc}mcal c='(10>9) && (10<9)' i=./indat/dat_cal2.csv a=x o=./outdat/out240.csv
${pfxc}mcal c='0b1' i=./indat/dat_cal2.csv a=x o=./outdat/out241.csv
${pfxc}mcal c='0b0' i=./indat/dat_cal2.csv a=x o=./outdat/out242.csv

${pfxc}mcal c='0t195700<0t195700' i=./indat/dat_cal2.csv a=x o=./outdat/out243.csv
${pfxc}mcal c='0t195700>0t195700' i=./indat/dat_cal2.csv a=x o=./outdat/out244.csv
${pfxc}mcal c='0t195700<=0t195700' i=./indat/dat_cal2.csv a=x o=./outdat/out245.csv
${pfxc}mcal c='0t195700>=0t195700' i=./indat/dat_cal2.csv a=x o=./outdat/out246.csv
${pfxc}mcal c='0t195700!=0t195700' i=./indat/dat_cal2.csv a=x o=./outdat/out247.csv
${pfxc}mcal c='0t195700==0t195700' i=./indat/dat_cal2.csv a=x o=./outdat/out248.csv

${pfxc}mcal c='0d20080923<0d20080923' i=./indat/dat_cal2.csv a=x o=./outdat/out249.csv
${pfxc}mcal c='0d20080923>0d20080923' i=./indat/dat_cal2.csv a=x o=./outdat/out250.csv
${pfxc}mcal c='0d20080923<=0d20080923' i=./indat/dat_cal2.csv a=x o=./outdat/out251.csv
${pfxc}mcal c='0d20080923>=0d20080923' i=./indat/dat_cal2.csv a=x o=./outdat/out252.csv
${pfxc}mcal c='0d20080923!=0d20080923' i=./indat/dat_cal2.csv a=x o=./outdat/out253.csv
${pfxc}mcal c='0d20080923==0d20080923' i=./indat/dat_cal2.csv a=x o=./outdat/out254.csv

${pfxc}mcal c='"abc"<"abc"' i=./indat/dat_cal2.csv a=x o=./outdat/out255.csv
${pfxc}mcal c='"abc">"abc"' i=./indat/dat_cal2.csv a=x o=./outdat/out256.csv
${pfxc}mcal c='"abc"<="abc"' i=./indat/dat_cal2.csv a=x o=./outdat/out257.csv
${pfxc}mcal c='"abc">="abc"' i=./indat/dat_cal2.csv a=x o=./outdat/out258.csv
${pfxc}mcal c='"abc"!="abc"' i=./indat/dat_cal2.csv a=x o=./outdat/out259.csv
${pfxc}mcal c='"abc"=="abc"' i=./indat/dat_cal2.csv a=x o=./outdat/out260.csv

${pfxc}mcal c='10>10' i=./indat/dat_cal2.csv a=x o=./outdat/out261.csv
${pfxc}mcal c='10<10' i=./indat/dat_cal2.csv a=x o=./outdat/out262.csv
${pfxc}mcal c='10<=10' i=./indat/dat_cal2.csv a=x o=./outdat/out263.csv
${pfxc}mcal c='10>=10' i=./indat/dat_cal2.csv a=x o=./outdat/out264.csv
${pfxc}mcal c='10==10' i=./indat/dat_cal2.csv a=x o=./outdat/out265.csv
${pfxc}mcal c='10!=10' i=./indat/dat_cal2.csv a=x o=./outdat/out266.csv

${pfxc}mcal c='10.5%3.2' i=./indat/dat_cal2.csv a=x o=./outdat/out267.csv
${pfxc}mcal c='10.5%3' i=./indat/dat_cal2.csv a=x o=./outdat/out268.csv
${pfxc}mcal c='10%3' i=./indat/dat_cal2.csv a=x o=./outdat/out269.csv

${pfxc}mcal c='1.5e+200/1.1e-200' i=./indat/dat_cal2.csv a=x o=./outdat/out270.csv
${pfxc}mcal c='10==(10/3*3)' i=./indat/dat_cal2.csv a=x o=./outdat/out271.csv
${pfxc}mcal c='10/3*3' i=./indat/dat_cal2.csv a=x o=./outdat/out272.csv
${pfxc}mcal c='0t121010-0t121000' i=./indat/dat_cal2.csv a=x o=./outdat/out273.csv
${pfxc}mcal c='0t235959+1' i=./indat/dat_cal2.csv a=x o=./outdat/out274.csv
${pfxc}mcal c='0t121010-10' i=./indat/dat_cal2.csv a=x o=./outdat/out275.csv
${pfxc}mcal c='0t121010+10' i=./indat/dat_cal2.csv a=x o=./outdat/out276.csv
${pfxc}mcal c='0d20080910-0d20080909' i=./indat/dat_cal2.csv a=x o=./outdat/out277.csv
${pfxc}mcal c='0d20080910-0d20080909' i=./indat/dat_cal2.csv a=x o=./outdat/out278.csv
${pfxc}mcal c='0d20080910-1000' i=./indat/dat_cal2.csv a=x o=./outdat/out279.csv
${pfxc}mcal c='0d20080910+10' i=./indat/dat_cal2.csv a=x o=./outdat/out280.csv

#ここから項目名指定のチェックをする
${pfxc}mcal      c='10==${num1}' i=./indat/dat_cal.csv    a=x o=./outdat/out281.csv
${pfxc}mcal -x   c='10==${1}'    i=./indat/dat_cal.csv    a=x o=./outdat/out281x.csv
${pfxc}mcal -nfn c='10==${1}'    i=./indat/dat_calnfn.csv     o=./outdat/out281nfn.csv

${pfxc}mcal      c='$t{time1}+${num1}' i=./indat/dat_cal.csv    a=x o=./outdat/out282.csv
${pfxc}mcal -x   c='$t{5}+${2}'        i=./indat/dat_cal.csv    a=x o=./outdat/out282x.csv
${pfxc}mcal -nfn c='$t{5}+${2}'        i=./indat/dat_calnfn.csv     o=./outdat/out282nfn.csv

${pfxc}mcal      c='$d{date1}+${num1}' i=./indat/dat_cal.csv    a=x o=./outdat/out283.csv
${pfxc}mcal -x   c='$d{3}+${1}'        i=./indat/dat_cal.csv    a=x o=./outdat/out283x.csv
${pfxc}mcal -nfn c='$d{3}+${1}'        i=./indat/dat_calnfn.csv     o=./outdat/out283nfn.csv

${pfxc}mcal      c='0d20080920+${num1}' i=./indat/dat_cal.csv    a=x o=./outdat/out284.csv
${pfxc}mcal -x   c='0d20080920+${1}'    i=./indat/dat_cal.csv    a=x o=./outdat/out284x.csv
${pfxc}mcal -nfn c='0d20080920+${1}'    i=./indat/dat_calnfn.csv     o=./outdat/out284nfn.csv

${pfxc}mcal      c='$d{date1}+10' i=./indat/dat_cal.csv    a=x o=./outdat/out285.csv
${pfxc}mcal -x   c='$d{3}+10'     i=./indat/dat_cal.csv    a=x o=./outdat/out285x.csv
${pfxc}mcal -nfn c='$d{3}+10'     i=./indat/dat_calnfn.csv     o=./outdat/out285nfn.csv

${pfxc}mcal c='0d20080920' i=./indat/dat_cal.csv a=x o=./outdat/out286.csv
${pfxc}mcal c='0d20080920+10' i=./indat/dat_cal.csv a=x o=./outdat/out287.csv

${pfxc}mcal      c='$s{key}+"abc"' i=./indat/dat_cal.csv    a=x o=./outdat/out288.csv
${pfxc}mcal -x   c='$s{0}+"abc"'   i=./indat/dat_cal.csv    a=x o=./outdat/out288x.csv
${pfxc}mcal -nfn c='$s{0}+"abc"'   i=./indat/dat_calnfn.csv     o=./outdat/out288nfn.csv

${pfxc}mcal      c='$s{key}' i=./indat/dat_cal.csv a=x o=./outdat/out289.csv
${pfxc}mcal -x   c='$s{0}'   i=./indat/dat_cal.csv a=x o=./outdat/out289x.csv
${pfxc}mcal -nfn c='$s{0}'   i=./indat/dat_calnfn.csv     o=./outdat/out289nfn.csv

${pfxc}mcal      c='${num1}+${num2}' i=./indat/dat_cal.csv    a=x o=./outdat/out290.csv
${pfxc}mcal -x   c='${1}+${2}'       i=./indat/dat_cal.csv    a=x o=./outdat/out290x.csv
${pfxc}mcal -nfn c='${1}+${2}'       i=./indat/dat_calnfn.csv     o=./outdat/out290nfn.csv

${pfxc}mcal      c='${num1}' i=./indat/dat_cal.csv    a=x o=./outdat/out291.csv
${pfxc}mcal -x   c='${1}'    i=./indat/dat_cal.csv    a=x o=./outdat/out291x.csv
${pfxc}mcal -nfn c='${1}'    i=./indat/dat_calnfn.csv     o=./outdat/out291nfn.csv

### 追加
#文字の差
${pfxc}mcal      c='$s{str}-"ba"' i=./indat/dat_cal.csv    a=x o=./outdat/out292.csv
${pfxc}mcal -x   c='$s{7}-"ba"'   i=./indat/dat_cal.csv    a=x o=./outdat/out292x.csv
${pfxc}mcal -nfn c='$s{7}-"ba"'   i=./indat/dat_calnfn.csv     o=./outdat/out292nfn.csv

${pfxc}mcal      c='$s{str2}-$s{str}' i=./indat/dat_cal.csv    a=x o=./outdat/out293.csv
${pfxc}mcal -x   c='$s{9}-$s{7}'     i=./indat/dat_cal.csv    a=x o=./outdat/out293x.csv
${pfxc}mcal -nfn c='$s{9}-$s{7}'     i=./indat/dat_calnfn.csv     o=./outdat/out293nfn.csv

#四則演算追加
${pfxc}mcal      c='${num1}*${num2}' i=./indat/dat_cal.csv    a=x o=./outdat/out294.csv
${pfxc}mcal -x   c='${1}*${2}'       i=./indat/dat_cal.csv    a=x o=./outdat/out294x.csv
${pfxc}mcal -nfn c='${1}*${2}'       i=./indat/dat_calnfn.csv     o=./outdat/out294nfn.csv

${pfxc}mcal      c='${num1}/${num2}' i=./indat/dat_cal.csv    a=x o=./outdat/out295.csv
${pfxc}mcal -x   c='${1}/${2}'       i=./indat/dat_cal.csv    a=x o=./outdat/out295x.csv
${pfxc}mcal -nfn c='${1}/${2}'       i=./indat/dat_calnfn.csv     o=./outdat/out295nfn.csv

${pfxc}mcal      c='${num1}%${num2}' i=./indat/dat_cal.csv    a=x o=./outdat/out296.csv
${pfxc}mcal -x   c='${1}%${2}'       i=./indat/dat_cal.csv    a=x o=./outdat/out296x.csv
${pfxc}mcal -nfn c='${1}%${2}'       i=./indat/dat_calnfn.csv     o=./outdat/out296nfn.csv

#if関数追加
${pfxc}mcal      c='if(${num1}>10,$s{str},$s{str2})' i=./indat/dat_cal.csv    a=x o=./outdat/out297.csv
${pfxc}mcal -x   c='if(${1}>10,$s{7},$s{9})'        i=./indat/dat_cal.csv    a=x o=./outdat/out297x.csv
${pfxc}mcal -nfn c='if(${1}>10,$s{7},$s{9})'        i=./indat/dat_calnfn.csv     o=./outdat/out297nfn.csv

${pfxc}mcal      c='if($s{key}=="x",$d{date1},$d{date2})' i=./indat/dat_cal.csv    a=x o=./outdat/out298.csv
${pfxc}mcal -x   c='if($s{0}=="x",$d{3},$d{5})'           i=./indat/dat_cal.csv    a=x o=./outdat/out298x.csv
${pfxc}mcal -nfn c='if($s{0}=="x",$d{3},$d{5})'           i=./indat/dat_calnfn.csv     o=./outdat/out298nfn.csv

${pfxc}mcal      c='if($s{key}=="y",$t{time1},$t{time2})' i=./indat/dat_cal.csv    a=x o=./outdat/out299.csv
${pfxc}mcal -x   c='if($s{0}=="y",$t{4},$t{6})'           i=./indat/dat_cal.csv    a=x o=./outdat/out299x.csv
${pfxc}mcal -nfn c='if($s{0}=="y",$t{4},$t{6})'           i=./indat/dat_calnfn.csv     o=./outdat/out299nfn.csv

#isnull追加
${pfxc}mcal      c='isnull(${num1})' i=./indat/dat_cal.csv    a=x o=./outdat/out300.csv
${pfxc}mcal -x   c='isnull(${2})'    i=./indat/dat_cal.csv    a=x o=./outdat/out300x.csv
${pfxc}mcal -nfn c='isnull(${2})'    i=./indat/dat_calnfn.csv     o=./outdat/out300nfn.csv

${pfxc}mcal      c='isnull($d{date1})' i=./indat/dat_cal.csv    a=x o=./outdat/out301.csv
${pfxc}mcal -x   c='isnull($d{3})'     i=./indat/dat_cal.csv    a=x o=./outdat/out301x.csv
${pfxc}mcal -nfn c='isnull($d{3})'     i=./indat/dat_calnfn.csv     o=./outdat/out301nfn.csv

${pfxc}mcal      c='isnull($t{time1})' i=./indat/dat_cal.csv    a=x o=./outdat/out302.csv
${pfxc}mcal -x   c='isnull($t{5})'     i=./indat/dat_cal.csv    a=x o=./outdat/out302x.csv
${pfxc}mcal -nfn c='isnull($t{5})'     i=./indat/dat_calnfn.csv     o=./outdat/out302nfn.csv

${pfxc}mcal      c='isnull($s{str})' i=./indat/dat_cal.csv    a=x o=./outdat/out303.csv
${pfxc}mcal -x   c='isnull($s{7})'   i=./indat/dat_cal.csv    a=x o=./outdat/out303x.csv
${pfxc}mcal -nfn c='isnull($s{7})'   i=./indat/dat_calnfn.csv     o=./outdat/out303nfn.csv

${pfxc}mcal      c='isnull($b{num1})' i=./indat/dat_cal.csv    a=x o=./outdat/out304.csv
${pfxc}mcal -x   c='isnull($b{1})'    i=./indat/dat_cal.csv    a=x o=./outdat/out304x.csv
${pfxc}mcal -nfn c='isnull($b{1})'    i=./indat/dat_calnfn.csv     o=./outdat/out304nfn.csv

#型変換関数追加
${pfxc}mcal      c='s2n($s{str})' i=./indat/dat_cal.csv    a=x o=./outdat/out305.csv
${pfxc}mcal -x   c='s2n($s{7})'   i=./indat/dat_cal.csv    a=x o=./outdat/out305x.csv
${pfxc}mcal -nfn c='s2n($s{7})'   i=./indat/dat_calnfn.csv     o=./outdat/out305nfn.csv

${pfxc}mcal      c='s2d($s{str})' i=./indat/dat_cal.csv    a=x o=./outdat/out306.csv
${pfxc}mcal -x   c='s2d($s{7})'   i=./indat/dat_cal.csv    a=x o=./outdat/out306x.csv
${pfxc}mcal -nfn c='s2d($s{7})'   i=./indat/dat_calnfn.csv     o=./outdat/out306nfn.csv

${pfxc}mcal      c='s2t($s{str})' i=./indat/dat_cal.csv    a=x o=./outdat/out307.csv
${pfxc}mcal -x   c='s2t($s{7})'   i=./indat/dat_cal.csv    a=x o=./outdat/out307x.csv
${pfxc}mcal -nfn c='s2t($s{7})'   i=./indat/dat_calnfn.csv     o=./outdat/out307nfn.csv

${pfxc}mcal      c='n2s(${num1})' i=./indat/dat_cal.csv    a=x o=./outdat/out308.csv
${pfxc}mcal -x   c='n2s(${1})'    i=./indat/dat_cal.csv    a=x o=./outdat/out308x.csv
${pfxc}mcal -nfn c='n2s(${1})'    i=./indat/dat_calnfn.csv     o=./outdat/out308nfn.csv

${pfxc}mcal      c='d2s($d{date1})' i=./indat/dat_cal.csv    a=x o=./outdat/out309.csv
${pfxc}mcal -x   c='d2s($d{3})'     i=./indat/dat_cal.csv    a=x o=./outdat/out309x.csv
${pfxc}mcal -nfn c='d2s($d{3})'     i=./indat/dat_calnfn.csv     o=./outdat/out309nfn.csv

${pfxc}mcal      c='time($t{time1})' i=./indat/dat_cal.csv    a=x o=./outdat/out310.csv
${pfxc}mcal -x   c='time($t{4})'     i=./indat/dat_cal.csv    a=x o=./outdat/out310x.csv
${pfxc}mcal -nfn c='time($t{4})'     i=./indat/dat_calnfn.csv     o=./outdat/out310nfn.csv

${pfxc}mcal      c='b2n($b{num1})' i=./indat/dat_cal.csv    a=x o=./outdat/out311.csv
${pfxc}mcal -x   c='b2n($b{1})'    i=./indat/dat_cal.csv    a=x o=./outdat/out311x.csv
${pfxc}mcal -nfn c='b2n($b{1})'    i=./indat/dat_calnfn.csv     o=./outdat/out311nfn.csv

${pfxc}mcal      c='b2s($b{str})' i=./indat/dat_cal.csv    a=x o=./outdat/out312.csv
${pfxc}mcal -x   c='b2s($b{8})'   i=./indat/dat_cal.csv    a=x o=./outdat/out312x.csv
${pfxc}mcal -nfn c='b2s($b{8})'   i=./indat/dat_calnfn.csv     o=./outdat/out312nfn.csv

${pfxc}mcal      c='n2b(${num1})' i=./indat/dat_cal.csv    a=x o=./outdat/out313.csv
${pfxc}mcal -x   c='n2b(${1})'    i=./indat/dat_cal.csv    a=x o=./outdat/out313x.csv
${pfxc}mcal -nfn c='n2b(${1})'    i=./indat/dat_calnfn.csv     o=./outdat/out313nfn.csv

${pfxc}mcal      c='s2b($s{str})' i=./indat/dat_cal.csv    a=x o=./outdat/out314.csv
${pfxc}mcal -x   c='s2b($s{8})'   i=./indat/dat_cal.csv    a=x o=./outdat/out314x.csv
${pfxc}mcal -nfn c='s2b($s{8})'   i=./indat/dat_calnfn.csv     o=./outdat/out314nfn.csv

#日付時刻関連
${pfxc}mcal c='today()' i=./indat/dat_cal.csv a=x o=./outdat/out315.csv
${pfxc}mcal c='now()' i=./indat/dat_cal.csv a=x o=./outdat/out316.csv

${pfxc}mcal      c='leapyear($d{date1})' i=./indat/dat_cal.csv    a=x o=./outdat/out317.csv
${pfxc}mcal -x   c='leapyear($d{3})'     i=./indat/dat_cal.csv    a=x o=./outdat/out317x.csv
${pfxc}mcal -nfn c='leapyear($d{3})'     i=./indat/dat_calnfn.csv     o=./outdat/out317nfn.csv

${pfxc}mcal      c='leapyear($t{time1})' i=./indat/dat_cal.csv    a=x o=./outdat/out318.csv
${pfxc}mcal -x   c='leapyear($t{4})'     i=./indat/dat_cal.csv    a=x o=./outdat/out318x.csv
${pfxc}mcal -nfn c='leapyear($t{4})'     i=./indat/dat_calnfn.csv     o=./outdat/out318nfn.csv

${pfxc}mcal      c='uxt2d(uxt($d{date1}))' i=./indat/dat_cal.csv    a=x o=./outdat/out319.csv
${pfxc}mcal -x   c='uxt2d(uxt($d{3}))'     i=./indat/dat_cal.csv    a=x o=./outdat/out319x.csv
${pfxc}mcal -nfn c='uxt2d(uxt($d{3}))'     i=./indat/dat_calnfn.csv     o=./outdat/out319nfn.csv

${pfxc}mcal c='uxt2d(0)' i=./indat/dat_cal.csv a=x o=./outdat/out320.csv

#算術関数
${pfxc}mcal c='factorial(10)' i=./indat/dat_cal.csv a=x o=./outdat/out321.csv

#文字列関数
${pfxc}mcal      c='cat("_",$s{str},$s{str2})' i=./indat/dat_cal.csv    a=x o=./outdat/out322.csv
${pfxc}mcal -x   c='cat("_",$s{7},$s{9})'     i=./indat/dat_cal.csv    a=x o=./outdat/out322x.csv
${pfxc}mcal -nfn c='cat("_",$s{7},$s{9})'     i=./indat/dat_calnfn.csv     o=./outdat/out322nfn.csv

#N radian N1 : 角度N1をラジアンに変換する。 N1*π/180.
${pfxc}mcal c='radian(180)' i=./indat/dat_cal2.csv a=x o=./outdat/out326.csv

#N degree N1 : ラジアンN1を角度に変換する. N1*180/π.
${pfxc}mcal c='degree(2*pi())' i=./indat/dat_cal2.csv a=x o=./outdat/out327.csv

#01という数値項目に"00a"という文字列があれば1を、そうでなければ0を出力する。
${pfxc}mcal      c='$s{01}=="00a"' a=x i=./indat/dat_cal.csv    o=./outdat/out328.csv
${pfxc}mcal -x   c='$s{10}=="00a"' a=x i=./indat/dat_cal.csv    o=./outdat/out328x.csv
${pfxc}mcal -nfn c='$s{10}=="00a"'     i=./indat/dat_calnfn.csv o=./outdat/out328nfn.csv

#new parameter
${pfxc}mcal      c='diffyear($d{date1},$d{date2})' a=x i=./indat/dat_cal.csv    o=./outdat/out329.csv
${pfxc}mcal      c='diffmonth($d{date1},$d{date2})' a=x i=./indat/dat_cal.csv    o=./outdat/out330.csv
${pfxc}mcal      c='diffday($d{date1},$d{date2})' a=x i=./indat/dat_cal.csv    o=./outdat/out331.csv

${pfxc}mcal      c='diffyear(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out332.csv
${pfxc}mcal      c='diffmonth(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out333.csv
${pfxc}mcal      c='diffday(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out334.csv
${pfxc}mcal      c='diffhour(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out335.csv
${pfxc}mcal      c='diffminute(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out336.csv
${pfxc}mcal      c='diffsecond(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out337.csv

${pfxc}mcal      c='tseconds($t{time1})' a=x i=./indat/dat_cal.csv    o=./outdat/out338.csv

${pfxc}mcal      c='avg(${num1},${num2},"-n")'     a=x i=./indat/dat_cal.csv    o=./outdat/out339.csv
${pfxc}mcal      c='sqsum(${num1},${num2},"-n")'  a=x i=./indat/dat_cal.csv    o=./outdat/out340.csv
${pfxc}mcal      c='product(${num1},${num2},"-n")' a=x i=./indat/dat_cal.csv    o=./outdat/out341.csv


${pfxc}mcal      c='avg(${num1},${num2},nulln(),"-n")'     a=x i=./indat/dat_cal.csv    o=./outdat/out342.csv
${pfxc}mcal      c='sqsum(${num1},${num2},nulln(),"-n")'  a=x i=./indat/dat_cal.csv    o=./outdat/out343.csv
${pfxc}mcal      c='product(${num1},${num2},nulln(),"-n")' a=x i=./indat/dat_cal.csv    o=./outdat/out344.csv


${pfxc}mcal      c='distgps(34.701909,135.4949770,35.681382,139.766084)'  a=x i=./indat/dat_cal.csv    o=./outdat/out345.csv

${pfxc}mcal      c='rand(1)'  a=x i=./indat/dat_cal.csv    o=./outdat/out346.csv
${pfxc}mcal      c='rand()'  a=x i=./indat/dat_cal.csv    o=./outdat/out347.csv

${pfxc}mcal      c='berrand(rand(1),2)'  a=x i=./indat/dat_cal.csv    o=./outdat/out348.csv
${pfxc}mcal      c='binomdist(randi(1,1000,1),1000,0.5)'  a=x i=./indat/dat_cal.csv    o=./outdat/out349.csv

${pfxc}mcal c='fixlenw($s{wstr},2,"L","#")' i=./indat/dat_cal.csv a=x o=./outdat/out350.csv
${pfxc}mcal c='fixlenw($s{wstr},2,"R","#")' i=./indat/dat_cal.csv a=x o=./outdat/out351.csv
${pfxc}mcal c='fixlenw($s{wstr},5,"L"," ")' i=./indat/dat_cal.csv a=x o=./outdat/out352.csv
${pfxc}mcal c='fixlenw($s{wstr},5,"R"," ")' i=./indat/dat_cal.csv a=x o=./outdat/out353.csv
${pfxc}mcal c='fixlenw($s{wstr},5,"L","#")' i=./indat/dat_cal.csv a=x o=./outdat/out354.csv
${pfxc}mcal c='fixlenw($s{wstr},5,"R","#")' i=./indat/dat_cal.csv a=x o=./outdat/out355.csv

${pfxc}mcal c='hasspacew("abcdef")' i=./indat/dat_cal.csv a=x o=./outdat/out356.csv
${pfxc}mcal c='hasspacew("abc def")' i=./indat/dat_cal.csv a=x o=./outdat/out357.csv
${pfxc}mcal c='hasspacew("abc　def")' i=./indat/dat_cal.csv a=x o=./outdat/out358.csv

${pfxc}mcal c='strchr($s{str},"c")' i=./indat/dat_cal.csv a=x o=./outdat/out359.csv
${pfxc}mcal c='strchr($s{str},"e")' i=./indat/dat_cal.csv a=x o=./outdat/out360.csv

${pfxc}mcal c='regexlenw($s{wstr},"あ")' i=./indat/dat_cal.csv a=x o=./outdat/out361.csv
${pfxc}mcal c='regexlenw($s{wstr},"し.*$")' i=./indat/dat_cal.csv a=x o=./outdat/out362.csv

${pfxc}mcal c='regexposw($s{wstr},"あ")' i=./indat/dat_cal.csv a=x o=./outdat/out363.csv
${pfxc}mcal c='regexposw($s{wstr},"し$")' i=./indat/dat_cal.csv a=x o=./outdat/out364.csv

${pfxc}mcal c='regexstrw($s{wstr},"あ")' i=./indat/dat_cal.csv a=x o=./outdat/out365.csv
${pfxc}mcal c='regexstrw($s{wstr},"し$")' i=./indat/dat_cal.csv a=x o=./outdat/out366.csv

${pfxc}mcal c='regexpfxw($s{wstr},"あ")' i=./indat/dat_cal.csv a=x o=./outdat/out367.csv
${pfxc}mcal c='regexpfxw($s{wstr},"し$")' i=./indat/dat_cal.csv a=x o=./outdat/out368.csv

${pfxc}mcal c='regexsfxw($s{wstr},"あ")' i=./indat/dat_cal.csv a=x o=./outdat/out369.csv
${pfxc}mcal c='regexsfxw($s{wstr},"し$")' i=./indat/dat_cal.csv a=x o=./outdat/out370.csv

${pfxc}mcal c='bottom()' i=./indat/dat_cal.csv a=x o=./outdat/out371.csv

${pfxc}mcal c='countnull(${num1},#{num1},nulln())' i=./indat/dat_cal.csv a=x o=./outdat/out372.csv
${pfxc}mcal c='countnull($s{str},#s{str},nulls())' i=./indat/dat_cal.csv a=x o=./outdat/out373.csv
${pfxc}mcal c='countnull($t{time1},#t{time1},nullt())' i=./indat/dat_cal.csv a=x o=./outdat/out374.csv
${pfxc}mcal c='countnull($d{date1},#d{date1},nulld())' i=./indat/dat_cal.csv a=x o=./outdat/out375.csv
${pfxc}mcal c='countnull($b{a},#b{a},nullb())'    i=./indat/dat4.csv a=x o=./outdat/out376.csv
${pfxc}mcal c='age(s2t($s{date1}+$s{time1}),s2t($s{date2}+$s{time2}))' a=x i=./indat/dat_cal.csv    o=./outdat/out377.csv
${pfxc}mcal c='10^2' i=./indat/dat_cal2.csv a=x o=./outdat/out378.csv

${pfxc}mcal      c='berrand(rand(1),-1)'  a=x i=./indat/dat_cal.csv    o=./outdat/out379.csv
${pfxc}mcal      c='binomdist(randi(1,10000,1),10000,0.5)'  a=x i=./indat/dat_cal.csv    o=./outdat/out380.csv


${pfxc}mcal c='matcha("bc","bc","bc","bc")' i=./indat/dat_cal2.csv a=x o=./outdat/out381.csv
${pfxc}mcal c='matcha("bc","bc","bcd")' i=./indat/dat_cal2.csv a=x o=./outdat/out382.csv
${pfxc}mcal c='match("a","a","b","c")' i=./indat/dat_cal2.csv a=x o=./outdat/out383.csv
${pfxc}mcal c='match("a","ba","ac")' i=./indat/dat_cal2.csv a=x o=./outdat/out384.csv

${pfxc}mcal c='argsize($s{num*})' i=./indat/dat_cal.csv a=x o=./outdat/out385.csv

${pfxc}mcal c='date(0t20080920121315)' i=./indat/dat_cal.csv a=x o=./outdat/out386.csv
${pfxc}mcal c='years(0t20080920121315)' i=./indat/dat_cal.csv a=x o=./outdat/out387.csv
${pfxc}mcal c='years(0d20080920)' i=./indat/dat_cal.csv a=x o=./outdat/out388.csv
${pfxc}mcal c='months(0t20080920121315)' i=./indat/dat_cal.csv a=x o=./outdat/out389.csv
${pfxc}mcal c='months(0d20080920)' i=./indat/dat_cal.csv a=x o=./outdat/out390.csv
${pfxc}mcal c='days(0t20080920121315)' i=./indat/dat_cal.csv a=x o=./outdat/out391.csv
${pfxc}mcal c='days(0d20080920)' i=./indat/dat_cal.csv a=x o=./outdat/out392.csv


${pfxc}mcal c='dowj($d{日付})' a="曜日" i=./indat/dat.csv o=./outdat/out393.csv
${pfxc}mcal c='dowj(s2t($s{date1}+$s{time1}))' a="曜日" i=./indat/dat_cal.csv o=./outdat/out394.csv
${pfxc}mcal c='week111($d{日付})' a="週" i=./indat/dat.csv o=./outdat/out395.csv
${pfxc}mcal c='week111(s2t($s{date1}+$s{time1}))' a="週" i=./indat/dat_cal.csv o=./outdat/out396.csv

${pfxc}mcal c='$s{str1}-$s{str2}' a=rls i=./indat/dat5.csv o=./outdat/out397.csv
${pfxc}mcal c='$d{date1}-${num2}' a=rls i=./indat/dat5.csv o=./outdat/out398.csv
${pfxc}mcal c='$t{dt1}-${num2}' a=rls i=./indat/dat5.csv o=./outdat/out399.csv
${pfxc}mcal c='${num1}%${num2}' a=rls i=./indat/dat5.csv o=./outdat/out400.csv
${pfxc}mcal c='${num1}^${num2}' a=rls i=./indat/dat5.csv o=./outdat/out401.csv
${pfxc}mcal c='$t{time1}>=$t{time2}' a=rls i=./indat/dat5.csv o=./outdat/out402.csv
${pfxc}mcal c='$t{time1}>$t{time2}' a=rls i=./indat/dat5.csv o=./outdat/out403.csv
${pfxc}mcal c='$t{time1}<=$t{time2}' a=rls i=./indat/dat5.csv o=./outdat/out404.csv
${pfxc}mcal c='$t{time1}<$t{time2}' a=rls i=./indat/dat5.csv o=./outdat/out405.csv
${pfxc}mcal c='$t{time1}==$t{time2}' a=rls i=./indat/dat5.csv o=./outdat/out406.csv
${pfxc}mcal c='$t{time1}!=$t{time2}' a=rls i=./indat/dat5.csv o=./outdat/out407.csv
${pfxc}mcal c='$b{bool1}^^$b{bool2}' a=rls i=./indat/dat5.csv o=./outdat/out408.csv


${pfxc}mcal c='if($b{bool1},${num1},${num2})' a=rls i=./indat/dat5.csv o=./outdat/out409.csv
${pfxc}mcal c='if($b{bool1},$d{date1},$d{date2})' a=rls i=./indat/dat5.csv o=./outdat/out410.csv
${pfxc}mcal c='if($b{bool1},$t{dt1},$t{dt2})' a=rls i=./indat/dat5.csv o=./outdat/out411.csv
${pfxc}mcal c='and($b{bool1},$b{bool2})' a=rls i=./indat/dat5.csv o=./outdat/out412.csv
${pfxc}mcal c='or($b{bool1},$b{bool2})' a=rls i=./indat/dat5.csv o=./outdat/out413.csv
${pfxc}mcal c='isnull($s{str1})' a=rls i=./indat/dat5.csv o=./outdat/out414.csv

${pfxc}mcal c='s2d($s{date1})' a=rls i=./indat/dat5.csv o=./outdat/out415.csv
${pfxc}mcal c='n2s(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out416.csv
${pfxc}mcal c='n2b(${bool1})' a=rls i=./indat/dat5.csv o=./outdat/out417.csv
${pfxc}mcal c='format(${num1},"%.3f")' a=rls i=./indat/dat5.csv o=./outdat/out418.csv

${pfxc}mcal c='date($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out419.csv
${pfxc}mcal c='time($t{time1})' a=rls i=./indat/dat5.csv o=./outdat/out420.csv

#再チェック
${pfxc}mcal c='julian($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out421.csv
${pfxc}mcal c='julian($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out422.csv
${pfxc}mcal c='julian2t(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out423.csv
${pfxc}mcal c='uxt($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out425.csv
${pfxc}mcal c='uxt2t(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out426.csv


${pfxc}mcal c='year($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out427.csv
${pfxc}mcal c='years($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out428.csv
${pfxc}mcal c='years($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out429.csv
${pfxc}mcal c='month($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out430.csv
${pfxc}mcal c='months($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out431.csv
${pfxc}mcal c='months($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out432.csv
${pfxc}mcal c='monthe($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out434.csv
${pfxc}mcal c='monthe($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out435.csv
${pfxc}mcal c='monthes($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out436.csv
${pfxc}mcal c='monthes($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out437.csv
${pfxc}mcal c='day($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out438.csv
${pfxc}mcal c='days($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out439.csv
${pfxc}mcal c='days($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out440.csv

${pfxc}mcal c='week($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out441.csv
${pfxc}mcal c='week($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out442.csv
${pfxc}mcal c='dow($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out443.csv
${pfxc}mcal c='dowe($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out444.csv
${pfxc}mcal c='dowes($d{date1})' a=rls i=./indat/dat5.csv o=./outdat/out445.csv
${pfxc}mcal c='dowes($t{dt1})' a=rls i=./indat/dat5.csv o=./outdat/out446.csv
${pfxc}mcal c='minutes($t{time1})' a=rls i=./indat/dat5.csv o=./outdat/out447.csv
${pfxc}mcal c='seconds($t{time1})' a=rls i=./indat/dat5.csv o=./outdat/out448.csv


${pfxc}mcal c='avg(${num1},${num2})' a=rls i=./indat/dat5.csv o=./outdat/out449.csv
${pfxc}mcal c='sqsum(${num1},${num2})' a=rls i=./indat/dat5.csv o=./outdat/out450.csv
${pfxc}mcal c='factorial(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out451.csv
${pfxc}mcal c='gcd(${num1},${num2})' a=rls i=./indat/dat5.csv o=./outdat/out452.csv
${pfxc}mcal c='lcm(${num1},${num2})' a=rls i=./indat/dat5.csv o=./outdat/out453.csv
${pfxc}mcal c='fract(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out454.csv
${pfxc}mcal c='int(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out455.csv
${pfxc}mcal c='round(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out456.csv
${pfxc}mcal c='floor(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out457.csv
${pfxc}mcal c='ceil(${num1})' a=rls i=./indat/dat5.csv o=./outdat/out458.csv
${pfxc}mcal c='product(${num1},${num2})' a=rls i=./indat/dat5.csv o=./outdat/out459.csv


${pfxc}mcal c='dist("euclid",${num1},${num2},100,200)' a=rls i=./indat/dat5.csv o=./outdat/out460.csv
${pfxc}mcal c='dist("hamming",$s{str1},$s{str2},"a","a")' a=rls i=./indat/dat5.csv o=./outdat/out461.csv
${pfxc}mcal c='distgps(nulln(),80,70,10)' a=rls i=./indat/dat5.csv o=./outdat/out462.csv
${pfxc}mcal c='distgps(200,200,200,200)' a=rls i=./indat/dat5.csv o=./outdat/out463.csv
${pfxc}mcal c='distgps(100,100,100,100)' a=rls i=./indat/dat5.csv o=./outdat/out464.csv
${pfxc}mcal c='heron(${num1},${num2},nulln(),4,5,6)' a=rls i=./indat/dat5.csv o=./outdat/out465.csv
${pfxc}mcal c='randi(nulln(),${num2},1)' a=rls i=./indat/dat5.csv o=./outdat/out466.csv
${pfxc}mcal c='randi(100,1,1)' a=rls i=./indat/dat5.csv o=./outdat/out467.csv
${pfxc}mcal c='rand(nulln())' a=rls i=./indat/dat5.csv o=./outdat/out468.csv
${pfxc}mcal c='nrand(nulln(),1,1)' i=./indat/dat5.csv a=x o=./outdat/out469.csv
${pfxc}mcal c='berrand(2,1)' i=./indat/dat5.csv a=x o=./outdat/out470.csv
${pfxc}mcal c='berrand(nulln(),1)' i=./indat/dat5.csv a=x o=./outdat/out471.csv
${pfxc}mcal c='binomdist(50,100,0.5)' i=./indat/dat5.csv a=x o=./outdat/out472.csv
${pfxc}mcal c='binomdist(nulln(),100,1)' i=./indat/dat5.csv a=x o=./outdat/out473.csv
${pfxc}mcal c='sign(${num1})' i=./indat/dat5.csv a=x o=./outdat/out474.csv
${pfxc}mcal c='acos(${num1})' i=./indat/dat5.csv a=x o=./outdat/out475.csv
${pfxc}mcal c='asin(${num1})' i=./indat/dat5.csv a=x o=./outdat/out476.csv
${pfxc}mcal c='atan2(${num1},${num2})' i=./indat/dat5.csv a=x o=./outdat/out477.csv
${pfxc}mcal c='cos(${num1})' i=./indat/dat5.csv a=x o=./outdat/out478.csv
${pfxc}mcal c='sin(${num1})' i=./indat/dat5.csv a=x o=./outdat/out479.csv
${pfxc}mcal c='tan(${num1})' i=./indat/dat5.csv a=x o=./outdat/out480.csv
${pfxc}mcal c='degree(${num1})' i=./indat/dat5.csv a=x o=./outdat/out481.csv
${pfxc}mcal c='radian(${num1})' i=./indat/dat5.csv a=x o=./outdat/out482.csv
${pfxc}mcal c='cosh(${num1})' i=./indat/dat5.csv a=x o=./outdat/out483.csv
${pfxc}mcal c='sinh(${num1})' i=./indat/dat5.csv a=x o=./outdat/out484.csv
${pfxc}mcal c='tanh(${num1})' i=./indat/dat5.csv a=x o=./outdat/out485.csv
${pfxc}mcal c='cat(nulls(),$s{str1},$s{str2})' i=./indat/dat5.csv a=x o=./outdat/out486.csv
${pfxc}mcal c='cat("_",$s{str1},$s{str2})' i=./indat/dat5.csv a=x o=./outdat/out487.csv
${pfxc}mcal c='fixlenw($s{str1},5,"L","_")' i=./indat/dat5.csv a=x o=./outdat/out488.csv
${pfxc}mcal c='rightw($s{str1},1)' i=./indat/dat5.csv a=x o=./outdat/out489.csv
${pfxc}mcal c='leftw($s{str1},1)' i=./indat/dat5.csv a=x o=./outdat/out490.csv
${pfxc}mcal c='mid($s{str1},1,1)' i=./indat/dat5.csv a=x o=./outdat/out491.csv

${pfxc}mcal c='if(top(),$s{str1},#s{}+$s{str1})' i=./indat/dat5.csv a=x o=./outdat/out492.csv
${pfxc}mcal c='if(top(),$t{dt1},#t{}+${num1})' i=./indat/dat5.csv a=x o=./outdat/out493.csv
${pfxc}mcal c='if(top(),$d{date1},#d{}+${num1})' i=./indat/dat5.csv a=x o=./outdat/out494.csv


${pfxc}mcal c='d2t($d{date1})' i=./indat/dat5.csv a=x o=./outdat/out495.csv
${pfxc}mcal c='t2d($t{dt1})' i=./indat/dat5.csv a=x o=./outdat/out496.csv
${pfxc}mcal c='b2s($b{bool1})' i=./indat/dat5.csv a=x o=./outdat/out497.csv

