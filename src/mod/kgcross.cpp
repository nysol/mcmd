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
// kgcross.cpp クロス集計クラス
// =============================================================================
#include <cstdio>
#include <iostream>
#include <sstream>
#include <kgcross.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgTempfile.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


namespace /////////////////////////////////////////////////////
{
class strsort{
	public:
		bool operator()(string t1,string t2) const {
			return strcmp(t1.c_str(),t2.c_str()) < 0 ;			
		}
};

class numsort{
	public:
		bool operator()(string t1,string t2) const {
			double a1 =atof(t1.c_str());
			double a2 =atof(t2.c_str());
			if (a1==a2){
				return strcmp(t1.c_str(),t2.c_str()) < 0 ;			
			}
			else{
				return a1 < a2 ;
			}
		}
};
}/////////////////////////////////////////////////////
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgCross::kgCross(void)
{
	_name    = "kgcross";
	_version = "###VERSION###";

	#include <help/en/kgcrossHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcrossHelp.h>
	#endif

}
//===============================================================================
// 項目名=>出力位置リスト生成&項目名出力
//   入力データを全行読込み、s=項目の内容で項目名=>出力位置リストを生成する
//   さらに項目名出力をする。
//	 ここで読み込まれたデータは一時ファイルに出力され次の処理で使用される
//================================================================================
void kgCross::setFldName(string tName)
{
	set<string, strsort> newfld;
	set<string, numsort> newfld_n;
	vector<kgstr_t> outFldName;

	//ここは元ファイルのnfnタイプで出力する
	kgCSVout toFile;
	toFile.open(tName, _env, _nfn_i);
	toFile.writeFldName(_iFile);

	// 展開項目名一覧生成＆読み込んだデータを一時ファイルに複製する
	// (後の処理は一時ファイルを元に行う。<=データがパイプ等のため)
	// s=項目名に%nが指定されている場合は、展開する項目名は数値として扱う
	while( EOF != _iFile.read() ){
		toFile.writeFld(_iFile.fldSize(),_iFile.getFld());
		char *ck_str = _iFile.getVal(_sField.num(0));
		if(*ck_str=='\0') continue;
		if( newfld.find(ck_str) == newfld.end() ){
			if(_numsort){ newfld_n.insert(ck_str);}
			else				{	newfld.insert(ck_str);}
		}
	}
	// 出力項目セット(無変更部分)
	if(!_nfn_o){
		for(size_t i=0; i<_kField.size(); i++){
			outFldName.push_back(_iFile.fldName(_kField.num(i),true));
		}
		outFldName.push_back(_a_str);
	}
	_iFile.close();
	toFile.close();


	// 展開項目名-出力位置番号mapの生成＆出力項目セット
	int no=0;
	if(_numsort){
		if(_reverse){  //数字ソート逆順
			for(set<string,numsort>::reverse_iterator j=newfld_n.rbegin(); j!=newfld_n.rend(); j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}else{				 //数字ソート
			for(set<string,numsort>::iterator          j=newfld_n.begin();  j!=newfld_n.end();  j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}
	}else{
		if(_reverse){	 //文字ソート逆順
			for(set<string,strsort>::reverse_iterator j=newfld.rbegin(); j!=newfld.rend(); j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}else{				 //文字ソート
			for(set<string,strsort>::iterator          j=newfld.begin();  j!=newfld.end();  j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}
	}
	//	項目名出力
	if(!_nfn_o){ _oFile.writeFldNameCHK(outFldName); }


}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgCross::setArgs(void)
{

	// パラメータチェック
	_args.paramcheck("f=,s=,i=,o=,k=,a=,v=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);

	// s= 項目引数のセット	
	vector< vector<kgstr_t> >  vvs_s = _args.toStringVecVec("s=","%:",2,true);

	// a= 項目引数のセット
	_a_str = _args.toString("a=",false);
	if(_a_str.size()==0){ _a_str = "fld";}

	// v= null値変換文字列セット
	_v_str = _args.toString("v=",false);
	if(_v_str.size()==0) { _n_flg=false; }
	else								 { _n_flg=true;	 }
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg&&!vs.empty()){ sortingRun(&_iFile,vs);}

	_kField.set(vs, &_iFile, _fldByNum);
	_fField.set(vvs, &_iFile, _fldByNum);
	_sField.set(vvs_s, &_iFile, _fldByNum);

	if(_sField.size()!=1){
		throw kgError("s= takes just one field name.");
	}
	//比較タイプセット(nがあるとtrueをセット(数字ソートになる)r)
	_reverse = _sField.attr(0).find("r") != kgstr_t::npos ;
	_numsort = _sField.attr(0).find("n") != kgstr_t::npos ;

}

int kgCross::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// データ複製、項目名=>出力位置リスト生成、項目名出力
	kgTempfile tempFile(_env);
	string tName = tempFile.create();
	setFldName(tName);

	// データファイルオープン
	kgCSVkey tiFile;
	tiFile.open(tName, _env, _nfn_i);
	tiFile.read_header();
	tiFile.setKey(_kField.getNum());

	
	size_t outValCount=_newFldMap.size()*_fField.size();
	vector<string> fldVals(outValCount);

	while( EOF != tiFile.read() ){
		if( tiFile.keybreak() ){
			// keybreak時にデータを出力する
			for(size_t fldNo=0; fldNo<_fField.size(); fldNo++){
				for(size_t i=0; i<_kField.size(); i++){
					_oFile.writeStr( tiFile.getOldVal( _kField.num(i) ), false);
				}
				_oFile.writeStr( _fField.name(fldNo).c_str(),false);
				for(size_t sno=0; sno<_newFldMap.size(); sno++){
					size_t no = sno * _fField.size() +fldNo;
					string o_str;
					if (!strcmp(fldVals.at(no).c_str(),"")){
						if( _n_flg ){ o_str = _v_str; }
						else{
							o_str = fldVals.at(no);
							if(_assertNullOUT){ _existNullOUT = true;}
						}
					}else{
						o_str = fldVals.at(no);
					}
					if(sno==_newFldMap.size()-1) _oFile.writeStr( o_str.c_str(), true );
					else                         _oFile.writeStr( o_str.c_str(), false);
				}
			}
			fldVals.clear();
			fldVals.resize(outValCount);
		}

		char *ck_str = tiFile.getNewVal(_sField.num(0));
		if(*ck_str == '\0') continue;
		int sno = _newFldMap[ck_str];
		for(size_t fldNo=0; fldNo<_fField.size(); fldNo++){
			size_t no = sno * _fField.size() +fldNo;
			fldVals.at(no) = tiFile.getNewVal(_fField.num(fldNo));
			if(_assertNullIN && fldVals.at(no).size()==0) { _existNullIN  = true;}

		}
	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = tiFile.keynull(); }
	// 終了処理
	th_cancel();
	tiFile.close();
	_oFile.close();
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
	kgError err("unknown error");
	errorEnd(err);
	return 1;
}
