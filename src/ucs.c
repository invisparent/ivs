/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include <ctype.h>
#include <string.h>

#include "ivs/ucs.h"


static const char ivs_static_ascii_from_digit_literal_lower[] = "0123456789abcdefghijklmnopqrstuvwxyz";
static const char ivs_static_ascii_from_digit_literal_upper[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char
ivs_ascii_from_digit(
    const int val,
    const _Bool is_upper
) {
    if (!is_upper) {
        ivs_assert(val >= 0 && val < sizeof(ivs_static_ascii_from_digit_literal_lower) / sizeof(ivs_static_ascii_from_digit_literal_lower[0]));
        return ivs_static_ascii_from_digit_literal_lower[val];
    } else {
        ivs_assert(val >= 0 && val < sizeof(ivs_static_ascii_from_digit_literal_upper) / sizeof(ivs_static_ascii_from_digit_literal_upper[0]));
        return ivs_static_ascii_from_digit_literal_upper[val];
    }
}

IVS_STATUS
ivs_ascii_string_init(
    ivs_ascii_string *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self);
    ivs_array_list_init(&self->dat);
    const char zero = '\0';
    if (ivs_array_list_push_back(&self->dat, 1, alloc, &zero))
        IVS_LOG_FAILED();
    return IVS_SUCCESS;
}

void
ivs_ascii_string_free(
    const ivs_ascii_string *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self && alloc);
    ivs_array_list_free(&self->dat, alloc);
}

void
ivs_ascii_string_clear(
    ivs_ascii_string *const self
) {
    ivs_assert(self);
    ivs_assert(!ivs_array_list_empty(&self->dat));
    /**
     * hack, not a good design, but have to do this.
     */
    self->dat.mid = ivs_pv_add(self->dat.beg, 1);
    *(char *) self->dat.beg = '\0';
}

IVS_STATUS
ivs_ascii_string_copy(
    ivs_ascii_string *const dst,
    const ivs_allocator *const alloc,
    const ivs_ascii_string *const src
) {
    ivs_assert(dst && alloc && src);
    if (ivs_array_list_copy(&dst->dat, alloc, &src->dat))
        IVS_LOG_FAILED();
    else
        return IVS_SUCCESS;
}

void
ivs_ascii_string_move(
    ivs_ascii_string *const dst,
    ivs_ascii_string *const src
) {
    ivs_assert(dst && src);
    ivs_array_list_move(&dst->dat, &src->dat);
}

char *
ivs_ascii_string_data(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    return ivs_array_list_data(&self->dat);
}

const char *
ivs_ascii_string_cstr(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    /**
     * It's guaranteed to be null-terminated.
     */
    // ivs_ascii_string_nullterm(self, alloc);
    return ivs_ascii_string_data(self);
}

IVS_STATUS
ivs_ascii_string_from_literal(
    ivs_ascii_string *const self,
    const ivs_allocator *const alloc,
    const char *str
) {
    ivs_assert(self && str);
    ivs_ascii_string_clear(self);
    while (*str)
        if (ivs_ascii_string_push_back(self, alloc, *str++))
            IVS_LOG_FAILED();
    return IVS_SUCCESS;
}

_Bool
ivs_ascii_string_empty(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    return ivs_array_list_size(&self->dat) == 1;
}

size_t
ivs_ascii_string_size(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    ivs_assert(ivs_array_list_size(&self->dat));
    return ivs_array_list_size(&self->dat) - 1;
}

size_t
ivs_ascii_string_length(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    ivs_assert(ivs_array_list_length(&self->dat, 1));
    return ivs_array_list_size(&self->dat) - 1;
}

size_t
ivs_ascii_string_memused(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    return ivs_array_list_memused(&self->dat);
}

ivs_iterator
ivs_ascii_string_begin(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    if (ivs_ascii_string_empty(self))
        return ivs_iterator_make(NULL);
    else
        return ivs_array_list_begin(&self->dat);
}

ivs_iterator
ivs_ascii_string_before_end(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    if (ivs_ascii_string_empty(self))
        return ivs_iterator_make(NULL);
    else {
        ivs_iterator ret = ivs_array_list_before_end(&self->dat, 1);
        ret = ivs_array_list_advance(&self->dat, 1, ret, -1);
        return ret;
    }
}

