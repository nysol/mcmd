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
// kgCSVout.cpp KGMODで用いられるCSVデータの出力関連の関数
// ============================================================================
#include <cstdio>
#include <sstream>
#include <cerrno>
#include <kgConfig.h>
#include <kgMessage.h>
#include <kgMethod.h>
#include <kgEnv.h>
#include <kgCSVout.h>
#include <kgError.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;
using namespace kglib;

// ----------------------------------------------------------------------------
// 最大record長超過エラーの表示&終了
// ----------------------------------------------------------------------------
static inline void recLenErr(void){
	throw kgError("write buffer border error");
}
// -----------------------------------------------------------------------------
// intからアルファベットへの変換
//  lower:tureで'a',falseで'A'スタート
// 以下アルファベットA-Cとした考えた場合の例
// 1     2     3     4     5     6     7     8     9     10    11    12    13
// A     B     C     AA    AB    AC    BA    BB    BC    CA    CB    CC    AAA
// 3*0+1 3*0+2 3*0+3 3*1+1 3*1+2 3*1+3 3*2+1 3*2+2 3*2+3 3*3+1 3*3+2 3*3+3 9*1+3*1*1 
// -----------------------------------------------------------------------------
static string int2alpha(int val,bool lower)
{
	int div,sub;
	string str;
	char base = 'A';
	if (lower) { base = 'a';}
	while(1){
		div = val/26;
		sub = val%26;
		if(sub==0){
			if(div){ div--;}
			sub=26;
		}
		str.insert(str.begin(),(char)base+sub-1);
		if(div>26){ val=div; }
		else{
			if(div){ str.insert(str.begin(),(char)base+div-1); }	
			break;
		}
	}
	return str;
}
// -----------------------------------------------------------------------------
//コンストラクタ
// -----------------------------------------------------------------------------
//kgCSVout::kgCSVout(kgstr_t fn, kgEnv *env, bool noFldName) 
//{
//	open(fn, env, noFldName);
//}
void kgCSVout::initialset(kgEnv *env, bool noFldName, size_t cnt)
{
	env_ = env;
	_noFldName = noFldName;
	_recNo	= 0;
	if(env_==NULL){
		_maxRecLen = KG_MaxRecLen;
		ioSize_    = KG_oSize;
	  sprintf(_dblFmt,"%%.%dg",KG_PRECISION);
	}else{
		_maxRecLen = env_->getMaxRecLen();
		ioSize_    = env_->oSize();
	  sprintf(_dblFmt,"%%.%dg",env_->precision());
	}
  queSize_ = cnt * _maxRecLen;
	if( queSize_ % ioSize_ != 0 ) {
		throw kgError("internal error: invalid write queue count");
  } 
	ioCnt_   = queSize_ / ioSize_;
  dupSize_ = _maxRecLen;
	bufSize_ = dupSize_ + queSize_;

	// データ領域確保
	try {
    _buf_ap.set(new char[bufSize_+1] );
	} catch(...) {
   	throw kgError("memory allocation error on CSVout");
	}
	_buf    = _buf_ap.get();
	_border = _buf+bufSize_-_maxRecLen;
	_end    = _buf+bufSize_;
	_curPnt = _buf;
	kgMsg(kgMsg::DEB, env_).output("O open inter 0 " + fname_);

}
// -----------------------------------------------------------------------------
// 書き込みファイルをオープンする。
// ファイル名がないの場合は標準出力としてオープンする。
// -----------------------------------------------------------------------------
void kgCSVout::popen(int fd, kgEnv *env, bool noFldName, size_t cnt)
{

	initialset(env,noFldName,cnt);
	// オープン処理
	try {
		fname_ = "STDOUT";
		fd_=fd;
	} catch(...) {
		ostringstream ss;
		ss << "file write open error: " << fname_;
		throw kgError(ss.str());
	}
	kgMsg(kgMsg::DEB, env_).output("O open inter 3");
	opened_= true;
	kgMsg(kgMsg::DEB, env_).output("O open inter 4");
}
// -----------------------------------------------------------------------------
// 書き込みファイルをオープンする。
// ファイル名がないの場合は標準出力としてオープンする。
// -----------------------------------------------------------------------------
void kgCSVout::open(kgstr_t fileName, kgEnv *env, bool noFldName, size_t cnt)
{
	initialset(env,noFldName,cnt);

	// オープン処理
	try {
		if(fileName.size()==0){
			fname_ = "STDOUT";
			fd_=1;
		}else{
			fname_ = fileName;
#ifdef WIN
			fd_ = ::_open(fname_.c_str(), KG_OOPEN_FLG ,_S_IREAD|_S_IWRITE);
#else
			//fd_ = ::open(fname_.c_str(), KG_OOPEN_FLG , S_IRWXU);
			fd_ = ::open(fname_.c_str(), KG_OOPEN_FLG , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
#endif
			if(fd_ == -1 ){ throw kgError();}
		}
	} catch(...) {
		ostringstream ss;
		ss << "file write open error: " << fname_;
		throw kgError(ss.str());
	}
	opened_= true;
}

// -----------------------------------------------------------------------------
// 書き込みファイルを追記オープンする。
// ファイル名がないの場合は標準出力としてオープンする。
// -----------------------------------------------------------------------------
void kgCSVout::aopen(kgstr_t fileName, kgEnv *env, bool noFldName, size_t cnt)
{

	initialset(env,noFldName,cnt);

	// オープン処理
	try {
		if(fileName.size()==0){
			fname_ = "STDOUT";
			fd_=1;
		}else{
			fname_ = fileName;
#ifdef WIN
			fd_ = ::_open(fname_.c_str(), KG_OOPEN_FLG ,_S_IREAD|_S_IWRITE);
#else
			//fd_ = ::open(fname_.c_str(), KG_OOPEN_FLG , S_IRWXU);
			fd_ = ::open(fname_.c_str(), KG_OOPEN_FLG , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
#endif


			if(fd_ == -1 ){ throw kgError();}
		}
	} catch(...) {
		ostringstream ss;
		ss << "file write open error: " << fname_;
		throw kgError(ss.str());
	}
	opened_= true;
}
// -----------------------------------------------------------------------------
//  有効桁数セット
// -----------------------------------------------------------------------------
void kgCSVout::setPrecision(int precision){
	     if(precision>KG_MAX_PRECISION) precision=KG_MAX_PRECISION;
	else if(precision<0               ) precision=0;
  sprintf(_dblFmt,"%%.%dg",precision);
}
void kgCSVout::forceclose(void){
	if(!opened_) return;
#ifdef WIN
	::_close(fd_);
#else
	::close(fd_);
#endif
	opened_ = false;
}
// -----------------------------------------------------------------------------
// 書き込みファイルをクローズする。
// -----------------------------------------------------------------------------
void kgCSVout::close(void)
{
	if(!opened_) return;
	flush();
	try {
#ifdef WIN
	::_close(fd_);
#else
	::close(fd_);
#endif
	}catch(...){
		ostringstream ss;
		ss << "file write close error: " << fname_;
		throw kgError(ss.str());
	}
	opened_ = false;
}
// -----------------------------------------------------------------------------
// bufferに残ったデータを出力する。
// -----------------------------------------------------------------------------
void kgCSVout::flush(void)
{
	// データ出力
	char* start=_buf;
	for(size_t i=0; i<ioCnt_; i++){
		size_t size=0;
		if(start+ioSize_ <= _curPnt){
			size=ioSize_;
		}else{
			size=_curPnt-start;
		}
		size_t wsize_ttl=0;
		int wsize =0;
		while(wsize_ttl<size){
#ifdef WIN
			wsize = ::_write(fd_, start+wsize_ttl, size-wsize_ttl);
#else
			wsize = ::write(fd_, start+wsize_ttl, size-wsize_ttl);
#endif
			if(wsize<0){
				if(errno==11){continue;}
				break;
			}
			wsize_ttl += wsize;
		}		
		if( wsize<0 ){
			if(32==errno){ // pipe broken
				//close();
				wsize=0;
			}else{
				ostringstream ss;
				ss << "file write error(" << strerror(errno) << "):" << fname_;
				throw kgError(ss.str());
			}
		}
		start += wsize_ttl;
		if(wsize_ttl < static_cast<size_t>(ioSize_)) break;
	}

	// バッファ溢れデータを先頭にコピー
	size_t nokori=0;
	if(_curPnt > _border){
		nokori = _curPnt - (_buf+queSize_);
		memcpy(_buf, _buf+queSize_, nokori );
	}
	_curPnt = _buf + nokori;
}
// =============================================================================
// データ型別出力関数
// =============================================================================
// -----------------------------------------------------------------------------
// 文字列項目の出力(DQUOTE,/,\ノ場合に\を追加する)
// -----------------------------------------------------------------------------
void kgCSVout::writeStrForJson(const char *str)
{
	while(*str!='\0'){
		if(_curPnt>=_end) recLenErr();
		if(*str=='"'||*str=='/'||*str=='\\'){
			*_curPnt++ = '\\';
			if(_curPnt>=_end) recLenErr();
		}
		*_curPnt++ = *str++;
	}
	if(_curPnt >= _border) flush();
}



// -----------------------------------------------------------------------------
// 文字列項目の出力(DQUOTEなし)
// -----------------------------------------------------------------------------
void kgCSVout::writeStrNdq(const char *str)
{
	while(*str!='\0'){
		if(_curPnt>=_end) recLenErr();
		*_curPnt++ = *str++;
 	}
 	if(_curPnt >= _border) flush();
}
// -----------------------------------------------------------------------------
// 文字列項目の出力(DQUOTEなし):区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeStrNdq(const char *str, bool eol)
{
	writeStrNdq(str);
	if(eol){ writeEol(); }
	else   { writeDlm(); }
 	if(_curPnt >= _border){ flush(); }
}
// -----------------------------------------------------------------------------
// 文字列項目の出力(DQUOTE自動付加)
// -----------------------------------------------------------------------------
void kgCSVout::writeStr(const char *str)
{
	char *top=_curPnt;
	char *cpp;
	int dq=0;
	while(1){
		if(dq){
			while(*str!='\0'){
				if(_curPnt>=_end) recLenErr();
				if(*str=='"'){
					*_curPnt++ = '"';
					if(_curPnt>=_end) recLenErr();
				}
				*_curPnt++ = *str++;
			}
			*_curPnt++ = '"';
		}else{
			while(*str!='\0'){
				if(_curPnt>=_end) recLenErr();
				if(*str=='\n' || *str=='"' || *str==','){
					for(cpp=_curPnt ; cpp>top; cpp--){
						*cpp=*(cpp-1);
					}
					*top='"';
					_curPnt++;
					dq=1;
					break;
				}
				*_curPnt++ = *str++;
			}
		}
		if(*str=='\0') break;
	}
	if(_curPnt >= _border) flush();
}
// -----------------------------------------------------------------------------
// 文字列項目の出力(DQUOTE自動付加):区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeStr(const char *str, bool eol)
{
	writeStr(str);
	if(eol) writeEol();
	else    writeDlm();
	if(_curPnt >= _border) flush();
}
// -----------------------------------------------------------------------------
// Double項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeDbl(double val){
	char buf[256];
	sprintf(buf,_dblFmt,val);
	writeStrNdq(buf);
}
// -----------------------------------------------------------------------------
// Double項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeDbl(double val, bool eol){
	char buf[256];
	sprintf(buf,_dblFmt,val);
	writeStrNdq(buf, eol);
}
// -----------------------------------------------------------------------------
// int項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeInt(int val){
	char buf[128];
	sprintf(buf,"%d",val);
	writeStrNdq(buf);
}
// -----------------------------------------------------------------------------
// int項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeInt(int val, bool eol){
	char buf[128];
	sprintf(buf,"%d",val);
	writeStrNdq(buf, eol);
}
// -----------------------------------------------------------------------------
// long項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeLong(long val){
	char buf[256];
	sprintf(buf,"%ld",val);
	writeStrNdq(buf);
}
// -----------------------------------------------------------------------------
// long項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeLong(long val, bool eol){
	char buf[256];
	sprintf(buf,"%ld",val);
	writeStrNdq(buf, eol);
}
// -----------------------------------------------------------------------------
// SizeT項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeSizeT(const size_t val){
	char buf[256];
	sprintf(buf,"%zu",val);
	writeStrNdq(buf);
}
// -----------------------------------------------------------------------------
// SizeT項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeSizeT(size_t val, bool eol){
	char buf[256];
	sprintf(buf,"%zu",val);
	writeStrNdq(buf, eol);
}
// -----------------------------------------------------------------------------
// Bool項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeBool(bool val){
	char buf[256];
	sprintf(buf,"%d",val);
	writeStrNdq(buf);
}
// -----------------------------------------------------------------------------
// Bool項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeBool(bool val, bool eol){
	char buf[256];
	sprintf(buf,"%d",val);
	writeStrNdq(buf, eol);
}
// -----------------------------------------------------------------------------
// date項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeDate(const boost::gregorian::date& val){
	char buf[128];
	sprintf(buf,"%04d%02d%02d",(int)val.year(),(int)val.month(),(int)val.day());
	writeStrNdq(buf);
}
// -----------------------------------------------------------------------------
// date項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeDate(const boost::gregorian::date& val,bool eol){
	char buf[128];
	sprintf(buf,"%04d%02d%02d",(int)val.year(),(int)val.month(),(int)val.day());
	writeStrNdq(buf, eol);
}
// -----------------------------------------------------------------------------
// date_time項目の出力
// -----------------------------------------------------------------------------
/*void kgCSVout::writeTime(const boost::posix_time::ptime& val){
	char buf[128];
	sprintf(buf,"%04d%02d%02d%02d%02d%02d",
	  static_cast<int>(val.date().year() ),
	  static_cast<int>(val.date().month()),
	  static_cast<int>(val.date().day()  ),
	                   val.time_of_day().hours()  ,
	                   val.time_of_day().minutes(),
                     val.time_of_day().seconds());
	writeStrNdq(buf);
}*/
// -----------------------------------------------------------------------------
// date_time項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeTime(const boost::posix_time::ptime& val){
	char buf[128];
	if ( val.time_of_day().fractional_seconds()==0 ){
		sprintf(buf,"%04d%02d%02d%02d%02d%02d",
	  static_cast<int>(val.date().year() ),
	  static_cast<int>(val.date().month()),
	  static_cast<int>(val.date().day()  ),
	                   val.time_of_day().hours()  ,
	                   val.time_of_day().minutes(),
                     val.time_of_day().seconds()
                     );
  }else{
		char fmt[128];
		sprintf(fmt,"%%04d%%02d%%02d%%02d%%02d%%02d.%%0%dlld",val.time_of_day().num_fractional_digits() );
		sprintf(buf,fmt,
		  static_cast<int>(val.date().year() ),
		  static_cast<int>(val.date().month()),
	 		static_cast<int>(val.date().day()  ),
			val.time_of_day().hours()  ,
			val.time_of_day().minutes(),
			val.time_of_day().seconds(),
			val.time_of_day().fractional_seconds()
    );  
  }      
	writeStrNdq(buf);
}

