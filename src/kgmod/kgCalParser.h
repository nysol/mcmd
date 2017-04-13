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
// kgCalParser.h kgcal,kgselで用いる構文解析パーサークラス
// =============================================================================
#pragma once
#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/classic_utility.hpp>
#include <boost/spirit/include/classic_ast.hpp>
#include <kgFunction.h>

using namespace boost::spirit::classic;
using namespace std;

namespace kgmod { ////////////////////////////////////////////// start namespace

struct kgCalParser : public grammar<kgCalParser>{
public:
	// paserタグのセット
	// 目的：parse時に定数，項目，関数(演算子)の区別を構文木のノードに
	// 記録しておくため．setparamにてこのIDに基づき定数は値として評価し，
	// 項目はCSVデータにおける項目番号として評価し，そして関数・演算子は
	// 関数クラスのインスタンス化を行う．
	// これらの値は構文木ノード構造体(struct tree_node)のメンバーである
	// データ値構造体(struct node_val_data)のメンバーidにセットされる
	static const int exprID       =  0; // 0固定
	static const int constIDstr   =  1;
	static const int constIDreal  =  2;
	static const int constIDdate  =  3;
	static const int constIDtime  =  4;
	static const int constIDbool  =  5;
	static const int fieldIDstr   =  6;
	static const int fieldIDreal  =  7;
	static const int fieldIDdate  =  8;
	static const int fieldIDtime  =  9;
	static const int fieldIDbool  = 10;
	static const int pfieldIDstr  = 11;
	static const int pfieldIDreal = 12;
	static const int pfieldIDdate = 13;
	static const int pfieldIDtime = 14;
	static const int pfieldIDbool = 15;

	static const int constIDutime  = 16;
	static const int fieldIDutime  = 17;
	static const int pfieldIDutime = 18;



