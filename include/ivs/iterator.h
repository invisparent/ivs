/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_ITERATOR_H
#define IVS_ITERATOR_H


#include "./core.h"


typedef struct ivs_iterator {
    void* dat;
}ivs_iterator;


ivs_iterator
ivs_iterator_make(
    void *p
);

void
ivs_iterator_set(
    ivs_iterator *self,
    void *p
);

void
ivs_iterator_set_jne(
    ivs_iterator *self
);

void *
ivs_iterator_raw(
    const ivs_iterator *self
);

void *
ivs_iterator_deref(
    const ivs_iterator *self,
    size_t offset
);

const void *
ivs_iterator_deref_const(
    const ivs_iterator *self,
    size_t offset
);

_Bool
ivs_iterator_equal(
    const ivs_iterator *self,
    ivs_iterator iter
);

_Bool
ivs_iterator_not_equal(
    const ivs_iterator *self,
    ivs_iterator iter
);

_Bool
ivs_iterator_empty(
    const ivs_iterator *self
);


#endif
