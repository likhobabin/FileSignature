#include "fsPrecompile.h"
//
#include "fsException.h"
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
TException::TException(void) throw () :
std::exception()
{
}
//

TException::TException(const char* __FErrDescr) :
std::exception(),
FDescription(__FErrDescr)
{
}
//
TException::TException(const std::string& __FErrDescr) :
std::exception(),
FDescription(__FErrDescr)
{
}
//
TException::TException(const TException& __FFrom) :
std::exception()
{
    (*this) = __FFrom;
}
//
const char* TException::what(void) const throw ()
{
    return ( FDescription.c_str());
}
//
TException& TException::operator=(const TException& __FFrom)
{
    if ((&__FFrom) == this)
        return (*this);
    //
    FDescription = __FFrom.getDescription();
    //
    return (*this);
}
//
TException::~TException(void) throw ()
{
}