/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_AVL_H
#define IVS_AVL_H


#include "./core.h"
#include "./iterator.h"
#include "./memory.h"


typedef struct ivs_static_avl_node ivs_static_avl_node;


typedef struct ivs_avl {
    ivs_static_avl_node *root;
} ivs_avl;


void
ivs_avl_init(
    ivs_avl *self
);

void
ivs_avl_free(
    const ivs_avl *self,
    const ivs_allocator *alloc
);

void
ivs_avl_clear(
    ivs_avl *self,
    const ivs_allocator *alloc
);

IVS_STATUS
ivs_avl_copy(
    ivs_avl *dst,
    size_t bpk,
    size_t bpv,
    const ivs_allocator *alloc,
    const ivs_avl *src
);

void
ivs_avl_move(
    ivs_avl *dst,
    ivs_avl *src
);

_Bool
ivs_avl_empty(
    const ivs_avl *self
);

size_t
ivs_avl_length(
    const ivs_avl *self
);

ivs_iterator
ivs_avl_begin(
    const ivs_avl *self
);

ivs_iterator
ivs_avl_before_end(
    const ivs_avl *self
);

ivs_iterator
ivs_avl_advance(
    const ivs_avl *self,
    ivs_iterator iter,
    ptrdiff_t step
);

const void *
ivs_avl_deref_key(
    const ivs_avl *self,
    ivs_iterator iter
);

void *
ivs_avl_deref_value(
    const ivs_avl *self,
    size_t bpk,
    ivs_iterator iter
);

ivs_iterator
ivs_avl_iter(
    const ivs_avl *self,
    int (*cmp)(const void *, const void *),
    const void *key
);

_Bool
ivs_avl_replace(
    const ivs_avl *self,
    size_t bpk,
    size_t bpv,
    int (*cmp)(const void *, const void *),
    const void *key,
    const void *value
);

ivs_iterator
ivs_avl_insert(
    ivs_avl *self,
    _Bool *opt_inserted,
    size_t bpk,
    size_t bpv,
    int (*cmp)(const void *, const void *),
    const ivs_allocator *alloc,
    const void *key,
    const void *opt_value
);

void *
ivs_avl_at(
    const ivs_avl *self,
    size_t bpk,
    int (*cmp)(const void *, const void *),
    const void *key
);

ivs_iterator
ivs_avl_erase_iter(
    ivs_avl *self,
    int (*cmp)(const void *, const void *),
    const ivs_allocator *alloc,
    ivs_iterator iter
);

ivs_iterator
ivs_avl_erase(
    ivs_avl *self,
    _Bool* opt_erased,
    int (*cmp)(const void *, const void *),
    const ivs_allocator *alloc,
    const void *key
);


#endif
