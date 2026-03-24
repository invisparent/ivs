/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include "ivs/random.h"


static
uint32_t
ivs_static_rng_u64_to_u32(
    uint64_t x
) {
    x >>= 32;
    const uint32_t ret = (uint32_t) x;
    return ret;
}

static
uint64_t
ivs_static_rng_u32_to_u64(
    const uint32_t x,
    const uint32_t y
) {
    uint64_t ret = x;
    ret <<= 32;
    ret += y;
    return ret;
}


uint32_t
ivs_rng_u32(
    const ivs_rng *self
) {
    ivs_assert(self);
    ivs_assert(self->vp->opt_u32 || self->vp->opt_u64);
    if (self->vp->opt_u32)
        return self->vp->opt_u32(self);
    else
        return ivs_static_rng_u64_to_u32(self->vp->opt_u64(self));
}

uint64_t
ivs_rng_u64(
    const ivs_rng *self
) {
    ivs_assert(self);
    ivs_assert(self->vp->opt_u32 || self->vp->opt_u64);
    if (self->vp->opt_u64)
        return self->vp->opt_u64(self);
    else {
        const uint32_t x = self->vp->opt_u32(self);
        const uint32_t y = self->vp->opt_u32(self);
        return ivs_static_rng_u32_to_u64(x, y);
    }
}

float
ivs_rng_u32_to_flt(
    const uint32_t x
) {
    return (float) x / (float) UINT32_MAX;
}

double
ivs_rng_u64_to_dbl(
    const uint64_t x
) {
    return (double) x / (double) UINT64_MAX;
}

float
ivs_rng_flt(
    const ivs_rng *self
) {
    ivs_assert(self);
    return ivs_rng_u32_to_flt(ivs_rng_u32(self));
}

double
ivs_rng_dbl(
    const ivs_rng *self
) {
    ivs_assert(self);
    return ivs_rng_u64_to_dbl(ivs_rng_u64(self));
}

void
ivs_rng_free(
    const ivs_rng *self
) {
    ivs_assert(self);
    if (self->vp->free)
        self->vp->free(self);
}


const ivs_rng_vtable ivs_xorshift_vtable = {

    .opt_u32 =
    (uint32_t(*const)(
        const ivs_rng *
    )) ivs_xorshift_u32,

    .opt_u64 =
    (uint64_t(*const)(
        const ivs_rng *
    )) ivs_xorshift_u64

};


/**
 * Xorshift algorithm.
 *
 * Reference:
 * Marsaglia, George. (2003). Xorshift RNGs. Journal of Statistical Software. 8. 10.18637/jss.v008.i14.
 */


void
ivs_xorshift_init(
    ivs_xorshift *const self,
    const uint32_t seed
) {
    ivs_assert(self);
    self->state = seed;
}

uint32_t
ivs_xorshift_u32(
    ivs_xorshift *const self
) {
    ivs_assert(self);
    self->state ^= self->state << 3;
    self->state ^= self->state >> 23;
    self->state ^= self->state << 25;
    return self->state;
}

uint64_t
ivs_xorshift_u64(
    ivs_xorshift *const self
) {
    ivs_assert(self);
    const uint32_t x = ivs_xorshift_u32(self);
    const uint32_t y = ivs_xorshift_u32(self);
    return ivs_static_rng_u32_to_u64(x, y);
}


void
ivs_xorshift_64_init(
    ivs_xorshift_64 *const self,
    const uint64_t seed
) {
    ivs_assert(self);
    self->state = seed;
}

uint32_t
ivs_xorshift_64_u32(
    ivs_xorshift_64 *const self
) {
    ivs_assert(self);
    return ivs_static_rng_u64_to_u32(ivs_xorshift_64_u64(self));
}

uint64_t
ivs_xorshift_64_u64(
    ivs_xorshift_64 *const self
) {
    ivs_assert(self);
    self->state ^= self->state << 23;
    self->state ^= self->state >> 17;
    self->state ^= self->state << 25;
    return self->state;
}


#ifdef IVS_EXT_X64


/**
 * @return true if this machine supports rdrand, 0 otherwise.
 */
_Bool
ivs_x64_rdrand_test(
    ivs_x64_rdrand* const self
) {
    (void) self;
    uint64_t cpuid;
    ivs_asm_volatile(
        "cpuid;"
        "");
}


#endif
