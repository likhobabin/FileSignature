#ifndef __FSEXCEPTION_H__
#define __FSEXCEPTION_H__
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
#endif // __FSEXCEPTION_H__
