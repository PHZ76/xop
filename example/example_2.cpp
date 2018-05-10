// 2018-5-7
// PHZ

// Timer event, Trigger event

#include "xop.h"
#include <memory> // shared_ptr

#if defined(WIN32) || defined(_WIN32) 
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"Iphlpapi.lib")
#endif 

using namespace xop;
using namespace std;

// 打印时间
void show()
{
    std::cout << Timestamp::localtime() << std::endl;
}

int test_2() // int main()
{
    std::shared_ptr<EventLoop> eventLoop = make_shared<EventLoop>(); 

    // 每隔一秒打印一次时间 
    //TimerId tid = eventLoop->addTimer([]{ show(); }, 1000/*ms*/, true);    
    auto tid = eventLoop->addTimer([eventLoop]{ eventLoop->addTriggerEvent([]{show();}); }, 1000/*ms*/, true);    
    
    eventLoop->loop();
    
    return 0;
}

