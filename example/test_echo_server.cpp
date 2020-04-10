// 2017-12-25
// PHZ

// echo server

#include "TcpServer.h"
#include "EventLoop.h"
#include "Timer.h"

class EchoServer : public xop::TcpServer
{
public:
	EchoServer(xop::EventLoop& eventLoop)
		: TcpServer(&eventLoop)
	{ }

	~EchoServer() { }

	virtual xop::TcpConnection::Ptr OnConnect(SOCKET sockfd)
	{
		auto conn = std::make_shared<xop::TcpConnection>(event_loop_->GetTaskScheduler().get(), sockfd);

		conn->SetReadCallback([this](xop::TcpConnection::Ptr conn, xop::BufferReader& buffer) { 
			std::string res(buffer.Peek(), buffer.ReadableBytes());
			buffer.RetrieveAll();
			conn->Send(res.c_str(), res.size());
			return true; 
		});

		return conn;
	}

private:

};

int main(int argc, char **argv)
{
	xop::EventLoop event_loop;

	EchoServer server(event_loop);
	server.Start("0.0.0.0", 12345);

	while(1)
	{
		xop::Timer::Sleep(1);        
	}

	server.Stop();
	return 0;
}
