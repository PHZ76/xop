// 2018-5-1
// PHZ

// TaskScheduler

#include "xop.h"

using namespace std;
using namespace xop;

void test()
{
	string input;
	cin >> input;
	cout << "input: " << input << endl;
}

int test_4() // int main()
{
	// TaskScheduler *taskScheduler = new EpollTaskScheduler(); 
	TaskScheduler *taskScheduler = new SelectTaskScheduler();
	std::shared_ptr<Channel> chn(new Channel(0)); // 0: stdin
	
	chn->setEvents(EVENT_IN);
	chn->setReadCallback(std::bind(test));
	taskScheduler->updateChannel(chn);
	
	while(1)
	{
		taskScheduler->handleEvent(1000/*ms*/);
	}
	
	return 0;
}


