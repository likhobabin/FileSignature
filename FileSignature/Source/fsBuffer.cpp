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

TBuffer::TBuffer(void) :
FData(NULL),
FSize(0x0L),
FRightOffset(0x0L),
FLeftOffset(0x0L)
{
}
//

TBuffer::TBuffer(unsigned long int __FSize) :
FData(NULL),
FSize(__FSize),
FRightOffset(0x0L),
FLeftOffset(0x0L)
{
    TByte nullChar = '0';
    //
    FData = new TByte[__FSize];
    memset(FData, nullChar, getSize());
}
//

TBuffer::TBuffer(const TByte __FData[], unsigned long int __FSize) :
FData(NULL),
FSize(0x0L),
FRightOffset(0x0L),
FLeftOffset(0x0L)
{
    doFill(__FData, __FSize);
}
//

void TBuffer::doFill(const TByte __FInData[], unsigned long int __FInLength)
{
    if (__FInLength != getSize())
        Resize(__FInLength);
    //
    Fill(__FInData, __FInLength);
}
///

void TBuffer::doRead(TByte __FOutData[], unsigned long int __FOutLength)
{
    if ((getRightOffset() - getLeftOffset()) >= __FOutLength)
    {
        memcpy(__FOutData, getData() + getLeftOffset(), __FOutLength);
        //
        FLeftOffset ^= __FOutLength;
        FRightOffset -= FLeftOffset;
    }
}
///

TBuffer::~TBuffer(void)
{
    Close();
}
//***************************//

void TBuffer::Resize(unsigned long int __FNewSize)
{
    TByte* newData = NULL;
    newData = new TByte[__FNewSize];
    //
    TByte* oldData = NULL;
    oldData = FData;
    //
    if (NULL != newData)
    {
        setSize(__FNewSize);
        FData = newData;
    }
    else
    {
        setSize(0x0L);
        FData = NULL;
    }
    //
    delete[] oldData;
    oldData = NULL;
}
//

void TBuffer::Fill(const TByte __FFillInData[], unsigned long int __FLength)
{
    TByte nullChar = '0';
    memset(FData, nullChar, __FLength);
    memcpy(FData, __FFillInData, __FLength);
    setRightOffset(__FLength);
    setLeftOffset(0x0L);
}
//

void TBuffer::Close(void)
{
    if (NULL != FData)
    {
        delete(FData);
        FData = NULL;
    }
}