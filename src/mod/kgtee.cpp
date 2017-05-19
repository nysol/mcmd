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
#include <kgtee.h>
#include <kgCSVout.h>
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

// =============================================================================
// 出力ファイルポインタ
// =============================================================================
// -----------------------------------------------------------------------------
// 各種変数を初期化する
// -----------------------------------------------------------------------------
void kgOFP::clear(void){
	type_ = 0;
	fd_ = 0;
	stdo_ = 0;
	opened_ = false;
	env_ = 0;
}

// -----------------------------------------------------------------------------
// kgOFPをクローズする
// -----------------------------------------------------------------------------
void kgOFP::close(void) throw(kgError) {
	if( !opened_ ) return;

	try {
		switch(type_){
		case 1: // #### ファイル
			//file_.close();
			::close(fd_);
			break;
		case 2: // #### 標準入力
			stdo_->flush();
			stdo_=0;
			break;
		}
		opened_=false;
	} catch(...) {
		ostringstream ss;
		ss << "file write close error: " << fname();
		throw kgError(ss.str());
	}
}

const char* kgOFP::fname(void){
	     if(type_==1) return fname_.c_str();
	else if(type_==2) return "STDOUT";
	else              return "";
}

// -----------------------------------------------------------------------------
// kgOFPをオープンする
// -----------------------------------------------------------------------------
void kgOFP::open(kgstr_t fn, size_t queSize, kgEnv* env) throw(kgError) {
	// 既にopenしていたらエラー
	if( opened_ ){
		ostringstream ss;
		ss << "the file is already opened: " << fname();
		throw kgError(ss.str());
	}
	// 各種メンバー変数のセット
	fname_ = fn;
	env_   = env;
	// ----------------------------------
	// ######## 標準出力
	// ----------------------------------
	if( fname_.empty() ){
		type_  = 2;
		stdo_=&cout;
	// ----------------------------------
	// ######## ファイル出力
	// ----------------------------------
	}else{
		type_  = 1;	
		try {
			fd_ = ::open(fname_.c_str(), O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, S_IRWXU);
			if(fd_ == -1 ){
				throw kgError("");
			}
		} catch(...) {
			ostringstream ss;
			ss << "file write open error: " << fname();
			throw kgError(ss.str());
		}
	}
	opened_= true;
};

// bufのsizeバイトをファイルに書き込む
// 返値: 書き込んだバイト数, eof,pipe broken時は0を返す
size_t kgOFP::write(char* buf, int size) throw(kgError) {
	if(! opened_){
		// シグナルトラップが起動していない場合、エラーとする
		if( !env_->sigactcheck( ) ) {	throw kgError("internal error: write file not opened"); }
	}
	try {
		int wsize=0;
		switch(type_){
		// ------------------------------------------
		// #### ファイル(blocking i/o)
		// ------------------------------------------
		case 1:
			wsize = ::write(fd_, buf, size );
			if( wsize<0 ){
				if(32==errno) { // pipe broken
					close();
					wsize=0;
				}else{
					ostringstream ss;
					ss << "file write error(" << strerror(errno) << "):" << fname_;
					throw kgError(ss.str());
				}
			}
			break;
		case 2: // #### 標準出力
  		stdo_->write(buf, size );
			if(! stdo_->good()) {
				if(32==errno) { // pipe broken
					close();
					wsize=0;
				}else{
					ostringstream ss;
					ss << "file write error(" << strerror(errno) << "):stdout";
					throw kgError(ss.str());
				}
			}
			wsize=size;
			break;
		}
		return wsize;
	}catch(kgError& err){
		if( env_->sigactcheck( ) )	{ return 0; }
		else 												{ throw err;}
	// 書き込みエラー 
	}catch(...){
		close();
		ostringstream ss;
		ss << "file write error2: " << fname();
		throw kgError(ss.str());
	}
}

