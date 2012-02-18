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

    unsigned long int getLength(void) const {
        return (FLength);
    }

    //

    unsigned long int getOffset(void) const {
        return (FOffset);
    }

    const TByte* getData(void) const {
        return (FData);
    }
    //

    bool isEmpty(void) const {
        return ((0x0L == getLength()) ? (true) : (false));
    }
    //
    void doFill(const TByte __FInData[], unsigned long int /*__FInLength*/);
    void doRead(TByte __FOutData[], unsigned long int /*__FOutLength*/);

    void doReset(void) {
        setOffset(0x0L);
    }
    //
    void doErase(void);
    ///    I
    ~TBuffer(void);

private:
    TByte* FData;
    unsigned long int FSize;
    unsigned long int FLength;
    unsigned long int FOffset;
    //
    void Resize(unsigned long int /*__FSize*/);
    void Fill(const TByte __FFillInData[], unsigned long int /*__FSize*/);
    //

    void setSize(unsigned long int __FNewSize) {
        FSize = __FNewSize;
    }
    //

    void setLength(unsigned long int __FLength) {
        FLength = __FLength;
    }
    //

    void setOffset(unsigned long int __FOffset) {
        FOffset = __FOffset;
    }

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

