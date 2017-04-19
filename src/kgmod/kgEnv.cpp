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
// kgEnv.cpp 環境変数設定
// ============================================================================
#include <kgError.h>
#include <kgEnv.h>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace kglib;
using namespace boost;

// -----------------------------------------------------------------------------
// コンストラクタ
// -----------------------------------------------------------------------------
kgEnv::kgEnv(void) 
{
	int   envVal;
	char *envStr;

	// readサイズ
	envStr=getenv("KG_iSize");
	if(envStr!=NULL){
		envVal=atoi(envStr);
		if(envVal>KG_iSize) iSize_=KG_iSize;
		else                iSize_=envVal;
	}else{
		iSize_=KG_iSize;
	}
  if( iSize_ <= 0 ) {
    throw kgError("internal error: invalid read size");
  }   
  //writeサイズ
	envStr=getenv("KG_oSize");
	if(envStr!=NULL){
		envVal=atoi(envStr);
		if(envVal>KG_oSize) oSize_=KG_oSize;
		else                oSize_=envVal;
	}else{
		oSize_=KG_oSize;
	}
  if( oSize_ <= 0 ) {
    throw kgError("internal error: invalid write size");
  }   

	// 最大レコード長
	envStr=getenv("KG_MaxRecLen");
	if(envStr!=NULL){
		envVal=atoi(envStr);
		if(envVal>KG_LimitRecLen) maxRecLen=KG_LimitRecLen;
		else                      maxRecLen=envVal;
	}else{
		maxRecLen=KG_MaxRecLen;
	}

	// キー単位での読込時、ブロック数
	//（ここで設定した個数分*単位メモリ、メモリに読み込む最大量）
	envStr=getenv("KG_BlockCount");
	if(envStr!=NULL){
		blockCount_ = atoi(envStr);
	}else{
		blockCount_ = KG_BlockCount;
	}

	// メッセージの出力レベル(kgEnd,kgErrorのstderr出力利用時のみ影響)
	verboseLevel=KG_VerboseLevel;
	envStr=getenv("KG_VerboseLevel");
	if(envStr!=NULL){
		     if(*envStr=='0') verboseLevel=0; // メッセージを一切出力しない
		else if(*envStr=='1') verboseLevel=1; //  + errorメッセージ出力
		else if(*envStr=='2') verboseLevel=2; //  + warningメッセージ出力
		else if(*envStr=='3') verboseLevel=3; //  + endメッセージ出力
		else if(*envStr=='4') verboseLevel=4; //  + msgメッセージ出力
		else if(*envStr=='5') verboseLevel=5; //  + debugメッセージ出力
	}

	envStr=getenv("KG_msgTimebyfsec");
	if( envStr != NULL ){
		if(!strcmp(envStr,"true")){ msgTimebyfsec_ = true;}
		else{ msgTimebyfsec_ = KG_msgTimebyfsec;}
	}else{
		msgTimebyfsec_ = KG_msgTimebyfsec;
	}


	// 作業ディレクトリ
	envStr=getenv("KG_TmpPath");
	if( envStr != NULL ){
		tmpPath=envStr;
	}else{
		tmpPath=KG_TmpPath;
	}

	// LANG環境変数の値を取得する（設定されていなければフォルトは"C")
	envStr=getenv("LANG");
	if( envStr != NULL ){
		encoding=envStr;
	}else{
		encoding="C";
	}

	// 1行目を項目名と見なさないフラグ
	envStr=getenv("KG_NoFldName");
	if( envStr != NULL ){
		noFldName=true;
	}else{
		noFldName=false;
	}

	// DOUBLEの有効桁数
	envStr=getenv("KG_Precision");
	if(envStr!=NULL){
		envVal=atoi(envStr);
	       if(envVal>KG_MAX_PRECISION) _precision=KG_MAX_PRECISION;
	  else if(envVal<1               ) _precision=1;
		else                             _precision=envVal;
	}else{
		_precision=KG_PRECISION;
	}

	// 項目番号で指定
	envStr=getenv("KG_FldByNum");
	if( envStr != NULL ){
		_fldByNum=true;
	}else{
		_fldByNum=false;
	}

	// tpipeで呼び出されるkgmodのメッセージを出力するかどうか
	recursiveMsg_=KG_RecursiveMsg;
	envStr=getenv("KG_RecursiveMsg");
	if( envStr != NULL ){
		recursiveMsg_=true;
	}

	// シグナルトラップ起動なし
	sigact_=false;

	// 乱数初期化
  unsigned long seed= static_cast<unsigned long>(boost::posix_time::microsec_clock::local_time().time_of_day().fractional_seconds());
	try {
		randStrAP_.set( new variate_generator< mt19937,uniform_int<> >(mt19937(seed),uniform_int<>(48,109) ) );
	}catch(...){
		throw kgError("memory allocation error in kgEnv");
	}
}
// -----------------------------------------------------------------------------
// 有効桁数の設定
// -----------------------------------------------------------------------------
void kgEnv::precision(int p){
	     if(p>KG_MAX_PRECISION) _precision=KG_MAX_PRECISION;
	else if(p<0               ) _precision=0;
	else                        _precision=p;
}
// -----------------------------------------------------------------------------
// 乱数文字作成（size桁文字列を作成）
// -----------------------------------------------------------------------------
string kgEnv::randStr(size_t size){
	string s;
	for(size_t i=0; i<size; i++){
		char c=static_cast<char>((*randStrAP_.get())());
		     if(c>=84) c+=13;
		else if(c>=58) c+= 7;
		s.push_back(c);
	}
	return s;
}

