#ifndef __FSBUFFWRITETHREAD_H__
#define	__FSBUFFWRITETHREAD_H__
////

class IFileAgent;
class IBuffThread;
//

class TBuffWriteThread : public IBuffThread {
public:
    TBuffWriteThread(std::string /*__FReadFilePath*/, TMutex& /*__FMutex*/);

    const bool& getDataDryState(void) const {
        return (bDataDry);
    }

    void setDataDry(bool __bDataDry) {
        bDataDry = __bDataDry;
    }

    virtual ~TBuffWriteThread(void);

protected:
    //
    virtual void setUp(void);
    //
    virtual void* execute(void);


private:
    std::string FReadFilePath;
    FILE* FReadFile;
    bool bDataDry;
    //**************

    const std::string& readFilePath(void) const {
        return (FReadFilePath);
    }
};

////
#endif	/* __FSBUFFWRITETHREAD_H__ */

