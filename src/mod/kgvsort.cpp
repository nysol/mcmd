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
// kgvsort.cpp ベクトル要素の並べ替えクラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <vector>
#include <kgvsort.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgVsort::kgVsort(void)
{
	_name    = "kgvsort";
	_version = "###VERSION###";

	#include <help/en/kgvsortHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgvsortHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgVsort::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,vf=,delim=,-A",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_IN|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o,_rp);
	_iFile.read_header();

	// vf= 項目引数のセットold%nr:new
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("vf=",":",2,true);

	for(size_t i=0;i<vvs[0].size();i++){
		vector<kgstr_t> spvec = splitToken(vvs[0].at(i),'%');
		vvs[0].at(i) = spvec[0];
		int flg =0;
		if(spvec.size()>1){
			if( spvec[1].find('n')!=kgstr_t::npos ) flg |= 1;
			if( spvec[1].find('r')!=kgstr_t::npos ) flg |= 2;
		}
		_icomp.push_back(kgvsort_local::itmComp(flg));
	}
	
	_vfField.set(vvs, &_iFile,_fldByNum);

	// -A（追加）フラグセット
	_add_flg 		= _args.toBool("-A");

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
	_delimstr[0] =_delim;
	_delimstr[1] ='\0';
	
}
void kgVsort::output_n(char *str,int flgno ,bool eol)
{
	*_outstr = '\0'; 
	int len = 0; 
	
	// itemset項目を" "でトークン分割してソート
	vector<char*> eachItem = splitToken( str ,_delim);
	sort(eachItem.begin(),eachItem.end(),_icomp[flgno]);
				
	for(vector<char*>::iterator j=eachItem.begin(); j!=eachItem.end(); j++){
		len += (strlen(_delimstr)+strlen(*j));
		if(len>=KG_MAX_STR_LEN){ throw kgError("field length exceeded KG_MAX_STR_LEN");}
		if(*_outstr!='\0'){ strcat(_outstr,_delimstr); }
		strcat(_outstr,*j);
	}
	if(_assertNullOUT && *_outstr=='\0'){ _existNullOUT = true;}
	_oFile.writeStr(_outstr,eol);
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgVsort::run(void) try 
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
				output_n(str,_vfField.flg(i),outcnt==outsize);
			}
		}
		if(_add_flg){
			for(kgstr_t::size_type i=0 ; i< _vfField.size() ;i++){
				outcnt++;
				if(_assertNullIN && *_iFile.getVal(_vfField.num(i))=='\0') { _existNullIN  = true;}
				output_n(_iFile.getVal(_vfField.num(i)),i,outcnt==outsize);
			}
		}
	}


	// 終了処理(メッセージ出力,thread pipe終了通知)
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
