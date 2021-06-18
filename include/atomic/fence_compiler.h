#ifdef _MSC_VER

#define snidr_cfence() \
    _ReadWriteBarrier();

#elif defined(__GNUC__)

#define snidr_cfence() \
    __asm__ volatile("":::"memory");

#endif
