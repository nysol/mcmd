#pragma once

#include <string>
#include <vector>
#include <kgConfig.h>
#include <kgEnv.h>
#include <kgmod.h>
#include <kgError.h>
#include <kgArgs.h>
#include <signal.h>
#include <kgTempfile.h>
using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgFifo : public kgMod {

	// 引数
	string _iName;   // i=
	string _oName;   // i=
	size_t _queSize; // n=

	pthread_t _thr_read;
	pthread_t _thr_write;
	
	int _iFD;					//i=ファイルディスクリプタ
	int _oFD; //o=ファイルディスクリプタ

	void setArgs(void);

	int runMain(void);

	void iClose(void) throw(kgError);
	void oClose(void) throw(kgError);

public:
	// コンストラクタ
	kgFifo(void);
	~kgFifo(void){}

	// 入出力ファイルオープン
	int run(void);

	void rw_cancel(void);
};
	

}
