/* ////////// LICENSE INFO ////////////////////

 * Copyright (C) 2013 by NYSOL CORPORATION
 *
 * Unless you have received this program directly from NYSOL pursuant
 * to the terms of a commercial license agreement with NYSOL, then
 * this program is licensed to you under the terms of the GNU Affero General
 * Public License (AGPL) as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF 
 * NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Please refer to the AGPL (http://www.gnu.org/licenses/agpl-3.0.txt)
 * for more details.

 ////////// LICENSE INFO ////////////////////*/
// ============================================================================
// kgCSVutils.cpp csvファイル(infile)関連のutils
// ============================================================================
#include <sstream>
#include <kgCSVutils.h>
#include <kgMethod.h>
#include <kgWildcard.h>

// -----------------------------------------------------------------------------
// 項目名->項目番号を評価する．（項目名変換あり）
// 項目名変換するのは以下の２つ．
// 1. 範囲指定 -:数値指定のみの場合
//	 ex. 1-3 => 1,3
// 2. ワイルドカード *:任意の文字列にマッチ ?:任意の一文字にマッチ
// 3. 第二vector(attr)の第一vector(name)による置換(&をnameに置換)
//   ex. aaa:&_cm =>aaa:aaa_cm  aa*:&_cm => aab:aab_cm,aac:aac_cm,...
// -----------------------------------------------------------------------------
vector<int> kglib::evalFldName(vector<kgstr_t>& name, vector<kgstr_t>& attr, kgCSV* csv,bool fldByNum)
{
	vector<int>     vi;
	vector<kgstr_t> vs1;
	vector<kgstr_t> vs2;
	for(size_t i=0; i<name.size(); i++){
		kgstr_t s1=name.at(i);
		kgstr_t s2=attr.at(i);
		//数値指定の場合
		if( fldByNum ){
			kgstr_t sf;
			kgstr_t st;
			string::size_type pos=s1.find('-');
			if(pos!=string::npos){   // 範囲指定がある場合
				sf=s1.substr(0,pos); // from
				st=s1.substr(pos+1); // to
			}else{                   // 範囲指定がない場合
				sf=s1;               // from
				st=s1;               // to
			}
			// 末尾からの項目番号指定を評価して項目番号を求める
			int n1=evalDigit(sf,csv->fldSize());
			int n2=evalDigit(st,csv->fldSize());
			// vectorに登録する
			// 一行めが項目行でない場合は項目番号をセットする
			if(n1>n2) {
				for(int j=n1; j>=n2; j--){
					vi.push_back(j);
					if(!csv->noFldName()){
						vs1.push_back(csv->fldName(j));
						vs2.push_back(attr.at(i));
					}
					else{
						ostringstream ss;
						ss << j; //name自体は変えない
						vs1.push_back(ss.str());
						vs2.push_back(attr.at(i));
					}
				}
			}else{
				for(int j=n1; j<=n2; j++){
					vi.push_back(j);
					if(!csv->noFldName()){
						vs1.push_back(csv->fldName(j));
						vs2.push_back(attr.at(i));
					}
					else{
						ostringstream ss;
						ss << j ;//name自体は変えない
						vs1.push_back(ss.str());
						vs2.push_back(attr.at(i));
					}
				}
			}
		}else{
			if(csv->noFldName()){
    		throw kgError("cannot specify the field names with -nfn option");
			}
			// ワイルドカード文字を含む場合は，CSVの項目名とマッチングする．
			// マッチングはソート情報を除いた物で行う
			kgWildCard wc(s1);
			if(wc.hasWildCard()){
				for(size_t j=0; j< csv->fldSize(); j++){
					// CSVの第i項目名がワイルドカードwcにマッチ?
					if( wc.match(csv->fldName(j)) ){
						vi.push_back(j);
						vs1.push_back(csv->fldName(j));
						vs2.push_back(attr.at(i));
					}
				}
			// ワイルドカード文字を含まない場合は，直接CSVの項目番号を求める.
			}else{
				vi.push_back(csv->fldNum(s1));
				vs1.push_back(name.at(i));
				vs2.push_back(attr.at(i));
			}
		}
	}
	name.clear();
	attr.clear();
	for(unsigned int i=0; i<vs1.size(); i++){
		name.push_back(vs1.at(i));
		attr.push_back(vs2.at(i));
	}
	return vi;
}
// -----------------------------------------------------------------------------
// 項目名->項目番号を評価する．（evalflg=true:項目名変換有,evalflg=false:項目名変換無）
// -----------------------------------------------------------------------------
vector<int> kglib::evalFldName(vector<kgstr_t>& name, kgCSV* csv,bool fldByNum,bool evalflg)
{
	vector<int> vi;
	if(evalflg){
		vector<kgstr_t> dummy; 
		dummy.resize(name.size()); 
		vi = evalFldName(name, dummy,  csv,fldByNum);
	}
	else{
		for(size_t i=0; i<name.size(); i++){
			kgstr_t s1=name.at(i);
			if( fldByNum ){
				int n1=evalDigit(s1,csv->fldSize());
				vi.push_back(n1);
			}else{
				if(csv->noFldName()){
	 	   		throw kgError("cannot specify field names with -nfn option");
				}
				vi.push_back(csv->fldNum(s1));
			}
		}
	}
	return vi;
}
// -----------------------------------------------------------------------------
// c=で与えられた式の項目名(${..})を検索し，項目名を展開する．
// $s{}$d{}$t{}$b{}にも対応
// exp1. c=sum(${a*})  c=sum(${aa},${ab})
// exp2. c=sum(${1_2L})  c=sum(${1},${2},${3})
// 返り値:展開後の式
// -----------------------------------------------------------------------------
kgstr_t kglib::evalCalFldName(kgstr_t& expr, kgCSV& iFile,bool fldByNum)
{
  kgstr_t newExpr;
	const kgstr_t base[] = {"","s","d","t","b"}; 
	int b_pos=-1;
	kgstr_t::size_type prv=0;
	
  while(1){
	  kgstr_t::size_type pos;
  	for(int i=0;i<5;i++){
	    pos = expr.find("$"+base[i]+"{",prv);
	    if(pos != kgstr_t::npos){ 
	    	b_pos = i;
	    	break;
	    }
	  }
		// 項目名発見時の処理
    if(pos != kgstr_t::npos){
			newExpr.append(expr,prv,pos-prv);            // "${"の直前までコピー
    	kgstr_t::size_type end = expr.find("}",pos); // }を探す
    	if(pos != kgstr_t::npos){                    // }を発見
				vector<kgstr_t> name; 
				kgstr_t fldName;                           //   項目名を切り出し
				fldName.append(expr,pos+base[b_pos].size()+2,end-(pos+base[b_pos].size())-2);      //   委ねる．
				name.push_back(fldName);
				vector<int> num = evalFldName(name, &iFile,fldByNum,true);
				if( fldByNum ){           //     項目番号指定の場合
					newExpr.append(
						toString(num,0,",","$"+base[b_pos]+"{","}")  //     番号リストを追加(項目番号は１から開始が０から開始になったので0をプラスするようにする)
					);
				}else{                                     //     項目名指定の場合
					newExpr.append(
						toString(name,",","$"+base[b_pos]+"{","}")   //     項目名リストを追加
					);
				}
				prv=end+1;                                 //     prvを更新して
				continue;                                  //     再び${検索に戻る
			}else{                                       // }が無ければエラー
	 	   	throw kgError("unmatched variable brackets {...}");
			}

		// 項目名がなければ最後までコピーして終了
		}else{
			newExpr.append(expr,prv,pos-prv);
			break;
		}
	}
	return newExpr;
}
// -----------------------------------------------------------------------------
// d=で与えられたファイル名で項目名(${..})を検索し，
// 分割した文字列を返す、項目番号をセットする
// exp1. d=dat-${日付}  	返り値文字列:dat-,\0 項目番号:1 
// exp2. d=${日付}${時間}	返り値文字列:\0,\0,\0 項目番号:1,2
// -----------------------------------------------------------------------------
vector<kgstr_t> kglib::evalFileFldName(kgstr_t& expr, kgCSV& iFile,vector<int>& set,bool fldByNum)
{
  vector<kgstr_t> fnamevstr;
	kgstr_t::size_type prv=0;
  while(1){
    kgstr_t::size_type pos = expr.find("${",prv);
		// 項目名発見時の処理
    if(pos != kgstr_t::npos){
			fnamevstr.push_back(expr.substr(prv,pos-prv)); // "${"の直前までをセット
    	kgstr_t::size_type end = expr.find("}",pos); // }を探す
    	if(pos != kgstr_t::npos){                    // }を発見
				vector<kgstr_t> name; 
				kgstr_t fldName;                           //   項目名を切り出し
				fldName.append(expr,pos+2,end-pos-2);      //   委ねる．
				name.push_back(fldName);	
				vector<int> num = evalFldName(name, &iFile,fldByNum);
				set.push_back(num.at(0));										//項目番号をセット
				prv=end+1;                                 //     prvを更新して
				continue;                                  //     再び${検索に戻る
			}else{                                       // }が無ければエラー
	 	   	throw kgError("unmatched variable brackets {...}");
			}
		// 項目名がなければ最後までコピーして終了
		}else{
			fnamevstr.push_back(expr.substr(prv,pos-prv));
			break;
		}
	}
	return fnamevstr;
}



