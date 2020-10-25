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
// kgmvstats.h 移動窓の統計量の算出クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgVal.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>
using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace
namespace kgmvsim_ {
	// =============================================================================
	// window集計クラス
	// =============================================================================
	class kgMvBase
	{
		protected:
		size_t  _skip;		
		size_t  _term;
		size_t  _fsize;
		bool 	  _filled; 

		size_t _spos;

		void pos_inc(){ _spos = (_spos+1) % _term; }

		public:
		kgMvBase(size_t skip,size_t term,size_t fsize)
			:_skip(skip),_term(term),_fsize(fsize),
			_filled(false),_spos(0){}

		bool isfilled(void){ return _filled;}

		size_t stocksize(void){ 
			if(_filled){ return _term;}
			else			 { return _spos;}
		}

	};
	// =============================================================================
	// window集計クラス（DOUBLE）
	// =============================================================================
	class kgMvBase_dbl :public kgMvBase
	{
		vector< vector<double> > _val;
		public:
		kgMvBase_dbl(size_t skip,size_t term,size_t fsize)
			:kgMvBase(skip,term,fsize),_val(fsize,vector<double>(term,0)){}

		void update(vector<double>& inp);
		void clear();

		double get(size_t i)						{ return _val.at(i).at(_spos); }
		double get(size_t i,size_t j)		{ return _val.at(i).at(j); }
		vector<double>& gets(size_t i)	{ return _val.at(i); }

	};
	// =============================================================================
	// window集計クラス（BOOL）
	// =============================================================================
	class kgMvBase_bool :public kgMvBase
	{
		vector< vector<bool> > _val;
		public:
		kgMvBase_bool(size_t skip,size_t term,size_t fsize)
			:kgMvBase(skip,term,fsize),_val(fsize,vector<bool>(term,false)){}

		void update(vector<bool>& inp);
		void clear();

		bool get(size_t i)					 { return _val.at(i).at(_spos); }
		vector<bool>& gets(size_t i) { return _val.at(i); }
	};
	// =============================================================================
	// 計算クラス (合計) 
	// =============================================================================
	class kgMvSum : public kgMvBase_dbl
	{
		vector<double> _sumary;

		public:	
		kgMvSum(size_t skip,size_t term,size_t fzize)
			:kgMvBase_dbl(skip,term,fzize),_sumary(fzize,0){}

		// 計算&初期化
		void calc(vector<double>& inp);
		void clear();

		double get_sum(size_t i){return _sumary.at(i);}

	};	
	// =============================================================================
	// 計算クラス (算術平均)
	// =============================================================================
	class kgMvMean : public kgMvSum
	{
		vector<double> _mean;
		public:	
		kgMvMean(size_t skip,size_t term,size_t fzize)
			:kgMvSum(skip,term,fzize),_mean(fzize,0){}

		// 計算&初期化
		void calc(vector<double>& inp);
		void clear();

		double get_mean(size_t i){return _mean.at(i);}

	};	
	// =============================================================================
	// 計算クラス (値ごとカウント)
	// =============================================================================
	class kgMvValCount : public kgMvBase_dbl
	{
		vector< map<double,int> > _vcount;
		public:	
		kgMvValCount(size_t skip,size_t term,size_t fzize)
			:kgMvBase_dbl(skip,term,fzize),_vcount(fzize){}

		// 集計&初期化
		void calc(vector<double>& inp);
		void clear();

		map<double,int>& get_valc(size_t i) { return _vcount[i]; }

	};	
	// =============================================================================
	// 計算クラス (Rank)
	// =============================================================================
	class kgMvRank : public kgMvValCount
	{
		vector< map<double,double> > _rank;
		public:	
		kgMvRank(size_t skip,size_t term,size_t fzize)
			:kgMvValCount(skip,term,fzize),_rank(fzize){}

		// 集計&初期化
		void calc(vector<double>& inp);
		void clear();

		double getRank(size_t i,double v){ return  _rank[i][v];}
	};		
	// =============================================================================
	// 計算クラス (True カウント)
	// =============================================================================
	class kgMvTrueCnt : public kgMvBase_bool
	{
		vector<double> _tcount;

		public:	
		kgMvTrueCnt(size_t skip,size_t term,size_t fzize)
			:kgMvBase_bool(skip,term,fzize),_tcount(fzize,0){}

		// 集計&初期化
		void calc(vector<bool>& inp);
		void clear();

		double get_tcnt(size_t i){return _tcount.at(i);}

	};	
	// =============================================================================
	// 計算クラス (BOOL Matrix)
	// =============================================================================
	class kgMvBoolMatrix : public kgMvBase_bool
	{
		vector<double> _matrix;

		public:	
		kgMvBoolMatrix(size_t skip,size_t term)
			:kgMvBase_bool(skip,term,2),_matrix(4,0){}

		// 集計&初期化
		void calc(vector<char*>& inp);
		void clear();

		double getMat(int x ,int y);
		double getMatP(int x,int y,int x_D,int y_D);
	};
	// ============================================================================
	// SIM関数関連クラス
	// ============================================================================
	class kgMvSimFunc{
		public:
		virtual void calc(kgVal &rls,vector<char*>& inp)=0;
		virtual void clear()=0;
		virtual size_t stocksize()=0;
	};
	// ============================================================================
	// SIM関数 :: COVAR
	// ============================================================================
	class kgMvSimFunc_Covar : public kgMvSimFunc
	{
		kgMvMean _data; 

