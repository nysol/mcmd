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
// ============================================================================
// kgavg.h : 項目値の平均計算クラス
// ============================================================================
#include <cstdio>
#include <vector>
#include <kgavg.h>
#include <kgError.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgAvg::kgAvg(void)
{
	_name    = "kgavg";
	_version = "###VERSION###";

	#include <help/en/kgavgHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgavgHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgAvg::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,-n,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
  _oFile.setPrecision(_precision);

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// -n オプションのセット
	_null=_args.toBool("-n");

	_iFile.read_header();

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg && !vs.empty()){ sortingRun(&_iFile,vs);}


	_fField.set(vvs, &_iFile, _fldByNum);
	_kField.set(vs,  &_iFile, _fldByNum);

}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgAvg::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
  _oFile.writeFldName(_fField, true);

	// 集計用変数領域確保＆初期化
	vector<double> sum(_fField.size() ,0);
	vector<double> cnt(_fField.size() ,0);
	vector<kgVal>  val(_fField.size() ,kgVal('N'));
	double count=0;
	
	// データ集計＆出力
	// keybreakしたら平均出力してデータ初期化
	// 通常時(値加算＆行数カウント)
	// -n 指定時はnullが一つでもあれば結果もnull
	while(_iFile.read()!=EOF){
		if( _iFile.keybreak() ){
			for(std::size_t i=0; i<_fField.size(); i++){
				if(_null){ 
					if(cnt.at(i)==count){val.at(i).r( sum.at(i)/cnt.at(i) );}
					else{	
						val.at(i).null(true);
						if(_assertNullOUT){ _existNullOUT = true;}
					}
				}else{
					if(cnt.at(i) > 0)   { val.at(i).r( sum.at(i)/cnt.at(i) );}
					else{
						val.at(i).null(true);
						if(_assertNullOUT){ _existNullOUT = true;}
					}
				}
			}
			_oFile.writeFld(_iFile.getOldFld(),_fField.getFlg_p(),val);
			if((_iFile.status() & kgCSV::End )) break;
			for(std::size_t i=0; i<val.size(); i++){
				sum.at(i)=0;
				cnt.at(i)=0;
			}
			count=0;
		}
		for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
			char* str=_iFile.getNewVal(_fField.num(i));
			if(*str!='\0'){
				sum.at(i) += atof(str);
				cnt.at(i) += 1;
			}else {
				if(_assertNullIN) { _existNullIN  = true;}
			}
		}
		count+=1;
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }
	th_cancel();
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