	template<typename ScannerT> struct definition{

		// 項目値用(文字列,整数,実数,日付,時刻,bool)
		rule<ScannerT, parser_context<>, parser_tag<fieldIDstr > > field_str;
		rule<ScannerT, parser_context<>, parser_tag<fieldIDreal> > field_real;
		rule<ScannerT, parser_context<>, parser_tag<fieldIDdate> > field_date;
		rule<ScannerT, parser_context<>, parser_tag<fieldIDtime> > field_time;
		rule<ScannerT, parser_context<>, parser_tag<fieldIDbool> > field_bool;
		rule<ScannerT, parser_context<>, parser_tag<fieldIDutime> > field_utime;

		// 前行項目値用(文字列,整数,実数,日付,時刻,bool)
		rule<ScannerT, parser_context<>, parser_tag<pfieldIDstr > > pfield_str;
		rule<ScannerT, parser_context<>, parser_tag<pfieldIDreal> > pfield_real;
		rule<ScannerT, parser_context<>, parser_tag<pfieldIDdate> > pfield_date;
		rule<ScannerT, parser_context<>, parser_tag<pfieldIDtime> > pfield_time;
		rule<ScannerT, parser_context<>, parser_tag<pfieldIDbool> > pfield_bool;
		rule<ScannerT, parser_context<>, parser_tag<pfieldIDutime> > pfield_utime;

		// 定数値用(文字列,整数,実数,日付,時刻,bool)
		rule<ScannerT, parser_context<>, parser_tag<constIDstr > > const_str;
		rule<ScannerT, parser_context<>, parser_tag<constIDreal> > const_real;
		rule<ScannerT, parser_context<>, parser_tag<constIDdate> > const_date;
		rule<ScannerT, parser_context<>, parser_tag<constIDtime> > const_time;
		rule<ScannerT, parser_context<>, parser_tag<constIDbool> > const_bool;
		rule<ScannerT, parser_context<>, parser_tag<constIDutime> > const_utime;

		//関数・演算子用
		rule<ScannerT, parser_context<>, parser_tag<exprID> >
			term1,term2,term3,term4,term5,term6,term7,term8,expr,
			function1,function2,fctr;
			
		// 文法定義(コンストラクタ)
		definition(const kgCalParser& self){

			// -----------------------------------------------------------------------
			// [項目の指定] $x{xxx}の部分
			// ${項目名}   : 数値, 12  12.1
			// $s{項目名}  : 文字, "abc"
			// $d{項目名}  : 日付, 20080912
			// $t{項目名}  : 時刻, 121522
			// -----------------------------------------------------------------------
			// 文字列項目指定
			field_str = discard_node_d[*space_p >> str_p("$s{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 数値項目指定
			field_real = discard_node_d[*space_p >> str_p("${")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 日付項目指定
			field_date =  discard_node_d[*space_p >> str_p("$d{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 時刻項目指定
			field_time = discard_node_d[*space_p >> str_p("$t{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// マイクロ時刻項目指定
			field_utime = discard_node_d[*space_p >> str_p("$u{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// bool項目指定
			field_bool = discard_node_d[*space_p >> str_p("$b{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// -----------------------------------------------------------------------
			// [前行項目の指定]
			// #{項目名}   : 数値, 12  12.1
			// #s{項目名}  : 文字, "abc"
			// #d{項目名}  : 日付, 20080912
			// #t{項目名}  : 時刻, 121522
			// -----------------------------------------------------------------------
			// 文字列項目指定
			pfield_str = discard_node_d[*space_p >> str_p("#s{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') | eps_p ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 数値項目指定
			pfield_real = discard_node_d[*space_p >> str_p("#{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') | eps_p ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 日付項目指定
			pfield_date =  discard_node_d[*space_p >> str_p("#d{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') | eps_p ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 時刻項目指定
			pfield_time = discard_node_d[*space_p >> str_p("#t{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') | eps_p ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// 小数点時刻項目指定
			pfield_utime = discard_node_d[*space_p >> str_p("#u{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') | eps_p ]]
				>> discard_node_d[ch_p('}') >> *space_p];


			// bool項目指定
			pfield_bool = discard_node_d[*space_p >> str_p("#b{")]
				>> lexeme_d[leaf_node_d[ *(anychar_p-'}') | eps_p ]]
				>> discard_node_d[ch_p('}') >> *space_p];

			// -----------------------------------------------------------------------
			// [定数の指定]
			// const_str  : 文字列, "abc"
			// const_real : 数値, 12 12.1
			// const_date : 日付, 0d20080912
			// const_time : 日付, 0t20080912121102
			// const_bin  : 2進数, 0b110100
			// const_oct  : 8進数, 0b7022
			// const_hex  : 16進数,0x8bff
			// -----------------------------------------------------------------------
			// 文字列の指定 "xxx"の部分
			const_str  = discard_node_d[*space_p >> ch_p('\"')]
	  		>> lexeme_d[leaf_node_d[*(c_escape_ch_p-'\"')]]
				>> discard_node_d[ch_p('\"') >> *space_p];

			// 数値の指定
			const_real = discard_node_d[*space_p]
			  >> leaf_node_d[real_p]
			  >> discard_node_d[*space_p];

			// 日付の指定
			const_date = discard_node_d[*space_p >> str_p("0d")]
				>> lexeme_d[leaf_node_d[repeat_p(8)[digit_p]]]
				>> discard_node_d[*space_p];

			// 時刻の指定
//			const_time = discard_node_d[*space_p >> str_p("0t")]
//				>> lexeme_d[leaf_node_d[repeat_p(14)[digit_p] | repeat_p(6)[digit_p] ]]
//				>> discard_node_d[*space_p];

			// 小数点時刻の指定
			const_time = discard_node_d[*space_p >> str_p("0t")]
				>> lexeme_d[leaf_node_d[ ( (repeat_p(14)[digit_p] | repeat_p(6)[digit_p] ) >> ch_p('.') >> repeat_p(1,6)[digit_p]) | repeat_p(14)[digit_p] | repeat_p(6)[digit_p] ]]
				>> discard_node_d[*space_p];


			// boolの指定
			const_bool = discard_node_d[*space_p >> str_p("0b")]
				>> lexeme_d[leaf_node_d[ch_p('0') | ch_p('1')]]
				>> discard_node_d[*space_p];

			// -----------------------------------------------------------------------
			// [関数の指定] 
			// function1 : 引数をとる関数, fff(x1,x2,...)
			// function2 : 引数をとらない関数, fff()
			// -----------------------------------------------------------------------
			// 引数をとる関数
			function1 = root_node_d[
				discard_node_d[*space_p] >> 
					leaf_node_d[
				   alpha_p >> *(alpha_p|digit_p|ch_p('_'))]]
				>> discard_node_d[ch_p('(') >> *space_p]
				>> ( expr % discard_node_d[ch_p(',') >> *space_p])
				>> discard_node_d[ch_p(')')]>> discard_node_d[*space_p];

			// 引数をとらない関数
			function2 = root_node_d[
				discard_node_d[*space_p] >> 
				leaf_node_d[alpha_p >> *(alpha_p|digit_p)]]
				>> discard_node_d[str_p("(") >> *space_p >> str_p(")")]
				>> discard_node_d[*space_p];

			// 二項演算子の指定 (優先順位込み)
			expr = term7 % root_node_d[
			                 discard_node_d[*space_p] >>
			                 str_p("||")              >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
 			                 str_p("^^")              >>
			                 discard_node_d[*space_p]
			               ];

			term7= term4 % root_node_d[
			                 discard_node_d[*space_p] >>
			                 str_p("&&")              >>
			                 discard_node_d[*space_p]
			               ];

			term4= term3 % root_node_d[
			                 discard_node_d[*space_p] >>
			                 str_p("==")              >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
			                 str_p("!=")              >>
			                 discard_node_d[*space_p] 
			               ];

			term3= term2 % root_node_d[
			                 discard_node_d[*space_p] >>
			                 str_p(">=")              >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
			                 str_p("<=")              >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
			                 str_p(">")               >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
 			                 str_p("<")               >>
			                 discard_node_d[*space_p]
			               ];

			term2= term1 % root_node_d[
			                 discard_node_d[*space_p] >>
			                 str_p("+")              >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
			                 str_p("-")               >>
			                 discard_node_d[*space_p]
			               ];

			term1= fctr  % root_node_d[
			                 discard_node_d[*space_p] >>
			                 str_p("*")               >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
			                 str_p("/")               >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
			                 str_p("%")               >>
			                 discard_node_d[*space_p] |
			                 discard_node_d[*space_p] >>
 			                 str_p("^")               >>
			                 discard_node_d[*space_p]
			               ];

			fctr = function2  | function1  | const_date | const_utime | const_time  |
 			       const_bool | const_real | const_str  | 
			       field_str  | field_real | field_date | field_time | field_bool | field_utime |
						 pfield_str |pfield_real |pfield_date |pfield_time |pfield_bool |pfield_utime |
			       inner_node_d[discard_node_d[*space_p]>>'('>>discard_node_d[*space_p]>>expr>>')'>>discard_node_d[*space_p]>>discard_node_d[*space_p]];		
		}
		rule<ScannerT, parser_context<>, parser_tag<exprID> >
		const& start() const {return expr;}
	};
};

} //////////////////////////////////////////////////////////////////////////////

