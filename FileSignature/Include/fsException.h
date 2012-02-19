#ifndef __FSEXCEPTION_H__
#define __FSEXCEPTION_H__
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
#endif // __FSEXCEPTION_H__
