/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_CORE_H
#define IVS_CORE_H


#define IVS_LIBC_MAJOR 3
#define IVS_LIBC_UPDATE 0
#define IVS_LIBC_PATCH 0

#define IVS_LIBC_MAJOR_ESSENTIAL "Cauchy"
#define IVS_LIBC_MAJOR_FULL "Augustin-Louis \"Cauchy\""


#include <stddef.h>


/**
 * Cpp compatibility
 */

#ifdef __cplusplus
#define _Bool bool
#endif


/**
 * Error handling
 */


#ifndef NULL
#define NULL ((void *) 0)
#endif


#define IVS_STATUS _Bool

#define IVS_SUCCESS ((_Bool) 0)
#define IVS_FAILED ((_Bool) 1)


void
ivs_assert_default_handler(
    const char* expr,
    const char *file,
    unsigned line,
    const char *func,
    const char *extra,
    ...
);

void
ivs_log_default_handler(
    const char *file,
    unsigned line,
    const char *func,
    const char *extra,
    ...
);

void
ivs_hint_default_handler(
    const char* expr,
    const char *file,
    unsigned line,
    const char *func,
    const char *extra,
    ...
);


extern void (*ivs_assert_handler)(const char *, const char *, unsigned, const char *, const char *, ...);

extern void (*ivs_log_handler)(const char *, unsigned, const char *, const char *, ...);

extern void (*ivs_hint_handler)(const char *, const char *, unsigned, const char *, const char *, ...);


#ifdef __RESHARPER__


/**
 * We're cheating CLion here.
 * The fucking stupid CLion doesn't allow OOP-style code completion in a function-like macro.
 */

void ivs_assert(_Bool expr);

void ivs_assert_fmt(_Bool expr, const char *str, ...);

void ivs_log(void);

void ivs_log_fmt(const char *str, ...);

void ivs_hint(_Bool expr);

void ivs_hint_fmt(_Bool expr, const char *str, ...);


#else


#ifndef IVS_NDEBUG

#define ivs_assert(expr) do { if (!(expr)) ivs_assert_handler(#expr, __FILE__, ((unsigned) __LINE__), __func__, NULL); } while(0)
#define ivs_assert_fmt(expr, ...) do { if (!(expr)) ivs_assert_handler(#expr, __FILE__, ((unsigned) __LINE__), __func__, __VA_ARGS__); } while(0)

#define ivs_log() ivs_log_handler(__FILE__, ((unsigned) __LINE__), __func__, NULL)
#define ivs_log_fmt(...) ivs_log_handler(__FILE__, ((unsigned) __LINE__), __func__, __VA_ARGS__)

#define ivs_hint(expr) do { if (!(expr)) ivs_hint_handler(#expr, __FILE__, ((unsigned) __LINE__), __func__, NULL); } while(0)
#define ivs_hint_fmt(expr, ...) do { if (!(expr)) ivs_hint_handler(#expr, __FILE__, ((unsigned) __LINE__), __func__, __VA_ARGS__); } while(0)

#else

#define ivs_assert(expr) ((void) 0)
#define ivs_assert_fmt(expr, ...) ((void) 0)

#define ivs_log() ((void) 0)
#define ivs_log_fmt(...) ((void) 0)

#define ivs_hint(expr) ((void) 0)
#define ivs_hint_fmt(expr, ...) ((void) 0)

#endif

#endif


#define IVS_LOG_FAILED() do { ivs_log(); return IVS_FAILED; } while(0)
#define IVS_LOG_FAILED_FMT(...) do { ivs_log_fmt(__VA_ARGS__); return IVS_FAILED; } while(0)


#define ivs_unreachable() ivs_assert_fmt(0, "ivs::unreachable: unreachable code executed")


int
ivs_errno(
    int err
);

int
ivs_errno_thread_local(
    int err
);


/**
 * Endian
 */

#define ivs_is_little_endian(boolean) \
    \
    do { \
        const unsigned ivs_local = 1; \
        boolean = ((_Bool) *(const char *) &ivs_local); \
    } while(0)


/**
 * Stream
 */

#define IVS_EOF (-1)
#define IVS_ERRSTREAM (256)


/**
 * inline assemblies
 */

#define ivs_asm asm

#define ivs_asm_volatile __asm__ volatile


/**
 * Utilities
 * Also, remember to cheat the fucking stupid CLion.
 */

#define ivs_inline_swap(type, a, b) \
    \
    do { \
        type const ivs_local_tmp = a; \
        a = b; \
        b = ivs_local_tmp; \
    } while(0)


#define ivs_inline_pad(size) (((size) % sizeof(void *)) ? (((size) / sizeof(void*)) + 1) * sizeof(void *) : (size) )


