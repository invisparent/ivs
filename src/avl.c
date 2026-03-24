/**
 * Copyright (c) 2026 Chenyi Wang.
 *   (a.k.a. Invisparent, an Art, Computer Science and Mathematics Noob.)
 * SPDX-License-Identifier: LGPL-3.0-only
 */


/**
 * Reference:
 *   Adelson-Velskii, G.M. and Landis, E.M., 1962.
 *   An algorithm for the organization of information (No. 17137).
 */


/**
 * Profiling result, compared with std::set (rb_tree):
 *   Computer:
 *     CPU: AMD Ryzen 9 9950X3D
 *     MB : Micro-Star X670E Carbon
 *     PBO: Enhanced Mode 2
 *     MEM: G-Skill Trident Z Royal, 2*48=96GB DDR5@6400MHz, c32
 *   System:
 *     Windows 11 25H2 build.26200.7623
 *     Clang 21.1.8 -O2 -flto
 *     MSVC STL 14.44.35207
 *   Result (STL libivs factor):
 *     1e7 uint32, uniform in [UINT32_MIN, UINT32_MAX], insertion:
 *       7.51s 9.49s 126.3%
 *     1e7 query:
 *       4.62s 8.38s 181.5%
 *     after 1e7 insertion, delete front 5e6 element:
 *       377ms 636ms 168.7%
 */


#include "ivs/avl.h"


struct ivs_static_avl_node {
    ivs_static_avl_node *parent;
    ivs_static_avl_node *left;
    ivs_static_avl_node *right;
    size_t height;
};

void
ivs_avl_init(
    ivs_avl *const self
) {
    ivs_assert(self);
    self->root = NULL;
}

static
void
ivs_static_avl_free(
    ivs_static_avl_node *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self);
    ivs_assert(alloc);
    if (self->left)
        ivs_static_avl_free(self->left, alloc);
    if (self->right)
        ivs_static_avl_free(self->right, alloc);
    ivs_allocator_free(alloc, self);
}

void
ivs_avl_free(
    const ivs_avl *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self && alloc);
    if (self->root)
        ivs_static_avl_free(self->root, alloc);
}

void
ivs_avl_clear(
    ivs_avl *const self,
    const ivs_allocator *const alloc
) {
    ivs_assert(self && alloc);
    ivs_avl_free(self, alloc);
    self->root = NULL;
}

static
void *
ivs_static_avl_deref_key(
    const ivs_avl *const self,
    const ivs_iterator iter
) {
    (void) self;
    return ivs_iterator_deref(&iter, sizeof(ivs_static_avl_node));
}

static
ivs_static_avl_node *
ivs_static_avl_copy(
    _Bool *const err,
    const size_t bpe,
    const ivs_allocator *const alloc,
    ivs_static_avl_node *const opt_parent,
    ivs_static_avl_node *const opt_src
) {
    ivs_assert(err && bpe && alloc);
    if (!opt_src || *err)
        return NULL;
    ivs_static_avl_node *const ret = ivs_allocator_malloc(alloc, sizeof(ivs_static_avl_node) + bpe);
    if (!ret) {
        *err = 1;
        return NULL;
    }
    ret->parent = opt_parent;
    ret->height = opt_src->height;
    ivs_memcpy(ivs_static_avl_deref_key(NULL, ivs_iterator_make(ret)), ivs_static_avl_deref_key(NULL, ivs_iterator_make(opt_src)), bpe);
    ret->left = ivs_static_avl_copy(err, bpe, alloc, ret, opt_src->left);
    ret->right = ivs_static_avl_copy(err, bpe, alloc, ret, opt_src->right);
    return ret;
}

IVS_STATUS
ivs_avl_copy(
    ivs_avl *const dst,
    const size_t bpk,
    const size_t bpv,
    const ivs_allocator *const alloc,
    const ivs_avl *const src
) {
    ivs_assert(dst && alloc && src);
    ivs_assert(bpk);
    ivs_avl_clear(dst, alloc);
    if (ivs_avl_empty(src))
        return IVS_SUCCESS;
    _Bool err = 0;
    dst->root = ivs_static_avl_copy(&err, bpk + bpv, alloc, NULL, src->root);
    if (err) {
        ivs_avl_clear(dst, alloc);
        IVS_LOG_FAILED();
    }
    return IVS_SUCCESS;
}

