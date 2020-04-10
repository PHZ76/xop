// 2018-5-7
// PHZ

// Timer event, Trigger event

#include "EventLoop.h"
#include "Timestamp.h"
#include "Timer.h"
#include <memory> 

using namespace xop;
using namespace std;

void test()
{
	std::cout << Timestamp::localtime() << std::endl;
}

int main()
{
	auto event_loop = make_shared<EventLoop>(); 

	int msec = 1000;    
	auto tid = event_loop->AddTimer([event_loop]{ 
		event_loop->AddTriggerEvent([]{
			test();            
		}); 
		return true; 
	}, msec);    

	while(1)
	{
		Timer::Sleep(1);        
	}

	return 0;
}

