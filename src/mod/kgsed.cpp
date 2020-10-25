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
// kgsed.h 正規表現による文字列置換
// =============================================================================
#include <cstdio>
#include <sstream>
#include <kgsed.h>
#include <kgError.h>
#include <kgMethod.h>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
using namespace boost::xpressive;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgSed::kgSed(void)
{
	_name    = "kgsed";
	_version = "###VERSION###";
	
	#include <help/en/kgsedHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsedHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSed::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,c=,v=,-A,-W,-g",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);
	_iFile.read_header();

	// -A:追加フラグ,g:グローバル置換,-w:ワイド文字
	_add 			= _args.toBool("-A");
	_global 	= _args.toBool("-g");
	_widechar = _args.toBool("-W");

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);
	_fField.set(vvs, &_iFile,_fldByNum);

	// c= 正規表現のセット
	_regstr = _args.toString("c=",true);

	// v= 置換文字列
	_vstr = _args.toString("v=",true);

}
// -----------------------------------------------------------------------------
// 出力（置換用）
// -----------------------------------------------------------------------------
void kgSed::writeFld(char** fld, const vector<int>* flg, const vector<string>* val)
{
	unsigned int i;
	int num;
	for(i=0; i<flg->size()-1; i++){ 
		num=flg->at(i);               
		if(num == -1) _oFile.writeStr( *(fld+i)   					 	, false );
		else          _oFile.writeStr( val->at(num).c_str()	, false );
	}
		num=flg->at(i);
		if(num == -1) _oFile.writeStr( fld[i]      					, true  );
		else          _oFile.writeStr( val->at(num).c_str()	, true  );
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSed::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	//char用コンパイル結果格納領域
	wsregex wre;
	sregex re;	

	//正規表現コンパイル
	if(_widechar){ wre = wsregex::compile(toWcs(_regstr));}
	else				 { re = sregex::compile(_regstr); }

	//出力項目名出力 追加 or 置き換
	if(_add) { _oFile.writeFldName(_iFile,_fField,true); }
	else		 { _oFile.writeFldName(_fField, true);}

	// 変数領域確保＆初期化
	vector<string> val;
	// データ出力
	while( EOF != _iFile.read() ){
		if(_widechar){
			if(_global){
				// ワイド文字+グローバルマッチ
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					if(_assertNullIN && *_iFile.getVal( _fField.num(i) ) != '\0' ) { _existNullIN  = true;}
					val.push_back(
						toMbs( 
							regex_replace(
								toWcs( _iFile.getVal( _fField.num(i) ) ) ,
								wre ,
								toWcs(_vstr) )
						));
					if(_assertNullOUT && val.back().size()==0 ) { _existNullOUT  = true;}
				}
			}
			else{
				// ワイド文字+最初に一致
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					if(_assertNullIN && *_iFile.getVal( _fField.num(i) ) != '\0' ) { _existNullIN  = true;}
					val.push_back( 
						toMbs( 
							regex_replace(
								toWcs( _iFile.getVal( _fField.num(i) ) ) ,
								wre ,
								toWcs(_vstr),
								regex_constants::format_first_only)
						));
					if(_assertNullOUT && val.back().size()==0 ) { _existNullOUT  = true;}
				}
			}
		}
		else{
			if(_global){
				// 通常文字+グローバルマッチ
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					if(_assertNullIN && *_iFile.getVal( _fField.num(i) ) != '\0' ) { _existNullIN  = true;}
					val.push_back( 
						regex_replace( 
							string(_iFile.getVal(_fField.num(i))) ,
							re , 
							_vstr ) );
					if(_assertNullOUT && val.back().size()==0 ) { _existNullOUT  = true;}
				}
			}
			else{
				// 通常文字+最初に一致
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					if(_assertNullIN && *_iFile.getVal( _fField.num(i) ) != '\0' ) { _existNullIN  = true;}
					val.push_back( 
						regex_replace( 
							string(_iFile.getVal(_fField.num(i))) ,
							re , 
							_vstr, 
							regex_constants::format_first_only) );
					if(_assertNullOUT && val.back().size()==0 ) { _existNullOUT  = true;}
				}
			}
		}
		// 出力　追加 or 置換 
		if(_add) { _oFile.writeFld(_iFile.getFld(),_iFile.fldSize(),&val); }
		else		 { writeFld(_iFile.getFld(),_fField.getFlg_p(),&val);}

		val.clear();
	}

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
