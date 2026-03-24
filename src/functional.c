/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include <stdint.h>

#include "ivs/functional.h"


/**
 * Various comparators
 */

_Bool
ivs_functional_less_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    return *pa != *pb;
}

_Bool
ivs_functional_less_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    return *pa < *pb;
}

_Bool
ivs_functional_less_equal_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    return *pa <= *pb;
}

_Bool
ivs_functional_greater_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    return *pa > *pb;
}

_Bool
ivs_functional_greater_equal_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    return *pa >= *pb;
}

_Bool
ivs_functional_equal_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    return *pa == *pb;
}

_Bool
ivs_functional_not_equal_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    return *pa != *pb;
}


int
ivs_functional_cmp_int(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int *const pa = a;
    const int *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_unsigned(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const unsigned *const pa = a;
    const unsigned *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_int8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int8_t *const pa = a;
    const int8_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_uint8_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint8_t *const pa = a;
    const uint8_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_int16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int16_t *const pa = a;
    const int16_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_uint16_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint16_t *const pa = a;
    const uint16_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_int32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int32_t *const pa = a;
    const int32_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_uint32_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint32_t *const pa = a;
    const uint32_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_int64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const int64_t *const pa = a;
    const int64_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_uint64_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const uint64_t *const pa = a;
    const uint64_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_size_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const size_t *const pa = a;
    const size_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_flt(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const float *const pa = a;
    const float *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_dbl(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const double *const pa = a;
    const double *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_ptrdiff_t(
    const void *const a,
    const void *const b
) {
    ivs_assert(a && b);
    const ptrdiff_t *const pa = a;
    const ptrdiff_t *const pb = b;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_ptr(
    const void *const ppa,
    const void *const ppb
) {
    ivs_assert(ppa && ppb);
    const void *const *const pa = ppa;
    const void *const *const pb = ppb;
    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int
ivs_functional_cmp_int_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_int(a, b);
}

int
ivs_functional_cmp_unsigned_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_unsigned(a, b);
}

int
ivs_functional_cmp_int8_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_int8_t(a, b);
}

int
ivs_functional_cmp_uint8_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_uint8_t(a, b);
}

int
ivs_functional_cmp_int16_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_int16_t(a, b);
}

int
ivs_functional_cmp_uint16_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_uint16_t(a, b);
}

int
ivs_functional_cmp_int32_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_int32_t(a, b);
}

int
ivs_functional_cmp_uint32_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_uint32_t(a, b);
}

int
ivs_functional_cmp_int64_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_int64_t(a, b);
}

int
ivs_functional_cmp_uint64_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_uint64_t(a, b);
}

int
ivs_functional_cmp_size_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_size_t(a, b);
}

int
ivs_functional_cmp_flt_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_flt(a, b);
}

int
ivs_functional_cmp_dbl_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_dbl(a, b);
}

int
ivs_functional_cmp_ptrdiff_t_reverse(
    const void *a,
    const void *b
) {
    ivs_assert(a && b);
    return -ivs_functional_cmp_ptrdiff_t(a, b);
}

int
ivs_functional_cmp_ptr_reverse(
    const void *ppa,
    const void *ppb
) {
    ivs_assert(ppa && ppb);
    return -ivs_functional_cmp_ptr(ppa, ppb);
}
