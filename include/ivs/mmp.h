/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


/**
 * mmp.h: macro metaprogramming library
 * This library utilizes a C23 extension.
 * Any program that depends on those macros in this file
 *   may no longer strictly conform to ISO/IEC 9899:2011 (The C11 Standard).
 * But for most compilers, even for those very, very old compilers
 *   (e.g. GCC-4.9, the first one that almost fully supports ISO C11 standard),
 *   it works fine.
 */


#ifndef IVS_MMP_H
#define IVS_MMP_H


#define IVS_MMP_CAT(a, b) a##b
#define IVS_MMP_EXCAT(a, b) IVS_MMP_EXCAT_(a, b)
#define IVS_MMP_EXCAT_(a, b) IVS_MMP_CAT(a, b)

#define IVS_MMP_STR(param) #param


#define IVS_MMP_POPFRONT(front, ...) __VA_ARGS__

#define IVS_MMP_PARAM_1(param, ...) param
#define IVS_MMP_PARAM_2(a, param, ...) param
#define IVS_MMP_PARAM_3(a, b, param, ...) param
#define IVS_MMP_PARAM_4(a, b, c, param, ...) param
#define IVS_MMP_PARAM_5(a, b, c, d, param, ...) param
#define IVS_MMP_PARAM_6(a, b, c, d, e, param, ...) param
#define IVS_MMP_PARAM_7(a, b, c, d, e, f, param, ...) param
#define IVS_MMP_PARAM_8(a, b, c, d, e, f, g, param, ...) param
#define IVS_MMP_PARAM_9(a, b, c, d, e, f, g, h, param, ...) param


#define IVS_MMP_PROBE(param) param, 1

#define IVS_MMP_CHECK(...) IVS_MMP_PARAM_2(__VA_ARGS__, 0)

#define IVS_MMP_EMPTY(param, ...) IVS_MMP_CHECK(IVS_MMP_EXCAT(IVS_MMP_CAT(IVS_MMP_EMPTY_, param), 0_))
#define IVS_MMP_EMPTY_0_ IVS_MMP_PROBE()

#define IVS_MMP_XEMPTY(param, ...) IVS_MMP_CHECK(IVS_MMP_EXCAT(IVS_MMP_CAT(IVS_MMP_XEMPTY_, param), 0_))
#define IVS_MMP_XEMPTY_ivs0_ IVS_MMP_PROBE()


#define IVS_MMP_NULL()

#define IVS_MMP_DEFER(expr) expr IVS_MMP_NULL()


#define IVS_MMP_FOREACH_1(macro, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_1_0_(macro, a, ...) macro(a) IVS_MMP_DEFER(IVS_MMP_FOREACH_1_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_1_1_(macro, a, ...) macro(a)
#define IVS_MMP_FOREACH_1_() IVS_MMP_FOREACH_1

#define IVS_MMP_FOREACH_2(macro, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_2_0_(macro, a, b, ...) macro(a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_2_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_2_1_(macro, a, b, ...) macro(a, b)
#define IVS_MMP_FOREACH_2_() IVS_MMP_FOREACH_2

#define IVS_MMP_FOREACH_3(macro, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_3_0_(macro, a, b, c, ...) macro(a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_3_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_3_1_(macro, a, b, c, ...) macro(a, b, c)
#define IVS_MMP_FOREACH_3_() IVS_MMP_FOREACH_3

#define IVS_MMP_FOREACH_4(macro, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_4_0_(macro, a, b, c, d, ...) macro(a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_4_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_4_1_(macro, a, b, c, d, ...) macro(a, b, c, d)
#define IVS_MMP_FOREACH_4_() IVS_MMP_FOREACH_4

#define IVS_MMP_FOREACH_5(macro, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_5_0_(macro, a, b, c, d, e, ...) macro(a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_5_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_5_1_(macro, a, b, c, d, e, ...) macro(a, b, c, d, e)
#define IVS_MMP_FOREACH_5_() IVS_MMP_FOREACH_5

#define IVS_MMP_FOREACH_6(macro, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_6_0_(macro, a, b, c, d, e, f, ...) macro(a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_6_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_6_1_(macro, a, b, c, d, e, f, ...) macro(a, b, c, d, e, f)
#define IVS_MMP_FOREACH_6_() IVS_MMP_FOREACH_6

#define IVS_MMP_FOREACH_7(macro, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_7_0_(macro, a, b, c, d, e, f, g, ...) macro(a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_7_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_7_1_(macro, a, b, c, d, e, f, g, ...) macro(a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_7_() IVS_MMP_FOREACH_7

#define IVS_MMP_FOREACH_8(macro, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_8_0_(macro, a, b, c, d, e, f, g, h, ...) macro(a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_8_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_8_1_(macro, a, b, c, d, e, f, g, h, ...) macro(a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_8_() IVS_MMP_FOREACH_8

#define IVS_MMP_FOREACH_9(macro, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_9_0_(macro, a, b, c, d, e, f, g, h, i, ...) macro(a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_9_)()(macro, __VA_ARGS__)
#define IVS_MMP_FOREACH_9_1_(macro, a, b, c, d, e, f, g, h, i, ...) macro(a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_9_() IVS_MMP_FOREACH_9


#define IVS_MMP_FOREACH_F1_1(macro, f1, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_1_0_(macro, f1, a, ...) macro(f1, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_1_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_1_1_(macro, f1, a, ...) macro(f1, a)
#define IVS_MMP_FOREACH_F1_1_() IVS_MMP_FOREACH_F1_1

#define IVS_MMP_FOREACH_F1_2(macro, f1, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_2_0_(macro, f1, a, b, ...) macro(f1, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_2_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_2_1_(macro, f1, a, b, ...) macro(f1, a, b)
#define IVS_MMP_FOREACH_F1_2_() IVS_MMP_FOREACH_F1_2

#define IVS_MMP_FOREACH_F1_3(macro, f1, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_3_0_(macro, f1, a, b, c, ...) macro(f1, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_3_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_3_1_(macro, f1, a, b, c, ...) macro(f1, a, b, c)
#define IVS_MMP_FOREACH_F1_3_() IVS_MMP_FOREACH_F1_3

#define IVS_MMP_FOREACH_F1_4(macro, f1, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_4_0_(macro, f1, a, b, c, d, ...) macro(f1, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_4_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_4_1_(macro, f1, a, b, c, d, ...) macro(f1, a, b, c, d)
#define IVS_MMP_FOREACH_F1_4_() IVS_MMP_FOREACH_F1_4

#define IVS_MMP_FOREACH_F1_5(macro, f1, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_5_0_(macro, f1, a, b, c, d, e, ...) macro(f1, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_5_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_5_1_(macro, f1, a, b, c, d, e, ...) macro(f1, a, b, c, d, e)
#define IVS_MMP_FOREACH_F1_5_() IVS_MMP_FOREACH_F1_5

#define IVS_MMP_FOREACH_F1_6(macro, f1, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_6_0_(macro, f1, a, b, c, d, e, f, ...) macro(f1, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_6_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_6_1_(macro, f1, a, b, c, d, e, f, ...) macro(f1, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F1_6_() IVS_MMP_FOREACH_F1_6

#define IVS_MMP_FOREACH_F1_7(macro, f1, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_7_0_(macro, f1, a, b, c, d, e, f, g, ...) macro(f1, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_7_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_7_1_(macro, f1, a, b, c, d, e, f, g, ...) macro(f1, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F1_7_() IVS_MMP_FOREACH_F1_7

#define IVS_MMP_FOREACH_F1_8(macro, f1, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_8_0_(macro, f1, a, b, c, d, e, f, g, h, ...) macro(f1, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_8_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_8_1_(macro, f1, a, b, c, d, e, f, g, h, ...) macro(f1, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F1_8_() IVS_MMP_FOREACH_F1_8

#define IVS_MMP_FOREACH_F1_9(macro, f1, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F1_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_9_0_(macro, f1, a, b, c, d, e, f, g, h, i, ...) macro(f1, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F1_9_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_FOREACH_F1_9_1_(macro, f1, a, b, c, d, e, f, g, h, i, ...) macro(f1, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F1_9_() IVS_MMP_FOREACH_F1_9


#define IVS_MMP_FOREACH_F2_1(macro, f1, f2, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_1_0_(macro, f1, f2, a, ...) macro(f1, f2, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_1_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_1_1_(macro, f1, f2, a, ...) macro(f1, f2, a)
#define IVS_MMP_FOREACH_F2_1_() IVS_MMP_FOREACH_F2_1

#define IVS_MMP_FOREACH_F2_2(macro, f1, f2, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_2_0_(macro, f1, f2, a, b, ...) macro(f1, f2, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_2_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_2_1_(macro, f1, f2, a, b, ...) macro(f1, f2, a, b)
#define IVS_MMP_FOREACH_F2_2_() IVS_MMP_FOREACH_F2_2

#define IVS_MMP_FOREACH_F2_3(macro, f1, f2, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_3_0_(macro, f1, f2, a, b, c, ...) macro(f1, f2, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_3_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_3_1_(macro, f1, f2, a, b, c, ...) macro(f1, f2, a, b, c)
#define IVS_MMP_FOREACH_F2_3_() IVS_MMP_FOREACH_F2_3

#define IVS_MMP_FOREACH_F2_4(macro, f1, f2, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_4_0_(macro, f1, f2, a, b, c, d, ...) macro(f1, f2, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_4_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_4_1_(macro, f1, f2, a, b, c, d, ...) macro(f1, f2, a, b, c, d)
#define IVS_MMP_FOREACH_F2_4_() IVS_MMP_FOREACH_F2_4

