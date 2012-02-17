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

class TBuffer {
public:
    TBuffer(void);
    TBuffer(const TByte data[], unsigned long int /*__FSize*/);
    TBuffer(unsigned long int /*__FSize*/);
    ///

    unsigned long int getSize(void) const {
        return (FSize);
    }
    //

    const TByte* getData(void) const {
        return (FData);
    }
    //
    void doFill(const TByte data[], unsigned long int /*__FSize*/);
    ///    
    ~TBuffer(void);

private:
    TByte* FData;
    unsigned long int FSize;
    //
    void Resize(unsigned long int /*__FSize*/);
    void Fill(const TByte __FFillInData[], unsigned long int /*__FSize*/);
    //

    void setSize(unsigned long int __FNewSize) {
        FSize = __FNewSize;
    }
    //

    TByte* getData(void) {
        return (FData);
    }
    //
    void Close(void);
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

