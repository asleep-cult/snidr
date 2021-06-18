#include "snidr.h"
#include "atomic/fence_compiler.h"
#if defined(SNIDR_ARCH_i386) || defined(SNIDR_ARCH_AMD64)
#   include "atomic/atomic_x86.h"
#   include "atomic/fence_x86.h"
#endif
