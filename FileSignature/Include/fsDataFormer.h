#ifndef __FSDATAFORMER_H__
#define __FSDATAFORMER_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class TBitGenerator;
//
class TDataFormer
{
public:
   TDataFormer(void );
   //
   void readFrom(const char* __FInputFilePath=0);
   void writeTo(const char* __FOutputFilePath=0);
   //
   ~TDataFormer(void );

private:
   TBitGenerator& FGenerator;
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
#endif // __FSDATAFORMER_H__
