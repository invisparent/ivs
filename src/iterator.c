/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include <stdint.h>

#include "ivs/iterator.h"


ivs_iterator
ivs_iterator_make(
    void *const p
) {
    const ivs_iterator ret = {p};
    return ret;
}

void
ivs_iterator_set(
    ivs_iterator *const self,
    void *const p
) {
    self->dat = p;
}

/**
 * Just not empty, but does not point to anything...
 */
void
ivs_iterator_set_jne(
    ivs_iterator *const self
) {
    self->dat = ivs_pv_add(NULL, UINTPTR_MAX);
}

void *
ivs_iterator_raw(
    const ivs_iterator *const self
) {
    return self->dat;
}

void *
ivs_iterator_deref(
    const ivs_iterator *const self,
    const size_t offset
) {
    return ivs_pv_add(self->dat, offset);
}

const void *
ivs_iterator_deref_const(
    const ivs_iterator *const self,
    const size_t offset
) {
    return ivs_pv_add_c(self->dat, offset);
}

_Bool
ivs_iterator_equal(
    const ivs_iterator *const self,
    const ivs_iterator iter
) {
    ivs_assert(self);
    return self->dat == iter.dat;
}

_Bool
ivs_iterator_not_equal(
    const ivs_iterator *const self,
    const ivs_iterator iter
) {
    ivs_assert(self);
    return self->dat != iter.dat;
}

_Bool
ivs_iterator_empty(
    const ivs_iterator *const self
) {
    return !ivs_iterator_raw(self);
}
