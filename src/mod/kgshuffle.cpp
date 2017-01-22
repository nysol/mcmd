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
// kgshuffle.cpp ファイル分割クラス
// =============================================================================
#include <cstdio>
#include <cstring>
#include <kgshuffle.h>
#include <kgError.h>
#include <kgTempfile.h>
#include <boost/filesystem.hpp>


using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgShuffle::kgShuffle(void)
{
	_name    = "kgshuffle";
	_version = "###VERSION###";
	_outCount=0;

	#include <help/en/kgshuffleHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgshuffleHelp.h>
	#endif


}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgShuffle::setArgs(void)
{
	// パラメータチェック
	// i=データ d=出力先 n=分割数 v=重みリスト f=キー項目 を指定させる	
	_args.paramcheck("i=,f=,d=,v=,n=");

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false),_env,_nfn_i);
	_iFile.read_header();

	// f= 項目引数のセット
	vector<kgstr_t>  vs_f = _args.toStringVector("f=",false);
	if(vs_f.size()==0){
		_woFld = true;
	}
	else{
		_woFld = false;
		_fField.set(vs_f, &_iFile, _fldByNum);
	}

	vector<kgstr_t> vs_v = _args.toStringVector("v=",false);
	       kgstr_t dname = _args.toString("d=",true);
	       kgstr_t nstr  = _args.toString("n=",false);
	       
	// d=,v=のどちらかが必須、両方指定されていたらサイズチェック
	if(!nstr.empty() && !vs_v.empty() && aToSizeT(nstr.c_str())!= vs_v.size() ){
	  throw kgError("You have to make the number of v= and the value of n=  the same.");
	}

  size_t outnum=10;
       if(!vs_v.empty()){ outnum = vs_v.size();}
	else if(!nstr.empty()){ outnum = aToSizeT(nstr.c_str());}
	
	_hashSize=0;
	for(size_t i=0; i<outnum; i++){
		if(vs_v.empty()){
			_hash2outf.push_back(i); 
			_hashSize++;
		}
		else { 
			int num = atoi(vs_v[i].c_str());
	  	if(num<=0){ throw kgError("v='s hash value must be greater than 0 .");}
		  for(int j=0; j<num; j++){
				_hash2outf.push_back(i);
		  }
			_hashSize+=num;		
		}
	}

	// 出力ファイル名生成&オープン d=の値 + _番号
  _csvOut_ap.set(new kgCSVout[outnum]);
  kgCSVout* csvOut = _csvOut_ap.get();
  char buf[256];
	try {
	  for(size_t i=0; i<outnum ; i++){
 	   sprintf(buf,"_%zu",i);
	    kgstr_t fstr = dname+buf;
			boost::filesystem::path filename=boost::filesystem::path(fstr);
			boost::filesystem::path dirname =filename.branch_path();
			if (! dirname.empty()){
				create_directories(dirname);
			}
	 	 	(csvOut+i)->open(fstr, _env,_nfn_o);
			_oFile.push_back(csvOut+i);
		}
	}catch (boost::filesystem::filesystem_error& ex) {
		throw kgError(ex.what());
  }

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgShuffle::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名出力
	for(size_t i=0; i<_oFile.size(); i++){
		_oFile.at(i)->writeFldName(_iFile);
	}
	// 入力ファイル読み込みループ
	while(_iFile.read()!=EOF){
		size_t hashVal=0;
		if(_woFld){ // 項目指定がない場合は行番号でhash値を計算する
			hashVal=_iFile.recNo();
		}else{
			for(std::size_t i=0; i<_fField.size(); i++){
				char* str=_iFile.getVal(_fField.num(i));
				while(*str != '\0') hashVal+=static_cast<size_t>(*str++);
			}
		}
		hashVal = hashVal % _hashSize;
		// hash値別にファイル出力
		_oFile.at(_hash2outf[hashVal])->writeFld(_iFile.fldSize(),_iFile.getFld());
		_outCount++;
	}

	// 終了処理
	_iFile.close();
	for(size_t i=0; i<_oFile.size(); i++){ _oFile.at(i)->close(); }
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

