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

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <kgMethod.h>
#include <kgError.h>
#include <kgConfig.h>
#include <kgWildcard.h>
#include <boost/filesystem.hpp>

using namespace std;
using namespace kglib;
using namespace boost;

// -----------------------------------------------------------------------------
// 項目数のカウント
//  現在地から次の改行または\0までに項目数(,)を数える
//  DQで囲まれている場合は一つの項目とする
// -----------------------------------------------------------------------------
size_t kglib::cntFldToken(char *str, size_t maxRecLen,bool fmtErrSkip)
{
	char* border=str+maxRecLen;
	unsigned int fldCnt=0;
	while(1){
		if(*str=='"'){
			while(1){
				str++; if(str>=border) kgError::recLenErr(maxRecLen);
				if(*str=='"'){
					str++; if(str>=border) kgError::recLenErr(maxRecLen);
					if(*str==','){
						fldCnt++;
						str++; if(str>=border) kgError::recLenErr(maxRecLen);
						break;
					} else if( *str=='\n' || *str=='\r' || *str=='\0'){
						return fldCnt+1;
					} else if(*str!='"' && !fmtErrSkip){ 
						throw kgError("csv format error"); 
					}
				}else if(*str=='\0'){
					return fldCnt+1;
				}
			}
		}else{
			while(1){
				if(*str==','){
					fldCnt++;
					str++; if(str>=border) kgError::recLenErr(maxRecLen);
					break;
				} else if( *str=='\n' || *str=='\r' || *str=='\0'){
					return fldCnt+1;
				}
				str++; if(str>=border){ kgError::recLenErr(maxRecLen);}
			}
		}
	}
	return fldCnt;
}
// ----------------------------------------------------------------------------
// 行分割（DQ考慮しない）
// 現在地から次の改行を見つけて、\0に置換
// 返値:改行の位置
// ----------------------------------------------------------------------------
char* kglib::sepRecTokenNdq(char* str)
{
	char* border=str+KG_MaxRecLen;
	for( ; str<border; str++){
		if(*str=='\n'){
			*str='\0';
			if(*(str-1)=='\r') *(str-1)='\0';
			break;
		}
	}
	if(str>=border) kgError::recLenErr();
	return str;
}

// ----------------------------------------------------------------------------
// 行分割（DQ考慮）
// 現在地から次の改行を見つけて、\0に置換（DQに囲まれた改行は無視する）
// 返値:改行の位置
// ----------------------------------------------------------------------------
char* kglib::sepRecToken(char *str, size_t maxRecLen)
{
	char *border=str+maxRecLen;
	while(1){
		if(*str=='"'){
			str++;
			for( ; str<border; str++){
				// DQの判定
				if(*str=='"'){
					str++; if(str>=border) kgError::recLenErr();
							 if(*str==',' ){          ; str++; break;     }  
					else if(*str=='\n'){ *str='\0';        return str;}  
					else if(*str=='\r'){ *str='\0';        return str;}  
					else if(*str!='"') { throw kgError("csv format error"); } 
				}
			}
			if(str>=border) kgError::recLenErr();
		}else{
			for( ; str<border; str++){
						 if(*str==',' ){	        ; str++; break;     }
				else if(*str=='\n'){
					*str='\0';
					return str;
				}	//UNIX
			} 
			if(str>=border) kgError::recLenErr();
		}
	}
}
// ----------------------------------------------------------------------------
// 項目分割（DQ考慮しない）
// 次の改行までのコンマを見つけて、\0に置換、
// 改行も\0に置換
// pntに各項目の先頭アドレスもセットする。
// 改行を見つける前に予定項目数を超えた場合はエラー
// 返値:strの終端('\n'の位置)
// ----------------------------------------------------------------------------
char* kglib::sepFldTokenNdq(char **pnt, size_t fldCnt, char *str)
{
	size_t j=0;
	char *border=str+KG_MaxRecLen;
	while(1){
		if(j>=fldCnt){ kgError::fldCntErr(fldCnt,j+1); }
		*(pnt+j)=str; j++;
		for( ; str<border; str++){
					 if(*str==',' ){ *str='\0'; str++; break;		 }  
			else if(*str=='\n'){
				*str='\0';
				if(j==fldCnt){ return str;}
				else{kgError::fldCntErr(fldCnt,j);}	
			}	
		}
		if(str>=border) kgError::recLenErr();
	}
}
// ----------------------------------------------------------------------------
// 項目分割（DQ考慮しない）
// 次の改行までのコンマを見つけて、\0に置換、
// 改行も\0に置換
// pntに各項目の先頭アドレスもセットする。
// 改行を見つける前に予定項目数を超えた場合はエラー
// 返値:strの終端('\n'の位置)
// ----------------------------------------------------------------------------
char* kglib::sepFldToken(char **pnt, size_t fldCnt, char *str, size_t maxRecLen)
{
	size_t j=0;
	char *border=str+maxRecLen;
	char *rpt;
	while(1){
		if(j>=fldCnt){ kgError::fldCntErr(fldCnt,j+1);}
		rpt=str;
		if(*str=='"'){
			str++;rpt++;
			*(pnt+j)=str; j++;
			for( ; rpt<border; *(++str)=*(++rpt)){
				if(*str=='"'){
					*(++str)=*(++rpt); if(str>=border) kgError::recLenErr();
							 if(*str==',' ){ *(str-1)='\0'; str=rpt+1; break; }
					else if(*str=='\n'){
						*(str-1)='\0';
						if(j==fldCnt){ return rpt;}
						else{ kgError::fldCntErr(fldCnt,j);}
					}
					else if(*str=='"' ){ str--		    ;                   }
					else{ throw kgError("csv format error"); }
				}
			}
			if(str>=border) kgError::recLenErr();
		}else{
			*(pnt+j)=str;	j++;
			for( ; str<border; str++){
						 if(*str==',' ){ *str='\0'; str++; break;	    }
				else if(*str=='\n'){
					*str='\0';
					if(j==fldCnt){ return str;}
					else{ kgError::fldCntErr(fldCnt,j);}
				}
			}
			if(str>=border) kgError::recLenErr();
		}
	}
}

