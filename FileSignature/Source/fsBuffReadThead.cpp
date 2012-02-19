#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsMutex.h"
#include "fsIBuffThread.h"
#include "fsBitEncoder.h"
#include "fsIFileAgent.h"
#include "fsFileAgentThr.h"
#include "fsBuffReadThread.h"
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

TBuffReadThread::TBuffReadThread(std::string __FWriteFilePath,
                                 TMutex& __FMutex,
                                 const bool& __bDataDry,
                                 long int __FEncBitSize) :
IBuffThread(__FMutex),
FWriteFilePath(__FWriteFilePath),
FWriteFile(NULL),
FEncoder(*(new TBitEncoder(__FEncBitSize))),
bDataDry(__bDataDry)
{
}
//

void TBuffReadThread::setUp(void)
{
    FWriteFile = fopen64(writeFilePath().c_str(), "wb");
    if (NULL == FWriteFile)
    {
        throw TException("Error TBuffReadThread::setUp [ NULL ] <= [ FWriteFile = fopen64(...) ]");
    }
    printf("\nDebug TBuffReadThread::setUp [ Read Buffer Thread Has Set Up ]\n");
}
//

void* TBuffReadThread::execute(void)
{
    printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread Has Started ]\n");

    printf("\nDebug TBuffReadThread::execute [ Try Lock Mutex ] \n");
    bool bDataDry = false;

    for (; !bDataDry;)
    {
        ////
        printf("\nDebug TBuffReadThread::execute [ Try Lock Mutex ] \n");
        mutex().doLock();
        printf("\nDebug TBuffReadThread::execute [ Mutex is locked ] \n");
        ////        
        if (getDataDry())
        {
            bDataDry = true;
            printf("\nDebug TBuffReadThread::execute [ Data is over ]\n");
        }
        ///
        if (!getSharedBuffer()->hasRead())
        {
            if (bDataDry)
                printf("\nDebug TBufferReaderThread::execute [true ] <= [Data Is Dry ];  \
                       [Buffer has yet some data]");
            encodeAndWriteFile();
        }
        else
            if (!bDataDry)
        {
            mutex().doSignal();
            printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is waiting data ]\n");
        }
        ////
        printf("\nDebug TBuffReadThread::execute [ Try UnLock Mutex ] \n");
        mutex().doUnlock();
        printf("\nDebug TBuffReadThread::execute [ UnLock Mutex Is Gotten ] \n");
        ////
    }
    ////
    IFileAgent::stCloseFile(FWriteFile);
    //
    printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is finishing ]\n");
    //
    return (NULL);
}

//

TBuffReadThread::~TBuffReadThread(void)
{
    printf("\nDebug TBuffReadThread::~TBuffReadThread [ Destroy ]\n");
}

//

void TBuffReadThread::encodeAndWriteFile(void)
{
    unsigned long int encodeBuffSize = TBitEncoder::stGetBitSize();
    TByte nullChar = '0';
    TByte buffer[encodeBuffSize];
    //
    memset(buffer, nullChar, encodeBuffSize);

    TBuffer& sharedBuff = *(getSharedBuffer());
    //
    printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread is getting data ]\n");
    sharedBuff.doRead(buffer, encodeBuffSize);
    printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has gotten data ]\n");
    //
    encoder().doEncode(buffer, encodeBuffSize);
    printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has passed data to encode ]\n");
    const TByte* encodedBuff = NULL;
    unsigned long int encodedBuffSize = 0x0L;
    //
    encodedBuffSize = encoder().getBuffer().getSize();
    encodedBuff = encoder().getBuffer().getData();
    printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has gotten encoded data ]\n");
    //
    if (encodedBuffSize != fwrite(encodedBuff, sizeof (TByte),
                                  encodedBuffSize,
                                  FWriteFile))
    {
        printf("\nDebug TBuffReadThread::encodeAndWriteFile [%ld] <= [ encodeBuffSize ]\n", encodeBuffSize);
        IFileAgent::stCloseFile(FWriteFile);
        throw TException("Error TBuffReadThread::encodeAndWriteFile [ FAILED ] <= [ fwrite ]");
    }
    else
    {
        printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Encoder Bit was successfully written ]\n");
    }
}
