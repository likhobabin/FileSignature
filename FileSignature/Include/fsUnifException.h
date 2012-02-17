#ifndef __FSUNIFEXCEPTION_H__
#define __FSUNIFEXCEPTION_H__
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////

class TException : public std::exception {
public:
#ifdef __fsLinux
    ////
    TException(void) throw ();
    TException(const char*);
    TException(const std::string&);
    TException(const TException&);
    //
    TException& operator=(const TException&);
    virtual const char* what(void) const throw ();
    //

    const std::string& getDescription(void) const {
        return (FDescription);
    }
    //
    virtual ~TException(void) throw ();

private:
    std::string FDescription;
#else
#if defined(__fsWindows)
    __CLR_OR_THIS_CALL TException(void);
    __CLR_OR_THIS_CALL TException(const char*);
    __CLR_OR_THIS_CALL TException(const std::string&);
    __CLR_OR_THIS_CALL TException(const TException&);
    //
    TException& __CLR_OR_THIS_CALL operator=(const TException&);
    virtual const char* __CLR_OR_THIS_CALL what(void) const;
    //
    virtual __CLR_OR_THIS_CALL ~TException(void);
#endif
    ////
#endif
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
#endif // __FSUNIFEXCEPTION_H__
