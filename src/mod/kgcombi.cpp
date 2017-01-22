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
// kgcombi.cpp 組合出力クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <kgcombi.h>
#include <kgError.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgCombi::kgCombi(void)
{
	_name    = "kgcombi";
	_version = "###VERSION###";

	#include <help/en/kgcombiHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcombiHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgCombi::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,a=,n=,s=,-p,-dup,-q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();

	// f= 項目引数のセット
	vector<kgstr_t> vs_f = _args.toStringVector("f=",true);
	if(vs_f.size()!=1){
		ostringstream ss;
		ss << "f= has only one value." << " [" << vs_f.size() << "]";	
		throw kgError(ss.str());
	}
	
	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",false);

	// a= 新規項目名
	_aField = _args.toStringVector("a=",false);
	if(_aField.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}

	// n= 組み合わせ数のセット
	kgstr_t vs_n = _args.toString("n=",true);
	_combi_cnt= aToSizeT(vs_n.c_str());
	
	// a=の指定個数とn=の値は同じ
	if((_aField.size()!=_combi_cnt)&& _nfn_o==false){
		ostringstream ss;
		ss << "	The number specified by n= should be equal to number of values specified by a= ."; 
		ss << " [" << _aField.size() << "." << _combi_cnt << "]";	
		throw kgError(ss.str());
	}

	// -p ,dup フラグ
	_p_flg = _args.toBool("-p");
	_dup_flg = _args.toBool("-dup");

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	vector<kgstr_t> vss = _args.toStringVector("s=",false);


	if(!seqflg && (!vs_k.empty()||!vss.empty())){ 
		vector<kgstr_t> vsk	= vs_k;
		vsk.insert(vsk.end(),vss.begin(),vss.end());
		sortingRun(&_iFile,vsk);
	}

	_kField.set(vs_k,  &_iFile, _fldByNum);
	_fField.set(vs_f, &_iFile, _fldByNum);


}
// -----------------------------------------------------------------------------
// 順列出力
// -----------------------------------------------------------------------------
void kgCombi::perm(vector<char*>& fldlist,int pos)
{
	if(pos>0){
    perm(fldlist,pos-1);
    for(int j=pos-1; j>=0; j--){
			if( _CombiList[pos] != _CombiList[j] ){
				int vtmp = _CombiList[pos];
				_CombiList[pos] = _CombiList[j];
				_CombiList[j] = vtmp;
      	perm(fldlist,pos-1);
     		int v2tmp = _CombiList[pos];
				_CombiList[pos] = _CombiList[j];
				_CombiList[j] = v2tmp;
			}
    }
  }else{
		for(unsigned int k=0; k<_combi_cnt; k++){
			_writedata[k] = fldlist[_CombiList[k]];
		}
		_oFile.writeFld(_iFile.getOldFld(),_iFile.fldSize(), _writedata,_combi_cnt);
  }
}
// -----------------------------------------------------------------------------
// 組合出力
// -----------------------------------------------------------------------------
void kgCombi::combi(vector<char*>& fldlist,unsigned int from, unsigned int depth)
{
	//最初に組み合わせ数に達した時に処理する
	if(depth==_combi_cnt){
		if(_p_flg){ // 順列出力はpermで出力
			perm(fldlist,_combi_cnt-1);
		}else{			// 組合出力
			for(unsigned int i=0; i<_combi_cnt; i++){
				_writedata[i] = fldlist[_CombiList[i]];
			}
			_oFile.writeFld(_iFile.getOldFld(),_iFile.fldSize(), _writedata,_combi_cnt);
		}
		return;
	}
	for(vector<char*>::size_type i=from; i<fldlist.size(); i++){
		_CombiList[depth]=i;
		if(_dup_flg){ combi(fldlist,i  ,depth+1);}
		else        { combi(fldlist,i+1,depth+1);}
  }
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCombi::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();
	
	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
	_oFile.writeFldName(_iFile,_aField);

	// 出力領域確保
	kgAutoPtr2<char*> ap2;
	try { 
		ap2.set( new char*[_combi_cnt] ); 
	}catch(...) { 
		throw kgError("memory allocation error ");
	}
	_writedata = ap2.get();			
	_CombiList = vector<int>(_combi_cnt,0);
	
	// データ集計＆出力
	vector<char*> fld_stock;
	char* fldtmp;
	while(_iFile.read()!=EOF){
		if( _iFile.keybreak() ){
			// 組合出力(nCk で k=<行数のとき出力)
		  if( fld_stock.size() >= _combi_cnt  ){ combi(fld_stock,0,0); } 
			if((_iFile.status() & kgCSV::End )) break;
			for(vector<char*>::size_type i=0;i<fld_stock.size();i++){
				delete [] fld_stock[i];
			}
			fld_stock.clear();
		}
		// 通常処理 f=で指定した項目をストック
		fldtmp =new char[KG_MAX_STR_LEN];
		strcpy(fldtmp, _iFile.getNewVal(_fField.num(0)) );
		if(_assertNullIN) { if(*fldtmp=='\0'){ _existNullIN  = true;}}

		fld_stock.push_back(fldtmp);
	}


	// 終了処理
	th_cancel();
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
