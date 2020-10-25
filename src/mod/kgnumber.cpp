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
// kgnumber.cpp 連続値項目の追加クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <kgnumber.h>
#include <kgError.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgNumber::kgNumber(void)
{
	_name    = "kgnumber";
	_version = "###VERSION###";

	#include <help/en/kgnumberHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgnumberHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgNumber::setArgs(void)
{
	// パラメータチェック()
	_args.paramcheck("a=,i=,o=,k=,s=,S=,I=,e=,-B,-q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_KEY);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",false);

	// s= 項目引数のセット
	vector< vector<kgstr_t> > vs_s = _args.toStringVecVec("s=","%",2,false);

	// a= 追加文字列
	_addstr = _args.toString("a=",false);
	if(_addstr.empty()&& _nfn_o==false){
		throw kgError("parameter a= is mandatory");
	}

	// I= 間隔
	kgstr_t str_I = _args.toString("I=",false);
	_interval=atoi(str_I.c_str());
	if(_interval==0){ _interval=1;}

	// S= 開始番号
	_alpha_flg=false;			
	kgstr_t str_S = _args.toString("S=",false);
	if(str_S.empty()){ _start=0; }
	else{	
		string digits("-0123456789");
		string alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		if(str_S.find_first_not_of(digits)==kgstr_t::npos){
			/*数値のみだった*/
			_start=atoi(str_S.c_str());
		}
		else if(str_S.find_first_not_of(alpha)==kgstr_t::npos){
			/*アルファベットのみだった*/
			_alpha_flg=true;			
			_start=0;
			for(kgstr_t::size_type i=0;i<str_S.size();i++){
				_start = (_start*26)+str_S[i]-'A'+1;
			}					
		}
		else{
			ostringstream ss;
			ss << "S= is digits or alpha" << str_S.c_str();	
			throw kgError(ss.str());
		}
	}

	// e= 処理方法seq:0,same:1,skip:2
		string str_e = _args.toString("e=",false);
				if(str_e=="seq")	{ _e_type=0;}
	else 	if(str_e=="same")	{ _e_type=1;}
	else 	if(str_e=="skip")	{ _e_type=2;}
	else	if(str_e=="")			{ _e_type=0;}
	else {
		ostringstream ss;
		ss << "e= seq|same|skip" << str_e;
		throw kgError(ss.str());	
	}
	// -B キー内では全行同じ番号
	_B_flg = _args.toBool("-B");

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	/*パラメータ組み合わせチェック*/
  /*-s と -Bは同時指定不可*/
  /*-e same|skip と -Bは同時指定不可*/
  /*-e same|skip は-sの指定がなければならない*/
	if(vs_s[0].size()!=0 && _B_flg==true ){
		throw kgError("s= cannot be specified with -B");
	}
	if(_e_type!=0 && _B_flg==true){
		throw kgError("[e=same|skip] cannot be specified with -B");
	}
	if(vs_s[0].size()==0 && _B_flg==false && !seqflg){
		throw kgError("s= must be specified when not be used -B or -q,-nfn");
	}


	if(!seqflg && (!vs_k.empty()||!vs_s[0].empty())){ 
		vector<kgstr_t> vs_ss = _args.toStringVector("s=",false);
		vector<kgstr_t> vsk	= vs_k;
		vsk.insert(vsk.end(),vs_ss.begin(),vs_ss.end());
		sortingRun(&_iFile,vsk);
	}

	_kField.set(vs_k,   &_iFile,_fldByNum);
	_sField.set(vs_s[0],&_iFile,_fldByNum);

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgNumber::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
  _oFile.writeFldName(_iFile,_addstr);

	int seqCnt	= _start - _interval;
	int sameCnt	= _start - _interval;
	int kb_flg		= 1;
	if(_B_flg){ seqCnt += _interval;}

	// カウント＆出力
	while(_iFile.read()!=EOF){
		/*ENDなら終了*/
		if((_iFile.status() & kgCSV::End )) break;
		if( _iFile.keybreak() ){
			if(_B_flg){
        seqCnt += _interval;
      }else{
        sameCnt = _start - _interval;
        seqCnt  = _start - _interval;
      }
			kb_flg=1;
		}
		/* 通常処理 */
		if(!_B_flg){
			if(_e_type!=0){
				/*sort項目が同じかチェック*/
				vector<kgstr_t>::size_type i;
				for(i=0; kb_flg!=1 && i<_sField.size(); i++){
					if ( strcmp(
							_iFile.getNewVal(_sField.num(i)),
							_iFile.getOldVal(_sField.num(i)) ) )
					{
						break;
					}
				}/*sort項目が同じ場合*/
				if(i==_sField.size()){
					seqCnt += _interval;
				}/*sort項目が違う場合*/
				else{
          if(_e_type==2){//skipが指定された場合
            seqCnt += _interval;
            sameCnt = seqCnt;
          }else{
            seqCnt += _interval;
            sameCnt += _interval;
          }
				}
			}
			else{
				seqCnt += _interval;
 			}
		}
		/*出力*/
    if(_e_type!=0){
			_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),sameCnt,_alpha_flg);    
		}else{
			_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),seqCnt,_alpha_flg);    
    }
		kb_flg=0;
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
