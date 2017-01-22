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
#include <kgItermios.h>
using namespace std;
using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgMseldsp : public kgMod
{
	#define MAX_SELCNT 256

	int _x_val;
	int _y_val;
	int _height;
	int _width;

	kgstr_t _f_str; // f=
	kgCSVout _oFile;  // o=
	kgstr_t _str_s; //seldata=
	kgstr_t _i_s;		// i=
	vector<bool> _outinfo;
	// 引数セット
	void setArgs(void);
	void sellist(kgTermiosEX* sc,char** selp,int st,int pos);
public:
	// コンストラクタ
	kgMseldsp(void);
	~kgMseldsp(void){}
	//実行メソッド
	int run(void);


};
}