// -----------------------------------------------------------------------------
// date_time項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
/*void kgCSVout::writeTime(const boost::posix_time::ptime& val, const bool eol){
	char buf[128];
	sprintf(buf,"%04d%02d%02d%02d%02d%02d",
	  static_cast<int>(val.date().year() ),
	  static_cast<int>(val.date().month()),
	  static_cast<int>(val.date().day()  ),
	                   val.time_of_day().hours()  ,
	                   val.time_of_day().minutes(),
                     val.time_of_day().seconds());
	writeStrNdq(buf, eol);
}
*/
// -----------------------------------------------------------------------------
// date_time項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeTime(const boost::posix_time::ptime& val, const bool eol){
	char buf[128];
	
	if ( val.time_of_day().fractional_seconds()==0 ){
		sprintf(buf,"%04d%02d%02d%02d%02d%02d",
	  static_cast<int>(val.date().year() ),
	  static_cast<int>(val.date().month()),
	  static_cast<int>(val.date().day()  ),
	                   val.time_of_day().hours()  ,
	                   val.time_of_day().minutes(),
                     val.time_of_day().seconds()
                     );
  }else{

		char fmt[128];
		sprintf(fmt,"%%04d%%02d%%02d%%02d%%02d%%02d.%%0%dlld",val.time_of_day().num_fractional_digits() );
		sprintf(buf,fmt,
		  static_cast<int>(val.date().year() ),
		  static_cast<int>(val.date().month()),
	 		static_cast<int>(val.date().day()  ),
			val.time_of_day().hours()  ,
			val.time_of_day().minutes(),
			val.time_of_day().seconds(),
			val.time_of_day().fractional_seconds()
    );  
    //後ろ０クリア
    for(char *p = buf+strlen(buf)-1 ; p>buf && *p=='0' ;p-- ){
    	*p='\0';
    }
  }      
	writeStrNdq(buf, eol);
}


