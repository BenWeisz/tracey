#include "math/ray.h"

VEC4 RAY_at(RAY ray, const f64 t)
{
    return VEC4_add(ray.origin, VEC4_mul(ray.dir, t));
}