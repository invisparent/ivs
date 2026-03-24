/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


#include "ivs/hash.h"


void
ivs_hash_md5_result_print(
    const ivs_hash_md5_result *const self,
    FILE *const os
) {
    ivs_assert(self && os);
    for (int t = 0; t < 16; ++t)
        fprintf(os, "%2x", *(unsigned char *) (self->dat + t));
}


uint32_t
ivs_static_hash_md5_f(
    const uint32_t x,
    const uint32_t y,
    const uint32_t z
) {
    return (x & y) | (~x & z);
}

uint32_t
ivs_static_hash_md5_g(
    const uint32_t x,
    const uint32_t y,
    const uint32_t z
) {
    return (x & z) | (y & ~z);
}

uint32_t
ivs_static_hash_md5_h(
    const uint32_t x,
    const uint32_t y,
    const uint32_t z
) {
    return x ^ y ^ z;
}

uint32_t
ivs_static_hash_md5_i(
    const uint32_t x,
    const uint32_t y,
    const uint32_t z
) {
    return y ^ (x | ~z);
}

uint32_t
ivs_static_hash_md5_rotate_left(
    const uint32_t x,
    const uint32_t n
) {
    return x << n | x >> (32 - n);
}

uint32_t
ivs_static_hash_md5_ff(
    const uint32_t a,
    const uint32_t b,
    const uint32_t c,
    const uint32_t d,
    const uint32_t x,
    const uint32_t s,
    const uint32_t ac
) {
    uint32_t ret = a;
    ret += ivs_static_hash_md5_f(b, c, d) + x + ac;
    ret = ivs_static_hash_md5_rotate_left(ret, s);
    ret += b;
    return ret;
}

uint32_t
ivs_static_hash_md5_gg(
    const uint32_t a,
    const uint32_t b,
    const uint32_t c,
    const uint32_t d,
    const uint32_t x,
    const uint32_t s,
    const uint32_t ac
) {
    uint32_t ret = a;
    ret += ivs_static_hash_md5_g(b, c, d) + x + ac;
    ret = ivs_static_hash_md5_rotate_left(ret, s);
    ret += b;
    return ret;
}

uint32_t
ivs_static_hash_md5_hh(
    const uint32_t a,
    const uint32_t b,
    const uint32_t c,
    const uint32_t d,
    const uint32_t x,
    const uint32_t s,
    const uint32_t ac
) {
    uint32_t ret = a;
    ret += ivs_static_hash_md5_h(b, c, d) + x + ac;
    ret = ivs_static_hash_md5_rotate_left(ret, s);
    ret += b;
    return ret;
}

uint32_t
ivs_static_hash_md5_ii(
    const uint32_t a,
    const uint32_t b,
    const uint32_t c,
    const uint32_t d,
    const uint32_t x,
    const uint32_t s,
    const uint32_t ac
) {
    uint32_t ret = a;
    ret += ivs_static_hash_md5_i(b, c, d) + x + ac;
    ret = ivs_static_hash_md5_rotate_left(ret, s);
    ret += b;
    return ret;
}

