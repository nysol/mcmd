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
#include <kginput.h>
using namespace std;
using namespace kglib;
using namespace kgmod;


// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------
kgInput::kgInput(void)
{
	_name    = "kginput";
	_version = "###VERSION###";

	#include <help/en/kginputHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kginputHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgInput::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("x=,y=,len=,o=,f=");

	_x_val =  atoi(_args.toString("x=",true).c_str());
	_y_val =  atoi(_args.toString("y=",true).c_str());
	_len   =  atoi(_args.toString("len=",true).c_str());
	// f= 項目引数のセット
	_f_str = _args.toString("f=",false);
  _oFile.open(_args.toString("o=",true), _env,_f_str.size()==0);


}




// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgInput::run(void) try
{
	// パラメータセット&出力ファイルオープン
	setArgs();

	char stchar[] ="[";
	char edchar[] ="]";
	kgTermiosEX scrn;
	
	scrn.move(_x_val,_y_val);
	scrn.output(stchar);
	scrn.move(_x_val+_len+1,_y_val);
	scrn.output(edchar);
	scrn.move(_x_val+1,_y_val);


	int rtnF=0; //終了時返り値
	kgTextArea data(_len);

	int mv = 0;
	kgExWchar ind ;//input DATA
	bool endFLG = false;
	while(1){
		ind = scrn.read();
		switch(ind.type){
			case KGI_KEY_ESC:
				rtnF=1;
				endFLG = true; 
				break;
			case KGI_KEY_LEFT:
				mv = data.shiftL();
				scrn.shift(mv*-1);
				break;
			case KGI_KEY_RIGHT:
				mv = data.shiftR();
				scrn.shift(mv);
				break;
			case KGI_KEY_ENTER:
			case KGI_KEY_TAB:
				rtnF=0; 
				endFLG = true;
				break;
			case KGI_KEY_BS:
				mv = data.del();
				scrn.backsp(mv);
				break;
			case KGI_NORMAL:
				mv = data.add(ind.c);
				scrn.putchar(ind.c,mv);
				break;
			default:
				break;
		}
		if(endFLG) break;
	}

	_oFile.writeFldName(_f_str);
	_oFile.writeStr(toMbs(data.output()).c_str(),true);
	_oFile.close();

	return rtnF;
	
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

