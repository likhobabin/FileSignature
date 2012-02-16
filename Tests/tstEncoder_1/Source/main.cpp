#include <fsPrecompile.h>
//
#include <fsBuffer.h>
#include <fsBitEncoder.h>
#include <fsFileAgent.h>
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
static void debugArguments(int /*__argc*/, const char* __args[]);
static void checkArgQuantity(int /*__argc*/);
static void extractInputPath(const char* __args[], std::string& /*__inputPath*/);
static void extractOutputPath(const char* __args[], std::string& /*__outputPath*/);
/////
int main(int argc, const char* args[])
{
 try
  {
    debugArguments(argc, args);
    //
    checkArgQuantity(argc);
    //
    std::string inputPath("");
    std::string outputPath("");
    //
    extractInputPath(args, inputPath);
    extractOutputPath(args, outputPath);
    //
    TFileAgent fileAgent;
    //
    fileAgent.doGenerate(inputPath, outputPath);
    printf("\n\nDebug [ %lld ] <= [ Input File Size Byte ]\n", 
           fileAgent.inPutFileSizeByte());
  }
 catch(std::exception& ex)
  {
     printf("\nDebug std::exception [%s] <= [Description]\n", ex.what());
  }
 catch(...)
  {
     printf("\nDebug unexpected exception \n");
  }
 return(0);
}
//**************************************************************************************************//
static void debugArguments(int __argc, const char* __args[])
{
    printf("Debug debugArguments List Arguments \n\t");
    for(int idx=0x0; __argc > idx; idx++)
    {
        printf("Debug debugArguments [ %d ] <= [ %s ]\n\t", idx, __args[idx]);
    }
}
//
static void checkArgQuantity(int __argc)
{
    const int correctArgQuantity=3;
    if(correctArgQuantity != __argc)
        throw TException("Error chechArgs [ incorrect argument quantity ]");
}
///
static void extractInputPath(const char* __args[], std::string& __inputPath)
{
    unsigned int argIdx = 1;
    __inputPath = __args[argIdx];
}
//
static void extractOutputPath(const char* __args[], std::string& __outputPath)
{
    unsigned int argIdx = 2;
    __outputPath = __args[argIdx];
}