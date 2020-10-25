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
// kghashavg.cpp 行集計(合計：ソーティング不要)
// =============================================================================
#include <cstdio>
#include <vector>
#include <kghashavg.h>
#include <kgFldHash.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgHashavg::kgHashavg(void)
{
	_name    = "kghashavg";
	_version = "###VERSION###";
	
	#include <help/en/kghashavgHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kghashavgHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgHashavg::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,hs=,-n",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
	_oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();
	_oFile.setPrecision(_precision);

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);
	_fField.set(vvs, &_iFile,_fldByNum);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);
	_kField.set(vs,  &_iFile,_fldByNum);

	// -n オプションのセット
	_null=_args.toBool("-n");

	// hv= ハッシュ値のセット
	kgstr_t s = _args.toString("hs=",false);
	if(!s.empty()){
		_hashSize=atoi(s.c_str());
		if(_hashSize<=100)     _hashSize=101;
		if(_hashSize>=2000000) _hashSize=1999999;
	}else{
		_hashSize=199999;
	}	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgHashavg::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名の出力
  _oFile.writeFldName(_fField, true,false);

	// ハッシュセット
	kgFldHash hash(_hashSize, &_iFile, &_kField, &_fField);
	while( EOF != _iFile.read() ){
		kgFldHashNode* hn = hash.insert(const_cast<const char**>(_iFile.getFld()));
		for(int i=0; i<hash.fldSize() ; i++){
			char* str=_iFile.getVal(_fField.num(i));
			if(*str != '\0'){
				hn->cnt(i,1);
				hn->sum(i,atof(str));
			}else{
				if(_assertNullIN) { _existNullIN  = true;}
				hn->nul(i,true);
			}
		}
	}

	//データ出力
	for(int i=0;i<hash.hashVal();i++){
		kgFldHashNode* node=hash.node(i);
		if(node==NULL){ continue;}
		while(node!=NULL){
			const vector<int>* flg=_fField.getFlg_p();
			for(std::size_t j=0; j<flg->size(); j++){ // csvの項目数で回す
				bool eol=false;
				if(j==flg->size()-1) eol=true;
				int num=flg->at(j);                  // 対応するval位置
				if(num == -1) _oFile.writeStr( node->idx(j)  ,eol );
				else{
					if(node->cnt(num)!=0 && (!_null || !node->nul(num)) ){
						_oFile.writeDbl( node->sum(num)/node->cnt(num),eol );
					}else{
						if(_assertNullOUT){ _existNullOUT = true;}
						_oFile.writeStr( ""            ,eol );
					}
				}
			}
			node=node->next();
		}
	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY =hash.keynull(); }
	// 終了処理
	_iFile.close();
	_oFile.close();
	successEnd();
	return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const exception& e) {
	kgError err(e.what());
	errorEnd(err);
	return 1;
}catch(char * er){
	kgError err(er);
	errorEnd(err);
	return 1;
}catch(...){
	kgError err("unknown error" );
	errorEnd(err);
	return 1;
}