//recデータをコンマ単位で分割
//maxサイズの指定無し(arff2csvで利用している)
char* kglib::sepFldToken(char **pnt, size_t fldCnt, char *str)
{
	size_t j=0;
	char *border=str+strlen(str)+1;
	char *rpt;  // read pointer
	while(1){
		if(j>=fldCnt){
			kgError::fldCntErr(fldCnt,j+1);
		}
		rpt=str;
		// ダブルクオーツあり
		if(*str=='"'){
			str++;rpt++;
			*(pnt+j)=str; j++;
			for( ; rpt<border; *(++str)=*(++rpt)){
				// DQの判定
				if(*str=='"'){
					*(++str)=*(++rpt); if(str>=border) kgError::recLenErr();
							 if(*str==',' ){*(str-1)='\0'; str=rpt+1; break; } //Comma
					else if(*str=='\0'){
						*(str-1)='\0';return rpt; 
						//項目数のチェック
						if(j==fldCnt){ return rpt;}
						else{ 	kgError::fldCntErr(fldCnt,j);}
					}//'\0'
					else if(*str=='"' ){ str--		    ;                   } // DQ("")
				}
			}
			if(str>=border) kgError::recLenErr();
		// シングルクオーツあり
		}else if(*str=='\''){
			str++;rpt++;
			*(pnt+j)=str; j++;
			for( ; rpt<border; *(++str)=*(++rpt)){
				// DQの判定
				if(*str=='\''){
					*(++str)=*(++rpt); if(str>=border) kgError::recLenErr();
							 if(*str==',' ){ *(str-1)='\0'; str=rpt+1; break; } //Comma
					else if(*str=='\0'){
						*(str-1)='\0';
						//項目数のチェック
						if(j==fldCnt){ return rpt;}
						else{ 	kgError::fldCntErr(fldCnt,j);}
						return rpt;
					}//'\0'
					else if(*str=='\'' ){ str--		    ;                   } // SQ('')
				}
			}
			if(str>=border) kgError::recLenErr();
		}
		else if(*str==' '){//先頭がスペースは読み飛ばす
			str++;
			for( ; str<border; str++){
				if(*str!=' ') break;
			}			
		}
		else{
			*(pnt+j)=str;	j++;
			for( ; str<border; str++){
						 if(*str==',' ){ *str='\0'; str++; break;	    } //Comma
				else if(*str=='\0'){
					if(j==fldCnt){ return str;}
					else{ kgError::fldCntErr(fldCnt,j);}
				}
			}
			if(str>=border) kgError::recLenErr();
		}
	}
}

