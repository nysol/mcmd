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
// kgCSV.cpp KGMODで用いられるCSVデータの入力関連の関数
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <sstream>
#include <kgEnv.h>
#include <kgConfig.h>
#include <kgMethod.h>
#include <kgCSV.h>
#include <kgCSVutils.h>
#include <kgError.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;
using namespace kglib;

// ----------------------------------------------------------------------------
// 項目数が異なるerrorメッセージの表示&終了
// ----------------------------------------------------------------------------
static void fldCntErr(int fldCnt, int j)  {
	ostringstream ss;
	ss << "detected different number of fields (header has " << fldCnt << " but the record has " << j<< ")";
	throw kgError(ss.str());
}
// ============================================================================
// kgCSVクラス
// ============================================================================
// ----------------------------------------------------------------------------
// clean up:初期状態の戻す
// ----------------------------------------------------------------------------
void kgCSV::clear(void)
{
	env_			 = 0;
	fd_				 = 0;
	opened_    = false;
	ap_.clear();
	buf_			 = 0;
	maxRecLen_ = 0;
	queSize_	 = 0;
	border_    = 0;
	dupTop_    = 0;
	dupSize_   = 0;
	bufSize_   = 0;
	curPnt_    = 0;
	noFldName_ = false;
  fldName_.clear();
  fldNameOrg_.clear();
	fldNum_.clear();
	fldSize_     = 0;
	fldByteSize_ = 0;
	status_    	 = 0;
	recNo_     	 = 0;
	fldSInfo_.clear();


}
// ----------------------------------------------------------------------------
//  データのバッファへの読み込み
//	バッファ最後のmaxRecLen_文字をbuffer先頭緩衝領域にコピー
// ----------------------------------------------------------------------------
void kgCSV::readCSVfile()  
{
	if(! begin()){ memcpy(buf_, dupTop_, dupSize_); }
	curPnt_ = curPnt_ - queSize_;
	size_t maxSize=ioSize_*ioCnt_;
	size_t accSize=0;
	size_t resSize=maxSize;
	while(accSize<maxSize){
		int rsize = ::read(fd_, buf_ + dupSize_ + accSize, resSize<ioSize_ ? resSize : ioSize_);
		if( rsize < 0 ){ 
			if(errno==70||errno==11){ continue;}
			throw kgError("read error"); 
		}
		if( rsize == 0 ) { 
			//最後が改行でなければ改行付加(ただしゼロバイトファイル除く)
			if( !( begin() && accSize==0) ){
				if (*(buf_+dupSize_+accSize-1)!='\n' 
						&& *(buf_+dupSize_+accSize-1)!='\r')
				{
					*(buf_+dupSize_+accSize)='\n';
					accSize++;
				}
			}
			break;
		}
		accSize+=static_cast<size_t>(rsize);
		resSize-=static_cast<size_t>(rsize);
	}
	*(buf_+dupSize_+accSize) = '\0';
}

void kgCSV::initialSet(const kgstr_t& fileName, kgEnv* env, bool noFldName,size_t cnt) {
	// 初期値セット
	noFldName_   = noFldName;
	buf_         = 0;
	curPnt_      = 0;
	fldByteSize_ = 0;
	recNo_       = 0;
	env_         = env;
	status_      = Begin;
	if(fileName.size()==0){ fname_="/dev/stdin"; }
	else									{ 
		vector<kgstr_t> name(1,fileName);
		fname_=kgFilesearch(name,false,false,false).at(0); 
	}
	if(env_==NULL){
		maxRecLen_ = KG_MaxRecLen;
		ioSize_    = KG_iSize;
	}else{
		maxRecLen_ = env_->getMaxRecLen();
		ioSize_    = env_->iSize();
	}
	queSize_   = cnt * ioSize_;
	if( queSize_ % ioSize_ != 0 ) {
		throw kgError("internal error: invalid queue count");
	}
  ioCnt_   = queSize_ / ioSize_;

}

