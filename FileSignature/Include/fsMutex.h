#ifndef __FSMUTEX_H__
#define	__FSMUTEX_H__
////

class TMutex {
public:
    TMutex(void);
    //
    bool doLock(void);
    bool doUnlock(void);
    //
    bool doWait();
    bool doSignal(void);

    ~TMutex(void);

private:
    pthread_mutex_t FMutexCount;
    pthread_cond_t FConditionId;
};

////
#endif	/* __FSMUTEX_H__ */

