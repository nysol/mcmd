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
// kgCSVout.h KGMODで用いられる入力CSVクラス
// =============================================================================
#pragma once
#include <iostream>
#include <kgConfig.h>
#include <kgError.h>
#include <kgEnv.h>
#include <kgCSV.h>
#include <kgArgFld.h>
#include <kgVal.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#define LIMIT_OUT 2
using namespace std;

namespace kglib  ////////////////////////////////////////////// start namespace
{
// 出力ファイルclass
// 入力バッファの構造体
// CSVの一行がメモリの連続領域にあることを保証したファイルバッファ
//
// バッファの全体像
//   _buf -----+------------+-----+-----+
//            0| ioSize_    |     |     |
//             +------------+     | _bufSize
//            1|            |     |     |
//             +------------+ queSize_  |
//            :|            |     |     |
//            :|            |     |     |
//            :|            |     |     |
//            :|            |     |     |
//             +------------+     |     |
//    ioCnt_-1 |            |     |     |
//             +------------+-----+     |
//             |            |           |
//             | _dupSize   |           |
//             |            |           |
//             +------------+-----+-----+
// _bufSize = _dupSize + _queSize
// _queSize = ioSize_ * writeCount_
// _dupSize :
//     書き出し緩衝領域
//     ファイルへの実writeは常に_bufからqueSize_バイトだけ出力される。
//     一方でkgWrite系関数ではqueSize以上をメモリに書き出す(超えた時にflushされる).
//     flush後に超過分を先頭(_buf)にコピーする. 
//     現在は_maxRecLenに等しい
// _writeSize  : FP.writeにて一回に書き込むサイズ
// _writeCnt : 何回writeするか。この回数でキューの大きさが決まる。
// _maxRecLen : 最大レコードサイズ : ユーザにより与えられる。
//             (kgConfig.h or 環境変数のKG_MaxRecLen)
// 制約事項 :
//   1) pipeのバッファサイズ = ioSize_ * n (nは1以上の整数)
//   2) _maxRecLen = ioSize_ * n (nは1以上の整数)
//   3) _dupSize <= _queSize
//   4) ioSize_ = readSize_(kgCSV.hより)
class kgCSVout 
{
private:
	kgEnv*           env_;           // 環境変数クラスへのポインタ
	int fd_;
	kgstr_t   fname_; // ファイル名へのポインタ(標準入力はempty)
	bool      opened_; // オープンしたかどうか

	kgAutoPtr2<char> _buf_ap;    // 出力バッファbufをラッピングするsmart pointer
	char*            _buf;       // 出力バッファ
	size_t           _maxRecLen; // レコード最大長(環境変数からセットされる)
	size_t           queSize_;       // 1つのqueueの大きさ(環境変数より)
	size_t           ioSize_;      // write関数で一回に書き込むサイズ
	size_t           ioCnt_;       // その回数

	bool             _noFldName; // １行目が項目名行でないフラグ
	char             _dblFmt[256]; // double型出力フォーマット
	bool 						 _rp;        // remove %
	char*            _curPnt;    // 現在の書き込み位置
	char*            _border;    // buf配列の境界アドレス(ここを越えるとflash)
	char*            _end;       // buf配列の最終アドレス(ここを越えるとerror)
	size_t           _recNo;     // 現在書き込み中の行番号

	size_t           dupSize_;   // スラック領域へコピーするサイズ
	size_t           bufSize_;   // スラック領域へコピーするサイズ

public:
	// コンストラクタ
	kgCSVout() : opened_(false),_recNo(0){}
	kgCSVout(kgstr_t fileName, kgEnv *env=NULL, bool noFldName=false);

	// デストラクタ 
	~kgCSVout(){ close();}
	
	// ファイルのオープンとクローズ
	void initialset(kgEnv *env, bool noFldName, size_t cnt,bool rp) throw(kgError);
	void open(kgstr_t fileName, kgEnv *env=NULL, bool noFldName=false, bool rp=false, size_t cnt=4) throw(kgError);
	void aopen(kgstr_t fileName, kgEnv *env=NULL, bool noFldName=false,bool rp=false, size_t cnt=4) throw(kgError);
	void popen(int fd, kgEnv *env=NULL, bool noFldName=false, bool rp=false, size_t cnt=4) throw(kgError);


	void close(void) throw(kgError);
	void forceclose(void);
	// 有効桁数セット
	void    setPrecision(int precision);

	// accessor
	bool    noFldName(void)	const {return _noFldName;}
	bool    isOpend(void)		const {return opened_;}
	size_t  recNo(void)			const {return _recNo;}

	// bufferの強制出力
	void flush();

