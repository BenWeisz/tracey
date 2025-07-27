#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <stdio.h>

#include "types.h"

typedef union VEC4
{
    struct {
        f64 x;
        f64 y;
        f64 z;
        f64 w;
    };
    struct {
        f64 r;
        f64 g;
        f64 b;
        f64 a;
    };
    f64 e[4];
} VEC4;

VEC4 VEC4_new(const f64 x, const f64 y, const f64 z, const f64 w);
VEC4 VEC4_zero();
VEC4 VEC4_neg(const VEC4 v);

VEC4 VEC4_sub(const VEC4 v1, const VEC4 v2);
VEC4 VEC4_add(const VEC4 v1, const VEC4 v2);
VEC4 VEC4_mul(const VEC4 v, const f64 c);
VEC4 VEC4_div(const VEC4 v, const f64 c);

f64 VEC4_norm(const VEC4 v);

f64 VEC4_dot(const VEC4 v1, const VEC4 v2);
VEC4 VEC4_cross(const VEC4 v1, const VEC4 v2);

VEC4 VEC4_normalize(const VEC4 v);

void VEC4_print(const VEC4 v);

#endif // VEC_H