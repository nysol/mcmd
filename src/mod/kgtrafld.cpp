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
// kgtrafld.cpp 一般項目→ベクトル型項目変換クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <kgtrafld.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;



// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgTrafld::kgTrafld(void)
{
	_name    = "kgtrafld";
	_version = "###VERSION###";

	#include <help/en/kgtrafldHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgtrafldHelp.h>
	#endif


}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgTrafld::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,a=,delim=,delim2=,-r,-valOnly",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	ifname_ = _args.toString("i=",false);
	_iFile.open(ifname_, _env,_nfn_i);
	_iFile.read_header();

	// -r 反転フラグ
	_reverse = _args.toBool("-r");

	// -valOnly 項目名は出力しないフラグ
	_valOnly = _args.toBool("-valOnly");

	// f= 項目引数のセット(f=が指定されたときはその並びで出力)
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
	//		i=の指定がなければf=が必須,
	if(_reverse){
		if(s_a.empty()){
			throw kgError("parameter a= is mandatory");
		}
		_fField.set(s_a, &_iFile,_fldByNum);
		if(vvs[0].size()==0 && ifname_.empty()){
			throw kgError("parameter i= is mandatory, when f= is not specified with -r.");
		}
		_newFlds=vvs;
	}
	else{
		_fField.set(vvs, &_iFile,_fldByNum);
		if(_fField.size()==0){
			throw kgError("paramter f= is mandatory, when -r is not specified");
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
		ss << "delim= takes 1 byte charactor (" <<  s_d << ")";
		throw kgError(ss.str());
	}
	else{
		_delim=*(s_d.c_str());
	}

	// delim2=項目引数セット
	kgstr_t s_d2 = _args.toString("delim2=",false);
	if(s_d2.empty()){
		_delim2='=';
	}
	else if(s_d2.size()!=1){
		ostringstream ss;
		ss << "delim2= takes 1 byte charactor (" <<  s_d2 << ")";
		throw kgError(ss.str());
	}
	else{
		_delim2=*(s_d2.c_str());
	}

	if(_delim == _delim2){
		throw kgError("The same character as delim and delim2 cannot be used. ");
	}

	if(_reverse && _valOnly){
		throw kgError("-r cannot be specified with -valOnly. ");
	}

}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgTrafld::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	//横から縦へ
	if(_reverse){
		set<kgstr_t> fldname;

		//f=の指定が無かった場合一度データを読み込み項目名を取得する
		//f=の指定があった場合はf=で指定されたものを出力する項目名とする
		if(_newFlds[0].size()==0){
			while( EOF != _iFile.read() ){
				kgstr_t sepaword =  _iFile.getVal(_fField.num(0)) ;
				vector< vector<kgstr_t> > sepafld(2);
				if(! sepaword.empty()){
					sepafld = transVector(splitToken2(sepaword,_delim,_delim2), 2);
				}
				for(vector<kgstr_t>::size_type i=0;i<sepafld[0].size();i++){
					fldname.insert(sepafld[0][i]);			
				}
			}
			_iFile.seekTop();
		}

		//ヘッダ出力
		if(!_nfn_o){
			vector<kgstr_t> outfld;
			for(size_t i=0; i<_iFile.fldSize(); i++){
				// a=指定項目でなければ出力
				if( _fField.flg(i)==-1) {
					outfld.push_back(_iFile.fldName(i,true));
				}
			}
			//f=が指定されているときは指定された順番で出力する。
			if(_newFlds[0].size()==0){
				for(set<kgstr_t>::iterator j=fldname.begin();j!=fldname.end();j++){
					outfld.push_back(*j);
				}
			}
			else{
				for(vector<kgstr_t>::size_type j=0;j<_newFlds[0].size();j++){
					outfld.push_back(_newFlds[0].at(j));
				}
			}
			_oFile.writeFldNameCHK(outfld);
		}

		//データ出力
		while( EOF != _iFile.read() ){
			//mapで項目名と値をセット
			map<kgstr_t,char*> outfld;
			kgstr_t sepaword =  _iFile.getVal(_fField.num(0));
			vector< vector<kgstr_t> > sepafld(2);
			if(! sepaword.empty()){
				sepafld = transVector(splitToken2(sepaword,_delim,_delim2), 2);
			}
			else{
				if(_assertNullIN) { _existNullIN  = true;}
			}
			vector< string > sepafld_s;
			for(vector<string>::size_type i=0;i<sepafld[0].size();i++){
				sepafld_s.push_back(sepafld[1][i]);
			}
			for(vector<kgstr_t>::size_type i=0;i<sepafld[0].size();i++){
				outfld[sepafld[0][i]]= const_cast<char*>(sepafld_s.at(i).c_str());
			}
			//キー項目部分出力a=で指定した項目は出力しない
			for(size_t i=0; i<_iFile.fldSize(); i++){
				if( _fField.flg(i)==-1){
					_oFile.writeStr( _iFile.getVal(i), false);
				}
			}
			//値の出力:項目名一覧(set)の内容今回読み込んだものにあれば(map)値を出力、なければnull
			//f=が指定されているときは指定された順番で出力する。
			if(_newFlds[0].size()==0){
				for(set<kgstr_t>::iterator j=fldname.begin();j!=fldname.end();j++){
					if(j!=fldname.begin()) _oFile.writeDlm();
					map<kgstr_t,char*>::iterator i = outfld.find(*j);
					if( i != outfld.end() ){ _oFile.writeStr(i->second);}
					else { if(_assertNullOUT){ _existNullOUT = true;}  }
				}
				_oFile.writeEol();
			}
			else{//f=が指定されている場合
				for(vector<kgstr_t>::size_type j=0;j<_newFlds[0].size();j++){
					if(j!=0)_oFile.writeDlm();
					map<kgstr_t,char*>::iterator i = outfld.find(_newFlds[0].at(j));
					if( i != outfld.end() ){ _oFile.writeStr(i->second); }
					else { if(_assertNullOUT){ _existNullOUT = true;}  }
				}
				_oFile.writeEol();
			}
		}
	}
	//縦から横へ
	else{

		// 項目名出力
		if(!_nfn_o){
			vector<kgstr_t> outfld;
			for(size_t i=0; i<_iFile.fldSize(); i++){
				// a=指定項目でなければ出力
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
	
			//f=で指定した項目以外の出力
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
				char* str = _iFile.getVal(_fField.num(i));
				if(*str=='\0'){
					if(_assertNullIN) { _existNullIN  = true;}
					 continue;
				}

				if(cnt!=0){
					if(pos+1>KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN" ); }
					*(outstr+pos) =  _delim ;
					pos++;
				}

				// second項目名が有ればそちらを有効
				kgstr_t oName=_fField.attr(i);           
				if( oName.empty()) oName=_fField.name(i);

				if(!_valOnly){
					const char * strtmp = oName.c_str();
					size_t len = strlen(strtmp);
					if(pos+len+1>KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN" ); }
					strncpy(outstr+pos,strtmp,len);
					*(outstr+pos+len) =  _delim2 ;
					pos += (len+1);						
				}
				size_t len = strlen(str);
				if(pos+len>KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN" ); }
				strncpy(outstr+pos,str,len);
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
