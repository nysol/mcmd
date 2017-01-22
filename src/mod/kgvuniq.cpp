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
// kgvuniq.cpp ベクトル要素の単一化クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <kgvuniq.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;
namespace {////////////////////////////////////////////////////////////
	struct strComp {
 	 bool operator() (char* a,char* b){
			while(true){
			       if(*a < *b) return  true;
				else if(*a > *b) return  false;
				if(*a=='\0') break; // *a==*b=='\0'
				a++;b++;
			}
			return false;
 	 }
	};
}/////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgVuniq::kgVuniq(void)
{
	_name    = "kgvuniq";
	_version = "###VERSION###";

	#include <help/en/kgvuniqHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgvuniqHelp.h>
	#endif
	
}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgVuniq::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,vf=,delim=,-n,-A",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_iFile.read_header();

	// vf= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("vf=","%:",2,true,true);
	_vfField.set(vvs, &_iFile,_fldByNum);

	// -n フラグ
	_seq  = _args.toBool("-n");

	// delim= 項目引数のセット
	kgstr_t s_d = _args.toString("delim=",false);
	if(s_d.empty()){	
		_delim=' ';
	}else if(s_d.size()!=1){
		ostringstream ss;
		ss << "delim= takes 1 byte charactor (" << s_d << ")";
		throw kgError(ss.str());
	}else{
		_delim=*(s_d.c_str());
	}

	// -A（追加）フラグセット
	_add_flg 		= _args.toBool("-A");

	//文字列生成用領域
	_delimstr[0] =_delim;
	_delimstr[1] ='\0';


}
// -----------------------------------------------------------------------------
// delimでトークン分割を行い分割された文字列をvectorで返す.(順列保持版)
// -----------------------------------------------------------------------------
vector<char*> seqUniqToken(char* str, char delim)
{
  vector<char*> vs;
	unsigned int prv=0;
	unsigned int prvdiff=0;
	unsigned int pos=0;
	bool uniq = false;
	while(1){
		if(*(str+pos) == '\0'){
			if(pos!=0){
				if(!uniq){ vs.push_back(str+prv);}
			}
			break;
		}else if(*(str+pos) == delim){
			*(str+pos) ='\0';
			if(!uniq){ vs.push_back(str+prv);}
			while(*(str+pos+1)==delim){ pos++; }
			prvdiff = pos+1-prv;
			prv=pos+1;
			uniq = true;
		}
		pos++;
		if(!uniq){continue;}
		//ユニークチェック
		//今回値と前回値が違えば不一致
		if(*(str+pos)==*(str+pos-prvdiff) || 
				( *(str+pos)==delim && *(str+pos-prvdiff) =='\0') ){
				continue; 
		}
		uniq = false;
	}
	return vs;
}
// -----------------------------------------------------------------------------
// delimでトークン分割を行い分割された文字列をsetで返す.
// -----------------------------------------------------------------------------
set<char*,strComp> uniqToken(char* str, char delim)
{
  set<char*,strComp> vs;
	unsigned int prv=0;
	unsigned int pos=0;

	while(1){
		if(*(str+pos) == '\0'){
			if(pos!=0){
				vs.insert(str+prv);
			}
			break;
		}else if(*(str+pos) == delim){
			*(str+pos) ='\0';
			vs.insert(str+prv);
			while(*(str+pos+1)==delim){ pos++; }
			prv=pos+1;
		}
		pos++;
	}
	return vs;
}
void kgVuniq::output_n(char *str,bool eol)
{
	*_outstr = '\0'; 
	int len=0;

	if(_seq){
		// _delimでトークン分割
		vector<char*> eachItem = seqUniqToken(str,_delim);
		for(vector<char*>::iterator j=eachItem.begin(); j!=eachItem.end(); j++){
			len += (strlen(_delimstr)+strlen(*j));
			if(len>=KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN");}
			if(*_outstr!='\0'){ strcat(_outstr,_delimstr); }
			strcat(_outstr,*j);
		}
	}
	else{
		// _delimでトークン分割
		set<char*,strComp> eachItem = uniqToken(str,_delim);
		for(set<char*,strComp>::iterator j=eachItem.begin(); j!=eachItem.end(); j++){
			len += (strlen(_delimstr)+strlen(*j));
			if(len>=KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN");}
			if(*_outstr!='\0'){ strcat(_outstr,_delimstr); }
			strcat(_outstr,*j);
		}
	}
	if(_assertNullOUT && *_outstr=='\0'){ _existNullOUT = true;}
	_oFile.writeStr(_outstr,eol);
	
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgVuniq::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	//出力項目名出力 追加 or 置換
	if(_add_flg) { _oFile.writeFldName(_iFile,_vfField,true);}
	else				 { _oFile.writeFldName(_vfField, true);}
	int outsize = _iFile.fldSize();
	if(_add_flg) { outsize += _vfField.size(); }	


	while(EOF != _iFile.read() ){
		int outcnt=0;
		for(size_t i=0; i<_iFile.fldSize(); i++){
			outcnt++;
			char* str=_iFile.getVal(i);

			if(_add_flg||_vfField.flg(i)==-1){
				_oFile.writeStr(str,outcnt==outsize);
			}
			else{
				if(_assertNullIN && *str=='\0' ) { _existNullIN  = true;}
				output_n(str,outcnt==outsize);
			}
		}
		if(_add_flg){
			for(kgstr_t::size_type i=0 ; i< _vfField.size() ;i++){
				outcnt++;
				if(_assertNullIN && *_iFile.getVal(_vfField.num(i))=='\0') { _existNullIN  = true;}
				output_n(_iFile.getVal(_vfField.num(i)),outcnt==outsize);
			}
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
