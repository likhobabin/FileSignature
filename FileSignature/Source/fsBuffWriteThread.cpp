#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsMutex.h"
#include "fsIBuffThread.h"
#include "fsIFileAgent.h"
#include "fsFileAgentThr.h"
#include "fsBitEncoder.h"
#include "fsBuffWriteThread.h"
#include "fsProgressBar.h"
////

#ifdef _MSC_VER
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#endif
/////

TBuffWriteThread::TBuffWriteThread(std::string __FReadFilePath, TMutex& __FMutex) :
IBuffThread(__FMutex),
FReadFilePath(__FReadFilePath),
bDataDryState(false)
{
}
//

void TBuffWriteThread::setUp(void)
{
    try
    {
        IBuffThread::getFileHandlerRef() = fopen64(readFilePath().c_str(), "rb");
        if (NULL == IBuffThread::getFileHandler())
            throw TException("Error TBuffWriteThread::setUp [ NULL ] <= "
                             "      [ IBuffThread::getFileHandler() = fopen64(...) ]");
        //
        //printf("\nDebug TBuffWriteThread::setUp [ Write Buffer Thread Has Set Up ]\n");
        ////
    }
    catch (std::exception& /*ex*/)
    {
        mutex().doLock();
        //
        TFileAgentThr::stSetExitSignal(true);
        //
        mutex().doUnlock();
    }
}
//

void* TBuffWriteThread::execute(void)
{
    //printf("\nDebug TBuffWriteThread::execute [ Write Buffer Thread Has Started ]\n");
    ////
    unsigned long int encodeBuffSize = TBitEncoder::stGetBitSize();
    bool bExit = false;
    //
    off64_t rdFileSize = 0x0LL;
    long int bitSize = 0x0L;
    unsigned long int allIterators = 0x0L;
    unsigned long int readBit = 0x0L;
    //
    rdFileSize = IFileAgent::stFileSize(IBuffThread::getFileHandler());
    bitSize = TBitEncoder::stGetBitSize();
    allIterators = (unsigned long int) (rdFileSize / bitSize);
    //
    TProgressBar progressBar(allIterators);
    //
    for (; !bExit;)
    {
        try
        {
            //printf("\nDebug TBuffWriteThread::execute [ Try Lock Mutex ] \n");
            mutex().doLock();
            //printf("\nDebug TBuffWriteThread::execute [ Lock Mutex is Gotten ] \n");

            if (TFileAgentThr::stGetExitSignal())
                bExit = true;
            //
            if (!bExit)
            {
                if (!getSharedBuffer()->hasRead())
                {
                    mutex().doWait();
                    //printf("\nDebug TBuffWriteThread::execute [ waiting file to being read...  mutex().doWait() ]\n");
                }
                else
                {
                    TByte nullChar = '0';
                    TByte buffer[encodeBuffSize];
                    //
                    memset(buffer, nullChar, encodeBuffSize);
                    //
                    if (0 == fread(buffer, sizeof (TByte), encodeBuffSize,
                                   IBuffThread::getFileHandler()))
                    {
                        //printf("\nDebug TBuffWriteThread::execute [ File Ended Up ]\n");
                        bExit = true;
                        setDataDryState(true);
                    }
                    else
                    {
                        ++readBit;
                        progressBar.Show(readBit);
                        //
                        TBuffer& sharedBuff = *(getSharedBuffer());
                        sharedBuff.doFill(buffer, encodeBuffSize);
                        //
                        //printf("\nDebug TBuffWriteThread::execute [ writing file... fread(...) ]\n");
                    }
                }
            }
            //
            //printf("\nDebug TBuffWriteThread::execute [ Try UnLock Mutex ] \n");
            mutex().doUnlock();
            //printf("\nDebug TBuffReadThread::execute [ UnLock Mutex Is Gotten ] \n");
        }
        catch (std::exception& /*ex*/)
        {
            TFileAgentThr::stSetExitSignal(true);
            bExit = true;
            //
            mutex().doUnlock();
        }
    }
    //
    IFileAgent::stCloseFile(IBuffThread::getFileHandler());
    //
    return (NULL);
}
//

TBuffWriteThread::~TBuffWriteThread(void)
{
}