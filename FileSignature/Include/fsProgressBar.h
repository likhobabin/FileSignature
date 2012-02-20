#ifndef __FSPROGRESSBAR_H__
#define	__FSPROGRESSBAR_H__
////

class TProgressBar {
public:
    TProgressBar(unsigned long int /*__FAllIterators*/);
    //
    void Show(unsigned long int /*__FItNum*/);
    //
    ~TProgressBar(void);

private:
    unsigned long int FAllIterators;
    double FLastPercent;
    bool bShow;
    //
    double progress(unsigned long int /*__FItNum*/);
    double onePercent(void);
    //
    
    TProgressBar(const TProgressBar&);
    TProgressBar& operator=(const TProgressBar&);
    //
};

////
#endif	/* __FSPROGRESSBAR_H__ */

