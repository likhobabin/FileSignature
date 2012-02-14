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
class TBitGenerator
{
public:
   TBitGenerator(unsigned int __FBitSize=0x400);//1024 byte

   void inputData(void );
   void outputData(void );

   ~TBitGenerator(void );

private:
   const unsigned int FBitSize;
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
