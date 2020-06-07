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
// kgcal.h 項目間演算クラス
// =============================================================================
#pragma once
#include <string>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgError.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgFunction.h>
#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/classic_core.hpp>
#include <boost/spirit/include/classic_utility.hpp>
#include <boost/spirit/include/classic_ast.hpp>

using namespace kglib;
using namespace boost::spirit::classic;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgCal_PreRSL{
	size_t _fldSize;
	vector<kgVal>   _prvResults;
	vector< kgAutoPtr1<ptime> > _prvtimeRsls;
	vector< kgAutoPtr1<date> >  _prvdateRsls;
	//vector< kgAutoPtr2<char> >  _prvcharRsls;
	char ** _prvcharRsls;

	public:
		kgCal_PreRSL(void){
			_fldSize=0;
			_prvcharRsls=NULL;
		}

		~kgCal_PreRSL(void){
			if(_fldSize>0){
				for(size_t i=0;i<_fldSize;i++){
					delete [] _prvcharRsls[i];
				}
				delete [] _prvcharRsls;
			}
		}
		void resize(size_t i){
			_fldSize=i;
			_prvResults.resize(_fldSize);
			_prvtimeRsls.resize(_fldSize);
			_prvdateRsls.resize(_fldSize);
			_prvcharRsls = new char* [_fldSize];
			for(size_t j=0;j<_fldSize;j++){
				_prvcharRsls[j] = new char[KG_MAX_STR_LEN];
			}
			for(size_t j=0;j<_prvResults.size();j++){
				_prvResults[j].null(true);
			}
		}
		kgVal* getVal(size_t i){
			return &_prvResults[i];
		}
		void setVal(kgVal *rls,size_t pos){
			char * p;
			_prvResults[pos].set(rls);
			if(!_prvResults[pos].null()){
				try {
					// 文字列,時間,日付の場合はデータを複製しておく
					switch(_prvResults[pos].type()){
					case 'S':
						strcpy(_prvcharRsls[pos],rls->s());
						_prvResults[pos].s(_prvcharRsls[pos]);
						break;
					case 'D':
						_prvdateRsls[pos].set( new date(*(rls->d())) );
						_prvResults[pos].d(_prvdateRsls[pos].get());
						break;
					case 'T':
  					_prvtimeRsls[pos].set( new ptime(*(rls->t())) );
						_prvResults[pos].t(_prvtimeRsls[pos].get());
						break;
					}
				}catch(...){
					_prvResults[pos].null(true);
				}
			}
		}
};




class kgCal:public kgMod {
	// 引数
	kgArgFld  _kField; // k=
	kgstr_t   _expr;   // c=
	kgstr_t   _newFld; // a=
	kgCSVkey  _iFile;  // i=
	kgCSVout  _oFile;  // o=
	kgVal     _prvRsl;// 前行の結果:初期値はNULL
	kgAutoPtr1 <ptime> _prv_t_ap;
	kgAutoPtr1 <date> _prv_d_ap;

//	char  _prv_s_p[KG_MAX_STR_LEN];

	kgstr_t _seed;

	vector<kgstr_t> _exprs;   // c=
	vector<kgstr_t> _newFlds;   // c=
	//vector<kgVal>   _prvRsls;// 前行の結果:初期値はNULL

	kgCal_PreRSL _prvRsls;

	kgFuncMap _funcMap;

	// 引数セット
	void setArgs(void);

	// 構文木を走査するiterator型定義
	typedef tree_match<std::string::const_iterator,
		node_val_data_factory<void *> >::tree_iterator tree_node_iter_t;

	// 計算実行
	void calculate( tree_node_iter_t const &iter );

	// 前処理(正規表現のコンパイルなど)
	void runPreProcess( tree_node_iter_t const &iter );

	// 構文解析後の初期設定及び引数タイプチェック
	kgVal* setFuncArg( tree_node_iter_t const &iter );

	// 構文解析後の関数の引数の数のチェック
	void chkFuncArgc( tree_node_iter_t const &iter );

	// ノードに関数(クラス)のアドレスの設定しクラスを初期化する
	char setFuncType( tree_node_iter_t const &iter ,kgVal* pre);

	// CSV項目出力
	void writeFld(char** fld,int size, vector<kgVal*>& val);

	//前回データセット
	//void prersl_set(kgVal *rls);

public:
	// コンストラクタ
	kgCal(void);
	~kgCal(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}

