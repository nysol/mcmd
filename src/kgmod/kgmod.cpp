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
// kgmod.cpp kgmodスーパークラス
// ============================================================================
#include <cstring>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <csignal>
#include <kgArgs.h>
#include <kgmod.h>
#include <kgMethod.h>
#include <kgMessage.h>
#include <kgTempfile.h>

#ifndef KGLIB_VERSON
 #define KGLIB_VERSON "0:0:0"
#endif
#ifndef KGMOD_VERSON
 #define KGMOD_VERSON "0:0:0"
#endif



// -----------------------------------------------------------------------------
//　Terminate設定
// -----------------------------------------------------------------------------
namespace 
{	
	class kgMod* mod;
	void kgTerminate()
	{
		ostringstream ss;
		ss << "terminated error (" << mod->name() << ")";
		kgError err(ss.str());
		mod->errorEnd(err);
		if(mod){ delete mod;}
		
		_exit(1);
	}
}

// -----------------------------------------------------------------------------
// コンストラクタ
// -----------------------------------------------------------------------------
kgMod::kgMod(void) :  _status( 0 ){
	_name    = "";
	_version = "";
	_title	 = "";
	_doc		 = "";
	_titleL	 = "";
	_docL		 = "";
	_localhelp = false;
	_libversion = KGLIB_VERSON;
	_modversion = KGMOD_VERSON;
	_existNullIN  = false;
	_existNullOUT = false;
	_existNullKEY = false;
	_rp = false;

}

// -----------------------------------------------------------------------------
// シグナルハンドラー設定
// -----------------------------------------------------------------------------
static kgMod* g_mod_=NULL;
void kgMod::signalHandler( int sigNo, siginfo_t* info, void* ctx )
{
	// 起動フラグON
	g_mod_->env( )->sigact( );

	// SIGPIPEの場合は正常終了
	if(sigNo==SIGPIPE){
		g_mod_->signalEnd();
		kgTempfile::interrupt_clean(g_mod_->tmpPath());
		g_mod_->successEnd();
		_exit( g_mod_->status( ) );
	}
	// ユーザイベント 未使用
	else if( sigNo==SIGUSR1 ) {
		g_mod_->successEnd( );
		_exit( g_mod_->status( ) );	
	}
	// その他のSIGNALはエラー終了とする
	// msg ex) end by signal 2 - CTRL-C (kgsortf:1111)
	else{	
		ostringstream ss;
		ss << "end by signal " << sigNo;
		switch(sigNo){
			case SIGINT:  ss << " - CTRL-C "         ; break;
			case SIGSEGV: ss << " - segmentation violation "; break;
		}
		ss << "(" << g_mod_->name() << ":" << getpid( ) << ")";
		kgError err=kgError(ss.str());
		g_mod_->errorEnd(err); // kgmodエラー終了処理
		kgTempfile::interrupt_clean(g_mod_->tmpPath());
		_exit( g_mod_->status( ) );
	}
}

//　signal　設定を別にする
void kgMod::signalset(void) try {
	if(g_mod_==NULL){ g_mod_= this; }
	struct sigaction sa_sigint;
	memset(&sa_sigint, 0, sizeof(sa_sigint));
	sa_sigint.sa_sigaction=this->signalHandler;
	sa_sigint.sa_flags=SA_RESETHAND | SA_SIGINFO;
	sigaction( SIGPIPE, &sa_sigint, NULL ); // signal  2
	sigaction( SIGINT , &sa_sigint, NULL ); // signal 11
	sigaction( SIGSEGV, &sa_sigint, NULL ); // signal 13
	sigaction( SIGUSR1, &sa_sigint, NULL ); // signal ユーザ定義
}catch(kgError& err){
  errorEnd(err);
}


// -----------------------------------------------------------------------------
// メンバー変数の初期化 kgargs
// -----------------------------------------------------------------------------
void kgMod::init(void) try 
{
	// -------------------------------------
	// terminate用関数の登録
	// -------------------------------------
	if(g_mod_==NULL){
		set_terminate(kgTerminate);
		mod=this;
	}
	// -------------------------------------
	// 各種メンバー変数の設定
	// -------------------------------------
	// _args = args; xcodeを新しくするとここでおかしくなる
	//_env  = env;
	// -------------------------------------
	// 環境変数の取り込み
	// -------------------------------------
	_tmpPath   = _env->getTmpPath();
	_encoding  = _env->getEncoding();
	_nfn_i     = _env->getNoFldName();
	_nfn_o     = _env->getNoFldName();
	_precision = _env->precision();

	//項目番号指定(項目名無の指定なら初期値でtrue)
	if(_nfn_i){ _fldByNum = true;}
	else			{ _fldByNum = _env->fldByNum();}

	//ロケール設定 
	setlocale(LC_CTYPE,_encoding.c_str());

	// -------------------------------------
	// 共通の引数
	// 全モジュール共通の引数をチェックし，
	// 指定されていればkgModのメンバー変数にセットする
	// -------------------------------------
	// 一時ファイル出力先
	kgstr_t k = _args.toString("tmpPath=",false);
	if(! k.empty() ) {
		_tmpPath=k;
		_env->setTmpPath(_tmpPath);
	}

	// エンコーディング
	string s = _args.toString("encoding=",false);
	if(! s.empty() ) _encoding=s;

	// 項目行なしフラグ
	bool b = _args.toBool("-nfn");
	if(b){
		_nfn_i = b;
		_nfn_o = b;
		_fldByNum = true;
	}

	// 出力項目行なしフラグ
	bool c = _args.toBool("-nfno");
	if(c){ _nfn_o = c; }

	// 有効桁数
	string t = _args.toString("precision=",false);
	if(! t.empty() ){
		int p=atoi(t.c_str());
		     if(p>KG_MAX_PRECISION) _precision=KG_MAX_PRECISION;
		else if(p<1               ) _precision=1;
		else                        _precision=p;
	}

	// 項目番号指定フラグ
	bool x = _args.toBool("-x");
	if(x){ _fldByNum = true; }

	// rp
	bool rp = _args.toBool("-rp");
	if(rp){ _rp = true; }


	// in-out-数チェック
	_assertDIff    = _args.toBool("-assert_diffSize");
	_assertNullIN  = _args.toBool("-assert_nullin");
	_assertNullOUT = _args.toBool("-assert_nullout");
	_assertNullKEY = _args.toBool("-assert_nullkey");

	// シグナルトラップ設定
/*
	if(g_mod_==NULL){ g_mod_= this; }
	struct sigaction sa_sigint;
	memset(&sa_sigint, 0, sizeof(sa_sigint));
	sa_sigint.sa_sigaction=this->signalHandler;
	sa_sigint.sa_flags=SA_RESETHAND | SA_SIGINFO;
	sigaction( SIGPIPE, &sa_sigint, NULL ); // signal  2
	sigaction( SIGINT , &sa_sigint, NULL ); // signal 11
	sigaction( SIGSEGV, &sa_sigint, NULL ); // signal 13
	sigaction( SIGUSR1, &sa_sigint, NULL ); // signal ユーザ定義
*/

}catch(kgError& err){
  errorEnd(err);
}
// -----------------------------------------------------------------------------
// メンバー変数の初期化 argc,argv
// -----------------------------------------------------------------------------
void kgMod::init(size_t argc, const char* argv[], kgEnv* env) try 
{
	_env=env;
	_args.add(argc, argv);
	init();
	signalset();
	
}catch(kgError& err){
  errorEnd(err);
}

