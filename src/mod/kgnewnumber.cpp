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
// kgnewnumber.cpp 連続値項目の新規生成クラス
// =============================================================================
#include <sstream>
#include <kgnewnumber.h>
#include <kgError.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgNewnumber::kgNewnumber(void)
{
	_name    = "kgNewnumber";
	_version = "###VERSION###";
	
	#include <help/en/kgnewnumberHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgnewnumberHelp.h>
	#endif
	
}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgNewnumber::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("a=,o=,S=,I=,l=");

	// 出力ファイルオープン
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);

	// a= 追加項目名
	_addstr = _args.toString("a=",false);
	if(_addstr.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}

	// S= 開始番号
	_alpha_flg=false;			
	string str_S = _args.toString("S=",false);
	if(str_S.empty()){ _start=0; }
	else{	
		string digits("-0123456789");
		string alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		if(str_S.find_first_not_of(digits)==kgstr_t::npos){//数値のみ
			_start=atoi(str_S.c_str());
		}
		else if(str_S.find_first_not_of(alpha)==kgstr_t::npos){//アルファベット
			_alpha_flg=true;			
			_start=0;
			for(string::size_type i=0;i<str_S.size();i++){
				_start = (_start*26)+str_S[i]-'A'+1;
			}					
		}
		else{
			ostringstream ss;
			ss << "S= is digits or alpha" << str_S.c_str();	
			throw kgError(ss.str());
		}
	}

	// I= 間隔
	string str_I = _args.toString("I=",false);
	_interval=atoi(str_I.c_str());
	if(_interval==0){ _interval=1;}
	if(_alpha_flg&&_interval<0){
		ostringstream ss;
		ss << "when S= is alpha, 0 or more can be specified with I=" << str_S.c_str();	
		throw kgError(ss.str());
	}

	kgstr_t s_l =  _args.toString("l=",false);
	if(s_l.empty()){
		_line = 10;
	}else{
		_line = aToSizeT(s_l.c_str()) ; 
	}
	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgNewnumber::run(void) try 
{
	// パラメータセット＆出力ファイルオープン
	setArgs();

	// 項目名の出力
	_oFile.writeFldName(_addstr);

	// データ出力
	size_t cnt = _start;
	for(size_t i=0;i<_line;i++){	
		_oFile.writeFld(NULL,0,cnt,_alpha_flg);
		cnt = cnt + _interval; 
	}

	// 終了処理(メッセージ出力,thread pipe終了通知)
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
