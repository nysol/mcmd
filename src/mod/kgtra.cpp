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
// kgtra.cpp 一般項目→ベクトル型項目変換
// =============================================================================
#include <cstdio>
#include <sstream>
#include <kgConfig.h>
#include <vector>
#include <kgtra.h>
#include <kgError.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgTra::kgTra(void)
{
	_name    = "kgtra";
	_version = "###VERSION###";

	#include <help/en/kgtraHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgtraHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgTra::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,delim=,-r,s=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
	_iFile.read_header();

	// -r 反転フラグ
	_reverse = _args.toBool("-r");

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	//-rの指定がある時はk=の指定はできない
	if(_reverse){
		if(vs.size()!=0){
				throw kgError("k= can not be specified with -r. ");
		}
	}

	// delim=項目引数セット
	kgstr_t s_d = _args.toString("delim=",false);
	if(s_d.empty()){ _delim=' ';}
	else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= takes 1 byte charactor (" <<  s_d << ")";
		throw kgError(ss.str());
	}
	else{
		_delim=*(s_d.c_str());
	}
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	vector<kgstr_t> vss = _args.toStringVector("s=",false);

	if(!seqflg && ( !vs.empty()||!vss.empty())){ 
		vector<kgstr_t> vsk	= vs;
		vsk.insert(vsk.end(),vss.begin(),vss.end());
		sortingRun(&_iFile,vsk);
	}

	_kField.set(vs,  &_iFile,_fldByNum);
	_fField.set(vvs, &_iFile,_fldByNum);
	if(_fField.size()!=1){
		ostringstream ss;
		ss << "f= takes just one field: f= size:" << _fField.size() ;
		throw kgError(ss.str());
	}


}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgTra::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名出力
	if(!_nfn_o){
		vector<kgstr_t> outfld;
		for(size_t i=0; i<_iFile.fldSize(); i++){
			if(_fField.flg(i)==-1) outfld.push_back(_iFile.fldName(i,true)); 
		}
		for(string::size_type  i=0; i<_fField.size(); i++){
			kgstr_t oName=_fField.attr(i); 
			if( oName.empty()) oName=_fField.name(i);
			outfld.push_back(oName); 
		}
		_oFile.writeFldNameCHK(outfld);
	}

	//横から縦へ変換
	if(_reverse){

		while(_iFile.read()!=EOF){

			if((_iFile.status() & kgCSV::End )) break;

			//指定したfieldを区切り文字で分割し一行ずつ出力する
			//0件だった場合は一行のみ出力する
			kgstr_t sepaword =  _iFile.getNewVal(_fField.num(0));
			if(_assertNullIN && sepaword.size()==0) { _existNullIN  = true;}

			vector<kgstr_t> sepafld = splitToken( sepaword ,_delim);

			for(vector<kgstr_t>::size_type i=0;i< sepafld.size();i++){
				for(size_t j=0; j<_iFile.fldSize(); j++){
					if( _fField.flg(j)==-1){
					 	_oFile.writeStr( _iFile.getNewVal(j), false);
					}
				}
				_oFile.writeStr(sepafld.at(i).c_str(),true);
			}

			if(sepafld.size()==0){
				for(size_t j=0; j<_iFile.fldSize(); j++){
					if( _fField.flg(j)==-1){
					 	_oFile.writeStr( _iFile.getNewVal(j), false);
					}
				}
				_oFile.writeEol();
				if(_assertNullOUT){ _existNullOUT = true;}
			}
		}
	}
	// 縦から横への変換
	else{

		//出力情報
		char outstr[KG_MAX_STR_LEN];
		size_t pos=0;
		bool writeflg=false;

		while(_iFile.read()!=EOF){

			//最初の一行め
			if(( _iFile.status() & kgCSV::Begin )){
				for(size_t i=0; i<_iFile.fldSize(); i++){
					if( _fField.flg(i)==-1){
					 	_oFile.writeStr( _iFile.getNewVal(i), false);
					}
				}
				writeflg=false;
			}

			//keybreakしたら改行して次の行の項目を出力
			else if( _iFile.keybreak() ){

				//出力処理
				if(_assertNullOUT && pos==0){ _existNullOUT = true;}
				*(outstr+pos)='\0';
				_oFile.writeStr(outstr,true);
				pos=0;

				// ENDなら終了
				if((_iFile.status() & kgCSV::End )) break;

				for(size_t i=0; i<_iFile.fldSize(); i++){
					if( _fField.flg(i)==-1){
					 	_oFile.writeStr( _iFile.getNewVal(i), false);
					}
				}
				writeflg=false;
			}
			
			// 通常：区切り文字出力
			else{
				if(writeflg){
					if(pos+1>KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN" ); }
					*(outstr+pos) =  _delim ;
					pos++;
				}
				writeflg=false;
			}

			//tra部分書き込み(NULLの場合はSKIPする)
			char *strtmp = _iFile.getNewVal(_fField.num(0));
			if(*strtmp!='\0'){
				size_t len = strlen(strtmp);
				if(pos+len>KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN" ); }
				strncpy(outstr+pos,strtmp,len);
				pos += len;
				writeflg=true;
			}
			else{
				if(_assertNullIN) { _existNullIN  = true;}
			}

		}
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理
	th_cancel();
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
