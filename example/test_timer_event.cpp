// 2018-5-7
// PHZ

// Timer event, Trigger event

#include "xop.h"
#include <memory> 

using namespace xop;
using namespace std;

// 打印时间
void test()
{
    std::cout << Timestamp::localtime() << std::endl;
}

int main()
{
    auto eventLoop = make_shared<EventLoop>(); 

    // 每隔一秒打印一次时间 
    int msec = 1000;    
    auto tid = eventLoop->addTimer([eventLoop]{ 
        eventLoop->addTriggerEvent([]{
            test();            
        }); 
        return true; // false:退出定时器
    }, msec);    

    eventLoop->loop();
    
    return 0;
}

