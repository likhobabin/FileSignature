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
FReadFile(NULL),
FDataDry(false)
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
    unsigned long int encodeBuffSize = TBitEncoder::stGetBitSize();
    bool bDataDry = false;
    //
    for (; !bDataDry; )
    {
        printf("\nDebug TBuffWriteThread::execute [ Try Lock Mutex ] \n");
        mutex().doLock();
        printf("\nDebug TBuffWriteThread::execute [ Lock Mutex is Gotten ] \n");
        ////
        if (!getSharedBuffer()->hasRead())
        {
            mutex().doWait();
            ////
            printf("\nDebug TBuffWriteThread::execute [ waiting file to being read...  mutex().doWait() ]\n");
        }
        else
        {
            TByte nullChar = '0';
            TByte buffer[encodeBuffSize];
            //
            memset(buffer, nullChar, encodeBuffSize);
            //
            if (0 == fread(buffer, sizeof (TByte), encodeBuffSize, FReadFile))
            { 
                setDataDry(true);
                printf("\nDebug TBuffWriteThread::execute [ File Ended Up ]\n");
                bDataDry = true;
            }
            else
            {
            //
            TBuffer& sharedBuff = *(getSharedBuffer());
            sharedBuff.doFill(buffer, encodeBuffSize);
            //
            printf("\nDebug TBuffWriteThread::execute [ writing file... fread(...) ]\n");
            }
        }
        //
        printf("\nDebug TBuffWriteThread::execute [ Try UnLock Mutex ] \n");
        mutex().doUnlock();
    }
    //
    IFileAgent::stCloseFile(FReadFile);
    //
    printf("\nDebug TBuffWriteThread::execute [ Write Buffer Thread is finishing ]\n");
    ////
    return (NULL);
}

//

TBuffWriteThread::~TBuffWriteThread(void)
{
    printf("\nDebug TBuffWriteThread::~TBuffWriteThread [ Destroy ]\n");
}