#ifndef __FSFILEAGENTTHR_H__
#define	__FSFILEAGENTTHR_H__
////

class TFileAgentThr : public IFileAgent {
public:
    //max bit size of encoder = 2147483647 byte
    TFileAgentThr(long int __FEncBitSize = 0x100000L); //1048576 byte 
    //

    virtual void doGenerate(const std::string& /*__FInputFilePath*/,
            const std::string& /*__FOutputFilePath*/);
    //
    ~TFileAgentThr(void);

    //*********************************************

    static void stSetExitSignal(bool __bExitSignal) {
        bExitSignal = __bExitSignal;
    }
    //

    static bool stGetExitSignal(void) {
        return (bExitSignal);
    }

private:
    TBuffer& FThrSharedBuff;
    //

    TFileAgentThr(const TFileAgentThr&);
    TFileAgentThr& operator=(const TFileAgentThr&);
    //
    //*********************************************
    static bool bExitSignal;

};

////
#endif	/* __FSFILEAGENTMTH_H__ */

