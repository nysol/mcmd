
#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <queue>
#include <csignal>
#include <cerrno>
#include <fcntl.h>
#include <sys/stat.h>


#include <kgfifo.h>
#include <kgError.h>
#include <kgMethod.h>
#include <kgMessage.h>
#include <kgArgs.h>
#include <kgConfig.h>
#include <kgTempfile.h>

using namespace std;
using namespace boost;
using namespace kglib;
using namespace kgmod;

class Queue {
private:
	pthread_mutex_t _mutex;
	pthread_cond_t 	_threadState;

	int _iFD;
	int _oFD;


	bool _oEnd;
	bool _readEnd;

	size_t _blkSize;
	size_t _queSize;
	kgAutoPtr2<char> _buf_ap;
	char* _buf;
	vector<char*> _que;
	size_t _enq;
	size_t _deq;
	vector<size_t> _readSize;
	
	// バッファFULL時、使用
	kgTempfile    _tempFile; 
	queue<string> _tmpname;
	queue<size_t> _rest_no;

	
	//ロックしてから動かすこと
	size_t nextQue(size_t n){
		n++;
		return n % _queSize;
	}

	// 全データ出力
	//ロックしてから動かすこと
	void extend_fileout(){
		//全データを吐き出す
		string tname=_tempFile.create(false, "merge");    	
		int fd=::open(tname.c_str(), O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, S_IRWXU);
		size_t deq_tmp = _deq;
		while(1){
			deq_tmp =nextQue(deq_tmp);
			size_t maxSize=_readSize.at(deq_tmp);
  	  char* buf=_que.at(deq_tmp);
 			size_t wsize = ::write(fd, buf , maxSize);
    	if( wsize!=maxSize ){
				std::ostringstream ss;
				ss << "file write error";
				throw kgError(ss.str());
			}
			if(deq_tmp==_enq){
				break;
			}
		}
		::close(fd);
		_tmpname.push(tname);
		_rest_no.push(_deq);
		_enq = nextQue(_deq);
	}


public:
	Queue(int iFD,int oFD, size_t queSize, size_t blkSize,kgEnv* env){
		_iFD = iFD;
		_oFD = oFD;
	  if (pthread_mutex_init(&_mutex, NULL) == -1) { 
			ostringstream ss;
			ss << "init mutex error";
			throw kgError(ss.str());
	  }
	  if (pthread_cond_init(&_threadState, NULL) == -1) { 
			ostringstream ss;
			ss << "init cond mutex error";
			throw kgError(ss.str());
	  }

		_queSize = queSize;
		_blkSize = blkSize;
		_enq = 0; // エンキュー
		_deq = 0; // デキュー
		_readEnd=false;
    _readSize.resize(_queSize,0);
		// que全体のbufferを確保
		_buf_ap.set( new char[_queSize * _blkSize] );
		_buf = _buf_ap.get();
		// 読み込み単位block別にポインター登録
		for(size_t i=0; i<_queSize; i++){
			_que.push_back(_buf + _blkSize*i);
		}
		// 一時ファイルの初期化
		_tempFile.init(env);
	}
	
	// ===================================================
	// データの読み込み
	// ===================================================
	int readData(){
	
		try{
			// mutexインスタンスにロックをかける
			pthread_mutex_lock(&_mutex);
			{
				// enqがdeqに追いついたら拡張
				size_t next=nextQue(_enq);
				if(next==_deq){ extend_fileout(); }
				else{ _enq=next; }// enqを一つ進める	
			}
			pthread_mutex_unlock(&_mutex);

			// readしてenq位置に格納
			size_t maxSize = _blkSize;
			size_t accSize = 0;
			size_t resSize = maxSize;
			char* buf=_que.at(_enq);
			while(accSize<maxSize){
 		   	int rsize = ::read(_iFD, buf + accSize, resSize<_blkSize ? resSize : _blkSize);
   		 	if( rsize < 0 ){
    			//boost wThreadState_.notify_one();
					pthread_cond_signal(&_threadState);
     		 	throw kgError();
    		}
    		if( rsize == 0 ) break;
				accSize+=static_cast<size_t>(rsize);
				resSize-=static_cast<size_t>(rsize);
			}
			_readSize.at(_enq)=accSize;		
			// read eof
  	  if( accSize == 0 ){
				pthread_mutex_lock(&_mutex);
				{
					_readEnd=true;
				}
				pthread_mutex_unlock(&_mutex);
 
 		   	//boost wThreadState_.notify_one();
				pthread_cond_signal(&_threadState);
				return 0;
			}
			// write側が待ち状態にあれば起こす
			//boost wThreadState_.notify_one();
			pthread_cond_signal(&_threadState);
			return 1;
		}catch(...){
			return 0;
		}
	}