#define IVS_MMP_FOREACH_F2_5(macro, f1, f2, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_5_0_(macro, f1, f2, a, b, c, d, e, ...) macro(f1, f2, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_5_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_5_1_(macro, f1, f2, a, b, c, d, e, ...) macro(f1, f2, a, b, c, d, e)
#define IVS_MMP_FOREACH_F2_5_() IVS_MMP_FOREACH_F2_5

#define IVS_MMP_FOREACH_F2_6(macro, f1, f2, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_6_0_(macro, f1, f2, a, b, c, d, e, f, ...) macro(f1, f2, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_6_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_6_1_(macro, f1, f2, a, b, c, d, e, f, ...) macro(f1, f2, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F2_6_() IVS_MMP_FOREACH_F2_6

#define IVS_MMP_FOREACH_F2_7(macro, f1, f2, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_7_0_(macro, f1, f2, a, b, c, d, e, f, g, ...) macro(f1, f2, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_7_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_7_1_(macro, f1, f2, a, b, c, d, e, f, g, ...) macro(f1, f2, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F2_7_() IVS_MMP_FOREACH_F2_7

#define IVS_MMP_FOREACH_F2_8(macro, f1, f2, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_8_0_(macro, f1, f2, a, b, c, d, e, f, g, h, ...) macro(f1, f2, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_8_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_8_1_(macro, f1, f2, a, b, c, d, e, f, g, h, ...) macro(f1, f2, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F2_8_() IVS_MMP_FOREACH_F2_8

#define IVS_MMP_FOREACH_F2_9(macro, f1, f2, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F2_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_9_0_(macro, f1, f2, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F2_9_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_FOREACH_F2_9_1_(macro, f1, f2, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F2_9_() IVS_MMP_FOREACH_F2_9


#define IVS_MMP_FOREACH_F3_1(macro, f1, f2, f3, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_1_0_(macro, f1, f2, f3, a, ...) macro(f1, f2, f3, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_1_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_1_1_(macro, f1, f2, f3, a, ...) macro(f1, f2, f3, a)
#define IVS_MMP_FOREACH_F3_1_() IVS_MMP_FOREACH_F3_1

#define IVS_MMP_FOREACH_F3_2(macro, f1, f2, f3, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_2_0_(macro, f1, f2, f3, a, b, ...) macro(f1, f2, f3, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_2_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_2_1_(macro, f1, f2, f3, a, b, ...) macro(f1, f2, f3, a, b)
#define IVS_MMP_FOREACH_F3_2_() IVS_MMP_FOREACH_F3_2

#define IVS_MMP_FOREACH_F3_3(macro, f1, f2, f3, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_3_0_(macro, f1, f2, f3, a, b, c, ...) macro(f1, f2, f3, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_3_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_3_1_(macro, f1, f2, f3, a, b, c, ...) macro(f1, f2, f3, a, b, c)
#define IVS_MMP_FOREACH_F3_3_() IVS_MMP_FOREACH_F3_3

#define IVS_MMP_FOREACH_F3_4(macro, f1, f2, f3, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_4_0_(macro, f1, f2, f3, a, b, c, d, ...) macro(f1, f2, f3, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_4_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_4_1_(macro, f1, f2, f3, a, b, c, d, ...) macro(f1, f2, f3, a, b, c, d)
#define IVS_MMP_FOREACH_F3_4_() IVS_MMP_FOREACH_F3_4

#define IVS_MMP_FOREACH_F3_5(macro, f1, f2, f3, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_5_0_(macro, f1, f2, f3, a, b, c, d, e, ...) macro(f1, f2, f3, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_5_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_5_1_(macro, f1, f2, f3, a, b, c, d, e, ...) macro(f1, f2, f3, a, b, c, d, e)
#define IVS_MMP_FOREACH_F3_5_() IVS_MMP_FOREACH_F3_5

#define IVS_MMP_FOREACH_F3_6(macro, f1, f2, f3, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_6_0_(macro, f1, f2, f3, a, b, c, d, e, f, ...) macro(f1, f2, f3, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_6_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_6_1_(macro, f1, f2, f3, a, b, c, d, e, f, ...) macro(f1, f2, f3, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F3_6_() IVS_MMP_FOREACH_F3_6

#define IVS_MMP_FOREACH_F3_7(macro, f1, f2, f3, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_7_0_(macro, f1, f2, f3, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_7_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_7_1_(macro, f1, f2, f3, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F3_7_() IVS_MMP_FOREACH_F3_7

#define IVS_MMP_FOREACH_F3_8(macro, f1, f2, f3, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_8_0_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_8_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_8_1_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F3_8_() IVS_MMP_FOREACH_F3_8

#define IVS_MMP_FOREACH_F3_9(macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F3_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_9_0_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F3_9_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_FOREACH_F3_9_1_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F3_9_() IVS_MMP_FOREACH_F3_9


#define IVS_MMP_FOREACH_F4_1(macro, f1, f2, f3, f4, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_1_0_(macro, f1, f2, f3, f4, a, ...) macro(f1, f2, f3, f4, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_1_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_1_1_(macro, f1, f2, f3, f4, a, ...) macro(f1, f2, f3, f4, a)
#define IVS_MMP_FOREACH_F4_1_() IVS_MMP_FOREACH_F4_1

#define IVS_MMP_FOREACH_F4_2(macro, f1, f2, f3, f4, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_2_0_(macro, f1, f2, f3, f4, a, b, ...) macro(f1, f2, f3, f4, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_2_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_2_1_(macro, f1, f2, f3, f4, a, b, ...) macro(f1, f2, f3, f4, a, b)
#define IVS_MMP_FOREACH_F4_2_() IVS_MMP_FOREACH_F4_2

#define IVS_MMP_FOREACH_F4_3(macro, f1, f2, f3, f4, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_3_0_(macro, f1, f2, f3, f4, a, b, c, ...) macro(f1, f2, f3, f4, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_3_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_3_1_(macro, f1, f2, f3, f4, a, b, c, ...) macro(f1, f2, f3, f4, a, b, c)
#define IVS_MMP_FOREACH_F4_3_() IVS_MMP_FOREACH_F4_3

#define IVS_MMP_FOREACH_F4_4(macro, f1, f2, f3, f4, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_4_0_(macro, f1, f2, f3, f4, a, b, c, d, ...) macro(f1, f2, f3, f4, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_4_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_4_1_(macro, f1, f2, f3, f4, a, b, c, d, ...) macro(f1, f2, f3, f4, a, b, c, d)
#define IVS_MMP_FOREACH_F4_4_() IVS_MMP_FOREACH_F4_4

#define IVS_MMP_FOREACH_F4_5(macro, f1, f2, f3, f4, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_5_0_(macro, f1, f2, f3, f4, a, b, c, d, e, ...) macro(f1, f2, f3, f4, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_5_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_5_1_(macro, f1, f2, f3, f4, a, b, c, d, e, ...) macro(f1, f2, f3, f4, a, b, c, d, e)
#define IVS_MMP_FOREACH_F4_5_() IVS_MMP_FOREACH_F4_5

#define IVS_MMP_FOREACH_F4_6(macro, f1, f2, f3, f4, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_6_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_6_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_6_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F4_6_() IVS_MMP_FOREACH_F4_6

#define IVS_MMP_FOREACH_F4_7(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_7_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_7_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_7_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F4_7_() IVS_MMP_FOREACH_F4_7

#define IVS_MMP_FOREACH_F4_8(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_8_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_8_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_8_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F4_8_() IVS_MMP_FOREACH_F4_8

#define IVS_MMP_FOREACH_F4_9(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F4_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_9_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F4_9_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_FOREACH_F4_9_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F4_9_() IVS_MMP_FOREACH_F4_9


#define IVS_MMP_FOREACH_F5_1(macro, f1, f2, f3, f4, f5, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_1_0_(macro, f1, f2, f3, f4, f5, a, ...) macro(f1, f2, f3, f4, f5, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_1_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_1_1_(macro, f1, f2, f3, f4, f5, a, ...) macro(f1, f2, f3, f4, f5, a)
#define IVS_MMP_FOREACH_F5_1_() IVS_MMP_FOREACH_F5_1

#define IVS_MMP_FOREACH_F5_2(macro, f1, f2, f3, f4, f5, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_2_0_(macro, f1, f2, f3, f4, f5, a, b, ...) macro(f1, f2, f3, f4, f5, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_2_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_2_1_(macro, f1, f2, f3, f4, f5, a, b, ...) macro(f1, f2, f3, f4, f5, a, b)
#define IVS_MMP_FOREACH_F5_2_() IVS_MMP_FOREACH_F5_2

#define IVS_MMP_FOREACH_F5_3(macro, f1, f2, f3, f4, f5, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_3_0_(macro, f1, f2, f3, f4, f5, a, b, c, ...) macro(f1, f2, f3, f4, f5, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_3_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_3_1_(macro, f1, f2, f3, f4, f5, a, b, c, ...) macro(f1, f2, f3, f4, f5, a, b, c)
#define IVS_MMP_FOREACH_F5_3_() IVS_MMP_FOREACH_F5_3

#define IVS_MMP_FOREACH_F5_4(macro, f1, f2, f3, f4, f5, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_4_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_4_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_4_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, a, b, c, d)
#define IVS_MMP_FOREACH_F5_4_() IVS_MMP_FOREACH_F5_4

