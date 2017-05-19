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
// kgCsvconv.cpp 行集計(合計)クラス
// =============================================================================
#include <cstdio>
#include <vector>
#include <kgConfig.h>
#include <kgcsvconv.h>
#include <kgError.h>
#include <kgVal.h>


using namespace std;
using namespace kglib;
using namespace kgmod;

char* kgtexFormatInfoTTL::skip(char * p,const char* clist){

	while(*p){
		const char *q = clist;
		while(*q){
			if(*p==*q){ break;}
			q++;
		}
		if(*q)break;
		p++;
	}
	return p;	
}
void kgtexFormatInfoTTL::completion(){


}

void kgtexFormatInfoTTL::set(char *dt,FILE * wfp,kgArgFld& kfld){

	int tp=-1;
	int keynum=0;
	_wfp = wfp;
	bool bsFLG=false;
	_kmax= kfld.size();

	_formatData =dt;
	char *p = _formatData;

	// 先頭セット
	stset(0,tp,0);

	while(*p){
		if (bsFLG){ 
			bsFLG = false;
			p++; 
			continue; 
		}
		if(*p=='\\'){
			bsFLG=true;
			p++; 
			continue;
		}
		if(*p=='%'){
			int pos=0;
			p++;
			while(*_tag[pos]){
				if( !strncmp(p,_tag[pos],strlen(_tag[pos])) ){
					break;
				}
				pos++;
			}
			//not keyword
			if(!*_tag[pos]){
				char *q = skip(p,"%\n");
				if (*q == '%'){
					if(p!=q){
						fldset(p-1-_formatData,q+1-_formatData,kfld.csv()->fldNum(kgstr_t(p,q)));
						p = q;
					}
				}
			}
			else{ //exist keyword
				endset(p-1-_formatData);
				keynum=0;
				p += strlen(_tag[pos]);
				if(*p&&(*p>'0'&& *p<='9')){
					while(*p&&(*p>='0'&&*p<'9')){ 
						keynum = keynum *10 + (*p-'0');
						p++;
					}
				}
				if(keynum>_kmax){ throw kgError("format error on csvconv"); }
				if(keynum==0) keynum=_kmax;
				p = skip(p,"\n");
				stset(p+1-_formatData,pos,keynum);
			}
		}
		p++;
		endset(p-_formatData);

	}
	//end処理
	completion();

}


// tex特殊文字 # $ % & _ { } < > \ ^ | ~
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgCsvconv::kgCsvconv(void)
{
	_name    = "kgcsvconv";
	_version = "###VERSION###";

	#include <help/en/kgcsvconvHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgcsvconvHelp.h>
	#endif
	_wfp=NULL;
}







// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgCsvconv::setArgs(void)
{

	// パラメータチェック
	_args.paramcheck("i=,o=,k=,m=,s=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
	kgstr_t ostr = _args.toString("o=",false);
	if(ostr.empty()){
		_wfp =stdout;
	}
	else{
		_wfp =fopen(ostr.c_str(),"wb");
		if(!_wfp){
			throw kgError("can't open write file on csvconv");
		}
	}

	kgstr_t formatNM = _args.toString("m=",true);

	struct stat st;
	if( stat(formatNM.c_str(),&st) ){
		throw kgError("can't get file size format file on csvconv");
	}
	try {
		_ap.set( new char[st.st_size +1] );
	} catch(...) {
		throw kgError("memory allocation error on csvconv");
	}
	_formatData = _ap.get();
	
	// format読み込み
	FILE *fp;
	if( !(fp = fopen(formatNM.c_str(),"rb")) ){ 
		throw kgError("can't open format file on csvconv");
	}
	/* ファイルを全件一度に読込み */
	if( fread(_formatData,st.st_size,1,fp) != 1 ){
		throw kgError("can't read format file on csvconv");
	}
	fclose(fp);
	_formatData[st.st_size] = '\0';
	
	
	// k= 項目引数のセット
	vector< vector<kgstr_t> > vvk = _args.toStringVecVec("k=","%:",2,false);
	vector<kgstr_t>  vvs = _args.toStringVector("s=",false);

	_iFile.read_header();	

	// 必要ならソートが実行されiFileは初期化され,
	// ソーティンぐ結果のが出力されるファイルで再度読み込み直される	
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if(!seqflg && (!vvk[0].empty()||!vvs.empty())){ 
		vector<kgstr_t> vsk	= vvk[0];
		vsk.insert(vsk.end(),vvs.begin(),vvs.end());
		sortingRun(&_iFile,vsk);
	}
	_kField.set(vvk, &_iFile,_fldByNum);
	texInfo.set(_formatData,_wfp,_kField);

}


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgCsvconv::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();
	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	while(_iFile.read()!=EOF){
		if( _iFile.begin() ){
			texInfo.beginOutput(_iFile.getNewFld());
		}
		else if( _iFile.keybreak() ){
		
			//check break filed
			int pos = 0;
			while(pos<_kField.size()){
				if( strcmp(_iFile.getNewVal(_kField.num(pos)),_iFile.getOldVal(_kField.num(pos)))){ break; }
				pos++;
			}
			texInfo.breakPreOutput(_iFile.getOldFld(),pos);
			//ENDなら終了
			if((_iFile.status() & kgCSV::End )) {
				texInfo.endOutput(_iFile.getOldFld());
				break;
			}
			texInfo.breakOutput(_iFile.getNewFld(),pos);
		}
		else{
			// 通常処理
			texInfo.lineOutput(_iFile.getNewFld());
		}

	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }

	// 終了処理
	th_cancel();
	_iFile.close();
	if(_wfp) fclose(_wfp);
//	_oFile.close();
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