void
ivs_static_hash_md5_block(
    ivs_hash_md5_result *const io,
    const uint32_t *const buf
) {
    ivs_assert(io && buf);

    uint32_t *const p = (uint32_t *) io->dat;

    uint32_t a = p[0];
    uint32_t b = p[1];
    uint32_t c = p[2];
    uint32_t d = p[3];

    // R1
    a = ivs_static_hash_md5_ff(a, b, c, d, buf[ 0],  7, 0xd76aa478);
    d = ivs_static_hash_md5_ff(d, a, b, c, buf[ 1], 12, 0xe8c7b756);
    c = ivs_static_hash_md5_ff(c, d, a, b, buf[ 2], 17, 0x242070db);
    b = ivs_static_hash_md5_ff(b, c, d, a, buf[ 3], 22, 0xc1bdceee);
    a = ivs_static_hash_md5_ff(a, b, c, d, buf[ 4],  7, 0xf57c0faf);
    d = ivs_static_hash_md5_ff(d, a, b, c, buf[ 5], 12, 0x4787c62a);
    c = ivs_static_hash_md5_ff(c, d, a, b, buf[ 6], 17, 0xa8304613);
    b = ivs_static_hash_md5_ff(b, c, d, a, buf[ 7], 22, 0xfd469501);
    a = ivs_static_hash_md5_ff(a, b, c, d, buf[ 8],  7, 0x698098d8);
    d = ivs_static_hash_md5_ff(d, a, b, c, buf[ 9], 12, 0x8b44f7af);
    c = ivs_static_hash_md5_ff(c, d, a, b, buf[10], 17, 0xffff5bb1);
    b = ivs_static_hash_md5_ff(b, c, d, a, buf[11], 22, 0x895cd7be);
    a = ivs_static_hash_md5_ff(a, b, c, d, buf[12],  7, 0x6b901122);
    d = ivs_static_hash_md5_ff(d, a, b, c, buf[13], 12, 0xfd987193);
    c = ivs_static_hash_md5_ff(c, d, a, b, buf[14], 17, 0xa679438e);
    b = ivs_static_hash_md5_ff(b, c, d, a, buf[15], 22, 0x49b40821);

    // R2
    a = ivs_static_hash_md5_gg(a, b, c, d, buf[ 1],  5, 0xf61e2562);
    d = ivs_static_hash_md5_gg(d, a, b, c, buf[ 6],  9, 0xc040b340);
    c = ivs_static_hash_md5_gg(c, d, a, b, buf[11], 14, 0x265e5a51);
    b = ivs_static_hash_md5_gg(b, c, d, a, buf[ 0], 20, 0xe9b6c7aa);
    a = ivs_static_hash_md5_gg(a, b, c, d, buf[ 5],  5, 0xd62f105d);
    d = ivs_static_hash_md5_gg(d, a, b, c, buf[10],  9, 0x2441453);
    c = ivs_static_hash_md5_gg(c, d, a, b, buf[15], 14, 0xd8a1e681);
    b = ivs_static_hash_md5_gg(b, c, d, a, buf[ 4], 20, 0xe7d3fbc8);
    a = ivs_static_hash_md5_gg(a, b, c, d, buf[ 9],  5, 0x21e1cde6);
    d = ivs_static_hash_md5_gg(d, a, b, c, buf[14],  9, 0xc33707d6);
    c = ivs_static_hash_md5_gg(c, d, a, b, buf[ 3], 14, 0xf4d50d87);
    b = ivs_static_hash_md5_gg(b, c, d, a, buf[ 8], 20, 0x455a14ed);
    a = ivs_static_hash_md5_gg(a, b, c, d, buf[13],  5, 0xa9e3e905);
    d = ivs_static_hash_md5_gg(d, a, b, c, buf[ 2],  9, 0xfcefa3f8);
    c = ivs_static_hash_md5_gg(c, d, a, b, buf[ 7], 14, 0x676f02d9);
    b = ivs_static_hash_md5_gg(b, c, d, a, buf[12], 20, 0x8d2a4c8a);

    // R3
    a = ivs_static_hash_md5_hh(a, b, c, d, buf[ 5],  4, 0xfffa3942);
    d = ivs_static_hash_md5_hh(d, a, b, c, buf[ 8], 11, 0x8771f681);
    c = ivs_static_hash_md5_hh(c, d, a, b, buf[11], 16, 0x6d9d6122);
    b = ivs_static_hash_md5_hh(b, c, d, a, buf[14], 23, 0xfde5380c);
    a = ivs_static_hash_md5_hh(a, b, c, d, buf[ 1],  4, 0xa4beea44);
    d = ivs_static_hash_md5_hh(d, a, b, c, buf[ 4], 11, 0x4bdecfa9);
    c = ivs_static_hash_md5_hh(c, d, a, b, buf[ 7], 16, 0xf6bb4b60);
    b = ivs_static_hash_md5_hh(b, c, d, a, buf[10], 23, 0xbebfbc70);
    a = ivs_static_hash_md5_hh(a, b, c, d, buf[13],  4, 0x289b7ec6);
    d = ivs_static_hash_md5_hh(d, a, b, c, buf[ 0], 11, 0xeaa127fa);
    c = ivs_static_hash_md5_hh(c, d, a, b, buf[ 3], 16, 0xd4ef3085);
    b = ivs_static_hash_md5_hh(b, c, d, a, buf[ 6], 23, 0x4881d05);
    a = ivs_static_hash_md5_hh(a, b, c, d, buf[ 9],  4, 0xd9d4d039);
    d = ivs_static_hash_md5_hh(d, a, b, c, buf[12], 11, 0xe6db99e5);
    c = ivs_static_hash_md5_hh(c, d, a, b, buf[15], 16, 0x1fa27cf8);
    b = ivs_static_hash_md5_hh(b, c, d, a, buf[ 2], 23, 0xc4ac5665);

    // R4
    a = ivs_static_hash_md5_ii(a, b, c, d, buf[ 0],  6, 0xf4292244);
    d = ivs_static_hash_md5_ii(d, a, b, c, buf[ 7], 10, 0x432aff97);
    c = ivs_static_hash_md5_ii(c, d, a, b, buf[14], 15, 0xab9423a7);
    b = ivs_static_hash_md5_ii(b, c, d, a, buf[ 5], 21, 0xfc93a039);
    a = ivs_static_hash_md5_ii(a, b, c, d, buf[12],  6, 0x655b59c3);
    d = ivs_static_hash_md5_ii(d, a, b, c, buf[ 3], 10, 0x8f0ccc92);
    c = ivs_static_hash_md5_ii(c, d, a, b, buf[10], 15, 0xffeff47d);
    b = ivs_static_hash_md5_ii(b, c, d, a, buf[ 1], 21, 0x85845dd1);
    a = ivs_static_hash_md5_ii(a, b, c, d, buf[ 8],  6, 0x6fa87e4f);
    d = ivs_static_hash_md5_ii(d, a, b, c, buf[15], 10, 0xfe2ce6e0);
    c = ivs_static_hash_md5_ii(c, d, a, b, buf[ 6], 15, 0xa3014314);
    b = ivs_static_hash_md5_ii(b, c, d, a, buf[13], 21, 0x4e0811a1);
    a = ivs_static_hash_md5_ii(a, b, c, d, buf[ 4],  6, 0xf7537e82);
    d = ivs_static_hash_md5_ii(d, a, b, c, buf[11], 10, 0xbd3af235);
    c = ivs_static_hash_md5_ii(c, d, a, b, buf[ 2], 15, 0x2ad7d2bb);
    b = ivs_static_hash_md5_ii(b, c, d, a, buf[ 9], 21, 0xeb86d391);

    p[0] += a;
    p[1] += b;
    p[2] += c;
    p[3] += d;
}

