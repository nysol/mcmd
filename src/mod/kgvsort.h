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
// kgvsort.h ベクトル要素の並べ替えクラス
// =============================================================================
#pragma once
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>


using namespace kglib;
namespace kgvsort_local {//////////////////////////////////////////////////

	// 文字列昇順
	inline int cmpStrAsc(unsigned char* a, unsigned char* b)
	{
		while(true){
		       if(*a < *b) return  1;
			else if(*a > *b) return -1;
			if(*a=='\0') break; // *a==*b=='\0'
			a++;b++;
		}
		return 0;
	}
	// 文字列降順
	inline int cmpStrDec(unsigned char* a, unsigned char* b)
	{
		while(true){
		       if(*a < *b) return -1;
			else if(*a > *b) return  1;
			if(*a=='\0') break; // *a==*b=='\0'
			a++;b++;
		}
		return 0;
	}
	// 数値昇順
	inline int cmpNumAsc(char* a, char* b)
	{
		if(*a=='\0'){
			if(*b=='\0') return 0;
			else         return 1;
		}else{
			if(*b=='\0') return -1;
			double fa=atof(a);
			double fb=atof(b);
		       if(fa < fb) return  1;
			else if(fa > fb) return -1;
			else             return  0;
		}
		return 0;
	}
	// 数値降順
	inline int cmpNumDec(char* a, char* b)
	{
		if(*a=='\0'){
			if(*b=='\0') return 0;
			else         return -1;
		}else{
			if(*b=='\0') return 1;
			double fa=atof(a);
			double fb=atof(b);
		       if(fa < fb) return -1;
			else if(fa > fb) return  1;
			else             return  0;
		}
		return 0;
	}
	// 比較クラス
	struct itmComp 
	{
		int type;//0:文字ソート,1:数字ソート,2:文字逆ソート,3:数字逆ソート
		itmComp(void){type=0;}
		itmComp(int x){type = x;}

 		bool operator()(char* v1, char* v2) {
 			int retVal=0;
			switch( type ){
				case 0: // 文字昇順
				retVal=cmpStrAsc((unsigned char*)v1, (unsigned char*)v2);
				break;
			case 1: // 数字昇順
				retVal=cmpNumAsc(v1, v2);
				break;
			case 2: // 文字降順
				retVal=cmpStrDec((unsigned char*)v1, (unsigned char*)v2);
				break;
			case 3: // 数字降順
				retVal=cmpNumDec(v1, v2);
				break;
	 		}
	   	if( retVal>0 ){ return true;}
  	 	else       		{ return false;}
  	 	return false;
  	}

};

} //////////////////////////////////////////////////////////////////////////////


namespace kgmod { ////////////////////////////////////////////// start namespace


class kgVsort:public kgMod 
{
	// 引数
	kgCSVfld _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgArgFld _vfField; // vf=
	char		 _delim; //delim=
	char		 _delimstr[2]; //delim=
	bool 	 _add_flg;  //-A
	char _outstr[KG_MAX_STR_LEN];

	vector <kgvsort_local::itmComp> _icomp;
	// 引数セット
	void setArgs(void);
	void output_n(char *str,int flgno,bool eol);

public:
	// コンストラクタ&引数セット
	kgVsort(void);
	~kgVsort(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
