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
#include <kgmod.h>
#include <kgCSVout.h>
using namespace std;
using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgMinput : public kgMod
{
	#define MAX_ITMCNT 512
	#define MAX_LINESIZE 4096

	vector<kgstr_t> _f_str; // f=
	kgCSVout _oFile;  // o=
	kgstr_t _i_s;		// i=
	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ
	kgMinput(void);
	~kgMinput(void){}
	//実行メソッド
	int run(void);


};
}


