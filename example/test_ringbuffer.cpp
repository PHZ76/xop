// 2018-5-1
// PHZ

// Ring Buffer

#include "xop.h"
#include <thread>
#include "RingBuffer.h"

using namespace std;
using namespace xop;

void readThread(RingBuffer<string>& ringBuffer)
{
    while(1)
    {
         std::string data;    
        if(ringBuffer.pop(data))
        {
            std::cout << data << flush;
        }
        
        Timer::sleep(300);      
    }   
}

int main()
{
    RingBuffer<string> ringBuffer;

    thread t(readThread, std::ref(ringBuffer));
    t.detach();

    while(1)
    {
        Timer::sleep(500);        
        ringBuffer.push(string("*"));
    }
	
    return 0;
}