void kgMod::init(kgArgs args, kgEnv* env)try 
{
	_env=env;
	_args = args;
	init();
	signalset();
	
}catch(kgError& err){
  errorEnd(err);
}


// -----------------------------------------------------------------------------
// 正常終了メッセージの出力
// -----------------------------------------------------------------------------
void kgMod::AssertWarnig(void){
	if(_assertDIff && iRecNo()!=size_t(-1) && 
		oRecNo()!=size_t(-1) && iRecNo()!=oRecNo() ){
		kgMsg asertmsg(kgMsg::WAR, _env);
		asertmsg.output("the number of lines is different");
	}
	if(_existNullIN){ 
		kgMsg asertmsg(kgMsg::WAR, _env);
		asertmsg.output("exist NULL in input data");
	}
	if(_existNullOUT){ 
		kgMsg asertmsg(kgMsg::WAR, _env);
		asertmsg.output("exist NULL in output data");
	}
	if(_existNullKEY){ 
		kgMsg asertmsg(kgMsg::WAR, _env);
		asertmsg.output("exist NULL in key filed");
	}
}

void kgMod::successEnd(void)
{
	AssertWarnig();
	kgMsg msg(kgMsg::END, _env);
	msg.output(this,"");
	_status = 0;
}
// -----------------------------------------------------------------------------
// 正常終了メッセージの出力（コメント付き）
// -----------------------------------------------------------------------------
void kgMod::successEnd(const string& comment)
{
	AssertWarnig();
	kgMsg msg(kgMsg::END, _env);
	msg.output(this, comment);
	_status = 0;
}
// -----------------------------------------------------------------------------
// error終了メッセージの出力
// -----------------------------------------------------------------------------
void kgMod::errorEnd(kgError& err)
{
	err.addModName(_name);
	kgMsg msg(kgMsg::ERR, _env);
	if( _env->recursiveMsg() ){
		msg.output(this,err.message());
	}else{
		msg.output(this,err.message(0));
	}
	_status = 1;
	if(!_env->sigactcheck()){ throw(err);}
}
// -----------------------------------------------------------------------------
// error終了メッセージの出力（コメント付き）
// -----------------------------------------------------------------------------
void kgMod::errorEnd(kgError& err, const string& comment)
{
	err.addModName(_name);
	kgMsg msg(kgMsg::ERR, _env);
	if( _env->recursiveMsg() ){
		msg.output(this,err.message(),comment);
	}else{
		msg.output(this,err.message(0),comment);
	}
	_status = 1;
	if(!_env->sigactcheck()){ throw(err); }
}
// -----------------------------------------------------------------------------
// error終了メッセージの出力（kgErrorを伴わないerror）なくなる予定
// -----------------------------------------------------------------------------
void kgMod::errorEnd(void)
{
	ostringstream ss;
	ss << "unexpected error (" << _name << ")";
	kgError err(ss.str());
	kgMsg msg(kgMsg::ERR, _env);
	msg.output(this,err.message());
	_status = 1;
	if(!_env->sigactcheck()){ throw(err); }
}
// -----------------------------------------------------------------------------
// error終了メッセージの出力（kgErrorを伴わないerror）（コメント付き）なくなる予定
// -----------------------------------------------------------------------------
void kgMod::errorEnd(const string& comment)
{
	ostringstream ss;
	ss << "unexpected error (" << _name << ")";
	kgError err(ss.str());
	kgMsg msg(kgMsg::ERR, _env);
	msg.output(this, err.message(), comment);
	_status = 1;
	if(!_env->sigactcheck()){ throw(err); }
}
// -----------------------------------------------------------------------------
// コマンドライン文字列
// -----------------------------------------------------------------------------
string kgMod::cmdline(void) const
{
	ostringstream ss;
	ss << _name << _args.to_s();
	return ss.str();
}
