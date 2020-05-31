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
// kgvdelim.cpp ベクトル区切り文字の変更クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <kgsplit.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSplit::kgSplit(void)
{
	_name    = "kgsplit";
	_version = "###VERSION###";

	#include <help/en/kgsplitHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsplitHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSplit::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,f=,delim=,a=,-r",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o,_rp);
	_iFile.read_header();

	// f= 項目引数のセット
	vector<kgstr_t>  vs = _args.toStringVector("f=",true);
	if( vs.size()!=1){
		ostringstream ss;
		ss << "f= must take just one item : f= size:" << vs.size() ;
		throw kgError(ss.str());
	}
	_fField.set(vs, &_iFile,_fldByNum); 

	_aStr = _args.toStringVector("a=",true);

	_remove = _args.toBool("-r");
	
	kgstr_t s_d = _args.toString("delim=",false);
	if(s_d.empty()){	
		_delim=' ';
	}else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= takes 1 byte charactor (" << s_d << ")";
		throw kgError(ss.str());
	}else{
		_delim=*(s_d.c_str());
	}

}


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSplit::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();
	char dmy[1];
	dmy[0] = '\0';

	// 項目名出力
	if (_remove){
		vector<kgstr_t> outFldName;
		for(size_t i=0; i<_iFile.fldSize(); i++){
			if( _fField.flg(i) == -1  ){
				outFldName.push_back(_iFile.fldName(i,true));
			}
		}
		for(vector<kgstr_t>::size_type i=0; i<_aStr.size(); i++){
			outFldName.push_back(_aStr.at(i));
		}
		if(!_nfn_o){ _oFile.writeFldNameCHK(outFldName); }
	}
	else{	
		_oFile.writeFldName(_iFile, _aStr);
	}

	kgAutoPtr2<char*> _o_stock_ap;
	_o_stock_ap.set( new char*[_aStr.size()] );
	char ** opp = _o_stock_ap.get();
	while(EOF != _iFile.read() ){
		strcpy(_outstr,_iFile.getVal(_fField.num(0)));
		if( *_outstr=='\0'){
			if( _assertNullIN ){ _existNullIN  = true;} 
			if( _assertNullOUT){ _existNullOUT = true;}
		}
		vector<char*> eachItem = splitToken(_outstr,_delim);
		for( size_t i=0 ;  i < _aStr.size() ;i++){
			if( i < eachItem.size() ){ * (opp+i) = 	eachItem[i] ;}
			else { 	
				* (opp+i) = dmy;
				if( _assertNullOUT){ _existNullOUT = true;}
			} 
		}
		if (_remove){
			for(size_t i=0; i<_iFile.fldSize(); i++){
				if( _fField.flg(i) == -1  ){ _oFile.writeStr( _iFile.getVal(i), false ); }
			}
			for(size_t i=0; i<_aStr.size()-1; i++){
				_oFile.writeStr( *(opp+i), false );
			}
				_oFile.writeStr( *(opp+_aStr.size()-1), true );
		}
		else{
			_oFile.writeFld(_iFile.getFld(),_iFile.fldSize(),opp,_aStr.size());
		}
	}

	// 終了処理
	_iFile.close();
	_oFile.close();
	successEnd();
	return 0;

// 例外catcher
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
