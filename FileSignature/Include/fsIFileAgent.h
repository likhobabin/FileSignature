#ifndef __FSIFILEAGENT_H__
#define	__FSIFILEAGENT_H__

////
class TBitEncoder;
//

class IFileAgent {
public:
    //max bit size of encoder = 2147483647 byte
    IFileAgent(long int __FEncBitSize = 0x100000L); //1048576 byte 
    //
    virtual void doGenerate(const std::string& /*__FInputFilePath*/,
            const std::string& /*__FOutputFilePath*/) = 0;
    //

    off64_t getInputFileSize(void) const {
        return (FInputFlSize);
    }
    //

    std::string getInputFilePath(void) const {
        return (FInputFilePath);
    }

    std::string getOutputFilePath(void) const {
        return (FOutputFilePath);
    }
    //
    virtual ~IFileAgent(void);
    //***************************************
    static off64_t stFileSize(FILE* /*__FPtrFile*/);
    static void stCloseFile(FILE* __FCloseFile = NULL);

protected:

    void setInputFilePath(const std::string& __FInputFilePath) {
        FInputFilePath = __FInputFilePath;
    }
    //

    void setOutputFilePath(const std::string& __FOutputFilePath) {
        FOutputFilePath = __FOutputFilePath;
    }
    //

    void setInputFileSize(off64_t __FInputFlSize) {
        FInputFlSize = __FInputFlSize;
    }
    //

    TBitEncoder& encoder(void) {
        return (FEncoder);
    }
    //

    const TBitEncoder& encoder(void) const {
        return (FEncoder);
    }

private:
    std::string FInputFilePath;
    std::string FOutputFilePath;
    off64_t FInputFlSize;
    //
    TBitEncoder& FEncoder;
};

////
#endif	/*__FSIFILEAGENT_H__*/

