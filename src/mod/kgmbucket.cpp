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
// kgmbucket.cpp 件数均等化バケット分割(２項目以上)
// =============================================================================
#include <cstdio>
#include <iostream>
#include <map>
#include <climits>
#include <cfloat>
#include <kgmbucket.h>
#include <kgError.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// static 
namespace { ////////////////////////////////////////////////////////////////
// -----------------------------------------------------------------------------
// 各次元のbuket番号から，対応するslice上の配列番号を計算する．
// -----------------------------------------------------------------------------
int calSliceAddress(int dim, vector<int>& bkt, vector<int>& bktSize){
	int address=0;
	int ce=1; // 各バケット番号に掛ける係数
	for(vector<int>::size_type i=0; i<bktSize.size(); i++){
		if(static_cast<int>(i)==dim) continue;
		address += bkt.at(i)*ce;
		ce*=bktSize.at(i);
	}
	return address;
}
// -----------------------------------------------------------------------------
// 各次元のbuket番号から，対応するcube上の配列番号を計算する．
// -----------------------------------------------------------------------------
int calAddress(vector<int>& bkt, vector<int>& bktSize){
	int address=0;
	int ce=1; // 各バケット番号に掛ける係数
	for(vector<int>::size_type i=0; i<bktSize.size(); i++){
		address += bkt.at(i)*ce;
		ce*=bktSize.at(i);
	}
	return address;
}
// =============================================================================
// Bucketクラス(各次元のbucket分割cut pointの値範囲)
// =============================================================================
class Bucket 
{
	vector< vector<double> > _lower;   // 下限値
	vector< vector<double> > _upper;   // 上限値
	vector<int>              _bktSize; // 各次元の分割数

public:
	Bucket(vector<int>& bktSize);

	// dim次元のbktNoバケットの下限値,上限値を得る
	double lower(int dim, int bktNo) const { return _lower.at(dim).at(bktNo);}
	double upper(int dim, int bktNo) const { return _upper.at(dim).at(bktNo);}

	// dim次元のbktNoバケットの下限値,上限値をnumに設定する
	double lower(int dim, int bktNo, double num){ return _lower.at(dim).at(bktNo)=num;}
	double upper(int dim, int bktNo, double num){ return _upper.at(dim).at(bktNo)=num;}

	// 次元数を得る
	int dimSize(void)    const { return _bktSize.size(); }

	// dim次元のバケット数を得る
	int bktSize(int dim) const { return _bktSize.at(dim);}

	// dim次元のバケットについてvalの属するバケット番号を返す
	int getNo(int dim, double val);

	void operator=(Bucket bucket);

};
// -----------------------------------------------------------------------------
// Bucketのコンストラクタ：各軸の値は全て0番bucketとする．
// -----------------------------------------------------------------------------
Bucket::Bucket(vector<int>& bktSize)
{
	_lower.resize(bktSize.size());
	_upper.resize(bktSize.size());
	for(vector<int>::size_type i=0; i<bktSize.size(); i++){
		_bktSize.push_back(bktSize.at(i));
		_lower.at(i).resize(bktSize.at(i),0);
		_upper.at(i).resize(bktSize.at(i),0);
		_lower.at(i).at(0)=-DBL_MAX;
		_upper.at(i).at(0)= DBL_MAX;
	}
}
// -----------------------------------------------------------------------------
// dim次元のbucket範囲からvalの属するバケットを検索し返す
// -----------------------------------------------------------------------------
int Bucket::getNo(int dim, double val)
{
	int k;
	for(k=0; k<bktSize(dim)-1; k++){
		if( val<upper(dim,k) ){ break; }
	}
	return k;
}
// -----------------------------------------------------------------------------
// 代入演算子
// -----------------------------------------------------------------------------
void Bucket::operator=(Bucket bucket)
{
	for(int i=0; i<dimSize(); i++){
		for(int j=0; j<bktSize(i); j++){
			lower(i,j, bucket.lower(i,j));
			upper(i,j, bucket.upper(i,j));
		}
	}
}
// =============================================================================
// 各次元の値クラス
// =============================================================================
class Val {
	double      _num;   // 値
	int         _bktNo; // 割り当てられたバケット番号
	int         _cnt;   // この値を持つレコード件数

