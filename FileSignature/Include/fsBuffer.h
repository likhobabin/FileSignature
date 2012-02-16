#ifndef __FSBUFFER_H__
#define	__FSBUFFER_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
class TBuffer
{
public:
    TBuffer(void);
    TBuffer(const TByte data[], unsigned long /*__FSize*/);
    TBuffer(unsigned long /*__FSize*/);
    ///
    unsigned long getSize(void ) const 
    {
        return(FSize);
    }
    //
    const TByte* getData(void ) const
    {
        return(FData);
    }
    //
    void doFill(const TByte data[], unsigned long /*__FSize*/);
    void doClose(void );
    ///    
    ~TBuffer(void);
    
private:
    TByte* FData; 
    unsigned long FSize;
    //
    void Resize(unsigned long /*__FSize*/);
    void Fill(const TByte __FFillInData[], unsigned long /*__FSize*/);
    //
    void setSize(unsigned long __FNewSize)
    {
        FSize = __FNewSize;
    }
    //
    TByte* getData(void )  
    {
        return(FData);
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
#endif	/*__FSBUFFER_H__ */

