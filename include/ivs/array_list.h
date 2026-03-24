/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_ARRAY_LIST_H
#define IVS_ARRAY_LIST_H


#include "./core.h"
#include "./iterator.h"
#include "./memory.h"


typedef struct ivs_array_list {
    void *beg;
    void *mid;
    void *end;
} ivs_array_list;


void
ivs_array_list_init(
    ivs_array_list *self
);

void
ivs_array_list_free(
    const ivs_array_list *self,
    const ivs_allocator *alloc
);

void
ivs_array_list_clear(
    ivs_array_list *self
);

IVS_STATUS
ivs_array_list_copy(
    ivs_array_list *dst,
    const ivs_allocator *alloc,
    const ivs_array_list *src
);

void
ivs_array_list_move(
    ivs_array_list *dst,
    ivs_array_list *src
);

void *
ivs_array_list_data(
    const ivs_array_list *self
);

_Bool
ivs_array_list_empty(
    const ivs_array_list *self
);

size_t
ivs_array_list_size(
    const ivs_array_list *self
);

size_t
ivs_array_list_length(
    const ivs_array_list *self,
    size_t bpe
);

size_t
ivs_array_list_memused(
    const ivs_array_list *self
);

size_t
ivs_array_list_capacity(
    const ivs_array_list *self,
    size_t bpe
);

ivs_iterator
ivs_array_list_begin(
    const ivs_array_list *self
);

ivs_iterator
ivs_array_list_before_end(
    const ivs_array_list *self,
    size_t bpe
);

void *
ivs_array_list_front(
    const ivs_array_list *self
);

void *
ivs_array_list_back(
    const ivs_array_list *self,
    size_t bpe
);

ivs_iterator
ivs_array_list_advance(
    const ivs_array_list *self,
    size_t bpe,
    ivs_iterator iter,
    ptrdiff_t step
);

void *
ivs_array_list_deref(
    const ivs_array_list *self,
    ivs_iterator iter
);

void *
ivs_array_list_at(
    const ivs_array_list *self,
    size_t bpe,
    size_t index
);

IVS_STATUS
ivs_array_list_push_back(
    ivs_array_list *self,
    size_t bpe,
    const ivs_allocator *alloc,
    const void *val
);

void
ivs_array_list_pop_back(
    ivs_array_list *self,
    size_t bpe
);


#endif
