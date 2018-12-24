// 2018-5-1
// PHZ

// TaskScheduler
// stdin --> stdout

#include "xop.h"

using namespace std;
using namespace xop;

void output(std::shared_ptr<TaskScheduler> taskScheduler, std::shared_ptr<Channel> stdoutChannel, std::string data)
{
    cout << "input: " << data << endl;

    // 取消写事件, 否则写事件会一直触发
    if(stdoutChannel->isWriting())
    {
         stdoutChannel->setEvents(0);
         taskScheduler->updateChannel(stdoutChannel);             
    } 
}

void input(std::shared_ptr<TaskScheduler> taskScheduler, std::shared_ptr<Channel> stdoutChannel)
{
    string data;
    cin >> data;
      
    //触发写事件
    if(!stdoutChannel->isWriting())
    {
        stdoutChannel->setEvents(EVENT_OUT);
        stdoutChannel->setWriteCallback(std::bind(output, taskScheduler, stdoutChannel, data));
        taskScheduler->updateChannel(stdoutChannel);  
    }    
}

int main()
{
    std::shared_ptr<TaskScheduler> taskScheduler(new TaskScheduler);
        
    std::shared_ptr<Channel> stdinChannel(new Channel(0));  // stdin fd: 0
    std::shared_ptr<Channel> stdoutChannel(new Channel(1)); // stdout fd: 1 

    // 监听读事件
    stdinChannel->setEvents(EVENT_IN);
    stdinChannel->setReadCallback(std::bind(input, taskScheduler, stdoutChannel));
    taskScheduler->updateChannel(stdinChannel);

    while(1)
    {
        int msec = 1000;
        taskScheduler->handleEvent(msec); 
    }

    return 0;
}


