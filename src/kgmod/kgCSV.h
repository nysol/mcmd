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
// kgCSV.h KGMODで用いられる入力CSVクラス
// =============================================================================
#pragma once
#include <sys/types.h>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cerrno>
#include <kgEnv.h>
#include <kgError.h>
#include <kgFldBuffer.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;

namespace kglib  ////////////////////////////////////////////// start namespace
{

// 入力バッファの構造体
// CSVの一行がメモリの連続領域にあることを保証したファイルバッファ
//
// バッファの全体像
//   buf_ -----+------------+-----------+
//             |            |           |
//             | _dupSize   |           |
//             |            |           |
//             +------------+-----+     |
//            0| ioSize_    |     |     |
//             +------------+     | bufSize_
//            1|            |     |     |
//             +------------+ queSize_  |
//            :|            |     |     |
//            :|            |     |     |
//            :|            |     |     |
//            :|            |     |     |
//             +------------+     |     |
//  readCnt_-1 |            |     |     |
//             +------------+-----+-----+
// bufSize_ = _dupSize + queSize_
// queSize_ = ioSize_ * readCount_
// _dupSize :
//     一行がメモリの連続領域にあることを保証するための緩衝領域。
//     curPnt_がbufの後ろのborder_を超えたら，後ろのdupSizeの領域を
//     先頭(buf_)にコピーする. 
//     CSVrec,CSVfldでは_maxRecLenに等しく，CSVkeyでは_maxRecLen*2
// _ioSize  : FP.readにて一回に読み込むサイズ
// _reqdCnt : 何回readするか。この回数でキューの大きさが決まる。
// _maxRecLen : 最大レコードサイズ : ユーザにより与えられる。
//             (kgConfig.h or 環境変数のKG_MaxRecLen)
// 制約事項 :
//   1) pipeのバッファサイズ = ioSize_ * n (nは1以上の整数)
//   2) _maxRecLen = ioSize_ * n (nは1以上の整数)
//   3) _dupSize <= queSize_
// 
class kgCSV 
{
public:
	enum Status {
		Begin    = 1,  // kgCSVkey: 二行目を読み込む前までON
		               // その他  : 最初の一行目を読み込んむ前のみBeginフラグはON
		KeyBreak = 2,  // kgCSVkeyのみ有効．キーブレーク読み込み時にON
		End      = 4,  // EOFを読み込もうとした時にONとなる
		Normal   = 8   // 通常行の読み込み時にON
	};

protected:
	kgEnv*           env_;         // 環境変数クラスへのポインタ
	int              fd_;          // ファイルディスクリプト
	bool             opened_;      // オープンしたかどうか
	string           fname_;       // ファイル名へのポインタ(標準入力は/dev/stdin)
	
	// バッファのアドレスやサイズ関連
	kgAutoPtr2<char> ap_;          // 入力バッファをラッピングするsmart pointer
	char*            buf_;         // バッファデータ本体
	size_t           maxRecLen_;   // 1行の最大長(環境変数より)
	size_t           queSize_;     // 1つのqueueの大きさ(環境変数より)
	size_t           ioSize_;      // 実際にreadするサイズ
	size_t           ioCnt_;       // 実際にreadする回数
	char*            border_;      // 次que読み込みポインタ
	char*            dupTop_;      // スラック領域へコピーする先頭アドレス
	size_t           dupSize_;     // スラック領域へコピーするサイズ
	size_t           bufSize_;     // スラック領域へコピーするサイズ
	char*            curPnt_;      // 現在の読み込みポインタ

	// 項目名関連
	bool             noFldName_;   // １行目が項目名行でないフラグ
	vector<kgstr_t>  fldName_;     // 項目名
	vector<kgstr_t>  fldNameOrg_;  // 項目名org
	vector<SortInfo> fldSInfo_;    // 項目sorting情報 csv_numeber=> info
	map<kgstr_t,int> fldNum_;      // 項目名->num用
	size_t           fldSize_;     // 登録項目数
	size_t           fldByteSize_; // 項目行のbyteサイズ

