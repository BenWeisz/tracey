#ifndef SHAPE_H
#define SHAPE_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "debug_assert.h"

#include "math/vec.h"
#include "math/interval.h"

#include "graphics/ray.h"
#include "util/glist.h"

#define SHAPE_TYPE_SPHERE 0x00

typedef struct SPHERE
{
    VEC4 c;
    f64 r;
} SPHERE;

typedef struct SHAPE
{
    u32 type;
    union {
        SPHERE sphere;
    };
} SHAPE;

typedef struct SHAPE_HIT
{
    SHAPE* shape;
    VEC4 p;
    VEC4 n;
    f64 t;
    u32 front_face;
} SHAPE_HIT;

u32 SHAPE_hit(SHAPE* shape, const RAY* ray, const INTERVAL t_interval, SHAPE_HIT* shape_hit);

u32 SPHERE_hit(const SPHERE* sphere, const RAY* ray, const INTERVAL t_interval, SHAPE_HIT* shape_hit);

GLIST_DECLARE(SHAPE, SHAPE_LIST)

#endif // SHAPE_H