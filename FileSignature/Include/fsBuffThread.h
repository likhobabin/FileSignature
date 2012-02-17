#ifndef __FSTHREAD_H__
#define	__FSTHREAD_H__
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

class TBuffThread {
public:
    TBuffThread(TMutex& );
    //
    void doStart(TBuffer* /*__FPtrThreadArg*/);
    //
    virtual ~TBuffThread(void);

protected:
    void run(void);
    virtual void setUp(void) = 0;
    virtual void execute(void) = 0;
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
    
    TMutex& mutex(void )
    {
        return(FMutex);
    }
    //
    
    const TMutex& mutex(void ) const
    {
        return(FMutex);
    }
    //
    void join(void )
    {
        pthread_join(FThreadId, NULL);
    }
    //**********************************************
    static void*  stStartPoint(void* /*__FPtrThreadArg*/);

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
#endif	/* __FSTHREAD_H__ */