char
ivs_ascii_string_front(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    ivs_assert(!ivs_ascii_string_empty(self));
    return *(const char *) ivs_array_list_front(&self->dat);
}

void
ivs_ascii_string_set_front(
    const ivs_ascii_string *const self,
    const char ch
) {
    ivs_assert(self);
    ivs_assert(!ivs_ascii_string_empty(self));
    ivs_assert(ch);
    *(char *) ivs_array_list_front(&self->dat) = ch;
}

char
ivs_ascii_string_back(
    const ivs_ascii_string *const self
) {
    ivs_assert(self);
    ivs_assert(!ivs_ascii_string_empty(self));
    return ivs_ascii_string_deref(self, ivs_ascii_string_before_end(self));
}

void
ivs_ascii_string_set_back(
    const ivs_ascii_string *const self,
    const char ch
) {
    ivs_assert(self);
    ivs_assert(!ivs_ascii_string_empty(self));
    ivs_assert(ch);
    const ivs_iterator iter = ivs_ascii_string_before_end(self);
    *(char *) ivs_array_list_deref(&self->dat, iter) = ch;
}

ivs_iterator
ivs_ascii_string_advance(
    const ivs_ascii_string *const self,
    const ivs_iterator iter,
    const ptrdiff_t step
) {
    ivs_assert(self);
    const ivs_iterator ret = ivs_array_list_advance(&self->dat, 1, iter, step);
    if (ivs_iterator_equal(&ret, ivs_array_list_before_end(&self->dat, 1)))
        return ivs_iterator_make(NULL);
    else
        return ret;
}

char
ivs_ascii_string_deref(
    const ivs_ascii_string *const self,
    const ivs_iterator iter
) {
    ivs_assert(self);
    ivs_assert(!ivs_iterator_empty(&iter));
    ivs_assert(*(const char *) ivs_array_list_deref(&self->dat, iter));
    return *(const char *) ivs_array_list_deref(&self->dat, iter);
}

const char *
ivs_ascii_string_deref_as_literal(
    const ivs_ascii_string *const self,
    const ivs_iterator iter
) {
    ivs_assert(self);
    ivs_assert(!ivs_ascii_string_empty(self));
    return ivs_array_list_deref(&self->dat, iter);
}

char
ivs_ascii_string_at(
    const ivs_ascii_string *const self,
    const size_t index
) {
    ivs_assert(self);
    ivs_assert(index < ivs_ascii_string_length(self));
    return *(const char *) ivs_array_list_at(&self->dat, 1, index);
}

void
ivs_ascii_string_at_set(
    const ivs_ascii_string *const self,
    const size_t index,
    const char ch
) {
    ivs_assert(self);
    ivs_assert(index < ivs_ascii_string_length(self));
    *(char *) ivs_array_list_at(&self->dat, 1, index) = ch;
}

IVS_STATUS
ivs_ascii_string_push_back(
    ivs_ascii_string *const self,
    const ivs_allocator *const alloc,
    const char ch
) {
    ivs_assert(self && alloc);
    ivs_assert(ch);
    *(char *) ivs_array_list_back(&self->dat, 1) = ch;
    const char zero = '\0';
    if (ivs_array_list_push_back(&self->dat, 1, alloc, &zero))
        IVS_LOG_FAILED();
    return IVS_SUCCESS;
}

void
ivs_ascii_string_pop_back(
    ivs_ascii_string *const self
) {
    ivs_assert(self);
    ivs_array_list_pop_back(&self->dat, 1);
    const char zero = '\0';
    *(char *) ivs_array_list_back(&self->dat, 1) = zero;
}

/**
 * Must be careful about whether the string is null-terminated.
 */
int
ivs_ascii_string_cmp(
    const ivs_ascii_string *const a,
    const ivs_ascii_string *const b
) {
    ivs_assert(a && b);
    ivs_iterator ia = ivs_ascii_string_begin(a);
    ivs_iterator ib = ivs_ascii_string_begin(b);
    while (!ivs_iterator_empty(&ia) && !ivs_iterator_empty(&ib)) {
        const char ca = ivs_ascii_string_deref(a, ia);
        const char cb = ivs_ascii_string_deref(b, ib);
        if (ca < cb)
            return -1;
        else if (ca > cb)
            return 1;
        else {
            ia = ivs_ascii_string_advance(a, ia, 1);
            ib = ivs_ascii_string_advance(b, ib, 1);
        }
    }
    if (ivs_iterator_empty(&ia))
        if (ivs_iterator_empty(&ib))
            return 0;
        else
            return -1;
    else
        return 1;
}