#define IVS_MMP_FOREACH_F5_5(macro, f1, f2, f3, f4, f5, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_5_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_5_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_5_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e)
#define IVS_MMP_FOREACH_F5_5_() IVS_MMP_FOREACH_F5_5

#define IVS_MMP_FOREACH_F5_6(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_6_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_6_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_6_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F5_6_() IVS_MMP_FOREACH_F5_6

#define IVS_MMP_FOREACH_F5_7(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_7_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_7_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_7_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F5_7_() IVS_MMP_FOREACH_F5_7

#define IVS_MMP_FOREACH_F5_8(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_8_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_8_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_8_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F5_8_() IVS_MMP_FOREACH_F5_8

#define IVS_MMP_FOREACH_F5_9(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F5_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_9_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F5_9_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_FOREACH_F5_9_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F5_9_() IVS_MMP_FOREACH_F5_9


#define IVS_MMP_FOREACH_F6_1(macro, f1, f2, f3, f4, f5, f6, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_1_0_(macro, f1, f2, f3, f4, f5, f6, a, ...) macro(f1, f2, f3, f4, f5, f6, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_1_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_1_1_(macro, f1, f2, f3, f4, f5, f6, a, ...) macro(f1, f2, f3, f4, f5, f6, a)
#define IVS_MMP_FOREACH_F6_1_() IVS_MMP_FOREACH_F6_1

#define IVS_MMP_FOREACH_F6_2(macro, f1, f2, f3, f4, f5, f6, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_2_0_(macro, f1, f2, f3, f4, f5, f6, a, b, ...) macro(f1, f2, f3, f4, f5, f6, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_2_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_2_1_(macro, f1, f2, f3, f4, f5, f6, a, b, ...) macro(f1, f2, f3, f4, f5, f6, a, b)
#define IVS_MMP_FOREACH_F6_2_() IVS_MMP_FOREACH_F6_2

#define IVS_MMP_FOREACH_F6_3(macro, f1, f2, f3, f4, f5, f6, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_3_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_3_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_3_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c)
#define IVS_MMP_FOREACH_F6_3_() IVS_MMP_FOREACH_F6_3

#define IVS_MMP_FOREACH_F6_4(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_4_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_4_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_4_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d)
#define IVS_MMP_FOREACH_F6_4_() IVS_MMP_FOREACH_F6_4

#define IVS_MMP_FOREACH_F6_5(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_5_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_5_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_5_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e)
#define IVS_MMP_FOREACH_F6_5_() IVS_MMP_FOREACH_F6_5

#define IVS_MMP_FOREACH_F6_6(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_6_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_6_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_6_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F6_6_() IVS_MMP_FOREACH_F6_6

#define IVS_MMP_FOREACH_F6_7(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_7_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_7_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_7_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F6_7_() IVS_MMP_FOREACH_F6_7

#define IVS_MMP_FOREACH_F6_8(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_8_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_8_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_8_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F6_8_() IVS_MMP_FOREACH_F6_8

#define IVS_MMP_FOREACH_F6_9(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F6_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_9_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F6_9_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_FOREACH_F6_9_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F6_9_() IVS_MMP_FOREACH_F6_9


#define IVS_MMP_FOREACH_F7_1(macro, f1, f2, f3, f4, f5, f6, f7, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_1_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_1_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_1_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, a)
#define IVS_MMP_FOREACH_F7_1_() IVS_MMP_FOREACH_F7_1

#define IVS_MMP_FOREACH_F7_2(macro, f1, f2, f3, f4, f5, f6, f7, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_2_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_2_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_2_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b)
#define IVS_MMP_FOREACH_F7_2_() IVS_MMP_FOREACH_F7_2

#define IVS_MMP_FOREACH_F7_3(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_3_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_3_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_3_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c)
#define IVS_MMP_FOREACH_F7_3_() IVS_MMP_FOREACH_F7_3

#define IVS_MMP_FOREACH_F7_4(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_4_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_4_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_4_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d)
#define IVS_MMP_FOREACH_F7_4_() IVS_MMP_FOREACH_F7_4

#define IVS_MMP_FOREACH_F7_5(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_5_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_5_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_5_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e)
#define IVS_MMP_FOREACH_F7_5_() IVS_MMP_FOREACH_F7_5

#define IVS_MMP_FOREACH_F7_6(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_6_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_6_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_6_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F7_6_() IVS_MMP_FOREACH_F7_6

#define IVS_MMP_FOREACH_F7_7(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_7_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_7_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_7_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F7_7_() IVS_MMP_FOREACH_F7_7

#define IVS_MMP_FOREACH_F7_8(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_8_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_8_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_8_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F7_8_() IVS_MMP_FOREACH_F7_8

#define IVS_MMP_FOREACH_F7_9(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F7_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_9_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F7_9_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_FOREACH_F7_9_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F7_9_() IVS_MMP_FOREACH_F7_9


#define IVS_MMP_FOREACH_F8_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_1_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_1_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_1_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a)
#define IVS_MMP_FOREACH_F8_1_() IVS_MMP_FOREACH_F8_1

#define IVS_MMP_FOREACH_F8_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_2_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_2_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_2_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b)
#define IVS_MMP_FOREACH_F8_2_() IVS_MMP_FOREACH_F8_2

#define IVS_MMP_FOREACH_F8_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_3_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_3_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_3_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c)
#define IVS_MMP_FOREACH_F8_3_() IVS_MMP_FOREACH_F8_3

#define IVS_MMP_FOREACH_F8_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_4_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_4_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_4_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d)
#define IVS_MMP_FOREACH_F8_4_() IVS_MMP_FOREACH_F8_4

#define IVS_MMP_FOREACH_F8_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_5_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_5_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_5_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e)
#define IVS_MMP_FOREACH_F8_5_() IVS_MMP_FOREACH_F8_5

#define IVS_MMP_FOREACH_F8_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_6_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_6_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_6_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F8_6_() IVS_MMP_FOREACH_F8_6

#define IVS_MMP_FOREACH_F8_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_7_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_7_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_7_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F8_7_() IVS_MMP_FOREACH_F8_7

#define IVS_MMP_FOREACH_F8_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_8_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_8_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_8_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F8_8_() IVS_MMP_FOREACH_F8_8

#define IVS_MMP_FOREACH_F8_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F8_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_9_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F8_9_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_FOREACH_F8_9_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F8_9_() IVS_MMP_FOREACH_F8_9


#define IVS_MMP_FOREACH_F9_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_1_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_1_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_1_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_1_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a)
#define IVS_MMP_FOREACH_F9_1_() IVS_MMP_FOREACH_F9_1

#define IVS_MMP_FOREACH_F9_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_2_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_2_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_2_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_2_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b)
#define IVS_MMP_FOREACH_F9_2_() IVS_MMP_FOREACH_F9_2

#define IVS_MMP_FOREACH_F9_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_3_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_3_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_3_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_3_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c)
#define IVS_MMP_FOREACH_F9_3_() IVS_MMP_FOREACH_F9_3

#define IVS_MMP_FOREACH_F9_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_4_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_4_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_4_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_4_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d)
#define IVS_MMP_FOREACH_F9_4_() IVS_MMP_FOREACH_F9_4

#define IVS_MMP_FOREACH_F9_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_5_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_5_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_5_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_5_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e)
#define IVS_MMP_FOREACH_F9_5_() IVS_MMP_FOREACH_F9_5

#define IVS_MMP_FOREACH_F9_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_6_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_6_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_6_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_6_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f)
#define IVS_MMP_FOREACH_F9_6_() IVS_MMP_FOREACH_F9_6

#define IVS_MMP_FOREACH_F9_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_7_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_7_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_7_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_7_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g)
#define IVS_MMP_FOREACH_F9_7_() IVS_MMP_FOREACH_F9_7

#define IVS_MMP_FOREACH_F9_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_8_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_8_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_8_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_8_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h)
#define IVS_MMP_FOREACH_F9_8_() IVS_MMP_FOREACH_F9_8

#define IVS_MMP_FOREACH_F9_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_FOREACH_F9_9_, IVS_MMP_EMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_9_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_FOREACH_F9_9_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_FOREACH_F9_9_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_FOREACH_F9_9_() IVS_MMP_FOREACH_F9_9


#define IVS_MMP_X_FOREACH_1(macro, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_1_0_(macro, a, ...) macro(a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_1_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_1_1_(macro, a, ...) macro(a)
#define IVS_MMP_X_FOREACH_1_() IVS_MMP_X_FOREACH_1

#define IVS_MMP_X_FOREACH_2(macro, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_2_0_(macro, a, b, ...) macro(a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_2_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_2_1_(macro, a, b, ...) macro(a, b)
#define IVS_MMP_X_FOREACH_2_() IVS_MMP_X_FOREACH_2

#define IVS_MMP_X_FOREACH_3(macro, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_3_0_(macro, a, b, c, ...) macro(a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_3_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_3_1_(macro, a, b, c, ...) macro(a, b, c)
#define IVS_MMP_X_FOREACH_3_() IVS_MMP_X_FOREACH_3

#define IVS_MMP_X_FOREACH_4(macro, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_4_0_(macro, a, b, c, d, ...) macro(a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_4_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_4_1_(macro, a, b, c, d, ...) macro(a, b, c, d)
#define IVS_MMP_X_FOREACH_4_() IVS_MMP_X_FOREACH_4

#define IVS_MMP_X_FOREACH_5(macro, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_5_0_(macro, a, b, c, d, e, ...) macro(a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_5_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_5_1_(macro, a, b, c, d, e, ...) macro(a, b, c, d, e)
#define IVS_MMP_X_FOREACH_5_() IVS_MMP_X_FOREACH_5

