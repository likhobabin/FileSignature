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
    //max bit size of encoder = 2147483647 byte
    TFileAgent(long int __FEncBitSize = 0x100000L); //1048576 byte 
    //

    std::string inPutPath(void) const {
        return (FInputFilePath);
    }

    off64_t inPutFileSizeByte(void) const {
        return (FInputFlSize);
    }
    //

    const TBitEncoder& encoder(void) const {
        return (FEncoder);
    }
    //
    void doGenerate(const std::string& /*__FInputFilePath*/,
            const std::string& /*__FOutputFilePath*/);
    //

    std::string outPutPath(void) const {
        return (FOutputFilePath);
    }
    //
    ~TFileAgent(void);

private:
    std::string FInputFilePath;
    std::string FOutputFilePath;
    off64_t FInputFlSize;
    //
    TBitEncoder& FEncoder;
    //

    TBitEncoder& encoder(void) {
        return (FEncoder);
    }
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