void
ivs_avl_move(
    ivs_avl *const dst,
    ivs_avl *const src
) {
    ivs_assert(dst && src);
    ivs_inline_swap(ivs_static_avl_node *, dst->root, src->root);
}

_Bool
ivs_avl_empty(
    const ivs_avl *const self
) {
    ivs_assert(self);
    return !self->root;
}

size_t
ivs_avl_length(
    const ivs_avl *const self
) {
    ivs_assert(self);
    size_t ret = 0;
    ivs_iterator iter = ivs_avl_begin(self);
    const ivs_iterator end = ivs_avl_before_end(self);
    while (ivs_iterator_not_equal(&iter, end)) {
        ++ret;
        iter = ivs_avl_advance(self, iter, 1);
    }
    return ret;
}

ivs_iterator
ivs_avl_begin(
    const ivs_avl *const self
) {
    ivs_assert(self);
    if (ivs_avl_empty(self))
        return ivs_iterator_make(NULL);
    ivs_static_avl_node *iter = self->root;
    while (iter->left)
        iter = iter->left;
    return ivs_iterator_make(iter);
}

ivs_iterator
ivs_avl_before_end(
    const ivs_avl *const self
) {
    ivs_assert(self);
    if (ivs_avl_empty(self))
        return ivs_iterator_make(NULL);
    ivs_static_avl_node *iter = self->root;
    while (iter->right)
        iter = iter->right;
    return ivs_iterator_make(iter);
}

void *
ivs_avl_front(
    const ivs_avl *const self,
    const size_t bpk
) {
    ivs_assert(!ivs_avl_empty(self));
    ivs_assert(bpk);
    const ivs_iterator iter = ivs_avl_begin(self);
    return ivs_avl_deref_value(self, bpk, iter);
}

void *
ivs_avl_back(
    const ivs_avl *const self,
    const size_t bpk
) {
    ivs_assert(!ivs_avl_empty(self));
    ivs_assert(bpk);
    const ivs_iterator iter = ivs_avl_before_end(self);
    return ivs_avl_deref_value(self, bpk, iter);
}

static
_Bool
ivs_static_avl_direction(
    const ivs_avl *const self,
    const ivs_static_avl_node *const iter
) {
    (void) self;
    ivs_assert(iter->parent);
    if (iter->parent->left == iter)
        return 0;
    else
        return 1;
}

static
ivs_static_avl_node *
ivs_static_avl_advance_forward(
    const ivs_avl *const self,
    ivs_static_avl_node *iter
) {
    ivs_assert(self && iter);
    if (iter->right) {
        iter = iter->right;
        while (iter->left)
            iter = iter->left;
        return iter;
    } else {
        while (iter->parent)
            if (!ivs_static_avl_direction(self, iter))
                return iter->parent;
            else
                iter = iter->parent;
        return NULL;
    }
}

static
ivs_static_avl_node *
ivs_static_avl_advance_backward(
    const ivs_avl *const self,
    ivs_static_avl_node *iter
) {
    ivs_assert(self && iter);
    if (iter->left) {
        iter = iter->left;
        while (iter->right)
            iter = iter->right;
        return iter;
    } else {
        while (iter->parent)
            if (ivs_static_avl_direction(self, iter))
                return iter->parent;
            else
                iter = iter->parent;
        return NULL;
    }
}

ivs_iterator
ivs_avl_advance(
    const ivs_avl *const self,
    ivs_iterator iter,
    ptrdiff_t step
) {
    ivs_assert(self);
    if (step < 0)
        while (step && !ivs_iterator_empty(&iter)) {
            if (ivs_iterator_empty(&iter))
                return ivs_iterator_make(NULL);
            iter = ivs_iterator_make(ivs_static_avl_advance_backward(self, ivs_iterator_raw(&iter)));
            ++step;
        }
    else if (step > 0)
        while (step && !ivs_iterator_empty(&iter)) {
            if (ivs_iterator_empty(&iter))
                return ivs_iterator_make(NULL);
            iter = ivs_iterator_make(ivs_static_avl_advance_forward(self, ivs_iterator_raw(&iter)));
            --step;
        }
    return iter;
}

