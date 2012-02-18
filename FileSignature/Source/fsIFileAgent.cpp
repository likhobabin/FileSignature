#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsBitEncoder.h"
#include "fsIFileAgent.h"
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

IFileAgent::IFileAgent(long int __FEncBitSize) :
FInputFilePath("InputFilePath::Unknown"),
FOutputFilePath("OutputFilePath::Unknown"),
FInputFlSize(0x0LL),
FEncoder(*(new TBitEncoder(__FEncBitSize)))
{
}
//

IFileAgent::~IFileAgent(void)
{
    delete(&FEncoder);
}
//********************************//

off64_t IFileAgent::stFileSize(FILE* __FPtrFile)
{
    off64_t outSize;
    //
    fseeko64(__FPtrFile, 0x0L, SEEK_END);
    //
    outSize = ftello64(__FPtrFile);
    //
    fseeko64(__FPtrFile, 0x0L, SEEK_SET);
    ///
    return (outSize);
}
//

void IFileAgent::stCloseFile(FILE* __FCloseFile)
{
    if (NULL != __FCloseFile)
    {
        fclose(__FCloseFile);
        __FCloseFile = NULL;
    }
}