#define IVS_MMP_X_FOREACH_6(macro, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_6_0_(macro, a, b, c, d, e, f, ...) macro(a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_6_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_6_1_(macro, a, b, c, d, e, f, ...) macro(a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_6_() IVS_MMP_X_FOREACH_6

#define IVS_MMP_X_FOREACH_7(macro, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_7_0_(macro, a, b, c, d, e, f, g, ...) macro(a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_7_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_7_1_(macro, a, b, c, d, e, f, g, ...) macro(a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_7_() IVS_MMP_X_FOREACH_7

#define IVS_MMP_X_FOREACH_8(macro, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_8_0_(macro, a, b, c, d, e, f, g, h, ...) macro(a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_8_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_8_1_(macro, a, b, c, d, e, f, g, h, ...) macro(a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_8_() IVS_MMP_X_FOREACH_8

#define IVS_MMP_X_FOREACH_9(macro, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_9_0_(macro, a, b, c, d, e, f, g, h, i, ...) macro(a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_9_)()(macro, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_9_1_(macro, a, b, c, d, e, f, g, h, i, ...) macro(a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_9_() IVS_MMP_X_FOREACH_9


#define IVS_MMP_X_FOREACH_F1_1(macro, f1, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_1_0_(macro, f1, a, ...) macro(f1, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_1_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_1_1_(macro, f1, a, ...) macro(f1, a)
#define IVS_MMP_X_FOREACH_F1_1_() IVS_MMP_X_FOREACH_F1_1

#define IVS_MMP_X_FOREACH_F1_2(macro, f1, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_2_0_(macro, f1, a, b, ...) macro(f1, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_2_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_2_1_(macro, f1, a, b, ...) macro(f1, a, b)
#define IVS_MMP_X_FOREACH_F1_2_() IVS_MMP_X_FOREACH_F1_2

#define IVS_MMP_X_FOREACH_F1_3(macro, f1, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_3_0_(macro, f1, a, b, c, ...) macro(f1, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_3_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_3_1_(macro, f1, a, b, c, ...) macro(f1, a, b, c)
#define IVS_MMP_X_FOREACH_F1_3_() IVS_MMP_X_FOREACH_F1_3

#define IVS_MMP_X_FOREACH_F1_4(macro, f1, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_4_0_(macro, f1, a, b, c, d, ...) macro(f1, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_4_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_4_1_(macro, f1, a, b, c, d, ...) macro(f1, a, b, c, d)
#define IVS_MMP_X_FOREACH_F1_4_() IVS_MMP_X_FOREACH_F1_4

#define IVS_MMP_X_FOREACH_F1_5(macro, f1, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_5_0_(macro, f1, a, b, c, d, e, ...) macro(f1, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_5_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_5_1_(macro, f1, a, b, c, d, e, ...) macro(f1, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F1_5_() IVS_MMP_X_FOREACH_F1_5

#define IVS_MMP_X_FOREACH_F1_6(macro, f1, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_6_0_(macro, f1, a, b, c, d, e, f, ...) macro(f1, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_6_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_6_1_(macro, f1, a, b, c, d, e, f, ...) macro(f1, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F1_6_() IVS_MMP_X_FOREACH_F1_6

#define IVS_MMP_X_FOREACH_F1_7(macro, f1, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_7_0_(macro, f1, a, b, c, d, e, f, g, ...) macro(f1, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_7_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_7_1_(macro, f1, a, b, c, d, e, f, g, ...) macro(f1, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F1_7_() IVS_MMP_X_FOREACH_F1_7

#define IVS_MMP_X_FOREACH_F1_8(macro, f1, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_8_0_(macro, f1, a, b, c, d, e, f, g, h, ...) macro(f1, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_8_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_8_1_(macro, f1, a, b, c, d, e, f, g, h, ...) macro(f1, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F1_8_() IVS_MMP_X_FOREACH_F1_8

#define IVS_MMP_X_FOREACH_F1_9(macro, f1, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F1_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_9_0_(macro, f1, a, b, c, d, e, f, g, h, i, ...) macro(f1, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F1_9_)()(macro, f1, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F1_9_1_(macro, f1, a, b, c, d, e, f, g, h, i, ...) macro(f1, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F1_9_() IVS_MMP_X_FOREACH_F1_9


#define IVS_MMP_X_FOREACH_F2_1(macro, f1, f2, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_1_0_(macro, f1, f2, a, ...) macro(f1, f2, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_1_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_1_1_(macro, f1, f2, a, ...) macro(f1, f2, a)
#define IVS_MMP_X_FOREACH_F2_1_() IVS_MMP_X_FOREACH_F2_1

#define IVS_MMP_X_FOREACH_F2_2(macro, f1, f2, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_2_0_(macro, f1, f2, a, b, ...) macro(f1, f2, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_2_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_2_1_(macro, f1, f2, a, b, ...) macro(f1, f2, a, b)
#define IVS_MMP_X_FOREACH_F2_2_() IVS_MMP_X_FOREACH_F2_2

#define IVS_MMP_X_FOREACH_F2_3(macro, f1, f2, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_3_0_(macro, f1, f2, a, b, c, ...) macro(f1, f2, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_3_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_3_1_(macro, f1, f2, a, b, c, ...) macro(f1, f2, a, b, c)
#define IVS_MMP_X_FOREACH_F2_3_() IVS_MMP_X_FOREACH_F2_3

#define IVS_MMP_X_FOREACH_F2_4(macro, f1, f2, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_4_0_(macro, f1, f2, a, b, c, d, ...) macro(f1, f2, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_4_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_4_1_(macro, f1, f2, a, b, c, d, ...) macro(f1, f2, a, b, c, d)
#define IVS_MMP_X_FOREACH_F2_4_() IVS_MMP_X_FOREACH_F2_4

#define IVS_MMP_X_FOREACH_F2_5(macro, f1, f2, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_5_0_(macro, f1, f2, a, b, c, d, e, ...) macro(f1, f2, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_5_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_5_1_(macro, f1, f2, a, b, c, d, e, ...) macro(f1, f2, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F2_5_() IVS_MMP_X_FOREACH_F2_5

#define IVS_MMP_X_FOREACH_F2_6(macro, f1, f2, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_6_0_(macro, f1, f2, a, b, c, d, e, f, ...) macro(f1, f2, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_6_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_6_1_(macro, f1, f2, a, b, c, d, e, f, ...) macro(f1, f2, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F2_6_() IVS_MMP_X_FOREACH_F2_6

#define IVS_MMP_X_FOREACH_F2_7(macro, f1, f2, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_7_0_(macro, f1, f2, a, b, c, d, e, f, g, ...) macro(f1, f2, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_7_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_7_1_(macro, f1, f2, a, b, c, d, e, f, g, ...) macro(f1, f2, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F2_7_() IVS_MMP_X_FOREACH_F2_7

#define IVS_MMP_X_FOREACH_F2_8(macro, f1, f2, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_8_0_(macro, f1, f2, a, b, c, d, e, f, g, h, ...) macro(f1, f2, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_8_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_8_1_(macro, f1, f2, a, b, c, d, e, f, g, h, ...) macro(f1, f2, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F2_8_() IVS_MMP_X_FOREACH_F2_8

#define IVS_MMP_X_FOREACH_F2_9(macro, f1, f2, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F2_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_9_0_(macro, f1, f2, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F2_9_)()(macro, f1, f2, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F2_9_1_(macro, f1, f2, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F2_9_() IVS_MMP_X_FOREACH_F2_9


#define IVS_MMP_X_FOREACH_F3_1(macro, f1, f2, f3, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_1_0_(macro, f1, f2, f3, a, ...) macro(f1, f2, f3, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_1_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_1_1_(macro, f1, f2, f3, a, ...) macro(f1, f2, f3, a)
#define IVS_MMP_X_FOREACH_F3_1_() IVS_MMP_X_FOREACH_F3_1

#define IVS_MMP_X_FOREACH_F3_2(macro, f1, f2, f3, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_2_0_(macro, f1, f2, f3, a, b, ...) macro(f1, f2, f3, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_2_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_2_1_(macro, f1, f2, f3, a, b, ...) macro(f1, f2, f3, a, b)
#define IVS_MMP_X_FOREACH_F3_2_() IVS_MMP_X_FOREACH_F3_2

#define IVS_MMP_X_FOREACH_F3_3(macro, f1, f2, f3, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_3_0_(macro, f1, f2, f3, a, b, c, ...) macro(f1, f2, f3, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_3_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_3_1_(macro, f1, f2, f3, a, b, c, ...) macro(f1, f2, f3, a, b, c)
#define IVS_MMP_X_FOREACH_F3_3_() IVS_MMP_X_FOREACH_F3_3

#define IVS_MMP_X_FOREACH_F3_4(macro, f1, f2, f3, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_4_0_(macro, f1, f2, f3, a, b, c, d, ...) macro(f1, f2, f3, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_4_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_4_1_(macro, f1, f2, f3, a, b, c, d, ...) macro(f1, f2, f3, a, b, c, d)
#define IVS_MMP_X_FOREACH_F3_4_() IVS_MMP_X_FOREACH_F3_4

#define IVS_MMP_X_FOREACH_F3_5(macro, f1, f2, f3, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_5_0_(macro, f1, f2, f3, a, b, c, d, e, ...) macro(f1, f2, f3, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_5_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_5_1_(macro, f1, f2, f3, a, b, c, d, e, ...) macro(f1, f2, f3, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F3_5_() IVS_MMP_X_FOREACH_F3_5

