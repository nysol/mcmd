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
// kgCsvconv.h tex変換
// =============================================================================
#pragma once
#include <sys/stat.h>
#include <kgmod.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace
class kgtexFormatFLD {
	size_t _st; //format開始位置
	size_t _ed; //format終了位置
	int _fldno;	
public:
	kgtexFormatFLD(){}
	kgtexFormatFLD(size_t spos ,size_t epos,int fldno){
		_st= spos;
		_ed = epos;
		_fldno = fldno;
	}

	~kgtexFormatFLD(){}
	size_t getST(){return _st;}
	size_t getED(){return _ed;}
	int getfldNo(){return _fldno;}

	// DEBUG
	void show(char *p){
		cerr << "=============" << endl;
		cerr << string(p+_st,p+_ed) << " "  << _fldno << endl;
		cerr << "=============" << endl;
	}


};

class kgtexFormatINFO {
	size_t _st; //format開始位置
	size_t _ed; //format終了位置
	int _tp;
	int _keynum;

	vector<kgtexFormatFLD> _fld;
public:
	kgtexFormatINFO();
	kgtexFormatINFO(size_t spos,int tp,int keynum){
		_st=spos;
		_tp=tp;
		_keynum=keynum;
	}
	~kgtexFormatINFO(){}
	void endset(size_t epos){ _ed =epos; }
	void fldset(size_t spos ,size_t epos,int fldno){
		_fld.push_back(kgtexFormatFLD(spos,epos,fldno));
	}
	int getkeyNum(){ return _keynum;}
	int getType(){ return _tp;}

	void outPut(char *data , char **ldt,FILE *wfp){
		size_t from = _st;
		for(size_t i=0 ;i<_fld.size();i++){
			fwrite(data+from,_fld[i].getST()-from,sizeof(char),wfp);
			fwrite(ldt[_fld[i].getfldNo()],strlen(ldt[_fld[i].getfldNo()]),sizeof(char),wfp);
			from =  _fld[i].getED();
		}
		fwrite(data+from,_ed-from,sizeof(char),wfp);
	}

	// DEBUG
	void show(char *p){
		cerr << "#### " << _keynum << " " << _tp << " " << _st <<  " "  << _ed <<  " ####" <<  endl;
		for(size_t i = 0 ; i<_fld.size();i++){
			_fld[i].show(p);
		}
		cerr << "--------------------" <<  endl;
		cerr << string(p+_st,p+_ed) << endl;
		cerr << "########" <<  endl;
	}


};

class kgtexFormatInfoTTL {
	char * _formatData;


	vector<kgtexFormatINFO> _info;
	vector<kgtexFormatINFO> _kinfo; 

	int _kmax; 
	int peakcnt;
	static char const *_tag[];
	FILE *_wfp;

	char* skip(char * p,const char* clist);
public:
  // コンストラクタ
	kgtexFormatInfoTTL(void){ peakcnt = 0;}
	~kgtexFormatInfoTTL(void){}


	void set(char *p,FILE *wfp ,kgArgFld& kfld);
	void completion();

	void endset(size_t epos){
		_info.back().endset(epos);
	}
	void stset(size_t spos,int tp,int keynum){
		_info.push_back(kgtexFormatINFO(spos,tp,keynum));

	}
	void fldset(size_t spos,size_t epos,int fldno){
		_info.back().fldset(spos,epos,fldno);
	}


	void breakPreOutput(char **dt,int bp){
		for(size_t i=0;i<_info.size();i++){
			if(_info[i].getType()==3&& bp+1 == _info[i].getkeyNum()){ 
				_info[i].outPut(_formatData,dt,_wfp);
			}
		}
	}
	
	void breakOutput(char **dt,int bp){
		bool lout =false;
		for(size_t i=0;i<_info.size();i++){
			if(_info[i].getType()==0 && (bp+1) == _info[i].getkeyNum() ){ 
				_info[i].outPut(_formatData,dt,_wfp);
			}
			if(_info[i].getType()==1 && (bp+1) == _info[i].getkeyNum() ){ 
				_info[i].outPut(_formatData,dt,_wfp);
				lout = true;
			}
		}
		if(!lout){
			for(size_t i=0;i<_info.size();i++){
				if(_info[i].getType()==2){ 
					_info[i].outPut(_formatData,dt,_wfp);
				}
			}
		}
	}
	void beginOutput(char **dt){
		_info[0].outPut(_formatData,dt,_wfp);
		breakOutput(dt,0);
	}
	void endOutput(char **dt){
			_info.back().outPut(_formatData,dt,_wfp);
	}

	void lineOutput(char **dt){
		for(size_t i=0;i<_info.size();i++){
			if(_info[i].getType()==2){ 
				_info[i].outPut(_formatData,dt,_wfp);
			}
		}
	}
	void lineLastOutput(char **dt){//future
	}
	// DEBUG
	void show(){
		for(size_t i = 0 ; i<_info.size();i++){
			_info[i].show(_formatData);
		}
	}
	
};

char const *kgtexFormatInfoTTL::_tag[] = {"KEYHEAD","KEYLINEDATA","LINEDATA","KEYFOOT","KEYEND","LINEEND",""};	
// 0:HEAD
// 1:KEYHEAD
//LINEDATA
//LINELAST
//KEYFOOT
//KEYEND
//END


class kgCsvconv : public kgModIncludeSort 
{
	// 引数
	kgArgFld _kField; // k=
	kgCSVkey _iFile;  // i=

	kgAutoPtr2<char> _ap;          // 入力バッファをラッピングするsmart pointer
	char * _formatData;	
	kgtexFormatInfoTTL texInfo;
	FILE *_wfp;

	kgCSVout _oFile;  // o=

	// 引数セット
  void setArgs(void);

public:
  // コンストラクタ
	kgCsvconv(void);
	~kgCsvconv(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return -1; }

	//実行メソッド
	int run(void);

};

}
