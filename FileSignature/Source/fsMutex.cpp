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
//**************************************************************

TMutex::TMutex(void)
{
    if(0x0 != pthread_mutex_init(&FMutexCount, NULL))
        printf("\nError TMutex::TMutex(...) [ FAILED ] <= [Init Mutex]\n");
    if(0x0 != pthread_cond_init(&FConditionId, NULL))
        printf("\nError TMutex::TMutex(...) [ FAILED ] <= [Init Condition]\n");
}
//

bool TMutex::doLock(void)
{
    if (0x0 != pthread_mutex_lock(&FMutexCount));
        return (false);
    ////
    return (true);
}

bool TMutex::doUnlock(void)
{
    if (0x0 != pthread_mutex_unlock(&FMutexCount));
        return (false);
    ////
    return (true);
}
//

bool TMutex::doWait()
{
    if (0x0 != pthread_cond_wait(&FConditionId, &FMutexCount))
        return (false);
    ////
    return (true);
}
//

bool TMutex::doSignal(void)
{
    if (0x0 != pthread_cond_signal(&FConditionId))
        return (false);
    ////
    return (true);
}

TMutex::~TMutex(void)
{
    if(0x0 != pthread_mutex_destroy(&FMutexCount))
        printf("\nError TMutex::TMutex(...) [ FAILED ] <= [Destroy Mutex]\n");
    ////
    if(0x0 != pthread_cond_destroy(&FConditionId))
        printf("\nError TMutex::TMutex(...) [ FAILED ] <= [Destroy Condition]\n");
        
}