#define IVS_MMP_X_FOREACH_F3_6(macro, f1, f2, f3, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_6_0_(macro, f1, f2, f3, a, b, c, d, e, f, ...) macro(f1, f2, f3, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_6_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_6_1_(macro, f1, f2, f3, a, b, c, d, e, f, ...) macro(f1, f2, f3, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F3_6_() IVS_MMP_X_FOREACH_F3_6

#define IVS_MMP_X_FOREACH_F3_7(macro, f1, f2, f3, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_7_0_(macro, f1, f2, f3, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_7_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_7_1_(macro, f1, f2, f3, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F3_7_() IVS_MMP_X_FOREACH_F3_7

#define IVS_MMP_X_FOREACH_F3_8(macro, f1, f2, f3, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_8_0_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_8_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_8_1_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F3_8_() IVS_MMP_X_FOREACH_F3_8

#define IVS_MMP_X_FOREACH_F3_9(macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F3_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_9_0_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F3_9_)()(macro, f1, f2, f3, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F3_9_1_(macro, f1, f2, f3, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F3_9_() IVS_MMP_X_FOREACH_F3_9


#define IVS_MMP_X_FOREACH_F4_1(macro, f1, f2, f3, f4, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_1_0_(macro, f1, f2, f3, f4, a, ...) macro(f1, f2, f3, f4, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_1_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_1_1_(macro, f1, f2, f3, f4, a, ...) macro(f1, f2, f3, f4, a)
#define IVS_MMP_X_FOREACH_F4_1_() IVS_MMP_X_FOREACH_F4_1

#define IVS_MMP_X_FOREACH_F4_2(macro, f1, f2, f3, f4, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_2_0_(macro, f1, f2, f3, f4, a, b, ...) macro(f1, f2, f3, f4, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_2_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_2_1_(macro, f1, f2, f3, f4, a, b, ...) macro(f1, f2, f3, f4, a, b)
#define IVS_MMP_X_FOREACH_F4_2_() IVS_MMP_X_FOREACH_F4_2

#define IVS_MMP_X_FOREACH_F4_3(macro, f1, f2, f3, f4, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_3_0_(macro, f1, f2, f3, f4, a, b, c, ...) macro(f1, f2, f3, f4, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_3_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_3_1_(macro, f1, f2, f3, f4, a, b, c, ...) macro(f1, f2, f3, f4, a, b, c)
#define IVS_MMP_X_FOREACH_F4_3_() IVS_MMP_X_FOREACH_F4_3

#define IVS_MMP_X_FOREACH_F4_4(macro, f1, f2, f3, f4, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_4_0_(macro, f1, f2, f3, f4, a, b, c, d, ...) macro(f1, f2, f3, f4, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_4_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_4_1_(macro, f1, f2, f3, f4, a, b, c, d, ...) macro(f1, f2, f3, f4, a, b, c, d)
#define IVS_MMP_X_FOREACH_F4_4_() IVS_MMP_X_FOREACH_F4_4

#define IVS_MMP_X_FOREACH_F4_5(macro, f1, f2, f3, f4, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_5_0_(macro, f1, f2, f3, f4, a, b, c, d, e, ...) macro(f1, f2, f3, f4, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_5_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_5_1_(macro, f1, f2, f3, f4, a, b, c, d, e, ...) macro(f1, f2, f3, f4, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F4_5_() IVS_MMP_X_FOREACH_F4_5

#define IVS_MMP_X_FOREACH_F4_6(macro, f1, f2, f3, f4, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_6_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_6_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_6_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F4_6_() IVS_MMP_X_FOREACH_F4_6

#define IVS_MMP_X_FOREACH_F4_7(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_7_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_7_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_7_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F4_7_() IVS_MMP_X_FOREACH_F4_7

#define IVS_MMP_X_FOREACH_F4_8(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_8_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_8_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_8_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F4_8_() IVS_MMP_X_FOREACH_F4_8

#define IVS_MMP_X_FOREACH_F4_9(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F4_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_9_0_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F4_9_)()(macro, f1, f2, f3, f4, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F4_9_1_(macro, f1, f2, f3, f4, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F4_9_() IVS_MMP_X_FOREACH_F4_9


#define IVS_MMP_X_FOREACH_F5_1(macro, f1, f2, f3, f4, f5, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_1_0_(macro, f1, f2, f3, f4, f5, a, ...) macro(f1, f2, f3, f4, f5, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_1_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_1_1_(macro, f1, f2, f3, f4, f5, a, ...) macro(f1, f2, f3, f4, f5, a)
#define IVS_MMP_X_FOREACH_F5_1_() IVS_MMP_X_FOREACH_F5_1

#define IVS_MMP_X_FOREACH_F5_2(macro, f1, f2, f3, f4, f5, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_2_0_(macro, f1, f2, f3, f4, f5, a, b, ...) macro(f1, f2, f3, f4, f5, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_2_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_2_1_(macro, f1, f2, f3, f4, f5, a, b, ...) macro(f1, f2, f3, f4, f5, a, b)
#define IVS_MMP_X_FOREACH_F5_2_() IVS_MMP_X_FOREACH_F5_2

#define IVS_MMP_X_FOREACH_F5_3(macro, f1, f2, f3, f4, f5, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_3_0_(macro, f1, f2, f3, f4, f5, a, b, c, ...) macro(f1, f2, f3, f4, f5, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_3_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_3_1_(macro, f1, f2, f3, f4, f5, a, b, c, ...) macro(f1, f2, f3, f4, f5, a, b, c)
#define IVS_MMP_X_FOREACH_F5_3_() IVS_MMP_X_FOREACH_F5_3

#define IVS_MMP_X_FOREACH_F5_4(macro, f1, f2, f3, f4, f5, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_4_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_4_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_4_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, a, b, c, d)
#define IVS_MMP_X_FOREACH_F5_4_() IVS_MMP_X_FOREACH_F5_4

#define IVS_MMP_X_FOREACH_F5_5(macro, f1, f2, f3, f4, f5, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_5_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_5_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_5_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F5_5_() IVS_MMP_X_FOREACH_F5_5

#define IVS_MMP_X_FOREACH_F5_6(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_6_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_6_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_6_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F5_6_() IVS_MMP_X_FOREACH_F5_6

#define IVS_MMP_X_FOREACH_F5_7(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_7_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_7_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_7_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F5_7_() IVS_MMP_X_FOREACH_F5_7

#define IVS_MMP_X_FOREACH_F5_8(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_8_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_8_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_8_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F5_8_() IVS_MMP_X_FOREACH_F5_8

#define IVS_MMP_X_FOREACH_F5_9(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F5_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_9_0_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F5_9_)()(macro, f1, f2, f3, f4, f5, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F5_9_1_(macro, f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F5_9_() IVS_MMP_X_FOREACH_F5_9


#define IVS_MMP_X_FOREACH_F6_1(macro, f1, f2, f3, f4, f5, f6, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_1_0_(macro, f1, f2, f3, f4, f5, f6, a, ...) macro(f1, f2, f3, f4, f5, f6, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_1_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_1_1_(macro, f1, f2, f3, f4, f5, f6, a, ...) macro(f1, f2, f3, f4, f5, f6, a)
#define IVS_MMP_X_FOREACH_F6_1_() IVS_MMP_X_FOREACH_F6_1

#define IVS_MMP_X_FOREACH_F6_2(macro, f1, f2, f3, f4, f5, f6, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_2_0_(macro, f1, f2, f3, f4, f5, f6, a, b, ...) macro(f1, f2, f3, f4, f5, f6, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_2_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_2_1_(macro, f1, f2, f3, f4, f5, f6, a, b, ...) macro(f1, f2, f3, f4, f5, f6, a, b)
#define IVS_MMP_X_FOREACH_F6_2_() IVS_MMP_X_FOREACH_F6_2

#define IVS_MMP_X_FOREACH_F6_3(macro, f1, f2, f3, f4, f5, f6, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_3_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_3_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_3_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c)
#define IVS_MMP_X_FOREACH_F6_3_() IVS_MMP_X_FOREACH_F6_3

#define IVS_MMP_X_FOREACH_F6_4(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_4_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_4_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_4_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d)
#define IVS_MMP_X_FOREACH_F6_4_() IVS_MMP_X_FOREACH_F6_4

#define IVS_MMP_X_FOREACH_F6_5(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_5_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_5_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_5_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F6_5_() IVS_MMP_X_FOREACH_F6_5

#define IVS_MMP_X_FOREACH_F6_6(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_6_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_6_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_6_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F6_6_() IVS_MMP_X_FOREACH_F6_6

#define IVS_MMP_X_FOREACH_F6_7(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_7_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_7_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_7_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F6_7_() IVS_MMP_X_FOREACH_F6_7

#define IVS_MMP_X_FOREACH_F6_8(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_8_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_8_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_8_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F6_8_() IVS_MMP_X_FOREACH_F6_8

#define IVS_MMP_X_FOREACH_F6_9(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F6_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_9_0_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F6_9_)()(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F6_9_1_(macro, f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F6_9_() IVS_MMP_X_FOREACH_F6_9


#define IVS_MMP_X_FOREACH_F7_1(macro, f1, f2, f3, f4, f5, f6, f7, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_1_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_1_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_1_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, a)
#define IVS_MMP_X_FOREACH_F7_1_() IVS_MMP_X_FOREACH_F7_1

#define IVS_MMP_X_FOREACH_F7_2(macro, f1, f2, f3, f4, f5, f6, f7, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_2_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_2_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_2_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b)
#define IVS_MMP_X_FOREACH_F7_2_() IVS_MMP_X_FOREACH_F7_2

