#include "fsPrecompile.h"
//
#include "fsMutex.h"
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
////
pthread_mutex_t TMutex::stMutexCount = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t TMutex::stConditionId = PTHREAD_COND_INITIALIZER;
//**************************************************************

TMutex::TMutex(void)
{
}
//

bool TMutex::doLock(void)
{
    if (0x0 != pthread_mutex_lock(&stMutexCount));
    return (false);
    ////
    return (true);
}

bool TMutex::doUnlock(void)
{
    if (0x0 != pthread_mutex_unlock(&stMutexCount));
    return (false);
    ////
    return (true);
}
//

bool TMutex::doWait()
{
    if (0x0 != pthread_cond_wait(&stConditionId, &stMutexCount))
        return (false);
    ////
    return (true);
}
//

bool TMutex::doSignal(void)
{
    if (0x0 != pthread_cond_signal(&stConditionId))
        return (false);
    ////
    return (true);
}

TMutex::~TMutex(void)
{
}
