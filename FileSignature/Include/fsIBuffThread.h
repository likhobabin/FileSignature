#ifndef __FSIBUFFTHREAD_H__
#define	__FSIBUFFTHREAD_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class TBuffer;
class TMutex;
//

class IBuffThread {
public:
    IBuffThread(TMutex&);
    //
    void doStart(TBuffer* /*__FPtrThreadArg*/);
    //
    void join(void) {
        pthread_join(FThreadId, NULL);
        printf("\nDebug IBuffThread::join [ Join Other Treads ]\n");
    }
    //
    virtual ~IBuffThread(void);

protected:
    void* run(void) 
    {
     setUp();
     return (execute());
    }
    virtual void setUp(void)
    {
        printf("\nDebug IBuffThread::setUp [ Setup Func Of Thread Interface ]\n");
    }
    virtual void* execute(void)
    {
        printf("\nDebug IBuffThread::execute [ Execute Func Of Thread Interface ]\n");
        return(NULL);
    }
    //

    void setBuffer(TBuffer* __FSharedBuffer) {
        FSharedBuffer = __FSharedBuffer;
    }
    //

    const TBuffer* getSharedBuffer(void) const {
        return (FSharedBuffer);
    }
    //

    TBuffer* getSharedBuffer(void) {
        return (FSharedBuffer);
    }
    //

    TMutex& mutex(void) {
        return (FMutex);
    }
    //

    const TMutex& mutex(void) const {
        return (FMutex);
    }
    //
    //**********************************************
    static void* stStartPoint(void* /*__FPtrThreadArg*/);

private:
    pthread_t FThreadId;
    TBuffer* FSharedBuffer;
    //
    TMutex& FMutex;
};
////
#ifdef _MSC_VER
#pragma pack(pop)
#endif
//
#ifdef __BORLANDC__
#pragma option pop
#endif
////
#endif	/* __FSIBUFFTHREAD_H__ */

