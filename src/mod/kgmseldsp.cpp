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
#include <sys/stat.h>
#include <kgArgs.h>
#include <kgError.h>
#include <kgItermios.h>
#include <kgTextarea.h>
#include <kgmseldsp.h>
using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgMseldsp::kgMseldsp(void)
{
	_name    = "kgseldsp";
	_version = "###VERSION###";

	#include <help/en/kgmseldspHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgmseldspHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgMseldsp::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("x=,y=,i=,seldata=,f=,o=,height=");

	_x_val =  atoi(_args.toString("x=",true).c_str());
	_y_val =  atoi(_args.toString("y=",true).c_str());
	if(_x_val<=0) { _x_val=1; } 
	if(_y_val<=0) { _y_val=1; } 


	kgstr_t h = _args.toString("height=",false);
	_height=-1;
	if( h.size()!=0){ _height = atoi(h.c_str()); }

	// f= 項目引数のセット
	_f_str = _args.toString("f=",false);
  _oFile.open(_args.toString("o=",true), _env,_f_str.size()==0);

	_str_s =  _args.toString("seldata=",false);
	_i_s   =  _args.toString("i=",false);

	if(_str_s.size()==0&&_i_s.size()==0){
		throw kgError("necessary i= or str=");
	}

}

void kgMseldsp::sellist(kgTermiosEX *sc,char **selp ,int st,int pos)
{
	for(int i=0; i<_height;i++){
		sc->move(_x_val,_y_val+i);
		if(i==pos){
			sc->del(_width);
			sc->outputCLR(selp[st+i]);
		}else{
			sc->del(_width);
			if(_outinfo[st+i]){
				sc->outputCLR(selp[st+i],KGI_CLR_DEFAULT,KGI_CLR_YELLOW);
			}
			else{
				sc->output(selp[st+i]);
			}
		}
	}
	sc->move(_x_val,_y_val+pos);

}

// fflush利用する
int kgMseldsp::run(void) try
{
	// パラメータセット&出力ファイルオープン
	setArgs();


	struct stat st;
	char *seldata;
	char *selp[MAX_SELCNT];
	kgAutoPtr2<char> ap; 

	if(_i_s.size()){
		if(stat(_i_s.c_str(),&st)!=0){
			throw kgError("file not found");
		}
		try {
			ap.set( new char[st.st_size+1] );
		} catch(...) {
			throw kgError("memory allocation error on kgdsp");
		}
		seldata = ap.get();
		FILE *fp = fopen(_i_s.c_str(),"r");
		fread(seldata, sizeof(char), st.st_size, fp);
		seldata[st.st_size] = '\0';
		fclose(fp);
	}
	else{
		try {
			ap.set( new char[strlen(_str_s.c_str())+1] );
		} catch(...) {
			throw kgError("memory allocation error on kgdsp");
		}
		seldata = ap.get();
		strcpy(seldata,_str_s.c_str());
		seldata[strlen(_str_s.c_str())] = '\0';

	} 
	vector<wstring> selpw;
	_width=0;
	int cnt=0;
	char *p=seldata;
	char *q=seldata;
	for(;*q!='\0';q++){
		if(*q=='\n'||*q==','){
			*q='\0';
			selp[cnt] = p;
			if (_width<toWcs(p).size()){ _width=toWcs(p).size();}
			cnt++;
			if (cnt >= MAX_SELCNT){  throw kgError("seldata line over"); }
			p=q+1;
		}
	}
	if(q!=p){
		selp[cnt] = p;
		if (_width<toWcs(p).size()){ _width=toWcs(p).size();}
		cnt++;
		if (cnt >= MAX_SELCNT){  throw kgError("seldata line over"); }
	}
	_width*=2;
	if(cnt<=0){ throw kgError("seldata 0 line"); }
	if(_height<=0) { _height=cnt; }
	if(_height>cnt){ _height=cnt; }
	
	_outinfo.resize(cnt,false); 
	// 初期描画
	kgTermiosEX scrn;
	sellist(&scrn,selp,0,0);

	// INPUT
	bool endFLG=false;
	int rtnFLG=0;
	//int selpos=0;
	int scrlpos=0;
	int viewpos=0;
	kgExWchar ind ;//input DATA
	
	while(1){
		ind = scrn.read();
		switch(ind.type){
			case KGI_KEY_ESC:
				rtnFLG=1;
				endFLG=true;
				break;
			case KGI_KEY_UP:
				if(scrlpos+viewpos> 0){
					if(viewpos==0){//再描画
						scrlpos--;
						sellist(&scrn,selp,scrlpos,0);
					} 
					else{
						if(_outinfo[scrlpos+viewpos]){
							scrn.outputCLR(selp[scrlpos+viewpos],KGI_CLR_DEFAULT,KGI_CLR_YELLOW);
						}else{
							scrn.output(selp[scrlpos+viewpos]);
						}
						viewpos--;
						scrn.move(_x_val,_y_val+viewpos);
						if(_outinfo[scrlpos+viewpos]){
							scrn.outputCLR(selp[scrlpos+viewpos],KGI_CLR_RED,KGI_CLR_YELLOW);
						}else{
							scrn.outputCLR(selp[scrlpos+viewpos]);
						}
						scrn.move(_x_val,_y_val+viewpos);
					}
				}
				break;
			case KGI_KEY_DOWN:
			case KGI_KEY_TAB:
				if(scrlpos+viewpos+1 < cnt){
					if(viewpos+1==_height){
						scrlpos++;
						sellist(&scrn,selp,scrlpos,_height-1);
					}
					else{
						if(_outinfo[scrlpos+viewpos]){
							scrn.outputCLR(selp[scrlpos+viewpos],KGI_CLR_DEFAULT,KGI_CLR_YELLOW);
						}else{
							scrn.output(selp[scrlpos+viewpos]);
						}
						viewpos++;
						scrn.move(_x_val,_y_val+viewpos);
						if(_outinfo[scrlpos+viewpos]){
							scrn.outputCLR(selp[scrlpos+viewpos],KGI_CLR_RED,KGI_CLR_YELLOW);
						}else{
							scrn.outputCLR(selp[scrlpos+viewpos]);
						}
						scrn.move(_x_val,_y_val+viewpos);
					}
				}
				break;
			case KGI_KEY_ENTER:
				rtnFLG=0;
				endFLG=true;
				break;
			default:
				if(ind.c == ' '){ 
					_outinfo[scrlpos+viewpos]=!_outinfo[scrlpos+viewpos]; 
					scrn.move(_x_val,_y_val+viewpos);
					if (_outinfo[scrlpos+viewpos]){
						scrn.outputCLR(selp[scrlpos+viewpos],KGI_CLR_RED,KGI_CLR_YELLOW);
					}
					else{
						scrn.outputCLR(selp[scrlpos+viewpos]);
					}
					scrn.move(_x_val,_y_val+viewpos);

				}
				break;
		}
		if(endFLG) break;
	}

	_oFile.writeFldName(_f_str);
	for(size_t i=0;i<_outinfo.size();i++){
		if(_outinfo[i]){ _oFile.writeStr(selp[i],true); }
	}
	
	_oFile.close();

	return rtnFLG;
}
catch(kgError& err){
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