#ifndef __RESHARPER__


#define ivs_inline_min(a, b) ((a) <= (b) ? (a) : (b))

#define ivs_inline_min_3(a, b, c) ((a) <= (b) ? (a) <= (c) ? (a) : (c) : (b) <= (c) ? (b) : (c))

#define ivs_inline_max(a, b) ((a) >= (b) ? (a) : (b))

#define ivs_inline_max_3(a, b, c) ((a) >= (b) ? (a) >= (c) ? (a) : (c) : (b) >= (c) ? (b) : (c))


#define ivs_inline_between_oo(lb, rb, x) ((lb) < (x) && (x) < (rb))

#define ivs_inline_between_oc(lb, rb, x) ((lb) < (x) && (x) <= (rb))

#define ivs_inline_between_co(lb, rb, x) ((lb) <= (x) && (x) < (rb))

#define ivs_inline_between_cc(lb, rb, x) ((lb) <= (x) && (x) <= (rb))


#define ivs_inline_approx(target, tolerance, x) ((x) >= (target) - (tolerance) && (x) <= (target) - (tolerance))

#define ivs_inline_approx_less(target, tolerance, x) ((x) <= (target) + (tolerance))

#define ivs_inline_approx_greater(target, tolerance, x) ((x) >= (target) - (tolerance))

#define ivs_inline_strict_less(target, tolerance, x) ((x) <= (target) - (tolerance))

#define ivs_inline_strict_greater(target, tolerance, x) ((x) >= (target) + (tolerance))


#else


_Bool ivs_inline_min(_Bool a, _Bool b);

_Bool ivs_inline_min_3(_Bool a, _Bool b, _Bool c);

_Bool ivs_inline_max(_Bool a, _Bool b);

_Bool ivs_inline_max_3(_Bool a, _Bool b, _Bool c);


_Bool ivs_inline_between_oo(_Bool lb, _Bool rb, _Bool x);

_Bool ivs_inline_between_oc(_Bool lb, _Bool rb, _Bool x);

_Bool ivs_inline_between_co(_Bool lb, _Bool rb, _Bool x);

_Bool ivs_inline_between_cc(_Bool lb, _Bool rb, _Bool x);


_Bool ivs_inline_approx(_Bool target, _Bool tolerance, _Bool x);

_Bool ivs_inline_approx_less(_Bool target, _Bool tolerance, _Bool x);

_Bool ivs_inline_approx_greater(_Bool target, _Bool tolerance, _Bool x);

_Bool ivs_inline_strict_less(_Bool target, _Bool tolerance, _Bool x);

_Bool ivs_inline_strict_greater(_Bool target, _Bool tolerance, _Bool x);


#endif


#define ivs_opt_arg_set(p, expr) \
    \
    do { \
        if (p) \
        *p = (expr); \
    } while(0)


/**
 * likely and unlikely, reserved for future use.
 */


#ifndef __RESHARPER__

#define ivs_likely(expr)   expr
#define ivs_unlikely(expr) expr

#else

_Bool ivs_likely(_Bool expr);
_Bool ivs_unlikely(_Bool expr);

#endif


/**
 * Mathematics
 * Also have to deal with the fucking stupid CLion...
 */

#ifndef __RESHARPER__

#define ivs_inline_lerp(lb, ub, ratio) ((lb) + ((ub) - (lb)) * (ratio))

#define ivs_inline_restrict(lb, ub, x) ((x) < (lb) ? (lb) : (x) > (ub) ? (ub) : x)

#else

_Bool ivs_inline_lerp(_Bool lb, _Bool ub, _Bool ratio);

_Bool ivs_inline_restrict(_Bool lb, _Bool ub, _Bool x);

#endif


/**
 * Pointer-to-void arithmetic extension
 *
 * Note arithmetic on a pointer to void is a GNU extension [-Werror, -Wgnu-pointer-arith],
 *   but many times it's necessary.
 */

#define ivs_pv_add(p, diff) ((void *) (((char *) (p)) + (diff)))

#define ivs_pv_add_c(p, diff) ((const void *) (((const char *) (p)) + (diff)))

#define ivs_pv_sub(p, diff) ((void *) (((char *) (p)) - (diff)))

#define ivs_pv_sub_c(p, diff) ((const void *) (((const char *) (p)) - (diff)))

#define ivs_pv_diff(pa, pb) (((const char *) (pa)) - ((const char *) (pb)))

#define ivs_pv_mod(p, mod) (((size_t) (p)) % (mod))


/**
 * _Static_assert extension
 *
 * Before C23, _Static_assert must contain info, so...
 */

#define ivs_static_assert(expr) _Static_assert((expr), "<no info>")


#endif
