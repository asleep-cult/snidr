#ifndef SNIDR_H
#define SNIDR_H

#ifdef __i386__
#   define SNIDR_ARCH_i386
#   define SNIDR_BYTE_ORDER 0
#elif defined(_M_X64) || defined(__x86_64__)
#   define SNIDR_ARCH_AMD64
#   define SNIDR_BYTE_ORDER 0
#elif defined(__arm__)
#   define SNIDR_ARCH_ARM
#elif defined(__aarch64__)
#   define SNIDR_ARCH_ARM64
#else
#   error "snidr failed to find the architecture"
#endif

#ifdef _WIN32
#   define SNIDR_OS_WIN
#else
#   error "snidr failed to find the operating system"
#endif

#ifdef _MSC_VER
#   define SNIDR_IMPORT __declspec(dllimport)
#   define SNIDR_EXPORT __declspec(dllexport)
#   define SNIDR_INLINE __forceinline
#else
#   define SNIDR_IMPORT __attribute__((visibility ("default")))
#   define SNIDR_EXPORT __attribute__((visibility ("default")))
#   define SNIDR_INLINE __attribute__((always_inline))
#endif


#define SNIDR_EXPORT_FUNC SNIDR_EXPORT
#define SNIDR_EXPORT_DATA extern SNIDR_EXPORT

#include <stdbool.h>
#include <stdint.h>

#ifdef SNIDR_OS_WIN
#   include <windows.h>
#endif

#endif
