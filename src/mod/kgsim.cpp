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
// kgsim.cpp 項目間類似度計算クラス
// =============================================================================
#include <cstdio>
#include <sstream>
#include <kgConfig.h>
#include <cfloat>
#include <map>
#include <kgsim.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgCSVout.h>
#include <kgVal.h>

using namespace std;
using namespace kglib;
using namespace kgmod;

// -----------------------------------------------------------------------------
// 二変数間関数
// -----------------------------------------------------------------------------
namespace {
	// ---------------------------------------------------------------------------
	// ピアソンの積率相関係数
	// ---------------------------------------------------------------------------
	kgVal pearson(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double sx=0,sy=0,sxx=0,syy=0,sxy=0,cnt=0;

		while(csv.blkread() != EOF){
			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}

			double dx = atof(str0)-sx;
   		double dy = atof(str1)-sy;
			sx += dx / (cnt+1); 
			sy += dy / (cnt+1); 
			sxx += cnt * dx * dx / (cnt+1); 
			syy += cnt * dy * dy / (cnt+1); 
			sxy += cnt * dx * dy / (cnt+1); 
			cnt+=1;
		}

		if(cnt > 1) { 
			sxx = sqrt(sxx / (cnt-1)); 
			syy = sqrt(syy / (cnt-1)); 
			if(sxx != 0 && syy !=0){ result.r(sxy/((cnt-1) * sxx * syy) ); }
			else                   { result.null(true); }
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// 共分散
	// ---------------------------------------------------------------------------
	kgVal covar(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double sx=0,sy=0,sxy=0,cnt=0;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}

			double dx = atof(str0)-sx;
   		double dy = atof(str1)-sy;
			sx += dx / (cnt+1); 
			sy += dy / (cnt+1); 
			sxy += cnt * dx * dy / (cnt+1); 
			cnt+=1;

		}

		if(cnt > 1) { result.r( sxy/(cnt) );}
		else				{ 
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// 共分散(不偏推定)
	// ---------------------------------------------------------------------------
	kgVal ucovar(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double sx=0,sy=0,sxy=0,cnt=0;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}
			double dx = atof(str0)-sx;
   		double dy = atof(str1)-sy;
			sx += dx / (cnt+1); 
			sy += dy / (cnt+1); 
			sxy += cnt * dx * dy / (cnt+1); 
			cnt+=1;

		}

		if(cnt > 1) { result.r( sxy/(cnt-1) );}
		else				{ 
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}

	// ---------------------------------------------------------------------------
	// 件数と平均ランク クラス
	// ---------------------------------------------------------------------------
	class CntRank 
	{
		double _cnt;     // 件数
		double _rank; // 平均ランク

	public:

		CntRank(void) : _cnt(0), _rank(0){}
		void rank(double rank){_rank=rank;}
		double rank(void){return _rank;}
		double cnt(void) {return _cnt;}
		void operator++(void){
			_cnt+=1;
		}

	};

	// ---------------------------------------------------------------------------
	// スピアマンの順位相関係数
	// ti : x変量のi個目の同一順位の件数
	// tj : y変量のj個目の同一順位の件数
	// r=(Tx+Ty-Σdi^2)/(2*sqrt(TxTy))
	// Tx={ (cnt^3-cnt)-Σ(ti^3-ti) }/12
	// Ty={ (cnt^3-cnt)-Σ(tj^3-tj) }/12
	// 参考URL http://aoki2.si.gunma-u.ac.jp/lecture/Soukan/spearman.html
	// ---------------------------------------------------------------------------
	kgVal spearman(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double cnt=0;
		map<double,CntRank> map0;
		map<double,CntRank> map1;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}

