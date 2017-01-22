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
// kgtermios 
// ============================================================================
#pragma once
#include <wchar.h>


class kgTextArea{
	#define kgTextAreaSIZE 4096
	wint_t* wcs;
	wchar_t* outD;
	int* viewpos;//開始が入る
	int d_pos; 
	int d_endpos;
	int v_limit;

	public:	
	kgTextArea(int limit=0):
		d_pos(0),d_endpos(0),v_limit(limit){
			wcs     = new wint_t [kgTextAreaSIZE];
			outD    = new wchar_t[kgTextAreaSIZE];
			viewpos = new int    [kgTextAreaSIZE];
			viewpos[0]=0;
			wcs[0]=L'\0';
	}
	~kgTextArea(){
		if(wcs) delete [] wcs;
		if(outD) delete [] outD;
		if(viewpos) delete [] viewpos;
	}
	int cpos(){ return viewpos[d_pos];}
	
	int add(wint_t ind){ //return 0:なにもしない 1:上書き 2:削除＆上書き
		int vSize;
		if(isascii(ind)){ vSize = 1; }
		else            { vSize = 2; }
		if(viewpos[d_pos]+vSize > v_limit){ return 0; }
		//slide;
		wint_t old_c = wcs[d_pos];
		if(d_pos==d_endpos){
			wcs[d_pos] = ind;
			d_pos++; d_endpos++;
			wcs[d_pos] = L'\0';
			viewpos[d_pos] =viewpos[d_pos-1]+vSize;
			return 1;
		}
		else{//d_pos<d_endpos
			int old_vSize;
			if(isascii(old_c)){ old_vSize=1;}
			else              { old_vSize=2;}
			wcs[d_pos] = ind;
			if(old_vSize==vSize){ //2==2 or 1==1 
				d_pos++;	
				return 1;
			}else if(old_vSize>vSize){ //2>1 
				for(int i=d_endpos;i>d_pos;i--){
					viewpos[i+1] =viewpos[i];
					wcs[i+1] = wcs[i];
				}
				d_pos++;
				wcs[d_pos] = L'\0';
				viewpos[d_pos] =viewpos[d_pos-1]+1;
				d_endpos++;
				return 2;
			}else{ // 1<2
				for(int i=d_pos+1;i<d_endpos;i++){
					viewpos[i] =viewpos[i+1];
					wcs[i] = wcs[i+1];
				}
				d_pos++;
				d_endpos--;
				return 1;
			}
		}
		return 0;
	}

	int shiftL(void){
		if(d_pos==0){ return 0;}
		d_pos--;
		if(isascii(wcs[d_pos])){ return 1;}
		else{ return 2;}
		return 0;
	}

	int shiftR(void){
		if(viewpos[d_pos]>=v_limit){ return 0;}
		if(d_pos<d_endpos){
			d_pos++;
			if(isascii(wcs[d_pos])){ return 1;}
			return 2;
		}
		else { 
			d_pos++;
			d_endpos++;
			wcs[d_pos]=L'\0';
			viewpos[d_pos]=viewpos[d_pos-1]+1;
			return 1;
		}
		return 0;
	}

	int del(void){
		int mv;
		if(d_pos==0){ return 0;}
		if(d_pos==d_endpos){ d_endpos--;}
		d_pos--;
		if(isascii(wcs[d_pos])){ mv =1;}
		else									 { mv =2;}
		wcs[d_pos]=L'\0';
		return mv;
	}
	wchar_t* output(void){
		bool charOKF =false ;
		for(int i=d_endpos-1 ;i>=0;i--){
			if(wcs[i]==L'\0')	{
				if(charOKF){ outD[i] = L' '; }
				else       { outD[i] = wcs[i]; }
			}
			else{
				outD[i] = wcs[i];
				charOKF=true;
			}
		}
		return outD;
	}
};

