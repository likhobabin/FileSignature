#include "fsPrecompile.h"
//
#include "fsUnifException.h"
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
#ifdef __fsLinux
TException::TException(void) throw () :
#else

__CLR_OR_THIS_CALL TException::TException(void) :
#endif
std::exception()
{
}
//
#ifdef __fsLinux
TException::TException(const char* __FErrDescr) :
std::exception(),
FDescription(__FErrDescr)
#else

__CLR_OR_THIS_CALL TException::TException(const char* __FErrDescr) :
std::exception(__FErrDescr)
#endif
{
}
//
#ifdef __fsLinux
TException::TException(const std::string& __FErrDescr) :
std::exception(),
FDescription(__FErrDescr)
#else

__CLR_OR_THIS_CALL TException::TException(std::string __FErrDescr) :
std::exception(__FErrDescr.c_str())
#endif
{
}
//
#ifdef __fsLinux
TException::TException(const TException& __FFrom) :
std::exception()
#else

__CLR_OR_THIS_CALL TException::TException(const TException& __FFrom) :
std::exception(__FFrom.what())
#endif
{
#ifdef __fsLinux
    (*this) = __FFrom;
#endif
}
//
#ifdef __fsLinux
const char* TException::what(void) const throw ()
#else

const char* __CLR_OR_THIS_CALL TException::what(void) const
#endif
{
#ifdef __fsLinux
    return ( FDescription.c_str());
#else
    return ( std::exception::what());
#endif
}
//
#ifdef __fsLinux
TException& TException::operator=(const TException& __FFrom)
#else

TException& __CLR_OR_THIS_CALL TException::operator=(const TException& __FFrom)
#endif
{
    if ((&__FFrom) == this)
        return (*this);
    //
#ifdef __fsLinux
    FDescription = __FFrom.getDescription();
#else
    std::exception::operator=(__FFrom);
#endif
    //
    return (*this);
}
//
#ifdef __fsLinux
TException::~TException(void) throw ()
#else

__CLR_OR_THIS_CALL TException::~TException(void)
#endif
{
}