	// 実行時変数
	int              status_;      // 読み込み状態
	size_t           recNo_;       // 現在読み込み中の行番号

	void setSortInfo(const kgstr_t& fileName);

	void initialSet(const kgstr_t& fileName, kgEnv* env, bool noFldName,size_t cnt=4)throw(kgError);

public:
	// コンストラクタ,デストラクタ
	kgCSV(void) : opened_(false),recNo_(0){}
	virtual ~kgCSV(void){close();};

	// ファイル操作
	void open(const kgstr_t& fname, kgEnv* env, bool noFldName, size_t readCnt=4) throw(kgError);
	void popen(int fd, kgEnv* env, bool noFldName, size_t readCnt=4) throw(kgError);
	void clear(void);

	virtual int read(void)=0;
	virtual void   read_header(void)=0;
	void seekTop(void) throw(kgError);
	void close(void) throw(kgError);

	// アクセッサ
	kgstr_t fileName(void) const				{ return fname_;}
	size_t fldSize(void)	const 				{ return fldSize_; }
	bool opened(void)			const 				{ return opened_; }
	bool noFldName(void)	const 				{ return noFldName_; }
	size_t recNo(void)		const 				{ return recNo_; }
	int fd(void)					const					{ return fd_;}
	size_t bufSize(void) 					const	{ return bufSize_;} 
	vector<kgstr_t> fldName(void) const {return fldName_;}
	vector<kgstr_t> orgName(void) const {return fldNameOrg_;}

	// ステータスの判定
	char status()					const { return status_;}
	bool end()    				const	{ return status_ & End  ;}
	bool begin()  				const	{ return status_ & Begin;}
	bool keybreak() 			const	{ return status_ & KeyBreak;}
	bool isEOF(void) 			const	{ return (*curPnt_=='\0'); }
	bool isEndOfBuf(void) const	{ return curPnt_ >= border_; }
	bool isStdin(void) 		const { return fname_=="/dev/stdin";}
	bool isFifo(void) const;
	
  // 項目名関連（項目名<->項目番号）
	kgstr_t fldName(const size_t,bool org=false) const throw(kgError);
	int fldNum(const kgstr_t& str,bool rtn=false) const throw(kgError);
	
	// データコピー（ruby mtable 専用）
	size_t bufCpy(char* to, bool toEnd) const;
	// sortが必要であればtrue
	bool sortFldchk(vector<int>& fld);
	bool sortFldchk(vector<kgstr_t>& fld,bool fldbynum);
	// sortの何番目のkeyかを取得
	int sortNumber(size_t pos){	
		if(pos<fldSInfo_.size()){
			return fldSInfo_.at(pos)._pos;
		}
		return -1;
	}

	kgstr_t sortParaStr(size_t pos){
		kgstr_t rtn;
		int snum = sortNumber(pos);
		if(snum<0){ return rtn;}
		rtn = "%";
		rtn.append(toString(sortNumber(pos)));
		switch(fldSInfo_.at(pos)._type){
			case SortInfo::CharSort:
				return rtn;
			case SortInfo::NumSort :
				return rtn.append("n");
			case SortInfo::CharSortR:
				return rtn.append("r");
			case SortInfo::NumSortR:
				return rtn.append("nr");
		}
		return rtn;
	}

protected:
	void set_fields(size_t cpSize);
	void readCSVfile(void) throw(kgError);
};
// ==============================================================================
// 継承クラス関連 
// kgCSVrec, 
//   一行単位での読み込み
//   一行ごとに読み込む。項目のトークン分割は行わないので高速である。
// kgCSVfld
//   一行項目単位の読み込み
//   一行ごとに読み込み、項目もトークン分割される。
// kgCSVkey
//   二行項目単位の読み込み
//     常にデータ行を二行キープしながら読み込む。キーブレーク処理に便利。
// ==============================================================================
//------------------------------------------------------------------------------
// 行単位読み込みバッファ
//------------------------------------------------------------------------------
class kgCSVrec : public kgCSV 
{
	char* _rec; 
public:
	kgCSVrec(void){};
	~kgCSVrec(void){};

	// 読込関連
	void  read_header(void);
	int   read(void);

