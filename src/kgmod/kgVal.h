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

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <kgMethod.h>
#include <kgError.h>
#include <kgConfig.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace kglib;
using namespace boost::gregorian;
using namespace boost::posix_time;

namespace kglib ////////////////////////////////////////////// namespace start
{
class kgVal 
{
	char _type;
  bool _null; 

	union {     
  	double r; // type=N 
  	char*  s; // type=S 
  	bool   b; // type=B 
  	date*  d; // type=D 
  	ptime* t; // type=T 
  	ptime* u; // type=u 
	} _v;

public:

	// コンストラクタ
	kgVal(void) : _type('0') {}
	kgVal(const char t){ type(t); }

	void r(double v) { _v.r=v; _null=false;}
	void s(char*  v) ;
	void b(bool   v) {_v.b=v; _null=false;}
	void d(date*  v) {_v.d=v; _null=false;}
	void t(ptime* v) {_v.t=v; _null=false;}
	void u(ptime* v) {_v.u=v; _null=false;}

	double r(void) const {return _v.r;}
	char*  s(void) const {return _v.s;}
	bool   b(void) const {return _v.b;}
	date*  d(void) const {return _v.d;}
	ptime* t(void) const {return _v.t;}
	ptime* u(void) const {return _v.u;}

	void type(char type);
	void null(bool null) { 
		_null=null; 
		if(_null){_v.s=const_cast<char*>("");}
	}
	char type(void) const { return _type; }
	bool null(void) const { return _null; }

	void set(const kgVal *from){
		this->_type=from->type();
		switch(this->_type){
			case 'N':
					this->r(from->r());
				break;
			case 'S':
					this->s(from->s());
				break;
			case 'B':
					this->b(from->b());
				break;
			case 'D':
					this->d(from->d());
				break;
			case 'T':
					this->t(from->t());
			case 'U':
					this->u(from->u());
				break;		
		}
		this->null(from->null());
	}

};

//	加算で実数がセットされる
void kgA2Fadd(char* str,kgVal& result);

} //////////////////////////////////////////////////////////////// namespace end


