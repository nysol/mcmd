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
// kgpadding.cpp 行補完クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <kgpadding.h>
#include <kgError.h>
#include <kgConfig.h>
#include <boost/date_time/gregorian_calendar.hpp>

using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost::gregorian;
using namespace boost::posix_time;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgPadding::kgPadding(void)
{
	_name    = "kgpadding";
	_version = "###VERSION###";
	_skip		 = false;

	#include <help/en/kgpaddingHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgpaddingHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgPadding::setArgs(void) 
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,v=,-n,S=,E=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o);
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",":%",2,true,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// v=のセット
	_pStr=_args.toString("v=",false);


	// typeのセット:int or date or tine
	_today=day_clock::local_day();
	if(vvs[1][0].find('r')!=string::npos)	{ _dict = -1;}
	else																	{ _dict =  1;}
	     if(vvs[1][0].find('n')!=string::npos)	{ _typeC='i';}
	else if(vvs[1][0].find('d')!=string::npos)	{ _typeC='d';}
	else if(vvs[1][0].find('t')!=string::npos)	{ _typeC='t';}
	else if(vvs[1][0].find('m')!=string::npos)	{ _typeC='m';}
	else																				{ _typeC='i';}
	
	//開始終了値
	_sStr = _args.toString("S=",false);
	_eStr = _args.toString("E=",false);
	
	// -nオプションのセット
	_nil=_args.toBool("-n");
	
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg){
		vector<kgstr_t> vsk = vs;
		kgstr_t vstmp = vvs[0][0];
		if(_typeC=='i'||_dict==-1){
			vstmp.push_back('%');
			if(_typeC=='i') { vstmp.push_back('n'); }
			if(_dict==-1)		{ vstmp.push_back('r'); }
		}
		vsk.push_back(vstmp);
		sortingRun(&_iFile,vsk);
	}


	_kField.set(vs,  &_iFile,_fldByNum);
	_fField.set(vvs, &_iFile,_fldByNum);
	if( _fField.attr(0).find('r')!=string::npos )	{ _dict = -1;}
	else																					{ _dict =  1;}


}
// -----------------------------------------------------------------------------
// char -> date
// -----------------------------------------------------------------------------
bool kgPadding::parseDate(const char* str,date& value)
{
	int y,m,d;
	if(false==date_set(str, &y,&m,&d)){ return false;}
	try {
		value=date(y,m,d);
	}catch(...){
		return false;
	}
	return true;
}
// -----------------------------------------------------------------------------
// char -> ptime
// -----------------------------------------------------------------------------
bool kgPadding::parseTime(const char* str,ptime& value)
{
	int h,m,s;
 	if(false==time_set(str, &h,&m,&s)){ return false; }
	try {
		value=ptime(_today,time_duration(h,m,s));
	}catch(...){
		return false;
	}
	return true;
}


//===================================================
// outtype : 1 = 既存行(old利用)
// outtype : 0 = padding(old利用):old次~new前,E
// outtype :-1 = padding(New利用):S~先頭前
//===================================================
void kgPadding::writePading(const char *str,int outtype)
{
	if(*str=='\0'&& _assertNullOUT){ _existNullOUT = true;}

	for(size_t j=0; j<_iFile.fldSize(); j++){
			bool eol=false;
			if(j==_iFile.fldSize()-1) eol=true;
			char *tmps ;
			if(outtype==-1){ tmps= _iFile.getNewVal(j);}
			else					 { tmps= _iFile.getOldVal(j);}
			// f=で指定した項目の出力(padding項目)
			if(j==static_cast<size_t>(_fField.num(0))){
				_oFile.writeStr(str,eol);
			}
			// k=で指定した項目の出力
			else if(_kField.getFlg_p()->at(j)!=-1){
				if(*tmps=='\0'&& _assertNullOUT){ _existNullOUT = true;}
				_oFile.writeStr(tmps,eol);
			}
			else{
				// その他の項目
				if(outtype==1){ 
					if(*tmps=='\0'&& _assertNullOUT){ _existNullOUT = true;}
					_oFile.writeStr(tmps, eol); 
				}
				else if(_nil) {
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeStr("", eol);
				}
				else{
					if(_pStr.empty()){
						if(*tmps=='\0'&& _assertNullOUT){ _existNullOUT = true;}
						_oFile.writeStr(tmps, eol);
					}
					else{
						_oFile.writeStr(_pStr.c_str(), eol);
					}
				}
			}
		}
}
void kgPadding::writePading(int val,int outtype)
{
	char buf[128];
	sprintf(buf,"%d",val);
	writePading(buf,outtype);
}
void kgPadding::writePading(date& val,int outtype)
{
	writePading(to_iso_string(val).c_str(),outtype);
}
void kgPadding::writePading(ptime& val,int outtype)
{
	time_duration td=val.time_of_day();
	char buf[16];
	sprintf(buf,"%02d%02d%02d",td.hours(),td.minutes(),td.seconds());
	writePading(buf,outtype);
}