void kgCSV::popen(int fd, kgEnv* env, bool noFldName,size_t cnt)  
{
	initialSet("",env, noFldName,cnt);

	// オープン処理
	try {
		fd_ = fd;
	}catch(kgError& err){
		ostringstream ss;
		ss << "file read open error: " << fname_;
		throw kgError(ss.str());
	}
	opened_=true;
}

// ----------------------------------------------------------------------------
// 各種変数の初期化＆ファイルオープン(実ファイルと標準入力の識別)
// queSize_ : queueのサイズ
// ioSize_ : read関数で一回に読込むサイズ
// ioCnt_ : 一回のkgIFP::readでread関数を何回呼ぶか(= queSize_/ioSize_)
// ----------------------------------------------------------------------------
void kgCSV::open(const kgstr_t& fileName, kgEnv* env, bool noFldName,size_t cnt)  
{
	initialSet(fileName,env, noFldName,cnt);

	// オープン処理
	try {
		fd_ = ::open(fname_.c_str(), KG_IOPEN_FLG);
		if(fd_ == -1 ){ throw kgError(); }
	}catch(kgError& err){
		ostringstream ss;
		ss << "file read open error: " << fname_ << "(" << errno << ")" ;
		throw kgError(ss.str());
	}
	opened_=true;
}

void kgCSV::setSortInfo(const kgstr_t& fldName)
{
	fldSInfo_.push_back(SortInfo(fldName));
}

//------------------------------------------------------------------------------
// ソートが必要であればtrue
//------------------------------------------------------------------------------
bool kgCSV::sortFldchk(vector<int>& fld)
{
	if(noFldName_){ return false; }

	for(kgstr_t::size_type i=0; i<fld.size(); i++){
		int num = fld[i];
		int checkType = SortInfo::CharSort;
		if( fldSInfo_.at(num).keypos()==(int)i 
			&& 	fldSInfo_.at(num)._type == checkType){
			continue;
		}
		return true;
	}
	return false;
}

