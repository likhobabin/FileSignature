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

#ifdef _MSC_VER
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
FEncoder(*(new TBitEncoder(__FEncBitSize))),
bDataDry(__bDataDry)
{
}
//

void TBuffReadThread::setUp(void)
{
    try
    {
        IBuffThread::getFileHandlerRef() = fopen64(writeFilePath().c_str(), "wb");
        if (NULL == IBuffThread::getFileHandler())
        {
            throw TException("Error TBuffReadThread::setUp [ NULL ] <= [ FWriteFile = fopen64(...) ]");
        }
        //printf("\nDebug TBuffReadThread::setUp [ Read Buffer Thread Has Set Up ]\n");
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

void* TBuffReadThread::execute(void)
{
    //printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread Has Started ]\n");
    bool bExit = false;

    for (; !bExit;)
    {
        try
        {
            //printf("\nDebug TBuffReadThread::execute [ Try Lock Mutex ] \n");
            mutex().doLock();
            //printf("\nDebug TBuffReadThread::execute [ Mutex is locked ] \n");
            ////     
            if (TFileAgentThr::stGetExitSignal())
            {
                bExit = true;
            }
            //
            if (!bExit)
            {
                if (getDataDryState())
                {
                    bExit = true;
                    //printf("\nDebug TBuffReadThread::execute [ Data is over ]\n");
                }
                ///
                if (!getSharedBuffer()->hasRead())
                {
                    encodeAndWriteFile();
                }
                else
                    if (!bDataDry)
                {
                    mutex().doSignal();
                    //printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is waiting data ]\n");
                }
                ////
                //printf("\nDebug TBuffReadThread::execute [ Try UnLock Mutex ] \n");
                mutex().doUnlock();
                //printf("\nDebug TBuffReadThread::execute [ UnLock Mutex Is Gotten ] \n");
            }
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
    IBuffThread::setFileClosedState(true);
    ////
    return (NULL);
}
//

TBuffReadThread::~TBuffReadThread(void)
{
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
    //printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread is getting data ]\n");
    sharedBuff.doRead(buffer, encodeBuffSize);
    //printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has gotten data ]\n");
    //
    encoder().doEncode(buffer, encodeBuffSize);
    //printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has passed data to encode ]\n");
    const TByte* encodedBuff = NULL;
    unsigned long int encodedBuffSize = 0x0L;
    //
    encodedBuffSize = encoder().getBuffer().getSize();
    encodedBuff = encoder().getBuffer().getData();
    //printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has gotten encoded data ]\n");
    //
    if (encodedBuffSize != fwrite(encodedBuff, sizeof (TByte),
                                  encodedBuffSize,
                                  IBuffThread::getFileHandler()))
    {
        //printf("\nDebug TBuffReadThread::encodeAndWriteFile [%ld] <= [ encodeBuffSize ]\n", encodeBuffSize);
        //
        throw TException("Error TBuffReadThread::encodeAndWriteFile [ FAILED ] <= [ fwrite ]");
    }
}
