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
// kgcsv2json.cpp 行集計(合計)クラス
// =============================================================================
#include <cstdio>
#include <vector>
#include <kgConfig.h>
#include <kgcsv2json.h>
#include <kgError.h>
#include <kgVal.h>


using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgCsv2json::kgCsv2json(void)
{
	_name    = "kgcsv2json";
	_version = "###VERSION###";

	#include <help/en/kgcsv2jsonHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcsv2jsonHelp.h>
	#endif
	_fldPtn=0;
}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgCsv2json::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,k=,p=,f=,h=,s=,-q,-flat",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o);


	// k= 項目引数のセット
	vector< vector<kgstr_t> > vvk = _args.toStringVecVec("k=","%:",2,false);
	vector<kgstr_t>  vvs = _args.toStringVector("s=",false);


	// fld 項目引数のセット
	vector<kgstr_t>  vvf = _args.toStringVector("f=",false);
	vector<kgstr_t>  vvh = _args.toStringVector("h=",false);
	vector< vector<kgstr_t> > vvp = _args.toStringVecVec("p=","%:",2,false);
	//f=,h=,p=はどれか一つ
	int cnt=0;
	if(!vvf.empty()) {cnt++; _fldPtn=0;} 
	if(!vvh.empty()) {cnt++; _fldPtn=1;} 
	if(!vvp[0].empty()) {cnt++; _fldPtn=2;} 
	if(cnt!=1){ throw kgError( "it is necessary any one [f=,h=,p=].");}

	_fltFlg = _args.toBool("-flat");


	_iFile.read_header();	

	// 必要ならソートが実行されiFileは初期化され,
	// ソーティンぐ結果のが出力されるファイルで再度読み込み直される	
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if(!seqflg && (!vvk[0].empty()||!vvs.empty())){ 
		vector<kgstr_t> vsk	= vvk[0];
		vsk.insert(vsk.end(),vvs.begin(),vvs.end());
		sortingRun(&_iFile,vsk);
	}

	_fField.set(vvf, &_iFile,_fldByNum);
	_hField.set(vvh, &_iFile,_fldByNum);
	_pFieldk.set(vvp[0], &_iFile,_fldByNum);
	_pFieldv.set(vvp[1], &_iFile,_fldByNum);

	_kField.set(vvk, &_iFile,_fldByNum);
	_oFLG.resize(_kField.size()+1,false);
	
	if(_fltFlg&&(_fldPtn!=0)){
		_oFLG[0]=true;
	}


	for(int i=0; i<_kField.size(); i++){
		if( _kField.attr(i).find('h')!=string::npos ){ _oFLG[i+1]=true; }
	}
}

void kgCsv2json::kebreak_output(int pos ,bool end){
	
	if( _oFLG[0] ){ _oFile.writeStrNdq("}");}
	else					{ _oFile.writeStrNdq("]");}
	for(int st=_kField.size() ; st>pos ; st--){
		if( _oFLG[st] ){ _oFile.writeStrNdq("}");}
		else					{ _oFile.writeStrNdq("]");}
	}
	if(end){
		_oFile.writeStrNdq("\n");
	}
	else{
		_oFile.writeStrNdq(",\n");
		for(int st= pos-1; st<_kField.size(); st++){
			if( _oFLG[st+1] ){ 
				if(st == pos-1){
					_oFile.writeStrNdq("\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_kField.num(st)));
					_oFile.writeStrNdq("\":");
				}else{
					_oFile.writeStrNdq("{\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_kField.num(st)));
					_oFile.writeStrNdq("\":");
				}
			}
			else{
				if(st != pos-1){ _oFile.writeStrNdq("[");}
			}
		}
		if( _oFLG[0] ){ _oFile.writeStrNdq("{");}
		else					{ _oFile.writeStrNdq("[");}
	}
}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCsv2json::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	while(_iFile.read()!=EOF){

		if( _iFile.begin() ){
			for(std::size_t i=0; i<_kField.size(); i++){
				if( _oFLG[i+1] ){ 
					_oFile.writeStrNdq("{\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_kField.num(i)));
					_oFile.writeStrNdq("\":");
				}
				else					{ _oFile.writeStrNdq("[");}
			}
			if( _oFLG[0] ){ _oFile.writeStrNdq("{");}
			else					{ _oFile.writeStrNdq("[");}
		}
		else if( _iFile.keybreak() ){
			//ENDなら終了
			if((_iFile.status() & kgCSV::End )) {
				kebreak_output(0,true);
				break;
			}
			// check change point
			int pos = 0;
			while(pos<_kField.size()){
				if( strcmp(_iFile.getNewVal(_kField.num(pos)),_iFile.getOldVal(_kField.num(pos)))){ break; }
				pos++;
			}
			kebreak_output(pos+1);
		}
		else{
			_oFile.writeStrNdq(",");
		}
		// 通常処理
		switch(_fldPtn){ 
			case 0:
				if(!_fltFlg){ _oFile.writeStrNdq("[");}
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					_oFile.writeStrNdq("\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_fField.num(i)));
					_oFile.writeStrNdq("\"");
					if (_fField.size()-1!=i){ _oFile.writeStrNdq(",");}
				}
				if(!_fltFlg){ _oFile.writeStrNdq("]");}
				break;
			case 1:
				if(!_fltFlg){ _oFile.writeStrNdq("{");}
				for(vector<kgstr_t>::size_type i=0; i<_hField.size(); i++){
					_oFile.writeStrNdq("\"");
					_oFile.writeStrForJson(_iFile.fldName(_hField.num(i)).c_str());
					_oFile.writeStrNdq("\":\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_hField.num(i)));
					_oFile.writeStrNdq("\"");
					if (_hField.size()-1!=i){ _oFile.writeStrNdq(",");}


				}
				if(!_fltFlg){ _oFile.writeStrNdq("}");}
				break;
			case 2:
				if(!_fltFlg){ _oFile.writeStrNdq("{");}
				for(vector<kgstr_t>::size_type i=0; i<_pFieldk.size(); i++){
					_oFile.writeStrNdq("\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_pFieldk.num(i)));
					_oFile.writeStrNdq("\":\"");
					_oFile.writeStrForJson(_iFile.getNewVal(_pFieldv.num(i)));
					_oFile.writeStrNdq("\"");
					if (_pFieldk.size()-1!=i){ _oFile.writeStrNdq(",");}
				}
				if(!_fltFlg){ _oFile.writeStrNdq("}");}
			
			
				break;
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

// 例外catcher
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
