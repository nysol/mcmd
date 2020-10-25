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
// kgfsort.h 項目ソートクラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <kgfsort.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


namespace kgfsort_local {//////////////////////////////////////////////////

	// 文字列昇順
	inline int cmpStrAsc(unsigned char* a, unsigned char* b)
	{
		while(true){
		       if(*a < *b) return  1;
			else if(*a > *b) return -1;
			if(*a=='\0') break; // *a==*b=='\0'
			a++;b++;
		}
		return 0;
	}
	// 文字列降順
	inline int cmpStrDec(unsigned char* a, unsigned char* b)
	{
		while(true){
		       if(*a < *b) return -1;
			else if(*a > *b) return  1;
			if(*a=='\0') break; // *a==*b=='\0'
			a++;b++;
		}
		return 0;
	}
	// 数値昇順
	inline int cmpNumAsc(char* a, char* b)
	{
		if(*a=='\0'){
			if(*b=='\0') return 0;
			else         return 1;
		}else{
			if(*b=='\0') return -1;
			double fa=atof(a);
			double fb=atof(b);
		       if(fa < fb) return  1;
			else if(fa > fb) return -1;
			else             return  0;
		}
		return 0;
	}
	// 数値降順
	inline int cmpNumDec(char* a, char* b)
	{
		if(*a=='\0'){
			if(*b=='\0') return 0;
			else         return -1;
		}else{
			if(*b=='\0') return 1;
			double fa=atof(a);
			double fb=atof(b);
		       if(fa < fb) return -1;
			else if(fa > fb) return  1;
			else             return  0;
		}
		return 0;
	}
	// 比較クラス
	struct itmComp 
	{
		int type;//0:文字ソート,1:数字ソート,2:文字逆ソート,3:数字逆ソート
		itmComp(void){type=0;}
		itmComp(int x){type = x;}

 		bool operator()(char* v1, char* v2) {
 			int retVal=0;
			switch( type ){
				case 0: // 文字昇順
				retVal=cmpStrAsc((unsigned char*)v1, (unsigned char*)v2);
				break;
			case 1: // 数字昇順
				retVal=cmpNumAsc(v1, v2);
				break;
			case 2: // 文字降順
				retVal=cmpStrDec((unsigned char*)v1, (unsigned char*)v2);
				break;
			case 3: // 数字降順
				retVal=cmpNumDec(v1, v2);
				break;
	 		}
	   	if( retVal>0 ){ return true;}
  	 	else       		{ return false;}
  	 	return false;
  	}

};

} //////////////////////////////////////////////////////////////////////////////
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgFsort::kgFsort(void)
{
	_name    = "kgfsort";
	_version = "###VERSION###";

	#include <help/en/kgfsortHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgfsortHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgFsort::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,f=,-n,-r",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);
	_fField.set(vvs, &_iFile, _fldByNum);

	// -r 逆順フラグ
	_reverse = _args.toBool("-r");

	// -n 数値ソートフラグ
	_numsort = _args.toBool("-n");

}
// -----------------------------------------------------------------------------
//  val : vector<kgVal>バージョン
// -----------------------------------------------------------------------------
void kgFsort::writeFld(char** fld, const vector<int>* flg, vector<char*>& val)
{	
	size_t i;
	int num;
	for(i=0; i<flg->size()-1; i++){ 
		num=flg->at(i);
		if(num == -1) { _oFile.writeStr( *(fld+i)   , false );}
		else          { _oFile.writeStr(val.at(num) , false );}
	}
		num=flg->at(i);
		if(num == -1) { _oFile.writeStr( *(fld+i)   , true );}
		else          { _oFile.writeStr(val.at(num) , true );}
}


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgFsort::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名出力
  _oFile.writeFldName(_fField, true);

	// ソート情報セット
	int flg=0;
	if(_numsort) { flg |= 1;}
	if(_reverse) { flg |= 2;}
	kgfsort_local::itmComp icomp(flg);
	

	while(EOF != _iFile.read() ){
		vector<char*> eachItem;
		for(size_t i=0; i<_fField.size(); i++){
			if(_assertNullIN && *_iFile.getVal(_fField.num(i))=='\0'){  _existNullIN  = true; }
			eachItem.push_back(_iFile.getVal(_fField.num(i)));
		}
		sort(eachItem.begin(),eachItem.end(),icomp);
		writeFld(_iFile.getFld(),_fField.getFlg_p(),eachItem);
	}

	// 終了処理(メッセージ出力,thread pipe終了通知)
	_iFile.close();
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
	kgError err("unknown error" );
	errorEnd(err);
	return 1;
}
