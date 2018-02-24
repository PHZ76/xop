#include "BufferWriter.h"
#include "Socket.h"

using namespace xop;

BufferWriter::BufferWriter(int bufferSize) 
	: _maxQueueLength(bufferSize)
{
	
}	

bool BufferWriter::append(std::shared_ptr<char> data, uint32_t size, uint32_t index)
{
	if(_buffer.size() >= _maxQueueLength)
	{
		return false;		
	}

	Packet pkt = {data, size, index};
	_buffer.emplace(std::move(pkt));	
	
	return true;
}

bool BufferWriter::append(const char* data, uint32_t size, uint32_t index)
{
	if(_buffer.size() >= _maxQueueLength)
	{
		return false;		
	}
	
	Packet pkt;
	pkt.data.reset(new char[size+512]);
	memcpy(pkt.data.get(), data, size);
	pkt.size = size;
	pkt.writeIndex = index;
	
	_buffer.emplace(std::move(pkt));
	
	return true;
}

int BufferWriter::send(int sockfd)
{		
	if(_buffer.empty())
		return 0;
		
	Packet &pkt = _buffer.front();
	
	int ret = ::send(sockfd, pkt.data.get()+pkt.writeIndex, pkt.size-pkt.writeIndex, 0);
	if(ret >= 0)
	{
		pkt.writeIndex += ret;
		if(pkt.size == pkt.writeIndex)
		{		
			_buffer.pop();
		}
	}
	else if(ret < 0)
	{
#if defined(__linux) || defined(__linux__)
		if(errno==EINTR || errno==EAGAIN)
			return 0;
#endif
	}
	
	return ret;
}