int
ivs_ascii_string_cmp_from_literal(
    const ivs_ascii_string *const self,
    const char *const str
) {
    ivs_assert(self && str);
    return strcmp(ivs_ascii_string_data(self), str);
}

int
ivs_functional_ascii_string_cmp(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    return ivs_ascii_string_cmp(a, b);
}

_Bool
ivs_ascii_string_equal(
    const ivs_ascii_string *const a,
    const ivs_ascii_string *const b
) {
    ivs_assert(a && b);
    if (ivs_ascii_string_length(a) != ivs_ascii_string_length(b))
        return 0;
    else
        return !ivs_ascii_string_cmp(a, b);
}

static
IVS_STATUS
ivs_static_ascii_string_to_printable_try_push(
    ivs_ascii_string *const self,
    const ivs_allocator *const alloc,
    const char ch
) {
    ivs_assert(self && alloc);
    if (isgraph(ch) || ch == ' ') {
        if (ivs_ascii_string_push_back(self, alloc, ch))
            IVS_LOG_FAILED();
    } else {
        if (ivs_ascii_string_push_back(self, alloc, '\\'))
            IVS_LOG_FAILED();
        switch (ch) {
            case '\0':
                if (ivs_ascii_string_push_back(self, alloc, '0'))
                    IVS_LOG_FAILED();
                break;
            case '\a':
                if (ivs_ascii_string_push_back(self, alloc, 'a'))
                    IVS_LOG_FAILED();
                break;
            case '\b':
                if (ivs_ascii_string_push_back(self, alloc, 'b'))
                    IVS_LOG_FAILED();
                break;
            case '\f':
                if (ivs_ascii_string_push_back(self, alloc, 'f'))
                    IVS_LOG_FAILED();
                break;
            case '\n':
                if (ivs_ascii_string_push_back(self, alloc, 'n'))
                    IVS_LOG_FAILED();
                break;
            case '\r':
                if (ivs_ascii_string_push_back(self, alloc, 'r'))
                    IVS_LOG_FAILED();
                break;
            case '\t':
                if (ivs_ascii_string_push_back(self, alloc, 't'))
                    IVS_LOG_FAILED();
                break;
            case '\v':
                if (ivs_ascii_string_push_back(self, alloc, 'v'))
                    IVS_LOG_FAILED();
                break;
            case '\"':
                if (ivs_ascii_string_push_back(self, alloc, '\"'))
                    IVS_LOG_FAILED();
                break;
            default:
                if (ivs_ascii_string_push_back(self, alloc, 'x'))
                    IVS_LOG_FAILED();
                if (ivs_ascii_string_push_back(self, alloc, ivs_ascii_from_digit(ch >> 4, 0)))
                    IVS_LOG_FAILED();
                if (ivs_ascii_string_push_back(self, alloc, ivs_ascii_from_digit(ch & (char) 0xf0, 0)))
                    IVS_LOG_FAILED();
        }
    }
    return IVS_SUCCESS;
}

IVS_STATUS
ivs_ascii_string_to_printable(
    ivs_ascii_string *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self && alloc);
    ivs_ascii_string out;
    if (ivs_ascii_string_init(&out, alloc))
        IVS_LOG_FAILED();
    ivs_iterator iter = ivs_ascii_string_begin(self);
    while (!ivs_iterator_empty(&iter)) {
        const char ch = ivs_ascii_string_deref(self, iter);
        if (ivs_static_ascii_string_to_printable_try_push(&out, alloc, ch)) {
            ivs_ascii_string_free(&out, alloc);
            IVS_LOG_FAILED();
        }
        iter = ivs_ascii_string_advance(self, iter, 1);
    }
    ivs_ascii_string_move(self, &out);
    ivs_ascii_string_free(&out, alloc);
    return IVS_SUCCESS;
}
