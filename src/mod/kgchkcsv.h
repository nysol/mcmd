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
#pragma once
#include <fstream>
#include <vector>
#include <kgConfig.h>
#include <kgEnv.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace
//------------------------------------------------------------------------------
// 行数情報
// 行数,行No.（行No.は３つまで）を記憶する
//------------------------------------------------------------------------------		
struct CntLine 
{
  int cnt;
  int lineNo[3];

	CntLine(void): cnt(0){
		for(int i=0;i<3;i++){ lineNo[i]=0; }
	}
	// count & set
	void set(size_t no)
	{
	  if(cnt<3){ lineNo[cnt]=no;}
	  cnt++;
  }
	// 内容表示（cntが０の場合,flgにより出力するか決める）
	void show( const char *str, int flg,ostream* ofp ,bool headflg)
	{
		int i;
		if(flg==0 && cnt==0) return;
		int div=0;
		if(!headflg) { div=1;}
		*ofp << str << " : " << cnt << " ";
		if(lineNo[0]!=0){
			*ofp << "(LineNo: " ;
			for(i=0; i<3; i++){
				if(lineNo[i]!=0){ *ofp << lineNo[i]-div << " " ; }
			}
			if(cnt>3) { *ofp << "... )" ;}
			else      { *ofp << ")" ;}
		}
		*ofp << endl;
	}
};
//------------------------------------------------------------------------------
// 行情報
//------------------------------------------------------------------------------		
struct RecInfo 
{
  struct CntLine cr;
  struct CntLine lf;
  struct CntLine crlf;
  struct CntLine zero;
  struct CntLine null;
  struct CntLine overMaxLen;

  size_t maxRecLen;
  int fldCnt[5];
  int fldCntLineNo[5];
  unsigned int fldCntCnt;
	size_t  maxFldCnt;

  size_t recCnt;		//全行数

	vector<kgstr_t> fldName;
  unsigned int  fldNameCnt;

  double avgLen;				// 行長平均	
  size_t sumLen;				// 行長合計
  size_t maxLen;				// 最大行長
  size_t maxLenLineNo;	// 最大行長の行No
  size_t minLen;				// 最小行長
  size_t minLenLineNo;	// 最小行長の行No

	RecInfo(void) : maxRecLen(0),fldCntCnt(0),maxFldCnt(0),recCnt(0),
				fldNameCnt(0),avgLen(0),sumLen(0),maxLen(0),maxLenLineNo(0),minLen(0),minLenLineNo(0)
	{
		for(int i=0;i<5;i++){
  		fldCnt[i]=0;
  		fldCntLineNo[i]=0;
		}
	} 
	void ave_cal(){
    if(recCnt>0){ avgLen=(double)sumLen / (double)recCnt;}
  }
	
};
//------------------------------------------------------------------------------
// 項目情報
//------------------------------------------------------------------------------		
struct FldInfo 
{
  struct CntLine null;  // null値の行数
  struct CntLine ctrl;  // x01~x1F,x7Fを含む行数
  struct CntLine dq0;  // DQUOTEで囲われていない行数
  struct CntLine dq0_dq;
  struct CntLine dq0_fspc;
  struct CntLine dq0_bspc;
  struct CntLine dq0_ftab;
  struct CntLine dq0_btab;
  struct CntLine dq0_mtab;
  struct CntLine dq1;  // DQUOTEで囲われた行数
  struct CntLine dq1_comma;
  struct CntLine dq1_lf;
  struct CntLine dq1_cr;
  struct CntLine dq1_crlf;
  struct CntLine dq1_dqdq;
  struct CntLine dq1_dq;
  struct CntLine dq1_fspc;
  struct CntLine dq1_bspc;
  struct CntLine dq1_ftab;
  struct CntLine dq1_btab;
  struct CntLine dq1_mtab;

  size_t lineCnt;  //null値行を省いた行数
  double avgLen;
  double avgNotNulLen;
  size_t sumLen;
  size_t maxLen;
  size_t minLen;
  size_t maxLenLineNo;
  size_t minLenLineNo;

	FldInfo(void):lineCnt(0),avgLen(0),avgNotNulLen(0),sumLen(0),
		maxLen(0),minLen(KG_SIZE_MAX),maxLenLineNo(0),minLenLineNo(0){}

	void summary_cal(){
		size_t tcnt = null.cnt + lineCnt;
    if( tcnt>0 ) { avgLen  = (double)sumLen / (double)(null.cnt+lineCnt); }
		if(lineCnt>0){ avgNotNulLen = (double)sumLen / (double)lineCnt;}
  }
	
};

class kgChkcsv : public kgMod {

	// 引数
	kgstr_t		_iFileName;  			// i=
	kgCSVout _oFile; 		 				// o=
	vector<kgstr_t>  _fldname; // a=
	bool     _diag; 					 // -diag
	bool			_ctrl;					 // -r
	bool			_head_read;			// ヘッダ読込フラグ

	ifstream _ffp;	// ファイルストリーム(標準入力用)
	istream* _fp;	  // ファイルストリーム

	ofstream _offp;// ファイルストリーム(-diag標準出力用)
	ostream* _ofp;// ファイルストリーム(-diag用)

	//処理行数
	size_t _in_rec;
	//
	bool _zeroflg;
	bool _bominc;

	// 引数セット
	void setArgs(void);

	int  getRec(char buf[], istream *fp, unsigned char* prevc);
	void setRecStat(char *rec, size_t recLen, RecInfo &recInfo);
	void setFldStat(char *fld, size_t fldLen, bool dqFlg, bool sngDqFlg,FldInfo &fi);
	void setFldCntCnt(int firstfldCnt,int fldCnt,RecInfo &ri);

	void showInfo(RecInfo &ri, vector<FldInfo> &fi);
	void showInfol(RecInfo &ri, vector<FldInfo> &fi);

public:
	// コンストラクタ
	kgChkcsv(void);
	~kgChkcsv(void){}

	// 実行	
	int run(void);

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { 
		if(_nfn_i || _in_rec==0) { return _in_rec;} 
		else										 { return _in_rec-1;} 
	}
	size_t oRecNo(void) const { return _oFile.recNo(); }
};

}
