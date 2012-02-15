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
   void doRead(const std::string& /*__FInputFilePath*/);
   void doWrite(const std::string& /*__FOutputFilePath*/);
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
