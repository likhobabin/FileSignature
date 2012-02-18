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
/////
class IFileAgent;
class TBitEncoder;
//

class TFileAgent : public IFileAgent {
public:
    //max bit size of encoder = 2147483647 byte
    TFileAgent(long int __FEncBitSize = 0x100000L); //1048576 byte 
    //

    virtual void doGenerate(const std::string& /*__FInputFilePath*/,
            const std::string& /*__FOutputFilePath*/);

    //
    ~TFileAgent(void);
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