	// データ取得関連
	char* getRec(void)	const	{ return _rec;}
	size_t recLen(void) const { return curPnt_ - _rec;} 
}; 	
//------------------------------------------------------------------------------
// TAB用行単位読み込みバッファ
//------------------------------------------------------------------------------
class kgCSVrecSimple : public kgCSV 
{
	char* _rec; 
public:
	kgCSVrecSimple(void){};
	~kgCSVrecSimple(void){};

	// 読込関連
	void  read_header(void);
	int   read(void);

	// データ取得関連
	char* getRec(void)	const	{ return _rec;}
	size_t recLen(void) const { return curPnt_ - _rec;} 
}; 	

//------------------------------------------------------------------------------
// キーブレーク読み込みバッファ
//------------------------------------------------------------------------------
class kgCSVkeyX : public kgCSV {
protected:
	kgAutoPtr2<char*> _fld0_ap;
	kgAutoPtr2<char*> _fld1_ap;
	char** _fld0;              // 各行各項目へのポインタ(old行 or new行)
	char** _fld1;              // 各行各項目へのポインタ(old行 or new行)
	char** _newFld;            // new行格納先へのポインタ
	char** _oldFld;            // old行格納先へのポインタ
	vector<int> _keyNum;
public:
	 kgCSVkeyX(void){}
	~kgCSVkeyX(void){};

	// キーセット
	void   setKey(vector<int> keyNum){ _keyNum = keyNum; }

	// 読込関連
	void   read_header(void);
	int    read(void);

	// データ取得関連
	char*  getNewVal(int no) const { return *(_newFld+no);}
	char*  getOldVal(int no) const { return *(_oldFld+no);}
	char** getNewFld(void)	 const { return   _newFld;}
	char** getOldFld(void)	 const { return   _oldFld;}
	size_t recLen(void) 		 const { return curPnt_ - *_newFld;}
	const vector<int>* getKey(void) const {return &_keyNum;}
};
//------------------------------------------------------------------------------
// 行-項目単位読み込みバッファ
//------------------------------------------------------------------------------
class kgCSVfld : public kgCSV 
{
	friend void csvFldCopy(kgCSVfld* from ,kgCSVfld* to){
		to->env_				 = from->env_;
		to->fd_					 = from->fd_;
		to->opened_			 = from->opened_;
		to->fname_			 = from->fname_;
		to->maxRecLen_	 = from->maxRecLen_;
		to->queSize_		 = from->queSize_;
		to->ioSize_			 = from->ioSize_;
		to->ioCnt_			 = from->ioCnt_;
		to->dupSize_		 = from->dupSize_;
		to->bufSize_		 = from->bufSize_;

		to->fldNameOrg_	 = from->fldNameOrg_;
		to->fldSInfo_		 = from->fldSInfo_;


		to->noFldName_	 = from->noFldName_;
		to->fldName_		 = from->fldName_;
		to->fldNum_			 = from->fldNum_;
		to->fldSize_		 = from->fldSize_;
		to->fldByteSize_ = from->fldByteSize_;
		to->status_			 = from->status_;
		to->recNo_			 = from->recNo_;
		try {
			to->ap_.set( new char[to->bufSize_+1] );
		} catch(...) {
			throw kgError("memory allocation error on CSVin");
		}
		to->buf_ = to->ap_.get();
		to->border_ = to->buf_ + (from->border_ - from->buf_) ;
		to->dupTop_ = to->buf_ + (from->dupTop_ - from->buf_) ;
		to->curPnt_ = to->buf_ + (from->curPnt_ - from->buf_) ;
		memcpy(to->buf_, from->buf_ , from->bufSize_ + 1    );
		to->_fld_ap.set( new char*[to->fldSize_] );
		to->_fld    = to->_fld_ap.get();
	}
protected:
	kgAutoPtr2<char*> _fld_ap;
	char** _fld;   
public:

	void replaceSet(kgCSVfld *csv, kgEnv* env, bool noFldName,size_t cnt=4);

	 kgCSVfld(void){}
	~kgCSVfld(void){};

