/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include "ivs/array_list.h"


void
ivs_array_list_init(
    ivs_array_list *const self
) {
    ivs_assert(self);
    self->beg = NULL;
    self->mid = NULL;
    self->end = NULL;
}

void
ivs_array_list_free(
    const ivs_array_list *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self && alloc);
    ivs_allocator_free(alloc, self->beg);
}

void
ivs_array_list_clear(
    ivs_array_list *const self
) {
    ivs_assert(self);
    self->mid = self->beg;
}

IVS_STATUS
ivs_array_list_copy(
    ivs_array_list *const dst,
    const ivs_allocator *const alloc,
    const ivs_array_list *const src
) {
    ivs_assert(dst && alloc && src);
    ivs_array_list_clear(dst);
    ivs_iterator iter = ivs_array_list_begin(src);
    while (!ivs_iterator_empty(&iter)) {
        if (ivs_array_list_push_back(dst, 1, alloc, ivs_array_list_deref(src, iter)))
            IVS_LOG_FAILED();
        else
            iter = ivs_array_list_advance(src, 1, iter, 1);
    }
    return IVS_SUCCESS;
}

void
ivs_array_list_move(
    ivs_array_list *const dst,
    ivs_array_list *const src
) {
    ivs_assert(dst && src);
    ivs_inline_swap(void *, dst->beg, src->beg);
    ivs_inline_swap(void *, dst->mid, src->mid);
    ivs_inline_swap(void *, dst->end, src->end);
}

void *
ivs_array_list_data(
    const ivs_array_list *const self
) {
    ivs_assert(self);
    if (ivs_array_list_empty(self))
        return NULL;
    else
        return self->beg;
}

_Bool
ivs_array_list_empty(
    const ivs_array_list *const self
) {
    ivs_assert(self);
    return self->beg == self->mid;
}

size_t
ivs_array_list_size(
    const ivs_array_list *const self
) {
    ivs_assert(self);
    return ivs_pv_diff(self->mid, self->beg);
}

static
_Bool
ivs_static_array_list_is_legal_bpe(
    const ivs_array_list *const self,
    const size_t bpe
) {
    if (!bpe)
        return 0;
    else if (ivs_array_list_empty(self))
        return 1;
    else
        return !(ivs_array_list_size(self) % bpe);
}

size_t
ivs_array_list_length(
    const ivs_array_list *const self,
    const size_t bpe
) {
    ivs_assert(self);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    return ivs_array_list_size(self) / bpe;
}

size_t
ivs_array_list_memused(
    const ivs_array_list *const self
) {
    ivs_assert(self);
    return ivs_pv_diff(self->end, self->beg);
}

size_t
ivs_array_list_capacity(
    const ivs_array_list *const self,
    const size_t bpe
) {
    ivs_assert(self);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    return ivs_array_list_memused(self) / bpe;
}

ivs_iterator
ivs_array_list_begin(
    const ivs_array_list *const self
) {
    ivs_assert(self);
    if (ivs_array_list_empty(self))
        return ivs_iterator_make(NULL);
    else
        return ivs_iterator_make(self->beg);
}

ivs_iterator
ivs_array_list_before_end(
    const ivs_array_list *const self,
    const size_t bpe
) {
    ivs_assert(self);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    if (ivs_array_list_empty(self))
        return ivs_iterator_make(NULL);
    else
        return ivs_iterator_make(ivs_pv_sub(self->mid, bpe));
}

void *
ivs_array_list_front(
    const ivs_array_list *const self
) {
    ivs_assert(self);
    ivs_assert(!ivs_array_list_empty(self));
    return self->beg;
}

void *
ivs_array_list_back(
    const ivs_array_list *const self,
    const size_t bpe
) {
    ivs_assert(self);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    ivs_assert(!ivs_array_list_empty(self));
    return ivs_pv_sub(self->mid, bpe);
}

ivs_iterator
ivs_array_list_advance(
    const ivs_array_list *const self,
    const size_t bpe,
    const ivs_iterator iter,
    const ptrdiff_t step
) {
    ivs_assert(self);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    if (ivs_array_list_empty(self))
        return ivs_iterator_make(NULL);
    void *const p = ivs_pv_add(ivs_iterator_raw(&iter), bpe * step);
    if (p < self->beg || p >= self->mid)
        return ivs_iterator_make(NULL);
    else
        return ivs_iterator_make(p);
}

void *
ivs_array_list_deref(
    const ivs_array_list *const self,
    const ivs_iterator iter
) {
    ivs_assert(self);
    ivs_assert(ivs_iterator_raw(&iter));
    return ivs_iterator_raw(&iter);
}

void *
ivs_array_list_at(
    const ivs_array_list *const self,
    const size_t bpe,
    const size_t index
) {
    ivs_assert(self);
    ivs_assert(!ivs_array_list_empty(self));
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    void *const ret = ivs_pv_add(self->beg, bpe * index);
    ivs_assert(ivs_pv_add(ret, bpe) <= self->mid);
    return ret;
}

static
IVS_STATUS
ivs_static_array_list_try_expand(
    ivs_array_list *const self,
    const ivs_allocator *const alloc,
    const size_t req
) {
    ivs_assert(self && alloc);
    if (req <= (size_t) ivs_pv_diff(self->end, self->mid))
        return IVS_SUCCESS;
    const size_t bm = ivs_array_list_size(self);
    const size_t be = ivs_array_list_memused(self);
    const size_t ns = ivs_inline_max_3(be * 2, req, 16);
    void *const p = ivs_allocator_realloc(alloc, self->beg, ns);
    if (!p)
        IVS_LOG_FAILED();
    self->beg = p;
    self->mid = ivs_pv_add(self->beg, bm);
    self->end = ivs_pv_add(self->beg, ns);
    return IVS_SUCCESS;
}

IVS_STATUS
ivs_array_list_push_back(
    ivs_array_list *const self,
    const size_t bpe,
    const ivs_allocator *const alloc,
    const void *const val
) {
    ivs_assert(self && alloc && val);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    if (ivs_static_array_list_try_expand(self, alloc, bpe))
        IVS_LOG_FAILED();
    ivs_memcpy(self->mid, val, bpe);
    self->mid = ivs_pv_add(self->mid, bpe);
    return IVS_SUCCESS;
}

void
ivs_array_list_pop_back(
    ivs_array_list *const self,
    const size_t bpe
) {
    ivs_assert(self);
    ivs_assert(ivs_static_array_list_is_legal_bpe(self, bpe));
    ivs_assert(!ivs_array_list_empty(self));
    self->mid = ivs_pv_sub(self->mid, bpe);
}
