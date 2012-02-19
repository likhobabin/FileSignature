#ifndef __FSBITENCODER_H__
#define __FSBITENCODER_H__
////

class TBuffer;
//

class TBitEncoder {
public:

    static long int stGetBitSize(void) {
        return (stBitSize);
    }
    //*****************************************************//
    //max bit size = 2147483647 byte
    TBitEncoder(long int __FBitSize = 0x100000L); //1048576 byte
    //
    void doEncode(const TByte __FInputData[], unsigned long int /*__FLength*/);
    //

    const TBuffer& getBuffer(void) const {
        return (FBuffer);
    }
    //
    ~TBitEncoder(void);

private:
    TBuffer& FBuffer;
    //

    TBuffer& Buffer(void) {
        return (FBuffer);
    }
    //******************************************
    static long int stBitSize;
    //

    static void stSetBitSize(long int __stBitSize) {
        if (0x0L < __stBitSize) {
            stBitSize = __stBitSize;
        }
    }
};

////
#endif // __FSBITGENERATOR_H__
