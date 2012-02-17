#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsBitEncoder.h"
#include "fsIFileAgent.h"
#include "fsFileAgentThr.h"
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
IFileAgent(__FEncBitSize)
{
}
//

void TFileAgentThr::doGenerate(const std::string& /*__FInputFilePath*/,
                               const std::string& /*__FOutputFilePath*/)
{
}
//

TFileAgentThr::~TFileAgentThr(void)
{
}
