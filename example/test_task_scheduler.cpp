// 2019-10-19
// PHZ

// TaskScheduler
// stdin --> stdout

#include "SelectTaskScheduler.h"

using namespace std;
using namespace xop;

void output(std::shared_ptr<TaskScheduler> task_scheduler, std::shared_ptr<Channel> stdout_channel, std::string data)
{
	cout << "stdout: " << data << endl;

	if(stdout_channel->IsWriting())
	{
		 stdout_channel->SetEvents(0);
		 task_scheduler->UpdateChannel(stdout_channel);             
	} 
}

void input(std::shared_ptr<TaskScheduler> task_scheduler, std::shared_ptr<Channel> stdout_channel)
{
	string data;
	cin >> data;
	
	if(!stdout_channel->IsWriting())
	{
		stdout_channel->SetEvents(EVENT_OUT);
		stdout_channel->SetWriteCallback(std::bind(output, task_scheduler, stdout_channel, data));
		task_scheduler->UpdateChannel(stdout_channel);  
	}    
}

int main()
{
	std::shared_ptr<xop::SelectTaskScheduler> task_scheduler(new xop::SelectTaskScheduler);
		
	std::shared_ptr<Channel> stdin_channel(new Channel(0));  // stdin fd: 0
	std::shared_ptr<Channel> stdout_channel(new Channel(1)); // stdout fd: 1 

	stdin_channel->SetEvents(EVENT_IN);
	stdin_channel->SetReadCallback(std::bind(input, task_scheduler, stdout_channel));
	task_scheduler->UpdateChannel(stdin_channel);

	while(1)
	{
		int msec = 1000;
		task_scheduler->HandleEvent(msec); 
	}

	return 0;
}