const void *
ivs_avl_deref_key(
    const ivs_avl *const self,
    const ivs_iterator iter
) {
    (void) self;
    return ivs_iterator_deref_const(&iter, sizeof(ivs_static_avl_node));
}

void *
ivs_avl_deref_value(
    const ivs_avl *const self,
    const size_t bpk,
    const ivs_iterator iter
) {
    (void) self;
    ivs_assert(bpk);
    return ivs_iterator_deref(&iter, sizeof(ivs_static_avl_node) + bpk);
}

static
size_t
ivs_static_avl_height(
    const ivs_avl *const self,
    const ivs_static_avl_node *const iter
) {
    (void) self;
    ivs_assert(iter);
    const size_t l = iter->left ? iter->left->height : 0;
    const size_t r = iter->right ? iter->right->height : 0;
    const size_t ret = ivs_inline_max(l, r) + 1;
    return ret;
}

static
int
ivs_static_avl_diff(
    const ivs_avl *const self,
    const ivs_static_avl_node *const iter
) {
    (void) self;
    ivs_assert(iter);
    const size_t l = iter->left ? iter->left->height : 0;
    const size_t r = iter->right ? iter->right->height : 0;
    if (l <= r)
        return (int) (r - l);
    else
        return -(int) (l - r);
}

static
void
ivs_static_avl_rotate_left(
    ivs_avl *const self,
    ivs_static_avl_node *const iter
) {
    ivs_assert(self && iter);
    ivs_assert(iter->right);
    ivs_static_avl_node *const sub = iter->right;
    ivs_static_avl_node *const p = iter->parent;
    ivs_static_avl_node *const l = iter->left; // NOLINT
    ivs_static_avl_node *const m = iter->right->left;
    ivs_static_avl_node *const r = iter->right->right; // NOLINT
    (void) l;
    (void) r;
    if (!p)
        self->root = sub;
    else {
        const _Bool d = ivs_static_avl_direction(self, iter);
        if (!d)
            p->left = sub;
        else
            p->right = sub;
    }
    if (m)
        m->parent = iter;
    iter->parent = sub;
    iter->right = m;
    sub->parent = p;
    sub->left = iter;
    iter->height = ivs_static_avl_height(self, iter);
    sub->height = ivs_static_avl_height(self, sub);
}

static
void
ivs_static_avl_rotate_right(
    ivs_avl *const self,
    ivs_static_avl_node *const iter
) {
    ivs_assert(self && iter);
    ivs_assert(iter->left);
    ivs_static_avl_node *const sub = iter->left;
    ivs_static_avl_node *const p = iter->parent;
    ivs_static_avl_node *const l = iter->left->left; // NOLINT
    ivs_static_avl_node *const m = iter->left->right;
    ivs_static_avl_node *const r = iter->right; // NOLINT
    (void) l;
    (void) r;
    if (!p)
        self->root = sub;
    else {
        const _Bool d = ivs_static_avl_direction(self, iter);
        if (!d)
            p->left = sub;
        else
            p->right = sub;
    }
    if (m)
        m->parent = iter;
    iter->parent = sub;
    iter->left = m;
    sub->parent = p;
    sub->right = iter;
    iter->height = ivs_static_avl_height(self, iter);
    sub->height = ivs_static_avl_height(self, sub);
}