// 行のトークン分割 (LF,COMMA+DQ内のLF,COMMA無視)
// 返値:strの終端('\n'の位置)
// kgchkcsvで使用している
char* kglib::sepFldToken(char **pnt, size_t fldCnt, char *str,vector<bool> &sngDQ,vector<bool> &dqflg){
	unsigned int j=0;		 // 項目数カウント用
	char *border=str+strlen(str)+1;
	char *rpt;  // read pointer
	while(1){
		if(j>=fldCnt){
			kgError::fldCntErr(fldCnt,j);
		}
		rpt=str;
		// ダブルクオーツあり
		if(*str=='"'){
			dqflg[j]=true;
			str++;rpt++;
			*(pnt+j)=str; j++;
			for( ; rpt<border; *(++str)=*(++rpt)){
				// DQの判定
				if(*str=='"'){
					*(++str)=*(++rpt); if(str>=border) kgError::recLenErr();
							 if(*str==',' ){ *(str-1)='\0'; str=rpt+1; break; } //Comma
					else if(*str=='"' ){ str--		    ;                   } // DQ("")
					else if(*str=='\0' ){  *(str-1)='\0'; rpt++; return rpt;} //EOLなし\0
					else {sngDQ[j-1]=true;} //DQに囲われた中での単一DQ
				}
			}
			if(str>=border) kgError::recLenErr();
		// ダブルクオーツなし
		}else{
			*(pnt+j)=str;	j++;
			for( ; str<border; str++){
						 if(*str==',' ){ *str='\0'; str++; break;	    } //Comma
       else if(*str=='\0'){             str++; return str; } //EOLなし
			}
			if(str>=border) kgError::recLenErr();
		}
	}
}
// -----------------------------------------------------------------------------
// マルチバイト文字列をワイド文字列に変換 (mbs -> wcs)
// kgstr_tはkgConfig.hで定義されている.
//
// mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps);
// 「最大」でlen文字のワイド文字が書き出される(ちまたのマニュアル).
// 正確に言うと，srcをlenバイト分ワイド文字に変換する．
// ただし，最後のNULL文字を含めるとlen-1バイトが最大出力文字数となる．
//   ex. UTF-8では「あ」という文字は3バイトで構成される．
//       src=あああ+'\0' = 10バイト => lenが10以上であれば変換可能
//       src=123456789+'\0' 10バイト => 同じくlenが10以上であれば変換可能
//
// エラー対処)
// 1. len-1バイトを超えて書き込もうとするsrcがNULL以外にセットされる．
//    そこで，kgmodが扱える最大文字数KG_MAX_STR_LENをlenとし，
//    src!=NULLでエラー終了するようにする．
// 2. 不正なマルチバイト文字を検出すると -1が返される．
//    その場合もエラー終了とする．
//
// ワイド文字書き込み領域にheapでなくstackを使う理由は速度の問題から(2~3倍違う).
//
// -----------------------------------------------------------------------------
wstring kglib::toWcs(const char* mbs){

	wchar_t wcs[KG_MAX_STR_LEN];
	const char* p=mbs;
	// mbsrtowcs内部で利用されるシフト状態を保持する変数
  // 参考) http://www.linux.or.jp/JM/html/LDP_man-pages/man3/mbsinit.3.html
	mbstate_t ms;
	memset(&ms,0,sizeof(mbstate_t));
	if( mbsrtowcs(wcs, &p, KG_MAX_STR_LEN, &ms) == KG_SIZE_MAX ){
		throw kgError("invalid multibyte charactor is detected");
	}
	if( p!=NULL ){
		throw kgError("too long string (toWcs)");
	}
	return wcs;
}
wstring kglib::toWcs(const string& mbs){
	return toWcs(mbs.c_str());
}

// -----------------------------------------------------------------------------
// ワイド文字列をマルチバイト文字列に変換 (wcs -> mbs)
//
// toWcsの逆
// 書き込みバイト数(マルチ文字のバイト数)がKG_MAX_STR_LENを超えるとエラー終了．
// ex) ワイド文字列が「ああああ+'\0'」の４文字でも，マルチバイト文字に変換すると
// 12+1バイトのため変換エラーとなる．
// -----------------------------------------------------------------------------
string kglib::toMbs(const wchar_t* wcs){

	char mbs[KG_MAX_STR_LEN];
	const wchar_t* p=wcs;

	// Linuxでは""をwcsrtombsするとp!=NULLが返るので特殊処理する．
	// Macでは以下の３行なくても問題ないが．．．
	if(*wcs == '\0'){
		return "";
	}
	// mbsrtowcs内部で利用されるシフト状態を保持する変数
	mbstate_t ms;
	memset(&ms,0,sizeof(mbstate_t));

	if( wcsrtombs(mbs, &p, KG_MAX_STR_LEN, &ms) == KG_SIZE_MAX ){
		throw kgError("invalid wide charactor is detected");
	}
	if( p!=NULL ){
		throw kgError("too long string (toMbs)");
	}

	return mbs;
}

string kglib::toMbs(const wstring& wcs){
	return toMbs(wcs.c_str());
}
// -----------------------------------------------------------------------------
// escape文字(\)を以下のルールで評価し，strの内容を更新する．
// 1. \t =>タブ('\t')
// 2. \n =>改行('\n')
// 3. \r =>復帰('\r')
// 4. \\ => '\'
// -----------------------------------------------------------------------------
void kglib::evalEscape(kgstr_t& str){
  kgstr_t::size_type pos=0;
  while(1){
    if(str[pos] == '\0') break;
    if(str[pos] == '\\'){
    	str.erase(pos,1);
    	if(str[pos] != '\0'){
      	if(str[pos]=='t'){
        	str[pos]='\t';
				} else if(str[pos]=='n'){
        	str[pos]='\n';
				}
    		pos++;
			}
		}else{
			pos++;
		}
  }
  return;
}


// -----------------------------------------------------------------------------
// 数字項目番号を配列要素番号(0から始まる)に変換する．
// 末尾L後ろからの番号とする
// 例) CSVは6項目あるとする:1,2,3,4,5,6
//     0 => 0,  1L => 4
// -----------------------------------------------------------------------------
int kglib::evalDigit(kgstr_t& s, int fldSize)
{
	int num;
	string::size_type pos=s.find('L');
	int fldNo = atoi( s.c_str() );
	if(fldNo==0){
		if(s!="0"&&s!="0L"){
	    ostringstream ss;
  	  ss << s.c_str() << " is not a numerical value.";
   		throw kgError(ss.str());
		}
	} 
	if(fldSize>0 && ( fldNo <0 || fldNo >=fldSize)){
    ostringstream ss;
    ss << "the field number ("  << s.c_str() << ") is out of range (0-" << fldSize-1 << ")";
    throw kgError(ss.str());
	}
	if(pos!=string::npos){   // 末尾相対指定の場合
		num = fldSize - fldNo - 1;
	}else{
		num = fldNo;
	}
	return num;
}

