#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsMutex.h"
#include "fsBuffThread.h"
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
TBuffThread(__FMutex),
FReadFilePath(__FReadFilePath),
FReadFile(NULL)
{
}
//

TBuffWriteThread::~TBuffWriteThread(void)
{
}