// -----------------------------------------------------------------------------
// kgVal項目の出力
// -----------------------------------------------------------------------------
void kgCSVout::writeVal(const kgVal& val){
	if(val.null()){
		writeStr("");
		return;
	}
	switch(val.type()){
	case 'N': // real
		writeDbl(val.r()); break;
	case 'S': // char*
		writeStr(val.s()); break;
	case 'B': // char*
		writeBool(val.b()); break;
	case 'D': // date
		writeDate(*val.d()); break;
	case 'T': // time
		writeTime(*val.t()); break;
	case 'U': // time
		writeTime(*val.u()); break;
	default:
		writeStr(""); break;
	}
}
// -----------------------------------------------------------------------------
// kgVal項目の出力:区切り文字付加
// -----------------------------------------------------------------------------
void kgCSVout::writeVal(const kgVal& val, bool eol){
	if(val.null()){
		writeStr("",eol);
		return;
	}
	switch(val.type()){
	case 'N': // real
		writeDbl(val.r(), eol); break;
	case 'S': // char*
		writeStr(val.s(), eol); break;
	case 'B': // char*
		writeBool(val.b(), eol); break;
	case 'D': // date
		writeDate(*val.d(), eol); break;
	case 'T': // time
		writeTime(*val.t(), eol); break;
	default:
		writeStr("", eol); break;
	}
}
// -----------------------------------------------------------------------------
// 数字からアルファベットに変換して出力
// (val>0であることが前提)
// -----------------------------------------------------------------------------
void kgCSVout::writeInt2alpha(int val)
{
	string str = int2alpha(val,true);
	writeStr( str.c_str());		
}
// =============================================================================
// データ行出力関数
// 高速化を図るために引数はアドレスで受け取ることを基本とする．
// =============================================================================
// -----------------------------------------------------------------------------
// 一行出力
// -----------------------------------------------------------------------------
void kgCSVout::writeRec(char* rec) {
	writeStrNdq( rec, true);
}
// -----------------------------------------------------------------------------
// 一行+int項目
// -----------------------------------------------------------------------------
void kgCSVout::writeRec(char* rec,int val) {
	writeStrNdq( rec, false);
	writeInt		( val, true);
}
// -----------------------------------------------------------------------------
// size個の文字列fldsを出力する．
// -----------------------------------------------------------------------------
void kgCSVout::writeFld(size_t size, char** flds, bool eol)
{
	size_t i;
	for(i=0; i<size-1; i++){
		writeStr( flds[i], false);
	}
	writeStr( flds[i], eol );
}
// -----------------------------------------------------------------------------
// flgが-1の項目はfldの文字列を出力し，それ以外は対応するvalを出力
//  例) CSV項目名 a,b,c,d,e  f=b,d,aの場合
//    CSV項目名   a  ,  b  ,  c  ,  d  ,  e
//    CSV項目値 "AAA","BBB","CCC","DDD","EEE"
//    flg         2  ,  0  , -1  ,  1  , -1
//    val        5.0,2.0,9.1
//      flgがCSV項目名とvalのmappingの役割を担っている．
//        ex. 第1項目名aのvalにおける位置は2であり，val[2]=9.1として項目値出力
//            第3項目名cは-1であり対応するvalはなし，CSV項目"CCC"を出力
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
//  val : char**バージョン
// -----------------------------------------------------------------------------
void kgCSVout::writeFld(char** fld, const vector<int>* flg, char** val){
	unsigned int i;
	int num;
	for(i=0; i<flg->size()-1; i++){
		num=flg->at(i);
		if(num == -1){ writeStr( *(fld+i)  , false );}
		else         { writeStr( *(val+num), false );}
	}
	num=flg->at(i);
	if(num == -1)  { writeStr( fld[i]    , true  );}
	else           { writeStr( *(val+num), true  );}
}
// -----------------------------------------------------------------------------
//  val : vector<kgVal>バージョン
// -----------------------------------------------------------------------------
void kgCSVout::writeFld(char** fld, const vector<int>* flg, vector<kgVal>& val)
{	
	size_t i;
	int num;
	for(i=0; i<flg->size()-1; i++){ 
		num=flg->at(i);
		if(num == -1) { writeStr( *(fld+i)   , false );}
		else          { writeVal(val.at(num) , false );}
	}
		num=flg->at(i);
		if(num == -1) { writeStr( *(fld+i)   , true );}
		else          { writeVal(val.at(num) , true );}
}
// -----------------------------------------------------------------------------
// joinでアウタージョイン(-Nの場合に使用)マスタにあってトラにない場合
// flgが-1のものはNULL出力し、それ以外はvalから項目番号割り出しを出力
// -----------------------------------------------------------------------------
void kgCSVout::writeFld( const vector<int>* flg, const vector<int>* val,char** fld,const vector<int>* addcnt){
	size_t i;
	int num;
	for(i=0; i<flg->size(); i++){
		num=flg->at(i);
		if(num == -1) { writeStr( ""									  , false );}
		else				  {	writeStr( *( fld+ val->at(num)) , false );}
	}

	// -nfnでtraデータない場合はflg->sizeは0となる．
	// その場合，参照ファイルのキーを出力する
	if(flg->size()==0){
		for(i=0; i<val->size(); i++){
			num=val->at(i);
			if(num != -1){ writeStr( *( fld+ val->at(num)), false );}
		}
	}

	// 追加項目出力
	for(i=0; i<addcnt->size()-1; i++){
		writeStr( *(fld+addcnt->at(i))   , false );
	}
		writeStr( *(fld+addcnt->at(i))   , true  );
}
// =============================================================================
//   CSV+付加項目出力(mnumberで使用)
//		size分fldの内容を出力(入力csv分)し
//		valの内容を出力(int)。
//		alpha_flgがtrueだと 1 => A,2 => B 26=>z ,27=>AA 52=>AZ 53=>BA出力
//    (val>0であることが前提)
// ============================================================================= 
void kgCSVout::writeFld(char** fld,size_t size,int val,bool alpha_flg)
{
	for(size_t i=0; i<size; i++){
		if(fld==NULL) { writeStr( ""    	 , false );}
		else 					{ writeStr( *(fld+i) , false );}
	}
	if(alpha_flg){
		string str = int2alpha(val,false);
		writeStr( str.c_str(), true );
	}
	else{
		writeInt( val, true );
	}
}
// =============================================================================
//   CSV+付加項目出力(mcountで使用)
//		size分fldの内容を出力(入力csv分)し
//		valの内容を出力(size_t)。
//		alpha_flgがtrueだと 1 => A,2 => B 26=>z ,27=>AA 52=>AZ 53=>BA出力
//    (val>0であることが前提)
// ============================================================================= 
void kgCSVout::writeFld(char** fld,size_t size, size_t val)
{
	for(size_t i=0; i<size; i++){
		if(fld==NULL) { writeStr( ""    	 , false );}
		else 					{ writeStr( *(fld+i) , false );}
	}
	writeSizeT( val, true );
}



