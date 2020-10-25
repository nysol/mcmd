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
// kgduprec.cpp 行の複製
// =============================================================================
#include <cstdio>
#include <kgtab2csv.h>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgTab2csv::kgTab2csv(void)
{
	_name    = "kgtab2csv";
	_version = "###VERSION###";

	#include <help/en/kgtab2csvHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgtab2csvHelp.h>
	#endif
	
}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgTab2csv::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,-r,d=",kgArgs::COMMON|kgArgs::IODIFF);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_iFile.read_header();

	// -r 出力反転フラグ
	_remove = _args.toBool("-r");

	kgstr_t s_d = _args.toString("d=",false);
	if(s_d.empty()){	
		_delim='\t';
	}else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= takes 1 byte charactor (" << s_d << ")";
		throw kgError(ss.str());
	}else{
		_delim=*(s_d.c_str());
	}

	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgTab2csv::run(void) try 
{
	char * data;
	size_t fcnt=0;

	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// headerがあるとき
	if(!_nfn_i){
		vector<string> head;
		if(EOF != _iFile.read()){
			char * data = _iFile.getRec();
			if (_remove){
				char *p = data;
				while( *p ){ p++;}
				if(p!=data && *(p-1)=='\r'){
					*(p-1)='\0';
				}
			}
			string hdata = data;
			head = splitToken(hdata,_delim);
			fcnt = head.size();
		}
		// headerを出力するとき
		if(!_nfn_o){ _oFile.writeFldName(head);}
	}
	// 行数を取得してデータ出力
	while( EOF != _iFile.read() ){
		data = _iFile.getRec();
		vector<char*> d_split = splitToken(data,_delim);
		if(fcnt==0){ fcnt = d_split.size();}
		if ( fcnt != d_split.size()){
			ostringstream ss;
			ss << "unmatch field size: ( " << fcnt << "," << d_split.size();
			throw kgError(ss.str());
		}
		if (_remove){
			char *p = d_split.back();
			while( *p ){ p++;}
			if(p!=d_split.back() && *(p-1)=='\r'){
				*(p-1)='\0';
			}
		}
		for(size_t i=0; i<fcnt; i++){
			_oFile.writeStr( d_split[i], i == fcnt-1);
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
