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
// kgdformat.h 日付時間フォーマットによる文字列置換
// =============================================================================
#pragma once
#include <string>
#include <cstdio>
#include <vector>
#include <kgConfig.h>
#include <kgmod.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;
namespace kgmod { ////////////////////////////////////////////// start namespace

//-------------------------------------------
//日付時間フォーマット
//-------------------------------------------
class kgTimeFormat{

	int _y,_m,_d;
	int _H,_M,_s,_us;
	char _uss[8];
	public:
	enum Pat {
		YEAR = 1,
		MON  = 2, 
		YM   = 3,
		DAY  = 4,
		MD   = 6,
		DATE = 7,
		HOUR = 8,
		MIN  = 16,
		HM	 = 24,
		YMDHM= 31,
		SEC  = 32,
		TIME = 56,
		DT	 = 63,
		USEC  = 64
	};

	kgTimeFormat(void):	_y(-1),_m(-1),_d(-1),_H(-1),_M(-1),_s(-1),_us(-1){}
		
	//年はチェックしない
	// 月は1-12 DAYはここでチェックせず出力時にチェック 
	// 時 0-24 分,秒は0-59 
	bool set(char *str ,int len ,int flg ){	
		if( flg == YEAR){
			_y=0;
			for(int i=0;i<len;i++){ 
				if ( *(str+i)==' ' ) { continue;}
				if(i>=0&&i<4){ _y= _y*10+*(str+i)-'0';} 
			}
		}
		else if( flg == MON){
			_m=0;
			for(int i=0;i<len;i++){ 
				if ( *(str+i)==' ' ) { continue;}
				if(i>=0&&i<2){ _m= _m*10+*(str+i)-'0';} 
			}
			if(_m<1||_m>12){return false;}
		}
		else if( flg == DAY){
			_d=0;
			for(int i=0;i<len;i++){ 
				if ( *(str+i)==' ' ) { continue;}
				if(i>=0&&i<2){ _d= _d*10+*(str+i)-'0';} 
			}
		}
		else if( flg == HOUR){
			_H=0;
			for(int i=0;i<len;i++){ 
				if ( *(str+i)==' ' ) { continue;}
				if(i>=0&&i<2){ _H= _H*10+*(str+i)-'0';} 
			}
			if(_H>24){return false;}
		}
		else if( flg == MIN){
			_M=0;
			for(int i=0;i<len;i++){ 
				if ( *(str+i)==' ' ) { continue;}
				if(i>=0&&i<2){ _M = _M*10+*(str+i)-'0';} 
			}
			if(_M>59){return false;}
		}
		else if( flg == SEC){
			_s=0;
			for(int i=0;i<len;i++){ 
				if ( *(str+i)==' ' ) { continue;}
				if(i>=0&&i<2){ _s = _s*10+*(str+i)-'0';} 
			}
			if(_s>59){return false;}
		}
		else if( flg == USEC){
			_us=len;
			for(int i=0;i<len;i++){ 
				_uss[i] = *(str+i);
			}
			_uss[len] = '\0';
		}
		return true;
	}
	bool dayerr(int flg){
		if(flg & YEAR){
			if(_m==2){
				if( ( ( _y % 4 ) == 0 && ( _y % 100 ) != 0 ) || ( _y % 400 ) == 0){
					return _d<1 || _d>29;
				}else{
					return _d<1 || _d>28;				
				}
			}
			else if(_m==4||_m==6||_m==9||_m==11){
				return _d<1 || _d>30;
			}else{
				return _d<1 || _d>31;
			}
		}
		else{
			if(_m==2){ 
				return _d<1 || _d>29; 
			}
			else if(_m==4||_m==6||_m==9||_m==11){ 
				return _d<1 || _d>30;
			}
			else{
				return _d<1 || _d>31;
			}
		}
	}

	kgstr_t str(int flg){
 
		char buf[32];

		if( (flg & DAY) && dayerr(flg)) { return ""; }

		     if(flg == YEAR) { sprintf(buf,"%d" ,_y);}
		else if(flg == MON)	 { sprintf(buf,"%d" ,_m);}
		else if(flg == YM)	 { sprintf(buf,"%d%02d" ,_y,_m);}
		else if(flg == DAY)	 { sprintf(buf,"%d" ,_d);}
		else if(flg == MD)	 { sprintf(buf,"%02d%02d" ,_m,_d);}
		else if(flg == DATE) { sprintf(buf,"%d%02d%02d" ,_y,_m,_d);}
		else if(flg == HOUR) { sprintf(buf,"%d" ,_H);}
		else if(flg == MIN)	 { sprintf(buf,"%d" ,_M);}
		else if(flg == HM)	 { sprintf(buf,"%0d%02d" ,_H,_M);}
		else if(flg == SEC)	 { 
			if(_us>0){ sprintf(buf,"%d.%s" ,_s,_uss); }
			else     { sprintf(buf,"%d" ,_s); }
		}
		else if(flg == TIME) { 
			if(_us>0){ sprintf(buf,"%02d%02d%02d.%s" ,_H,_M,_s,_uss); }
			else     { sprintf(buf,"%02d%02d%02d" ,_H,_M,_s); }
		}
		else if(flg == DT)	 { 
			if(_us>0){ sprintf(buf,"%04d%02d%02d%02d%02d%02d.%s" ,_y,_m,_d,_H,_M,_s,_uss); }
			else     { sprintf(buf,"%04d%02d%02d%02d%02d%02d" ,_y,_m,_d,_H,_M,_s); }
		}
		else if(flg == YMDHM){ sprintf(buf,"%04d%02d%02d%02d%02d" ,_y,_m,_d,_H,_M);}
		else								 { buf[0] = '\0'; }
		return string(buf);
	}
};

//-------------------------------------------
//開始位置,長さ,パターンを記憶
//-------------------------------------------
class kgTimeparser
{
	vector<int> start;
	vector<int> length;
	vector<char> pattrn;
	char _buf[KG_MAX_STR_LEN];
	int _outpat;
	int numlength(char *str,int lim){
		char *p=str;
		char *limc = str+lim;
		while(*p && p<limc) { 
			if(!(*p>='0'&&*p<='9')&&*p!=' ') break;  
			p++;
		} 
		return p-str;
	}

	int numlength(char *str,int lim,int lim2){
		char *p=str;
		char *limc = str+lim;
		while(*p && p<limc) { 
			if(!(*p>='0'&&*p<='9')&&*p!=' ') break;  
			p++;
		}
		if(*p=='.'){
			while(*p && p<limc) { 
				if(!(*p>='0'&&*p<='9')&&*p!=' ') break;  
				p++;
			}
		}
		return p-str;
	}



	public:
	void compile(const char * cstr);
	kgstr_t extraction(char * cstr , bool err = true);



};


class kgDformat : public kgMod {

	// 引数
	kgArgFld _fField;  	// f=
	kgCSVfld _iFile;  	// i=
	kgCSVout _oFile;		// o=
	kgstr_t   _regstr;	// c=
	bool     _add;			// -A

	kgTimeparser _parser;
	// CSV項目出力
	void writeFld(char** fld, const vector<int>* flg, const vector<string>* val);

	// 引数セット
	void setArgs(void);
public:
	// コンストラクタ
	kgDformat(void);
	~kgDformat(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }
	
	//実行メソッド
	int run(void);

};

}
