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
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <kgConfig.h>
#include <kgEnv.h>
#include <kgmod.h>
#include <kgError.h>
#include <kgArgs.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <fcntl.h>
using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace
class kgTeeIFP{
	int type_;       // 1:file, 2:stdin, 3:socket, 4:pipe
	ifstream  file_; // ファイル
	istream*  stdi_; // 標準入力

	string    fname_; // ファイル名へのポインタ(標準入力はempty)
	bool      opened_; // オープンしたかどうか
	int   rsize_; // 読み込みサイズ
	bool   eof_; //EOF
	kgEnv*    env_;

public:
	 kgTeeIFP(void) : type_(0), stdi_(0), opened_(false) {rsize_=0; eof_=false; }
	~kgTeeIFP(void){}

	bool opened(void){return opened_;}
	int gcount(void){return rsize_;}
	bool eof(void){return eof_;}
	const char* fname(void);
	void open(kgstr_t fname, kgEnv* env) throw(kgError) ;
	void read(char* buf, int size) throw(kgError) ;
	void close(void) throw(kgError) ;

	int type(void) const {return type_;}
};



class kgOFP {
	int type_;       // 1:file, 2:stdout, 3:socket, 4:pipe

	int fd_;
	ostream*  stdo_; // 標準入力

	kgstr_t   fname_; // ファイル名へのポインタ(標準入力はempty)
	bool      opened_; // オープンしたかどうか
	kgEnv*    env_;

public:
	 kgOFP(void) {clear();}
	~kgOFP(void){}

	bool opened(void){return opened_;}
	const char* fname(void);
	void open(kgstr_t fn, size_t queSize, kgEnv* env) throw(kgError);
	size_t write(char* buf, int size) throw(kgError) ;
	void clear(void);
	void close(void) throw(kgError) ;

	int type(void) const {return type_;}
};




class kgTee : public kgMod {

	// 引数
	kgTeeIFP        _iFile;   // i=
	vector<kgstr_t> _ofNames; // o=
	bool            _nostdout; // -nostdout

	bool            _ifin; // -nostdout

	kgAutoPtr2<kgOFP> ap_;
	kgOFP*  csvOut_;   // i=
	
	ofstream otmpfile_;
	int                  size_;
	volatile size_t incnt_;

	size_t _oRecCnt;

	void setArgs(void);
public:
  // コンストラクタ
	kgTee(void);
	~kgTee(void){}

	// 実行
	void open(void);
	void close(void);
	int run(void);
	void tee_write(kgstr_t  ifname,int no);
	void tee_read();

	static void* tee_writeTH(void *obj);
	static void* tee_readTH(void *obj);


	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return 0; }
	size_t oRecNo(void) const { return _oRecCnt; }

};

struct teeR_ST {
	kgTee *mobj;
	kgstr_t otmpname;
	int i;
};

}
