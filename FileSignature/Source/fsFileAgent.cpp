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

TFileAgent::TFileAgent(long int __FEncBitSize) :
FInputFilePath("InputFilePath::Unknown"),
FOutputFilePath("OutputFilePath::Unknown"),
FInputFlSize(0x0L),
FEncoder(*(new TBitEncoder(__FEncBitSize)))
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
    ptrWriteFile = fopen64(outPutPath().c_str(), "wb");
    if (NULL == ptrWriteFile)
    {
        stCloseFile(ptrReadFile);
        throw TException("Error TFileAgent::doGenerate [ NULL ] <= [ ptrWriteFile = fopen(...) ]");
    }
    //
    off64_t itQuantity = inPutFileSizeByte() / sizeof (TByte);
    //
    printf("\nDebug TFileAgent::doGenerate [ %ld ] <= [Encoder Bit Size]\n", TBitEncoder::stGetBitSize());
    printf("\nDebug TFileAgent::doGenerate [ %d ] <= [TByte Size]\n", sizeof (TByte));
    printf("\nDebug TFileAgent::doGenerate [ Started Job... ] <= [File Agent]\n");
    //
    bool bDataDry = false;
    off64_t idx = 0x0LL;
    //
    for (; itQuantity > idx && !bDataDry; idx++)
    {
        TByte nullChar = '0';
        TByte buffer[TBitEncoder::stGetBitSize()];
        memset(buffer, nullChar, TBitEncoder::stGetBitSize());
        //
        if (0 == fread(buffer, sizeof (TByte), TBitEncoder::stGetBitSize(), ptrReadFile))
            bDataDry = true;
        else
        {
            encoder().doEncode(buffer, (unsigned long int) (TBitEncoder::stGetBitSize()));
            //
            const TByte* encodedBuff = NULL;
            encodedBuff = encoder().getBuffer().getData();
            unsigned long int encodedBuffSize = encoder().getBuffer().getSize();
            //
            if (encodedBuffSize != fwrite(encodedBuff, sizeof (TByte),
                                          encodedBuffSize,
                                          ptrWriteFile))
            {
                stCloseFile(ptrReadFile);
                stCloseFile(ptrWriteFile);
                throw TException("Error TFileAgent::doGenerate [ FAILED ] <= [ fwrite ]");
            }
        }
    }
    //
    stCloseFile(ptrWriteFile);
    //
    stCloseFile(ptrReadFile);
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
//

void TFileAgent::stCloseFile(FILE* __FCloseFile)
{
    if (NULL != __FCloseFile)
    {
        fclose(__FCloseFile);
        __FCloseFile = NULL;
    }
}
