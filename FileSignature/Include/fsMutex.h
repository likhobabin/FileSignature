#ifndef __FSMUTEX_H__
#define	__FSMUTEX_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
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
    static pthread_mutex_t stMutexCount;
    static pthread_cond_t stConditionId;
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
#endif	/* __FSMUTEX_H__ */

