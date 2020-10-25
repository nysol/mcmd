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
// kgsim.h 項目間類似度計算クラス
// =============================================================================
#pragma once
#include <vector>
#include <kgConfig.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace
	
// -----------------------------------------------------------------------------
// covar:共分散
// ucovar:不偏共分散
// pearson:ピアソンの積率相関係数
// spearman:スピアマンの順位相関係数
// kendall:ケンドールの順位相関係数
// euclid:ユークリッド距離
// cosine:コサイン
// cityblock:都市ブロック距離
// hamming:ハミング距離
// support:支持度
// lift:リフト値
// phi:ファイ係数
// chi:カイ二乗値
// jaccard:ジャックカード係数
// confMax:
// confMin:
// yuleQ:
// yuleY:
// kappa:
// oddsRatio:
// convMax:
// convMin:
// の計算が可能
// -----------------------------------------------------------------------------
class kgSim : public kgModIncludeSort
{
	// 引数
	kgArgFld _kField; // k=
	kgArgFld _fField; // f=
	kgCSVblk _iFile;  // i=
	kgCSVout _oFile;  // o=
	vector<kgstr_t> _vField;//a=
	string   _aField; //v=
	string   _c_type; // c=
	vector<vector<kgstr_t> >  _c_types; // c=
	bool _null; //-n

	// 方向性を持つかどうか
	// 方向性があれば上下三角行列を出力する．
	// なければ下三角行列のみ出力する．
	bool     _direction; 

	vector<kgVal (*)(kgCSVblk&,kgArgFld&,int,int,kgstr_t&,bool,bool,bool,bool*,bool*)> _functions;
	vector<string> _names; // 出力する距離の名称(ex. euclid ユークリッド)

	void setArgs(void);
public:
  // コンストラクタ
	kgSim(void);
	~kgSim(void){}

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

	//実行メソッド
	int run(void);

};

}