	// ===================================================
	// データの書き込み
	// ===================================================
	int writeData(){
		try{
			
			bool fout=false;
			size_t deq_tmp=0;

			pthread_mutex_lock(&_mutex);
			{
				if(_tmpname.size() ){
					fout = true	;
					deq_tmp = _rest_no.front();
				}
				// deqがenqに追いついたら休眠(buffer full)
				if(_tmpname.size()==0 && _deq==_enq){
					if(_readEnd){
						//boost rThreadState_.notify_one();
						pthread_cond_signal(&_threadState);
						pthread_mutex_unlock(&_mutex);
						return 0;
					}else{
						//boost wThreadState_.wait(mutex_);
						pthread_cond_wait(&_threadState, &_mutex);
					}
				}
			}
			pthread_mutex_unlock(&_mutex);
			//ファイル出力が存在すればそっちから先に処理する
			if(fout && deq_tmp != _deq){
				kgAutoPtr2<char> buf_tmp_ap; 
				buf_tmp_ap.set( new char[_blkSize] );
				char* buf = buf_tmp_ap.get();
				int tFD;
				pthread_mutex_lock(&_mutex);
				{
					tFD = ::open(_tmpname.front().c_str(), O_RDONLY);
					_tmpname.pop();
					_rest_no.pop();
				}
				pthread_mutex_unlock(&_mutex);
				while(1){
	  	  	int rsize = ::read(tFD, buf, _blkSize);
	   			if(rsize < 0){
						ostringstream ss;
						ss << "file read error";
						throw kgError(ss.str());
					}
					if(rsize==0) { break;} 
					size_t maxSize=rsize;
					size_t accSize=0;
					size_t resSize=maxSize;
					// deq位置のデータをwrite
 					while(accSize<maxSize){
  	  			int wsize = ::write(_oFD, buf + accSize, resSize<maxSize ? resSize : maxSize);
  	  			if( wsize<0 ){
							// boost rThreadState_.notify_one();
							pthread_cond_signal(&_threadState);

							if(32==errno){ // pipe broken
								_oEnd = true;
								return 0;
							}else{
								ostringstream ss;
								ss << "file write error";
								throw kgError(ss.str());
							}
						}
   			 		if( wsize == 0 ){
							_oEnd = true;
							return 0;
						}
						accSize+=static_cast<size_t>(wsize);
						resSize-=static_cast<size_t>(wsize);
					}
				}
				::close(tFD);
			}
			else{
				// deq位置のデータをwrite
				size_t maxSize=_readSize.at(_deq);
				size_t accSize=0;
				size_t resSize=maxSize;
				char* buf = _que.at(_deq);
				while(accSize<maxSize){
					int wsize = ::write(_oFD, buf + accSize, resSize<maxSize ? resSize : maxSize);
					if( wsize<0 ){
						//boost rThreadState_.notify_one();
						pthread_cond_signal(&_threadState);
						if(32==errno){ // pipe broken
							return 0;
						}else{
							ostringstream ss;
							ss << "file write error";
							throw kgError(ss.str());
						}
					}
					if( wsize == 0 ){ return 0; }
					accSize+=static_cast<size_t>(wsize);
					resSize-=static_cast<size_t>(wsize);
				}
				pthread_mutex_lock(&_mutex);
				{
					// deqを一つ進める
					if(_deq==_enq){
						if(_readEnd){
							pthread_mutex_unlock(&_mutex);
							return 0;
						}else{
							//boostwThreadState_.wait(mutex_);
							pthread_cond_wait(&_threadState, &_mutex);
						}
					}
					_deq=nextQue(_deq);
				}
				pthread_mutex_unlock(&_mutex);

			}
			// read側が待ち状態にあれば起こす
			pthread_cond_signal(&_threadState);
			return 1;
		}catch(...){
			cerr << "writeTHREAD EXCPTIOIN ERROR 0" << endl;
			return 0;
		}
	}
};

