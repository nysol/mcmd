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

class kg2Tee : public kgMod {

	// 引数
	kgstr_t         _iName;
	vector<kgstr_t> _oName;
	int         _iFD;
	vector<int> _oFD;
	vector<bool> _endFlg;
	kgAutoPtr2<char> _buf_ap;
	char* _buf;


	void setArgs(void);

	int runMain(void);

public:
  // コンストラクタ
	kg2Tee(void);
	~kg2Tee(void){}

	int run(void);

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return -1; }
	size_t oRecNo(void) const { return -1; }

	void runErrEnd(void){
		::close(_iFD);
		for(size_t i=0 ; i<_oFD.size();i++){
			if(!_endFlg[i]){
				::close(_oFD[i]);
			}
		}
	}


};

}
