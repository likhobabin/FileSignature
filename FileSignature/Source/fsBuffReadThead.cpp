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
                                 long int __FEncBitSize) :
IBuffThread(__FMutex),
FWriteFilePath(__FWriteFilePath),
FWriteFile(NULL),
FEncoder(*(new TBitEncoder(__FEncBitSize)))
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
    
    mutex().doLock();
    TFileAgentThr::thrCount++;
    mutex().doUnlock();
//    bool bDataDry = false;
//    //
//    for (; !bDataDry;)
//    {
//        ////
//        printf("\nDebug TBuffReadThread::execute [ Try Lock Mutex ] \n");
//        mutex().doLock();
//        ////
//        if (TFileAgentThr::stDataDry())
//        {
//            bDataDry = true;
//            printf("\nDebug TBuffReadThread::execute [ Data is over ]\n");
//        }
//        else
//        {
//            unsigned long int encodeBuffSize = TBitEncoder::stGetBitSize();
//            TByte nullChar = '0';
//            TByte buffer[encodeBuffSize];
//            //
//            memset(buffer, nullChar, encodeBuffSize);
//            //
//            if (getSharedBuffer()->isEmpty())
//            {
//                mutex().doSignal();
//                printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is waiting data ]\n");
//            }
//            else
//            {
//                TBuffer& sharedBuff = *(getSharedBuffer());
//                //
//                printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is getting data ]\n");
//                sharedBuff.doRead(buffer, encodeBuffSize);
//                printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread has gotten data ]\n");
//                //
//                encoder().doEncode(buffer, encodeBuffSize);
//                printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread has passed data to encode ]\n");
//                const TByte* encodedBuff = NULL;
//                encodedBuff = encoder().getBuffer().getData();
//                printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread has gotten encoded data ]\n");
//                //
//                if (encodeBuffSize != fwrite(encodedBuff, sizeof (TByte),
//                                             encodeBuffSize,
//                                             FWriteFile))
//                {
//                    IFileAgent::stCloseFile(FWriteFile);
//                    throw TException("Error TFileAgent::doGenerate [ FAILED ] <= [ fwrite ]");
//                }
//                //
//                printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread has written data bit to file ]\n");
//            }
//        }
//        ////
//        printf("\nDebug TBuffReadThread::execute [ Try UnLock Mutex ] \n");
//        mutex().doUnlock();
//        ////
//    }
//    ////
//    IFileAgent::stCloseFile(FWriteFile);
    ///
    printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is finishing ]\n");
    ///
    return (NULL);
}

//

TBuffReadThread::~TBuffReadThread(void)
{
    printf("\nDebug TBuffReadThread::~TBuffReadThread [ Destroy ]\n");
}
