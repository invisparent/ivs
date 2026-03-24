/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_MEMORY_H
#define IVS_MEMORY_H


#include "./core.h"


typedef struct ivs_allocator_vtable ivs_allocator_vtable;


typedef struct ivs_allocator {
    const ivs_allocator_vtable *vp;
} ivs_allocator;


struct ivs_allocator_vtable {

    void *
    (*const malloc)(
        const ivs_allocator *,
        size_t
    );

    void *
    (*const calloc)(
        const ivs_allocator *,
        size_t,
        size_t
    );

    void *
    (*const realloc)(
        const ivs_allocator *,
        void *p,
        size_t
    );

    void
    (*const free)(
        const ivs_allocator *,
        void *
    );

};


void *
ivs_allocator_malloc(
    const ivs_allocator *self,
    size_t size
);

void *
ivs_allocator_calloc(
    const ivs_allocator *self,
    size_t num,
    size_t size
);

void *
ivs_allocator_realloc(
    const ivs_allocator *self,
    void *p,
    size_t size
);

void
ivs_allocator_free(
    const ivs_allocator *self,
    void *p
);


/**
 * "Trivial" allocator
 */


extern const ivs_allocator_vtable ivs_allocator_trivial_vtable;


typedef struct ivs_allocator_trivial {
    ivs_allocator base;
} ivs_allocator_trivial;


void *
ivs_allocator_trivial_malloc(
    const ivs_allocator_trivial *self,
    size_t size
);

void *
ivs_allocator_trivial_calloc(
    const ivs_allocator_trivial *self,
    size_t num,
    size_t size
);

void *
ivs_allocator_trivial_realloc(
    const ivs_allocator_trivial *self,
    void *p,
    size_t size
);

void
ivs_allocator_trivial_free(
    const ivs_allocator_trivial *self,
    void *p
);


extern ivs_allocator_trivial ivs_alloc;

extern const ivs_allocator *const ivs_palloc;


/**
 * memset, memmove and more.
 */


void
ivs_memset(
    void *dst,
    int ch,
    size_t count
);

void
ivs_memcpy(
    void *dst,
    const void *src,
    size_t count
);

void
ivs_memmove(
    void *dst,
    const void *src,
    size_t count
);

int
ivs_memcmp(
    const void *lhs,
    const void *rhs,
    size_t count
);


/**
 * fixed pool
 */


extern const ivs_allocator_vtable ivs_fixed_pool_vtable;


typedef struct ivs_fixed_pool {
    ivs_allocator base;
    void *beg;
    void *mid;
    void *end;
    size_t align;
} ivs_fixed_pool;


IVS_STATUS
ivs_fixed_pool_init(
    ivs_fixed_pool *self,
    const ivs_allocator *alloc,
    size_t size,
    size_t align
);

void *
ivs_fixed_pool_malloc(
    ivs_fixed_pool *self,
    size_t size
);

void *
ivs_fixed_pool_calloc(
    ivs_fixed_pool *self,
    size_t num,
    size_t size
);

void *
ivs_fixed_pool_realloc(
    const ivs_fixed_pool *self,
    void *p,
    size_t size
);

void
ivs_fixed_pool_free(
    const ivs_fixed_pool *self,
    void *p
);

void
ivs_fixed_pool_self_free(
    const ivs_fixed_pool *self,
    const ivs_allocator *alloc
);


#endif