		public:
		kgMvSimFunc_Covar(size_t skip,size_t term)
			:_data(skip,term,2){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: UCOVAR
	// ============================================================================
	class kgMvSimFunc_Ucovar : public kgMvSimFunc
	{
		kgMvMean _data; 

		public:
		kgMvSimFunc_Ucovar(size_t skip,size_t term)
			:_data(skip,term,2){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: SPEARMAN
	// ============================================================================
	class kgMvSimFunc_Spearman : public kgMvSimFunc
	{
		kgMvRank _data; 

		public:
		kgMvSimFunc_Spearman(size_t skip,size_t term)
			:_data(skip,term,2){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: KENDALL
	// ============================================================================
	class kgMvSimFunc_kendall : public kgMvSimFunc
	{
		kgMvValCount _data; 

		public:
		kgMvSimFunc_kendall(size_t skip,size_t term)
			:_data(skip,term,2){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: PEARSON
	// ============================================================================
	class kgMvSimFunc_Pearson : public kgMvSimFunc
	{
		kgMvMean _data; 
		vector<kgVal> _mean;
		public:
		kgMvSimFunc_Pearson(size_t skip,size_t term)
			:_data(skip,term,2),_mean(2,kgVal('N')){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: EUCLID
	// ============================================================================
	class kgMvSimFunc_Euclid : public kgMvSimFunc
	{
		kgMvSum _data; 

		public:
		kgMvSimFunc_Euclid(size_t skip,size_t term)
			:_data(skip,term,1){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: COSINE
	// ============================================================================
	class kgMvSimFunc_Cosine : public kgMvSimFunc
	{
		kgMvSum _data; 
		public:
		kgMvSimFunc_Cosine(size_t skip,size_t term)
			:_data(skip,term,3){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: CITYBLOCK
	// ============================================================================	
	class kgMvSimFunc_CityBlock : public kgMvSimFunc
	{
		kgMvSum _data; 
		public:
		kgMvSimFunc_CityBlock(size_t skip,size_t term)
			:_data(skip,term,1){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: HAMMING
	// ============================================================================	
	class kgMvSimFunc_Hamming : public kgMvSimFunc
	{
		kgMvTrueCnt _data; 
		vector<kgVal> _rlssum;
		public:
		kgMvSimFunc_Hamming(size_t skip,size_t term)
			:_data(skip,term,1),_rlssum(1,kgVal('N')){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: PHI
	// ============================================================================	
	class kgMvSimFunc_Phi : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_Phi(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: CHI
	// ============================================================================		
	class kgMvSimFunc_Chi : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_Chi(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: JACCARD
	// ============================================================================			
	class kgMvSimFunc_Jaccard : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 
		vector<kgVal> _rlssum;
		public:
		kgMvSimFunc_Jaccard(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: SUPPORT
	// ============================================================================				
	class kgMvSimFunc_Support : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_Support(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: LIFT
	// ============================================================================			
	class kgMvSimFunc_Lift : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_Lift(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: CONFMAX
	// ============================================================================			
	class kgMvSimFunc_ConfMax : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 
		
		public:
		kgMvSimFunc_ConfMax(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: CONFMIN
	// ============================================================================			
	class kgMvSimFunc_ConfMin : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_ConfMin(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: YULEQ
	// ============================================================================			
	class kgMvSimFunc_YuleQ : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_YuleQ(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: YULEY
	// ============================================================================			
	class kgMvSimFunc_YuleY : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_YuleY(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}

	};
	// ============================================================================
	// SIM関数 :: Kappa
	// ============================================================================			
	class kgMvSimFunc_Kappa : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_Kappa(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}
	};
	// ============================================================================
	// SIM関数 :: ODDSRATIO
	// ============================================================================				
	class kgMvSimFunc_OddsRatio : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_OddsRatio(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}
	};
	// ============================================================================
	// SIM関数 :: CONVMAX
	// ============================================================================				
	class kgMvSimFunc_ConvMax : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_ConvMax(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}
	};
	// ============================================================================
	// SIM関数 :: CONVMAX
	// ============================================================================	
	class kgMvSimFunc_ConvMin : public kgMvSimFunc
	{
		kgMvBoolMatrix _data; 

		public:
		kgMvSimFunc_ConvMin(size_t skip,size_t term)
			:_data(skip,term){}

		virtual void calc(kgVal &rls,vector<char*>& inp);
		virtual size_t stocksize(){ return _data.stocksize();}
		virtual void clear(){ _data.clear();}
	};

}

class kgMvsim : public kgModIncludeSort {

	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVblk _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgstr_t  _c_type; // c=
	size_t   _skip; 	// skip=
	size_t   _term; 	// skip=
	kgstr_t _addstr; // a=
	bool 		_nullout; //-n

	boost::function<kgmvsim_::kgMvSimFunc*(size_t,size_t)> _function;

  void setArgs(void);

public:
  // コンストラクタ
	kgMvsim(void);
	~kgMvsim(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }
	
	//実行メソッド
	int run(void);

};

}
