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
FSize(0x0L)
{
}
//

TBuffer::TBuffer(unsigned long int __FSize) :
FData(NULL),
FSize(__FSize)
{
    TByte nullChar = '0';
    //
    FData = new TByte[__FSize];
    memset(FData, nullChar, getSize());
}
//

TBuffer::TBuffer(const TByte __FData[], unsigned long int __FSize) :
FData(NULL),
FSize(0x0L)
{
    doFill(__FData, __FSize);
}
//

void TBuffer::doFill(const TByte __FData[], unsigned long int __FSize)
{
    if (__FSize != getSize())
        Resize(__FSize);
    //
    Fill(__FData, __FSize);
}
///

void TBuffer::doClear(void )
{
    if(0x0L != getSize())
    {
        TByte* oldData=NULL;
        //
        oldData = FData;
        FData=NULL;
        setSize(0x0L);
        //
        delete[] oldData;
        oldData=NULL;
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

void TBuffer::Fill(const TByte __FFillInData[], unsigned long int __FSize)
{
    TByte nullChar = '0';
    memset(FData, nullChar, __FSize);
    memcpy(FData, __FFillInData, __FSize);
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