// 項目展開＆チェック
bool kgCSV::sortFldchk(vector<kgstr_t>& fld ,bool fldbynum)
{
	if(noFldName_){ return false; }

	vector<kgstr_t> name;
	vector<kgstr_t> attr;
	for(kgstr_t::size_type i=0; i<fld.size(); i++){
		vector <kgstr_t> spfld = splitToken(fld[i],'%');

		if(spfld.size()>0){
			name.push_back(spfld[0]);
		}
		else{
			name.push_back("");		
		}
		if(spfld.size()>1){ 
			attr.push_back(spfld[1]); 
		}
		else {
			attr.push_back("");
		}
	}
	vector<int> numv = evalFldName(name, attr, this ,fldbynum);
	
	// 項目名再セット fldbynum trueの場合番号セット 
	fld.clear();
	if (fldbynum){
		for(kgstr_t::size_type i=0; i<numv.size(); i++){
			if(attr[i]!=""){ fld.push_back(toString(numv[i])+"%"+attr[i]); }
			else           { fld.push_back(toString(numv[i])); }
		}
	}
	else{
		for(kgstr_t::size_type i=0; i<name.size(); i++){
			if(attr[i]!=""){ fld.push_back(name[i]+"%"+attr[i]); }
			else           { fld.push_back(name[i]); }
		}
	}

	for(kgstr_t::size_type i=0; i<name.size(); i++){
		int num;
		if(fldbynum){	num = numv[i];}
		else{ num = fldNum(name[i]);}
		int checkType = SortInfo::CharSort;
		if(attr[i]!=""){
			if(attr[i].find("n")!=kgstr_t::npos){ checkType = SortInfo::NumSort;}
			if(attr[i].find("r")!=kgstr_t::npos){ checkType |= SortInfo::Reverse;}
		}
		if( fldSInfo_.at(num).keypos()==(int)i 
			&& 	fldSInfo_.at(num)._type == checkType){
			continue;
		}
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
// バッファの確保＆項目行の読み込み
//------------------------------------------------------------------------------
void kgCSV::set_fields(size_t dupSize) 
{
	//バッファ確保
	dupSize_ = dupSize;
	bufSize_ = dupSize_ + queSize_;
	try {
		ap_.set( new char[bufSize_+1] );
	} catch(...) {
		throw kgError("memory allocation error on CSVin");
	}
	buf_ = ap_.get();

	// データ読込（readCSVfileで読み込まれる）
	// border_ : 読み込み限界位置、
	// dupTop_ : 緩衝領域へのコピーする先頭アドレス（バッファ末尾か１or２行分前アドレス）
	// curPnt_ : バッファ末尾+1にセット。初回のreadCSVfileのため
	border_ = buf_ + bufSize_ - maxRecLen_;
	dupTop_ = buf_ + bufSize_ - dupSize_;
	curPnt_ = buf_+bufSize_;
	readCSVfile();

	// いきなりのeofの検知:
	// -nfnで0バイトファイルの場合はなにもせずreturn
	// -nfnでなく0バイトファイルの場合はエラー
	if(isEOF()){
		status_=End;
		if(noFldName_){
  		fldSize_=0;
			return;
		}else{
			ostringstream ss;
			ss << "no data found : " << fname_;
			throw kgError(ss.str());
		}
	}

	// 項目名(先頭行)の取得
	// 項目名無しの場合は番号がセットされる
	if(!noFldName_){
  	fldSize_=kglib::cntFldToken(curPnt_, maxRecLen_);
		kgAutoPtr2<char*> nameChr_ap;
		nameChr_ap.set( new char*[fldSize_] );
		char** nameChr = nameChr_ap.get();
		char*  endStr;
		try{
			endStr=sepFldToken(nameChr, fldSize_, curPnt_, maxRecLen_);
		}catch(kgError& err){
			err.addMessage("[ " + fname_ + " ]");
			throw err;
		}

  	for(size_t i=0; i<fldSize_; i++){
			string s=*(nameChr+i);
			fldNameOrg_.push_back( s );
			vector<string> str_s = splitToken(s,'%');
			if(str_s.size()==0){
				ostringstream ss;
				ss << "field name is null";
				throw kgError(ss.str());
			}
			fldName_.push_back( str_s[0] );
			fldNum_[str_s[0]]=i;
			if(str_s.size()>1) { setSortInfo(str_s[1]); }
			else							 { setSortInfo("");}
		}
		fldByteSize_=endStr - buf_ - dupSize_ + 1;
		curPnt_ = endStr + 1;
	}else{ 
  	fldSize_=kglib::cntFldToken(curPnt_, maxRecLen_);
		fldByteSize_=0;
  	for(size_t i=0; i<fldSize_; i++){ 
			fldNameOrg_.push_back( toString(i) );
			fldName_.push_back( toString(i) );
  		setSortInfo("");
  	}
	}
}
// ----------------------------------------------------------------------------
// 読み込みファイルのクローズ
//  ファイル入力の場合(stdinでない場合)にclose処理
// ----------------------------------------------------------------------------
void kgCSV::close(void)  
{
	if(!opened_) return;
	try {
		::close(fd_);
	}catch(kgError& err){
		ostringstream ss;
		ss << "file read close error: " << fname_;
		throw kgError(ss.str());
	}
	opened_=false;
}
// ----------------------------------------------------------------------------
// num番目の項目名を返す
// ----------------------------------------------------------------------------
kgstr_t kgCSV::fldName(const size_t num,bool org) const  
{
	if(num < fldSize_){
		if(org){ return fldNameOrg_.at(num);}
		else	 { return fldName_.at(num);}
	}else{
		ostringstream ss;
		ss << "field number " << num+1 <<  " is out of range :" << fname_;
		throw kgError(ss.str());
	}
}
// ----------------------------------------------------------------------------
// 項目名から番号を返す。
// 項目名が見つからない時は rtnがtrueなら-1 rtnがfalseならエラー デフォルトはfalse
// ----------------------------------------------------------------------------
int kgCSV::fldNum(const kgstr_t& str,bool rtn) const  
{
	map<kgstr_t,int>::const_iterator i = fldNum_.find(str);
	if( i != fldNum_.end() ){
		return i->second;
	}else{
		if(rtn){ return -1;}
		else{
			ostringstream ss;
			ss << "field name not found: `" << str << "' in "<< fname_;
			throw kgError(ss.str());
		}
	}
}
// ----------------------------------------------------------------------------
// バッファ内容の丸ごとコピー
// toEndがtrueならばカレントポインタに関係なく全バッファをコピー
// falseならばカレントポインタまでをコピーする
// コピーしたバイト数を返す。
// rubyのmtableで利用している.
// ----------------------------------------------------------------------------
size_t kgCSV::bufCpy(char* to, bool toEnd) const
{
	if(toEnd) memcpy(to, buf_, bufSize_ + 1    );
	else      memcpy(to, buf_, curPnt_ - buf_ + 1);
	return to - buf_;
}
// ----------------------------------------------------------------------------
// ファイルがパイプかどうかのチェック
// ----------------------------------------------------------------------------
bool kgCSV::isFifo(void) const
{
	struct stat st;
	if(fname_.empty()){ return false;}
	if(::fstat(fd_, &st)==-1){ return false;}
	return S_ISFIFO(st.st_mode);
}
// ----------------------------------------------------------------------------
// データ部の先頭の位置へ戻す処理
// 標準入力あるいはパイプの場合はエラーとする
// ----------------------------------------------------------------------------
void kgCSV::seekTop(void) 
{
	// 先頭シーク
	try {
		::lseek(fd_,0,0);       
	}catch(...){
		ostringstream ss;
		ss << "input file seek error: " << fname_;
		throw kgError(ss.str());
	}

	// バッファ再読込
	status_ = Begin;
	recNo_=0;
	curPnt_ = buf_ + bufSize_;
	readCSVfile();

	// いきなりのeofの検知:
	// -nfnで0バイトファイルの場合はなにもせずreturn
	// -nfnでなく0バイトファイルの場合はエラー
	if(isEOF()){
		status_=End;
		if(noFldName_){
			fldSize_=0;
			return;
		}else{
			ostringstream ss;
			ss << "no data found: " << fname_;
			throw kgError(ss.str());
		}
	}

	// 項目名がある場合は項目行をスキップ
	if(!noFldName_){ 
		curPnt_ =  buf_ + dupSize_ + fldByteSize_;
		if(isEOF()) status_ = End;
	}
}
// ============================================================================
// kgCSVrec
// ============================================================================
// -----------------------------------------------------------------------------
// バッファ確保＆ヘッダ読み込み
// -----------------------------------------------------------------------------
void kgCSVrec::read_header(void)
{
	_rec=NULL;
	if(!opened_) return;
	set_fields(maxRecLen_);
	if(isEOF()){ status_ = End; }
}
// -----------------------------------------------------------------------------
// 読み込み
//  _recに現在読込データ位置がセットされる
// -----------------------------------------------------------------------------
int kgCSVrec::read() 
{
	// データ読込
	if( end() ) return EOF;
	if(isEndOfBuf()) readCSVfile();

	// データセット
	_rec = curPnt_;
	curPnt_ = sepRecToken(curPnt_, maxRecLen_) + 1;
		
	recNo_++;

	// statusセット
	if(isEOF()) status_ = End;
	else        status_ = Normal;
	return 1;
}
// ============================================================================
// kgCSVrecSIMPLE
// ============================================================================
// -----------------------------------------------------------------------------
// バッファ確保＆ヘッダ読み込み
// -----------------------------------------------------------------------------
void kgCSVrecSimple::read_header(void)
{
	_rec=NULL;
	if(!opened_) return;

	//バッファ確保
	dupSize_ = maxRecLen_;
	bufSize_ = dupSize_ + queSize_;
	try {
		ap_.set( new char[bufSize_+1] );
	} catch(...) {
		throw kgError("memory allocation error on CSVin");
	}
	buf_ = ap_.get();

	// データ読込（readCSVfileで読み込まれる）
	// border_ : 読み込み限界位置、
	// dupTop_ : 緩衝領域へのコピーする先頭アドレス（バッファ末尾か１or２行分前アドレス）
	// curPnt_ : バッファ末尾+1にセット。初回のreadCSVfileのため
	border_ = buf_ + bufSize_ - maxRecLen_;
	dupTop_ = buf_ + bufSize_ - dupSize_;
	curPnt_ = buf_+bufSize_;
	readCSVfile();

	// いきなりのeofの検知:
	// -nfnで0バイトファイルの場合はなにもせずreturn
	// -nfnでなく0バイトファイルの場合はエラー
	if(isEOF()){
		status_=End;
		if(noFldName_){
  		fldSize_=0;
			return;
		}else{
			ostringstream ss;
			ss << "no data found : " << fname_;
			throw kgError(ss.str());
		}
	}
}
// -----------------------------------------------------------------------------
// 読み込み
//  _recに現在読込データ位置がセットされる
// -----------------------------------------------------------------------------
int kgCSVrecSimple::read() 
{
	// データ読込
	if( end() ) return EOF;
	if(isEndOfBuf()) readCSVfile();

	// データセット
	_rec = curPnt_;
	curPnt_ = sepRecTokenNdq(curPnt_) + 1;
	recNo_++;

	// statusセット
	if(isEOF()) status_ = End;
	else        status_ = Normal;
	return 1;
}

// ============================================================================
// kgCSVfld
// ============================================================================
// -----------------------------------------------------------------------------
// バッファ確保＆ヘッダ読み込み
// -----------------------------------------------------------------------------
void kgCSVfld::read_header(void)
{
	if(!opened_) return;
	set_fields(maxRecLen_);
	_fld_ap.set( new char*[fldSize_] );
	_fld    = _fld_ap.get();
	if(isEOF()) status_ = End;
}
// -----------------------------------------------------------------------------
// 読み込み
//  _fldに現在読込データ位置がセットされる(分割された各項目へのポインタ)
// -----------------------------------------------------------------------------
int kgCSVfld::read(void) 
{
	// データ読込
	if( end() ) return EOF;
	if(isEndOfBuf()) readCSVfile();

	// 項目分割	&データセット
	try{
		curPnt_ = sepFldToken(_fld, fldSize_, curPnt_, maxRecLen_) + 1;
	}catch(kgError& err){
		err.addMessage("[ " + fname_ + " ]");
		throw err;
	}
	recNo_++;

	// statusセット
	if(isEOF()) status_ = End;
	else        status_ = Normal;
	return 1;
}
// -----------------------------------------------------------------------------
// 読み込み(一つのバッファ制限を超えたらEOFを返す)
// ruby のmtableで利用している。
// -----------------------------------------------------------------------------
int kgCSVfld::read_limit(void) 
{
	// データ読込
	if(end()) return EOF;
	if(isEndOfBuf()) return -9;

	// 項目分割	&データセット
	try{
		curPnt_ = sepFldToken(_fld, fldSize_, curPnt_, maxRecLen_) + 1;
	}catch(kgError& err){
		err.addMessage("[ " + fname_ + " ]");
		throw err;
	}

	recNo_++;

	// statusセット
	if(isEOF()) status_ = End;
	else        status_ = Normal;
	return 1;
}

void kgCSVfld::replaceSet(kgCSVfld *csv, kgEnv* env, bool noFldName,size_t cnt)
{
	csvFldCopy(csv ,this);
}
// ============================================================================
// kgCSVkey
// ============================================================================
// -----------------------------------------------------------------------------
// バッファ確保＆ヘッダ読み込み
// -----------------------------------------------------------------------------
void kgCSVkeyX::read_header(void) 
{
	if(!opened_) return;
	set_fields(maxRecLen_*2);
	if(isEOF()){
		status_=KeyBreak;
		status_|=End;
	}
	_newFld = NULL;
	_oldFld = NULL;
	_fld0_ap.set( new char*[fldSize_] );
	_fld1_ap.set( new char*[fldSize_] );
	_fld0 = _fld0_ap.get();
	_fld1 = _fld1_ap.get();
	for(size_t i=0; i<fldSize_; i++){
		_fld0[i]=const_cast<char*>(""); 
		_fld1[i]=const_cast<char*>(""); 
	}
	_newFld   = _fld0;
	_oldFld   = _fld1;
}
// -----------------------------------------------------------------------------
// 読み込み
//  _newFld,_oldFldに現在読込データ位置がセットされる(分割された各項目へのポインタ)
// -----------------------------------------------------------------------------
int kgCSVkeyX::read() 
{
	if( end() ) return EOF;
	if(isEndOfBuf()){
		readCSVfile();
		for(size_t i=0; i<fldSize_; i++){ _newFld[i] -= queSize_; }
	}

	// newとoldを入れ換える(次にnewに新しい行の項目位置を代入)
	char **tmpFld=_newFld;
	      _newFld=_oldFld;
	      _oldFld= tmpFld;

	// ファイル終了時はnew行にダミーセット
	if(isEOF()){
		status_=KeyBreak;
		status_|=End;
		for(size_t i=0; i<fldSize_; i++){
			_newFld[i]=const_cast<char*>(""); // NULL;
		}
		return 1;
	}

	// 項目分割	
	try{
		curPnt_ = sepFldToken(_newFld, fldSize_, curPnt_, maxRecLen_) + 1;
	}catch(kgError& err){
		err.addMessage("[ " + fname_ + " ]");
		throw err;
	}
	recNo_++;

	// statusセット
	// 最初の行の読み込み時はBegin
	// 二行目以降の読み込み時はNormal or KeyBreak
	if( recNo_==1 ){ 
		status_=Begin;
	}else{               
		char *newKey;
		char *oldKey;
		status_=Normal;
		for(unsigned int i=0; i<_keyNum.size(); i++){
			newKey=getNewVal(_keyNum.at(i));
			oldKey=getOldVal(_keyNum.at(i));
			if( strcmp(newKey,oldKey)!=0 ){
				status_=KeyBreak;
				break;
			}
		}
	}
	return 1;
}

// ============================================================================
// kgCSVkey
// ============================================================================
// -----------------------------------------------------------------------------
// バッファ確保＆ヘッダ読み込み
// -----------------------------------------------------------------------------
void kgCSVkey::read_header(void) 
{
	if(!opened_) return;
	set_fields(maxRecLen_*2);
	if(isEOF()){
		status_=KeyBreak;
		status_|=End;
	}
	_newFld = NULL;
	_oldFld = NULL;

	_fld_ap.set( new char*[fldSize_] );
	_fld1_ap.set( new char*[fldSize_] );
	_fld = _fld_ap.get();
	_fld1 = _fld1_ap.get();
	for(size_t i=0; i<fldSize_; i++){
		_fld[i]=const_cast<char*>(""); 
		_fld1[i]=const_cast<char*>(""); 
	}
	_newFld   = _fld;
	_oldFld   = _fld1;
}
// -----------------------------------------------------------------------------
// 読み込み
//  _newFld,_oldFldに現在読込データ位置がセットされる(分割された各項目へのポインタ)
// -----------------------------------------------------------------------------
int kgCSVkey::read() 
{
	if( end() ) return EOF;
	if(isEndOfBuf()){
		readCSVfile();
		for(size_t i=0; i<fldSize_; i++){ _newFld[i] -= queSize_; }
	}

	// newとoldを入れ換える(次にnewに新しい行の項目位置を代入)
	char **tmpFld=_newFld;
	      _newFld=_oldFld;
	      _oldFld= tmpFld;

	// ファイル終了時はnew行にダミーセット
	if(isEOF()){
		status_=KeyBreak;
		status_|=End;
		for(size_t i=0; i<fldSize_; i++){
			_newFld[i]=const_cast<char*>(""); // NULL;
		}
		return 1;
	}

	// 項目分割	
	try{
		curPnt_ = sepFldToken(_newFld, fldSize_, curPnt_, maxRecLen_) + 1;
	}catch(kgError& err){
		err.addMessage("[ " + fname_ + " ]");
		throw err;
	}

	recNo_++;

	// statusセット
	// 最初の行の読み込み時はBegin
	// 二行目以降の読み込み時はNormal or KeyBreak
	if( recNo_==1 ){ 
		for(unsigned int i=0; i<_keyNum.size(); i++){
			if(*getNewVal(_keyNum.at(i))=='\0'){ _keynull=true; break;}
		}
		status_=Begin;
	}else{               
		char *newKey;
		char *oldKey;
		status_=Normal;
		for(unsigned int i=0; i<_keyNum.size(); i++){
			newKey=getNewVal(_keyNum.at(i));
			oldKey=getOldVal(_keyNum.at(i));
			if( strcmp(newKey,oldKey)!=0 ){
				if(*newKey=='\0'){ _keynull=true;}
				status_=KeyBreak;
				break;
			}
		}
	}
	return 1;
}
// ============================================================================
// kgCSVblk
// ============================================================================
// -----------------------------------------------------------------------------
// バッファ確保＆ヘッダ読み込み
//  kgCSVkeyのバッファ確保＆ヘッダ読み込み＋ kgCSVblk用のバッファを確保
// -----------------------------------------------------------------------------
void kgCSVblk::read_header(void) 
{
	kgCSVkey::read_header();
	if(!opened_) return;
	if(env_==NULL){
		_pageSize = KG_BlockCount;
	}else{
		_pageSize = env_->getBlockCount();
	}
	try {
		_fldbuf_ap.set( new kgFldBuffer(_pageSize,bufSize_+1,env_) );
		_blk_ap.set( new char*[fldSize_] );

	} catch(...) {
		throw kgError("memory allocation error on kgCSVblk");
	}
	_fldbuf = _fldbuf_ap.get();
	_blkFld = _blk_ap.get();
}

// -----------------------------------------------------------------------------
// バッファページサイズ変更(read_header使用前のみ利用可)
// -----------------------------------------------------------------------------
void kgCSVblk::setbufsize(size_t psize)
{ 
	if(_fldbuf!=0){ throw kgError("run setbufsize() after read_header()");}
	_pageSize=psize; 
}
// -----------------------------------------------------------------------------
// キーブレークまでのデータがセットされる
//	kgCSVblk::blkread()によって一行ずつ読み込みことができる
//	再読込前にデータ複製
// -----------------------------------------------------------------------------
int kgCSVblk::blkset() 
{
	// 初期設定
	_fldbuf->reset();
	if( end() ) return EOF;
	size_t s_rec=recNo_;
	_start = curPnt_;	
	if(recNo_==0)	{ s_rec = 1; }
	else					{ _start = curPnt_-recLen(); }

	while(1){
		// データ読込
		if(isEndOfBuf()){
			if( recNo_!=0 ){ _fldbuf->write(_start,curPnt_-_start-recLen()); }
			readCSVfile();
			for(size_t i=0; i<fldSize_; i++){ _newFld[i] -= queSize_; }
			_start = curPnt_-recLen();
		}

		// newとoldを入れ換える(次にnewに新しい行の項目位置を代入)
		char **tmpFld=_newFld;
		      _newFld=_oldFld;
	 		   	_oldFld= tmpFld;

		// ファイル終了時はnew行にダミーセット	
		if(isEOF()){
			status_=KeyBreak;
			status_|=End;
			for(size_t i=0; i<fldSize_; i++){
				_newFld[i]=const_cast<char*>(""); // NULL;
			}
			_end = curPnt_;
			_blkrec = recNo_ +1 - s_rec;
			break;
		}

		// 項目分割	
		try{
			curPnt_ = sepFldToken(_newFld, fldSize_, curPnt_, maxRecLen_) + 1;
		}catch(kgError& err){
			err.addMessage("[ " + fname_ + " ]");
			throw err;
		}

		recNo_++;

	// statusセット
	// 最初の行の読み込み時はBegin
	// 二行目以降の読み込み時はNormal or KeyBreak
		if( recNo_==1 ){ 
			status_=Begin;
			for(unsigned int i=0; i<_keyNum.size(); i++){
				if(*getNewVal(_keyNum.at(i))=='\0'){ _keynull=true; break;}
			}
		}else{               
			char *newKey;
			char *oldKey;
			status_=Normal;
			for(unsigned int i=0; i<_keyNum.size(); i++){
				newKey=getNewVal(_keyNum.at(i));
				oldKey=getOldVal(_keyNum.at(i));
				if( strcmp(newKey,oldKey)!=0 ){
					if(*newKey=='\0'){ _keynull=true;}
					status_=KeyBreak;
					break;
				}
			}
		}
		if(status_&KeyBreak){
			_end = curPnt_-recLen();
			_blkrec = recNo_ - s_rec;
			break;
		}
	}
	_pos = _start ; 
	return _blkrec;
}
// -----------------------------------------------------------------------------
// blkset()によってセットされたデータを１行ずつ読み込む
//  blkset()の際にsepFldTokenのよって項目分割されている
//  "\0"によってデータ分割されているので(','と'\n'が’\0’に置換えられる)
//  項目数分の"\0"までをよみこめばOK。
//  ただしデータにDQが存在していた時ように特殊処理をしている
//  データDQが存在していた場合sepFldTokenによって
//  "38669",38669,65,"7",50
//  38106,"""3""8106",32,4,50
//   ↓
//  "38669\0,38669\065\0"7\0,50\0
//  38106,""3"8106\0,",32\04\050\0
//  となっており,
//  開始のDQをそのままで終了DQは'\0'に置換えられる
//  (','と'\n'はそのまま残っているので読み飛ばす必要が有る)
//  さらにDQでかこまれた中にDQDQが有るとDQとして変換される 
//  そのため次に項目を読み込む際に減らしたDQ分読みとバス必要が有る
// -----------------------------------------------------------------------------
int kgCSVblk::blkread(void){

	if(_fldbuf->getFld(_blkFld,fldSize_)==EOF){
		if(_pos == _end) { return EOF;}
		if(*_pos =='"' && (_pos+1) == _end) { return EOF;}
		size_t i=0;
		bool DQflg=false;
		int DQcnt=0; 
		if(*_pos=='"'){ _pos++; DQflg=true;}

		for(char *p=_pos; p<_end && i<fldSize_ ;p++){
			if(*p=='"'){DQcnt++;}
			if(!*p){
				_blkFld[i]=_pos; 
				if(DQflg){
					if(p<_end){ p=p+1+DQcnt; }
					DQflg=false;
				}
				if(p<_end && *(p+1)=='"'&& i+1!=fldSize_){ 
					//最終項目以外次回読み込み位置セット
					DQflg=true;
					p++; 
				}
				_pos=p+1; 
				DQcnt=0;
				i++;
			}
		}
		if(i<fldSize_){ fldCntErr(fldSize_,i);}
	}
	else {
		int DQcnt=0; 

		for (size_t i=0;i<fldSize_;i++){
			char *p = _blkFld[i]+DQcnt;
			_blkFld[i] =p;
			DQcnt =0;
			if(*p=='"'){ _blkFld[i]++; p++; DQcnt++; }
			while(*p){
				if(*p=='"'){DQcnt++;}
				p++;
			}
		}
	}
	return 1;
}
// -----------------------------------------------------------------------------
// ブロック先頭SEEK
// -----------------------------------------------------------------------------
int kgCSVblk::seekBlkTop(void){
	_pos = _start;
	return _fldbuf->seekRTop();	
}

