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
// kgpadding.h 行補完クラス
// =============================================================================
#pragma once

#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgMethod.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

// =============================================================================
// kgpadding 行補完クラス
// =============================================================================
class kgPadding : public kgModIncludeSort
{
	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVkey _iFile;  // i=
	kgCSVout _oFile;  // o=
	bool     _nil;    // -n
	kgstr_t	 _pStr;   // v=
	kgstr_t		_sStr;
	kgstr_t		_eStr;
	char     	_typeC;
	bool     	_skip; 
	int 			_dict;
	date _today;
	
  void setArgs(void);
	bool parseTime(const char* str,boost::posix_time::ptime& value);
	bool parseDate(const char* str,boost::gregorian::date& value);

	void writePading(const char* val,int outtype);
	void writePading(int val,int outtype);
	void writePading(date& val,int outtype);
	void writePading(ptime& val,int outtype);

	void writePading(const char *from,const char *to ,int direct,int outtype);
	void writePading_int(const char *from,const char *to ,int direct,int outtype);
	void writePading_date(const char *from,const char *to ,int direct,int outtype);
	void writePading_time(const char *from,const char *to ,int direct,int outtype);	

public:
  // コンストラクタ
	kgPadding(void);
	~kgPadding(void){}

	// 実行
	int run(void);

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }


};

}
