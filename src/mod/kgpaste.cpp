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
// kgpaste.h 参照ファイル項目の行番号マッチング結合クラス
// =============================================================================
#include <cstdio>
#include <kgpaste.h>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgPaste::kgPaste(void)
{
	_name    = "kgpaste";
	_version = "###VERSION###";

	#include <help/en/kgpasteHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgpasteHelp.h>
	#endif
	
}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgPaste::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,m=,-n,-N",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	kgstr_t ifile = _args.toString("i=",false);
	kgstr_t mfile = _args.toString("m=",false);
	if(ifile.empty() && mfile.empty()){
		throw kgError("Either i= or m= must be specified.");
	}
	_iFile.open(ifile,_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_mFile.open(mfile,_env,_nfn_i);
	_iFile.read_header();
	_mFile.read_header();

	// f= 項目引数のセット指定が無かった場合はk=の項目以外をセットする
	vector< vector<kgstr_t> >  vvs = _args.toStringVecVec("f=",':',2,false);
	if(vvs[0].empty()){
		for(size_t i=0 ; i< _mFile.fldSize();i++){
			vvs[0].push_back(toString(i));				
			vvs[1].push_back("");				
		}
		_fField.set(vvs, &_mFile, true);
	}else{
		_fField.set(vvs, &_mFile, _fldByNum);
	}
	// -n,-N アウタージョインフラグ
	_i_outer = _args.toBool("-n");
	_m_outer = _args.toBool("-N");

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgPaste::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名出力
	_oFile.writeFldName(_iFile,_fField,true);

	//比較結果用フラグ
	int cmpflg=0;

	//追加項目no
  vector<int> fField =_fField.getNum();

	//入力、参照ファイルの最終チェック(1なら終了)
	bool traEnd=false;
	bool mstEnd=false;

	// データ出力(入力ファイルあるいは参照ファイルどちらか最後まで読み込むまで)
	while(true){
		// 読み込み
		if(_iFile.read() == EOF) traEnd=true;
		if(_mFile.read() == EOF) mstEnd=true;

		// traとmstのキーの比較 (終了しているかどうか)
		     if(traEnd && mstEnd) break;
		else if(traEnd          ) cmpflg= 1;
		else if(          mstEnd) cmpflg=-1;
		else                      cmpflg= 0;

		// tra,mst両者とも書き出す
		if(cmpflg==0){
			for( size_t i=0; i<_iFile.fldSize(); i++){
				_oFile.writeStr(_iFile.getVal(i),false);
			}
			for(vector<int>::size_type i=0; i<fField.size(); i++){
				bool ret=false;
				if(i==fField.size()-1) ret=true;
				if(_assertNullIN && *_mFile.getVal(fField.at(i))=='\0' ){ _existNullIN  = true; }
				_oFile.writeStr(_mFile.getVal(fField.at(i)),ret);
			}
		// mstのみ書き出す
		}else if( _m_outer && cmpflg>0 ){
			if(_assertNullOUT){ _existNullOUT = true;}
			for( size_t i=0; i<_iFile.fldSize(); i++){
				_oFile.writeStr("",false);
			}
			for(vector<int>::size_type i=0; i<fField.size(); i++){
				bool ret=false;
				if(i==fField.size()-1) ret=true;
				_oFile.writeStr(_mFile.getVal(fField.at(i)),ret);
			}
		// traのみ書き出す
		}else if( _i_outer && cmpflg<0 ){
			if(_assertNullOUT){ _existNullOUT = true;}
			for( size_t i=0; i<_iFile.fldSize(); i++){
				_oFile.writeStr(_iFile.getVal(i),false);
			}
			for(vector<int>::size_type i=0; i<fField.size(); i++){
				bool ret=false;
				if(i==fField.size()-1) ret=true;
				_oFile.writeStr("",ret);
			}
		}
	}
	// 終了処理
	_iFile.close();
	_mFile.close();
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
