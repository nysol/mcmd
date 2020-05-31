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
// kgrjoin.cpp 参照ファイル項目の数値範囲マッチング結合クラス
// =============================================================================
#include <sstream>
#include <vector>
#include <kgrjoin.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgConfig.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgRjoin::kgRjoin(void)
{
	_name    = "kgrjoin";
	_version = "###VERSION###";

	#include <help/en/kgrjoinHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgrjoinHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgRjoin::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,m=,k=,K=,r=,rf=,R=,-n,-lo,-q",kgArgs::ALLPARAM);

	//ファイル指定チェック
	kgstr_t ifile = _args.toString("i=",false);
	kgstr_t mfile = _args.toString("m=",false);
	if(ifile.empty() && mfile.empty()){
		throw kgError("Either i= or m= must be specified.");
	}
	_iFile.open(ifile,_env,_nfn_i);
	_mFile.open(mfile,_env,_nfn_i);
	_oFile.open(_args.toString("o=",false),_env,_nfn_o,_rp);
	_iFile.read_header();
	_mFile.read_header();

	// k= 項目引数のセット
	vector<kgstr_t> vs_k = _args.toStringVector("k=",false);

	// K= 項目引数のセット
	// K=の指定がなければk=の値をセットする
	vector<kgstr_t> vs_K = _args.toStringVector("K=",false);
	if(vs_K.empty()){ vs_K = vs_k;}
	
	// k=とK=の数があっている化チェック
	if(vs_k.size()!=vs_K.size()){
		ostringstream ss;
		ss << "not match keyfield size k:" << vs_k.size() << " K:" << vs_K.size() ;
		throw kgError(ss.str());
	}

	// f= 項目引数のセット指定が無かった場合はk=の項目以外をセットする
	vector< vector<kgstr_t> >  vvs = _args.toStringVecVec("f=",':',2,false);

	// r= 項目引数のセット(指定するのは１項目)
	vector< vector<kgstr_t> >  vvs_r  = _args.toStringVecVec("r=","%:",2,false);
	
	if(!vvs_r[0].empty()){
		kgMsg asertmsg(kgMsg::WAR, _env);
		asertmsg.output("r= is deprecated,use rf= parameter");	
	}
	else{
		vvs_r = _args.toStringVecVec("rf=","%:",2,true);
	}
	if( vvs_r[0].size()!=1){
		ostringstream ss;
		ss << "rf=(r=) must take just one item : rf=(r=) size:" << vvs_r[0].size();
		throw kgError(ss.str());
	}


	//比較タイプセット(nがあるとtrueをセット(数字ソートになる))
	if( vvs_r[1][0].find("n") == kgstr_t::npos){
		_cmp_type = false;
	}else{
		_cmp_type = true;		
	}

	// R= 項目引数のセット(指定するのは1項目)指定がなければr=の値をセット
	vector<kgstr_t>  vs_R = _args.toStringVector("R=",false);
	if(vs_R.empty()){ vs_R = vvs_r[0];}

	if(vs_R.size()!=1){
		ostringstream ss;
		ss << "R= must take just one item : R= size:" << _RField.size() ;
		throw kgError(ss.str());
	}
	// -n アウタージョインフラグ
	_i_outer = _args.toBool("-n");
	//範囲タイプセット
	_range_type = _args.toBool("-lo");

	vector<kgCSVfld*> csv_p;  
	vector< vector<kgstr_t> > fld_ary;  
	csv_p.push_back(&_iFile);
	csv_p.push_back(&_mFile);
	vector<kgstr_t> vsrtmp = vs_k; 
	vector<kgstr_t> vsRtmp = vs_K;
	if(_cmp_type){
		vsrtmp.push_back(vvs_r[0][0]+"%n");
		vsRtmp.push_back(vs_R[0]+"%n");
	}
	else{
		vsrtmp.push_back(vvs_r[0][0]);
		vsRtmp.push_back(vs_R[0]);
	}
	fld_ary.push_back(vsrtmp);
	fld_ary.push_back(vsRtmp);

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg){ sortingRun(csv_p,fld_ary);}
	
	_kField.set(vs_k, &_iFile,_fldByNum);
	_KField.set(vs_K, &_mFile,_fldByNum);	
	
	if(!vvs[0].empty()){ _fField.set(vvs, &_mFile,_fldByNum); }
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
	_rField.set(vvs_r, &_iFile,_fldByNum);
	_RField.set( vs_R, &_mFile,_fldByNum);

}
// -----------------------------------------------------------------------------
// キーが一致した場合にrangeと比較してマッチすれば出力する
// -----------------------------------------------------------------------------
void kgRjoin::range_match(void)
{
	int comp_flg;	
	vector<int> fField =_fField.getNum();
	vector<int> KField =_KField.getNum();

	//最初の位置1行目のチェック
	_mFile.read();

	// 範囲項目でマッチするものを探して出力
	// 参照fileのnewに上限の値、oldに下限の値が入る状態になっている
	// マッチすればoldの値を入力ファイルにつけて出力
	while(1){
		if( _mFile.keybreak() ){
			//アウタージョインが指定されて入れば現在行を出力しておく
			if(_i_outer==true){
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
			}
			_iFile.read();
			break;
		}
		//範囲項目の比較
		if(*(_iFile.getNewVal(_rField.num(0)))=='\0'){//NULLの時はアンマッチ
			comp_flg=-1;
		}
		else if(_cmp_type){//数字比較
			double val= atof( _iFile.getNewVal(_rField.num(0)));
			double ed = atof( _mFile.getNewVal(_RField.num(0)));
			double st = atof( _mFile.getOldVal(_RField.num(0)));
			if(_range_type){//true:より大きい〜以下 false:以上〜未満
				if(val>ed)			 {comp_flg=1;}
				else if(val<=st) {comp_flg=-1;}
				else						 {comp_flg=0;}
			}
			else{
				if(val>=ed)			{comp_flg=1;}
				else if(val<st)	{comp_flg=-1;}
				else						{comp_flg=0;}
			}
		}
		else{//文字比較
			if(_range_type){//true:より大きい〜以下 false:以上〜未満
				if(strcmp(_iFile.getNewVal(_rField.num(0)),_mFile.getNewVal(_RField.num(0))) >0){
					comp_flg=1;
				}else if(strcmp(_iFile.getNewVal(_rField.num(0)),_mFile.getOldVal(_RField.num(0))) <=0){
					comp_flg=-1;
				}else{
					comp_flg=0;
				}
			}
			else{
				if(strcmp(_iFile.getNewVal(_rField.num(0)),_mFile.getNewVal(_RField.num(0))) >=0){
					comp_flg=1;
				}else if(strcmp(_iFile.getNewVal(_rField.num(0)),_mFile.getOldVal(_RField.num(0))) <0){
					comp_flg=-1;
				}else{
					comp_flg=0;
				}
			}
		}
		/*一致したので出力*/
		if(comp_flg==0){
			if(_assertNullIN && _mFile.isNull(fField)){  _existNullIN  = true;}
			_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),_mFile.getOldFld(),&fField);
		}
		else if(comp_flg==1){//入力データの方が大きいので参照ファイルの次の行を読み込む						
			_mFile.read();
			continue;
		}
		else{//参照データの方が大きい場合
			if(_i_outer==true){
				if(_assertNullOUT){ _existNullOUT = true;}
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
			}
		}
		_iFile.read();
		if( _iFile.keybreak() ){break;}
	}
	//参照ファイルのデータが残っていた場合のデータ出力
	if( !_mFile.keybreak() ){
		while(1){
			_mFile.read();
			if( _mFile.keybreak() ){break;}
		}
	}
	//入力ファイルのデータが残っていた場合のデータ出力
	if(! _iFile.keybreak() ){
		while(1){
			if(_i_outer==true){
				if(_assertNullOUT){ _existNullOUT = true;}
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
			}
			_iFile.read();
			if( _iFile.keybreak() ){break;}
		}
	}
}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgRjoin::run(void) try 
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

	// k=,K=でマッチするところを検索し、
	// その後r=,R=で比較マッチをする
	// k,K,r,Rはソートされていることが前提
	while( 1 ){
		if((_iFile.status() & kgCSV::End )||
				(_mFile.status() & kgCSV::End ))
		{ 
			break;
		}

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
		// キー一致したのでrangeでチェック
		if(cmpflg==0){ range_match(); }

		// 参照ファイルの方が小さい(参照の次の行を読み込む)
		else if(cmpflg>0){
			while(1){
				_mFile.read();
				if( _mFile.keybreak() ){break;}
			}
		}

		/*参照ファイルの方が大きくなった(_i_outer(-n)が指定されていればno_matchとして書き出す)*/
		else{
			while(1){
				if(_i_outer==true){
					if(_assertNullOUT){ _existNullOUT = true;}
					_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);	
				}
				//次の行読み込み
				_iFile.read();
				if( _iFile.keybreak() ){break;}
			}
		}
	}

	//入力ファイルのデータが残っていた場合のデータ出力
	if(!(_iFile.status() & kgCSV::End )){
		if(_i_outer){
			if(_assertNullOUT){ _existNullOUT = true;}
			while(1){
				_oFile.writeFld(_iFile.getNewFld(),_iFile.fldSize(),static_cast<char**>(NULL),&fField);
				_iFile.read();
 				if(_iFile.status() & kgCSV::End){ break;} 
			}
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
