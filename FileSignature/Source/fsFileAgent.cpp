#include "fsPrecompile.h"
//
#include "fsBitEncoder.h"
#include "fsFileAgent.h"
#include "fsBuffer.h"
////
#ifdef __BORLANDC__
#pragma option -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
//
#ifdef _MSC_VER
#pragma pack(8)
#pragma warning(disable:4355)
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#endif
//

TFileAgent::TFileAgent(void) :
FInputFilePath("InputFilePath::Unknown"),
FInputFlSize(0x0L),
FOutputFilePath("OutputFilePath::Unknown"),
FEncoder(*(new TBitEncoder()))
{
}
//

void TFileAgent::doGenerate(const std::string& __FInputFilePath, const std::string& __FOutputFilePath)
{
    FInputFilePath = __FInputFilePath;
    FOutputFilePath = __FOutputFilePath;
    //
    FILE* ptrReadFile = NULL;
    FILE* ptrWriteFile = NULL;
    //
    ptrReadFile = fopen64(inPutPath().c_str(), "rb");
    if (NULL == ptrReadFile)
        throw TException("Error TFileAgent::doGenerate [ NULL ] <= [ ptrReadFile = fopen(...) ]");
    FInputFlSize = stFileSize(ptrReadFile);
    //
    ptrWriteFile = fopen64(outPutPath().c_str(), "ab+");
    if (NULL == ptrWriteFile)
        throw TException("Error TFileAgent::doGenerate [ NULL ] <= [ ptrWriteFile = fopen(...) ]");
    //
    printf("\nDebug TFileAgent::doGenerate [%d] <= [Byte Size]\n", sizeof (TByte));
    off64_t itQuantity = inPutFileSizeByte() / sizeof (TByte);
    printf("\nDebug TFileAgent::doGenerate [%lld] <= [Iterator Quantity]\n", itQuantity);
    //
    bool bDataDry = false;
    for (off64_t idx = 0x0LL; itQuantity > idx && !bDataDry; idx++)
    {
        TByte nullChar = '0';
        TByte buffer[TBitEncoder::stGetBitSize()];
        memset(buffer, TBitEncoder::stGetBitSize(), nullChar);
        //
        if (0 == fread(buffer, sizeof (TByte), TBitEncoder::stGetBitSize(), ptrReadFile))
            bDataDry = true;
        else
        { 
            //printf("\nDebug TFileAgent::doGenerate [%ld] <= [Default Size]\n", 
            //       TBitEncoder::stGetBitSize());
            FEncoder.doEncode(buffer, TBitEncoder::stGetBitSize());
            //
            const TByte* encodedBuff = NULL;
            encodedBuff = encoder().getBuffer().getData();
            unsigned long encodedBuffSize = encoder().getBuffer().getSize();
            printf("[ %s ]\n\t", encodedBuff);
            //
            if (encodedBuffSize != fwrite(encodedBuff, sizeof (TByte),
                                                       encodedBuffSize,
                                                       ptrWriteFile))
            {
                throw TException("Error TFileAgent::doGenerate [ FAILED ] <= [ fwrite ]");
            }
        }
    }
    //
    fclose(ptrWriteFile);
    ptrWriteFile = NULL;
    //
    fclose(ptrReadFile);
    ptrReadFile = NULL;
}
//

TFileAgent::~TFileAgent(void)
{
    delete(&FEncoder);
}
//******************************************************//

off64_t TFileAgent::stFileSize(FILE* __FOpenedFile)
{
    off64_t outSize;
    //
    fseeko64(__FOpenedFile, 0x0L, SEEK_END);
    //
    outSize = ftello64(__FOpenedFile);
    //
    fseeko64(__FOpenedFile, 0x0L, SEEK_SET);
    ///
    return (outSize);
}