#define IVS_MMP_X_FOREACH_F7_3(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_3_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_3_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_3_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c)
#define IVS_MMP_X_FOREACH_F7_3_() IVS_MMP_X_FOREACH_F7_3

#define IVS_MMP_X_FOREACH_F7_4(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_4_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_4_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_4_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d)
#define IVS_MMP_X_FOREACH_F7_4_() IVS_MMP_X_FOREACH_F7_4

#define IVS_MMP_X_FOREACH_F7_5(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_5_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_5_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_5_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F7_5_() IVS_MMP_X_FOREACH_F7_5

#define IVS_MMP_X_FOREACH_F7_6(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_6_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_6_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_6_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F7_6_() IVS_MMP_X_FOREACH_F7_6

#define IVS_MMP_X_FOREACH_F7_7(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_7_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_7_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_7_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F7_7_() IVS_MMP_X_FOREACH_F7_7

#define IVS_MMP_X_FOREACH_F7_8(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_8_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_8_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_8_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F7_8_() IVS_MMP_X_FOREACH_F7_8

#define IVS_MMP_X_FOREACH_F7_9(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F7_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_9_0_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F7_9_)()(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F7_9_1_(macro, f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F7_9_() IVS_MMP_X_FOREACH_F7_9


#define IVS_MMP_X_FOREACH_F8_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_1_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_1_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_1_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a)
#define IVS_MMP_X_FOREACH_F8_1_() IVS_MMP_X_FOREACH_F8_1

#define IVS_MMP_X_FOREACH_F8_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_2_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_2_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_2_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b)
#define IVS_MMP_X_FOREACH_F8_2_() IVS_MMP_X_FOREACH_F8_2

#define IVS_MMP_X_FOREACH_F8_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_3_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_3_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_3_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c)
#define IVS_MMP_X_FOREACH_F8_3_() IVS_MMP_X_FOREACH_F8_3

#define IVS_MMP_X_FOREACH_F8_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_4_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_4_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_4_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d)
#define IVS_MMP_X_FOREACH_F8_4_() IVS_MMP_X_FOREACH_F8_4

#define IVS_MMP_X_FOREACH_F8_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_5_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_5_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_5_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F8_5_() IVS_MMP_X_FOREACH_F8_5

#define IVS_MMP_X_FOREACH_F8_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_6_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_6_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_6_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F8_6_() IVS_MMP_X_FOREACH_F8_6

#define IVS_MMP_X_FOREACH_F8_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_7_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_7_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_7_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F8_7_() IVS_MMP_X_FOREACH_F8_7

#define IVS_MMP_X_FOREACH_F8_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_8_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_8_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_8_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F8_8_() IVS_MMP_X_FOREACH_F8_8

#define IVS_MMP_X_FOREACH_F8_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F8_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_9_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F8_9_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F8_9_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F8_9_() IVS_MMP_X_FOREACH_F8_9


#define IVS_MMP_X_FOREACH_F9_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_1_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_1_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_1_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_1_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a)
#define IVS_MMP_X_FOREACH_F9_1_() IVS_MMP_X_FOREACH_F9_1

#define IVS_MMP_X_FOREACH_F9_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_2_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_2_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_2_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_2_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b)
#define IVS_MMP_X_FOREACH_F9_2_() IVS_MMP_X_FOREACH_F9_2

#define IVS_MMP_X_FOREACH_F9_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_3_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_3_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_3_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_3_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c)
#define IVS_MMP_X_FOREACH_F9_3_() IVS_MMP_X_FOREACH_F9_3

#define IVS_MMP_X_FOREACH_F9_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_4_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_4_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_4_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_4_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d)
#define IVS_MMP_X_FOREACH_F9_4_() IVS_MMP_X_FOREACH_F9_4

#define IVS_MMP_X_FOREACH_F9_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_5_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_5_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_5_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_5_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e)
#define IVS_MMP_X_FOREACH_F9_5_() IVS_MMP_X_FOREACH_F9_5

#define IVS_MMP_X_FOREACH_F9_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_6_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_6_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_6_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_6_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f)
#define IVS_MMP_X_FOREACH_F9_6_() IVS_MMP_X_FOREACH_F9_6

#define IVS_MMP_X_FOREACH_F9_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_7_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_7_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_7_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_7_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g)
#define IVS_MMP_X_FOREACH_F9_7_() IVS_MMP_X_FOREACH_F9_7

#define IVS_MMP_X_FOREACH_F9_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_8_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_8_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_8_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_8_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h)
#define IVS_MMP_X_FOREACH_F9_8_() IVS_MMP_X_FOREACH_F9_8

#define IVS_MMP_X_FOREACH_F9_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, ...) IVS_MMP_EXCAT(IVS_MMP_EXCAT(IVS_MMP_X_FOREACH_F9_9_, IVS_MMP_XEMPTY(__VA_ARGS__)), _) (macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_9_0_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i) IVS_MMP_DEFER(IVS_MMP_X_FOREACH_F9_9_)()(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__)
#define IVS_MMP_X_FOREACH_F9_9_1_(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i, ...) macro(f1, f2, f3, f4, f5, f6, f7, f8, f9, a, b, c, d, e, f, g, h, i)
#define IVS_MMP_X_FOREACH_F9_9_() IVS_MMP_X_FOREACH_F9_9


#define IVS_MMP_EVALUATE(...)  IVS_MMP_MCSTK_A1_(IVS_MMP_MCSTK_A1_(IVS_MMP_MCSTK_A1_(IVS_MMP_MCSTK_A1_(__VA_ARGS__))))
#define IVS_MMP_MCSTK_A1_(...) IVS_MMP_MCSTK_A2_(IVS_MMP_MCSTK_A2_(IVS_MMP_MCSTK_A2_(IVS_MMP_MCSTK_A2_(__VA_ARGS__))))
#define IVS_MMP_MCSTK_A2_(...) IVS_MMP_MCSTK_A3_(IVS_MMP_MCSTK_A3_(IVS_MMP_MCSTK_A3_(IVS_MMP_MCSTK_A3_(__VA_ARGS__))))
#define IVS_MMP_MCSTK_A3_(...) IVS_MMP_MCSTK_A4_(IVS_MMP_MCSTK_A4_(IVS_MMP_MCSTK_A4_(IVS_MMP_MCSTK_A4_(__VA_ARGS__))))

#ifdef IVS_MMP_MCSTK_EXT
#define IVS_MMP_MCSTK_A4_(...) IVS_MMP_MCSTK_A5_(IVS_MMP_MCSTK_A5_(IVS_MMP_MCSTK_A5_(IVS_MMP_MCSTK_A5_(__VA_ARGS__))))
#else
// #define IVS_MMP_MCSTK_A4_(...) IVS_MMP_MCSTK_A5_(IVS_MMP_MCSTK_A5_(IVS_MMP_MCSTK_A5_(IVS_MMP_MCSTK_A5_(__VA_ARGS__))))
#endif

// #define IVS_MMP_MCSTK_A5_(...) IVS_MMP_MCSTK_A6_(IVS_MMP_MCSTK_A6_(IVS_MMP_MCSTK_A6_(IVS_MMP_MCSTK_A6_(__VA_ARGS__))))
// #define IVS_MMP_MCSTK_A6_(...) IVS_MMP_MCSTK_A7_(IVS_MMP_MCSTK_A7_(IVS_MMP_MCSTK_A7_(IVS_MMP_MCSTK_A7_(__VA_ARGS__))))
// #define IVS_MMP_MCSTK_A7_(...) IVS_MMP_MCSTK_A8_(IVS_MMP_MCSTK_A8_(IVS_MMP_MCSTK_A8_(IVS_MMP_MCSTK_A8_(__VA_ARGS__))))
// #define IVS_MMP_MCSTK_A8_(...) IVS_MMP_MCSTK_A9_(IVS_MMP_MCSTK_A9_(IVS_MMP_MCSTK_A9_(IVS_MMP_MCSTK_A9_(__VA_ARGS__))))

#ifdef IVS_MMP_MCSTK_EXT
#define IVS_MMP_MCSTK_A5_(...) __VA_ARGS__
#else
#define IVS_MMP_MCSTK_A4_(...) __VA_ARGS__
#endif


#define IVS_MMP_1(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_1(macro, __VA_ARGS__))
#define IVS_MMP_2(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_2(macro, __VA_ARGS__))
#define IVS_MMP_3(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_3(macro, __VA_ARGS__))
#define IVS_MMP_4(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_4(macro, __VA_ARGS__))
#define IVS_MMP_5(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_5(macro, __VA_ARGS__))
#define IVS_MMP_6(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_6(macro, __VA_ARGS__))
#define IVS_MMP_7(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_7(macro, __VA_ARGS__))
#define IVS_MMP_8(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_8(macro, __VA_ARGS__))
#define IVS_MMP_9(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_9(macro, __VA_ARGS__))

#define IVS_MMP_F1_1(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_1(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_2(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_2(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_3(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_3(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_4(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_4(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_5(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_5(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_6(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_6(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_7(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_7(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_8(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_8(macro, f1, __VA_ARGS__))
#define IVS_MMP_F1_9(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F1_9(macro, f1, __VA_ARGS__))

#define IVS_MMP_F2_1(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_1(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_2(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_2(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_3(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_3(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_4(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_4(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_5(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_5(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_6(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_6(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_7(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_7(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_8(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_8(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_F2_9(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F2_9(macro, f1, f2, __VA_ARGS__))

