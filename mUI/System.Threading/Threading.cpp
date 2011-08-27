﻿#include "Threading.h"

#include "GlobalTLS.h"

namespace mUI{ namespace System{ namespace Threading{

bool Init()
{
	bool ret = GlobalTLS::Init();
	assert(ret);
	Thread::_MakeTCB();

	return ret;
}

void THREADING_ENTRY Dispose()
{
	Thread::DisposeTCBForMainThread();
}

}}}