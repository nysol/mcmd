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
// kgtonull.h NULL値の置換クラス
// =============================================================================
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <kgtonull.h>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
//	文字列比較(当てはまればtrue)vstrにある文字列のどれかに一致すればtrue
// -----------------------------------------------------------------------------
namespace 
{
	// ワイド文字による部分文字列比較
	bool strCompSub(char* str,vector<wstring>& vstr){
		for(vector<wstring>::size_type i=0;i<vstr.size();i++){
			wstring ws=toWcs(str);
			if(ws.find(vstr[i])!=wstring::npos) {return true;}
		}
		return false;
	}
	// 通常の部分文字列比較
	bool strCompSub(char* str,vector<string>& vstr){
		for(vector<string>::size_type i=0;i<vstr.size();i++){
			if(NULL!=strstr(str,vstr[i].c_str())) {return true;}
		}
		return false;
	}
	// 完全マッチ比較
	bool strComp(char* str,vector<string>& vstr){
		for(vector<string>::size_type i=0;i<vstr.size();i++){
			if(!strcmp(str,vstr[i].c_str())) {return true;}
		}
		return false;
	}
}

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgTonull::kgTonull(void)
{
	_name    = "kgtonull";
	_version = "###VERSION###";

	#include <help/en/kgtonullHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgtonullHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgTonull::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,f=,v=,-sub,-W",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN);

	// ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_iFile.read_header();

	// f= 項目引数のセット
	vector<kgstr_t>  vs_f = _args.toStringVector("f=",true);
	_fField.set(vs_f, &_iFile,_fldByNum);

	// -sub 部分マッチフラグ
	_substr     = _args.toBool("-sub");
	_widechr    = _args.toBool("-W");

	// v= 項目引数のセット
	_vField = _args.toStringVector("v=",true);
	for(vector<kgstr_t>::size_type i=0;i<_vField.size();i++){
		if(_substr && _widechr){
			_vFieldw.push_back(toWcs(_vField[i]));
		}
	}

}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgTonull::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名出力
	_oFile.writeFldName(_iFile);

	while( EOF != _iFile.read() ){
		const vector<int>* flg=_fField.getFlg_p();
		for(vector<int>::size_type i=0; i<flg->size(); i++){

			bool eol= (i==flg->size()-1);	// 改行出力フラグ
			int   num = flg->at(i);       // f=で指定されたかどうか
			char* str = _iFile.getVal(i); // 項目の値

			// f=で指定された項目以外の場合はそのまま出力
			if(num == -1){
				_oFile.writeStr(str, eol);
			}else{
				// f=で指定された項目の場合
				if(_assertNullIN && *str=='\0') { _existNullIN  = true;}
				if(_substr){ // 部分マッチの比較
					if(_widechr){
						if( strCompSub(str, _vFieldw) ) _oFile.writeStr("" ,eol);
						else                            _oFile.writeStr(str,eol);
					}else{
						if( strCompSub(str, _vField ) ) _oFile.writeStr("" ,eol);
						else                            _oFile.writeStr(str,eol);
					}
				}else{// 完全一致の比較
					if( strComp(str, _vField) ) _oFile.writeStr("" ,eol);
					else                        _oFile.writeStr(str,eol);
				}
			}
  	} 
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
