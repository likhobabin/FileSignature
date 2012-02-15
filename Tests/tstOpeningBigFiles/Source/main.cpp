#include <fsPrecompile.h>
//
#include <fsBuffer.h>
#include <fsBitGenerator.h>
#include <fsDataFormer.h>
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
int main(int /*argc*/, const char** /*args*/)
{
 try
  {
    std::string inputPath = "/home/user/Workspace/Programming/FileSignature/Tests/tstData/1.txt";
    TDataFormer dataFormer;
    //
    dataFormer.doRead(inputPath);
  }
 catch(std::exception& )
  {
  }
 catch(...)
  {
  }
 return(0);
}
