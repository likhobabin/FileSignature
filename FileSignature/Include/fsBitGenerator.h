#ifndef __FSBITGENERATOR_H__
#define __FSBITGENERATOR_H__
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

class TBitGenerator 
{
public:
    static unsigned long stGetBitSize(void) 
    {
        return (stBitSize);
    }
    //*****************************************************//
    TBitGenerator(void ); 
    //
    void doWrite(TByte __FData[], unsigned long /*__FLength*/);
    //
    const TBuffer& getBuffer(void) const 
    {
        return (FBuffer);
    }
    //
    void doClose(void);
    //
    ~TBitGenerator(void);

private:
    static const unsigned int stBitSize = 0x100000; //1048576 byte
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
