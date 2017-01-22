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
// kgselstr.cpp 文字列による行選択クラス
// =============================================================================
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <kgselnum.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSelnum::kgSelnum(void)
{
	_name    = "kgselnum";
	_version = "###VERSION###";

	#include <help/en/kgselnumHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgselnumHelp.h>
	#endif


}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSelnum::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,u=,k=,f=,c=,-r,-F,-R,bufcount=,-q",kgArgs::COMMON|kgArgs::IODIFF|kgArgs::NULL_KEY|kgArgs::NULL_IN);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	kgstr_t ufile = _args.toString("u=",false);
	if(ufile.empty()){
		_elsefile=false;
	}
	else {
		_elsefile=true;
		_uFile.open(ufile,_env,_nfn_o);
	}		
	kgstr_t s=_args.toString("bufcount=",false);
	int bcnt = 10;
	if(!s.empty()){ 
		bcnt = atoi(s.c_str());
		if(bcnt<=0){ bcnt=1;}
	}
	_iFile.setbufsize(bcnt);
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",false);

	// f= 項目引数のセット
	vector<kgstr_t>  vs_f = _args.toStringVector("f=",true);

	// -r 条件反転,-Rキー単位sel、-Fselの条件
	_reverse    = _args.toBool("-r");
	_keysel_flg = _args.toBool("-R");
	_sel_flg    = _args.toBool("-F");

	// c= 項目引数のセット 偶数個の指定でないと行けない
	vector<kgstr_t> cstr = _args.toStringVector("c=",true);
	if( cstr.size()%2 !=0){ throw kgError("the number of c= must be even"); }
	int ccnt = cstr.size() / 2;
	_cField.resize(ccnt);
	for (int i=0;i<ccnt;i++){
		_cField[i].dataSet(cstr[i*2],cstr[i*2+1]);
	}

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if(!seqflg && !vs_k.empty()){ sortingRun(&_iFile,vs_k);}
	_kField.set(vs_k, &_iFile,_fldByNum);
	_fField.set(vs_f, &_iFile,_fldByNum);

}
// -----------------------------------------------------------------------------
//	文字列比較(当てはまればtrue)vstrにある文字列のどれかに一致すればtrue
// -----------------------------------------------------------------------------
bool kgSelnum::rangeMatch(double val)
{
	for(vector<wstring>::size_type i=0;i<_cField.size();i++){
		if ( _cField[i].match(val) ){ return true;}	
	}
	return false;
}
// -----------------------------------------------------------------------------
// １行での条件マッチ
// -----------------------------------------------------------------------------
bool kgSelnum::lineCheck(vector<int>& cnt,char** str)
{
	bool rtn=false;
	for(vector<int>::size_type i=0;i<cnt.size();i++){
		if(_assertNullIN && *(str+cnt[i])=='\0') { _existNullIN  = true;}
		double tmpval = atof( *(str+cnt[i]) );
		if(_reverse){//条件反転
			if(_sel_flg){//すべて不一致
				if(rangeMatch(tmpval)){ rtn=false; continue;}
				else{rtn = true; break;}				
			}
			else{/*どれかが不一致*/
				if(rangeMatch(tmpval)){ rtn=false;break;}
				else{ rtn = true;continue;}
			}
		}
		else{
			if(_sel_flg){//すべて一致
				if(rangeMatch(tmpval)){rtn=true;continue;}
				else{rtn = false;break;}
			}
			else{/*どれか一致*/
				if(rangeMatch(tmpval)){rtn=true;break;}
				else{rtn = false;continue;}				
			}
		}
	}
	return rtn;
}



// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSelnum::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名出力
	_oFile.writeFldName(_iFile);
	if(_elsefile){ _uFile.writeFldName(_iFile); }

	vector<int> fieldlst= _fField.getNum();

	// キー単位処理をするかで処理を変える
	if(_kField.size()){

		// 条件反転がセットされている場合、初期値をfalse
		// 逆にセットされていない場合、初期値をtrue
		while(_iFile.blkset()!=EOF){
			bool finalSel=false;		
			while(_iFile.blkread() != EOF){
       bool lineSel=lineCheck(fieldlst,_iFile.getBlkFld());
				if(_reverse){
					if(_keysel_flg){
           if(!lineSel){finalSel=false; continue;}
           else       {finalSel=true; break   ;}
					}
					else{
           if(!lineSel){finalSel=false; break   ;}
           else       {finalSel=true; continue;}
					}
				}
				else{ 
					/*and条件*/
					if(_keysel_flg){
						if(lineSel){finalSel=true; continue;}
						else       {finalSel=false; break   ;}
					}
					/*or条件*/
					else{
						if(lineSel){finalSel=true; break   ;}
						else       {finalSel=false; continue;}
					}
				}
			}
			_iFile.seekBlkTop();
			if(finalSel){
				while(_iFile.blkread() != EOF){
					_oFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld());
				}
			}
			else{
				if(_elsefile){
					while(_iFile.blkread() != EOF){
						_uFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld());
					}
				}
			}
		}
	}
	else{//行単位処理
		while(_iFile.read()!=EOF){			
			if(_iFile.status() & kgCSV::End)break;
			if(lineCheck(fieldlst,_iFile.getNewFld())){
				_oFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
			}
			else{
				if(_elsefile){
					_uFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
				}
			}
		}
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理
	th_cancel();
	_iFile.close();
	_oFile.close();
	if(_elsefile){ _uFile.close();}
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
