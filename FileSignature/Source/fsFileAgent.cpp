#include "fsPrecompile.h"
//
#include "fsBitEncoder.h"
#include "fsIFileAgent.h"
#include "fsFileAgent.h"
#include "fsBuffer.h"
#include "fsProgressBar.h"
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
IFileAgent(__FEncBitSize)
{
}
//

void TFileAgent::doGenerate(const std::string& __FInputFilePath, const std::string& __FOutputFilePath)
{
    IFileAgent::setInputFilePath(__FInputFilePath);
    IFileAgent::setOutputFilePath(__FOutputFilePath);
    //
    FILE* ptrReadFile = NULL;
    FILE* ptrWriteFile = NULL;
    //
    ptrReadFile = fopen64(IFileAgent::getInputFilePath().c_str(), "rb");
    if (NULL == ptrReadFile)
        throw TException("Error TFileAgent::doGenerate [ NULL ] <= [ ptrReadFile = fopen(...) ]");
    //
    IFileAgent::setInputFileSize(IFileAgent::stFileSize(ptrReadFile));
    //
    ptrWriteFile = fopen64(IFileAgent::getOutputFilePath().c_str(), "wb");
    if (NULL == ptrWriteFile)
    {
        stCloseFile(ptrReadFile);
        throw TException("Error TFileAgent::doGenerate [ NULL ] <= [ ptrWriteFile = fopen(...) ]");
    }
    //
    printf("\nDebug TFileAgent::doGenerate [ %ld ] <= [Encoder Bit Size]\n", TBitEncoder::stGetBitSize());
    printf("\nDebug TFileAgent::doGenerate [ %d ] <= [TByte Size]\n", sizeof (TByte));
    printf("\nDebug TFileAgent::doGenerate [ Started Job... ] <= [File Agent]\n");
    //
    off64_t rdFileSize=0x0LL;
    long int bitSize = 0x0L;
    unsigned long int allIterators = 0x0L;
    unsigned long int readBit=0x0L;
    //
    bitSize = TBitEncoder::stGetBitSize();
    rdFileSize = IFileAgent::stFileSize(ptrReadFile);
    allIterators = (unsigned long int)(rdFileSize/bitSize);
    //
    TProgressBar progressBar(allIterators);
    //
    bool bDataDry = false;
    //
    for (; !bDataDry;readBit++)
    {
        //printf("\nDebug TFileAgent::doGenerate [ %ld ]\n", readBit);
        TByte nullChar = '0';
        TByte buffer[TBitEncoder::stGetBitSize()];
        memset(buffer, nullChar, TBitEncoder::stGetBitSize());
        //
        if (0 == fread(buffer, sizeof (TByte), TBitEncoder::stGetBitSize(), ptrReadFile))
            bDataDry = true;
        else
        {
            progressBar.Show(readBit);
            encoder().doEncode(buffer, (unsigned long int) (TBitEncoder::stGetBitSize()));
            //
            const TByte* encodedBuff = NULL;
            encodedBuff = IFileAgent::encoder().getBuffer().getData();
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
}
