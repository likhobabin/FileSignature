#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsBitGenerator.h"
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
/////
TBitGenerator::TBitGenerator(void )://1024 byte
   FBuffer(*(new TBuffer( TBitGenerator::stGetBitSize() )))
{
}
//
void TBitGenerator::doWrite(TByte __FData[], unsigned long __FLength)
{
 Buffer().doFill(__FData, __FLength);
}
//
void TBitGenerator::doClose(void )
{
 Buffer().doClose();
}
//
TBitGenerator::~TBitGenerator(void )
{
 doClose();
 delete (&FBuffer);
}
