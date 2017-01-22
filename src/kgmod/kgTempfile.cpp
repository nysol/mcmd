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
// kgTempfile.cpp : 一時ファイルクラス
// ============================================================================
#include <sstream>
#include <cerrno>
#include <kgMethod.h>
#include <kgError.h>
#include <kgConfig.h>
#include <kgTempfile.h>
#include <fcntl.h>
#include <kgWildcard.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <boost/filesystem.hpp>

using namespace std;
using namespace kglib;
using namespace boost;

// -----------------------------------------------------------------------------
// 一時ファイル(パイプor実ファイル)を作成し、そのファイル名を返す
// 一時ファイル名の命名規則 : tmpPath/__KGTMP_pid_乱数文字10文字
// 今のところはパイプは使われない？
// -----------------------------------------------------------------------------
string kgTempfile::create(bool pipe, string prefix)
{
	if(env_==0){ throw kgError("internal error: initialize kgTempfile");}

	string ret;
	int tryCnt=0;
	if(pipe){
		for(; tryCnt<10; tryCnt++){ // あり得ないが、ファイル名が重複する場合を考慮し10回tryする。
 			ostringstream ss;
			ss << env_->getTmpPath() << "/__KGTMP_" << getpid() << "_" << prefix << "_" << env_->randStr(14);
			int fd = mkfifo(ss.str().c_str(),0600);
      if(fd==-1 && errno!=EINVAL)	{ continue;}
      else												{ ret=ss.str(); break;}
		}
	}else{
		// 0バイトファイルを一時的に作成する(排他制御のため)
		for(; tryCnt<10; tryCnt++){
 			ostringstream ss;
			ss << env_->getTmpPath() << "/__KGTMP_" << getpid() << "_" << prefix << "_" << env_->randStr(14);
			int fd = open(ss.str().c_str(),O_CREAT | O_EXCL, S_IRWXU);
			if(fd==-1){ continue;}
			else			{	close(fd); ret=ss.str(); break;}
		}
	}
	if(tryCnt>=10){ throw kgError("internal error: cannot create temp file"); }
	// ファイル名を配列に登録しておく(削除のため)
	names_.push_back(ret);

	// ファイル名を返す。
	return ret;
}

bool kgTempfile::empty(void)
{
	if( names_.empty() ) return true;
	else                 return false;
}
void kgTempfile::remove_all(void){
  vector<string>::const_iterator i;
  for(i=names_.begin(); i!=names_.end(); i++){
		filesystem::path file = filesystem::path(i->c_str());
		filesystem::remove(file);
	}
}
// 登録された全ての一時ファイルを削除する
kgTempfile::~kgTempfile(void)
{
	if(env_==0){ return;}
  vector<string>::const_iterator i;
  for(i=names_.begin(); i!=names_.end(); i++){
		filesystem::path file = filesystem::path(i->c_str());
		filesystem::remove(file);
	}
}

// 強制削除 __KGTMP_pid を強制削除
void kgTempfile::interrupt_clean(kgstr_t path){
 	ostringstream ss;
	ss << path << "/__KGTMP_" << getpid() << "*";
	vector<kgstr_t> fn(1,ss.str());
	vector<kgstr_t> fnL = kgFilesearch(fn);
  vector<kgstr_t>::const_iterator i;
  for(i=fnL.begin(); i!=fnL.end(); i++){
		filesystem::path file = filesystem::path(i->c_str());
		filesystem::remove(file);
	}
}

