#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsBuffThread.h"
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

TBuffThread::TBuffThread(TMutex& __FMutex) :
FSharedBuffer(NULL),
FMutex(__FMutex)
{
}
//

void TBuffThread::doStart(TBuffer* __FSharedBuffer)
{
    setBuffer(__FSharedBuffer);
    //
    int retResult = 0x0;
    //
    retResult = pthread_create(&FThreadId, NULL, TBuffThread::stStartPoint,
                               reinterpret_cast<void*> (this));
    if (0 != retResult)
        throw TException("Error TBuffThread::Start [FAILED] <= [pthread_create(...)]");
}
//

TBuffThread::~TBuffThread(void)
{
    join();
}
//

void TBuffThread::run(void)
{
    setUp();
    execute();
}
//**************************************************//

void* TBuffThread::stStartPoint(void* __FPtrOnItselfThr)
{
    TBuffThread* runThread = static_cast<TBuffThread*> (__FPtrOnItselfThr);
    if (NULL != runThread)
    {
        runThread->run();
    }
    return (NULL);
}