#ifndef __FSPRECOMPILE_H__
#define __FSPRECOMPILE_H__
////
#include <iostream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <string.h>
#include <limits.h>
#include <openssl/md5.h>
//
#include "fsException.h"
////
typedef unsigned char TByte;
////
#ifdef _MSC_VER
#pragma pack(push,8)
#endif
//
#ifdef __BORLANDC__
#pragma option push -w -O2 -vi- -b -6 -k -a8 -pc -ff
#endif
////
////
#ifdef _MSC_VER
#pragma pack(pop)
#endif
//
#ifdef __BORLANDC__
#pragma option pop
#endif
////
#endif // __FSBITGENERATOR_H__