static
void
ivs_static_avl_balance(
    ivs_avl *const self,
    ivs_static_avl_node *iter
) {
    ivs_assert(self && iter);
    while (1) {
        if (!iter)
            break;
        iter->height = ivs_static_avl_height(self, iter);
        const int d1 = ivs_static_avl_diff(self, iter);
        if (ivs_inline_between_cc(-1, 1, d1)) {
            iter = iter->parent;
            continue;
        }
        ivs_static_avl_node *const next = iter->parent;
        ivs_assert(ivs_inline_between_cc(-2, 2, d1));
        if (d1 == -2) {
            ivs_assert(iter->left);
            const int d2 = ivs_static_avl_diff(self, iter->left);
            // ivs_assert(ivs_inline_between_cc(-1, 1, d2));
            // LL case
            if (d2 < 0)
                ivs_static_avl_rotate_right(self, iter);
            // LR case
            else {
                ivs_static_avl_rotate_left(self, iter->left);
                ivs_static_avl_rotate_right(self, iter);
            }
        } else {
            ivs_assert(iter->right);
            const int d2 = ivs_static_avl_diff(self, iter->right);
            // ivs_assert(ivs_inline_between_cc(-1, 1, d2));
            // RR case
            if (d2 > 0)
                ivs_static_avl_rotate_left(self, iter);
            // RL case
            else {
                ivs_static_avl_rotate_right(self, iter->right);
                ivs_static_avl_rotate_left(self, iter);
            }
        }
        iter = next;
    }
}

/**
 * @param opt_pos_hint 0: exact
 *                     1: left
 *                     2: right
 *                     3: root
 */

static
ivs_static_avl_node *
ivs_static_avl_find(
    const ivs_avl *const self,
    int *const opt_pos_hint,
    int (*const cmp)(const void *, const void *),
    const void *const key
) {
    ivs_assert(self && cmp && key);
    if (!self->root) {
        ivs_opt_arg_set(opt_pos_hint, 3);
        return NULL;
    }
    ivs_static_avl_node *iter = self->root;
    while (1) {
        const ivs_iterator it = ivs_iterator_make(iter);
        const int r = cmp(key, ivs_avl_deref_key(self, it));
        if (r < 0)
            if (iter->left)
                iter = iter->left;
            else {
                ivs_opt_arg_set(opt_pos_hint, 1);
                break;
            }
        else if (r > 0)
            if (iter->right)
                iter = iter->right;
            else {
                ivs_opt_arg_set(opt_pos_hint, 2);
                break;
            }
        else {
            ivs_opt_arg_set(opt_pos_hint, 0);
            break;
        }
    }
    return iter;
}

ivs_iterator
ivs_avl_iter(
    const ivs_avl *const self,
    int (*const cmp)(const void *, const void *),
    const void *const key
) {
    ivs_assert(self && cmp && key);
    int pos;
    ivs_static_avl_node *const ret = ivs_static_avl_find(self, &pos, cmp, key);
    if (!pos)
        return ivs_iterator_make(ret);
    else
        return ivs_iterator_make(NULL);
}

_Bool
ivs_avl_replace(
    const ivs_avl *const self,
    const size_t bpk,
    const size_t bpv,
    int (*const cmp)(const void *, const void *),
    const void *const key,
    const void *const value
) {
    ivs_assert(self && cmp && key && value);
    ivs_assert(bpk);
    ivs_assert(bpv);
    int stat;
    ivs_static_avl_node *const pos = ivs_static_avl_find(self, &stat, cmp, key);
    if (!stat) {
        const ivs_iterator iter = ivs_iterator_make(pos);
        void *const dst = ivs_avl_deref_value(self, bpk, iter);
        ivs_memmove(dst, value, bpv);
        return 1;
    } else
        return 0;
}

/**
 * Internal insert.
 * New node's value is not initialized.
 *
 * @return iter point to the new-created node. NULL if error occurred.
 */
