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
// kgError.cpp エラーメッセージ処理
// ============================================================================
#include <sstream>
#include <kgError.h>

using namespace std;
using namespace kglib;

// -----------------------------------------------------------------------------
// コンストラクタ
// -----------------------------------------------------------------------------
kgError::kgError(string msg){
	message_.push_back(msg);
}
// -----------------------------------------------------------------------------
// msgを追加する
// -----------------------------------------------------------------------------
void kgError::addMessage(string msg){
	message_.push_back(msg);
}
// -----------------------------------------------------------------------------
// msgの最後のメッセージに文字列を追加する
// -----------------------------------------------------------------------------
void kgError::addModName(string msg){
	int no=(int)message_.size()-1;
	if(no!=-1){
		message_.at(no)+=" (";
		message_.at(no)+=msg;
		message_.at(no)+=")";
	}
}
// -----------------------------------------------------------------------------
// 項目数が異なるerrorメッセージスロー
// -----------------------------------------------------------------------------
void kgError::fldCntErr(int fldCnt, int j)
{
	ostringstream ss;
	ss << "detected different number of fields (" << fldCnt << ", " << j<< ")";
	throw kgError(ss.str());
}
// -----------------------------------------------------------------------------
// 最大record長超過エラーメッセージスロー
// -----------------------------------------------------------------------------
void kgError::recLenErr(void) 
{
	throw kgError("exceed border length");
}
void kgError::recLenErr(size_t manlen)
{
	ostringstream ss;
	ss << "exceed max record length(" << manlen << ")" ;
	throw kgError(ss.str());
}
