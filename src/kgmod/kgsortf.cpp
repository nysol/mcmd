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
// kgsortf.cpp 項目指定によるレコードの並べ換えクラス
// ============================================================================
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <kgsortf.h>
#include <kgConfig.h>
#include <kgMethod.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <kgEnv.h>
#include <kgArgFld.h>



using namespace std;
using namespace kglib;
using namespace kgmod;
using namespace boost;

namespace kgmod         {//////////////////////////////////////////////////
namespace kgsortf_local {//////////////////////////////////////////////////

	// mergeの際の優先キューにセットする要素
	struct PQkey {

		int               fno_;  // マージ対象ファイル番号
		char**            rec_;  // 対象レコード
		struct _COMP_FLD* cfld_;

		// csvから一行読み込み、PQkeyにセットする
		int set( kgCSVfld* csv, int fno, struct _COMP_FLD* cfld) 
		{
			cfld_ = cfld;

			if(EOF==csv->read()){
				return EOF;
			}else{
				rec_ = csv->getFld();      // 読みこんだ文字の先頭アドレス
				fno_ = fno;                // バケット番号のセット
				return 0;
			}
		}
	};
// -----------------------------------------------------------------------------
// 内部で利用する関数
// -----------------------------------------------------------------------------
	// 文字列昇順
	inline int cmpStrAsc(unsigned char* a, unsigned char* b)
	{
		while(true){
		       if(*a < *b) return -1;
			else if(*a > *b) return  1;
			if(*a=='\0') break; // *a==*b=='\0'
			a++;b++;
		}
		return 0;
	}

	// 文字列降順
	inline int cmpStrDec(unsigned char* a, unsigned char* b)
	{
		while(true){
		       if(*a < *b) return  1;
			else if(*a > *b) return -1;
			if(*a=='\0') break; // *a==*b=='\0'
			a++;b++;
		}
		return 0;
	}

	// 数値昇順
	inline int cmpNumAsc(char* a, char* b)
	{
		if(*a=='\0'){
			if(*b=='\0') return 0;
			else         return -1;
		}else{
			if(*b=='\0') return 1;
			double fa=atof(a);
			double fb=atof(b);
		       if(fa < fb) return -1;
			else if(fa > fb) return  1;
			else             return  0;
		}

		return 0;

	}
	// 数値昇順
	inline int cmpNumDec(char* a, char* b)
	{
		if(*a=='\0'){
			if(*b=='\0') return 0;
			else         return 1;
		}else{
			if(*b=='\0') return -1;
			double fa=atof(a);
			double fb=atof(b);
		       if(fa < fb) return  1;
			else if(fa > fb) return -1;
			else             return  0;
		}

		return 0;

	}

// ---------------------------------------------------------------------------
// priority_queueで利用する優先順位比較のためのファンクタ
// cmpFld2はcmpFld関数と整合性をとる必要有り．
// ---------------------------------------------------------------------------
struct recComp 
{
	// cmpFld with cfld
	int cmpFld2(char** fld1, char** fld2, struct _COMP_FLD* cfld) 
	{
		int retVal=0;
		for(int i=0; i<cfld->cnt; i++){
			int no=cfld->num[i];

			switch( cfld->flg[i] ){
			case 0: // 数値昇順
				retVal=cmpStrAsc((unsigned char*)fld1[no], (unsigned char*)fld2[no]);
				break;
			case 1: // 文字昇順
				retVal=cmpNumAsc(fld1[no], fld2[no]);
				break;
			case 2: // 数値降順
				retVal=cmpStrDec((unsigned char*)fld1[no], (unsigned char*)fld2[no]);
				break;
			case 3: // 文字降順
				retVal=cmpNumDec(fld1[no], fld2[no]);
				break;
			}

			if(retVal){ // 同じでなくなれば判定が決まる
				return retVal;
			}
		}
    return 0; // fld1==fld2
  }
 	bool operator()(const PQkey& v1, const PQkey& v2)
 	{
   	if( cmpFld2(v1.rec_,v2.rec_,v1.cfld_)>0 ) return true;
	 	else                                      return false;
 	}

};

} //////////////////////////////////////////////////////////////////////////////
} //////////////////////////////////////////////////////////////////////////////
using namespace kgsortf_local;
// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSortf::kgSortf(void)
{
	_name    = "kgsortf";
	_version = "###VERSION###";

	#include <help/en/kgsortfHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsortfHelp.h>
	#endif


}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgSortf::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,pways=,maxlines=,blocks=,threadCnt=,-noflg",kgArgs::COMMON|kgArgs::IODIFF);
	// 
	_noflg =_args.toBool("-noflg");

	// バッファのブロック数 1block=KG_MAX_REC_LEN*4
	kgstr_t s=_args.toString("blocks=",false);
	if(s.empty()) _blocks=10;
	else          _blocks=atoi(s.c_str());
	if(_blocks < 1 || _blocks>1000){
		kgError err("invalid blocks: must be in range [1,1000]");
		errorEnd(err);
	}
	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env, _nfn_i, _blocks);
	_oFile.open(_args.toString("o=",false), _env, _nfn_o,_rp);
	_iFile.read_header();

	// マージソートを行う際に、何個までのファイルを同時に併合させるか
	s=_args.toString("pways=",false);
	if(s.empty()) _pways=32;
	else          _pways=atoi(s.c_str());
	if(_pways < 2 || _pways>100){
		throw kgError("invalid pways: must be in range [2,100]");
	}

	// 分割ソートでのデータ読み込み行数の上限値
	s=_args.toString("maxlines=",false);
	if(s.empty()) _maxlines=500000;
	else          _maxlines=aToSizeT(s.c_str());
