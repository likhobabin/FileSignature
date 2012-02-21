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
        return (bDataDryState);
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
    bool bDataDryState;
    //

    TBuffWriteThread(const TBuffWriteThread&);
    TBuffWriteThread& operator=(const TBuffWriteThread&);
    //

    const std::string& readFilePath(void) const {
        return (FReadFilePath);
    }
    //

    void setDataDryState(bool __bDataDryState) {
        bDataDryState = __bDataDryState;
    }
    //
};

////
#endif	/* __FSBUFFWRITETHREAD_H__ */