// =============================================================================
//   CSV項目指定出力
//		cnt分fldの内容を出力(参照csv分)。
//		cntには出力すべき内容のfldでの項目番号がセットされている
//		項目番号が-1の場合はNULLを出力する
//		eolによって改行するかどうかを決定する
// =============================================================================
void kgCSVout::writeFld(char** fld, const vector<int   >* cnt, bool eol)
{
	size_t  i;
	for(i=0; i<cnt->size()-1; i++){
		if(cnt->at(i)==-1) { writeStr( ""   						, false  );}
		else							 { writeStr( *(fld+cnt->at(i)), false  );}
	}
		if(cnt->at(i)==-1) { writeStr( ""   							, eol );}
		else 							 { writeStr( *(fld+cnt->at(i))  , eol );}
}
// =============================================================================
//   CSV+付加項目出力
//		size分fldの内容を出力(入力csv分)し
//		addcnt分addfldの内容を出力(参照csv分)。
//		addcntには出力すべき内容のaddfldでの項目番号がセットされている
//		fld,addfldがNULLである時、size,addcnt分NULL("")を出力する
// =============================================================================
void kgCSVout::writeFld(char** fld,size_t size,char** addfld, const vector<int   >* addcnt)
{
	size_t  j;
	for(size_t i=0; i<size; i++){
		if(fld==NULL) {	writeStr( ""    	  , false ); }
		else 					{	writeStr( *(fld+i), false );   }
	}
	if( addcnt->size() > 0 ){
		for(j=0; j<addcnt->size()-1; j++){
			if(addfld==NULL) { writeStr( ""                        , false ); }
			else 						 { writeStr( *(addfld+addcnt->at(j))   , false ); }
		}
		if(addfld==NULL)   { writeStr( ""                        , true  ); }
		else						   { writeStr( *(addfld+addcnt->at(j))   , true  ); }
	}else{
		writeEol();
	}
}
// =============================================================================
//   CSV+付加項目出力
//		size分fldの内容を出力(入力csv分)し
//		addfldの内容を出力(参照csv分)。
// =============================================================================
void kgCSVout::writeFld(char** fld,size_t size,char** addfld,int addsize)
{
	for(size_t i=0; i<size; i++){
		if(fld==NULL){ writeStr( ""    	  , false ); }
		else 				 { writeStr( *(fld+i) , false ); }
	}
	for(int i=0; i<addsize; i++){
		if(addfld==NULL){
			if(i<addsize-1){ writeStr( ""						, false  ); }
			else					 { writeStr( ""						, true   ); }
		}else{
			if(i<addsize-1){ writeStr( *(addfld+i)	, false  ); }
			else					 { writeStr( *(addfld+i)	, true   ); }
		}
	}
}
// =============================================================================
//   CSV+付加項目出力
//		size分fldの内容を出力(入力csv分)し
//		newFld(vector<>の内容を出力。
// =============================================================================
void kgCSVout::writeFld(char** fld,size_t size,vector<string> *newFld)
{ 	
	for(size_t i=0; i<size; i++){ 
		writeStr( *(fld+i), false );
	}
	vector<kgstr_t>::size_type newsize = newFld->size();
	for(vector<kgstr_t>::size_type i=0; i<newsize; i++){
		if(i<newsize-1) { writeStr( newFld->at(i).c_str()	, false );}
		else						{ writeStr( newFld->at(i).c_str()	, true  );}
	}
}
// =============================================================================
// 項目名特化出力関数
//  項目名無しの場合にはskipされる
// =============================================================================
// -----------------------------------------------------------------------------
// 項目名にかぶっているものがないこと
// 項目名が正当かどうか
// を確認してから出力する
// -----------------------------------------------------------------------------
void kgCSVout::writeFldNameCHK(vector<kgstr_t>& outfld ,bool rp)
{
	int fsize = outfld.size();
	//ソート情報チェック
	vector<kgstr_t>  flddata (fsize);
	vector<SortInfo> sortinfo(fsize);
	vector<bool>     scheck  (fsize,false);
	int lim;
	for(int i=0; i<fsize; i++){
		vector<string> spstr = splitToken(outfld.at(i),'%');
		if( spstr.empty() ){ flddata[i]="";}
		else							 { flddata[i]=spstr.at(0);}
		if(spstr.size()>1) { sortinfo[i] =  SortInfo(spstr.at(1)); }
		else							 { sortinfo[i] =  SortInfo(); }
		int keypos = sortinfo[i].keypos(); 
		if(keypos!=-1 && keypos < fsize ){ 
			scheck[keypos] = true;
		}
	}
	for(lim=0 ;lim<fsize ;lim++){
		if(scheck[lim]==false){ break; }
	}
	if(rp){ lim=0; }
	//出力項目再セット
	vector<kgstr_t> newfld(fsize);
	for(int i=0; i<fsize; i++){
		int keypos = sortinfo.at(i).keypos();
		if(keypos>=lim){ newfld[i] = flddata[i]; }
		else					 { newfld[i] = outfld[i]; }
	}
	sort(flddata.begin(),flddata.end());
	vector<kgstr_t>::iterator i = adjacent_find(flddata.begin(),flddata.end()); 
	if(i!=flddata.end()){
		ostringstream ss;
		ss << "same field name is specified: " << *i;
		throw kgError(ss.str());
	}
	for(vector<kgstr_t>::size_type i=0; i<newfld.size(); i++){
		if(chkFldName(newfld.at(i))==false){
			ostringstream ss;
			ss << "There is an illegal character in the item name. :" << outfld.at(i);
			throw kgError(ss.str());
		}
		if(i<newfld.size()-1){ writeStr( newfld.at(i).c_str(), false);}
		else                 { writeStr( newfld.at(i).c_str()); writeEolNC();}
	}	
}
// -----------------------------------------------------------------------------
// csv項目名を出力する．
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgCSV& csv,bool org)
{
	if( _noFldName ) return;
	int size=csv.fldSize();
	if(size<=0){ throw kgError("no output fields"); }

	//出力項目セット
	vector<kgstr_t> outfld;
	for(int i=0; i<size; i++){
		outfld.push_back( csv.fldName(i,org) );
	}
	writeFldNameCHK(outfld);
}
// -----------------------------------------------------------------------------
// csv項目名を出力する．
// ソート情報追加VERSION
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgArgFld& fld,kgstr_t addstr)
{
	if( _noFldName ) return;
	int size=fld.csv()->fldSize();
	if(size<=0){ throw kgError("no output fields"); }

	//出力項目セット
	vector<kgstr_t> outfld;
	for(int i=0; i<size; i++){
		if(fld.flg(i)==-1){//旧ソート情報は削除
			outfld.push_back( fld.csv()->fldName(i) );
		}
		else{
			kgstr_t tstr=fld.csv()->fldName(i);
			tstr.append(addstr);
			tstr.append(toString(fld.flg(i)));
			tstr.append(fld.attr(fld.flg(i)));
			outfld.push_back( tstr );
		}
	}
	writeFldNameCHK(outfld);
}


