/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include <stdlib.h>

#include "ivs/memory.h"

#include <string.h>


/**
 * Error handling:
 *   All xallocs returns NULL if allocation failed.
 */

void *
ivs_allocator_malloc(
    const ivs_allocator *const self,
    const size_t size
) {
    ivs_assert(self);
    ivs_assert(self->vp->malloc);
    return self->vp->malloc(self, size);
}

void *
ivs_allocator_calloc(
    const ivs_allocator *const self,
    const size_t num,
    const size_t size
) {
    ivs_assert(self);
    ivs_assert(self->vp->calloc);
    return self->vp->calloc(self, num, size);
}

void *
ivs_allocator_realloc(
    const ivs_allocator *const self,
    void *const p,
    const size_t size
) {
    ivs_assert(self);
    ivs_assert(self->vp->realloc);
    return self->vp->realloc(self, p, size);
}

void
ivs_allocator_free(
    const ivs_allocator *const self,
    void *const p
) {
    ivs_assert(self);
    ivs_assert(self->vp->free);
    self->vp->free(self, p);
}


const ivs_allocator_vtable ivs_allocator_trivial_vtable = {

    .malloc =
    (void *(*const)(
        const ivs_allocator *,
        size_t
    )) ivs_allocator_trivial_malloc,

    .calloc =
    (void *(*const)(
        const ivs_allocator *,
        size_t,
        size_t
    )) ivs_allocator_trivial_calloc,

    .realloc =
    (void *(*const)(
        const ivs_allocator *,
        void *,
        size_t
    )) ivs_allocator_trivial_realloc,

    .free =
    (void(*const)(
        const ivs_allocator *,
        void *
    )) ivs_allocator_trivial_free

};


void *
ivs_allocator_trivial_malloc(
    const ivs_allocator_trivial *const self,
    const size_t size
) {
    (void) self;
    return malloc(size);
}

void *
ivs_allocator_trivial_calloc(
    const ivs_allocator_trivial *const self,
    const size_t num,
    const size_t size
) {
    (void) self;
    return calloc(num, size);
}

void *
ivs_allocator_trivial_realloc(
    const ivs_allocator_trivial *const self,
    void *const p,
    const size_t size
) {
    (void) self;
    return realloc(p, size);
}

void
ivs_allocator_trivial_free(
    const ivs_allocator_trivial *const self,
    void *const p
) {
    (void) self;
    free(p);
}


ivs_allocator_trivial ivs_alloc = {
    .base = {&ivs_allocator_trivial_vtable}
};

const ivs_allocator *const ivs_palloc = (ivs_allocator *) &ivs_alloc;


void
ivs_memset(
    void *const dst,
    const int ch,
    const size_t count
) {
    ivs_assert(dst);
    memset(dst, ch, count);
}

void
ivs_memcpy(
    void *const dst,
    const void *const src,
    const size_t count
) {
    ivs_assert(dst && src);
    memcpy(dst, src, count);
}

void
ivs_memmove(
    void *const dst,
    const void *const src,
    const size_t count
) {
    ivs_assert(dst && src);
    memmove(dst, src, count);
}

int
ivs_memcmp(
    const void *const lhs,
    const void *const rhs,
    const size_t count
) {
    ivs_assert(lhs && rhs);
    return memcmp(lhs, rhs, count);
}


const ivs_allocator_vtable ivs_fixed_pool_vtable = {

    .malloc =
    (void *(*const)(
        const ivs_allocator *,
        size_t
    )) ivs_fixed_pool_malloc,

    .calloc =
    (void *(*const)(
        const ivs_allocator *,
        size_t,
        size_t
    )) ivs_fixed_pool_calloc,

    .realloc =
    (void *(*const)(
        const ivs_allocator *,
        void *,
        size_t
    )) ivs_fixed_pool_realloc,

    .free =
    (void(*const)(
        const ivs_allocator *,
        void *
    )) ivs_fixed_pool_free

};


/**
 * @return whether the operation failed.
 */
IVS_STATUS
ivs_fixed_pool_init(
    ivs_fixed_pool *const self,
    const ivs_allocator *const alloc,
    const size_t size,
    const size_t align
) {
    ivs_assert(self && alloc);
    ivs_assert(align);
    self->base.vp = &ivs_fixed_pool_vtable;
    void *const beg = ivs_allocator_malloc(alloc, size);
    if (!beg)
        IVS_LOG_FAILED();
    self->beg = beg;
    self->mid = self->beg;
    self->end = ivs_pv_add(self->beg, size);
    self->align = align;
    return IVS_SUCCESS;
}

void *
ivs_fixed_pool_malloc(
    ivs_fixed_pool *const self,
    const size_t size
) {
    ivs_assert(self);
    void *const mid = ivs_pv_add(self->mid, self->align - ivs_pv_mod(self->mid, self->align));
    void *const end = ivs_pv_add(mid, size);
    if (end > self->end)
        return NULL;
    self->mid = end;
    return mid;
}

void *
ivs_fixed_pool_calloc(
    ivs_fixed_pool *const self,
    const size_t num,
    const size_t size
) {
    ivs_assert(self);
    return ivs_fixed_pool_malloc(self, num * size);
}

/**
 * Fixed pool currently not support realloc.
 */
void *
ivs_fixed_pool_realloc(
    const ivs_fixed_pool *const self,
    void *const p,
    const size_t size
) {
    (void)self;
    (void)p;
    (void)size;
    ivs_log();
    return NULL;
}

void
ivs_fixed_pool_free(
    const ivs_fixed_pool *const self,
    void *const p
) {
    (void) self;
    (void) p;
}

void
ivs_fixed_pool_self_free(
    const ivs_fixed_pool *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self && alloc);
    ivs_allocator_free(alloc, self->beg);
}
