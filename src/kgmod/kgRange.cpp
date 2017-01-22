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
// kgRange.cpp : 範囲マッチ関するクラス
//  再考する必要有
// ============================================================================
#include <cfloat>
#include <kgRange.h>
#include <stdlib.h>

using namespace std;
using namespace kglib;

// -----------------------------------------------------------------------------
// 検索部分
// -----------------------------------------------------------------------------
bool kgRange::serch(char *str)
{
	bool rtn=false;
	_tbl_ed_str.clear();
	_tbl_ed_dbl.clear();

	// 開始部分での検索
	if(_nsFlg){	
		multimap<double,kgRangetbl*,list_stsort_n>::iterator i;
		double val =atof(str);
		if(_stEQflg) { i = _tbl_st_dbl.upper_bound(val);}
		else				 { i = _tbl_st_dbl.lower_bound(val);}
		for(multimap<double,kgRangetbl*,list_stsort_n>::iterator j=_tbl_st_dbl.begin() ;j!=i;j++){
			_tbl_ed_dbl.insert(make_pair((j->second)->ed.f,j->second));			
		}
	}
	else{ //文字タイプの場合
		multimap<char *,kgRangetbl*,list_stsort>::iterator i;
		if(_stEQflg) { i = _tbl_st_str.upper_bound(str); }
		else				 { i = _tbl_st_str.lower_bound(str); }
		for(multimap<char*,kgRangetbl*,list_stsort>::iterator j=_tbl_st_str.begin() ;j!=i;j++){
			_tbl_ed_str.insert(make_pair((j->second)->ed.s,j->second));			
		}
	}

	//終了範囲で検索
	//(開始部分での検索結果から終了部分を満たさない部分を取り除く
	// マッチしたのもの書き込みをフラグをON)
	if(_nsFlg){// 数字タイプの場合
		multimap<double,kgRangetbl*,list_edsort_n>::iterator i;
		if(_edEQflg) { i = _tbl_ed_dbl.upper_bound(atof(str));}
		else				 { i = _tbl_ed_dbl.lower_bound(atof(str));}
		_tbl_ed_dbl.erase(i,_tbl_ed_dbl.end());
		for(i=_tbl_ed_dbl.begin();i!=_tbl_ed_dbl.end();i++){
			(i->second)->writeflg = true;
		}
	}
	else{ //文字タイプの場合
		multimap<char*,kgRangetbl*,list_edsort>::iterator i;
		if(_edEQflg) { i = _tbl_ed_str.upper_bound(str); }
		else				 { i = _tbl_ed_str.lower_bound(str);}
		_tbl_ed_str.erase(i,_tbl_ed_str.end());
		for(i=_tbl_ed_str.begin();i!=_tbl_ed_str.end();i++){
			(i->second)->writeflg = true;
		}
	}
	if(_nsFlg){// 数字タイプの場合
		rtn = (_tbl_ed_dbl.size()!=0);
	}else{
		rtn = (_tbl_ed_str.size()!=0);
	}
	return rtn;
}
// -----------------------------------------------------------------------------
// 範囲の一覧作成
// -----------------------------------------------------------------------------
void kgRange::set_table(char * st_data,char * ed_data,char **rec_data,int size)
{
	kgRangetbl* tmptbl;
	tmptbl = new kgRangetbl;
	tmptbl->rec = new char*[size];
  tmptbl->stEq=_stEQflg;
  tmptbl->edEq=_edEQflg;
	tmptbl->reccnt= size;
	tmptbl->writeflg= false;
	for(int i=0;i<size;i++){
		*(tmptbl->rec+i) = new char[strlen(*(rec_data+i))+1];
		strcpy(*(tmptbl->rec+i),*(rec_data+i)); 
	}
	
	if(_nsFlg){//数字比較の場合
		if(*st_data=='\0') tmptbl->st.f =-DBL_MAX;
		else								 tmptbl->st.f =atof(st_data);
		if(*ed_data=='\0') tmptbl->ed.f = DBL_MAX;
		else								 tmptbl->ed.f =atof(ed_data);
		_tbl_st_dbl.insert(make_pair(tmptbl->st.f,tmptbl));
	}
	else{//文字タイプの場合
		tmptbl->st.s = new char[strlen(st_data)+1];
		strcpy(tmptbl->st.s,st_data);
		tmptbl->ed.s = new char[strlen(ed_data)+1];
		strcpy(tmptbl->ed.s,ed_data);
		_tbl_st_str.insert(make_pair(tmptbl->st.s,tmptbl));
	}
	
}

