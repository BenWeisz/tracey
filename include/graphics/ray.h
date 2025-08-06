#ifndef RAY_H
#define RAY_H

#include "math/vec.h"
#include "types.h"

typedef struct RAY
{
    VEC4 origin;
    VEC4 dir;
} RAY;

VEC4 RAY_at(RAY ray, const f64 t);

#endif // RAY_H