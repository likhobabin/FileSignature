#ifndef __FSBITENCODER_H__
#define __FSBITENCODER_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class TBuffer;
//
class TBitEncoder 
{
public:
    static unsigned long stGetBitSize(void) 
    {
        return (stBitSize);
    }
    //*****************************************************//
    TBitEncoder(void ); 
    //
    void doEncode(const TByte __FInputData[], unsigned long /*__FLength*/);
    //
    const TBuffer& getBuffer(void) const 
    {
        return (FBuffer);
    }
    //
    void doClose(void);
    //
    ~TBitEncoder(void);

private:
    static unsigned long stBitSize; //1048576 byte
    TBuffer& FBuffer;
    //
    TBuffer& Buffer(void) 
    {
        return (FBuffer);
    }
};
////
#ifdef _MSC_VER
#pragma pack(pop)
#endif
//
#ifdef __BORLANDC__
#pragma option pop
#endif
////
#endif // __FSBITGENERATOR_H__