ivs_hash_md5_result
ivs_hash_md5(
    int (*fn)(void *),
    void *const opt_fd
) {
    ivs_assert(fn);
    _Bool little;
    ivs_is_little_endian(little);
    ivs_hash_md5_result ret;
    uint32_t *const rd = (uint32_t *) ret.dat;
    if (little) {
        rd[0] = 0x67452301;
        rd[1] = 0xefcdab89;
        rd[2] = 0x98badcfe;
        rd[3] = 0x10325476;
    } else {
        rd[0] = 0x01234567;
        rd[1] = 0x89abcdef;
        rd[2] = 0xfedcba98;
        rd[3] = 0x76543210;
    }
    uint64_t len = 0;
    char buf[64];
    const char *const end = buf + 64;
    const char *const pad_ctrl = buf + 56;
    char *iter = buf;
    while (1) {
        const int ch = fn(opt_fd);
        if (ch == IVS_EOF)
            break;
        ++len;
        *iter++ = (char) ch;
        if (iter == end) {
            ivs_static_hash_md5_block(&ret, (const uint32_t *) buf);
            iter = buf;
        }
    }
    _Bool add_one = 0;
    if (iter >= pad_ctrl) {
        if (iter < end) {
            *iter++ = '\x80';
            add_one = 1;
        }
        while (iter < end)
            *iter++ = '\0';
        ivs_static_hash_md5_block(&ret, (const uint32_t *) buf);
        iter = buf;
    }
    if (iter < pad_ctrl) {
        if (!add_one)
            *iter++ = '\x80';
        while (iter < pad_ctrl)
            *iter++ = '\0';
    }
    len *= 8;
    const char *const p = (const char *) &len;
    if (little)
        for (int t = 0; t < 8; ++t)
            *iter++ = p[t];
    else
        for (int t = 7; t >= 0; --t)
            *iter++ = p[t];
    ivs_static_hash_md5_block(&ret, (const uint32_t *) buf);
    return ret;
}
