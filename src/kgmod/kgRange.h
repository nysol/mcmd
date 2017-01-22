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
// kgRange.h : 範囲マッチ関するクラス
//  再考する必要有
// ============================================================================
#pragma once
#include <map>
#include <string.h>

using namespace std;

namespace kglib  ////////////////////////////////////////////// start namespace
{
//	multimapで使用するソート
class list_stsort_n {
	public:
		bool operator()(double t1,double t2) const {
			return t1 < t2;
		}
};
class list_stsort{
	public:
		bool operator()(char* t1,char* t2) const {
			return strcmp(t1,t2) < 0 ;			
		}
};
class list_edsort_n{
	public:
		bool operator()(double t1,double t2) const {
			return t1 > t2;
		}
};
class list_edsort{
	public:
		bool operator()(char* t1,char* t2) const {
			if(*t1=='\0') return true;
			if(*t2=='\0') return false;
			return strcmp(t1,t2) > 0 ;		
		}
};

/*マップでキーになるデータに使用*/
union range_data{
	double f;
	char* s;
};

/*rangeの一覧用の構造体*/
struct kgRangetbl{
  range_data st;		//開始部分のデータ
  bool      stEq;	//イコールを含むor含まない(開始部分) true:含む false:含まない 
  range_data ed;		//終了部分のデータ
  bool      edEq;	//イコールを含むor含まない(終了部分) true:含む false:含まない 
  char **rec;		//出力する文字列
	int reccnt;		//recの個数
	bool writeflg;//書き込み済みフラグ
	bool isNull(void){ 
		for(int i=0 ;i < reccnt ;i++){
			if( *rec[i]=='\0') return true;
		}
		return false;
	}
};

// コマンドライン引数クラス
class kgRange {
	bool _nsFlg;		//ソートタイプ true:数字 flase:文字
	bool _stEQflg;	//イコールを含むor含まない(開始部分) true:含む false:含まない 
	bool _edEQflg;	//イコールを含むor含まない(終了部分) true:含む false:含まない 

	//範囲の一覧に使用(double用、char*)
	multimap<double,kgRangetbl*,list_stsort_n> _tbl_st_dbl;
	multimap<char*,kgRangetbl*,list_stsort> 	_tbl_st_str;

	//検索の結果に使用(double用、char*)
	multimap<double,kgRangetbl*,list_edsort_n> _tbl_ed_dbl;
	multimap<char*,kgRangetbl*,list_edsort> 	_tbl_ed_str;

public:
	/* コンストラクタ、デストラクタ*/
	kgRange(){}
	~kgRange(){
		if(!_nsFlg){
			for(multimap<char*,kgRangetbl*,list_stsort>::iterator i=_tbl_st_str.begin();i!=_tbl_st_str.end();i++){
				for(int j=0;j<(i->second)->reccnt;j++){
					delete [] *((i->second)->rec+j);
				}
				delete [] (i->second)->st.s;
				delete [] (i->second)->ed.s;
				delete i->second;
			}
		}
		else{
			for(multimap<double,kgRangetbl*,list_stsort_n>::iterator i=_tbl_st_dbl.begin();i!=_tbl_st_dbl.end();i++){
				for(int j=0;j<(i->second)->reccnt;j++){
					delete [] *((i->second)->rec+j);
				}
				delete i->second;
			}
		}
	}	
	void set(int nsflg,int steqflg,int edeqflg){
		_nsFlg = nsflg;
		_stEQflg = steqflg;
		_edEQflg = edeqflg;
	}

	//一覧のセット
	void set_table(char * st_data,char * ed_data,char **rec_data,int size);

	//一覧からの検索
	bool serch(char *str);

	/*一覧、検索結果を返す*/
	multimap<double,kgRangetbl*,list_edsort_n> get_tbl_dbl(void){ return _tbl_ed_dbl;}
	multimap<char*,kgRangetbl*,list_edsort> 	get_tbl_str(void){ return _tbl_ed_str;}
	multimap<double,kgRangetbl*,list_stsort_n> get_list_dbl(void){ return _tbl_st_dbl;}
	multimap<char*,kgRangetbl*,list_stsort> 	get_list_str(void){ return _tbl_st_str;}
};

} //////////////////////////////////////////////////////////////// end namespace
