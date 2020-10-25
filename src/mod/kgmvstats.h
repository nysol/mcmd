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
// --------------------------------------------------------------------------------------------
// window集計クラス
// -----------------------------------------------------------------------------
namespace kgmvstats_ {

	class kgMvBase
	{
		size_t _term;
		size_t _fsize;
		vector< vector<kgVal> > _val;
		vector< size_t > _stock_size;
		size_t _spos;
		bool _filled; 
		protected:

		void pos_inc(){ _spos = (_spos+1) % _term; }
		void update(vector<kgVal>& inp);
		double get(size_t i){ 
			return _val.at(i).at(_spos).r(); 
		}
		vector<kgVal>& gets(size_t i){ 
			return _val.at(i); 
		}


		public:
		kgMvBase(size_t term,size_t fsize)
			:_term(term),_fsize(fsize),	_val(fsize,vector<kgVal>(term,kgVal('N'))),
			_stock_size(fsize,0),_spos(0), _filled(false){}

		bool isNull(size_t i){
			if(_filled){ return _term!=_stock_size.at(i);}
			else			 { return _spos!=_stock_size.at(i);}
		}

		size_t stocksize(size_t i){ return _stock_size.at(i); }
		
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp)=0;
		virtual void clear();
		
	};

	// =============================================================================
	// c=sum(合計) 
	// =============================================================================
	class kgMvSum : public kgMvBase
	{
		vector<double> _sumary;

		public:	
		kgMvSum(size_t term,size_t fzize)
			:kgMvBase(term,fzize),_sumary(fzize,0){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
		virtual void clear();
	};
	// =============================================================================
	// c=mean(算術平均) 
	// =============================================================================
	class kgMvMean : public kgMvSum
	{
		vector<double> _mean;
		public:	
		kgMvMean(size_t term,size_t fzize)
			:kgMvSum(term,fzize),_mean(fzize,0){}

		double get(size_t i){return _mean.at(i);}
		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
		virtual void clear();
	};
	// =============================================================================
	// c=devsp(二乗差) 
	// =============================================================================
	class kgMvDevsq : public kgMvMean
	{
		public:	
		kgMvDevsq(size_t term,size_t fzize)
			:kgMvMean(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=var(分散) 
	// =============================================================================
	class kgMvVar : public kgMvDevsq
	{
		public:	
		kgMvVar(size_t term,size_t fzize)
			:kgMvDevsq(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=uvar(分散 (不偏推定値)) 
	// =============================================================================
	class kgMvUvar : public kgMvDevsq
	{
		public:	
		kgMvUvar(size_t term,size_t fzize)
			:kgMvDevsq(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=sd(標準偏差) 
	// =============================================================================
	class kgMvSd : public kgMvDevsq
	{
		public:	
		kgMvSd(size_t term,size_t fzize)
			:kgMvDevsq(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=sud(標準偏差 (不偏推定値)) 
	// =============================================================================
	class kgMvUsd : public kgMvDevsq
	{
		public:	
		kgMvUsd(size_t term,size_t fzize)
			:kgMvDevsq(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=cv(変動係数) 
	// =============================================================================
	class kgMvCv : public kgMvSd
	{
		public:	
		kgMvCv(size_t term,size_t fzize)
			:kgMvSd(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=min(最小値) 
	// =============================================================================
	class kgMvMin : public kgMvBase
	{
		public:	
		kgMvMin(size_t term,size_t fzize)
			:kgMvBase(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=max(最大値) 
	// =============================================================================
	class kgMvMax : public kgMvBase
	{
		public:	
		kgMvMax(size_t term,size_t fzize)
			:kgMvBase(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=range(範囲) 
	// =============================================================================
	class kgMvRange : public kgMvBase
	{
		public:	
		kgMvRange(size_t term,size_t fzize)
			:kgMvBase(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=歪度 
	// =============================================================================
	class kgMvSkew : public kgMvMean
	{
		public:	
		kgMvSkew(size_t term,size_t fzize)
			:kgMvMean(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=歪度 (不偏推定値)
	// =============================================================================
	class kgMvUskew : public kgMvMean
	{
		public:	
		kgMvUskew(size_t term,size_t fzize)
			:kgMvMean(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=尖度 
	// =============================================================================
	class kgMvKurt : public kgMvMean
	{
		public:	
		kgMvKurt(size_t term,size_t fzize)
			:kgMvMean(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
	// =============================================================================
	// c=尖度 
	// =============================================================================
	class kgMvUkurt : public kgMvMean
	{
		public:	
		kgMvUkurt(size_t term,size_t fzize)
			:kgMvMean(term,fzize){}

		// 集計&初期化
		virtual void calc(vector<kgVal>& rls ,vector<kgVal>& inp);
	};
}

class kgMvstats : public kgModIncludeSort {

	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVblk _iFile;  // i=
	kgCSVout _oFile;  // o=
	kgstr_t  _c_type; // c=
	size_t   _skip; 	// skip=
	size_t   _term; 	// skip=
	bool     _null; 	// skip=

	boost::function<kgmvstats_::kgMvBase*(size_t,size_t)> _function;

  void setArgs(void);

public:
  // コンストラクタ
	kgMvstats(void);
	~kgMvstats(void){}

	// コマンド固有の公開メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }
	
	//実行メソッド
	int run(void);

};

}
