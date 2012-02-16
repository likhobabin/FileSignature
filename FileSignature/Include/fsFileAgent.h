#ifndef __FSFILEAGENT_H__
#define __FSFILEAGENT_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class TBitEncoder;
//

class TFileAgent {
public:
    TFileAgent(void);
    //
    std::string inPutPath(void ) const 
    {
        return(FInputFilePath);
    }
    off64_t inPutFileSizeByte(void ) const 
    {
        return(FInputFlSize);
    }
    //
    const TBitEncoder& encoder(void) const 
    {
        return(FEncoder);
    }
    //
    void doGenerate(const std::string& /*__FInputFilePath*/, 
                    const std::string& /*__FOutputFilePath*/);
    //
    std::string outPutPath(void ) const 
    {
        return(FOutputFilePath);
    }
    //
    ~TFileAgent(void);

private:
    std::string FInputFilePath;
    off64_t FInputFlSize;
    //
    std::string FOutputFilePath;
    TBitEncoder& FEncoder;
    //************************************************
    static off64_t stFileSize(FILE* /*__FOpenedFile*/);
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
#endif // __FSFILEAGENT_H__