void kgPadding::writePading(kgMonthForPadding& val,int outtype)
{
	char buf[128];
	sprintf(buf,"%d%02d",val.year(),val.month());
	writePading(buf,outtype);
}



// -----------------------------------------------------------------------------
// output (int)
// outtype: 1:最終行~E
// outtype: 0:old~new
// outtype:-1:s=~先頭行
// -----------------------------------------------------------------------------	
void kgPadding::writePading_int(const char *from,const char *to ,int direct,int outtype)
{
	if(outtype<0){
		if(*from=='\0'){return;}
		int st = atoi(from);
		if(*to=='\0'){
			writePading(st,-1);
			return;
		}
		int ed = atoi(to);
		while(1){
			if( (direct>0 && st >= ed ) || (direct<0 && st <= ed )) { break; }
			writePading(st,-1);
			st+=direct;
		}
	}else{
		bool val_check=false;
		if(*from=='\0'){ writePading("",1); }
		else{
			int st = atoi(from);
			writePading(st,1);
			if(*to!='\0'){
				int ed = atoi(to);
				if( (direct>0 && st >= ed ) || (direct<0 && st <= ed )) { val_check=true; }
				while(1){
					st+=direct;
					if( (direct>0 && st >= ed ) || (direct<0 && st <= ed )) { break; }
					writePading(st,0);
				}
			}
		}
		if(outtype==1&&*to!='\0'&&!val_check){ 
			int ed = atoi(to);
			writePading(ed,0);
		}
	}
	return ;
}
// -----------------------------------------------------------------------------
// output (date)
// -----------------------------------------------------------------------------	
void kgPadding::writePading_date(const char *from,const char *to ,int directv,int outtype)
{
	date st,ed;	
	if(outtype<0){
		if(!parseDate(from,st)){return;}
		if(!parseDate(to,ed)){
			writePading(st,-1);
			return;
		}
		date_duration direct= date_duration(directv);
		while(1){
			if( (directv>0 && st >= ed ) || (directv<0 && st <= ed )) { break; }
			writePading(st,-1);
			st+=direct;
		}
	}else{
		bool val_check=false;
		bool fr_ok=parseDate(from,st);
		bool to_ok=parseDate(to,ed);
		if(!fr_ok){ writePading(from,1); }
		else{
			writePading(st,1);
			if(to_ok){
				date_duration direct= date_duration(directv);
				if( (directv>0 && st >= ed ) || (directv<0 && st <= ed )) { val_check=true; }
				while(1){
					st+=direct;
					if( (directv>0 && st >= ed ) || (directv<0 && st <= ed )) { break; }
					writePading(st,0);
				}
			}
		}
		if(outtype==1&&to_ok&&!val_check){
			writePading(ed,0);
		}
	}
	return ;
}
// -----------------------------------------------------------------------------
// output (time)
// -----------------------------------------------------------------------------	
void kgPadding::writePading_time(const char *from,const char *to ,int directv,int outtype)
{
	ptime st,ed;	
	if(outtype<0){
		if(!parseTime(from,st)){return;}
		if(!parseTime(to,ed)){
			writePading(st,-1);
			return;
		}
		time_duration direct= time_duration(0,0,directv);
		while(1){
			if( (directv>0 && st >= ed ) || (directv<0 && st <= ed )) { break; }
			writePading(st,-1);
			st+=direct;
		}
	}else{
		bool val_check=false;
		bool fr_ok=parseTime(from,st);
		bool to_ok=parseTime(to,ed);
		if(!fr_ok){ writePading(from,1); }
		else{
			writePading(st,1);
			if(to_ok){
				if( (directv>0 && st >= ed ) || (directv<0 && st <= ed )) { val_check=true; }
				time_duration direct= time_duration(0,0,directv);
				while(1){
					st+=direct;
					if( (directv>0 && st >= ed ) || (directv<0 && st <= ed )) { break; }
					writePading(st,0);
				}
			}
		}
		if(outtype==1&&to_ok&&!val_check){
			writePading(ed,0);
		}
	}
	return ;
}
// -----------------------------------------------------------------------------
// output (month)
// -----------------------------------------------------------------------------	
void kgPadding::writePading_month(const char *from,const char *to ,int direct,int outtype)
{
	kgMonthForPadding st,ed;	

	if(outtype<0){
		if(!kgMonthForPadding::parseMonth(from,st)){return;}
		if(!kgMonthForPadding::parseMonth(to,ed)){
			writePading(st,-1);
			return;
		}
		// date_duration direct= date_duration(directv);
		while(1){
			if( (direct>0 && st >= ed ) || (direct<0 && st <= ed )) { break; }
			writePading(st,-1);
			st+=direct;
		}
	}else{
		bool val_check=false;
		bool fr_ok=kgMonthForPadding::parseMonth(from,st);
		bool to_ok=kgMonthForPadding::parseMonth(to,ed);
		if(!fr_ok){ writePading(from,1); } // format エラー時
		else{
			writePading(st,1);
			if(to_ok){
				//date_duration direct= date_duration(directv);
				if( (direct>0 && st >= ed ) || (direct<0 && st <= ed )) { val_check=true; }
				while(1){
					st+=direct;
					if( (direct>0 && st >= ed ) || (direct<0 && st <= ed )) { break; }
					writePading(st,0);
				}
			}
		}
		if(outtype==1 && to_ok && !val_check){
			writePading(ed,0);
		}
	}
	return ;
}
// -----------------------------------------------------------------------------
// output (all->int,date,time)
// outtype: 1:最終行~E
// outtype: 0:old~new
// outtype:-1:s=~先頭行
// -----------------------------------------------------------------------------	
void kgPadding::writePading(const char *from ,const char *to,int dir,int outtype)
{
	switch(_typeC){
		case 'i':
			writePading_int(from ,to,dir, outtype);
			break;
		case 'd':
			writePading_date(from ,to,dir, outtype);
			break;
		case 't':
			writePading_time(from ,to,dir, outtype);
			break;
		case 'm':
			writePading_month(from ,to,dir, outtype);
			break;
	}
}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgPadding::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
  _oFile.writeFldName(_iFile, true);

	while(_iFile.read()!=EOF){
	
		char* oldv = _iFile.getOldVal(_fField.num(0));
		char* newv = _iFile.getNewVal(_fField.num(0));

		if(_iFile.begin()){			
			writePading(_sStr.c_str(),newv,_dict,-1);
		}
		else if( _iFile.keybreak() ){
			if(*oldv=='\0'&&_assertNullIN){ _existNullIN  = true;}
			writePading(oldv,_eStr.c_str(),_dict,1);
			if( !_iFile.end() ){
				writePading(_sStr.c_str(),newv,_dict,-1);
			}
		}else{
			if(*oldv=='\0'&&_assertNullIN){ _existNullIN  = true;}
			writePading(oldv,newv,_dict,0);
		}
	}

	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理
	th_cancel();
	_iFile.close();
	_oFile.close();
	successEnd();
	return 0;

// 例外catcher
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
