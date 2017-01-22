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
// kgcommon.cpp 参照ファイルによる行選択クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <kgcommon.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgCommon::kgCommon(void)
{
	_name    = "kgcommon";
	_version = "###VERSION###";

	#include <help/en/kgcommonHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcommonHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgCommon::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,m=,k=,K=,u=,-r,q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_KEY);

	// 入出力ファイルオープン
	kgstr_t ifile = _args.toString("i=",false);
	kgstr_t mfile = _args.toString("m=",false);
	kgstr_t ufile = _args.toString("u=",false);
	if(ifile.empty() && mfile.empty()){
		throw kgError("Either i= or m= must be specified.");
	}
	_iFile.open(ifile,_env,_nfn_i);
	_mFile.open(mfile,_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	if(ufile.empty()){ _elsefile=false; }
	else {
		_elsefile=true;
		_uFile.open(ufile,_env,_nfn_o);
	}		
	_iFile.read_header();
	_mFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",true);

	// K= 項目引数のセット
	// K=の指定がなければk=の値をセットする
	vector<kgstr_t> vs_K = _args.toStringVector("K=",false);
	if(vs_K.empty()){ vs_K =vs_k;}

	// k=とK=の数があっている化チェック
	if(vs_K.size()!=vs_k.size()){
		ostringstream ss;
		ss << "not match keyfield size k:" << _kField.size() << " K:" << _KField.size() ;
		throw kgError(ss.str());
	}
	// -r 条件反転
	_reverse = _args.toBool("-r");
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	vector<kgCSVfld*> csv_p;  
	vector< vector<kgstr_t> > fld_ary;  
	csv_p.push_back(&_iFile);
	csv_p.push_back(&_mFile);
	fld_ary.push_back(vs_k);
	fld_ary.push_back(vs_K);
	if ( !seqflg ) { sortingRun(csv_p,fld_ary);}

	_kField.set(vs_k, &_iFile, _fldByNum);
	_KField.set(vs_K, &_mFile, _fldByNum);	
	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCommon::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();	
	// 項目名出力
	_oFile.writeFldName(_iFile);
	if(_elsefile){ _uFile.writeFldName(_iFile); }

	// keyサイズとデータセット
	int ksize = _kField.size();
	vector<int> kField =_kField.getNum();
	vector<int> KField =_KField.getNum();

	//比較結果用フラグ
	int cmpflg=0;
	bool mstEnd=false;
	bool begin=true;

	// データ出力(入力ファイルあるいは参照ファイルどちらか最後まで読み込むまで)
	while(true){
		// traの読み込み
		if(cmpflg<=0){ if(_iFile.read() == EOF) break; }
		// mstの読み込み
		if(cmpflg>0 || begin){
			if(_mFile.read() == EOF){ mstEnd=true; }
			begin=false;
		}
		// traとmstのキーの比較 (tra - mstの演算結果)
		if(mstEnd){
			cmpflg=-1;
		}else{
			cmpflg=0;
			for(int i=0;i<ksize;i++){
				if(_assertNullKEY) { 
					if( *(_iFile.getVal(kField[i]))=='\0' || *(_mFile.getVal(KField[i]))=='\0'){
						_existNullKEY = true;
					}
				}
				cmpflg = strcmp( _iFile.getVal(kField[i]), _mFile.getVal(KField[i]) );
				if(cmpflg!=0) break;
				//両方共NULLならアンマッチとする
				if( *(_iFile.getVal(kField[i]))=='\0' && *(_mFile.getVal(KField[i]))=='\0'){
					cmpflg=1;
					break;
				}
			}
		}
		// 一致
		if( (cmpflg==0 && !_reverse) || (cmpflg<0 && _reverse) ){
			_oFile.writeFld(_iFile.fldSize(),_iFile.getFld());
		}
		if(_elsefile){
			if( (cmpflg==0 && _reverse) || (cmpflg<0 && !_reverse) ){
				_uFile.writeFld(_iFile.fldSize(),_iFile.getFld());
			}
		}
	}
	//ソートスレッドを終了させて、終了確認
	//for(size_t i=0 ;i<_th_st.size();i++){ pthread_cancel(_th_st[i]->native_handle());	}
	//for(size_t i=0 ;i<_th_st.size();i++){ pthread_join(_th_st[i]->native_handle(),NULL);}
	// 終了処理
	th_cancel();
	_iFile.close();
	_mFile.close();
	_oFile.close();
	if(_elsefile){ _uFile.close(); }
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