// -----------------------------------------------------------------------------
// attrの'&'をnameで置き換える. 
// -----------------------------------------------------------------------------
void kglib::evalAttr(vector<kgstr_t>& name, vector<kgstr_t>& attr)
{
	for(string::size_type i=0; i<attr.size(); i++){
		kgstr_t s=attr.at(i);
		if( !attr.at(i).empty() ) {
			string::size_type pos=0;
			while(1){
				pos=attr.at(i).find("&",pos);
				if(pos==string::npos) break;
				attr.at(i).erase(pos,1);
				attr.at(i).insert(pos,name.at(i));
			}
		}
	}
}
// -----------------------------------------------------------------------------
// chr1が有るかチェック(ただしchr1+chr2ではない)mchkcsvのみ利用
// -----------------------------------------------------------------------------
bool kglib::hasSingleChr(char *fld, char chr1, char chr2){
  int i;
  int fldLen=strlen(fld);
  if(fldLen<1) return false;
  for(i=0; i<fldLen-1; i++){
    if(*(fld+i)==chr1 && *(fld+i+1)==chr2){
      i++;
      continue;
    }
    if(*(fld+i)==chr1){
      return true;
    }
  }
  return false;
}
// -----------------------------------------------------------------------------
// 末尾に指定文字が有るかチェック（ただし、すべて同じ文字の場合false）
// -----------------------------------------------------------------------------
bool kglib::hasBchr(char *fld, char chr){
  int i;
  int fldLen=strlen(fld);
  if(fldLen<1) return false;
  if(*(fld+fldLen-1)!=chr) return false;
  for(i=fldLen-1; i>=0; i--) if(*(fld+i)!=chr) return true;
  return false;
}
// -----------------------------------------------------------------------------
// 先頭＆末尾以外に指定文字が有るかチェック
// -----------------------------------------------------------------------------
bool kglib::hasMchr(char *fld, char chr){
  while(*fld!='\0' && *fld==chr) fld++;
  if(*fld=='\0') return false;
  while(*fld!='\0' && *fld!=chr) fld++;
  if(*fld=='\0') return false;
  while(*fld!='\0' && *fld==chr) fld++;
  if(*fld=='\0') return false;
  return true;
}
// -----------------------------------------------------------------------------
// eol削除
// -----------------------------------------------------------------------------
void kglib::rmEol(char* rec, int recLen){
  if(recLen>1){
    if(*(rec+recLen-2)=='\r' && *(rec+recLen-1)=='\n'){
    	*(rec+recLen-2)='\0'; *(rec+recLen-1)='\0';
    }else if(*(rec+recLen-1)=='\n'){
    	*(rec+recLen-1)='\0';
    }else if(*(rec+recLen-1)=='\r'){
    	*(rec+recLen-1)='\0';
    }
  }else if(recLen>0){
    if(*(rec+recLen-1)=='\n'){
    	*(rec+recLen-1)='\0';
    }else if(*(rec+recLen-1)=='\r'){
    	*(rec+recLen-1)='\0';
    }
  }
}

