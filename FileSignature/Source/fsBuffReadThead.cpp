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
                                 const bool& __bDataDryState,
                                 long int __FEncBitSize) :
IBuffThread(__FMutex),
FWriteFilePath(__FWriteFilePath),
FEncoder(*(new TBitEncoder(__FEncBitSize))),
bDataDryState(__bDataDryState)
{
}
//

void TBuffReadThread::setUp(void)
{

    IBuffThread::getFileHandlerRef() = fopen64(writeFilePath().c_str(), "wb");
    if (NULL == IBuffThread::getFileHandler())
    {
        mutex().doLock();
        //
        TFileAgentThr::stSetExitSignal(true);
        //
        mutex().doUnlock();
        //
        IBuffThread::setExtraExit(true);
    }
    //printf("\nDebug TBuffReadThread::setUp [ Read Buffer Thread Has Set Up ]\n");

}
//

void* TBuffReadThread::execute(void)
{
    //printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread Has Started ]\n");
    if (!IBuffThread::ExtraExit())
    {
        bool bUnLock = false;
        bool bDataDry = false;

        for (; !bDataDry && !IBuffThread::ExtraExit();)
        {
            try
            {
                //printf("\nDebug TBuffReadThread::execute [ Try Lock Mutex ] \n");
                mutex().doLock();
                //printf("\nDebug TBuffReadThread::execute [ Mutex is locked ] \n");
                ////     
                if (TFileAgentThr::stGetExitSignal())
                {
                    IBuffThread::setExtraExit(true);
                    mutex().doUnlock();
                }
                //
                if (!IBuffThread::ExtraExit())
                {
                    if (getDataDryState())
                    {
                        IBuffThread::setExtraExit(true);
                        //printf("\nDebug TBuffReadThread::execute [ Data is over ]\n");
                    }
                    //
                    if (!getSharedBuffer()->hasRead())
                    {
                        unsigned long int encBuffSize = TBitEncoder::stGetBitSize();
                        TByte nullChar = '0';
                        TByte encBuffer[encBuffSize];
                        //
                        memset(encBuffer, nullChar, encBuffSize);
                        //
                        TBuffer& sharedBuff = *(getSharedBuffer());
                        //
                        //printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread is getting data ]\n");
                        sharedBuff.doRead(encBuffer, encBuffSize);
                        //printf("\nDebug TBuffReadThread::encodeAndWriteFile [ Read Buffer Thread has gotten data ]\n");
                        ////
                        //printf("\nDebug TBuffReadThread::execute [ Try UnLock Mutex ] \n");
                        mutex().doUnlock();
                        bUnLock = true;
                        //printf("\nDebug TBuffReadThread::execute [ UnLock Mutex Is Gotten ] \n");
                        ////
                        encodeAndWriteFile(encBuffer, encBuffSize);
                    }
                    else
                    {
                        if (!bDataDry)
                        {
                            mutex().doSignal();
                            //printf("\nDebug TBuffReadThread::execute [ Read Buffer Thread is waiting data ]\n");
                            //      
                            //printf("\nDebug TBuffReadThread::execute [ Try UnLock Mutex ] \n");

                            //printf("\nDebug TBuffReadThread::execute [ UnLock Mutex Is Gotten ] \n");
                        }
                        mutex().doUnlock();
                    }

                }
            }
            catch (std::exception& /*ex*/)
            {
                TFileAgentThr::stSetExitSignal(true);
                IBuffThread::setExtraExit(true);
                //
                if (!bUnLock)
                    mutex().doUnlock();
            }
        }
        //
        IFileAgent::stCloseFile(IBuffThread::getFileHandler());
    }
    ////
    return (NULL);
}
//

TBuffReadThread::~TBuffReadThread(void)
{
}
//

void TBuffReadThread::encodeAndWriteFile(TByte __FEncBuff[],
                                         unsigned long int __FEncBuffSize)
{
    encoder().doEncode(__FEncBuff, __FEncBuffSize);
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
