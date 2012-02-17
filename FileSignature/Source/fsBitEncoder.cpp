#include "fsPrecompile.h"
//
#include "fsBuffer.h"
#include "fsBitEncoder.h"
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
long int TBitEncoder::stBitSize = 0x100000L;
//******************************************
//

TBitEncoder::TBitEncoder(long int __FBitSize) :
FBuffer(*(new TBuffer()))
{
    stSetBitSize(__FBitSize);
}
//

void TBitEncoder::doEncode(const TByte __FInputData[], unsigned long int __FLength)
{
    MD5_CTX md5Encoder;
    //
    if (1 != MD5_Init(&md5Encoder))
    {
        throw TException("Error TBitEncoder::doEncode [1 != ] <= [ MD5_Init(...) ]");
    }
    //
    TByte md5[MD5_DIGEST_LENGTH];
    unsigned long encodeBuffLength = MD5_DIGEST_LENGTH;
    //
    if (1 != MD5_Update(&md5Encoder, __FInputData, __FLength))
    {
        std::string errDescr("Error TBitEncoder::doEncode [1 != ] <= [ MD5_Update(...) ");
        //
        if (1 != MD5_Final(md5, &md5Encoder))
        {
            errDescr += "&& MD5_Final(...) ]";
        }
        else
        {
            errDescr += "]";
        }
        //
        throw TException(errDescr);
    }
    //
    if (1 != MD5_Final(md5, &md5Encoder))
        throw TException("Error TBitEncoder::doEncode [1 != ] <= [ MD5_Init(...)  ]");
    //
    Buffer().doFill(md5, encodeBuffLength);
}
//

TBitEncoder::~TBitEncoder(void)
{
    delete (&FBuffer);
}