// -----------------------------------------------------------------------------
// delimで区切った場合の分割数
// str:'\0'で終了する文字列
// delim:区切り文字
// skip:trueで連続したtrueを一つとして扱う
// このメソッドは文字列DQは気にしなくていい状態になっていると想定する
// -----------------------------------------------------------------------------
size_t kglib::cntToken(char *str, char delim , bool skip)
{
	if(*str=='\0'){return 0;}
	size_t rtn_cnt=1;
	while(*str){
		if(*str == delim){
			rtn_cnt++;
			if(skip){ while(*(str+1)==delim){ str++; } }
		}
		str++;
	}
	return rtn_cnt;
}
// -----------------------------------------------------------------------------
// delimでトークン分割を行い分割された文字列をvectorで返す.
// escape文字は'\' 
// \delimにてdelim文字もescapeされる．
// char* 文字列用
// 例) ab,cd\,ef -> 0:ab 1:cd,ef
// skip:trueの場合連続したdelimおよび先頭、末尾のdelimは無視される
// -----------------------------------------------------------------------------
vector<char*> kglib::splitToken(char* str, char delim,bool skip)
{
  vector<char*> vs;
	size_t prv=0;
	size_t pos=0;
	while(1){
		if(*(str+pos) == '\0'){
			if(skip && prv == pos ){
				break;
			}
			if(pos!=0){
				vs.push_back(str+prv);
			}
			break;
		}else if(*(str+pos) == delim){
			if(skip && pos==0){
				while(*(str+pos+1)==delim){ pos++; }			
				prv=pos+1;
				pos++;
				continue;
			}
			*(str+pos) ='\0';
			vs.push_back(str+prv);
			if(skip){
				while(*(str+pos+1)==delim){ pos++; }
			}
			prv=pos+1;
		}
		pos++;
	}
	return vs;
}
// -----------------------------------------------------------------------------
// delimでトークン分割を行い分割された文字列をvectorで返す.
// escape文字は'\' 
// \delimにてdelim文字もescapeされる．
// string 文字列用
// 例) ab,cd\,ef -> 0:ab 1:cd,ef
// skip:trueの場合連続したdelimおよび先頭、末尾のdelimは無視される
// -----------------------------------------------------------------------------
vector<string> kglib::splitToken(string& str, char delim,bool skip)
{
  vector<string> vs;
	if(! str.empty()){
  	string::size_type prv=0;
  	string::size_type pos=0;
  	while(1){
    	if(str[pos] == L'\0'){
				if(skip && prv == pos ){
					break;
				}
				if(pos!=0){
  	    	vs.push_back(str.substr(prv, pos-prv));
  	    }
 				break;
			}
    	if(str[pos] == '\\'){
    		str.erase(pos,1);
    		if(str[pos] != L'\0'){
      		if(str[pos]=='t'){
        		str[pos]='\t';
					} else if(str[pos]=='n'){
        		str[pos]='\n';
					}
    			pos++;
				}
			}else if(str[pos] == delim){
				if(skip && pos==0){
					while(str[pos+1]==delim){ pos++; }			
					prv=pos+1;
					pos++;
					continue;
				}
      	vs.push_back(str.substr(prv, pos-prv));
				if(skip){
					while(str[pos+1]==delim){ pos++; }
				}
				prv = ++pos;
			}else{
				pos++;
			}
		}
  }
  return vs;
}
// -----------------------------------------------------------------------------
// delimでトークン分割を行い分割された文字列をvectorで返す.
// escape文字は'\' 
// \delimにてdelim文字もescapeされる．
// wstring 文字列用
// 例) ab,cd\,ef -> 0:ab 1:cd,ef
// skip:trueの場合連続したdelimおよび先頭、末尾のdelimは無視される
// -----------------------------------------------------------------------------
vector<wstring> kglib::splitToken(wstring& str, wchar_t delim){
  vector<wstring> vs;
	if(! str.empty()){
  	wstring::size_type prv=0;
  	wstring::size_type pos=0;
  	while(1){
    	if(str[pos] == L'\0'){
      	vs.push_back(str.substr(prv, pos-prv));
 				break;
			}
    	if(str[pos] == '\\'){
    		str.erase(pos,1);
    		if(str[pos] != L'\0'){
      		if(str[pos]=='t'){
        		str[pos]='\t';
					} else if(str[pos]=='n'){
        		str[pos]='\n';
					}
    			pos++;
				}
			}else if(str[pos] == delim){
      	vs.push_back(str.substr(prv, pos-prv));
				prv = ++pos;

			}else{
				pos++;
			}
		}
  }
  return vs;
}
// -----------------------------------------------------------------------------
// delim1,delim2でトークン分割を行い分割された文字列を2次元vectorで返す.
// escape文字は'\' \delim1 or \delim2 にてdelim文字もescapeされる．
// 例) str=> a:b:c,c\:d,e:f  vvs=> 0:(0:a 1:b 2:c) 1:(0:c:d) 2:(0:e 1:f)
// -----------------------------------------------------------------------------
vector<vector <kgstr_t> > kglib::splitToken2(kgstr_t& str, kgchr_t delim1, kgchr_t delim2 ){
  vector<kgstr_t> vs;
  vector<vector <kgstr_t> > vvs;
	if(! str.empty()){
  	kgstr_t::size_type prv=0;
  	kgstr_t::size_type pos=0;
  	while(1){
    	if(str[pos] == L'\0'){
      	vs.push_back(str.substr(prv, pos-prv));
				vvs.push_back(vs);
 				break;
			}

    	if(str[pos] == '\\'){
    		str.erase(pos,1);
    		if(str[pos] != L'\0'){
      		if(str[pos]=='t'){
        		str[pos]='\t';
					} else if(str[pos]=='n'){
        		str[pos]='\n';
					}
    			pos++;
				}

			}else if(str[pos] == delim2){
      	vs.push_back(str.substr(prv, pos-prv));
				prv = ++pos;

			}else if(str[pos] == delim1){
      	vs.push_back(str.substr(prv, pos-prv));
      	vvs.push_back(vs);
				vs.clear();
				prv = ++pos;

			}else{
				pos++;
			}
		}
  }
  return vvs;
}
// -----------------------------------------------------------------------------
// delim1,delim2でトークン分割を行い分割された文字列を2次元vectorで返す.
// delim2がkgstr_tバージョン
// escape文字は'\' \delim1 or \delim2 にてdelim文字もescapeされる．
// 例) str=> a:b:c,c\:d,e:f  vvs=> 0:(0:a 1:b 2:c) 1:(0:c:d) 2:(0:e 1:f)
// -----------------------------------------------------------------------------
vector<vector <kgstr_t> > kglib::splitToken2(kgstr_t& str, kgchr_t delim1, kgstr_t delim2 ){
  vector<kgstr_t> vs;
  vector<vector <kgstr_t> > vvs;
	if(! str.empty()){
  	kgstr_t::size_type prv=0;
  	kgstr_t::size_type pos=0;
  	while(1){
    	if(str[pos] == L'\0'){
      	vs.push_back(str.substr(prv, pos-prv));
				vvs.push_back(vs);
 				break;
			}
    	if(str[pos] == '\\'){
    		str.erase(pos,1);
    		if(str[pos] != L'\0'){
      		if(str[pos]=='t'){
        		str[pos]='\t';
					} else if(str[pos]=='n'){
        		str[pos]='\n';
					}
    			pos++;
				}
			}
			else if(delim2.find_first_of(str[pos])!=wstring::npos){
      	vs.push_back(str.substr(prv, pos-prv));
				prv = ++pos;
			}else if(str[pos] == delim1){
      	vs.push_back(str.substr(prv, pos-prv));
      	vvs.push_back(vs);
				vs.clear();
				prv = ++pos;
			}else{
				pos++;
			}
		}
  }
  return vvs;
}
// -----------------------------------------------------------------------------
// 2次元ベクトルを転置する．
//      a A          a b c
//      b B     ===> A B C
//      c C   
// in=a:A,b:B,c:C out=a:b:c,e:f:g
// NULL値がある場合
//   vvs=(a:A),(b),(c:C) vvs2=(a,b,c),(A,,C)
// rowSize=3: 行数が0以外の値であれば，出力行数を指定の値に強制出力する
// 　vvs=(a:A),(b),(c)   vvs2=(a,b,c),(A:b:c),(A:b:c)
// rowSize=0の場合は入力の最大列数を出力の行数とする．
// -----------------------------------------------------------------------------
vector<vector <kgstr_t> > kglib::transVector( const vector<vector <kgstr_t> >& vvs, unsigned int rowSize )
{
	typedef vector<vector <kgstr_t> >::size_type vvs_type;
	vvs_type max=0;
	if(rowSize==0){
		max=0;
		for(vvs_type i=0; i<vvs.size(); i++){
			if( max<vvs[i].size()) max=vvs[i].size();
		}
	}else{
		max=rowSize;
	}
 	vector<kgstr_t> vs2;
 	vector<vector <kgstr_t> > vvs2;
	for(vvs_type i=0; i<max; i++){
		vvs2.push_back(vs2);
	}
	for(vvs_type i=0; i<max ;i++){
		for(vvs_type j=0; j<vvs.size() ;j++){
			if(i < vvs[j].size()){
				vvs2[i].push_back(vvs[j][i]);
			}else{
				vvs2[i].push_back("");
			}
		}
	}
	return vvs2;
}
// -----------------------------------------------------------------------------
// intを文字列に変換する
// -----------------------------------------------------------------------------
kgstr_t kglib::toString(const int i, const string s1, const string s2){
	ostringstream ss;
	ss << s1 << i << s2;
	return ss.str();
}
// -----------------------------------------------------------------------------
// int vectorをカンマ区切りの文字列に変換する
// vi=(0,1,2) add=1 dlm="," s1=${ s2=}  -> ${1},${2},$(3}
// -----------------------------------------------------------------------------
kgstr_t kglib::toString(const vector<int>& vi, int add, const string dlm, const string s1, const string s2)
{
	ostringstream ss;
	vector<int>::size_type i;
	vector<int>::size_type size=vi.size();
	if(size>0){
		for( i=0; i<size-1; i++){
			ss << s1 << vi[i]+add << s2 << ",";
		}	
		ss << s1 << vi[i]+add << s2;
	}
	return ss.str();
}

