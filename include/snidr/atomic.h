/* When writing code that utilizes multiple CPU (Core)s,
 * you must take care to ensure that access to shared memory
 * happens in the correct order. Imagine you have a flag
 * representing the state of a mutex, one CPU tries to lock the mutex
 * and is free to do so without waiting because the flag is not set
 * but before being able the set the flag another CPU does the exact
 * same thing. This renders the mutex ineffective since there would
 * be 2 CPUs with access to the critical section at once. The atomic
 * module fixes this problem by providing a "front-end" to "atomic"
 * CPU instructions and compile time behavior.
 * 
 * This module defines 4 kinds of atomic operations: fencing, syncing,
 * locking, and excluding. These operations fall under 2 different
 * categories: memory ordering and atomic memory access. Fencing
 * and syncing are related to memory order while locking and excluding
 * are related to atomic memory access.
 */
#ifndef SNIDR_ATOMIC_H
#define SNIDR_ATOMIC_H

#include "snidr.h"

#ifdef _MSC_VER
#   include <intrin.h>
#endif

#ifdef _MSC_VER

#define snidr_compiler_rwfence() \
    _ReadWriteBarrier()

#define snidr_compiler_rfence() \
    _ReadBarrier()

#define snidr_compiler_wfence() \
    _WriteBarrier()

#define snidr_atomic_rwfence() \
    snidr_compiler_rwfence();  \
    __asm {                    \
        mfence;                \
    }                          

#define snidr_atomic_rfence() \
    snidr_compiler_rfence();  \
    __asm {                   \
        lfence;               \
    }

#define snidr_atomic_wfence() \
    snidr_compiler_wfence();  \
    __asm {                   \
        sfence;               \
    }

#else /* _MSC_VER */

#if defined(SNIDR_ARCH_i386) || defined(SNIDR_ARCH_AMD64)

#define snidr_compiler_rwfence() \
    __asm__ volatile("":::"memory")

#define snidr_compiler_rfence() \
    snidr_compiler_rwfence()

#define snidr_compiler_wfence() \
    snidr_compiler_rwfence()

#define snidr_atomic_rwfence() \
    __asm__ volatile("mfence":::"memory");

#define snidr_atomic_rfence() \
    __asm__ volatile("lfence":::"memory");

#define snidr_atomic_wfence() \
    __asm__ volatile("sfence":::"memory");

#endif /* defined(SNIDR_ARCH_i386) || defined(SNIDR_ARCH_AMD64) */

#endif

#endif /* SNIDR_ATOMIC_H */
