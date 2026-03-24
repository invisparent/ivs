/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_UTF_H
#define IVS_UTF_H


#include "./array_list.h"
#include "./core.h"
#include "./iterator.h"
#include "./memory.h"


char
ivs_ascii_from_digit(
    int val,
    _Bool is_upper
);


typedef struct ivs_ascii_string {
    ivs_array_list dat;
} ivs_ascii_string;


IVS_STATUS
ivs_ascii_string_init(
    ivs_ascii_string *self,
    const ivs_allocator *alloc
);

void
ivs_ascii_string_free(
    const ivs_ascii_string *self,
    const ivs_allocator *alloc
);

void
ivs_ascii_string_clear(
    ivs_ascii_string *self
);

IVS_STATUS
ivs_ascii_string_copy(
    ivs_ascii_string *dst,
    const ivs_allocator *alloc,
    const ivs_ascii_string *src
);

void
ivs_ascii_string_move(
    ivs_ascii_string *dst,
    ivs_ascii_string *src
);

char *
ivs_ascii_string_data(
    const ivs_ascii_string *self
);

const char *
ivs_ascii_string_cstr(
    const ivs_ascii_string *self
);

IVS_STATUS
ivs_ascii_string_from_literal(
    ivs_ascii_string *self,
    const ivs_allocator *alloc,
    const char *str
);

_Bool
ivs_ascii_string_empty(
    const ivs_ascii_string *self
);

size_t
ivs_ascii_string_size(
    const ivs_ascii_string *self
);

size_t
ivs_ascii_string_length(
    const ivs_ascii_string *self
);

size_t
ivs_ascii_string_memused(
    const ivs_ascii_string *self
);

ivs_iterator
ivs_ascii_string_begin(
    const ivs_ascii_string *self
);

ivs_iterator
ivs_ascii_string_before_end(
    const ivs_ascii_string *self
);

char
ivs_ascii_string_front(
    const ivs_ascii_string *self
);

void
ivs_ascii_string_set_front(
    const ivs_ascii_string *self,
    char ch
);

char
ivs_ascii_string_back(
    const ivs_ascii_string *self
);

void
ivs_ascii_string_set_back(
    const ivs_ascii_string *self,
    char ch
);

ivs_iterator
ivs_ascii_string_advance(
    const ivs_ascii_string *self,
    ivs_iterator iter,
    ptrdiff_t step
);

char
ivs_ascii_string_deref(
    const ivs_ascii_string *self,
    ivs_iterator iter
);

const char *
ivs_ascii_string_deref_as_literal(
    const ivs_ascii_string *self,
    ivs_iterator iter
);

char
ivs_ascii_string_at(
    const ivs_ascii_string *self,
    size_t index
);

void
ivs_ascii_string_at_set(
    const ivs_ascii_string *self,
    size_t index,
    char ch
);

IVS_STATUS
ivs_ascii_string_push_back(
    ivs_ascii_string *self,
    const ivs_allocator *alloc,
    char ch
);

void
ivs_ascii_string_pop_back(
    ivs_ascii_string *self
);

int
ivs_ascii_string_cmp(
    const ivs_ascii_string *a,
    const ivs_ascii_string *b
);

int
ivs_ascii_string_cmp_from_literal(
    const ivs_ascii_string *self,
    const char *str
);

int
ivs_functional_ascii_string_cmp(
    const void *a,
    const void *b
);

_Bool
ivs_ascii_string_equal(
    const ivs_ascii_string *a,
    const ivs_ascii_string *b
);

IVS_STATUS
ivs_ascii_string_to_printable(
    ivs_ascii_string *self,
    const ivs_allocator *alloc
);


#endif
