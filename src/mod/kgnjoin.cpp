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
// kgnjoin.h 参照ファイル項目の自然結合
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <kgnjoin.h>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgNjoin::kgNjoin(void)
{
	_name    = "kgnjoin";
	_version = "###VERSION###";

	#include <help/en/kgnjoinHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgnjoinHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgNjoin::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,m=,k=,K=,-n,-N,bufcount=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン&バッファ設定
	kgstr_t ifile = _args.toString("i=",false);
	kgstr_t mfile = _args.toString("m=",false);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o,_rp);
	if(ifile.empty() && mfile.empty()){
		throw kgError("Either i= or m= must be specified.");
	}
	_iFile.open(ifile,_env,_nfn_i);
	_mFile.open(mfile,_env,_nfn_i);

	kgstr_t s=_args.toString("bufcount=",false);
	int bcnt = 10;
	if(!s.empty()){ 
		bcnt = atoi(s.c_str());
		if(bcnt<=0){ bcnt=1;}
	}
	_mFile.setbufsize(bcnt);
	_iFile.read_header();
	_mFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",true);

	// K= 項目引数のセット
	// K=の指定がなければk=の値をセットする
	vector<kgstr_t> vs_K = _args.toStringVector("K=",false);
	if(vs_K.empty()){ vs_K = vs_k;}



	// k=とK=の数があっているかチェック
	if(vs_k.size()!=vs_K.size()){
		ostringstream ss;
		ss << "not match keyfield size k:" << vs_k.size() << " K:" << vs_K.size() ;
		throw kgError(ss.str());
	}

	// f= 項目引数のセット指定が無かった場合はk=の項目以外をセットする
	vector< vector<kgstr_t> >  vvs = _args.toStringVecVec("f=",':',2,false);

	// -n,-N アウタージョインフラグ
	_i_outer = _args.toBool("-n");
	_m_outer = _args.toBool("-N");

	vector<kgCSVfld*> csv_p;  
	vector< vector<kgstr_t> > fld_ary;  
	csv_p.push_back(&_iFile);
	csv_p.push_back(&_mFile);
	fld_ary.push_back(vs_k);
	fld_ary.push_back(vs_K);

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if( !seqflg ){ sortingRun(csv_p,fld_ary);}

	_kField.set(vs_k, &_iFile,_fldByNum);
	_KField.set(vs_K, &_mFile,_fldByNum);

	// f= 項目引数のセット指定が無かった場合はk=の項目以外をセットする
	if(!vvs[0].empty()){ _fField.set(vvs, &_mFile, _fldByNum); }
	else {
		for(size_t i=0 ; i< _mFile.fldSize();i++){
			int num= _KField.getFlg().at(i);
			if(num == -1) {
				vvs[0].push_back(toString(i));				
				vvs[1].push_back("");				
			}
		}
		_fField.set(vvs, &_mFile,true);
	}

}



// -----------------------------------------------------------------------------
// データ出力
// -----------------------------------------------------------------------------
void kgNjoin::writeTM(void)
{
	//参照ファイルのデータをセット
	_mFile.blkset();

	//参照ファイルの出力項目セット
	vector<int> fField =_fField.getNum();

	// データ出力(入力ファイルに対して参照ファイルの全データをマッチして出力)
	// 参照ファイルは入力ファイルを読み込むたびに位置を先頭行へセットしなおす
	while(1){
		while(_mFile.blkread() != EOF){
			if(_assertNullIN && _mFile.isNull(fField) ){ _existNullIN = true; }
			_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),_mFile.getBlkFld(),&fField);
		}
		_iFile.read();
		if( _iFile.keybreak() ){break;}
		_mFile.seekBlkTop();
	}
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgNjoin::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力,参照ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());
	_mFile.setKey(_KField.getNum());

	// 項目名出力
	_oFile.writeFldName(_iFile,_fField,true);

	// keyサイズとデータセット
	int ksize = _kField.size();
	vector<int> kField =_kField.getNum();
	vector<int> KField =_KField.getNum();
	vector<int> fField =_fField.getNum();

	//比較結果用フラグ
	int cmpflg=0;

	//一行め読み込み
	_mFile.read();
	_iFile.read();

	// メイン処理
	while( 1 ){
		if((_iFile.status() & kgCSV::End )|| (_mFile.status() & kgCSV::End )){ break;}
		for(int i=0;i<ksize;i++){
			cmpflg = strcmp( 
				_iFile.getNewVal(kField[i]), 
				_mFile.getNewVal(KField[i]) 
				);
			if(cmpflg!=0){break;}
			//両方共NULLならアンマッチとする
			if( *(_iFile.getNewVal(kField[i]))=='\0' && *(_mFile.getNewVal(KField[i]))=='\0'){
				cmpflg=1;
				break;
			}
		}
		// 一致したら出力
		if(cmpflg==0){ writeTM(); }
		// 参照ファイルの方が小さい(参照の次の行を読み込む)
		// _m_outer(-N)が指定されている場合、
		//	現参照行をキー単位でno_matchとして書き出す
		else if(cmpflg>0){
			while(1){
				if(_m_outer==true){
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeFld(_kField.getFlg_p(),&KField,_mFile.getNewFld(),&fField);
				}
				_mFile.read();
				if( _mFile.keybreak() ){break;}
			}
		}
		// 参照ファイルの方が大きくなった
		// (_i_outer(-n)が指定されていればno_matchとして書き出す)
		else{
			while(1){
				if(_i_outer==true){
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
				}
				_iFile.read();
				if( _iFile.keybreak() ){break;}
			}
		}
	}

	//入力ファイルのデータが残っていた場合のデータ出力
	if(!(_iFile.status() & kgCSV::End ) ==true){
		if(_i_outer){
			if(_assertNullOUT){ _existNullOUT = true;}
			while(1){
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
				_iFile.read();
 				if(_iFile.status() & kgCSV::End){ break;} 
			}
		}
	}
	//参照ファイルのデータが残っていた場合のデータ出力
	else if(!(_mFile.status() & kgCSV::End ) && _m_outer==true){
		if(_assertNullOUT){ _existNullOUT = true;}
		while(1){
			_oFile.writeFld(_kField.getFlg_p(),&KField,_mFile.getNewFld(),&fField);
			_mFile.read();
 			if(_mFile.status() & kgCSV::End){ break;} 
		}
	}
	//ソートスレッドを終了させて、終了確認
	//for(size_t i=0 ;i<_th_st.size();i++){ pthread_cancel(_th_st[i]->native_handle()); }
	//for(size_t i=0 ;i<_th_st.size();i++){ pthread_join(_th_st[i]->native_handle(),NULL);}

	if(_assertNullKEY) { _existNullKEY = _iFile.keynull()||_mFile.keynull(); }
	// 終了処理(メッセージ出力,thread pipe終了通知)
	th_cancel();
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
