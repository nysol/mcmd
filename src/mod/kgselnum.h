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
// kgselnum.h 数値による行選択クラス
// =============================================================================
#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <cfloat>
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

// 範囲条件クラス
class kgRangeParam 
{
	char stype;
	char etype;
	double start;
	double end;

	public:
	bool match(double val){
		bool check=false;
		switch(stype){
			case '(':
				check = start < val;
				break;
			case '[':
				check = start <= val ;
				break;
		}
		if (!check) { return check; }
		check=false;
		switch(etype){
			case ')':
				check = end > val;
				break;
			case ']':
				check = end >= val ;
				break;
		}
		return check;
	}


	void dataSet(kgstr_t& st,kgstr_t& et)
	{
		// スペース除去	
		size_t pos;
		while((pos = st.find_first_of(" 　\t")) != kgstr_t::npos){
    	st.erase(pos, 1);
		}	
		while((pos = et.find_first_of(" 　\t")) != kgstr_t::npos){
    	et.erase(pos, 1);
    }
		const char *p = st.c_str();
		const char *q = et.c_str();
		size_t plen = strlen(p);
		size_t qlen = strlen(q);
		
		// 構文チェック
		if(*p=='\0'||*q=='\0'){ throw kgError("parse error c= ");	}
		if(*p!='(' && *p!='['){ throw kgError("parse error c= ");	}
		if(*(q+qlen-1)!=')' && *(q+qlen-1)!=']'){ 
			throw kgError("parse error c= ");	
		}

		//start情報設定
		if(*p=='('){ stype='('; }
		else 			 { stype='['; }
		if(plen==1){ start = -DBL_MAX;}
		else			 { start = atof(p+1);}

		//end情報設定
		if(*(q+qlen-1)==')'){ etype=')'; }
		else 								{ etype=']'; }
		if(qlen==1) { end = DBL_MAX;}
		else				{ end = atof(et.substr(0,et.size()-1).c_str()); }
	}
};



class kgSelnum: public kgModIncludeSort
{
	// 引数
	kgArgFld _kField;  // k=
	kgArgFld _fField;  // f=
	vector<kgRangeParam> _cField;//c=
	
	kgCSVblk _iFile;   // i=
	kgCSVout _oFile;   // o=
	kgCSVout _uFile;   // u=

	bool     _sel_flg; // -F
	bool     _keysel_flg; // -R
	bool     _reverse; // -r
	bool     _elsefile; // 不一致ファイルを使用するかどうか(u=の指定があればtrue)

	// 条件検索
	bool rangeMatch(double val);
	bool lineCheck(vector<int>& cnt,char** str);

	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ&引数セット
	kgSelnum(void);
	~kgSelnum(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
