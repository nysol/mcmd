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
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <csignal>
#include <sys/stat.h>
#include <kg2tee.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgMessage.h>
#include <kgArgs.h>
#include <kgConfig.h>
#include <kgTempfile.h>
#include <pthread.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kg2Tee::kg2Tee(void){

	_name    = "kg2tee";
	_version = "###VERSION###";
	#include <help/en/kgteeHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgteeHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kg2Tee::setArgs(void){
	// unknown parameter check
	_args.paramcheck("i=,o=");
	
	// 入出力ファイル名の取得
	_iName = _args.toString("i=",false);
	_oName = _args.toStringVector("o=",true);

	if(_iName.empty()){
		_iFD=0;
	}else{
		_iFD = ::open(_iName.c_str(), O_RDONLY);
		if(_iFD == -1 ){
			ostringstream ss;
			ss << "file read open error: " << _iName;
			throw kgError(ss.str());
		}
	}
	for(size_t i=0;i<_oName.size();i++){
		int ofd = ::open(_oName[i].c_str(), O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, S_IRWXU);
		if( ofd == -1 ){
			ostringstream ss;
			ss << "file write open error: " << _oName[i];
			throw kgError(ss.str());
		}
		_oFD.push_back(ofd);
		_endFlg.push_back(false);
	}

}

// -----------------------------------------------------------------------------
// runMain
// -----------------------------------------------------------------------------
int kg2Tee::runMain()
{

	// que全体のbufferを確保
	_buf_ap.set( new char[KG_iSize] );
	_buf = _buf_ap.get();
	
	while(1){
		int rsize = ::read(_iFD, _buf, KG_iSize);
		if( rsize < 0 ){
			throw kgError();
		}
		if( rsize == 0 ) break;
		for(size_t i=0 ; i<_oFD.size();i++){
			if(_endFlg[i]){continue;}
			int wsize = ::write(_oFD[i], _buf , rsize);
			if( wsize<0 ){
				if(32==errno){ // pipe broken
					_endFlg[i]=true;
				}else{
					ostringstream ss;
					ss << "file write error";
					throw kgError(ss.str());
				}
			}
		}
	}
	
	::close(_iFD);
	for(size_t i=0 ; i<_oFD.size();i++){
		if(!_endFlg[i]){
			::close(_oFD[i]);
		}
	}

	return 0;

// 例外catcher
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kg2Tee::run(void) 
{
	try {

		setArgs();
		int sts = runMain();
		successEnd();
		return sts;

	}catch(kgError& err){
		runErrEnd();
		errorEnd(err);
	}catch (const exception& e) {
		runErrEnd();
		kgError err(e.what());
		errorEnd(err);
	}catch(char * er){
		runErrEnd();
		kgError err(er);
		errorEnd(err);
	}catch(...){
		runErrEnd();
		kgError err("unknown error" );
		errorEnd(err);
	}
	return 1;
}