	// --------------------
	// データ型別の出力関数群
	// (第２引数が有るのは区切り文字出力あり true:改行、false:コンマ)
	// --------------------
	void writeStrNdq(const char *str, bool eol);
	void writeStrNdq(const char *str);
	void writeStrForJson(const char *str);
	void writeStr(const char *str, bool eol);
	void writeStr(const char *str);
	void writeDbl(double val, bool eol);
	void writeDbl(double val);
	void writeInt(int val, bool eol);
	void writeInt(int val);
	void writeLong(long val, bool eol);
	void writeLong(long val);
	void writeSizeT(size_t val, bool eol);
	void writeSizeT(size_t val);
	void writeBool(bool val, const bool eol);
	void writeBool(bool val);
	void writeDate(const boost::gregorian::date& val, const bool eol);
	void writeDate(const boost::gregorian::date& val);
	void writeTime(const boost::posix_time::ptime& val, const bool eol);
//	void writeUtime(const boost::posix_time::ptime& val, const bool eol);
	void writeTime(const boost::posix_time::ptime& val);
//	void writeUtime(const boost::posix_time::ptime& val);

	void writeVal(const kgVal& val, bool eol);
	void writeVal(const kgVal& val);
	
	// --------------------
	// 一行出力
	// --------------------
	// csv一行を出力する(項目の解釈(DQなど)なし)．
	void writeRec(char* rec);
	// csv一行+数値(mrandで使用)
	void writeRec(char* rec,int val);

	// --------------------
	//  項目値の出力関数群
	// --------------------
	// csv項目を出力する．
	// 使用= 汎用
	void writeFld(size_t size, char** flds, bool eol=true);

	// flgが-1の項目はfldの文字列を出力し，それ以外は対応するvalを出力
	// 使用= sum, argv
	void writeFld(char** fld, const vector<int>* flg, vector<kgVal>& val);

	// 使用= chgstr, chgnum
	void writeFld(char** fld, const vector<int>* flg, char** val);

	//joinでアウタージョイン(-Nの場合に使用)マスタにあってトラにない場合
	// flgが-1のものはNULL出力し、それ以外はvalから項目番号割り出しを出力
	// 使用= join, njoin, nrjoin, rjoin
	void writeFld(const vector<int>* flg,const vector<int>* num,char** fld , const vector<int   >* addcnt);

	// 使用= number, newnumber, rand
	void writeFld(char** fld ,size_t size ,int val,bool alpha_flg);

	// 使用= count,
	void writeFld(char** fld ,size_t size ,size_t val);

	// 使用= cat, cut
	void writeFld(char** fld ,const vector<int>* cnt,bool eol=true);

	// 使用= join, nrjoin, rjoin
	void writeFld(char** fld,size_t size, char** addfld , const vector<int   >* addcnt);

	// 使用= chgstr, chgnum, nrjoin
	void writeFld(char** fld,size_t size, char** addfld ,int addsize);

	// 使用= setstr, sed
	void writeFld(char** fld,size_t size, vector<string> *newFld);

	// int -> アルファベット出力
	// 使用 = kgcm
	void writeInt2alpha(int val);

	// --------------------
	//  項目名の出力関数群
	// --------------------
	//同じものがないことを確認してから出力する
	void writeFldNameCHK(vector<kgstr_t>& outfld ) throw(kgError);

	// csv項目名を出力する．
	// 使用= 汎用
	void writeFldName(kgCSV& csv,bool org=true) throw(kgError);

	// csv項目名を出力する．FLGを追加して出力
	// 使用= 汎用
	void writeFldName(kgArgFld& fld,kgstr_t addstr) throw(kgError);


	// csv項目名を出力する． (利用mod: kgsum)
	//   ex1. CSV a,b,c : f=a:A,c : a,b,c
	// ただし，second=tureの場合，fldに指定された項目のみattr名に変えて出力
	//   ex1. CSV a,b,c : f=a:A,c : A,b,c
	// 使用= 汎用
	void writeFldName(kgArgFld& fld, bool second,bool org=true) throw(kgError);

	// csv項目+fld項目を出力．or fld項目+csv項目 (利用mod: kgjoin or mwindow)
	//   ex. CSV a,b,c  fld x,y : a,b,c,x,y
	// ただし，second=tureの場合，fldに指定された項目はattr名に変えて出力
	//   ex. CSV a,b,c  fld x:X,y:Y : a,b,c,X,Y
	// 使用= 汎用
	void writeFldName(kgCSV& csv,kgArgFld& fld,bool second,bool back=true) throw(kgError);

	// csv項目+newFldを出力
	// 使用= rand, cal, count, number
	void writeFldName(kgCSV& csv, kgstr_t newFld) throw(kgError);

	// csv項目+newFld(vector)を出力
	// 使用= combi, setstr
	void writeFldName(kgCSV& csv, vector<kgstr_t> newFld) throw(kgError);

	// 新規項目の項目名を出力
	// 使用= newrand, newstr, newnumber
	void writeFldName(kgstr_t newFld) throw(kgError);

	// 新規項目の項目名(複数)を出力
	// 使用= cat、chkcsv、fldname, sep2, cm
	void writeFldName(vector<kgstr_t> newFld) throw(kgError);

	//区切り文字出力(コンマ、改行、改行[出力行数カウント有り])
	void writeDlm(void){ *_curPnt++ = ','; }
	void writeEolNC(void){ *_curPnt++ = '\n'; }
	void writeEol(void){
		_recNo++;
		//if(_recNo>LIMIT_OUT){
		//	throw kgError("limit line over");
		//}
		*_curPnt++ = '\n';
	}

};


} //////////////////////////////////////////////////////////////// end namespace

