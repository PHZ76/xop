// PHZ
// 2018-5-15

// PHZ
// 2018-5-15

#ifndef XOP_TCPSERVER_H
#define XOP_TCPSERVER_H

#include <memory>
#include <string>
#include "Socket.h"

namespace xop
{

class Acceptor;
class EventLoop;

class TcpServer 
{
public:	
    TcpServer(EventLoop* loop, std::string ip, uint16_t port);
    virtual ~TcpServer();  

protected:
	virtual void newConnection(SOCKET sockfd);

    EventLoop* _eventLoop; 
    std::shared_ptr<Acceptor> _acceptor; 
};

}

#endif 
