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
// kgArgFld.cpp 引数項目クラス
// ============================================================================
#include <kgArgFld.h>
#include <kgMethod.h>
#include <kgCSVutils.h>

using namespace kglib;
using namespace std;

// =============================================================================
// private
// =============================================================================
// -----------------------------------------------------------------------------
// _num_flg_Set :
//	 _name,_attrの項目名展開および_num,_flgへのデータセット
// csv:参照ファイル
// fldByNum:項目番号指定フラグ
// attrEval:項目名展開フラグ
// -----------------------------------------------------------------------------
void kgArgFld::_num_flg_Set(kgCSV* csv,bool fldByNum,bool attrEval)
{
	// 項目展開＆_numへのセット
	if(attrEval){
		if(_attr.size()==0){
			_num = evalFldName(_name, csv,fldByNum,attrEval);
		}else{
			_num = evalFldName(_name, _attr, csv,fldByNum);
			evalAttr(_name, _attr);
		}	
	}
	else{
		_num = evalFldName(_name, csv,fldByNum);	
	}	

	// _flgへのセット
	if(_csv->fldSize()==0){ 
		// -nfnで0バイトファイルの場合
		int max=0;
		for(unsigned int i=0; i<_num.size(); i++){
			if(max<_num.at(i))max=_num.at(i);
		}
		_flg.resize(max+1, -1); 
	}else{
		_flg.resize(_csv->fldSize(), -1); 
	}
	for(unsigned int i=0; i<_num.size(); i++){
		_flg.at(_num.at(i))=i;
	}
}

// =============================================================================
// public
// =============================================================================
// -----------------------------------------------------------------------------
// set 2次元配列(項目名とその属性)の場合 ex f=a:b,c:d , k=a%nr
// -----------------------------------------------------------------------------
void kgArgFld::set(vector< vector<kgstr_t> >& vvs, kgCSV* csv,bool fldByNum, bool attrEval) throw(kgError) 
{
	if(csv==NULL || vvs.empty()){
    throw kgError("internal error on fields augument");
	}
	_csv=csv;
	_name=vvs.at(0);
	_attr=vvs.at(1);
	_num_flg_Set(csv,fldByNum,attrEval);
}

// -----------------------------------------------------------------------------
// set 1次元配列(項目名とその属性)の場合 ex f=a,b,c , k=a%nr
// -----------------------------------------------------------------------------
void kgArgFld::set(vector<kgstr_t>& vs, kgCSV* csv, bool fldByNum) throw(kgError) 
{
	if(csv==NULL){
    throw kgError("internal error on fields augument");
	}
	_csv=csv;
	_name=vs;
	_num_flg_Set(csv,fldByNum);
}

// -----------------------------------------------------------------------------
// set 文字列の場合 ex a* 1_4
// -----------------------------------------------------------------------------
void kgArgFld::set(kgstr_t& s, kgCSV* csv, bool fldByNum) throw(kgError)
{
	vector<kgstr_t> vs;
	vs.push_back(s);
	set(vs, csv, fldByNum);
}

// -----------------------------------------------------------------------------
// num番目に登録された引数項目の名前を返す．
//  ex.  f=a,b,c  name(2) => c
// -----------------------------------------------------------------------------
const kgstr_t kgArgFld::name(size_t num) const
{
	if( num < _name.size() ){
		return _name.at(num);
	}else{
		throw kgError("internal error argFld.name vector number is out of range");
	}
}
// -----------------------------------------------------------------------------
// num番目に登録された引数項目の属性を返す．
//  ex.  f=a:A,b:B,c  attr(1) => B
// -----------------------------------------------------------------------------
const kgstr_t kgArgFld::attr(size_t num) const
{
	if( num < _attr.size() ){
		return _attr.at(num);
	}else{
		throw kgError("internal error argFld.attr vector number is out of range");
	}
}
// -----------------------------------------------------------------------------
// num番目に登録された引数項目のCSVにおける項目番号を返す
//  ex. CSV: a,b,c f=c,b =>2,1
// -----------------------------------------------------------------------------
int kgArgFld::num(size_t num)  const
{
	if( num < _num.size() ){
		return _num.at(num);
	}else{
		throw kgError("internal error argFld._num vector number is out of range");
	}
}

// -----------------------------------------------------------------------------
// 各CSV項目に対応する引数項目の番号を返す．
//  ex.  CSV:a,b,c f=c,b => -1,1,0
// -----------------------------------------------------------------------------
int kgArgFld::flg(size_t num)  const 
{
	if( num < _flg.size() ){
		return _flg.at(num);
	}else{
		throw kgError("internal error argFld._flg vector number is out of range");
	}
}