static
ivs_static_avl_node *
ivs_static_avl_insert(
    ivs_avl *const self,
    const size_t bpk,
    const size_t bpv,
    int (*const cmp)(const void *, const void *),
    const ivs_allocator *const alloc,
    const void *const key,
    ivs_static_avl_node *const iter,
    const int stat
) {
    ivs_assert(self && cmp && alloc && key);
    ivs_assert(bpk);
    ivs_assert(ivs_inline_between_cc(1, 3, stat));
    ivs_static_avl_node *const ret = ivs_allocator_malloc(alloc, sizeof(ivs_static_avl_node) + bpk + bpv);
    if (!ret)
        return NULL;
    const ivs_iterator it = ivs_iterator_make(ret);
    ivs_memcpy(ivs_static_avl_deref_key(self, it), key, bpk);
    ret->left = NULL;
    ret->right = NULL;
    switch (stat) {
        case 3:
            ret->parent = NULL;
            self->root = ret;
            break;
        case 1:
            ivs_assert(!iter->left);
            iter->left = ret;
            ret->parent = iter;
            break;
        case 2:
            ivs_assert(!iter->right);
            iter->right = ret;
            ret->parent = iter;
            break;
        default:
            ivs_unreachable();
    }
    ivs_static_avl_balance(self, ret);
    return ret;
}

/**
 * @return Empty if error occurred. (e.g. malloc failed)
 *         If not empty, it points to the node that has the specified key.
 * @param opt_inserted Shows whether the insertion really happens.
 * @param opt_value    If not null we'll override the value using this.
 *                     Otherwise, memory of value will keep unchanged or uninitialized.
 * @param bpv          If bpv == 0, opt_value must be null.
 */
ivs_iterator
ivs_avl_insert(
    ivs_avl *const self,
    _Bool *const opt_inserted,
    const size_t bpk,
    const size_t bpv,
    int (*const cmp)(const void *, const void *),
    const ivs_allocator *const alloc,
    const void *const key,
    const void *const opt_value
) {
    ivs_assert(self && cmp && alloc && key);
    ivs_assert(bpk);
    ivs_assert(opt_value ? bpv : 1);
    int stat;
    ivs_static_avl_node *const pos = ivs_static_avl_find(self, &stat, cmp, key);
    if (!stat) {
        ivs_opt_arg_set(opt_inserted, 0);
        const ivs_iterator ret = ivs_iterator_make(pos);
        if (opt_value)
            ivs_memmove(ivs_avl_deref_value(self, bpk, ret), opt_value, bpv);
        return ret;
    } else {
        ivs_static_avl_node *const p = ivs_static_avl_insert(self, bpk, bpv, cmp, alloc, key, pos, stat);
        if (!p) {
            ivs_opt_arg_set(opt_inserted, 0);
            ivs_log();
            return ivs_iterator_make(NULL);
        } else {
            ivs_opt_arg_set(opt_inserted, 1);
            const ivs_iterator ret = ivs_iterator_make(p);
            if (opt_value)
                ivs_memmove(ivs_avl_deref_value(self, bpk, ret), opt_value, bpv);
            return ret;
        }
    }
}

/**
 * @return Null if not found.
 */
void *
ivs_avl_at(
    const ivs_avl *const self,
    const size_t bpk,
    int (*const cmp)(const void *, const void *),
    const void *key
) {
    ivs_assert(self && cmp && key);
    ivs_assert(bpk);
    const ivs_iterator ret = ivs_avl_iter(self, cmp, key);
    if (ivs_iterator_empty(&ret))
        return NULL;
    else
        return ivs_avl_deref_value(self, bpk, ret);
}