//	if(_maxlines < 100 || _maxlines>10000000){
//		throw kgError("invalid maxlines: must be in range [100,10000000]");
//	}

	// ソートするthreadの数
	s=_args.toString("threadCnt=",false);
	if(s.empty()) _threadCnt=8;
	else          _threadCnt=atoi(s.c_str());
	if(_threadCnt < 1 || _threadCnt>50){
		throw kgError("invalid threadCnt: must be in range [1,50]");
	}

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvsf = _args.toStringVecVec("f=","%:",2,true);
	vector< vector<kgstr_t> > vvs(2);
	for(size_t i=0;i<vvsf[0].size();i++){
		bool add = true;
		for(size_t j=0;j<vvs[0].size();j++){
			if(vvsf[0][i]==vvsf[0][j]){
				add = false;
				break;
			}
		}
		if(add){
			vvs[0].push_back(vvsf[0][i]);
			vvs[1].push_back(vvsf[1][i]);
		}
	}

	//_fField.set(vvs, &_iFile,_fldByNum, false); // 項目名展開は行わない
	_fField.set(vvs, &_iFile,_fldByNum); // 項目名展開は行わない

	// 一時ファイルの初期化
	tempFile_.init(_env);
}
// ---------------------------------------------------------------------------
// 一時ファイル名の取得
// ---------------------------------------------------------------------------
kgstr_t& kgSortf::getTmpName(size_t level,size_t no)
{
	if(tmpName_.size() < level+1){
		throw kgError("internal error: getTmpName1()");
	}else{
		if(tmpName_.at(level).size() < no+1){
			throw kgError("internal error: getTmpName2()");
		}
	}
	return tmpName_.at(level).at(no);

}
// ---------------------------------------------------------------------------
// 新たなファイル名の生成
// ---------------------------------------------------------------------------
kgstr_t& kgSortf::newTmpName(size_t level,size_t no)
{
	if(tmpName_.size() < level+1) tmpName_.resize(level+1);
	kgstr_t tp = tempFile_.create(false,"sortf");
	tmpName_.at(level).push_back(tp);
	//tmpName_.at(level).push_back(tempFile_.create(false,"sortf"));
	return tmpName_.at(level).back();

}
// ---------------------------------------------------------------------------
// cfldnoの設定
// ---------------------------------------------------------------------------
void kgSortf::setCfld(kgArgFld* fField)
{
	// キー項目の数
	cfld_.cnt = fField->size();

	// キー項目番号配列
	try {
		compFld_num_.set( new int[cfld_.cnt] );
	} catch(...) {
		throw kgError("memory allocation error in kgSortDat1");
	}

	cfld_.num = compFld_num_.get();
	for(int i=0; i<cfld_.cnt; i++){
		cfld_.num[i] = fField->num(i);
	}

	// キー項目フラグ配列
	try {
		compFld_flg_.set( new int[cfld_.cnt] );
	} catch(...) {
		throw kgError("memory allocation error in kgSortDat2");
	}
	cfld_.flg = compFld_flg_.get();

	for(int i=0; i<cfld_.cnt; i++){
		kgstr_t s=fField->attr(i);
		int flg=0;
		if( s.find('n')!=string::npos ) flg |= 1;
		if( s.find('r')!=string::npos ) flg |= 2;
		cfld_.flg[i] = flg;
	}
}
// ---------------------------------------------------------------------------
// 項目単位での比較(文字昇順)
// ---------------------------------------------------------------------------
int kgSortf::cmpFld(char** fld1, char** fld2)
{
	int retVal=0;

	for(int i=0; i<cfld_.cnt; i++){

		int no=cfld_.num[i];
		switch( cfld_.flg[i] ){
		case 0: // 数値昇順
			retVal=cmpStrAsc((unsigned char*)fld1[no], (unsigned char*)fld2[no]);
			break;
		case 1: // 文字昇順
			retVal=cmpNumAsc(fld1[no], fld2[no]);
			break;
		case 2: // 数値降順
			retVal=cmpStrDec((unsigned char*)fld1[no], (unsigned char*)fld2[no]);
			break;
		case 3: // 文字降順
			retVal=cmpNumDec(fld1[no], fld2[no]);
			break;
		}

		if(retVal){ // 同じでなくなれば判定が決まる
			return retVal;
		}
	}

	return 0; // fld1==fld2

}
//---------------------------------------------------------------------------
// 以下の文献に掲載されたソースを改変して利用
// 河村知行「UNIXのクイックソートの罠」bit, vol 346, pp.21-27, 1995/7.
//---------------------------------------------------------------------------
void kgSortf::qsort5(char*** base, int nel)
{
	// L,l R,rを積むスタックの構造体*/
	typedef struct      { char ***LL, ***RR; } stack_node;

	// L,l,R,rを積む
	#define PUSH(ll,rr) {top->LL = (ll); top->RR = (rr); ++top;} // L,l,R,rを積む

	#define POP(ll,rr)  {--top; ll = top->LL; rr = top->RR;} // L,l,R,rを戻す
	#define M(x,y)      { *(x)=*(y); }                 // yをxへ複写する*/
	#define SWAP(x,y)   {M(s,x); M(x,y); M(y,s);}  // swap 
	#define IF3R        {if (l+1 == m)             goto nxt;} // 要素数３の時
	#define IF3BR       {if (l+1 == m) {M(m,s);    goto nxt;}}
	#define IF3SR       {if (l+1 == m) {SWAP(l,r); goto nxt;}}
	#define SET_lr      {l++; if ((--r) != m) M(m,r);} // 右に空の要素を作る
	#define THREASHOLD  10 // 挿入ソートに切り替える要素数

 	register char ***l, ***r, ***m;    // l,r:左右の集団の端　m:配列の中央の位置
 	register int t, eq_l, eq_r;        // eq_l:左の集団が全てsに等しいことを示す
	char** ss;
 	char*** s=&ss;                     // 分割要素を保存する所　SWAPにも使用
 	char*** L = base;                  // 現在分割している区間の左端の要素の先頭
 	char*** R = base + nel - 1;        // 現在分割している区間の右端の要素の先頭
 	int chklim = 100;                  // 昇(降)順検査をする要素の下限*/
	stack_node stack[64], *top = stack;// スタックの深さ.32ビットマシンでは32で十分
	int n;

	if (nel <= 1) {return;}   // 要素数が１以下の時は即終了する
	
	goto start;

	nxt:

	if (stack == top) {return;} // スタックが空になったとき終了する

	POP(L,R);

	for (;;) {

		start:
  	// 要素数が少なくなってきたら挿入ソートに切り替え
 		if (R-L < THREASHOLD) {
   		int first = L-base;
   		int last  = R-base;
			for (int i = first + 1; i <= last; i++){
				for (int j = i; j > first && cmpFld(base[j - 1],base[j]) > 0; --j){
					SWAP( &base[j], &base[j - 1]);
				}
			}
   		goto nxt;
 		}

		n=(R-L+1);
		l = L; r = R;
		m=L+(n >> 1);      // 配列の中央を決定

		if ((t = cmpFld(*l,*m)) < 0) {                                    // 3-5-?
     	if ((t = cmpFld(*m,*r)) < 0) {                                  // 3-5-7
       	IF3R;
       	if (chklim && nel >= chklim) {                   // 既に昇順か検査する
         	char ***p;
         	chklim = 0;
         	for (p = l; p < r; p++) if (cmpFld(*p,*(p+1)) > 0) goto fail;
         	goto nxt;
       	}
       	fail: M(s,m); goto loopA;
     	}
     	if (t > 0) {
       	if (cmpFld(*l,*r) <= 0) {M(s,r); M(r,m); IF3BR; goto loopA;}  // 3-5-4
       	M(s,l); M(l,r); M(r,m); IF3BR; goto loopA;                    // 3-5-2
     	}
     	IF3R; M(s,m); goto loopB;                                       // 3-5-5
   	}
   	if (t > 0) {                                                      // 7-5-?
     	if ((t = cmpFld(*m,*r)) > 0) {                                  // 7-5-3
       	IF3SR;
       	if (chklim && nel >= chklim) {                   // 既に降順か検査する
         	char ***p;
         	chklim = 0;
         	for  (p = l; p < r; p++) if (cmpFld(*p,*(p+1)) < 0) goto fail2;
         	while (l<r){SWAP(l,r); l++; r--;} // 区間全体を逆順にする
         	goto nxt;
       	}
       	fail2: SWAP(l,r); M(s,m); goto loopA;                         // 7-5-3
     	}
     	if (t < 0) {
        if (cmpFld(*l,*r) <= 0) {M(s,l); M(l,m); IF3BR; goto loopB;}  // 7-5-8
       	M(s,r); M(r,l); M(l,m); IF3BR; goto  loopA;                   // 7-5-6
     	}
     	IF3SR; M(s,r); M(r,l); M(l,m); goto loopA;                      // 7-5-5
   	}

   	if ((t = cmpFld(*m,*r)) < 0) {IF3R; M(s,m); goto loopA;}          // 5-5-7
   	if (t > 0) {IF3SR; M(s,l); M(l,r); M(r,m); goto loopB;}           // 5-5-3

   	IF3R; M(s,m); SET_lr; // 5-5-5のときに分割の種類を決める          // 5-5-5

   	for (;;) {
     	if ((t = cmpFld(*l,*s)) > 0) {eq_l = 1; eq_r = 0; goto loopAx;} // 5-5-7
     	if (t < 0)                 {eq_l = 0; eq_r = 1; goto loopBy;}   // 5-5-3
     	if (++l >= r)      {M(l,s); goto nxt;}                          // 5-5-5
   	}

   	loopA: SET_lr; eq_l = 1; eq_r = 0; // タイプＡの分割 左 <= 分割値 < 右

   	for (;;) {
     	for (;;) {
       	if ((t = cmpFld(*l,*s)) > 0) break;
       	if (t < 0) eq_l = 0;
       	if (++l >= r) goto fin;
     	}
     	loopAx:
     	M(r,l); if (l >= --r) goto fin; // 左から右へ放リ投げる

     	for (;;) {
       	if ((t = cmpFld(*r,*s)) < 0) {eq_l = 0; break;}
       	if (t == 0) break;
       	if (l >= --r) goto fin;
     	}

     	M(l,r); if ( ++l >= r) goto fin; // 右から左へ放リ投げる

   	}

   	loopB: SET_lr; eq_l = 0; eq_r = 1; // タイプＢの分割左 <= 分割値 < 右

   	for (;;) {
     	for (;;) {
       	if ((t = cmpFld(*l,*s)) > 0) {eq_r = 0; break;}
       	if (t == 0) break;
       	loopBy:
       	if (++l >= r) goto fin;
     	}
     	M(r,l); if (l >= --r) goto fin; // 左から右へ放リ投げる

     	for (;;) {
       	if ((t = cmpFld(*r,*s)) < 0) break;
       	if (t > 0) eq_r = 0;
       	if (l >= --r) goto fin;
     	}
     	M(l,r); if (++l >= r) goto fin; // 右から左へ放リ投げる
   	}

   	fin: M(l,s); // 保存しておいた値を戻す　ここでは必ず　l == r になっている

   	if (l-L < R-l) {               // 分割後の区間の短い方から再分割する
     	if (eq_r == 0) PUSH(l+1,R);  // 右側には必ず２個以上ある
     	if (L < l-1 && eq_l == 0) R = l-1; else goto nxt; // 左から先にやる
   	}
   	else {
     	if (eq_l == 0) PUSH(L,l-1);  // 左側には必ず２個以上ある
     	if (l+1 < R && eq_r == 0) L = l+1; else goto nxt; // 右から先にやる
   	}
	}
}
// ---------------------------------------------------------------------------
// qsortの結果を一時ファイルに書き込む関数
// 一時ファイルの項目名は書き出さない
// ---------------------------------------------------------------------------
void kgSortf::writeBuf(char ***index, int recCnt, int fldCnt, kgstr_t& ofName)
{
	// ファイルオープン
	kgCSVout csvOut;
	csvOut.open( ofName, _env );

	// indexで示されたデータ(recCnt行)の書きだし
	for(int i=0; i<recCnt; i++){
		csvOut.writeFld(fldCnt,index[i]);
	}

	// ファイルクローズ
	csvOut.close();

}
// ---------------------------------------------------------------------------
// recCnt行のindexの内容をsortし,ofNameファイルに書き出す
// ---------------------------------------------------------------------------
void kgSortf::do_sort(char*** index, int recCnt, kgstr_t ofName)
{
	qsort5(index,recCnt);
	writeBuf(index,recCnt,_iFile.fldSize(),ofName);
}

