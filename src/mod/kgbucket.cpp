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
// =============================================================================
// kgbucket.cpp 件数均等化バケット分割クラス
// =============================================================================
#include <cstdio>
#include <map>
#include <kgbucket.h>
#include <kgCSVout.h>
#include <kgError.h>
#include <kgConfig.h>
#include <cfloat>

using namespace std;
using namespace kglib;
using namespace kgmod;

namespace ///////////////////////////////////// start static function space
{
	// 値-累計ペア
	struct sTbl{
		double val;
		int accum;
	};
	// レンジペア(from->to) 
	struct rTbl { 
 	 double from;
 	 double to;
	};
	// k-cluster table
	struct kTbl { 
	           double minVar;
		unsigned long prvNo;
		unsigned long from;
		unsigned long to;
	};
	// 分割点計算
	vector<rTbl> calcutpoint( map<double,int> &ctable,unsigned int cutCnt) 
	{
		// 値と出現数のテーブル(ctables)から値と出現数累積値のテーブル(stable)に
		vector<sTbl> stable;
		int sval=0;
		for(map<double,int>::iterator j=ctable.begin();j!=ctable.end();j++)	{	
			sTbl stbltmp;
			sval = j->second + sval;
			stbltmp.accum=sval;
			stbltmp.val=j->first;
			stable.push_back(stbltmp);
		}
		//	1から入力分割値までで、分割数ごとの分散最小値(実質的には二乗値を計算)
		//	値と出現数累積値のテーブル(stable)から分散値テーブル(ktables)
		vector< vector<kTbl> > ktables;
		ktables.resize(cutCnt);
		for(unsigned int i=0; i<cutCnt; i++){
			ktables.at(i).resize(ctable.size());
		}
		// 分割数１の場合の計算
		for(unsigned int j=0;j<stable.size();j++){
			ktables.at(0).at(j).minVar = (double)stable.at(j).accum * (double)stable.at(j).accum;
			ktables.at(0).at(j).prvNo  = 0;
			ktables.at(0).at(j).from   = 0;
			ktables.at(0).at(j).to     = j;
		}
		// 値の種類数よりもカット数(k=の値)が大きければcutCntを調整
		if(cutCnt>ctable.size()) cutCnt=ctable.size();
		// 分割数２以上の場合の計算(j=1で始まるのはk分割の1は配列の0に対応)
		// minMinVar tmpVarの不等式を>にすれば、同じ件数の場合に後を多くし
		//                         >=にすれば、同じ件数の場合に前を多くする
		for(unsigned int j=1; j<cutCnt; j++){
			unsigned int prvPrvNo=j-1;
			for(unsigned int k=j; k<ctable.size(); k++){
				double minMinVar=DBL_MAX;
				unsigned long   minPrvNo=0;
				unsigned long   minFrom=0;
				unsigned long   minTo=0;
				for(unsigned int l=prvPrvNo; l<k; l++){
					double tmpVar = ktables.at(j-1).at(l).minVar +
								(double)(stable.at(k).accum-stable.at(l).accum)*
								(double)(stable.at(k).accum-stable.at(l).accum);
					if( minMinVar > tmpVar ){
						minMinVar =tmpVar;
						minPrvNo  =l;
						minFrom   =l+1;
						minTo     =k;
					}
				}
				ktables.at(j).at(k).minVar = minMinVar;
				ktables.at(j).at(k).prvNo  = minPrvNo;
				ktables.at(j).at(k).from   = minFrom;
				ktables.at(j).at(k).to     = minTo;
				prvPrvNo=minPrvNo;
			}
		} 
		vector<rTbl> rtable(cutCnt);
		kTbl tmpKtbl=ktables.at(cutCnt-1).at(ctable.size()-1);
		for( int j=cutCnt-1; j>=0; j--){
			rtable.at(j).from=stable.at(tmpKtbl.from).val;
			rtable.at(j).to  =stable.at(tmpKtbl.to).val;
			if(j-1 >= 0 ){
				tmpKtbl=ktables.at(j-1).at(tmpKtbl.prvNo);
			}
		}
		//fromとtoの中点をカットポイントとしてセットする
		unsigned int s;
		if(cutCnt>1){
			rtable.at(0).to=(rtable.at(0).to+rtable.at(1).from)/2;
			for(s=1; s<cutCnt-1; s++){
				rtable.at(s).from=rtable.at(s-1).to;
				rtable.at(s).to  =(rtable.at(s).to+rtable.at(s+1).from)/2;
			}
			rtable.at(s).from=rtable.at(s-1).to;
		}
		return rtable;
	}
} ///////////////////////////////////// end static function space
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgBucket::kgBucket(void)
{
	_name    = "kgbucket";
	_version = "###VERSION###";

	#include <help/en/kgbucketHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgbucketHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgBucket::setArgs(void){
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,O=,n=,F=,-r,-rng,bufcount=,-q",kgArgs::ALLPARAM);
	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
  _oFile.setPrecision(_precision);
	kgstr_t rFile = _args.toString("O=",false);
	if(rFile.empty()){ _rangefile=false; }
	else {
		_rangefile=true;
		_rFile.open(rFile,_env,_nfn_o);
  	_rFile.setPrecision(_precision);
	}	
	//バッファサイズ変更
	kgstr_t s=_args.toString("bufcount=",false);
	int bcnt = 10;
	if(!s.empty()){ 
		bcnt = atoi(s.c_str());
		if(bcnt<=0){ bcnt=1;}
	}
	_iFile.setbufsize(bcnt);

	// 入力ファイルから項目名行を読み込む
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// n= 分割数のセット(2以上)
	vector<kgstr_t> vs_n =_args.toStringVector("n=",true);
	for(vector<kgstr_t>::size_type i=0; i<vs_n.size();i++){
		int cnt = atoi(vs_n.at(i).c_str());
		if(cnt < 2){ throw kgError("the number of buckets (n=) must be >=2"); }
		_bktSize.push_back(cnt);			
	}
	
	

	// F=出力タイプ(0 or 1 or 2)
	kgstr_t F_s = _args.toString("F=",false);
	if(F_s.empty())	{ _out_type=0;}
	else						{ _out_type = atoi(F_s.c_str());}
	if(_out_type>2 && _out_type<0){
		throw kgError("F= parameter must take 0,1 or 2");
	}
	
	//rngタイプバケット分割する
	_rng_flg = _args.toBool("-rng");

	//逆順でバケット番号をふる
	_reverse = _args.toBool("-r");
	
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg && !vs.empty()){ sortingRun(&_iFile,vs);}

	_kField.set(vs,  &_iFile, _fldByNum);
	_fField.set(vvs, &_iFile, _fldByNum);

	// n=パラメータに指定された値が一つであれば，全ての項目の分割数を
	// この値にする．
	if(_bktSize.size()==1){
		for(vector<kgstr_t>::size_type i=1; i<_fField.size(); i++){
			_bktSize.push_back(_bktSize.at(0));			
		}
	}
	// サイズチェック
	if( _fField.size() != _bktSize.size()){
		throw kgError("the number of arguments on f= and n= must be same");
	}

}
// -----------------------------------------------------------------------------
// 範囲ファイルの項目名の出力
// キー項目,fieldName,bucketNo,rangeFrom,rangeTo
// キー項目(なければ出力なし),対象項目名,バケット番号,開始範囲,終了範囲
// -----------------------------------------------------------------------------
void kgBucket::writeFldName_RangeF()
{
	if(_rFile.noFldName()){ return; }
	int size=_kField.size();
  if(size>0){
  	for(int i=0; i<size; i++){
			kgstr_t oName=_kField.name(i); 
			_rFile.writeStr( oName.c_str(), false);
		}
  }
	_rFile.writeStr("fieldName",false);
	_rFile.writeStr("bucketNo" ,false);
	_rFile.writeStr("rangeFrom",false);
	_rFile.writeStr("rangeTo"  );
	_rFile.writeEolNC();
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgBucket::run(void) try 
{
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
  _oFile.writeFldName(_iFile,_fField, true);
	if(_rangefile){ writeFldName_RangeF();}

	while(_iFile.blkset()!=EOF){
		//範囲セット領域
		vector< vector<rTbl> > rtables(_fField.size());
		if(_rng_flg){
			// 最小値と最大値を計算
			vector<double> mintables(_fField.numSize(), DBL_MAX);
			vector<double> maxtables(_fField.numSize(),-DBL_MAX);
			while(_iFile.blkread() != EOF){
				for(vector<kgstr_t>::size_type i=0; i<_fField.numSize(); i++){
					char* str=_iFile.getBlkVal(_fField.num(i));
					if(*str!='\0'){ // null値判定
          	double tmp_val=atof(str);
						if( maxtables.at(i) < tmp_val ) maxtables.at(i)=tmp_val;
						if( mintables.at(i) > tmp_val ) mintables.at(i)=tmp_val;
					}
				}
			}
			// 範囲のセット
			for(vector<kgstr_t>::size_type i=0; i<_fField.numSize(); i++){
				if(maxtables.at(i)==-DBL_MAX || mintables.at(i)== DBL_MAX){ continue; }
				if(maxtables.at(i)==mintables.at(i)){
					vector<rTbl> rtable(1);
					rtable.at(0).from	= maxtables.at(i);
					rtable.at(0).to		= mintables.at(i);
					rtables.at(i) = rtable;
				}else{
					vector<rTbl> rtable(_bktSize.at(i));
					double step = ( maxtables.at(i) - mintables.at(i) )/(double)(_bktSize.at(i));
					for(vector<kgstr_t>::size_type j=0 ;j<_bktSize.at(i);j++){
						rtable.at(j).from	= mintables.at(i)+ j*step;
						if(j==_bktSize.at(i)-1)	rtable.at(j).to		= maxtables.at(i);
						else 												rtable.at(j).to		= mintables.at(i)+(j+1)*step;
					}
					rtables.at(i) = rtable;
				}
			}
		}
		else{
			// 値と出現回数のmapテーブル作成
			vector< map<double,int> >ctables(_fField.size());
			while(_iFile.blkread() != EOF){
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					char* str=_iFile.getBlkVal(_fField.num(i));
					if(*str!='\0'){ // null値判定
						++((ctables.at(i))[atof(str)]);
					}
				}
			}
			//	値と出現数のテーブルからfieldごとに最適カットポイントを求める
			//	最終的にrtablesにfieldごとの最適なカットポイント(範囲)をセットする
			for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
				if(ctables.at(i).size()!=0){ // 一件もデータがない時は分割実行しない
					rtables.at(i)= calcutpoint( ctables.at(i),_bktSize.at(i));
				}
			}
		}
		// 範囲ファイルの出力
		if(_rangefile){
			for(vector<kgstr_t>::size_type h=0; h<_fField.size(); h++){
				if(rtables.at(h).size()==0) continue; // 一件もデータがない時は出力しない
				for(unsigned int j=0; j<rtables.at(h).size(); j++){
					for(unsigned int k=0; k<_kField.size(); k++){
						_rFile.writeStr(_iFile.getOldVal(_kField.num(k)),false);
					}
					_rFile.writeStr(_fField.name(h).c_str(),false);
					if(_reverse) _rFile.writeInt(rtables.at(h).size()-j,false);
					else         _rFile.writeInt(j+1                ,false);
					if(j==0){ // 最初のバケットのlowerは出力しない
						_rFile.writeStr("",false);
					}else{
						_rFile.writeDbl(rtables.at(h).at(j).from,false);
					}
					if(j==rtables.at(h).size()-1){ // 最後のバケットのupperは出力しない
						_rFile.writeStr("",true);
					}else{
						_rFile.writeDbl(rtables.at(h).at(j).to,true);
					}
				}
			}
		}
		// 出力処理
		_iFile.seekBlkTop();
		while(_iFile.blkread() != EOF){
			_oFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld(),false);
			vector<int> val(_fField.size());
			for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
				bool eol= ( i==_fField.size()-1 );
				char* str = _iFile.getBlkVal(_fField.num(i));
				if(*str=='\0'){
					if(_assertNullIN) { _existNullIN  = true;}
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeStr("", eol);
				}else{
					double checkval = atof( _iFile.getBlkVal(_fField.num(i)) );
					unsigned int bktNo;
					for(bktNo=0; bktNo<rtables.at(i).size()-1; bktNo++){
						if( checkval<rtables.at(i).at(bktNo).to ) break;
					}
					switch (_out_type){
					case 0:
						if(_reverse){ _oFile.writeInt(rtables.at(i).size()-bktNo,eol);}
						else        { _oFile.writeInt(bktNo+1                   ,eol);}
						break;
					case 1:
						if(bktNo!=0){ _oFile.writeDbl( rtables.at(i).at(bktNo).from );}
						_oFile.writeStr( "_" );
						if(bktNo!=rtables.at(i).size()-1){ _oFile.writeDbl( rtables.at(i).at(bktNo).to, eol );}
						else{	_oFile.writeStr("",eol);}
						break;
					default :
						if(_reverse){ _oFile.writeInt(rtables.at(i).size()-bktNo);}
						else        { _oFile.writeInt(bktNo+1                );}
						_oFile.writeStr( ":" );
						if(bktNo!=0){ _oFile.writeDbl( rtables.at(i).at(bktNo).from );}
						_oFile.writeStr( "_" );
						if(bktNo!=rtables.at(i).size()-1){ _oFile.writeDbl( rtables.at(i).at(bktNo).to, eol );}
						else{ _oFile.writeStr("",eol);}
						break;
					}
				}
			}
		}
	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }
	th_cancel();
	// 終了処理
	_iFile.close();
	_oFile.close();
	if(_rangefile){ _rFile.close();}
	successEnd();
	return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const exception& e) {
	kgError err(e.what());
	errorEnd(err);
	return 1;
}catch(char * er){
	kgError err(er);
	errorEnd(err);
	return 1;
}catch(...){
	kgError err("unknown error" );
	errorEnd(err);
	return 1;
}
