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
// kgmodincludesort
// ============================================================================
#pragma once
#include <kgmod.h>
#include <kgMessage.h>
#include <kgsortf.h>
//#include <pthread.h>
#include <boost/thread.hpp>
#include <fcntl.h>

using namespace kglib;

namespace kgmod  ////////////////////////////////////////////// start namespace
{
class kgModIncludeSort : public kgMod 
{

	void setSortMod(size_t num);
	void sortingRunMain(kgCSVfld* csv ,kgstr_t fldname ,size_t num,bool numflg);

protected:
	kgTempfile _sortingFile;
	kgSortf *_inner_sort;
	size_t _sortModSize;
  kgEnv    _env_sort;
	kgAutoPtr2<kgSortf> _aps;
	//pthread_t *_th_st_p;
	//kgAutoPtr2<pthread_t> _aps_pth;
	kgAutoPtr2<boost::thread*> _aps_pth;
	boost::thread** _th_st_p;

	kgModIncludeSort(void){ _sortModSize=0; }
	size_t getSmod(void){ return _sortModSize;}
	void signalEnd(void){ _sortingFile.remove_all();	}

	void sortingRun(vector<kgCSVfld*> csv,vector< vector<kgstr_t> > fldname,bool sortF=false);
	void sortingRun(kgCSVfld* csv,vector<kgstr_t> fldname,bool sortF=false);
	void sortingRun(kgCSVfld* csv,vector<int> fldnum,bool sortF=false);
	
	public:

	virtual ~kgModIncludeSort(void){}

	static void* run_noargs_pth(void *obj);

	void th_cancel(void);

	void init(kgArgs args, kgEnv* env);
	void init(size_t argc, const char* argv[], kgEnv* env);

};

}
