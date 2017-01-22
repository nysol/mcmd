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
// kgFldHash.cpp 項目ハッシュ(hashavg,hashsumで使用)
// =============================================================================
#include <cstring>
#include <kgFldHash.h>
#include <kgError.h>

using namespace kglib;
// =============================================================================
// kgFldHash関連
// =============================================================================
// -----------------------------------------------------------------------------
// コンストラクタ
// -----------------------------------------------------------------------------
kgFldHash::kgFldHash(int hashVal, kgCSVfld* csv, kgArgFld* key, kgArgFld* fld)
{
	_hashVal=hashVal;
	_cnt=0;
	_csv=csv;
	_key=key;
	_fld=fld;
	_node.resize(_hashVal,NULL);
	_keynull=false;

}
// -----------------------------------------------------------------------------
// デストラクタ
// -----------------------------------------------------------------------------
kgFldHash::~kgFldHash(void)
{
	for(int i=0;i<hashVal();i++){
		kgFldHashNode* node=_node.at(i);
		while(node!=NULL){
			kgFldHashNode* next=node->next();
			delete node;
			node=next;
		}
	}
}
// -----------------------------------------------------------------------------
// Hash値の計算
// -----------------------------------------------------------------------------
unsigned int kgFldHash::calHashVal(const char** flds)
{
	unsigned int v=0;
	for(size_t i=0; i<_key->size(); i++){
		const char* key=*( flds + _key->num(i) );
		if(*key != '\0'){ _keynull=true;}
		while(*key != '\0') v+=v*137+static_cast<unsigned int>(*key++);
	}
	return v % _hashVal;
}
// -----------------------------------------------------------------------------
// 挿入
// -----------------------------------------------------------------------------
kgFldHashNode* kgFldHash::insert(const char** flds)
{
	unsigned int hv;
	kgFldHashNode* newNode;
	kgFldHashNode* node;
	kgFldHashNode* last=NULL;

	hv=calHashVal(flds);
	node=_node.at(hv);

	if(node==NULL){
		newNode=new kgFldHashNode(flds,this);
		_node.at(hv)=newNode;
	}else{
		while(node!=NULL){
			if( node->keycmp(flds) ){
				return node;
			}else{
				last=node;
				node=node->next();
			}
		}
		newNode=new kgFldHashNode(flds,this);
		last->next(newNode);
	}
	_cnt++;
	return newNode;
}
// =============================================================================
// kgFldHashNode関連
// =============================================================================
// -----------------------------------------------------------------------------
// コンストラクタ
// -----------------------------------------------------------------------------
kgFldHashNode::kgFldHashNode(const char** flds, kgFldHash* hash)
{
	_hash=hash;
	// 1つのレコードを丸ままコピー
	try {
		_ap1.set(new char[_hash->recLen()]);
	} catch(...) {
		throw kgError("memory allocation error on kgFldHashNode");
	}
	_buf = _ap1.get();
	memcpy(_buf, *flds, _hash->recLen());

	// 項目へのインデックス作成
	try {
		_ap2.set(new char*[_hash->csvSize()]);
	} catch(...) {
		throw kgError("memory allocation error on kgFldHashNode");
	}
	_idx=_ap2.get();
	for(int i=0; i<_hash->csvSize(); i++){
		*(_idx+i)=_buf+(_hash->csv(i)-_hash->csv(0));
	}

	// 件数と合計の領域確保(f=で指定された項目数)
	_cnt.resize(_hash->fldSize(),0);
	_sum.resize(_hash->fldSize(),0);
	_nul.resize(_hash->fldSize(),false);
	_next = NULL;
}
// -----------------------------------------------------------------------------
// keyの比較
// -----------------------------------------------------------------------------
bool kgFldHashNode::keycmp(const char** flds)
{
	for(int i=0; i<_hash->keySize(); i++){
		if( 0!=strcmp(*(flds+_hash->key(i)), *(_idx+_hash->key(i))) ) return false;
	}
	return true;
}