// -----------------------------------------------------------------------------
// kgstr_t vectorをカンマ区切りの文字列に変換する
// -----------------------------------------------------------------------------
kgstr_t kglib::toString(const vector<kgstr_t>& vs, const string dlm, const string s1, const string s2)
{
	ostringstream ss;
	vector<kgstr_t> ::size_type i;
	vector<kgstr_t> ::size_type size=vs.size();
	if(size>0){
		for( i=0; i<size-1; i++){
			ss << s1 << vs[i] << s2 << ",";
		}	
		ss << s1 << vs[i] << s2;
	}
	return ss.str();
}
// -----------------------------------------------------------------------------
// 文字列としての日付を年月日の整数変数にセットする関数
// 返値：trueで成功, falseで変換失敗
// 利用関数例: kgFunction_constant_date::initialize(string str)
// -----------------------------------------------------------------------------
bool kglib::date_set(const char * str,int *y,int *m,int *d)
{
	size_t len = strlen(str);
	if(len!=8){ return false;}
	char y_str[8],m_str[8],d_str[8];
	strncpy(y_str,str  ,4);
	strncpy(m_str,str+4,2);
	strncpy(d_str,str+6,2);
	*(y_str+4)='\0';
	*(m_str+2)='\0';
	*(d_str+2)='\0';
	*y = atoi(y_str);
	*m = atoi(m_str);
	*d = atoi(d_str);
	return true;
}
// -----------------------------------------------------------------------------
// 文字列としての日付を時,分,秒の整数変数にセットする関数
// 返値：trueで成功, falseで変換失敗
// 利用関数例: kgFunction_constant_time::initialize(string str)
// -----------------------------------------------------------------------------
bool kglib::time_set(const char * str,int *h,int *m,int *s)
{
	size_t len = strlen(str);
	if(len!=6){ return false;}
	char h_str[6],m_str[6],s_str[6];
	strncpy(h_str,str  ,2);
	strncpy(m_str,str+2,2);
	strncpy(s_str,str+4,2);
	*(h_str+2)='\0';
	*(m_str+2)='\0';
	*(s_str+2)='\0';
	*h = atoi(h_str);
	*m = atoi(m_str);
	*s = atoi(s_str);
	return true;
}
// -----------------------------------------------------------------------------
// 文字列としての日付を時,分,秒の整数変数にセットする関数
// 返値：trueで成功, falseで変換失敗
// 利用関数例: kgFunction_constant_time::initialize(string str)
// -----------------------------------------------------------------------------
bool kglib::utime_set(const char * str,int *h,int *m,int *s,int *us, int resolv)
{
	size_t dtlen = 7; 
	// 分解能によって取得する桁数変更 最大6桁
	size_t flenMax = 6; 
	
	if(flenMax > resolv){ flenMax = resolv; }
	size_t len = strlen(str);
	if(len<=dtlen){ return false;}
	
	size_t flen = len - dtlen; 
	if(flen > flenMax) flen = flenMax;

	char h_str[8],m_str[8],s_str[8],us_str[16];
	strncpy(h_str,str  ,2);
	strncpy(m_str,str+2,2);
	strncpy(s_str,str+4,2);
	strncpy(us_str,str+dtlen,flen);

	// 桁合わせ
	for(size_t i=flen;i<resolv;i++){
		us_str[i] = '0';
	}

	*(h_str+2)='\0';
	*(m_str+2)='\0';
	*(s_str+2)='\0';
	*(us_str+resolv)='\0';
	*h = atoi(h_str);
	*m = atoi(m_str);
	*s = atoi(s_str);
	*us = atoi(us_str);
	return true;
}