static void *rThread(void *arg){
	try {
		Queue *hd =(Queue *)arg; 
		while(hd->readData()==1){}
	}catch(...){
		cerr << "readTHREAD EXCPTIOIN ERROR" << endl;
	}	
  return NULL;
}

static void *wThread(void *arg){
	try {
		Queue *hd =(Queue *)arg; 
		while(hd->writeData()==1){}
	}catch(...){
		cerr << "writeTHREAD EXCPTIOIN ERROR" << endl;
	}
	return NULL;
}

// -----------------------------------------------------------------------------
// コンストラクタ(モジュール名，バージョン登録,パラメータ)
// -----------------------------------------------------------------------------

kgFifo::kgFifo(void){

	_name    = "kgfifo";
	_version = "###VERSION###";

	#include <help/en/kgfifoHelp.h>
	_titleL = _title;
	_docL   = _doc;
	#ifdef JPN_FORMAT
		#include <help/jp/kgfifoHelp.h>
	#endif

}

// -----------------------------------------------------------------------------
// 入出力ファイルオープン
// -----------------------------------------------------------------------------
void kgFifo::setArgs(void){
	// unknown parameter check
	_args.paramcheck("i=,o=,n=");

	// 入出力ファイル名の取得
	_iName = _args.toString("i=",false);
	_oName = _args.toString("o=",false);

	if(_iName.empty()){
	 _iFD=0;
	}else{
		_iFD = ::open(_iName.c_str(), KG_IOPEN_FLG);
		if(_iFD == -1 ){
			ostringstream ss;
			ss << "file read open error: " << _iName;
			throw kgError(ss.str());
		}
	}
	if(_oName.empty()){
		_oFD=1;
	}else{
		_oFD = ::open(_oName.c_str(), KG_OOPEN_FLG, S_IRWXU);
		if(_oFD == -1 ){
			ostringstream ss;
			ss << "file write open error: " << _oName;
			throw kgError(ss.str());
		}
	}
	string queSize = _args.toString("n=",false);
	if(queSize.empty()){
		_queSize=32;
	}else{
		_queSize= atoi(queSize.c_str());
	}
	if(_queSize<=2){
		throw kgError("n= must take greater than 2.");
	}

}


void kgFifo::oClose(void)  {
	//flush();
	try {
		::close(_oFD);
	}catch(kgError& err){
		ostringstream ss;
		ss << "file write close error: " << _oName;
		throw kgError(ss.str());
	}
}

void kgFifo::iClose(void)  {
	try {
		::close(_iFD);
	}catch(kgError& err){
		ostringstream ss;
		ss << "file read close error: " << _iName;
		throw kgError(ss.str());
	}
}
void kgFifo::rw_cancel(void){

  pthread_cancel(_thr_write);
	pthread_cancel(_thr_read);
  pthread_join(_thr_write, NULL);
	pthread_join(_thr_read, NULL);
	oClose();
	iClose();
}

// -----------------------------------------------------------------------------
// 実行
// -----------------------------------------------------------------------------
int kgFifo::runMain(void) {

	Queue que(_iFD,_oFD,_queSize,KG_iSize,_env);

	//int rth_rtn = 
	pthread_create( &_thr_read, NULL, &rThread ,(void*)&que);		
	//int wth_rtn = 
	pthread_create( &_thr_write, NULL, &wThread ,(void*)&que);		

	pthread_join(_thr_read, NULL);
  pthread_join(_thr_write, NULL);

	iClose();
	oClose();

	return 0;
// 例外catcher
}
// -----------------------------------------------------------------------------
// 実行 
// -----------------------------------------------------------------------------
int kgFifo::run(void)
{
	try {

		setArgs();
		int sts = runMain();
		successEnd();
		return sts;
	}
	catch(kgError& err){
		iClose();
		oClose();
		errorEnd(err);
	}catch(...){
		iClose();
		oClose();
		errorEnd();
	}
	return 1;
}

