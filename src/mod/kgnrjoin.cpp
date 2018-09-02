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
// kgnrjoin.cpp 参照ファイル項目の数値範囲マッチング自然結合クラス
// =============================================================================
#include <sstream>
#include <vector>
#include <map>
#include <kgnrjoin.h>
#include <kgError.h>
#include <kgRange.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;



// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgNrjoin::kgNrjoin(void)
{
	_name    = "kgnrjoin";
	_version = "###VERSION###";

	#include <help/en/kgnrjoinHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgnrjoinHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgNrjoin::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,m=,k=,K=,r=,rf=,R=,-n,-N,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	kgstr_t ifile = _args.toString("i=",false);
	kgstr_t mfile = _args.toString("m=",false);
	if(ifile.empty() && mfile.empty()){
		throw kgError("Either i= or m= must be specified.");
	}
	_iFile.open(ifile,_env,_nfn_i);
	_mFile.open(mfile,_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o);
	_iFile.read_header();
	_mFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",false);

	// K= 項目引数のセット
	// K=の指定がなければk=の値をセットする
	vector<kgstr_t> vs_K = _args.toStringVector("K=",false);
	if(vs_K.empty()) { vs_K = vs_k; }

	
	// k=とK=の数があっている化チェック
	if(_kField.size()!=_KField.size()){
		ostringstream ss;
		ss << "not match keyfield size k:" << _kField.size() << " K:" << _KField.size() ;
		throw kgError(ss.str());
	}
	// f=
	vector< vector<kgstr_t> >  vvs = _args.toStringVecVec("f=",':',2,false);

	// r= 項目引数のセット(指定するのは１項目)
	vector< vector<kgstr_t> >  vvs_rs = _args.toStringVecVec("r=","%:",2,false);
	if(!vvs_rs[0].empty()){
		kgMsg asertmsg(kgMsg::WAR, _env);
		asertmsg.output("r= is deprecated,use rf= parameter");	
	}
	else{
		vvs_rs = _args.toStringVecVec("rf=","%:",2,true);
	}
	// R= 項目引数のセット(指定するのは２項目)
	vector< vector<kgstr_t> >  vvs_r = _args.toStringVecVec("R=","%:",2,true);

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg && !vs_k.empty()){ 
		vector<kgCSVfld*> csv_p;  
		vector< vector<kgstr_t> > fld_ary;  
		csv_p.push_back(&_iFile);
		csv_p.push_back(&_mFile);
		fld_ary.push_back(vs_k);
		fld_ary.push_back(vs_K);
		sortingRun(csv_p,fld_ary);
	}
	_kField.set(vs_k, &_iFile,_fldByNum);
	_KField.set(vs_K, &_mFile,_fldByNum);

	// f= 項目引数のセット指定が無かった場合はk=の項目以外をセットする
	if(!vvs[0].empty()){ _fField.set(vvs, &_mFile,_fldByNum);	}
	else{
		for(size_t i=0 ; i< _mFile.fldSize();i++){
			int num= _KField.getFlg().at(i);
			if(num == -1) {
				vvs[0].push_back(toString(i));				
				vvs[1].push_back("");				
			}
		}
		_fField.set(vvs, &_mFile,true);
	}
	_rField.set(vvs_rs, &_iFile,_fldByNum);
	_RField.set(vvs_r, &_mFile,_fldByNum);


	//範囲タイプセット(equalを含むときは場合ture)
	if( _RField.attr(0).find("n") == kgstr_t::npos){
		_range1_type = true;
	}else{
		_range1_type = false;		
	}
	if( _RField.attr(1).find("e") == kgstr_t::npos){
		_range2_type = false;
	}else{
		_range2_type = true;		
	}
	//比較タイプセット(nがあるとtrueをセット(数字ソートになる))
	if( _rField.attr(0).find("n") == kgstr_t::npos){
		_cmp_type = false;
	}else{
		_cmp_type = true;		
	}

	// -n,-N アウタージョインフラグ
	_i_outer = _args.toBool("-n");
	_m_outer = _args.toBool("-N");

	if(_rField.size()!=1){
		ostringstream ss;
		ss << "r= has 1 item : r= size:" << vvs_rs.size() ;
		throw kgError(ss.str());
	}
	if(_RField.size()!=2){
		ostringstream ss;
		ss << "R= has 2 item : R= size:" << vvs_r.size();
		throw kgError(ss.str());
	}

}

