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
// kgsel.cpp 条件式による行選択クラス
// =============================================================================
#include <sstream>
#include <string>
#include <vector>
#include <kgsel.h>
#include <kgCSVutils.h>
#include <kgFunction.h>
#include <kgError.h>
#include <kgCalParser.h>
#include <boost/spirit/include/classic_core.hpp>
#include <boost/spirit/include/classic_utility.hpp>
#include <boost/spirit/include/classic_ast.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>
#include <boost/function.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::spirit::classic;
using namespace boost::lambda;
using namespace boost;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgSel::kgSel(void)
{
	_name    = "kgsel";
	_version = "###VERSION###";
	
	#include <help/en/kgselHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgselHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSel::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("c=,i=,o=,u=,-r",kgArgs::COMMON|kgArgs::IODIFF);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o,_rp);
	_iFile.read_header();
	kgstr_t str = _args.toString("u=",false);
	if(str.empty()){
		_uFlg=false;
	}else{
		_uFlg=true;
		_uFile.open(str, _env, _nfn_o,_rp);
	}

	// -r 反転フラグ
	_reverse = _args.toBool("-r");
	// u= unmatch出力ファイルオープン

	// c= 式を文字列として取得
	_expr    = _args.toString("c=",true);

}
// -----------------------------------------------------------------------------
//	各行の計算の実行
//	vector<kgVal> *valに関数からの返り値がセットされる
//
//	power(${数量},2)*${金額}の場合
//	'*'-+--'power'-+--'数量'
//				|            |
//				|            +--2
//				+--'金額'
//	というツリー構造になっている
//	$は項目の指定
//
//	各ノードのvalue.value()に対応するクラス(kgFunction)のアドレスを格納
//	そのクラスには必ず返り値と引数を格納するメンバーがいる．
//	  返値: kgVal _result
//	  引数: vector<kgVal>_args
//	_argsは子ノードのクラスの_resultへのポインタである．
//	よって,行が読み込まれる度に深さ優先で_resultを評価することにより
//	トップノードの_resultに最終計算結果が格納される事になる．
// -----------------------------------------------------------------------------
void kgSel::calculate( tree_node_iter_t const &iter )
{
	// 子ノードを先に評価する(深さ優先)
	for(unsigned int i=0;i<iter->children.size();i++){
		calculate(iter->children.begin()+i);
	}

	// 現在ノードの関数(クラス)のアドレスセット&実行
	kgFunction* fun_ptr = static_cast<kgFunction*>(iter->value.value());
	fun_ptr->run();

}
// -----------------------------------------------------------------------------
// 乱数の種，正規表現コンパイルなど
// 多くの関数では何もしない
// -----------------------------------------------------------------------------
void kgSel::runPreProcess( tree_node_iter_t const &iter )
{
	// 子ノードの個数分再帰呼び出し
	kgFunction* func = static_cast<kgFunction*>(iter->value.value());
	for(unsigned int j=0; j<iter->children.size(); j++) {
		runPreProcess(iter->children.begin()+j);
	}

	func->preprocess();

}
// -----------------------------------------------------------------------------
// 構文解析後の初期設定及び引数タイプチェック
// paserタグによって、
// 関数、項目値、文字列、定数を判別して
// クラスでのインスタンス化及び初期設定関数を起動する
// 返り値はそれぞれのクラスの関数が返す型タイプ
// -----------------------------------------------------------------------------
kgVal* kgSel::setFuncArg( tree_node_iter_t const &iter )
{
	// 子ノードの個数分再帰呼び出し
	// 子ノードの返り値へのアドレスをvectorにセット
	kgFunction* func = static_cast<kgFunction*>(iter->value.value());
	for(unsigned int j=0; j<iter->children.size(); j++) {
		func->_args.push_back( setFuncArg(iter->children.begin()+j) );
 	}
	return &func->_result;

}
// -----------------------------------------------------------------------------
// 構文解析後の引数の数のチェック
// -----------------------------------------------------------------------------
void kgSel::chkFuncArgc( tree_node_iter_t const &iter )
{
	// 子ノードの個数分再帰呼び出し
	kgFunction* func = static_cast<kgFunction*>(iter->value.value());
	for(unsigned int j=0; j<iter->children.size(); j++) {
		chkFuncArgc(iter->children.begin()+j);
 	}
	func->chkArgc();
}
// -----------------------------------------------------------------------------
// ノードに関数(クラス)のアドレスの設定しクラスを初期化する
// -----------------------------------------------------------------------------
char kgSel::setFuncType( tree_node_iter_t const &iter )
{
	// 関数名,定数値,項目名
	kgstr_t str(iter->value.begin(), iter->value.end());
	// parse時にセットされたIDに従ってクラスを実体化させる
	kgFunction* kgf;
	     if(iter->value.id()==kgCalParser::constIDstr ){kgf=_funcMap.get("CS");}
	else if(iter->value.id()==kgCalParser::constIDreal){kgf=_funcMap.get("CN");}
	else if(iter->value.id()==kgCalParser::constIDdate){kgf=_funcMap.get("CD");}
	else if(iter->value.id()==kgCalParser::constIDtime){kgf=_funcMap.get("CT");}
	else if(iter->value.id()==kgCalParser::constIDbool){kgf=_funcMap.get("CB");}
	else if(iter->value.id()==kgCalParser::fieldIDstr ){kgf=_funcMap.get("FS");}
	else if(iter->value.id()==kgCalParser::fieldIDreal){kgf=_funcMap.get("FN");}
	else if(iter->value.id()==kgCalParser::fieldIDdate){kgf=_funcMap.get("FD");}
	else if(iter->value.id()==kgCalParser::fieldIDtime){kgf=_funcMap.get("FT");}
	else if(iter->value.id()==kgCalParser::fieldIDbool){kgf=_funcMap.get("FB");}
	else if(iter->value.id()==kgCalParser::pfieldIDstr ){kgf=_funcMap.get("PS");}
	else if(iter->value.id()==kgCalParser::pfieldIDreal){kgf=_funcMap.get("PN");}
	else if(iter->value.id()==kgCalParser::pfieldIDdate){kgf=_funcMap.get("PD");}
	else if(iter->value.id()==kgCalParser::pfieldIDtime){kgf=_funcMap.get("PT");}
	else if(iter->value.id()==kgCalParser::pfieldIDbool){kgf=_funcMap.get("PB");}
	else{
		// 関数と演算子のidを作る (ex. "+_FF")
		string id=str+"_";
		// 子ノードの個数分再帰呼び出し
		for(unsigned int j=0; j<iter->children.size(); j++) {
			id.push_back( setFuncType(iter->children.begin()+j) );
 		}
		kgf=_funcMap.get(id);
	}

	// ノードに関数(クラス)のptrをセットする．
	iter->value.value( kgf );

	// 項目値取得のためにkgFunctionのメンバーとして登録する
	// _csvをkgFunctionから派生する全クラス共通のメンバーとするのは
	// 心苦しいが良い方法がない．．
	kgf->_csv=&_iFile;
	kgf->_fldno=_fldByNum;
	kgf->_prvRsl=&_prvRsl;
	kgf->_dseed= -1;

	// 関数の初期化(返値タイプのセット,定数,変数のセット)
	kgf->initialize(str);

	// 返値タイプを返す
	return kgf->_result.type();

}
// -----------------------------------------------------------------------------
// kgsel起動部分
// -----------------------------------------------------------------------------
int kgSel::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 項目名を展開する(ワイルドカードと番号指定)
	_expr=evalCalFldName(_expr, _iFile,_fldByNum);

	// パーサーのインスタンス化
	kgCalParser parser;

	// ast_parse : BOOSTライブラリの構文木を生成する関数
	//	引数 : 解析する対象文字列, パーサー, スキップするパーサー
	tree_parse_info< std::string::const_iterator ,node_val_data_factory<void *> >
		info = ast_parse< node_val_data_factory<void *>,std::string::const_iterator >
				( _expr.begin(),_expr.end(),parser,nothing_p);

	// 構文木作成失敗
	if(!info.full){
		ostringstream ss;
		ss << "parse error in "  << _expr;
		ss << " (KGLIB)";
		throw kgError(ss.str());
		return 1;
	}

	// 関数,演算子,定数,項目値のクラスを実体化して各ノードにセットする
	setFuncType(info.trees.begin());

	// 各関数,演算子のとる引数をそれぞれの子ノードの_resultに紐づける
	setFuncArg(info.trees.begin());

	// 関数の引数の数のチェック
	chkFuncArgc(info.trees.begin());

	// 引数が定まってから可能となる前処理(正規表現コンパイルなど)
	runPreProcess(info.trees.begin());

	// 最終結果_resultのアドレスは静的に決まる(topノードの_result)
	kgVal* result =
 		&static_cast<kgFunction*>(info.trees.begin()->value.value())->_result;

	if(result->type()!='B'){
		throw kgError("data type of the result must be bool");
	}

	// 前行結果の初期値はNull
	_prvRsl.null(true);

	// 項目名の出力
	_oFile.writeFldName(_iFile);
	if(_uFlg) _uFile.writeFldName(_iFile);

	// データ出力
	while( EOF != _iFile.read() ){
		if((_iFile.status() & kgCSV::End )) break;

		// 計算の実行(トップノード関数の_resultの値が最終結果)
		calculate(info.trees.begin());
		if(result->b()!=_reverse && !result->null()){
			_oFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
		}
		else if(_uFlg){
			_uFile.writeFld(_iFile.fldSize(),_iFile.getNewFld());
		}
		// 前行結果をセット
		_prvRsl=*result;
	}

	// 終了処理(メッセージ出力,thread pipe終了通知)
	_iFile.close();
	_oFile.close();
	if(_uFlg){ _uFile.close();}
	successEnd();
	return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const std::exception& e) {
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