#define IVS_MMP_F3_1(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_1(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_2(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_2(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_3(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_3(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_4(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_4(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_5(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_5(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_6(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_6(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_7(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_7(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_8(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_8(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_F3_9(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F3_9(macro, f1, f2, f3, __VA_ARGS__))

#define IVS_MMP_F4_1(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_1(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_2(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_2(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_3(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_3(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_4(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_4(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_5(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_5(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_6(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_6(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_7(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_7(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_8(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_8(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_F4_9(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F4_9(macro, f1, f2, f3, f4, __VA_ARGS__))

#define IVS_MMP_F5_1(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_1(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_2(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_2(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_3(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_3(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_4(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_4(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_5(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_5(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_6(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_6(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_7(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_7(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_8(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_8(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_F5_9(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F5_9(macro, f1, f2, f3, f4, f5, __VA_ARGS__))

#define IVS_MMP_F6_1(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_1(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_2(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_2(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_3(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_3(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_4(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_4(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_5(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_5(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_6(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_6(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_7(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_7(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_8(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_8(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_F6_9(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F6_9(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))

#define IVS_MMP_F7_1(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_1(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_2(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_2(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_3(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_3(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_4(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_4(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_5(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_5(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_6(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_6(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_7(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_7(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_8(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_8(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_F7_9(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F7_9(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))

#define IVS_MMP_F8_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_F8_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F8_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))

#define IVS_MMP_F9_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_F9_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_FOREACH_F9_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))


#define IVS_MMP_X_1(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_1(macro, __VA_ARGS__))
#define IVS_MMP_X_2(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_2(macro, __VA_ARGS__))
#define IVS_MMP_X_3(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_3(macro, __VA_ARGS__))
#define IVS_MMP_X_4(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_4(macro, __VA_ARGS__))
#define IVS_MMP_X_5(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_5(macro, __VA_ARGS__))
#define IVS_MMP_X_6(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_6(macro, __VA_ARGS__))
#define IVS_MMP_X_7(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_7(macro, __VA_ARGS__))
#define IVS_MMP_X_8(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_8(macro, __VA_ARGS__))
#define IVS_MMP_X_9(macro, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_9(macro, __VA_ARGS__))

#define IVS_MMP_X_F1_1(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_1(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_2(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_2(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_3(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_3(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_4(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_4(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_5(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_5(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_6(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_6(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_7(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_7(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_8(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_8(macro, f1, __VA_ARGS__))
#define IVS_MMP_X_F1_9(macro, f1, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F1_9(macro, f1, __VA_ARGS__))

#define IVS_MMP_X_F2_1(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_1(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_2(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_2(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_3(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_3(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_4(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_4(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_5(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_5(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_6(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_6(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_7(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_7(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_8(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_8(macro, f1, f2, __VA_ARGS__))
#define IVS_MMP_X_F2_9(macro, f1, f2, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F2_9(macro, f1, f2, __VA_ARGS__))

#define IVS_MMP_X_F3_1(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_1(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_2(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_2(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_3(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_3(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_4(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_4(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_5(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_5(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_6(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_6(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_7(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_7(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_8(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_8(macro, f1, f2, f3, __VA_ARGS__))
#define IVS_MMP_X_F3_9(macro, f1, f2, f3, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F3_9(macro, f1, f2, f3, __VA_ARGS__))

#define IVS_MMP_X_F4_1(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_1(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_2(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_2(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_3(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_3(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_4(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_4(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_5(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_5(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_6(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_6(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_7(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_7(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_8(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_8(macro, f1, f2, f3, f4, __VA_ARGS__))
#define IVS_MMP_X_F4_9(macro, f1, f2, f3, f4, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F4_9(macro, f1, f2, f3, f4, __VA_ARGS__))

#define IVS_MMP_X_F5_1(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_1(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_2(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_2(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_3(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_3(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_4(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_4(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_5(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_5(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_6(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_6(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_7(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_7(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_8(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_8(macro, f1, f2, f3, f4, f5, __VA_ARGS__))
#define IVS_MMP_X_F5_9(macro, f1, f2, f3, f4, f5, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F5_9(macro, f1, f2, f3, f4, f5, __VA_ARGS__))

#define IVS_MMP_X_F6_1(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_1(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_2(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_2(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_3(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_3(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_4(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_4(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_5(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_5(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_6(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_6(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_7(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_7(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_8(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_8(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))
#define IVS_MMP_X_F6_9(macro, f1, f2, f3, f4, f5, f6, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F6_9(macro, f1, f2, f3, f4, f5, f6, __VA_ARGS__))

#define IVS_MMP_X_F7_1(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_1(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_2(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_2(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_3(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_3(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_4(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_4(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_5(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_5(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_6(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_6(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_7(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_7(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_8(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_8(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))
#define IVS_MMP_X_F7_9(macro, f1, f2, f3, f4, f5, f6, f7, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F7_9(macro, f1, f2, f3, f4, f5, f6, f7, __VA_ARGS__))

#define IVS_MMP_X_F8_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))
#define IVS_MMP_X_F8_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F8_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, __VA_ARGS__))

#define IVS_MMP_X_F9_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_1(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_2(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_3(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_4(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_5(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_6(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_7(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_8(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))
#define IVS_MMP_X_F9_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...) IVS_MMP_EVALUATE(IVS_MMP_X_FOREACH_F9_9(macro, f1, f2, f3, f4, f5, f6, f7, f8, f9, __VA_ARGS__))


// #ifndef IVS_DISABLE_INT128_EXT
// #define IVS_MMP_ARGLIST_I128 ,ivsI128, i128
// #define IVS_MMP_ARGLIST_U128 ,ivsU128, u128
// #else
// #define IVS_MMP_ARGLIST_I128
// #define IVS_MMP_ARGLIST_U128
// #endif
//
//
// #define IVS_MMP_ARGLIST_SINT           ivsI8, i8, ivsI16, i16, ivsI32, i32, ivsI64, i64 IVS_MMP_ARGLIST_I128
// #define IVS_MMP_ARGLIST_UINT           ivsU8, u8, ivsU16, u16, ivsU32, u32, ivsU64, u64 IVS_MMP_ARGLIST_U128
// #define IVS_MMP_ARGLIST_CHAR           ivsC8, c8
// #define IVS_MMP_ARGLIST_SZTP           ivsSz, sz
// #define IVS_MMP_ARGLIST_INT            IVS_MMP_ARGLIST_SINT, IVS_MMP_ARGLIST_UINT, IVS_MMP_ARGLIST_CHAR, IVS_MMP_ARGLIST_SZTP
// #define IVS_MMP_ARGLIST_XPTR           ivsPtr, ptr
// #define IVS_MMP_ARGLIST_CPTR           ivsCptr, cptr
// #define IVS_MMP_ARGLIST_PTR            IVS_MMP_ARGLIST_XPTR, IVS_MMP_ARGLIST_CPTR
// #define IVS_MMP_ARGLIST_INTPTR         IVS_MMP_ARGLIST_INT, IVS_MMP_ARGLIST_PTR
// #define IVS_MMP_ARGLIST_FP             ivsFs, fs, ivsFd, fd, ivsFx, fx
// #define IVS_MMP_ARGLIST_BYTE           ivsByte, byte
// #define IVS_MMP_ARGLIST_ALL_BUILTIN    IVS_MMP_ARGLIST_INTPTR, IVS_MMP_ARGLIST_FP, IVS_MMP_ARGLIST_BYTE


// #define IVS_MMP_GENERIC(func_name, param_name) _Generic()


#define IVS_MMP_CONJUNCTION_(fn, sep, expr) sep fn(expr)
#define IVS_MMP_CONJUNCTION(fn, sep, first, ...) fn(first) IVS_MMP_F2_1(IVS_MMP_CONJUNCTION_, fn, sep, __VA_ARGS__)


#define IVS_MMP_CONJUNCTION_X_(fn, sep, zero, expr) sep fn(expr)
#define IVS_MMP_CONJUNCTION_X(fn, sep, zero, first, ...) fn(first) IVS_MMP_X_F2_2(IVS_MMP_CONJUNCTION_X_, fn, sep, __VA_ARGS__)


#define IVS_MMP_LOWER_1TH  a
#define IVS_MMP_LOWER_2TH  b
#define IVS_MMP_LOWER_3TH  c
#define IVS_MMP_LOWER_4TH  d
#define IVS_MMP_LOWER_5TH  e
#define IVS_MMP_LOWER_6TH  f
#define IVS_MMP_LOWER_7TH  g
#define IVS_MMP_LOWER_8TH  h
#define IVS_MMP_LOWER_9TH  i
#define IVS_MMP_LOWER_10TH j
#define IVS_MMP_LOWER_11TH k
#define IVS_MMP_LOWER_12TH l
#define IVS_MMP_LOWER_13TH m
#define IVS_MMP_LOWER_14TH n
#define IVS_MMP_LOWER_15TH o
#define IVS_MMP_LOWER_16TH p
#define IVS_MMP_LOWER_17TH q
#define IVS_MMP_LOWER_18TH r
#define IVS_MMP_LOWER_19TH s
#define IVS_MMP_LOWER_20TH t
#define IVS_MMP_LOWER_21TH u
#define IVS_MMP_LOWER_22TH v
#define IVS_MMP_LOWER_23TH w
#define IVS_MMP_LOWER_24TH x
#define IVS_MMP_LOWER_25TH y
#define IVS_MMP_LOWER_26TH z

