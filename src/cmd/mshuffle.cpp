// ============================================================================
// mshuffle : 項目のhash値によるファイル分割
// ============================================================================
#include <kgEnv.h>
#include <kgshuffle.h>

using namespace kgmod;
using namespace kglib;

int main(int argc, const char *argv[]) try
{
  kgEnv    env;
  kgShuffle kgmod;
  
  for(int i=1; i<argc; i++){
    if(0==strcmp("--help",argv[i]) || 0==strcmp("-help",argv[i])){
      cout << kgmod.doc() << endl;
	    exit(0);
    }
    if(0==strcmp("--helpl",argv[i]) || 0==strcmp("-helpl",argv[i])){
      cout << kgmod.docl() << endl;
	    exit(0);
    }
		if(0==strcmp("--version",argv[i]) || 0==strcmp("-version",argv[i])){
			cout << kgmod.lver() << endl;
			exit(0);
    }
  }

  kgmod.init(argc, argv, &env);
  return kgmod.run();


}catch(...){
  return 1;
}
