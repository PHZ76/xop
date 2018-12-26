// 2017-12-25
// PHZ

// echo server

#include "TcpServer.h"
#include "EventLoop.h"

class EchoServer : public xop::TcpServer
{
public:
	EchoServer(xop::EventLoop& eventLoop, std::string ip, uint16_t port)
		: TcpServer(&eventLoop, ip, port)
	{ }

	~EchoServer() { }

	virtual xop::TcpConnection::Ptr newConnection(SOCKET sockfd)
	{
		auto conn = std::make_shared<xop::TcpConnection>(_eventLoop->getTaskScheduler().get(), sockfd);

		conn->setReadCallback([this](xop::TcpConnection::Ptr conn, xop::BufferReader& buffer) { 
			std::string res(buffer.peek(), buffer.readableBytes());
			buffer.retrieveAll();
			conn->send(res.c_str(), res.size());
            return true; //false 关闭连接
		});

		return conn;
	}

private:

};

int main(int argc, char **argv)
{
	xop::EventLoop eventLoop;

	EchoServer server(eventLoop, "0.0.0.0", 12345);
	server.start();

	eventLoop.loop();

	return 0;
}
