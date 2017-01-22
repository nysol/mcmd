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
// kgFldBuffer.cpp 項目データバッファクラス
// ============================================================================
#include <cstdio>
#include <sstream>
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <kgFldBuffer.h>
#include <kgError.h>

using namespace std;
using namespace kglib;

namespace kglib 
{
// -----------------------------------------------------------------------------
//  バッファへの書き込み
//    書き込みページが最大ページに達するとファイル出力に切り替わる
// -----------------------------------------------------------------------------
void kgFldBuffer::write(char * start,size_t size)
{
	if(w_page_==max_page_){
		string tmpname = tempFile_.create();
		flist_.push_back(tmpname);
		try {
			int fd = ::open(tmpname.c_str(), O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, S_IRWXU);
			if(fd == -1 ){ throw kgError("");}
			int wsize = ::write(fd, start, size);
			if( wsize<0 ){
				ostringstream ss;
				ss << "file write error(" << strerror(errno) << "):" << tmpname;
				throw kgError(ss.str());
			}
			if( (size_t)wsize!= size){ throw kgError("file write size error");}
			::close(fd);
			end_pos_.push_back(wsize);
		}catch(kgError& err){
			ostringstream ss;
			ss << "file write or close error: " << tmpname;
			throw kgError(ss.str());
		}
	}
	else{
		if(w_page_ >= limit_page_){
			page_p_.at(limit_page_).set( new char[page_size_] );
			limit_page_++;
		}
		memcpy(page_p_.at(w_page_).get(), start, size);
		end_pos_[w_page_] = size;
		w_page_++;
	}
}
// -----------------------------------------------------------------------------
//  ファイル出力されたデータを読み込む
//		fno：ファイルid
//		読み込んだデータはfpage_p_にセットされる
// -----------------------------------------------------------------------------
void kgFldBuffer::fileload(int fno)
{
	try {
		if(fno==0){ fpage_p_.set( new char[page_size_] );}
		int fd = ::open(flist_[fno].c_str(), O_RDONLY);
		if(fd == -1 ){ throw kgError("");}
		int rsize = ::read(fd, fpage_p_.get(), page_size_);		
		if( rsize < 0 ){	throw kgError();}
		if( (size_t)rsize != end_pos_[r_page_]){ throw kgError();}
		::close(fd);
		r_pos_=0;
	}catch(kgError& err){
		ostringstream ss;
		ss << "file write close error: ";
		throw kgError(ss.str());
	}	
}
// -----------------------------------------------------------------------------
//  読み込みページセット
//    読み込みページが最大ページを超えている場合、
//		ファイルからデータを読み込み直して読み込みページをセット
// -----------------------------------------------------------------------------
char* kgFldBuffer::pageSet(void)
{
	if(r_page_==w_page_+flist_.size()){ return NULL;}
	if(r_page_>=max_page_){ 
		if(r_pos_==0){ fileload(r_page_-max_page_); }
		return fpage_p_.get();
	}
	else{
		return page_p_.at(r_page_).get();
	}
	return NULL;
}

// -----------------------------------------------------------------------------
//  項目所得
//    データを読み込み、pntに指定項目数分データをセットする
//    rpage,r_posで読込み場所が決定する
// -----------------------------------------------------------------------------
int kgFldBuffer::getFld(char ** pnt, int fldcnt)
{
	// データ読み込み
	char * page;
	if(r_page_==w_page_+flist_.size()){ return EOF;}
	if(end_pos_[r_page_]==r_pos_){
		r_pos_=0;
		r_page_++;
	}
	page = pageSet();	
	if (page ==NULL) { return EOF;}	

	// 項目セット
	int fldno=0;
	size_t bgn = r_pos_;
	while(1){
		while(*(page+r_pos_)){ r_pos_++;}
		pnt[fldno++] = page+bgn;
		r_pos_++;
		if(fldno==fldcnt){ break;}
		if(end_pos_[r_page_]==r_pos_){
			r_pos_=0;
			r_page_++;	
			page = pageSet();	
			if (page ==NULL) { return EOF;}
		}
		bgn = r_pos_;
	}
	return 1;
}
// -----------------------------------------------------------------------------
//  データリセット
// -----------------------------------------------------------------------------
void kgFldBuffer::reset(){
	w_page_=0;
	r_page_=0;
	r_pos_=0;
	end_pos_.resize(max_page_,0);
	flist_.clear();
}
// -----------------------------------------------------------------------------
//  読み込み位置リセット
// -----------------------------------------------------------------------------
int kgFldBuffer::seekRTop(){
	r_page_=0;
	r_pos_=0;
	return 1;
}

}
