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
#include <mdata.h>
#include <sys/stat.h>

using namespace std;

/// 標準出力
void output0(const char* data){
	cout << data;
	cout.flush();
}

// ファイル出力
void output1(string fname,const char* data){
	ostringstream ss;
	ss << fname << ".csv";
	ofstream ofp( ss.str().c_str() );
	ofp << data;
	ofp.flush();
}

// ファイル出力
void output2(const char* path, const char* fname, const char* data){
	ostringstream ss;
	ss << path << "/" << fname << ".csv";

	ofstream ofp( ss.str().c_str() );
	ofp << data;
	ofp.flush();
}

// 文字列strの"/"によるtoken分解
void setArgs(char* str, vector<char*>& args){
//printf("setArgs\n");
	char* p=str;
	args.push_back(p);
	while(*p){
		if(*p=='/'){
			*p = '\0';
			args.push_back(p+1);
		}
		p++;
	}
}

// ################################################
// tutorialデータの出力
void tutorial(vector<char*>& args){

	// １ファイル標準出力
	if(args.size()>1){
		int found=0;
		for(size_t i=0;dsample_[i][0]!='\0';i++){ 
			if(strcmp(dsample_[i][0],args[0])==0){
				if(strcmp(dsample_[i][1],args[1])==0){
					output0(dsample_[i][2]);
					found=1;
					break;
				}
			}
		}
		if(found==0){
			cerr << "#ERROR# mdata: data name not found: `" << args[1] << "' in " << args[0] << " dataset." << endl;
		}

	// 全ファイル、ファイル出力
	}else{
		::mkdir(args[0],0777);

		for(size_t i=0;dsample_[i][0]!='\0';i++){ 
			if(strcmp(dsample_[i][0],args[0])==0){
				output2(dsample_[i][0],dsample_[i][1],dsample_[i][2]);
			}
  	}
	}
}

void iris(vector<char*>& args){
	// １ファイル標準出力
	int found=0;
	for(size_t i=0;dsample_[i][0]!='\0';i++){ 
		if(strcmp(dsample_[i][0],args[0])==0){
			output0(dsample_[i][2]);
			found=1;
			break;
		}
	}
	if(found==0){
		cerr << "#ERROR# mdata: data name not found: `" << args[1] << "' in " << args[0] << " dataset." << endl;
	}
}


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
/*
exit(0);
  multimap<string,const char*> imap;
	for(size_t i=0;grpidx_[i][0]!='\0';i++){ 
		imap.insert( pair<string,const char*>(grpidx_[i][0],grpidx_[i][1]) );
	} 
  map<string,const char*> smap;
	for(size_t i=0;dsample_[i][0]!='\0';i++){ 
  	smap[dsample_[i][0]] = dsample_[i][1];
  } 
	// グループ検索
	pair <multimap<string,const char*>::iterator, multimap<string,const char*>::iterator> ret;	
	ret = imap.equal_range(argv[1]);
  if (ret.first != ret.second ){
		for(multimap<string,const char*>::iterator it = ret.first ; it != ret.second ;it++ ){
			map<string,const char*>::iterator rls = smap.find(it->second);
	  	if (rls!=smap.end()){
	  		;//::output1(it->second,rls->second);
	  	}
		}
  }
  else{
		map<string,const char*>::iterator rls = smap.find(argv[1]);
  	if (rls!=smap.end()){
			cout << rls->second;  	
			cout.flush();
  	}
  	else{
	  	cerr << "data not found " << endl;
		}
	}
*/
  return 0;

}catch(...){
  return 1;
}