// -----------------------------------------------------------------------------
// csv項目名を出力する． (利用mod: kgsum)
//   ex1. CSV a,b,c : f=a:A,c : a,b,c
// ただし，second=tureの場合，fldに指定された項目のみattr名に変えて出力
//   ex2. CSV a,b,c : f=a:A,c : A,b,c
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgArgFld& fld, bool second,bool org)
{
	if( _noFldName ) return;
	int size=fld.csv()->fldSize();
	if( fld.size()<=0 || (second && fld.attrSize()<=0) ){
    throw kgError("no output fields");
	}

	//出力項目セット
	vector<kgstr_t> outfld;
	kgstr_t oName;
	int flg;
	if(second){
		for(int i=0; i<size; i++){
			flg=fld.flg(i);
			if( flg==-1 ){ oName=fld.csv()->fldName(i,org);}
			else{
				oName=fld.attr(flg);
				if( oName.empty()){ oName=fld.name(flg); }
			}
			outfld.push_back( oName );
		}
		writeFldNameCHK(outfld);
	}else{
		for(int i=0; i<size; i++){
			flg=fld.flg(i);
			if( flg==-1 ){ oName=fld.csv()->fldName(i,org);}
			else         { oName=fld.name(flg);}
			outfld.push_back( oName );
		}
		writeFldNameCHK(outfld);
	}
}

