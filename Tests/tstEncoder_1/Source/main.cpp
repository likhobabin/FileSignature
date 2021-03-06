#include <fsPrecompile.h>
//
#include <fsBuffer.h>
#include <fsBitEncoder.h>
#include <fsIFileAgent.h>
#include <fsFileAgent.h>
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

static void checkArgQuantity(int /*__argc*/);
static void extractInputPath(const char* __args[], std::string& /*__inputPath*/);
static void extractOutputPath(const char* __args[], std::string& /*__outputPath*/);
static void extractBitSize(const char* __args[], long int& /*__bitSize*/);
static void debugArguments(int /*__argc*/, const char* __args[]);
/////

int main(int argc, const char* args[])
{
    unsigned long int length = 256; //0x100000000;
    unsigned long int offset = 9; //0x100000000;
    offset ^= length;
    //
    try
    {
        checkArgQuantity(argc);
        //
        std::string inputPath("");
        std::string outputPath("");
        //
        extractInputPath(args, inputPath);
        extractOutputPath(args, outputPath);
        //
        long int bitSize = 0x0L;
        extractBitSize(args, bitSize);
        //
        printf("\n*****Debug main [ MD5 Of OpenSSL] <= [ Hash Algorithm Representation ]****\n\n");
        //
        debugArguments(argc, args);
        //
        TFileAgent fileAgent(bitSize);
        //
        fileAgent.doGenerate(inputPath, outputPath);
        //
        printf("\nDebug [***The End***] <= [ File Agent finished job ] =)\n");
    }
    catch (std::exception& ex)
    {
        printf("\nDebug std::exception [%s] \n", ex.what());
    }
    catch (...)
    {
        printf("\nDebug unexpected exception \n");
    }
    return (0);
}
//**************************************************************************************************//

static void checkArgQuantity(int __argc)
{
    const int correctArgQuantity = 4;
    if (correctArgQuantity != __argc)
        throw TException("Error chechArgs [ incorrect argument quantity ]");
}
///

static void extractInputPath(const char* __args[], std::string& __inputPath)
{
    const unsigned int argIdx = 1;
    __inputPath = __args[argIdx];
}
//

static void extractOutputPath(const char* __args[], std::string& __outputPath)
{
    const unsigned int argIdx = 2;
    __outputPath = __args[argIdx];
}
//

static void extractBitSize(const char* __args[], long int& __bitSize)
{
    const unsigned int argIdx = 3;
    const char* convertStr = __args[argIdx];
    //
    __bitSize = atol(convertStr);
    //
    if ((LONG_MAX == __bitSize) || (LONG_MIN == __bitSize))
        throw TException("Error extractBitSize [value is out of the range of representable values] <= [ Input Bit Size]");
    //
    if (0x0L >= __bitSize)
        throw TException("Error extractBitSize [no valid conversion could be performed] <= [Input Bit Size]");
    //   
}
//

static void debugArguments(int __argc, const char* __args[])
{
    const int nfArgQuantity = 4;
    //
    if (__argc == nfArgQuantity)
    {
        printf("Debug debugArguments List Arguments \
            \n\t[ %s ] <= [ Input File Path ] \
            \n\t[ %s ] <= [ Output File Path ] \
            \n\t[ %s ] <= [ Size Of Input Bit Of Hash Func ]\n",
               __args[1],
               __args[2],
               __args[3]);
    }
}