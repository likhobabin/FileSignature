#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsMutex.h"
#include "fsIBuffThread.h"
#include "fsIFileAgent.h"
#include "fsFileAgentThr.h"
#include "fsBitEncoder.h"
#include "fsBuffWriteThread.h"
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

TBuffWriteThread::TBuffWriteThread(std::string __FReadFilePath, TMutex& __FMutex) :
IBuffThread(__FMutex),
FReadFilePath(__FReadFilePath),
FReadFile(NULL)
{
}
//

void TBuffWriteThread::setUp(void)
{
    FReadFile = fopen64(readFilePath().c_str(), "rb");
    if (NULL == FReadFile)
        throw TException("Error TBuffWriteThread::setUp [ NULL ] <= [ ptrReadFile = fopen64(...) ]");
    //
    printf("\nDebug TBuffWriteThread::setUp [ Write Buffer Thread Has Set Up ]\n");
}
//

void* TBuffWriteThread::execute(void)
{
    printf("\nDebug TBuffWriteThread::execute [ Write Buffer Thread Has Started ]\n");
    ////
    mutex().doLock();
    TFileAgentThr::thrCount++;
    mutex().doUnlock();
//    off64_t itQuantity = IFileAgent::stFileSize(FReadFile) / sizeof (TByte);
//    bool bDataDry = false;
//    off64_t idx = 0x0LL;
//    //
//    for (; itQuantity > idx && !bDataDry; idx++)
//    {
//        ////
//        printf("\nDebug TBuffWriteThread::execute [ Try Lock Mutex ] \n");
//        mutex().doLock();
//        //
//        if (!getSharedBuffer()->isEmpty())
//        {
//            mutex().doWait();
//            //
//            printf("\nDebug TBuffWriteThread::execute [ waiting file to being read...  mutex().doWait() ]\n");
//        }
//        else
//        {
//            unsigned long int encodeBuffSize = TBitEncoder::stGetBitSize();
//            TByte nullChar = '0';
//            TByte buffer[encodeBuffSize];
//            //
//            memset(buffer, nullChar, encodeBuffSize);
//            //
//            if (0 == fread(buffer, sizeof (TByte), encodeBuffSize, FReadFile))
//            {
//                TFileAgentThr::setDataDry(true);
//                bDataDry = true;
//            }
//            //
//            TBuffer& sharedBuff = *(getSharedBuffer());
//            sharedBuff.doFill(buffer, encodeBuffSize);
//            //
//            printf("\nDebug TBuffWriteThread::execute [ writing file... fread(...) ]\n");
//        }
//        ///
//        printf("\nDebug TBuffWriteThread::execute [ Try UnLock Mutex ] \n");
//        mutex().doUnlock();
//    }
//    ////
//    IFileAgent::stCloseFile(FReadFile);
//    ////
//    printf("\nDebug TBuffWriteThread::execute [ Write Buffer Thread is finishing ]\n");
//    ////
    return (NULL);
}

//

TBuffWriteThread::~TBuffWriteThread(void)
{
    printf("\nDebug TBuffWriteThread::~TBuffWriteThread [ Destroy ]\n");
}