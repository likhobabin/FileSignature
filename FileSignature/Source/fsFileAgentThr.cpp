#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsBitEncoder.h"
#include "fsMutex.h"
#include "fsIFileAgent.h"
#include "fsIBuffThread.h"
#include "fsFileAgentThr.h"
#include "fsBuffWriteThread.h"
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
/////

TFileAgentThr::TFileAgentThr(long int __FEncBitSize) :
IFileAgent(__FEncBitSize),
FThrSharedBuff(*(new TBuffer(__FEncBitSize)))
{
}
//

void TFileAgentThr::doGenerate(const std::string& __FInputFilePath,
                               const std::string& __FOutputFilePath)
{
    unsigned long int encBitSize = TBitEncoder::stGetBitSize();
    TMutex thrSyncMutex;
    TBuffWriteThread wrThread(__FInputFilePath, thrSyncMutex);
    TBuffReadThread rdThread(__FOutputFilePath, thrSyncMutex,
                             wrThread.getDataDryState(),
                             encBitSize);
    //
    wrThread.doStart(&FThrSharedBuff);
    rdThread.doStart(&FThrSharedBuff);
    //
    wrThread.join();
    rdThread.join();
}
//

TFileAgentThr::~TFileAgentThr(void)
{
}

