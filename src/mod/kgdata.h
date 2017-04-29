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
// msample.h : sampleの表示用データ
// ============================================================================
#include <vector>
#include <kgConfig.h>
#include <kgmod.h>

#include "dat/iris_dat.h"
#include "dat/abalone_dat.h"

#include "dat/man0.h"
#include "dat/man1.h"

#include "dat/yakiniku_en.h"
#include "dat/yakiniku_jp.h"

#include "dat/tutorial_jp_dat.h"
#include "dat/tutorial_jp_cust.h"
#include "dat/tutorial_jp_syo.h"
#include "dat/tutorial_jp_jicfs1.h"
#include "dat/tutorial_jp_jicfs2.h"
#include "dat/tutorial_jp_jicfs4.h"
#include "dat/tutorial_jp_jicfs6.h"

#include "dat/tutorial_en_dat.h"
#include "dat/tutorial_en_cust.h"
#include "dat/tutorial_en_syo.h"
#include "dat/tutorial_en_jicfs1.h"
#include "dat/tutorial_en_jicfs2.h"
#include "dat/tutorial_en_jicfs4.h"
#include "dat/tutorial_en_jicfs6.h"

const char * helpMsg_ =
"1) mdata iris : output iris dataset to STDOUT\n\
2) mdata tutorial_jp : output all files used in Japanese tutorial\n\
2.1) mdata tutorial_jp/dat|cust|syo|jicfs1|jicfs2|jicfs4|jicfs6 : output each data used in Japanese tutorial to STDOUT\n\
3) mdata tutorial_en : output all files used in English tutorial\n\
3.1) mdata tutorial_en/dat|cust|syo|jicfs1|jicfs2|jicfs4|jicfs6 : output each data used in English tutorial to STDOUT\n\
";

// sampleデータ
const char* dsample_[][3]={

//追加する場合は以下に",{grpname,name,data}"で追加する
{"iris","",iris_dat},
{"abalone","",abalon_dat},

{"man0","",man0},
{"man1","",man1},

{"yakiniku_jp","",yakiniku_jp},
{"yakiniku_en","",yakiniku_en},

{"tutorial_jp","dat"   ,tutorial_jp_dat   },
{"tutorial_jp","cust"  ,tutorial_jp_cust  },
{"tutorial_jp","syo"   ,tutorial_jp_syo   },
{"tutorial_jp","jicfs1",tutorial_jp_jicfs1},
{"tutorial_jp","jicfs2",tutorial_jp_jicfs2},
{"tutorial_jp","jicfs4",tutorial_jp_jicfs4},
{"tutorial_jp","jicfs6",tutorial_jp_jicfs6},

{"tutorial_en","dat"   ,tutorial_en_dat   },
{"tutorial_en","cust"  ,tutorial_en_cust  },
{"tutorial_en","syo"   ,tutorial_en_syo   },
{"tutorial_en","jicfs1",tutorial_en_jicfs1},
{"tutorial_en","jicfs2",tutorial_en_jicfs2},
{"tutorial_en","jicfs4",tutorial_en_jicfs4},
{"tutorial_en","jicfs6",tutorial_en_jicfs6},

//ここ以下に追加しない
{"",""}
};


using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgData:public kgMod 
{
	bool _dic;
	vector<string> _vals;
	string _val;
	string _outinfo;
	
	void setArgs(void);
	void output_file(void);
	void output_dic(void);

public:
	// コンストラクタ
	kgData(void);
	~kgData(void){}
	void init(size_t argc, const char* argv[], kgEnv* env);
	//実行メソッド
	int run(void);

};

}



