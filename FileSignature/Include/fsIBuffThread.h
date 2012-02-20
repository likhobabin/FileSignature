#ifndef __FSIBUFFTHREAD_H__
#define	__FSIBUFFTHREAD_H__

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
        //printf("\nDebug IBuffThread::join [ Join Other Treads ]\n");
    }

    //

    const FILE* getFileHandler(void) const {
        return (FPtrFileHandle);
    }
    //

    FILE* getFileHandler(void) {
        return (FPtrFileHandle);
    }
    //

    bool getFileClosedState(void) {
        return (bFileClosed);
    }
    //

    void setFileClosedState(bool __bFileClosed) {
        bFileClosed = __bFileClosed;
    }
    //

    virtual ~IBuffThread(void);

protected:

    void* run(void) {
        setUp();
        return (execute());
    }

    virtual void setUp(void) {
        //printf("\nDebug IBuffThread::setUp [ Setup Func Of Thread Interface ]\n");
    }

    virtual void* execute(void) {
        //printf("\nDebug IBuffThread::execute [ Execute Func Of Thread Interface ]\n");
        return (NULL);
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

    const TMutex& mutex(void) const {
        return (FMutex);
    }
    //

    FILE*& getFileHandlerRef(void) {
        return (FPtrFileHandle);
    }
    //
    
    TMutex& mutex(void) {
        return (FMutex);
    }
    //
    
    //**********************************************
    static void* stStartPoint(void* /*__FPtrThreadArg*/);

private:
    pthread_t FThreadId;
    TBuffer* FSharedBuffer;
    FILE* FPtrFileHandle;
    bool bFileClosed;
    //
    TMutex& FMutex;
};

////
#endif	/* __FSIBUFFTHREAD_H__ */

