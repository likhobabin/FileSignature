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
TFileAgentThr::TFileAgentThr(long int __FEncBitSize) :
IFileAgent(__FEncBitSize),
FThrSharedBuff(*(new TBuffer(__FEncBitSize)))
{
}
//

void TFileAgentThr::doGenerate(const std::string& __FInputFilePath,
                               const std::string& __FOutputFilePath)
{
    TMutex thrSyncMutex;
    TBuffWriteThread wrThread(__FInputFilePath, thrSyncMutex);
    TBuffReadThread rdThread(__FOutputFilePath, thrSyncMutex);
    //
    wrThread.doStart(&FThrSharedBuff);
    rdThread.doStart(&FThrSharedBuff);
}
//

TFileAgentThr::~TFileAgentThr(void)
{
}

//****************************************************
bool TFileAgentThr::stBDataDry = false;
