// 2018-5-7
// PHZ

// log

#include "Logger.h"
#include "Timer.h"

#if defined(WIN32) || defined(_WIN32) 
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"Iphlpapi.lib")
#endif 

using namespace xop;
using namespace std;

int main()
{    
	//Logger::instance().init("log.txt");
	LOG_INFO("hello world.");    
	LOG_ERROR("hello world.");  
	xop::Timer::Sleep(1000);
	return 0;
}


