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
// mdata : datasetの出力
// ============================================================================
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <kgMethod.h>
#include <kgdata.h>
#include <sys/stat.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

/// 標準出力
static void output0(const char* data){
	cout << data;
	cout.flush();
}

// ファイル出力
static void output1(string fname,const char* data){
	ostringstream ss;
	ss << fname ;
	ofstream ofp( ss.str().c_str() );
	ofp << data;
	ofp.flush();
}

// ファイル出力
static void output2(const char* path, const char* fname, const char* data){
	ostringstream ss;
	ss << path << "/" << fname << ".csv";
	ofstream ofp( ss.str().c_str() );
	ofp << data;
	ofp.flush();
}

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgData::kgData(void)
{
	_name    = "kgData";
	_version = "###VERSION###";

	#include <help/en/kgdataHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgdataHelp.h>
	#endif
	_dic = false;
	
}

void kgData::output_dic(void){
	const char *dicname;
	if(_outinfo.empty()){
		dicname = _vals[0].c_str();
	}else{
		dicname = _outinfo.c_str();
	}
	::mkdir(dicname,0777);

	for(size_t i=0;dsample_[i][0]!='\0';i++){ 
		if(!strcmp(dsample_[i][0],_vals[0].c_str())){
			output2(dicname,dsample_[i][1],dsample_[i][2]);
		}
  }
}


void kgData::output_file(void){

	int found=0;
	for(size_t i=0;dsample_[i][0]!='\0';i++){ 
		if( _vals.size() == 1 ){
			if( !strcmp(dsample_[i][0],_vals[0].c_str()) ){
				if(_outinfo.empty()){
					output0(dsample_[i][2]);
				}else{
					output1(_outinfo,dsample_[i][2]);
				}
				found=1;
				break;
			}
		}
		else{
			if( !strcmp(dsample_[i][0],_vals[0].c_str()) &&
				  !strcmp(dsample_[i][1],_vals[1].c_str()) ){
				if(_outinfo.empty()){
					output0(dsample_[i][2]);
				}else{
					output1(_outinfo,dsample_[i][2]);
				}
				found=1;
				break;
			}
		}
	}
	if(found==0){
		ostringstream ss;	
		ss << "data name not found: `" << _val;
		throw kgError(ss.str());
	}
}


// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgData::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("O=,-man0,-man1,-iris,-yakiniku_jp,-yakiniku_en,-tutorial_jp,-tutorial_en",kgArgs::NOADD);
	
	// 出力ファイルオープン
	_outinfo = _args.toString("O=",false);

	int chenum =1;
	if(!_outinfo.empty()){
		chenum = 2;
	}
	if(_args.size()!=chenum){
		throw kgError("Parameter is only one");
	}
	// - cut
	_val = _args.begin()->first.substr(1);
	if(_val == "tutorial_jp" || _val == "tutorial_en"){ //ディレクトリ出力
		_dic = true;
	}
	_vals = splitToken(_val,'/');

}

// -----------------------------------------------------------------------------
// メンバー変数の初期化 argc,argv
// -----------------------------------------------------------------------------
void kgData::init(size_t argc, const char* argv[], kgEnv* env) try 
{

	_env=env;
	for(size_t i=1; i<argc; i++){
		if(strlen(argv[i])> KG_ARGLEN_MAX){
			ostringstream ss;
			ss << "too long argument is specified (" << KG_ARGLEN_MAX << ")";
			throw kgError(ss.str());
		}
		if(strchr(argv[i],'=')!=NULL){
			_args.add( argv[i] );
		}
		else if(*argv[i]!='-'){
			string aval = "-" + string(argv[i]);
			_args.add( aval );
		}
		else{
			_args.add( argv[i] );
		}
	}
	kgMod::init();
	kgMod::signalset();
	
}catch(kgError& err){
  errorEnd(err);
}


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgData::run(void) try 
{
	// パラメータセット＆出力ファイルオープン
	setArgs();
	if(_dic){
		output_dic();
	}
	else{
		output_file();
	}

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

/*

int main(int argc, const char *argv[]) try
{
	if(argc==1){
    cout << helpMsg_ << endl;
		exit(0);
	}
  for(int i=1; i<argc; i++){
    if(0==strcmp("--help",argv[i]) || 0==strcmp("-help",argv[i])){
      cout << helpMsg_ << endl;
	    exit(0);
    }
  }

	//第一引数のコピー
  //行単位領域確保
	kglib::kgAutoPtr2<char> ap1;
	try {
		ap1.set( new char[120] );
	} catch(...) {
		cerr << "#ERROR# mdata: memory allocation error" << endl;
	}
	char* argStr=ap1.get();

	const char* p=argv[1];
	      char* q=argStr;
	while(*p){
		*q=*p;
		q++; p++;
		if(p-argv[1]>100){
			cerr << "#ERROR# mdata: too long argument string (>100)" << endl;
			exit(-1);
		}
	}
	*q=*p;

	// 第一引数の"/"token分解
	vector<char*> args;
	setArgs(argStr,args);
	      if(strcmp(args[0],"iris")==0){
		iris(args);
	}else if(strcmp(args[0],"man0")==0){
		iris(args);
	}else if(strcmp(args[0],"man1")==0){
		iris(args);
	}else if(strcmp(args[0],"tutorial_jp")==0){
		tutorial(args);
	}else if(strcmp(args[0],"tutorial_en")==0){
		tutorial(args);
	}else{
		cerr << "#ERROR# mdata: dataset not found: `" << args[0] << "'" <<  endl;
		exit(-1);
	}

	cerr << "#END# mdata " << argv[1] << endl;

  return 0;

}catch(...){
  return 1;
}
*/
