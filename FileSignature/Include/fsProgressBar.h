#ifndef __FSPROGRESSBAR_H__
#define	__FSPROGRESSBAR_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////

class TProgressBar
{
public:
    TProgressBar(unsigned long int /*__FAllIterators*/);
    //
    void Show(unsigned long int /*__FItNum*/);
    //
    ~TProgressBar(void );    

private:
    unsigned long int FAllIterators;
    double FLastPercent;
    bool bShow;
    //
    double progress(unsigned long int /*__FItNum*/);
    double onePercent(void );
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
#endif	/* __FSPROGRESSBAR_H__ */