// -----------------------------------------------------------------------------
// 文字列としての日付を年月日時分秒の整数変数にセットする関数
// 返値：trueで成功, false以外で変換失敗
// 利用関数例: kgFunction_constant_time::initialize(string str)
// -----------------------------------------------------------------------------
bool kglib::ptime_set(const char * str,int *yr, int *mo, int *dy, int *hr,int *mi,int *sc)
{
	size_t len = strlen(str);
	if(len!=14){ return false;}
	char yr_str[6],mo_str[6],dy_str[6];
	char hr_str[6],mi_str[6],sc_str[6];

	strncpy(yr_str,str,   4);
	strncpy(mo_str,str+ 4,2);
	strncpy(dy_str,str+ 6,2);
	strncpy(hr_str,str+ 8,2);
	strncpy(mi_str,str+10,2);
	strncpy(sc_str,str+12,2);
	*(yr_str+4)='\0';
	*(mo_str+2)='\0';
	*(dy_str+2)='\0';
	*(hr_str+2)='\0';
	*(mi_str+2)='\0';
	*(sc_str+2)='\0';
	*yr = atoi(yr_str);
	*mo = atoi(mo_str);
	*dy = atoi(dy_str);
	*hr = atoi(hr_str);
	*mi = atoi(mi_str);
	*sc = atoi(sc_str);
	return true;
}
// -----------------------------------------------------------------------------
// 文字列としての日付を年月日時分秒.小数点以下の整数変数にセットする関数
// 返値：trueで成功, false以外で変換失敗
// 利用関数例: kgFunction_constant_time::initialize(string str)
// -----------------------------------------------------------------------------
bool kglib::putime_set(const char * str,int *yr, int *mo, int *dy, int *hr,int *mi,int *sc,int *usc ,int resolv)
{
	size_t dtlen = 15; 
	// 分解能によって取得する桁数変更 最大6桁
	size_t flenMax = 6; 

	if(flenMax > resolv){ flenMax = resolv; }
	size_t len = strlen(str);
	if(len<=dtlen){ return false;}

	size_t flen = len - dtlen; 
	if(flen > flenMax) flen = flenMax;

	char yr_str[8],mo_str[8],dy_str[8];
	char hr_str[8],mi_str[8],sc_str[8];
	char usc_str[16];
	strncpy(yr_str,str,   4);
	strncpy(mo_str,str+ 4,2);
	strncpy(dy_str,str+ 6,2);
	strncpy(hr_str,str+ 8,2);
	strncpy(mi_str,str+10,2);
	strncpy(sc_str,str+12,2);
	strncpy(usc_str,str+dtlen,flen);
	// 桁合わせ
	for(size_t i=flen;i<resolv;i++){
		usc_str[i] = '0';
	}
	*(yr_str+4)='\0';
	*(mo_str+2)='\0';
	*(dy_str+2)='\0';
	*(hr_str+2)='\0';
	*(mi_str+2)='\0';
	*(sc_str+2)='\0';
	*(usc_str+resolv)='\0';
	*yr = atoi(yr_str);
	*mo = atoi(mo_str);
	*dy = atoi(dy_str);
	*hr = atoi(hr_str);
	*mi = atoi(mi_str);
	*sc = atoi(sc_str);
	*usc = atoi(usc_str);

	return true;
}


