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
// kgFunction.h 演算に使用する関数のクラス
// ============================================================================
#pragma once
#include <vector>
#include <string>
#include <cfloat>
#include <cstdio>
#include <kgCSV.h>
#include <kgArgFld.h>
#include <kgVal.h>
#include <kgMethod.h>
#include <kgConfig.h>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/xpressive_fwd.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/random.hpp>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>

namespace kglib  ////////////////////////////////////////////// start namespace
{
// 関数の基底クラス
// 派生クラスでの各種関数の役割
//   コンストラクタ:返り値の型や名前など静的に決まる変数の設定
//   initialize : 式をparseした後の定数や項目番号の設定
//   preprocess : initialize以外で必要な前処理
class kgFunction {
	public:	
		kgVal          _result; // 返値
		vector<kgVal*> _args;   // 引数
		kgCSVkey*      _csv;    // 入力ファイル
		kgVal*         _prvRsl; // 前行の計算結果
		bool			      _fldno;  // 項目番号指定

		// 指定された引数の数をチェックするために以下の2つの変数を導入
		vector<int>::size_type _minArgc;  // 最小引数数
		vector<int>::size_type _maxArgc;  // 最大引数数
		// エラーメッセージに利用する演算子名,関数名
		const char*    _name; // 関数名

		// 実行 (定数では実装する必要なし)
		virtual void run(void){}

		// 定数,項目名の評価
		virtual void initialize(kgstr_t&){}

		// 関数毎に行う前処理不必要な関数では何もしない．
		virtual void preprocess(void){}

		virtual ~kgFunction(){}

