#include "fsPrecompile.h"
//
#include "fsProgressBar.h"
////
#ifdef __BORLANDC__
#pragma option -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
//
#ifdef _MSC_VER
#pragma pack(8)
#pragma warning(disable:4355)
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#endif
////
TProgressBar::TProgressBar(unsigned long int __FAllIterators):
FAllIterators(__FAllIterators),
FLastPercent(0x0f),
bShow(false)
{
}
//
void TProgressBar::Show(unsigned long int __FItNum)
{
    double currProgress = progress(__FItNum);
    //
    char proc = 0x25;

    if(bShow && (101 != (unsigned int)currProgress) )
        printf("[ %3.0f %c ]\n", currProgress, proc);
}
//
TProgressBar::~TProgressBar(void)
{
}
//
double TProgressBar::onePercent(void )
{
    return( floor( (double)(FAllIterators/100) ) );
}
//
double TProgressBar::progress(unsigned long int __FItNum)
{
    unsigned long int outProgress=0x0;
    //
    outProgress = (double)floor((double)(__FItNum / onePercent() ));
    if(outProgress != FLastPercent)
    {
        bShow=true;
        FLastPercent = outProgress;
        if(101 == outProgress)
                printf("101");
    }
    else
        bShow=false;
    //
    return(outProgress);
}