// 2018-7-12
// PHZ

// MemoryPool

#include "MemoryManager.h"
#include <memory>

int main()
{
	char *p = (char *)xop::Alloc(10);
	xop::Free(p);

	std::shared_ptr<char> buffer((char*)xop::Alloc(1024*100), xop::Free);
	return 0;
}