	// そのvalに対する他の次元の範囲cubeの累積件数
	vector<int> _slice;

public:
	Val(double num){ _num=num; _bktNo=0; _cnt=1;}
	void addCnt(int cnt){_cnt+=cnt;}
	int cnt(void){return _cnt;}
	double num(void){return _num;}
	void bktNo(int bktNo){_bktNo=bktNo;}
	void addCntSlice(int add,int cnt){ _slice.at(add)+=cnt; }
	void setCntSlice(int add,int cnt){ _slice.at(add) =cnt; }

	void initSlice(int dim, vector<int>& bktSize);
	void clearSlice(void);

	int  bktNo(void) 					const { return _bktNo;}
	int  sliceSize(void) 			const { return static_cast<int>(_slice.size());}
	int  getCntSlice(int add) const { return _slice.at(add); }

};
// -----------------------------------------------------------------------------
// スライスのサイズを計算しvector配列を確保する
// 対応する次元dimを除いたバケット総数
// -----------------------------------------------------------------------------
void Val::initSlice(int dim, vector<int>& bktSize)
{
	int nob=1;
	for(vector<int>::size_type i=0; i<bktSize.size(); i++){
		if(static_cast<int>(i)==dim) continue;
		nob*=bktSize.at(i);
	}
	_slice.resize(nob);
}
// -----------------------------------------------------------------------------
// スライスのクリア
// -----------------------------------------------------------------------------
void Val::clearSlice(void)
{
	for(vector<int>::size_type i=0; i<_slice.size(); i++){
		_slice[i]=0;
	}
}
// =============================================================================
// CubeのCell　クラス
// =============================================================================
class Cell 
{
	vector<Val*> _val; // _indexへのポインタ
	int          _cnt; // そのセルの件数
	vector<int>  _bkt; // そのセルのバケット番号配列

public:
	Cell(int dim){ _val.resize(dim); _cnt=1;}
	void addVal(int dim, Val* val){ _val[dim]=val; }
	void addCnt(int cnt){_cnt+=cnt;}
	vector<int> bkt(void);

