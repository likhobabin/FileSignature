#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsIBuffThread.h"
#include "fsIFileAgent.h"
////

#ifdef _MSC_VER
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#endif
/////
//

IBuffThread::IBuffThread(TMutex& __FMutex) :
FSharedBuffer(NULL),
FPtrFileHandle(NULL),
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
                               (void*) (this));
    if (0 != retResult)
        throw TException("Error IBuffThread::doStart [FAILED] <= [pthread_create(...)]");
}
//

IBuffThread::~IBuffThread(void)
{
    FSharedBuffer = NULL;
}

//**************************************************//

void* IBuffThread::stStartPoint(void* __FPtrOnItselfThr)
{
    IBuffThread* runThread = (IBuffThread*) (__FPtrOnItselfThr);
    if (NULL != runThread)
    {
        return ( runThread->run());
    }
    return (NULL);
}