	// 読込関連
	void   read_header(void);
	int    read(void);
	int    read_limit(void);

	// データ取得関連
	virtual char*  getVal(int no) const { return *(_fld+no);}
	virtual char** getFld(void)	 	const { return _fld;}
	size_t recLen(void)		const { return curPnt_ - *_fld;}
	bool isNull(vector<int>& fldNo){
		for(size_t i=0;i<fldNo.size();i++){
			if(fldNo.at(i)==-1){ continue;}
			if(*_fld[fldNo.at(i)]=='\0'){return true; }
		}
		return false;
	}

};
//------------------------------------------------------------------------------
// 行-項目単位読み込みバッファKEy2
//------------------------------------------------------------------------------
class kgCSVkey : public kgCSVfld 
{
protected:
	kgAutoPtr2<char*> _fld1_ap;
	char** _fld1;
	char** _newFld;            // new行格納先へのポインタ
	char** _oldFld;            // old行格納先へのポインタ
	vector<int> _keyNum;
	bool _keynull;
public:
	 kgCSVkey(void){}
	~kgCSVkey(void){};

	// キーセット
	void   setKey(vector<int> keyNum){ _keyNum = keyNum; }

	// 読込関連
	void   read_header(void);
	int    read(void);
	bool   keynull(void){ return _keynull;}
	int    read_limit(void);

	// データ取得関連
	char*  getVal(int no) const { return *(_newFld+no);}
	char** getFld(void)	 	const { return _newFld;}

	char*  getNewVal(int no) const { return *(_newFld+no);}
	char*  getOldVal(int no) const { return *(_oldFld+no);}
	char** getNewFld(void)	 const { return   _newFld;}
	char** getOldFld(void)	 const { return   _oldFld;}
	size_t recLen(void) 		 const { return curPnt_ - *_newFld;}
	const vector<int>* getKey(void) const {return &_keyNum;}

	bool isNull(vector<int>& fldNo,bool old=true){
		for(size_t i=0;i<fldNo.size();i++){
			if(fldNo.at(i)==-1){ continue;}
			if(old) { if(*_oldFld[fldNo.at(i)]=='\0'){return true; } }
			else    { if(*_newFld[fldNo.at(i)]=='\0'){return true; } }
		}
		return false;
	}

};


//------------------------------------------------------------------------------
// BLOCK読み込みバッファ付きkgCSVkey
//------------------------------------------------------------------------------
// 最終的にBLOCK読み込むすると
// +------------+ 
// |            | kgfldBuffer  -+- メモリバッファ
// |            |               +- ファイルバッファ
// +------------+
// |            | kgCSVのメモリバッファ
// +-------------
// で一つのBLOCKとなる
//
class kgCSVblk : public kgCSVkey 
{
	kgAutoPtr1<kgFldBuffer> _fldbuf_ap;
	kgAutoPtr2<char*> _blk_ap;
	size_t _pageSize;					
	kgFldBuffer *_fldbuf;

	char** _blkFld;
	char* _start; //kgCSV上のバッファ開始位置
	char* _end; 	//kgCSV上のバッファ終了位置
	char* _pos; 	//kgCSV上のバッファ終了位置
	size_t _blkrec;					 //ブロックの行数

public:
	 kgCSVblk(): _fldbuf(0),_blkrec(0){ }
	~kgCSVblk(void){}

	//バッファサイズ設定
	void setbufsize(size_t psize);

	// 読込関連
	void   read_header(void);	
	int blkset(void);
	int blkread(void);
	int seekBlkTop(void);

	// データ取得関連
	char* getBlkVal(int no)	 const { return *(_blkFld+no);}
	char** getBlkFld(void)	 const { return _blkFld;}
	size_t blkrecNo(void)		 const { return _blkrec;}

	bool isNull(vector<int>& fldNo){
		for(size_t i=0;i<fldNo.size();i++){
			if(fldNo.at(i)==-1){ continue;}
			if(*_blkFld[fldNo.at(i)]=='\0'){return true; }
		}
		return false;
	}
};
} //////////////////////////////////////////////////////////////// end namespace
