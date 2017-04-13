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
// ============================================================================
// 複数ファイルの併合
// ============================================================================
#include <cstdio>
#include <sstream>
#include <kgcat.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgCat::kgCat(void)
{
	_name    = "kgcat";
	_version = "###VERSION###";
	_iCnt    = 0;

	#include <help/en/kgcatHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcatHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 引数の設定
// -----------------------------------------------------------------------------
void kgCat::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,flist=,o=,f=,-skip,-nostop,-force,-skip_fnf,-add_fname,-stdin,kv=,-skip_zero",
				kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN);

	// 項目名指定
	_fvstr = _args.toStringVector("f=",false);

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// フラグセット
	// (-skip_fnf,-add_fname,-stdin,-force,-skip,-nostop")
	// -force,-skip,-nostopのいずれか指定されていれば
	// _stopがfalse(項目名違っていてもERRORにならないようにする)
	// -force,-skipは同時に指定できない
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	_skip_fnf = _args.toBool("-skip_fnf");
	_add_fn   = _args.toBool("-add_fname");
	_stdin    = _args.toBool("-stdin");
	_force		= _args.toBool("-force");
	_skip 		= _args.toBool("-skip");
	_zskip 		= _args.toBool("-skip_zero");
	
	_stop			= !(_force || _skip || _args.toBool("-nostop"));
	_is_f     = !_fvstr.empty();
	if(_skip && _force){ throw kgError("choose one from -force or -skip");}

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// 入力ファイル名取得（ファイルオープンはしない）
	// _stdin==trueで最初のファイル名は""(標準入力)
	// ファイルが一つもなければエラー
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	vector<kgstr_t> vs = _args.toStringVector("i=",false);
	vector< vector<kgstr_t> > vsf = _args.toStringVecVec("flist=",':',2,false);
	if(!vsf.empty()){
		for(size_t i=0;i<vsf[0].size();i++){
			kgCSVfld iFileL;
			kgArgFld fFieldL;	
			iFileL.open(vsf[0][i], _env,_nfn_i);
			iFileL.read_header();

			fFieldL.set(vsf[1][i], &iFileL, _fldByNum);
			// ファイルリスト読み込み
			while( EOF != iFileL.read() ){ vs.push_back(iFileL.getVal(fFieldL.num(0))); }
			iFileL.close();
		}
	}
	_iFilename = kgFilesearch(vs,_skip_fnf,_stdin);
	if(_iFilename.empty()){ throw kgError("all files on i= are not found");	}

	// o= 出力ファイルオープン
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);

	vector<kgstr_t> vskv = _args.toStringVector("kv=",false);
	if (vskv.size()!=0) {
		for ( size_t i=0 ;i < vskv.size();i++){
			_kv.push_back(aToSizeT(vskv[i].c_str()));
		}
	}

}
// -----------------------------------------------------------------------------
// データ出力
// -----------------------------------------------------------------------------
void kgCat::output(kgCSVfld* csv)
{
	if(!csv->opened()) return;
	vector<int> outFldNo;
	if(_force){ // 強制併合
		size_t i;
		for(i=0; i<_fldSize; i++){
			if(i < csv->fldSize() ) { outFldNo.push_back( i);}
			else                    { outFldNo.push_back(-1);}
		}
	}else{
		if(csv->noFldName()){ // 項目名行なしの場合
			if(csv->fldSize() < _fldSize){
				if(_stop){
					ostringstream ss;
					ss << "the number of fields is less than [" << _fldSize
						<< "] on file [" << csv->fileName() << "]";
					throw kgError(ss.str());
				}
				if(_skip){ return; }
			}
			if(_is_f){ // f=指定あり 指定項目を選択
				for(size_t i=0; i<_fldSize; i++){
					if(i < csv->fldSize() ){ outFldNo.push_back(_fField.getNum().at(i));}
					else                   { outFldNo.push_back(-1);}
				}
			}else{
				for(size_t i=0; i<_fldSize; i++){
					if(i < csv->fldSize() ) { outFldNo.push_back( i);}
					else                   	{ outFldNo.push_back(-1);}
				}
			}
		}else{ // 項目名行ありの場合
			for(size_t i=0; i<_fldSize; i++){
				int no=csv->fldNum(_fldNames.at(i),true);
				if(no==-1){
					if(_stop){
						ostringstream ss;
						ss << "field name [" << _fldNames.at(i)
						  << "] not found on file ["   << csv->fileName() << "]";
						throw kgError(ss.str());
					}
					if(_skip)return;
				}
 				outFldNo.push_back(no);
			}
		}
	}
	// ファイル名スプリット
	vector<vector <kgstr_t> > fsplit;
	string fn = csv->fileName();
	fsplit = splitToken2(fn, '/','_'); 
	int endpos = fsplit.size()-1;

	// 出力実行
	while( EOF != csv->read() ){
		_iCnt++;
		if(_assertNullIN) { if(csv->isNull(outFldNo) ){_existNullIN  = true; } }
		if(_kv.size()!=0){
			_oFile.writeFld(csv->getFld(),&outFldNo,false);
			if (_add_fn){ _oFile.writeStr(csv->fileName().c_str(), false ); }
			for(size_t i=0;i<_kv.size();i++){
				int pos =  endpos - _kv[i];
				if(pos<0 || fsplit[pos].size()<2){
					_oFile.writeStr("", i == _kv.size()-1);
				}
				else{
					for(size_t j=1;j<fsplit[pos].size();j+=2){
						_oFile.writeStr(fsplit.at(pos).at(j).c_str(), i == _kv.size()-1 &&  j==fsplit[pos].size()-1 );
					}

				}
			}
		}else if (_add_fn){
			_oFile.writeFld(csv->getFld(),&outFldNo,false);
			_oFile.writeStr(csv->fileName().c_str(), true );
		}else{
			_oFile.writeFld(csv->getFld(),&outFldNo);
		}
	}	
}
// -----------------------------------------------------------------------------
// 処理ファイルセット
//  fnameで指定されたファイルのヘッダまで読み込む
// -----------------------------------------------------------------------------
int kgCat::readFile_set(kgstr_t fname)
{
	if(fname=="")	{ _iCsv = &_iFile; }
	else					{ _iCsv = new kgCSVfld;}
	if( _iCsv->opened()==false ){
		_iCsv->open(fname, _env, _nfn_i);
		try {
			_iCsv->read_header();
		}catch(kgError& err){
			if( _zskip && err.message(0).find("no data found :")!=string::npos ){
				return 1;
			}
			throw err;
		}
	}
	return 0;
}
// -----------------------------------------------------------------------------
// 処理ファイル解除
//  _iCsvで指定されているファイルをクローズする（標準入力の場合はSKIP）
// -----------------------------------------------------------------------------
void kgCat::readFile_unset()
{
	if(!_iCsv->isStdin()){
		_iCsv->close();
		delete _iCsv;
	}
	return;
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCat::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// 出力項目名or出力項目数決定
	// データがある最初ファイルの項目名or項目数を基準とする
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	for( _inf_pos = 0; _inf_pos<_iFilename.size(); _inf_pos++ ){
		if(readFile_set( _iFilename.at(_inf_pos) )){
			readFile_unset();
			continue;
		}
		if(0==_iCsv->fldSize()){ 
			readFile_unset();
			continue;
		}
		if(_is_f){
			_fField.set(_fvstr, _iCsv, _fldByNum);
			_fldNames = _fField.getName();
			_fldSize  = _fField.size();
		}else{
			_fldNames = _iCsv->fldName();
			_fldSize  = _iCsv->fldSize();
		}
		readFile_unset();
		break;
	}

	// 項目名の出力
	vector<kgstr_t> fldtNames = _fldNames;
	if(_add_fn){ 
		fldtNames.push_back("fileName"); 
	}
	if(_kv.size()!=0){
		// ファイル名スプリット
		vector<vector <kgstr_t> >  fsplit;
		string fn = _iFilename.at(_inf_pos);
		fsplit = splitToken2(fn, '/','_'); 
		int endpos = fsplit.size()-1;
		for(size_t i=0;i<_kv.size();i++){
			int pos =  endpos - _kv[i];
			if(pos<0){ throw kgError("kv key not found");}
			for(size_t j=0;j<fsplit[pos].size();j+=2){
				fldtNames.push_back(fsplit[pos][j]);
			}
		}
	}
	if(!_nfn_o){ _oFile.writeFldName(fldtNames);  }

	// データの出力
	for( ; _inf_pos<_iFilename.size(); _inf_pos++ ){
		if(readFile_set( _iFilename.at(_inf_pos) )){
			readFile_unset();
			continue;
		}
		if(_iCsv->fldSize()!=0) { output(_iCsv); }
		readFile_unset();
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
