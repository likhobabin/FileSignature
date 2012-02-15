#include "fsPrecompile.h"
//
#include "fsBitGenerator.h"
#include "fsDataFormer.h"
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
TDataFormer::TDataFormer(void ):
   FGenerator( *( new TBitGenerator( ) ) )
{
}
//
void TDataFormer::doRead(const std::string& /*__FInputFilePath*/)
{
}
//
void TDataFormer::doWrite(const std::string& /*__FOutputFilePath*/)
{
}
//
TDataFormer::~TDataFormer(void )
{
   delete(&FGenerator);
}
//