// PHZ
// 2018-5-15

#include "TcpServer.h"
#include "Acceptor.h"
#include "EventLoop.h"
#include <cstdio>  

using namespace xop;
using namespace std;

TcpServer::TcpServer(EventLoop* eventLoop, std::string ip, uint16_t port)
    : _eventLoop(eventLoop),
      _acceptor(new Acceptor(eventLoop, ip, port))
{
    _acceptor->setNewConnectionCallback([this](SOCKET sockfd) { this->newConnection(sockfd); });
    _acceptor->listen();
}

TcpServer::~TcpServer()
{
	
}



