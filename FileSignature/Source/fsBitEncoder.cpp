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

TBitEncoder::TBitEncoder(void) :
FBuffer(*(new TBuffer( )))
{
}
//

void TBitEncoder::doEncode(const TByte __FInputData[], unsigned long __FLength)
{

    MD5_CTX md5Encoder;
    //
    if(1 != MD5_Init(&md5Encoder))
       throw TException("Error TBitEncoder::doEncode [1 != ] <= [ MD5_Init(..,)  ]");
    //
    TByte md5[MD5_DIGEST_LENGTH];
    unsigned long encodeBuffLength = MD5_DIGEST_LENGTH;
    //
    if(1 != MD5_Update(&md5Encoder, __FInputData, __FLength))
        throw TException("Error TBitEncoder::doEncode [1 != ] <= [ MD5_Init(..,)  ]");
    //
    if (1 != MD5_Final(md5, &md5Encoder))
      throw TException("Error TBitEncoder::doEncode [1 != ] <= [ MD5_Init(..,)  ]");
    //
    Buffer().doFill(md5, encodeBuffLength);
}
//

void TBitEncoder::doClose(void)
{
    Buffer().doClose();
}
//

TBitEncoder::~TBitEncoder(void)
{
    doClose();
    delete (&FBuffer);
}

//***********************************************
unsigned long TBitEncoder::stBitSize = 0x100000;