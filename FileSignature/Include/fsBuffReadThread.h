#ifndef __FSBUFFREADTHREAD_H__
#define	__FSBUFFREADTHREAD_H__

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

class TBuffReadThread : public IBuffThread {
public:
    TBuffReadThread(std::string /*__FWriteFilePath*/, TMutex& /*__FMutex*/);

    ~TBuffReadThread(void);

protected:

    virtual void setUp(void) {
    }
    //

    virtual void execute(void) {
    }

private:
    std::string FWriteFilePath;
    FILE* FWriteFile;
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
#endif	/* __FSBUFFREADTHREAD_H__ */

