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

 ////////// LICENSE INFO //////////////////// */
// =============================================================================
// kgxml2csv.h 行集計(合計)クラス
// =============================================================================
#pragma once
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/encoding.h>

#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgMethod.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

typedef struct {
	//int                 cnt;       // キー要素の数
	kgstr_t             path;      // k=で指定されたxml path
	size_t              length;    // pathの長さ
	bool                in;        // 現在マッチしているキーpath文字列要素番号
} XmlKey;

// f=項目名構造体
// ex) f=rec@id:recID,rec2・・・
//        要素パス@属性名%オプション:新項目名
typedef struct {
  int   cnt;                 // 項目数
  vector<kgstr_t> element;   // 要素名UTF8
  vector<kgstr_t> attribute; // 属性名UTF8
  vector<char>    option;    // オプション t:テキスト,f:フラグ,n:名前
  vector<kgstr_t> field;     // 新項目名UTF8
  vector<bool>    in;        // 各要素の内側に入っているかどうか
} XmlFld;

typedef struct {
  int              level;       // 現在処理中の要素Nodeのレベル(rootNode=0)
	kgArgs          *args;        // コマンド引数
	xmlParserCtxtPtr ctxt;        // XMLパーサーハンドラ
	XmlKey          *key;         // k=で指定したXML pathの構造体
	XmlFld          *fld;         // f=で指定したXML pathの構造体
	string          *currentPath; // 現在処理中の要素パス
	vector<kgstr_t> *fldDat;      // 出力データ
	kgCSVout				*oFile;       // 出力ファイルポインタ
	int             *iRecNo;      // 入力ファイル行カウンタ
} XmlState;

class kgXml2csv : public kgMod 
{

	// 引数
	kgCSVout _oFile;  // o=

	// 引数セット
  void setArgs(void);

	// 以下、XML関連
	void setXmlFld(void);

	static void start_element(XmlState *state, char *fullname, char **atts);
	static void end_element(XmlState *state, char *fullname);
	static void start_characters(XmlState *state, xmlChar *chars, int len);

	xmlSAXHandler    _SAXFunctions; //
	string           _fname;        // xmlファイル名
	xmlParserCtxtPtr _ctxt;
	XmlState         _state;
	XmlKey           _key;
	XmlFld           _fld;
	string           _currentPath;
	vector<kgstr_t>  _fldDat;      // 出力される項目データ
	int              _iRecNo;      // 入力行カウンタ
	
public:
  // コンストラクタ
	kgXml2csv(void);
	~kgXml2csv(void){}

	// i/o件数カウント
  size_t iRecNo(void) const { return *_state.iRecNo; }
  size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
