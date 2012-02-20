#ifndef __FSFILEAGENT_H__
#define __FSFILEAGENT_H__
////

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

private:
    TFileAgent(const TFileAgent&);
    TFileAgent& operator=(const TFileAgent&);
    //
};

////
#endif // __FSFILEAGENT_H__
