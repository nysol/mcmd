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
// kgsep.cpp 行の複数ファイルへの分割
// =============================================================================
#include <cstdio>
#include <string>
#include <vector>
#include <kgsep.h>
#include <kgCSVutils.h>
#include <kgError.h>
#include <boost/filesystem.hpp>

using namespace boost;
using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSep::kgSep(void)
{
	_name    = "kgsep";
	_version = "###VERSION###";

	#include <help/en/kgsepHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsepHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSep::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("d=,i=,-p,-q,f=,s=",kgArgs::COMMON|kgArgs::NULL_IN);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
	_iFile.read_header();

	// d= 項目のセット
	kgstr_t str = _args.toString("d=",true);
	_dField_str = evalFileFldName(str,_iFile,_dField,_fldByNum);

	vector<kgstr_t> vf = _args.toStringVector("f=",false);

	// s= 項目引数のセット
	vector< vector<kgstr_t> > vs_s = _args.toStringVecVec("s=","%",2,false);

	bool seqflg = _args.toBool("-q");


	if(_nfn_i) { seqflg = true; }
	if(!seqflg){ 

		vector<kgstr_t> vsk;
		if(_fldByNum){
			for(size_t i=0;i<_dField.size();i++){
				vsk.push_back( toString(_dField[i]) );
			}
		}
		else{
			for(size_t i=0;i<_dField.size();i++){
				vsk.push_back( _iFile.fldName(_dField[i]) );
			}
		
		}
		vector<kgstr_t> vs_ss = _args.toStringVector("s=",false);
		vsk.insert(vsk.end(),vs_ss.begin(),vs_ss.end());

		sortingRun(&_iFile,vsk);
	}

	_fField.set(vf, &_iFile,_fldByNum);

	_sField.set(vs_s, &_iFile,_fldByNum);

	// -p
	_mkdir_flg = _args.toBool("-p");
	
}

void kgSep::writeFldName() throw(kgError)
{
	if( _oFile.noFldName( ) ) return;
	if (_fField.size()==0){
		if(_sField.size()!=0){
			_oFile.writeFldName(_sField,kgstr_t("%"));
		}
		else{		
			_oFile.writeFldName(_iFile);
		}
	}else{
		if(_sField.size()!=0){
			/*
			vector<kgstr_t> outfld;
			for(size_t i=0; i<_fField;i++){
			 = _fField.getName();
			kgstr_t oName;
			*/
			vector<kgstr_t> outfld;
			for(size_t i=0; i<_fField.size();i++){
				kgstr_t oName;
				oName = _iFile.fldName(_fField.num(i));
				oName.append(_iFile.sortParaStr(_fField.num(i),_dField.size()));
				outfld.push_back(oName);
			}
			_oFile.writeFldName(outfld,_rp);

		}
		else{

			//vector<kgstr_t> outfld = _fField.getName();
			//_oFile.writeFldName(outfld);
			vector<kgstr_t> outfld;
			for(size_t i=0; i<_fField.size();i++){
				kgstr_t oName;
				oName = _iFile.fldName(_fField.num(i));
				oName.append(_iFile.sortParaStr(_fField.num(i)));
				outfld.push_back(oName);
			}
			_oFile.writeFldName(outfld,_rp);
		
		}
	}
} 

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSep::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_dField);

	// データ出力
	while(_iFile.read()!=EOF){
		//keybreak or最初はファイル名を生成
		if( _iFile.keybreak() || _iFile.begin() ){
			if( _iFile.keybreak() ) { _oFile.close();}
			if((_iFile.status() & kgCSV::End )) break;
			/*ファイル名生成*/
			kgstr_t fstr;
			vector<kgstr_t>::size_type i=0;
			for(vector<int>::size_type j=0;j<_dField.size();j++,i++){
				if(_assertNullIN && *_iFile.getNewVal(_dField[j])=='\0') { _existNullIN  = true;}
				fstr = fstr+ _dField_str[i] + _iFile.getNewVal(_dField[j]);			
			}
			fstr = fstr+_dField_str[i];
			if(_mkdir_flg){
				filesystem::path filename=filesystem::path(fstr);
				filesystem::path dirname =filename.branch_path();
				create_directories(dirname);
			}
			// ファイルオープン
			_oFile.open(fstr, _env,_nfn_o);
			writeFldName();

		}
		//通常処理
			if (_fField.size()==0){
				_oFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
			}else{
				vector<int>	vt = _fField.getNum();
				_oFile.writeFld(_iFile.getNewFld(),&vt);
			}
	}
	// 終了処理
	th_cancel();
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
