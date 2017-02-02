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
// kg2cross.cpp クロス集計クラス(N vs 1)
// =============================================================================
#include <cstdio>
#include <iostream>
#include <sstream>
#include <kg2cross.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgTempfile.h>

using namespace std;
using namespace kglib;
using namespace kgmod;


namespace /////////////////////////////////////////////////////
{
class strsort{
	public:
		bool operator()(string t1,string t2) const {
			return strcmp(t1.c_str(),t2.c_str()) < 0 ;			
		}
};

class numsort{
	public:
		bool operator()(string t1,string t2) const {
			return atof(t1.c_str()) < atof(t2.c_str()) ;			
		}
};
}/////////////////////////////////////////////////////
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kg2Cross::kg2Cross(void)
{
	_name    = "kg2cross";
	_version = "###VERSION###";

	#include <help/en/kg2crossHelp.h>	
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kg2crossHelp.h>
	#endif

}
//===============================================================================
// 項目名=>出力位置リスト生成&項目名出力
//   入力データを全行読込み、s=項目の内容で項目名=>出力位置リストを生成する
//   さらに項目名出力をする。
//	 ここで読み込まれたデータは一時ファイルに出力され次の処理で使用される
//================================================================================
void kg2Cross::setFldName(string tName)
{
	set<string, strsort> newfld;
	set<string, numsort> newfld_n;
	vector<kgstr_t> outFldName;

	//ここは元ファイルのnfnタイプで出力する
	kgCSVout toFile;
	toFile.open(tName, _env, _nfn_i);
	toFile.writeFldName(_iFile);

	// 展開項目名一覧生成＆読み込んだデータを一時ファイルに複製する
	// (後の処理は一時ファイルを元に行う。<=データがパイプ等のため)
	// s=項目名に%nが指定されている場合は、展開する項目名は数値として扱う

	// ダミーがあればセット
	for(size_t i=0; i<_fixfld.size(); i++){
		if(_numsort){
			if( newfld_n.find(_fixfld[i]) == newfld_n.end() ){
				 newfld_n.insert(_fixfld[i]);
			}
		}else{
			if( newfld.find(_fixfld[i]) == newfld.end() ){
				 newfld.insert(_fixfld[i]);
			}
		}
	}
	while( EOF != _iFile.read() ){
		toFile.writeFld(_iFile.fldSize(),_iFile.getFld());
		char *ck_str = _iFile.getVal(_sField.num(0));
		if(*ck_str=='\0') continue;
		if(_numsort){
			if( newfld_n.find(ck_str) == newfld_n.end() ){
				 newfld_n.insert(ck_str);
			}
		}else{
			if( newfld.find(ck_str) == newfld.end() ){
				 newfld.insert(ck_str);
			}
		}
	}
	// 出力項目セット(f=以外)
	if(!_nfn_o){
		for(size_t i=0; i<_iFile.fldSize(); i++){
			if( _fField.flg(i) == -1 && _sField.flg(i) == -1 ){
				outFldName.push_back(_iFile.fldName(i,true));
			}
		}
	}
	_iFile.close();
	toFile.close();


	// 展開項目名-出力位置番号mapの生成＆出力項目セット
	int no=0;
	if(_numsort){
		if(_reverse){  //数字ソート逆順
			for(set<string,numsort>::reverse_iterator j=newfld_n.rbegin(); j!=newfld_n.rend(); j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}else{				 //数字ソート
			for(set<string,numsort>::iterator          j=newfld_n.begin();  j!=newfld_n.end();  j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}
	}else{
		if(_reverse){	 //文字ソート逆順
			for(set<string,strsort>::reverse_iterator j=newfld.rbegin(); j!=newfld.rend(); j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}else{				 //文字ソート
			for(set<string,strsort>::iterator          j=newfld.begin();  j!=newfld.end();  j++){
				_newFldMap[*j] = no++;
				if(!_nfn_o){ outFldName.push_back(*j);}
			}
		}
	}
	//	項目名出力
	if(!_nfn_o){ _oFile.writeFldNameCHK(outFldName); }


}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kg2Cross::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,s=,a=,k=,v=,i=,o=,fixfld=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vk  = _args.toStringVector("k=",false);

	// f= 項目引数のセット
	vector<kgstr_t> vf = _args.toStringVector("f=",true);

	// s= 項目引数のセット	%nr
	vector< vector<kgstr_t> >  vs = _args.toStringVecVec("s=","%:",2,false);

	// a= 項目引数のセット
	_a_str = _args.toStringVector("a=",false);

	_fixfld = _args.toStringVector("fixfld=",false);

	// v= null値変換文字列セット
	_v_str = _args.toString("v=",false);
	if(_v_str.size()==0) { _n_flg=false; }
	else								 { _n_flg=true;	 }

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg&&!vk.empty()){ sortingRun(&_iFile,vk);}

	_kField.set(vk, &_iFile, _fldByNum);
	_fField.set(vf, &_iFile, _fldByNum);
	_sField.set(vs, &_iFile, _fldByNum);

	// ー => |　:: a=必須 f=必須             v=オプション
	// | => ー　:: s=必須 f=必須 k=オプション  v=オプション
	if(_a_str.size()==0){
		if(_sField.size()!=1){ throw kgError("s= takes just one field name."); }
		if(_fField.size()!=1){ throw kgError("f= takes just one field name."); }

		//比較タイプセット(nがあるとtrueをセット(数字ソートになる)r)
		_reverse = _sField.attr(0).find("r") != kgstr_t::npos ;
		_numsort = _sField.attr(0).find("n") != kgstr_t::npos ;	
		_t_type = true;
	}
	else{	
		if(_a_str.size()!=2){ throw kgError("a= takes just two field name."); }
		if(_fixfld.size()>0){ throw kgError("fixfld= must be specified with s="); }
		_reverse = false;
		_numsort = false;
		_t_type = false;
	}
}

int kg2Cross::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	//縦から横へ
	if(_t_type){
		// データ複製、項目名=>出力位置リスト生成、項目名出力
		kgTempfile tempFile(_env);
		string tName = tempFile.create();
		setFldName(tName);

		// データファイルオープン
		kgCSVkey tiFile;
		tiFile.open(tName, _env, _nfn_i);
		tiFile.read_header();
		tiFile.setKey(_kField.getNum());

		size_t outValCount=_newFldMap.size();
		vector<string> fldVals(outValCount);

		while( EOF != tiFile.read() ){
			if( tiFile.keybreak() ){
				// keybreak時にデータを出力する
				for(size_t i=0; i<_iFile.fldSize(); i++){
					if( _fField.flg(i) == -1 && _sField.flg(i) == -1){
						_oFile.writeStr( tiFile.getOldVal(i), false);
					}
				}
				for(size_t i=0; i < outValCount; i++){
					string o_str;
					if (!strcmp(fldVals.at(i).c_str(),"")){
						if( _n_flg ){ o_str = _v_str; }
						else{
							o_str = fldVals.at(i);
							if(_assertNullOUT){ _existNullOUT = true;}
						}
					}else{
						o_str = fldVals.at(i);
					}
					if(i==outValCount-1) _oFile.writeStr( o_str.c_str(), true );
					else                 _oFile.writeStr( o_str.c_str(), false);
				}
				fldVals.clear();
				fldVals.resize(outValCount);
			}
			// Normal
			char *ck_str = tiFile.getNewVal(_sField.num(0));
			if(*ck_str == '\0') continue;
			int sno = _newFldMap[ck_str];
			fldVals.at(sno) = tiFile.getNewVal(_fField.num(0));
			if(_assertNullIN && fldVals.at(sno).size()==0) { _existNullIN  = true;}	
		}
		//ASSERT keynull_CHECK
		if(_assertNullKEY) { _existNullKEY = tiFile.keynull(); }
		th_cancel();
	// 終了処理
		tiFile.close();
	}
	//横から縦へ
	else{
		vector<kgstr_t> outFldName;
		vector<size_t> outsNo;
		if(_kField.size()==0){
			for(size_t i=0; i<_iFile.fldSize(); i++){
				if( _fField.flg(i) == -1 ){ outsNo.push_back(i); }
			}
		}
		else{
			for(size_t i=0; i<_kField.size(); i++){
				outsNo.push_back(_kField.num(i));
			}
		}

		//	項目名出力
		for(size_t i=0; i<outsNo.size(); i++){
			outFldName.push_back(_iFile.fldName(outsNo.at(i),true));
		}
		for(size_t i=0; i<_a_str.size(); i++){
			outFldName.push_back(_a_str.at(i));
		}
		if(!_nfn_o){ _oFile.writeFldNameCHK(outFldName); }

		//	展開出力
		while( EOF != _iFile.read() ){
			for(size_t i=0;i<_fField.size(); i++){
				for(size_t j=0; j<outsNo.size(); j++){
					_oFile.writeStr( _iFile.getVal(outsNo.at(j)), false);
				}
				char *ckstr = _iFile.getVal(_fField.num(i));
				_oFile.writeStr( _iFile.fldName(_fField.num(i),false).c_str(),false);
				if(*ckstr == '\0' && _n_flg ){
					_oFile.writeStr( _v_str.c_str(), true);			
					if(_assertNullOUT){ _existNullOUT = true;}
				}
				else {
					_oFile.writeStr( ckstr, true);			
				}
			}
		}
		th_cancel();
		_iFile.close();
	}
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