// -----------------------------------------------------------------------------
// csv項目+fld項目を出力(利用mod: kgjoin,mwindow)
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgCSV& csv, kgArgFld& fld, bool second,bool back)
{
	if( _noFldName ) return;

	//項目セット
	int size=csv.fldSize();
	vector<kgstr_t> outfld;
	if(back){
		for(int i=0; i<size; i++){
			outfld.push_back( csv.fldName(i,true) ); 
		}
	}
	string::size_type msize=fld.size();
	if(second){
		kgstr_t oName;
		for(string::size_type i=0; i<msize; i++){
			oName=fld.attr(i);                    
			if( oName.empty()) oName=fld.name(i);
			outfld.push_back( oName );
		}
	}
	else{
		for(string::size_type i=0; i<msize; i++){
			outfld.push_back( fld.name(i) );	
		}
	}
	if(!back){
		for(int i=0; i<size; i++){
			outfld.push_back( csv.fldName(i,true) );
		}
	}
	writeFldNameCHK(outfld);
}
	
// -----------------------------------------------------------------------------
// csv項目+newFldを出力
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgCSV& csv, kgstr_t newFld)
{
	if( _noFldName ) return;
	int size=csv.fldSize();
	if(size<=0){ throw kgError("no output fields"); }

	//項目セット
	vector<kgstr_t> outfld;
	for(int i=0; i<size; i++){ 
		outfld.push_back( csv.fldName(i,true) );
	}
	outfld.push_back( newFld );	
	writeFldNameCHK(outfld);
}

// -----------------------------------------------------------------------------
// csv項目+newFld(vector)を出力
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgCSV& csv, vector<kgstr_t> newFld)
{
	if( _noFldName ) return;
	int size=csv.fldSize();
	if(size<=0){ throw kgError("no output fields");}
	
	//項目セット
	vector<kgstr_t> outfld;
	for(int i=0; i<size; i++){ 
		outfld.push_back( csv.fldName(i,true) );
	}
	vector<kgstr_t>::size_type newsize=newFld.size();
	for(vector<kgstr_t>::size_type i=0; i<newsize; i++){
		outfld.push_back( newFld[i] );
	}
	writeFldNameCHK(outfld);
}
// -----------------------------------------------------------------------------
// newFldを出力
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(kgstr_t newFld)
{
	if( _noFldName ) return;

	//項目セット
	vector<kgstr_t> outfld;
	outfld.push_back( newFld );	
	writeFldNameCHK(outfld);
}
// -----------------------------------------------------------------------------
// newFld(vector)を出力
// -----------------------------------------------------------------------------
void kgCSVout::writeFldName(vector<kgstr_t> newFld,bool rp)
{
	if( _noFldName ) return;

	//項目セット
	writeFldNameCHK(newFld);
}
