#ifndef __FSFILEAGENTTHR_H__
#define	__FSFILEAGENTTHR_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class TFileAgentThr : public IFileAgent
{
    //max bit size of encoder = 2147483647 byte
    TFileAgentThr(long int __FEncBitSize = 0x100000L); //1048576 byte 
    //
    
    virtual void doGenerate(const std::string& /*__FInputFilePath*/,
                            const std::string& /*__FOutputFilePath*/);
    
    //
    ~TFileAgentThr(void);

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

#endif	/* __FSFILEAGENTMTH_H__ */

