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
#include <kgminput.h>
using namespace std;
using namespace kglib;
using namespace kgmod;


struct posInfo{
	int x;
	int y;
	int len;
};

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgMinput::kgMinput(void)
{
	_name    = "kgminput";
	_version = "###VERSION###";

	#include <help/en/kgminputHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgminputHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgMinput::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("i=,f=,o=");

	_i_s   =  _args.toString("i=",true);
	_f_str = _args.toStringVector("f=",false);
  _oFile.open(_args.toString("o=",true), _env,_f_str.size()==0);

}


// fflush利用する
int kgMinput::run(void) try
{

	// パラメータセット&出力ファイルオープン
	setArgs();

	char buf[MAX_LINESIZE];
	posInfo posinfo[MAX_ITMCNT];//[x,y,len]

	int item=0;
	
	// フォーマット読み込み
	int x=1,y=1,mv=0; 

	FILE *ffp = fopen(_i_s.c_str(),"r");
	if(ffp==NULL){
		throw kgError("file not found");
	}
	wint_t indt;
	while ( (indt = fgetwc(ffp))!=WEOF){
		if(isascii(indt)){ mv = 1; }
		else						{ mv = 2; }
		if(indt=='['){
			posinfo[item].x=x+1;
			posinfo[item].y=y;
		}else if(indt==']'){
			posinfo[item].len=x-posinfo[item].x;
			item++;
			if(item>=MAX_ITMCNT){
				throw kgError("the number of item over");
			}
		}
		else if(indt=='\n'){
			y++; x = 0;
		}
		x+=mv;
	}
	fclose(ffp);
	ffp = fopen(_i_s.c_str(),"r");
	//clearerr(ffp);
	//fseek(ffp,0,SEEK_SET);

	if(_f_str.size()!=0&&_f_str.size()!=item){
		throw kgError("unmatch size of f=");
	}

	//データ保存領域確保
	vector<kgTextArea *> dbarea;
	vector< kgAutoPtr1<kgTextArea> > ap1;
	ap1.resize(item);
	for(size_t i=0;i<item;i++){
		try {
			ap1.at(i).set( new kgTextArea(posinfo[i].len) );
		} catch(...) {
			throw kgError("memory allocation error ");
		}
		dbarea.push_back( ap1.at(i).get() );
	}	

	// 再読み込み&表示
	kgTermiosEX scrn;
	int len=0;
	while ( fgets(buf,MAX_LINESIZE,ffp)!=NULL){
		len++;
		scrn.move(0,len);
		scrn.output(buf);
	}
	fclose(ffp);

	// 入力
	int ipos = 0;
	bool bF=false;
	int rtnFLG=0;

	
	scrn.move(posinfo[ipos].x,posinfo[ipos].y);

	kgExWchar ind ;//input DATA
	int xpos;
	while(1){
		ind = scrn.read();
		switch(ind.type){
			case KGI_KEY_UP:
				ipos--;
				if(ipos<0){ ipos= item-1;}
				xpos = dbarea[ipos]->cpos();
				scrn.move(posinfo[ipos].x+xpos,posinfo[ipos].y);
				break;
			case KGI_KEY_ESC:
				rtnFLG=1;
				bF=true;
				break;
			case KGI_KEY_DOWN:
			case KGI_KEY_TAB:
				ipos++;
				if(ipos>=item){ ipos=0;}
				xpos = dbarea[ipos]->cpos();
				scrn.move(posinfo[ipos].x+xpos,posinfo[ipos].y);
				break;
			case KGI_KEY_ENTER:
				ipos++;
				if(ipos>=item){ rtnFLG =0; bF=true;}
				else{ 
					xpos = dbarea[ipos]->cpos();
					scrn.move(posinfo[ipos].x+xpos,posinfo[ipos].y);
				}
				break;
			case KGI_KEY_LEFT:
				mv = dbarea[ipos]->shiftL();
				scrn.shift(mv*-1);
				break;
			case KGI_KEY_RIGHT:
				mv = dbarea[ipos]->shiftR();
				scrn.shift(mv);
				break;
			case KGI_KEY_BS:
				mv = dbarea[ipos]->del();
				scrn.backsp(mv);
				break;
			case KGI_NORMAL:
				mv = dbarea[ipos]->add(ind.c);
				scrn.putchar(ind.c,mv);
				break;
			default:
				break;
		}
		if(bF) break;
	}

	_oFile.writeFldName(_f_str);
	for(int i=0;i<item;i++){
		if(i==item-1){
			_oFile.writeStr(toMbs(dbarea[i]->output()).c_str(),true);
		}else{
			_oFile.writeStr(toMbs(dbarea[i]->output()).c_str(),false);
		}
	}

	_oFile.close();
 return rtnFLG;

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
