// 2018-5-1
// PHZ

// Ring Buffer
#include "RingBuffer.h"
#include "Timer.h"
#include <thread>

using namespace std;
using namespace xop;

void ReadThread(RingBuffer<string>& ring_buffer)
{
	while(1)
	{
		 std::string data;    
		if(ring_buffer.pop(data))
		{
			std::cout << data << flush;
		}
		
		Timer::Sleep(300);      
	}   
}

int main()
{
	RingBuffer<string> ring_buffer;

	thread t(ReadThread, std::ref(ring_buffer));
	t.detach();

	while(1)
	{
		Timer::Sleep(500);        
		ring_buffer.push(string("*"));
	}

	return 0;
}

