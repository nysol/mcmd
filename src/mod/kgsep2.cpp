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
// kgsep2.h 行の複数ファイルへの分割ver.2
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <kgsep2.h>
#include <kgCSVout.h>
#include <kgError.h>
#include <kgMethod.h>
#include <boost/filesystem.hpp>

using namespace boost;
using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSep2::kgSep2(void)
{
	_name    = "kgsep2";
	_version = "###VERSION###";

	#include <help/en/kgsep2Help.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsep2Help.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSep2::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("k=,O=,o=,i=,-p,a=,-q",kgArgs::COMMON|kgArgs::NULL_KEY );

	// 入力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();

	// -p
	forceFlg_ = _args.toBool("-p");

	// 出力ディレクトリ名
	{
		kgstr_t str = _args.toString("O=",false);
		if(str.empty()){
			oPath_=boost::filesystem::path("./");
		}else{
			oPath_=boost::filesystem::path(str);
		}
		if(forceFlg_) create_directory  (oPath_);
		else          create_directories(oPath_);
	}

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",true);

	// a= 出力項目名
	_newFld  = _args.toString("a=",false);
	if(_newFld.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg){ sortingRun(&_iFile,vs);}
	_kField.set(vs,  &_iFile,_fldByNum);
	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSep2::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力(k=の項目名,"no")
	vector<kgstr_t> name;
	if(! (_iFile.end() && _nfn_o) ){
		for(vector<kgstr_t>::size_type i=0; i<_kField.size(); i++){
			name.push_back(_iFile.fldName(_kField.num(i),true));
		}
		name.push_back(_newFld);
 	 _oFile.writeFldName(name);
 	}

	// データ出力
	kgCSVout sepFile;  // 出力用
	unsigned int fno=0;
	while(_iFile.read()!=EOF){
		//keybreak or最初はファイル名を生成
		if( _iFile.keybreak() || _iFile.begin() ){
			if( _iFile.keybreak() ) { sepFile.close();}
			if((_iFile.status() & kgCSV::End )) break;

			// sepファイル名(連番)生成
			ostringstream ss;
			ss << fno++;
			boost::filesystem::path fstr=oPath_ / ss.str();

			// k=とファイル名の対応表出力
			for(vector<kgstr_t>::size_type i=0; i<_kField.size(); i++){
				char* str=_iFile.getNewVal(_kField.num(i));
				_oFile.writeStr(str,false);
			}
			_oFile.writeStr(fstr.string().c_str(),true);

			//ファイルオープン&出力
			sepFile.open(fstr.string(), _env,_nfn_o);
			sepFile.writeFldName(_iFile);
		}
		//通常処理
		sepFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理
	th_cancel();
	sepFile.close();
	_oFile.close();
	_iFile.close();
	successEnd();
	return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const std::exception& e) {
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
