/**
* Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#ifndef IVS_HASH_H
#define IVS_HASH_H


#include <stdint.h>
#include <stdio.h>

#include "./core.h"


typedef struct ivs_hash_md5_result {
    char dat[16];
} ivs_hash_md5_result;


void
ivs_hash_md5_result_print(
    const ivs_hash_md5_result *self,
    FILE *os
);

ivs_hash_md5_result
ivs_hash_md5(
    int (*fn)(void *),
    void *opt_fd
);


#endif
