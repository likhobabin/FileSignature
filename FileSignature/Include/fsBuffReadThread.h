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
    bool getDataDry(void ) const 
    {
        return(FDataDry);
    }

private:
    std::string FWriteFilePath;
    FILE* FWriteFile;
    TBitEncoder& FEncoder;
    const bool& FDataDry;
    //

    TBitEncoder& encoder(void) {
        return (FEncoder);
    }
    //

    const TBitEncoder& encoder(void) const {
        return (FEncoder);
    }
    //
    const std::string& writeFilePath(void ) const 
    {
        return(FWriteFilePath);
    }
    //
    void encodeAndWriteFile(void );
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

