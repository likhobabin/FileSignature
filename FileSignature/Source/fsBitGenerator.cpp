#include "fsPrecompile.h"
//
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
TBitGenerator::TBitGenerator(unsigned int __FBitSize=0x400)://1024 byte
   FBitSize(__FBitSize)
{
}

void TBitGenerator::inputData(void )
{
}
void TBitGenerator::outputData(void )
{
}

TBitGenerator::~TBitGenerator(void )
{
}