#define IVS_MMP_UPPER_1TH  A
#define IVS_MMP_UPPER_2TH  B
#define IVS_MMP_UPPER_3TH  C
#define IVS_MMP_UPPER_4TH  D
#define IVS_MMP_UPPER_5TH  E
#define IVS_MMP_UPPER_6TH  F
#define IVS_MMP_UPPER_7TH  G
#define IVS_MMP_UPPER_8TH  H
#define IVS_MMP_UPPER_9TH  I
#define IVS_MMP_UPPER_10TH J
#define IVS_MMP_UPPER_11TH K
#define IVS_MMP_UPPER_12TH L
#define IVS_MMP_UPPER_13TH M
#define IVS_MMP_UPPER_14TH N
#define IVS_MMP_UPPER_15TH O
#define IVS_MMP_UPPER_16TH P
#define IVS_MMP_UPPER_17TH Q
#define IVS_MMP_UPPER_18TH R
#define IVS_MMP_UPPER_19TH S
#define IVS_MMP_UPPER_20TH T
#define IVS_MMP_UPPER_21TH U
#define IVS_MMP_UPPER_22TH V
#define IVS_MMP_UPPER_23TH W
#define IVS_MMP_UPPER_24TH X
#define IVS_MMP_UPPER_25TH Y
#define IVS_MMP_UPPER_26TH Z


#define IVS_MMP_LOWER_1  a
#define IVS_MMP_LOWER_2  a, b
#define IVS_MMP_LOWER_3  a, b, c
#define IVS_MMP_LOWER_4  a, b, c, d
#define IVS_MMP_LOWER_5  a, b, c, d, e
#define IVS_MMP_LOWER_6  a, b, c, d, e, f
#define IVS_MMP_LOWER_7  a, b, c, d, e, f, g
#define IVS_MMP_LOWER_8  a, b, c, d, e, f, g, h
#define IVS_MMP_LOWER_9  a, b, c, d, e, f, g, h, i
#define IVS_MMP_LOWER_10 a, b, c, d, e, f, g, h, i, j
#define IVS_MMP_LOWER_11 a, b, c, d, e, f, g, h, i, j, k
#define IVS_MMP_LOWER_12 a, b, c, d, e, f, g, h, i, j, k, l
#define IVS_MMP_LOWER_13 a, b, c, d, e, f, g, h, i, j, k, l, m
#define IVS_MMP_LOWER_14 a, b, c, d, e, f, g, h, i, j, k, l, m, n
#define IVS_MMP_LOWER_15 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
#define IVS_MMP_LOWER_16 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
#define IVS_MMP_LOWER_17 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q
#define IVS_MMP_LOWER_18 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r
#define IVS_MMP_LOWER_19 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s
#define IVS_MMP_LOWER_20 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t
#define IVS_MMP_LOWER_21 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u
#define IVS_MMP_LOWER_22 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v
#define IVS_MMP_LOWER_23 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w
#define IVS_MMP_LOWER_24 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x
#define IVS_MMP_LOWER_25 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y
#define IVS_MMP_LOWER_26 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z

#define IVS_MMP_UPPER_1  A
#define IVS_MMP_UPPER_2  A, B
#define IVS_MMP_UPPER_3  A, B, C
#define IVS_MMP_UPPER_4  A, B, C, D
#define IVS_MMP_UPPER_5  A, B, C, D, E
#define IVS_MMP_UPPER_6  A, B, C, D, E, F
#define IVS_MMP_UPPER_7  A, B, C, D, E, F, G
#define IVS_MMP_UPPER_8  A, B, C, D, E, F, G, H
#define IVS_MMP_UPPER_9  A, B, C, D, E, F, G, H, I
#define IVS_MMP_UPPER_10 A, B, C, D, E, F, G, H, I, J
#define IVS_MMP_UPPER_11 A, B, C, D, E, F, G, H, I, J, K
#define IVS_MMP_UPPER_12 A, B, C, D, E, F, G, H, I, J, K, L
#define IVS_MMP_UPPER_13 A, B, C, D, E, F, G, H, I, J, K, L, M
#define IVS_MMP_UPPER_14 A, B, C, D, E, F, G, H, I, J, K, L, M, N
#define IVS_MMP_UPPER_15 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
#define IVS_MMP_UPPER_16 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P
#define IVS_MMP_UPPER_17 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q
#define IVS_MMP_UPPER_18 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R
#define IVS_MMP_UPPER_19 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S
#define IVS_MMP_UPPER_20 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T
#define IVS_MMP_UPPER_21 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U
#define IVS_MMP_UPPER_22 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V
#define IVS_MMP_UPPER_23 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W
#define IVS_MMP_UPPER_24 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X
#define IVS_MMP_UPPER_25 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y
#define IVS_MMP_UPPER_26 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z


#define IVS_MMP_LOWER_ARGMAKE_1(front)  front a
#define IVS_MMP_LOWER_ARGMAKE_2(front)  front a, front b
#define IVS_MMP_LOWER_ARGMAKE_3(front)  front a, front b, front c
#define IVS_MMP_LOWER_ARGMAKE_4(front)  front a, front b, front c, front d
#define IVS_MMP_LOWER_ARGMAKE_5(front)  front a, front b, front c, front d, front e
#define IVS_MMP_LOWER_ARGMAKE_6(front)  front a, front b, front c, front d, front e, front f
#define IVS_MMP_LOWER_ARGMAKE_7(front)  front a, front b, front c, front d, front e, front f, front g
#define IVS_MMP_LOWER_ARGMAKE_8(front)  front a, front b, front c, front d, front e, front f, front g, front h
#define IVS_MMP_LOWER_ARGMAKE_9(front)  front a, front b, front c, front d, front e, front f, front g, front h, front i
#define IVS_MMP_LOWER_ARGMAKE_10(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j
#define IVS_MMP_LOWER_ARGMAKE_11(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k
#define IVS_MMP_LOWER_ARGMAKE_12(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l
#define IVS_MMP_LOWER_ARGMAKE_13(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m
#define IVS_MMP_LOWER_ARGMAKE_14(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n
#define IVS_MMP_LOWER_ARGMAKE_15(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o
#define IVS_MMP_LOWER_ARGMAKE_16(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p
#define IVS_MMP_LOWER_ARGMAKE_17(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q
#define IVS_MMP_LOWER_ARGMAKE_18(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r
#define IVS_MMP_LOWER_ARGMAKE_19(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s
#define IVS_MMP_LOWER_ARGMAKE_20(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t
#define IVS_MMP_LOWER_ARGMAKE_21(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t, front u
#define IVS_MMP_LOWER_ARGMAKE_22(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t, front u, front v
#define IVS_MMP_LOWER_ARGMAKE_23(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t, front u, front v, front w
#define IVS_MMP_LOWER_ARGMAKE_24(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t, front u, front v, front w, front x
#define IVS_MMP_LOWER_ARGMAKE_25(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t, front u, front v, front w, front x, front y
#define IVS_MMP_LOWER_ARGMAKE_26(front) front a, front b, front c, front d, front e, front f, front g, front h, front i, front j, front k, front l, front m, front n, front o, front p, front q, front r, front s, front t, front u, front v, front w, front x, front y, front z

#define IVS_MMP_UPPER_ARGMAKE_1(front)  front A
#define IVS_MMP_UPPER_ARGMAKE_2(front)  front A, front B
#define IVS_MMP_UPPER_ARGMAKE_3(front)  front A, front B, front C
#define IVS_MMP_UPPER_ARGMAKE_4(front)  front A, front B, front C, front D
#define IVS_MMP_UPPER_ARGMAKE_5(front)  front A, front B, front C, front D, front E
#define IVS_MMP_UPPER_ARGMAKE_6(front)  front A, front B, front C, front D, front E, front F
#define IVS_MMP_UPPER_ARGMAKE_7(front)  front A, front B, front C, front D, front E, front F, front G
#define IVS_MMP_UPPER_ARGMAKE_8(front)  front A, front B, front C, front D, front E, front F, front G, front H
#define IVS_MMP_UPPER_ARGMAKE_9(front)  front A, front B, front C, front D, front E, front F, front G, front H, front I
#define IVS_MMP_UPPER_ARGMAKE_10(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J
#define IVS_MMP_UPPER_ARGMAKE_11(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K
#define IVS_MMP_UPPER_ARGMAKE_12(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L
#define IVS_MMP_UPPER_ARGMAKE_13(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M
#define IVS_MMP_UPPER_ARGMAKE_14(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N
#define IVS_MMP_UPPER_ARGMAKE_15(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O
#define IVS_MMP_UPPER_ARGMAKE_16(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P
#define IVS_MMP_UPPER_ARGMAKE_17(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q
#define IVS_MMP_UPPER_ARGMAKE_18(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R
#define IVS_MMP_UPPER_ARGMAKE_19(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S
#define IVS_MMP_UPPER_ARGMAKE_20(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T
#define IVS_MMP_UPPER_ARGMAKE_21(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T, front U
#define IVS_MMP_UPPER_ARGMAKE_22(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T, front U, front V
#define IVS_MMP_UPPER_ARGMAKE_23(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T, front U, front V, front W
#define IVS_MMP_UPPER_ARGMAKE_24(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T, front U, front V, front W, front X
#define IVS_MMP_UPPER_ARGMAKE_25(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T, front U, front V, front W, front X, front Y
#define IVS_MMP_UPPER_ARGMAKE_26(front) front A, front B, front C, front D, front E, front F, front G, front H, front I, front J, front K, front L, front M, front N, front O, front P, front Q, front R, front S, front T, front U, front V, front W, front X, front Y, front Z


#endif
