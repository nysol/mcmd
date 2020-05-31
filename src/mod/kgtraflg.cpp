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
// kgtraflg.cpp 一般項目→ベクトル型項目変換クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <kgtraflg.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgTraflg::kgTraflg(void)
{
	_name    = "kgtraflg";
	_version = "###VERSION###";

	#include <help/en/kgtraflgHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgtraflgHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgTraflg::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,a=,delim=,-r",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
	_iFile.read_header();

	// -r 反転フラグ
	_reverse = _args.toBool("-r");

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,false);

	// a= 出力項目名
	kgstr_t s_a  = _args.toString("a=",false);

	// a=,f=は-rの指定があるか無いかによってセット及びチェックの仕方を変える
	// -rが無い場合
	//		a=は-nfnoなど項目名を出力しない場合を除き必須
	//		f=は必須
	//		a=の値はトランザクションデータの項目名として使用する、
	//		f=の値はトランザクションデータの元になるデータを指定する
	// -rがある場合
	//		a=は必須
	//		f=はオプション
	//		a=の値はトランザクションデータを指定
	//		f=の値はトランザクションデータから実際出力する項目(指定がなければ全データ出力する)
	if(_reverse){
		if(s_a.empty()){
			throw kgError("parameter a= is mandatory");
		}
		_fField.set(s_a, &_iFile,_fldByNum);
		_newFlds=vvs;
	}
	else{
		_fField.set(vvs, &_iFile,_fldByNum);
		if(_fField.size()==0){
			throw kgError("When -r is not specified, parameter f= is mandatory");
		}		
		if(s_a.empty()&& _nfn_o==false){
			throw kgError("parameter a= is mandatory");
		}
		_newFld=s_a;
	}

	// delim=項目引数セット
	kgstr_t s_d = _args.toString("delim=",false);
	if(s_d.empty()){
		_delim=' ';
	}
	else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= size is 1 byte (" <<  s_d << ")";
		throw kgError(ss.str());
	}
	else{
		_delim=*(s_d.c_str());
	}

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgTraflg::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	if(_reverse){

		set<kgstr_t> fldname;

		//f=の指定が無かった場合一度データを読み込み項目名を取得する
		//f=の指定があった場合はf=で指定されたものを出力する項目名とする
		if(_newFlds[0].size()==0){
			while( EOF != _iFile.read() ){
				kgstr_t sepaword =  _iFile.getVal(_fField.num(0));
				vector<kgstr_t> sepafld;
				if(! sepaword.empty()){
					sepafld = splitToken(sepaword,_delim);
				}
				for(vector<kgstr_t>::size_type i=0;i<sepafld.size();i++){
					fldname.insert(sepafld[i]);			
				}
			}
			_iFile.seekTop();
		}

		//ヘッダ出力
		if(!_nfn_o){
			vector<kgstr_t> outfldhed;
			for(size_t i=0; i<_iFile.fldSize(); i++){
				// a=指定項目でなければ出力
				if( _fField.flg(i)==-1) {
					outfldhed.push_back(_iFile.fldName(i,true));
				}
			}

			//f=が指定されているときは指定された順番で出力する。
			if(_newFlds[0].size()==0){
				for(set<kgstr_t>::iterator j=fldname.begin();j!=fldname.end();j++){
						outfldhed.push_back(*j);
				}
			}
			else{
				for(vector<kgstr_t>::size_type j=0;j<_newFlds[0].size();j++){
					outfldhed.push_back(_newFlds[0].at(j));
				}
			}
			_oFile.writeFldNameCHK(outfldhed);
		}

		//データ出力
		while( EOF != _iFile.read() ){

			//setで値をセット
			set<kgstr_t> outfld;
			kgstr_t sepaword =  _iFile.getVal(_fField.num(0));
			vector<kgstr_t> sepafld;
			if(! sepaword.empty()){
				sepafld = splitToken(sepaword,_delim);
			}
			else{
				if(_assertNullIN) { _existNullIN  = true;}			
			}
			for(vector<kgstr_t>::size_type i=0;i<sepafld.size();i++){
				outfld.insert(sepafld[i]);			
			}

			//キー項目部分出力a=で指定した項目は出力しない
			for(size_t i=0; i<_iFile.fldSize(); i++){
				if( _fField.flg(i)==-1){
					_oFile.writeStr( _iFile.getVal(i), false);
				}
			}

			//値の出力:項目名一覧(set)の内容今回読み込んだものにあれば(set)値を出力、なければnull
			//f=が指定されているときは指定された順番で出力する。
			if(_newFlds[0].size()==0){
				for(set<kgstr_t>::iterator j=fldname.begin();j!=fldname.end();j++){
					if(j!=fldname.begin()) _oFile.writeDlm();
					set<kgstr_t>::iterator i = outfld.find(*j);
					if( i != outfld.end() ){ _oFile.writeInt(1); }
					else { if(_assertNullOUT){ _existNullOUT = true;}  }
				}
				_oFile.writeEol();
			}
			//f=が指定されている場合
			else{
				for(vector<kgstr_t>::size_type j=0;j<_newFlds[0].size();j++){
					if(j!=0)_oFile.writeDlm();
					set<kgstr_t>::iterator i = outfld.find(_newFlds[0].at(j));
					if( i != outfld.end() ){ _oFile.writeInt(1); }
					else { if(_assertNullOUT){ _existNullOUT = true;}  }
				}
				_oFile.writeEol();
			}
		}		
	}
	else{
		// 項目名出力
		if(!_nfn_o){
			vector<kgstr_t> outfld;
			for(size_t i=0; i<_iFile.fldSize(); i++){
				// f=指定項目でなければ出力
				if( _fField.flg(i)==-1) {
					outfld.push_back(_iFile.fldName(i,true));
				}
			}
			outfld.push_back(_newFld);
			_oFile.writeFldNameCHK(outfld);
		}

		//出力情報
		char outstr[KG_MAX_STR_LEN];

		// データ出力
		while( EOF != _iFile.read() ){
			//キー項目部分出力f=で指定した項目は出力しない
			for(size_t i=0; i<_iFile.fldSize(); i++){
				if( _fField.flg(i)==-1){
					_oFile.writeStr( _iFile.getVal(i), false);
				}
			}

			//位置情報初期化
			size_t pos=0;
			int cnt=0;

			for(unsigned int i=0;i<_fField.size(); i++){
	
				//今回項目の値がNULLかチェック
				if( *(_iFile.getVal(_fField.num(i)))=='\0' ){
					if(_assertNullIN) { _existNullIN  = true;}
					continue;
				}

				if(cnt!=0){
					if(pos+1>KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN" ); }
					*(outstr+pos) =  _delim ;
					pos++;
				}

				// second項目名が有ればそちらを有効
				kgstr_t oName=_fField.attr(i);            // second項目名
				if( oName.empty()) oName=_fField.name(i); // second項目名がない時
				
				const char * strtmp = oName.c_str();
				size_t len = strlen(strtmp);
				if(pos+len>KG_MAX_STR_LEN){ throw kgError("fld length exceeded KG_MAX_STR_LEN" ); }
				strncpy(outstr+pos,strtmp,len);
				pos += len;
				cnt++;
			}
			//出力処理
			*(outstr+pos)='\0';
			_oFile.writeStr(outstr,true);
			if(_assertNullOUT && pos==0){ _existNullOUT = true;}
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
