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
// kgMessage.cpp メッセージ関係クラス
// =============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <kgMessage.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <fcntl.h>
#define LIMIT_OUT 100000
#define LIMIT_MSG "#ERROR# It exceeds processing limit of 10K records in free license.Please contact NYSOL (http://www.nysol.jp) about a commercial license."

using namespace std;
using namespace kglib;
using namespace boost::posix_time;

// -----------------------------------------------------------------------------
// 出力処理
// -----------------------------------------------------------------------------
void kgMsg::WriteMsg(string v ,string t)
{
		struct flock lock;
	  lock.l_type = F_WRLCK;
	  lock.l_whence = SEEK_SET;
	  lock.l_start = 0;
	  lock.l_len = 0;
		if( fcntl(2,F_SETLKW, &lock) >=0 ){
			cerr << v << "; " <<t << endl;
			lock.l_type = F_UNLCK;
			fcntl(2,F_SETLKW, &lock);
		}
		else{
			cerr << v << "; " <<t << endl;
		}
}
// -----------------------------------------------------------------------------
// 出力要否チェック
// -----------------------------------------------------------------------------
bool kgMsg::isOn(void){
	bool result=false;
	if(env_){
		int vl=env_->getVerboseLevel();
		switch(plevel_){
			case ERR: if(vl>=1) result=true; break;
			case WAR: if(vl>=2) result=true; break;
			case END: if(vl>=3) result=true; break;
			case MSG: if(vl>=4) result=true; break;
			case DEB: if(vl>=5) result=true; break;
 		}
	}
	return result;
}
// -----------------------------------------------------------------------------
// ヘッダ文字列取得
// -----------------------------------------------------------------------------
string kgMsg::header(void){
	ostringstream ss;
	switch(plevel_){
		case ERR: ss << "#ERROR#"  ; break;
		case WAR: ss << "#WARNING#"; break;
		case END: ss << "#END#"    ; break;
		case MSG: ss << "#MSG#"    ; break;
		case DEB: ss << "#DEBUG#"  ; break;
	}
	return ss.str();
}
// -----------------------------------------------------------------------------
// 時刻取得
// -----------------------------------------------------------------------------
string kgMsg::getTime(void){
	//time_t t;
	//struct tm *ltm;
	//time(&t);             
	//ltm = localtime(&t);  

	char buf[128];
	ostringstream ss;
	boost::posix_time::ptime _now = microsec_clock::local_time();
	
	if(env_->msgTimebyfsec()){
		sprintf(buf,"%04d/%02d/%02d ",
			static_cast<int>(_now.date().year()),
			static_cast<int>(_now.date().month()),
			static_cast<int>(_now.date().day())
		);
		ss << buf << to_simple_string(_now.time_of_day());
	
	}
	else{
		sprintf(buf,"%04d/%02d/%02d %02d:%02d:%02d",
			static_cast<int>(_now.date().year()),
			static_cast<int>(_now.date().month()),
			static_cast<int>(_now.date().day()),
			static_cast<int>(_now.time_of_day().hours()),
			static_cast<int>(_now.time_of_day().minutes()),
			static_cast<int>(_now.time_of_day().seconds())
		);
		ss << buf;
	}
	return ss.str();
}
// -----------------------------------------------------------------------------
// v + commentをメッセージ出力する
// -----------------------------------------------------------------------------
void kgMsg::output(const string& v, const string& comment)
{
	if(isOn()){
		ostringstream ss;
		ss << header() << " " << comment << "; " << v;
		WriteMsg(ss.str(),getTime());
	}
}
// -----------------------------------------------------------------------------
// vector v + commentをメッセージ出力する
// -----------------------------------------------------------------------------
void kgMsg::output(const vector<string>& vv, const string& comment)
{
	if(isOn()){
		ostringstream ss;
		ss << header() << " ";
		if( !comment.empty( ) ) {
			ss << comment << "; ";
		}
		for(size_t i=0; i<vv.size(); i++){
			ss << vv.at(i) << "; ";
		}
		WriteMsg(ss.str(),getTime());
	}
}
// -----------------------------------------------------------------------------
// コマンドライン 入出力行数 msg + commentをメッセージ出力する
// -----------------------------------------------------------------------------
void kgMsg::output(kgMod* kgmod, string msg, const string& comment)
{	
	//if(kgmod->oRecNo()>LIMIT_OUT){WriteMsg(LIMIT_MSG,getTime());}
	if(isOn()){
		ostringstream ss;
		ss << header() << " ";
		if( !comment.empty( ) ) {
			ss << comment << "; ";
		}
		if(!msg.empty()){
			ss << msg << "; ";
		}

		// コマンドライン,引数出力
		ss << kgmod->cmdline() << "; ";

		//行数出力
		if(kgmod->iRecNo()!=size_t(-1)) ss << "IN="  << kgmod->iRecNo();
		if(kgmod->oRecNo()!=size_t(-1)) ss << " OUT=" << kgmod->oRecNo();
		WriteMsg(ss.str(),getTime());
	}
}
// -----------------------------------------------------------------------------
// コマンドライン 入出力行数 vector msg + commentをメッセージ出力する
// -----------------------------------------------------------------------------
void kgMsg::output(kgMod* kgmod, vector<string> vv, const string& comment){
	
	//if(kgmod->oRecNo()>LIMIT_OUT){WriteMsg(LIMIT_MSG,getTime());}
	if(isOn()){
		ostringstream ss;
		ss << header() << " ";
		if( !comment.empty( ) ) {
			ss << comment << "; ";
		}
		for(size_t i=0; i<vv.size(); i++){
			ss << vv.at(i) << "; ";
		}
		// コマンドライン,引数出力
		ss << kgmod->cmdline() << "; ";

		//行数出力
		if(kgmod->iRecNo()!=size_t(-1)) ss << "IN="  << kgmod->iRecNo();
		if(kgmod->oRecNo()!=size_t(-1)) ss << " OUT=" << kgmod->oRecNo();
		WriteMsg(ss.str(),getTime());
	}
}
