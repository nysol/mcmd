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
// kgarff2csv.cpp : wekaのデータフォーマット→CSV変換
// ============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <kgarff2csv.h>
#include <kgError.h>
#include <kgMethod.h>
using namespace std;
using namespace kglib;
using namespace kgmod;

//static function
namespace {
	// arff formatからデータ抽出 
	// @attribute行の２項目目が項目名なのでその部分setする
	void arff2data(char* recdata,char* setdata)
	{
		bool s_demi=false,e_demi=false;
		char *p=recdata,*q=setdata;
		while(*p){
			if(*p==' '||*p=='\t'){
				p++;
				if(s_demi==false){
					s_demi=true;
					continue;
				}
				else{
					if(e_demi==false)	{ continue; }
					else							{ break; }
				}
			}
			if(s_demi==true){ e_demi=true;}
			if(s_demi==true&&e_demi==true){ *q++=*p; }
			p++;
		}
		*q='\0';
	}
	// 文字列の比較（小文字アルファベットに変換してから）
	bool sameStr(const char* rec, const char* str)
	{
		if(*rec=='\0' || *str=='\0'){ return false; }
		while(*rec!='\0' && *str!='\0'){
			if(tolower(*rec)!=tolower(*str)) return false;
			rec++;str++;
		}
		return true;
	}
}
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgArff2csv::kgArff2csv(void)
{
	_name    = "kgarff2csv";
	_version = "###VERSION###";

	#include <help/en/kgarff2csvHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgarff2csvHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgArff2csv::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=",kgArgs::COMMON|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	// (入力ファイルオープンヘッダ無パターンで読み込む)
	_iFile.open(_args.toString("i=",false), _env, true);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_iFile.read_header();
}

// -----------------------------------------------------------------------------
// 実行
// arffは@ATTRIBUTEが項目名行(上から順番にcsvの左から順番の項目になる)で、
// @DATA行以降がデータ(csv)になるので@DATA行以降csvとして出力していく(DQのチェックも行う)
// -----------------------------------------------------------------------------
int kgArff2csv::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	bool dataflg=false;
	int fldcnt=0;
	char** sepstr=0;
	kgAutoPtr2<char*> ap;
	vector<kgstr_t> outfld;
	char strtmp[KG_MaxRecLen];

	// arff -> csv変換処理
	while( EOF != _iFile.read() ){
		char* recstr =	_iFile.getRec();
		//コメント行はskip
		if(*recstr=='%'){continue; }
		if(dataflg){//データ行出力
			strcpy(strtmp,recstr);
			sepFldToken(sepstr,fldcnt,strtmp);
			if(_assertNullOUT){ 
				for(size_t i=0 ; i<fldcnt ; i++){
					if( *sepstr[i] =='\0' ){ _existNullOUT = true; break;}
				}
			}
			_oFile.writeFld(fldcnt,sepstr);
		}
		else{
			char *p =strtmp;
			if(sameStr(recstr,"@attribute")){
				arff2data(recstr,p);
				fldcnt++;
				outfld.push_back(p);
			}
			if(sameStr(recstr,"@data")){
				if( !_oFile.noFldName( ) ){
					_oFile.writeFldNameCHK(outfld);
				}
				dataflg=true;
				try {
					ap.set( new char*[fldcnt] );
				}catch(...){
					throw kgError("memory allocation error");
				}
				sepstr=ap.get();
			}
		}
	}
	// 終了処理
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