// -----------------------------------------------------------------------------
// クローズ
// -----------------------------------------------------------------------------
void kgTeeIFP::close(void) throw(kgError) {
	if( !opened_ ) return;
	try {
		switch(type_){
		case 1: // #### ファイル
			file_.close();
			break;
		case 2: // #### 標準入力
			stdi_=0;
			break;
		}
		opened_=false;
	} catch(...) {
		ostringstream ss;
		ss << "file read close error: " << fname();
		throw kgError(ss.str());
	}
}

const char* kgTeeIFP::fname(void){
	     if(type_==1) return fname_.c_str();
	else if(type_==2) return "STDIN";
	else              return "";
}
// -----------------------------------------------------------------------------
// オープン
// -----------------------------------------------------------------------------
void kgTeeIFP::open(kgstr_t fn, kgEnv* env) throw(kgError) {
	env_   = env;
	// 既にopenしていたらエラー
	if( opened_ ){
		ostringstream ss;
		ss << "file is already opened: " << fname();
		throw kgError(ss.str());
	}
	// 各種メンバー変数のセット
	fname_ = fn;
	// ######## 標準入力
	if( fname_.empty() ){
		type_  = 2;	
		stdi_=&cin;
		stdi_->exceptions(ios_base::badbit);
	}else{
		type_  = 1;	
		//オープンエラー用にios::failbitをセット
		// basic_ifstream.open()関数はrdbuf()->open()を呼び出すが，
		// そこでnullポインタを返すとfailbitがonになる．
		// C++ライブラリクイックリファレンス p.187
		//file_.exceptions(ios::failbit);
		try {
			file_.open( fname_.c_str(), ios::binary | ios::in );
			if(!file_){
				ostringstream ss;
				ss << "file read open error: " << fname();
				throw kgError(ss.str());
			}
		} catch(...) {
			ostringstream ss;
			ss << "file read open error: " << fname();
			throw kgError(ss.str());
		}
		// badbitで例外を投げるように設定
		// failbitもonにするとeof読み込みも例外になってしまう
		//file_.exceptions(ios_base::badbit);
	}
	opened_= true;
}
// -----------------------------------------------------------------------------
// 読み込み
// -----------------------------------------------------------------------------
void kgTeeIFP::read(char* buf, int size) throw(kgError) {
	try {
		rsize_=0;
		switch(type_){
		  case 1: // #### ファイル
 			file_.read(buf, size);
			if(! file_.good() && ! file_.eof()) {
				if(32==errno) { // pipe broken
					close();
					//return -1;
				}
				throw kgError("");
			}
			rsize_=file_.gcount();
			if(file_.eof()){
				eof_=true;
			}
			break;
		case 2: // #### 標準入力
 			stdi_->read(buf, size);
			rsize_=stdi_->gcount();
			if(stdi_->eof()){	eof_=true;}
			break;
		}
	// 読み取りエラー 
	}catch(...){
		ostringstream ss;
		ss << "file read error: " << fname();
		throw kgError(ss.str());
	}
}


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgTee::kgTee(void){

	_name    = "kgtee";
	_version = "###VERSION###";
	incnt_=0;
	_oRecCnt=0;
	_ifin =false;

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
void kgTee::setArgs(void){
	// unknown parameter check
	_args.paramcheck("i=,o=,-nostdout");
	
	// 入力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env); 

	// o= 出力ファイル名のセット
	_ofNames = _args.toStringVector("o=",false);

	// -nostdout 標準出力に出力しないフラグ
	_nostdout = _args.toBool("-nostdout");

 
	// 出力ファイルオープン 
	size_=_ofNames.size(); 
	ap_.set( new kgOFP[size_+1] ); // +1はstdout用 
	csvOut_=ap_.get(); 

	int i;
	for(i=0; i<size_; i++){
		csvOut_[i].open( _ofNames.at(i),2048*4 ,_env); // o=のファイルopen			
	}
	
	// 標準出力オープン
	if(!_nostdout){
		csvOut_[i].open( "",2048*4, _env ); // 標準出力open
		size_++;
	}

	if(_nostdout && _ofNames.empty()){
		throw kgError("-nostdout must be specified with o=.");
	}
}

////////////////////////////////////////////////
void kgTee::tee_write(kgstr_t  ifname,int no){
	ifstream   inp_file;
	size_t ocnt=0;
	kgAutoPtr2<char> buf_ap_;
	char* buf;
	buf_ap_.set( new char[KG_MaxRecLen] );
	buf = buf_ap_.get();
	inp_file.open(ifname.c_str());
	while(1){
		if(_ifin && inp_file.eof()){ break; }
		//if(ocnt<incnt_){ ////futere work
		inp_file.read(buf, KG_MaxRecLen);
//			if(! inp_file.good() && inp_file.eof()) {
//				break; 
//			}
		if(inp_file.gcount()==0){ continue;}
		csvOut_[no].write(buf, inp_file.gcount());
		ocnt++; ////futere work
		//}
	}
	inp_file.close();
	csvOut_[no].close();
}

void kgTee::tee_read(){
	kgAutoPtr2<char> buf_ap_;
	char* buf;
	buf_ap_.set( new char[KG_MaxRecLen] );
	buf = buf_ap_.get();
	//いきなりEOFはなにもせずに終了
	while(!_iFile.eof()){
		_iFile.read(buf, KG_MaxRecLen);
		otmpfile_.write(buf, _iFile.gcount());
		otmpfile_.flush();
		incnt_++; //futere work
	}

	otmpfile_.close();
	_ifin = true;
}

void* kgTee::tee_writeTH(void *arg){
	teeR_ST * dt = ((teeR_ST*)arg);
	dt->mobj->tee_write(dt->otmpname,dt->i);
	return NULL;
}
void* kgTee::tee_readTH(void *arg){
	((kgTee*)arg)->tee_read();
	return NULL;
}


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgTee::run(void) try {

	setArgs();

	// 一時ファイル
	kgTempfile tempFile(_env);

	// 入力ファイルをtempファイルに保存
	kgstr_t otmpname = tempFile.create();
	otmpfile_.open(otmpname.c_str() , ios_base::out | ios_base::trunc );
	
	// データ出力
	//_oRecCnt=0;

	//書き込み
	//threadで書き込み
	{
		// thread データ構造作成
		kgAutoPtr2<teeR_ST> aps;
		kgAutoPtr2<pthread_t> aps_pth;
		try {
			aps.set    ( new teeR_ST[size_] );
			aps_pth.set( new pthread_t[size_+1] );
		} catch(...) {
			throw kgError("memory allocation error");
		}
		teeR_ST* data      = aps.get();
		pthread_t* th_st_p = aps_pth.get();

		if( pthread_create( &th_st_p[0], NULL, kgTee::tee_readTH ,this ) ){
			throw kgError("can't create read_thread");
		}
		int rtn = pthread_join(th_st_p[0],NULL);
		if(rtn!=0) { cerr << "waring  fail thread join : " << rtn << endl; }

		for(int i=0; i<size_; i++){
			data[i].otmpname = otmpname;
			data[i].i = i;
			data[i].mobj = this;
			if ( pthread_create( &th_st_p[i+1], NULL, kgTee::tee_writeTH ,(void *)&data[i]) ){
			 	throw kgError("can't create write_thread");
			}
		}
		for(int i=1; i<size_+1; i++){
			int rtn = pthread_join(th_st_p[i],NULL);
			if(rtn!=0) { cerr << "waring  fail thread join : " << rtn << endl; }
		}
	}
		
	// 全ファイルクローズ

	// 終了処理(メッセージ出力,thread pipe終了通知)
	successEnd();
	return 0;

// 例外catcher
}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const std::exception& e) {
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
