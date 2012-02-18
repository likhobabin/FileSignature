#ifndef __FSBUFFWRITETHREAD_H__
#define	__FSBUFFWRITETHREAD_H__

////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class IBuffThread;
//

class TBuffWriteThread : public IBuffThread {
public:
    TBuffWriteThread(std::string /*__FReadFilePath*/, TMutex& /*__FMutex*/);

    ~TBuffWriteThread(void);

protected:

    virtual void setUp(void) {
    }
    //

    virtual void execute(void) {
    }

private:
    std::string FReadFilePath;
    FILE* FReadFile;
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
#endif	/* __FSBUFFWRITETHREAD_H__ */

