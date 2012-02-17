#ifndef __FSPRECOMPILE_H__
#define __FSPRECOMPILE_H__
////
#if defined(__MINGW32__)
#define __fsWindows
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#undef WINVER
#define WINVER _WIN32_WINNT
#else
#if 0x0601 > _WIN32_WINNT
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#undef WINVER
#define WINVER _WIN32_WINNT
#endif
#endif
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define __fsWindows
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#undef WINVER
#define WINVER _WIN32_WINNT
#else
#if 0x0601 > _WIN32_WINNT
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#undef WINVER
#define WINVER _WIN32_WINNT
#endif
#endif
#else
#define __fsLinux
#endif
//////
#include <iostream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <openssl/md5.h>
//
#include "fsUnifException.h"
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