	int valSize(void)	const {return _val.size();}
	Val* val(int i)		const {return _val.at(i);}
	int cnt(void) 		const {return _cnt;}

};
// -----------------------------------------------------------------------------
// _index値取得
// -----------------------------------------------------------------------------
vector<int> Cell::bkt(void)
{
	vector<int> b;
	for(vector<Val*>::size_type i=0; i<_val.size(); i++){
		b.push_back(_val.at(i)->bktNo());
	}
	return b;
}
// =============================================================================
// 比較関数オペレーター
// =============================================================================
struct cmpCell
{
  bool operator()( const Cell* c1,  const Cell* c2) const {
		for(int i=0; i<c1->valSize(); i++){
    	     if ( c1->val(i) < c2->val(i) ) return true;
    	else if ( c1->val(i) > c2->val(i) ) return false;
		}
    return false;
  }
};
// =============================================================================
// Cubeクラス
// =============================================================================
class Cube 
{
	int _dimSize;       // 次元数
	set<Cell*,cmpCell > _cell; // セル
	vector< map<double,Val*> > _index; // 各次元(外側)のval(内側)へのポインタ
	map<double,Val*>::const_iterator _idx_i; // _index専用iterator

public:
	Cube(int dimSize){_dimSize=dimSize;_index.resize(dimSize);}
	~Cube(void);
	Val* findVal(int dim, double val);
	Val* insVal(int dim, double val);
	int  cntCell(void){return _cell.size();}
	int  indexSize(int dim){ return _index[dim].size();}
	const map<double,Val*>& index(int dim) const { return _index[dim]; }
	void addCell(vector<double>&);
	vector<int> adjustBktSize(vector<int>& bktSize);
	void updBktNo(int dim, Bucket& bucket);
	void updSlice(vector<int>& bktSize);
	void initSlice(vector<int>& bktSize);
	double calTotalVar(vector<int>& bktSize);

};
// -----------------------------------------------------------------------------
// デストラクタ
// -----------------------------------------------------------------------------
Cube::~Cube(void)
{
	// スマートポインタに変更すること
	for(vector< map<double,Val*> >::size_type i=0; i<_index.size(); i++){
		for(_idx_i=_index[i].begin(); _idx_i!=_index[i].end(); _idx_i++){
			delete _idx_i->second;
		}
	}
}
// -----------------------------------------------------------------------------
// 2乗和集計
// -----------------------------------------------------------------------------
double Cube::calTotalVar(vector<int>& bktSize)
{
	int nob=1;
	for(vector<int>::size_type i=0; i<bktSize.size(); i++){
		nob*=bktSize.at(i);
	}
	vector<int> rCube(nob);

	// Cube上の全セルで回し全スライスに件数をセット
	for( set<Cell*,cmpCell>::const_iterator si=_cell.begin(); si!=_cell.end(); si++ ){
		Cell* cell=*si;
		// セルが属するバケット(各次元のバケット番号vector)
		vector<int> bkt=cell->bkt();
		rCube[ calAddress(bkt,bktSize) ]+= cell->cnt();
	}
	double sqSum=0;
	for(vector<int>::size_type i=0; i<rCube.size(); i++){
		sqSum+=static_cast<double>(rCube[i]) * static_cast<double>(rCube[i]);
	}
	return sqSum;
}
// -----------------------------------------------------------------------------
// 更新された範囲に従ってcubeに登録された次元dimの値vecotrのbkt番号を更新する.
// -----------------------------------------------------------------------------
void Cube::updSlice(vector<int>& bktSize)
{
	// sliceをクリアする
	for(vector< map<double,Val*> >::size_type i=0; i<_index.size(); i++){
		for(_idx_i=_index[i].begin(); _idx_i!=_index[i].end(); _idx_i++){
			_idx_i->second->clearSlice();
		}
	}
	// Cube上の全セルで回し全スライスに件数をセット
	for( set<Cell*,cmpCell>::const_iterator si=_cell.begin(); si!=_cell.end(); si++ ){
		Cell* cell=*si;
		// セルが属するバケット(各次元のバケット番号vector)
		vector<int> bkt=cell->bkt();
		for(vector< map<double,Val*> >::size_type i=0; i<_index.size(); i++){
			Val* targetVal=cell->val(i); // このvalのsliceを更新
			targetVal->addCntSlice( calSliceAddress(i,bkt,bktSize), cell->cnt() );
		}
	}
	// 次元ごとにsliceの累積値を計算する
	for(vector< map<double,Val*> >::size_type i=0; i<_index.size(); i++){
		map<double,Val*>::const_iterator prev_idx_i=_index[i].begin();
		for(_idx_i=_index[i].begin(); _idx_i!=_index[i].end(); _idx_i++){
			Val* prvVal=prev_idx_i->second;
			Val* curVal=    _idx_i->second;
			// 一段目は累積計算はなし
			if( prvVal==curVal ) continue;
			// sliceの各セルの累積
			for(int j=0; j<curVal->sliceSize(); j++){ // sliceの各セル
				int curCnt=curVal->getCntSlice(j);
				int prvCnt=prvVal->getCntSlice(j);
				curVal->setCntSlice(j,prvCnt+curCnt);
			}
			prev_idx_i=_idx_i;
		}
	}
}
// -----------------------------------------------------------------------------
// 更新された範囲に従ってcubeに登録された次元dimの値vecotrのbkt番号を更新する.
// -----------------------------------------------------------------------------
void Cube::initSlice(vector<int>& bktSize)
{
	for(vector< map<double,Val*> >::size_type i=0; i<_index.size(); i++){
		map<double,Val*>& index = _index[i];
		for(_idx_i=index.begin(); _idx_i!=index.end(); _idx_i++){
			Val* val=_idx_i->second;
			val->initSlice(i,bktSize);
		}
	}
}
// -----------------------------------------------------------------------------
// 更新された範囲に従ってcubeに登録された次元dimの値vecotrのbkt番号を更新する.
// -----------------------------------------------------------------------------
void Cube::updBktNo(int dim, Bucket& bucket){
	map<double,Val*>& index = _index[dim];
	int bktNo=0;
	double upper=bucket.upper(dim,bktNo);
	// bucketの範囲と突き合わせながら valのbktNoを更新していく
	for(_idx_i=index.begin(); _idx_i!=index.end(); _idx_i++){
		Val* val=_idx_i->second;
		// val->numが現在のbucket範囲より大きいならば次のbucketへ
		while(1){
			if(val->num() > upper){ upper=bucket.upper(dim,++bktNo);}
			else                  { break;}
		}
		val->bktNo(bktNo);
	}
}
// -----------------------------------------------------------------------------
// パラメータとして与えられた各次元のバケットサイズが
// 値の種類数より大きい時は，値の種類数に調整する．
// -----------------------------------------------------------------------------
vector<int> Cube::adjustBktSize(vector<int>& bktSize)
{
	vector<int> rtn(bktSize.size());
	for(vector<int>::size_type i=0; i<bktSize.size(); i++){
		if( bktSize.at(i) > static_cast<int>(_index.at(i).size()) ){
			rtn.at(i)=_index.at(i).size();
		}
		else{
			rtn.at(i) = bktSize.at(i) ;
		}
	}
	return rtn;
}
// -----------------------------------------------------------------------------
// dim次元にvalを挿入しそのvalアドレスを返す.
// 既に登録されていれば，そのvalアドレスを返す.
// -----------------------------------------------------------------------------
Val* Cube::insVal(int dim, double val)
{
	map<double,Val*>& index=_index.at(dim);
	_idx_i = index.find(val);
	if( _idx_i == index.end() ){
		Val* v=new Val(val);
		index[val]=v;
		_idx_i = index.find(val);
	}else{
		_idx_i->second->addCnt(1);
	}
	return _idx_i->second;
}
// -----------------------------------------------------------------------------
// vに従ってCellを生成してCubeに追加
// -----------------------------------------------------------------------------
void Cube::addCell( vector<double>& v )
{
	Cell* cell=new Cell(v.size());

	// Valベクトルに各軸の値クラス(Val)のアドレスをセットする
	for(vector<Val*>::size_type i=0; i<v.size(); i++){
		Val* vAdd=insVal(i,v[i]); // 次元iにv[i]をセットしアドレス取得
		cell->addVal(i,vAdd);
	}
	// Valベクトルが既にCellとして登録されていればcount up
	// さもなければ新規登録
	set<Cell*,cmpCell>::const_iterator si = _cell.find(cell);
	if( si == _cell.end() ){
		_cell.insert(cell);
	}else{
		delete cell;
		(*si)->addCnt(1);
	}
}
// -----------------------------------------------------------------------------
// 目的関数である分散(実際には各バケットの件数の二乗和)を求める
// -----------------------------------------------------------------------------
double calVar(vector<Val*>& val, int lower, int upper)
{
	vector<int> _slice; // そのvalに対する他の次元の範囲cubeの累積件数^2
	double sum=0;
	for(int i=0; i<val[upper]->sliceSize(); i++){
		int uCnt,lCnt;
		uCnt = val[upper  ]->getCntSlice(i);
		if(lower==0) { lCnt = 0; }
		else         { lCnt = val[lower-1]->getCntSlice(i); }
		sum += (static_cast<double>(uCnt-lCnt)*static_cast<double>(uCnt-lCnt));
	}
	return sum;
}
	//k-cluster table
struct DP 
{ 
	double var;  // 分散最小値
	int    prv;  // 分散最小となるh-1カットにおける
	int    from;
	int    to;
};
// -----------------------------------------------------------------------------
// bucket分割のSUB(動的計画法による最適bucket分割cutpointの探索)
// -----------------------------------------------------------------------------
double runDP( int dim, Bucket& bucket, Cube& cube )
{
	int bktSize=bucket.bktSize(dim); // 分割数
	int valSize=cube.indexSize(dim); // 値の種類数
	// dpTableの領域確保 valSize×bktSizeの二次元配列
	vector< vector<DP> > dpTable;
	dpTable.resize(	bktSize );
	for(int bkt=0; bkt<bktSize; bkt++){
		dpTable[bkt].resize(valSize);
	}
	// define vector in order to access Val by number
	vector<Val*> val;
	const map<double,Val*>& idx=cube.index(dim);
	for(map<double,Val*>::const_iterator i=idx.begin(); i!=idx.end(); i++){
		val.push_back(i->second);
	}
	//分割数１の場合の計算
	for(int v=0; v<valSize; v++){
		dpTable[0][v].var  = calVar(val, 0, v);
		dpTable[0][v].prv  = 0;
		dpTable[0][v].from = 0;
		dpTable[0][v].to   = v;
	}
	//分割数２以上の場合の計算
	for(int cut=1; cut<bktSize; cut++){ //i=1で始まるのはk分割の1は配列の0に対応
		int prvCut=cut-1;
		for(int v=cut; v<valSize; v++){
			double minVar  = DBL_MAX;
			int minPrv  = 0;
			int minFrom = 0;
			int minTo   = 0;
			for(int g=prvCut; g<v; g++){
				double var = dpTable[cut-1][g].var + calVar(val,g+1,v);
				//ここの不等式を>にすれば、同じ件数の場合に後を多くする
				//ここの不等式を>=にすれば、同じ件数の場合に前を多くする
				if( minVar > var ){
					minVar  =var;
					minPrv  =g;
					minFrom =g+1;
					minTo   =v;
				}
			}
			dpTable[cut][v].var  = minVar;
			dpTable[cut][v].prv  = minPrv;
			dpTable[cut][v].from = minFrom;
			dpTable[cut][v].to   = minTo;
		}
	}
	// 最適解から分割範囲をbucketにセットする
	DP& dp=dpTable[bktSize-1][valSize-1];
	for( int bkt=bktSize-1; bkt>=0; bkt--){
		bucket.lower( dim, bkt, val[dp.from]->num() );
		bucket.upper( dim, bkt, val[dp.to  ]->num() );
		if(bkt>0) dp=dpTable[bkt-1][dp.prv];
	}
	//fromとtoの中点をカットポイントとしてセットする
	for(int bkt=0; bkt<bktSize; bkt++){
		double lw,up;
		up=bucket.upper(dim,bkt  );
		if(bkt!=bktSize-1){ lw=bucket.lower(dim,bkt+1); }
		else              { lw=bucket.upper(dim,bkt  ); }
		if(bkt!=0)        { bucket.lower( dim,bkt,bucket.upper(dim,bkt-1) );}
		bucket.upper( dim,bkt,(up+lw)/2 );
	}
	return dp.var;
}
// -----------------------------------------------------------------------------
// bucket分割の本体(動的計画法による最適bucket分割cutpointの探索)
// -----------------------------------------------------------------------------
Bucket calCutPoint( Cube& cube, vector<int>& bktSize, bool multiStart )
{
	double optVar=DBL_MAX;
	Bucket optBucket(bktSize);
	int iterEnd=1;
	if(multiStart) iterEnd=bktSize.size();
	for(int iter=0; iter<iterEnd; iter++){
		// マルチスタートのメッセージ
		if(iterEnd>1) cerr << "iteration #" << iter << " on multi-start" << endl;

		// バケットの範囲を初期化
		Bucket bucket(bktSize);
		for(vector<int>::size_type i=0; i<bktSize.size(); i++){
			cube.updBktNo(i,bucket);
		}

		// 最小値を見つけるため繰り返す
		double minVar=DBL_MAX;
		double var=0;
		while(1){
			bool updated=false; // 分散更新フラグ
			// 更新された範囲に従ってcubeに登録された値vecotrの範囲番号を更新する.
			cerr << "calculating on dimension ...";
			for(int i=iter; i<iter+bucket.dimSize(); i++){	
				int dim=i%bucket.dimSize();
				cerr << " #" << dim;
				cube.updSlice(bktSize);
				var = runDP(dim,bucket,cube);
				cube.updBktNo(dim,bucket);
			}

			var=cube.calTotalVar(bktSize);
			cerr << " done. VAR=" << var;
			if(var<minVar){
				minVar=var;
				updated=true;
			}
			if(var<optVar){
				optVar=var;
				optBucket=bucket;
				cerr << " updated!" << endl;
			}else{
				cerr << endl;
			}
			// 更新されなかった，もしくは一次元分割の場合は終了
			if(!updated || bucket.dimSize()==1) break;
		}
	}
	return optBucket;
}
} ////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgMbucket::kgMbucket(void)
{
	_name    = "kgmbucket";
	_version = "###VERSION###";

	#include <help/en/kgmbucketHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgmbucketHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// パラメータセット＆入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgMbucket::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("f=,i=,o=,k=,O=,n=,F=,-ms,-r,bufcount=,-q",kgArgs::ALLPARAM);

	// 入出力ファイルオープン&バッファッサイズ設定
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);
	_oFile.setPrecision(_precision);
	kgstr_t s=_args.toString("bufcount=",false);
	int bcnt = 10;
	if(!s.empty()){ 
		bcnt = atoi(s.c_str());
		if(bcnt<=0){ bcnt=1;}
	}
	kgstr_t rFile = _args.toString("O=",false);
	if(rFile.empty()){ _rangefile=false; }
	else {
		_rangefile=true;
		_rFile.open(rFile,_env,_nfn_o,_rp);
		_rFile.setPrecision(_precision);
	}		
	_iFile.setbufsize(bcnt);
	_iFile.read_header();

	// f= 項目引数のセット
	vector< vector<kgstr_t> > vvs = _args.toStringVecVec("f=",':',2,true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// n= 分割数のセット(2以上)
	vector<kgstr_t> vs_n =_args.toStringVector("n=",true);
	for(vector<kgstr_t>::size_type i=0; i<vs_n.size();i++){
		int cnt = atoi(vs_n[i].c_str());
		if(cnt < 2){
			throw kgError("the number of buckets (n=) must be greater than 2");
		}
		_bktSize.push_back(cnt);			
	}

	// F=出力タイプ(0 or 1 or 2)
	kgstr_t F_s = _args.toString("F=",false);
	if(F_s.empty()) { _out_type=0;}
	else						{ _out_type = atoi(F_s.c_str()); }
	if(_out_type>2 && _out_type<0){
		throw kgError("F= parameter must take 0,1 or 2)");
	}

	// -r:逆順でバケット番号をふる,-ms:マルチスタート
	_reverse = _args.toBool("-r");
	_multiStart = _args.toBool("-ms");
	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }

	if(!seqflg && !vs.empty()){ sortingRun(&_iFile,vs);}

	_kField.set(vs,  &_iFile,_fldByNum);
	_fField.set(vvs, &_iFile,_fldByNum);

	// n=パラメータに指定された値が一つであれば，全ての項目の分割数を
	// この値にする．
	if(_bktSize.size()==1){
		for(vector<kgstr_t>::size_type i=1; i<_fField.size(); i++){
			_bktSize.push_back(_bktSize.at(0));			
		}
	}
	if(_fField.size() != _bktSize.size()){
		throw kgError("the number of arguments on f= and n= must be same");
	}


}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgMbucket::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力&範囲ファイルの項目名の出力
	// キー項目,fieldName,bucketNo,rangeFrom,rangeTo
	// キー項目(なければ出	なし),対象項目名,バケット番号,開始範囲,終了範囲
  _oFile.writeFldName(_iFile,_fField, true);
	if(_rangefile){
		if(!_rFile.noFldName()){
			// key項目名の出力
		  int size=_kField.size();
  		if(size>0){
				for(int i=0; i<size; i++){
					kgstr_t oName=_kField.name(i); // second項目名がない時
					_rFile.writeStr( oName.c_str(), false);
				}
  		}
			// key項目以外の項目名は以下の通り固定項目名
			_rFile.writeStr("fieldName",false);
			_rFile.writeStr("bucketNo" ,false);
			_rFile.writeStr("rangeFrom",false);
			_rFile.writeStr("rangeTo"  );
			_rFile.writeEolNC();
		}
	}

	while(_iFile.blkset()!=EOF){
		Cube cube(_fField.size());
		// 指定された値ベクトルとその出現回数のCubeを作成
		while(_iFile.blkread() != EOF){
			vector<double> valtmp(_fField.size());
			bool nullFlg=false;
			for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
				char* str=_iFile.getBlkVal(_fField.num(i));
				if(*str=='\0'){ // null値判定
					if(_assertNullIN) { _existNullIN  = true;}
					nullFlg=true;
					break;
				}
				valtmp[i]=atof(_iFile.getBlkVal(_fField.num(i)));
			}
			if(!nullFlg) cube.addCell(valtmp);
		}
		// データが一件もなかった場合はnull出力
		if(cube.cntCell()==0){ 
			_iFile.seekBlkTop();
			while(_iFile.blkread() != EOF){
				_oFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld(),false);
				for(vector<kgstr_t>::size_type i=0; i<_fField.size()-1; i++){
					_oFile.writeStr("", false);
				}
				_oFile.writeStr("", true);
			}	
			if(_assertNullOUT){ _existNullOUT = true;}
		}else{
			
			// 指定のバケット分割数が値の種類数より少ない時は調整する
			vector<int> adjbktSize =  cube.adjustBktSize(_bktSize);

			// スライスの初期化(領域確保)
			cube.initSlice(adjbktSize);

			// バケット(結果)の初期化(領域確保)
			Bucket bucket(adjbktSize);

			// bucketのカットポイントを計算
			bucket=calCutPoint( cube, adjbktSize, _multiStart );

			// 範囲ファイルの出力
			if(_rangefile){
				for(int h=0; h<bucket.dimSize(); h++){
					for(int j=0; j<bucket.bktSize(h); j++){
						for(unsigned int k=0; k<_kField.size(); k++){
							_rFile.writeStr(_iFile.getOldVal(_kField.num(k)),false);
						}
						_rFile.writeStr(_fField.name(h).c_str(),false);
						if(_reverse){ _rFile.writeInt(bucket.bktSize(h)-j,false); }
						else        { _rFile.writeInt(j+1                ,false); }

						if(j==0){ // 最初のバケットのlowerは出力しない
							_rFile.writeStr("",false);
						}else{
							_rFile.writeDbl(bucket.lower(h,j),false);
						}

						if(j==bucket.bktSize(h)-1){ // 最後のバケットのupperは出力しない
							_rFile.writeStr("",true);
						}else{
							_rFile.writeDbl(bucket.upper(h,j),true);
						}
					}
				}
			}
			//	出力処理
			_iFile.seekBlkTop();
			while(_iFile.blkread() != EOF){
				_oFile.writeFld(_iFile.fldSize(),_iFile.getBlkFld(),false);
				// 各次元に一つでもnullがあるかどうかチェック
				// (一つでもnullならばnull出力するため)
				bool nullFlg=false;
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					char* str = _iFile.getBlkVal(_fField.num(i));
					if(*str=='\0'){
						if(_assertNullIN) { _existNullIN  = true;}
						nullFlg=true;
						break;
					}
				}
				// null出力の場合
				if(nullFlg){
					for(vector<kgstr_t>::size_type i=0; i<_fField.size()-1; i++){
						_oFile.writeStr("", false);
					}
						_oFile.writeStr("", true);
					if(_assertNullOUT){ _existNullOUT = true;}
					continue;
				}
				for(vector<kgstr_t>::size_type i=0; i<_fField.size(); i++){
					// 最終項目かどうかを判定(改行出力のため)
					bool eol=false;
					if(i==_fField.size()-1) eol=true;

					// 次元iの対象となる値(文字列として)
					char* str = _iFile.getBlkVal(_fField.num(i));

					// 次元iの値atof(str)が属するバケット番号を検索
					int bktNo=bucket.getNo(i, atof(str));

					// ##### バケット番号で出力
					if(_out_type==0){
						if(_reverse) { _oFile.writeInt(bucket.bktSize(i)-bktNo,eol);}
						else         { _oFile.writeInt(bktNo+1                ,eol);}
					// ##### 範囲で出力
					}else if(_out_type==1){
						if(bktNo!=0){ // 最初のバケットのlowerは出力しない
							_oFile.writeDbl( bucket.lower(i,bktNo) );
						}
						_oFile.writeStr( "_" );
						if(bktNo!=bucket.bktSize(i)-1){ // 最後のバケットのupperは出力しない
							_oFile.writeDbl( bucket.upper(i,bktNo), eol );
						}else{
							_oFile.writeStr("",eol);
						}
					// ##### バケット番号+範囲で出力
					}else{
						if(_reverse) _oFile.writeInt(bucket.bktSize(i)-bktNo);
						else         _oFile.writeInt(bktNo+1                );
						_oFile.writeStr( ":" );
						if(bktNo!=0){ // 最初のバケットのlowerは出力しない
							_oFile.writeDbl( bucket.lower(i,bktNo) );
						}
						_oFile.writeStr( "_" );
						if(bktNo!=bucket.bktSize(i)-1){ // 最後のバケットのupperは出力しない
							_oFile.writeDbl( bucket.upper(i,bktNo), eol );
						}else{
							_oFile.writeStr("",eol);
						}
					}
				}
			}
		}	
	}
	//ASSERT keynull_CHECK
	if(_assertNullKEY) { _existNullKEY = _iFile.keynull(); }
	// 終了処理(メッセージ出力,thread pipe終了通知)
	th_cancel();
	_iFile.close();
	_oFile.close();
	_rFile.close();
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