// -----------------------------------------------------------------------------
// null値考慮型割り算
// -----------------------------------------------------------------------------
bool kglib::kgDiv(double* val, char* a, char* b)
{
	if(*a=='\0' || *b=='\0'){
		return true;
	}
	double x=atof(a);
	double y=atof(b);
	if(y==0){
		return true;
	}else{
		*val=x/y;
		return false;
	}
}
// -----------------------------------------------------------------------------
// 最大公約数
// -----------------------------------------------------------------------------
int kglib::gcd(int x, int y)
{
	if(y==0) return x;
	return gcd(y, x%y);
}
// -----------------------------------------------------------------------------
// 最小公倍数
// -----------------------------------------------------------------------------
int kglib::lcm(int x, int y)
{
	return abs(x)/gcd(x,y)*abs(y);
}
// -----------------------------------------------------------------------------
// 正しい項目名か調べる
// 項目名使用不可文字（,*?:&\）が含まれていないかチェック
// %をOKにする 2014/05/02
// -----------------------------------------------------------------------------
bool kglib::chkFldName(kgstr_t str)
{
	if(str.find_first_of(",*?:&\\")!=string::npos)   return false;
	else															return true;                  					
}

	// path:検索する検索するデイレクトリ
	static	void kgFilesearch_sub(vector<kgstr_t>& ptn, kgstr_t path,vector<kgstr_t>& rtn,unsigned int lvl){
		bool out_flg = false;
		kgWildCard *wc = new kgWildCard(path+"/"+ptn[lvl]);
		
		if(ptn.size()==lvl+1) { out_flg = true;}

		filesystem::path dir=filesystem::path(path+"/");
		filesystem::directory_iterator it(dir);
		filesystem::directory_iterator end;
		for(; it!=end; ++it){
			filesystem::path p = *it;
			if( wc->match( p.string() ) ){
				if( is_directory(p) && !out_flg ){
					kgFilesearch_sub(ptn,p.string(),rtn,lvl+1);
				}
				else if( !is_directory(p) && out_flg){
					rtn.push_back(p.string());
				}
			}
		}
		delete wc;
	}
	
	static kgstr_t tildeReplace(kgstr_t& str)
	{
		kgstr_t tmps=str;
		if(tmps.size()<2){ return tmps; }
		if(tmps[0]=='~' && tmps[1]=='/'){
			char * envStr=getenv("HOME");
			tmps.replace(0,1,envStr);
			return tmps;
		}
		return tmps;
	}
	
	//ファイル名検索
	//指定したファイル名のファイルが存在するか探して存在するならファイル名をセットしなおす
	//ワイルドカードを使用している場ファイル名の展開も行う。
	//boostを使用
	// skipがtrueなら直ファイル名がなくてもエラーとしない
	// stdinFlgがtrueならば，vectorの先頭に""を追加する．	
	vector<kgstr_t> kglib::kgFilesearch(vector<kgstr_t>& vs, bool skip, bool stdinFlg,bool glob){
		vector<kgstr_t> r_vs;
		if(stdinFlg) r_vs.push_back("");
		for(vector<kgstr_t>::size_type i=0;i<vs.size();i++){
			//ワイルドカードを含むかチェック
			kgstr_t::size_type pos =vs[i].find_first_of("*?");
			//含まなければファイルが存在することをチェックしてファイル名を格納(glob展開しない場合も)
			if(!glob || pos == kgstr_t::npos){
				filesystem::path filename=filesystem::path(tildeReplace(vs[i]));
				if( exists(filename) && !is_directory(filename) ){
					r_vs.push_back(filename.string());
				}else{
					if(!skip){
						ostringstream ss;
						ss << "file not found : " << filename.string();
						throw kgError(ss.str());
					}
			  }
			}
			//含まむときは検索するディレクトリを決めてからファイル検索する
			//ディレクトリ階層ごとに検索する
			else{
				unsigned int lvl=1; 
				kgstr_t fname = tildeReplace(vs[i]);
				//絶対パスでなければ絶対パス変更する
				if (fname[0]!='/'){
					fname = boost::filesystem::current_path().string() + '/' + vs[i];			
				}
				vector<kgstr_t> vss = splitToken(fname,'/');
				vector<kgstr_t> vsss;
				for(vector<kgstr_t>::size_type i=0;i<vss.size();i++){
					if(vss[i]==".")				{ continue;}
					else if(vss[i]=="..")	{ vsss.pop_back();}
					else									{ vsss.push_back(vss[i]);}
				}
				// 分割した１項目めが""なら全体パス
				kgFilesearch_sub(vsss,"",r_vs,lvl);
			}
	}
	return r_vs;
}

size_t kglib::aToSizeT(const char * str)
{
	size_t val = 0;
	if(*str=='\0'){ throw kgError("error :not number in a2size_t");}
	if(*str<'0' || *str>'9'){ throw kgError("error :not number in a2size_t");}
	val = *str-'0';
	if(val==0 && *(str+1)!='\0'){ throw kgError("error :not number in a2size_t"); }
	for(const char *p = str+1 ;*p ; p++){
		if(*p<'0' || *p>'9'){ throw kgError("error :not number in a2size_t");}
		val = val * 10 + (*p-'0');
	}
	return val;
}

