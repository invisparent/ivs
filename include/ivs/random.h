/**
* Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_RANDOM_H
#define IVS_RANDOM_H


#include <stdint.h>

#include "./core.h"


/**
 * A special date when a white little spirit embraced the light...
 */
#define IVS_RANDOM_SEED 20230205


typedef struct ivs_rng_vtable ivs_rng_vtable;


typedef struct ivs_rng {
    const ivs_rng_vtable *vp;
} ivs_rng;


struct ivs_rng_vtable {

    uint32_t
    (*const opt_u32)(
        const ivs_rng *
    );

    uint64_t
    (*const opt_u64)(
        const ivs_rng *
    );

    void
    (*const free)(
        const ivs_rng *
    );
};


uint32_t
ivs_rng_u32(
    const ivs_rng *self
);

uint64_t
ivs_rng_u64(
    const ivs_rng *self
);

float
ivs_rng_u32_to_flt(
    uint32_t x
);

double
ivs_rng_u64_to_dbl(
    uint64_t x
);

float
ivs_rng_flt(
    const ivs_rng *self
);

double
ivs_rng_dbl(
    const ivs_rng *self
);

void
ivs_rng_free(
    const ivs_rng *self
);


extern const ivs_rng_vtable ivs_xorshift_vtable;


typedef struct ivs_xorshift {
    ivs_rng base;
    uint32_t state;
} ivs_xorshift;


void
ivs_xorshift_init(
    ivs_xorshift *self,
    uint32_t seed
);

uint32_t
ivs_xorshift_u32(
    ivs_xorshift *self
);

uint64_t
ivs_xorshift_u64(
    ivs_xorshift *self
);


extern const ivs_rng_vtable ivs_xorshift_64_vtable;


typedef struct ivs_xorshift_64 {
    ivs_rng base;
    uint64_t state;
} ivs_xorshift_64;


void
ivs_xorshift_64_init(
    ivs_xorshift_64 *self,
    uint64_t seed
);

uint32_t
ivs_xorshift_64_u32(
    ivs_xorshift_64 *self
);

uint64_t
ivs_xorshift_64_u64(
    ivs_xorshift_64 *self
);


#ifdef IVS_EXT_X64


extern const ivs_rng_vtable ivs_x64_rdrand_vtable;


typedef struct ivs_x64_rdrand {
    ivs_rng base;
} ivs_x64_rdrand;


#endif


#endif