void* kgSortf::run_sort_thread(void *obj){
	sortArgST* thObj = ((sortArgST*)obj);
	thObj->mobj->do_sort(thObj->start,thObj->blkSize,thObj->ofName);
	return NULL;
}
// -----------------------------------------------------------------------------
// 入力データを分割&sorting&一時ファイル出力
// 入力: CSV file
// 出力: sort済みのoCnt個のCSV file , ファイル番号 0?oCnt(返値)
// -----------------------------------------------------------------------------
int kgSortf::sort(kgCSVfld& csv)  
{
	int fldCnt = csv.fldSize();

	// ソーティング用レコードインデックス領域の確保
	kgAutoPtr2<char**> ap1;
	try {
		ap1.set( new char**[_maxlines] );
	} catch(...) {
		throw kgError("memory allocation error in sorting1");
	}
	char*** index = ap1.get();

	// ソーティング用キー項目インデックス領域の確保
	kgAutoPtr2<char*> ap2;
	try {
		ap2.set( new char*[_maxlines*fldCnt] ); // 行数×csv項目数
	} catch(...) {
		throw kgError("memory allocation error in sorting2");
	}
	char** fldIndex = ap2.get();

	int oCnt   = 0; // 分割されたファイル番号
	int recCnt = 0; // インデックス上のレコード数

	// 入力ファイルの行単位read
	while(EOF != csv.read() ){
		char** flds = csv.getFld();

		// fldインデックスの作成
		for(int i=0; i<fldCnt; i++){
			fldIndex[recCnt*fldCnt+i]=flds[i];
		}

		// インデックスの作成
		index[recCnt]=fldIndex+recCnt*fldCnt;
		recCnt++;

		// sort & ワークファイルへの書き出し
		if( csv.isEndOfBuf() || csv.isEOF() || recCnt>=_maxlines){
			// 10000件以下 or threadCntが1であればthread利用しない
			if( recCnt<10000 || _threadCnt==1 ){

				kgstr_t& ofName = newTmpName(0,oCnt++);
				do_sort(index, recCnt, ofName);

			}else{
				// thread データ構造作成速度チェックすること　
				kgAutoPtr2<sortArgST> aps;
				kgAutoPtr2<pthread_t> aps_pth;
				try {
					aps.set    ( new sortArgST[_threadCnt] );
					aps_pth.set( new pthread_t[_threadCnt] );
				} catch(...) {
					throw kgError("memory allocation error on CSVin");
				}
				sortArgST* data    = aps.get();
				pthread_t* th_st_p = aps_pth.get();

				// バッファのデータを_threadCnt個に分割しthreadでsort
				int blkSize  = recCnt / _threadCnt; // 1ブロックの件数
				int amari    = recCnt % _threadCnt; // 端数は最後のブロックにて
				for(int i=0; i<_threadCnt; i++){
					char*** start = index+blkSize*i;  // sorting対象indexのスタートaddress
					if(i == _threadCnt-1) blkSize += amari;
				
					data[i].mobj=this;
					data[i].start=start;
					data[i].ofName = newTmpName(0,oCnt++);
					data[i].blkSize=blkSize;
					if( pthread_create( &th_st_p[i], NULL,
  			      kgSortf::run_sort_thread ,(void *)&data[i] )){
  			      throw kgError("cant't create thread on kgModIncludeSort");
  				}
  			}
				for(int i=0; i<_threadCnt; i++){
					int rtn = pthread_join(th_st_p[i],NULL);
					if(rtn!=0) { cerr << "waring  fail thread join : " << rtn << endl; }
				}
			}
			recCnt=0;
		}
	}
	return oCnt;
}
// -----------------------------------------------------------------------------
// (level)回戦のiBgn~iEndまでを併合して (level+1)回戦のoNumを作成する
// -----------------------------------------------------------------------------
void kgSortf::merge(int level, int iBgn, int iEnd, int oNum, bool final)
{
	// 併合するCSVrec配列
	kgAutoPtr2<kgCSVfld> api(new kgCSVfld[iEnd-iBgn]);
	kgCSVfld* csv=api.get();
	priority_queue<PQkey, vector<PQkey>, recComp> pQue; // 優先キュー
	struct PQkey pqKey;                                 // queに入れるデータ

	// iBgnからiEndまでのファイルをオープンし，最初の行をキューに入れる
	int fno=0;
	for(int i=iBgn; i<iEnd; i++){

		csv[fno].open( getTmpName(level,i), _env, true, 4 );
		csv[fno].read_header();

		// csv[fno]から一行読み込みpqKeyにセット
		if( EOF!=pqKey.set(&csv[fno], fno, &cfld_)){
			pQue.push(pqKey); // キューにセット
		}
		fno++;
	}

	// 出力ファイルオープン(決勝戦では_oFileに出力する．
	kgCSVout *oTemp; // 出力CSVファイルポインタ
	kgAutoPtr1<kgCSVout> apo;

	if(final){
		oTemp = &_oFile;
	}else{
		apo.set(new kgCSVout);
		oTemp = apo.get();
 		oTemp->open( newTmpName(level+1,oNum), _env );
	}
	// 項目名の書きだし
	if(final){
		if(_noflg) { oTemp->writeFldName(_iFile); }
		else			 { oTemp->writeFldName(_fField,kgstr_t("%")); }
	}

	//----------------------------------------------------
	// Pway個のファイルから一行づつ読み込み書き出すループ
	//----------------------------------------------------
	while(1) {

		if( pQue.empty() ) break;        // キューが空なら終了

		fno=pQue.top().fno_;             // 最優先のファイル番号
		oTemp->writeFld(_iFile.fldSize(), pQue.top().rec_); //一行書き出し
		pQue.pop();                      // 最優先データをキューから削除

		// popで削除したファイル番号のcsvから一行読み込みqueueにセット
		if( EOF!=pqKey.set(&csv[fno], fno, &cfld_)){
			pQue.push(pqKey);
		}

	}
	//----------------------------------------------------
	// 出力ファイルのclose(flush)
	//----------------------------------------------------
	if(!final) oTemp->close();

	// 一時入力ファイルの消去&close (removeはboost関数)
	for(int i=0; i<iEnd-iBgn; i++){
		string fn=csv[i].fileName();
    csv[i].close();
		remove(fn.c_str());
	}

}
// -----------------------------------------------------------------------------
// PriorityQueを用いたPWayマージ
// 既に並べ変わっているiCnt個のバケットをmergeし,
// round_up(iCnt/PWay)個のファイルを得る．
// 得られた出力ファイル数を返す．
// -----------------------------------------------------------------------------
int kgSortf::mergeOneLevel(int level, int iCnt) 
{
  // 残りPWay個以下なら決勝戦
	bool final=false;
	if(iCnt<=_pways) final=true;

	int oCnt=0;
	int iBgn=0;
	int iEnd=0;

	for(oCnt=0; iEnd!=iCnt ;oCnt++){
		iBgn = _pways *  oCnt;
		iEnd = _pways * (oCnt+1);
		if(iEnd>iCnt) iEnd=iCnt;

		// level_iBgnからlevel_iEndまでの一時ファイルを併合し
		// (level+1)_oCnt に書き出す．
		merge( level, iBgn, iEnd, oCnt, final );
	}

	if(final) return 0;
	else      return oCnt;

}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSortf::run(void) try 
{	
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	if( _iFile.noFldName() && _iFile.fldSize()==0 ){
		successEnd();
		return 0;
	}

	// ソート対象項目のセット
	setCfld(&_fField);

	// thread分割ソート
	int iCnt=sort(_iFile);

	// 入力件数0の時は例外的に項目名のみ出力して終了
	if(iCnt==0){
		if(_noflg) { _oFile.writeFldName(_iFile); }
		else			 { _oFile.writeFldName(_fField,kgstr_t("%")); }
		_oFile.close();
	}else{
		// マージ
		for(int level=0; iCnt!=0 ;level++){
			iCnt=mergeOneLevel(level, iCnt);
		}
	}

	// 終了処理
	_iFile.close();
	_oFile.close();
	successEnd();
	return 0;

}catch(kgError& err){
	errorEnd(err);
	return 1;
}catch (const std::exception& e) {
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

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
void kgSortf::prerun_noargs(int fd) try 
{
	_oFile.popen(fd, _env, _nfn_o);
}catch(kgError& err){
	tempFile_.remove_all();
	errorEnd(err);
}
catch(...){
	tempFile_.remove_all();
}

///* thraad cancel action
static void cleanup_handler(void *arg)
{
    ((kgSortf*)arg)->forcedClose();
}


// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
void kgSortf::run_noargs() try 
{
	// thread cleanup 登録
	pthread_cleanup_push(&cleanup_handler, this);	
	 
	_blocks=10;
	_pways=32;
	_maxlines=500000;
	_threadCnt=8;
	_noflg=false;
	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=","%:",2,true);
	_fField.set(vvs, &_iFile,_fldByNum);
	tempFile_.init(_env);

	if( _iFile.noFldName() && _iFile.fldSize()==0 ){
		successEnd();
		return;
	}

	// ソート対象項目のセット
	setCfld(&_fField);

	// thread分割ソート
	int iCnt=sort(_iFile);

	// 入力件数0の時は例外的に項目名のみ出力して終了
	if(iCnt==0){
		if(_noflg) { _oFile.writeFldName(_iFile); }
		else			 { _oFile.writeFldName(_fField,kgstr_t("%")); }
		_oFile.close();

	}else{
		// マージ
		for(int level=0; iCnt!=0 ;level++){
			iCnt=mergeOneLevel(level, iCnt);
		}
	}
	// 終了処理
	_iFile.close();
	_oFile.close();
	successEnd();
	// thread cleanup 解除
  pthread_cleanup_pop(0);
  
}catch(kgError& err){
	tempFile_.remove_all();
	errorEnd(err);
}catch (const std::exception& e) {
	tempFile_.remove_all();
}catch(char * er){
	tempFile_.remove_all();
}catch(...){
	tempFile_.remove_all();
	//pthread_cancelが起こったときthrowしないabortする
	throw;
}