static
void
ivs_static_avl_swap(
    ivs_avl *const self,
    ivs_static_avl_node *const a,
    ivs_static_avl_node *const b
) {
    ivs_assert(self && a && b);
    if (a == b)
        return;
    if (a->parent == b) {
        if (!b->parent)
            self->root = a;
        else {
            const _Bool d = ivs_static_avl_direction(self, b);
            if (!d)
                b->parent->left = a;
            else
                b->parent->right = a;
        }
        if (a->left)
            a->left->parent = b;
        if (a->right)
            a->right->parent = b;
        const _Bool d = ivs_static_avl_direction(self, a);
        if (d) {
            if (b->left)
                b->left->parent = a;
            a->parent = b->parent;
            b->parent = a;
            ivs_inline_swap(ivs_static_avl_node *, a->left, b->left);
            b->right = a->right;
            a->right = b;
        } else {
            if (b->right)
                b->right->parent = a;
            a->parent = b->parent;
            b->parent = a;
            ivs_inline_swap(ivs_static_avl_node *, a->right, b->right);
            b->left = a->left;
            a->left = b;
        }
    } else if (b->parent == a) {
        if (!a->parent)
            self->root = b;
        else {
            const _Bool d = ivs_static_avl_direction(self, a);
            if (!d)
                a->parent->left = b;
            else
                a->parent->right = b;
        }
        if (b->left)
            b->left->parent = a;
        if (b->right)
            b->right->parent = a;
        const _Bool d = ivs_static_avl_direction(self, b);
        if (d) {
            if (a->left)
                a->left->parent = b;
            b->parent = a->parent;
            a->parent = b;
            ivs_inline_swap(ivs_static_avl_node *, a->left, b->left);
            a->right = b->right;
            b->right = a;
        } else {
            if (a->right)
                a->right->parent = b;
            b->parent = a->parent;
            a->parent = b;
            ivs_inline_swap(ivs_static_avl_node *, a->right, b->right);
            a->left = b->left;
            b->left = a;
        }
    } else {
        if (!a->parent)
            self->root = b;
        else {
            const _Bool d = ivs_static_avl_direction(self, a);
            if (!d)
                a->parent->left = b;
            else
                a->parent->right = b;
        }
        if (!b->parent)
            self->root = a;
        else {
            const _Bool d = ivs_static_avl_direction(self, b);
            if (!d)
                b->parent->left = a;
            else
                b->parent->right = a;
        }
        if (a->left)
            a->left->parent = b;
        if (a->right)
            a->right->parent = b;
        if (b->left)
            b->left->parent = a;
        if (b->right)
            b->right->parent = a;
        ivs_inline_swap(ivs_static_avl_node *, a->parent, b->parent);
        ivs_inline_swap(ivs_static_avl_node *, a->left, b->left);
        ivs_inline_swap(ivs_static_avl_node *, a->right, b->right);
        ivs_inline_swap(size_t, a->height, b->height);
    }
}

ivs_iterator
ivs_avl_erase_iter(
    ivs_avl *const self,
    int (*const cmp)(const void *, const void *),
    const ivs_allocator *const alloc,
    const ivs_iterator iter
) {
    ivs_assert(self && cmp && alloc);
    ivs_assert(!ivs_iterator_empty(&iter));
    ivs_static_avl_node *const p = ivs_iterator_raw(&iter);
    ivs_static_avl_node *q = p;
    if (q->right) {
        q = q->right;
        while (q->left)
            q = q->left;
    }
    if (p != q)
        ivs_static_avl_swap(self, p, q);
    if (p->right)
        ivs_static_avl_swap(self, p, p->right);
    ivs_static_avl_node *const x = p->parent;
    if (p->parent) {
        const _Bool d = ivs_static_avl_direction(self, p);
        if (!d)
            x->left = NULL;
        else
            x->right = NULL;
    }
    ivs_allocator_free(alloc, p);
    if (!x) {
        self->root = NULL;
        return ivs_iterator_make(NULL);
    } else {
        ivs_static_avl_balance(self, x);
        return ivs_iterator_make(ivs_static_avl_advance_forward(self, x));
    }
}

/**
 * @return Null if erase failed because of element doesn't exist,
 *           or next element is end.
 */
ivs_iterator
ivs_avl_erase(
    ivs_avl *const self,
    _Bool *const opt_erased,
    int (*const cmp)(const void *, const void *),
    const ivs_allocator *const alloc,
    const void *const key
) {
    ivs_assert(self && cmp && alloc && key);
    const ivs_iterator iter = ivs_avl_iter(self, cmp, key);
    if (!ivs_iterator_empty(&iter)) {
        ivs_opt_arg_set(opt_erased, 1);
        return ivs_avl_erase_iter(self, cmp, alloc, iter);
    } else {
        ivs_opt_arg_set(opt_erased, 0);
        return ivs_iterator_make(NULL);
    }
}