// -----------------------------------------------------------------------------
// マスタアウタージョイン時の出力する
// -----------------------------------------------------------------------------
void kgNrjoin::writeFld( const vector<int>* flg, char** keyfld,char** fld,int addsize)
{
	int num;
	for(unsigned int i=0; i<flg->size(); i++){ // csvの項目数で回す
		num=flg->at(i);                  // 対応するval位置
		if(num == -1){
			_oFile.writeStr( "", false );
		}
		else{
			_oFile.writeStr( *(keyfld+ i), false );
		}
	}
	int j;
	for(j=0; j<addsize-1; j++){ // addcntの項目数で回す
		_oFile.writeStr( *(fld+j)   , false  );
	}
	_oFile.writeStr( *(fld+j)   , true  );
}
// -----------------------------------------------------------------------------
// キーが一致した場合にrangeと比較して マッチすれば出力する
// -----------------------------------------------------------------------------
void kgNrjoin::range_match(void)
{

	vector<int> KField =_KField.getNum();

	// 付加項目格納先
	kgAutoPtr2<char*> ap_str;
	try {
		ap_str.set( new char*[_fField.size()] ); // 行数×csv項目数
	} catch(...) {
		throw kgError("memory allocation error ");
	}
	char** tmpstr = ap_str.get();
	// 参照ファイルからrange一覧を作成
	// range一覧にはfield,keyのデータをセットしておく
	kgRange range;
	range.set(_cmp_type,_range1_type,_range2_type);
	while(1){
		for(kgstr_t::size_type i=0;i<_fField.size();i++){
			*(tmpstr+i) = _mFile.getNewVal(_fField.num(i));
		}
		range.set_table(_mFile.getNewVal(_RField.num(0)),_mFile.getNewVal(_RField.num(1)),tmpstr,_fField.size());	
		_mFile.read();
		if( _mFile.keybreak() ){break;}
	}

	// rangeからマッチするものを探して出力
	while(1){
		if( *(_iFile.getNewVal(_rField.num(0))) == '\0'){//NULLの場合、アンマッチ
			if(_i_outer==true){
				if(_assertNullOUT){ _existNullOUT = true;}
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),(char**)NULL,_fField.size());
			}
		}
		else{
			bool match = range.serch(_iFile.getNewVal(_rField.num(0)));
			if(match){
				if(_cmp_type){
					multimap<double,kgRangetbl*,list_edsort_n> list_out = range.get_tbl_dbl();
					for(multimap<double,kgRangetbl*,list_edsort_n>::iterator i=list_out.begin();i!=list_out.end();i++){
						if(_assertNullIN && (i->second)->isNull() ){ _existNullIN = true;}
						_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),(i->second)->rec,_fField.size());
					}
				}else{
					multimap<char*,kgRangetbl*,list_edsort> list_out = range.get_tbl_str();
					for(multimap<char*,kgRangetbl*,list_edsort>::iterator i=list_out.begin();i!=list_out.end();i++){
						if(_assertNullIN && (i->second)->isNull() ){ _existNullIN = true;}
						_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),(i->second)->rec,_fField.size());
					}	
				}
			}else{
				if(_i_outer){
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),(char**)NULL,_fField.size());
				}
			}
		}
		_iFile.read();
		if( _iFile.keybreak() ){break;}
	}	

	if(_m_outer==true){
		if(_cmp_type){//数字タイプ
			multimap<double,kgRangetbl*,list_stsort_n> list_out = range.get_list_dbl();
			for(multimap<double,kgRangetbl*,list_stsort_n>::iterator i=list_out.begin();i!=list_out.end();i++){
				if((i->second)->writeflg==false){
					if(_assertNullOUT){ _existNullOUT = true;}
					writeFld(_kField.getFlg_p(),_iFile.getOldFld(),(i->second)->rec,_fField.size());
				}
			}
		}
		else{//文字タイプ
			multimap<char*,kgRangetbl*,list_stsort> list_out = range.get_list_str();
			for(multimap<char*,kgRangetbl*,list_stsort>::iterator i=list_out.begin();i!=list_out.end();i++){
				if((i->second)->writeflg==false){
					if(_assertNullOUT){ _existNullOUT = true;}
					writeFld(_kField.getFlg_p(),_iFile.getOldFld(),(i->second)->rec,_fField.size());
				}
			}
		}
	}
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgNrjoin::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力、参照ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());
	_mFile.setKey(_KField.getNum());

	// 項目名出力
	_oFile.writeFldName(_iFile,_fField,true);

	// keyサイズとデータセット
	int ksize = _kField.size();
	vector<int> kField =_kField.getNum();
	vector<int> KField =_KField.getNum();
	vector<int> fField =_fField.getNum();

	//比較結果用フラグ
	int cmpflg=0;

	//一行目読み込み
	_iFile.read();
	_mFile.read();

	// k=,K=でマッチするところを検索し、その後v=,r=で比較マッチをする
	// k,Kはソートされていることが前提
	while( 1 ){
		if((_iFile.status() & kgCSV::End )||
			(_mFile.status() & kgCSV::End )){ break;}

		for(int i=0;i<ksize;i++){
			cmpflg = strcmp( _iFile.getNewVal(kField[i]), _mFile.getNewVal(KField[i]) );
			if(cmpflg!=0){break;}
			//両方共NULLならアンマッチとする
			if( *(_iFile.getNewVal(kField[i]))=='\0' && 
				*(_mFile.getNewVal(KField[i]))=='\0')
			{
				cmpflg=1;
				break;
			}
		}
		// 一致したのでrangeでチェック
		if(cmpflg==0){ range_match(); }

		// 参照ファイルの方が小さい(参照の次の行を読み込む)
		// _m_outer(-N)が指定されている場合、
		// 現参照行が一度も出力されていなければno_matchとして書き出す
		else if(cmpflg>0){
			while(1){
				if(_m_outer==true){
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeFld(_kField.getFlg_p(),&KField,_mFile.getNewFld(),&fField);
				}
				_mFile.read();
				if( _mFile.keybreak() ){break;}
			}
		}
		// 参照ファイルの方が大きくなった(_i_outer(-n)が指定されていればno_matchとして書き出す)
		else{
			if(_i_outer==true){
				if(_assertNullOUT){ _existNullOUT = true;}
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
			}
			//次の行読み込み
			_iFile.read();
		}
	}
	//入力ファイルのデータが残っていた場合のデータ出力
	if(!(_iFile.status() & kgCSV::End ) ){
		if(_i_outer){
			if(_assertNullOUT){ _existNullOUT = true;}
			while(1){
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
				_iFile.read();
 				if(_iFile.status() & kgCSV::End){ break;} 
			}
		}
	}
	//参照ファイルのデータが残っていた場合のデータ出力
	else if(!(_mFile.status() & kgCSV::End ) && _m_outer==true){
		if(_assertNullOUT){ _existNullOUT = true;}
		while(1){
			_oFile.writeFld(_kField.getFlg_p(),&KField,_mFile.getNewFld(),&fField);
			_mFile.read();
 			if(_mFile.status() & kgCSV::End){ break;} 
		}
	}
	//ソートスレッドを終了させて、終了確認
	//for(size_t i=0 ;i<_th_st.size();i++){ pthread_cancel(_th_st[i]->native_handle());	}
	//for(size_t i=0 ;i<_th_st.size();i++){ pthread_join(_th_st[i]->native_handle(),NULL);}

	if(_assertNullKEY) { _existNullKEY = _iFile.keynull()||_mFile.keynull(); }

	// 終了処理(メッセージ出力,thread pipe終了通知)
	th_cancel();
	_iFile.close();
	_mFile.close();
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
