#ifndef XOP_TCP_CONNECTION_H
#define XOP_TCP_CONNECTION_H

#include <atomic>
#include <mutex>
#include "TaskScheduler.h"
#include "BufferReader.h"
#include "BufferWriter.h"
#include "Channel.h"

namespace xop
{

class TcpConnection : public std::enable_shared_from_this<TcpConnection>
{
public:
	using Ptr = std::shared_ptr<TcpConnection>;
	using DisconnectCallback = std::function<void()> ;
	using ReadCallback = std::function<void(Ptr, xop::BufferReader& buffer)>;

	TcpConnection(TaskScheduler *taskScheduler, int sockfd);
	virtual ~TcpConnection();

	TaskScheduler* getTaskScheduler() const 
	{ return _taskScheduler; }

	void setReadCallback(const ReadCallback& cb)
	{ _readCB = cb; }

	void send(std::shared_ptr<char> data, uint32_t size);
	void send(const char *data, uint32_t size);
	void close();

private:
	friend class TcpServer;
	void setDisconnectCallback(const DisconnectCallback& cb)
	{ _disconnectCB = cb; }

	void handleRead();
	void handleWrite();
	void handleClose();
	void handleError();

	TaskScheduler *_taskScheduler;
	std::shared_ptr<xop::BufferReader> _readBufferPtr;
	std::shared_ptr<xop::BufferWriter> _writeBufferPtr;
	std::shared_ptr<xop::Channel> _channelPtr;
	std::mutex _mutex;
	std::atomic_bool _isClosed;

	DisconnectCallback _disconnectCB = [] {};
	ReadCallback _readCB;
};

}

#endif 
