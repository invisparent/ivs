/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include <stdarg.h>
#include <stdatomic.h>
#include <stdio.h>

#include "ivs/core.h"


void
ivs_assert_default_handler(
    const char *const expr,
    const char *const file,
    const unsigned line,
    const char *const func,
    const char *const extra,
    ...
) {
    fprintf(stderr, "ivs::assert_default_handler: expr: %s, file: %s:%u in %s\n", expr, file, line, func);
    if (extra) {
        va_list args;
        va_start(args, extra);
        fputs("extra info:\n", stderr);
        vfprintf(stderr, extra, args);
        va_end(args);
        fputc('\n', stderr);
    }
}

void
ivs_log_default_handler(
    const char *const file,
    const unsigned line,
    const char *const func,
    const char *const extra,
    ...
) {
    fprintf(stderr, "ivs::log_default_handler: file: %s:%u in %s\n", file, line, func);
    if (extra) {
        va_list args;
        va_start(args, extra);
        fputs("extra info:\n", stderr);
        vfprintf(stderr, extra, args);
        va_end(args);
        fputc('\n', stderr);
    }
}

void
ivs_hint_default_handler(
    const char *const expr,
    const char *const file,
    const unsigned line,
    const char *const func,
    const char *const extra,
    ...
) {
    fprintf(stderr, "ivs::hint_default_handler: expr: %s, file: %s:%u in %s\n", expr, file, line, func);
    if (extra) {
        va_list args;
        va_start(args, extra);
        fputs("extra info:\n", stderr);
        vfprintf(stderr, extra, args);
        va_end(args);
        fputc('\n', stderr);
    }
}

void (*ivs_assert_handler)(const char *, const char *, unsigned, const char *, const char *, ...) = ivs_assert_default_handler;

void (*ivs_log_handler)(const char *, unsigned, const char *, const char *, ...) = ivs_log_default_handler;

void (*ivs_hint_handler)(const char *, const char *, unsigned, const char *, const char *, ...) = ivs_hint_default_handler;

static _Atomic int ivs_static_errno = 0;

static _Thread_local int ivs_static_thread_errno = 0;

int
ivs_errno(
    const int err
) {
    const int a = ivs_static_thread_errno;
    ivs_static_thread_errno = err;
    const int b = atomic_exchange_explicit(&ivs_static_errno, err, memory_order_relaxed);
    return a ? a : b;
}

int
ivs_errno_thread_local(
    int err
) {
    ivs_inline_swap(int, err, ivs_static_thread_errno);
    return err;
}
