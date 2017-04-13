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
#include <kgVal.h>

using namespace std;
using namespace kglib;
namespace kglib {

void kgVal::type(char type){
	_type=type;
	_null=true;
	switch(_type){
		case 'N': _v.r=0     ; break;
		case 'S': _v.s=const_cast<char*>(""); break;
		case 'B': _v.b=false ; break;
		case 'D': _v.d=NULL  ; break;
		case 'T': _v.t=NULL  ; break;
		case 'U': _v.u=NULL  ; break;
	}
}

void kgVal::s(char*  v) {
	_v.s=v;
	if(*_v.s=='\0'){ _null=true; } 
	else 					 { _null=false;}
}

//	加算で実数がセットされる
void kgA2Fadd(char* str,kgVal& result){
	if(*str=='\0'||result.null()){
		result.null(true);
	}else{
		result.null(false);
		result.r(atof(str)+result.r());
	}
}

}

