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
#include <sys/stat.h>
#include <kgArgs.h>
#include <kgError.h>
#include <kgItermios.h>
#include <kgdsp.h>
using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgDsp::kgDsp(void)
{
	_name    = "kgdsp";
	_version = "###VERSION###";

	#include <help/en/kgdspHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgdspHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgDsp::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("x=,y=,str=,i=");
	_x_val =  atoi(_args.toString("x=",true).c_str());
	_y_val =  atoi(_args.toString("y=",true).c_str());
	_str_s =  _args.toString("str=",false);
	_i_s   =  _args.toString("i=",false);
	if(_str_s.size()==0&&_i_s.size()==0){
		throw kgError("necessary i= or str=");
	}
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgDsp::run(void) try
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	char *msg;
	struct stat st;
	kgAutoPtr2<char> ap; 

	if(_i_s.size()){
		
		if(stat(_i_s.c_str(),&st)!=0){
			throw kgError("file not found");
		}
		try {
			ap.set( new char[st.st_size+1] );
		} catch(...) {
			throw kgError("memory allocation error on kgdsp");
		}
		msg = ap.get();
		FILE *fp = fopen(_i_s.c_str(),"r");
		fread(msg, sizeof(char), st.st_size, fp);
		msg[st.st_size] = '\0';
		fclose(fp);
	}
	else{
		try {
			ap.set( new char[strlen(_str_s.c_str())+1] );
		} catch(...) {
			throw kgError("memory allocation error on kgdsp");
		}
		msg = ap.get();
		strcpy(msg,_str_s.c_str());
		msg[strlen(_str_s.c_str())] = '\0';

	} 
	kgTermiosEX scrn;
	int cnt=0;
	char *p=msg;
	char *q=msg;
	for(;*q!='\0';q++){
		if(*q=='\n'){
			*q='\0';
			scrn.move(_x_val,_y_val+cnt);
			scrn.output(p);
			cnt++;
			p=q+1;
		}
	}
	if(q!=p){
		scrn.move(_x_val,_y_val+cnt);
		scrn.output(p);
	}

	return 0;

}
catch(kgError& err){
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
