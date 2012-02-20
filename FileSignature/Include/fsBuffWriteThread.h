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

    virtual ~TBuffWriteThread(void);
    //

protected:
    //
    virtual void setUp(void);

    virtual void* execute(void);
    //

private:
    std::string FReadFilePath;
    bool bDataDry;
    //

    TBuffWriteThread(const TBuffWriteThread&);
    TBuffWriteThread& operator=(const TBuffWriteThread&);
    //

    const std::string& readFilePath(void) const {
        return (FReadFilePath);
    }
    //

    void setDataDryState(bool __bDataDry) {
        bDataDry = __bDataDry;
    }
    //
};

////
#endif	/* __FSBUFFWRITETHREAD_H__ */

