#ifndef SNIDR_ATOMIC
#define SNIDR_ATOMIC

#include "snidr.h"

#ifdef _MSC_VER

#define snidr_cfence() \
    _ReadWriteBarrier();

#elif defined(__GNUC__)

#define snidr_cfence() \
    __asm__ volatile("":::"memory");

#endif

#if defined(SNIDR_ARCH_i386) || defined(SNIDR_ARCH_AMD64)
#   include "atomic/atomic_x86.h"
#endif

#endif
