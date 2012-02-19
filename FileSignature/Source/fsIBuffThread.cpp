#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsIBuffThread.h"
////
#ifdef __BORLANDC__
#pragma option -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
//
#ifdef _MSC_VER
#pragma pack(8)
#pragma warning(disable:4355)
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#endif
//

IBuffThread::IBuffThread(TMutex& __FMutex) :
FSharedBuffer(NULL),
FMutex(__FMutex)
{
}
//

void IBuffThread::doStart(TBuffer* __FSharedBuffer)
{
    setBuffer(__FSharedBuffer);
    //
    int retResult = 0x0;
    //
    retResult = pthread_create(&FThreadId, NULL, IBuffThread::stStartPoint,
                              (void* ) (this));
    if (0 != retResult)
        throw TException("Error IBuffThread::Start [FAILED] <= [pthread_create(...)]");
}
//

IBuffThread::~IBuffThread(void)
{
}

//**************************************************//

void* IBuffThread::stStartPoint(void* __FPtrOnItselfThr)
{
    IBuffThread* runThread = (IBuffThread* ) (__FPtrOnItselfThr);
    if (NULL != runThread)
    {
        return ( runThread->run());
    }
    return (NULL);
}