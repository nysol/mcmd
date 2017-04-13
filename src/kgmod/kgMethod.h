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
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <kgConfig.h>

using namespace std;

namespace kglib {////////////////////////////////////////////// namespace start

vector<kgstr_t> kgFilesearch(vector<kgstr_t>& vs, bool skip=false, bool stdinFlg=false,bool glob=true);

wstring toWcs(const string& mbs);
wstring toWcs(const char* mbs);
string  toMbs(const wchar_t* wcs);
string  toMbs(const wstring& wcs);
void evalEscape(kgstr_t& str);
int evalDigit(kgstr_t& s, int fldSize);
void evalAttr(vector<kgstr_t>& name, vector<kgstr_t>& attr);

bool hasSingleChr(char *fld, char chr1, char chr2);
bool hasBchr(char *fld, char chr);
bool hasMchr(char *fld, char chr);
void rmEol(char* rec, int recLen);

size_t cntFldToken(char *str, size_t maxRecLen,bool fmtErrSkip=false);
char* sepRecTokenNdq(char* str);
char* sepRecToken(char *str, size_t maxRecLen); 

char* sepFldToken(char **pnt, size_t fldCnt, char *str); 
char* sepFldToken(char **pnt, size_t fldCnt, char *str, vector<bool> &sngDQ,vector<bool> &dqflg);
char* sepFldToken(char **pnt, size_t fldCnt, char *str, size_t maxRecLen); 
char* sepFldTokenNdq(char **pnt, size_t fldCnt, char *str); 

//データの終了が\0
vector<char*> splitToken(char* str, char delim,bool skip=false);
vector<string> splitToken(string& str, char delim,bool skip=false);
vector<wstring> splitToken(wstring& str, wchar_t delim);
vector<vector <kgstr_t> > splitToken2(kgstr_t& str, kgchr_t delim1, kgchr_t delim2);
vector<vector <kgstr_t> > splitToken2(kgstr_t& str, kgchr_t delim1, kgstr_t delim2);
vector<vector <kgstr_t> > transVector(const vector<vector <kgstr_t> >& vvs, unsigned int rowSize);
size_t cntToken(char* str, char delim,bool skip=false);

kgstr_t toString(const int i, const string s1="", const string s2="");
kgstr_t toString(const vector<int>& vi, int add=0, const string dlm=",", const string s1="", const string s2="");
kgstr_t toString(const vector<kgstr_t>& vs, const string dlm=",", const string s1="", const string s2="");

bool date_set(const char * str,int *y,int *d,int *m);
bool time_set(const char * str,int *h,int *m,int *s);
bool ptime_set(const char * str,int *yr, int *mo, int *dy, int *hr,int *mi,int *sc);

bool putime_set(const char * str,int *yr, int *mo, int *dy, int *hr,int *mi,int *sc,int *usc,int resolv);
bool utime_set(const char * str,int *h,int *m,int *s,int *usc,int resolv);


bool kgDiv(double* val, char* a, char* b);
int gcd(int a, int b);
int lcm(int a, int b);
size_t aToSizeT(const char * a);

bool chkFldName(kgstr_t vvs);


struct SortInfo{
	enum SortStatus {
		Nosort   = 0,  //　ソート無し
		CharSort = 1,  // 文字ソート
		NumSort  = 2,  // 数字そーと
		Reverse  = 4,   // 逆順
		CharSortR= 5,  // 文字ソート逆順
		NumSortR = 6   // 数字そーと逆順
	};

	int _type;
	int _pos;

	SortInfo(int type=0,int pos=-1):_type(type),_pos(pos){}
	SortInfo(const kgstr_t& str){
		_type = Nosort;
		if(str==""){ _pos=-1; return; }
		if(str.find('n') != kgstr_t::npos){ _type =  NumSort;}
		else															{ _type =  CharSort;}	
		if(str.find('r') != kgstr_t::npos){ _type |= Reverse;}
		_pos = 0;
		for(const char *p = str.c_str() ; *p && '0' <= *p && *p <= '9'  ; p++ ){
			_pos = _pos*10 + (*p-'0');
		}
	}
	int keypos(void){ return _pos; }
};

//------------------------------------------------------------------------------
// setを備えたauto_ptr
//------------------------------------------------------------------------------
template<class T>
class kgAutoPtr1 
{
  T* _ptr;
public:
  kgAutoPtr1(T* ptr=0) : _ptr(ptr) {}
  virtual ~kgAutoPtr1(void) { if(_ptr != 0) delete _ptr; _ptr=0;}
  T* get(void) const throw() { return _ptr; }
  void set(T* ptr) throw() { if(_ptr!=0) delete _ptr; _ptr=ptr;}
  void clear(void) { if(_ptr!=0) delete _ptr; _ptr=0;}
};

//------------------------------------------------------------------------------
// 配列型に拡張したauto_ptr
//------------------------------------------------------------------------------
template<class T>
class kgAutoPtr2 
{
  T* _ptr;
public:
  kgAutoPtr2(T* ptr=0) : _ptr(ptr) {}
  virtual ~kgAutoPtr2(void) { if(_ptr != 0) delete[] _ptr; _ptr=0;}
	kgAutoPtr2<T>& operator=(T* ptr){_ptr=ptr; return *this;} 
  T* get(void) const throw() { return _ptr; }
  void set(T* ptr) throw() { if(_ptr!=0) delete[] _ptr; _ptr=ptr; }
  void clear(void) { if(_ptr!=0) delete[] _ptr; _ptr=0;}
};
//------------------------------------------------------------------------------
// vectorをsetに変換するテンプレート
//------------------------------------------------------------------------------
template<class T>
set<T> vector2set(const vector<T>& v)
{
	set<T> s;
	for(size_t i=0; i<v.size(); i++){
		s.insert(v[i]);
	}
	return s;
}

}////////////////////////////////////////////// namespace end

