#ifndef __FSBUFFREADTHREAD_H__
#define	__FSBUFFREADTHREAD_H__
////

class TFileAgentThr;
class TBitEncoder;
class IFileAgent;
class IBuffThread;
//

class TBuffReadThread : public IBuffThread {
public:
    TBuffReadThread(std::string /*__FWriteFilePath*/,
            TMutex& /*__FMutex*/,
            const bool& /*__FDataDry*/,
            long int __FEncBitSize = 0x100000L
            );

    virtual ~TBuffReadThread(void);

protected:
    //
    virtual void setUp(void);
    //
    virtual void* execute(void);
    //

    bool getDataDry(void) const {
        return (bDataDry);
    }

private:
    std::string FWriteFilePath;
    FILE* FWriteFile;
    TBitEncoder& FEncoder;
    const bool& bDataDry;
    //

    TBitEncoder& encoder(void) {
        return (FEncoder);
    }
    //

    const TBitEncoder& encoder(void) const {
        return (FEncoder);
    }
    //

    const std::string& writeFilePath(void) const {
        return (FWriteFilePath);
    }
    //
    void encodeAndWriteFile(void);
};

////
#endif	/* __FSBUFFREADTHREAD_H__ */