			double dx = atof(str0);
   		double dy = atof(str1);
			++map0[dx];
			++map1[dy];
			cnt+=1;

		}

		// 同一ランクについて平均ランクを求める
		double rank=0;
		for(map<double,CntRank>::iterator i=map0.begin(); i!=map0.end(); i++){

			double c=i->second.cnt();
			i->second.rank(rank+(c+1.0)/2.0);
			rank+=c;

		}

		rank=0;

		for(map<double,CntRank>::iterator i=map1.begin(); i!=map1.end(); i++){
			double c=i->second.cnt();
			i->second.rank(rank+(c+1.0)/2.0);
			rank+=c;
		}

		//Tx,Tyの計算
		double tx=0;

		for(map<double,CntRank>::iterator i=map0.begin(); i!=map0.end(); i++){
			double c=i->second.cnt();
			if(c>1) tx+=c*c*c-c;
		}

		double ty=0;

		for(map<double,CntRank>::iterator i=map1.begin(); i!=map1.end(); i++){
			double c=i->second.cnt();
			if(c>1) ty+=c*c*c-c;
		}

		tx=((cnt*cnt*cnt-cnt)-tx)/12;
		ty=((cnt*cnt*cnt-cnt)-ty)/12;

		// Σdi^2の計算
		double sum=0;
		csv.seekBlkTop();

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0') continue;

			CntRank& dx= map0[atof(str0)];
			CntRank& dy= map1[atof(str1)];
			sum += (dx.rank()-dy.rank())*(dx.rank()-dy.rank());

		}

		if(cnt>1 && tx>0 && ty>0) { result.r((tx+ty-sum)/(2*sqrt(tx*ty)));}
		else											{ 
			result.null(true); 
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// ケンドールの順位相関係数
	// r=((ΣPij-ΣQij)/2)/(sqrt((cnt^2-cnt)/2-Tx)sqrt((cnt^2-cnt)/2-Ty))
	// xi>xj & yi>yj のときPij=1 (i!=j)
	// xi<xj & yi<yj のときPij=1 (i!=j)
	// xi>xj & yi<yj のときQij=1 (i!=j)
	// xi<xj & yi>yj のときQij=1 (i!=j)
	// ti : x変量のi個目の同一順位の件数
	// tj : y変量のj個目の同一順位の件数
	// Tx=Σ(ti^2-ti)/2
	// Ty=Σ(tj^2-tj)/2
	// 参考URL http://aoki2.si.gunma-u.ac.jp/lecture/Soukan/spearman.html
	// ---------------------------------------------------------------------------
	kgVal kendall(kgCSVblk& csv1, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

	// 集計用変数領域確保＆初期化
		double cnt=0;
		double tx=0;
		double ty=0;

		{
			map<double,CntRank> map0;
			map<double,CntRank> map1;

			//ファイルオープン
			kgCSVout csv2;
			csv2.open(tmpfName2, NULL, true);

			while(csv1.blkread() != EOF){

				csv2.writeFld(csv1.fldSize(),csv1.getBlkFld());
				char* str0=csv1.getBlkVal(fld.num(x));
				char* str1=csv1.getBlkVal(fld.num(y));

				// データがnullの場合は何もしない
				if(*str0=='\0' || *str1=='\0'){
					if(a_Nin){ *e_Nin =true ;}
					if(nullF) { cnt = 0; break; }
					continue;
				}

				double dx = atof(str0);
				double dy = atof(str1);
				++map0[dx];
				++map1[dy];
				cnt+=1;

			}

			csv2.close();

			//Tx,Tyの計算
			for(map<double,CntRank>::iterator i=map0.begin(); i!=map0.end(); i++){

				double c=i->second.cnt();
				if(c>1) { tx+=(c*c-c)/2.0; }

			}

			for(map<double,CntRank>::iterator i=map1.begin(); i!=map1.end(); i++){

				double c=i->second.cnt();
				if(c>1) ty+=(c*c-c)/2.0;

			}

		}

		kgCSVfld csv2;
		csv2.open(tmpfName2,NULL,true);
		csv2.read_header();

		double pSum=0;
		double qSum=0;
		csv1.seekBlkTop();

		while(csv1.blkread() != EOF){

			char* str1x=csv1.getBlkVal(fld.num(x));
			char* str1y=csv1.getBlkVal(fld.num(y));
			csv2.seekTop();

			while( EOF != csv2.read() ){

				char* str2x=csv2.getVal(fld.num(x));
				char* str2y=csv2.getVal(fld.num(y));
				double d1x=atof(str1x);
				double d1y=atof(str1y);
				double d2x=atof(str2x);
				double d2y=atof(str2y);

				     if(d1x>d2x && d1y>d2y) pSum+=1;
				else if(d1x<d2x && d1y<d2y) pSum+=1;
				else if(d1x>d2x && d1y<d2y) qSum+=1;
				else if(d1x<d2x && d1y>d2y) qSum+=1;

			}

		}

		csv2.close();

		if(cnt>1) { 

			double nn=(cnt*cnt-cnt)/2.0;
			if(nn!=tx && nn!=ty){
				result.r( ((pSum-qSum)/2.0)/(sqrt(nn-tx)*sqrt(nn-ty)) );
			}else{
				result.null(true);
			if(a_Nout) {*e_Nout=true;}
			}

		}else{

			result.null(true);
			if(a_Nout) {*e_Nout=true;}

		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// 都市ブロック距離
	// ---------------------------------------------------------------------------
	kgVal cityblock(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double dis=0;
		int cnt=0;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}

			double dx = atof(str0);
   		double dy = atof(str1);
			dis+=fabs(dx-dy);
			cnt++;

		}

		if(cnt > 0)	{ result.r(dis);}
		else				{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// ユークリッド距離
	// ---------------------------------------------------------------------------
	kgVal euclid(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double sum=0;
		int cnt=0;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}
			double dx = atof(str0);
   		double dy = atof(str1);
			sum+=(dx-dy)*(dx-dy);
			cnt++;

		}

		if(cnt > 0) { result.r(sqrt(sum));}
		else				{ 
			result.null(true); 
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// コサイン
	// ---------------------------------------------------------------------------
	kgVal cosine(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double xy=0,xx=0,yy=0;
		int cnt=0;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue;
			}

			double dx = atof(str0);
   		double dy = atof(str1);
			xy+=dx*dy;
			xx+=dx*dx;
			yy+=dy*dy;
			cnt++;

		}

		if(cnt > 0) {

			if(xx != 0 && yy !=0)  result.r(xy/sqrt(xx * yy));
			else                   result.null(true);

		}else{

			result.null(true);
			if(a_Nout) {*e_Nout=true;}

		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// ハミング距離
	// ---------------------------------------------------------------------------
	kgVal hamming(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		// 集計用変数領域確保＆初期化
		double dis=0;
		double cnt=0;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF) { cnt = 0; break; }
				continue; 
			}
			
			if(strcmp(str0,str1)!=0){ dis+=1;}
			cnt++;

		}

		if(cnt > 0) { result.r(dis/cnt);}
		else				{ 
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}
	// ---------------------------------------------------------------------------
	//2×2分割表クラス
	//     b   nb
	//  a c11 c10 c1x
	// na c01 c00 c0x
	//    cx1 cx0 cxx
	struct Matrix01 
	{
		double c00,c01,c10,c11;
		double c0x,c1x,cx0,cx1;
		double cxx;
		double p_a,p_b,p_na,p_nb;
		double p_ab,p_nanb,p_nab,p_anb,p_nabn;
		double cp_anb,cp_ab,cp_nanb,cp_nab;
		double cp_bna,cp_ba,cp_nbna,cp_nba;

		Matrix01(void) :
		 c00(0),c01(0),c10(0),c11(0),c0x(0),c1x(0),cx0(0),cx1(0),cxx(0),
		 p_a(0),p_b(0),p_na(0),p_nb(0),p_ab(0),p_nanb(0),p_nab(0),p_anb(0),
		 p_nabn(0),cp_anb(0),cp_ab(0),cp_nanb(0),cp_nab(0),
		 cp_bna(0),cp_ba(0),cp_nbna(0),cp_nba(0) {};

		void reset(void){
			c00 = c01 = c10 = c11 =0;
			c0x = c1x = cx0 = cx1 = cxx = 0;
			p_a = p_b = p_na = p_nb = p_ab = 0;
			p_nanb = p_nab = p_anb = p_nabn = cp_anb = cp_ab = 0;
			cp_nanb = cp_nab = cp_bna = cp_ba = cp_nbna = cp_nba = 0;
		}

		void sum(void){
			c0x=c00+c01; c1x=c10+c11;
			cx0=c00+c10; cx1=c01+c11;
			cxx=c0x+c1x;
		}

		void calProb(void){
			if(cxx>0){ p_a    =c1x/cxx;}
			if(cxx>0){ p_b    =cx1/cxx;}
			if(cxx>0){ p_na   =c0x/cxx;}
			if(cxx>0){ p_nb   =cx0/cxx;}
			if(cxx>0){ p_ab   =c11/cxx;}
			if(cxx>0){ p_nanb =c00/cxx;}
			if(cxx>0){ p_nab  =c01/cxx;}
			if(cxx>0){ p_anb  =c10/cxx;}
			if(cxx>0){ p_nabn =(cxx-c11)/cxx;}
			if(cx1>0){cp_ab   =c11/cx1;}
			if(cx1>0){cp_nab  =c01/cx1;}
			if(cx0>0){cp_anb  =c10/cx0;}
			if(cx0>0){cp_nanb =c00/cx0;}
			if(c1x>0){cp_ba   =c11/c1x;}
			if(c1x>0){cp_nba  =c10/c1x;}
			if(c0x>0){cp_bna  =c01/c0x;}
			if(c0x>0){cp_nbna =c00/c0x;}
		}

	};

	// csvからデータを読み込み2×2分割表を作成し返す
	Matrix01 calMatrix01(kgCSVblk& csv, kgArgFld& fld, int x, int y,bool nullF,bool a_Nin ,bool* e_Nin )
	{
		struct Matrix01 mtx;

		while(csv.blkread() != EOF){

			char* str0=csv.getBlkVal(fld.num(x));
			char* str1=csv.getBlkVal(fld.num(y));

			// データがnullの場合は何もしない
			if(*str0=='\0' || *str1=='\0'){
				if(a_Nin){ *e_Nin =true ;}
				if(nullF){ mtx.reset(); break; }
				continue;
			}

			// データが1文字以上の場合は何もしない
			if(*(str0+1)!='\0' || *(str1+1)!='\0') continue;

			if(*str0=='0'){

			       if(*str1=='0') mtx.c00++;
				else if(*str1=='1') mtx.c01++;
				else                continue;

			}else if(*str0=='1'){

			       if(*str1=='0') mtx.c10++;
				else if(*str1=='1') mtx.c11++;
				else                continue;

			}else{

				continue;

			}

		}

		mtx.sum();
		mtx.calProb();

		return mtx;

	}
	// ---------------------------------------------------------------------------
	// support
	// ---------------------------------------------------------------------------
	kgVal support(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0) { result.r(mtx.c11/mtx.cxx);}
		else						{ 
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// lift
	// ---------------------------------------------------------------------------
	kgVal lift(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0 && mtx.c1x > 0 &&  mtx.cx1 >0){
			result.r((mtx.c11 * mtx.cxx)/(mtx.c1x * mtx.cx1));
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}

	// ---------------------------------------------------------------------------
	// chi
	// ---------------------------------------------------------------------------
	kgVal chi(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if( (mtx.c11+mtx.c01)>0 && 
			  (mtx.c00+mtx.c10)>0 &&
			  (mtx.c11+mtx.c10)>0 &&
			  (mtx.c00+mtx.c01)>0 ){

			result.r(( mtx.cxx                         *
			          (mtx.c11*mtx.c00-mtx.c10*mtx.c01)*
			          (mtx.c11*mtx.c00-mtx.c10*mtx.c01) )
			         /
			         ((mtx.c11+mtx.c01)*
			          (mtx.c00+mtx.c10)*
			          (mtx.c11+mtx.c10)*
			          (mtx.c00+mtx.c01) ) );

		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// jaccard係数
	// ---------------------------------------------------------------------------
	kgVal jaccard(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0 && mtx.c11>0){
			result.r(mtx.c11/(mtx.c11+mtx.c01+mtx.c10));
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// confidence
	// ---------------------------------------------------------------------------
	kgVal confidence(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.c1x==0){
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}else{
			result.r(mtx.cp_ba);
		}  
		return result;

	}
	// ---------------------------------------------------------------------------
	// conviction 
	// ---------------------------------------------------------------------------
	kgVal conviction(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);


		if(mtx.cxx > 0){
			result.r(mtx.p_a*mtx.p_nb/mtx.p_anb);
		}
		else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}

	// ---------------------------------------------------------------------------
	// phi係数
	// ---------------------------------------------------------------------------
	kgVal phi(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{

		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0 && mtx.c0x>0 && mtx.c1x>0 && mtx.cx1>0 && mtx.cx0>0){

			result.r((mtx.c11*mtx.c00-mtx.c10*mtx.c01)/
			         sqrt(mtx.c0x*mtx.c1x*mtx.cx1*mtx.cx0));

		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// Odds ratio
	// ---------------------------------------------------------------------------
	kgVal oddsRatio(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){
			if(mtx.p_anb==0 || mtx.p_nab==0){
				result.r(DBL_MAX);
			}else{
				result.r((mtx.p_ab*mtx.p_nanb)/(mtx.p_anb*mtx.p_nab));
			}
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}  

		return result;

	}
	// ---------------------------------------------------------------------------
	// Yule's Q
	// ---------------------------------------------------------------------------
	kgVal yuleQ(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{

		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){
			if(mtx.p_anb==0 || mtx.p_nab==0){
				result.r(1);
			}else{
				double alpha=(mtx.p_ab*mtx.p_nanb)/(mtx.p_anb*mtx.p_nab);
				result.r((alpha-1)/(alpha+1));
			}
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// Yule's Y
	// ---------------------------------------------------------------------------
	kgVal yuleY(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{

		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){
			if(mtx.p_anb==0 || mtx.p_nab==0){

				result.r(1);

			}else{

				double alpha=(mtx.p_ab*mtx.p_nanb)/(mtx.p_anb*mtx.p_nab);
				result.r((sqrt(alpha)-1)/(sqrt(alpha)+1));

			}

		}else{

			result.null(true);
			if(a_Nout) {*e_Nout=true;}

		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// Kappa
	// ---------------------------------------------------------------------------
	kgVal kappa(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){
			if(mtx.p_anb==0 || mtx.p_nab==0){
				result.r(1);
			}else{
				double bunbo=1-mtx.p_a*mtx.p_b-mtx.p_na*mtx.p_nb;
				if(bunbo==0){
					result.r(DBL_MAX);
				}else{
					double bunsi=mtx.p_ab+mtx.p_nanb-mtx.p_a*mtx.p_b-mtx.p_na*mtx.p_nb;
					result.r(bunsi/bunbo);
				}
			}
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}
		return result;
	}



	// ---------------------------------------------------------------------------
	// Conviction max
	// ---------------------------------------------------------------------------
	kgVal convMax(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');

		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){

			double convab=mtx.p_a*mtx.p_nb/mtx.p_anb;
			double convba=mtx.p_b*mtx.p_na/mtx.p_nab;
			if(convab>convba){ result.r(convab);}
			else             { result.r(convba);}

		}else{

			result.null(true);
			if(a_Nout) {*e_Nout=true;}

		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// Conviction min
	// ---------------------------------------------------------------------------
	kgVal convMin(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');
		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){

			double convab=mtx.p_a*mtx.p_nb/mtx.p_anb;
			double convba=mtx.p_b*mtx.p_na/mtx.p_nab;

			if(convab<convba) { result.r(convab);}
			else              { result.r(convba);}

		}else{

			result.null(true);
			if(a_Nout) {*e_Nout=true;}

		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// Confidence max
	// ---------------------------------------------------------------------------
	kgVal confMax(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');
		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){
			if(mtx.c1x==0 || mtx.cx1==0){
				result.null(true);
				if(a_Nout) {*e_Nout=true;}
			}else{
				if(mtx.cp_ab>mtx.cp_ba){ result.r(mtx.cp_ab);}
				else                   { result.r(mtx.cp_ba);}
			}
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}
	// ---------------------------------------------------------------------------
	// Confidence min
	// ---------------------------------------------------------------------------
	kgVal confMin(kgCSVblk& csv, kgArgFld& fld, int x, int y, kgstr_t& tmpfName2,bool nullF,bool a_Nin ,bool a_Nout ,bool* e_Nin ,bool* e_Nout )
	{
		kgVal result('N');
		struct Matrix01 mtx=calMatrix01(csv,fld,x,y,nullF,a_Nin,e_Nin);

		if(mtx.cxx > 0){
			if(mtx.c1x==0 || mtx.cx1==0){
				result.null(true);
				if(a_Nout) {*e_Nout=true;}
			}else{
				if(mtx.cp_ab<mtx.cp_ba){ result.r(mtx.cp_ab);}
				else                   { result.r(mtx.cp_ba);}
			}
		}else{
			result.null(true);
			if(a_Nout) {*e_Nout=true;}
		}

		return result;

	}

}//////////////////////////////////////////////////////////////////////////////////name sapce

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録)
// -----------------------------------------------------------------------------
kgSim::kgSim(void)
{
	_name    = "kgsim";
	_version = "###VERSION###";

	#include <help/en/kgsimHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgsimHelp.h>
	#endif

}
// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------

void kgSim::setArgs(void)
{
	// パラメータチェック
	_args.paramcheck("a=,f=,i=,o=,k=,c=,-d,bufcount=,-q,-n",kgArgs::ALLPARAM);

	// 入出力ファイルオープン
	_iFile.open(_args.toString("i=",false), _env,_nfn_i);
  _oFile.open(_args.toString("o=",false), _env,_nfn_o,_rp);

	kgstr_t s=_args.toString("bufcount=",false);
	int bcnt = 10;
	if(!s.empty()){ 
		bcnt = atoi(s.c_str());
		if(bcnt<=0){ bcnt=1;}
	}

	_iFile.setbufsize(bcnt);
  _oFile.setPrecision(_precision);
	_iFile.read_header();

	// a=　新項目名セット
	_vField = _args.toStringVector("a=",false);
	if(_vField.empty()){
		_vField.push_back("fld1");
		_vField.push_back("fld2");
	}else if(_vField.size()!=2){
		throw kgError("paraeter a= takes two field names or ommit them all.");
	}

	// f= 項目引数のセット
	vector<kgstr_t> vs_f = _args.toStringVector("f=",true);

	// k= 項目引数のセット
	vector<kgstr_t> vs = _args.toStringVector("k=",false);

	// 両方向から出すかどうかフラグ
	// 方向のある距離がしていされていれば後で強制的にtrueとなる
	_direction = _args.toBool("-d");

	// c= 計算方法のセット
	_c_types = _args.toStringVecVec("c=", ':', 2, true);
	for(std::size_t i=0; i<_c_types.at(0).size();i++){
		kgstr_t kw=_c_types.at(0).at(i);
	     	 if(kw=="covar"    ){_functions.push_back(&covar);    }
	  else if(kw=="ucovar"   ){_functions.push_back(&ucovar);    }
	  else if(kw=="pearson"  ){_functions.push_back(&pearson);  }
		else if(kw=="spearman" ){_functions.push_back(&spearman); }
		else if(kw=="kendall"  ){_functions.push_back(&kendall);  }
		else if(kw=="euclid"   ){_functions.push_back(&euclid);   }
		else if(kw=="cosine"   ){_functions.push_back(&cosine);   }
		else if(kw=="cityblock"){_functions.push_back(&cityblock);}
		else if(kw=="hamming"  ){_functions.push_back(&hamming);  }
		else if(kw=="support"  ){_functions.push_back(&support);  }
		else if(kw=="lift"     ){_functions.push_back(&lift);     }
		else if(kw=="phi"      ){_functions.push_back(&phi);      }
		else if(kw=="chi"      ){_functions.push_back(&chi);      }
		else if(kw=="jaccard"  ){_functions.push_back(&jaccard);  }
		else if(kw=="confMax"  ){_functions.push_back(&confMax);  }
		else if(kw=="confMin"  ){_functions.push_back(&confMin);  }
		else if(kw=="yuleQ"    ){_functions.push_back(&yuleQ);    }
		else if(kw=="yuleY"    ){_functions.push_back(&yuleY);    }
		else if(kw=="kappa"    ){_functions.push_back(&kappa);    }
		else if(kw=="oddsRatio"){_functions.push_back(&oddsRatio);}
		else if(kw=="convMax"  ){_functions.push_back(&convMax);  }
		else if(kw=="convMin"  ){_functions.push_back(&convMin);  }
		else if(kw=="confidence"){_functions.push_back(&confidence);  }	
		else if(kw=="conviction"){_functions.push_back(&conviction);  }
		else {
			ostringstream ss;
			ss << "unknown keyword: " << kw 
				<< ": c=covar|ucovar|pearson|spearman|kendall|euclid|cosine|cityblock|hamming|chi|phi|jaccard|lift|support" 
				<< "|confMax|confMin|yuleQ|yuleY|kappa|oddsRatio|convMax|convMin|confidence|conviction: "
				<< _c_type;
			throw kgError(ss.str());	
		}

	}

	for(std::size_t i=0; i<_c_types.at(1).size(); i++){
		kgstr_t str=_c_types.at(1).at(i);
		if(str.empty()) _names.push_back(_c_types.at(0).at(i));
		else            _names.push_back(str);
	}
	_null = _args.toBool("-n");

	bool seqflg = _args.toBool("-q");
	if(_nfn_i) { seqflg = true; }
	if(!seqflg && !vs.empty()){ sortingRun(&_iFile,vs);}
	_kField.set(vs,  &_iFile,_fldByNum);
	_fField.set(vs_f, &_iFile,_fldByNum);
	if(_fField.size()<2){
		throw kgError("f= takes two or more parameters");
	}


}
// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgSim::run(void) try 
{
	// パラメータセット＆入出力ファイルオープン
	setArgs();

	// 入力ファイルにkey項目番号をセットする．
	_iFile.setKey(_kField.getNum());

	// 項目名の出力
  if(!_nfn_o){
  	vector<kgstr_t> headval;
		for(size_t k=0; k < _kField.size(); k++){
			headval.push_back(_iFile.fldName(_kField.num(k),true));
		}
		for(std::size_t k=0; k<_vField.size(); k++){
			headval.push_back(_vField.at(k));
		}
		for(std::size_t k=0; k<_names.size(); k++){
			headval.push_back(_names.at(k));
		}
		_oFile.writeFldNameCHK(headval);
	}

	// kendall計算用ファイル名(グローバル変数)
	kgTempfile tempFile(_env);
	kgstr_t tmpfName2 = tempFile.create();

	// データ集計＆出力
	while(	_iFile.blkset()!=EOF){

		for(std::size_t i=0; i<_fField.size(); i++){

			int st= _direction ? 0 : i+1; // 方向のある類似度であれば正方行列を求める
			for(std::size_t j=st; j<_fField.size(); j++){

				// 結果出力
				for(std::size_t k=0; k<_kField.size(); k++){ // k=項目出力
					_oFile.writeStr(_iFile.getOldVal(_kField.num(k)),false);
				}

				// 対象項目名xとy
				_oFile.writeStr(_fField.name(i).c_str(),false);
				_oFile.writeStr(_fField.name(j).c_str(),false);

				// 計算の実行本体
				for(std::size_t k=0; k<_functions.size(); k++){

					bool retFlg=false;
					if(k==_functions.size()-1) retFlg=true;
					kgVal result = _functions.at(k)(_iFile,_fField,i,j,tmpfName2,_null,_assertNullIN,_assertNullOUT,&_existNullIN,&_existNullOUT);

					_oFile.writeVal(result,retFlg);
					_iFile.seekBlkTop();

				}

			}
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