		// 引数の数のチェック
		void chkArgc(void);
};
// ============================================================================
// 定数関係クラス
// ============================================================================
// -------------------------------------------------------------------------
// 文字列
// -------------------------------------------------------------------------
class kgFunction_const_str : public kgFunction
{
	string _val;
	public:
	kgFunction_const_str(void)
		{_result.type('S');_name="const";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};
// -------------------------------------------------------------------------
// 数値
// -------------------------------------------------------------------------
class kgFunction_const_real : public kgFunction
{
	public:
	kgFunction_const_real(void)
		{_result.type('N');_name="const";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};
// -------------------------------------------------------------------------
// 日付
// -------------------------------------------------------------------------
class kgFunction_const_date : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_const_date(void)
		{_result.type('D');_name="const";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};
// -------------------------------------------------------------------------
// 時刻
// -------------------------------------------------------------------------
class kgFunction_const_time : public kgFunction
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_const_time(void)
		{_result.type('T');_name="const";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};
// -------------------------------------------------------------------------
// 時刻
// -------------------------------------------------------------------------
class kgFunction_const_utime : public kgFunction
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_const_utime(void)
		{_result.type('T');_name="const";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};


// -------------------------------------------------------------------------
// bool
// -------------------------------------------------------------------------
class kgFunction_const_bool : public kgFunction
{
	public:
	kgFunction_const_bool(void)
		{_result.type('B');_name="const";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};

// ============================================================================
// 項目関係クラス
// ============================================================================
// -------------------------------------------------------------------------
// スーパークラス
// -------------------------------------------------------------------------
class kgFunction_field : public kgFunction
{
	protected:
	kgArgFld  _fld;
	public:
	kgFunction_field(void){_name="field";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str){ _fld.set(str,_csv,_fldno); }
};
// -------------------------------------------------------------------------
// 文字列
// -------------------------------------------------------------------------
class kgFunction_field_str : public kgFunction_field
{
	public:
	kgFunction_field_str(void){_result.type('S');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// 数値
// -------------------------------------------------------------------------
class kgFunction_field_real : public kgFunction_field
{
	public:
	kgFunction_field_real(void) {_result.type('N');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// 日付
// -------------------------------------------------------------------------
class kgFunction_field_date : public kgFunction_field
{
	kgAutoPtr1<date> _ap;
	public:
	kgFunction_field_date(void) {_result.type('D');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// 時刻
// -------------------------------------------------------------------------
class kgFunction_field_time : public kgFunction_field
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_field_time(void){_result.type('T');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// bool
// -------------------------------------------------------------------------
class kgFunction_field_bool : public kgFunction_field
{
	public:
	kgFunction_field_bool(void){_result.type('B');}
	virtual void run(void);
};
// ============================================================================
// 前行項目関係クラス
// ============================================================================
// -------------------------------------------------------------------------
// スーパークラス
// -------------------------------------------------------------------------
class kgFunction_pfield : public kgFunction
{
	protected:
	kgArgFld  _fld;
	bool      _rsl;
	public:
	kgFunction_pfield(void){_name="pfield";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};
// -------------------------------------------------------------------------
// 文字列
// -------------------------------------------------------------------------
class kgFunction_pfield_str : public kgFunction_pfield
{
	public:
	kgFunction_pfield_str(void){ _result.type('S');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// 数値
// -------------------------------------------------------------------------
class kgFunction_pfield_real : public kgFunction_pfield
{
	public:
	kgFunction_pfield_real(void){ _result.type('N');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// 日付
// -------------------------------------------------------------------------
class kgFunction_pfield_date : public kgFunction_pfield
{
	kgAutoPtr1<date> _ap;
	public:
	kgFunction_pfield_date(void){ _result.type('D');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// 時刻
// -------------------------------------------------------------------------
class kgFunction_pfield_time : public kgFunction_pfield
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_pfield_time(void){_result.type('T');}
	virtual void run(void);
};
// -------------------------------------------------------------------------
// bool
// -------------------------------------------------------------------------
class kgFunction_pfield_bool : public kgFunction_pfield
{
	public:
	kgFunction_pfield_bool(void){ _result.type('B');}
	virtual void run(void);
};
// ============================================================================
// 四則演算関係クラス
// ============================================================================
// -----------------------------------------------------------------------------
// 文字列 + 文字列 => 文字列
// -----------------------------------------------------------------------------
class kgFunction_add_str : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_add_str(void)
	{_result.type('S');_name="+";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 + 数値 => 数値
// -----------------------------------------------------------------------------
class kgFunction_add_real : public kgFunction
{
	public:
	kgFunction_add_real(void)
	{_result.type('N');_name="+";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 + 数値 => 日付
// -----------------------------------------------------------------------------
class kgFunction_add_day : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_add_day(void)
	{_result.type('D');_name="+";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 + 数値 => 時刻
// -----------------------------------------------------------------------------
class kgFunction_add_sec : public kgFunction
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_add_sec(void)
	{_result.type('T');_name="+";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 文字列 - 文字列 => 文字列
// -----------------------------------------------------------------------------
class kgFunction_sub_str : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_sub_str(void)
	{_result.type('S');_name="-";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 - 数値 => 数値
// -----------------------------------------------------------------------------
class kgFunction_sub_real : public kgFunction
{
	public:
	kgFunction_sub_real(void)
	{_result.type('N');_name="-";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 - 日付 => 数値
// -----------------------------------------------------------------------------
class kgFunction_sub_date : public kgFunction
{
	public:
	kgFunction_sub_date(void)
	{_result.type('N');_name="-";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 - 時刻 => 数値
// -----------------------------------------------------------------------------
class kgFunction_sub_time : public kgFunction
{
	public:
	kgFunction_sub_time(void)
	{_result.type('N');_name="-";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 - 数値 => 日付
// -----------------------------------------------------------------------------
class kgFunction_sub_day : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_sub_day(void)
	{_result.type('D');_name="-";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 - 数値 => 時刻
// -----------------------------------------------------------------------------
class kgFunction_sub_sec : public kgFunction
{
	kgAutoPtr1 <ptime> _ap;
	public:
	kgFunction_sub_sec(void)
	{_result.type('T');_name="-";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 * 数値 => 数値
// -----------------------------------------------------------------------------
class kgFunction_mul_real : public kgFunction
{
	public:
	kgFunction_mul_real(void)
	{_result.type('N');_name="*";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 / 数値 => 数値
// -----------------------------------------------------------------------------
class kgFunction_div_real : public kgFunction
{
	public:
	kgFunction_div_real(void)
	{_result.type('N');_name="/";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 % 数値 => 数値
// -----------------------------------------------------------------------------
class kgFunction_mod_real : public kgFunction
{
	public:
	kgFunction_mod_real(void)
	{_result.type('N');_name="%";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 ^ 数値 => 数値
// -----------------------------------------------------------------------------
class kgFunction_pow_real : public kgFunction
{
	public:
	kgFunction_pow_real(void)
	{_result.type('N');_name="^";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// ============================================================================
// 比較演算子関係クラス
// ============================================================================
// -----------------------------------------------------------------------------
// 文字列 >= 文字列 => bool
// -----------------------------------------------------------------------------
class kgFunction_ge_str : public kgFunction
{
	public:
	kgFunction_ge_str(void)
	{_result.type('B');_name=">=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 >= 数値 => bool
// -----------------------------------------------------------------------------
class kgFunction_ge_real : public kgFunction
{
	public:
	kgFunction_ge_real(void)
	{_result.type('B');_name=">=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 >= 日付 => bool
// -----------------------------------------------------------------------------
class kgFunction_ge_date : public kgFunction
{
	public:
	kgFunction_ge_date(void)
	{_result.type('B');_name=">=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 >= 時刻 => bool
// -----------------------------------------------------------------------------
class kgFunction_ge_time : public kgFunction
{
	public:
	kgFunction_ge_time(void)
	{_result.type('B');_name=">=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 文字列 <= 文字列 => bool
// -----------------------------------------------------------------------------
class kgFunction_le_str : public kgFunction
{
	public:
	kgFunction_le_str(void)
	{_result.type('B');_name="<=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 <= 数値 => bool
// -----------------------------------------------------------------------------
class kgFunction_le_real : public kgFunction
{
	public:
	kgFunction_le_real(void)
	{_result.type('B');_name="<=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 <= 日付 => bool
// -----------------------------------------------------------------------------
class kgFunction_le_date : public kgFunction
{
	public:
	kgFunction_le_date(void)
	{_result.type('B');_name="<=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 <= 時刻 => bool
// -----------------------------------------------------------------------------
class kgFunction_le_time : public kgFunction
{
	public:
	kgFunction_le_time(void)
	{_result.type('B');_name="<=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 文字列 > 文字列 => bool
// -----------------------------------------------------------------------------
class kgFunction_gt_str : public kgFunction
{
	public:
	kgFunction_gt_str(void)
	{_result.type('B');_name=">";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 > 数値 => bool
// -----------------------------------------------------------------------------
class kgFunction_gt_real : public kgFunction
{
	public:
	kgFunction_gt_real(void)
	{_result.type('B');_name=">";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 > 日付 => bool
// -----------------------------------------------------------------------------
class kgFunction_gt_date : public kgFunction
{
	public:
	kgFunction_gt_date(void)
	{_result.type('B');_name=">";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 > 時刻 => bool
// -----------------------------------------------------------------------------
class kgFunction_gt_time : public kgFunction
{
	public:
	kgFunction_gt_time(void)
	{_result.type('B');_name=">";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 文字列 < 文字列 => bool
// -----------------------------------------------------------------------------
class kgFunction_lt_str : public kgFunction
{
	public:
	kgFunction_lt_str(void)
	{_result.type('B');_name="<";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 < 数値 => bool
// -----------------------------------------------------------------------------
class kgFunction_lt_real : public kgFunction
{
	public:
	kgFunction_lt_real(void)
	{_result.type('B');_name="<";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 < 日付 => bool
// -----------------------------------------------------------------------------
class kgFunction_lt_date : public kgFunction
{
	public:
	kgFunction_lt_date(void)
	{_result.type('B');_name="<";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 < 時刻 => bool
// -----------------------------------------------------------------------------
class kgFunction_lt_time : public kgFunction
{
	public:
	kgFunction_lt_time(void)
	{_result.type('B');_name="<";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 文字列 == 文字列 => bool
// -----------------------------------------------------------------------------
class kgFunction_eq_str : public kgFunction
{
	public:
	kgFunction_eq_str(void)
	{_result.type('B');_name="==";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 == 数値 => bool
// -----------------------------------------------------------------------------
class kgFunction_eq_real : public kgFunction
{
	public:
	kgFunction_eq_real(void)
	{_result.type('B');_name="==";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 == 日付 => bool
// -----------------------------------------------------------------------------
class kgFunction_eq_date : public kgFunction
{
	public:
	kgFunction_eq_date(void)
	{_result.type('B');_name="==";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 == 時刻 => bool
// -----------------------------------------------------------------------------
class kgFunction_eq_time : public kgFunction
{
	public:
	kgFunction_eq_time(void)
	{_result.type('B');_name="==";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 文字列 != 文字列 => bool
// -----------------------------------------------------------------------------
class kgFunction_ne_str : public kgFunction
{
	public:
	kgFunction_ne_str(void)
	{_result.type('B');_name="!=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 数値 != 数値 => bool
// -----------------------------------------------------------------------------
class kgFunction_ne_real : public kgFunction
{
	public:
	kgFunction_ne_real(void)
	{_result.type('B');_name="!=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 日付 != 日付 => bool
// -----------------------------------------------------------------------------
class kgFunction_ne_date : public kgFunction
{
	public:
	kgFunction_ne_date(void)
	{_result.type('B');_name="!=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// 時刻 != 時刻 => bool
// -----------------------------------------------------------------------------
class kgFunction_ne_time : public kgFunction
{
	public:
	kgFunction_ne_time(void)
	{_result.type('B');_name="!=";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// ============================================================================
// 論理演算子関数クラス
// ============================================================================
// -----------------------------------------------------------------------------
// bool && bool => bool
// -----------------------------------------------------------------------------
class kgFunction_and : public kgFunction
{
	public:
	kgFunction_and(void)
	{_result.type('B');_name="&&";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// and(bool,bool,...,bool) => bool
// -----------------------------------------------------------------------------
class kgFunction_multi_and : public kgFunction
{
	public:
	kgFunction_multi_and(void)
	{_result.type('B');_name="and";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// bool || bool => bool
// -----------------------------------------------------------------------------
class kgFunction_or : public kgFunction
{
	public:
	kgFunction_or(void)
	{_result.type('B');_name="||";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// or(bool,bool,...,bool) => bool
// -----------------------------------------------------------------------------
class kgFunction_multi_or : public kgFunction
{
	public:
	kgFunction_multi_or(void)
	{_result.type('B');_name="or";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// bool ^^ bool => bool 
// -----------------------------------------------------------------------------
class kgFunction_xor : public kgFunction
{
	public:
	kgFunction_xor(void)
	{_result.type('B');_name="^^";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// not(bool) => bool
// -----------------------------------------------------------------------------
class kgFunction_not : public kgFunction
{
	public:
	kgFunction_not(void)
	{_result.type('B');_name="not";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// if(bool,文字列,文字列)  => 文字列
// -----------------------------------------------------------------------------
class kgFunction_if_str : public kgFunction
{
	public:
	kgFunction_if_str(void)
	{_result.type('S');_name="if";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// if(bool,数値,数値)  => 数値
// -----------------------------------------------------------------------------
class kgFunction_if_real : public kgFunction
{
	public:
	kgFunction_if_real(void)
	{_result.type('N');_name="if";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// if(bool,日付,日付)  => 日付
// -----------------------------------------------------------------------------
class kgFunction_if_date : public kgFunction
{
	public:
	kgFunction_if_date(void)
	{_result.type('D');_name="if";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// if(bool,時刻,時刻)  => 時刻
// -----------------------------------------------------------------------------
class kgFunction_if_time : public kgFunction
{
	public:
	kgFunction_if_time(void)
	{_result.type('T');_name="if";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// if(bool,bool,bol)  => bool
// -----------------------------------------------------------------------------
class kgFunction_if_bool : public kgFunction
{
	public:
	kgFunction_if_bool(void)
	{_result.type('B');_name="if";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// ============================================================================
// NULL値関連関数クラス
// ============================================================================
// -----------------------------------------------------------------------------
// null_s
// -----------------------------------------------------------------------------
class kgFunction_const_nulls : public kgFunction
{
	public:
	kgFunction_const_nulls(void){ 
		_result.type('S');_name="nulls";_minArgc=0;_maxArgc=0;
		_result.null(true);_result.s(const_cast<char*>(""));
	}
};
// -----------------------------------------------------------------------------
// null_n
// -----------------------------------------------------------------------------
class kgFunction_const_nulln : public kgFunction
{
	public:
	kgFunction_const_nulln(void){ 
		_result.type('N');_name="nulln";_minArgc=0;_maxArgc=0;
		_result.null(true);
	}
};
// -----------------------------------------------------------------------------
// null_d
// -----------------------------------------------------------------------------
class kgFunction_const_nulld : public kgFunction
{
	public:
	kgFunction_const_nulld(void){ 
		_result.type('D');_name="nulld";_minArgc=0;_maxArgc=0;
		_result.null(true);
	}
};
// -----------------------------------------------------------------------------
// null_t
// -----------------------------------------------------------------------------
class kgFunction_const_nullt : public kgFunction
{
	public:
	kgFunction_const_nullt(void){ 
		_result.type('T');_name="nullt";_minArgc=0;_maxArgc=0;
		_result.null(true);
	}
};
// -----------------------------------------------------------------------------
// null_b
// -----------------------------------------------------------------------------
class kgFunction_const_nullb : public kgFunction
{
	public:
	kgFunction_const_nullb(void){ 
		_result.type('B');_name="nullb";_minArgc=0;_maxArgc=0;
		_result.null(true);
	}
};
// -----------------------------------------------------------------------------
// isnull(文字列) => bool
// -----------------------------------------------------------------------------
class kgFunction_isnull_s : public kgFunction
{
	public:
	kgFunction_isnull_s(void)
	{_result.type('B');_name="isnull";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// isnull(数値) => bool
// -----------------------------------------------------------------------------
class kgFunction_isnull_n : public kgFunction
{
	public:
	kgFunction_isnull_n(void)
	{_result.type('B');_name="isnull";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// isnull(日付) => bool
// -----------------------------------------------------------------------------
class kgFunction_isnull_d : public kgFunction
{
	public:
	kgFunction_isnull_d(void)
	{_result.type('B');_name="isnull";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// isnull(時刻) => bool
// -----------------------------------------------------------------------------
class kgFunction_isnull_t : public kgFunction
{
	public:
	kgFunction_isnull_t(void)
	{_result.type('B');_name="isnull";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// isnull(bool) => bool
// -----------------------------------------------------------------------------
class kgFunction_isnull_b : public kgFunction
{
	public:
	kgFunction_isnull_b(void)
	{_result.type('B');_name="isnull";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// countnull(文字列,文字列...) => 数値
// -----------------------------------------------------------------------------
class kgFunction_countnull_s : public kgFunction
{
	public:
	kgFunction_countnull_s(void)
	{_result.type('N');_name="countnull";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// countnull(数値,数値,....) => 数値
// countnull(日付,日付,...) => 数値
// countnull(時刻,時刻,...) => 数値
// countnull(bool,bool,..) => 数値
// -----------------------------------------------------------------------------
class kgFunction_countnull : public kgFunction
{
	public:
	kgFunction_countnull(void)
	{_result.type('N');_name="countnull";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// ============================================================================
// 型変換関数クラス
// ============================================================================
// -----------------------------------------------------------------------------
// s2n(文字列) => 数値
// -----------------------------------------------------------------------------
class kgFunction_s2n : public kgFunction
{
	public:
	kgFunction_s2n(void)
	{_result.type('N');_name="s2n";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// s2d(文字列) => 日付
// -----------------------------------------------------------------------------
class kgFunction_s2d : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_s2d(void)
	{_result.type('D');_name="s2d";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// s2t(文字列) => 時刻
// -----------------------------------------------------------------------------
class kgFunction_s2t : public kgFunction
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_s2t(void)
	{_result.type('T');_name="s2t";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// t2d(時刻) => 日付
// -----------------------------------------------------------------------------
class kgFunction_t2d : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_t2d(void)
	{_result.type('D');_name="t2d";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// d2t(日付) => 時刻
// -----------------------------------------------------------------------------
class kgFunction_d2t : public kgFunction
{
	kgAutoPtr1<ptime> _ap;
	public:
	kgFunction_d2t(void)
	{_result.type('T');_name="d2t";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};



// -----------------------------------------------------------------------------
// n2s(数値) => 文字列
// -----------------------------------------------------------------------------
class kgFunction_n2s : public kgFunction
{
	char _buf[256];
	public:
	kgFunction_n2s(void)
	{_result.type('S');_name="n2s";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// d2s(日付) => 文字列
// -----------------------------------------------------------------------------
class kgFunction_d2s : public kgFunction
{
	char _buf[10];
	public:
	kgFunction_d2s(void)
	{_result.type('S');_name="d2s";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// t2s(時刻) => 文字列
// -----------------------------------------------------------------------------
class kgFunction_t2s : public kgFunction
{
	char _buf[20];
	public:
	kgFunction_t2s(void)
	{_result.type('S');_name="t2s";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// b2n(bool) => 数値
// -----------------------------------------------------------------------------
class kgFunction_b2n : public kgFunction
{
	public:
	kgFunction_b2n(void)
	{_result.type('N');_name="b2n";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// b2s(bool) => 文字列
// -----------------------------------------------------------------------------
class kgFunction_b2s : public kgFunction
{
	char _buf[2];
	public:
	kgFunction_b2s(void)
	{_result.type('S');_buf[1]='\0';_name="b2s";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// n2b(数値) => bool
// -----------------------------------------------------------------------------
class kgFunction_n2b : public kgFunction
{
	public:
	kgFunction_n2b(void)
	{_result.type('B');_name="n2b";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// n2b(文字列) => bool
// -----------------------------------------------------------------------------
class kgFunction_s2b : public kgFunction
{
	public:
	kgFunction_s2b(void)
	{_result.type('B');_name="s2b";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// format(数値,文字列[書式]) => 文字列 : 数値の書式付き変換
// -----------------------------------------------------------------------------
class kgFunction_format_real : public kgFunction
{
	char _buf[256];
	public:
	kgFunction_format_real(void)
	{_result.type('S');_name="format";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// ============================================================================
// 日付時刻関数クラス
// ============================================================================
// -----------------------------------------------------------------------------
// today() => 日付 
// -----------------------------------------------------------------------------
class kgFunction_today : public kgFunction
{
	boost::gregorian::date _today;
	public:
	kgFunction_today(void)
	{_result.type('D');_name="today";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};
// -----------------------------------------------------------------------------
// now() => 時刻 
// -----------------------------------------------------------------------------
class kgFunction_now : public kgFunction
{
  boost::posix_time::ptime _now;
	public:
	kgFunction_now(void)
	{_result.type('T');_name="now";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};

// -----------------------------------------------------------------------------
// now() => 時刻 
// -----------------------------------------------------------------------------
class kgFunction_unow : public kgFunction
{
  boost::posix_time::ptime _unow;
	public:
	kgFunction_unow(void)
	{_result.type('T');_name="unow";_minArgc=0;_maxArgc=0;}
	virtual void initialize(kgstr_t& str);
};

// -----------------------------------------------------------------------------
// time(時刻) => 文字列
// -----------------------------------------------------------------------------
class kgFunction_time_str : public kgFunction
{
	char _buf[32];
	public:
	kgFunction_time_str(void)
	{_result.type('S');_name="time";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// date(時刻) => 文字列
// -----------------------------------------------------------------------------
class kgFunction_date_str : public kgFunction
{
	char _buf[20];
	public:
	kgFunction_date_str(void)
	{_result.type('S');_name="date";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// leapyear(日付) => bool : 閏年判定する
// -----------------------------------------------------------------------------
class kgFunction_leapyear_d : public kgFunction
{
	public:
	kgFunction_leapyear_d(void)
	{_result.type('B');_name="leapyear";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// leapyear(時刻) => bool : 閏年判定する
// -----------------------------------------------------------------------------
class kgFunction_leapyear_t : public kgFunction
{
	public:
	kgFunction_leapyear_t(void)
	{_result.type('B');_name="leapyear";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// d2julian(日付) => 数値 :  ユリウス通日を求める
// -----------------------------------------------------------------------------
class kgFunction_d2julian : public kgFunction
{
	public:
	kgFunction_d2julian(void)
	{_result.type('N');_name="d2julian";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// t2julian(時刻) => 数値 :  ユリウス通日を求める
// -----------------------------------------------------------------------------
class kgFunction_t2julian : public kgFunction
{
	public:
	kgFunction_t2julian(void)
	{_result.type('N');_name="t2julian";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// julian2d(数値) => 日付 :  ユリウス通日から日付を求める
// -----------------------------------------------------------------------------
class kgFunction_julian2d : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_julian2d(void)
	{_result.type('D');_name="julian2d";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// julian2t(数値) => 日付 :  ユリウス通日から時刻を求める
// -----------------------------------------------------------------------------
class kgFunction_julian2t : public kgFunction
{
	kgAutoPtr1 <ptime> _ap;
	public:
	kgFunction_julian2t(void)
	{_result.type('T');_name="julian2t";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// uxt2d(数値) => 日付 :  UNIX時刻から通常日付を求める
// -----------------------------------------------------------------------------
class kgFunction_uxt2d : public kgFunction
{
	kgAutoPtr1 <date> _ap;
	public:
	kgFunction_uxt2d(void)
	{_result.type('D');_name="uxt2d";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// uxt2t(時刻) => 日付 :  UNIX時刻から通常日時を求める
// -----------------------------------------------------------------------------
class kgFunction_uxt2t : public kgFunction
{
	kgAutoPtr1 <ptime> _ap;
	public:
	kgFunction_uxt2t(void)
	{_result.type('T');_name="uxt2t";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// d2uxt(日付) => 数値 :  通常の日付をUNIX時刻に変換する
// -----------------------------------------------------------------------------
class kgFunction_d2uxt : public kgFunction
{
	public:
	kgFunction_d2uxt(void)
	{_result.type('N');_name="d2uxt";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// t2uxt(時刻) => 数値 :  通常の日時をUNIX時刻に変換する
// -----------------------------------------------------------------------------
class kgFunction_t2uxt : public kgFunction
{
	public:
	kgFunction_t2uxt(void)
	{_result.type('N');_name="t2uxt";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// age(日付1,日付2) => 数値 : 日付1を生年月日とした時の 日付2時点での年齢
// -----------------------------------------------------------------------------
class kgFunction_age_d : public kgFunction
{
	public:
	kgFunction_age_d(void)
	{_result.type('N');_name="age";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// age(時刻1,時刻2) => 数値 : 時刻1を生年月日日時とした時の 時刻2時点での年齢
// -----------------------------------------------------------------------------
class kgFunction_age_t : public kgFunction
{
	public:
	kgFunction_age_t(void)
	{_result.type('N');_name="age";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffyear(日付1,日付2) => 数値 : 
//  日付の引き算(日付1-日付2)
//  年数差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffyear_d : public kgFunction
{
	public:
	kgFunction_diffyear_d(void)
	{_result.type('N');_name="diffyear";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffmonth(日付1,日付2) => 数値 : 
//  日付の引き算(日付1-日付2)
//  月数差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffmonth_d : public kgFunction
{
	public:
	kgFunction_diffmonth_d(void)
	{_result.type('N');_name="diffmonth";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffday(日付1,日付2) => 数値 : 
//  日付の引き算(日付1-日付2)
//  日数差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffday_d : public kgFunction
{
	public:
	kgFunction_diffday_d(void)
	{_result.type('N');_name="diffday";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffyear(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ年数差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffyear_t : public kgFunction
{
	public:
	kgFunction_diffyear_t(void)
	{_result.type('N');_name="diffyear";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffmonth(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ月数差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffmonth_t : public kgFunction
{
	public:
	kgFunction_diffmonth_t(void)
	{_result.type('N');_name="diffmonth";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffday(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ日数差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffday_t : public kgFunction
{
	public:
	kgFunction_diffday_t(void)
	{_result.type('N');_name="diffday";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffhour(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ時間差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffhour_t : public kgFunction
{
	public:
	kgFunction_diffhour_t(void)
	{_result.type('N');_name="diffhour";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffminute(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ分差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffminute_t : public kgFunction
{
	public:
	kgFunction_diffminute_t(void)
	{_result.type('N');_name="diffminute";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// diffsecond(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ秒差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffsecond_t : public kgFunction
{
	public:
	kgFunction_diffsecond_t(void)
	{_result.type('N');_name="diffsecond";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// diffsecond(時刻1,時刻2) => 数値 : 
//  時刻の引き算(時刻1-時刻2)
//	それぞれ秒差を計算する
// -----------------------------------------------------------------------------
class kgFunction_diffusecond_t : public kgFunction
{
	public:
	kgFunction_diffusecond_t(void)
	{_result.type('N');_name="diffusecond";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// year(日付) => 数値 : 年抽出
// -----------------------------------------------------------------------------
class kgFunction_year_d : public kgFunction
{
	public:
	kgFunction_year_d(void)
	{_result.type('N');_name="year";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// year(時刻) => 数値 : 年抽出
// -----------------------------------------------------------------------------
class kgFunction_year_t : public kgFunction
{
	public:
	kgFunction_year_t(void)
	{_result.type('N');_name="year";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// years(日付) => 文字列 : 年抽出
// -----------------------------------------------------------------------------
class kgFunction_years_d : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_years_d(void)
	{_result.type('S');_name="years";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// years(時刻) => 数値 : 年抽出
// -----------------------------------------------------------------------------
class kgFunction_years_t : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_years_t(void)
	{_result.type('S');_name="years";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// month(日付) => 文字列 : 月抽出
// -----------------------------------------------------------------------------
class kgFunction_month_d : public kgFunction
{
	public:
	kgFunction_month_d(void)
	{_result.type('N');_name="month";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// month(時刻) => 数値 : 月抽出
// -----------------------------------------------------------------------------
class kgFunction_month_t : public kgFunction
{
	public:
	kgFunction_month_t(void)
	{_result.type('N');_name="month";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// months(日付) => 文字列 : 月抽出
// -----------------------------------------------------------------------------
class kgFunction_months_d : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_months_d(void)
	{_result.type('S');_name="months";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// months(時刻) => 文字列 : 月抽出
// -----------------------------------------------------------------------------
class kgFunction_months_t : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_months_t(void)
	{_result.type('S');_name="months";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// emonthスーパークラス => 文字列 : 月抽出（英語表記）
// -----------------------------------------------------------------------------
class kgFunction_emonth : public kgFunction
{
	protected:
	static const char* _str[13];
};
// -----------------------------------------------------------------------------
// emonth(日付) => 文字列 : 月抽出（英語表記）
// -----------------------------------------------------------------------------
class kgFunction_emonth_d : public kgFunction_emonth
{
	public:
	kgFunction_emonth_d(void)
	{_result.type('S');_name="emonth";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// emonth(時刻) => 文字列 : 月抽出（英語表記）
// -----------------------------------------------------------------------------
class kgFunction_emonth_t : public kgFunction_emonth
{
	public:
	kgFunction_emonth_t(void)
	{_result.type('S');_name="emonth";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// esmonthスーパークラス => 文字列 : 月抽出（短縮英語表記）
// -----------------------------------------------------------------------------
class kgFunction_esmonth : public kgFunction
{
	protected:
	static const char* _str[13];
};
// -----------------------------------------------------------------------------
// esmonth(日付) => 文字列 : 月抽出（短縮英語表記）
// -----------------------------------------------------------------------------
class kgFunction_esmonth_d : public kgFunction_esmonth
{
	public:
	kgFunction_esmonth_d(void)
	{_result.type('S');_name="esmonth";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// esmonth(時刻) => 文字列 : 月抽出（短縮英語表記）
// -----------------------------------------------------------------------------
class kgFunction_esmonth_t : public kgFunction_esmonth
{
	public:
	kgFunction_esmonth_t(void)
	{_result.type('S');_name="esmonth";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// day(日付) => 数値 : 日抽出
// -----------------------------------------------------------------------------
class kgFunction_day_d : public kgFunction
{
	public:
	kgFunction_day_d(void)
	{_result.type('N');_name="day";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// day(時刻) => 数値 : 日抽出
// -----------------------------------------------------------------------------
class kgFunction_day_t : public kgFunction
{
	public:
	kgFunction_day_t(void)
	{_result.type('N');_name="day";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// days(日付) => 文字列 : 日抽出
// -----------------------------------------------------------------------------
class kgFunction_days_d : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_days_d(void)
	{_result.type('S');_name="days";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// days(時刻) => 文字列 : 日抽出
// -----------------------------------------------------------------------------
class kgFunction_days_t : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_days_t(void)
	{_result.type('S');_name="days";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// week(日付) => 数値 : 週数抽出
// -----------------------------------------------------------------------------
class kgFunction_week_d : public kgFunction
{
	public:
	kgFunction_week_d(void)
	{_result.type('N');_name="week";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// week(時刻) => 数値 : 週数抽出
// -----------------------------------------------------------------------------
class kgFunction_week_t : public kgFunction
{
	public:
	kgFunction_week_t(void)
	{_result.type('N');_name="week";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// week111(日付) => 数値 : 週数抽出
// -----------------------------------------------------------------------------
class kgFunction_week111_d : public kgFunction
{
	public:
	kgFunction_week111_d(void)
	{_result.type('N');_name="week111";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// week(時刻) => 数値 : 週数抽出
// -----------------------------------------------------------------------------
class kgFunction_week111_t : public kgFunction
{
	public:
	kgFunction_week111_t(void)
	{_result.type('N');_name="week111";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};


// -----------------------------------------------------------------------------
// dow(日付) => 数値 : 曜日番号抽出(0:日曜)
// -----------------------------------------------------------------------------
class kgFunction_dow_d : public kgFunction
{
	public:
	kgFunction_dow_d(void)
	{_result.type('N');_name="dow";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// dow(時刻) => 数値 : 曜日番号抽出(0:日曜)
// -----------------------------------------------------------------------------
class kgFunction_dow_t : public kgFunction
{
	public:
	kgFunction_dow_t(void)
	{_result.type('N');_name="dow";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// edowスーパークラス => 文字列 : 曜日抽出(英語表記)
// -----------------------------------------------------------------------------
class kgFunction_edow : public kgFunction
{
	protected:
	static const char* _str[8];
};
// -----------------------------------------------------------------------------
// edow(日付) => 文字列 : 曜日抽出(英語表記)
// -----------------------------------------------------------------------------
class kgFunction_edow_d : public kgFunction_edow
{
	public:
	kgFunction_edow_d(void)
	{_result.type('S');_name="edow";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// edow(時刻) => 文字列 : 曜日抽出(英語表記)
// -----------------------------------------------------------------------------
class kgFunction_edow_t : public kgFunction_edow
{
	public:
	kgFunction_edow_t(void)
	{_result.type('S');_name="edow";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// esdow(日付) => スーパークラス : 曜日抽出(短縮英語表記)
// -----------------------------------------------------------------------------
class kgFunction_esdow : public kgFunction
{
	protected:
	static const char* _str[8];
};
// -----------------------------------------------------------------------------
// esdow(日付) => 文字列 : 曜日抽出(短縮英語表記)
// -----------------------------------------------------------------------------
class kgFunction_esdow_d : public kgFunction_esdow
{
	public:
	kgFunction_esdow_d(void)
	{_result.type('S');_name="esdow";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// esdow(時刻) => 文字列 : 曜日抽出(短縮英語表記)
// -----------------------------------------------------------------------------
class kgFunction_esdow_t : public kgFunction_esdow
{
	public:
	kgFunction_esdow_t(void)
	{_result.type('S');_name="esdow";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// dowj(日付) => スーパークラス : 曜日抽出(日本語表記)
// -----------------------------------------------------------------------------
class kgFunction_dowj : public kgFunction
{
	protected:
	static const char* _str[8];
};
// -----------------------------------------------------------------------------
// esdow(日付) => 文字列 : 曜日抽出(短縮英語表記)
// -----------------------------------------------------------------------------
class kgFunction_dowj_d : public kgFunction_dowj
{
	public:
	kgFunction_dowj_d(void)
	{_result.type('S');_name="esdowj";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// esdow(時刻) => 文字列 : 曜日抽出(短縮英語表記)
// -----------------------------------------------------------------------------
class kgFunction_dowj_t : public kgFunction_dowj
{
	public:
	kgFunction_dowj_t(void)
	{_result.type('S');_name="esdowj";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};


// -----------------------------------------------------------------------------
// hours(時刻) => 数値 : 時間抽出
// -----------------------------------------------------------------------------
class kgFunction_hour_t : public kgFunction
{
	public:
	kgFunction_hour_t(void)
	{_result.type('N');_name="hour";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// hours(時刻) => 文字列 : 時間抽出
// -----------------------------------------------------------------------------
class kgFunction_hours_t : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_hours_t(void)
	{_result.type('S');_name="hours";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// minute(時刻) => 数値 : 分抽出
// -----------------------------------------------------------------------------
class kgFunction_minute_t : public kgFunction
{
	public:
	kgFunction_minute_t(void)
	{_result.type('N');_name="minute";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// minutes(時刻) => 文字列 : 分抽出
// -----------------------------------------------------------------------------
class kgFunction_minutes_t : public kgFunction
{
	char _buf[8];
	public:
	kgFunction_minutes_t(void)
	{_result.type('S');_name="minutes";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// second(時刻) => 数値 : 秒抽出
// -----------------------------------------------------------------------------
class kgFunction_second_t : public kgFunction
{
	public:
	kgFunction_second_t(void)
	{_result.type('N');_name="second";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// usecond(時刻) => 数値 : 秒抽出マイクロ対応
// -----------------------------------------------------------------------------
class kgFunction_usecond_t : public kgFunction
{
	public:
	kgFunction_usecond_t(void)
	{_result.type('N');_name="usecond";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// seconds(時刻) => 数値 : 秒抽出
// -----------------------------------------------------------------------------
class kgFunction_seconds_t : public kgFunction
{
	char _buf[16];
	public:
	kgFunction_seconds_t(void)
	{_result.type('S');_name="seconds";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// seconds(時刻) => 数値 : 秒抽出
// -----------------------------------------------------------------------------
class kgFunction_useconds_t : public kgFunction
{
	char _buf[32];
	public:
	kgFunction_useconds_t(void)
	{_result.type('S');_name="useconds";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// tseconds(時刻) => 数値 : トータルの秒数計算
// -----------------------------------------------------------------------------
class kgFunction_tseconds_t : public kgFunction
{
	public:
	kgFunction_tseconds_t(void)
	{_result.type('N');_name="tseconds";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// tseconds(時刻) => 数値 : トータルの秒数計算
// -----------------------------------------------------------------------------
class kgFunction_tuseconds_t : public kgFunction
{
	public:
	kgFunction_tuseconds_t(void)
	{_result.type('N');_name="tuseconds";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// ============================================================================
// 数値関連クラス
// ============================================================================
// -----------------------------------------------------------------------------
// sum(数値,...,数値) => 数値 : 合計(NULLはskip)
// -----------------------------------------------------------------------------
class kgFunction_sum : public kgFunction
{
	public:
	kgFunction_sum(void)
	{_result.type('N');_name="sum";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// suma(数値,...,数値) => 数値 : 合計(1でもNULLが有ると結果はNULL)
// -----------------------------------------------------------------------------
class kgFunction_sum_N : public kgFunction
{
	public:
	kgFunction_sum_N(void)
	{_result.type('N');_name="sum";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// avg(数値,...,数値) => 数値 : 平均計算(NULLはskip)
// -----------------------------------------------------------------------------
class kgFunction_avg : public kgFunction
{
	public:
	kgFunction_avg(void)
	{_result.type('N');_name="avg";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// avga(数値,...,数値) => 数値 : 平均計算(1でもNULLが有ると結果はNULL)
// -----------------------------------------------------------------------------
class kgFunction_avg_N : public kgFunction
{
	public:
	kgFunction_avg_N(void)
	{_result.type('N');_name="avg";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// sqsum(数値,...,数値) => 数値 : 平方合計(NULLはskip)
// -----------------------------------------------------------------------------
class kgFunction_sqsum : public kgFunction
{
	public:
	kgFunction_sqsum(void)
	{_result.type('N');_name="sqsum";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// sqsuma(数値,...,数値) => 数値 : 平方合計(1でもNULLが有ると結果はNULL)
// -----------------------------------------------------------------------------
class kgFunction_sqsum_N : public kgFunction
{
	public:
	kgFunction_sqsum_N(void)
	{_result.type('N');_name="sqsum";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// factorial(数値) => 数値 : 階乗計算
// -----------------------------------------------------------------------------
class kgFunction_factorial : public kgFunction
{
	public:
	kgFunction_factorial(void)
	{_result.type('N');_name="factorial";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// gcd(数値,数値) => 数値 : 最大公約数計算
// -----------------------------------------------------------------------------
class kgFunction_gcd : public kgFunction
{
	public:
	kgFunction_gcd(void)
	{_result.type('N');_name="gcd";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// lcm(数値,数値) => 数値 : 最小公倍数計算
// -----------------------------------------------------------------------------
class kgFunction_lcm : public kgFunction
{
	public:
	kgFunction_lcm(void)
	{_result.type('N');_name="lcm";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// sqrt(数値) => 数値 : 平方根計算
// -----------------------------------------------------------------------------
class kgFunction_sqrt : public kgFunction
{
	public:
	kgFunction_sqrt(void)
	{_result.type('N');_name="sqrt";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// fract(数値) => 数値 : 小数部分抽出
// -----------------------------------------------------------------------------
class kgFunction_fract : public kgFunction
{
	public:
	kgFunction_fract(void)
	{_result.type('N');_name="fract";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// int(数値) => 数値 : 整数部分抽出
// -----------------------------------------------------------------------------
class kgFunction_int : public kgFunction
{
	public:
	kgFunction_int(void)
	{_result.type('N');_name="int";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// min(数値,...,数値) => 数値 : 最小値計算(NULLはskip)
// -----------------------------------------------------------------------------
class kgFunction_min : public kgFunction
{
	public:
	kgFunction_min(void)
	{_result.type('N');_name="min";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// mina(数値,...,数値) => 数値 : 最小値計算(1でもNULLが有ると結果はNULL)
// -----------------------------------------------------------------------------
class kgFunction_min_N : public kgFunction
{
	public:
	kgFunction_min_N(void)
	{_result.type('N');_name="min";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// max(数値,...,数値) => 数値 : 最大値計算(NULLはskip)
// -----------------------------------------------------------------------------
class kgFunction_max : public kgFunction
{
	public:
	kgFunction_max(void)
	{_result.type('N');_name="max";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// maxa(数値,...,数値) => 数値 : 最大値計算(1でもNULLが有ると結果はNULL)
// -----------------------------------------------------------------------------
class kgFunction_max_N : public kgFunction
{
	public:
	kgFunction_max_N(void)
	{_result.type('N');_name="max";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// abs(数値) => 数値 : 絶対値計算
// -----------------------------------------------------------------------------
class kgFunction_abs : public kgFunction
{
	public:
	kgFunction_abs(void)
	{_result.type('N');_name="abs";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// round(数値1,数値2) => 数値 : 四捨五入計算(数値１を数値2の値で四捨五入)
// -----------------------------------------------------------------------------
class kgFunction_round : public kgFunction
{
	char _dblFmt[256]; // double型出力フォーマット
	public:
	kgFunction_round(void)
	{
		_result.type('N');_name="round";_minArgc=1;_maxArgc=2;
		sprintf(_dblFmt,"%%.%dg",KG_MAX_PRECISION);
	}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// power(数値1,数値2) => 数値 : べき乗計算(数値１を数値2の値でべき乗)
// -----------------------------------------------------------------------------
class kgFunction_power : public kgFunction
{
	public:
	kgFunction_power(void)
	{_result.type('N');_name="power";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// floor(数値1,数値2) => 数値 : 切捨計算(数値１を数値2の値で切り捨てて０に近い値にする)
// -----------------------------------------------------------------------------
class kgFunction_floor : public kgFunction
{
	char _dblFmt[256]; // double型出力フォーマット
	public:
	kgFunction_floor(void)
	{
		_result.type('N');_name="floor";_minArgc=1;_maxArgc=2;
		sprintf(_dblFmt,"%%.%dg",KG_MAX_PRECISION);
	}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// ceil(数値1,数値2) => 数値 : 切上計算(数値１を数値2の値で切り上げて０に遠い値にする)
// -----------------------------------------------------------------------------
class kgFunction_ceil : public kgFunction
{
	char _dblFmt[256]; // double型出力フォーマット

	public:
	kgFunction_ceil(void)
	{
		_result.type('N');_name="ceil";_minArgc=1;_maxArgc=2;
		sprintf(_dblFmt,"%%.%dg",KG_MAX_PRECISION);
	}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// exp(数値) => 数値 : eを底とするべき乗計算
// -----------------------------------------------------------------------------
class kgFunction_exp : public kgFunction
{
	public:
	kgFunction_exp(void)
	{_result.type('N');_name="exp";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// ln(数値) => 数値 : 自然対数計算
// -----------------------------------------------------------------------------
class kgFunction_ln : public kgFunction
{
	public:
	kgFunction_ln(void)
	{_result.type('N');_name="ln";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// log(数値) => 数値 : 対数計算
// -----------------------------------------------------------------------------
class kgFunction_log : public kgFunction
{
	public:
	kgFunction_log(void)
	{_result.type('N');_name="log";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// log2(数値) => 数値 : 2を底とする対数計算
// -----------------------------------------------------------------------------
class kgFunction_log2 : public kgFunction
{
	public:
	kgFunction_log2(void)
	{_result.type('N');_name="log2";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// log10(数値) => 数値 : 10を底とする対数計算
// -----------------------------------------------------------------------------
class kgFunction_log10 : public kgFunction
{
	public:
	kgFunction_log10(void)
	{_result.type('N');_name="log10";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// product(数値,...,数値) => 数値 : 数値すべての積(NULLはskip)
// -----------------------------------------------------------------------------
class kgFunction_product : public kgFunction
{
	public:
	kgFunction_product(void)
	{_result.type('N');_name="product";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// product_N(数値,...,数値) => 数値 : 数値すべての積(1でもNULLが有ると結果はNULL)
// -----------------------------------------------------------------------------
class kgFunction_product_N : public kgFunction
{
	public:
	kgFunction_product_N(void)
	{_result.type('N');_name="producta";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// sign(数値) => 数値 : 正負符号を判定する(正:1,負:-1,0:0)
// -----------------------------------------------------------------------------
class kgFunction_sign : public kgFunction
{
	public:
	kgFunction_sign(void)
	{_result.type('N');_name="sign";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// dist(距離関数名,数値,...,数値[2n]) => 数値 : n次元の2点の座標間のユークリッド距離を計算
// -----------------------------------------------------------------------------
class kgFunction_dist : public kgFunction
{
	unsigned int _dim;
	char _type;
	public:
	kgFunction_dist(void)
	{_result.type('N');_name="dist";_minArgc=5;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// disth(数値,...,数値[2n]) => 数値 : n次元の2点の座標間のハミング距離を計算
// -----------------------------------------------------------------------------
class kgFunction_disth : public kgFunction
{
	unsigned int _dim;
	public:
	kgFunction_disth(void)
	{_result.type('N');_name="dist";_minArgc=5;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// distgps(数値[緯度],数値[経度],数値[緯度],数値[経度]) => 数値 : 2点の緯度経度から距離を計算
// -----------------------------------------------------------------------------
class kgFunction_distgps : public kgFunction
{
	static const double Eradius_;
	public:
	kgFunction_distgps(void)
	{_result.type('N');_name="distgps";_minArgc=4;_maxArgc=4;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// heron(数値,...,数値[3n]) => 数値 : n次元の3点の座標によって作られる3角形の面積を計算
// -----------------------------------------------------------------------------
class kgFunction_heron : public kgFunction
{
	unsigned int _dim;
	public:
	kgFunction_heron(void)
	{_result.type('N');_name="heron";_minArgc=3;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// pi() => 数値 : PI
// -----------------------------------------------------------------------------
class kgFunction_pi : public kgFunction
{
	public:
	kgFunction_pi(void)
	{_result.type('N');_name="pi";_minArgc=0;_maxArgc=0;_result.r(M_PI);}
};
// -----------------------------------------------------------------------------
// e() => 数値 : ネイピア数
// -----------------------------------------------------------------------------
class kgFunction_e : public kgFunction
{
	public:
	kgFunction_e(void)
	{_result.type('N');_name="e";_minArgc=0;_maxArgc=0;_result.r(M_E);}
};
// -----------------------------------------------------------------------------
// rand(数値[最小値]，数値[最大数]，数値[シード]) => 数値 : 一様乱数を発生させる(整数)
// -----------------------------------------------------------------------------
class kgFunction_rand : public kgFunction
{
	kgAutoPtr1<boost::variate_generator< boost::mt19937,boost::uniform_int<>  > > _api;
	public:
	kgFunction_rand(void)
	{_result.type('N');_name="randi";_minArgc=2;_maxArgc=3;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// rand(数値[シード],"-real") => 数値 : 一様乱数を発生させる(実数)
// -----------------------------------------------------------------------------
class kgFunction_rand_real : public kgFunction
{
	kgAutoPtr1<boost::variate_generator< boost::mt19937,boost::uniform_real<> > > _apr;
	public:
	kgFunction_rand_real(void)
	{_result.type('N');_name="rand";_minArgc=0;_maxArgc=1;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// nrand(数値[平均値]，数値[標準偏差]，数値[シード]) => 数値 : 正規乱数を発生させる
// -----------------------------------------------------------------------------
class kgFunction_nrand : public kgFunction
{
	kgAutoPtr1<boost::variate_generator< boost::mt19937,boost::normal_distribution<> > > _ap;
	public:
	kgFunction_nrand(void)
	{_result.type('N');_name="nrand";_minArgc=2;_maxArgc=3;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// berrand(数値[?]，数値[シード]) => 数値 : ベルヌーイ分布に基づいた乱数生成
// -----------------------------------------------------------------------------
class kgFunction_berrand : public kgFunction
{
	kgAutoPtr1<boost::variate_generator< boost::mt19937,boost::bernoulli_distribution<> > > _ap;
	public:
	kgFunction_berrand(void)
	{_result.type('B');_name="berrand";_minArgc=1;_maxArgc=2;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// binomdist(数値[成功回数],数値[試行回数],数値[確率]) => 数値 : 二項分布の確率?
// -----------------------------------------------------------------------------
class kgFunction_binomdist : public kgFunction
{
	//size_t ub_;
	vector< vector<int> > pascal_;
	public:
	kgFunction_binomdist(void)
	{_result.type('N');_name="binomdist";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
	//virtual void preprocess(void);
};
// ============================================================================
// 三角関数関連クラス
// ============================================================================
// -----------------------------------------------------------------------------
// acos(数値) => 数値 : アークコサインを計算
// -----------------------------------------------------------------------------
class kgFunction_acos : public kgFunction
{
	public:
	kgFunction_acos(void)
	{_result.type('N');_name="acos";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// asin(数値) => 数値 : アークサインを計算
// -----------------------------------------------------------------------------
class kgFunction_asin : public kgFunction
{
	public:
	kgFunction_asin(void)
	{_result.type('N');_name="asin";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// atan(数値) => 数値 : アークタンジェントを計算
// -----------------------------------------------------------------------------
class kgFunction_atan : public kgFunction
{
	public:
	kgFunction_atan(void)
	{_result.type('N');_name="atan";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// atan2(数値1,数値2) => 数値 : x,y座標(数値1,数値2)と原点を結ぶ線分とx軸とが作る角度を計算する
// -----------------------------------------------------------------------------
class kgFunction_atan2 : public kgFunction
{
	public:
	kgFunction_atan2(void)
	{_result.type('N');_name="atan2";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// cos(数値) => 数値 : 数値(ラジアン)に相当するコサインを計算
// -----------------------------------------------------------------------------
class kgFunction_cos : public kgFunction
{
	public:
	kgFunction_cos(void)
	{_result.type('N');_name="cos";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// sin(数値) => 数値 : 数値(ラジアン)に相当するサインを計算
// -----------------------------------------------------------------------------
class kgFunction_sin : public kgFunction
{
	public:
	kgFunction_sin(void)
	{_result.type('N');_name="sin";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// tan(数値) => 数値 : 数値(ラジアン)に相当するタンジェントを計算
// -----------------------------------------------------------------------------
class kgFunction_tan : public kgFunction
{
	public:
	kgFunction_tan(void)
	{_result.type('N');_name="tan";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// degree(数値) => 数値 : 数値(ラジアン)を角度に変換する
// -----------------------------------------------------------------------------
class kgFunction_degree : public kgFunction
{
	public:
	kgFunction_degree(void)
	{_result.type('N');_name="degree";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// radian(数値) => 数値 : 数値(角度)をラジアンに変換する
// -----------------------------------------------------------------------------
class kgFunction_radian : public kgFunction
{
	public:
	kgFunction_radian(void)
	{_result.type('N');_name="radian";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// cosh(数値) => 数値 : 双曲線余弦(ハイパーボリックコサイン)を計算
// -----------------------------------------------------------------------------
class kgFunction_cosh : public kgFunction
{
	public:
	kgFunction_cosh(void)
	{_result.type('N');_name="cosh";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// sinh(数値) => 数値 : 双曲線正弦(ハイパーボリックサイン)を計算する
// -----------------------------------------------------------------------------
class kgFunction_sinh : public kgFunction
{
	public:
	kgFunction_sinh(void)
	{_result.type('N');_name="sinh";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// tanh(数値) => 数値 : 双曲線逆正接(ハイパーボリックタンジェントの逆関数)を計算する
// -----------------------------------------------------------------------------
class kgFunction_tanh : public kgFunction
{
	public:
	kgFunction_tanh(void)
	{_result.type('N');_name="tanh";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// ============================================================================
// 文字列関数クラス
// ============================================================================
// -----------------------------------------------------------------------------
// cat(文字列0，文字列1，...，文字列m) => 文字列 : 
//  文字列1...文字列mを文字列0（トークン）で結合する
// -----------------------------------------------------------------------------
class kgFunction_cat : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_cat(void)
	{_result.type('S');_name="cat";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// length(文字列) => 数値 : 文字列の長さを計算
// -----------------------------------------------------------------------------
class kgFunction_length : public kgFunction
{
	public:
	kgFunction_length(void)
	{_result.type('N');_name="length";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// lengthw(文字列) => 数値 : 文字列の長さを計算（マルチバイト文字文字用）
// -----------------------------------------------------------------------------
class kgFunction_lengthw : public kgFunction
{
	public:
	kgFunction_lengthw(void)
	{_result.type('N');_name="lengthw";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// fixlen(文字列,数値,文字1[R|L],文字2) => 文字列 : 
//   文字列を数値分固定長に変換(文字1はR:右詰orL:左詰,文字2は詰める文字)
// -----------------------------------------------------------------------------
class kgFunction_fixlen : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_fixlen(void)
	{_result.type('S');_name="fixlen";_minArgc=4;_maxArgc=4;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// fixlenw(文字列,数値,文字,文字) => 文字列 :(マルチバイト文字ベース)
//   文字列を数値分固定長に変換(文字1はR:右詰orL:左詰,文字2は詰める文字)
// -----------------------------------------------------------------------------
class kgFunction_fixlenw : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_fixlenw(void)
	{_result.type('S');_name="fixlenw";_minArgc=4;_maxArgc=4;}
	virtual void run(void);
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// right(文字列,数値) => 文字列 : 文字列を右から数値分抽出
// -----------------------------------------------------------------------------
class kgFunction_right : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_right(void)
	{_result.type('S');_name="right";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// rightw(文字列,数値) => 文字列 : 文字列を右から数値分抽出(マルチバイト文字ベース)
// -----------------------------------------------------------------------------
class kgFunction_rightw : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_rightw(void)
	{_result.type('S');_name="rightw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// left(文字列,数値) => 文字列 : 文字列を左から数値分抽出
// -----------------------------------------------------------------------------
class kgFunction_left : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_left(void)
	{_result.type('S');_name="left";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// leftw(文字列,数値) => 文字列 : 文字列を左から数値分抽出(マルチバイト文字ベース)
// -----------------------------------------------------------------------------
class kgFunction_leftw : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_leftw(void)
	{_result.type('S');_name="leftw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// mid(文字列,数値[開始位置],数値[抽出長]) => 文字列 :
//  文字列を左から開始位置と抽出長を指定して抽出する
// -----------------------------------------------------------------------------
class kgFunction_mid : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_mid(void)
	{_result.type('S');_name="mid";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// midw(文字列,数値[開始位置],数値[抽出長]) => 文字列 :(マルチバイト文字ベース)
//  文字列を左から開始位置と抽出長を指定して抽出する
// -----------------------------------------------------------------------------
class kgFunction_midw : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_midw(void)
	{_result.type('S');_name="midw";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// toupper(文字列) => 文字列 : 文字列をすべて大文字に変更
// -----------------------------------------------------------------------------
class kgFunction_toupper : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_toupper(void)
	{_result.type('S');_name="toupper";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// tolower(文字列) => 文字列 : 文字列をすべて小文字に変更
// -----------------------------------------------------------------------------
class kgFunction_tolower : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_tolower(void)
	{_result.type('S');_name="tolower";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// capitalize(文字列) => 文字列 : 文字列の先頭を大文字に変更
// -----------------------------------------------------------------------------
class kgFunction_capitalize : public kgFunction
{
	char _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_capitalize(void)
	{_result.type('S');_name="capitalize";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};

// -----------------------------------------------------------------------------
// match(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのいずれかに文字列0が存在すれば真，しなければ偽(全マッチ)
// -----------------------------------------------------------------------------
class kgFunction_match : public kgFunction
{
	public:
	kgFunction_match(void)
	{_result.type('B');_name="match";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// matcha(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのすべてに文字列0が存在すれば真，しなければ偽(全マッチ)
// -----------------------------------------------------------------------------
class kgFunction_matcha : public kgFunction
{
	public:
	kgFunction_matcha(void)
	{_result.type('B');_name="matcha";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// matchs(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのいずれかに文字列0が存在すれば真，しなければ偽(部分マッチ)
// -----------------------------------------------------------------------------
class kgFunction_matchs : public kgFunction
{
	public:
	kgFunction_matchs(void)
	{_result.type('B');_name="matchs";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// matchas(文字列0,文字列1,...,文字列n) => bool :
//   文字列1,...,文字列nのすべてに文字列0が存在すれば真，しなければ偽(部分マッチ)
// -----------------------------------------------------------------------------
class kgFunction_matchas : public kgFunction
{
	public:
	kgFunction_matchas(void)
	{_result.type('B');_name="matchas";_minArgc=2;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// hasspace(文字列) => bool : 文字列に空白があれば真，なければ偽
// -----------------------------------------------------------------------------
class kgFunction_hasspace : public kgFunction
{
	public:
	kgFunction_hasspace(void)
	{_result.type('B');_name="hasspace";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// hasspacew(文字列) => bool : 文字列に空白(全角半角空白)があれば真，なければ偽
// -----------------------------------------------------------------------------
class kgFunction_hasspacew : public kgFunction
{
	public:
	kgFunction_hasspacew(void)
	{_result.type('B');_name="hasspacew";_minArgc=1;_maxArgc=1;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// strchr(文字列,文字) => 数値 : 文字列の文字がある位置を調べる
// -----------------------------------------------------------------------------
class kgFunction_strchr : public kgFunction
{
	public:
	kgFunction_strchr(void)
	{_result.type('N');_name="strchr";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// ============================================================================
// 正規表現関連クラス
// ============================================================================
// -----------------------------------------------------------------------------
// 正規表現スーパークラス
// -----------------------------------------------------------------------------
class kgFunction_regex : public kgFunction
{
	protected:
	boost::xpressive::cregex _reg;
	public:	
	virtual void preprocess(void);

};
class kgFunction_regexw : public kgFunction
{
	protected:
	boost::xpressive::wsregex _reg;
	public:
	virtual void preprocess(void);
};
// -----------------------------------------------------------------------------
// regexs(文字列,文字列[正規表現]) => bool : 
//   文字列に対して正規表現がマッチする部分文字列があれば真を返す
// -----------------------------------------------------------------------------
class kgFunction_regexs : public kgFunction_regex
{
	public:
	kgFunction_regexs(void)
	{_result.type('B');_name="regexs";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexsw(文字列,文字列[正規表現]) => bool : (マルチバイト文字ベース)
//   文字列に対して正規表現がマッチする部分文字列があれば真を返す
// -----------------------------------------------------------------------------
class kgFunction_regexsw : public kgFunction_regexw
{
	public:
	kgFunction_regexsw(void)
	{_result.type('B');_name="regexsw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexm(文字列,文字列[正規表現]) => bool : 
//   文字列に対して正規表現が完全にマッチすれば真を返す
// -----------------------------------------------------------------------------
class kgFunction_regexm : public kgFunction_regex
{
	public:
	kgFunction_regexm(void)
	{_result.type('B');_name="regexm";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexmw(文字列,文字列[正規表現]) => bool : (マルチバイト文字ベース)
//   文字列に対して正規表現が完全にマッチすれば真を返す
// -----------------------------------------------------------------------------
class kgFunction_regexmw : public kgFunction_regexw
{
	public:
	kgFunction_regexmw(void)
	{_result.type('B');_name="regexmw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexrep(文字列,文字列[正規表現],文字列[置換文字列]) => 文字列 : 
//   文字列に対して正規表現がマッチする部分を置換文字列に置換する
// -----------------------------------------------------------------------------
class kgFunction_regexrep : public kgFunction_regex
{
	string _buf;
	public:
	kgFunction_regexrep(void)
	{_result.type('S');_name="regexrep";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexrepw(文字列,文字列[正規表現],文字列[置換文字列]) => 文字列 : (マルチバイト文字ベース)
//   文字列に対して正規表現がマッチする部分を置換文字列に置換する
// -----------------------------------------------------------------------------
class kgFunction_regexrepw : public kgFunction_regexw
{
	string  _buf;
	public:
	kgFunction_regexrepw(void)
	{_result.type('S');_name="regexrepw";_minArgc=3;_maxArgc=3;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexlen(文字列,文字列[正規表現]) => 数値 :
//  文字列に対して正規表現がマッチした長さを返す
// -----------------------------------------------------------------------------
class kgFunction_regexlen : public kgFunction_regex
{
	boost::xpressive::cmatch _mat;
	public:
	kgFunction_regexlen(void)
	{_result.type('N');_name="regexlen";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexlenw(文字列,文字列[正規表現]) => 数値 : (マルチバイト文字ベース)
//  文字列に対して正規表現がマッチした長さを返す
// -----------------------------------------------------------------------------
class kgFunction_regexlenw : public kgFunction_regexw
{
	boost::xpressive::wsmatch _mat;
	public:
	kgFunction_regexlenw(void)
	{_result.type('N');_name="regexlenw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexpos(文字列,文字列[正規表現]) => 数値 :
//  文字列に対して正規表現がマッチした先頭位置を返す
// -----------------------------------------------------------------------------
class kgFunction_regexpos : public kgFunction_regex
{
	boost::xpressive::cmatch _mat;
	public:
	kgFunction_regexpos(void)
	{_result.type('N');_name="regexpos";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexposw(文字列,文字列[正規表現]) => 数値 :(マルチバイト文字ベース)
//  文字列に対して正規表現がマッチした先頭位置を返す
// -----------------------------------------------------------------------------
class kgFunction_regexposw : public kgFunction_regexw
{
	boost::xpressive::wsmatch _mat;
	public:
	kgFunction_regexposw(void)
	{_result.type('N');_name="regexposw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexstr(文字列,文字列[正規表現]) => 文字列 :
//  文字列に対して正規表現がマッチする部分文字列を返す
// -----------------------------------------------------------------------------
class kgFunction_regexstr : public kgFunction_regex
{
	boost::xpressive::cmatch _mat;
	char   _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_regexstr(void)
	{_result.type('S');_name="regexstr";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexstrw(文字列,文字列[正規表現]) => 文字列 :(マルチバイト文字ベース)
//  文字列に対して正規表現がマッチする部分文字列を返す
// -----------------------------------------------------------------------------
class kgFunction_regexstrw : public kgFunction_regexw
{
	boost::xpressive::wsmatch _mat;
	string  _buf;
	public:
	kgFunction_regexstrw(void)
	{_result.type('S');_name="regexstrw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexpfx(文字列,文字列[正規表現]) => 文字列 :
//  文字列に対して正規表現がマッチした部分文字列の直前までの文字列を左から出力する
// -----------------------------------------------------------------------------
class kgFunction_regexpfx : public kgFunction_regex
{
	boost::xpressive::cmatch _mat;
	char   _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_regexpfx(void)
	{_result.type('S');_name="regexpfx";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexpfxw(文字列,文字列[正規表現]) => 文字列 :(マルチバイト文字ベース)
//  文字列に対して正規表現がマッチした部分文字列の直前までの文字列を左から出力する
// -----------------------------------------------------------------------------
class kgFunction_regexpfxw : public kgFunction_regexw
{
	boost::xpressive::wsmatch _mat;
	string  _buf;
	public:
	kgFunction_regexpfxw(void)
	{_result.type('S');_name="regexpfxw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexsfx(文字列,文字列[正規表現]) => 文字列 :
//  文字列に対して正規表現がマッチした部分文字列の直後から右方向に最後までの文字列を出力する
// -----------------------------------------------------------------------------
class kgFunction_regexsfx : public kgFunction_regex
{
	boost::xpressive::cmatch _mat;
	char   _buf[KG_MAX_STR_LEN];
	public:
	kgFunction_regexsfx(void)
	{_result.type('S');_name="regexsfx";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// regexsfxw(文字列,文字列[正規表現]) => 文字列 :(マルチバイト文字ベース)
//  文字列に対して正規表現がマッチした部分文字列の直後から右方向に最後までの文字列を出力する
// -----------------------------------------------------------------------------
class kgFunction_regexsfxw : public kgFunction_regexw
{
	boost::xpressive::wsmatch _mat;
	string  _buf;
	public:
	kgFunction_regexsfxw(void)
	{_result.type('S');_name="regexsfxw";_minArgc=2;_maxArgc=2;}
	virtual void run(void);
};
// ============================================================================
// 行項目関連
// ============================================================================
// -----------------------------------------------------------------------------
// line() => 数値 :処理行中番号の取得
// -----------------------------------------------------------------------------
class kgFunction_line : public kgFunction
{
	public:
	kgFunction_line(void)
	{_result.type('N');_name="line";_minArgc=0;_maxArgc=0;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// fldcnt() => 数値 :データ項目数の取得
// -----------------------------------------------------------------------------
class kgFunction_fldsize : public kgFunction
{
	public:
	kgFunction_fldsize(void)
	{_result.type('N');_name="fldsize";_minArgc=0;_maxArgc=0;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// top() => bool :先頭行チェック 先頭ならtrue
// -----------------------------------------------------------------------------
class kgFunction_top : public kgFunction
{
	public:
	kgFunction_top(void)
	{_result.type('B');_name="top";_minArgc=0;_maxArgc=0;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// bottom() => bool :最終行チェック 最終ならtrue
// -----------------------------------------------------------------------------
class kgFunction_bottom : public kgFunction
{
	public:
	kgFunction_bottom(void)
	{_result.type('B');_name="bottom";_minArgc=0;_maxArgc=0;}
	virtual void run(void);
};
// -----------------------------------------------------------------------------
// bottom() => bool :最終行チェック 最終ならtrue
// -----------------------------------------------------------------------------
class kgFunction_argsize : public kgFunction
{
	public:
	kgFunction_argsize(void)
	{_result.type('N');_name="argsize";_minArgc=1;_maxArgc=KG_MAX_CAL_TERMS;}
	virtual void run(void);
};

// ============================================================================
// 関数の検索map構造体
// ============================================================================
class kgFuncMap 
{
	typedef map<std::string, boost::function<kgFunction* ()> > func_map_t;

	func_map_t    _func_map; //keyword - 関数対応表
	vector<std::string> _func_vecREG;//正規表現

	kgAutoPtr1<kgFunction> _ap[KG_MAX_CAL_TERMS]; //関数クラスのアドレスを格納するスマートポインタ
	int _usedCnt; // 使用関数クラス数

	kgFunction* getSUB(const string& id);
public:
	// コンストラクタ(インデックスの作成)
	kgFuncMap(void);
	// 関数表のidを検索し，関数のbindアドレスを得る
	kgFunction* get(const string& id);
};


} //////////////////////////////////////////////////////////////// end namespace

