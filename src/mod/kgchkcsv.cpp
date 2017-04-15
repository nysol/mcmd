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
// kgchkcsv.cpp CSVデータのチェッククラス
// =============================================================================
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <kgchkcsv.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgArgs.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgChkcsv::kgChkcsv(void)
{
	_name    = "kgchkcsv";
	_version = "###VERSION###";
	_in_rec  =0;
	_bominc  = false;
	#include <help/en/kgchkcsvHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgchkcsvHelp.h>
	#endif
	
}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgChkcsv::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,o=,a=,-diag,-diagl,-r",kgArgs::COMMON|kgArgs::NULL_OUT);

	// 入出力ファイルオープン
	_iFileName = _args.toString("i=",false);
	if( _iFileName.empty() ){ _fp=&cin; }
	else{
		try{ 
			_ffp.open( _iFileName.c_str() );
			if(!_ffp.is_open()){ 
				ostringstream ss;
				ss << "file read open error: " << _iFileName;
				throw kgError(ss.str());
			}
			_fp=&_ffp;	
			_fp->exceptions(ios_base::badbit);
		} catch(...) {
			ostringstream ss;
			ss << "file read open error: " << _iFileName;
			throw kgError(ss.str());
		}
	}

	// -diag チェック内容表示フラグセット
	_diag = _args.toBool("-diag") || _args.toBool("-diagl");

	//出力ファイル設定
	if(_diag){
		kgstr_t v = _args.toString("o=",false);
		if(v.empty()){
			_ofp=&cout;
		}
		else{
			try{ 
				_offp.open(v.c_str());
				if(!_offp.is_open()){ throw; }
				_ofp=&_offp;	
				_ofp->exceptions(ios_base::badbit);
			} catch(...) {
				ostringstream ss;
				ss << "file write open error: " << v;
				throw kgError(ss.str());
			}
		}
	}
	else{
		_oFile.open(_args.toString("o=",false), _env, _nfn_o);	
	}

	// a= 項目指定
	_fldname = _args.toStringVector("a=",false);


	// -r 制御文字無視フラグ
	_ctrl = _args.toBool("-r");

	//-r -diagはどちらか一つ
	if(_diag&&_ctrl){ throw kgError("-r cannot be specified with -diag");}

	//ヘッダ読込済フラグ
	_head_read = _nfn_i;
}
// -----------------------------------------------------------------------------
// diag表示
// -----------------------------------------------------------------------------
void kgChkcsv::showInfol(RecInfo &ri, vector<FldInfo> &fi)
{
	*_ofp << "#===================================================" << endl;
	*_ofp << "# CSVファイル診断 " << endl;
	*_ofp << "# file name : " << _iFileName << endl;
	*_ofp << "#---------------------------------------------------" << endl;
	*_ofp << "# 結果の一文字目の意味" << endl;
	*_ofp << "# # : 情報行(問題なし)" << endl;
	*_ofp << "# ? : KGMODにて扱えない問題点(?の後の文字は解説参照)" << endl;
	*_ofp << "# よって、左端が全て#になればOK" << endl;
	*_ofp << "#===================================================" << endl;
	if(_bominc){ *_ofp << "?l 先頭にBOMが含まれている" << endl; }
	*_ofp << "############################ ヘッダー情報(1行目) ###" << endl;
	if(ri.maxFldCnt==0){
		*_ofp << "# なし" << endl;
	}else{
		*_ofp << "# 項目数 : " << ri.fldNameCnt << endl;
		if(!_nfn_i){
			*_ofp << "# 項目No.  項目名" << endl;
			for(unsigned int i=0; i<ri.fldNameCnt; i++){
				*_ofp << "# " << i+1 << "   " << ri.fldName.at(i) << endl;
			}
		}
	}
	if(!_nfn_i){
		for(unsigned int i=0; i<ri.fldNameCnt-1; i++){
			for(unsigned int j=i+1; j<ri.fldNameCnt; j++){
				if( ri.fldName.at(i)==ri.fldName.at(j) ){
					*_ofp << "?a 同一項目名 : [" << i << "] " << ri.fldName.at(i) << " , [" << j << "] " << ri.fldName.at(j) << endl ;
				}
			}
		}
		for(unsigned int i=0; i<ri.fldNameCnt; i++){
			if(chkFldName(ri.fldName.at(i))==false){
				*_ofp << "?b 不正な項目名 : [" << i << "] " << ri.fldName.at(i)  << endl ;
			}
		}
	}
	*_ofp << "#"<< endl;
	*_ofp << "############## EOL(End Of Line)情報(ヘッダー含む) ##" << endl;
	if(ri.recCnt==0 && ri.maxFldCnt==0){
		*_ofp << "# データなし" << endl;
	}else{
		ri.lf.show	("#         LF改行行数",0,_ofp,_nfn_i);
		ri.cr.show	("?c        CR改行行数",0,_ofp,_nfn_i);
		ri.crlf.show("?c      CRLF改行行数",0,_ofp,_nfn_i);
		ri.null.show("?d 最終行にEOLがない",0,_ofp,_nfn_i);
	}
	*_ofp << "#"<< endl;
	if(ri.maxFldCnt==0){ ri.minLen=0;}
	*_ofp << "################# データ行情報(ヘッダー含まない) ###"<< endl;
	if(ri.recCnt==0){
		*_ofp << "# データなし" << endl;
	}else{
		*_ofp << "#           総行数 : "  << ri.recCnt  << endl;
		*_ofp << "#       総バイト数 : "  << ri.sumLen    << endl;
		*_ofp << "#           平均長 : "  << ri.avgLen   << endl;
		*_ofp << "#           最大長 : "  << ri.maxLen;
		*_ofp << " (LineNo:"<< ri.maxLenLineNo << ")" << endl;
		*_ofp << "#           最小長 : " << ri.minLen;
		*_ofp << " (LineNo:" << ri.minLenLineNo << ")" << endl;
		ri.zero.show			("?e   \\0を含む行数",0,_ofp,_nfn_i);
		ri.overMaxLen.show("?f 最大長超過行数",0,_ofp,_nfn_i);
		*_ofp << "# 注:長さは、改行文字も含めた長さ" << endl;
	}
	*_ofp << "#" << endl;
	*_ofp << "################################# 項目数の一貫性 ###" << endl;
	if(ri.fldCntCnt>0){
		*_ofp << "?g 異なる項目数の行が発見されました。" << endl;
		for(unsigned int i=0; i<ri.fldCntCnt; i++){
			*_ofp << "?g  項目数:" << ri.fldCnt[i]<< " (LineNo:" << ri.fldCntLineNo[i] << ")"  << endl;
		}
	}else{
		if(ri.maxFldCnt==0) { *_ofp << "# 項目なし"<< endl;}
    else								{	*_ofp << "# 全てのレコードの項目数は" << ri.fldNameCnt << "で同じでした。" << endl; }
	}
	*_ofp << "#" << endl;
	*_ofp << "####################################### 項目情報 ###" << endl;
	if(ri.maxFldCnt==0){
		*_ofp << "# 項目なし" << endl;
		*_ofp << "#" << endl;
	}
	for(size_t i=0; i<ri.maxFldCnt; i++){
		if(i<ri.fldNameCnt&&!_nfn_i) { 
			*_ofp << "#  項目番号[" << i+1 << "] 項目名[" <<  ri.fldName.at(i) << "]" << endl;
		}else{
			*_ofp << "#  項目番号[" << i+1 << "]"<< endl;
		}
		fi[i].null.show			("#    NULL値の行数               ",1,_ofp,_nfn_i);
		fi[i].ctrl.show			("?h   制御文字を含む行数         ",0,_ofp,_nfn_i);
		fi[i].dq0.show			("#    DQUOTEで囲われていない行数 ",1,_ofp,_nfn_i);
		fi[i].dq0_dq.show		("?j    |         DQUOTEを含む行数",0,_ofp,_nfn_i);
		fi[i].dq0_fspc.show	("#     |     先頭に空白がある行数",0,_ofp,_nfn_i);
		fi[i].dq0_bspc.show	("#     |     末尾に空白がある行数",0,_ofp,_nfn_i);
		fi[i].dq0_ftab.show	("?i    |      先頭にTABがある行数",0,_ofp,_nfn_i);
		fi[i].dq0_btab.show	("?i    |      末尾にTABがある行数",0,_ofp,_nfn_i);
		fi[i].dq0_mtab.show	("?i    |    値としてTABを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1.show			("#    DQUOTEで囲われている行数   ",1,_ofp,_nfn_i);
		fi[i].dq1_comma.show("#     |          COMMAを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1_lf.show		("#     |             LFを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1_cr.show		("?c    |             CRを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1_crlf.show	("?c    |           CRLFを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1_dq.show		("?k    |         DQUOTEを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1_dqdq.show	("#     | 連続するDQUOTEを含む行数",0,_ofp,_nfn_i);
		fi[i].dq1_fspc.show	("#     |     先頭に空白がある行数",0,_ofp,_nfn_i);
		fi[i].dq1_bspc.show	("#     |     末尾に空白がある行数",0,_ofp,_nfn_i);
		fi[i].dq1_ftab.show	("?i    |      先頭にTABがある行数",0,_ofp,_nfn_i);
		fi[i].dq1_btab.show	("?i    |      末尾にTABがある行数",0,_ofp,_nfn_i);
		fi[i].dq1_mtab.show	("?i    |    値としてTABを含む行数",0,_ofp,_nfn_i);
		*_ofp << "#"<< endl;
	}
	*_ofp << "################################### 問題点の解説 ###" << endl;
	*_ofp << "# ?a : 同じ項目名があると項目番号を特定できない。" << endl;
	*_ofp << "#  【対処方法】kgchkcsv a=x,y,z のように項目名を新たに指定する。" << endl;
	*_ofp << "# ?b : 項目名に不正な文字があるとエラーになる" << endl;
	*_ofp << "#  【対処方法】kgchkcsv a=x,y,z のように項目名を新たに指定する。" << endl;
	*_ofp << "# ?c : KGMODが扱う改行は高速化のためLF(UNIX改行)のみ。" << endl;
	*_ofp << "#      この問題はRFC4180には準拠しておらずKGMOD独自の制約である。" << endl;
	*_ofp << "#  【対処方法】kgchkcsv にて全てLFに変換される。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?d : 最終行にLFやCRなどの改行(EOL)文字が存在しない。" << endl;
	*_ofp << "#      これはRFC4180にも準拠していない。" << endl;
	*_ofp << "#  【対処方法】kgchkcsv にてLFが付加される。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?e : データファイル内に'\\0'が入り込んでいる。" << endl;
	*_ofp << "#      テキストファイルでない可能性が高い。" << endl;
	*_ofp << "#      RFC4180には準拠していない。" << endl;
	*_ofp << "#  【対処方法】kgchkcsv にて、\"&#x00;\"に変換される。" << endl;
	*_ofp << "#              kgchkcsv -rにて\\0は削除される。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?f : KGMODが扱える一行の最大長を超過している。" << endl;
	*_ofp << "#      現在の設定では" << ri.maxRecLen << "バイト以上の長さの行は扱えない。" << endl;
	*_ofp << "#  【対処方法】環境変数を設定することで最大値を変更可能である。" << endl;
	*_ofp << "#        ex) export KG_MaxRecLen=204800" << endl;
	*_ofp << "#      ただし" << KG_LimitRecLen << "バイトを越えては指定できない。 " << endl;
	*_ofp << "#      この問題はRFC4180には準拠しておりKGMOD独自の制約である。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?g : KGMODでは全行同じ項目数を前提とする。" << endl;
	*_ofp << "#      この問題はRFC4180には準拠しておりKGMOD独自の制約である。" << endl;
	*_ofp << "#  【対処方法】" << endl;
	*_ofp << "#       1) kgchkcsv  データHEADERの項目数に合わせる." << endl;
	*_ofp << "#            超過項目は捨てられ、足りない項目はnull値となる" << endl;
	*_ofp << "#       2) kgchkcsv  a=x,y,z HEADER行をスキップし、" << endl;
	*_ofp << "#            指定したx,y,zを項目名として1)と同様の処理を行う。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?h : 制御文字(0x01~0x1F,0x7F)が項目値として入り込んでいる。" << endl;
	*_ofp << "#      テキストファイルでない可能性が高い。" << endl;
	*_ofp << "#      RFC4180には準拠していない。" << endl;
	*_ofp << "#  【対処方法】kgchkcsv にて、\"&#x01;\"の様にテキストコードに変換される。" << endl;
	*_ofp << "#              kgchkcsv -rにて制御文字は削除される。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?i : TABは利用できない。" << endl;
	*_ofp << "#      RFC4180には準拠していない。" << endl;
	*_ofp << "#  【対処方法】kgchksv にて、\"&#x09;\"に変換される。" << endl;
	*_ofp << "#              kgchkcsv -rにてTABは削除される。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?j : DQUOTEで囲われていない中でDQUOTEが見つかった" << endl;
	*_ofp << "#        ex) NG: xxx,oo\"oo,xxx  -> OK: xxx,\"oo\"\"oo\",xxx" << endl;
	*_ofp << "#      RFC4180には準拠していない。" << endl;
	*_ofp << "#  【対処方法】kgchkcsv にて上記の変換を行う。" << endl;
	*_ofp << "#" << endl;
	*_ofp << "# ?k : DQUOTEで囲われている中で単一のDQUOTEが見つかった" << endl;
	*_ofp << "#      ex) NG: xxx,\"oo\"oo\",xxx  -> OK: xxx,\"oo\"\"oo\",xxx" << endl;
	*_ofp << "#      RFC4180には準拠していない。" << endl;
	*_ofp << "#  【対処方法】kgchkcsvにて上記の変換を行う。" << endl;
	*_ofp << "# ?l : 先頭にBOMが含まれている" << endl;
	*_ofp << "#  【対処方法】kgchkcsvにてBOMは除去される。" << endl;
	*_ofp << "#-------------------------------------------------------------" << endl;
}

// -----------------------------------------------------------------------------
// diag表示
// -----------------------------------------------------------------------------
void kgChkcsv::showInfo(RecInfo &ri, vector<FldInfo> &fi)
{

	*_ofp<< "#===================================================" << endl;
	*_ofp<< "# diagnosis for the CSV file " << endl;
	*_ofp<< "# file name : " << _iFileName << endl;
	*_ofp<< "#---------------------------------------------------" << endl;
	*_ofp<< "# meaning of the first charactor on each line" << endl;
	*_ofp<< "# # : commnet or resutl with no error" << endl;
	*_ofp<< "#   : that is, mcmd can handle the CSV file if all lines begin with '#'" << endl;
	*_ofp<< "# ? : error that mcmd cannot handle" << endl;
	*_ofp<< "#   : refer the 'explanation' section for the meaning of the alphabet next of '?'" << endl;
	*_ofp<< "#===================================================" << endl;
	if(_bominc){ *_ofp << "?l It has BOM (Bite Order Mark) at the beginning of data." << endl; }
	*_ofp<< "############################ CSV header for field names(first line) ###" << endl;
	if(ri.maxFldCnt==0){
		*_ofp<< "# no error" << endl;
	}else{
		*_ofp<< "# the number of fields : " << ri.fldNameCnt << endl;
		if(!_nfn_i){
			*_ofp<< "# fieldNo.  name" << endl;
			for(unsigned int i=0; i<ri.fldNameCnt; i++){
				*_ofp<< "# " << i+1 << "   " << ri.fldName.at(i) << endl;
			}
		}
	}
	if(!_nfn_i){
		for(unsigned int i=0; i<ri.fldNameCnt-1; i++){
			for(unsigned int j=i+1; j<ri.fldNameCnt; j++){
				if( ri.fldName.at(i)==ri.fldName.at(j) ){
					*_ofp<< "?a duplicate field names : [" << i << "] " << ri.fldName.at(i) << " , [" << j << "] " << ri.fldName.at(j) << endl ;
				}
			}
		}
		for(unsigned int i=0; i<ri.fldNameCnt; i++){
			if(chkFldName(ri.fldName.at(i))==false){
				*_ofp<< "?b invalid field name : [" << i << "] " << ri.fldName.at(i)  << endl ;
			}
		}
	}
	*_ofp<< "#"<< endl;
	*_ofp<< "############## about EOL(End Of Line) (including a CSV header) ##" << endl;
	if(ri.recCnt==0 && ri.maxFldCnt==0){
		*_ofp<< "# no data found" << endl;
	}else{
		ri.lf.show	("# the number of lines with LF",0,_ofp,_nfn_i);
		ri.cr.show	("?c the number of lines with CR",0,_ofp,_nfn_i);
		ri.crlf.show("?c the number of lines with CRLF",0,_ofp,_nfn_i);
		ri.null.show("?d no EOL found at the end of file",0,_ofp,_nfn_i);
	}
	*_ofp<< "#"<< endl;
	if(ri.maxFldCnt==0){ ri.minLen=0;}
	*_ofp<< "################# about data lines (no including a CSV header) ###"<< endl;
	if(ri.recCnt==0){
		*_ofp<< "# no data found" << endl;
	}else{

		*_ofp<< "# the number of lines : "  << ri.recCnt  << endl;
		*_ofp<< "# data volume in byte : "  << ri.sumLen    << endl;
		*_ofp<< "# the average number of lines : "  << ri.avgLen   << endl;
		*_ofp<< "# the maximum number of lines : "  << ri.maxLen;
		*_ofp<< " (LineNo:"<< ri.maxLenLineNo << ")" << endl;
		*_ofp<< "# the maximum number of lines : " << ri.minLen;
		*_ofp<< " (LineNo:" << ri.minLenLineNo << ")" << endl;
		ri.zero.show			("?e the number of lines having \\0",0,_ofp,_nfn_i);
		ri.overMaxLen.show("?f the number of charactors per line exceeding the limit",0,_ofp,_nfn_i);
		*_ofp << "# note: EOL charactor is counted in the numbers" << endl;

	}
	*_ofp<< "#" << endl;
	*_ofp<< "################################# aoubt the number of fields ###" << endl;
	if(ri.fldCntCnt>0){
		*_ofp<< "?g lines with different number of fields are detected" << endl;
		for(unsigned int i=0; i<ri.fldCntCnt; i++){
			*_ofp<< "?g  # of fields:" << ri.fldCnt[i]<< " (LineNo:" << ri.fldCntLineNo[i] << ")"  << endl;
		}
	}else{
		if(ri.maxFldCnt==0) { *_ofp<< "# no fields found"<< endl;}
    else								{	*_ofp<< "# all lines have same number of fields:" << ri.fldNameCnt << endl; }
	}
	*_ofp<< "#" << endl;
	*_ofp<< "####################################### about field ###" << endl;
	if(ri.maxFldCnt==0){
		*_ofp<< "# no fields" << endl;
		*_ofp<< "#" << endl;
	}
	for(size_t i=0; i<ri.maxFldCnt; i++){
		if(i<ri.fldNameCnt&&!_nfn_i) { 
			*_ofp<< "#  fieldNo[" << i+1 << "] name[" <<  ri.fldName.at(i) << "]" << endl;
		}else{
			*_ofp<< "#  fieldNo[" << i+1 << "]"<< endl;
		}

		fi[i].null.show			("#    # of lines in NULL",1,_ofp,_nfn_i);
		fi[i].ctrl.show			("?h   # of lines with control charactors",0,_ofp,_nfn_i);
		fi[i].dq0.show			("#    # of lines not enclosed with double quotation",1,_ofp,_nfn_i);
		fi[i].dq0_dq.show		("?j    | # of lines having double quotation as a data",0,_ofp,_nfn_i);
		fi[i].dq0_fspc.show	("#     | # of lines having spaces at the beginning",0,_ofp,_nfn_i);
		fi[i].dq0_bspc.show	("#     | # of lines having spaces at the end",0,_ofp,_nfn_i);
		fi[i].dq0_ftab.show	("?i    | # of lines having TAB at the beginning",0,_ofp,_nfn_i);
		fi[i].dq0_btab.show	("?i    | # of lines having TAB at the end",0,_ofp,_nfn_i);
		fi[i].dq0_mtab.show	("?i    | # of lines having TAB",0,_ofp,_nfn_i);
		fi[i].dq1.show			("#    # of lines enclosed with double quotation",1,_ofp,_nfn_i);
		fi[i].dq1_comma.show("#     | # of lines having COMMA",0,_ofp,_nfn_i);
		fi[i].dq1_lf.show		("#     | # of lines having LF",0,_ofp,_nfn_i);
		fi[i].dq1_cr.show		("?c    | # of lines having LF CR",0,_ofp,_nfn_i);
		fi[i].dq1_crlf.show	("?c    | # of lines having LF CRLF",0,_ofp,_nfn_i);
		fi[i].dq1_dq.show		("?k    | # of lines having single double quotation as a data",0,_ofp,_nfn_i);
		fi[i].dq1_dqdq.show	("#     | # of lines having consecutive two double quotation as a data",0,_ofp,_nfn_i);
		fi[i].dq1_fspc.show	("#     | # of lines having spaces at the beginning",0,_ofp,_nfn_i);
		fi[i].dq1_bspc.show	("#     | # of lines having spaces at the end",0,_ofp,_nfn_i);
		fi[i].dq1_ftab.show	("?i    | # of lines having TAB at the beginning",0,_ofp,_nfn_i);
		fi[i].dq1_btab.show	("?i    | # of lines having TAB at the end",0,_ofp,_nfn_i);
		fi[i].dq1_mtab.show	("?i    | # of lines having TAB",0,_ofp,_nfn_i);
		*_ofp<< "#"<< endl;
	}


	*_ofp<< "################################### explanation ###" << endl;
	*_ofp<< "# ?a : It cannot assign the field if there are duplicat name of fields." << endl;
	*_ofp<< "#  [how to] Specify a complete set of field names like 'mchkcsv a=x,y,z'" << endl;
	*_ofp<< "# ?b : MCMD has a valid set of charactors for a field name." << endl;
	*_ofp<< "#  [how to]Specify a complete set of field names like 'mchkcsv a=x,y,z'" << endl;
	*_ofp<< "# ?c : MCMD can handle only lines with LF as a EOL." << endl;
	*_ofp<< "#      This is MCMD original restriction, conforming to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv command that convert CR,CRLF to LF." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?d : The last line does not have a EOL charactor." << endl;
	*_ofp<< "#      It does not conform to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv command add LF at the end." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?e : Data file has '\\0' charactor." << endl;
	*_ofp<< "#      The data may not be a text." << endl;
	*_ofp<< "#      It does not conform to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv that convert the charactor to \"&#x00;\"." << endl;
	*_ofp<< "#           Run mchkcsv command with '-r' option that delete '\\0' characotr." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?f : The number of charactors per line exceed the limit MCMD can handle." << endl;
	*_ofp<< "#      MCMD can handle a line less than or equal to " << ri.maxRecLen << " bytes of charactors." << endl;
	*_ofp<< "#  [how to] Change a enviroment variable KG_MaxRecLen." << endl;
	*_ofp<< "#        ex) export KG_MaxRecLen=2048000" << endl;
	*_ofp<< "#      You cannot specify the number greater than " << KG_LimitRecLen << " bytes." << endl;
	*_ofp<< "#      This is MCMD original restriction, conforming to RFC4180." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?g : MCMD can handle only a CSV data that all lines have same number of fields." << endl;
	*_ofp<< "#      This is MCMD original restriction, conforming to RFC4180." << endl;
	*_ofp<< "#  [how to]" << endl;
	*_ofp<< "#       1) Use mchkcsv command that aligns all lines with same number of the field name header." << endl;
	*_ofp<< "#            Exceeded field value will be cut off, and it will add a NULL value for missing field." << endl;
	*_ofp<< "#       2) Use mchkcsv command with a= parameter." << endl;
	*_ofp<< "#            It uses the field names on a= parameter just as a header line (the header line will be skipped)." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?h : Field value include a control charactors (0x01~0x1F,0x7F)." << endl;
	*_ofp<< "#      The data may not be a text." << endl;
	*_ofp<< "#      It does not conform to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv that convert the charactor to text like \"&#x01;\"." << endl;
	*_ofp<< "#           Run mchkcsv command with '-r' option that delete the control characotrs." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?i : TAB cannot be used." << endl;
	*_ofp<< "#      It does not conform to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv that convert the TAB to \"&#x09;\"." << endl;
	*_ofp<< "#           Run mchkcsv command with '-r' option that delete the TAB." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?j : Double quotation charactor is found in a value not enclosed by double quotation." << endl;
	*_ofp<< "#        ex) NG: xxx,oo\"oo,xxx  -> OK: xxx,\"oo\"\"oo\",xxx" << endl;
	*_ofp<< "#      It does not conform to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv that makes convertion in the above example." << endl;
	*_ofp<< "#" << endl;
	*_ofp<< "# ?k : Double quotation charactor is found in a value enclosed by double quotation." << endl;
	*_ofp<< "#      ex) NG: xxx,\"oo\"oo\",xxx  -> OK: xxx,\"oo\"\"oo\",xxx" << endl;
	*_ofp<< "#      It does not conform to RFC4180." << endl;
	*_ofp<< "#  [how to] Run mchkcsv that makes convertion in the above example." << endl;
	*_ofp<< "# ?l : It has BOM (Bite Order Mark) at the beginning of data." << endl;
	*_ofp<< "#  [how to] Run mchkcsv command that remove the BOM." << endl;
	*_ofp<< "#-------------------------------------------------------------" << endl;
}

// -----------------------------------------------------------------------------
//  record関連情報の設定
// -----------------------------------------------------------------------------
void kgChkcsv::setRecStat(char *rec, size_t recLen, RecInfo &recInfo)
{
  // 最大長overの統計
  if(recLen>recInfo.maxRecLen){ recInfo.overMaxLen.set(_in_rec); }
  
  // '\0'読み込みの統計 getRec関数で'\0'を読み込んだらzeroFlgが立つ
  if(_zeroflg) { recInfo.zero.set(_in_rec);}

  // 改行の統計(文字数によって)
  if(recLen>1){
    if(*(rec+recLen-2)=='\r' && *(rec+recLen-1)=='\n') { recInfo.crlf.set(_in_rec); }
    else if(*(rec+recLen-1)=='\n')										 { recInfo.lf.set(_in_rec); }
    else if(*(rec+recLen-1)=='\r')										 { recInfo.cr.set(_in_rec);}
    else																							 { recInfo.null.set(_in_rec);} 
  }else if(recLen>0){
    if(*(rec+recLen-1)=='\n')			 { recInfo.lf.set(_in_rec);}
    else if(*(rec+recLen-1)=='\r') { recInfo.cr.set(_in_rec);}
    else													 { recInfo.null.set(_in_rec);}
  }

  // レコード長の統計
  if(_head_read){
    if(recLen>recInfo.maxLen){
      recInfo.maxLen=recLen;
      recInfo.maxLenLineNo=_in_rec;
    }
    if(recLen<recInfo.minLen){
      recInfo.minLen=recLen;
      recInfo.minLenLineNo=_in_rec;
    }
    recInfo.sumLen+=recLen;
    recInfo.recCnt+=1;
  }
  _head_read=true;
}
// -----------------------------------------------------------------------------
//  field関連情報の設定(cnt) //5つ以上は登録しない
// -----------------------------------------------------------------------------
void kgChkcsv::setFldCntCnt(int firstfldCnt,int fldCnt,RecInfo &ri)
{
  if(firstfldCnt==fldCnt) return;
  if(ri.fldCntCnt>=5) return; 
	ri.fldCnt[ri.fldCntCnt]=fldCnt;
  ri.fldCntLineNo[ri.fldCntCnt]=_in_rec;
	ri.fldCntCnt++;
}
// -----------------------------------------------------------------------------
//  field関連情報の設定(stat)
// -----------------------------------------------------------------------------
void kgChkcsv::setFldStat(char *fld, size_t fldLen, bool dqFlg, bool sngDqFlg,FldInfo &fi)
{
	// 項目長の累計
  fi.sumLen+=fldLen;  
  
	// データのカウント(NULL or NULL以外)
  if(*fld=='\0'){          
    fi.null.set(_in_rec);
  }else{
    fi.lineCnt++;         
    if(fldLen>fi.maxLen){ 
      fi.maxLen=fldLen;
      fi.maxLenLineNo=_in_rec;
    }
    if(fldLen<fi.minLen){ // 項目最小長の更新
      fi.minLen=fldLen;
      fi.minLenLineNo=_in_rec;
    }
  }
  // コントロールキャラクタを含むかどうかの判定(TAB,CR,LFは除く)
  for(size_t j=0; j<fldLen; j++){
    unsigned char c=*(fld+j);
    if( (c<0x20 && c!=0x0d && c!=0x0a && c!=0x09) || *(fld+j)==0x7F){
      fi.ctrl.set(_in_rec);
      break;
    }
  }
  if( dqFlg ){
    fi.dq1.set(_in_rec);
    if(strstr(fld,",") != NULL) 		{ fi.dq1_comma.set(_in_rec); }
    if(strstr(fld,"\n")!=NULL) 			{ fi.dq1_lf.set(_in_rec); }
    if(hasSingleChr(fld,'\r','\n')) { fi.dq1_cr.set(_in_rec); }
    if(strstr(fld,"\r\n") != NULL) 	{ fi.dq1_crlf.set(_in_rec); }
    if(strstr(fld,"\"") != NULL)   	{ fi.dq1_dqdq.set(_in_rec); }
    if(sngDqFlg)                   	{ fi.dq1_dq.set(_in_rec); }
    if(*fld==' ')                  	{ fi.dq1_fspc.set(_in_rec); }
    if(*fld=='\t')                 	{ fi.dq1_ftab.set(_in_rec); }
    if(hasBchr(fld,' '))        	  { fi.dq1_bspc.set(_in_rec); }
    if(hasBchr(fld,'\t'))          	{ fi.dq1_btab.set(_in_rec); }
    if(hasMchr(fld,'\t'))          	{ fi.dq1_mtab.set(_in_rec); }
  }else{
   	fi.dq0.set(_in_rec);
    if(strstr(fld,"\"") != NULL)   { fi.dq0_dq.set(_in_rec); }
    if(*fld==' ')                  { fi.dq0_fspc.set(_in_rec); }
    if(*fld=='\t')                 { fi.dq0_ftab.set(_in_rec); }
    if(hasBchr(fld,' '))           { fi.dq0_bspc.set(_in_rec); }
    if(hasBchr(fld,'\t'))          { fi.dq0_btab.set(_in_rec); }
    if(hasMchr(fld,'\t'))          { fi.dq0_mtab.set(_in_rec); }
  }
}
// -----------------------------------------------------------------------------
// 行単位読み込み(prevcはMac改行チェック用(\rの次が\nでないときにその値がセットされる))
// -----------------------------------------------------------------------------
int kgChkcsv::getRec(char* buf, istream *fp, unsigned char* prevc)
{
	int cr=0;
	int i,j;
	char hexbuf[10];
  _zeroflg=false;
  bool dqFlg = false;    //項目の先頭がDQの場合のみtrueになる
  bool prvDQFlg = false; //前回がDQの場合のみtrueになる

	for(i=0; i<KG_LimitRecLen; i++){
		//-------------------------------------
		//  データ読込
		//-------------------------------------
		unsigned char cc;
		if(*prevc!='\0'){ // 初回チェック 前回のgetRecの最後のcharが\0でない(mac改行)
			cc=*prevc;
			*prevc='\0';
		}else{
			int c = fp->get();
			if(c==EOF && i==0) return 0;
			if(c==EOF) break;
			cc=static_cast<unsigned char>(c);
		}
		//-------------------------------------
		//  前回値'\r'の場合の処理
		//-------------------------------------
		if(cr==1){
			if(cc=='\n') {  buf[i++] = cc; }
			else				 { *prevc    = cc; }
			break;
		}
		// 項目の先頭がDQで一つ前がDQだったときの処理
		if(prvDQFlg){
			if(cc=='\n'||cc=='\r'||cc==','){ dqFlg=false; prvDQFlg=false; }
			else if(cc!='"'){prvDQFlg=false;}
		}

		// diagモードの場合         \0のみ無視
		// 制御コード無視モードの場合 制御コード無視
    // 制御コード置換(通常)の場合 データ置換え
		if(_diag){
			if(cc=='\0'){ _zeroflg=true; continue; }
		}
		else if( _ctrl ){    
			if( (cc<0x20 && cc!=0x0d && cc!=0x0a) || cc==0x7F){ i--; continue; }
		}else {
			if( (cc<0x20 && cc!=0x0d && cc!=0x0a) || cc==0x7F){
				sprintf(hexbuf,"&#x%02x;",cc);
				for(j=0; j<6 && i<KG_LimitRecLen; j++,i++){ buf[i]=hexbuf[j]; }
				if(i>=KG_LimitRecLen){kgError::recLenErr();}
				i--;
				continue;
			}
		}
		buf[i]=cc;
		if(!dqFlg && cc=='\n'){ i++; break; }
		if(!dqFlg && cc=='\r'){ cr=1; continue; }
		if(cc=='"'){ 
			if(prvDQFlg){
				prvDQFlg = false;
			}else if(dqFlg){
				prvDQFlg = true;
			}
			else{
				if(i==0||buf[i-1]==','){ dqFlg = true;}
			}
		}
	}
	if(i>=KG_LimitRecLen){ kgError::recLenErr(); }
	// buf[i]='\0';<-???
	//行数カウント
	_in_rec++;
	return i;
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgChkcsv::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();
  vector<FldInfo>  fldInfo;
  RecInfo recInfo;
	int fistlinefcnt=0;
	//レコード情報の初期設定
	recInfo.maxRecLen=_env->getMaxRecLen();
	recInfo.minLen=KG_LimitRecLen;
	//行単位領域確保
  kgAutoPtr2<char> ap1;
  try {
    ap1.set( new char[KG_LimitRecLen] ); // 行数×csv項目数
  } catch(...) {
    throw kgError("memory allocation error ");
  }
  char* rec = ap1.get();

	unsigned char prevc='\0';
  while(1){
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
  	//record(行)関連情報の設定
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
		size_t recLen = getRec(rec,_fp,&prevc);
		if(recLen == 0){ break; }

		if(_in_rec==1 && recLen >= 3){//BOMチェック
			if((unsigned char)*rec==0xEF && (unsigned char)*(rec+1)==0xBB && (unsigned char)*(rec+2) == 0xBF){ _bominc	= true; }
		}
    if(_diag){ setRecStat(rec,recLen,recInfo);}
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
  	//fld(項目)関連情報の設定
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
		rmEol(rec,recLen);
		size_t fldCnt;
    try{
	    fldCnt=cntFldToken(rec,recInfo.maxRecLen,true);
	  } catch(kgError& err) {
			ostringstream ss;
			ss << "at line #" << _in_rec;
	  	err.addMessage(ss.str());
	  	throw err;
	  }

		kgAutoPtr2<char*> ap2;
		try {
			ap2.set( new char*[fldCnt] );
		} catch(...) {
			throw kgError("memory allocation error2");
		}
		char** strdata =ap2.get();
		vector<bool> sngDQ(fldCnt ,false);
		vector<bool> dqflg(fldCnt ,false);
		if(_in_rec==1){ fistlinefcnt=fldCnt;}
    if(_diag){
			setFldCntCnt(fistlinefcnt,fldCnt,recInfo);
			if(fldCnt>recInfo.maxFldCnt){
				for(size_t i=recInfo.maxFldCnt; i<fldCnt; i++){
					FldInfo fldInfoadd;
					fldInfo.push_back(fldInfoadd);
        }
        recInfo.maxFldCnt=fldCnt;
      }
    }
		sepFldToken(strdata, fldCnt, rec,sngDQ,dqflg);
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
  	//header(ヘッダ項目)関連情報の設定
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
		if(_in_rec==1){
			recInfo.fldNameCnt=fldCnt;
			if(_diag){
				if(!_nfn_i){
					for(unsigned int i=0; i<fldCnt; i++){
						string s=string(strdata[i]);
						recInfo.fldName.push_back(s);
        	}
        }
        continue;
      }else{
				if(_fldname.size()){
					recInfo.fldNameCnt=_fldname.size();
					_oFile.writeFldName(_fldname);
					if(!_nfn_i){ continue; }
				}
				else{
					if(!_nfn_i){//１行目が項目名
						if(!_nfn_o){
							for(unsigned int i=0; i<fldCnt; i++){
								char *p = strdata[i];
								if(i==0 && _bominc){ p = p+3; }
								if(i<fldCnt-1){
									_oFile.writeStr(p, false);
								}
								else{
									_oFile.writeStr(p);
								}
							}
							_oFile.writeEolNC();
						}
						continue;
					}
				}
      }
		}
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
		// data(データ項目)関連情報の設定
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
		if(_diag){
			for(unsigned int i=0; i<fldCnt; i++){
				setFldStat(strdata[i],strlen(strdata[i]),dqflg[i],sngDQ[i],fldInfo[i]);
			}     
		}else{// データの出力
			if(recInfo.fldNameCnt>fldCnt){//項目名の数が多い場合
				size_t i=0;
				for(i=0; i<fldCnt; i++){ 
					if(_assertNullOUT){ if(*strdata[i]=='\0') { _existNullOUT = true;} }
					if(_in_rec==1 && _bominc && i==0){
						_oFile.writeStr( strdata[i]+3, false); 
					}
					else{
						_oFile.writeStr( strdata[i], false); 
					}
				}
				for(; i<recInfo.fldNameCnt-1; i++){ _oFile.writeDlm(); }
				_oFile.writeEol();
			}
			else{
				for(size_t i=0; i<recInfo.fldNameCnt; i++){
					if(_assertNullOUT){ if(*strdata[i]=='\0') { _existNullOUT = true;} }
					
					if(_in_rec==1 && _bominc && i==0){
						_oFile.writeStr( strdata[i]+3, i==recInfo.fldNameCnt-1);
					}
					else{					
						_oFile.writeStr( strdata[i], i==recInfo.fldNameCnt-1);
					}
				}
			}
    }		
	}
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
	// final(最終結果)出力
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
  if(_diag){
    //recInfo.lineCnt=_in_rec;
		recInfo.ave_cal();
    for(size_t i=0; i<recInfo.maxFldCnt; i++){
			fldInfo[i].summary_cal();
		}
		if(_args.toBool("-diagl")){	
	    showInfol(recInfo,fldInfo);
	  }else{
	    showInfo(recInfo,fldInfo);
	  }
  }
	// 終了処理
	if(_ffp.is_open()){ _ffp.close();}
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
