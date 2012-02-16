#include "fsPrecompile.h"
//
#include "fsBuffer.h"
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

TBuffer::TBuffer(void):
FData(NULL),
FSize(0x0L)
{
}
//

TBuffer::TBuffer(unsigned long __FSize) :
FData(NULL),
FSize(__FSize)
{
    TByte nullChar = '0';
    //
    FData = new TByte[__FSize];
    memset(FData, getSize(), nullChar);
}
//

TBuffer::TBuffer(const TByte __FData[], unsigned long __FSize) :
FData(NULL),
FSize(0x0L)
{
    doFill(__FData, __FSize);
}
//

void TBuffer::doFill(const TByte __FData[], unsigned long __FSize)
{
    if (__FSize != getSize())
        Resize(__FSize);
    //
    Fill(__FData, __FSize);
    setSize(__FSize);
}
//

void TBuffer::doClose(void)
{
    if (NULL != FData)
    {
        delete(FData);
        FData = NULL;
        setSize(0x0L);
    }
}
///    
TBuffer::~TBuffer(void)
{
    doClose();
}
//***************************//
void TBuffer::Resize(unsigned long __FNewSize)
{
    TByte* newData = NULL;
    newData = new TByte[__FNewSize];
    //
    TByte* oldData = FData;
    //
    if (NULL != newData)
    {
        FSize = __FNewSize;
        FData = newData;
    }
    else
    {
        FSize = 0x0;
        FData = NULL;
    }
    //
    delete[] oldData;
    oldData = NULL;
}
//
void TBuffer::Fill(const TByte __FFillInData[], unsigned long __FSize)
{
    TByte nullChar = '0';
    memset(FData, __FSize, nullChar);
    memcpy(FData, __FFillInData, __FSize);
}
