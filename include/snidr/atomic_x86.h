#ifndef SNIDR_ATOMIC_x86_H
#define SNIDR_ATOMIC_x86_H

#include "snidr.h"
#include "atomic.h"

#ifdef _MSC_VER

#define snidr_rfence() \
    snidr_cfence();    \
    _mm_lfence();

#define snidr_wfence() \
    snidr_cfence();    \
    _mm_sfence();

#define snidr_rwfence() \
    snidr_cfence();     \
    _mm_mfence();

#elif defined(__GNUC__)

#define snidr_rfence() \
    __asm__ volatile("lfence":::"memory");

#define snidr_wfence() \
    __asm__ volatile("sfence":::"memory");

#define snidr_rwfence() \
    __asm__ volatile("mfence":::"memory");

#endif

#endif
