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
// kgtermios 
// ============================================================================
#pragma once
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <termios.h>
#include <wchar.h>

#define KGI_NULL       0
#define KGI_NORMAL     2
#define KGI_KEY_ESC    3
#define KGI_KEY_UP     4
#define KGI_KEY_DOWN   5
#define KGI_KEY_RIGHT  6
#define KGI_KEY_LEFT   7
#define KGI_KEY_ENTER	 8
#define KGI_KEY_BS		 9
#define KGI_KEY_TAB 	 10
#define KGI_UNDEFINE -1


#define KGI_CLR_BLACK   0
#define KGI_CLR_RED     1
#define KGI_CLR_GREEN   2
#define KGI_CLR_YELLOW  3
#define KGI_CLR_BLUE    4
#define KGI_CLR_MAGENDA 5
#define KGI_CLR_CYAN    6
#define KGI_CLR_WHITE   7
#define KGI_CLR_DEFAULT 8


struct kgExWchar{
	int type;
	wint_t c;
	kgExWchar(){
		type = KGI_NORMAL;
		c=L'\0';
	}
};


class kgTermiosEX
{
	#define BUF_SZ 4096
	#define DF_TIMEOUT 4000
	#define ESC_TIMEOUT 500

	struct termios	tio_save;
	const int _scrfd;
	char _buf[BUF_SZ];
	wchar_t _wbuf[BUF_SZ];
  struct timeval tv;
	fd_set rfds;
	int bufend;
	int bufpos;
	int timout;
	bool escFLG;
	mbstate_t ms;

	void flush(){ fflush(stdout); }
	

	// 読み込みメイン
	wint_t read_inner(){
	
		//読み込み済み
		if(bufpos<bufend){
			bufpos++;
			if(escFLG)escFLG=false;
			return _wbuf[bufpos-1];
		}
		int retval;
		while(1){
			// 入力待機
			if(timout==0){
				FD_ZERO(&rfds);
				FD_SET(0, &rfds);
				retval = select(1, &rfds, NULL, NULL, NULL);
			}
			else{
				FD_ZERO(&rfds);
				FD_SET(0, &rfds);
			  tv.tv_sec = timout/1000;
  			tv.tv_usec = timout%1000;
  			retval = select(1, &rfds, NULL, NULL, &tv);
			}
			// 入力状態変化
			if (retval == -1){
				printf("err\n");
				return '\0';
  		}else if (retval == 0){ //timeout
	  		if(escFLG){//ESC OnLY
  				timout = 4000;
  				escFLG=false;
					return '\0';
  			}else{
  				timout = 0;
  			}
  		}
  		else{ break; }
  	}
  	// 読み込みあり
		if(FD_ISSET(0, &rfds)){// 一応チェック
			int len = ::read(_scrfd,_buf,BUF_SZ);
			_buf[len]='\0';
			const char* p=_buf;
			mbsrtowcs(_wbuf, &p, BUF_SZ, &ms);
			bufpos =0;
			bufend =wcslen(_wbuf);
			if(_wbuf[bufpos]==0x1b){
				escFLG=true;
				timout = ESC_TIMEOUT;
			}
			else{timout = 4000;}
			bufpos++;
			return _wbuf[bufpos-1];
		}
		return '\0';
	}

	void undo(){ bufpos--;}

	public:
	kgTermiosEX(int scrfd=0):
		_scrfd(scrfd),bufend(0),bufpos(0),
		timout(DF_TIMEOUT),escFLG(false){
		struct termios	tio;
		tcgetattr(_scrfd,&tio);
		tio_save = tio;
		tio.c_lflag&=~(ICANON|IEXTEN|ECHO|ECHOE|ECHOK|ECHONL);
		tcsetattr(_scrfd,TCSANOW,&tio);
		setlocale(LC_ALL,"");
		memset(&ms,0,sizeof(mbstate_t));
	}
	~kgTermiosEX(){
		tcsetattr(_scrfd,TCSANOW,&tio_save);
	}

	////////////////////////////////////////
	// 入力関係
	////////////////////////////////////////
	// 入力されるエスケープシーケンスを調べるのは
	// 面倒なので抜粋したものみ
	kgExWchar read(){
		kgExWchar rtn;
		wint_t ind ;
		ind = read_inner();
		if(ind==0x1b){//ESC処理
			ind = read_inner();
			if(ind=='\0'){ rtn.type=KGI_KEY_ESC;}
			else if (ind==0x5b){//arrow
				ind = read_inner();
				if (ind==0x41){rtn.type=KGI_KEY_UP;}
				else if (ind==0x42){rtn.type=KGI_KEY_DOWN;}
				else if (ind==0x43){rtn.type=KGI_KEY_RIGHT;}
				else if (ind==0x44){rtn.type=KGI_KEY_LEFT;}
				else{ rtn.type=KGI_UNDEFINE	;}
			}
			else{// ESCのあとに読み込まれたのでもどす（他のエスケープの対応要）
				undo();
				rtn.type=KGI_KEY_ENTER;
			}
		}
		else if(ind=='\n'){//改行
			rtn.type=KGI_KEY_ENTER	;
			rtn.c=ind;
		}
		else if(ind==0x7F){//バックスペース
			rtn.type=KGI_KEY_BS	;
			rtn.c=ind;
		}
		else if(ind=='\t'){//TAB
			rtn.type=KGI_KEY_TAB	;
			rtn.c=ind;
		}
		else if(ind=='\0'){//NUL
			rtn.type=KGI_NULL	;
			rtn.c=ind;
		}
		else{
			rtn.c=ind;
		}
		return rtn;
	}
	
	////////////////////////////////////////
	// 出力関係
	////////////////////////////////////////
	// 位置指定移動
	void move(int x,int y){	
		printf("\e[%d;%dH",y,x);
		flush();
	}

	// 移動
	void shift(int i){
		if(i==0){ return;}
		if(i<0) { printf("\e[%dD",i*-1);}
		else    { printf("\e[%dC",i   );}
		flush();
	}	

	// バックスペース削除
	void backsp(int i){	
		if(i==0) { return ;}
		printf("\e[%dD",i);
		printf("\e[%dX",i);
		flush();
	}
	// 削除
	void del(int i){	
		printf("\e[%dX",i);
		flush();
	}

	// 文字列出力
	void output(char *d){	//d:出力文字列
		printf("%s",d);		
		flush();
	}

	// 文字列カラー出力
	void outputCLR(char *d,int fclr=KGI_CLR_RED,int bclr=KGI_CLR_GREEN,bool bold=false){ //d:出力文字列
		if(bold){
			printf("\e[1;3%d;4%dm%s\e[0;39;49m",fclr,bclr,d);
		}
		else{
			printf("\e[3%d;4%dm%s\e[39;49m",fclr,bclr,d);
		}
		flush();
	}
	
	
	// tp 2: 削除＆ADD 1:ADD 0:NO DEL && NO ADD 
	void putchar(wint_t ind ,int tp=1){
		if(tp==2){
			int vSize;
			if(isascii(ind)){ vSize = 1; }
			else            { vSize = 2; }
			printf("\e[%dX",vSize);
		}
		if(tp){ printf("%lc",ind);}
		if(bufpos==bufend){ flush();}
	}
	
};

	

